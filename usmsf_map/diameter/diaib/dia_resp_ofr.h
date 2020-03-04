#ifndef _DIAIB_RESP_MAIN_H
#define _DIAIB_RESP_MAIN_H

#include <uxcutor/uxc_worker.h>
#include <uxlib/ux_evtmgr.h>
#include <schedule_timer.h>
#include <worker_util.h>

#include "diaib.h"
#include "diaib_trace.h"

diaib_ofr_respQ_t* create_ofr_resp(smsf_msg_t *mo_msg, stAddr *orig, stAddr *imsi, unsigned char msgRef);
int add_ofr_resp_msg(uxc_worker_t *worker, diaib_ofr_respQ_t *resp_msg);
int del_ofr_resp_msg(uxc_worker_t *worker, diaib_ofr_respQ_t *resp_msg);
int get_ofr_msg_resQ_key(char *key_str, udia_msg_t *diamsg);
int destroy_diaib_ofr_resp(diaib_ofr_respQ_t *resp);
int canc_diaib_ofr_resp_timer(uxc_worker_t *worker, diaib_ofr_respQ_t *resp_msg);
void *get_ofr_resp_msg(uxc_worker_t *worker, char *key);
int transaction_msg_timeout(ux_tmtype_t timer_type, void *data);

#endif
