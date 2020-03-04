#include <sys/msg.h>
#include <errno.h>

#include <ua_atif.h>
#include <ua_log.h>
#include <ua_mtype.h>

#include <sigtran_util.h>

/* for linking to libss7.sl */
int tc_errno;
char *tc_error_text[] = { "not used" };


int sendTCUAbort( int cid, int myQid, int atifQid)
{
	AtifSleeMsgType snd;

	initAtifMsg( &snd, myQid, PROTOCOL_GMAP, 0, 0, cid);

	snd.dlgMode = TCAP_DLG_ABORT;
	snd.compMode = TCAP_COMP_NULL;

	if ( msgsnd( atifQid, &snd, ATIF_SLEE_MSG_LEN(snd), IPC_NOWAIT) < 0) {
		uaLog( L_MAJ, "msgsnd failed qid=%d E=%d", atifQid, errno);
		return -1;
	}

    return 0;
}


int initAtifMsg( AtifSleeMsgType *snd, int myQid, 
	int protocol, int opcode, int opclass, int cid)
{
	snd->mtype = MTYPE_SLEE;
	snd->protocol = protocol;

	/* set dest addr */
	memset( snd->dest, 0, MAX_TCAP_ADDR_LEN);
	memset( snd->orig, 0, MAX_TCAP_ADDR_LEN);
	snd->destLen = 0;
	snd->origLen = 0;

	snd->did = -1;
	snd->cid = cid;
	snd->iid = 0;
	snd->opclass = opclass;
	snd->opcode = opcode;
	snd->lidFlag = 0;
	snd->lid = 0;
	snd->lastComponent = 1;
	snd->compSeq = 1;
	snd->srcQid = myQid;

	/* copy parameter */
	snd->paraOffset = 0;
	snd->paraLen = 0;

	/* set dlgCtrl */
	memset( snd->dlgCtrl, 0, DLG_CTRL_MAX_ITEMS);
	snd->dlgType = DLG_TYPE_NUL;

	return 0;
}

/*
	받은 메시지를 가지고 atif에 보낼 메시지를 만든다.
	snd : 보낼 메시지
	rcv : 받은 메시지
	dlg : dialogue mode
	comp : component mode
*/
int makeAtifResponse( 
	AtifSleeMsgType *snd, 	/* OUT : snd msg */
	AtifSleeMsgType *rcv, 	/* IN : rcv msg */
	int myQid,				/* IN : my Q id */
	int paraLen,			/* IN : parameter length */
	unsigned char *para		/* IN : parameter */
	)
{
	snd->protocol = rcv->protocol;
	snd->dlgMode = 0;
	snd->compMode = 0;
	snd->endType = TCAP_END_BASIC;

	/* set dest addr */
	snd->destLen = rcv->origLen;
	memcpy( snd->dest, rcv->orig, rcv->origLen);

	snd->origLen = rcv->destLen;
	memcpy( snd->orig, rcv->dest, rcv->destLen);

	snd->did = rcv->did;
	snd->cid = rcv->cid;
	snd->iid = rcv->iid;
	snd->opclass = rcv->opclass;
	snd->opcode = rcv->opcode;
	snd->lidFlag = 0;
	snd->lid = 0;
	snd->lastComponent = 1;
	snd->compSeq = 1;
	snd->srcQid = myQid;

	/* copy parameter */
	snd->paraOffset = 0;
	snd->paraLen = paraLen;

	memcpy( snd->parameter, para, paraLen);

	/* set dlgCtrl */
	memset( snd->dlgCtrl, 0, DLG_CTRL_MAX_ITEMS);
	snd->dlgType = DLG_TYPE_NUL;

	return 0;
}


/*
	send TCAP message to ATIF
*/
int sendTcapMsg( int qid, AtifSleeMsgType *msg, int dlg, int comp, 
	int origLen, unsigned char *orig, 
	int destLen, unsigned char *dest, 
	int iid, int usrDid)
{
	char origAddr[64], destAddr[64];

	if ( origLen > 0 ) {
		memcpy( msg->orig, orig, origLen);
		msg->origLen = origLen;
	}

	if ( destLen > 0 ) {
		memcpy( msg->dest, dest, destLen);
		msg->destLen = destLen;
	}

	msg->mtype = MTYPE_SLEE;
	msg->dlgMode = dlg;
	msg->compMode = comp;
	msg->iid = iid;
	msg->usrDid = usrDid;

	uaLog( L_INFO, "SEND TCAP %d %d %s %s", 
		msg->dlgMode, msg->compMode, 
		addr2str(msg->orig, origAddr), addr2str(msg->dest, destAddr));

	if ( msgsnd( qid, msg, ATIF_SLEE_MSG_LEN(*msg), IPC_NOWAIT) < 0) {
		uaLog( L_MAJ, "msgsnd failed qid=%d  E=%d", qid, errno);
		return -1;
	}

	return 0;
}


