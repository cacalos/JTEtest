
#include <iXTrace.h>
#include <ua_log.h>
#include <iXSem.h>

stTraceShm    *gpTrace;

int gTraceLevel;
stAddr gTraceAddr;
int gMyCallIndex;


void OpenTraceShm()
{
    gpTrace = (stTraceShm *)GetTracep();
}


int ChangeTraceShm(stTraceShm *pstTraceMsg)
{
//    if(P(IXTRACE_SEM_ID) < 0)
 //   {
  //      uaLog(L_CRT, "Trace Shm P Error, semid: %d",
   //         IXTRACE_SEM_ID);
  //      return IXERR;
 //   }

    memcpy((void *)gpTrace, (void *)pstTraceMsg, sizeof(stTraceShm));

//    if(V(IXTRACE_SEM_ID) < 0)
 //   {
  //      uaLog(L_CRT, "Trace Shm V Error, semid: %d",
   //         IXTRACE_SEM_ID);
    //    return IXERR;
  //  }
    return IXOK;
}


int ResetTraceShm()
{
/*	

    if(P(IXTRACE_SEM_ID) < 0)
    {
        uaLog(L_CRT, "Trace Shm P Error, semid: %d",
            IXTRACE_SEM_ID);
        return IXERR;
    }
*/
	
    bzero((void *)&gpTrace, sizeof(stTraceShm));
/*
    if(V(IXTRACE_SEM_ID) < 0)
    {
        uaLog(L_CRT, "Trace Shm V Error, semid: %d",
            IXTRACE_SEM_ID);
        return IXERR;
    }
*/	
    return IXOK;
}


int GetTraceMin(stTraceShm *msg)
{
	int i, expired= 0;
	time_t now;

    memcpy((void *)msg, (void *)gpTrace, sizeof(stTraceShm));

	now = time(0);
	for( i =0; i< msg->reg_count; )
	{
		/* expire time을 체크하도록 수정함 */
		if ( msg->trace[i].time < now ) {
			/* time expired, move data */
			memmove( &msg->trace[i], &msg->trace[msg->reg_count-1], 
					sizeof(msg->trace[0]));
			msg->reg_count --;
			expired = 1;
		}
		else i++;
	}

	if ( expired) ChangeTraceShm( msg);

	return IXOK;
}


void InitTraceShm()
{
    uaLog(L_CRT, "Init Trace Shm !!");
    bzero((void *)gpTrace, sizeof(stTraceShm));
    uaLog(L_CRT, "gpTrace->reg_count=%d", gpTrace->reg_count);
}


int ClearTrace_IndexShm(int idx, char *mdn)
{
    int               i;

	if ( idx < 0 || idx >= gpTrace->reg_count)
		return -1;

	if ( mdn)
		strcpy( mdn, gpTrace->trace[idx].addr.min);

	for(i = idx; i < gpTrace->reg_count -1; i++) {
		memcpy(&gpTrace->trace[i], &gpTrace->trace[i+1], sizeof(gpTrace->trace[0]));
	}

	gpTrace->reg_count--;
	bzero(&gpTrace->trace[gpTrace->reg_count], sizeof(gpTrace->trace[0]));

	return 0;
}


int IsThisMinTrace(stAddr *addr)
{
	time_t now;
	int  i;

	if ( addr == NULL) return IXERR;

	now = time(0);
	for(i =0; i< gpTrace->reg_count; )
	{
		/* expire time을 체크하도록 수정함 */
		if(strcmp(gpTrace->trace[i].addr.min, addr->min) == 0 &&
				gpTrace->trace[i].time > now )
			return gpTrace->trace[i].level;
		if ( gpTrace->trace[i].time < now ) {
			/* time expired, move data */
			memmove( &gpTrace->trace[i], &gpTrace->trace[gpTrace->reg_count-1], 
					sizeof(gpTrace->trace[0]));
			gpTrace->reg_count --;
		}
		else i++;
	}
	
    return IXERR;
}

