#include <sigtran_util.h>
#include <ua_log.h>
#include <ua_datatypes.h>

#include <SS7/ix7map.h>
#include <ASN/asn_smsc.h>

// dduckk change header
//#include <usigtran/usccp_def.h>
#include <usrg/usccp_def.h>

void Print_Component(UTcapComponents  *comp);
void Print_Primitive(UTcapPrimitive  *prim);


int sig_minTraceTcap(char *fName, char *funName, int lNum, 
	stAddr *addr, UTcapPrimitive *prim, UTcapComponents *comp, int sent)
{
	int ret;
	int errCode;
	UTcapPrimitive_DAT_REQ *req;
	UTcapPrimitive_DAT_IND *ind;
	int acnLen;
	unsigned char *acn;
	int abortReason=0;

	if ( prim->type == UTcapPrimitiveType_DAT_REQ )
	{
		req = &(prim->u.datReq);

		if ( req->dlgEv.pres ) {
			acn = req->dlgEv.apConName.string;
			acnLen = req->dlgEv.apConName.len;
		}
		else {
			acn = 0;
			acnLen = 0;
		}

		/* sjkim add : TcapTrace can display including COMP_ERROR case */
		if( comp->compType == UTCAP_COMP_ERROR )
		{
			if( sig_decodeError(&errCode, comp)==IXERR )
				uaLog(L_MAJ," ErrorCode Decode fail. errcode=%d", errCode );

			return sig_minTraceTcapComplex( fName, funName, lNum, addr, sent,
				req->msgType, req->spDlgId, req->suDlgId, 
				acn, acnLen, abortReason, &req->srcAddr, &req->dstAddr,
				UTCAP_COMP_ERROR, errCode,
				comp->invokeId.pres ? comp->invokeId.octet : 0,
				comp->cpBuf, comp->bufLen);
		}
		else 
		{
			return sig_minTraceTcapComplex( fName, funName, lNum, addr, sent,
				req->msgType, req->spDlgId, req->suDlgId, 
				acn, acnLen, abortReason, &req->srcAddr, &req->dstAddr,
				comp->compType, comp->opCode.len > 0 ? comp->opCode.string[0] : 0,
				comp->invokeId.pres ? comp->invokeId.octet : 0,
				comp->cpBuf, comp->bufLen);
		}
	}
	else  if ( prim->type == UTcapPrimitiveType_DAT_IND) 
	{
		ind = &(prim->u.datInd);

		if ( ind->dlgEv.pres ) {
			acn = ind->dlgEv.apConName.string;
			acnLen = ind->dlgEv.apConName.len;
		}
		else {
			acn = 0;
			acnLen = 0;
		}

		/* sjkim add : TcapTrace can display including COMP_ERROR case */
		if( comp->compType == UTCAP_COMP_ERROR )
		{
			if( sig_decodeError(&errCode, comp)==IXERR )
				uaLog(L_MAJ," ErrorCode Decode fail. errcode=%d", errCode );

			return sig_minTraceTcapComplex( fName, funName, lNum, addr, sent,
				ind->msgType, ind->spDlgId, ind->suDlgId, 
				acn, acnLen, abortReason, &ind->srcAddr, &ind->dstAddr,
				UTCAP_COMP_ERROR, errCode,
				comp->invokeId.pres ? comp->invokeId.octet : 0,
				comp->cpBuf, comp->bufLen);
		}
		else 
		{
			return sig_minTraceTcapComplex( fName, funName, lNum, addr, sent,
				ind->msgType, ind->spDlgId, ind->suDlgId, 
				acn, acnLen, abortReason, &ind->srcAddr, &ind->dstAddr,
				comp->compType, comp->opCode.len > 0 ? comp->opCode.string[0] : 0,
				comp->invokeId.pres ? comp->invokeId.octet : 0,
				comp->cpBuf, comp->bufLen);
		}
	}

	uaLog( L_MAJ, "Invalid primitive type to trace %d", prim->type);
	/*
	uaLog( L_MAJ, "Invalid primitive type to trace %s", 
			UTCAP_PRIMITIVE_TYPE_STR(prim->type));
	*/
	return -1;
}

/*
   SIGTRAN 용 TCAP API를 사용하는 경우 
   */
int sig_minTraceTcapComplex(char *fName, char *funName, int lNum, 
	stAddr *addr, int sent,
	int primType, int provId, int userId, 
	unsigned char *acn, int acnLen, int abortReason,
	USccpAddr *srcAddr, USccpAddr *dstAddr,
	int compType, int opcode, int invId, unsigned char *paraPtr, int paraLen)
{
	int 	ptrLen=0;
    char    buff[2000];
    char    p_name[20], c_name[20];
    char    op_name[48];
	char 	para[1024];
	char	appContxt[128];
	char	ext[80];
	char	origAddr[200], destAddr[200];
	char 	*ptr;
	int i;

	const char *lineStr = "-----------------------------------------------------------\n";

	ptr = para;

	memset(origAddr,0,sizeof(origAddr));
	memset(destAddr,0,sizeof(destAddr));

	/*
	uaLog( L_INFO,"primType=%d, pId=%d userId=%d acn=%s acnLen=%d\n"
				"srcAddr:PC=%d SSN=%d dstAddr:PC=%d SSN=%d\n"
				"abortReason=%d compType=%d opCode=%d invId=%d, paraLen=%d",
					primType, provId, userId, acn, acnLen, 
					srcAddr->pc, srcAddr->ssn, 
					dstAddr->pc, dstAddr->ssn,
					abortReason, compType, opcode, invId, paraLen );
	*/

    if(addr == NULL || fName == NULL)
        return IXERR;

    if(IsThisMinTrace(addr) == IXERR)
        return 0;
    strcpy(p_name, UTCAP_TRANSACTION_STR(primType));
    strcpy(c_name, UTCAP_COMPONENT_STR(compType));

	/* get address string */
	/*
	uSccpAddr2str( srcAddr, origAddr);
	uSccpAddr2str( dstAddr, destAddr);
	*/

	sig_addr2str( srcAddr, origAddr);
	sig_addr2str( dstAddr, destAddr);

    if( paraLen > 0) {
		sprintf( ptr, "%s", lineStr);
		ptr += strlen(ptr);

		for(i = 0; i < paraLen; i++)
		{
			if( i> 0 && (i % 20) == 0) {
				sprintf(ptr, "\n");
				ptr += strlen(ptr);
			}
			sprintf(ptr, "%02X ", (unsigned char)paraPtr[i]);
			ptr += strlen(ptr);
		}
		sprintf( ptr, "\n%s", lineStr);
		ptr += strlen(ptr);
	}
	if ( primType == UTCAP_U_ABORT || primType == UTCAP_P_ABORT) {
		MinTrace( fName, funName, lNum, addr, 
"--- TCAP %s : %s %s ---\n\
Orig Addr  : %s\n\
Dest Addr  : %s\n\
DiagID     : %d\n",
			sent ? "SENT":"RECV", p_name, c_name, 
			origAddr, destAddr, userId);
		return IXOK;
	}


	/* add extra info */
	switch ( compType ) {
	case UTCAP_COMP_ERROR: 
		sprintf( ext, "Error code : %d\n", opcode );
		break;
	case UTCAP_COMP_INVOKE :
	case UTCAP_COMP_RET_RES_L :
	case UTCAP_COMP_RET_RES_NL :
		if ( paraLen > 0) {
			getOpName( op_name, opcode);
			sprintf( ext, "OP code    : %d  (H'%x)  %s\n",
				opcode, opcode, op_name);
		}
		else ext[0] = 0;

		break;
	default:
		ext[0] = 0;
		break;
	}


	MinTrace( fName, funName, lNum, addr, 
"--- TCAP %s : %s %s ---\n\
Orig Addr  : %s\n\
Dest Addr  : %s\n\
%s\
Invoke ID  : %d\n\
DiagID     : %d\n\
ParaLength : %d\n%s",
			sent ? "SENT":"RECV", p_name, c_name, 
			origAddr, destAddr,
			ext,
			invId, userId, paraLen, (paraLen>0)?para:"");

	return IXOK;
}

