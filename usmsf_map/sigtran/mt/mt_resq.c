
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <didlib.h>

#include <limits.h>

#include <iXtypes.h>
#include <ua_log.h>
#include <iXCauseCode.h>
#include <SS7/ix7map.h>
#include <SS7/ss7_resq.h>

#include <usrg/utcap.h>
#include "mt.h"

stMtResponseQ mtResQ[MAX_DIAG_ID_MT];

int			head, tail;
int			num_used;

int InitMtResponseQ()
{
	init_resq_data();

	return IXOK;
}

int GetNumMtResQ()
{
	//return num_used;
	return resq_data_count();
}

int GetMtQelmt(unsigned char msgRef, char *supi, stMtResponseQ *inRes)
{
	stMtResponseQ *result;

	result = get_resq_data(msgRef, supi);
	if(!result)
	{
        uaLog(L_CRT, "GetInQelmt: get_resq_data fail. msgRef: %d, IMSI:%s", msgRef, supi);
		return IXERR;
	}

    if(result->status != MQ_SENT)
    {
        uaLog(L_CRT, "Q status error.  msgRef:%d, IMSI:%s, status = %d", msgRef, supi, result->status);
        return IXERR;
    }
    memcpy(inRes, result, sizeof(stMtResponseQ));
    return IXOK;
}

#if 0
int setTraceModeIN(unsigend char msgRef, stAddr *orig, stAddr *dest)
{
	stAddr *ptr = 0;
	int level;
    stMtResponseQ *inResQ;

	if ( (level = IsThisMinTrace(dest)) > 0 ) ptr = dest;
	else if( (level = IsThisMinTrace(orig)) > 0 ) ptr = orig;
	
	if ( ptr) {
        if((inResQ = get_resq_data(msgRef, dest->min)) == NULL) {
			// 없으니 insert 하자
			add_resq_data_for_trace(diagId, 1, level, ptr);
		} else {
			// 있으면 정보 update
			memcpy( &inResQ->imsi, ptr, sizeof(stAddr));
			inResQ->trace = 1;
			inResQ->level = level;
			inResQ->diag_id = diagId;
		}
		uaLog( L_INFO, "setTrace did=%d %s %s", diagId, orig->min, dest->min);
	}
	return IXOK;
}

int isInTrace( int diagId, int level)
{
    stMtResponseQ *inResQ;

    if((inResQ = get_resq_data(diagId)) == NULL)
	    return 0;

    if ( inResQ->level >= level)
	    return inResQ->trace;

	return 0;
}

stAddr *getTraceNum( int diagId)
{
    stMtResponseQ *inResQ;

    if((inResQ = get_resq_data(diagId)) == NULL)
	    return NULL;

	return &inResQ->imsi;
}
#endif

#if 0
int getNodeIndex( int diagId)
{
    stMtResponseQ *inResQ;

    if((inResQ = get_resq_data(diagId)) == NULL)
	    return IXERR;

	return inResQ->nodeIdx;
}

int setNodeIndex( int diagId, char *addr)
{
	int idx;
	stMtResponseQ *inResQ;

	if((inResQ = get_resq_data(diagId)) == NULL)
		return IXERR;

	if ((idx = getHash( &gHash, addr)) >= 0) {
		inResQ->nodeIdx = idx;
		strcpy( inResQ->nodeAddr, addr);

		setSS7StatDestAddr( idx, addr);

		uaLog( L_INFO, "setNodeIdx idx=%d isdn=%s", idx, addr);
	}
	return IXOK;
}
#endif

int insertMtResQ(int diag_id, int u_id, int prov_id, int inv_id,
	  unsigned char acn, USccpAddr *dstAddr, USccpAddr *srcAddr, char isMMS, stAddr *imsi, unsigned char msgRef, stNodeNumber *node)
{
	stMtResponseQ *inRes;

	if((inRes = get_resq_data(msgRef, imsi->min)) == NULL) {
		// 없으면 insert
		return add_resq_data(diag_id, u_id, prov_id, inv_id, acn, dstAddr, srcAddr, isMMS, imsi, msgRef, node);
	} else {
		// 있으면 정보 update
		inRes->diag_id = diag_id;
		inRes->user_id = u_id;
		inRes->prov_id = prov_id;
		inRes->inv_id = inv_id;
		inRes->acn = acn;
		memcpy(&inRes->dstAddr, dstAddr, sizeof(USccpAddr));
		memcpy(&inRes->srcAddr, srcAddr, sizeof(USccpAddr));
		inRes->sent_tm = time(0);
		inRes->status = MQ_SENT;
		inRes->msgRef = msgRef;
		memcpy(&inRes->imsi, imsi, sizeof(stAddr));
		memcpy(&inRes->node, node, sizeof(stNodeNumber));
	}

    return IXOK;
}

int CleanMtResQ()
{
	return IXOK;
}

int SetDone(unsigned char msgRef, char *supi)
{
	return remove_resq_data(msgRef, supi);
}

/* find time-outed mesgs, and send the results to job queue */
int CheckTimeOut(int timeOut)
{
	check_timeout(timeOut);
}

int ShowQStatus()
{
	uaLog(L_CRT,
			"head = %2d, tail = %2d, Q_size = %2d, In_use = %2d, InQ=%d",
			head, tail, MAX_DIAG_ID_MT, num_used, GetMtQLen());

	return IXOK;
}


