#include <iXConfParam.h>
#include <iXSem.h>
#include <ua_log.h>
//#include <iXDualAct.h>
//#include <dcm.h>

stCPShm    *gpCP;


void OpenCPshm()
{
    gpCP = (stCPShm *)GetCPp();
}


int	InitCPshm()
{
    if(P(IXCP_SEM_ID) < 0)
    {
	   	uaLog(L_CRT, "CP Shm P Error, semid: %d",
            IXCP_SEM_ID);
        return IXERR;
    }

	gpCP->end = 0;

    if(V(IXCP_SEM_ID) < 0)
    {
    	uaLog(L_CRT, "CP Shm V Error, semid: %d",
            IXCP_SEM_ID);
        return IXERR;
    }

	return IXOK;
}


int CP_compare(const void *n1, const void *n2)
{
	stCP *cp1 = (stCP*)n1, *cp2 = (stCP*)n2;

    if(strlen(cp2->name) == 0)
        return 1;

    return strcmp(cp1->name, cp2->name);
}


int GetCP(char *name, stCP *info)
{
	/* v400 added by jhung , use for  temp use */
	// added by km 2017/04/26
	stCP 	rcvInfo, *ptr = NULL;

	strcpy(rcvInfo.name, name);

	ptr = (stCP *)bsearch((void *)&rcvInfo, (void *)gpCP->table, gpCP->end, sizeof(stCP), CP_compare);
	
	if(ptr == NULL)
		return IXERR;
    
	memcpy((void*)info, (void *)ptr, sizeof(stCP));
	
	return IXOK;
}

/* 0 */
int getChargeInd(int *flag)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_CHARGE_INDI].name, CP_CHARGE_INDI))
	if(GetCP(CP_CHARGE_INDI, &info) != IXOK)
		*flag = CP_INIT_CHARGE_INDI;
	else
		*flag = info.intVal;
//		*flag = gpCP->table[CP_INDEX_CHARGE_INDI].intVal;
	return IXOK;
}

/* 1 */
int getExpiredTime(int *time_val)
{
	stCP info;
//	if (strcmp(gpCP->table[CP_INDEX_DEF_PERIOD].name, CP_DEF_PERIOD))
	if(GetCP(CP_DEF_PERIOD, &info) != IXOK)	
		*time_val = CP_INIT_DEF_PERIOD;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_DEF_PERIOD].intVal;
	return IXOK;
}

/* 2 */
int getDefProfile(int *profile)
{
	stCP info;

//	if (strcmp(gpCP->table[CP_INDEX_DEF_PROFILE].name, CP_DEF_PROFILE))
	if(GetCP(CP_DEF_PROFILE, &info) != IXOK)
		*profile = CP_INIT_DEF_PROFILE;
	else
		*profile = info.intVal;
//		*profile = gpCP->table[CP_INDEX_DEF_PROFILE].intVal;
	return IXOK;
}

/* 3 */
int getDppEngTime(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_DPP_ENG_TIME].name, CP_DPP_ENG_TIME))
	if(GetCP(CP_DPP_ENG_TIME, &info) != IXOK)
		*time_val = CP_INIT_DPP_ENG_TIME;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_DPP_ENG_TIME].intVal;
	return IXOK;
}

/* 4 */
int getSS7DppTime(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_DPP_SS7_TIME].name, CP_DPP_SS7_TIME))
	if(GetCP(CP_DPP_SS7_TIME, &info) != IXOK)
		*time_val = CP_INIT_DPP_SS7_TIME;
	else
		*time_val = info.intVal; 
//		*time_val = gpCP->table[CP_INDEX_DPP_SS7_TIME].intVal;
	return IXOK;
}

/* 5 */
int getFirstTryNode(int *seq)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_FIRST_SGSN].name, CP_FIRST_SGSN))
	if(GetCP(CP_FIRST_SGSN, &info) != IXOK)
		*seq = CP_INIT_FIRST_SGSN;
	else
		*seq = info.intVal;
//		*seq = gpCP->table[CP_INDEX_FIRST_SGSN].intVal;
	return IXOK;
}

/* 6 */
int getInbhRetry(int *count)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_INBH_RETRY].name, CP_INBH_RETRY))
	if(GetCP(CP_INBH_RETRY, &info) != IXOK)
		*count = CP_INIT_INBH_RETRY;
	else
		*count = info.intVal;
//		*count = gpCP->table[CP_INDEX_INBH_RETRY].intVal;
	return IXOK;
}

