#include <stdio.h>

#include "uxcutor/uxc_worker.h"
#include "uxlib/ux_evtmgr.h"

#include "schedule_timer.h"


/* 
	tm_type: 별도 정의 하지 않으면 -1로 설정
	timeout: millisecond 단위임
	handle: timeout callback function
	data: callback function argument
*/
int reg_timer_schedule(uxc_worker_t* worker, ux_tmevt_t* tmevt, int tm_type, int timeout, void* data, ux_tmevt_handle_f handle)
{
	int				rv;
	ux_evtmgr_t* evtmgr =  uxc_worker_get_evtmgr(worker);

	if(tm_type < 0) tm_type = UX_TM_WTIMER;

	rv = ux_evtmgr_schedule_tm( evtmgr, tmevt, tm_type, timeout, data, handle );
	if(rv < UX_SUCCESS) {
		return -1;
	}
	return 0;
}

int cancel_timer_schedule(uxc_worker_t* worker, ux_tmevt_t* tmevt)
{
	int 		rv;
	ux_evtmgr_t* evtmgr =  uxc_worker_get_evtmgr(worker);

	rv = ux_evtmgr_cancel_tm( evtmgr, tmevt );
	if(rv < UX_SUCCESS) {
		return -1;
	}
	return 0;
}

int re_reg_timer_schedule(uxc_worker_t* worker, ux_tmevt_t* tmevt)
{
	int			rv;
    ux_evtmgr_t* evtmgr =  uxc_worker_get_evtmgr(worker);

	rv = ux_evtmgr_reschedule_tm( evtmgr, tmevt );
	if(rv < UX_SUCCESS) {
		return -1;
	}
	return 0;

}
