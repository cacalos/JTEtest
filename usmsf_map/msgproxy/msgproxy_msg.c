#include "smsf.h"
#include <errno.h>

int convert_to_smsfif_msg(smsf_msg_t *smsf_msg, smsf_send_t *smsf_sendmsg, int *len)
{
	if(smsf_msg == NULL)
		return IXERR;

	smsf_sendmsg->type = smsf_msg->msg_type;
//	*len = sizeof(smsf_sendmsg->type);

	if(smsf_sendmsg->type != MO_RESP)
	{
		ux_log(UXL_CRT, "Invalid Message Type from RecvMessage(SIGMO)");
		return IXERR;
	}

	smsf_sendmsg->causeCode = smsf_msg->causeCode;
//	*len += sizeof(smsf_sendmsg->causeCode);

	smsf_sendmsg->supi_len = strlen(smsf_msg->supi);
	if(smsf_sendmsg->supi_len > COMMON_LEN || smsf_sendmsg->supi_len <= 0 ) {

		ux_log( UXL_INFO, "Invalid SUPI Length SupiLen[%d]", smsf_sendmsg->supi_len);
		return IXERR;
	}

	memcpy(smsf_sendmsg->supi, &smsf_msg->supi, smsf_sendmsg->supi_len);
//	*len += sizeof(smsf_sendmsg->supi_len) + smsf_sendmsg->supi_len;

	smsf_sendmsg->gpsiLen = strlen(smsf_msg->gpsi);
	if(smsf_sendmsg->gpsiLen > COMMON_LEN || smsf_sendmsg->gpsiLen <= 0 ) {
		ux_log( UXL_INFO, "Invalid GPSI Length GpsiLen[%d]", smsf_sendmsg->gpsiLen);
		return IXERR;
	}

	memcpy(smsf_sendmsg->gpsi, &smsf_msg->gpsi, smsf_sendmsg->gpsiLen);
//	*len += sizeof(smsf_sendmsg->gpsiLen) + smsf_sendmsg->gpsiLen;

	smsf_sendmsg->contentDataLen = smsf_msg->data_len;
	if(smsf_sendmsg->contentDataLen != 0) {
		if(smsf_sendmsg->contentDataLen > RP_DATA_LEN || smsf_sendmsg->contentDataLen <= 0 ) {
			ux_log( UXL_INFO, "Invalid RPDATA Length RpdataLen[%d]", smsf_sendmsg->contentDataLen);
			return IXERR;
		}

		memcpy(smsf_sendmsg->contentData, &smsf_msg->data, smsf_sendmsg->contentDataLen);
//		*len += sizeof(smsf_sendmsg->contentDataLen) + smsf_sendmsg->contentDataLen;
	}

//	smsf_sendmsg->total_len = *len;

	return IXOK;
}