int sig_sendResultComplex(UTcap *tcapInfo, int acn,
		int provId, unsigned char invId,
		unsigned char opcode, unsigned char *para, int paraLen ,int msgType)
{
	UTcapPrimitive txPrim;
	UTcapComponents txComp;
	int rval;

	memset( &txPrim, 0, sizeof(txPrim));
	memset( &txComp, 0, sizeof(txComp));

	txComp.suDlgId = 1;
	txComp.spDlgId = provId;

	/* copy parameter */
	txComp.bufLen = paraLen;
	memcpy( txComp.cpBuf, para, paraLen);

	/* set sndonent data */
	if(msgType == UTCAP_CONTINUE) {
		/* r121
		txComp.compType = UTCAP_COMP_RET_RES_NL; */
		txComp.compType = UTCAP_COMP_RET_RES_L;
	} else {
		txComp.compType = UTCAP_COMP_RET_RES_L;
	}
	if ( invId > 0) {
		txComp.invokeId.pres = 1;
		txComp.invokeId.octet = invId;
	}
	else {
		txComp.invokeId.pres = 0;
	}

	/* set opcode */
	txComp.opCodeFlg = UTCAP_LOCAL;
	txComp.opCode.len = 1;
	txComp.opCode.string[0] = opcode;

	/* send component */
	if ( (rval = utcap_putComp( tcapInfo, txComp.suDlgId, txComp.spDlgId, &txComp)) < 0) {
		uaLog( L_MAJ, "utcap_putComp failed did=%d opcode=%d, rval=%d",
				txComp.suDlgId, opcode, rval);
		return -1;
	}

	/* set primitive */
	txPrim.type = UTcapPrimitiveType_DAT_REQ;

	txPrim.u.datReq.msgType = msgType;
	txPrim.u.datReq.suDlgId = txComp.suDlgId;
	txPrim.u.datReq.spDlgId = txComp.spDlgId;

	setDialogPortion( acn, &txPrim.u.datReq.dlgEv, 0);

	if ( (rval = utcap_send( tcapInfo, &txPrim)) < 0) {
		uaLog( L_MAJ, "utcap_send failed opcode=%d", opcode);
		return -1;
	}
	return 0;
}
int sig_sendContinueResultComplex( UTcap *tcapInfo, int acn,
		        int provId, unsigned char invId,
				        unsigned char opcode, unsigned char *para, int paraLen )
{
	return sig_sendResultComplex(tcapInfo, acn, provId, invId, opcode
				            , para, paraLen , UTCAP_CONTINUE);
}
 

/*
   make sigtran  GSM component, return result
   */
int sig_sendEndResultComplex( UTcap *tcapInfo, int acn, 
		int provId, unsigned char invId,
		unsigned char opcode, unsigned char *para, int paraLen )
{
	UTcapPrimitive txPrim;
	UTcapComponents txComp;
	int rval;

	memset( &txPrim, 0, sizeof(txPrim));
	memset( &txComp, 0, sizeof(txComp));

	txComp.suDlgId = 1;
	txComp.spDlgId = provId;

	/* copy parameter */
	txComp.bufLen = paraLen;
	memcpy( txComp.cpBuf, para, paraLen);

	/* set sndonent data */
	txComp.compType = UTCAP_COMP_RET_RES_L;
	if ( invId > 0) {
		txComp.invokeId.pres = 1;
		txComp.invokeId.octet = invId;
	}
	else {
		txComp.invokeId.pres = 0;
	}

	/* set opcode */
	txComp.opCodeFlg = UTCAP_LOCAL;
	txComp.opCode.len = 1;
	txComp.opCode.string[0] = opcode;

	/* send component */
	if ( (rval = utcap_putComp( tcapInfo, txComp.suDlgId, txComp.spDlgId, &txComp)) < 0) {
		uaLog( L_MAJ, "utcap_putComp failed did=%d opcode=%d, rval=%d",
				txComp.suDlgId, opcode, rval);
		return -1;
	}

	/* set primitive */
	txPrim.type = UTcapPrimitiveType_DAT_REQ;

	txPrim.u.datReq.msgType = UTCAP_END;
	txPrim.u.datReq.suDlgId = txComp.suDlgId;
	txPrim.u.datReq.spDlgId = txComp.spDlgId;

	setDialogPortion( acn, &txPrim.u.datReq.dlgEv, 0);

	if ( (rval = utcap_send( tcapInfo, &txPrim)) < 0) {
		uaLog( L_MAJ, "utcap_send failed opcode=%d", opcode);
		return -1;
	}

	Print_Primitive(&txPrim);
	Print_Component(&txComp);

	return 0;
}
/*
   make sigtran component, return result
   */
int sig_sendEndResultComplexSMSG( UTcap *tcapInfo, int acn, 
		int provId, unsigned char invId,
		unsigned char opcode, unsigned char *para, int paraLen  , USccpAddr *dest)
{
	UTcapPrimitive txPrim;
	UTcapComponents txComp;
	int rval;

	memset( &txPrim, 0, sizeof(txPrim));
	memset( &txComp, 0, sizeof(txComp));

	txComp.suDlgId = 1;
	txComp.spDlgId = provId;

	/* copy parameter */
	txComp.bufLen = paraLen;
	memcpy( txComp.cpBuf, para, paraLen);

	/* set sndonent data */
	txComp.compType = UTCAP_COMP_RET_RES_L;
	if ( invId > 0) {
		txComp.invokeId.pres = 1;
		txComp.invokeId.octet = invId;
	}
	else {
		txComp.invokeId.pres = 0;
	}

	/* set opcode */
	txComp.opCodeFlg = UTCAP_LOCAL;
	txComp.opCode.len = 1;
	txComp.opCode.string[0] = opcode;

	/* send component */
	if ( (rval = utcap_putComp( tcapInfo, txComp.suDlgId, txComp.spDlgId, &txComp)) < 0) {
		uaLog( L_MAJ, "utcap_putComp failed did=%d opcode=%d, rval=%d",
				txComp.suDlgId, opcode, rval);
		return -1;
	}

	/* set primitive */
	txPrim.type = UTcapPrimitiveType_DAT_REQ;

	txPrim.u.datReq.msgType = UTCAP_END;
	txPrim.u.datReq.suDlgId = txComp.suDlgId;
	txPrim.u.datReq.spDlgId = txComp.spDlgId;

	memcpy( &txPrim.u.datReq.srcAddr, dest , sizeof(USccpAddr));

	setDialogPortion( acn, &txPrim.u.datReq.dlgEv, 0);



	if ( (rval = utcap_send( tcapInfo, &txPrim)) < 0) {
		uaLog( L_MAJ, "utcap_send failed opcode=%d", opcode);
		return -1;
	}

	return 0;
}

int setDialogPortion(int acn, UTcapDialogPortion *dlg, int abortReason)
{
	if (acn == IS_ACN_NOT_SET)
	{
		dlg->pres = 0;
	}
	else
	{
		int len;
		unsigned char acnStr[12];

		memset( dlg, 0, sizeof(UTcapDialogPortion));

		dlg->pres = 1;

		dlg->dlgType = UTCAP_DLGP_RSP;

		MakeACN(&len, acnStr, acn);

		dlg->apConName.len = len;
		memcpy( dlg->apConName.string, acnStr, len);

		dlg->resPres = 1;
		dlg->resSrc = UTCAP_DLG_USR_RES;

		if ( abortReason) {
			dlg->result = UTCAP_DLG_REJ_PERM;
			dlg->resReason = abortReason;
		}
		else {
			dlg->result = UTCAP_DLG_ACCEPTED;
			dlg->resReason = UTCAP_DLG_RSD_NULL;
		}
	}

	return 0;
}


