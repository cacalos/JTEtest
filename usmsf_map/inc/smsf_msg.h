#ifndef _FEP_MSG_H
#define _FEP_MSG_H

#include <iXtypes.h>

#define MO_MSG 		1
#define MO_RESP 	2
#define MT_MSG		3
#define MT_RESP		4
#define ERR_TYPE    5

#define MMS_FALSE	0
#define MMS_TRUE	1

#define ROUTE_PC                 0
#define ROUTE_SYSTEM_GT          1

typedef struct smsf_msg_s smsf_msg_t;
struct smsf_msg_s {
	char 			msg_type;
	int 			causeCode;
	char 			supi[DEFAULT_ADDR_LEN];
	/* Interworking info for SMSC using SIGTRAN */
	char 			gpsi[DEFAULT_ADDR_LEN];				/* OA in MOF */
	char 			isMMS;								/* mmsFlag in MTF */
	char 			my_isdn[DEFAULT_ISDN_LEN+1];	  	/* SMSF Address(ISDN) for SIGTRAN */
	int 			my_pc;								/* SMSF Address(Ponit Code) for SIGTRAN */
	unsigned char 	my_ssn;								/* SMSF Address(SSN) for SIGTRAN */
	char 			smsc_isdn[DEFAULT_ISDN_LEN+1];		/* SMSC address(ISDN) for SIGTRAN */
	int 			smsc_pc;							/* SMSC Address(Ponit Code) for SIGTRAN */
	unsigned char  	smsc_ssn;							/* SMSC Address(SSN) for SIGTRAN */
	char 			routing_type;						/* PC/SYSTEM_GT/MSISDN_GT for SIGTRAN */
	/* Interworking info for SMSC using DIAMETER */
	char 			my_realm[DEFAULT_DIA_HOST+1];		/* Diameter SMSC Address for DIAMETER */
	char 			dest_realm[DEFAULT_DIA_REALM+1];	/* Diameter SMSC Address for DIAMETER */
	char 			dest_host[DEFAULT_DIA_HOST+1];		/* Diameter SMSC Address for DIAMETER */
	/* common */	
	int 			ctrlFlag;							/* flow Control */
	int 			data_len;
	char 			data[250];

	/*Failure Noti */
//	char 			MsgType[32];
//	char			ResultCode[64];

	/* for resp */
	char  			diag_id[32];
	int 			acn;
	int 			prov_id;
	int 			inv_id;
	int             hop_id;
    int             end_id;
    int             peer_id;
    char            orig_realm[24];
    char            orig_host[24];
    char            smsc_node[24];
	char 			session_id[512];
};

int InsProxyQMsg(char *pstMsg, int mType);

#endif
