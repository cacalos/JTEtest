#ifndef _DIAIB_RESP_MAIN_H
#define _DIAIB_RESP_MAIN_H

#include <uxcutor/uxc_worker.h>
#include <uxlib/ux_evtmgr.h>
#include <schedule_timer.h>
#include <worker_util.h>

#include "diaib.h"
#include "diaib_trace.h"

upa_diamsg_t* create_diaib_tfr_rsp(int operation, int hop_id, int end_id, int peer_id);
void diaib_tfr_resp_timeout(ux_tmtype_t tmtype, void *data);
diaib_tfr_respQ_t* diaib_tfr_resp_insert(uxc_worker_t *worker,
        char *imsi, char *session_id,
        char *orig_realm, char *dest_realm, char *orig_host, char *dest_host,
        int hop_id, int end_id, int peer_id, unsigned char msgRef, char *smsc_node);
int diaib_resp_set_timeout(
        ux_evtmgr_t *evtmgr,
        ux_tmevt_t  *tmevt,
        diaib_tfr_respQ_t *resqQ
        );
int diaib_tfr_resp_remove(uxc_worker_t *worker, char *key);
diaib_tfr_respQ_t *diaib_tfr_resp_find(uxc_worker_t *worker, char *key);
int diaib_tfr_resp_cancel_timer(ux_evtmgr_t *evtmgr, ux_tmevt_t *tmevt);


#endif
