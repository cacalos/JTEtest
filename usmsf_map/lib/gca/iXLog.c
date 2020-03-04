
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdarg.h>
#include <time.h>
#include <errno.h>

#include <iXCauseCode.h>
#include <iXtypes.h>
#include <iXLog.h>

#include <stdlib.h>
#include <ua_sysdef.h>

#define DATE_LEN        9
#define MAX_BUF         1024
#define MAX_PATH_NAME   128
#define MAX_TIME_LEN    9
#define PROC_ID_NOT_SET -1
#define MAX_MSG_PAYLOAD_LEN      65532

char    gCurNackLogDate[DATE_LEN+2];
char    gOldNackLogDate[DATE_LEN+2];
char    gLogModulName[MAX_PATH_NAME];
FILE    *gnFd = NULL;

//char    gMinTraceFile[MAX_PATH_NAME];
///*
char    gCurMIN[MAX_PATH_NAME];
char    gOldMIN[MAX_PATH_NAME];
FILE    *gMinTrFd = NULL;
//*/

int     gLogDisplayFlag = 0;

/* 로그를 stderr로 display해주는 기능. 현재는 iXRecovery가 Backup된 MMDB를 */
/* Recovery할때의 과정이 터미널로 출력되는 부분에서만 사용되고 있음        */
void LogDisplayOn()
{
    gLogDisplayFlag = 1;
}
	 
void LogDisplayOff()
{
    gLogDisplayFlag = 0;
}

int MinTrace_Hex(char *fName, char *funName, int lNum, stAddr *addr, char *cmt,
        unsigned char *s, int len)
{
    int    i;
    char   buf[MAX_MSG_PAYLOAD_LEN], *ptr = buf;
 
    if(addr == NULL || fName == NULL)
        return IXERR;
 
    if(len < 1 || s == NULL)
        return IXERR;

    strcpy( ptr, cmt);
    ptr += strlen(ptr);
 
    strcpy( ptr, "-----------------------------------------------------------\n");
    ptr += strlen(ptr);
 
    for(i = 0; i < len; i++)
    {
        sprintf(ptr, "%02X ", (unsigned char)s[i]);
        ptr += strlen(ptr);
 
        if(i % 20 == 19) {
            sprintf(ptr, "\n");
            ptr+= strlen(ptr);
        }
    }
 
    strcpy( ptr, "\n-----------------------------------------------------------\n");
 
    MinTrace( fName, funName, lNum, addr, "%s", buf);
    return IXOK;
}

int MinTrace(char *fName, char *funName, int lNum, stAddr *addr, char *fmt,
              ...)
{
    char            buf[MAX_MSG_PAYLOAD_LEN];
    va_list         args;
    time_t          now;
	struct tm timer;
    char            logPathName[MAX_PATH_NAME];
    char           *homePtr;
	char num[64];
	int len, curDate;
	static int lastDate = 0;
	int		tmpLen;


    if(IsThisMinTrace(addr) == IXERR)
        return NOTOK;

    now = time(0);
	localtime_r( &now, &timer);
	len = strlen(fName);
    sprintf( buf, "\n%12s:%4d [%02d:%02d:%02d]\n", 
		(len>12)?fName+len-12:fName, lNum, 
		timer.tm_hour, timer.tm_min, timer.tm_sec);

    va_start(args,fmt);

 	vsprintf(&buf[strlen(buf)],fmt,args);
    va_end(args);

//#if 0
    /* Write error message to Log file */
    strcpy(gCurMIN, addr->min);
	curDate = (timer.tm_year+1900)*10000 + (timer.tm_mon+1)*100 + timer.tm_mday;

    if( gMinTrFd == NULL || strcmp(gCurMIN, gOldMIN) || curDate != lastDate)
    {
        strcpy(gOldMIN, gCurMIN);
        if(gMinTrFd != NULL)
            fclose(gMinTrFd);

		homePtr = getenv("TRACE_HOME_ENV_NAME");
		if ( homePtr == NULL) return;

//		sprintf(logPathName, "%s/log/maptrc/%02d/%02d",
//			homePtr, timer.tm_mon+1, timer.tm_mday);
//		sprintf(logPathName, "%s/trace/",
//			homePtr);
		sprintf(logPathName, "%s/",
			homePtr);

		ua_mkdir( logPathName);

		sprintf( &logPathName[strlen(logPathName)], 
			"%04d%02d%02d_imsi-%s", 
			timer.tm_year+1900, timer.tm_mon+1, timer.tm_mday, gCurMIN);


/*
		sprintf( &logPathName[strlen(logPathName)], 
			"/trc_%s.%04d%02d%02d", 
			gCurMIN, timer.tm_year+1900, timer.tm_mon+1, timer.tm_mday);
*/
        if((gMinTrFd = fopen(logPathName, "a+")) == NULL) {
            perror("File Open Error");
			return;
		}

		lastDate = curDate;
    }

    fprintf(gMinTrFd, "%s\n", buf);
    fflush(gMinTrFd);
//#endif

	return IXOK;
}


