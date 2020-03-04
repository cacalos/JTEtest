#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
//getpid
#include <sys/types.h>
//getpid
#include <unistd.h>

#include "iXtypes.h"
#include "ua_log.h"
#include "iXCauseCode.h"
#include "ASN/asn_smsc.h"
#include "SS7/ix7map.h"
#include "SS7/map2.h"
#include "sigtran_util.h"
#include "iXLog.h"
#include <TPDU/TPDU.h>

#include <ua_log.h>
#include <ua_macro.h>

#define SMSC_CONF_FILE_PATH "./smsc.conf"
#define PARAM_BUFFER_SIZE 1024

#define APP_ID_HLR3 2
#define APP_ID_HLR2 3
#define APP_ID_MSC3 4
#define APP_ID_MSC2 5
#define APP_ID_SGSN 6
#define APP_ID_SMSC 7

#define INS_ID_NODE 1
#define INS_ID_ALERT 2
#define INS_ID_MO 3

int	gLogId;
int gUid = 0;
int gVersion = 2;
int gCnxId;
int MyPC;
int MySSN = 8;
int gnMtfReq = 0;
int gnMtfAck = 0;
int gnMtfNack = 0;
int gNack;
int gError;
int gZero;
int gAdr;
char StackName[20]  = "SS7_Stack";

/* OSS Global */
OssBuf param;
struct ossGlobal w, *world = &w;

/* for sigtran */
UTcap *gTcapInfo;


void CloseProc()
{
    exit(0);
}

int power(int x, int y)
{
    int i, num;

    if(y == 0)
        return (0);

    for(i = 1, num = 1; i <= y; i++)
       num = num * x;
    return num;
}

void IntWriteString(char *dest, int source, int n)
{
	int        i;

	if(source < 0)
	{
		dest[0] = 0;
		return;
	}

	for(i = 1; i < n; i++)
	{
		dest[i-1] = '0' + source / power(10, n - i);
		source %= power(10, n - i);
	}
	dest[i-1] = '0' + source;
}

