#include <RPDU/RPDU.h>
#include <RPDU/okhTypes.h>

#include "handle_msg.h"
#include "handle_ofr_req_msg.h"
#include "handle_ofr_resp_msg.h"
#include "dia_resp_ofr.h"
#include "diaib_avp_util.h"
#include "stat.h"

int handle_ofr_msg(uxc_worker_t *worker, smsf_msg_t *mo_msg) 
{
	int                 rv, thread_id;
	unsigned char 		msgRef = 0;
	diaib_ofr_respQ_t	*ofr_resp = NULL;
	upa_diamsg_t        *pa_diamsg = NULL;
	stAddr 				orig, imsi;
	smsf_msg_t 			mo_resp;

	thread_id = uxc_worker_get_thread_id(worker);

	if(strlen(mo_msg->supi) < 1 || strlen(mo_msg->gpsi) < 1) 
	{
		ux_log(UXL_CRT, "[Thread %d] supi or gpsi value is null, supi[%s], gpsi[%s]",
				thread_id, mo_msg->supi, mo_msg->gpsi);
		return DIAIB_RESULT_ERROR;
	}

	if(strlen(mo_msg->dest_host) < 1 && strlen(mo_msg->dest_realm) < 1) 
	{
		ux_log(UXL_CRT, "[Thread %d] supi or gpsi value is null, dest_host[%s], dest_realm[%s]",
				thread_id, mo_msg->dest_host, mo_msg->dest_realm);
		return DIAIB_RESULT_ERROR;
	}

	memset(&orig, 0, sizeof(stAddr));
	memset(&imsi, 0, sizeof(stAddr));
	memset(&mo_resp, 0, sizeof(smsf_msg_t));

	orig.len = sprintf(orig.min, "%s", mo_msg->gpsi);
	imsi.len = sprintf(imsi.min, "%s", mo_msg->supi);

	orig.ton = imsi.ton = TON_UNKNOWN;
	orig.npi = imsi.npi - NPI_E164;

	ux_log(UXL_INFO, "[Thread %d] Received OFR, imsi[%s], gpsi[%s], dest_host[%s], dest_realm[%s], isdn[%s]",
			thread_id, mo_msg->supi, mo_msg->gpsi, mo_msg->dest_host, mo_msg->dest_realm, mo_msg->smsc_isdn);

	check_smsc_list(mo_msg->smsc_isdn);

	/* Create PA_diameter OFR msg */
    //TODO Check dia_util function ??¢¬
    pa_diamsg = create_diamsg( diaib_get_padia(), UDIA_CMD_OFR, 0, get_config_host_id() );
    if( pa_diamsg == NULL ){
        ux_log( UXL_CRT, "[Thread %d] Create Diameter msg FAIL(supi[%s])",
                thread_id, mo_msg->supi );
        set_ofr_fail_resp( ofr_resp, CC_DIAMETER_INTERNAL_ERROR, &mo_resp );
        goto error;
    }

	/* Convert eng msg to OFR upa_diamsg */
    rv = conv_msg_to_ofr( mo_msg, pa_diamsg->stackmsg, &orig, &imsi, &msgRef );
    if( rv != DIAIB_RESULT_OK ){
        ux_log( UXL_CRT, "[Thread %d] Convert msg into Diameter msg(supi[%s])",
                thread_id, mo_msg->supi);
        set_ofr_fail_resp( ofr_resp, CC_DIAMETER_INTERNAL_ERROR, &mo_resp );
        goto error;
    }

	/* Create ENG response msg */
	ofr_resp = create_ofr_resp( mo_msg, &orig, &imsi, msgRef );
	if( ofr_resp == NULL ){
		ux_log( UXL_CRT,
				"[Thread %d] Create resonse msg FAIL. Tiemout occured.(supi:%s)", thread_id, mo_msg->supi);
		/* response msg ??¡¾ ?¤í ENG?¼뢮 response륨ù¡í? ??¢´. */
		//inc_ofr_send_fail(smsc_isdn);
		return DIAIB_RESULT_NOTOK;
	}

	ux_log( UXL_DBG1, "[Thread %d] Create resonse msg SUCCESS(supi:%s, gpsi:%s)",
			thread_id, mo_msg->supi, mo_msg->gpsi);

	/* Set key value of response msg */
    rv = get_ofr_msg_resQ_key( ofr_resp->resp_key, (udia_msg_t *)pa_diamsg->stackmsg );
    if( rv != DIAIB_RESULT_OK ){
        ux_log( UXL_CRT, "[Thread %d] Get key of response msg from Diameter msg FAIL(supi[%s])",
                thread_id, mo_msg->supi);
        set_ofr_fail_resp( ofr_resp, CC_DIAMETER_INTERNAL_ERROR, &mo_resp );
        goto error;
    }

    /* Insert response Q */
    rv = add_ofr_resp_msg( worker, ofr_resp);
    if( rv != DIAIB_RESULT_OK ){
        ux_log( UXL_CRT, "[Thread %d] Add resp_msg data into Worker FAIL.(supi[%s])",
                thread_id, mo_msg->supi);
        set_ofr_fail_resp( ofr_resp, CC_DIAMETER_INTERNAL_ERROR, &mo_resp );
        goto error;
    }

	/* Set Trace flag */
	set_addr_mintrace_flag( NULL, &orig, &imsi);
    print_send_call_trace( pa_diamsg->stackmsg, &orig, &imsi);
	dia_msg_trc( worker, pa_diamsg->stackmsg );

	/* Send Diamsg */
	rv = send_msg_to_dia( worker, pa_diamsg );
    if( rv != DIAIB_RESULT_OK ){
        ux_log( UXL_CRT, "[Thread %d] Send OFR msg FAIL(operation_name[OFR] supi[%s] err[%d])",
                thread_id, mo_msg->supi, rv );
        set_ofr_fail_resp( ofr_resp, CC_DIAMETER_INTERNAL_ERROR, &mo_resp );
        goto error;
    }
	else {
		ux_log( UXL_INFO, "[Thread %d] Send OFR msg Success(operation_name[OFR] supi[%s])",
                thread_id, mo_msg->supi);
	}

	inc_ofr_send_succ(mo_msg->smsc_isdn);

    if( pa_diamsg ) upa_diamsg_destroy( pa_diamsg );
	return DIAIB_RESULT_OK;

	/* destory diamsg */
error:
    inc_ofr_send_fail(mo_msg->smsc_isdn);
//    send_resp_to_mof_eng( ofr_resp );
    del_ofr_resp_msg( worker, ofr_resp );
    if( pa_diamsg ) upa_diamsg_destroy( pa_diamsg );
    return DIAIB_RESULT_ERROR;
}

