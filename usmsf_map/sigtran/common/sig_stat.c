
#include <stdio.h>
#include <string.h>

#include <ua_syslib.h>
#include <ua_log.h>

#include <iXtypes.h>
#include <iXstat.h>


int 				smscCnt;

stSmscList 		    smscList[MAX_SMSC_LIST];
stSMSCstat			smscStat[MAX_SMSC_LIST];


void initMOFstat()
{
	int 		i;

	memset(smscStat, 0, sizeof(stSMSCstat) * MAX_SMSC_LIST);

	for( i = 0; i < smscCnt; i++) {
		strcpy(smscStat[i].isdn, smscList[i].isdn);
	}

	return;
}

void initMTFstat()
{
	int 		i;

	memset(smscStat, 0, sizeof(stSMSCstat) * MAX_SMSC_LIST);

	for( i = 0; i < smscCnt; i++) {
		strcpy(smscStat[i].isdn, smscList[i].isdn);
	}

	return;
}

void updateMOFstat() 
{
	int         i;
	stStatMsg 	stat_msg;

	memset(&stat_msg, 0, sizeof(stStatMsg));

	stat_msg.mtype = MSGQ_MTYPE_STAT;
	stat_msg.protocol = MAP_STAT_SMSC_STAT;

	for(i = 0; i < smscCnt; i++)
	{
		memcpy(&stat_msg.u.smscStat, &smscStat[i], sizeof(stSMSCstat));
		if(InsStatQMsg(&stat_msg) != IXOK) {
			uaLog(L_CRT, "<<< FAIL send to ixstat >>> ISDN=[%s]", smscStat[i].isdn);
		}
		else {
			uaLog(L_DBG, "ISDN[%s] %d, %d, %d, %d, %d", smscStat[i].isdn,
					smscStat[i].mof_send_succ, smscStat[i].mof_send_fail,
					smscStat[i].mof_resp_ack, smscStat[i].mof_resp_nack, smscStat[i].mof_timeout);
		}
	}

	initMOFstat();

    return;
}

void updateMTFstat() 
{
	int         i;
	stStatMsg 	stat_msg;

	memset(&stat_msg, 0, sizeof(stStatMsg));

	stat_msg.mtype = MSGQ_MTYPE_STAT;
	stat_msg.protocol = MAP_STAT_SMSC_STAT;

	for(i = 0; i < smscCnt; i++)
	{
		memcpy(&stat_msg.u.smscStat, &smscStat[i], sizeof(stSMSCstat));
		if(InsStatQMsg(&stat_msg) != IXOK) {
			uaLog(L_CRT, "<<< FAIL send to ixstat >>> ISDN=[%s]", smscStat[i].isdn);
		}
		else {
			uaLog(L_DBG, "ISDN[%s] %d, %d, %d, %d, %d", smscStat[i].isdn,
					smscStat[i].mtf_recv_succ, smscStat[i].mtf_recv_fail,
					smscStat[i].mtf_send_ack, smscStat[i].mtf_send_nack, smscStat[i].mtf_timeout);
		}

	}

	initMTFstat();

    return;
}

void initSmscList()
{
	memset(smscList, 0, sizeof(stSmscList) * MAX_SMSC_LIST); 

	return;
}

void checkSmscList(char *isdn)
{
	int 			i;

	for(i = 0; i < smscCnt; i++) {
		if(strcmp(smscList[i].isdn, isdn) == 0) {
			uaLog(L_DBG, "Find SMSC[%s], index[%d] in smscList", isdn, i);
			return;
		}
	}

	strcpy(smscList[i].isdn, isdn);
	strcpy(smscStat[i].isdn, isdn);
	smscCnt = i + 1;
	uaLog(L_INFO, "Add SMSC ISDN[%s], idx[%d], cnt[%d] in smscList", isdn, i, smscCnt);

	return;
}


int getNodeIndex(char *isdn)
{
	int 		i;

	for(i = 0; i < smscCnt; i++)
	{
		if(strcmp(smscList[i].isdn, isdn) == 0)
			return i;
	}

	return IXERR;
}


int inc_mof_send_succ(char *isdn)
{
    int    index;

	if ( (index = getNodeIndex(isdn)) < 0) {
		uaLog( L_MIN, "getNodeIndex(%s) failed", isdn);
		return IXERR;
	}

	smscStat[index].mof_send_succ++;

	uaLog(L_DBG, "inc_mof_send_succ: %d, ISDN[%s], idx[%d]", smscStat[index].mof_send_succ, isdn, index);

	return IXOK;
}