int getConf(char *file, char *conf, char *data)
{
    FILE      *fp;
    char       buf[128];
    char      *token, *last;

    if((fp = fopen(file, "r")) == NULL)
        return -1;

    while(fgets(buf, 128, fp) != NULL)
    {
        if(buf[0] == '#' || buf[0] == '\n')
            continue;

        token = (char *)strtok_r(buf, " =\t\n", &last);
        if(strcasecmp(token, conf) == 0)
        {
            token = (char *)strtok_r(NULL, " =\t\n", &last);
            strcpy(data, token);

            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return -1;
}


int GetMscConf(char *file)
{
    char               buf[64];

    if(getConf(file, "STACK_NAME", buf) < 0)
    {
        printf("Conf: can't find 'STACK_NAME' item in <%s>\n", file);
        return -1;
    }
    else
        strcpy(StackName, buf);

    if(getConf(file, "MY_PCODE", buf) < 0)
    {
        printf("Conf: can't find 'MY_PCODE' item in <%s>\n", file);
        return -1;
    }
    else
        MyPC = (int)atoi(buf);

    if(getConf(file, "MY_SSN", buf) < 0)
    {
        printf("Conf: can't find 'MY_SSN' item in <%s>\n", file);
        MySSN = 8;
    }
    else
        MySSN = (int)atoi(buf);

	printf("MY_PCODE : %d, MY_SSN : %d\n", MyPC, MySSN);


    if(getConf(file, "NACK_RATE", buf) < 0)
    {
        printf("Conf: can't find 'NACK_RATE' item in <%s>\n", file);
        gNack = 0;
    }
    else
    {
        gNack = (int)atoi(buf);
        if(gNack < 0 || gNack > 10)
            gNack = 0;
    }

	if(getConf(file, "ERROR_CODE", buf) < 0)
	{
		printf("Conf: can't find 'ERROR_CODE' item in <%s>\n", file);
		return -1;
	}
	else if(!strcasecmp(buf, "CC_ABSENT_SUBSCRIBER_SM"))
		gError = CC_ABSENT_SUBSCRIBER_SM - 3000;
	else if(!strcasecmp(buf, "CC_SM_DELIVERY_FAILURE"))
		gError = CC_SM_DELIVERY_FAILURE- 3000;
	else if(!strcasecmp(buf, "CC_SYSTEM_FAILURE"))
		gError = CC_SYSTEM_FAILURE- 3000;
    else if(strlen(buf) == 4) {
	    gError  = atoi(buf);
    }
	else
		return -1;

	if(getConf(file, "MAP_VERSION", buf) < 0)
	{
		printf("Conf: can't find 'MAP_VERSION' item in <%s>\n", file);
		return -1;
	}
	else
		gVersion = (int)atoi(buf);

	if(getConf(file, "PARAM_ZERO", buf) < 0)
	{
		printf("Conf: can't find 'PARAM_ZERO' item in <%s>\n", file);
		gZero = 0;
	}
	else
		gZero = (int)atoi(buf);

    return 1;
}


int TransImsiToMsisdn(IMSI *imsi, stAddr *addr)
{
    ConvIMSIToAddress(imsi, addr);
    addr->min[0] = '0';
    return 1;
}


int TransMsisdnToImsi(stAddr *addr, IMSI *imsi)
{
    addr->min[0] = '9';
    ConvAddressToIMSI(addr, imsi);
    return 1;
}


int TransLmsiToMsisdn(LMSI *lmsi, stAddr *addr)
{
    int nLMSI;

    memcpy((int *)&nLMSI, lmsi->value, 4);
    IntWriteString(addr->min, nLMSI, 10);
    addr->min[10] = 0;
    addr->ton = 1;
    addr->npi = 1;
    addr->len = 10;
    return 1;
}


int TransMsisdnToLmsi(stAddr addr, LMSI *lmsi)
{
    int n;
    char min[11];

    memcpy(min, addr.min, addr.len);
    min[10] = 0;
    n = atoi(min);
    memcpy(lmsi->value, (int *)&n, 4);
    lmsi->length = 4;
    return 1;
}


int SendMtfAck2(UTcapPrimitive *prim, ForwardSM_Arg_V2 *Mtf, int u_id,
        int prov_id, int inv_id, int isACN, int diagId)
{
    int opCode;

    /*
    MakeOperationCode(&operation, forwardSM_V2.u.localValue);
    */


#if 0
    if (isACN == MAP_VERSION_2)
    {
        opCode = forwardSM_V2.u.localValue ;
        ret = ossEncode(world, ForwardSM_Arg_V2_PDU, Mtf, &param);
    }
    else
    {
        opCode = mt_forwardSM_V3.u.localValue ;
        ret = ossEncode(world, MT_ForwardSM_Res_V3_PDU, Mtf, &param);
    }
#endif

	opCode = forwardSM_V2.u.localValue ;

#if 0 
	ret = ossEncode(world, ForwardSM_Arg_V2_PDU, Mtf, &param);

    if(ret)
    {
        uaLog(L_MAJ,  "ossEncode error: %s", ossGetErrMsg(world));
        return IXERR;
    }

    ptr = (char *)param.value;
    ossFreeBuf(world, ptr);
#endif

	/*
    dstAddr.ind = USccpAddrInd_ROUTE_ON_SSN_PC | USccpAddrInd_PC_PRESENT | USccpAddrInd_SSN_PRESENT  ;
    dstAddr.pc = MyPC;
    dstAddr.ssn = 11;

    srcAddr.ind = USccpAddrInd_ROUTE_ON_SSN_PC | USccpAddrInd_PC_PRESENT | USccpAddrInd_SSN_PRESENT ;
    srcAddr.pc = MyPC;
    srcAddr.ssn = MySSN;
	*/
	
#if 0
    ret = sig_sendBeginInvoke( MPOS, &srcAddr, &dstAddr, gTcapInfo,
          opCode, u_id, &provId, MyPC, MySSN, MyPC, MySSN,
          param.value, param.length, MAP_VERSION_2 ) ;

    *prov_id = provId ;
#endif

	param.length = 0;
	param.value = NULL;

    if(Mtf->bit_mask & ForwardSM_Arg_V2_moreMessagesToSend_present)
	{
		if( sig_sendContinueResult( gTcapInfo, opCode, diagId, NULL, NULL, 0,
			(unsigned char *)param.value, param.length
			, inv_id, prov_id) == UTCAP_RETURN_OK )
		{
			printf("\n CONTINUE Diag %d sent\n", u_id ) ;
		}
		else
		{
			printf("\n CONTINUE Diag %d sent failed (diagId[%d] prov_id[%d] inv_id[%d])...1\n"
					, u_id, diagId, prov_id, inv_id ) ;
		}
	}
    else
	{
		if(sig_sendEndResultComplex(gTcapInfo, isACN, prov_id, inv_id,  opCode, (unsigned char *)param.value, param.length ) == UTCAP_RETURN_OK)
		{
			/*
			printf("\n Diag %d sent\n", u_id ) ;
			*/
		}
		else
		{
			printf("\n Diag %d sent failed\n", u_id ) ;
		}
	}


#if 0 

    bzero((void *)&dp, sizeof(tc_dialog_portion));

    if(isACN != IS_ACN_NOT_SET && isACN != IS_ACN_FAIL)
    {
        dp.dlg_info_present = TC_YES;
		memcpy(&dp, &gdp, sizeof(gdp));
        /*MakeACN(&dp.application_context_name.length,
            dp.application_context_name.data, isACN);*/
    }
    else
	{
		dp.dlg_info_present = TC_YES;
		memcpy(&dp, &gdp, sizeof(gdp));
		/*MakeACN(&dp.application_context_name.length,
			dp.application_context_name.data, */
        //dp.dlg_info_present = TC_NO;
	}

    if(Mtf->bit_mask & ForwardSM_Arg_V2_moreMessagesToSend_present)
        /*ret = send_messageSim(gCnxId, TC_CONTINUE, &dp, &dest_addr, &orig_addr,
            u_id == 0 ? gUid : u_id, prov_id, gDebug);*/
        ret = send_message(gCnxId, TC_CONTINUE, &dp, &dest_addr, &orig_addr,
            U_id == 0 ? gUid : u_id, prov_id);
    else
        /*ret = send_messageSim(gCnxId, TC_END, &dp, &dest_addr, &orig_addr,
            u_id == 0 ? gUid : u_id, prov_id, gDebug); */
        ret = send_message(gCnxId, TC_END, &dp, &dest_addr, &orig_addr,
            u_id == 0 ? gUid : u_id, prov_id);

#endif
	return 0;

}

#if 0
int SendMtfAck3(UTcapPrimitive *prim, UTcapComponents *comp,
		MT_ForwardSM_Arg_V3 *Mtf, int u_id,
		int prov_id, int inv_id, int isACN)
{
	int                            ret, opCode, acn;
	int                            comp_len;
	int                            acn_length;
	char                           acn_datas[100];
	stAddr                         addr;
	USccpAddr                      dest;
	USccpAddr                      orig;

	param.length = 0;
	param.value = NULL;

	opCode = mt_forwardSM_V3.u.localValue ;


	memcpy(&dest, &prim->u.datReq.srcAddr, sizeof(USccpAddr));
	memcpy(&orig, &prim->u.datReq.dstAddr, sizeof(USccpAddr));

	if(Mtf->bit_mask & MT_ForwardSM_Arg_V3_moreMessagesToSend_present)
	{
		if( sig_sendContinueResult( LPOS, NULL, NULL, gTcapInfo, IS_ACN_NOT_SET,
					prov_id, inv_id,  opCode,
					(u_char *)param.value, param.length ) == UTCAP_RETURN_OK )
		{
			printf("\n CONTINUE Diag %d sent\n", u_id ) ;
		}
		else
		{
			printf("\n CONTINUE Diag %d sent failed\n", u_id ) ;
		}
	}
	else
	{
		if( sig_sendEndResult( gTcapInfo, acn, prim, comp,
					(u_char *)param.value, param.length ) == UTCAP_RETURN_OK )
		{
			printf("\n Diag %d sent\n", u_id ) ;
		}
		else
		{
			printf("\n Diag %d sent failed\n", u_id ) ;
		}
	}
}
#endif
int SendMofAck3(UTcapPrimitive *prim, int u_id, int prov_id, int inv_id, int isACN, int diagId)
{
	int opCode;

	param.length = 0;
	param.value = NULL;

	opCode = mo_forwardSM_V3.u.localValue ;

#if 0
	ret = ossEncode(world, MT_ForwardSM_Res_V3_PDU, Mtf, &param);

    if(ret)
    {
        uaLog(L_MAJ,  "ossEncode error: %s", ossGetErrMsg(world));
        return IXERR;
    }

    ptr = (char *)param.value;
    ossFreeBuf(world, ptr);
#endif

	/*
    dstAddr.ind = USccpAddrInd_ROUTE_ON_SSN_PC | USccpAddrInd_PC_PRESENT | USccpAddrInd_SSN_PRESENT  ;
    dstAddr.pc = MyPC;
    dstAddr.ssn = 11;

    srcAddr.ind = USccpAddrInd_ROUTE_ON_SSN_PC | USccpAddrInd_PC_PRESENT | USccpAddrInd_SSN_PRESENT ;
    srcAddr.pc = MyPC;
    srcAddr.ssn = MySSN;
	*/
	
#if 0
    if( sig_sendEndResult( MPOS, NULL, NULL, gTcapInfo, IS_ACN_NOT_SET,
        prov_id, inv_id,  opCode,
        (u_char *)param.value, param.length ) == UTCAP_RETURN_OK )
    {
        printf("\n Diag %d sent", u_id ) ;
    }
    else
    {
        printf("\n Diag %d sent failed", u_id ) ;
    }
#endif


#if 0

        if( sig_sendContinueResult( MPOS, NULL, NULL, gTcapInfo, IS_ACN_NOT_SET,
            prov_id, inv_id,  opCode,
            (u_char *)param.value, param.length ) == UTCAP_RETURN_OK )
        {
            printf("\n CONTINUE Diag %d sent", u_id ) ;
        }
        else
        {
            printf("\n CONTINUE Diag %d sent failed", u_id ) ;
        }
#endif
#if  1

		//printf(">>> Send msg provId[%d]\n", prov_id ); 

		if(sig_sendEndResultComplex(gTcapInfo, isACN, prov_id, inv_id,  opCode, (unsigned char *)param.value, param.length ) == UTCAP_RETURN_OK)
		{
			/*
			   printf("\n Diag %d sent (diagId[%d] prov_id[%d] inv_id[%d])..2\n"
			   , u_id, diagId, prov_id, inv_id ) ;
			 */
		}
		else
			printf("\n Diag %d sent failed (diagId[%d] prov_id[%d] inv_id[%d])..2\n" ,u_id, diagId, prov_id, inv_id);

#endif
#if 0
    ret = sig_sendBeginInvoke( MPOS, &srcAddr, &dstAddr, gTcapInfo,
          opCode, u_id, &provId, MyPC, MySSN, MyPC, MySSN,
          param.value, param.length, MAP_VERSION_3 ) ;

    *prov_id = provId ;

#endif

#if 0
    /*
    MakeOperationCode(&operation, mt_forwardSM_V3.u.localValue);
    */
    MakeOperationCode(&operation, -1);

    bzero((void *)&error, sizeof(tc_error));

    param.length = 0;
    param.value = NULL;

    comp_len = build_componentSim(gCnxId, TC_RESULT_L, inv_id, -1,
        u_id == 0 ? ++gUid : u_id, prov_id,
        &operation, 10, (int)param.length, param.value, &error, gDebug);
    if(comp_len < 0)
        return -1;

    memcpy(&dest_addr, &prim->o_address, sizeof(tc_address));
    memcpy(&orig_addr, &prim->d_address, sizeof(tc_address));

    bzero((void *)&dp, sizeof(tc_dialog_portion));

    if(isACN != IS_ACN_NOT_SET && isACN != IS_ACN_FAIL)
    {
        dp.dlg_info_present = TC_YES;
        /*MakeACN(&dp.application_context_name.length,
            dp.application_context_name.data, isACN);*/
		memcpy(&dp, &gdp, sizeof(gdp));
    }
    else
	{
        //dp.dlg_info_present = TC_NO;
        dp.dlg_info_present = TC_YES;
		memcpy(&dp, &gdp, sizeof(gdp));
	}

    if(Mtf->bit_mask & MT_ForwardSM_Arg_V3_moreMessagesToSend_present)
        /*ret = send_messageSim(gCnxId, TC_CONTINUE, &dp, &dest_addr, &orig_addr,
            u_id == 0 ? gUid : u_id, prov_id, gDebug);*/
        ret = send_messageSim(gCnxId, TC_CONTINUE, &dp, &dest_addr, &orig_addr,
            u_id == 0 ? gUid : u_id, prov_id, gDebug);
    else
        /*ret = send_messageSim(gCnxId, TC_END, &dp, &dest_addr, &orig_addr,
            u_id == 0 ? gUid : u_id, prov_id, gDebug); */
        ret = send_messageSim(gCnxId, TC_END, &dp, &dest_addr, &orig_addr,
            u_id == 0 ? gUid : u_id, prov_id, gDebug);
#endif
	return 0;
}


int SendMofNack(UTcapPrimitive *prim, UTcapComponents *comp, int u_id, int prov_id, int inv_id, char isACN, int errCode)
{
    SM_DeliveryFailureCause        failure;
    AbsentSubscriberSM_Param       absent;

	if((gError == CC_ABSENT_SUBSCRIBER_SM) || (gError >= CC_NPR3G_CS && gError <= CC_UNIDENTIFIED_PS))
    {
        bzero((void *)&absent, sizeof(AbsentSubscriberSM_Param));
        absent.bit_mask |= AbsentSubscriberSM_Param_absentSubscriberDiagnosticSM_present;
        //absent.absentSubscriberDiagnosticSM = gDiagnostic;

		if(gError >= 3170)
			absent.absentSubscriberDiagnosticSM = gError - 3170;
		else
			absent.absentSubscriberDiagnosticSM = 12;

        if(ossEncode(world, AbsentSubscriberSM_Param_PDU, &absent, &param))
        {
            printf("ossEncode error: %s\n", ossGetErrMsg(world));
            return -1;
        }
        else
        {
            printf("\n AbsentSubscriberSM_Param_PDU ..... encoded.. gDiagnostic=[%d] \n", absent.absentSubscriberDiagnosticSM);
        }

        gAdr = CC_ABSENT_SUBSCRIBER_SM;
    }
	else if((gError == CC_SM_DELIVERY_FAILURE) || (gError >= CC_MCEF && gError <= CC_NOT_SC_SUBSCRIBER))
    {
        bzero((void *)&failure, sizeof(SM_DeliveryFailureCause));
        /*
 *            failure.bit_mask |=
 *                       SM_DeliveryFailureCause_extensionContainer_present;
 *                                */
		//failure.sm_EnumeratedDeliveryFailureCause = gDiagnostic;
		if(gError >= CC_MCEF) 
		{
			if(gError == CC_MCEF)
				failure.sm_EnumeratedDeliveryFailureCause =
					SM_EnumeratedDeliveryFailureCause_memoryCapacityExceeded;
			else if(gError == CC_PROTOCOL_ERR)
				failure.sm_EnumeratedDeliveryFailureCause = equipmentProtocolError;
			else if(gError == CC_NOT_SM_EQUIPPED)
				failure.sm_EnumeratedDeliveryFailureCause = equipmentNotSM_Equipped;
			else if(gError == CC_UNKNOWN_SC)
				failure.sm_EnumeratedDeliveryFailureCause = unknownServiceCentre;
			else if(gError == CC_SC_CONGESTION)
				failure.sm_EnumeratedDeliveryFailureCause = sc_Congestion;
			else if(gError == CC_INVALID_SME_ADDR)
				failure.sm_EnumeratedDeliveryFailureCause = invalidSME_Address;
			else if(gError == CC_NOT_SC_SUBSCRIBER)
				failure.sm_EnumeratedDeliveryFailureCause = subscriberNotSC_Subscriber;
		}

        if(ossEncode(world, SM_DeliveryFailureCause_PDU, &failure, &param))
        {
            printf("ossEncode error: %s\n", ossGetErrMsg(world));
            return -1;
        }
        else
        {
            printf("\n SM_DeliveryFailureCause_PDU ..... encoded.. gDiagnostic=[%d] \n", failure.sm_EnumeratedDeliveryFailureCause);
        }

        gAdr = CC_SM_DELIVERY_FAILURE;
    }
    else
        gAdr = gError;

	printf("Error Code : %d,Param Len : %ld\n", gAdr,param.length);

	if(gZero)
	{
		if(sig_sendEndError(gTcapInfo, IS_ACN_NOT_SET, prim, comp, gAdr-3000, param.value, param.length) == UTCAP_RETURN_OK)
		{
			uaLog(L_INFO, "Diag %4d Nack Sent", prim->u.datInd.suDlgId);
			return IXOK;
		}
		else
		{
			uaLog(L_MIN, "Diag %4d sig_sendEndError Send failed", prim->u.datInd.suDlgId);
			return IXERR;
		}
	}
	else
	{
		if(sig_sendEndError(gTcapInfo, IS_ACN_NOT_SET, prim, comp, gAdr-3000, NULL, 0) == UTCAP_RETURN_OK)
		{
			uaLog(L_INFO, "Diag %4d Nack Sent", prim->u.datInd.suDlgId);
			return IXOK;
		}
		else
		{
			uaLog(L_MIN, "Diag %4d sig_sendEndError Send failed", prim->u.datInd.suDlgId);
			return IXERR;
		}
	}

#if 0 
	gAdr = errCode;
	
    if(prim == NULL)
        return IXERR;

    opCode = -1 ;

    if( sig_sendEndErrorComplex(gTcapInfo, IS_ACN_NOT_SET,
        prov_id, inv_id,
        opCode, gAdr, NULL, 0) == UTCAP_RETURN_OK )
    {
        uaLog(L_INFO, "Diag %4d Nack Sent", prim->u.datInd.suDlgId );
        return IXOK;
    }
    else
    {
        uaLog(L_MIN, "Diag %4d sig_sendEndError Send failed", prim->u.datInd.suDlgId);
        return IXERR;
    }
#endif

   // EncodeError(&error, errCode);

#if 0
    param.length = 0;
    param.value = NULL;

    if(errCode == (CC_ABSENT_SUBSCRIBER_SM - 3000))
    {
        bzero((void *)&absent, sizeof(AbsentSubscriberSM_Param));
        absent.bit_mask |=
            AbsentSubscriberSM_Param_absentSubscriberDiagnosticSM_present;
        absent.absentSubscriberDiagnosticSM = 0;
            /* 0 for imx, 5 for sgsn */

        if(ossEncode(world, AbsentSubscriberSM_Param_PDU, &absent, &param))
        {
            printf("ossEncode error: %s\n", ossGetErrMsg(world));
            return -1;
        }
    }
    else if(errCode == (CC_SM_DELIVERY_FAILURE - 3000))
    {
        bzero((void *)&failure, sizeof(SM_DeliveryFailureCause));
        /*
		failure.bit_mask = diagnosticInfo_present;
        */
		failure.sm_EnumeratedDeliveryFailureCause = 
			SM_EnumeratedDeliveryFailureCause_memoryCapacityExceeded;
/*
          SM_EnumeratedDeliveryFailureCause_memoryCapacityExceeded = 0,
          equipmentProtocolError = 1,
          equipmentNotSM_Equipped = 2,
          unknownServiceCentre = 3,
          sc_Congestion = 4,
          invalidSME_Address = 5,
          subscriberNotSC_Subscriber = 6
*/
        if(ossEncode(world, SM_DeliveryFailureCause_PDU, &failure, &param))
        {
            printf("ossEncode error: %s\n", ossGetErrMsg(world));
            return -1;
        }
    }

    ret =  sig_sendEndErrorComplex(gTcapInfo,ACN_MT_V3 ,
                                prov_id, inv_id, mt_forwardSM_V3.u.localValue, errCode,
                                (u_char *)param.value, param.length);
#endif

#if 0
    comp_len = build_componentSim(gCnxId, TC_U_ERROR, inv_id, -1, 
        u_id == 0 ? ++gUid : u_id, prov_id,
        &operation, 10, (int)param.length, param.value, &error, gDebug);
    if(comp_len < 0)
        return -1;

    memcpy(&dest_addr, &prim->o_address, sizeof(USccpAddr));
    memcpy(&orig_addr, &prim->t_address, sizeof(USccpAddr));

    bzero((void *)&dp, sizeof(tc_dialog_portion));
    if(isACN != IS_ACN_NOT_SET && isACN != IS_ACN_FAIL)
    {
        dp.dlg_info_present = TC_YES;
        MakeACN(&dp.application_context_name.length,
            dp.application_context_name.data, ACN_MT_V3);
    }
    else
        dp.dlg_info_present = TC_NO;

	if(sig_sendEndError( gTcapInfo , ACN_MO_V3 , prim , comp , errCode , 
				param.value , param.length   ) )

	ptr = (char *)param.value ; 
	ossFreeBuf(world , ptr );

#endif

/*
    ret = send_messageSim(gCnxId, TC_END, &dp, &dest_addr, &orig_addr,
        u_id == 0 ? gUid : u_id, prov_id, gDebug);
*/
}


#if 0 
int ProcPrim(tcx_primitive *prim, int u_id)
{
    switch (TC_P_PROVIDER_ID(prim))
    {
        case NO_PRIMITIVE:
            /*
            SendTCUAbort2(gCnxId, TC_P_PROVIDER_ID(prim));
            */
            break;

        case TC_P_ABORT:
            break;

        case TC_U_ABORT:
            break;

        case SCCP_USER_STATUS:
            break;

        case SCCP_PC_STATUS:
            break;

        case TC_NOTICE:
            break;
    }
    return 1;
}
#endif


int ProcPrim(UTcapPrimitive *prim)
{
    int    err_code = CC_RECV_UNKNOWN_PRIM;
    UTcapPrimitive_DAT_IND      *ind;

    if(prim->type != UTcapPrimitiveType_DAT_IND)
	{
        printf("Invalid prim type %d", prim->type);
        return -1;
    }

    ind = &(prim->u.datInd);
    printf("Invalid primitive %s", UTCAP_TRANSACTION_STR(ind->msgType));

	if(ind->msgType == UTCAP_P_ABORT) 
		err_code = CC_RECV_PABORT;

    return 0 ;
}


int receiveFromIPMG()
{
    int                             i;
    int                             ret;
    int                             userId, provId, diagId, invId;
    UTcapPrimitive                  prim ;
    UTcapComponents                 comp ;
    enum UTcapTransactionType       msgType ;
    //int                             maxFd = 0 ;
    bool                            isActive ;
    struct timeval                  timeout;
    int                             selectRc, rval2, compNum, isComp, rCnt = 0 ;
    int                             isACN, pduNum ;
    ForwardSM_Arg_V2				*Mtf2;
    MO_ForwardSM_Arg_V3				*Mof3;
	stAddr                        	addr;

	_TPDU		                    rTPDU;

    do
    {
        bzero(&prim, sizeof(UTcapPrimitive));
        bzero(&comp, sizeof(UTcapComponents));

        //maxFd = 0;
        timeout.tv_sec = 0;
        timeout.tv_usec = 100000;   /* 100 msec */


        selectRc = utcap_select( gTcapInfo, 0, NULL, NULL, NULL, &timeout, &isActive);

        if(isActive)
        {
            /* read messages incoming from TCAP */
            rval2 = utcap_recv(gTcapInfo, (void*)&prim, &isComp, &compNum);
            if( rval2 < 0) 
			{
                printf("utcap_recv() failed : ec=%d", u_ec());

                return -1 ;
            }

//          printf("New Msg Received.................!!!\n");

            rCnt++;

            isComp = rval2;

            if((prim.type == UTcapPrimitiveType_DAT_IND && prim.u.datInd.msgType == UTCAP_END))
			{
                ProcPrim(&prim);
                continue;
            }


            msgType = prim.u.datInd.msgType ;
            userId = prim.u.datInd.suDlgId ;
            provId = prim.u.datInd.spDlgId ;
			/*
			printf("<<< Receive msg userId[%d] provId[%d]\n", userId, provId); 
			*/

            inc_prim_cnt(msgType);

            isACN = CheckACN(&prim.u.datInd.dlgEv,
					&prim.u.datInd.dlgEv.apConName.string, prim.u.datInd.dlgEv.apConName.len);

            diagId = userId;

			if(!compNum) 
			{
				rval2 = sig_sendResultNotComp(gTcapInfo, isACN, prim.u.datInd.spDlgId, &prim , UTCAP_CONTINUE);

                if(rval2 < 0) 
                   uaLog(L_CRT, "sig_sendEndResultNotComp fail");
	            else 
                    uaLog(L_INFO, ">>> NOT COMPONENT ACK Sent dlgId[%d]", diagId);
			    continue;
			}

	        for(i = 0 ; i < compNum ; i++)
	        {
	            rval2 = utcap_getComp(gTcapInfo, userId, provId, &comp) ;
	            if(rval2 < 0)
	                uaLog( L_MAJ, "utcap_getComp failed E=%d", rval2);

	            inc_comp_cnt(comp.compType);

	            invId = comp.invokeId.octet;

                /* version nego */
                if(msgType == UTCAP_BEGIN && ((isACN == ACN_MO_V3 && gVersion != 3) || (isACN == ACN_MO_V2 && gVersion != 2)))
				{
                    printf("sendUAbort received acn %d %d \n", isACN, gVersion);
 
                    sig_sendTCUAbortWithDP(gTcapInfo, userId, provId , gVersion == MAP_VERSION_2?ACN_MO_V2:ACN_MO_V3);
                    continue;
                }

				gnMtfReq++; 

	            if(comp.opCode.len == 0)
	                break;
	            else if(comp.opCode.string[0] == mo_forwardSM_V3.u.localValue || comp.opCode.string[0] == forwardSM_V2.u.localValue)    /* 45 */
	            {
                    param.length = (long)comp.bufLen;
                    param.value = (u_char *)comp.cpBuf; 
					if(gVersion == 2)
					{
						pduNum = ForwardSM_Arg_V2_PDU;
						Mtf2 = NULL;
						if(ossDecode(world, &pduNum, &param, (void **)&Mtf2))
						{
							printf("map_ver2 ossDecode() error:(%s)\n", ossGetErrMsg(world));
							param.length = 0 ;
							param.value = NULL;
							break;
						}
					}
					else
					{
						pduNum = MO_ForwardSM_Arg_V3_PDU;
						Mof3 = NULL;
						if(ossDecode(world, &pduNum, &param, (void **)&Mof3))
						{
							printf("map_ver3 ossDecode() error:(%s)\n", ossGetErrMsg(world));
							param.length = 0 ;
							param.value = NULL;
							break;
						}
					}

					if(Mof3->sm_RP_DA.choice == SM_RP_DA_imsi_chosen)
						TransImsiToMsisdn(&(Mof3->sm_RP_DA.u.imsi), &addr);
					else if(Mof3->sm_RP_DA.choice == lmsi_chosen)
						TransLmsiToMsisdn(&(Mof3->sm_RP_DA.u.lmsi), &addr);
#if 0
					else
						break;
#endif

					ret = DecodeTPDU(&rTPDU, Mof3->sm_RP_UI.value, Mof3->sm_RP_UI.length, DIRECTION_MS_SC, TPDU_FALSE);  
					/* printf("userData  %s\n",  rTPDU.Union.SMSSubmit.UserData.Data ); */

					/*
					   if ( world) {
					   char buf[2048];
					   myOssPrintPDU( buf, world, MT_ForwardSM_Arg_V3_PDU, Mtf3);
					   }
					*/

					int tmp = rand() % 10;
					if(tmp < gNack)
					{
						SendMofNack(&prim, &comp, userId, provId, invId, isACN, gError);
						gnMtfNack++;
						break;
					}

					SendMofAck3(&prim, userId, provId, invId, isACN, diagId);
					gnMtfAck++;
				}
			}
        }
    }while(isActive > 0 && rCnt <= 100);

    return IXOK;
}


int sec_ellapsed(int sec)
{
    static time_t       old_time = 0;
    time_t              cur_time;

    time(&cur_time);
    if(old_time + sec <= cur_time)
    {
        old_time = cur_time;
        return 1;
    }
    else
        return 0;
}


int main(int argc, char *argv[])
{
	int Result;
	char fname[128], *env; 

	GET_SYS_HOME_ENV(env);
	sprintf(fname, "%s/log/%s/%s", env, _MODULE_NAME, _MODULE_NAME);

	gLogId = LOG_open( fname,
			LOG_MODE_CHANGE_DAILY | LOG_FORMAT_TIME_MSEC |
			LOG_FORMAT_CATEGORY | LOG_FORMAT_SRC_FILE | LOG_FLAG_EXT_CTRL|
			LOG_FLAG_STDOUT | LOG_FLAG_THREAD_SAFE );

	if(gLogId < 0) 
	{
		fprintf( stderr, "LOG_open: E=%d", gLogId);
		return -1;
	}

    if(argc == 2 && atoi(argv[1]) == 2)
        gVersion = 2;

    if(argc == 3 && atoi(argv[2]) == 2)
        gVersion = 2;

    Result = GetMscConf(SMSC_CONF_FILE_PATH);
    if(Result == -1)
        exit(0);


    srand(getpid());

    signal(SIGINT,  (void (*)(int))CloseProc);
    signal(SIGTERM, (void (*)(int))CloseProc);

    ossinit(world, map_protocol);

    //if((gTcapInfo = initSigtran( argc, argv, "SMSC_SIM")) == 0)
    if((gTcapInfo = initSigtran( argc, argv, "MO_SIM")) == 0)
	{
        printf("InitSigtran failed");
        exit(-1);
    }

    //ossSetEncodingFlags(world, DEBUGPDU);
    //ossSetDecodingFlags(world, DEBUGPDU);

    while(1)
    {
        receiveFromIPMG();

        if(sec_ellapsed(1))
        {
            printf("Mof[Req:%d, Res:%d, Ack:%d, Nack:%d]\n", gnMtfReq, gnMtfAck+gnMtfNack, gnMtfAck, gnMtfNack);

			gnMtfReq = gnMtfAck = gnMtfNack =0;
        }
    }
}
