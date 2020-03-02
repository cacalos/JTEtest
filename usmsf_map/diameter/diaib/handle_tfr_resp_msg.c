#include <RPDU/RPDU.h>
#include <RPDU/okhTypes.h>

#include "handle_msg.h"
#include "handle_tfr_resp_msg.h"
#include "dia_resp_tfr.h"
#include "stat.h"

int handle_tfr_resp_msg(uxc_worker_t *worker, smsf_msg_t *smsf_msg)
{
	int 				rv, cc, thread_id;
	char 				key_str[64];
	_RPDU 				rpdu;
	upa_diamsg_t        *pa_diamsg = NULL;
	diaib_tfr_respQ_t   *resQ;

	thread_id = uxc_worker_get_thread_id(worker);

	if(strlen(smsf_msg->supi) < 1 && smsf_msg->data_len < 1)
	{
		ux_log(UXL_CRT, "[Thread %d] IMSI is NULL or data_len : %d", 
				thread_id, smsf_msg->data_len);
		return DIAIB_RESULT_NOTOK;
	}

	memset(&rpdu, 0, sizeof(_RPDU));
	rv = DecodeRPDU(&rpdu, (void *)smsf_msg->data, smsf_msg->data_len, DIRECTION_MS_N);
	if(rv > 0 && (rpdu.MessageType != RPDU_RP_ACK && rpdu.MessageType != RPDU_RP_ERROR))
	{
		ux_log(UXL_CRT, "[Thread %d] DecodeRPDU() fail, ret = %d, MsgType = %d", thread_id, rv, rpdu.MessageType);
		return DIAIB_RESULT_NOTOK;
	}
	else {
		ux_log(UXL_INFO, "[Thread %d] DecodeRPDU() succ, supi[%s], msgType[%d], msgRef[%d]", 
				thread_id, smsf_msg->supi, rpdu.MessageType, rpdu.MessageReference);
	}

	sprintf(key_str, "%s-%d", smsf_msg->supi, rpdu.MessageReference);

	resQ = diaib_tfr_resp_find(worker, key_str);
	if( resQ == NULL)
	{
		ux_log(UXL_CRT, "[Thread %d]diaib_tfr_resp_find error(key(%s) ====", thread_id, key_str);
        return DIAIB_RESULT_NOTOK;
	}
	else {
		ux_log(UXL_INFO, "[Thread %d] Get success resp, key[%s]", thread_id, key_str);
	}
	
	diaib_tfr_resp_cancel_timer(uxc_worker_get_evtmgr(worker), (void *)resQ->tmevt);
    diaib_tfr_resp_remove(worker, key_str);

	pa_diamsg = create_diaib_tfr_rsp(UDIA_CMD_TFR, resQ->hop_id, resQ->end_id, resQ->peer_id);

	if(smsf_msg->causeCode > 0 || rpdu.MessageType == RPDU_RP_ERROR)
	{
		if( smsf_msg->causeCode > 0)
		{
			switch(smsf_msg->causeCode)
			{
				case ATTEMPTING_TO_REACH_UE :
				case N1_N2_TRANSFER_INITIATED :
				case WAITING_FOR_ASYNCHRONOUS_TRANSFER :
				case UE_NOT_RESPONDING :
				case N1_MSG_NOT_TRANSFERRED :
					cc = CC_NPR3G_CS;
					break;
				case UE_NOT_REACHABLE_FOR_SESSION :
					cc = CC_DEREGISTED_NON_GPRS;
					break;
				case HTTP_ERROR_FORBIDDEN :
				case HTTP_ERROR_NOT_FOUND :
					cc = CC_NPR3G_CS;
					break;
				case HTTP_ERROR_NOT_ALLOWED :
					cc = CC_CALL_BARRED;
					break;
				case HTTP_ERROR_TEMPORARY_REDIRECT :
				case HTTP_ERROR_BAD_REQUEST :
				case HTTP_ERROR_NOT_IMPLEMENTED :
				case HTTP_ERROR_SERVICE_UNAVAIABLE :
				case HTTP_ERROR_GATEWAY_TIMEOUT :
				default :
					cc = CC_ABSENT_SUBSCRIBER;
					break;
			}
		}
		else 
		{
			if(rpdu.Union.rError.CauseCode.cause > 0) {
				cc = ConvRpErrToCauseCode(rpdu.Union.rError.CauseCode.cause);

				switch(cc)
				{
					case CC_RP_MEMORY_CAPACITY_EXCEEDED :
						cc = CC_MCEF;
						break;
					case CC_RP_INVALID_SM_TRANSFER_REF_VALUE :
					case CC_RP_SEMANTICALLY_INCORRECT_MESSAGE :
					case CC_RP_INVALID_MANDATORY_INFORMATION :
					case CC_RP_MESSAGE_TYPE_NON_EXISTENT :
					case CC_RP_MESSAGE_NOT_COMPATIBLE :
					case CC_RP_INFO_ELEMENT_NON_EXISTENT :
					case CC_RP_PROTOCOL_ERROR_UNSPECIFIED :
					default :
						cc = CC_PROTOCOL_ERR;
				}
			}
		}

		set_avp_for_tfa_nack(pa_diamsg->stackmsg, resQ->session_id, resQ->orig_realm, resQ->orig_host, cc);
		inc_tfr_send_nack(resQ->smsc_node);
	}
	else {
		set_avp_for_tfa_ack(pa_diamsg->stackmsg, resQ->session_id, resQ->orig_realm, resQ->orig_host);
		inc_tfr_send_ack(resQ->smsc_node);
	}

	/* Set Trace flag */
	set_addr_mintrace_flag( NULL, NULL, &resQ->imsi);
    print_send_call_trace( pa_diamsg->stackmsg, NULL, &resQ->imsi);
	dia_msg_trc( worker, pa_diamsg->stackmsg );


	rv = send_msg_to_dia(worker, pa_diamsg);
	if( rv != DIAIB_RESULT_OK ) {
        ux_log( UXL_CRT, "[Thread %d] Send TFA msg FAIL(operation_name[TFA] supi[%s] err[%d])",
                thread_id, smsf_msg->supi, rv);
    }
	else {
		ux_log( UXL_INFO, "[Thread %d] Send TFA msg SUCCESS(operation_name[TFA] supi[%s])",
                thread_id, smsf_msg->supi);
	}

	return DIAIB_RESULT_OK;
}