/*
   make sigtran component, return result
   */
int sig_sendEndResult( UTcap *tcapInfo, int acn, UTcapPrimitive *rxPrim, 
		UTcapComponents *rxComp, unsigned char *para, int paraLen)
{
	return sig_sendEndResultComplex( tcapInfo, acn, rxComp->spDlgId, 
			rxComp->invokeId.pres ? rxComp->invokeId.octet : 0,
			rxComp->opCode.string[0],
			para, paraLen);

}

/*
   make sigtran component, return error
   */
int sig_sendEndErrorComplexSMSG( UTcap *tcapInfo, int acn, int provId, 
		unsigned char invId, unsigned char opcode, 
		int errCode,
		unsigned char *para, int paraLen , USccpAddr *dest )
{
	UTcapPrimitive txPrim;
	UTcapComponents txComp;
	int rval;

	memset( &txPrim, 0, sizeof(txPrim));
	memset( &txComp, 0, sizeof(txComp));

	txComp.suDlgId = 1;
	txComp.spDlgId = provId;

	/* copy parameter */
	txComp.bufLen = paraLen;
	memcpy( txComp.cpBuf, para, paraLen);

	/* set sndonent data */
	txComp.compType = UTCAP_COMP_ERROR;

	if ( invId > 0)  {
		txComp.invokeId.pres = 1;
		txComp.invokeId.octet = invId;
	}
	else {
		txComp.invokeId.pres = 0;
	}

	/* set error code */
	txComp.errorCodeFlg = UTCAP_LOCAL;
	txComp.errorCode.len = 1;
	txComp.errorCode.string[0] = errCode;

	/* set opcode */
	txComp.opCodeFlg = UTCAP_LOCAL;
	txComp.opCode.len = 1;
	txComp.opCode.string[0] = opcode;

	/* send component */
	if ( (rval = utcap_putComp( tcapInfo, txComp.suDlgId, txComp.spDlgId, &txComp)) < 0) {
		uaLog( L_MAJ, "utcap_putComp failed did=%d opcode=%d, rval=%d",
				txComp.suDlgId, opcode, rval);
		return -1;
	}

	/* set primitive */
	txPrim.type = UTcapPrimitiveType_DAT_REQ;

	txPrim.u.datReq.msgType = UTCAP_END;
	txPrim.u.datReq.suDlgId = txComp.suDlgId;
	txPrim.u.datReq.spDlgId = txComp.spDlgId;

	memcpy( &txPrim.u.datReq.srcAddr, dest , sizeof(USccpAddr));

	setDialogPortion( acn, &txPrim.u.datReq.dlgEv, 0);

	Print_Primitive(&txPrim);
	Print_Component(&txComp);

	if ( (rval = utcap_send( tcapInfo, &txPrim)) < 0) {
		uaLog( L_MAJ, "utcap_send failed opcode=%d");
		return -1;
	}

	return 0;
}


/*
   make sigtran component, return error
   */
int sig_sendEndErrorComplex( UTcap *tcapInfo, int acn, int provId, 
		unsigned char invId, unsigned char opcode, 
		int errCode,
		unsigned char *para, int paraLen)
{
	UTcapPrimitive txPrim;
	UTcapComponents txComp;
	int rval;

	memset( &txPrim, 0, sizeof(txPrim));
	memset( &txComp, 0, sizeof(txComp));

	txComp.suDlgId = 1;
	txComp.spDlgId = provId;

	/* copy parameter */
	txComp.bufLen = paraLen;
	memcpy( txComp.cpBuf, para, paraLen);

	/* set sndonent data */
	txComp.compType = UTCAP_COMP_ERROR;

	if ( invId > 0)  {
		txComp.invokeId.pres = 1;
		txComp.invokeId.octet = invId;
	}
	else {
		txComp.invokeId.pres = 0;
	}

	/* set error code */
	txComp.errorCodeFlg = UTCAP_LOCAL;
	txComp.errorCode.len = 1;
	txComp.errorCode.string[0] = errCode;

	/* set opcode */
	txComp.opCodeFlg = UTCAP_LOCAL;
	txComp.opCode.len = 1;
	txComp.opCode.string[0] = opcode;

	/* send component */
	if ( (rval = utcap_putComp( tcapInfo, txComp.suDlgId, txComp.spDlgId, &txComp)) < 0) {
		uaLog( L_MAJ, "utcap_putComp failed did=%d opcode=%d, rval=%d",
				txComp.suDlgId, opcode, rval);
		return -1;
	}

	/* set primitive */
	txPrim.type = UTcapPrimitiveType_DAT_REQ;

	txPrim.u.datReq.msgType = UTCAP_END;
	txPrim.u.datReq.suDlgId = txComp.suDlgId;
	txPrim.u.datReq.spDlgId = txComp.spDlgId;

	setDialogPortion( acn, &txPrim.u.datReq.dlgEv, 0);

	if ( (rval = utcap_send( tcapInfo, &txPrim)) < 0) {
		uaLog( L_MAJ, "utcap_send failed opcode=%d");
		return -1;
	}

	Print_Primitive(&txPrim);
	Print_Component(&txComp);

	return 0;
}

int sig_sendEndError( UTcap *tcapInfo, int acn, UTcapPrimitive *rxPrim, 
		UTcapComponents *rxComp, 
		int errCode, unsigned char *para, int paraLen)
{
	return  sig_sendEndErrorComplex( tcapInfo, acn, 
		rxComp->spDlgId,
		rxComp->invokeId.pres ? rxComp->invokeId.octet : 0,
		rxComp->opCode.string[0], errCode, para, paraLen);
}


char *sig_addr2str( USccpAddr  *addr, char *str)
{
	//str[0] = 0;

	if ( addr->ind & USccpAddrInd_PC_PRESENT) {
		sprintf( str, "PC=%d (H'%x)  ", addr->pc, addr->pc);
	}

	if ( addr->ind & USccpAddrInd_SSN_PRESENT) {
		sprintf( &str[strlen(str)], "SSN=%d ", addr->ssn);
	}

	if ( addr->ind & USccpAddrInd_GT_PRESENT)
	{
		int bcdDigit=0;
		sprintf( &str[strlen(str)], "GTA=" );

		if( (addr->gta.nDigit%2)==0 )
			bcdDigit = addr->gta.nDigit/2;
		else
			bcdDigit = (addr->gta.nDigit+1)/2;

		nbcd2str( addr->gta.gtStr, bcdDigit, &str[strlen(str)] , 40 );
	}

	return str;
}

UTcap *initSigtran( int argc, char *argv[], char *name)
{
	int e;

	e = utcap_init( argc, argv);
	U_ASSERT(e==0);

	return utcap_open( name );
}

int sig_getOpcode( UTcapOperation *opCode)
{
	if ( opCode->len == 1) return opCode->string[0];
	return -1;
}