int GetTraceMinInfo(char *min, time_t *until_time, int *level)
{
	time_t now;
	int  i;

	if ( min == NULL) 
		return IXERR;

	now = time(0);
	for(i =0; i < gpTrace->reg_count; i++)
	{
		/* expire time을 체크하도록 수정함 */
		if(strcmp(gpTrace->trace[i].addr.min, min) == 0 && gpTrace->trace[i].time > now)
		{	
			*until_time = gpTrace->trace[i].time;
			*level = gpTrace->trace[i].level;
			return IXOK;
		}

		if ( gpTrace->trace[i].time < now ) {
			/* time expired, move data */
			memmove( &gpTrace->trace[i], &gpTrace->trace[gpTrace->reg_count-1], 
					sizeof(gpTrace->trace[0]));
			gpTrace->reg_count --;
		}
	}
	
    return IXERR;
}

int setTraceMode( stAddr *orig, stAddr *dest, stAddr *imsi)
{
	stAddr *ptr = 0;

	if ( (gTraceLevel = IsThisMinTrace(dest)) > 0 ) ptr = dest;
	else if( (gTraceLevel = IsThisMinTrace(orig)) > 0 ) ptr = orig;
	else if( (gTraceLevel = IsThisMinTrace(imsi)) > 0 ) ptr = imsi;
	
	if ( ptr) {
		memcpy( &gTraceAddr, ptr, sizeof(stAddr));
	}
	else{
		memset( &gTraceAddr, 0x00, sizeof(stAddr)); //v520
	}


	return 0;
}


/* Added by ksy 2006-08-17 v260 */
int IsGlobalTrace()
{
	time_t     currTime;

	time(&currTime);
	if(gpTrace->traceFlag == GLOBAL_TRACE_ON &&
       gpTrace->expireTime > currTime)
		return IXOK;

	return IXERR;
}

void setGlobalTrace()
{
	gpTrace->expireTime = time(0)+DEFAULT_GLOBAL_TRACE_TIME; /* 360 default expire time */
	gpTrace->traceFlag  = GLOBAL_TRACE_ON;
}

void resetGlobalTrace()
{
	gpTrace->traceFlag  = GLOBAL_TRACE_OFF;
	gpTrace->expireTime = 0;
}


int ProcessStoreAddr(char *addr, int duration, int level)
{
    int              idx;
    stTraceShm       msg;

    bzero((void *)&msg, sizeof(stTraceShm));    
    GetTraceMin(&msg);
    idx = IsExistAddr(addr);
    
    // only for EndProc
    gMyCallIndex = idx;

    if(idx >= 0) // exist already
    {   
		msg.trace[idx].time = duration + time(0);
		msg.trace[idx].level = level;
    }
    else // new
    {
        if(msg.reg_count == MAX_TRACE_REG_CNT)
        {
			/* table is full */
			return IXERR;
        }
        else
        {
            strcpy(msg.trace[msg.reg_count].addr.min, addr);
            msg.trace[msg.reg_count].addr.ton = TON_NATIONAL;
            msg.trace[msg.reg_count].addr.npi = NPI_E164;
            msg.trace[msg.reg_count].addr.len = 
				strlen(msg.trace[msg.reg_count].addr.min);
		msg.trace[msg.reg_count].time = duration + time(0);
	//		msg.trace[msg.reg_count].time = duration;
			msg.trace[msg.reg_count].level = level;
            msg.reg_count++;
        }

        gMyCallIndex = msg.reg_count -1;
    }

    return ChangeTraceShm(&msg);
}


int IsExistAddr(char *addr)
{
    int              i;
    stTraceShm       msg;
	time_t now;

    bzero((void *)&msg, sizeof(stTraceShm));
    GetTraceMin(&msg);
	now = time(0);

    for(i = 0; i < msg.reg_count; i++)
       if(strcmp(msg.trace[i].addr.min, addr) == 0 && msg.trace[i].time> now )
            return i;

    return -1; //Not exist.
}


int IsExistIndex(int idx)
{
    stTraceShm       msg;
	time_t now;

    bzero((void *)&msg,sizeof(stTraceShm));
    GetTraceMin(&msg);

	now = time(0);//test required

    if(idx >= msg.reg_count || msg.trace[idx].time < now)
        return  -1;
    return idx;
}
