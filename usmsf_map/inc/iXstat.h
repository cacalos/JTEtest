#include <iXtypes.h>

#ifndef IX_STAT_INCLUDED__
#define IX_STAT_INCLUDED__

#define MAX_SMSC_LIST               1024
#define SMSC_ISDN_SIZE              DEFAULT_ISDN_LEN+1

#define STAT_MAX_RETRY          	3

#define MSGQ_MTYPE_STAT 	    	1

#define MAP_STAT_DIA_STAT    		1   // SMSC MAP STAT
#define MAP_STAT_SMSC_STAT   		2   // SMSC DIA STAT

typedef struct _stSmscList {
    char    isdn[DEFAULT_ISDN_LEN];
} stSmscList;

typedef struct _stSMSCstat {
    char    isdn[SMSC_ISDN_SIZE];
    int     mof_send_succ;
    int     mof_send_fail;
    int     mof_resp_ack;
    int     mof_resp_nack;
    int     mof_timeout;
    int     mtf_recv_succ;
    int     mtf_recv_fail;
    int     mtf_send_ack;
    int     mtf_send_nack;
    int     mtf_timeout;
} stSMSCstat;

typedef struct _stDIAstat {
    char    isdn[SMSC_ISDN_SIZE];
    int     ofr_send_succ;
    int     ofr_send_fail;
    int     ofr_resp_ack;
    int     ofr_resp_nack;
    int     ofr_timeout;
    int     tfr_recv_succ;
    int     tfr_recv_fail;
    int     tfr_send_ack;
    int     tfr_send_nack;
    int     tfr_timeout;
} stDIAstat;

typedef struct _stStatMsg {
	long			mtype;
	unsigned char 	protocol;
	union {
		stSMSCstat 		smscStat;
		stDIAstat 		diaStat;
	} u;
} stStatMsg;

void OpenStatQ();
int InsStatQMsg(char *pstMsg);
int GetStatMsg(stStatMsg *msg);

#endif    /* _IX_STAT_INCLUDED    */
