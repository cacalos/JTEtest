#include <signal.h>
#include <errno.h>
#include <sys/msg.h>
#include <signal.h>

#include <uxlib/ux_util.h>

#include <ua_log.h>
#include <ua_sysdef.h>
#include <ua_syslib.h>

#include <iXGCA.h>
#include <iXstat.h>

#include "stat_func.h"

#define NO_EXIST_STAT   0
#define EXIST_STAT      1

int gLogId;

int smscCnt;
int diaCnt;

stDIAstat 			gpDiaStat[MAX_SMSC_LIST];
stSMSCstat 			gpSmscStat[MAX_SMSC_LIST];

void IntProc()
{
    uaLog(L_CRT, "-----  %s Ends  -----\n", _MODULE_NAME);
    exit(0);
}

void gpSmscStatAdd(stSMSCstat *stat)
{
	char            stat_chk = NO_EXIST_STAT;
	int 			i, idx;
	static int 		cnt = 0;

	for(i = 0; i < cnt; i++)
	{
		if(strcmp(gpSmscStat[i].isdn, stat->isdn) == 0)
		{
			idx = i;
			stat_chk = EXIST_STAT;
			break;
		}
	}

	if(stat_chk == NO_EXIST_STAT)
	{
		idx = i;
        cnt = i + 1;
        uaLog(L_MIN, "Add MAP stat info[isdn=%s, idx=%d], cnt[%d]", stat->isdn,  idx, i);

		smscCnt = cnt;
	}

	if(cnt == MAX_SMSC_LIST)
    {
        uaLog(L_CRT, "SMSC Map statistic list is full. can not store dia stat. id[%s]", stat->isdn);
        return;
    }

	strcpy(gpSmscStat[idx].isdn, stat->isdn);

	gpSmscStat[idx].mof_send_succ += stat->mof_send_succ;
	gpSmscStat[idx].mof_send_fail += stat->mof_send_fail;
	gpSmscStat[idx].mof_resp_ack += stat->mof_resp_ack;
	gpSmscStat[idx].mof_resp_nack += stat->mof_resp_nack;
	gpSmscStat[idx].mof_timeout += stat->mof_timeout;

	gpSmscStat[idx].mtf_recv_succ += stat->mtf_recv_succ;
	gpSmscStat[idx].mtf_recv_fail += stat->mtf_recv_fail;
	gpSmscStat[idx].mtf_send_ack += stat->mtf_send_ack;
	gpSmscStat[idx].mtf_send_nack += stat->mtf_send_nack;
	gpSmscStat[idx].mtf_timeout += stat->mtf_timeout;

	return;
}


void gpDiaStatAdd(stDIAstat *stat)
{
	char            stat_chk = NO_EXIST_STAT;
	int 			i, idx;
	static int 		cnt = 0;

	for(i = 0; i < cnt; i++)
	{
		if(strcmp(gpDiaStat[i].isdn, stat->isdn) == 0)
		{
			idx = i;
			stat_chk = EXIST_STAT;
			break;
		}
	}

	if(stat_chk == NO_EXIST_STAT)
	{
		idx = i;
        cnt = i + 1;
        uaLog(L_MIN, "Add DIA stat info[isdn=%s, idx=%d], cnt[%d]", stat->isdn,  idx, i);

		diaCnt = cnt;
	}

	if(cnt == MAX_SMSC_LIST)
    {
        uaLog(L_CRT, "SMSC DIA  statistic list is full. can not store dia stat. id[%s]", stat->isdn);
        return;
    }

	strcpy(gpDiaStat[idx].isdn, stat->isdn);

	gpDiaStat[idx].ofr_send_succ += stat->ofr_send_succ;
	gpDiaStat[idx].ofr_send_fail += stat->ofr_send_fail;
	gpDiaStat[idx].ofr_resp_ack += stat->ofr_resp_ack;
	gpDiaStat[idx].ofr_resp_nack += stat->ofr_resp_nack;
	gpDiaStat[idx].ofr_timeout += stat->ofr_timeout;

	gpDiaStat[idx].tfr_recv_succ += stat->tfr_recv_succ;
	gpDiaStat[idx].tfr_recv_fail += stat->tfr_recv_fail;
	gpDiaStat[idx].tfr_send_ack += stat->tfr_send_ack;
	gpDiaStat[idx].tfr_send_nack += stat->tfr_send_nack;
	gpDiaStat[idx].tfr_timeout += stat->tfr_timeout;

	return;
}


int UpdateSmscForStat(stStatMsg *stat)
{
	gpSmscStatAdd(&stat->u.smscStat);
	
	return IXOK;
}

int UpdateDiaNodeForStat(stStatMsg *stat)
{
	gpDiaStatAdd(&stat->u.diaStat);

	return IXOK;
}

int UpdateStatProc(stStatMsg *msg)
{
	switch(msg->protocol)
	{
		case MAP_STAT_DIA_STAT:
			UpdateDiaNodeForStat(msg);
			break;
		case MAP_STAT_SMSC_STAT:
			UpdateSmscForStat(msg);
			break;
		default:
			uaLog(L_CRT, "Can't find Protocol Number[%d]", msg->protocol);
			return IXERR;
	}
	
	return IXOK;
}

int main(int argc, char *argv[])
{
	char			fname[MAX_PATH_NAME];
	char 			*env;
	int 			key, ret;

	stStatMsg 		statMsg;

	ua_changeCoreDir(_MODULE_NAME);

	GET_SYS_HOME_ENV(env);
	sprintf( fname, "%s/log/%s/%s", env, _MODULE_NAME, _MODULE_NAME);

	gLogId = LOG_open( fname,
			LOG_MODE_LIMIT_SIZE | LOG_FORMAT_TIME_MSEC |
			LOG_FORMAT_CATEGORY | LOG_FORMAT_SRC_FILE | LOG_FLAG_EXT_CTRL|
			LOG_FLAG_STDOUT | LOG_FLAG_THREAD_SAFE );
	if ( gLogId < 0) {
		fprintf( stderr, "LOG_open: E=%d", gLogId); 
		return -1; 
	}

	key = msgq_getProcKey( _MODULE_NAME);
	if ( key < 0) {
		uaLog( L_CRT, "MSG Q KEY not found for %s", _MODULE_NAME);
		return -1;
	}

	proc_heartInit( _MODULE_NAME);

    uaLog(L_CRT, "+++++ %s Start +++++", _MODULE_NAME);

    signal(SIGINT,  (void (*)(int))IntProc);
    signal(SIGTERM, (void (*)(int))IntProc);

    if(OpenGCA() != IXOK)
    {
        uaLog(L_CRT, "iXGCA Open Fail! exit..");
        exit(1);
    }
    uaLog(L_CRT, "iXGCA Open OK!");

	//Init For MSGQ...
	OpenStatQ();
	uaLog(L_CRT, "Init Msg Queue ........................... OK!");

	ux_make_dir(getenv("SMS_STAT_DIR"), 0755);

    while(1)
    {
		proc_heartBeat();
		
		StatProc(NULL);

		memset(&statMsg, 0, sizeof(stStatMsg));

		ret = GetStatMsg(&statMsg);
		if(ret != IXOK)
			usleep(2000);
		else 
			UpdateStatProc(&statMsg);
		
    }
}

