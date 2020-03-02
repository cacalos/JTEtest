#include "dia_avp_util.h"

/* Octet string type avp 설정 	*/
int add_avp_octet_item(udia_avplist_t *src, char *avp_name, char *data, int data_len)
{
	int 			rv;
	udia_avp_t 		*avp;

	avp = udia_avplist_alloc_n( src, avp_name, &rv );
	if( avp == NULL ) {
		ux_log( UXL_MAJ, "create avp failed ... avpname:%s,result:%d]", avp_name, rv);
		return AVP_UTIL_RESULT_NOTOK;
	}

	rv = udia_avp_set_data( avp, UDIA_AVPFL_NONE, data, data_len );
	if( rv < UDIA_SUCCESS ) {
		ux_log( UXL_MAJ, "set data failed ... avpname:%d,result:%d]", avp_name, rv);
		return AVP_UTIL_RESULT_NOTOK;
	}

	rv = udia_avplist_append( src, avp );
	if( rv < UDIA_SUCCESS ) {
		ux_log( UXL_MAJ, "add avp failed ... avpname:%s,result:%d]", avp_name, rv);
		return AVP_UTIL_RESULT_NOTOK;
	}

	return AVP_UTIL_RESULT_OK;
}

/* Octet string type avp 설정   */
int add_avp_octet_copy_item(udia_avplist_t *src, char *avp_name, char *data, int data_len)
{
	int             rv;
	udia_avp_t      *avp;

	avp = udia_avplist_alloc_n( src, avp_name, &rv );
	if( avp == NULL ) {
		ux_log( UXL_MAJ, "create avp failed ... avpname:%s,result:%d]", avp_name, rv);
		return AVP_UTIL_RESULT_NOTOK;
	}

	rv = udia_avp_set_data( avp, UDIA_AVPFL_NEED_COPY, data, data_len );
	if( rv < UDIA_SUCCESS ) {
		ux_log( UXL_MAJ, "set data failed ... avpname:%d,result:%d]", avp_name, rv);
		return AVP_UTIL_RESULT_NOTOK;
	}

	rv = udia_avplist_append( src, avp );
	if( rv < UDIA_SUCCESS ) {
		ux_log( UXL_MAJ, "add avp failed ... avpname:%s,result:%d]", avp_name, rv);
		return AVP_UTIL_RESULT_NOTOK;
	}

	return AVP_UTIL_RESULT_OK;
}

/* Octet string type avp 를 가져 온다. 	*/
/* Return value: 성공시 avp data size. 	*/
/*               실패시 음수값. 		*/
int get_avp_octet_item(udia_avplist_t *src, char *avp_name, char *dst, size_t dst_size)
{
	int				rv;
	int				data_len;
	udia_avp_t 		*avp;
	char			*ptr;

	avp = udia_avplist_get_avp_n(src, avp_name, &rv);
	if(avp == NULL)
		return -1;

	/*
	data_len = udia_avp_get_buflen(avp);

	if( dst_size < data_len ) return AVP_UTIL_RESULT_NOTOK;

	memcpy( dst, avp->value.ptr, data_len );
	*/
	ptr = (char *)udia_avp_get_octs(avp, &data_len);
	if( dst_size < data_len ) return AVP_UTIL_RESULT_NOTOK;
	memcpy(dst, ptr, data_len);

	return data_len;
}

/* string type avp 를 가져 온다. */
int get_avp_str_item(udia_avplist_t *src, char *avp_name, char *dst, size_t dst_size)
{
	char    *cp = NULL;
	int     rv;

	cp = udia_avplist_get_str_n( src, avp_name, &rv);
	if (cp == NULL) {
		dst[0] = '\0';
		return AVP_UTIL_RESULT_OK;
	}

	secure_strcpy( dst, dst_size, cp);

	return AVP_UTIL_RESULT_OK;
}


/* int type avp 를 가져 온다. */
int get_avp_int_item(udia_avplist_t *src, char *avp_name, int *dst)
{
	int     rv;
	long    tmp_val;

	tmp_val = udia_avplist_get_int_n( src, avp_name, &rv);
	if (rv != UDIA_SUCCESS) {
		*dst = -1;
		return AVP_UTIL_RESULT_NOTOK;
	}

	*dst = (int) tmp_val;

	return AVP_UTIL_RESULT_OK;
}

int get_avp_time_item(udia_avplist_t *src, char *avp_name, time_t *dst)
{
	int     	rv;
	uint32_t    tmp_val;

	tmp_val = udia_avplist_get_time_n( src, avp_name, &rv);
	if (rv != UDIA_SUCCESS) {
		*dst = -1;
		return AVP_UTIL_RESULT_NOTOK;
	}

	*dst = (time_t) tmp_val;

	return AVP_UTIL_RESULT_OK;
}

