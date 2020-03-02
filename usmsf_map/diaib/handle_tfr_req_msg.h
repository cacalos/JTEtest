#include "diaib.h"

int handle_recv_tfr(uxc_worker_t *worker, uxc_msg_t *msg);
int make_mt_msg(udia_msg_t *diamsg, smsf_msg_t *mt_msg, uint32_t *err_code, unsigned char *mRef, stAddr *smscAddr);
void set_addr_mintrace_flag(stAddr *dest, stAddr *orig, stAddr *imsi);
int send_tfr_fail_response(uxc_worker_t *worker, upa_diamsg_t *diamsg, int result_code, int dlvy_fail_cause, stAddr *smscAddr);

