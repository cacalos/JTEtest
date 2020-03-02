#ifndef _SCHEDULE_TIMER_H
#define _SCHEDULE_TIMER_H

#include "uxcutor/uxc_worker.h"

int reg_timer_schedule(uxc_worker_t* worker, ux_tmevt_t* tmevt, int tm_type, int timeout, void* data, ux_tmevt_handle_f handle);
int cancel_timer_schedule(uxc_worker_t* worker, ux_tmevt_t* tmevt);
int re_reg_timer_schedule(uxc_worker_t* worker, ux_tmevt_t* tmevt);

#endif
