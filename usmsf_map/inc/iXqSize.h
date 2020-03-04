
#ifndef _QSIZE_H_INCLUDE_
#define _QSIZE_H_INCLUDE_

#ifdef	SMSC_BUILD_DEV
#define MAX_Q_SIZE_SBMT                5
#define MAX_Q_SIZE_CNX                 5
#define MAX_Q_SIZE_SRI                 5
#define MAX_Q_SIZE_Sri                 5
#define MAX_Q_SIZE_Pre                 5
#define MAX_Q_SIZE_REQ                 5
#define MAX_Q_SIZE_Req                 5
#define MAX_Q_SIZE_MTF                 5
#define MAX_Q_SIZE_Mtf                 5
#define MAX_Q_SIZE_DPP                 5
#define MAX_Q_SIZE_Dpp                 5
#define MAX_Q_SIZE_IN                  5
#define MAX_Q_SIZE_NOTI                5
#define MAX_Q_SIZE_MO                  5
#define MAX_Q_SIZE_CMD                 5
#define MAX_Q_SIZE_RCVACK              5
#define MAX_Q_SIZE_SNDACK              5
#define MAX_Q_SIZE_BILL                5
#define MAX_Q_SIZE_NPS                 5
#define MAX_Q_SIZE_NCNX                5
#define MAX_Q_SIZE_INBH                5
#define MAX_Q_SIZE_SMGS                5
#define MAX_Q_SIZE_Smgs                5
#define MAX_Q_SIZE_WINGS               5
#define MAX_Q_SIZE_SYNCQ               5
#define MAX_Q_SIZE_SCP                 5
#define MAX_Q_SIZE_SMSF                5 //v430
/*** added for linux ***/
#define MAX_Q_SIZE_MYSQLIB			   5
#define MAX_Q_SIZE_DIA				   5
#else
#define MAX_Q_SIZE_SBMT                20000
#define MAX_Q_SIZE_CNX                 1000
#define MAX_Q_SIZE_SRI                 50000 //V450 1000->2000
#define MAX_Q_SIZE_Sri                 20000
#define MAX_Q_SIZE_Pre                 20000 //v520
#define MAX_Q_SIZE_REQ                 5000
#define MAX_Q_SIZE_Req                 20000
#define MAX_Q_SIZE_MTF                 50000 //V450 1000->2000
#define MAX_Q_SIZE_Mtf                 20000
#define MAX_Q_SIZE_DPP                 5000
#define MAX_Q_SIZE_Dpp                 20000
#define MAX_Q_SIZE_IN                  20000
#define MAX_Q_SIZE_NOTI                20000
#define MAX_Q_SIZE_MO                  20000
#define MAX_Q_SIZE_CMD                 20000
#define MAX_Q_SIZE_RCVACK              20000
#define MAX_Q_SIZE_SNDACK              20000
#define MAX_Q_SIZE_BILL               20000
//#define MAX_Q_SIZE_NPS                 1000
#define MAX_Q_SIZE_NPS                 20000
#define MAX_Q_SIZE_NCNX                500
#define MAX_Q_SIZE_INBH                9000
#define MAX_Q_SIZE_SMGS                10000
#define MAX_Q_SIZE_Smgs                10000
#define MAX_Q_SIZE_WINGS               9000
#define MAX_Q_SIZE_SYNCQ               9000
#define MAX_Q_SIZE_SCP                 5000 
#define MAX_Q_SIZE_STAT                 5000 
#define MAX_Q_SIZE_SMSF                20000  //v430
/*** added for linux ***/
#define MAX_Q_SIZE_MYSQLIB			   10000*3
#define MAX_Q_SIZE_DIA                 5000*3
#endif

#endif /* _QSIZE_H_INCLUDE_ */