/* 7 */
int getInbhSleep(time_t *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_INBH_SLEEP].name, CP_INBH_SLEEP))
	if(GetCP(CP_INBH_SLEEP, &info) != IXOK)
		*time_val = CP_INIT_INBH_SLEEP;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_INBH_SLEEP].intVal;
	return IXOK;
}

/* 8 time_t */
int getInbhTimeout(time_t *time_val)
{
	stCP info;


	//if (strcmp(gpCP->table[CP_INDEX_INBH_TIMEOUT].name, CP_INBH_TIMEOUT))
	if(GetCP(CP_INBH_TIMEOUT, &info) != IXOK)
		*time_val = CP_INIT_INBH_TIMEOUT;
	else
		*time_val = info.intVal;
	//	*time_val = gpCP->table[CP_INDEX_INBH_TIMEOUT].intVal;
	return IXOK;
}

/* 9 */
int getIncomingTime(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_INCOMING_TIME].name, CP_INCOMING_TIME))
	if(GetCP(CP_INCOMING_TIME, &info) != IXOK)
		*time_val = CP_INIT_INCOMING_TIME;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_INCOMING_TIME].intVal;
	return IXOK;
}

/* 10 */
int getMaxUDCdma(int *size)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_MAX_UD_CDMA].name, CP_MAX_UD_CDMA))
	if(GetCP(CP_MAX_UD_CDMA, &info) != IXOK)
		*size = CP_INIT_MAX_UD_CDMA;
	else
		*size = info.intVal;
//		*size = gpCP->table[CP_INDEX_MAX_UD_CDMA].intVal;
	return IXOK;
}

/* 11 */
int getMaxUDGsm(int *size)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_MAX_UD_GSM].name, CP_MAX_UD_GSM))
	if(GetCP(CP_MAX_UD_GSM, &info) != IXOK)
		*size = CP_INIT_MAX_UD_GSM;
	else
		*size = info.intVal;
//		*size = gpCP->table[CP_INDEX_MAX_UD_GSM].intVal;
	return IXOK;
}

/* 12 */
int getMoFlow(int *flag)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_MO_FLOW_CTRL].name, CP_MO_FLOW_CTRL))
	if(GetCP(CP_MO_FLOW_CTRL, &info) != IXOK)
		*flag = CP_INIT_MO_FLOW_CTRL;
	else
		*flag = info.intVal;
//		*flag = gpCP->table[CP_INDEX_MO_FLOW_CTRL].intVal;
	return IXOK;
}

/* 13 */
int getMsgCnt(int *cnt)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_MSG_CNT].name, CP_MSG_CNT))
	if(GetCP(CP_MSG_CNT, &info) != IXOK)
		*cnt = CP_INIT_MSG_CNT;
	else
		*cnt = info.intVal;
//		*cnt = gpCP->table[CP_INDEX_MSG_CNT].intVal;
	return IXOK;
}

/* 14 */
int getNpsEngTime(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_NPS_ENG_TIME].name, CP_NPS_ENG_TIME))
	if(GetCP(CP_NPS_ENG_TIME, &info) != IXOK)
		*time_val = CP_INIT_NPS_ENG_TIME;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_NPS_ENG_TIME].intVal;
	return IXOK;
}

/* 15 */
int getNpsTcpTime(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_NPS_TCP_TIME].name, CP_NPS_TCP_TIME))
	if(GetCP(CP_NPS_TCP_TIME, &info) != IXOK)
		*time_val = CP_INIT_NPS_TCP_TIME;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_NPS_TCP_TIME].intVal;
	return IXOK;
}

/* 16 */
int getReqEngTime(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_REQ_ENG_TIME].name, CP_REQ_ENG_TIME))
	if(GetCP(CP_REQ_ENG_TIME, &info) != IXOK)
		*time_val = CP_INIT_REQ_ENG_TIME;
	else
		*time_val = info.intVal;
//*time_val = gpCP->table[CP_INDEX_REQ_ENG_TIME].intVal;
	return IXOK;
}

/* 17 */
int getSS7ReqTime(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_REQ_SS7_TIME].name, CP_REQ_SS7_TIME))
	if(GetCP(CP_REQ_SS7_TIME, &info) != IXOK)
		*time_val = CP_INIT_REQ_SS7_TIME;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_REQ_SS7_TIME].intVal;
	return IXOK;
}

/* 18 */
int getRoutingSccp(int *flag)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_ROUTING_SCCP].name, CP_ROUTING_SCCP))
	if(GetCP(CP_ROUTING_SCCP, &info) != IXOK)
		*flag = CP_INIT_ROUTING_SCCP;
	else
		*flag = info.intVal;
//		*flag = gpCP->table[CP_INDEX_ROUTING_SCCP].intVal;
	return IXOK;
}

