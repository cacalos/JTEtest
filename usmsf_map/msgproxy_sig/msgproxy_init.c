#include "smsf.h"

int smsfif_init(char *cfile);
//static void _smsfif_destroy( uxc_plugin_t *pi);
static int _smsfif_on_close(upa_tcp_t *tcp, ux_channel_t *channel, ux_cnector_t *cnector, upa_peerkey_t *peerkey);
static int _smsfif_on_open(upa_tcp_t *tcp, ux_channel_t *channel, ux_cnector_t *cnector, upa_peerkey_t *peerkey);
static int _smsfif_on_accept(upa_tcp_t *tcp, ux_channel_t *channel, ux_accptor_t *accptor,
		ux_cnector_t *cnector, upa_peerkey_t *peerkey);
int _smsfif_heartbit(uxc_plugin_t *plugin, ux_tmtype_t tmevt);

smsf_t* smsf_instance( void)
{   
	static smsf_t    singleton;

	return &singleton;
}

ux_mutex_t* get_proxy_stat_mutex()
{
	return &smsf_instance()->mutex[0];
}

int smsfif_init(char *cfile)
{
	smsf_t 	*smsf = smsf_instance();

	ux_log(UXL_INFO, "init smsfif ----------------------------");

	smsf->xcutor = uxc_xcutor_instance();

	smsf->patcp = (upa_tcp_t *)uxc_xcutor_get_paif(uxc_xcutor_instance(), "PA_TCP");
	if(smsf->patcp == NULL)
	{
		ux_log(UXL_CRT, "Can't find TCP Protocol_Adadpt");
		ux_free(ux_mem_default(), smsf);
		return eUXC_ERROR;
	}

	upa_tcp_set_accept_cb( smsf->patcp, _smsfif_on_accept );
    upa_tcp_set_open_cb( smsf->patcp, _smsfif_on_open );
    upa_tcp_set_close_cb( smsf->patcp, _smsfif_on_close );

	return eUXC_SUCCESS;
}


uxc_plugin_t *smsfif_create(void *xcutor, const char *cfile)
{
	int 			i, rv, cnt = 0;
	smsf_t 			*smsf = smsf_instance(); 
	
	char        *ifName[3] = { "MSGPROXY", "SIGMO", "SIGMT", "DIAIB" };

	rv = uxc_plugin_init(smsf->base, xcutor, cfile);
	if(rv < eUXC_SUCCESS) {
		return NULL;
	}

	smsf->xcutor = (uxc_xcutor_t *) xcutor;

	rv = smsfif_init((char *) cfile);
	if(rv != eUXC_SUCCESS) {
		return NULL;
	}

	if(load_common_config(cfile, &smsf->mode) != eUXC_SUCCESS)
		return (uxc_plugin_t*) NULL;

	smsf->ifQid[SMSF_QID] = msgq_getProcId("MSGPROXY");
	if(smsf->mode == SIGTRAN_MODE)
	{
		smsf->ifQid[SIGIB_IN_QID] = msgq_getProcId("SIGMO");
		smsf->ifQid[SIGIB_OUT_QID] = msgq_getProcId("SIGMT");
	}
	else
	{
		smsf->ifQid[DIAIB_QID] = msgq_getProcId("DIAIB");
	}

	init_msgproxy_stat(smsf);

/* different between MCTC and NBIoT(uain, uaout, fepproxy _ for init.c
	smsf->base->destroy = _smsfif_destroy ;
	smsf->base->reconf = _smsfif_reconf;
	smsf->base->heartbeat = _smsfif_heartbit;
	smsf->base->reload = NULL;
*/
	smsf->base->heartbeat = _smsfif_heartbit;

	return (uxc_plugin_t *) smsf;
}

void _smsfif_final(uxc_plugin_t *plugin)
{
}

int _smsfif_reconf(uxc_plugin_t *plugin)
{
	ux_log(UXL_MAJ, "Reconfigure plugin ......");
	return 0;
}

int _smsfif_heartbit(uxc_plugin_t *plugin, ux_tmtype_t tmevt)
{
	print_msgproxy_stat(smsf_instance());
	return 0;
}
int worker_reload(uxc_plugin_t *plugin, void * worker)
{
	ux_log(UXL_MAJ, "Reload worker...");

	return 0;
}

static int _smsfif_on_accept(upa_tcp_t *tcp, ux_channel_t *channel, ux_accptor_t *accptor,
                ux_cnector_t *cnector, upa_peerkey_t *peerkey)
{
    char        ip_name[128];
	int 		port;

    memset(ip_name, 0, sizeof(ip_name));

	port = (int)ntohs(ux_sockaddr_port(accptor->addr));
    ux_sockaddr_get_name( cnector->addr, ip_name, sizeof(ip_name));
    ux_log( UXL_INFO, "Accept TCP connection, ip[%s], port[%u]", ip_name, port);

    return eUXC_SUCCESS;
}


static int _smsfif_on_open(upa_tcp_t *tcp, ux_channel_t *channel, ux_cnector_t *cnector, upa_peerkey_t *peerkey)
{
    ux_log( UXL_INFO, "Open TCP connection");
    return eUXC_SUCCESS;
}


static int _smsfif_on_close(upa_tcp_t *tcp, ux_channel_t *channel, ux_cnector_t *cnector, upa_peerkey_t *peerkey)
{
   char        ip_name[128];

    ux_log( UXL_INFO, "Close TCP connection");

    ux_sockaddr_get_name( cnector->addr, ip_name, sizeof(ip_name));
    ux_log( UXL_INFO, "Accept TCP connection, ip[%s]", ip_name);

    return eUXC_SUCCESS;
}

/*
static void _smsfif_destroy( uxc_plugin_t *pi)
{
    smsf_t *plugin;

    ux_log( UXL_INFO, "destroy server_final()");

    plugin = (smsf_t *)pi;
    uxc_plugin_final( plugin->base);
	ux_free( ux_mem_default(), plugin);
}
*/

int worker_start(uxc_plugin_t *plugin)
{
	ux_log(UXL_MAJ, "Start worker...");

	return 0;
}


mproxy_stat_t* get_mproxy_stat()
{
	return &smsf_instance()->stat;
}
