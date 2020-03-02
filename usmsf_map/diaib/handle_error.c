#include "diaib.h"

int conv_dia_err_to_cc(udia_avp_t* rst_code)
{
	int             rv, rst;

	if( rst_code == NULL ) return CC_DIAMETER_INTERNAL_ERROR;

	rst = udia_avp_get_int( rst_code, &rv);
	if( rv != UDIA_SUCCESS )
		return CC_DIAMETER_INTERNAL_ERROR;

	ux_log( UXL_DEBUG, "Convert Diameter AVP Result-Code to CC code. Result-AVP(%d)", rst );
	/* Conv Result-Code to CC TODO Recheck */
	switch( rst ){
		/**** Success Result ****/
		case UDIA_RESULT_SUCCESS:           return DIAIB_RESULT_OK;
		case UDIA_LIMITED_SUCCESS:          return DIAIB_RESULT_OK;
											/**** Informational Result ****/
		case UDIA_MULTI_ROUND_AUTH:         return CC_DIAMETER_ROUND_AUTH;
											/**** Protocol Error Result ****/
		case UDIA_PROTOCOL_ERROR:           return CC_DIAMETER_PROTOCOL_ERR;
		case UDIA_COMMAND_UNSUPPORTED:      return CC_DIAMETER_COMMAND_UNSUPPORTED;
											/* ELG MME NPR�� ���ؼ� �ش� ������ ó���ϰ� �־
											   Report_SM�� ó���� �� ���� ���󶧹��� ���⼭ �������ش�. added by jiju 16/02/25 */
		case UDIA_UNABLE_TO_DELIVER:        return CC_NPR3G_CS;
											//      case UDIA_UNABLE_TO_DELIVER:        return CC_DIAMETER_UNABLE_TO_DELIVER;
		case UDIA_REALM_NOT_SERVED:         return CC_DIAMETER_REALM_NOT_SERVED;
		case UDIA_TOO_BUSY:                 return CC_DIAMETER_TOO_BUSY;
		case UDIA_LOOP_DETECTED:            return CC_DIAMETER_LOOP_DETECTED;
		case UDIA_REDIRECT_INDICATION:      return CC_DIAMETER_REDIRECT_INDICATION;
		case UDIA_APPLICATION_UNSUPPORTED:  return CC_DIAMETER_APPLICATION_UNSUPPORTED;
		case UDIA_INVALID_HDR_BITS:         return CC_DIAMETER_INVALID_HDR_BITS;
		case UDIA_INVALID_AVP_BITS:         return CC_DIAMETER_INVALID_AVP_BITS;
		case UDIA_UNKNOWN_PEER:             return CC_DIAMETER_UNKNOWN_PEER;
											/**** Transient Error Result ****/
		case UDIA_AUTHENTICATION_REJECTED:  return CC_DIAMETER_AUTHENTICATION_REJECTED;
		case UDIA_OUT_OF_SPACE:             return CC_DIAMETER_OUT_OF_SPACE;
		case UDIA_ELECTION_LOST:            return CC_DIAMETER_ELECTION_LOST;
		case UDIA_END_USER_SERVICE_DENIED:  return CC_DIAMETER_END_USER_SERVICE_DENIED;
											//case UDIA_USER_UNKNOWN:   return CC_DIAMETER_ERROR_USER_UNKNOWN;
		case UDIA_UNKNOWN_SESSION_ID:       return CC_DIAMETER_UNKNOWN_SESSION_ID;
		case UDIA_AUTHORIZATION_REJECTED:   return CC_DIAMETER_AUTHORIZATION_REJECTED;
		case UDIA_INVALID_AVP_VALUE:        return CC_DIAMETER_INVALID_AVP_VALUE;
		case UDIA_MISSING_AVP:              return CC_DIAMETER_MISSING_AVP;
		case UDIA_RESOURCES_EXCEEDED:       return CC_DIAMETER_RESOURCES_EXCEEDED;
		case UDIA_CONTRADICTING_AVPS:       return CC_DIAMETER_CONTRADICTING_AVPS;
		case UDIA_AVP_NOT_ALLOWED:          return CC_DIAMETER_AVP_NOT_ALLOWED;
		case UDIA_NO_COMMON_APPLICATION:    return CC_DIAMETER_NO_COMMON_APPLICATION;
		case UDIA_UNSUPPORTED_VERSION:      return CC_DIAMETER_UNSUPPORTED_VERSION;
		case UDIA_UNABLE_TO_COMPLY:         return CC_DIAMETER_UNABLE_TO_COMPLY;
		case UDIA_INVALID_BIT_IN_HEADER:    return CC_DIAMETER_INVALID_BIT_IN_HEADER;
		case UDIA_INVALID_AVP_LENGTH:       return CC_DIAMETER_INVALID_AVP_LENGTH;
		case UDIA_INVALID_MESSAGE_LENGTH:   return CC_DIAMETER_INVALID_MESSAGE_LENGTH;
		case UDIA_INVALID_AVP_BIT_COMBO:    return CC_DIAMETER_INVALID_AVP_BIT_COMBO;
		case UDIA_NO_COMMON_SECURITY:       return CC_DIAMETER_NO_COMMON_SECURITY;
											/* Peer ������ ���������� ��� ADIF����
											   Transieng_error��  �߻��Ͽ� peer disconnected Error�� ������*/
		case UDIA_TRANSIENT_ERROR:          return CC_DIAMETER_PEER_DISCONNECTED;

		default:
			ux_log( UXL_MAJ, "Couldn't mapping UDIA Erro to CC Code(UDIA_RESULT:%d)", rst);
			/*  �� Result-Code�� Mapping���� �ʴ�   */
			/*  4000����� 5000���� Result-Code��   */
			/*  Cause Code�� �����Ͽ� ó���ϵ��� ����*/
			/*  �ʸ�ũ�� ���ǵ� ����                */
			if( rst/5000 == 1 )
				return CC_DIAMETER_PERIMENTAL_ERROR;
			else if( rst/4000 == 1 )
				return CC_DIAMETER_TRANSIENT_ERROR;
			else
				return CC_DIAMETER_INTERNAL_ERROR;
	}
}