/* 19 */
int getSmscNumber(char *smsc)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_SMSC_NUMBER].name, CP_SMSC_NUMBER))
	if(GetCP(CP_SMSC_NUMBER, &info) != IXOK)
	{
		uaLog(L_CRT, "SC ADDRESS DEFAULT SETTING... [821028520236]");
		strcpy(smsc, "821028520236");
	//	strcpy(smsc, ""); //conf-para 안되서 일단 임시값
	}
	else
		strcpy(smsc, info.strVal);
//		strcpy(smsc, gpCP->table[CP_INDEX_SMSC_NUMBER].strVal);

	return IXOK;
}

/* 20 */
int getSupportGPRS(int *flag)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_SUPPORT_GPRS].name, CP_SUPPORT_GPRS))
	if(GetCP(CP_SUPPORT_GPRS, &info) != IXOK)
		*flag = CP_INIT_SUPPORT_GPRS;
	else
		*flag = info.intVal;
//		*flag = gpCP->table[CP_INDEX_SUPPORT_GPRS].intVal;
	return IXOK;
}

/* 21 */
int getSvcEngTime(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_SVR_ENG_TIME].name, CP_SVR_ENG_TIME))
	if(GetCP(CP_SVR_ENG_TIME, &info) != IXOK)
		*time_val = CP_INIT_SVR_ENG_TIME;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_SVR_ENG_TIME].intVal;
	return IXOK;
}

/* 22 */
int getSvcTcpTime(int *time_val)
{
	stCP info;

//	if (strcmp(gpCP->table[CP_INDEX_SVR_SMPP_TIME].name, CP_SVR_SMPP_TIME))
	if(GetCP(CP_SVR_SMPP_TIME, &info) != IXOK)
		*time_val = CP_INIT_SVR_SMPP_TIME;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_SVR_SMPP_TIME].intVal;
	return IXOK;
}

/* 23 */
int getSysInfoInterval(int *time_val)
{
	stCP info;
//	if (strcmp(gpCP->table[CP_INDEX_SYSINFO_INTERVAL].name,CP_SYSINFO_INTERVAL))
	if(GetCP(CP_SYSINFO_INTERVAL, &info) != IXOK)
		*time_val = CP_INIT_SYSINFO_INTERVAL;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_SYSINFO_INTERVAL].intVal;
	return IXOK;
}

/* 24 */
int getWingsEngTime(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_WINGS_ENG_TIME].name, CP_WINGS_ENG_TIME))
	if(GetCP(CP_WINGS_ENG_TIME, &info) != IXOK)
		*time_val = CP_INIT_WINGS_ENG_TIME;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_WINGS_ENG_TIME].intVal;
	return IXOK;
}

/* 25 */
int getWingsTcpTime(int *time_val_val)
{
	stCP info;

//	if (strcmp(gpCP->table[CP_INDEX_WINGS_TCP_TIME].name, CP_WINGS_TCP_TIME))
	if(GetCP(CP_WINGS_TCP_TIME, &info) != IXOK)
		*time_val_val = CP_INIT_WINGS_TCP_TIME;
	else
		*time_val_val = info.intVal;
//		*time_val_val = gpCP->table[CP_INDEX_WINGS_TCP_TIME].intVal;
	return IXOK;
}

/* 26 */
int getDelayEngTime(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_DELAY_ENG_TIME].name, CP_DELAY_ENG_TIME))
	if(GetCP(CP_DELAY_ENG_TIME, &info) != IXOK)
		*time_val = CP_INIT_DELAY_ENG_TIME;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_DELAY_ENG_TIME].intVal;

	return IXOK;
}

/* 27 */
int getNpsSysInfo(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_NPS_SYSINFO].name,CP_NPS_SYSINFO))
	if(GetCP(CP_NPS_SYSINFO, &info) != IXOK)
		*time_val = CP_INIT_NPS_SYSINFO;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_NPS_SYSINFO].intVal;
	return IXOK;
}

/* 28 */
int getScpSysInfo(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_SCP_SYSINFO].name,CP_SCP_SYSINFO))
	if(GetCP(CP_SCP_SYSINFO, &info) != IXOK)
		*time_val = CP_INIT_SCP_SYSINFO;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_SCP_SYSINFO].intVal;
	return IXOK;
}

/* 29 */
int getSmppSysInfo(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_SMPP_SYSINFO].name,CP_SMPP_SYSINFO))
	if(GetCP(CP_SMPP_SYSINFO, &info) != IXOK)
		*time_val = CP_INIT_SMPP_SYSINFO;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_SMPP_SYSINFO].intVal;
	return IXOK;
}