int sig_sendContinueResult( UTcap *tcapInfo, 
		int opcode, int dlgId, USccpAddr *orig, USccpAddr *dest,
		int timer, unsigned char *para, int paraLen, int invoke_id, int prov_id)
{
	UTcapPrimitive 		txPrim;
	UTcapComponents		txComp;
	int					rval;

	memset( &txPrim, 0, sizeof(txPrim));
	memset( &txComp, 0, sizeof(txComp));
	
	txComp.suDlgId = dlgId;
	txComp.spDlgId = prov_id;

	txComp.bufLen = paraLen;
	memcpy( txComp.cpBuf, para, paraLen);

	txComp.compType = UTCAP_COMP_RET_RES_L;

	if(invoke_id > 1)
	{
		txComp.invokeId.pres = 1;
		txComp.invokeId.octet = invoke_id;
	}

	txComp.opCodeFlg = UTCAP_LOCAL;
	txComp.opCode.len = 1;
	txComp.opCode.string[0] = opcode;

	if((rval = utcap_putComp(tcapInfo, txComp.suDlgId, txComp.spDlgId, &txComp)) < 0)
	{
		uaLog(L_MAJ, "utcap_putCom failed did=%d opcode=%d prov_id=%d inv_id=%d",
				txComp.suDlgId, opcode, txComp.spDlgId, invoke_id);
		return -1;
	}

	txPrim.type = UTcapPrimitiveType_DAT_REQ;

	txPrim.u.datReq.msgType = UTCAP_CONTINUE;
	txPrim.u.datReq.suDlgId = txComp.suDlgId;
	txPrim.u.datReq.spDlgId = txComp.spDlgId;

	if((rval = utcap_send(tcapInfo, &txPrim)) < 0) 
	{
		uaLog(L_MAJ, "utcap-send failed opcode=%d", rval);
		return -1;
	}
	
	return 0;
	
}

int sig_sendContinueInvoke( UTcap *tcapInfo, 
		int opcode, int dlgId, USccpAddr *orig, USccpAddr *dest,
		int timer, unsigned char *para, int paraLen, int invId, int provId)
{
	UTcapPrimitive txPrim;
	UTcapComponents txComp;
	int rval;

	memset( &txPrim, 0, sizeof(txPrim));
	memset( &txComp, 0, sizeof(txComp));

	txComp.suDlgId = dlgId;
	/* when smsc invokes TC_CONTINUE, smsc must set to first time's provId */
	txComp.spDlgId = provId;

	/* copy parameter */
	txComp.bufLen = paraLen;
	memcpy( txComp.cpBuf, para, paraLen);

	/* set sndonent data */
	txComp.compType = UTCAP_COMP_INVOKE;
	txComp.invokeId.pres = TRUE;
	txComp.invokeId.octet = invId;

	/* set opcode */
	txComp.opCodeFlg = UTCAP_LOCAL;
	txComp.opCode.len = 1;
	txComp.opCode.string[0] = opcode;

	/* set opclass */
	txComp.opClass = 1;

	/* set timer */
	txComp.invokeTimer = timer;

	/* send component */
	if ( (rval = utcap_putComp( tcapInfo, txComp.suDlgId, txComp.spDlgId, &txComp)) < 0) {
		uaLog( L_MAJ, "utcap_putComp failed did=%d opcode=%d",
				txComp.suDlgId, opcode);
		return -1;
	}

	sig_printComponent(&txComp);

	/* set primitive */
	txPrim.type = UTcapPrimitiveType_DAT_REQ;
	//txPrim.lssn = orig->ssn;

	txPrim.u.datReq.msgType = UTCAP_CONTINUE;
	txPrim.u.datReq.suDlgId = txComp.suDlgId;
	txPrim.u.datReq.spDlgId = txComp.spDlgId;

	/* set address */
	memcpy( &txPrim.u.datReq.srcAddr, orig, sizeof(USccpAddr));
	memcpy( &txPrim.u.datReq.dstAddr, dest, sizeof(USccpAddr));

	if ( (rval = utcap_send( tcapInfo, &txPrim)) < 0) {
		uaLog( L_MAJ, "utcap_send failed opcode=%d");
		return -1;
	}

	sig_printPrimitive(&txPrim);

	return 0;
}	


/*
   make sigtran component, return result
   */
int sig_sendBeginInvoke( UTcap *tcapInfo, 
		int opcode, int dlgId, USccpAddr *orig, USccpAddr *dest,
		int timer,
		unsigned char *para, int paraLen, int acn,
		char *sigTraceNum ) // add for sig stack trace.
{
	UTcapPrimitive txPrim;
	UTcapComponents txComp;
	int rval;

	memset( &txPrim, 0, sizeof(txPrim));
	memset( &txComp, 0, sizeof(txComp));

	txComp.suDlgId = dlgId;
	txComp.spDlgId = -1;		// modified by jhnoh 2005/05/11 ( old : 1, new : -1 )

	/* copy parameter */
	txComp.bufLen = paraLen;
	memcpy( txComp.cpBuf, para, paraLen);

	/* set sndonent data */
	txComp.compType = UTCAP_COMP_INVOKE;
	txComp.invokeId.pres = TRUE;
	txComp.invokeId.octet = 1;

	/* set opcode */
	txComp.opCodeFlg = UTCAP_LOCAL;
	txComp.opCode.len = 1;
	txComp.opCode.string[0] = opcode;

	/* set opclass */
	txComp.opClass = 1;

	/* set timer */
	txComp.invokeTimer = timer;

	/* send component */
	if ( (rval = utcap_putComp( tcapInfo, txComp.suDlgId, txComp.spDlgId, &txComp)) < 0) {
		uaLog( L_MAJ, "utcap_putComp failed did=%d opcode=%d",
				txComp.suDlgId, opcode);
		return -1;
	}

	sig_printComponent(&txComp);

	/* set primitive */
	txPrim.type = UTcapPrimitiveType_DAT_REQ;
	//txPrim.lssn = orig->ssn;

	txPrim.u.datReq.msgType = UTCAP_BEGIN;
	txPrim.u.datReq.suDlgId = txComp.suDlgId;
	// txPrim.u.datReq.spDlgId = txComp.spDlgId;
	txPrim.u.datReq.spDlgId = -1 ;	// modified by jhnoh 2005/05/11

	txPrim.u.datReq.seqCtrl = dlgId;  // 임시로 넣었음(0이 아닌 값) 화웨이 땜시 by k-you

	/* set address */
	memcpy( &txPrim.u.datReq.srcAddr, orig, sizeof(USccpAddr));
	memcpy( &txPrim.u.datReq.dstAddr, dest, sizeof(USccpAddr));

	setDialogPortion( acn, &txPrim.u.datReq.dlgEv, 0);


	txPrim.traceId = -1;

	Print_Primitive(&txPrim);
	Print_Component(&txComp);

	if ( (rval = utcap_send( tcapInfo, &txPrim)) < 0) {
		uaLog( L_MAJ, "utcap_send failed opcode=%d ret=%d", opcode, rval);
		return -1;
	}

	sig_printPrimitive(&txPrim);

	return 0;
}

int sig_sendBeginNotComp( UTcap *tcapInfo,
        int dlgId, USccpAddr *orig, USccpAddr *dest,
        int timer,
        int acn,
        char *sigTraceNum ) // add for sig stack trace.
{
    UTcapPrimitive txPrim;
    int rval;

    memset( &txPrim, 0, sizeof(txPrim));

    /* set primitive */
    txPrim.type = UTcapPrimitiveType_DAT_REQ;

    txPrim.u.datReq.msgType = UTCAP_BEGIN;
    txPrim.u.datReq.suDlgId = dlgId;
    txPrim.u.datReq.spDlgId = -1 ;  // modified by jhnoh 2005/05/11

    txPrim.u.datReq.seqCtrl = dlgId;  // 임시로 넣었음(0이 아닌 값) 화웨이 땜시 by k-you

    /* set address */
    memcpy( &txPrim.u.datReq.srcAddr, orig, sizeof(USccpAddr));
    memcpy( &txPrim.u.datReq.dstAddr, dest, sizeof(USccpAddr));

    setDialogPortion( acn, &txPrim.u.datReq.dlgEv, 0);

	// dduckk _UTcapPrimitive가 변경됨.
    //txPrim.u.datReq.traceId = -1;
    txPrim.traceId = -1;

    if ( (rval = utcap_send( tcapInfo, &txPrim)) < 0) {
        uaLog( L_MAJ, "utcap_send failed ret=%d", rval);
        return -1;
    }

    sig_printPrimitive(&txPrim);

    return 0;
}

