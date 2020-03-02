#ifndef _WORKER_UTIL_H
#define _WORKER_UTIL_H

#include "uxcutor/uxc_worker.h"

int insert_data_to_worker(uxc_worker_t *worker, char *key, void *data);
void *get_data_to_worker(uxc_worker_t *worker, char *key);
int delete_data_to_worker(uxc_worker_t *worker, char *key);

#endif
