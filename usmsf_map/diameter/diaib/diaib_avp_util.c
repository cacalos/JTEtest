#include "diaib_avp_util.h"


int set_avp_ofr_RP_UI( udia_avplist_t *avp_list, char *data, int len)
{
    int                 rv;

    if( len == 0 ){
        ux_log( UXL_CRT, "add_avp_octet_item() Fail(sm_RP_UI len is 0)");
        return DIAIB_RESULT_NOTOK;
    }

//    rv = add_avp_octet_item( avp_list, AVP_NAME_SM_RP_UI, (char *)data, len );
    rv = add_avp_octet_copy_item( avp_list, AVP_NAME_SM_RP_UI, (char *)data, len );
    if( rv != AVP_UTIL_RESULT_OK ){
        ux_log( UXL_CRT, "add_avp_octet_item() Fail");
        return DIAIB_RESULT_NOTOK;
    }

    return DIAIB_RESULT_OK;
}

int set_avp_ofr_RP_DA( udia_avplist_t *avp_list, char *isdn)
{
    int             rv;
    AddressString   rp_da;
    stAddr          addr;

    memset(&addr, 0, sizeof(stAddr));
    addr.len = sprintf(addr.min, "%s", isdn);

    ConvStrToAddressString(addr.len, addr.min, &rp_da);
    rv = add_avp_octet_copy_item( avp_list, AVP_NAME_SC_ADDRESS, (char *)rp_da.value, rp_da.length );

    if( rv != AVP_UTIL_RESULT_OK ){
        ux_log( UXL_MAJ, "add_avp_octet_copy_item() fail.");
        return DIAIB_RESULT_NOTOK;
    }

    return DIAIB_RESULT_OK;
}

int set_avp_ofr_RP_OA( udia_avplist_t *avp_list, stAddr *orig, stAddr *orig_imsi )
{
    int                 rv;
    AddressString       msisdn;
    udia_avplist_t      *groupavp;

    rv = udia_avplist_add_group_n( avp_list, AVP_NAME_USER_IDENTIFIER, &groupavp);

    if(rv == AVP_UTIL_RESULT_OK)
    {
        if(orig->len > 0)
        {
            memset(&msisdn, 0, sizeof(AddressString));
            ConvStrToAddressString(orig->len, orig->min, &msisdn);
            rv = add_avp_octet_copy_item( groupavp, AVP_NAME_MSISDN, (char *)msisdn.value, msisdn.length );
        }

        if(orig_imsi->len > 0)
            rv = udia_avplist_add_str_n(groupavp, AVP_NAME_USER_NAME, orig_imsi->min);
    }

    if(rv != AVP_UTIL_RESULT_OK) {
        ux_log( UXL_MAJ, "add_avp_str_item() fail.");
        return DIAIB_RESULT_NOTOK;
    }

    return DIAIB_RESULT_OK;
}

int set_avp_node_info( udia_avplist_t *avp_list, char *host, char *realm)
{
	ux_log( UXL_DEBUG, "set_avp_node_info O_HOST[%s] O_REALM[%s] D_HOST[%s] D_REALM[%s]", 
			get_config_orig_host(), get_config_orig_realm(), host, realm);
	add_avp_str_item( avp_list, AVP_NAME_ORIGIN_HOST, get_config_orig_host() );
	add_avp_str_item( avp_list, AVP_NAME_ORIGIN_REALM, get_config_orig_realm() );

	add_avp_str_item( avp_list, AVP_NAME_DESTINATION_REALM, realm );
	add_avp_str_item( avp_list, AVP_NAME_DESTINATION_HOST, host );

	return DIAIB_RESULT_OK;
}

