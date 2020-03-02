#ifndef _DIAOUT_STAT_H
#define _DIAOUT_STAT_H

#include "uxcutor/uxc_statmgr.h"
#include "dia_util.h"

int init_diaib_stat(diaib_t *diaib);
int update_diaib_stat(diaib_t *diaib);
int get_idx_in_dianode_tab(char *isdn, stSmscList *dia_list);
void check_smsc_list(char *isdn);

void inc_ofr_send_succ(char *isdn);
void inc_ofr_send_fail(char *isdn);
void inc_ofr_resp_ack(char *isdn);
void inc_ofr_resp_nack(char *isdn);
void inc_ofr_send_time(char *isdn);

void inc_tfr_recv_succ(char *isdn);
void inc_tfr_recv_fail(char *isdn);
void inc_tfr_send_ack(char *isdn);
void inc_tfr_send_nack(char *isdn);
void inc_tfr_recv_time(char *isdn);

#endif
