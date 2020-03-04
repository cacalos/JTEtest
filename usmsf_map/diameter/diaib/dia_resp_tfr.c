#include "diaib.h"
#include "diaib_config.h"
#include "dia_resp_tfr.h"
#include "stat.h"

#define DIA_IF_TIMEOUT_IDX    0x00000001
#define DIA_RESP_TIMEOUT 10*1000

diaib_tfr_respQ_t* diaib_tfr_resp_insert(uxc_worker_t *worker,
        char *imsi, char *session_id,
        char *orig_realm, char *dest_realm, char *orig_host, char *dest_host,
        int hop_id, int end_id, int peer_id, unsigned char msgRef, char *smsc_node)
{
   // int count, rv, thread_id;
    int rv, thread_id;
    diaib_tfr_respQ_t 	*resqQ = malloc(sizeof(diaib_tfr_respQ_t));
    ux_tmevt_t   		*tmevt = malloc(sizeof(ux_tmevt_t));

	thread_id = uxc_worker_get_thread_id(worker);

    /* 1. set response structure */
    memset(resqQ, 0x00, sizeof(diaib_tfr_respQ_t));
    memset(tmevt, 0x00, sizeof(ux_tmevt_t));

    resqQ->tmevt = tmevt;

    sprintf(resqQ->resp_key, "%s-%d", imsi, msgRef);

    resqQ->imsi.len = sprintf(resqQ->imsi.min, "%s", imsi);
    strcpy(resqQ->session_id, session_id);
    strcpy(resqQ->orig_realm, orig_realm);
    strcpy(resqQ->dest_realm, dest_realm);
    strcpy(resqQ->orig_host, orig_host);
    strcpy(resqQ->dest_host, dest_host);
    resqQ->hop_id = hop_id;
    resqQ->end_id = end_id;
    resqQ->peer_id = peer_id;
	resqQ->msgRef = msgRef;
    strcpy(resqQ->smsc_node, smsc_node);

    /* 2. insert hash table */
    rv = uxc_worker_set_data( worker, (char*)resqQ->resp_key, &resqQ->hnode);
    if( rv < UX_SUCCESS ) {
        ux_log(UXL_MAJ, "[Thread %d] Can't register outgoing response key=%s. (err=%d,%s)",
                thread_id, resqQ->resp_key, rv, uxc_errnostr(rv));
        free(resqQ->tmevt);
        free(resqQ);
        return NULL;
    }
	else {
		ux_log(UXL_INFO, "[Thread %d] Insert Response Q, key[%s]", thread_id, resqQ->resp_key);
	}

    rv = diaib_resp_set_timeout( uxc_worker_get_evtmgr(worker), resqQ->tmevt, resqQ);
    if( rv < UX_SUCCESS)
    {
        diaib_tfr_resp_remove(worker, resqQ->resp_key);
        free(resqQ->tmevt);
        free(resqQ);
        return NULL;
    }
    return resqQ;
}


int diaib_resp_set_timeout(
        ux_evtmgr_t *evtmgr,
        ux_tmevt_t  *tmevt,
        diaib_tfr_respQ_t *resqQ
        )
{
    int rv;

    rv = ux_evtmgr_schedule_tm(evtmgr, tmevt, DIA_IF_TIMEOUT_IDX, DIA_RESP_TIMEOUT, resqQ, (void *)diaib_tfr_resp_timeout);
    if( rv < UX_SUCCESS) {
        ux_log(UXL_CRT, "Can't schedule timer for outgoing transaction ");
        return rv;
    }
    ux_log(UXL_DEBUG, "Set schedule timer for outgoing transaction, %d", DIA_RESP_TIMEOUT);
    return UX_SUCCESS;
}

int diaib_tfr_resp_remove(uxc_worker_t *worker, char *key)
{
    uxc_worker_remove_data(worker, key);

    return 0;
}

diaib_tfr_respQ_t *diaib_tfr_resp_find(uxc_worker_t *worker, char *key)
{
    return uxc_worker_get_data(worker, key);
}


int diaib_tfr_resp_cancel_timer(ux_evtmgr_t *evtmgr, ux_tmevt_t *tmevt)
{
    ux_evtmgr_cancel_tm(evtmgr, tmevt);
}


upa_diamsg_t* create_diaib_tfr_rsp(int operation, int hop_id, int end_id, int peer_id)
{
   // int             rv;
	upa_diamsg_t    *pa_diamsg;
   // udia_msg_t      *stack_msg;

    udia_dict_t *dic = upa_dia_get_dict(diaib_get_padia());

    pa_diamsg = upa_diamsg_create_rsp(dic, operation);
    if(pa_diamsg == NULL)
        return NULL;

    udia_msg_set_hop_id( pa_diamsg->stackmsg, hop_id);
    udia_msg_set_end_id( pa_diamsg->stackmsg, end_id);
    udia_msg_set_peer_id( pa_diamsg->stackmsg, peer_id);

    return pa_diamsg;
}

void  diaib_tfr_resp_timeout(ux_tmtype_t tmtype, void *data)
{
    int rv;
    diaib_tfr_respQ_t *resqQ = (diaib_tfr_respQ_t*)data, *hash_resqQ;

    uxc_xcutor_t *xcutor = uxc_xcutor_instance();
    uxc_workermgr_t *wkmgr = uxc_xcutor_get_wkmgr(xcutor);
    uxc_worker_t *worker = uxc_workermgr_current_worker(wkmgr);

    //ux_log(UXL_CRT, "before, %d", diaib_resp_count(uxc_workermgr_current_worker(wkmgr)));

    ux_log(UXL_CRT, "diaib_response timeout(key:%s, msi:%s)", resqQ->resp_key, resqQ->imsi.min);
    /* 1. find response Q */
    hash_resqQ = diaib_tfr_resp_find( worker, resqQ->resp_key);
    if(hash_resqQ == NULL)
    {
        ux_log(UXL_CRT, "diaib_tfr_resp_find error(key:%s, imsi:%s)", resqQ->resp_key, resqQ->imsi.min);
        return;
    }
    ux_log(UXL_INFO, "==== diaib_tfr_respQ_timeout, thread number [%d] [%s]====", 
			uxc_worker_get_thread_id(worker), hash_resqQ->resp_key);
	inc_tfr_recv_time(resqQ->smsc_node);

    /* 2. remove response Q */
    rv = diaib_tfr_resp_remove(uxc_workermgr_current_worker(wkmgr), hash_resqQ->resp_key);
	if( rv < 0) {
		ux_log(UXL_CRT, "diaib_tfr_resp_remove() fail");
	}

    free(resqQ->tmevt);
    free(resqQ);

	return;
}
