#ifndef _DIAIB_CONFIG_MAIN_H
#define _DIAIB_CONFIG_MAIN_H

#include "diaib.h"

int load_common_config(const char *cfile, common_conf_t *conf);
int get_config_trans_timeout();
int get_config_host_id();
char* get_config_orig_host();
char* get_config_orig_realm();
int set_config_host_id(int value);

#endif
