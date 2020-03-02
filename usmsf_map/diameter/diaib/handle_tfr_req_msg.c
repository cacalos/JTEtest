#include "diaib.h"
#include "handle_msg.h"
#include "handle_tfr_req_msg.h"
#include "dia_resp_tfr.h"
#include "stat.h"

int handle_recv_tfr(uxc_worker_t *worker, uxc_msg_t *msg)
{
	int                 rv, thread_id, err_code = 0;
	int                 hop_id, end_id, peer_id;
//	char                resp_key[DIAIB_RESP_KEY_MAX_LEN];
	char                session_id[256], orig_host[64], orig_realm[64], dest_host[64], dest_realm[64];
	unsigned char 		msgRef = 0;
	smsf_msg_t 			mt_msg;
	diaib_tfr_respQ_t 	*resQ;
	stAddr 				imsi, smscAddr;

	upa_diamsg_t        *rcv_pa_diamsg  = (upa_diamsg_t *)msg->data;
	udia_msg_t          *rcv_diamsg     = (udia_msg_t *)rcv_pa_diamsg->stackmsg;

	thread_id = uxc_worker_get_thread_id(worker);

	ux_log(UXL_INFO, "[Thread %d] handle_recv_tfr()", thread_id);

	memset(&mt_msg, 0, sizeof(smsf_msg_t));
	memset(&imsi, 0x00, sizeof(stAddr));
	memset(&smscAddr, 0x00, sizeof(stAddr));

	hop_id  = udia_msg_get_hop_id(rcv_diamsg);
    end_id  = udia_msg_get_end_id(rcv_diamsg);
    peer_id  = udia_msg_get_peer_id(rcv_diamsg);

	rv = make_mt_msg(rcv_diamsg, &mt_msg, (void *)&err_code, &msgRef, &smscAddr);

	check_smsc_list(smscAddr.min);

	if( rv != DIAIB_RESULT_OK)
	{
		inc_tfr_recv_fail(smscAddr.min);
		rv = send_tfr_fail_response(worker, rcv_pa_diamsg, DIAMETER_ERROR_SM_DELIVERY_FAILURE, equipmentProtocolError, &smscAddr );
		if(rv != DIAIB_RESULT_OK) {
			ux_log(UXL_MAJ, "send_tfr_fail_response() fail");
		}

		return DIAIB_RESULT_NOTOK;
	}
	else {
		ux_log(UXL_INFO, "[Thread %d] make_mt_msg(), imsi[%s], msgRef[%d], mms[%d]", 
				thread_id, mt_msg.supi, msgRef, mt_msg.isMMS);
		inc_tfr_recv_succ(smscAddr.min);
	}
	
	rv = get_dia_msg_for_resp_msg(rcv_diamsg, session_id, orig_realm, dest_realm, orig_host, dest_host);
	if( rv != DIAIB_RESULT_OK)
	{
		ux_log( UXL_CRT, "[Thread %d] Can't get Session-ID, or Realm, Host", thread_id);
		send_tfr_fail_response(worker, rcv_pa_diamsg, DIAMETER_ERROR_SM_DELIVERY_FAILURE, equipmentProtocolError, &smscAddr );
		if(rv != DIAIB_RESULT_OK) {
			ux_log(UXL_MAJ, "send_tfr_fail_response() fail");
		}
		return DIAIB_RESULT_NOTOK;
	}

	resQ = (diaib_tfr_respQ_t *)diaib_tfr_resp_insert(worker, mt_msg.supi, session_id, orig_realm, dest_realm, orig_host, dest_host,
			hop_id, end_id, peer_id, msgRef, smscAddr.min);
	if(resQ == NULL)
	{
		ux_log( UXL_CRT, "[Thread %d] handle_recv_tfr: diaout_tfr_resp_insert fail. msisdn: %s", thread_id, mt_msg.supi);
		return DIAIB_RESULT_ERROR;
	}
	/* Set Trace flag */

	imsi.len = sprintf(imsi.min, "%s", mt_msg.supi);

	set_addr_mintrace_flag( NULL, NULL, &imsi);
	print_rcv_call_trace( rcv_diamsg, NULL, &imsi, 0);
	dia_msg_trc( worker, rcv_diamsg);
  
	rv = InsProxyQMsg((void *)&mt_msg, MTYPE_MT);
	if( rv != IXOK) {
		ux_log(UXL_CRT, "[Thread %d] InsProxyQMsg() fail, imsi[%s]", thread_id, mt_msg.supi);
	} else {
		ux_log(UXL_INFO, "[Trhead %d] InsProxyQMsg() succ, imsi[%s]", thread_id, mt_msg.supi);
	}

	return DIAIB_RESULT_OK;
}


