
#include <stdio.h>
#include <errno.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#include <iXtypes.h>

#ifndef __IX_TRACE_DEFIENED
#define __IX_TRACE_DEFIENED

#define REG                   1
#define NOT_REG               0

#define MAX_TRACE_REG_CNT     10
#define MAX_TRACE_FILE_SIZE   128

#define GLOBAL_TRACE_OFF        0
#define GLOBAL_TRACE_ON         1

#define DEFAULT_GLOBAL_TRACE_TIME  360

typedef struct _stTraceShm{
	/* Process Trace , v260 */
	char        traceFlag;
    char        trcFile[MAX_TRACE_FILE_SIZE];
    time_t      expireTime;

	/* MIN Trace         */
    int         reg_count;
	struct {
		stAddr      addr;
		time_t		time;	/* bhtak 2004/7/26 add expire time */
		int 		level;	/* bhtak 2004/8/4 add trace level */
	} trace[MAX_TRACE_REG_CNT];

} stTraceShm;

#ifdef _CPP_SOURCE_ONLY_HEADER_
extern "C"
{
#endif

stTraceShm *GetTracep(void );
void OpenTraceShm(void);
int ChangeTraceShm(stTraceShm *pstTraceMsg);
int ResetTraceShm(void);
int GetTraceMin(stTraceShm *msg);
void InitTraceShm(void);
int ClearTrace_IndexShm(int index, char *mdn);
int IsThisMinTrace(stAddr *addr);
int setTraceMode( stAddr *orig, stAddr *dest, stAddr *imsi);
int IsGlobalTrace(void);
void setGlobalTrace(void);
void resetGlobalTrace(void);
int ProcessStoreAddr(char *addr, int duration, int level);
int IsExistAddr(char *addr);
int IsExistIndex(int index);
int GetAllTrace(stTraceShm *msg);
int DeleteAllTrace(void);
int DeleteTraceIndex(int index);
int DelTrace(char *msisdn);
int AddTrace(char *msisdn, int duration, int level);

int GetTraceMinInfo(char *min, time_t *until_time, int *level);


#ifdef _CPP_SOURCE_ONLY_HEADER_
}
#endif
extern int gTraceLevel;
extern stAddr gTraceAddr;
//#define IS_IN_TRACE(l)	(gTraceLevel >= (l))
#define IS_IN_TRACE(l)	(l == 1)
#endif /* __IX_TRACE_DEFIENED*/