int sig_sendTCUAbort( UTcap *tcapInfo, int dlgId, int provId, int mySSN)
{
	UTcapPrimitive txPrim;
	int rval;

	memset( &txPrim, 0, sizeof(txPrim));

	/* set primitive */
	txPrim.type = UTcapPrimitiveType_DAT_REQ;
	//txPrim.lssn = mySSN;

	txPrim.u.datReq.msgType = UTCAP_U_ABORT;
	txPrim.u.datReq.suDlgId = dlgId;
	txPrim.u.datReq.spDlgId = provId;
	
	uaLog( L_INFO,"send U_ABORT(suDlgId=%d spDlgId=%d)", dlgId, provId );

	if ( (rval = utcap_send( tcapInfo, &txPrim)) < 0) {
		uaLog( L_MAJ, "utcap_send failed E=%d", rval);
		return -1;
	}

	return 0;
}

int sig_sendTCUAbortWithDP( UTcap *tcapInfo, int dlgId, int provId, int acn)
{
	UTcapPrimitive txPrim;
	int rval;
	UTcapDialogPortion *dlg;
	int len;
	unsigned char acnStr[12];

	memset( &txPrim, 0, sizeof(txPrim));

	dlg = &txPrim.u.datReq.dlgEv;

	/* set primitive */
	txPrim.type = UTcapPrimitiveType_DAT_REQ;
	//txPrim.lssn = mySSN;

	txPrim.u.datReq.msgType = UTCAP_U_ABORT;
	txPrim.u.datReq.suDlgId = dlgId;
	txPrim.u.datReq.spDlgId = provId;

	/*
	setDialogPortion( acn, &txPrim.u.datReq.dlgEv, UTCAP_DLG_REFUSED); 
	dlg->dlgType = UTCAP_DLGP_ABT;
	*/
	memset( dlg, 0, sizeof(UTcapDialogPortion));

	dlg->pres = 1;

	dlg->dlgType = UTCAP_DLGP_RSP;

	MakeACN(&len, acnStr, acn);

	dlg->apConName.len = len;
	memcpy( dlg->apConName.string, acnStr, len);

	dlg->resPres = 1;
	dlg->resSrc = UTCAP_DLG_USR_RES;

	dlg->result = UTCAP_DLG_REFUSED;
	dlg->resReason = 0x00;

	uaLog( L_INFO,"send U_ABORT(suDlgId=%d spDlgId=%d)", dlgId, provId );

	if ( (rval = utcap_send( tcapInfo, &txPrim)) < 0) {
		uaLog( L_MAJ, "utcap_send failed E=%d", rval);
		return -1;
	}

	return 0;
}

int sig_sendResultNotComp(UTcap *tcapInfo, int acn, int provId, UTcapPrimitive *rxPrim, int msgType)
{
    int rval;
    UTcapPrimitive txPrim;
 
    memset( &txPrim, 0, sizeof(txPrim));
 
    /* set primitive */
    txPrim.type = UTcapPrimitiveType_DAT_REQ;
 
    txPrim.u.datReq.msgType = msgType;
    txPrim.u.datReq.suDlgId = 1;
    txPrim.u.datReq.spDlgId = provId;
 
    /*memcpy(&txPrim.u.datReq.dlgEv, &rxPrim->u.datReq.dlgEv, sizeof(UTcapPrimitive)); */
 
    setDialogPortion( acn, &txPrim.u.datReq.dlgEv, 0);
    /* 임시 조치로 강제 0을 넣는다. */
    txPrim.u.datReq.dlgEv.resSrc = 0x00;
 
    /*
    memcpy(&txPrim.u.datReq.bufLen, &rxPrim->u.datReq.bufLen, sizeof(int16_t)); 
    memcpy(&txPrim.u.datReq.uiBuf, &rxPrim->u.datReq.uiBuf
      , (sizeof(uint8_t) * UTCAP_MAX_TC_BUF)); 
    */
 
    if ( (rval = utcap_send( tcapInfo, &txPrim)) < 0) {
        uaLog( L_MAJ, "utcap_send failed");
        return -1;
    }
    sig_printPrimitive(&txPrim);
 
    return 0;
}


int sig_makeGT_test( USccpAddr *addr, char *isdn, int translation, int ssn)  /* ytl specific */
{
	int tmp=0;

	addr->ind = USccpAddrInd_ROUTE_ON_GT;
	addr->ind |= USccpAddrInd_GT_PRESENT;

	if ( ssn ) { 
		addr->ind |= USccpAddrInd_SSN_PRESENT;
		addr->ssn = ssn;
	}
	addr->pc = 0;
	addr->gtt.gti = USccpGtInd_TT_NP_ES_NAI;					
	addr->gtt.tt = translation;					 
	addr->gtt.np = USccpGtNumberingPlan_TELEPHONY;
//	addr->gtt.nai = USccpGtNatureOfAddr_INTERNATIONAL;
	if ( strncmp(isdn, "20", 2) == 0 ) /* temprary test for ytl intl sms */
		addr->gtt.nai = 1;
	else
		addr->gtt.nai = 4;

    if((strlen(isdn) % 2) == 0)
        addr->gtt.es = USccpGtEncodingScheme_EVEN;
    else
        addr->gtt.es = USccpGtEncodingScheme_ODD;


	/* 05/06/21 sjkim :
	 * str2nbcd() return value is byte digit */

	//addr->gta.nDigit = str2nbcd( isdn, addr->gta.gtStr, sizeof(addr->gta.gtStr));

	/* old version str2nbcd : filler is 0xF, new version str2nbcdApp : filler is 0x0  by k-you */
//	tmp = str2nbcd( isdn, addr->gta.gtStr, sizeof(addr->gta.gtStr));
	tmp = str2nbcdApp( isdn, addr->gta.gtStr, sizeof(addr->gta.gtStr));
	if( strlen(isdn)%2==0 )	
		addr->gta.nDigit = tmp*2;
	else	
		addr->gta.nDigit = (tmp*2)-1;

	uaLog( L_INFO, " ISDN=%s nDigit=%d(tmp=%d) SSN=%d git=TT_NP_ES_NAI"
				   " tt=%d np=TELEPHONY nai=%d",
				   isdn, addr->gta.nDigit, tmp, ssn, addr->gtt.tt, addr->gtt.nai );

    return IXOK;
}

int sig_makeGT( USccpAddr *addr, char *isdn, int translation, int ssn)
{
	int tmp=0;

	addr->ind = USccpAddrInd_ROUTE_ON_GT;
	addr->ind |= USccpAddrInd_GT_PRESENT;

	if ( ssn ) { 
		addr->ind |= USccpAddrInd_SSN_PRESENT;
		addr->ssn = ssn;
	}
	addr->pc = 0;
	addr->gtt.gti = USccpGtInd_TT_NP_ES_NAI;					
	addr->gtt.tt = translation;					
	addr->gtt.np = USccpGtNumberingPlan_TELEPHONY;
	addr->gtt.nai = USccpGtNatureOfAddr_INTERNATIONAL;

    if((strlen(isdn) % 2) == 0)
        addr->gtt.es = USccpGtEncodingScheme_EVEN;
    else
        addr->gtt.es = USccpGtEncodingScheme_ODD;

	/* old version str2nbcd : filler is 0xF, new version str2nbcdApp : filler is 0x0  by k-you */
//	tmp = str2nbcd( isdn, addr->gta.gtStr, sizeof(addr->gta.gtStr));
	tmp = str2nbcdApp( isdn, addr->gta.gtStr, sizeof(addr->gta.gtStr));
	if( strlen(isdn)%2==0 )	
		addr->gta.nDigit = tmp*2;
	else	
		addr->gta.nDigit = (tmp*2)-1;

	uaLog( L_INFO, " ISDN=%s nDigit=%d(tmp=%d) SSN=%d git=TT_NP_ES_NAI"
				   " tt=%d np=TELEPHONY nai=%d",
				   isdn, addr->gta.nDigit, tmp, ssn, addr->gtt.tt, addr->gtt.nai );

    return IXOK;
}

