#include "smsf.h"

void init_msgproxy_stat(smsf_t *smsf)
{
	mproxy_stat_t *stat  = get_mproxy_stat();

	memset(&smsf->stat, 0, sizeof(mproxy_stat_t));
	
	return;
}

void inc_msgproxy_stat(char type)
{
	mproxy_stat_t *stat  = get_mproxy_stat();

	if(type == MO_MSG)
		atomic_inc(&stat->mo_cnt);
	else if(type == MO_RESP)
		atomic_inc(&stat->mo_resp_cnt);
	else if(type == MT_MSG)
		atomic_inc(&stat->mt_cnt);
	else if(type == MT_RESP)
		atomic_inc(&stat->mt_resp_cnt);
	else if(type == ERR_TYPE)
		atomic_inc(&stat->mt_err_cnt);
	else
		atomic_inc(&stat->other_cnt);

	return;
}


void print_msgproxy_stat(smsf_t *smsf)
{
	mproxy_stat_t *stat  = get_mproxy_stat();

	if(stat->mo_cnt+stat->mo_resp_cnt+stat->mt_cnt+stat->mt_resp_cnt+stat->mt_err_cnt+stat->other_cnt > 0)
	{
		ux_log(UXL_CRT, "MO:%d, MO_RESP:%d, MT:%d, MT_RESP:%d, ERR:%d, OTHER:%d",
				stat->mo_cnt, stat->mo_resp_cnt, stat->mt_cnt, stat->mt_resp_cnt, stat->mt_err_cnt, stat->other_cnt);
	}

	init_msgproxy_stat(smsf);
}
