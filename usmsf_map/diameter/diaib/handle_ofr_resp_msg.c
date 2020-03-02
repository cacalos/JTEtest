#include <iXTrace.h>

#include "handle_ofr_resp_msg.h"
#include "dia_resp_ofr.h"
#include "stat.h"

int handle_dia_resp_msg(uxc_worker_t* worker, uxc_msg_t *msg)
{
	int					rv, thread_id, err_code;
	char				resp_key[DIAIB_RESP_KEY_MAX_LEN];

	upa_diamsg_t		*pa_diamsg; 
	diaib_ofr_respQ_t	*resp_msg;
	smsf_msg_t          mo_resp;

	thread_id = uxc_worker_get_thread_id(worker);
	pa_diamsg = (upa_diamsg_t *) msg->data;

	memset(&mo_resp, 0, sizeof(smsf_msg_t));

	ux_log(UXL_INFO, "[Thread %d] Recv RESP Message, cmd_code[%d]", thread_id, udia_msg_get_code(pa_diamsg->stackmsg));

	/* Get response msg Key from Session-Id AVP */
	rv = get_ofr_msg_resQ_key(resp_key, pa_diamsg->stackmsg);
	if( rv != DIAIB_RESULT_OK ){
		ux_log( UXL_CRT, "[Thread %d] Get key of response msg FAIL", thread_id );
		return DIAIB_RESULT_NOTOK;
	}

	/* Get response msg from woker_data */
	resp_msg = (diaib_ofr_respQ_t *) get_ofr_resp_msg( worker, resp_key );
	if( resp_msg == NULL ){
		ux_log( UXL_CRT, "[Thread %d] Get response msg(key[%s]) FAIL, cmd_cod[%d]", 
				thread_id, resp_key, udia_msg_get_code(pa_diamsg->stackmsg));
		return DIAIB_RESULT_NOTOK;
	} else {
		// response timer를 취소 한다. by comus 2015/06/08
		canc_diaib_ofr_resp_timer(worker, resp_msg);
		ux_log( UXL_INFO, "[Thread %d] Get response msg(key[%s]) SUCCESS, imsi[%s]", thread_id, resp_key, resp_msg->imsi.min);
	}

	rv = conv_ofa_to_resp( pa_diamsg->stackmsg, resp_msg, &mo_resp, &err_code );
	if( rv != DIAIB_RESULT_OK ){
		ux_log( UXL_MAJ, "[Thread %d] Convert OFA into eng_response msg FAIL(err:%d)", thread_id, rv);
		return DIAIB_RESULT_NOTOK;
	}else{
		ux_log( UXL_INFO, "[Thread %d] Convert OFA into eng_response msg SUCCESS", thread_id );
	}

	if(err_code > 0) {
		inc_ofr_resp_nack(resp_msg->dest_node.isdn);
	} else {
		inc_ofr_resp_ack(resp_msg->dest_node.isdn);
	}

	/* Set Trace */
	set_addr_mintrace_flag(NULL, &resp_msg->orig, &resp_msg->imsi);
	print_rcv_call_trace(pa_diamsg->stackmsg, &resp_msg->orig, &resp_msg->imsi, err_code);
	dia_msg_trc( worker, pa_diamsg->stackmsg );

	rv = send_resp_to_ofa( &mo_resp );
	if(rv != DIAIB_RESULT_OK) {
		ux_log(UXL_CRT, "[Thread %d] Send Fail OFA, imsi[%s]", thread_id, resp_msg->imsi.min)
	}
	else {
		ux_log(UXL_INFO, "[Thread %d] Send Succ OFA, imsi[%s]", thread_id, resp_msg->imsi.min)
	}

#if 0
	if(check_error_resp(pa_diamsg->stackmsg) == DIAIB_RESULT_OK)
		inc_diaib_resp_stat(fep_resp, 0);
	else
		inc_diaib_resp_stat(fep_resp, 1);
#endif

	/* Delete response msg */
	rv = del_ofr_resp_msg( worker, resp_msg );
	if( rv != DIAIB_RESULT_OK ){
		ux_log( UXL_MAJ, "[Thread %d] Delete response msg in Worker FAIL(err:%d)", thread_id, rv );
	}else{
		ux_log( UXL_DBG1, "[Thread %d] Delete response msg in Worker SUCCESS", thread_id );
	}

	return DIAIB_RESULT_OK;
}

void set_ofr_succ_resp(diaib_ofr_respQ_t *resp, smsf_msg_t *mo_resp)
{
	int 			rv;

	mo_resp->msg_type = MO_RESP;
	strcpy(mo_resp->supi, resp->imsi.min);
    strcpy(mo_resp->gpsi, resp->orig.min);

	rv = MakeRPDU(MSG_RESP, DIRECTION_N_MS, 0, NULL, NULL, 0, resp->msgRef, &mo_resp->data_len, mo_resp->data);
    if(rv != IXOK)
    {
        ux_log(UXL_CRT, "MakeRPDU(), Make RP-ACK fail, supi[%s], gpsi[%s]", mo_resp->supi, mo_resp->gpsi);
        return;
    }
	ux_log(UXL_INFO, "MakeRPDU(), Make RP-ACK, supi[%s], gpsi[%s]", mo_resp->supi, mo_resp->gpsi);

	return;
}