#if 0
int set_avp_TFR_Flag( udia_avplist_t *avp_list, MT_ForwardSM_Arg_V3 *mtf3)
{
	int 				rv;
	if( mtf3->bit_mask & MT_ForwardSM_Arg_V3_moreMessagesToSend_present){
		rv = add_avp_int_item( avp_list, AVP_NAME_TFR_FLAGS, 1);
		if( rv != AVP_UTIL_RESULT_OK ){
			ux_log( UXL_CRT, "Add TFR-Flag AVP Fail!!. add_avp_int_item() Fail");
			return DIAIB_RESULT_NOTOK;
		}
	}
	
	return DIAIB_RESULT_OK;
}

int set_avp_User_Identifier(udia_avplist_t *avp_list, stAddr *addr)
{
	int					rv;
	AddressString		msisdn;
	udia_avplist_t      *groupavp;

	rv = udia_avplist_add_group_n( avp_list, AVP_NAME_USER_IDENTIFIER, &groupavp);

	if(rv == AVP_UTIL_RESULT_OK)
	{
		if(addr->ton == TON_DEVICE_REPORT)
		{
			memset(&msisdn, 0, sizeof(AddressString));
			ConvStrToAddressString(addr->len, addr->min, &msisdn);
			rv = add_avp_octet_copy_item( groupavp, AVP_NAME_MSISDN, (char *)msisdn.value, msisdn.length );
		}
		else
			rv = udia_avplist_add_str_n(groupavp, AVP_NAME_USER_NAME, addr->min);
	}
	
	if(rv != AVP_UTIL_RESULT_OK) {
		ux_log( UXL_MAJ, "add_avp_str_item() fail.");
		return DIAIB_RESULT_NOTOK;
	}

	return DIAIB_RESULT_OK;
}

#endif

int set_avp_session_id( udia_avplist_t *avp_list)
{
	int			thd_idx;
	uint32_t	dialog_id = get_n_inc_diaib_diag_id();
	char 		sess_id[AVP_SESSION_ID_MAX_LEN];

	/* Get Thread id */
	thd_idx = uxc_worker_get_thread_id( uxc_xcutor_current_worker(diaib_instance()->xcutor) );

	/* Session-Id: <origin-host>; <high 32bit>; <low 32bit>;[<thread_id>] */
	sprintf( sess_id, "%s%c%u%c%u%c%d", get_config_orig_host(), DIAIB_SESSION_ID_SEP
			, get_diaib_start_time(), DIAIB_SESSION_ID_SEP
			, dialog_id, DIAIB_SESSION_ID_SEP
			, thd_idx-1); 

	add_avp_str_item( avp_list, AVP_NAME_SESSION_ID, sess_id );
	return DIAIB_RESULT_OK;
}


int set_avp_basic(udia_avplist_t *avp_list, int interface)
{
	udia_avplist_t*		sub_avplist;

	/* Set VENDOR_SPECIFIC_APPLICATION_ID */
	udia_avplist_add_group_n( avp_list, AVP_NAME_VENDOR_SPECIFIC_APPLICATION_ID, &sub_avplist );
	add_avp_int_item( sub_avplist, AVP_NAME_VENDOR_ID, UDIA_3GPP_VENDOR_ID );
	add_avp_int_item( sub_avplist, AVP_NAME_AUTH_APPLICATION_ID, interface);

	/* Set AUTH_SESSION_STATE */
	add_avp_int_item( avp_list, AVP_NAME_AUTH_SESSION_STATE, 1 );

	return DIAIB_RESULT_OK;
}

int get_thread_idx_from_session_id(char *session_id)
{
	int				i, len, found_delim;
	char			*key = NULL;

	len = strlen(session_id);	

	found_delim = 0;
	for(i = len-1; i > len - 5; i--) {
		if(session_id[i] == DIAIB_SESSION_ID_SEP) {
			found_delim = 1;
			break;
		}
	}

	if(found_delim)
		key = &session_id[i+1];
	else 
		key = NULL;
	
	if(key != NULL) {
		ux_log( UXL_DEBUG, "DIAMETER PA Thread Key(%s).", key );
		return atoi(key);
	} else {
		ux_log( UXL_CRT, "Thread Key is NULL. Thread index Set to [0]." );
		return 0;
	}
}

