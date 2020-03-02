#include <string.h>

#include <iXstat.h>

#include "diaib.h"
#include "stat.h"

/* Init stat */
int init_diaib_stat(diaib_t *diaib)
{
	int					i;
	stSmscList			*dia_list = get_diaib_dia_list();
	stDIAstat			*dia_stat = get_diaib_dia_stat();

	memset(dia_stat, 0, sizeof(stDIAstat) * MAX_SMSC_LIST);

	/* Get list for stat */
	for( i = 0; i < diaib->smscCnt; i++){
		secure_strcpy( dia_stat[i].isdn, SMSC_ISDN_SIZE, dia_list[i].isdn );
	}

	return IXOK;
}

/* Update stat */
int update_diaib_stat(diaib_t *diaib)
{
	int					i, sum = 0;
	int					ofr_snd_msg, ofr_rcv_ack, ofr_rcv_nack, ofr_timeout;
	int					tfr_rcv_msg, tfr_snd_ack, tfr_snd_nack, tfr_timeout;
	stStatMsg 			stat_msg;
	ux_mutex_t          *stat_mutex = get_diaib_stat_mutex();
//	stSmscList			*dia_list  = get_diaib_dia_list();
	stDIAstat			*dia_stat  = get_diaib_dia_stat();

	memset( &stat_msg, 0x00, sizeof(stStatMsg) );
	stat_msg.mtype = MSGQ_MTYPE_STAT;
	stat_msg.protocol = MAP_STAT_DIA_STAT;

	ofr_snd_msg = ofr_rcv_ack = ofr_rcv_nack = ofr_timeout = 0;
	tfr_rcv_msg = tfr_snd_ack = tfr_snd_nack = tfr_timeout = 0;

	/***** Mutex LOCK *****/
	ux_mutex_lock( stat_mutex );

	/* Insert stat data to StatQ */
	for( i = 0; i < diaib->smscCnt ; i++ )
	{
		sum = dia_stat[i].ofr_send_succ + dia_stat[i].ofr_resp_ack + dia_stat[i].ofr_resp_nack + dia_stat[i].ofr_timeout + 
			  dia_stat[i].tfr_recv_succ + dia_stat[i].tfr_recv_fail + dia_stat[i].tfr_send_ack + dia_stat[i].tfr_send_nack + 
			  dia_stat[i].tfr_timeout;

		if(sum == 0)
			continue;

		memcpy( &stat_msg.u.diaStat, &dia_stat[i], sizeof(stDIAstat) );
		if(InsStatQMsg((void *)&stat_msg) != IXOK)
		{
			ux_log(UXL_CRT, "<<< FAIL send to ixstat >>> ISDN=[%s]", dia_stat[i].isdn);
		} else {
			ux_log(UXL_DETAIL, "<<< SUCC send to ixstat >>> ISDN=[%s], %d,%d,%d,%d,%d,%d,%d,%d", dia_stat[i].isdn, 
					stat_msg.u.diaStat.ofr_send_succ,
					stat_msg.u.diaStat.ofr_resp_ack,
					stat_msg.u.diaStat.ofr_resp_nack,
					stat_msg.u.diaStat.ofr_timeout,
					stat_msg.u.diaStat.tfr_recv_succ,
					stat_msg.u.diaStat.tfr_send_ack,
					stat_msg.u.diaStat.tfr_send_nack,
					stat_msg.u.diaStat.tfr_timeout );
		}

		/* For Call count per sec */
		ofr_snd_msg += stat_msg.u.diaStat.ofr_send_succ;
		ofr_rcv_ack += stat_msg.u.diaStat.ofr_resp_ack;
		ofr_rcv_nack += stat_msg.u.diaStat.ofr_resp_nack;
		ofr_timeout += stat_msg.u.diaStat.ofr_timeout;
		tfr_rcv_msg += stat_msg.u.diaStat.tfr_recv_succ;
		tfr_snd_ack += stat_msg.u.diaStat.tfr_send_ack;
		tfr_snd_nack += stat_msg.u.diaStat.tfr_send_nack;
		tfr_timeout += stat_msg.u.diaStat.tfr_timeout;
	}

	/* Print call count per sec */
	if( ofr_snd_msg > 0 || ofr_rcv_ack > 0 || ofr_rcv_nack > 0 || ofr_timeout > 0 || 
		tfr_rcv_msg > 0 || tfr_snd_ack > 0 || tfr_snd_nack > 0 || tfr_timeout > 0)
	{
		ux_log( UXL_CRT, 
		"[Snd] OFR:%d [Rcv] (OFA) A:%d N:%d T:%d, [Rcv] TFR:%d, [Snd] (TFA) A:%d, N:%d, T:%d",
				ofr_snd_msg, ofr_rcv_ack, ofr_rcv_nack, ofr_timeout,
				tfr_rcv_msg, tfr_snd_ack, tfr_snd_nack, tfr_timeout);
	}

	/* reset stat list */
	init_diaib_stat( diaib );

	/***** Mutex UNLOCK *****/
	ux_mutex_unlock( stat_mutex );
		
	return IXOK;
}

