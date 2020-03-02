#include "smsf.h"

int load_common_config(const char *cfile, int *mode)
{
	const char section[] = "[MSGPROXY_COMMON]";

	*mode = uxc_get_conf_int(cfile, section, "MODE", 0);

	print_common_config();

	return eUXC_SUCCESS;
}

void print_common_config()
{
	int rv = get_config_proxy_mode();

	ux_log(UXL_ALWAYS, "=================== COMMON_CONFIG =====================");
    ux_log(UXL_ALWAYS, "MODE                   = %d(%s)", rv, rv == SIGTRAN_MODE ? "SIGTRAN" : "DIAMETER");
    ux_log(UXL_ALWAYS, "========================================================\n");
}

int get_config_proxy_mode()
{
	return smsf_instance()->mode;
}
