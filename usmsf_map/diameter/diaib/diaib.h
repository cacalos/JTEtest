#ifndef _DIAIB_MAIN_H
#define _DIAIB_MAIN_H

#include <uxcutor/uxc_xcutor.h>
#include <uxcutor/uxc_actor.h>
#include <uxcutor/uxc_worker.h>
#include <uxcutor/uxc_msg.h>
#include <uxcutor/uxc_dllmgr.h>
#include <uxcutor/uxc_ipcmsg.h>
#include <uxlib/ux_string.h>
#include <uxlib/ux_log.h>

#include <dia_avp_util.h>

#include <upa/upa_dia.h>
#include <upa/upa_diamsg.h>
#include <upa/upa_dbif.h>

#include <RPDU/RPDU.h>
#include <RPDU/okhTypes.h>

#include <iXCauseCode.h>
#include <smsf_msg.h>
#include <iXtypes.h>
#include <iXstat.h>

#include "trc_util.h"

#define DIAIB_RESULT_OK 				0
#define DIAIB_RESULT_NOTOK				-1
#define DIAIB_RESULT_ERROR				-2

#define UDIA_CMD_TFR					8388646
#define UDIA_CMD_SRR					8388647
#define UDIA_CMD_RDR					8388649
#define UDIA_CMD_DRR					8388644
#define UDIA_CMD_ACR					271
#define UDIA_CMD_OFR            		8388645

#define DIAIB_SESSION_ID_SEP			';'
#define DIAIB_PA_DBIF					"PA_DBIF"
#define DIAIB_PA_DIAMETER				"PA_DIAMETER"
#define DIAIB_PA_DIAMETER_CHNL			"ADIF_CHNL"
#define DIAIB_PA_DIA_THREAD_KEY		"Session-Id"
#define DIAIB_RESP_KEY_MAX_LEN			AVP_SESSION_ID_MAX_LEN
#define DIAIB_INVOKE_MSG        		"DIAIB_INVOKE"
#define DIAIB_RETURN_MSG        		"DIAIB_RETURN"

#define DIRECTION_SC_MS             1
#define DIRECTION_MS_SC             2

#define IS_NULL_STRING( s)  ((s)[0] == '\0')
#define DIAIB_DEBUG					1
#define ORIG_HOST_SIZE					64

#ifdef LINUX
#define atomic_inc(P) __sync_add_and_fetch((P), 1)
#elif HPUX64
#include <atomic.h>
#define atomic_inc(P) atomic_inc_32(P)
#endif

typedef struct common_conf_s common_conf_t;
struct common_conf_s {
	int 		host_id;
	char		orig_host[ORIG_HOST_SIZE];
	char		orig_realm[ORIG_HOST_SIZE];
	int 		ofr_timeout;
	/* Transaction timeout은 Eng에서 관리하여 제거 */
//	int			trans_timeout;
};

typedef struct diaib_s diaib_t;
struct diaib_s {
	uxc_plugin_t  			base;
	uxc_xcutor_t 			*xcutor; 		// uxcutor object
	upa_dia_t               *padia;			// diameter pa object
	upa_dbif_t              *padbif;		// dbif pa object
	char 					cfile[512]; 
	/* 소용량의 경우 dialog-id 를 위해 mutex 1개를 더 사용한다 */
	// ( 0: stat mutex / 1: dialog_id mutex / 2: trace mutex / 3: Nack Print / 4: proc trace)
	ux_mutex_t              mutex[4];       
	uint32_t				diag_id;		// Session-ID (low 32bit)
	uint32_t				start_time;		// Session-ID (high 32bit)
	common_conf_t			common_conf;	// diaib config object

	int                 	srcQid;
    int                 	dstQid;

	/* for stat */
	uint32_t				smscCnt;
    stSmscList            	smsc_list[MAX_SMSC_LIST];
    stDIAstat           	dia_stat[MAX_SMSC_LIST];
};

typedef struct diaib_ofr_respQ_s diaib_ofr_respQ_t;
struct diaib_ofr_respQ_s {
	char			resp_key[AVP_SESSION_ID_MAX_LEN];
	ux_tmevt_t		*tmevt;
	stAddr			orig;
	stAddr 			imsi;
	char			msgRef;
	stNodeNumber	orig_node;
	stNodeNumber	dest_node;
};

typedef struct diaib_tfr_respQ_s diaib_tfr_respQ_t;
struct diaib_tfr_respQ_s {
	ux_hnode_t      hnode;
	char			resp_key[AVP_SESSION_ID_MAX_LEN];
	ux_tmevt_t		*tmevt;
	char            session_id[512];
	char            orig_realm[24];
	char            dest_realm[24];
	char            orig_host[24];
	char            dest_host[24];
	int           	hop_id;
	int           	end_id;
	int           	peer_id;
	stAddr			imsi;
	unsigned char 	msgRef;
	char 			smsc_node[24];
};

diaib_t* diaib_instance( void);

uint32_t get_n_inc_diaib_diag_id();
uint32_t get_diaib_start_time();
int get_thread_id_by_key(char *str);
int diaib_init( char *cfile);
void diaib_final( uxc_plugin_t *plugin);
int diaib_reconf( uxc_plugin_t *plugin);
int diaib_heartbit( uxc_plugin_t *plugin, ux_tmtype_t tmevt);
int worker_reload( uxc_plugin_t *plugin, void* worker);
int worker_start( uxc_plugin_t *plugin);

uint32_t get_n_inc_diaib_diag_id();
uint32_t get_diaib_start_time();

upa_dia_t *diaib_get_padia(void);

ux_mutex_t* get_diaib_stat_mutex();
ux_mutex_t* get_diaib_trc_mutex();
ux_mutex_t* get_diaib_nack_mutex();
ux_mutex_t* get_diaib_proc_mutex();
ux_mutex_t* get_diaib_slist_mutex();

int get_diaib_src_qid();
int get_diaib_dst_qid();

udia_dict_t *diaib_get_dict(void);

/* function prototype for stat.c */
stDIAstat* get_diaib_dia_stat();
stSmscList* get_diaib_dia_list();


int conv_absent_user_to_cc(udia_avplist_t* avplist);
int conv_dlvy_fail_to_cc(udia_avplist_t* avplist);
int conv_exp_err_to_cc(udia_avplist_t* avplist);
int conv_dia_err_to_cc(udia_avp_t* rst_code);

#endif
