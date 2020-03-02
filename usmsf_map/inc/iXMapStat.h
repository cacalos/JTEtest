
#ifndef _IX_MAP_STAT_INCLUDED
#define _IX_MAP_STAT_INCLUDED

#include <stdio.h>
#include <errno.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/time.h>

#include <iXBEP.h>
#include <iXESME.h>
#include <iXDiameterNode.h>

#include <iXEsmeStat.h>

#define MAX_NUM_OF_DEST	1024

#define IS_MAP_STAT_EMPTY(X) ((X) <= 0)

#define HOURLY      'H'
#define DAILY       'D'
#define MONTHLY     'M'
#define MINUTELY    'U'

typedef struct _stESMEidTab {
    int     esmes;
    char    esmeId[ESME_ESMEID_ARR][ESME_ESMEID_SIZE];
} stESMEidTab;

typedef struct _stDiaNodeTab {
	int     node_cnt;
	int     type[DIA_ISDN_ARR];
	char    isdn[DIA_ISDN_ARR][DIA_ISDN_SIZE];
	int     flowCtrl[DIA_ISDN_ARR];
} stDiaNodeTab;

typedef struct _stBepTab {
	int		beps;
	char 	bep_id[BEP_BEPID_ARR][BEP_IPADDR_SIZE];
} stBepTab;

typedef    struct _stSMPPstat {
    char   esmeId[ESME_ESMEID_SIZE];
    char   protocol_type;
    int    sub_recv_succ;
    int    sub_recv_fail;
    int    sub_recv_ack;
    int    sub_recv_nack;
    int    sub_recv_err;
    int    sub_recv_time;
    int    del_send_succ;
    int    del_send_fail;
    int    del_send_ack;
    int    del_send_nack;
    int    del_send_time;
} stSMPPstat;

typedef struct _stDiaNodestat {
	char   isdn[DIA_ISDN_SIZE];
	char	node_type;
	// todo : need refectoring
	int    diain_recv_succ;//센터->msc
	int    diain_recv_fail;//센터->msc
	int    diaout_send_succ;//센터->msc
	int    diaout_send_fail;
	int    diaout_send_ack;
	int    diaout_send_nack;
	int    diaout_send_time;
	int    diaout_flow_ctrl;
	int    tfr_send_succ;//센터->msc
	int    tfr_send_fail;
	int    tfr_send_ack;
	int    tfr_send_nack;
	int    tfr_send_time;
	int    tfr_flow_ctrl;
	int    ofr_send_succ;//센터->msc
	int    ofr_send_fail;
	int    ofr_send_ack;
	int    ofr_send_nack;
	int    ofr_send_time;
	int    ofr_flow_ctrl;
	int    ofr_recv_succ;//MME->센터
	int    ofr_recv_fail;
	int    ofr_recv_ack;
	int    ofr_recv_nack;
	int    ofr_recv_time;
	int    srr_send_succ;//센터->hlr
	int    srr_send_fail;
	int    srr_send_ack;
	int    srr_send_nack;
	int    srr_send_time;
	int    srr_flow_ctrl;
	int    rdr_send_succ;//센터->hlr
	int    rdr_send_fail;
	int    rdr_send_ack;
	int    rdr_send_nack;
	int    rdr_send_time;
	int    alr_recv_succ; //hlr -> smsc
	int    alr_recv_fail;
	int    alr_recv_ack;
	int    alr_recv_nack;
	int    alr_recv_time;
	int	   dtr_recv_succ;
	int	   dtr_recv_fail;
	int    dtr_recv_ack;
	int    dtr_recv_nack;
	int    dtr_recv_time;
	int    drr_send_succ;
	int    drr_send_fail;
	int    drr_send_ack;
	int    drr_send_nack;
	int    drr_send_time;
	int    acr_send_succ;
	int    acr_send_fail;
	int    acr_send_ack;
	int    acr_send_nack;
	int    acr_send_time;
} stDiaNodestat; 

typedef struct _stBEPstat {
    char   bep_id[BEP_HOSTNAME_LEN];
    char   protocol_type;
	int	   recv_inv;
	int    snd_resp;
	int	   snd_inv;
	int	   recv_resp;
} stBEPstat;

/* End of MAP STAT */

typedef struct _stMapStat{
	stESMEidTab	      esmeList;
	stDiaNodeTab   	  diaList;
	stBepTab		  bepList;
	stSMPPstat        esmeSmppStat[ESME_ESMEID_ARR];
	stDiaNodestat  	  diaStat[DIA_ISDN_ARR];
	stBEPstat		  bepStat[BEP_BEPID_ARR];
	/* End of MAP STAT */
} stMapStat;

/* 주소별 통계에서 HLR, MSC node 주소에 대한 index 값을 유지하기 위해 
 * hash 구조를 정의함 */

typedef struct {
	short keySize;
	short maxElm;
	char *key;	/* pointer to memory which stores key value array */
	char *used;	/* slot status, used or not-used */
} HashTable;


/* declare local function */
stMapStat *GetMapStatp(void);
void OpenMapStat(void);
int InitMapStat(void);
void InitESMEList(void);
void GetESMEList(stESMEidTab *esmeTab);
int GetEsmeIndex(char *esmeId);
void InsEsmeList(stESMEidTab *info);
void GetDiaNodeList(stDiaNodeTab *diaTab);
int EsmeSMPPstatAdd(char *esmeId, char protocol, stSMPPstat *smppInfo);
int openSS7stat(void);
int setSS7StatDestAddr( int idx, char *isdn);
int GetCurrAllEsmeSmppQ(stSMPPstat *smpp);
int GetCurrEsmeSmppQ(char *esmeId, stSMPPstat *smpp);
int GetCurrAllEsmeQ(stEsmeStat *esmeQ);
int GetCurrEsmeQ(char *esmeId, stEsmeStat *esmeQ);
int initHash( HashTable *hash, int maxElm, int elmSize);
int buildHash( HashTable *hash, int nElm, int elmSize, char *addr);
int insertHash( HashTable *hash, char *key);
int getHash( HashTable *hash, char *key);

void InsDiaNodeList(stDiaNodeTab *info);
int GetBepIndex(char *id);
void GetBepList(stBepTab *bepTab);
void InsBepList(stBEP *info);
int fepStatAdd(char *node, stBEPstat *info);
int diaStatAdd(char *isdn, stDiaNodestat *info);
/* End of Added MAP STAT */

#endif    /* _IX_MAP_STAT_INCLUDED */
