#include <stdio.h>

#include "uxcutor/uxc_worker.h"
#include "uxlib/ux_log.h"

#include "worker_util.h"

int insert_data_to_worker(uxc_worker_t *worker, char *key, void *data)
{
	int 	e;

	e = uxc_worker_set_data( worker, key, data);
	if (e != eUXC_SUCCESS) {
		ux_log( UXL_MAJ, "[Thread %d]uxc_worker_set_data() failed: err=%d, key=\"%s\""
				, uxc_worker_get_thread_id(worker), e, key);
		return -1;
	}else {
		ux_log( UXL_DEBUG, "[Thread %d]uxc_worker_set_data() success: err=%d, key=\"%s\""
				, uxc_worker_get_thread_id(worker), e, key);
	}

	return 0;
}

void *get_data_to_worker(uxc_worker_t *worker, char *key)
{
	return uxc_worker_get_data( worker, key);
}

int delete_data_to_worker(uxc_worker_t *worker, char *key)
{
	int 	e;

	e = uxc_worker_remove_data(worker, key);
	if (e != eUXC_SUCCESS) {
		ux_log( UXL_MAJ, "[Thread %d]uxc_worker_remove_data() failed: err=%d, key=\"%s\""
				, uxc_worker_get_thread_id(worker), e, key);
		return -1;
	}

	return 0;
}