int convert_to_smsfif_msg_mt(smsf_msg_t *smsf_msg, smsf_sendmt_t *smsf_sendmsg, int *len)
{
	if(smsf_msg == NULL)
		return IXERR;

	smsf_sendmsg->type = smsf_msg->msg_type;
	*len = sizeof(smsf_sendmsg->type);

	if(smsf_sendmsg->type != MT_MSG)
	{
		ux_log(UXL_CRT, "Invalid Message Type from RecvMessage(SIGOUT)");
		return IXERR;
	}

	smsf_sendmsg->causeCode = smsf_msg->causeCode;
	*len += sizeof(smsf_sendmsg->causeCode);

	smsf_sendmsg->supi_len = strlen(smsf_msg->supi);	
	if(smsf_sendmsg->supi_len > COMMON_LEN || smsf_sendmsg->supi_len <= 0 ) {

		ux_log( UXL_INFO, "Invalid SUPI Length SupiLen[%d]", smsf_sendmsg->supi_len);
		return IXERR;
	}
	memcpy(smsf_sendmsg->supi, &smsf_msg->supi, smsf_sendmsg->supi_len);
	*len += sizeof(smsf_sendmsg->supi_len) + smsf_sendmsg->supi_len;

	smsf_sendmsg->mmsflag = smsf_msg->isMMS;
	*len += sizeof(smsf_sendmsg->mmsflag);

	smsf_sendmsg->diag_id_len = strlen(smsf_msg->diag_id);
	memcpy(smsf_sendmsg->diag_id, &smsf_msg->diag_id, smsf_sendmsg->diag_id_len);
	*len += sizeof(smsf_sendmsg->diag_id_len) + smsf_sendmsg->diag_id_len; 
	
	smsf_sendmsg->acn = smsf_msg->acn;
	*len += sizeof(smsf_msg->acn);

	smsf_sendmsg->prov_id = smsf_msg->prov_id;
	*len += sizeof(smsf_sendmsg->prov_id);

	smsf_sendmsg->inv_id = smsf_msg->inv_id;
	*len += sizeof(smsf_sendmsg->inv_id);

	smsf_sendmsg->hop_id = smsf_msg->hop_id;
	*len += sizeof(smsf_sendmsg->hop_id);

	smsf_sendmsg->end_id = smsf_msg->end_id;
	*len += sizeof(smsf_sendmsg->end_id);

	smsf_sendmsg->peer_id = smsf_msg->peer_id;
	*len += sizeof(smsf_sendmsg->peer_id);

	smsf_sendmsg->orig_realm_len = strlen(smsf_msg->orig_realm);
	memcpy(smsf_sendmsg->orig_realm, &smsf_msg->orig_realm, smsf_sendmsg->orig_realm_len);
	*len += sizeof(smsf_sendmsg->orig_realm_len) + smsf_sendmsg->orig_realm_len;

	smsf_sendmsg->orig_host_len = strlen(smsf_msg->orig_host);
	memcpy(smsf_sendmsg->orig_host, &smsf_msg->orig_host, smsf_sendmsg->orig_host_len);
	*len += sizeof(smsf_sendmsg->orig_host_len) + smsf_sendmsg->orig_host_len;

	smsf_sendmsg->smsc_node_len = strlen(smsf_msg->smsc_node);
	memcpy(smsf_sendmsg->smsc_node, &smsf_msg->smsc_node, smsf_sendmsg->smsc_node_len);
	*len += sizeof(smsf_sendmsg->smsc_node_len) + smsf_sendmsg->smsc_node_len;

	smsf_sendmsg->session_id_len = strlen(smsf_msg->session_id);
	memcpy(smsf_sendmsg->session_id, &smsf_msg->session_id, smsf_sendmsg->session_id_len);
	*len += sizeof(smsf_sendmsg->session_id_len) + smsf_sendmsg->session_id_len;


	smsf_sendmsg->contentDataLen = smsf_msg->data_len;
	if(smsf_sendmsg->contentDataLen != 0) {
		if(smsf_sendmsg->contentDataLen > RP_DATA_LEN || smsf_sendmsg->contentDataLen <= 0 ) {
			ux_log( UXL_INFO, "Invalid RPDATA Length RpdataLen[%d]", smsf_sendmsg->contentDataLen);
			return IXERR;
		}
		memcpy(smsf_sendmsg->contentData, &smsf_msg->data, smsf_sendmsg->contentDataLen);
		*len += sizeof(smsf_sendmsg->contentDataLen) + smsf_sendmsg->contentDataLen;
	}
	smsf_sendmsg->total_len = *len;

	return IXOK;
}



