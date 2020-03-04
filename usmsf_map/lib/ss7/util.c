
#include <iXtypes.h>
#include <ASN/asn_smsc.h>

#include <SS7/ix7map.h>

#include <iXss7Trace.h>
#include <iXCauseCode.h>


#ifdef USIGTRAN
#include <sigtran_util.h>
#else
#include <TCAP_ccitt.h>
#endif

//#include <iXGCA.h>

extern ObjectID        shortMsgGatewayContext_v3;
extern ObjectID        shortMsgGatewayContext_v2;
extern ObjectID        shortMsgMO_RelayContext_v3;
extern ObjectID        shortMsgMO_RelayContext_v2;
extern ObjectID        shortMsgAlertContext_v2;
extern ObjectID        shortMsgMT_RelayContext_v3;
extern ObjectID        shortMsgMT_RelayContext_v2;


int MakeACN(int *length, char *data, char acn)
{
    if(acn == IS_ACN_NOT_SET)
    {
        *length = 0;
        data[0] = 0;
        return NOTOK;
    }

    if(acn == ACN_GW_V3)
    {
        *length = shortMsgGatewayContext_v3.length;
        memcpy(data, shortMsgGatewayContext_v3.value, *length);
        return IXOK;
    }
    else if(acn == ACN_GW_V2)
    {
        *length = shortMsgGatewayContext_v2.length;
        memcpy(data, shortMsgGatewayContext_v2.value, *length);
        return IXOK;
    }
    else if(acn == ACN_MO_V3)
    {
        *length = shortMsgMO_RelayContext_v3.length;
        memcpy(data, shortMsgMO_RelayContext_v3.value, *length);
        return IXOK;
    }
	else if(acn == ACN_MO_V2)
    {
        *length = shortMsgMO_RelayContext_v2.length;
        memcpy(data, shortMsgMO_RelayContext_v2.value, *length);
        return IXOK;
    }
    else if(acn == ACN_MT_V3)
    {
        *length = shortMsgMT_RelayContext_v3.length;
        memcpy(data, shortMsgMT_RelayContext_v3.value, *length);
        return IXOK;
    }
    else if(acn == ACN_MT_V2)
    {
        *length = shortMsgMT_RelayContext_v2.length;
        memcpy(data, shortMsgMT_RelayContext_v2.value, *length);
        return IXOK;
    }
    else if(acn == ACN_ALERT_V2)
    {
        *length = shortMsgAlertContext_v2.length;
        memcpy(data, shortMsgAlertContext_v2.value, *length);
        return IXOK;
    }
	else if(acn == ACN_READY_V3)
	{
		*length = mwdMngtContext_v3.length;
		memcpy(data, mwdMngtContext_v3.value, *length);
		return IXOK;
	}
	else if(acn == ACN_ATM_V3) //added by Charge
	{
		*length = anyTimeInfoHandlingContext_v3.length;
		memcpy(data, anyTimeInfoHandlingContext_v3.value, *length);
		return IXOK;
	}

    *length = 0;
    data[0] = 0;
    return IXERR;
}


/* bhtak 2004/8/2
 * for performance
 * */
int CheckACN( int dlgFlag, unsigned char *acn, int len)
{
	if ( dlgFlag == 0) 
		return IS_ACN_NOT_SET;

	if ( len != 7)
        return IS_ACN_NOT_SET;

	switch ( acn[5] ) {
	case 0x14 : 
	/*
	ObjectID shortMsgGatewayContext_v3 = {
		7,
		{ 0x04, 0x00, 0x00, 0x01, 0x00, 0x14, 0x03 }
	};
	ObjectID shortMsgGatewayContext_v2 = {
		7,
		{ 0x04, 0x00, 0x00, 0x01, 0x00, 0x14, 0x02 }
	};
	*/
		if ( acn[6] == 0x03 )
			return ACN_GW_V3;
		if ( acn[6] == 0x02 )
			return ACN_GW_V2;
		break;
	/*
	ObjectID shortMsgMO_RelayContext_v3 = {
		7,
		{ 0x04, 0x00, 0x00, 0x01, 0x00, 0x15, 0x03 }
	};
	*/
	case 0x15 :
		if ( acn[6] == 0x03)
			return ACN_MO_V3;
		if ( acn[6] == 0x02)
			return ACN_MO_V2;
		break;

	/*
	ObjectID shortMsgMT_RelayContext_v3 = {
		7,
		{ 0x04, 0x00, 0x00, 0x01, 0x00, 0x19, 0x03 }
	};
	*/
	case 0x19 :
		if ( acn[6] == 0x03)
			return ACN_MT_V3;
		if ( acn[6] == 0x02)
			return ACN_MT_V2;
		break;

	/*
	ObjectID shortMsgAlertContext_v2 = {
		7,
		{ 0x04, 0x00, 0x00, 0x01, 0x00, 0x17, 0x02 }
	};
	*/
	case 0x17:
		if ( acn[6] == 0x02)
			return ACN_ALERT_V2;
		break;

	case 0x2B:
		if ( acn[6] == 0x03)
			return ACN_ATM_V3;
		break;
		
	case 0x18:
		if( acn[6] == 0x03)
			return ACN_READY_V3;
		break;

	default:
		return IS_ACN_NOT_SET;
		break;
	}

	return IS_ACN_FAIL;
}


