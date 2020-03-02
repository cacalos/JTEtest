#include "handle_msg.h"
#include "handle_tfr_resp_msg.h"
//#include "handle_resp_msg.h"
//#include "handle_req_msg.h"

int handle_rcv_smsc_msg( uxc_action_t *action, uxc_worker_t* worker, uxc_msg_t *msg)
{
	int				is_req, rv;
	uint32_t        cmd_code;
	upa_diamsg_t*	rcv_diamsg;

	rcv_diamsg = (upa_diamsg_t *) msg->data;
	cmd_code = udia_msg_get_code(rcv_diamsg->stackmsg);

  	ux_log( UXL_INFO, "[Thread %d] Processing handle_rcv_dia_msg", uxc_worker_get_thread_id(worker) );

	/* Check Diameter Command Type */
	is_req = udia_msg_is_request(rcv_diamsg->stackmsg);
	if( is_req ){
		if(cmd_code == UDIA_CMD_TFR)
		{
			rv = handle_recv_tfr(worker, msg);
			ux_log(UXL_MAJ, "[Thread %d] handle_recv_tfr() fail, rv=%d", uxc_worker_get_thread_id(worker), rv);
		}
		else
		{
			ux_log(UXL_CRT, "Diameter REQUEST command is not allowed.(cmd_code:%d)",
					udia_msg_get_code(rcv_diamsg->stackmsg));
		}
	} 
	else 
	{
		handle_dia_resp_msg(worker, msg);
	}

	return DIAIB_RESULT_OK;
}

int handle_rcv_smsf_msg(uxc_action_t *action, uxc_worker_t* worker, uxc_msg_t *msg)
{
//	int				is_resp;
	uxc_ipcmsg_t 	*rcv_msg = (uxc_ipcmsg_t *)msg->data;
	smsf_msg_t      *smsf_msg = (smsf_msg_t *) rcv_msg->data;
//	upa_diamsg_t    *pa_diamsg = NULL;
//	udia_msg_t      *stackmsg;

  	ux_log( UXL_DEBUG, "[Thread %d] Processing handle_rcv_eng_msg", uxc_worker_get_thread_id(worker) );

	if(smsf_msg->msg_type == MO_MSG)
	{
		ux_log( UXL_INFO, "[Thread %d] Recv MO Msg, supi[%s], gpsi[%s]", uxc_worker_get_thread_id(worker), smsf_msg->supi, smsf_msg->gpsi);
		handle_ofr_msg(worker, smsf_msg);
	}
	else if(smsf_msg->msg_type == MT_RESP)
	{
		ux_log( UXL_INFO, "[Thread %d] Recv MT Resp Msg, supi[%s], gpsi[%s]", uxc_worker_get_thread_id(worker), smsf_msg->supi, smsf_msg->gpsi);
		handle_tfr_resp_msg(worker, smsf_msg);
	}
	else
	{
		ux_log( UXL_CRT, "[Thread %d] Recv Unknown Msg from msgproxy!(type:%d)", uxc_worker_get_thread_id(worker), smsf_msg->msg_type );
	}

	return DIAIB_RESULT_OK;
}

/* Send pa_diamsg to adif */
int send_msg_to_dia( uxc_worker_t *worker, upa_diamsg_t *pa_diamsg )
{
	upa_dia_t*      pa_dia;

	pa_dia = diaib_get_padia();

	/* select Channel */
	/* ADIF 이중화를 위해 메시지를 2개의 채널로 분배할 경우 이 부분 수정 */
	/* uxcutor의 secondary IP 사용이 가능하다면 필요는 없을듯 */
	pa_diamsg->channel = upa_dia_get_channel_n(pa_dia, DIAIB_PA_DIAMETER_CHNL);
	if( pa_diamsg->channel == NULL ){
		ux_log( UXL_CRT, "upa_dia_get_channel_n() fail. Can't get channel(%s)", DIAIB_PA_DIAMETER_CHNL );
		return DIAIB_RESULT_NOTOK;
	}

	/* trace 2중 출력을 막기 위해 send하기 전에 trace를 off해준다. */
	set_trace_flag( NULL, 0 );
	return send_diamsg_to_peer( pa_dia, pa_diamsg );
}

int handle_snd_smsf_msg( smsf_msg_t *snd_msg)
{
    int                 rv;
    uxc_ipcmsg_t        ipcmsg;

    memset(&ipcmsg, 0, sizeof(uxc_ipcmsg_t));

    ipcmsg.mtype = UXC_MTYPE_SLEE;
    ipcmsg.header.cmdId = -1;
    ipcmsg.header.msgId = 100;
    ipcmsg.header.srcQid = get_diaib_src_qid();
    ipcmsg.header.dstQid = get_diaib_dst_qid();

    memcpy(ipcmsg.data, snd_msg, sizeof(smsf_msg_t));

    rv = uxc_ipcmsg_send(&ipcmsg, sizeof(smsf_msg_t));
    if(rv < eUXC_SUCCESS)
    {
        ux_log( UXL_CRT, "Send message failed.(to fepproxy), rv=%d", rv);
        return DIAIB_RESULT_ERROR;
    }

    ux_log( UXL_INFO, "Send message success.(to fepproxy)");
    return DIAIB_RESULT_OK;
}
