#include <stdio.h>

#include <iXGCA.h>
#include <smsf_msg.h>

#include "diaib.h"
#include "stat.h"
#include "dia_util.h"
#include "diaib_avp_util.h"
#include "diaib_config.h"

static int get_padia_thread_id( uxc_paif_t *paif, uxc_msg_t *msg);
static int get_padbif_thread_id( uxc_paif_t *paif, uxc_msg_t *msg);
static long get_str_hashkey(char *str);

diaib_t* diaib_instance( void)
{
	static diaib_t    singleton;

	return &singleton;
}

/* Get Mutex */
ux_mutex_t* get_diaib_stat_mutex()
{
	return &diaib_instance()->mutex[0];
}

ux_mutex_t* get_diaib_slist_mutex()
{
	return &diaib_instance()->mutex[1];
}

/* Get Mutex for trace */
ux_mutex_t* get_diaib_trc_mutex()
{
	return &diaib_instance()->mutex[2];
}

/* Get Mutex for NackPrint */
ux_mutex_t* get_diaib_nack_mutex()
{
	return &diaib_instance()->mutex[3];
}

int get_diaib_src_qid()
{
    return diaib_instance()->srcQid;
}

int get_diaib_dst_qid()
{
    return diaib_instance()->dstQid;
}

int* get_diaib_smsc_cnt()
{
    return &diaib_instance()->smscCnt;
}

static int get_padia_thread_id( uxc_paif_t *paif, uxc_msg_t *msg)
{
	/* Session-Id 값에 대한 최대 값이 규격상 정의되어 있지 않아 512로 지정*/
	int				rv;
	int				key;
	int				max_thread;
	uint32_t        cmd_code;
	char			session_id[AVP_SESSION_ID_MAX_LEN];
	char            *user_name;
	udia_msg_t*		dia_msg = ((upa_diamsg_t *) msg->data)->stackmsg;
	udia_avplist_t*	avplist;

	cmd_code = udia_msg_get_code(dia_msg);

	/* Get Session-Id AVP value */
	avplist = udia_msg_get_root(dia_msg);

	if(cmd_code == UDIA_CMD_TFR)
	{
		user_name = udia_avplist_get_str_n(avplist, "User-Name", &rv);
		if(user_name == NULL || rv != AVP_UTIL_RESULT_OK) {
			ux_log( UXL_CRT, "Get AVP(User-Name) FAIL.(err:%d)", rv);
			return 0;
		}

		ux_log(UXL_DEBUG, "DIA PA Thread Key [%s]", user_name);

		return get_thread_id_by_key(user_name);
	}
	else 
	{
		rv = get_avp_str_item(avplist, AVP_NAME_SESSION_ID, session_id, AVP_SESSION_ID_MAX_LEN );
		
		if( session_id == NULL || rv != AVP_UTIL_RESULT_OK ){
			ux_log( UXL_CRT, "Get AVP(Session-Id) FAIL.(err:%d)", rv);
			return 0;
		}


		key = get_thread_idx_from_session_id( session_id );
		max_thread = uxc_xcutor_get_worker_count(uxc_xcutor_instance());

		return (key % max_thread);
	}
}

static int get_padbif_thread_id( uxc_paif_t *paif, uxc_msg_t *msg)
{
	char					key[DIAIB_RESP_KEY_MAX_LEN];
	uxc_ipcmsg_t            *ipc_msg = (uxc_ipcmsg_t *)msg->data;
	smsf_msg_t              *smsf_msg = (smsf_msg_t *)(ipc_msg->data);

	/*
	int 					max_thread;
	max_thread = uxc_xcutor_get_worker_count(uxc_xcutor_instance());
	*/

	sprintf( key, "%s", smsf_msg->supi);

	ux_log(UXL_DEBUG, "DBIF PA Thread Key [%s]", key);

	return get_thread_id_by_key(key);
}

uint32_t get_n_inc_diaib_diag_id()
{
	return atomic_inc( &diaib_instance()->diag_id );
}

uint32_t get_diaib_start_time()
{
	return diaib_instance()->start_time;
}

int get_thread_id_by_key(char *str)
{
	int             magic_key;
	int             max_thread;

	magic_key = get_str_hashkey(str);
	max_thread = uxc_xcutor_get_worker_count(uxc_xcutor_instance());
	ux_log( UXL_DEBUG, "Magic_key(%d). Selected Thread num[Thread %d]"
			, magic_key,  (magic_key % max_thread) +1 );

	return (magic_key % max_thread);
}

static long get_str_hashkey(char *str)
{
	ssize_t         key = 0;
	long            hash_key;

	while(*str) {
		key = (31*key) + *str++;
	}
	hash_key = key & 0x7FFFFFFF;

	return hash_key;
}