int sig_getNodeNumber( stNodeNumber *node, USccpAddr *addr)
{
	memset((void *)node, 0, sizeof(stNodeNumber));

	if ( addr->ind & USccpAddrInd_PC_PRESENT)
	{
		node->pCode = addr->pc;
        uaLog( L_INFO, "PC_Present. pc=%d", node->pCode ) ;
	}

	if ( addr->ind & USccpAddrInd_SSN_PRESENT)
	{
		node->ssn = addr->ssn;
        uaLog( L_INFO, "SSN_Present. ssn=%d", node->ssn) ;
	}

	if ( addr->ind & USccpAddrInd_GT_PRESENT)
	{
		int bcdDigit=0;

		/* sjkim modified */
		//nbcd2str( addr->gta.gtStr, node->isdn, sizeof(node->isdn));
		
		if( (addr->gta.nDigit%2)==0 )
			bcdDigit = addr->gta.nDigit/2;
		else
			bcdDigit = (addr->gta.nDigit+1)/2;

		nbcd2str( addr->gta.gtStr, bcdDigit, node->isdn, sizeof(node->isdn));
		/* 하웨이 교환기의 경우 짝수길이만 세팅 가능 하여
		   nDigit와 isdn의 길이가 다른 경우 nDigit에 길이를 맞춘다.
		   added by comus 2007/09/13
		 */
		if(strlen(node->isdn) != addr->gta.nDigit) {
			uaLog(L_INFO, "Before Convert GT isdn[%s]", node->isdn);
			node->isdn[addr->gta.nDigit] = '\0';
		}
		uaLog( L_INFO, "GT_Present. addr->gta.nDigit=%d(bcdDigit=%d) isdn=%s", 
			addr->gta.nDigit, bcdDigit, node->isdn) ;
	}

	return 0;
}

int sig_checkACN(UTcapDialogPortion *pDiagPortion)
{
    if( pDiagPortion->pres == 0 )
    {
        uaLog( L_MIN, "None dialog info" ) ;
        return -1 ;
    }

    if(pDiagPortion->apConName.len == 0)
        return IS_ACN_NOT_SET ;
    else if(pDiagPortion->apConName.len ==
           shortMsgGatewayContext_v3.length &&
       !memcmp(pDiagPortion->apConName.string,
            shortMsgGatewayContext_v3.value,
            pDiagPortion->apConName.len))
        return ACN_GW_V3;
    else if(pDiagPortion->apConName.len ==
           shortMsgGatewayContext_v2.length &&
       !memcmp(pDiagPortion->apConName.string,
            shortMsgGatewayContext_v2.value,
            pDiagPortion->apConName.len))
        return ACN_GW_V2;
    else if(pDiagPortion->apConName.len ==
           shortMsgMT_RelayContext_v3.length &&
       !memcmp(pDiagPortion->apConName.string,
           shortMsgMT_RelayContext_v3.value,
            pDiagPortion->apConName.len))
        return ACN_MT_V3;
    else if(pDiagPortion->apConName.len ==                       
           shortMsgMO_RelayContext_v3.length &&                   
       !memcmp(pDiagPortion->apConName.string,                   
           shortMsgMO_RelayContext_v3.value,                      
            pDiagPortion->apConName.len))                        
        return ACN_MO_V3;
    else if(pDiagPortion->apConName.len ==                       
           shortMsgMT_RelayContext_v2.length &&                   
       !memcmp(pDiagPortion->apConName.string,                   
           shortMsgMT_RelayContext_v2.value,                      
            pDiagPortion->apConName.len))                        
        return ACN_MT_V2; 
    else if(pDiagPortion->apConName.len ==                       
           shortMsgMO_RelayContext_v2.length &&                   
       !memcmp(pDiagPortion->apConName.string,                   
           shortMsgMO_RelayContext_v2.value,                      
            pDiagPortion->apConName.len))                        
        return ACN_MO_V2; 
    else if(pDiagPortion->apConName.len ==                       
           shortMsgAlertContext_v2.length &&                      
       !memcmp(pDiagPortion->apConName.string,                   
           shortMsgAlertContext_v2.value,                         
            pDiagPortion->apConName.len))                        
        return ACN_ALERT_V2;
    else if(pDiagPortion->apConName.len == 
           mwdMngtContext_v3.length &&                      
       !memcmp(pDiagPortion->apConName.string,                   
           mwdMngtContext_v3.value,                         
            pDiagPortion->apConName.len))                        
        return ACN_READY_V3;
	else if(pDiagPortion->apConName.len ==
			anyTimeInfoHandlingContext_v3.length &&
			!memcmp(pDiagPortion->apConName.string,
				anyTimeInfoHandlingContext_v3.value,
				pDiagPortion->apConName.len))
		return ACN_ATM_V3;
    else
    	return IS_ACN_FAIL;                                                                                       
}  


int	sig_decodeError(int *errCode, UTcapComponents *comp)
{
	if( comp->errorCodeFlg == UTCAP_LOCAL )
	{
		*errCode = comp->errorCode.string[0] ;
		return IXOK ;
	}
	else
	{
		*errCode = 0 ;
		return IXERR ;
	}
}


int sig_printPrimitive(UTcapPrimitive *prim)
{
	UTcapPrimitive_DAT_REQ *req=NULL;
	UTcapPrimitive_DAT_IND *ind=NULL;
	char origAddr[100], dstAddr[100];

	if ( prim->type == UTcapPrimitiveType_DAT_REQ )
	{
		req = &(prim->u.datReq);

		memset(origAddr,0,sizeof(origAddr));
		memset(dstAddr,0,sizeof(dstAddr));

		sig_addr2str( &req->srcAddr, origAddr );
		sig_addr2str( &req->dstAddr, dstAddr );

		uaLog( L_INFO,"---PRIMITIVE (TYPE=REQ)---\n"
"                         TYPE=%s spDlgId=%d suDlgId=%d seqCtrl=%d \n"
"                         SRC_ADDR : %s\n" 
"                         DST_ADDR : %s", 
			UTCAP_TRANSACTION_STR(req->msgType), req->spDlgId, req->suDlgId,
			req->seqCtrl, origAddr, dstAddr); 
	}
	else  if ( prim->type == UTcapPrimitiveType_DAT_IND) 
	{
		ind = &(prim->u.datInd);

		memset(origAddr,0,sizeof(origAddr));
		memset(dstAddr,0,sizeof(dstAddr));

		sig_addr2str( &ind->srcAddr, origAddr );
		sig_addr2str( &ind->dstAddr, dstAddr );

		uaLog( L_INFO,"---PRIMITIVE(TYPE=IND) :\n"
"                         TYPE=%s spDlgId=%d suDlgId=%d\n"
"                         ORG_ADDR : %s\n" 
"                         DST_ADDR : %s", 
			UTCAP_TRANSACTION_STR(ind->msgType), ind->spDlgId, ind->suDlgId,
			origAddr, dstAddr );
	}
	return 0;
}


int sig_printComponent(UTcapComponents *comp)
{
	char op_name[40];

	getOpName( op_name, comp->opCode.len > 0 ? comp->opCode.string[0] : 0 );

	uaLog(L_DBG,"---COMPONENT: TYPE=%s  OPCODE=%s  Invoke_ID=%d",
			UTCAP_COMPONENT_STR(comp->compType),
			op_name,
			(comp->invokeId.pres ? comp->invokeId.octet : 0) );

	if( comp->bufLen > 0 )
	{
		uaLog(L_DBG,"comp->bufLen : %d", comp->bufLen );
		PrintHexStr(comp->bufLen,
			(unsigned char*)comp->cpBuf, 0 );
	}

	return 0;
}

