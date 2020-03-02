#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include <ua_log.h>

#include <uxlib/ux_memory.h>
#include <uxlib/ux_hash.h>
#include <uxlib/ux_os.h>
#include <uxlib/ux_util.h>
#include <uxlib/ux_errno.h>

#include <iXtypes.h>
#include <SS7/ss7_resq.h>

typedef struct sigmt_resq_hash_s sigmt_resq_hash_t ;
struct sigmt_resq_hash_s {
	ux_mem_t        *allocator;
	ux_hash_t       resq_hash[1];
};

typedef struct sigmt_resq_s sigmt_resq_t ;
struct sigmt_resq_s {
	ux_hnode_t      hnode[1];
	char			hashkey[128];
	stMtResponseQ   in_res;
};

typedef struct mms_table_hash_s mms_table_hash_t ;
struct mms_table_hash_s {
	ux_mem_t        *allocator;
	ux_hash_t       resq_hash[1];
};

typedef struct mms_table_s mms_table_t ;
struct mms_table_s {
	ux_hnode_t      hnode[1];
	char			hashkey[128];
	int           	diag_id;
	int				user_id;
	int				prov_id;
	stAddr			co_addr;
	time_t        	sent_tm;
};

sigmt_resq_hash_t 	gResqHash;
mms_table_hash_t 	gMmsTableHash;

int init_resq_data()
{
	int			rv;

	gResqHash.allocator = ux_fxmem_create( sizeof(sigmt_resq_hash_t), 0, 10, UX_TRUE);
	if(gResqHash.allocator == NULL) {
		uaLog(L_CRT, "Create allocator for in_resq failed.");
		return IXERR;
	}

	rv = ux_hash_init(gResqHash.resq_hash, 32, ux_compare_str, ux_hash_str, gResqHash.allocator);
	if(rv < UX_SUCCESS) {
		uaLog(L_CRT, "failed to initiate in_resq hash table. e=%d, %s", rv, ux_errnostr(rv));
		return IXERR;
	} else {
		uaLog(L_CRT, "Success to initiate in_resq hash table.");
	}

	gMmsTableHash.allocator = ux_fxmem_create( sizeof(mms_table_t), 0, 10, UX_TRUE);
	if(gMmsTableHash.allocator == NULL) {
		uaLog(L_CRT, "Create allocator for mms hash table failed.");
		return IXERR;
	}

	rv = ux_hash_init(gMmsTableHash.resq_hash, 32, ux_compare_str, ux_hash_str, gMmsTableHash.allocator);
	if(rv < UX_SUCCESS) {
		uaLog(L_CRT, "failed to initiate mms hash table. e=%d, %s", rv, ux_errnostr(rv));
		return IXERR;
	} else {
		uaLog(L_CRT, "Success to initiate mms hash table.");
	}

	return IXOK;
}

/* trace를 추가한 함수 */
stMtResponseQ *add_resq_data_for_trace(int diag_id, int trace, int level, stAddr *imsi)
{
	int 		rv;

	sigmt_resq_t	*res_data;

	res_data = ux_zalloc(ux_mem_default(), sizeof(sigmt_resq_t));
	if(res_data == NULL) {
		uaLog(L_CRT, "res_data memory alloc failed");
		return NULL;
	}

	sprintf(res_data->hashkey, "%d", diag_id);

	if(imsi) {
		memcpy(&res_data->in_res.imsi, imsi, sizeof(stAddr));
	}
    res_data->in_res.diag_id = diag_id;
	res_data->in_res.trace = trace;
	res_data->in_res.level = level;

    res_data->in_res.sent_tm = time(0);
    res_data->in_res.status = MQ_SENT;

	rv = ux_hash_insert(gResqHash.resq_hash, res_data->hashkey, res_data->hnode);
	if(rv == UX_EEXIST) {
		ux_free( ux_mem_default(), res_data);
		uaLog(L_CRT, "Already exist diag_id: %d", diag_id);
		return NULL;
	} else if(rv < UX_SUCCESS) {
		uaLog(L_CRT, "Can't add res info(diag_id:%d)", diag_id);
		return NULL;
	}
    uaLog( L_INFO, "insertInResQ diag_id=%d tm=%d uid=%d pid=%d",
        diag_id, res_data->in_res.sent_tm,
        res_data->in_res.user_id, res_data->in_res.prov_id);

	return &res_data->in_res;
}

