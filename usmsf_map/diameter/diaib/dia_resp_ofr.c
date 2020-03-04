//#include "diaib_resp.h"
#include "diaib_config.h"
#include "dia_resp_ofr.h"
#include "stat.h"

#define TIMER_TYPE_TRANSACTION  0x00000101

int add_ofr_resp_msg(uxc_worker_t *worker, diaib_ofr_respQ_t *resp_msg)
{
	int					rv, thread_id;
	char				*key = resp_msg->resp_key;

	thread_id = uxc_worker_get_thread_id(worker);

	if(key == NULL)
	{
		ux_log(UXL_CRT, "[Thread %d] Insert Response message failed.(key is NULL)", thread_id);
		return DIAIB_RESULT_NOTOK;
	}

	rv = insert_data_to_worker(worker, key, resp_msg);
	if(rv < 0)
	{
		ux_log(UXL_CRT, "[Thread %d] Insert Response message failed.(key[%s])", thread_id, key);
		return DIAIB_RESULT_NOTOK;
	}
	else
		ux_log( UXL_DEBUG, "[Thread %d] Insert Response message success.(key[%s])", thread_id, key);

	rv = reg_timer_schedule(worker, resp_msg->tmevt, 
			TIMER_TYPE_TRANSACTION, get_config_trans_timeout()*1000, resp_msg, transaction_msg_timeout);
	if( rv < 0)
	{
		ux_log(UXL_CRT, "[Thread %d] Reg Response timer failed.(key[%s])", thread_id, key);
		delete_data_to_worker(worker, key);     // timer를 정상 등록 하지 못했으니 response 처리 포기
		return DIAIB_RESULT_NOTOK;
	}
	else
		ux_log( UXL_DEBUG, "[Thread %d] Reg Response timer success.(key[%s])", thread_id, key);

	return DIAIB_RESULT_OK;
}

int del_ofr_resp_msg(uxc_worker_t *worker, diaib_ofr_respQ_t *resp_msg)
{
	int					rv, thread_id;
	char				*key = resp_msg->resp_key;

	thread_id = uxc_worker_get_thread_id(worker);

	rv = delete_data_to_worker(worker, key);
	if(rv < 0) {
		ux_log(UXL_CRT, "[Thread %d] Delete Response message failed.(key[%s])",
				thread_id, key);
		return DIAIB_RESULT_NOTOK;
	}

	rv = cancel_timer_schedule(worker, resp_msg->tmevt);
	if(rv < 0)
	{
		ux_log(UXL_CRT, "[Thread %d] Cancel Response timer failed.(key[%s])",
				thread_id, key);
		return DIAIB_RESULT_NOTOK;
	}

	ux_log(UXL_DEBUG, "[Thread %d] Delete response msg success.(key[%s])", thread_id, key);

	/* Destory response msg */
	destroy_diaib_ofr_resp( resp_msg );

	return DIAIB_RESULT_OK ;
}


int get_ofr_msg_resQ_key(char *key_str, udia_msg_t *diamsg)
{
	int					rv;
	udia_avplist_t 		*avplist;

	avplist = udia_msg_get_root(diamsg);
	rv = get_avp_str_item(avplist, AVP_NAME_SESSION_ID, key_str, AVP_SESSION_ID_MAX_LEN);
	if(rv != UDIA_SUCCESS) {
		ux_log(UXL_CRT, "get_avp_str_item(AVP_NAME_SESSION_ID) fail(err:%d)", rv);
		return DIAIB_RESULT_NOTOK;
	}

	ux_log(UXL_DEBUG, "udia_avp_get_str() success(key[%s])", key_str);
	return DIAIB_RESULT_OK;
}

diaib_ofr_respQ_t* create_ofr_resp(smsf_msg_t *mo_msg, stAddr *orig, stAddr *imsi, unsigned char msgRef)
{
    diaib_ofr_respQ_t  *respQ_msg  = malloc( sizeof(diaib_ofr_respQ_t) );
    ux_tmevt_t      *tmevt = malloc( sizeof(ux_tmevt_t) );

    memset( respQ_msg, 0x00, sizeof(diaib_ofr_respQ_t) );
    memset( tmevt, 0x00, sizeof(ux_tmevt_t) );

    respQ_msg->tmevt = tmevt;

	memcpy(&respQ_msg->orig, orig, sizeof(stAddr));
	memcpy(&respQ_msg->imsi, imsi, sizeof(stAddr));
	secure_strcpy(respQ_msg->dest_node.isdn, DEFAULT_ADDR_LEN+1, mo_msg->smsc_isdn);
	respQ_msg->msgRef = msgRef;

    return respQ_msg;
}

int destroy_diaib_ofr_resp(diaib_ofr_respQ_t *resp)
{
	if( resp )
	{
		free( resp->tmevt );
		resp->tmevt = NULL;
		free( resp );
	}
	else {
		ux_log( UXL_MAJ, "destroy_srr_resp() fail.");
	}

	return DIAIB_RESULT_OK;
}

int canc_diaib_ofr_resp_timer(uxc_worker_t *worker, diaib_ofr_respQ_t *resp_msg)
{
	char			*key = NULL;
	int				rv, thread_id;

	thread_id = uxc_worker_get_thread_id(worker);

	if(resp_msg == NULL) {
		ux_log(UXL_CRT, "Response msg is NULL");
		return DIAIB_RESULT_ERROR;
	}

	key = resp_msg->resp_key;

	/* Cancle timeout Timer */
	rv = cancel_timer_schedule(worker, resp_msg->tmevt );
	if(rv < 0) {
		ux_log(UXL_CRT, "[Thread %d] Cancel Response timer failed.(key[%s])", thread_id, key);
		return DIAIB_RESULT_NOTOK;
	} else {
		ux_log(UXL_DEBUG, "[Thread %d] Cancel Response timer success.(key[%s])", thread_id, key);
	}

	return DIAIB_RESULT_OK;
}

void *get_ofr_resp_msg(uxc_worker_t *worker, char *key)
{
	return get_data_to_worker(worker, key);
}

int transaction_msg_timeout(ux_tmtype_t timer_type, void *data)
{
	diaib_ofr_respQ_t      *resp_msg = (diaib_ofr_respQ_t *)data;

	/* Get worker */
	uxc_xcutor_t *xcutor = uxc_xcutor_instance();
	uxc_workermgr_t *wkmgr = uxc_xcutor_get_wkmgr(xcutor);
	uxc_worker_t *worker = uxc_workermgr_current_worker(wkmgr);

	/* Get Response msg from worker_data */
	resp_msg = get_ofr_resp_msg( worker, resp_msg->resp_key );

	/* Send response msg to mtf */
	ux_log( UXL_MAJ, "[Thread %d]TRANSACTION TIMEOUT!(Session-id[%s] ISDN[%s] imsi[%s])",
			uxc_worker_get_thread_id(worker), resp_msg->resp_key, resp_msg->dest_node.isdn, resp_msg->imsi.min );

	inc_ofr_send_time(resp_msg->dest_node.isdn);
	/* Delete response msg */
	del_ofr_resp_msg( worker, resp_msg );

	return DIAIB_RESULT_OK;
}
