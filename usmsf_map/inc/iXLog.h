
#ifndef _IX_LOG_INCLUDED
#define _IX_LOG_INCLUDED

#include <ASN/asn_smsc.h>
#include <iXtypes.h>

#define DATE_LEN        9
#define MAX_BUF         1024
#define MAX_TIME_LEN    9

#ifdef __GCC__
#define FUNCTION_MACRO  (__FUNCTION__)
#else
#define FUNCTION_MACRO  ("")
#endif

#define ALARM_CRITICAL                   1
#define ALARM_MAJOR                      2
#define ALARM_MINOR                      3
#define ALARM_INFORM                     4
#define ALARM_CLEARED                    5

#define ALARM_ON                         0
#define ALARM_OFF                        1

#define LPOS               __FILE__,FUNCTION_MACRO,__LINE__
#define MPOS               LPOS,_MODULE_NAME
#define LIB_LPOS           LPOS,gLogModulName

#define CONDITION       0
#define UNCONDITION     1

#define GLOBAL_TRACE_FILE     "/.globalTrace"

extern char gLogModulName[MAX_PATH_NAME];

typedef char (*FuncPtr)();

/* declare local function */
void LogDisplayOn();
void LogDisplayOff();
int CloseLogFile();
int MinTrace(char *, char *, int, stAddr *, char *, ...);
int MinTraceHex(char *fName, char *funName, int lNum, stAddr *addr, char *cmt,
		unsigned char *s, int len);
int MinTraceMap(char *fName, char *funName, int lNum, stAddr *addr, 
		unsigned char *s, int len, 
		struct ossGlobal *world, int pdu, void *msg);
time_t LPrint(int , char *, char *, int, char *, char *, ...);
time_t ELPrint(int, int, char *, char *, ...);
void NackPrint(char *, char *, ...);
int GetProcPtr(char *, FuncPtr *);
char checkAlarmInfo(int);

#define	TCAP_SEND	1
#define	TCAP_RECV	0

#endif /* _IX_LOG_INCLUDED */