int check_sc_address(udia_avplist_t *avp_list, smsf_msg_t *mt_msg, stAddr *smscAddr)
{
#define MAX_SC_ADDRESS_AVP_LEN         24
//    char                smsc_addr[24];
    stAddr              dest;

#define MAX_SC_ADDRESS_AVP_SIZE         9
    int                 len;
    ISDN_AddressString  sc_address;
    char                value[MAX_SC_ADDRESS_AVP_SIZE];

    len = get_avp_octet_item(avp_list, AVP_NAME_SC_ADDRESS, value, MAX_SC_ADDRESS_AVP_SIZE);
    if(len < AVP_UTIL_RESULT_OK)
    {
        ux_log(UXL_MAJ, "Get SC-Address fail.");
        return DIAIB_RESULT_NOTOK;
    }

    sc_address.value[0] = 0xA1;
    len = CheckISDNAddressLength(len); /* ISDN Address length check logic 171117 by.shlee */
    memcpy(&sc_address.value[1], value, len);
    sc_address.length = len+1;
    ConvISDNStringToAddress(&sc_address, &dest);

	strcpy(mt_msg->smsc_isdn, dest.min);
	memcpy(smscAddr, &dest, sizeof(stAddr));

    return DIAIB_RESULT_OK;
}

int get_dia_msg_for_resp_msg(udia_msg_t *diamsg, char *session_id, char *orig_realm, char *dest_realm,
                char *orig_host,  char *dest_host)
{
    int                 rv;
    char                *tmp_str;
    udia_avplist_t      *avplist = udia_msg_get_root(diamsg);

    tmp_str = udia_avplist_get_str_n( avplist, "Session-Id", &rv);
    if ( rv < UDIA_SUCCESS) {
        ux_log( UXL_MAJ, "udia_avplist_get_int_n() is failed(Session-Id e=%d)", rv);
    	return DIAIB_RESULT_NOTOK;
    }
    strcpy(session_id, tmp_str);

    tmp_str = udia_avplist_get_str_n( avplist, "Origin-Realm", &rv);
    if ( rv < UDIA_SUCCESS) {
        ux_log( UXL_MAJ, "Origin-Realm: Not Found");
    }
    else
        strcpy(orig_realm, tmp_str);

    tmp_str = udia_avplist_get_str_n( avplist, "Destination-Realm", &rv);
    if ( rv < UDIA_SUCCESS) {
        ux_log( UXL_MAJ, "Destination-Realm: Not Found");
    }
    else
        strcpy(dest_realm, tmp_str);

    tmp_str = udia_avplist_get_str_n( avplist, "Origin-Host", &rv);
    if ( rv < UDIA_SUCCESS) {
        ux_log( UXL_MAJ, "Origin-Host: Not Found");
    }
    else
        strcpy(orig_host, tmp_str);

    tmp_str = udia_avplist_get_str_n( avplist, "Destination-Host", &rv);
    if ( rv < UDIA_SUCCESS) {
        ux_log( UXL_INFO, "Destination-Host: Not Found");
        strcpy(dest_host,  upa_dia_get_server_name(diaib_get_padia()));
    }
    else
        strcpy(dest_host, tmp_str);

    return DIAIB_RESULT_OK;
}

int set_avp_for_tfa_ack(udia_msg_t *diamsg, char *session_id, char *orig_realm, char *orig_host)
{
//	int     rv;
//	udia_avplist_t *groupavp;
//	udia_avp_t     *new_avp;

	udia_avplist_t *avplist = udia_msg_get_root(diamsg);
	if(!avplist) return DIAIB_RESULT_NOTOK;

	udia_avplist_add_str_n(avplist, "Session-Id", session_id);
	udia_avplist_add_str_n(avplist, "Origin-Host", orig_host);
	udia_avplist_add_str_n(avplist, "Origin-Realm", orig_realm);
	udia_avplist_add_int_n(avplist, "Auth-Session-State", 1);

	udia_avplist_add_int_n(avplist, "Result-Code", UDIA_RESULT_SUCCESS);

	return DIAIB_RESULT_OK;
}

