
#ifndef _SS7_RESQ_H_INCLUDED_
#define _SS7_RESQ_H_INCLUDED_

#include <iXtypes.h>
#include <iXMoQ.h>

#ifdef USIGTRAN
//#include <usigtran/utcap.h>
#include <usrg/utcap.h>
#endif

/* Msg Queue 상태에 관련된 Header */
#define MQ_DONE                         0
#define MQ_SENT                         1
#define MQ_BEGINNULL                    4

#define MAX_DIAG_ID_MT                 100000
#define MAX_DIAG_ID_MO                 100000


typedef struct _stMtResponseQ {
    int           diag_id;
	int 		  user_id;
	int 		  prov_id;
	int 		  inv_id;
	USccpAddr 	  srcAddr;
	USccpAddr 	  dstAddr;

    int           status;
    time_t        sent_tm;
	char 		  acn;
	char 		  isMMS;
	char          nodeAddr[20];
    stNodeNumber  node;
	int		  	  nodeIdx;	/* HLR or MSC isdn number index */
	char		  trace;	/* 0:No Trace, 1: Trace */
	char		  level;	/* trace level */
	stAddr		  imsi;	 	/* imsi */
	unsigned char msgRef;
} stMtResponseQ;

typedef struct _stMoResponseQ {
	int           diag_id;
    int           status;
    time_t        sent_tm;
    int           nodeIdx;  /* HLR or MSC isdn number index */
    char          trace;    /* 0:No Trace, 1: Trace */
    char          level;    /* trace level */
    stAddr        addr;
    stMoMsg       moMsg;
} stMoResponseQ;

stAddr *getTraceNum( int);

#define MAX_HANDSHAKE_LIST              1024
typedef struct _stHandShakeList {
	char            isdn[DEFAULT_ISDN_LEN];
	unsigned char   acn_version;
} stHandShakeInfo;

#define IS_HANDSHAKELIST_FULL(X) !((X) < MAX_HANDSHAKE_LIST)

typedef struct _stHandShakeListShm {
	int                end;
	int                on_off;
	stHandShakeInfo    table[MAX_HANDSHAKE_LIST];
} stHandShakeListShm;

#endif  /* _SS7_RESQ_H_INCLUDED_ */

