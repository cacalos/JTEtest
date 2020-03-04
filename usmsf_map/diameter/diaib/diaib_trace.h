#ifndef _DIAIB_DIA_TRACE_H
#define _DIAIB_DIA_TRACE_H
#include <upa/upa_dia.h>
#include <upa/upa_diamsg.h>

#include <iXLog.h>
#include <iXTrace.h>
#include "dia_avp_util.h"

#define TRC_DIA_SEND_MSG_HEAD       "\t=====>> DIAMETER Message_Req =====>>"
#define TRC_DIA_RECV_MSG_HEAD       "\t<<===== DIAMETER Message_Resp <<===="

#define MAX_TRC_BUFFER_SIZE 	2048
#define MAX_OCTET_BUFFER_SIZE 	256

void set_addr_mintrace_flag(stAddr *dest, stAddr *orig, stAddr *imsi);
void print_send_call_trace(udia_msg_t *dia_msg, stAddr *orig, stAddr *imsi);
void print_rcv_call_trace(udia_msg_t *dia_msg, stAddr *orig, stAddr *imsi, int cc_code);

#endif
