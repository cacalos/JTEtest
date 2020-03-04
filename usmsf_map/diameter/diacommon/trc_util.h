#ifndef _TRC_UTIL_H
#define _TRC_UTIL_h

#include "uxcutor/uxc_worker.h"
#include "udia/udia_msg.h"
#include "udia/udia_avps.h"
#include "udia/udia_msg.h"


#define dia_msg_trc( a, b) ex_dia_msg_trc( __FILE__, __LINE__, a, b)

int set_trace_flag(char *trc_key, int is_on);
int is_trace_on(void);
//int set_trace_flag(uxc_worker_t *worker, char *trc_key, int is_on);
void ex_dia_msg_trc(char *src_file, int src_line, uxc_worker_t *worker, udia_msg_t *stackmsg);
void sprint_dia_msg_to_buff(char *buffer, char *rpui, int buffer_size, udia_msg_t *stackmsg);
void sprint_dia_avp_to_buff(char *buffer, char *rpui, int buffer_size, udia_msg_t *stackmsg);

#endif