int handle_interface_resp_message(uxc_worker_t *worker, uxc_msg_t *msg)
{
	int                 ret, msg_size, len;
	uxc_ipcmsg_t        *rcv_msg = (uxc_ipcmsg_t *)msg->data;
	smsf_msg_t          *smsf_msg;
	smsf_t          	*smsf = smsf_instance();
	smsf_send_t			smsf_sendmsg;
	ux_channel_t 		*channel;
	upa_peerkey_t 		peerkey;
	char 				rpack[1024];
	int 				remain;

	smsf_msg = (smsf_msg_t *)rcv_msg->data;

	if(smsf->mode == SIGTRAN_MODE) { 
		ux_log(UXL_INFO, "[Thread %d] handle_sigmo_resp_message(), msgtype[%u], causecode[%d], supi[%s], gpsi[%s], MMS[%d], data_len[%d]",
				uxc_worker_get_thread_id(worker), smsf_msg->msg_type, 
				smsf_msg->causeCode, 
				smsf_msg->supi,
				smsf_msg->gpsi,
				smsf_msg->isMMS,
				smsf_msg->data_len);

	} else if(smsf->mode == DIAMETER_MODE) {
		ux_log(UXL_INFO, "[Thread %d] handle_Diaib_resp_message(), msgtype[%u], causecode[%d], supi[%s], gpsi[%s], MMS[%d], data_len[%d]",
				uxc_worker_get_thread_id(worker), smsf_msg->msg_type, 
				smsf_msg->causeCode, 
				smsf_msg->supi,
				smsf_msg->gpsi,
				smsf_msg->isMMS,
				smsf_msg->data_len);
	} else {
		ux_log(UXL_INFO, "[Thread %d] Not Sigtran and Diaib", uxc_worker_get_thread_id(worker));

	}
	memset(rpack, 0x00, sizeof(rpack));

	ret = MakeStrHexa(rpack, smsf_msg->data, smsf_msg->data_len, &remain, 100, 100);
	if(ret != IXOK) {
		ux_log(UXL_INFO, "[Thread %d], Converting Error MT data from %s", 
				uxc_worker_get_thread_id(worker), smsf->mode == SIGTRAN_MODE ? "SIGMO" : "DIAIB");
	} else {
		ux_log(UXL_INFO, "[Thread %d], Recv MO-ACK from %s [%s]", 
				uxc_worker_get_thread_id(worker), rpack, smsf->mode == SIGTRAN_MODE ? "SIGMO" : "DIAIB");	
	}


	peerkey.chnl_idx = 0; // configuration 첫번째 채널
	channel = upa_tcp_get_channel( smsf->patcp, peerkey.chnl_idx);
	peerkey.peer_key = channel->lpeerkey-1;

	ret = convert_to_smsfif_msg(smsf_msg, &smsf_sendmsg, &len);
	if(ret != IXOK)
		return IXERR;

	inc_msgproxy_stat(smsf_sendmsg.type);

	msg_size = sizeof(smsf_send_t);
	smsf_sendmsg.total_len = msg_size;

	ret = upa_tcp_send2(smsf->patcp, &peerkey, &smsf_sendmsg, msg_size, 1);
	if(ret < UX_SUCCESS)
	{
		ux_log( UXL_CRT, "[Thread %d] upa_tcp_send2() fail, [%d], Type[%d], CC[%d], SUPI[%s], GPSI[%s], DataLen[%d]",
				uxc_worker_get_thread_id(worker),
				msg_size,
				smsf_sendmsg.type, 
				smsf_sendmsg.causeCode,
				smsf_sendmsg.supi,
				smsf_sendmsg.gpsi,
				smsf_sendmsg.contentDataLen);

		return IXERR;
	}
	else
	{
		ux_log( UXL_INFO, "[Thread %d] upa_tcp_send2() success, TotalLen[%d], Type[%d], CC[%d], SUPI[%s], GPSI[%s], DataLen[%d]",
				uxc_worker_get_thread_id(worker), 
				msg_size,
				smsf_sendmsg.type, 
				smsf_sendmsg.causeCode,
				smsf_sendmsg.supi,
				smsf_sendmsg.gpsi,
				smsf_sendmsg.contentDataLen);
	}

	return IXOK;
}