void set_ofr_fail_resp(diaib_ofr_respQ_t *resp, int error_code, smsf_msg_t *mo_resp)
{
	int 			rv;

	mo_resp->msg_type = MO_RESP;
	strcpy(mo_resp->supi, resp->imsi.min);
    strcpy(mo_resp->gpsi, resp->orig.min);

	rv = MakeRPDU(MSG_RESP, DIRECTION_N_MS, error_code, NULL, NULL, 0, resp->msgRef, &mo_resp->data_len, mo_resp->data);
    if(rv != IXOK)
    {
        ux_log(UXL_CRT, "MakeRPDU(), Make RP-ERROR fail, supi[%s], gpsi[%s]", mo_resp->supi, mo_resp->gpsi);
        return;
    }
	ux_log(UXL_INFO, "MakeURPDU(), Make RP-ERROR, supi[%s], gpsi[%s], CC[%d]", mo_resp->supi, mo_resp->gpsi, error_code);

	return;
}

#if 0
void inc_diaib_resp_stat(fep_msg_t *fepmsg, int err_code)
{
	switch(fepmsg->operation_name)
	{
		case SRR:
			if(err_code)
				inc_srr_send_nack(fepmsg->dest_node.isdn);
			else
				inc_srr_send_ack(fepmsg->dest_node.isdn);
			break;
		case TFR:
			if(err_code)
				inc_tfr_send_nack(fepmsg->dest_node.isdn);
			else
				inc_tfr_send_ack(fepmsg->dest_node.isdn);
			break;
		case DRR:
			if(err_code)
				inc_drr_send_nack(fepmsg->dest_node.isdn);
			else
				inc_drr_send_ack(fepmsg->dest_node.isdn);
			break;
		case RDR:
			if(err_code)
				inc_rdr_send_nack(fepmsg->dest_node.isdn);
			else
				inc_rdr_send_ack(fepmsg->dest_node.isdn);
			break;
		case ACR:
			if(err_code)
				inc_acr_send_nack(fepmsg->dest_node.isdn);
			else
				inc_acr_send_ack(fepmsg->dest_node.isdn);
			break;
		case OFR:
			if(err_code)
				inc_ofr_send_nack(fepmsg->dest_node.isdn);
			else
				inc_ofr_send_ack(fepmsg->dest_node.isdn);
			break;
	}
}
#endif

int check_error_resp(udia_msg_t *dia_msg)
{
	int			cc_code;
	udia_avplist_t      *avplist = udia_msg_get_root(dia_msg);

	cc_code = conv_exp_err_to_cc(avplist);
	if(cc_code != DIAIB_RESULT_OK)
		return DIAIB_RESULT_NOTOK;
	
	cc_code = conv_dia_err_to_cc( udia_msg_get_result_code_avp(dia_msg));
	if(cc_code != DIAIB_RESULT_OK)
		return DIAIB_RESULT_NOTOK;

	return DIAIB_RESULT_OK;
}

int conv_ofa_to_resp(udia_msg_t* dia_msg, diaib_ofr_respQ_t* resp, smsf_msg_t *mo_resp, int *err_code)
{
    int                 cc_code = 0;
    udia_avplist_t      *avplist = udia_msg_get_root(dia_msg);

    if( resp == NULL ){
        ux_log( UXL_CRT, "conv_ofa_to_resp() fail. resp is NULL");
        return DIAIB_RESULT_NOTOK;
    }

    /* Check Experimental-Result of diameter msg */
    cc_code = conv_exp_err_to_cc( avplist );
    if( cc_code != DIAIB_RESULT_OK ){
        ux_log( UXL_INFO, "Convert OFA messge to Result-Code(err_code:%d)", cc_code );
        set_ofr_fail_resp( resp, cc_code, mo_resp );
        return DIAIB_RESULT_OK;
    }

    /* Check Result-Code of diameter msg */
    cc_code = conv_dia_err_to_cc(udia_msg_get_result_code_avp(dia_msg));
    if( cc_code != DIAIB_RESULT_OK ){
        ux_log( UXL_MIN, "AVP Result-Code value is not UDIA_SUCCESS.(cc=%d)", cc_code);
        set_ofr_fail_resp( resp, cc_code, mo_resp );
        return DIAIB_RESULT_OK;
    }

	*err_code = cc_code;

    if( cc_code == DIAIB_RESULT_OK ){
        ux_log( UXL_DEBUG, "OFA response result is SUCESS");
        set_ofr_succ_resp( resp, mo_resp );
        return DIAIB_RESULT_OK;
    }else{
        ux_log( UXL_MIN, "OFA response result is FAIL");
        set_ofr_fail_resp( resp, cc_code, mo_resp );
        return DIAIB_RESULT_OK;
    }
}


int send_resp_to_ofa(smsf_msg_t *mo_resp)
{
    int             rv;

    //print_recv_tfa_trc( &mof_msg->dest, TRC_DIA_RECV_TFA_HEAD, mof_msg );

    /* Insert Mtf Q */
	rv = InsProxyQMsg((void *)mo_resp, MTYPE_RESP);
    if( rv == IXOK ){
        ux_log( UXL_DEBUG, "InsProxyQMsg() success.(supi:%s)", mo_resp->supi);
        return DIAIB_RESULT_OK;
    } else {
        /* Insert response Q Fail */
        ux_log( UXL_MAJ, "InsProxyQMsg() fail.(supi:%s)", mo_resp->supi);
        return DIAIB_RESULT_NOTOK;
    }
}