/* 30 */
int getNpsSleep(time_t *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_NPS_SLEEP].name, CP_NPS_SLEEP))
	if(GetCP(CP_NPS_SLEEP, &info) != IXOK)
		*time_val = CP_INIT_NPS_SLEEP;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_NPS_SLEEP].intVal;
	return IXOK;
}

/* 31 - time_t */
int getScpSleep(time_t *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_SCP_SLEEP].name, CP_SCP_SLEEP))
	if(GetCP(CP_SCP_SLEEP, &info) != IXOK)
		*time_val = CP_INIT_SCP_SLEEP;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_SCP_SLEEP].intVal;
	return IXOK;
}

/* 32 : 05/04/06 add */
int getHlrDelayEngTime(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_HLR_DELAY_ENG_TIME].name, CP_HLR_DELAY_ENG_TIME))
	if(GetCP(CP_HLR_DELAY_ENG_TIME, &info) != IXOK)
		*time_val = CP_INIT_HLR_DELAY_ENG_TIME;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_HLR_DELAY_ENG_TIME].intVal;

	return IXOK;
}
/* 33 : v302 sjlee Max Retry */
int getMaxRetry(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_MAX_RETRY].name, CP_MAX_RETRY))
	if(GetCP(CP_MAX_RETRY, &info) != IXOK)
		*time_val = CP_INIT_MAX_RETRY;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_MAX_RETRY].intVal;

	return IXOK;
}
/* 34 : v302 sjlee DB PoolSize */
int getDBPoolSize(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_DB_POOL_SIZE].name, CP_DB_POOL_SIZE ))
	if(GetCP(CP_DB_POOL_SIZE, &info) != IXOK)
		*time_val = CP_INIT_DB_POOL_SIZE;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_DB_POOL_SIZE].intVal;

	return IXOK;
}

/* 35 */
int getMaxUDCdmaBefore(int *size)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_MAX_UD_CDMA_BEFORE].name, CP_MAX_UD_CDMA_BEFORE))
	if(GetCP(CP_MAX_UD_CDMA_BEFORE, &info) != IXOK)
		*size = CP_INIT_MAX_UD_CDMA_BEFORE;
	else
		*size = info.intVal;
//		*size = gpCP->table[CP_INDEX_MAX_UD_CDMA_BEFORE].intVal;
	return IXOK;
}

/* 36 */
int getSigReturnOpt(uint8_t *size)
{
	stCP info;
	//Added by Nersion. (sigtran 용 시뮬레이터 예외처리를 위해서 사용.. default OFF set retrun.
	if(gpCP == NULL)
	{
		*size = CP_INIT_SIG_RETURN_OPT;
		return IXOK;
	}

	//if (strcmp(gpCP->table[CP_INDEX_SIG_RETURN_OPT].name, CP_SIG_RETURN_OPT))
	if(GetCP(CP_SIG_RETURN_OPT, &info) != IXOK)
		*size = CP_INIT_SIG_RETURN_OPT;
	else
		*size = info.intVal;
//		*size = gpCP->table[CP_INDEX_SIG_RETURN_OPT].intVal;
	return IXOK;
}

/* 37 */
int getCpRipInfo(int *ripInfo)
{
	stCP info;

	//if(strcmp(gpCP->table[CP_INDEX_RIP_INFO].name, CP_RIP_INFO))
	if(GetCP(CP_RIP_INFO, &info) != IXOK)
	    *ripInfo = CP_RIP_INFO_UNKNOWN;
	else
		*ripInfo = info.intVal;
//		*ripInfo = gpCP->table[CP_INDEX_RIP_INFO].intVal;

	return IXOK;
}

/* 38 */
int getCpPfxInfo(int *pfxInfo)
{
	stCP info;

	//if(strcmp(gpCP->table[CP_INDEX_PREFIX_INFO].name, CP_PREFIX_INFO))
	if(GetCP(CP_PREFIX_INFO, &info) != IXOK)
	    *pfxInfo = CP_PREFIX_INFO_BOTH;
	else
		*pfxInfo = info.intVal;
//		*pfxInfo = gpCP->table[CP_INDEX_PREFIX_INFO].intVal;

	if(*pfxInfo != CP_PREFIX_INFO_ODD && *pfxInfo != CP_PREFIX_INFO_EVEN)
	   *pfxInfo = CP_PREFIX_INFO_BOTH;

	return IXOK;
}

/* 39 */
/* v320 sjlee Dpc Control On/Off Option */
int getDpcCtrlOpt(char *size)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_DPC_CTRL_OPT].name, CP_DPC_CTRL_OPT))
	if(GetCP(CP_DPC_CTRL_OPT, &info) != IXOK)
		*size = CP_INIT_DPC_CTRL_OPT;
	else
		*size = info.intVal;