int sig_sendEndErrorMultiComp(
		UTcap *tcapInfo, int acn,
		int prov_id, int invoke_id, int opCode ,
		u_char *para, int paraLen, u_char errCode,
		int opCode2, u_char *para2, int paraLen2)
{
	UTcapPrimitive txPrim;
	UTcapComponents txComp;
	UTcapComponents txComp2;
	int rval, opcode ;

	memset( &txPrim, 0, sizeof(UTcapPrimitive));
	memset( &txComp, 0, sizeof(UTcapComponents));
	memset( &txComp2, 0, sizeof(UTcapComponents));

	/* Inform 두번째 Comp */
	txComp2.suDlgId = 1;
	txComp2.spDlgId = prov_id ;

	/* copy parameter */
	txComp2.bufLen = paraLen2;
	memcpy( txComp2.cpBuf, para2, paraLen2);

	/* set sndonent data */
	txComp2.compType = UTCAP_COMP_INVOKE;

	if( invoke_id >1 )
	{
		txComp2.invokeId.pres = 1 ;
		txComp2.invokeId.octet = invoke_id ;
	}

	txComp2.opClass = 1;
	txComp2.opCodeFlg = UTCAP_LOCAL ;
	txComp2.opCode.len = 1 ;
	txComp2.opCode.string[0] = opCode2 ;
	txComp2.lastCmp = TRUE;

	uaLog( L_MIN, "opCode - [%d:%d:%d]",
			txComp2.opCodeFlg, txComp2.opCode.len, txComp2.opCode.string[0]);

	/* send component */
	if ( (rval = utcap_putComp( tcapInfo, txComp2.suDlgId, txComp2.spDlgId, &txComp2)) < 0) {
		uaLog( L_MAJ, "utcap_putComp failed did=%d opcode=%d, rval=%d",
				txComp2.suDlgId, opCode2, rval);
		return -1;
	}

	/* Sri Nack 시 첫번째 comp */
	txComp.suDlgId = 1;
	txComp.spDlgId = prov_id ;

	/* copy parameter */
	txComp.bufLen = paraLen;
	memcpy( txComp.cpBuf, para, paraLen);

	/* set sndonent data */
	txComp.compType = UTCAP_COMP_ERROR;

	if( invoke_id >1 )
	{
		txComp.invokeId.pres = 1 ;
		txComp.invokeId.octet = invoke_id ;
	}

	txComp.opCodeFlg = UTCAP_LOCAL ;
	txComp.opCode.len = 1 ;
	txComp.opCode.string[0] = opCode ;

	/* set error code */
	txComp.errorCodeFlg = UTCAP_LOCAL ;
	txComp.errorCode.len = 1;
	txComp.errorCode.string[0] = errCode;

	uaLog( L_MIN, "opCode - [%d:%d:%d] Error - [%d:%d:%d] ",
			txComp.opCodeFlg, txComp.opCode.len, txComp.opCode.string[0],
			txComp.errorCodeFlg, txComp.errorCode.len, txComp.errorCode.string[0] );
 
	/* send component */
	if ( (rval = utcap_putComp( tcapInfo, txComp.suDlgId, txComp.spDlgId, &txComp)) < 0) {
		uaLog( L_MAJ, "utcap_putComp failed did=%d, rval=%d",
				txComp.suDlgId, rval);
		return -1;
	}

	/* set primitive */
	txPrim.type = UTcapPrimitiveType_DAT_REQ;

	txPrim.u.datReq.msgType = UTCAP_END;
	txPrim.u.datReq.suDlgId = txComp.suDlgId;
	txPrim.u.datReq.spDlgId = txComp.spDlgId;

	setDialogPortion( acn, &txPrim.u.datReq.dlgEv, 0);

	if ( (rval = utcap_send( tcapInfo, &txPrim)) < 0) {
		uaLog( L_MAJ, "utcap_send failed opcode=%d");
		return -1;
	}

	return 0;
}

int sig_sendEndMultiComp( 
		UTcap *tcapInfo, int acn,
		int prov_id, int invoke_id, int opCode ,
		u_char *para, int paraLen, u_char errCode,
		int opCode2, u_char *para2, int paraLen2)
{
	UTcapPrimitive txPrim;
	UTcapComponents txComp;
	UTcapComponents txComp2;
	int rval, opcode ;

	memset( &txPrim, 0, sizeof(UTcapPrimitive));
	memset( &txComp, 0, sizeof(UTcapComponents));
	memset( &txComp2, 0, sizeof(UTcapComponents));

	/* Inform 두번째 Comp */
	txComp2.suDlgId = 1;
	txComp2.spDlgId = prov_id ;

	/* copy parameter */
	txComp2.bufLen = paraLen2;
	memcpy( txComp2.cpBuf, para2, paraLen2);

	/* set sndonent data */
	txComp2.compType = UTCAP_COMP_INVOKE;

	if( invoke_id >1 )
	{
		txComp2.invokeId.pres = 1 ;
		txComp2.invokeId.octet = invoke_id ;
	}

	txComp2.opClass = 1;
	txComp2.opCodeFlg = UTCAP_LOCAL ;
	txComp2.opCode.len = 1 ;
	txComp2.opCode.string[0] = opCode2 ;
	txComp2.lastCmp = TRUE;

	uaLog( L_MIN, "opCode - [%d:%d:%d]",
			txComp2.opCodeFlg, txComp2.opCode.len, txComp2.opCode.string[0]);

	/* send component */
	if ( (rval = utcap_putComp( tcapInfo, txComp2.suDlgId, txComp2.spDlgId, &txComp2)) < 0) {
		uaLog( L_MAJ, "utcap_putComp failed did=%d opcode=%d, rval=%d",
				txComp2.suDlgId, opCode2, rval);
		return -1;
	}
	
	/* Sri Nack 시 첫번째 comp */
	txComp.suDlgId = 1;
	txComp.spDlgId = prov_id ;

	/* copy parameter */
	txComp.bufLen = paraLen;
	memcpy( txComp.cpBuf, para, paraLen);

	/* set sndonent data */
	txComp.compType = UTCAP_COMP_RET_RES_L;

	if( invoke_id >1 )
	{
		txComp.invokeId.pres = 1 ;
		txComp.invokeId.octet = invoke_id ;
	}
	else {
		txComp.invokeId.pres = 0;
	}

	txComp.opClass = 1;
	txComp.opCodeFlg = UTCAP_LOCAL ;
	txComp.opCode.len = 1 ;
	txComp.opCode.string[0] = opCode ;
	txComp.lastCmp = FALSE;

	uaLog( L_INFO, "opCode - [%d:%d:%d] ",
			txComp.opCodeFlg, txComp.opCode.len, txComp.opCode.string[0]);

	/* send component */
	if ( (rval = utcap_putComp( tcapInfo, txComp.suDlgId, txComp.spDlgId, &txComp)) < 0) {
		uaLog( L_MAJ, "utcap_putComp failed did=%d, rval=%d",
				txComp.suDlgId, rval);
		return -1;
	}

	/* set primitive */
	txPrim.type = UTcapPrimitiveType_DAT_REQ;

	txPrim.u.datReq.msgType = UTCAP_END;
	txPrim.u.datReq.suDlgId = txComp.suDlgId;
	txPrim.u.datReq.spDlgId = txComp.spDlgId;

	setDialogPortion( acn, &txPrim.u.datReq.dlgEv, 0);

	if ( (rval = utcap_send( tcapInfo, &txPrim)) < 0) {
		uaLog( L_MAJ, "utcap_send failed opcode=%d");
		return -1;
	}

	return 0;
}