void NackPrint(char *pName, char *fmt, ...)
{
    char           buf[200];
    va_list        args;
    time_t         timer;
    char           logPathName[MAX_PATH_NAME];
    char           timeBuf[MAX_TIME_LEN];
    char          *homePtr;
    static FILE          *fp = NULL;

    va_start(args, fmt);

#ifndef NO_VPRINTF
    vsprintf(buf, fmt, args);
#else
    {
        FILE foo;

        foo._cnt = MAX_BUF;
        foo._base = foo._ptr = buf;
        foo._flag = _IOWRT+_IOSTRG;
        _doprnt(fmt, args, &foo);
        *foo._ptr = NULL;
    }
#endif

    va_end(args);

#ifdef  PRINT
    dprintf("%s", buf);
#endif

    time(&timer);
    strftime(gCurNackLogDate, DATE_LEN+2, "%Y%m%d%H", localtime(&timer));
    strftime(timeBuf, MAX_TIME_LEN, "%H:%M:%S", localtime(&timer));
    strcpy(gLogModulName, "");
    if( fp == NULL || strcmp(gCurNackLogDate, gOldNackLogDate))
    {
        strcpy(gOldNackLogDate, gCurNackLogDate);
        if(gnFd != NULL)
            fclose(gnFd);

		homePtr = getenv(UASYS_HOME_ENV_NAME);
		if ( homePtr == NULL) return;

		sprintf(logPathName, "%s/log/NACKLOG", homePtr);
		ua_mkdir( logPathName);

		sprintf(&logPathName[strlen(logPathName)], "/NACK%s", gCurNackLogDate);
        if((gnFd = fopen(logPathName, "a+")) == NULL) {
            perror("File Open Error");
			return;
		}
    }

    fprintf(gnFd, "[%s][%-15s][%s]\n", timeBuf, pName, buf);
    fflush(gnFd);
}


#if 0
char *errToStr(int errCode)
{
    switch( errCode )
    {   
        case    CC_ENGINE_TIMEOUT :             return "CC_ENGINE_TIMEOUT" ;
        case    CC_SIP_TIMEOUT :                return "CC_SIP_TIMEOUT" ;
        case    CC_ESME_TIMEOUT :               return "CC_ESME_TIMEOUT" ;
        case    CC_ESME_NOT_CONNECTED :         return "CC_ESME_NOT_CONNECTED" ;
        case    CC_ESME_TEMPARARY_ERR :         return "CC_ESME_TEMPARARY_ERR" ;
        case    CC_ESME_PERMANENT_ERR :         return "CC_ESME_PERMANENT_ERR" ;
        case    CC_ESME_REJECT :                return "CC_ESME_REJECT" ;
        case    CC_ESME_OTHER_ERROR :           return "CC_ESME_OTHER_ERROR" ;
        case    CC_NO_ROUTE_CANC :              return "CC_NO_ROUTE_CANC" ;
        case    CC_ADMIN_CANC :                 return "CC_ADMIN_CANC" ;
        case    CC_SOURCE_CANC :                return "CC_SOURCE_CANC" ;
        case    CC_ADMIN_BARRED :               return "CC_ADMIN_BARRED" ;
        case    CC_LOCAL_ERROR :                return "CC_LOCAL_ERROR" ;
        case    CC_GET_CONTACT_FAILED :         return  "CC_GET_CONTACT_FAILED" ;
        case    CC_INVALID_SVC_STATUS :         return  "CC_INVALID_SVC_STATUS" ;
        case    CC_MODEL_NAME_NONE :            return  "CC_MODEL_NAME_NONE" ;
        case    CC_SUBSCRIBER_NOT_REGIST :      return  "CC_SUBSCRIBER_NOT_REGIST" ;
        case    CC_XML_NOT_SUPPORT :            return  "CC_XML_NOT_SUPPORT" ;
        case    CC_MODEL_NOT_FOUND :            return  "CC_MODEL_NOT_FOUND" ;
        case    CC_REG_EXPIRED :                return  "CC_REG_EXPIRED" ;
        case    CC_INACTIVE_SUBS    :           return  "CC_INACTIVE_SUBS" ;
        case    CC_NO_SUBSCRIBER :              return  "CC_NO_SUBSCRIBER" ;
        case    CC_SERVICE_UNAVAILABLE :        return  "CC_SERVICE_UNAVAILABLE" ;
        case    CC_SIP_INVALID_HEADER_LEN :     return  "CC_SIP_INVALID_HEADER_LEN" ;
        case    CC_SIPHEADER_DECODE_FAILED :    return  "CC_SIPHEADER_DECODE_FAILED" ;
        case    CC_NETWORK_FAILURE :    		return  "CC_NETWORK_FAILURE" ;
        case    CC_IN_BARRED_CANC :    			return  "CC_IN_BARRED_CANC" ;
        case    CC_OUT_BARRED_CANC :    		return  "CC_OUT_BARRED_CANC" ;
 
        default :                   return "RESERVED" ;
        break ;
    }
}
#endif
