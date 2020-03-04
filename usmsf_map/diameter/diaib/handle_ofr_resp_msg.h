#include "diaib.h"

int handle_dia_resp_msg(uxc_worker_t* worker, uxc_msg_t *msg);
void set_ofr_succ_resp(diaib_ofr_respQ_t *resp, smsf_msg_t *mo_resp);
void set_ofr_fail_resp(diaib_ofr_respQ_t *resp, int error_code, smsf_msg_t *mo_resp);
int check_error_resp(udia_msg_t *dia_msg);
int conv_ofa_to_resp(udia_msg_t* dia_msg, diaib_ofr_respQ_t* resp, smsf_msg_t *mo_resp, int *err_code);
int send_resp_to_ofa(smsf_msg_t *mo_resp);