/* string type avp 추가 한다. */
int add_avp_str_item(udia_avplist_t *avplist, char *avp_name, char *value)
{
	int         rv;

	if (!IS_NULL_STRING( value)) {
		rv = udia_avplist_add_str_n( avplist, avp_name, value);
		if (rv != UDIA_SUCCESS) {
			ux_log( UXL_MAJ, "add_avp_str_item() failed: err=%s, avp_name=\"%s\", avp_value=%d", 
					udia_errcode_to_str(rv), avp_name, value);
			return AVP_UTIL_RESULT_NOTOK;
		}
		return AVP_UTIL_RESULT_OK;
	} else {
		return AVP_UTIL_RESULT_NOTOK;
	}
}

/* int type avp 추가 한다. */
int add_avp_int_item(udia_avplist_t *avplist, char *avp_name, int64_t value)
{
	int         rv;

	rv = udia_avplist_add_int_n( avplist, avp_name, value);
	if (rv != UDIA_SUCCESS) {
		ux_log( UXL_MAJ, "add_avp_int_item() failed: err=%s, avp_name=\"%s\", avp_value=%d", 
				udia_errcode_to_str(rv), avp_name, value);
		return AVP_UTIL_RESULT_NOTOK;
	}
	return AVP_UTIL_RESULT_OK;
}

/* time_t type avp 추가 한다. */
int add_avp_time_item(udia_avplist_t *avplist, char *avp_name, time_t value)
{
	int         rv;

	rv = udia_avplist_add_time_n( avplist, avp_name, value);
	if (rv != UDIA_SUCCESS) {
		ux_log( UXL_MAJ, "add_avp_time_item() failed: err=%s, avp_name=\"%s\", avp_value=%d", 
				udia_errcode_to_str(rv), avp_name, value);
		return AVP_UTIL_RESULT_NOTOK;
	}
	return AVP_UTIL_RESULT_OK;
}

/* Remove avp */
int remove_avp_item(udia_avplist_t *avplist, char *avp_name)
{
    udia_avp_t 		*avp;
	int				rv;

	avp = udia_avplist_get_avp_n(avplist, avp_name, &rv);
	if( avp == NULL ) return AVP_UTIL_RESULT_ERROR;

	rv = udia_avplist_remove(avplist, avp);
	if(rv != UDIA_SUCCESS) {
		ux_log( UXL_MAJ, "remove_avp_item() failed: err=%s, avp_name=\"%s\"", udia_errcode_to_str(rv), avp_name);
		return AVP_UTIL_RESULT_ERROR;
	} 

	return AVP_UTIL_RESULT_OK;
}

int remove_group_userid_item( udia_avplist_t *avplist, char *avp_name)
{
	udia_avplist_t	*user_id;
	udia_avp_t		*avp;
	udia_err_t 		err;
	int				rv;

	user_id = udia_avplist_get_group_n(avplist, avp_name, &err);
	if( user_id == NULL) 
	{
		ux_log( UXL_INFO, "get_group() does not item: avp_name=\"%s\"", AVP_NAME_USER_IDENTIFIER);
		return AVP_UTIL_RESULT_ERROR;
	}

	avp = udia_avplist_get_avp_n(user_id, AVP_NAME_MSISDN, &err);
	if(avp != NULL)
	{
		rv = udia_avplist_remove(user_id, avp);
		if(rv != UDIA_SUCCESS)
		{
			ux_log( UXL_MAJ, "remove_avp_item() failed: err=%s, avp_name=\"%s\"", udia_errcode_to_str(rv), AVP_NAME_USER_NAME);
			return AVP_UTIL_RESULT_ERROR;
		}
	}
	else
		ux_log( UXL_DETAIL, "remove_avp_item() does not item: avp_name=\"%s\"", AVP_NAME_MSISDN);

	avp = udia_avplist_get_avp_n(user_id, AVP_NAME_USER_NAME, &err);
	if(avp != NULL)
	{
		rv = udia_avplist_remove(user_id, avp);
		if(rv != UDIA_SUCCESS)
		{
			ux_log( UXL_MAJ, "remove_avp_item() failed: err=%s, avp_name=\"%s\"", udia_errcode_to_str(rv), AVP_NAME_EXTERNAL_IDENTIFIER);
			return AVP_UTIL_RESULT_ERROR;
		}
	}
	else
		ux_log( UXL_DETAIL, "remove_avp_item() does not item: avp_name=\"%s\"", AVP_NAME_USER_NAME);

	return AVP_UTIL_RESULT_OK;
}

void ConvStrToAddr(char *str, int ton, int npi, stAddr *addr)
{
	strcpy(addr->min, str);
	addr->len = strlen(str);
	addr->ton = ton;
	addr->npi = npi;

	return;
}
