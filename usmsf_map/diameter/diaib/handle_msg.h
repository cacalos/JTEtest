#ifndef _DIAIB_HANDLE_REQ_MAIN_H
#define _DIAIB_HANDLE_REQ_MAIN_H

#include <uxcutor/uxc_worker.h>
#include <iXCauseCode.h>

#include "diaib.h"
#include "diaib_config.h"
//#include "diaib_resp.h"
#include "diaib_avp_util.h"
#include "diaib_trace.h"

#define AVP_BUFF_MAX_SIZE 1024
#define REQ_MSG				1

/* function prototype */
int send_msg_to_dia( uxc_worker_t *worker, upa_diamsg_t *pa_diamsg );
int handle_recv_tfr(uxc_worker_t *worker, uxc_msg_t *msg);
int handle_dia_resp_msg(uxc_worker_t* worker, uxc_msg_t *msg);
int handle_ofr_msg(uxc_worker_t *worker, smsf_msg_t *mo_msg); 
//int handle_snd_fep_msg( fep_msg_t *snd_msg);
//upa_diamsg_t* make_diamsg_for_request(uxc_worker_t *worker, fep_msg_t *fepmsg);

#endif
