#include "diaib.h"

int handle_ofr_msg(uxc_worker_t *worker, smsf_msg_t *mo_msg);
int conv_msg_to_ofr(smsf_msg_t *mo_msg, udia_msg_t *diamsg, stAddr *orig, stAddr *imsi, unsigned char *msgRef);