int handle_interface_message(uxc_worker_t *worker, uxc_msg_t *msg)
{
	int                 ret, msg_size, len;
	uxc_ipcmsg_t        *rcv_msg = (uxc_ipcmsg_t *)msg->data;
	smsf_msg_t          *smsf_msg;
	smsf_t          	*smsf = smsf_instance();
	smsf_sendmt_t		smsf_sendmsg;
	ux_channel_t 		*channel;
	upa_peerkey_t 		peerkey;
	char 				rpdata[1024];
	int                 remain;

	smsf_msg = (smsf_msg_t *)rcv_msg->data;

	ux_log(UXL_INFO, "[Thread %d] handle_mt_message(), msgtype[%u], causecode[%d], supi[%s],  gpsi[%s], MMS[%d], data_len[%d], diag_id[%s], acn[%d], prov_id[%d], inv_id[%d]",
			uxc_worker_get_thread_id(worker), smsf_msg->msg_type, 
			smsf_msg->causeCode, 
			smsf_msg->supi,
			smsf_msg->gpsi,
			smsf_msg->isMMS,
			smsf_msg->data_len,
			smsf_msg->diag_id,
			smsf_msg->acn,
			smsf_msg->prov_id,
			smsf_msg->inv_id);

	memset(rpdata, 0x00, sizeof(rpdata));

	ret = MakeStrHexa(rpdata, smsf_msg->data, smsf_msg->data_len, &remain, 100, 100);
	if(ret != IXOK) {
		ux_log(UXL_INFO, "[Thread %d], Converting Error MT data from %s", 
				uxc_worker_get_thread_id(worker), smsf->mode == SIGTRAN_MODE ? "SIGTRAN" : "DIAMETER");
	} else {
		ux_log(UXL_INFO, "[Thread %d], Recv MT data from %s [%s]", 
				uxc_worker_get_thread_id(worker), smsf->mode == SIGTRAN_MODE ? "SIGTRAN" : "DIAMETER", rpdata);	
	}
	peerkey.chnl_idx = 0; // configuration 첫번째 채널
	channel = upa_tcp_get_channel(smsf->patcp, peerkey.chnl_idx);
	peerkey.peer_key = channel->lpeerkey-1;

	memset(&smsf_sendmsg, 0x00, sizeof(smsf_sendmt_t));
	ret = convert_to_smsfif_msg_mt(smsf_msg, &smsf_sendmsg, &len);
	if(ret != IXOK)
		return IXERR;

	msg_size = sizeof(smsf_sendmt_t);
	smsf_sendmsg.total_len = msg_size;	
	inc_msgproxy_stat(smsf_sendmsg.type);

	ret = upa_tcp_send2(smsf->patcp, &peerkey, &smsf_sendmsg, msg_size, 1);
	
	if(ret < UX_SUCCESS)
	{
		ux_log( UXL_CRT, "[Thread %d] upa_tcp_send2() fail, Type[%d], CC[%d], SUPI[%s]",
				uxc_worker_get_thread_id(worker), 
				smsf_sendmsg.type, 
				smsf_sendmsg.causeCode,
				smsf_sendmsg.supi);
	}
	else
	{
		ux_log(UXL_INFO, "[Thread %d] upa_tcp_send2() success, Size[%d], Type[%d], CC[%d], SUPI[%s]",
				uxc_worker_get_thread_id(worker),
				msg_size,
				smsf_sendmsg.type, 
				smsf_sendmsg.causeCode, 
				smsf_sendmsg.supi);
	}
	return IXOK;
}

int send_to_sigtran(uxc_worker_t *worker, smsf_msg_t *msg)
{
	int 			msgqid; 
	smsf_t          *smsf = smsf_instance();

	if(msg->msg_type == MO_MSG) {
		msgqid = smsf->ifQid[SIGIB_IN_QID];
	}
	else {
		msgqid = smsf->ifQid[SIGIB_OUT_QID];
	} 

	send_msg_print(msg);

	if(msgsnd(msgqid, msg, sizeof(smsf_msg_t), IPC_NOWAIT) == -1) { 
		perror("Error");
		ux_log( UXL_CRT, "[Thread %d] Send message failed.(to %s)", 
				uxc_worker_get_thread_id(worker), msg->msg_type == MO_MSG ? "SIGMO" : "SIGMT"); 
		return IXERR;
	} else {
		ux_log( UXL_INFO, "[Thread %d] Send message success.(to %s)", 
				uxc_worker_get_thread_id(worker), msg->msg_type == MO_MSG ? "SIGMO" : "SIGMT");
	}

	return IXOK;
}

int send_to_diameter(uxc_worker_t *worker, smsf_msg_t *msg)
{
	int 			msgqid;
	uxc_ipcmsg_t    snd_msg;
	smsf_t          *smsf = smsf_instance();
	int ret;

	snd_msg.mtype = MTYPE_DIAMETER_MESSAGE_TYPE;
	snd_msg.header.cmdId = -1;
	snd_msg.header.msgId = MTYPE_DIAMETER_MESSAGE_TYPE;
	snd_msg.header.srcQid = smsf->ifQid[SMSF_QID];
	snd_msg.header.dstQid = smsf->ifQid[DIAIB_QID];
	snd_msg.header.length = sizeof(smsf_msg_t);

	memcpy(snd_msg.data, msg, sizeof(smsf_msg_t));

	send_msg_print(msg);

	ret = uxc_ipcmsg_send( &snd_msg, sizeof(smsf_msg_t));
	if(ret != eUXC_SUCCESS) {
		ux_log( UXL_CRT, "[Thread %d] Send message failed.(to Diameter)",
				uxc_worker_get_thread_id(worker));
	}
	else {
		ux_log( UXL_INFO, "[Thread %d] Send message success.(to Diameter)", 
				uxc_worker_get_thread_id(worker));

	}

	return IXOK;
}