// 프로세스 초기화 작업
int diaib_init( char *cfile)
{
	diaib_t 		*diaib = diaib_instance();

    ux_log(UXL_INFO, "init ......");

	diaib->xcutor = uxc_xcutor_instance();

	/***** Reg diaib Protocol Adapter *****/
	diaib->padia  = (upa_dia_t *)uxc_xcutor_get_paif( diaib->xcutor, DIAIB_PA_DIAMETER);	
	diaib->padbif = (upa_dbif_t *)uxc_xcutor_get_paif( diaib->xcutor, DIAIB_PA_DBIF);	
	if( diaib->padia == NULL || diaib->padbif == NULL ){
		ux_log(UXL_CRT, "Cannot find Diameter protocol adapter.");
		return eUXC_INIT_FAIL;
	}

	/***** Reg select thread id callback func *****/
	uxc_xcutor_set_get_thrid_cb( diaib->xcutor, DIAIB_PA_DIAMETER, get_padia_thread_id);
	uxc_xcutor_set_get_thrid_cb( diaib->xcutor, DIAIB_PA_DBIF, get_padbif_thread_id);

	secure_strcpy(diaib->cfile, sizeof(diaib->cfile), cfile);

	/* GCA attach */
	if( OpenGCA() == IXERR ){
		ux_log(UXL_CRT, "Can't open GCA !!!");
		return eUXC_INIT_FAIL;
	}

	ux_mutex_init(&diaib->mutex[0], NULL);  // for statistics
	ux_mutex_init(&diaib->mutex[1], NULL);  // for list
	ux_mutex_init(&diaib->mutex[2], NULL);  // for MinTrace
	ux_mutex_init(&diaib->mutex[3], NULL);  // for NackPrint
	ux_mutex_init(&diaib->mutex[4], NULL);  // for proc trace

	diaib->srcQid = msgq_getProcId("DIAIB");
	diaib->dstQid = msgq_getProcId("MSGPROXY");

	OpenProxyQ();
	OpenStatQ();
	/* Init start time */
	diaib->start_time = time(NULL);

	init_diaib_stat(diaib);

	return eUXC_SUCCESS;
}

upa_dbif_t *diaib_get_padbif(void)
{
	return diaib_instance()->padbif;
}

upa_dia_t *diaib_get_padia(void)
{
	return diaib_instance()->padia;
}

udia_dict_t *diaib_get_dict(void)
{
	return upa_dia_get_dict(diaib_get_padia());
}

uxc_plugin_t* diaib_create( void *xcutor, const char *cfile)
{
	int         rv;
	diaib_t   *diaib = diaib_instance();

	rv = uxc_plugin_init( &diaib->base, xcutor, cfile);
	if (rv < eUXC_SUCCESS) {
		return NULL;
	}

	diaib->xcutor = (uxc_xcutor_t *) xcutor;

	rv = diaib_init( (char *) cfile);
	if( rv != eUXC_SUCCESS ){
		return NULL;
	}

	diaib->base.destroy = diaib_final;
	diaib->base.reconf = diaib_reconf;
	diaib->base.heartbeat = diaib_heartbit;
	diaib->base.reload = worker_reload;
	diaib->base.start = worker_start;

	if(load_common_config(cfile, &diaib->common_conf) != eUXC_SUCCESS)
		return (uxc_plugin_t*) NULL;

	return (uxc_plugin_t *) diaib;

}

void diaib_final( uxc_plugin_t *plugin)
{
    // TODO
	/* response Q Clear? */
}

int diaib_reconf( uxc_plugin_t *plugin)
{
	/*  */
    //ux_log(UXL_MAJ, "Reconfigure plugin......");
	return 0;
}

// 1초 마다 한번식 호출 되는 녀석
int diaib_heartbit( uxc_plugin_t *plugin, ux_tmtype_t tmevt)
{
	/* Print Call count per sec & Send stat info to ixstat */
	update_diaib_stat(diaib_instance());

	return 0;
}

// worker reload 시 callback function
int worker_reload( uxc_plugin_t *plugin, void* worker)
{
    ux_log(UXL_DEBUG, "Reload worker..");
	return 0;
}

// worker start 시 callback function
int worker_start( uxc_plugin_t *plugin)
{
	ux_log(UXL_DEBUG, "Start worker..");

	return 0;
}

/* Get function for stat */
stDIAstat* get_diaib_dia_stat()
{
	return diaib_instance()->dia_stat;
}

stSmscList* get_diaib_dia_list()
{
	return &diaib_instance()->smsc_list;
}
