#include <stdio.h>
#include <errno.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <ua_syslib.h>
#include <ua_sysdef.h>
#include <ua_log.h>

#include <iXGCA.h> //must be include!
#include <iXtypes.h>
#include <iXNqlib.h>
//#include <iXUtil.h>

extern int errno;

/* Static function list */ 
static int _OpenMsgQueForQKey(key_t qKey);
static int _GetMsgQue(int idx, void *data, size_t dataSize);
static int _InsMsgQue(int idx, void *data, size_t dataSize);
/* KT NEW SMSC FOR IXSTAT */
static int _GetMsgQue_Ex(int idx, long mtype, void *data, size_t dataSize);
static int _InsMsgQue_Ex(int idx, long mtype, void *data, size_t dataSize);


static int _OpenMsgQueForQKey(key_t qKey)
{
	int qId = IXERR;

	qId = msgget(qKey, 0666 | IPC_CREAT | IPC_EXCL );
	if(qId < 0)
	{
		if(errno == EEXIST)
			qId = msgget(qKey, 0);
	}
	
	if(qId < 0)
	{
		uaLog(L_CRT, "Can't open MSG_Q (key:%u)", qKey);
		return IXERR;
	}

	return qId;
}

//dataSize = > struct or data sizeof value - sizeof(long) val...
static int _GetMsgQue(int idx, void *data, size_t dataSize)
{
	static stQueList *qList = NULL;
	int i;

	if(qList == NULL)
		qList = GetInstanceMsgQueList();

	//음... 이걸 할당된놈으로 Over를 검사할까.. 어찌할까..????
	if(idx >= MSGQ_MAX_INDEX_SIZE)
	{
		uaLog(L_CRT, "Index range over!!! (%d: 0 ~ 255)", idx);
		return IXERR;
	}

	if(qList[idx].init_v != IXOK)
	{
		if(InitMsgQueueForIndex(idx) == IXERR)
		{
			uaLog(L_CRT, "Init message queue fail... index(%d)", idx);
			return IXERR;
		}
	} 

	for(i=0; i< MSGQ_MAX_RETRY_CNT; i++)
	{
		if(msgrcv(qList[idx].qId, data, dataSize, 0, IPC_NOWAIT | MSG_NOERROR) < 0)
		{
			if(errno == ENOMSG)
				return NOTOK;
			else
			{
				uaLog(L_CRT, "Fatal Error : idx(%d) msgrcv error E:%d", idx, errno);
				return IXERR;
			}
		}
		else
			break;
	}
	
	return IXOK;
}

static int _GetMsgQue_Ex(int idx, long mtype, void *data, size_t dataSize)
{
	static stQueList *qList = NULL;
	static int log_flag = 0;
	int i;

	if(qList == NULL)
		qList = GetInstanceMsgQueList();

	//음... 이걸 할당된놈으로 Over를 검사할까.. 어찌할까..????
	if(idx >= MSGQ_MAX_INDEX_SIZE)
	{
		uaLog(L_CRT, "Index range over!!! (%d: 0 ~ 255)", idx);
		return IXERR;
	}

	if(qList[idx].init_v != IXOK)
	{
		if(InitMsgQueueForIndex(idx) == IXERR)
		{
			uaLog(L_CRT, "Init message queue fail... index(%d)", idx);
			return IXERR;
		}
	} 

	if(mtype < 0)
	{
		//절대값으로 선별적 msgrcv를 지원하지 않도록 한다. (써도 상관은 없지만... 그냥 막는다)
		if(log_flag != IXOK)
		{
			uaLog(L_MAJ, "mtype(%d) is not supported NQLIB. default set 0", mtype);
			log_flag = IXOK;
		}
		mtype = 1;
	}

	for(i=0; i< MSGQ_MAX_RETRY_CNT; i++)
	{
		if(msgrcv(qList[idx].qId, data, dataSize, mtype, IPC_NOWAIT | MSG_NOERROR) < 0)
		{
			if(errno == ENOMSG)
				return NOTOK;
			else
			{
				uaLog(L_CRT, "Fatal Error : idx(%d) msgrcv error E:%d", idx, errno);
				return IXERR;
			}
		}
		else
			break;
	}
	
	return IXOK;
}

static int _InsMsgQue(int idx, void *data, size_t dataSize)
{
	static stQueList *qList = NULL;
	static long mtype = MSGQ_MTYPE_NORMAL; //나중에 확장하던지 하자.. 현재 SMSC에선 무쓸모
	int i, qLen = 0 ;

	if(qList == NULL)
		qList = GetInstanceMsgQueList();

	if(idx >= MSGQ_MAX_INDEX_SIZE)
	{
		uaLog(L_CRT, "Index range over!!! (%d: 0 ~ 255)", idx);
		return IXERR;
	}

	if(qList[idx].init_v != IXOK)
	{
		if(InitMsgQueueForIndex(idx) == IXERR)
		{
			uaLog(L_CRT, "Init message queue fail... index(%d)", idx);
			return IXERR;
		}
	}

	memcpy(data, &mtype, sizeof(long)); //long type cpy....	

	qLen = GetMsgQueCount(idx, qList[idx].pName);
	if(qLen >= DEFAULT_Q_SIZE_NQLIB)
	{
		uaLog(L_CRT, "[%s] Q Size Over. [MAX:%d]", qList[idx].pName, DEFAULT_Q_SIZE_NQLIB);
		return IXERR;
	}
	
	for(i=0; i< MSGQ_MAX_RETRY_CNT; i++)
	{
		if(msgsnd(qList[idx].qId, data, dataSize, IPC_NOWAIT) < 0)
		{
			if(errno != EAGAIN)
			{
				uaLog(L_CRT, "Fatal Error : idx(%d) msgsnd error E:%d", idx, errno);
				return IXERR;
			}
		}
		else
			break;
	}	

	return IXOK;
}