int convert_interface_msg(smsf_msg_t *msg, smsf_recv_t *rcv_msg)
{

	if (rcv_msg == NULL) {
		ux_log( UXL_INFO, "Recv Data is NULL in convert_interface_msg");
		return IXERR;
	}

	memset(msg, 0x00, sizeof(smsf_msg_t));
	if(rcv_msg->type == ERR_TYPE) {
		msg->msg_type = MT_RESP;
	}
	else {
		msg->msg_type = rcv_msg->type;
	}

	if(!strcmp(rcv_msg->MsgType, "Failure-Notify")) {
			if(!strcmp(rcv_msg->ResultCode, "ATTEMPTING_TO_REACH_UE")) 
				msg->causeCode = 800;	
			else if(!strcmp(rcv_msg->ResultCode, "N1_N2_TRANSFER_INITIATED")) 
				msg->causeCode = 801;
			else if(!strcmp(rcv_msg->ResultCode, "WAITING_FOR_ASYNCHRONOUS_TRANSFER")) 
				msg->causeCode = 802;
			else if(!strcmp(rcv_msg->ResultCode, "UE_NOT_RESPONDING")) 
				msg->causeCode = 803;
			else if(!strcmp(rcv_msg->ResultCode, "N1_MSG_NOT_TRANSFERRED")) 
				msg->causeCode = 804;
			else if(!strcmp(rcv_msg->ResultCode, "UE_NOT_REACHABLE_FOR_SESSION")) 
				msg->causeCode = 805;
			else 
				msg->causeCode = rcv_msg->causecode;
	}  else {
		msg->causeCode = rcv_msg->causecode;
	}

//	msg->causeCode = rcv_msg->causecode;
	memcpy(msg->supi, rcv_msg->supi, strlen(rcv_msg->supi));
	
	if(msg->msg_type == MO_MSG) {
		memcpy(msg->gpsi, rcv_msg->gpsi, strlen(rcv_msg->gpsi));
	}

	msg->isMMS = rcv_msg->mmsflag;

	msg->data_len = rcv_msg->contentDataLen;
	memcpy(msg->data, rcv_msg->contentData, msg->data_len);

	/********************* SIG INFO *********************/
	msg->my_pc = rcv_msg->Commoninfo.SmsfPointCode;
	msg->smsc_pc = rcv_msg->InterFinfo.Pc;
	msg->my_ssn = rcv_msg->Commoninfo.SmsfSsn;
	msg->smsc_ssn = rcv_msg->InterFinfo.Ssn;
	memcpy(msg->my_isdn, rcv_msg->Commoninfo.SmsfMapAddress, rcv_msg->Commoninfo.SmsfMapAddressLen);
	memcpy(msg->smsc_isdn, rcv_msg->InterFinfo.Isdn, rcv_msg->InterFinfo.IsdnLen);
	memcpy(msg->dest_host, rcv_msg->InterFinfo.DestHost, rcv_msg->InterFinfo.DestHostLen);
	memcpy(msg->dest_realm, rcv_msg->InterFinfo.DestRealm, rcv_msg->InterFinfo.DestRealmLen);
	msg->routing_type = rcv_msg->InterFinfo.Type;
/*
	// FAILURE NOTI CASE
	memcpy(msg->MsgType, rcv_msg->MsgType, rcv_msg->MsgTypeLen);
	memcpy(msg->ResultCode, rcv_msg->ResultCode, rcv_msg->ResultCodeLen);
*/
	// Mt resp data
	memcpy(msg->diag_id, rcv_msg->diag_id, rcv_msg->diag_id_len);
	msg->acn = rcv_msg->acn;
	msg->prov_id = rcv_msg->prov_id;
	msg->inv_id = rcv_msg->inv_id;
	msg->hop_id = rcv_msg->hop_id;
	msg->end_id = rcv_msg->end_id;
	msg->peer_id = rcv_msg->peer_id;

	memcpy(msg->orig_realm, rcv_msg->orig_realm, rcv_msg->orig_realm_len);
	memcpy(msg->orig_host, rcv_msg->orig_host, rcv_msg->orig_host_len);
	memcpy(msg->smsc_node, rcv_msg->smsc_node, rcv_msg->smsc_node_len);
	memcpy(msg->session_id, rcv_msg->session_id, rcv_msg->session_id_len);

	return IXOK;
}