int add_resq_data(int diag_id, int u_id, int prov_id, int inv_id, unsigned char acn,
			        USccpAddr *dstAddr, USccpAddr *srcAddr, char isMMS, stAddr *imsi, unsigned char msgRef, stNodeNumber *node)
{
	int 		rv;

	sigmt_resq_t	*res_data;

	res_data = ux_zalloc(ux_mem_default(), sizeof(sigmt_resq_t));

	sprintf(res_data->hashkey, "%s_%d", imsi->min, msgRef);

    res_data->in_res.diag_id = diag_id;
    res_data->in_res.user_id = u_id;
    res_data->in_res.prov_id = prov_id;
    res_data->in_res.inv_id = inv_id;
    res_data->in_res.acn = acn;
    memcpy(&(res_data->in_res.dstAddr), dstAddr, sizeof(USccpAddr));
    memcpy(&(res_data->in_res.srcAddr), srcAddr, sizeof(USccpAddr));
    res_data->in_res.sent_tm = time(0);
    res_data->in_res.status = MQ_SENT;
	res_data->in_res.msgRef = msgRef;
	memcpy(&(res_data->in_res.imsi), imsi, sizeof(stAddr));
	memcpy(&res_data->in_res.node, node, sizeof(stNodeNumber));

	rv = ux_hash_insert(gResqHash.resq_hash, res_data->hashkey, res_data->hnode);
	if(rv == UX_EEXIST) {
		ux_free( ux_mem_default(), res_data);
		uaLog(L_CRT, "Already exist diag_id: %d", diag_id);
		return IXERR;
	} else if(rv < UX_SUCCESS) {
		uaLog(L_CRT, "Can't add res info(diag_id:%d)", diag_id);
		return IXERR;
	}
    uaLog( L_INFO, "insertInResQ diag_id=%d tm=%d uid=%d pid=%d",
        diag_id, res_data->in_res.sent_tm,
        res_data->in_res.user_id, res_data->in_res.prov_id);

	return IXOK;
}

stMtResponseQ *get_resq_data(unsigned char msgRef, char *supi)
{
	sigmt_resq_t	*res_data = NULL;
	char			hashKey[128];

	sprintf(hashKey, "%s_%d", supi, msgRef);

    res_data = (sigmt_resq_t *)ux_hash_find(gResqHash.resq_hash, hashKey);
	if(res_data == NULL) {
		//uaLog(L_INFO, "Not found res data(diag_id:%d)", diag_id);
		return NULL;
	} else {
		return &res_data->in_res;
	}

}

int remove_resq_data(unsigned char msgRef, char *supi)
{
	sigmt_resq_t    *res_data = NULL;
	char            hashKey[128];

	sprintf(hashKey, "%s_%d", supi, msgRef);

	res_data = (sigmt_resq_t *)ux_hash_remove(gResqHash.resq_hash, hashKey);
	if(res_data == NULL) {
		uaLog(L_CRT, "Not found res data(key:%s)", hashKey);
		return IXERR;
	} else {
		ux_free( ux_mem_default(), res_data);
	}

	return IXOK;
}

int resq_data_count()
{
	int 		rv;

	rv = ux_hash_count(gResqHash.resq_hash);

	return rv;
}

void check_timeout(int timeOut)
{
	time_t cur_time;
	sigmt_resq_t	*res_data = NULL, *temp;

	time(&cur_time);

    res_data = (sigmt_resq_t *)ux_hash_head(gResqHash.resq_hash);
    while(res_data != NULL) {

        if((cur_time - res_data->in_res.sent_tm) < timeOut)
        {
            res_data = (sigmt_resq_t *)ux_hash_next(gResqHash.resq_hash, res_data->hnode);
		    continue;
		}

        /* stat */
		/*
        if (res_data->in_res.select & IN_RES_Q_SRI_SELECT) {
            inc_sri_resp_time(res_data->in_res.diag_id, &res_data->in_res.node);
        }
        else if (res_data->in_res.select & IN_RES_Q_MT_SELECT) {
            inc_mtf_resp_time(res_data->in_res.diag_id, &res_data->in_res.node);
        }
		*/
		inc_mtf_resp_time(res_data->in_res.node.isdn);

        send_error3_timeout(&res_data->in_res);

        uaLog( L_CRT, "Timeout %d diagId=%d s_time=%d, send_error[3034]",
                    (cur_time - res_data->in_res.sent_tm), res_data->in_res.diag_id, res_data->in_res.sent_tm);

		temp = res_data;
        res_data = (sigmt_resq_t *)ux_hash_next(gResqHash.resq_hash, res_data->hnode);

		ux_hash_remove_node(gResqHash.resq_hash, temp->hnode);
		ux_free( ux_mem_default(), temp);
    }
}