int conv_exp_err_to_cc(udia_avplist_t* avplist)
{
	int                     rv, rst_code;
	udia_avplist_t          *expl_rst;

	/* Get Experimental-Result AVP */
	expl_rst  = udia_avplist_get_group_n( avplist, AVP_NAME_EXPERIMENTAL_RESULT, &rv );
	if( rv == UDIA_ERR_MISSING_AVP ){
		return DIAIB_RESULT_OK;
	} else if( rv < UDIA_SUCCESS ){
		ux_log( UXL_CRT, "Get Experimental-Result AVP Fail.(err:%d)", rv);
		return CC_DIAMETER_INTERNAL_ERROR;
	}

	/* Get Experimetal-Result-Code AVP */
	rv = get_avp_int_item( expl_rst, AVP_NAME_EXPERIMENTAL_RESULT_CODE, &rst_code );
	if( rv != AVP_UTIL_RESULT_OK ){
		ux_log( UXL_MAJ, "Get Experimental-Result-Code fail." );
		return CC_DIAMETER_INTERNAL_ERROR;
	}

	ux_log( UXL_MIN, "Recv Experimetal-Result-Code.(Result-Code:%d)", rst_code );

	/* Mapping Error Code */
	switch( rst_code ){
		case DIAMETER_ERROR_SM_DELIVERY_FAILURE:    /* SM Delivery Failue */
			return conv_dlvy_fail_to_cc( avplist );

		case DIAMETER_ERROR_ABSENT_USER:            /* ABSENT User Failue */
			return conv_absent_user_to_cc( avplist );

		case DIAMETER_ERROR_USER_UNKNOWN:
			return CC_DIAMETER_USER_UNKNOWN;
		case DIAMETER_ERROR_USER_BUSY_FOR_MT_SMS:
			return CC_DIAMETER_ERROR_USER_BUSY_FOR_MT_SMS;
		case DIAMETER_ERROR_FACILITY_NOT_SUPPORTED:
			return CC_DIAMETER_ERROR_FACILITY_NOT_SUPPORTED;
		case DIAMETER_ERROR_ILLEGAL_USER:
			return CC_DIAMETER_ERROR_ILLEGAL_USER;
		case DIAMETER_ERROR_ILLEGAL_EQUIPMENT:
			return CC_DIAMETER_ERROR_ILLEGAL_EQUIPMENT;
		case DIAMETER_ERROR_SERVICE_NOT_SUBSCRIBED:
			return CC_DIAMETER_ERROR_SERVICE_NOT_SUBSCRIBE;
		case DIAMETER_ERROR_SERVICE_BARRED:
			return CC_DIAMETER_ERROR_SERVICE_BARRED;
		case DIAMETER_ERROR_MWD_LIST_FULL:
			return CC_DIAMETER_ERROR_MWD_LIST_FULL;

			/* ELG MME NPR�� ���ؼ� �ش� ������ ó���ϰ� �־
			   Report_SM�� ó���� �� ���� ���󶧹��� ���⼭ �������ش�. added by jiju 16/02/25 */
			/* ELG MME�� Experimental-Error�� ������ �����Ѵ�. ���� �߰�����. */
		case UDIA_UNABLE_TO_DELIVER:        return CC_NPR3G_CS;
		case DIAMETER_ERROR_UNREACHABLE_USER:       return CC_IMSI_DETACHED;
//      case DIAMETER_ERROR_SUSPENDED_USER:         return CC_DIAMETER_ERROR_ABSENT_USER;
		/* 4223�� Detached �迭�� �����ش޶�� �ڰ���M�� ��û */
		case DIAMETER_ERROR_DETACHED_USER:      return CC_IMSI_DETACHED;

		default:
			ux_log( UXL_MAJ, "Could not mapping Experimental-Result-Code.(Code:%d)", rst_code );
			/*  �� Result-Code�� Mapping���� �ʴ�   */
			/*  4000����� 5000���� Result-Code��   */
			/*  Cause Code�� �����Ͽ� ó���ϵ��� ����*/
			/*  �ʸ�ũ�� ���ǵ� ����                */
			if( rst_code/5000 == 1 )
				return CC_DIAMETER_PERIMENTAL_ERROR;
			else if( rst_code/4000 == 1 )
				return CC_DIAMETER_TRANSIENT_ERROR;
			else
				return CC_DIAMETER_INTERNAL_ERROR;
	}
}

