#include <stdio.h>
#include "upa/upa_diamsg.h"
#include "upa/upa_dia.h"

char *secure_strcpy( char *dst, size_t dst_size, const char *src);
upa_diamsg_t *create_diamsg(upa_dia_t *dia, uint32_t operation, int is_response, int host_id);
int send_diamsg_to_peer(upa_dia_t *paif, upa_diamsg_t *diamsg);
int CheckISDNAddressLength(int len);