#if 0
/* Table : SMSC, MSC, SGSN */
int UpdateACNOnTable(char nodeType, char *isdn, char oldVer, char acn)
{
	char cvtVer;
	int  ret;

	if(acn == ACN_MT_V1 || acn == ACN_GW_V1 || acn == ACN_MO_V1)
		cvtVer = MAP_VERSION_1;
	else if(acn == ACN_MT_V2 || acn == ACN_GW_V2 || acn == ACN_MO_V2)
		cvtVer = MAP_VERSION_2;
	else if(acn == ACN_MT_V3 || acn == ACN_GW_V3 || acn == ACN_MO_V3)
		cvtVer = MAP_VERSION_3;
	else
		cvtVer = UNSUPPORTED_ACN_VERSION;

	if(nodeType == NODE_SMSC) 
		UpdateSMSCAcnVersion(isdn, cvtVer);
	else if(nodeType == NODE_MSC || nodeType == NODE_SGSN)
		UpdateMscSgsnAcnVersion(isdn, cvtVer);

	if(cvtVer != UNSUPPORTED_ACN_VERSION && cvtVer != oldVer)
		return cvtVer;

	return IXERR;
}
#endif




char *getACName( int acnIdx)
{
	switch ( acnIdx) {
	case ACN_GW_V3:
		return  "shortMsgGatewayContext_v3";
	case ACN_GW_V2:
		return  "shortMsgGatewayContext_v2";
	case ACN_MO_V3:
		return "shortMsgMO_RelayContext_v3";
	case ACN_MO_V2:
		return "shortMsgMO_RelayContext_v2";
	case ACN_MT_V3:
		return "shortMsgMT_RelayContext_v3";
	case ACN_MT_V2:
		return "shortMsgMT_RelayContext_v2";
	case ACN_ALERT_V2:
		return "shortMsgAlertContext_v2";
	case ACN_ATM_V3:
		return "anyTimeModificationContext_v3"; //added by Charge
	default:
		return "unknown";
	}

	return "unknown";
}


/* return error code index */
int getErrCodeIndexCDMA( int code)
{
	static int first = 1;
	static char errIdx[256];

	if ( first ) {
		int idx = 0;
#define	SET_CDMA_ERR_IDX(a)	errIdx[CC_##a - 2000] = idx++;
		memset( errIdx, 0, sizeof(errIdx));

		SET_CDMA_ERR_IDX( ADDRESS_VACANT)
		SET_CDMA_ERR_IDX( ADDR_TRANS_FAILURE)
		SET_CDMA_ERR_IDX( NW_RESOURCE_SHORTAGE)
		SET_CDMA_ERR_IDX( NETWORK_FAILURE)
		SET_CDMA_ERR_IDX( INVAILD_TELESERVICEID)
		SET_CDMA_ERR_IDX( OTHER_NETWORK_PROBLEM)
		SET_CDMA_ERR_IDX( NO_PAGE_RESPONSE)
		SET_CDMA_ERR_IDX( DESTINATION_BUSY)
		SET_CDMA_ERR_IDX( NO_ACKMOWLEDGEMENT)
		SET_CDMA_ERR_IDX( DEST_RESOURCE_SHORTAGE)
		SET_CDMA_ERR_IDX( SMS_DELIVERY_POSTPHONE)
		SET_CDMA_ERR_IDX( DEST_OUT_OF_SERVICE)
		SET_CDMA_ERR_IDX( DESTINATION_NO_LONGER)
		SET_CDMA_ERR_IDX( OTHER_TERMINAL_PROBLEM)
		SET_CDMA_ERR_IDX( RADIO_IF_RESOURCE_SHORT)
		SET_CDMA_ERR_IDX( RADIO_IF_INCOMPATIBILITY)
		SET_CDMA_ERR_IDX( OTHER_RADIO_IF_PROBLEM)
		SET_CDMA_ERR_IDX( INCODING_PROBLEM)
		SET_CDMA_ERR_IDX( SMS_ORIGINATION_DENIED)
		SET_CDMA_ERR_IDX( SMS_TERMINATION_DENIED)
		SET_CDMA_ERR_IDX( SUPPL_SVC_NOT_SUPPORTED)
		SET_CDMA_ERR_IDX( SMS_NOT_SUPPORTED)
		SET_CDMA_ERR_IDX( MISSING_EXPECTED_PARA)
		SET_CDMA_ERR_IDX( MISSING_MANDATORY_PARA)
		SET_CDMA_ERR_IDX( UNRECOGNIZED_PARA_VALUE)
		SET_CDMA_ERR_IDX( UNEXPECTED_PARA_VALUE)
		SET_CDMA_ERR_IDX( USER_DATA_SIZE_ERROR)
		SET_CDMA_ERR_IDX( OTHER_GENERAL_PROBLEM)
		SET_CDMA_ERR_IDX( ADR_DENIED)
		SET_CDMA_ERR_IDX( ADR_POSTPHONE)
		SET_CDMA_ERR_IDX( ADR_UNAVAILABLE)
		SET_CDMA_ERR_IDX( CDMA_HLR_PORTED_OUT)
		SET_CDMA_ERR_IDX( CDMA_ADR_SPAM)

		first = 0;
	}

	if ( code >= 2000) code -= 2000;
	if ( code < 0 || code >= 256) {
		//uaLog(L_CRT,"err_Code[%d] Invalid.", code );
		return 0;
	}

	return errIdx[code];
}