void check_smsc_list(char *isdn)
{
	int 			i;
	diaib_t   		*diaib = diaib_instance();
	stSmscList		*smsc_list = get_diaib_dia_list();
	stDIAstat		*dia_stat  = get_diaib_dia_stat();
	ux_mutex_t      *smsc_mutex = get_diaib_slist_mutex();

	for(i = 0; i < diaib->smscCnt; i++)
	{
		if(strcmp(smsc_list[i].isdn, isdn) == 0) {
			ux_log(UXL_DETAIL, "Find SMSC[%s], index[%d] in smscList", isdn, i);
			return;
		}
	}

	ux_mutex_lock(smsc_mutex);
	strcpy(smsc_list[i].isdn, isdn);
	strcpy(dia_stat[i].isdn, isdn);
	diaib->smscCnt = i + 1;
	ux_mutex_unlock(smsc_mutex);

	ux_log(UXL_INFO, "Add SMSC ISDN[%s], idx[%d], cnt[%d] in smscList", isdn, i, diaib->smscCnt);

	return;
}

int get_idx_in_dianode_tab(char *isdn, stSmscList *dia_list)
{
	int		i;
	char	node[DIA_ISDN_SIZE];
	diaib_t   *diaib = diaib_instance();

	if(isdn == NULL){
		ux_log( UXL_MAJ, "get_idx_in_dianode_tab() fail. point is NULL");
		return IXERR;
	}

	strcpy(node, isdn);

	for(i = 0; i < diaib->smscCnt; i++)
	{
		if(strcmp(dia_list[i].isdn, node) == 0)
			return i;
	}

	return IXERR;
}

void inc_ofr_send_succ(char *isdn)
{
	int				idx;
	stSmscList* 	dia_list = get_diaib_dia_list();
	stDIAstat*		dia_stat = get_diaib_dia_stat();
	ux_mutex_t		*stat_mutex = get_diaib_stat_mutex();

	idx = get_idx_in_dianode_tab(isdn, dia_list);
	if( idx < 0 ){
		ux_log( UXL_CRT, "get_idx_in_dianode_tab() fail.(err[%d] isdn[%s] )", idx, isdn );
		return;
	}
	ux_mutex_lock( stat_mutex );
	dia_stat[idx].ofr_send_succ++;		// Increase count
	ux_mutex_unlock( stat_mutex );
	return;
}

void inc_ofr_send_fail(char *isdn)
{
	int				idx;
	stSmscList* 	dia_list = get_diaib_dia_list();
	stDIAstat*		dia_stat = get_diaib_dia_stat();
	ux_mutex_t		*stat_mutex = get_diaib_stat_mutex();

	idx = get_idx_in_dianode_tab(isdn, dia_list);
	if( idx < 0 ){
		ux_log( UXL_CRT, "get_idx_in_dianode_tab() fail.(err[%d] isdn[%s] )", idx, isdn );
		return;
	}
	ux_mutex_lock( stat_mutex );
	dia_stat[idx].ofr_send_fail++;		// Increase count
	ux_mutex_unlock( stat_mutex );
	return;
}

void inc_ofr_resp_ack(char *isdn)
{
	int				idx;
	stSmscList* 	dia_list = get_diaib_dia_list();
	stDIAstat*		dia_stat = get_diaib_dia_stat();
	ux_mutex_t      *stat_mutex = get_diaib_stat_mutex();

	idx = get_idx_in_dianode_tab(isdn, dia_list);
	if( idx < 0 ){
		ux_log( UXL_CRT, "get_idx_in_dianode_tab() fail.(err[%d] isdn[%s] )", idx, isdn );
		return;
	}
	ux_mutex_lock( stat_mutex );
	dia_stat[idx].ofr_resp_ack++;		// Increase count
	ux_mutex_unlock( stat_mutex );
	return;
}

void inc_ofr_resp_nack(char *isdn)
{
	int				idx;
	stSmscList* 	dia_list = get_diaib_dia_list();
	stDIAstat*		dia_stat = get_diaib_dia_stat();
	ux_mutex_t      *stat_mutex = get_diaib_stat_mutex();

	idx = get_idx_in_dianode_tab(isdn, dia_list);
	if( idx < 0 ){
		ux_log( UXL_CRT, "get_idx_in_dianode_tab() fail.(err[%d] isdn[%s] )", idx, isdn );
		return;
	}
	ux_mutex_lock( stat_mutex );
	dia_stat[idx].ofr_resp_nack++;		// Increase count
	ux_mutex_unlock( stat_mutex );
	return;
}