//		*size = gpCP->table[CP_INDEX_DPC_CTRL_OPT].intVal;
	return IXOK;
}
/* 40 */
/* sndAck DB Store On/Off */
int getSndAckCtrl(char *size)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_SNDACK_CTRL].name, CP_SNDACK_CTRL))
	if(GetCP(CP_SNDACK_CTRL, &info) != IXOK)
		*size = CP_INIT_SNDACK_CTRL;
	else
		*size = info.intVal;
//		*size = gpCP->table[CP_INDEX_SNDACK_CTRL].intVal;
	return IXOK;
}
/* 41 */
int getPfxStatCtrl(char *size)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_PFX_STAT_CTRL].name, CP_PFX_STAT_CTRL))
	if(GetCP(CP_PFX_STAT_CTRL, &info) != IXOK)
		*size = CP_INIT_PFX_STAT_CTRL;
	else
		*size = info.intVal;
//		*size = gpCP->table[CP_INDEX_PFX_STAT_CTRL].intVal;
	return IXOK;
}

/* 42 */
int getRomeGroupId(unsigned char *romeGid)
{
	stCP info;

//	if (strcmp(gpCP->table[CP_INDEX_ROME_GROUP].name, CP_ROME_GROUP))
	if(GetCP(CP_ROME_GROUP, &info) != IXOK)
		*romeGid = CP_INIT_ROME_GROUP;
	else
		*romeGid = info.intVal;
//		*romeGid = gpCP->table[CP_INDEX_ROME_GROUP].intVal;
	return IXOK;
}

/* 43 : CP_INDEX_PREFIX_INFO*/
int changeDistributionMethod( int method)
{
	//이거 안쓰는데?
	stCP info, *cPtr = NULL;

	//if(strcmp(gpCP->table[CP_INDEX_PREFIX_INFO].name, CP_PREFIX_INFO))
	if(GetCP(CP_PREFIX_INFO, &info) != IXOK)
    {
        uaLog( L_CRT, "Different ConfPara name (%s, %s)", 
                      gpCP->table[CP_INDEX_PREFIX_INFO],  CP_PREFIX_INFO);
        return IXERR;
    }
    
    if(P(IXCP_SEM_ID) < 0)
    {
        uaLog( L_CRT, "changeDistributionMethod failed. P Error, semid: %d",
            IXCP_SEM_ID);
        return IXERR;
    }
 
	cPtr = (stCP *)bsearch((void *)&info, (void *)gpCP->table,
			gpCP->end, sizeof(stCP), (int (*)(const void *, const void *))CP_compare);
	
	//if(cPtr == NULL)
	if(cPtr->name == NULL || cPtr->strVal == NULL)
	{
        uaLog( L_CRT, "changeDistributionMethod failed. P Error, semid: %d",
            IXCP_SEM_ID);
		if(V(IXCP_SEM_ID) < 0)
		{
			uaLog( L_CRT, "changeDistributionMethod failed. V Error, semid: %d",
					IXCP_SEM_ID);
			return IXERR;
		}
	}
	
	cPtr->intVal = method;

    //gpCP->table[CP_INDEX_PREFIX_INFO].intVal = method;
 
    if(V(IXCP_SEM_ID) < 0)
    {
        uaLog( L_CRT, "changeDistributionMethod failed. V Error, semid: %d",
            IXCP_SEM_ID);
        return IXERR;
    }
 
    return IXOK;
}

/* 44 R.3.7.0 jjh UDL*/
int getUdlLimit()
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_UDL_LENGTH_LIMIT].name, CP_UDL_LENGTH_LIMIT))
	if(GetCP(CP_UDL_LENGTH_LIMIT, &info) != IXOK)
		return CP_INIT_UDL_LENGTH_LIMIT;
	else
		return info.intVal;
//		return  gpCP->table[CP_INDEX_UDL_LENGTH_LIMIT].intVal;
}

/* v370 Db Select Method */
int getDbSelect()
{
	return CP_INIT_DB_SELECT; // v430 db select off (ixmmdb를 통해서 db접근)
}

#if 0
/* 45 v380 Msg Dump  Method added by jhjung 20081119*/
int getMsgDumpInd()
{
	if (strcmp(gpCP->table[CP_INDEX_MSG_DUMP_IND].name, CP_MSG_DUMP_IND))
		return CP_INIT_MSG_DUMP_IND;
	else
		return  gpCP->table[CP_INDEX_MSG_DUMP_IND].intVal;
}
#endif