int make_mt_msg(udia_msg_t *diamsg, smsf_msg_t *mt_msg, uint32_t *err_code, unsigned char *mRef, stAddr *smscAddr)
{
	int 					rv, buff_len;
	int 		 			mmsFlag = MMS_FALSE;
	static unsigned char 	msgRef = 0;
	char 					buff[DIA_AVP_SM_RP_UI_MAX];
	char                	*tmp_str;
	udia_avplist_t 			*avp_list;

	memset( buff, 0x00, DIA_AVP_SM_RP_UI_MAX );

	avp_list = udia_msg_get_root(diamsg);

	/* Set Dest IMSI */
	tmp_str = udia_avplist_get_str_n(avp_list, "User-Name", &rv);
	if(tmp_str != NULL)
    {
        ux_log( UXL_DEBUG, "TFR's User-Name Info(IMSI:%s)", tmp_str);
		strcpy(mt_msg->supi, tmp_str);
    }
    else
        return DIAIB_RESULT_ERROR;

	rv = check_sc_address(avp_list, mt_msg, smscAddr);
	if(rv != DIAIB_RESULT_OK) {
		ux_log( UXL_CRT, "check_sc_address() fail." );
		*err_code = DIAMETER_ERROR_SM_DELIVERY_FAILURE;
		return DIAIB_RESULT_NOTOK;
	}

	/* Get AVP SM-RP-UI */
    buff_len = get_avp_octet_item( avp_list, AVP_NAME_SM_RP_UI, buff, DIA_AVP_SM_RP_UI_MAX );
    if ( buff_len <= 0 )           /* AVP(SM-RP-UI) lengthê0보뢴 ?거ë°? 경ì ??? ì¦? */
	{
        ux_log( UXL_CRT, "get_avp_octet_item() fail. " );
        return DIAIB_RESULT_NOTOK;
    }

	mmsFlag = udia_avplist_get_int_n(avp_list, "MWD-Status", &rv);
	if(rv == UDIA_SUCCESS && mmsFlag == 1) {
		mt_msg->isMMS = MMS_TRUE;
	}
	else {
		mt_msg->isMMS = MMS_FALSE;
	}

	mt_msg->msg_type = MT_MSG;
	atomic_inc(&msgRef);
	*mRef = msgRef;

	rv = MakeRPDU(MSG_DATA, DIRECTION_N_MS, NULL, smscAddr, 
			buff, buff_len, msgRef,
			&mt_msg->data_len, mt_msg->data);
	if(rv != IXOK || mt_msg->data_len < 1)
    {
        ux_log(UXL_CRT, "MakeRPDU() fail, smsc_isdn[%s], imsi[%s]", smscAddr->min, mt_msg->supi);
        return DIAIB_RESULT_NOTOK;
    }
	return DIAIB_RESULT_OK;
}


int send_tfr_fail_response(uxc_worker_t *worker, upa_diamsg_t *diamsg, int result_code, int dlvy_fail_cause, stAddr *smscAddr)
{
    int                 rv;
    //upa_dia_t           *padia;
    udia_msg_t          *rsp_msg;
    udia_avplist_t      *rsp_avplist;

    //padia = diaib_get_padia();
    /* Set diameter response msg from ALR msg */
	rsp_msg = udia_msg_make_answer( diamsg->stackmsg, UDIA_RESULT_SUCCESS, &rv );
    rsp_avplist = udia_msg_get_root(rsp_msg);
	/*
    rsp_msg = udia_msg_make_respond( diamsg->stackmsg, UDIA_RESULT_SUCCESS, &rv );
    rsp_avplist = &rsp_msg->avplist;
	 */
    if( rv < 0){
        ux_log( UXL_CRT, "udia_msg_make_respond() fail.err(%d)", rv);
    }

    /* Remove unnecessary AVP */
    set_fail_tfa_avp( rsp_avplist,  result_code );

    /* Set Result Code for response */
    switch( result_code ){
        case CC_SM_DELIVERY_FAILURE:
        case DIAMETER_ERROR_SM_DELIVERY_FAILURE:
            add_avp_exp_rst( rsp_avplist, DIAMETER_ERROR_SM_DELIVERY_FAILURE );
            break;

        case CC_FACILITY_NOT_SUPPORTED:
        case DIAMETER_ERROR_FACILITY_NOT_SUPPORTED:
            add_avp_exp_rst( rsp_avplist, DIAMETER_ERROR_FACILITY_NOT_SUPPORTED );
            break;

        case 0:/* ¼­ºñ»ó¡·¯·Îó¸®ÇÁ¸¸ SUCCESS·Î³ª°¡´Â°æ */
            break;

        default:/* ETC Error(handle execption) */
            add_avp_exp_rst( rsp_avplist, DIAMETER_ERROR_SM_DELIVERY_FAILURE );
            break;
    }

    if( rv < 0){
        ux_log( UXL_CRT, "udia_msg_make_respond() fail.err(%d)", rv);
    } else {
        diamsg->stackmsg = rsp_msg;
        rv = send_msg_to_dia( worker, diamsg );
        if( rv < UX_SUCCESS ) {
            ux_log(UXL_CRT, "send_diamsg_to_peer() fail.(rv:%d)", rv);
            rv = DIAIB_RESULT_NOTOK;
        } else {
            ux_log( UXL_DEBUG, "Send Fail ALA success.CC_Code(%d)", result_code );
            rv = DIAIB_RESULT_OK;
        }
    }

	inc_tfr_send_nack(smscAddr->min);

    /********* Unref diamsg ************/
    if(rsp_msg) udia_msg_unref(rsp_msg);
    /***********************************/

    return rv;
}
