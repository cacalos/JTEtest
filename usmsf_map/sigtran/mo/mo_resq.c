
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include <limits.h>

#include <iXtypes.h>
#include <iXCauseCode.h>
#include <SS7/ss7_resq.h>

#include <ua_log.h>
#include <ua_syslib.h>
#if 0
#include <SS7/links.h>
#include <ua_ss7mgt.h>
#include <iXMapStat.h>
#include <iXDpcStat.h>
#endif

#include "mo.h"

int                moUserIDinTable[MAX_DIAG_ID_MO];
int                moUserTimeInTable[MAX_DIAG_ID_MO];

//extern HashTable gHash;
extern unsigned int        gTimeOutCnt;


int InitMoResponseQ()
{
	init_resq_data();
    return IXOK;
}

int GetNumMoResQ()
{           
    //return num_used;
    return resq_data_count();
}

stMoMsg *GetMoQelmt(int diagId)
{
	stMoResponseQ *moResQ;

	moResQ = get_resq_data(diagId);
	if(!moResQ)
	{
		uaLog(L_CRT, "GetMoQelmt: get_resq_data fail. diag_id: %d", diagId);
		return NULL;
	}

	if(moResQ->status != MQ_SENT &&
	   moResQ->status != MQ_BEGINNULL )
	{
		uaLog(L_MAJ, "Q status error.  Diag = %d, status = %d",
				diagId, moResQ->status);
		return NULL;
	}

	return &moResQ->moMsg;
}

int GetMoQsts(int diagId)
{
	stMoResponseQ *moResQ;

	if((moResQ = get_resq_data(diagId)) == NULL)
	{
		 uaLog(L_MAJ, "GetMoQsts(): Diag ID, In Q = %d, diag = %d",
				moResQ->diag_id, diagId);
		 return IXERR;
	}

	return moResQ->status;
}


int insertMoResQ(int diagId, stMoMsg *new_msg)
{
	stMoResponseQ *moResQ;
	int status;

	if( new_msg == NULL )
		status = MQ_BEGINNULL;
	else
		status = MQ_SENT;

	if((moResQ = get_resq_data(diagId)) == NULL)
	{
		// insert
		return add_resq_data(diagId, status, new_msg);
	} 
	else 
	{
		// update
		moResQ->diag_id = diagId;
		moResQ->status = status;
		moResQ->sent_tm = time(0);
		memcpy(&moResQ->moMsg, new_msg, sizeof(stMoMsg));
	}

	return IXOK;
}

#if 0
int getNodeIndex( int diagId , char *netIdx)
{
	stMoResponseQ *moResQ;

	if((moResQ = get_resq_data(diagId)) == NULL)
		return IXERR;

	return moResQ->nodeIdx;
}

int setNodeIndex( int diagId, char *isdn )
{
	int idx;
	stMoResponseQ *moResQ;

	if((moResQ = get_resq_data(diagId)) == NULL)
		return IXERR;


	if((idx = getHash( &gHash, isdn )) >= 0) {
		moResQ->nodeIdx = idx;
		setSS7StatDestAddr( idx, isdn );
		uaLog( L_INFO, "setNodeIndex isdn=%s idx=%d", isdn, idx );
	}

	return IXOK;
}
#endif

/* set trace mode
 * */
int setTraceModeMo( int diagId, stAddr *orig, stAddr *dest, stAddr *imsi )
{
	stAddr *ptr = 0;
	int level;
	stMoResponseQ *moResQ;

	if ( (level = IsThisMinTrace(dest)) > 0 ) ptr = dest;
	else if( (level = IsThisMinTrace(orig)) > 0 ) ptr = orig;
	else if( (level = IsThisMinTrace(imsi)) > 0 ) ptr = imsi;

	if ( ptr ) {
		if((moResQ = get_resq_data(diagId)) == NULL){
			// 없으니 insert 
			add_resq_data_for_trace(diagId, 1, level, ptr);	
		} else{
			// 있으니 update
			moResQ->diag_id = diagId;
			moResQ->trace = 1;
			moResQ->level = level;
			memcpy(&moResQ->addr, ptr, sizeof(stAddr));
		}           
		uaLog(L_INFO, "setTrace did=%d %s %s %s", diagId, orig->min, dest->min, imsi->min);
	}

	return 0;
}

stAddr* getTraceNum( int diagId) 
{
	stMoResponseQ *moResQ;

	if((moResQ = get_resq_data(diagId)) == NULL)
		return NULL;

	return &moResQ->addr;
}

int isInTrace( int diagId, int level) 
{
	stMoResponseQ *moResQ;

	if((moResQ = get_resq_data(diagId)) == NULL)
		return 0;

	if(moResQ->level >= level)
		return moResQ->trace;

	return 0;
}



int SetDone(int diagId)
{
	return remove_resq_data(diagId);
}


/* find time-outed mesgs, and send the results to job queue */
int CheckTimeOut(int timeMo)
{
	check_timeout(timeMo, &gTimeOutCnt);
}



void prn_moResQ(int diagId)
{
	stMoResponseQ *moResQ;
	time_t    cur_time;

	if((moResQ = get_resq_data(diagId)) == NULL)
	{
		uaLog(L_MAJ,
				"Not Existed Mo Response: DiagId= %d", diagId);
		return ;
	}

	time(&cur_time);

	uaLog(L_MAJ,
			"For %d:  Diag= %d, status= %d, sent_tm= %d, ellapsed= %d",
			diagId, moResQ->diag_id, moResQ->status,
			moResQ->sent_tm, cur_time - moResQ->sent_tm);
}


int getDiagId(int userId)
{
	int diagId;

	if ( userId < 0 || userId >= MAX_DIAG_ID_MO) {
		return -1;
	}

	uaLog( L_INFO, "getDiagId userId=%d diagId=%d", userId, moUserIDinTable[userId]);

    diagId = moUserIDinTable[userId];
    moUserIDinTable[userId] = 0;
    moUserTimeInTable[userId] = 0;

    return diagId;
}


int SetDiagIDinTable(int userId, int diagId)
{
    time_t                now;

	if ( userId < 0 || userId >= MAX_DIAG_ID_MO) {
		uaLog( L_MAJ, "Invalid user id %d", userId);
		return IXERR;
	}

	now = time(0);
	moUserIDinTable[userId] = diagId;
	moUserTimeInTable[userId] = now;
	return IXOK;
}


int UnsetDiagIDinTable(int userId)
{
	if ( userId < 0 || userId >= MAX_DIAG_ID_MO) {
		uaLog( L_MAJ, "Invalid user id %d", userId);
		return IXERR;
	}

    moUserIDinTable[userId] = 0;
    moUserTimeInTable[userId] = 0;
    return IXOK;
}


int CheckDiagIDinTable(int sec)
{
    int                       i, n = 0;
    time_t                    now;

    if(sec <= 0)
        return -1;

    time(&now);
    for(i = 0; i < MAX_DIAG_ID_MO; i++)
        if(moUserTimeInTable[i] != 0 && (moUserTimeInTable[i] + sec) <= now)
        {
            moUserIDinTable[i] = 0;
            moUserTimeInTable[i] = 0;
            n++;
        }

    return n;
}