/* 45 Auto Dump Use Indicator */
int getAutoDumpUse()
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_AUTO_DUMP_USE].name, CP_AUTO_DUMP_USE))
	if(GetCP(CP_AUTO_DUMP_USE, &info) != IXOK)
		return CP_INIT_AUTO_DUMP_USE;
	else
		return info.intVal;
//		return  gpCP->table[CP_INDEX_AUTO_DUMP_USE].intVal;
}

#if 0
/* 46 */
int getMsgFlow(int *flag)
{
	if (strcmp(gpCP->table[CP_INDEX_MO_DUMP_FLOW].name, CP_MO_DUMP_FLOW))
		*flag = CP_INIT_MO_DUMP_FLOW;
	else
		*flag = gpCP->table[CP_INDEX_MO_DUMP_FLOW].intVal;
	return IXOK;
}
#endif

/* 46 Auto Backup Usage */
int getAutoBackupUsage(int *usage)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_AUTO_BACKUP_USAGE].name, CP_AUTO_BACKUP_USAGE))
	if(GetCP(CP_AUTO_BACKUP_USAGE, &info) != IXOK)
		*usage = CP_INIT_AUTO_BACKUP_USAGE;
	else
		*usage = info.intVal;
//		*usage = gpCP->table[CP_INDEX_AUTO_BACKUP_USAGE].intVal;
	return IXOK;
}

/* 47 */
int getSystemId()
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_SYSTEM_ID].name, CP_SYSTEM_ID))
	if(GetCP(CP_SYSTEM_ID, &info) != IXOK)
		return CP_INIT_SYSTEM_ID;
	else
		return info.intVal;
//		return  gpCP->table[CP_INDEX_SYSTEM_ID].intVal;
}

/* 48 CP_INDEX_CONCAT_CHRG_RC removed, isam에는 존재 */
#if 0
/* 49 */
int getTeleUdCtrl()
{
	if (strcmp(gpCP->table[CP_INDEX_TELE_UD_CTRL].name, CP_TELE_UD_CTRL))
		return CP_INIT_TELE_UD_CTRL;
	else
		return  gpCP->table[CP_INDEX_TELE_UD_CTRL].intVal;
}
#endif

/* 50 */
int getSmsfEngTime(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_SMSF_ENG_TIME].name, CP_SMSF_ENG_TIME))
	if(GetCP(CP_SMSF_ENG_TIME, &info) != IXOK)
		*time_val = CP_INIT_SMSF_ENG_TIME;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_SMSF_ENG_TIME].intVal;
	return IXOK;
}

/* 51 */
int getSmsfTcpTime(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_SMSF_TCP_TIME].name, CP_SMSF_TCP_TIME))
	if(GetCP(CP_SMSF_TCP_TIME, &info) != IXOK)
		*time_val = CP_INIT_SMSF_TCP_TIME;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_SMSF_TCP_TIME].intVal;
	return IXOK;
}

/* 52 */
int getSmsfSleep(time_t *time_val)
{
	stCP info;

//	if (strcmp(gpCP->table[CP_INDEX_SMSF_SLEEP].name, CP_SMSF_SLEEP))
	if(GetCP(CP_SMSF_SLEEP, &info) != IXOK)
		*time_val = CP_INIT_SMSF_SLEEP;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_SMSF_SLEEP].intVal;
	return IXOK;
}

/* 53 */
int getSmsfSysInfo(int *time_val)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_SMSF_SYSINFO].name, CP_SMSF_SYSINFO))
	if(GetCP(CP_SMSF_SYSINFO, &info) != IXOK)
		*time_val = CP_INIT_SMSF_SYSINFO;
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_SMSF_SYSINFO].intVal;
	return IXOK;
}

#if 0
/* 54 */
int getSmsfCtrl(void)
{
	if (strcmp(gpCP->table[CP_INDEX_SMSF_CTRL].name, CP_SMSF_CTRL))
		return CP_INIT_SMSF_CTRL;
	else
		return gpCP->table[CP_INDEX_SMSF_CTRL].intVal;
}
#endif

/* 55 */
int getRegSmsDest(char *dest)                    //v443
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_REG_SMS_DEST].name, CP_REG_SMS_DEST))
	if(GetCP(CP_REG_SMS_DEST, &info) != IXOK)
		strcpy(dest, "");
	else
		strcpy(dest, info.strVal);
//		strcpy(dest, gpCP->table[CP_INDEX_REG_SMS_DEST].strVal);

	return IXOK;
}