int add_mms_data(int user_id, int diag_id, int prov_id, stAddr *co_addr)
{
	int 		rv;
	mms_table_t		*mms_data;

	mms_data = ux_zalloc(ux_mem_default(), sizeof(mms_table_t));

	sprintf(mms_data->hashkey, "%d", prov_id);

	mms_data->diag_id = diag_id;
	mms_data->user_id = user_id;
	mms_data->prov_id = prov_id;
	memcpy(&(mms_data->co_addr), co_addr, sizeof(stAddr));
	mms_data->sent_tm = time(0);

	rv = ux_hash_insert(gMmsTableHash.resq_hash, mms_data->hashkey, mms_data->hnode);
	if(rv == UX_EEXIST) {
		ux_free( ux_mem_default(), mms_data);
		uaLog(L_CRT, "Already exist prov_id: %d", prov_id);
		return IXERR;
	} else if(rv < UX_SUCCESS) {
		uaLog(L_CRT, "Can't add mms info(prov_id:%d)", prov_id);
		return IXERR;
	}
    uaLog( L_INFO, "add_mms_data(), user_id=%d prov_id=%d tm=%d co_addr=%s",
        user_id, prov_id, mms_data->sent_tm, co_addr->min);

	return IXOK;
}

int get_mms_data(int prov_id, stAddr *co_addr)
{
	mms_table_t		*mms_data = NULL;
	char			hashKey[128];

	sprintf(hashKey, "%d", prov_id);

    mms_data = (mms_table_t *)ux_hash_find(gMmsTableHash.resq_hash, hashKey);
	if(mms_data == NULL) {
		uaLog(L_MAJ, "Not found mms data(prov_id:%d)", prov_id);
		return IXERR;
	}
	else {
		memcpy(co_addr, &mms_data->co_addr, sizeof(stAddr));
		return IXOK;
	}
}

int remove_mms_data(int prov_id)
{
	mms_table_t    *mms_data = NULL;
	char            hashKey[128];

	sprintf(hashKey, "%d", prov_id);

	mms_data = (mms_table_t *)ux_hash_remove(gMmsTableHash.resq_hash, hashKey);
	if(mms_data == NULL) {
		uaLog(L_CRT, "Not found res data(prov_id:%d)", prov_id);
		return IXERR;
	} else {
		ux_free( ux_mem_default(), mms_data);
	}

	return IXOK;
}


void mms_check_timeout(int timeOut)
{
	time_t 			cur_time;
	mms_table_t		*mms_data = NULL, *temp;

	time(&cur_time);

    mms_data = (mms_table_t *)ux_hash_head(gMmsTableHash.resq_hash);
    while(mms_data != NULL) {

        if((cur_time - mms_data->sent_tm) < timeOut)
        {
            mms_data = (mms_table_t *)ux_hash_next(gMmsTableHash.resq_hash, mms_data->hnode);
		    continue;
		}

        uaLog( L_DBG, "Delete %d prov_id=%d user_id=%d diag_id=%d s_time=%d, co_addr=%s in MMS Table",
                    (cur_time - mms_data->sent_tm), mms_data->prov_id, mms_data->user_id, mms_data->diag_id, 
					mms_data->sent_tm, mms_data->co_addr.min);

		temp = mms_data;
        mms_data = (mms_table_t *)ux_hash_next(gMmsTableHash.resq_hash, mms_data->hnode);

		ux_hash_remove_node(gMmsTableHash.resq_hash, temp->hnode);
		ux_free( ux_mem_default(), temp);
    }
}
