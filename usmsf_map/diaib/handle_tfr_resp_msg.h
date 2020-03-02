#include "diaib.h"

int handle_tfr_resp_msg(uxc_worker_t *worker, smsf_msg_t *smsf_msg);
int diaib_tfr_resp_cancel_timer(ux_evtmgr_t *evtmgr, ux_tmevt_t *tmevt);