/* 56 */
int getRegSmsGid(unsigned char *gid)             //v443
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_REG_SMS_GID].name, CP_REG_SMS_GID))
	if(GetCP(CP_REG_SMS_GID, &info) != IXOK)
		*gid = CP_INIT_REG_SMS_GID;
	else
		*gid = info.intVal;
//		*gid = gpCP->table[CP_INDEX_REG_SMS_GID].intVal;
	return IXOK;
}
#if 0
/* 57 */
int getSbmtDumpFlow(int *flow)                   //v450
{
	if (strcmp(gpCP->table[CP_INDEX_SBMT_DUMP_FLOW].name, CP_SBMT_DUMP_FLOW))
		*flow = CP_INIT_SBMT_DUMP_FLOW; 
	else
		*flow = gpCP->table[CP_INDEX_SBMT_DUMP_FLOW].intVal;

	return IXOK;
}
#endif

/* 57 Auto Recovery Usage */
int getAutoRecoveryUsage(int *usage)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_AUTO_RECOVERY_USAGE].name, CP_AUTO_RECOVERY_USAGE))
	if(GetCP(CP_AUTO_RECOVERY_USAGE, &info) != IXOK)
		*usage = CP_INIT_AUTO_RECOVERY_USAGE; 
	else
		*usage = info.intVal;
//		*usage = gpCP->table[CP_INDEX_AUTO_RECOVERY_USAGE].intVal;

	return IXOK;
}

#if 0
/* 58 */
int getDumpDuration(unsigned int *time)                   //v450
{
	if (strcmp(gpCP->table[CP_INDEX_DUMP_DURATION].name, CP_DUMP_DURATION))
		*time = CP_INIT_DUMP_DURATION; 
	else
		*time = gpCP->table[CP_INDEX_DUMP_DURATION].intVal;

	return IXOK;
}
#endif

/* 58 Auto Recovery Cnt */
int getAutoRecoveryCnt(int *cnt)
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_AUTO_RECOVERY_CNT].name, CP_AUTO_RECOVERY_CNT))
	if(GetCP(CP_AUTO_RECOVERY_CNT, &info) != IXOK)
		*cnt = CP_INIT_AUTO_RECOVERY_CNT; 
	else
		*cnt = info.intVal;
//		*cnt = gpCP->table[CP_INDEX_AUTO_RECOVERY_CNT].intVal;

	return IXOK;
}

/* 59 */
int getDefaultDuration(int *time_val)                   //v450
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_DEFAULT_DURATION].name, CP_DEFAULT_DURATION))
	if(GetCP(CP_DEFAULT_DURATION, &info) != IXOK)
		*time_val = CP_INIT_DEFAULT_DURATION; 
	else
		*time_val = info.intVal;
//		*time_val = gpCP->table[CP_INDEX_DEFAULT_DURATION].intVal;

	return IXOK;
}
/* ====================================================== */

#if 0
int checkDurationTime(int dumpInd, int modId)                   //v450
{
	unsigned int durationTime;
	time_t now;


	getDumpDuration(&durationTime);

	if(durationTime == 0)
		return IXERR;

	time(&now);
	if(now < durationTime)
		return IXOK;
	else
	{
		if(dumpInd == CP_MSG_DUMP_SET_MO_SBMT)
		{
			stCP   cpInfo;
			bzero((void*)&cpInfo, sizeof(stCP));
			cpInfo.index = CP_INDEX_MSG_DUMP_IND;
			strcpy(cpInfo.name, CP_MSG_DUMP_IND);
			if(modId == SBMT_MOD_ID)
				cpInfo.intVal = CP_MSG_DUMP_SET_MO;
			else
				cpInfo.intVal = CP_MSG_DUMP_SET_SBMT;
			dbUpdateCP(cpInfo);
		}
		else if(dumpInd == CP_MSG_DUMP_SET_MO)
		{
			stCP   cpInfo;
			bzero((void*)&cpInfo, sizeof(stCP));
			cpInfo.index = CP_INDEX_MSG_DUMP_IND;
			strcpy(cpInfo.name, CP_MSG_DUMP_IND);
			cpInfo.intVal = CP_MSG_DUMP_SET_NOT_USED;
			dbUpdateCP(cpInfo);

			bzero((void*)&cpInfo, sizeof(stCP));
			cpInfo.index = CP_INDEX_DUMP_DURATION;
			strcpy(cpInfo.name, CP_DUMP_DURATION);
			cpInfo.intVal = 0;
			dbUpdateCP(cpInfo);

		}
		else if(dumpInd == CP_MSG_DUMP_SET_SBMT)
		{
			stCP   cpInfo;
			bzero((void*)&cpInfo, sizeof(stCP));
			cpInfo.index = CP_INDEX_MSG_DUMP_IND;
			strcpy(cpInfo.name, CP_MSG_DUMP_IND);
			cpInfo.intVal = CP_MSG_DUMP_SET_NOT_USED;
			dbUpdateCP(cpInfo);

			bzero((void*)&cpInfo, sizeof(stCP));
			cpInfo.index = CP_INDEX_DUMP_DURATION;
			strcpy(cpInfo.name, CP_DUMP_DURATION);
			cpInfo.intVal = 0;
			dbUpdateCP(cpInfo);
		}
						
		return IXERR;
	}

}
#endif