int recv_msg_decodef(smsf_tcp_msg_t *tcp_msg, smsf_recv_t *rcv_msg)
{
	int offset = 0;

	if(tcp_msg == NULL)
	{
		ux_log( UXL_INFO, "rcv_msg_decodef is NULL");
		return IXERR;

	}
	memset(rcv_msg, 0x00, sizeof(smsf_recv_t));

	rcv_msg->total_len = tcp_msg->header.body_len;
	rcv_msg->type = tcp_msg->data[offset];
	offset++;

	if(rcv_msg->type == ERR_TYPE ) {
		memcpy(&rcv_msg->causecode, &tcp_msg->data[offset], sizeof(int));
		offset += sizeof(int);
	}

	rcv_msg->supi_len = tcp_msg->data[offset]; //supi_Len
	offset++;
	if(rcv_msg->supi_len > COMMON_LEN || rcv_msg->supi_len <= 0 ) {
		ux_log( UXL_INFO, "Invalid SUPI Length SupiLen[%d]", rcv_msg->supi_len);
		return IXERR;
	}

	memcpy(rcv_msg->supi, &tcp_msg->data[offset], rcv_msg->supi_len); //supivalue
	offset = offset + rcv_msg->supi_len; // shift supi

	if(rcv_msg->type == MO_MSG ) {

		rcv_msg->gpsiLen = tcp_msg->data[offset]; //gpsi len
		offset++;
		if(rcv_msg->gpsiLen > COMMON_LEN || rcv_msg->gpsiLen <= 0 ) {
			ux_log( UXL_INFO, "Invalid GPSI Length GpsiLen[%d]", rcv_msg->gpsiLen);
			return IXERR;
		}

		memcpy(rcv_msg->gpsi, &tcp_msg->data[offset], rcv_msg->gpsiLen); //gpsi
		offset = offset + rcv_msg->gpsiLen; //shift gpsi

	} else {

		if(rcv_msg->type == ERR_TYPE) 
		{
		}
		else
		{
			rcv_msg->mmsLen = tcp_msg->data[offset];
			offset++;
			rcv_msg->mmsflag = tcp_msg->data[offset];
			offset++;
		}
	}

	if(rcv_msg->type == MT_RESP || rcv_msg->type == ERR_TYPE) {

		memcpy(&rcv_msg->MsgTypeLen, &tcp_msg->data[offset], sizeof(char));
		offset = offset + sizeof(char);
		memcpy(rcv_msg->MsgType, &tcp_msg->data[offset], rcv_msg->MsgTypeLen);
		offset = offset + rcv_msg->MsgTypeLen;

		memcpy(&rcv_msg->ResultCodeLen, &tcp_msg->data[offset], sizeof(char));
		offset = offset + sizeof(char);
		memcpy(rcv_msg->ResultCode, &tcp_msg->data[offset], rcv_msg->ResultCodeLen);
		offset = offset + rcv_msg->ResultCodeLen;

		// 결국 이부분을 수정해야 하는데...
		// 기존 설계에서.. diameter 부분... 왜 넣은거지????
		// diaib에서는 supi와 msgrefer를 보고 response key를 만든다...
		// 이부분 확인해보자(2020.01.22)
/*
		memcpy(&rcv_msg->diag_id_len, &tcp_msg->data[offset], sizeof(char));
		offset = offset + sizeof(char);
		memcpy(rcv_msg->diag_id, &tcp_msg->data[offset], rcv_msg->diag_id_len);
		offset = offset + rcv_msg->diag_id_len;

		memcpy(&rcv_msg->acn, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int);

		memcpy(&rcv_msg->prov_id, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int);

		memcpy(&rcv_msg->inv_id, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int);

		memcpy(&rcv_msg->hop_id, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int);

		memcpy(&rcv_msg->end_id, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int);

		memcpy(&rcv_msg->peer_id, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int);

		memcpy(&rcv_msg->orig_realm_len, &tcp_msg->data[offset], sizeof(char));
		offset = offset + sizeof(char);
		memcpy(&rcv_msg->orig_realm, &tcp_msg->data[offset], rcv_msg->orig_realm_len);
		offset = offset + rcv_msg->orig_realm_len;

		memcpy(&rcv_msg->orig_host_len, &tcp_msg->data[offset], sizeof(char));
		offset = offset + sizeof(char);
		memcpy(rcv_msg->orig_host, &tcp_msg->data[offset], rcv_msg->orig_host_len);
		offset = offset + rcv_msg->orig_host_len;

		memcpy(&rcv_msg->smsc_node_len, &tcp_msg->data[offset], sizeof(char));
		offset = offset + sizeof(char);
		memcpy(rcv_msg->smsc_node, &tcp_msg->data[offset], rcv_msg->smsc_node_len);
		offset = offset + rcv_msg->smsc_node_len;

		memcpy(&rcv_msg->session_id_len, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int);
		memcpy(rcv_msg->session_id, &tcp_msg->data[offset], rcv_msg->session_id_len);
		offset = offset + rcv_msg->session_id_len;
*/
	}

	if(rcv_msg->ResultCodeLen > 0 ) {
			ux_log( UXL_INFO, "FAILURE NOTI SEND CASE");
	} else {
		rcv_msg->contentDataLen = tcp_msg->data[offset]; // RP-DATA Len
		offset++;
		if(rcv_msg->contentDataLen > RP_DATA_LEN || rcv_msg->contentDataLen <= 0 ) {
			ux_log( UXL_INFO, "Invalid RPDATA Length RpdataLen[%d]", rcv_msg->contentDataLen);
			return IXERR;
		} 
		memcpy(rcv_msg->contentData, &tcp_msg->data[offset], rcv_msg->contentDataLen); //RP-DATA
		offset = offset + rcv_msg->contentDataLen;
	}

	/********************* IF INFORMATION ****************************/
	if(rcv_msg->type == MO_MSG ) {
		// Name
		memcpy(&rcv_msg->InterFinfo.NameLen, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int)*2;
		if(rcv_msg->InterFinfo.NameLen > 1) {
			memcpy(rcv_msg->InterFinfo.Name, &tcp_msg->data[offset], rcv_msg->InterFinfo.NameLen);
			offset = offset + rcv_msg->InterFinfo.NameLen;
		}

		// Isdn
		memcpy(&rcv_msg->InterFinfo.IsdnLen, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int)*2;
		if(rcv_msg->InterFinfo.IsdnLen > 0 && rcv_msg->InterFinfo.IsdnLen < 256 ) {
			memcpy(rcv_msg->InterFinfo.Isdn, &tcp_msg->data[offset], rcv_msg->InterFinfo.IsdnLen);
			offset = offset + rcv_msg->InterFinfo.IsdnLen;
		}

		// Pc
		memcpy(&rcv_msg->InterFinfo.PcLen, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int)*2;
		memcpy(&rcv_msg->InterFinfo.Pc, &tcp_msg->data[offset], rcv_msg->InterFinfo.PcLen);
		offset = offset + rcv_msg->InterFinfo.PcLen;

		// SSN
		memcpy(&rcv_msg->InterFinfo.SsnLen, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int)*2;
		memcpy(&rcv_msg->InterFinfo.Ssn, &tcp_msg->data[offset], rcv_msg->InterFinfo.SsnLen);
		offset = offset + rcv_msg->InterFinfo.SsnLen;

		// Type
		memcpy(&rcv_msg->InterFinfo.TypeLen, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int)*2;
		memcpy(&rcv_msg->InterFinfo.Type, &tcp_msg->data[offset], rcv_msg->InterFinfo.TypeLen);
		offset = offset + rcv_msg->InterFinfo.TypeLen;

		//FlowCont
		memcpy(&rcv_msg->InterFinfo.FlowCtrlLen, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int)*2;
		memcpy(&rcv_msg->InterFinfo.FlowCtrl, &tcp_msg->data[offset], rcv_msg->InterFinfo.FlowCtrlLen);
		offset = offset + rcv_msg->InterFinfo.FlowCtrlLen;

		//DestHost
		memcpy(&rcv_msg->InterFinfo.DestHostLen, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int)*2;
		if(rcv_msg->InterFinfo.DestHostLen > 1 && rcv_msg->InterFinfo.DestHostLen < 256) {
			memcpy(rcv_msg->InterFinfo.DestHost, &tcp_msg->data[offset], rcv_msg->InterFinfo.DestHostLen);
			offset = offset + rcv_msg->InterFinfo.DestHostLen;
		}

		//DestRealm
		memcpy(&rcv_msg->InterFinfo.DestRealmLen, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int)*2;
		if(rcv_msg->InterFinfo.DestRealmLen > 1 && rcv_msg->InterFinfo.DestRealmLen < 256) {
			memcpy(rcv_msg->InterFinfo.DestRealm, &tcp_msg->data[offset], rcv_msg->InterFinfo.DestRealmLen);
			offset = offset + rcv_msg->InterFinfo.DestRealmLen;
		}

		//DESC
		memcpy(&rcv_msg->InterFinfo.DescLen, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int)*2;
		if(rcv_msg->InterFinfo.DescLen > 1 && rcv_msg->InterFinfo.DescLen < 256) {
			memcpy(rcv_msg->InterFinfo.Desc, &tcp_msg->data[offset], rcv_msg->InterFinfo.DescLen);
			offset = offset + rcv_msg->InterFinfo.DescLen;
		}

		//PlmnId
		memcpy(&rcv_msg->Commoninfo.PlmnIdLen, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int)*2;
		memcpy(&rcv_msg->Commoninfo.PlmnId, &tcp_msg->data[offset], rcv_msg->Commoninfo.PlmnIdLen);
		offset = offset + rcv_msg->Commoninfo.PlmnIdLen;

		//SmsfInstaceId
		memcpy(&rcv_msg->Commoninfo.SmsfInstanceIdLen, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int)*2;
		memcpy(rcv_msg->Commoninfo.SmsfInstanceId, &tcp_msg->data[offset], rcv_msg->Commoninfo.SmsfInstanceIdLen);
		offset = offset + rcv_msg->Commoninfo.SmsfInstanceIdLen; 

		//SmsfMapAddr
		memcpy(&rcv_msg->Commoninfo.SmsfMapAddressLen, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int)*2;
		memcpy(rcv_msg->Commoninfo.SmsfMapAddress, &tcp_msg->data[offset], rcv_msg->Commoninfo.SmsfMapAddressLen);
		offset = offset + rcv_msg->Commoninfo.SmsfMapAddressLen;

		//SmsfDiaAddr
		memcpy(&rcv_msg->Commoninfo.SmsfDiameterAddressLen, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int)*2;
		memcpy(rcv_msg->Commoninfo.SmsfDiameterAddress, &tcp_msg->data[offset], rcv_msg->Commoninfo.SmsfDiameterAddressLen);
		offset = offset + rcv_msg->Commoninfo.SmsfDiameterAddressLen;

		//SmsfPointCode
		memcpy(&rcv_msg->Commoninfo.SmsfPointCodeLen, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int)*2;
		memcpy(&rcv_msg->Commoninfo.SmsfPointCode, &tcp_msg->data[offset], rcv_msg->Commoninfo.SmsfPointCodeLen);
		offset = offset + rcv_msg->Commoninfo.SmsfPointCodeLen;

		//SmsfSsn
		memcpy(&rcv_msg->Commoninfo.SmsfSsnLen, &tcp_msg->data[offset], sizeof(int));
		offset = offset + sizeof(int)*2;
		memcpy(&rcv_msg->Commoninfo.SmsfSsn, &tcp_msg->data[offset], rcv_msg->Commoninfo.SmsfSsnLen);
		offset = offset + rcv_msg->Commoninfo.SmsfSsnLen;
	}

	

	return IXOK;
}