void inc_ofr_send_time(char *isdn)
{
	int				idx;
	stSmscList* 	dia_list = get_diaib_dia_list();
	stDIAstat*		dia_stat = get_diaib_dia_stat();
	ux_mutex_t      *stat_mutex = get_diaib_stat_mutex();

	idx = get_idx_in_dianode_tab(isdn, dia_list);
	if( idx < 0 ){
		ux_log( UXL_CRT, "get_idx_in_dianode_tab() fail.(err[%d] isdn[%s] )", idx, isdn );
		return;
	}

	ux_mutex_lock( stat_mutex );
	dia_stat[idx].ofr_timeout++;		// Increase count
	ux_mutex_unlock( stat_mutex );
	return;
}


void inc_tfr_recv_succ(char *isdn)
{
	int				idx;
	stSmscList* 	dia_list = get_diaib_dia_list();
	stDIAstat*		dia_stat = get_diaib_dia_stat();
	ux_mutex_t		*stat_mutex = get_diaib_stat_mutex();

	idx = get_idx_in_dianode_tab(isdn, dia_list);
	if( idx < 0 ){
		ux_log( UXL_CRT, "get_idx_in_dianode_tab() fail.(err[%d] isdn[%s] )", idx, isdn );
		return;
	}
	ux_mutex_lock( stat_mutex );
	dia_stat[idx].tfr_recv_succ++;		// Increase count
	ux_mutex_unlock( stat_mutex );
	return;
}

void inc_tfr_recv_fail(char *isdn)
{
	int				idx;
	stSmscList* 	dia_list = get_diaib_dia_list();
	stDIAstat*		dia_stat = get_diaib_dia_stat();
	ux_mutex_t		*stat_mutex = get_diaib_stat_mutex();

	idx = get_idx_in_dianode_tab(isdn, dia_list);
	if( idx < 0 ){
		ux_log( UXL_CRT, "get_idx_in_dianode_tab() fail.(err[%d] isdn[%s] )", idx, isdn );
		return;
	}
	ux_mutex_lock( stat_mutex );
	dia_stat[idx].tfr_recv_fail++;		// Increase count
	ux_mutex_unlock( stat_mutex );
	return;
}

void inc_tfr_send_ack(char *isdn)
{
	int				idx;
	stSmscList* 	dia_list = get_diaib_dia_list();
	stDIAstat*		dia_stat = get_diaib_dia_stat();
	ux_mutex_t      *stat_mutex = get_diaib_stat_mutex();

	idx = get_idx_in_dianode_tab(isdn, dia_list);
	if( idx < 0 ){
		ux_log( UXL_CRT, "get_idx_in_dianode_tab() fail.(err[%d] isdn[%s] )", idx, isdn );
		return;
	}
	ux_mutex_lock( stat_mutex );
	dia_stat[idx].tfr_send_ack++;		// Increase count
	ux_mutex_unlock( stat_mutex );
	return;
}

void inc_tfr_send_nack(char *isdn)
{
	int				idx;
	stSmscList* 	dia_list = get_diaib_dia_list();
	stDIAstat*		dia_stat = get_diaib_dia_stat();
	ux_mutex_t      *stat_mutex = get_diaib_stat_mutex();

	idx = get_idx_in_dianode_tab(isdn, dia_list);
	if( idx < 0 ){
		ux_log( UXL_CRT, "get_idx_in_dianode_tab() fail.(err[%d] isdn[%s] )", idx, isdn );
		return;
	}
	ux_mutex_lock( stat_mutex );
	dia_stat[idx].tfr_send_nack++;		// Increase count
	ux_mutex_unlock( stat_mutex );
	return;
}

void inc_tfr_recv_time(char *isdn)
{
	int				idx;
	stSmscList* 	dia_list = get_diaib_dia_list();
	stDIAstat*		dia_stat = get_diaib_dia_stat();
	ux_mutex_t      *stat_mutex = get_diaib_stat_mutex();

	idx = get_idx_in_dianode_tab(isdn, dia_list);
	if( idx < 0 ){
		ux_log( UXL_CRT, "get_idx_in_dianode_tab() fail.(err[%d] isdn[%s] )", idx, isdn );
		return;
	}

	ux_mutex_lock( stat_mutex );
	dia_stat[idx].tfr_timeout++;		// Increase count
	ux_mutex_unlock( stat_mutex );
	return;
}
