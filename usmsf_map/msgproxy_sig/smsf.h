#ifndef __SMSF_H__
#define __SNSF_H__

#include <uxcutor/uxc_xcutor.h>
#include <uxcutor/uxc_actor.h>
#include <uxcutor/uxc_msg.h>
#include <uxcutor/uxc_dllmgr.h>
#include <uxcutor/uxc_ipcmsg.h>
#include <uxcutor/uxc_dbmgr.h>

#include <upa/upa_dbif.h>
#include <upa/upa_tcp.h>

#include <uxlib/ux_string.h>
#include <uxlib/ux_log.h>

#include <iXUtil.h>
#include <smsf_msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>
#include <iXtypes.h>

#ifdef LINUX
#define atomic_inc(P) __sync_add_and_fetch((P), 1)
#elif HPUX64
#include <atomic.h>
#define atomic_inc(P) atomic_inc_32(P)
#endif

/* message type */
#define SIG_IN_TYPE 1
#define SIG_OUT_TYPE 2
#define SIG_OUT_ERR_TYPE 3

#define MTYPE_SIGIN_MESSAGE_TYPE 100
#define MTYPE_SIGOUT_MESSAGE_TYPE 101
#define MTYPE_DIAMETER_MESSAGE_TYPE 102

#define SMSF_QID           0
#define SIGIB_IN_QID       1
#define SIGIB_OUT_QID      2
#define DIAIB_QID      	   3
#define MAX_ENGINE_QID     4

#define COMMON_LEN	128
#define RP_DATA_LEN	250

#define SIGTRAN_MODE 		0
#define DIAMETER_MODE 		1

typedef struct mproxy_stat_s mproxy_stat_t;
struct mproxy_stat_s {
	int 	mo_cnt;
	int 	mo_resp_cnt;
	int 	mt_cnt;
	int 	mt_resp_cnt;
	int 	mt_err_cnt;
	int 	other_cnt;
};

typedef struct smsf_s smsf_t;
struct smsf_s {
	uxc_plugin_t        base[1];
	uxc_xcutor_t        *xcutor;        // uxcutor object
	upa_dbif_t          *padbif;       // dbif pa object
	upa_tcp_t			*patcp;
	char                cfile[512];
	int                 ifQid[MAX_ENGINE_QID];
	ux_mutex_t          mutex[2]; 
	int 				mode;
	mproxy_stat_t 		stat;
};

typedef struct CommonInfo_s CommonInfo_t;
struct CommonInfo_s {
	int PlmnIdLen;
	int PlmnId;
	int SmsfInstanceIdLen;
	char SmsfInstanceId[256];
	int SmsfMapAddressLen;
	char SmsfMapAddress[256];
	int SmsfDiameterAddressLen;
	char SmsfDiameterAddress[256];
	int SmsfPointCodeLen;
	int SmsfPointCode;
	int SmsfSsnLen;
	int SmsfSsn;

};

typedef struct InterFInfo_s InterFinfo_t;
struct InterFInfo_s {
	int 	NameLen;
	char 	Name[256]; 
	int		IsdnLen; 
	char 	Isdn[256];
	int		PcLen; 
	int		Pc;         
	int		SsnLen;      
	int		Ssn;        
	int		TypeLen;     
	int		Type;        
	int		FlowCtrlLen; 
	int		FlowCtrl; 
	int 	DestHostLen;
	char 	DestHost[256];
	int     DestRealmLen;
	char    DestRealm[256];
	int		DescLen;     
	char	Desc[256];        

};


typedef struct smsf_send_s smsf_send_t;
struct smsf_send_s {
	int	total_len;

	int type; 

	int causeCode;

	int supi_len;
	char supi[128];
	
	int gpsiLen;
	char gpsi[128];

	int mmsLen;
	int mmsflag;
									           
	int contentDataLen;
	char contentData[250];
};

