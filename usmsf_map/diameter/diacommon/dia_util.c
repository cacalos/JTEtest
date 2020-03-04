#include <string.h>

#include "upa/upa_diamsg.h"
#include "upa/upa_dia.h"

#include "dia_util.h"

char *secure_strcpy( char *dst, size_t dst_size, const char *src)
{
	if (dst_size > strlen( src)) {
		strcpy( dst, src);
	} else {
		strncpy( dst, src, dst_size - 1);
		dst[dst_size] = '\0';
	}

	return dst;
}


/*  
	operation(ex): �Ʒ��� ���ð�
		#define UDIA_CMD_ACR                             271
		#define UDIA_CMD_CCR                             272
	
	[���ǻ���]
	retrun ���� upa_diamsg_t�� ���Ϸ� �� �ݵ�� 
	�Ʒ� �ڵ�� ���� free �� �־�� �Ѵ�.(�޸� �� �߻���)
	    if( msg ) upa_diamsg_unref( msg );

	host_id : request�� ��츸 ����ϸ� �ý��ۺ��� �ٸ��� �����Ǿ�� �Ѵ�.
			hop_id, end_id�� base key ������ ����
*/
upa_diamsg_t *create_diamsg(upa_dia_t *dia, uint32_t operation, int is_response, int host_id)
{
	udia_dict_t		*dict = upa_dia_get_dict(dia);

	if(is_response) {
		return upa_diamsg_create_rsp(dict, operation);
	} else {
		return upa_diamsg_create_req(dict, operation, host_id);
	}
}

int send_diamsg_to_peer(upa_dia_t *paif, upa_diamsg_t *diamsg)
{
	int					e;

	e = upa_dia_sendmsg(paif, diamsg, 1);
	if (e < UX_SUCCESS) {
		ux_log(UXL_MAJ, "SEND Diameter message failed. e=%d", e);
		return -1;
	}

	return 0;
}

/* common maximum value size of ISDNString is 9,
 * index 0 of value is ton/npi
 * index 1~8 using for address. 171117 by shlee */
int CheckISDNAddressLength(int len)
{
#define MAX_ISDN_Address_LENGTH 8
	if(len > MAX_ISDN_Address_LENGTH)
		return MAX_ISDN_Address_LENGTH;
	else
		return len;
}