int getAutoDumpInd(int *autoDumpInd) //450
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_DEFAULT_AUTO_DUMP].name, CP_DEFAULT_AUTO_DUMP))
	if(GetCP(CP_DEFAULT_AUTO_DUMP, &info) != IXOK)
        *autoDumpInd = CP_INIT_AUTO_DUMP_IND;
    else
		*autoDumpInd = info.intVal;
//        *autoDumpInd = gpCP->table[CP_INDEX_DEFAULT_AUTO_DUMP].intVal;

    return IXOK;
}

int getChrgFlag(int *chrgFlag) //v480
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_CHRG_FLAG].name, CP_CHRG_FLAG ))
	if(GetCP(CP_CHRG_FLAG, &info) != IXOK)
        *chrgFlag = CP_INIT_CHRG_FLAG;
    else
		*chrgFlag = info.intVal;
//        *chrgFlag = gpCP->table[CP_INDEX_CHRG_FLAG].intVal;

    return IXOK;
}

int getRomeChrg(int *chrgFlag) //v480
{
	stCP info;

	//if (strcmp(gpCP->table[CP_INDEX_ROME_CHRG].name, CP_ROME_CHRG ))
	if(GetCP(CP_ROME_CHRG, &info) != IXOK)
        *chrgFlag = CP_INIT_ROME_CHRG;
    else
		*chrgFlag = info.intVal;
//        *chrgFlag = gpCP->table[CP_INDEX_ROME_CHRG].intVal;

    return IXOK;
}



int GetAllCP(stCP *cpInfo, int *cpCnt)
{
    int                  i;

    if(gpCP->end > CP_REC_ARR)
        *cpCnt = CP_REC_ARR;
    else
        *cpCnt = gpCP->end;

    for(i = 0; i < *cpCnt; i++)
        memcpy(&cpInfo[i], &gpCP->table[i], sizeof(stCP));

    return IXOK;
}


int InsertCP(stCP *info)
{
	if(IS_CP_FULL(gpCP->end))
    {
	    uaLog(L_CRT, "CP Table full error!!");
		return IXERR;
	}

    if(P(IXCP_SEM_ID) < 0)
    {
	   	uaLog(L_CRT, "CP Shm P Error, semid: %d",
            IXCP_SEM_ID);
        return IXERR;
    }

	if(gpCP->end == CP_REC_ARR)
    {
		/* Max CP Number reached */
	    if(V(IXCP_SEM_ID) < 0)
        {
	   		uaLog(L_CRT, "CP Shm V Error, semid: %d",
                IXCP_SEM_ID);
            return IXERR;
       	}

		return IXERR;
	}

    memcpy((void *)&(gpCP->table[gpCP->end]), (void *)info, sizeof(stCP));
	(gpCP->end)++;

    if(V(IXCP_SEM_ID) < 0)
    {
    	uaLog(L_CRT, "CP Shm V Error, semid: %d",
            IXCP_SEM_ID);
        return IXERR;
    }

	return IXOK;
}

int sortCP()
{
    if(P(IXCP_SEM_ID) < 0)
    {
        uaLog(L_CRT, "CP Shm P Error, semid: %d", IXCP_SEM_ID);
        return IXERR;
    }

    qsort(gpCP->table, gpCP->end, sizeof(stCP), CP_compare);

    if(V(IXCP_SEM_ID) < 0)
    {
        uaLog(L_CRT, "CP Shm V Error, semid: %d", IXCP_SEM_ID);
        return IXERR;
    }
	return IXOK;
}

int Update_CP_List(stCPShm *cp_list)
{
    if(P(IXCP_SEM_ID) < 0)
    {
        uaLog(L_CRT, "CP Shm P Error, semid: %d",
                IXCP_SEM_ID);
        return IXERR;
    }

    memcpy(gpCP, cp_list, sizeof(stCPShm));

    if(V(IXCP_SEM_ID) < 0)
    {
        uaLog(L_CRT, "CP Shm V Error, semid: %d",
                IXCP_SEM_ID);
        return IXERR;
    }

    return IXOK;
}