typedef struct smsf_sendmt_s smsf_sendmt_t;
struct smsf_sendmt_s {
	int	total_len;

	int type; //0:mo , 1:mt

	int causeCode;

	int supi_len;
	char supi[128];

	int mmsLen;
	int mmsflag;
/*
	//for FAILURE NOTI
	int MsgTypeLen;
	char MsgType[32];

	int ResultCodeLen;
	char ResultCode[64];
*/
	//for resp
	int				diag_id_len;
	char  			diag_id[32];
	int 			acn;
	int 			prov_id;
	int 			inv_id;
	int             hop_id;
    int             end_id;
    int             peer_id;
	int 			orig_realm_len;
    char            orig_realm[24];
	int             orig_host_len;
    char            orig_host[24];
	int             smsc_node_len;
    char            smsc_node[24];
	int				session_id_len;
	char 			session_id[512];

	int contentDataLen;
	char contentData[250];

};

typedef struct smsf_recv_s smsf_recv_t;
struct smsf_recv_s {
	int	total_len;

	char type; 

	int causecode; // add on

	int supi_len;
	char supi[128];

	int amfIdLen;
	char amfId[128];

	int gpsiLen;
	char gpsi[128];

	char mmsLen;
	char mmsflag;

	//for FAILURE NOTI
	int MsgTypeLen;
	char MsgType[32];
	int ResultCodeLen;
	char ResultCode[64];

	//for resp
	int				diag_id_len;
	char  			diag_id[32];
	int 			acn;
	int 			prov_id;
	int 			inv_id;
	int             hop_id;
    int             end_id;
    int             peer_id;
	int 			orig_realm_len;
    char            orig_realm[24];
	int             orig_host_len;
    char            orig_host[24];
	int             smsc_node_len;
    char            smsc_node[24];
	int				session_id_len;
	char 			session_id[512];

									           
	int contentDataLen;
	char contentData[250];

	InterFinfo_t InterFinfo;
	CommonInfo_t Commoninfo;
};

typedef struct smsf_header_s smsf_header_t;
struct smsf_header_s {
	unsigned int body_len;
};

typedef struct smsf_tcp_msg_s smsf_tcp_msg_t;
struct smsf_tcp_msg_s {
    smsf_header_t   		header;
    char 				data[4096];
};


int handle_interface_message(uxc_worker_t *worker, uxc_msg_t *msg);

smsf_t* smsf_instance( void);
uxc_plugin_t* smsfif_create(void *xcutor, const char *cfile);
int smsfif_init(char *cfile);
void _smsfif_final(uxc_plugin_t *plugin);
int _smsfif_reconf(uxc_plugin_t *plugin);
int _smsfif_heartbit(uxc_plugin_t *plugin, ux_tmtype_t tmevt);
ux_mutex_t* get_proxy_stat_mutex();

int worker_reload( uxc_plugin_t *plugin, void* worker);
int worker_start( uxc_plugin_t *plugin);

int handle_recv_interface_msg(uxc_action_t *action, uxc_worker_t *worker, uxc_msg_t *uxcmsg);
int handle_smsf_msg(uxc_action_t *action, uxc_worker_t *worker, uxc_msg_t *uxcmsg, upa_peerkey_t *peerkey);

int send_to_sigtran(uxc_worker_t *worker, smsf_msg_t *msg);
int convert_interface_msg(smsf_msg_t *msg, smsf_recv_t *rcv_msg);
int recv_msg_decodef(smsf_tcp_msg_t *tcp_msg, smsf_recv_t *rcv_msg);
void send_msg_print(smsf_msg_t * msg);
int load_common_config(const char *cfile, int *mode);
int get_config_proxy_mode();

void init_msgproxy_stat(smsf_t *smsf);
void inc_msgpoxy_stat(char type);
void print_msgproxy_stat(smsf_t *smsf);
mproxy_stat_t* get_mproxy_stat();

#endif