void Print_Primitive(UTcapPrimitive *prim)
{
	int             gtLen;
	char            buf[1024];
	char            str[64];

	uaLog( L_DBG, "\t---------- Primitive ------------");
	uaLog( L_DBG, "\tprim->p_type : [%s]", UTCAP_TRANSACTION_STR(prim->u.datInd.msgType));
	uaLog( L_DBG, "\tprim->suDlgId : [%d]", prim->u.datInd.suDlgId);
	uaLog( L_DBG, "\tprim->spDlgId : [%d]", prim->u.datInd.spDlgId);
	uaLog( L_DBG, "\tprim->dstAddr.pc : [0x%x %d]", prim->u.datInd.dstAddr.pc, prim->u.datInd.dstAddr.pc);
	uaLog( L_DBG, "\tprim->dstAddr.ssn : [0x%x %d]", prim->u.datInd.dstAddr.ssn, prim->u.datInd.dstAddr.ssn);
	uaLog( L_DBG, "\tprim->srcAddr.pc : [0x%x %d]", prim->u.datInd.srcAddr.pc, prim->u.datInd.srcAddr.pc);
	uaLog( L_DBG, "\tprim->srcAddr.ssn : [0x%x %d]", prim->u.datInd.srcAddr.ssn, prim->u.datInd.srcAddr.ssn);
	uaLog( L_DBG, "\tprim->compsPres : [%d]", prim->u.datInd.compsPres);
	uaLog( L_DBG, "\tprim->dlgEv.pres : [%d]", prim->u.datInd.dlgEv.pres);
	uaLog( L_DBG, "\tprim->dlgEv.dlgType : [%d]", prim->u.datInd.dlgEv.dlgType);
	uaLog( L_DBG, "\tprim->dlgEv.resPres : [%d]", prim->u.datInd.dlgEv.resPres);
	uaLog( L_DBG, "\tprim->dlgEv.result : [%d]", prim->u.datInd.dlgEv.result);
	uaLog( L_DBG, "\tprim->bufLen : [%d]", prim->u.datInd.bufLen);
	uaLog( L_DBG, "\t------------------------------");

	return;
}

void Print_Component(UTcapComponents  *comp)
{
	uaLog( L_DBG, "\t---------- Component ------------");
	uaLog( L_DBG, "\tcomp->compType : [%s]", UTCAP_COMPONENT_STR(comp->compType) ) ;
	uaLog( L_DBG, "\tcomp->suDlgId : [%d]", comp->suDlgId ) ;
	uaLog( L_DBG, "\tcomp->invokeId.pres : [%d]", comp->invokeId.pres ) ;
	uaLog( L_DBG, "\tcomp->invokeId.octet : [%d]", comp->invokeId.octet ) ;
	uaLog( L_DBG, "\tcomp->invokeTimer : [%d]", comp->invokeTimer ) ;
	uaLog( L_DBG, "\tcomp->opCode.len : [%d]", comp->opCode.len ) ;
	uaLog( L_DBG, "\tcomp->opCode.string[0] : [%d]", comp->opCode.string[0] ) ;
	uaLog( L_DBG, "\tcomp->errCode.len : [%d]", comp->errorCode.len ) ;
	uaLog( L_DBG, "\tcomp->errCode.string[0] : [%d]", comp->errorCode.string[0] ) ;
	uaLog( L_DBG, "\tcomp->invokeTimer : [%d]", comp->invokeTimer ) ;
	uaLog( L_DBG, "\tcomp->bufLen : [%d]", comp->bufLen ) ;
	return;
}

int setRouteAddr(unsigned char routeType, USccpAddr *dest, USccpAddr *orig, 
		int origPc, int origSsn, char *myIsdn, int nodePc, int nodeSsn,
		char *nodeIsdn, char *destIsdn, int nodeType)
{
	/* setRouteAddr() : orig, dest에 routeType에 따라 필요한 정보 설정
	   routeType = PC ==> dest, orig는 PC와 SSN으로 설정
	   routeType = SYSTEM_GT ==> dest는 HLR isdn으로 설정된 GT 값 + SSN
	   orig는 IPMG isdn으로 설정된 GT 값 + SSN
	   routeType = MSISDN_GT ==> dest는 Dest의 isdn으로 설정된 GT 값 + SSN
	   orig는 IPMG isdn으로 설정된 GT 값 + SSN   */

	unsigned char ssn;
	stAddr ipmgName;
	int myPc, mySsn, baseSsn;

#if 0
	getMyPC(&myPc);
	getMySSN(&mySsn);
#endif
	myPc = origPc;
	mySsn = origSsn;

	if(nodeType == NODE_HLR)
		baseSsn = 6;
	else if(nodeType == NODE_SMSC)
		baseSsn = 11;

	if(routeType == ROUTE_PC)
	{
		dest->ind = USccpAddrInd_ROUTE_ON_SSN_PC;
		dest->ind |= USccpAddrInd_PC_PRESENT;
		dest->ind |= USccpAddrInd_SSN_PRESENT;

		dest->pc = nodePc;
		if(nodeSsn == 0)
			dest->ssn = baseSsn;
		else
			dest->ssn = nodeSsn;

		orig->ind = USccpAddrInd_ROUTE_ON_SSN_PC;
		orig->ind |= USccpAddrInd_PC_PRESENT;
		orig->ind |= USccpAddrInd_SSN_PRESENT;

		orig->pc = myPc;
		orig->ssn = mySsn;

		uaLog(L_INFO, "Routing Method : PC, Dest : pc[%d], ssn[%d]", dest->pc, dest->ssn);
	}
	else if (routeType == ROUTE_SYSTEM_GT)
	{
		if(nodeSsn == 0)
			ssn = baseSsn;
		else
			ssn = nodeSsn;

		sig_makeGT(dest, nodeIsdn, 0, ssn );

		//getIpmgName(&ipmgName);
		strcpy(ipmgName.min, myIsdn);

		if(!strcmp(ipmgName.min, ""))
			sig_makeGT(orig, "", 0, mySsn );
		else
			sig_makeGT(orig, ipmgName.min, 0, mySsn);

		uaLog(L_INFO, "Routing Method : SYSTEM_GT, Dest : ISDN[%d], ssn[%d]", nodeIsdn, dest->ssn);
	}
	else if (routeType == ROUTE_MSISDN_GT)
	{
		if(nodeSsn == 0)
			ssn = baseSsn;
		else
			ssn = nodeSsn;

		sig_makeGT(dest, destIsdn, 0, ssn );

		//getIpmgName(&ipmgName);
		strcpy(ipmgName.min, "8210123456768");
		if(!strcmp(ipmgName.min, ""))
			sig_makeGT(orig, "", 0, mySsn );
		else
			sig_makeGT(orig, ipmgName.min, 0, mySsn);

		uaLog(L_INFO, "Routing Method : MSISDN_GT, Dest : ISDN[%d], ssn[%d]", destIsdn, dest->ssn);
	}
	else
	{
		dest->ind = USccpAddrInd_ROUTE_ON_SSN_PC;
		dest->ind |= USccpAddrInd_PC_PRESENT;
		dest->ind |= USccpAddrInd_SSN_PRESENT;

		dest->pc = nodePc;
		dest->ssn = nodeSsn;

		orig->ind = USccpAddrInd_ROUTE_ON_SSN_PC;
		orig->ind |= USccpAddrInd_PC_PRESENT;
		orig->ind |= USccpAddrInd_SSN_PRESENT;

		orig->pc = myPc;
		orig->ssn = mySsn;

		uaLog(L_INFO, "Routing Method : PC, Dest : pc[%d], ssn[%d]", dest->pc, dest->ssn);
	}



	return IXOK;
}