int conv_dlvy_fail_to_cc(udia_avplist_t* avplist)
{
	int                 rv, sm_dlvy_cc;
	udia_avplist_t      *sm_dlvy_fail;

	sm_dlvy_fail = udia_avplist_get_group_n(avplist, AVP_NAME_SM_DELIVERY_FAILURE_CAUSE, &rv );
	if(sm_dlvy_fail == NULL)
	{
		ux_log( UXL_CRT, "NO AVP DATA INSERTED in DIAMETER_ERROR_SM_DELIVERY_FAILURE case return default error : %d",
				CC_DIAMETER_ERROR_SM_DELIVERY_FAILURE );

		return CC_DIAMETER_ERROR_SM_DELIVERY_FAILURE;
	}
	get_avp_int_item( sm_dlvy_fail, AVP_NAME_SM_ENUMERATED_DELIVERY_FAILURE_CAUSE, &sm_dlvy_cc);

	switch( sm_dlvy_cc )
	{   /* ���� Cause Code�� ����ϰ�, ���� �䱸���� �߻��� ���� */
		case SM_EnumeratedDeliveryFailureCause_memoryCapacityExceeded:
			return CC_MCEF;
		case equipmentProtocolError:
			return CC_PROTOCOL_ERR;
		case equipmentNotSM_Equipped:
			return CC_NOT_SM_EQUIPPED;
		case unknownServiceCentre:
			return CC_UNKNOWN_SC;
		case sc_Congestion:
			return CC_SC_CONGESTION;
		case invalidSME_Address:
			return CC_INVALID_SME_ADDR;
		case subscriberNotSC_Subscriber:
			return CC_INVALID_SME_ADDR;
			/* todo : CC_CALL_FORWARD_WCDMA ? */
		default:
			return CC_DIAMETER_ERROR_SM_DELIVERY_FAILURE;
	}
}

int conv_absent_user_to_cc(udia_avplist_t* avplist)
{
	int                 rv, absent_diagnostic;

	rv = get_avp_int_item( avplist, AVP_NAME_ABSENT_USER_DIAGNOSTIC_SM, &absent_diagnostic );

	/* ABSENT_USER_DIAGNOSTIC_SM AVP�� �������� �ʰų� �ش� AVP���� 0�� ��� CC_DIAMETER_ERROR_ABSENT_USER�� ó��
	   ���� �ش� ���� ������ ��쿡�� ���� ������� CC(3170 +diagnostic)�� ó�� */
	if( rv != AVP_UTIL_RESULT_OK ) {
		return CC_DIAMETER_ERROR_ABSENT_USER;
	}

	/* ���� MTF���� Absend_user Error ó���� �����ϰ� ���� */
	if( absent_diagnostic == 0)
		return CC_DIAMETER_ERROR_ABSENT_USER;
	else
		return absent_diagnostic + 3170 ;
}
