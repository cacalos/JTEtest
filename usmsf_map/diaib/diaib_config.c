#include "diaib_config.h"

static void print_common_config(common_conf_t *conf);

int load_common_config(const char *cfile, common_conf_t *conf)
{
	const char	section[] = "[DIAIB_COMMON]";

	conf->host_id = uxc_get_conf_int( cfile, section, "HOST_ID", 1);
	uxc_get_conf_str( cfile, section, "ORIG_HOST", conf->orig_host, ORIG_HOST_SIZE, "" );
	uxc_get_conf_str( cfile, section, "ORIG_REALM", conf->orig_realm, ORIG_HOST_SIZE, "" );
	conf->ofr_timeout = uxc_get_conf_int( cfile, section, "OFR_TIMEOUT", 10 );

	if(strlen(conf->orig_host) <= 0) {
		ux_log(UXL_CRT, "Can't open load transport identity !!!");
		return eUXC_INIT_FAIL;
	}

	if(strlen(conf->orig_realm) <= 0) {
		ux_log(UXL_CRT, "Can't open load transport realm_name !!!");
		return eUXC_INIT_FAIL;
	}

	print_common_config(conf);

	return eUXC_SUCCESS;
}

static void print_common_config(common_conf_t *conf)
{
	ux_log(UXL_ALWAYS, "=================== COMMON_CONFIG =====================");
	ux_log(UXL_ALWAYS, "HOST_ID                    = %d", get_config_host_id() );
	ux_log(UXL_ALWAYS, "ORIG_REALM                 = %s", get_config_orig_realm() );
	ux_log(UXL_ALWAYS, "ORIG_HOST                  = %s", get_config_orig_host() );
	ux_log(UXL_ALWAYS, "OFR_TIMEOUT                = %d", get_config_trans_timeout() );
	ux_log(UXL_ALWAYS, "========================================================\n");
}

int get_config_trans_timeout()
{
	return diaib_instance()->common_conf.ofr_timeout;
}

char* get_config_orig_realm()
{
	return diaib_instance()->common_conf.orig_realm;
}

char* get_config_orig_host()
{
	return diaib_instance()->common_conf.orig_host;
}

int get_config_host_id()
{
	return diaib_instance()->common_conf.host_id;
}

int set_config_host_id(int value)
{
	/* value에 대한 무결성 검사 TODO*/

	diaib_instance()->common_conf.host_id = value;
	return 0;
}