int inc_mof_send_fail(char *isdn)
{
    int    index;

	if ( (index = getNodeIndex(isdn)) < 0) {
		uaLog( L_MIN, "getNodeIndex(%s) failed", isdn);
		return IXERR;
	}

	smscStat[index].mof_send_fail++;

	uaLog(L_DBG, "inc_mof_send_fail: %d, ISDN[%s], idx[%d]", smscStat[index].mof_send_fail, isdn, index);

	return IXOK;
}

int inc_mof_resp_ack(char *isdn)
{
    int    index;

	if ( (index = getNodeIndex(isdn)) < 0) {
		uaLog( L_MIN, "getNodeIndex(%s) failed", isdn);
		return IXERR;
	}

	smscStat[index].mof_resp_ack++;

	uaLog(L_DBG, "inc_mof_resp_ack: %d, ISDN[%s], idx[%d]", smscStat[index].mof_resp_ack, isdn, index);

	return IXOK;
}

int inc_mof_resp_nack(char *isdn)
{
    int    index;

	if ( (index = getNodeIndex(isdn)) < 0) {
		uaLog( L_MIN, "getNodeIndex(%s) failed", isdn);
		return IXERR;
	}

	smscStat[index].mof_resp_nack++;

	uaLog(L_DBG, "inc_mof_resp_nack: %d, ISDN[%s], idx[%d]", smscStat[index].mof_resp_nack, isdn, index);

	return IXOK;
}

int inc_mof_send_time(char *isdn)
{
    int    index;

	if ( (index = getNodeIndex(isdn)) < 0) {
		uaLog( L_MIN, "getNodeIndex(%s) failed", isdn);
		return IXERR;
	}

	smscStat[index].mof_timeout++;

	uaLog(L_DBG, "inc_mof_send_time: %d, ISDN[%s], idx[%d]", smscStat[index].mof_timeout, isdn, index);

	return IXOK;
}


int inc_mtf_recv_succ(char *isdn)
{
    int    index;

	if ( (index = getNodeIndex(isdn)) < 0) {
		uaLog( L_MIN, "getNodeIndex(%s) failed", isdn);
		return IXERR;
	}

	smscStat[index].mtf_recv_succ++;

	uaLog(L_DBG, "inc_mtf_recv_succ: %d, ISDN[%s], idx[%d]", smscStat[index].mtf_recv_succ, isdn, index);

	return IXOK;
}

int inc_mtf_recv_fail(char *isdn)
{
    int    index;

	if ( (index = getNodeIndex(isdn)) < 0) {
		uaLog( L_MIN, "getNodeIndex(%s) failed", isdn);
		return IXERR;
	}

	smscStat[index].mtf_recv_fail++;

	uaLog(L_DBG, "inc_mtf_recv_fail: %d, ISDN[%s], idx[%d]", smscStat[index].mtf_recv_fail, isdn, index);

	return IXOK;
}

int inc_mtf_send_ack(char *isdn)
{
    int    index;

	if ( (index = getNodeIndex(isdn)) < 0) {
		uaLog( L_MIN, "getNodeIndex(%s) failed", isdn);
		return IXERR;
	}

	smscStat[index].mtf_send_ack++;

	uaLog(L_DBG, "inc_mtf_send_ack: %d, ISDN[%s], idx[%d]", smscStat[index].mtf_send_ack, isdn, index);

	return IXOK;
}

int inc_mtf_send_nack(char *isdn)
{
    int    index;

	if ( (index = getNodeIndex(isdn)) < 0) {
		uaLog( L_MIN, "getNodeIndex(%s) failed", isdn);
		return IXERR;
	}

	smscStat[index].mtf_send_nack++;

	uaLog(L_DBG, "inc_mtf_send_nack: %d, ISDN[%s], idx[%d]", smscStat[index].mtf_send_nack, isdn, index);

	return IXOK;
}

int inc_mtf_resp_time(char *isdn)
{
    int    index;

	if ( (index = getNodeIndex(isdn)) < 0) {
		uaLog( L_MIN, "getNodeIndex(%s) failed", isdn);
		return IXERR;
	}

	smscStat[index].mtf_timeout++;

	uaLog(L_DBG, "inc_mtf_recv_time: %d, ISDN[%s], idx[%d]", smscStat[index].mtf_timeout, isdn, index);

	return IXOK;
}