static int _InsMsgQue_Ex(int idx, long mtype, void *data, size_t dataSize)
{
	static stQueList *qList = NULL;
	static int log_flag = 0;
	int i, qLen = 0 ;

	if(qList == NULL)
		qList = GetInstanceMsgQueList();

	if(idx >= MSGQ_MAX_INDEX_SIZE)
	{
		uaLog(L_CRT, "Index range over!!! (%d: 0 ~ 255)", idx);
		return IXERR;
	}

	if(qList[idx].init_v != IXOK)
	{
		if(InitMsgQueueForIndex(idx) == IXERR)
		{
			uaLog(L_CRT, "Init message queue fail... index(%d)", idx);
			return IXERR;
		}
	}

	if(mtype < 1)
	{
		if(log_flag != IXOK)
		{
			uaLog(L_MAJ, "mtype is always bigger than 1.");
			log_flag = IXOK;
		}
		mtype = MSGQ_MTYPE_NORMAL; 
	}

	memcpy(data, &mtype, sizeof(long)); //long type cpy....	

	qLen = GetMsgQueCount(idx, qList[idx].pName);
	if(qLen >= DEFAULT_Q_SIZE_NQLIB)
	{
		uaLog(L_CRT, "[%s] Q Size Over. [MAX:%d]", qList[idx].pName, DEFAULT_Q_SIZE_NQLIB);
		return IXERR;
	}
	
	for(i=0; i< MSGQ_MAX_RETRY_CNT; i++)
	{
		if(msgsnd(qList[idx].qId, data, dataSize, IPC_NOWAIT) < 0)
		{
			if(errno != EAGAIN)
			{
				uaLog(L_CRT, "Fatal Error : idx(%d) msgsnd error E:%d", idx, errno);
				return IXERR;
			}
		}
		else
			break;
	}	

	return IXOK;
}

/* End of static func */

stQueList *GetInstanceMsgQueList()
{
	static stQueList qList[MSGQ_MAX_INDEX_SIZE];
	static int init_v = 0;

	if(init_v == IXOK)
		return qList;

	memset(qList, 0x00, sizeof(qList));
	init_v = IXOK;

	return qList;
}

//print q info... for debug
int PrintMsgQueueInfo(stQueList *info, int idx)
{
	uaLog(L_INFO, "Message Queue Information.....");
	if(idx >= 0)
		uaLog(L_INFO, "Index         : %d", idx);
	uaLog(L_INFO, "Init_v        : %d", info->init_v);
	uaLog(L_INFO, "pName         : %s", info->pName);
	uaLog(L_INFO, "qKey          : 0x%X(%u)", info->qKey, info->qKey);
	uaLog(L_INFO, "qId           : %u", info->qId);
	uaLog(L_INFO, "---------------------------------------------");	
	return IXOK;
}

//.... not used..?
int CheckAlreadyInit(int idx)
{
	stQueList *qList = NULL;
	qList = GetInstanceMsgQueList();
	
	if(idx >= MSGQ_MAX_INDEX_SIZE)
	{
		uaLog(L_CRT, "Index range over!!! (%d: 0 ~ 255)", idx);
		return NOTOK;
	}
	
	if(qList[idx].init_v == IXOK)
		return IXOK;

	return IXERR;
}