int getErrCodeIndexGSM( int code)
{
	static int first = 1;
	static char errIdx[256];

	if ( first ) {
		/* idx 를 1로 초기화 하는 이유는 
		   아래 정의된 error code 외의 error code의 경우는 
		   idx = 0 에 count 하기 위해서 이다. 
		   comment by comus 2007/04/06
		 */
		int idx = 1;
		/*int idx = 0; */
#define	SET_GSM_ERR_IDX(a)	errIdx[CC_##a - 3000] = idx++;
		memset( errIdx, 0, sizeof(errIdx));

		SET_GSM_ERR_IDX(UNKNOWN_SUBSCRIBER)
		SET_GSM_ERR_IDX(ABSENT_SUBSCRIBER_SM)
		SET_GSM_ERR_IDX(ILLEGAL_SUBSCRIBER)
		SET_GSM_ERR_IDX(TELESERVICE_NOT_PROVISIONED)
		SET_GSM_ERR_IDX(ILLEGALEQUIPMENT)

		SET_GSM_ERR_IDX(CALL_BARRED)
		SET_GSM_ERR_IDX(FACILITY_NOT_SUPPORTED)
		SET_GSM_ERR_IDX(ABSENT_SUBSCRIBER)
		SET_GSM_ERR_IDX(INCOMPATIBLE_TERMINAL)
		SET_GSM_ERR_IDX(SUBSCRIBER_BUSY_FOR_MT_SMS)

		SET_GSM_ERR_IDX(SM_DELIVERY_FAILURE)
		SET_GSM_ERR_IDX(MESSAGE_WAITING_LIST_FULL)
		SET_GSM_ERR_IDX(SYSTEM_FAILURE)
		SET_GSM_ERR_IDX(DATA_MISSING)
		SET_GSM_ERR_IDX(UNEXPECTED_DATA_VALUE)

		SET_GSM_ERR_IDX(BUSY_SUBSCRIBER)
		SET_GSM_ERR_IDX(RESOURCE_LIMITATION)
		SET_GSM_ERR_IDX(UNKNOWN_ALPHABET)
		SET_GSM_ERR_IDX(GSM_HLR_PORTED_OUT)
		SET_GSM_ERR_IDX(GSM_ADR_SPAM) 
		//Error 추가 시, cc_stat.conf 같이 수정 할 것!

		first = 0;
	}

	/* YTL 1.7.4 PKG */
	if (code >= CC_NPR3G_CS && code <= CC_UNIDENTIFIED_PS)
		code = CC_ABSENT_SUBSCRIBER_SM ;
	else if (code >= CC_MCEF && code <= CC_NOT_SC_SUBSCRIBER)
		code = CC_SM_DELIVERY_FAILURE;    

	if ( code >= 3000) code -= 3000;
	if ( code < 0 || code >= 256) {
		//uaLog(L_CRT,"err_Code[%d] Invalid.", code );
		return 0;
	}

	return errIdx[code];
}