int set_avp_for_tfa_nack(udia_msg_t *diamsg, char *session_id, char *orig_realm, char *orig_host, int causeCode)
{
	int     cc, rv;
	udia_avplist_t *groupavp;

	udia_avplist_t *avplist = udia_msg_get_root(diamsg);
	if(!avplist) return DIAIB_RESULT_NOTOK;

	udia_avplist_add_str_n(avplist, "Session-Id", session_id);
	udia_avplist_add_str_n(avplist, "Origin-Host", orig_host);
	udia_avplist_add_str_n(avplist, "Origin-Realm", orig_realm);
	udia_avplist_add_int_n(avplist, "Auth-Session-State", 1);

	rv = udia_avplist_add_group_n( avplist, "Experimental-Result", &groupavp);
	if(rv == UDIA_SUCCESS && groupavp != NULL)
	{
		switch(causeCode)
		{
			case CC_ABSENT_SUBSCRIBER :
				cc = 5550;
				break;
			case CC_MCEF :
				cc = 5558;
				break;
			case CC_PROTOCOL_ERR :
				cc = 5555;
				break;
			case CC_CALL_BARRED :
				cc = 5557;
				break;
			default :
				cc = 5550;
		}

		udia_avplist_add_int_n(groupavp, "Vendor-Id", 10415);
		udia_avplist_add_int_n(groupavp, "Experimental-Result-Code", cc);
	}
	else 
	{
		ux_log(UXL_CRT, "Can not set Experimental-Result");
		return DIAIB_RESULT_NOTOK;
	}

	ux_log(UXL_INFO, "set_avp_for_tfa_nack(), causecode = %d, cc = %d", causeCode, cc);

	return DIAIB_RESULT_OK;
}

int set_fail_tfa_avp(udia_avplist_t *avplist, int exp_rst_code)
{
    int             rv = UX_SUCCESS;

    remove_avp_for_tfa(exp_rst_code, avplist);

    return rv;
}

int remove_avp_for_tfa(int result_code, udia_avplist_t *avplist)
{
	remove_avp_item( avplist, AVP_NAME_USER_NAME );
    remove_avp_item( avplist, AVP_NAME_SC_ADDRESS);
    remove_avp_item( avplist, AVP_NAME_SM_RP_UI );
    remove_avp_item( avplist, AVP_NAME_MME_NUMBER_FOR_MT_SMS);
    remove_avp_item( avplist, AVP_NAME_SGSN_NUMBER);
    remove_avp_item( avplist, AVP_NAME_TFR_FLAGS );
    remove_avp_item( avplist, AVP_NAME_SM_DELIVERY_TIME);
    remove_avp_item( avplist, AVP_NAME_SM_DELIVERY_START_TIME);
    remove_avp_item( avplist, AVP_NAME_SMSMI_CORRELATION_ID);
	
    if(result_code)
        remove_avp_item( avplist, AVP_NAME_RESULT_CODE );

    return AVP_UTIL_RESULT_OK;
}

int add_avp_exp_rst(udia_avplist_t  *avplist, int exp_rst_code)
{
    int                     rv;
    udia_avplist_t          *group_avplist = NULL;

    /*  add expreimental_result group avp */
    rv = udia_avplist_add_group_n( avplist, AVP_NAME_EXPERIMENTAL_RESULT, &group_avplist );
    if( rv < UDIA_SUCCESS ) return rv;

    /* 3gpp vendor_id */
    rv = add_avp_int_item( group_avplist, AVP_NAME_VENDOR_ID, UDIA_3GPP_VENDOR_ID );
    if( rv < UDIA_SUCCESS ) return rv;

    rv = add_avp_int_item( group_avplist, AVP_NAME_EXPERIMENTAL_RESULT_CODE, exp_rst_code );
    if( rv < UDIA_SUCCESS ) return rv;

    return rv;
}
