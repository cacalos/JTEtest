#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include <iXtypes.h>
#include <iXCauseCode.h>
#include <ua_log.h>
#include <uxlib/ux_memory.h>
#include <uxlib/ux_hash.h>
#include <uxlib/ux_os.h>
#include <uxlib/ux_util.h>
#include <uxlib/ux_errno.h>
#include <SS7/ss7_resq.h>

typedef struct sigmo_resq_hash_s sigmo_resq_hash_t ;
struct sigmo_resq_hash_s {
	ux_mem_t        *allocator;
	ux_hash_t       resq_hash[1];
};

typedef struct sigmo_resq_s sigmo_resq_t ;
struct sigmo_resq_s {
	ux_hnode_t      hnode[1];
	char			hashkey[128];
	stMoResponseQ	out_res;
};

sigmo_resq_hash_t gResqHash;

int init_resq_data()
{
	int			rv;

	gResqHash.allocator = ux_fxmem_create( sizeof(sigmo_resq_hash_t), 0, 10, UX_TRUE);
	if(gResqHash.allocator == NULL) {
		uaLog(L_CRT, "Create allocator for statistics failed.");
		return IXERR;
	}

	rv = ux_hash_init(gResqHash.resq_hash, 32, ux_compare_str, ux_hash_str, gResqHash.allocator);
	if(rv < UX_SUCCESS) {
		uaLog(L_CRT, "failed to initiate resq hash table. e=%d, %s", rv, ux_errnostr(rv));
		return IXERR;
	} else {
		uaLog(L_CRT, "Success to initiate resq hash table.");
	}
	return IXOK;
}

/* trace를 추가한 함수 */
stMoResponseQ *add_resq_data_for_trace(int diag_id, int trace, int level, stAddr *addr)
{
	int 		rv;

	sigmo_resq_t	*res_data;

	res_data = ux_zalloc(ux_mem_default(), sizeof(sigmo_resq_t));
	if(res_data == NULL) {
		uaLog(L_CRT, "res_data memory alloc failed");
		return NULL;
	}

	sprintf(res_data->hashkey, "%d", diag_id);

	if(addr) {
		memcpy(&res_data->out_res.addr, addr, sizeof(stAddr));
	}
    res_data->out_res.diag_id = diag_id;
	res_data->out_res.trace = trace;
	res_data->out_res.level = level;

	rv = ux_hash_insert(gResqHash.resq_hash, res_data->hashkey, res_data->hnode);
	if(rv == UX_EEXIST) {
		ux_free( ux_mem_default(), res_data);
		uaLog(L_CRT, "Already exist diag_id: %d", diag_id);
		return NULL;
	} else if(rv < UX_SUCCESS) {
		uaLog(L_CRT, "Can't add res info(diag_id:%d)", diag_id);
		return NULL;
	}
    uaLog( L_INFO, "insertOutResQ diag_id=%d tm=%d",
        diag_id, res_data->out_res.sent_tm);

	return &res_data->out_res;
}

int add_resq_data(int diag_id, int status, void *new_msg)
{
	int 		rv;

	sigmo_resq_t	*res_data;

	res_data = ux_zalloc(ux_mem_default(), sizeof(sigmo_resq_t));

	sprintf(res_data->hashkey, "%d", diag_id);

    res_data->out_res.diag_id = diag_id;
    res_data->out_res.status = status;
	res_data->out_res.sent_tm = time(0);
    memcpy(&(res_data->out_res.moMsg), new_msg, sizeof(stMoMsg));

	rv = ux_hash_insert(gResqHash.resq_hash, res_data->hashkey, res_data->hnode);
	if(rv == UX_EEXIST) {
		ux_free( ux_mem_default(), res_data);
		uaLog(L_CRT, "Already exist diag_id: %d", diag_id);
		return IXERR;
	} else if(rv < UX_SUCCESS) {
		uaLog(L_CRT, "Can't add res info(diag_id:%d)", diag_id);
		return IXERR;
	}
    uaLog( L_INFO, "insertMofResQ diag_id=%d tm=%d",
        diag_id, res_data->out_res.sent_tm);

	return IXOK;
}

stMoResponseQ *get_resq_data(int diag_id)
{
	sigmo_resq_t	*res_data = NULL;
	char			hashKey[128];

	sprintf(hashKey, "%d", diag_id);

    res_data = (sigmo_resq_t *)ux_hash_find(gResqHash.resq_hash, hashKey);
	if(res_data == NULL) {
		//uaLog(L_INFO, "Not found res data(diag_id:%d)", diag_id);
		return NULL;
	} else {
		return &res_data->out_res;
	}

}

int remove_resq_data(int diag_id)
{
	sigmo_resq_t    *res_data = NULL;
	char            hashKey[128];

	sprintf(hashKey, "%d", diag_id);

	res_data = (sigmo_resq_t *)ux_hash_remove(gResqHash.resq_hash, hashKey);
	if(res_data == NULL) {
		uaLog(L_CRT, "Not found res data(diag_id:%d)", diag_id);
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

void check_timeout(int timeOut, int *gTimeOutCnt)
{
	time_t cur_time;
	sigmo_resq_t	*res_data = NULL, *temp;

	time(&cur_time);

    res_data = (sigmo_resq_t *)ux_hash_head(gResqHash.resq_hash);
    while(res_data != NULL) {

        if((cur_time - res_data->out_res.sent_tm) < timeOut)
        {
            res_data = (sigmo_resq_t *)ux_hash_next(gResqHash.resq_hash, res_data->hnode);
		    continue;
		}

		uaLog( L_CRT, "time out %d secs diagId=%d sts=%d",
				  cur_time - res_data->out_res.sent_tm, res_data->out_res.diag_id, res_data->out_res.status);
		(*gTimeOutCnt)++;
		sendErrToEngine(res_data->out_res.diag_id, CC_SS7_TIMEOUT, MAP_VERSION_N);

		temp = res_data;
        res_data = (sigmo_resq_t *)ux_hash_next(gResqHash.resq_hash, res_data->hnode);

		ux_hash_remove_node(gResqHash.resq_hash, temp->hnode);
		ux_free( ux_mem_default(), temp);
    }
}
