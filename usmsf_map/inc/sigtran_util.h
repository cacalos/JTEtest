#ifndef	SIGTRAN_UTIL_H__
#define	SIGTRAN_UTIL_H__

#include <iXtypes.h>
//#include <ua_atif.h>

#define	TCAP_RECV	0
#define	TCAP_SENT	1

#define	TCAP_ADDR_LEN_PC_SSN	4


char *getOpName( char *op_name, int op_code);
char *getErrCodeNameCDMA( int code);
char *addr2str( unsigned char *addr, char *str);
int addr2pc( unsigned char *addr, int *pc, int *ssn);
#if 0
int minTraceTcap( char *fName, char *funName, int lNum, 
	stAddr *addr, AtifSleeMsgType *msg, int sent);
int sendTCUAbort( int cid, int myQid, int atifQid);
int makeAtifResponse( 
	AtifSleeMsgType *snd, 	/* OUT : snd msg */
	AtifSleeMsgType *rcv, 	/* IN : rcv msg */
	int myQid,				/* IN : my Q id */
	int paraLen,			/* IN : parameter length */
	unsigned char *para		/* IN : parameter */
	);
int sendTcapMsg( int qid, AtifSleeMsgType *msg, int dlg, int comp, 
	int origLen, unsigned char *orig, 
	int destLen, unsigned char *dest, int iid, int usrDid);
#endif
int pc2addr( int pc, int ssn, unsigned char *addr);

#if 0
int initAtifMsg( AtifSleeMsgType *snd, int myQid, int protocol, int opcode, int opclass, int cid);
#endif

/* New SIGTRAN APIs */
#ifdef	USIGTRAN

/*
#include <ulib/ulib.h>
#include <ulib/uprefs.h>
#include <ulib/utimer.h>
#include "usigtran/usccp_def.h"
#include "usigtran/ugua.h"
#include "usigtran/ugua_common.h"
#include "usigtran/utcap_def.h"
*/
//#include "usigtran/utcap.h"
#include "usrg/utcap.h"


	/**
   * if 'USIGTRAN_CONF_ENV' exists, the value of it
    * is used as the directory of confiuration files
	 * otherwise, use 'USIGTRAN_ROOT_ENV'/'USIGTRAN_DEFAULT_CONF_DIR'.
#define USIGTRAN_ROOT_ENV           "USIGTRAN_ROOT"
#define USIGTRAN_CONF_ENV           "USIGTRAN_CONF"
#define USIGTRAN_DEFAULT_CONF_DIR   "data"
	  */


char *sig_addr2str( USccpAddr  *addr, char *str);
UTcap *initSigtran( int argc, char *argv[], char *name);
int sig_getOpcode( UTcapOperation *opCode);
int sig_sendContinueInvoke( UTcap *tcapInfo, 
		int opcode, int dlgId, USccpAddr *orig, USccpAddr *dest,
		int timer, unsigned char *para, int paraLen, int invId, int provId);
int sig_sendBeginInvoke( UTcap *tcapInfo, 
		int opcode, int dlgId, USccpAddr *orig, USccpAddr *dest,
		int timer, unsigned char *para, int paraLen, int acn, char *sigTraceNum );
int sig_sendBeginNotComp( UTcap *tcapInfo, 
		int dlgId, USccpAddr *orig, USccpAddr *dest,
		int timer, int acn, char *sigTraceNum );
int sig_sendTCUAbort( UTcap *tcapInfo, 
					int dlgId, int provId, int mySSN);
int sig_makeGT( USccpAddr *addr, char *isdn, int translation, int ssn);
int sig_getNodeNumber( stNodeNumber *node, USccpAddr *addr);
int sig_minTraceTcap(char *fName, char *funName, int lNum, 
	stAddr *addr, UTcapPrimitive *prim, UTcapComponents *comp, int sent);
int sig_minTraceTcapComplex(char *fName, char *funName, int lNum, 
	stAddr *addr, int sent,
	int primType, int provId, int userId, 
	unsigned char *acn, int acnLen, int abortReason,
	USccpAddr *orig, USccpAddr *dest,
	int compType, int opcode, int invId, unsigned char *paraPtr, int paraLen);
int sig_sendEndResult( UTcap *tcapInfo, int acn, UTcapPrimitive *rxPrim, 
		UTcapComponents *rxComp, 
		unsigned char *para, int paraLen);
int sig_sendEndResultComplex( UTcap *tcapInfo, int acn,
		int provId, unsigned char invId,
		unsigned char opcode, 
		unsigned char *para, int paraLen);
int sig_sendEndErrorComplex( UTcap *tcapInfo, int acn, int provId, 
		unsigned char invId, unsigned char opcode, int errCode,
		unsigned char *para, int paraLen);
int sig_sendEndError( UTcap *tcapInfo, int acn, UTcapPrimitive *rxPrim, 
		UTcapComponents *rxComp, int errCode, 
		unsigned char *para, int paraLen);

int sig_checkACN(UTcapDialogPortion *pDiagPortion);
int sigCheckACN(UTcapDialogPortion *pDiagPortion);
int	sig_decodeError(int *errCode, UTcapComponents *comp);
int setDialogPortion(int acn, UTcapDialogPortion *dlg, int abortReason);
int sig_sendContinueResult( UTcap *tcapInfo,
		int opcode, int dlgId, USccpAddr *orig, USccpAddr *dest,
		int timer, unsigned char *para, int paraLen, int invoke_id, int prov_id);
int sig_printPrimitive(UTcapPrimitive *prim);
int sig_printComponent(UTcapComponents *comp);
int sig_sendResultComp( UTcap *tcapInfo, int acn, int provId, UTcapPrimitive *rxPrim, int msgType, int compType);

#endif	/* USIGTRAN */
#endif