void send_msg_print(smsf_msg_t * msg)
{
	int remain;
	char rpdata[1024];

	if(msg == NULL) {
		ux_log( UXL_CRT,"Invalid Print Format");
		return;
	}
	
	ux_log( UXL_INFO, "Recv-Message From Service Pod");
	ux_log( UXL_INFO, "msg_type : %d", msg->msg_type);
	ux_log( UXL_INFO, "causecode : %d", msg->causeCode);
	ux_log( UXL_INFO, "supi: %s", msg->supi);
	ux_log( UXL_INFO, "gpsi: %s", msg->gpsi);
	ux_log( UXL_INFO, "isMMS: %d", msg->isMMS);
	ux_log( UXL_INFO, "data_len: %d", msg->data_len);
	ux_log( UXL_INFO, "diag_id: %s", msg->diag_id);
	ux_log( UXL_INFO, "acn: %d", msg->acn);
	ux_log( UXL_INFO, "prov_id: %d", msg->prov_id);
	ux_log( UXL_INFO, "inv_id: %d", msg->inv_id);

	memset(rpdata, 0x00, sizeof(rpdata));
	MakeStrHexa(rpdata, msg->data, msg->data_len, &remain, 100, 100);
	ux_log(UXL_INFO, "DATA [%s]", rpdata);	

	return;
}