int conv_msg_to_ofr(smsf_msg_t *mo_msg, udia_msg_t *diamsg, stAddr *orig, stAddr *imsi, unsigned char *msgRef)
{
	int                     rv;
    udia_avplist_t          *avp_list = udia_msg_get_root(diamsg);
	_RPDU 					rpdu;

	/* Set Session-ID AVP */
    rv = set_avp_session_id( avp_list );
    if( rv != DIAIB_RESULT_OK ){
        ux_log( UXL_CRT, "set_avp_session_id() fail.[supi:%s]", mo_msg->supi);
        return DIAIB_RESULT_NOTOK;
    }

    /* Set BASIC AVP */
    rv = set_avp_basic( avp_list, AVP_APP_ID_SGD_IF );
    if( rv != DIAIB_RESULT_OK ){
        ux_log( UXL_CRT, "set_avp_basic() fail.[supi:%s]", mo_msg->supi);
        return DIAIB_RESULT_NOTOK;
    }

	/* Set Orig/Dest Info */
    rv = set_avp_node_info( avp_list, mo_msg->dest_host, mo_msg->dest_realm);
    if( rv != DIAIB_RESULT_OK){
        ux_log( UXL_CRT, "set_avp_node_info() fail.[supi:%s]", mo_msg->supi);
        return DIAIB_RESULT_NOTOK;
    }

	/* Set Sc-Address */
    rv = set_avp_ofr_RP_DA( avp_list, mo_msg->smsc_isdn);
    if( rv != DIAIB_RESULT_OK){
        ux_log( UXL_CRT, "set_avp_RP_OA() fail.[supi:%s]", mo_msg->supi);
        return DIAIB_RESULT_NOTOK;
    }

    /* Set User-Name */
    rv = set_avp_ofr_RP_OA( avp_list, orig, imsi);
    if( rv != DIAIB_RESULT_OK){
        ux_log( UXL_CRT, "set_avp_RP_DA() fail.[orig:%s]", mo_msg->supi);
        return DIAIB_RESULT_NOTOK;
    }

	memset(&rpdu, 0, sizeof(_RPDU));

	rv = DecodeRPDU(&rpdu, (void *)mo_msg->data, mo_msg->data_len, DIRECTION_MS_SC);
	if(rv < 0)
	{
		ux_log(UXL_CRT, "DecodeRPDU() fail, supi[%s]", mo_msg->supi);
        return DIAIB_RESULT_NOTOK;
	}

	int i;
	char buf[1024], *ptr = buf;

	memset(buf, 0, sizeof(buf));

	for(i = 0; i < rpdu.Union.rData.RpDataLength; i++) {
		sprintf(ptr, "%02X", rpdu.Union.rData.RpUserData[i]);
		ptr += strlen(ptr);
	}
	ux_log(UXL_DBG1, "RPDU Raw Data, len[%d]", rpdu.Union.rData.RpDataLength);
	ux_log(UXL_DBG1, "%s", buf);

	/* Set RP-UI */
    rv = set_avp_ofr_RP_UI( avp_list, (char *)rpdu.Union.rData.RpUserData, (int)rpdu.Union.rData.RpDataLength);
    if( rv != DIAIB_RESULT_OK){
        ux_log( UXL_CRT, "set_avp_RP_UI() fail.[supi:%s]", mo_msg->supi);
        return DIAIB_RESULT_NOTOK;
    }

	*msgRef = rpdu.MessageReference;

    return DIAIB_RESULT_OK;
}