#if 0
int getNodeFromSrcAddr(
		stNodeNumber 			*node , 
		stHLR                   *hlrInfo,
		stSMSC					*smscInfo,
		stMscSgsn				*nodeInfo)
{

	bzero((void *)hlrInfo, sizeof(stHLR));
	bzero((void *)nodeInfo, sizeof(stMscSgsn));
	bzero((void *)smscInfo, sizeof(stSMSC));

	if(node->isdn[0] != '\0') 
	{
		strcpy(hlrInfo->isdn, node->isdn);
		strcpy(nodeInfo->isdn, node->isdn);
	}

	hlrInfo->pCode = node->pCode;
	hlrInfo->ssn = node->ssn;

	nodeInfo->pCode = node->pCode;
	nodeInfo->ssn   = node->ssn;

	smscInfo->pCode = node->pCode;
	//nodeInfo->ssn   = node->ssn;
	smscInfo->ssn   = node->ssn;

	if(GetMscSgsn(nodeInfo) == IXOK)
	{
		strcpy(node->isdn, nodeInfo->isdn);
		node->pCode    = nodeInfo->pCode;
		node->ssn      = nodeInfo->ssn;
		if(nodeInfo->nodeType == MSC_SGSN_NODE_MSC)
			node->nodeType = NODE_MSC;
		else
			node->nodeType = NODE_SGSN;
	}
	else if(GetHLR(hlrInfo) == IXOK)
	{
		strcpy(node->isdn, hlrInfo->isdn);
		node->pCode    = hlrInfo->pCode;
		node->ssn      = hlrInfo->ssn;
		node->nodeType = NODE_HLR;
	}
	else if(GetSMSC(smscInfo) == IXOK)
	{
		strcpy(node->isdn, smscInfo->isdn);
		node->pCode    = smscInfo->pCode;
		node->ssn      = smscInfo->ssn;
		node->nodeType = NODE_SMSC;
	}
	else
		node->nodeType = NODE_UNKNOWN;

	return IXOK;
}
#endif

#if 0
int UpdateAcvVersionNego(stNodeNumber  *node ,  unsigned char acn )
{
	if(node->nodeType == NODE_MSC)
	{
		if(acn == ACN_MO_V3)
			UpdateMSC_AcnVersion(node->isdn, MAP_VERSION_3);
		else if(acn == ACN_MO_V2)
			UpdateMSC_AcnVersion(node->isdn, MAP_VERSION_2);
	}
	else if(node->nodeType == NODE_SGSN)
	{
		if(acn == ACN_MO_V3)
			UpdateSGSN_AcnVersion(node->isdn, MAP_VERSION_3);
		else if(acn == ACN_MO_V2)
			UpdateSGSN_AcnVersion(node->isdn, MAP_VERSION_2);
	}

	return IXOK ;
}
#endif



#ifndef USIGTRAN
int ConvGtToAddress(tc_global_title *gt, stAddr *addr)
{
	int                       n = 0;

	if(gt->nature == tc_international_nb)
		addr->ton = TON_INTERNATIONAL;
	else if(gt->nature == tc_national_nb)
		addr->ton = TON_NATIONAL;
	else
	{
		addr->min[0] = 0;
		addr->len = 0;
		return IXERR;
	}

	addr->npi = NPI_E164;

    strcpy(addr->min, gt->digit);
    addr->len = strlen(addr->min);

    return IXOK;
}

int MakeGT(tc_global_title *gt, char *isdn, int translation)
{
	int                    i;

	gt->routeOnGt = TC_YES;
	gt->gtIndicator = tc_gt_type4;
	gt->translation = translation;
	gt->numbering = tc_num_isdn;
    gt->nature = tc_international_nb;

    strcpy(gt->digit, isdn);
    if((strlen(isdn) % 2) == 0)
        gt->encoding = tc_bcd_even;
    else
        gt->encoding = tc_bcd_odd;

    return IXOK;
}


int EncodeError(tc_error *error, int errCode)
{
    bzero((void *)error, sizeof(tc_error));
    error->tag = LOCAL_TYPE;
    error->length = 1;
    error->datas[0] = errCode;
    return IXOK;
}


int DecodeError(int *errCode, tc_error *error)
{
    if(error->tag == LOCAL_TYPE)
    {
        *errCode = error->datas[0];
        return IXOK;
    }
    else
    {
        *errCode = 0;
        return IXERR;
    }
}


int MakeOperationCode(tc_operation *op, int opCode)
{
    if(opCode < 0)
        bzero((void *)op, sizeof(tc_operation));
    else
    {
        op->tag = LOCAL_TYPE;
        op->length = 1;
        op->datas[0] = (char)opCode;
    }

    return IXOK;
}


int MakeDialoguePortion(tc_dialog_portion *dp, tc_primitive_type p_type,
						char acn)
{
    int          acn_length;
    char         acn_datas[MAX_FIELD];    /* 100 in TCAP_common.h */

	acn_length = 0;
	bzero((void *)acn_datas, sizeof(acn_datas));
	
    MakeACN(&acn_length, acn_datas,acn);

	if(p_type != TC_U_ABORT && acn_length !=0)
	{
		dp->dlg_info_present = TC_YES; 
		dp->application_context_name.length = acn_length; 
		memcpy(dp->application_context_name.data, acn_datas, acn_length);
		dp->user_information.length = 0;
	}
	else
		dp->dlg_info_present = TC_NO; 

	return IXOK;
}
#endif


