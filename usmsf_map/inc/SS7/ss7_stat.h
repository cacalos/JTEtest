
#ifndef _SS7_STAT_H_INCLUDED_
#define _SS7_STAT_H_INCLUDED_

#include <iXtypes.h>

#define MAX_SMSC_LIST              	1024
#define SMSC_ISDN_SIZE 				DEFAULT_ISDN_LEN+1

typedef struct _stSmscList {
    char            isdn[DEFAULT_ISDN_LEN];
} stSmscList;

typedef struct _stSMSCstat {
	char 	isdn[SMSC_ISDN_SIZE];
	int 	mof_send_succ;
	int 	mof_send_fail;
	int 	mof_resp_ack;
	int 	mof_resp_nack;
	int 	mof_timeout;
	int 	mtf_recv_succ;
	int 	mtf_recv_fail;
	int 	mtf_send_ack;
	int 	mtf_send_nack;
	int 	mtf_timeout;
} stSMSCstat;

#endif  /* _SS7_STAT_H_INCLUDED_ */