int InitMsgQueueForIndex(int idx)
{
	char *pEnv = NULL;
	char fileName[MSGQ_MAX_FILE_LEN], mBuf[MSGQ_MAX_FILE_LEN], idxBuf[32];	
	key_t qKey = 0;
	int qId = 0;
	stQueList *qList = NULL, *pNode = NULL;

	if(idx >= MSGQ_MAX_INDEX_SIZE)
	{
		uaLog(L_CRT, "Index range over!!! (%d: 0 ~ 255)", idx);
		return IXERR;
	}

	qList = GetInstanceMsgQueList();

	if(qList[idx].init_v == IXOK)
	{
		uaLog(L_INFO, "already init [%d:%s].", idx, qList[idx].pName);
		return qList[idx].qId;
	}

	if((pEnv = getenv(UASYS_HOME_ENV_NAME)) == NULL)
	{
		uaLog(L_CRT, "Can't find env <%s>", UASYS_HOME_ENV_NAME);
		return IXERR;
	}

	sprintf(fileName, "%s/%s", pEnv, MSGQ_CONFIG_FILE);
	sprintf(idxBuf, "%d", idx);

	if(getConf(fileName, idxBuf, mBuf) < 0)
	{
		uaLog(L_CRT, "Can't find [%s] in \"%s\"", idxBuf, fileName);
		return IXERR;
	}
	
	pNode = &qList[idx];

	qKey = msgq_getProcKey(mBuf);
	//qKey = msgQKeyGetForName(mBuf); //v610 by Nersion. 큐키값 새로 부여

	if(qKey == IXERR)
	{
		uaLog(L_CRT, "Can't get process[%s] key", mBuf);
		return IXERR;
	}

	qId = _OpenMsgQueForQKey(qKey);
	if(qId < 0)
	{
		uaLog(L_CRT, "Can't get msg que id. [qKey:%u]", qKey);
		return IXERR;
	}

	//Init que info
	pNode->init_v = IXOK;
	strcpy(pNode->pName, mBuf);
	pNode->qKey = qKey;
	pNode->qId = qId;

	//Print Info?
	PrintMsgQueueInfo(pNode, idx); //음.. 어차피 최초 Init 때만 출력될꺼니까 걍 냅두자

	return qId;	
}

//not recommend (Get & Ins func is check queue init state)
int InitAllMsgQueue()
{
	int i = 0;
	for(i=0; i<MSGQ_MAX_VAL; i++)
	{
		if(InitMsgQueueForIndex(i) == IXERR)
		{
			uaLog(L_CRT, "Init fail message queue list index[%d]", i);
		}
	}	
	return IXOK;
}

int msgqCall(int mode, int idx, void *data, size_t dataSize)
{
	static size_t rcvCalcLen = sizeof(long);

	if(mode == MSGQ_INS)
		return _InsMsgQue(idx, data, dataSize - rcvCalcLen);
	else if(mode == MSGQ_GET)
		return _GetMsgQue(idx, data, dataSize - rcvCalcLen);

	uaLog(L_CRT, "mode(%d) is wrong. msgqCall error", mode);
	return IXERR;
}

/* New msgqCall added by Nersion */
int msgqCall_Ex(int mode, int idx, long mtype, void *data, size_t dataSize)
{
	static size_t rcvCalcLen = sizeof(long);

	if(mode == MSGQ_INS)
		return _InsMsgQue_Ex(idx, mtype, data, dataSize - rcvCalcLen);
	else if(mode == MSGQ_GET)
		return _GetMsgQue_Ex(idx, mtype, data, dataSize - rcvCalcLen);

	uaLog(L_CRT, "mode(%d) is wrong. msgqCall error", mode);
	return IXERR;

}

/* msgq status get */
int GetMsgQueCount(int idx, char *pName)
{
	static stQueList *qList = NULL;
	struct msqid_ds buf;

	if(qList == NULL)
		qList = GetInstanceMsgQueList();

	if(idx >= MSGQ_MAX_INDEX_SIZE)
	{
		uaLog(L_CRT, "Index range over!!! (%d: 0 ~ 255)", idx);
		return IXERR;
	}

	if(qList[idx].init_v != IXOK)
	{
		uaLog(L_INFO, "Not found index[%d] message queue info...", idx);
		return IXERR;
	}

//	memset(&buf, 0x00, sizeof(buf)); 

	if(msgctl(qList[idx].qId, IPC_STAT, &buf) < 0)
	{
		uaLog(L_CRT, "Can't get QID[%u] status. index(%d)", qList[idx].qId, idx);
		return IXERR;
	}

	if(pName != NULL)
		strcpy(pName, qList[idx].pName);

	return buf.msg_qnum;
}

/* msgq status get all */
int GetMsgQueCountAll(stMsgQStatus *list, int *cnt)
{
	//char pName[P_NAME_LEN];
	//int	 i;
	
	return 0;
}

char* GetProcessName(int id, char *buf)
{
	static stQueList *qList = NULL;

	if(qList == NULL)
		qList = GetInstanceMsgQueList();

	switch(id)
	{
		case MSGQ_SMSFIF:
		case MSGQ_SIGMO :
		case MSGQ_SIGMT :
//		case MSGQ_SIGMTF :
//		case MSGQ_DIAOUT :
//		case MSGQ_DIAIN :
//		case MSGQ_ESMEROUTER :
			break;
		default :
			strcpy(buf, "UNKWNON");
			return buf; 
	}

	strcpy(buf, qList[id].pName);

	return NULL;
}

//v610 by Nersion. Message Queue Key Get.
int msgQKeyGetForName(char *procName)
{
    char *pTmp, *pEnv;
    int key;

    if ((pEnv = getenv(UASYS_HOME_ENV_NAME)) == NULL){
        uaLog( L_CRT,"pEnv Not found %s",UASYS_HOME_ENV_NAME);
        return  -1;
    }

    pTmp = cfg_getSecConf(pEnv, PROC_CONF_FILE, "[MESSAGE_QUEUE_KEY]", procName);
    if (pTmp == NULL) {
        uaLog( L_CRT,"%s %s key is not found", pEnv, procName);
        return  -1;
    }

    key = strtol( pTmp, (char**)0, 0);

    return key;
}
