#include "smsf.h"

int handle_smsf_msg(uxc_action_t *action, uxc_worker_t *worker, uxc_msg_t *uxcmsg, upa_peerkey_t *peerkey)
{
	int 			rv = -1;
	upa_tcpmsg_t 	*tcpmsg = (upa_tcpmsg_t *) uxcmsg->data;
	smsf_tcp_msg_t	*tcp_msg;
	smsf_msg_t 		msg;
	smsf_recv_t 	rcv_msg;
	smsf_t          *smsf = smsf_instance();

	tcp_msg = (smsf_tcp_msg_t *)tcpmsg->netmsg->buffer;

	if(tcpmsg->evtype == UPA_TCP_EVENT_RECV)
	{
		rv = recv_msg_decodef(tcp_msg, &rcv_msg);
		if( rv != IXOK ) {
			ux_log(UXL_INFO, "Recieve Message Decoding Fail");
			return IXERR;
		}

		inc_msgproxy_stat(rcv_msg.type);

		rv = convert_interface_msg(&msg, &rcv_msg);
		if( rv != IXOK ) {
			ux_log(UXL_INFO, "Convert Decoding Message to Sigib Message Fail");
			return IXERR;
		}

		if(smsf->mode == SIGTRAN_MODE) { 
			rv = send_to_sigtran(worker, &msg);
		}  else if(smsf->mode == DIAMETER_MODE) {
			rv = send_to_diameter(worker, &msg);
		}
		if( rv != IXOK ) {
			return IXERR;
		}
	}
	else 
	{
		ux_log(UXL_INFO, "Undefined Message Type[%d]", tcpmsg->evtype);
		return IXERR;
	}

	return IXOK;
}

int handle_recv_interface_msg(uxc_action_t *action, uxc_worker_t *worker, uxc_msg_t *uxcmsg)
{
	uxc_ipcmsg_t    *rcv_msg = (uxc_ipcmsg_t *)uxcmsg->data;
	int             ret;
	uxc_dbif_t      *dbif ;

	dbif = uxc_ipcmsg_get_dbif( rcv_msg);
	smsf_t          *smsf = smsf_instance();

	ux_log(UXL_DBG1, "SIGIB, MTYPE[%d], HEADER[ %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d]",
			rcv_msg->mtype,
			rcv_msg->header.srcSubSysId,
			rcv_msg->header.srcProcId,
			rcv_msg->header.dstSubSysId,
			rcv_msg->header.dstProcId,
			rcv_msg->header.srcQid,
			rcv_msg->header.dstQid,
			rcv_msg->header.msgId,
			rcv_msg->header.cmdId,
			rcv_msg->header.userData,
			rcv_msg->header.fdIdx,
			rcv_msg->header.length,
			rcv_msg->header.result);

	switch(rcv_msg->mtype)
	{
		case MTYPE_SIGOUT_MESSAGE_TYPE : // mt
			// excute func
			ret = handle_interface_message(worker, uxcmsg);
			break;
		case MTYPE_SIGIN_MESSAGE_TYPE : // mo-resp
			ret = handle_interface_resp_message(worker, uxcmsg);
			break;
		default :
			ux_log(UXL_CRT, "Undefined Message Type = %ld", rcv_msg->mtype);
			break;

	}
	ux_log( UXL_INFO, "[Thread %d] Processing [%s]", uxc_worker_get_thread_id(worker), smsf->mode == SIGTRAN_MODE ? "SIG_MSG" : "DIA_MSG" );

	return ret;
}
