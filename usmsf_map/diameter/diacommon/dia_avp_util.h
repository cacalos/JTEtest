#include <uxlib/ux_string.h>
#include <uxlib/ux_log.h>
#include <uxlib/ux_ctypes.h>
#include <udia/udia_dict.h>
#include "udia/udia_avps.h"
#include "dia_util.h"
#include "udia/udia_avps.h"

#include <iXtypes.h>

/** AVPs **/
#define AVP_NAME_SESSION_ID									"Session-Id"
#define AVP_NAME_SC_ADDRESS									"SC-Address"
#define AVP_NAME_VENDOR_ID									"Vendor-Id"
#define AVP_NAME_SM_RP_UI									"SM-RP-UI"
#define AVP_NAME_SM_DELIVERY_OUTCOME 						"SM-Delivery-Outcome"
#define AVP_NAME_SM_DELIVERY_FAILURE_CAUSE					"SM-Delivery-Failure-Cause"
#define AVP_NAME_SM_ENUMERATED_DELIVERY_FAILURE_CAUSE		"SM-Enumerated-Delivery-Failure-Cause"
#define AVP_NAME_SM_DIAGNOSTIC_INFO							"SM-Diagnostic-Info"
#define AVP_NAME_SUPPORTED_FEATURES  						"Supported-Features"
#define AVP_NAME_EXPERIMENTAL_RESULT 						"Experimental-Result"
#define AVP_NAME_ABSENT_USER_DIAGNOSTIC_SM					"Absent-User-Diagnostic-SM"
#define AVP_NAME_ABSENT_MME_USER_DIAGNOSTIC_SM				"MME-Absent-User-Diagnostic-SM"
#define AVP_NAME_ABSENT_MSC_USER_DIAGNOSTIC_SM				"MSC-Absent-User-Diagnostic-SM"
#define AVP_NAME_ABSENT_SGSN_USER_DIAGNOSTIC_SM				"SGSN-Absent-User-Diagnostic-SM"
#define AVP_NAME_SM_DELIVERY_CAUSE                          "SM-Delivery-Cause"
//TODO Recheck
#define AVP_NAME_RESULT_CODE 								"Result-Code"
#define AVP_NAME_EXPERIMENTAL_RESULT_CODE 					"Experimental-Result-Code"
#define AVP_NAME_TFR_FLAGS									"TFR-Flags"
#define AVP_NAME_OFR_FLAGS									"OFR-Flags"
#define AVP_NAME_USER_IDENTIFIER							"User-Identifier"
#define AVP_NAME_MSISDN										"MSISDN"
#define AVP_NAME_EXTERNAL_IDENTIFIER 						"External-Identifier"
#define AVP_NAME_SKT_OSFI									"ORIGINATIN-SERVICE-FEATURE-INDICATOR"
#define AVP_NAME_SKT_SMS_OSFI								"SMS-ORIGINATIN-SERVICE-FEATURE-INDICATOR"
#define	AVP_NAME_VENDOR_SPECIFIC_APPLICATION_ID				"Vendor-Specific-Application-Id"
#define	AVP_NAME_VENDOR_ID									"Vendor-Id"
#define	AVP_NAME_AUTH_APPLICATION_ID						"Auth-Application-Id"
#define	AVP_NAME_AUTH_SESSION_STATE							"Auth-Session-State"
#define	AVP_NAME_DESTINATION_REALM							"Destination-Realm"	
#define	AVP_NAME_DESTINATION_HOST							"Destination-Host"	
#define AVP_NAME_ORIGIN_HOST 								"Origin-Host"
#define AVP_NAME_ORIGIN_REALM								"Origin-Realm"
#define AVP_NAME_USER_NAME									"User-Name"
#define AVP_NAME_MSC_NUMBER									"MSC-Number"
#define AVP_NAME_SGSN_NUMBER								"SGSN-Number"
#define AVP_NAME_MME_NUMBER_FOR_MT_SMS						"MME-Number-for-MT-SMS"
#define AVP_NAME_SMSMI_CORRELATION_ID						"SMSMI-Correlation-ID"
#define AVP_NAME_SM_DELIVERY_OUTCOME						"SM-Delivery-Outcome"
#define AVP_NAME_MAXIMUM_UE_AVAILABILITY_TIME               "Maximum-UE-Availability-Time"
#define AVP_NAME_SMS_GMSC_ALERT_EVENT                       "SMS-GMSC-Alert-Event"
#define AVP_NAME_MME_SM_DELIVERY_OUTCOME                    "MME-SM-Delivery-Outcome"
#define AVP_NAME_MSC_SM_DELIVERY_OUTCOME                    "MSC-SM-Delivery-Outcome"
#define AVP_NAME_SGSN_SM_DELIVERY_OUTCOME                   "SGSN-SM-Delivery-Outcome"
#define AVP_NAME_MME_ABSENT_USER_DIAGNOSTIC_SM              "MME-Absent-User-Diagnostic-SM"
#define AVP_NAME_MSC_ABSENT_USER_DIAGNOSTIC_SM              "MSC-Absent-User-Diagnostic-SM"
#define AVP_NAME_SGSN_ABSENT_USER_DIAGNOSTIC_SM             "SGSN-Absent-User-Diagnostic-SM"
#define AVP_NAME_MWD_STATUS									"MWD-Status"
#define AVP_NAME_SM_DELIVERY_TIME							"SM-Delivery-Timer"
#define AVP_NAME_SM_DELIVERY_START_TIME						"SM-Delivery-Start-Time"

// T4 AVP
#define AVP_NAME_DRMP										"DRMP"
#define AVP_NAME_SERVING_NODE								"Serving-Node"
#define AVP_NAME_ADDITIONAL_SERVING_NODE					"Additional-Serving-Node"
#define AVP_NAME_REFERENCE_NUMBER							"Reference-Number"
#define AVP_NAME_VALIDITY_TIME								"Validity-Time"
#define AVP_NAME_PRIORITY_INDICATION						"Priority-Indication"
#define AVP_NAME_SMS_APPLICATION_PORT_ID  					"Application-Port-Identifier"
#define AVP_NAME_SMS_APPLICATION_PORT_ID_T4					"SMS-Application-Port-ID"
#define AVP_NAME_OLD_REFERENCE_NUMBER						"Old-Reference-Number"
#define AVP_NAME_TRIGGER_ACTION								"Trigger-Action"
#define AVP_NAME_PAYLOAD									"Payload"
#define AVP_NAME_SM_RP_SMEA									"SM-RP-SMEA"
#define AVP_NAME_SM_DELIVERY_OUTCOME_T4						"SM-Delivery-Outcome-T4"
#define AVP_NAME_ABSENT_SUBSCRIBER_DIAGNOSTIC_T4			"Absent-Subscriber-Diagnostic-T4"
#define AVP_NAME_MTC_ERROR_DIAGNOSTIC						"MTC-Error-Diagnostic"

#define AVP_CODE_SKT_OSFI									1700
#define AVP_CODE_SKT_SMSOSFI								1701
#define AVP_SKT_SMSC_VENDOR_ID								5806

#define AVP_APP_ID_T4_IF									16777311
#define AVP_APP_ID_S6C_IF									16777312
#define AVP_APP_ID_SGD_IF									16777313
#define AVP_APP_ID_RF_IF									3

#define AVP_SESSION_ID_MAX_LEN								512
#define DIA_AVP_SM_RP_UI_MAX								201

#define ACR_EVENT_RECORD									1
#define UDIA_APP_ACCOUNTING									3

/** SMS Over SGd Error Code (3gpp 23.338) / T4 Error Code (3gpp 29.337)**/
#define DIAMETER_ERROR_USER_UNKNOWN							5001
#define DIAMETER_ERROR_INVALID_SME_ADDRESS 					5530
#define DIAMETER_ERROR_SC_CONGESTION						5531
#define DIAMETER_ERROR_TRIGGER_REPLACE_FAILURE				5533
#define DIAMETER_ERROR_TRIGGER_RECALL_FAILURE				5534
#define DIAMETER_ERROR_ORIGINAL_MESSAGE_NOT_PENDING 		5535
#define DIAMETER_ERROR_ABSENT_USER							5550
#define DIAMETER_ERROR_USER_BUSY_FOR_MT_SMS					5551
#define DIAMETER_ERROR_FACILITY_NOT_SUPPORTED				5552
#define DIAMETER_ERROR_ILLEGAL_USER							5553
#define DIAMETER_ERROR_ILLEGAL_EQUIPMENT					5554
#define DIAMETER_ERROR_SM_DELIVERY_FAILURE					5555
#define DIAMETER_ERROR_SERVICE_NOT_SUBSCRIBED				5556
#define DIAMETER_ERROR_SERVICE_BARRED						5557
#define DIAMETER_ERROR_MWD_LIST_FULL						5558

/** Location Service For SGd Error Code (3gpp 29.172) **/
#define DIAMETER_ERROR_UNREACHABLE_USER						4221
//#define DIAMETER_ERROR_SUSPENDED_USER			4221
#define DIAMETER_ERROR_DETACHED_USER						4223

#define DIAMETER_ERROR_MISSING_AVP							5005

#define AVP_UTIL_RESULT_OK							0
#define AVP_UTIL_RESULT_NOTOK						-1
#define AVP_UTIL_RESULT_ERROR						-2

#define IS_NULL_STRING( s)  ((s)[0] == '\0')

/* Get AVP */
int get_avp_str_item(udia_avplist_t *src, char *avp_name, char *dst, size_t dst_size);
int get_avp_octet_item(udia_avplist_t *src, char *avp_name, char *dst, size_t dst_size);
int add_avp_octet_copy_item(udia_avplist_t *src, char *avp_name, char *data, int data_len);
//int get_avp_octet_item(udia_avplist_t *src, char *avp_name, char *dst);
int get_avp_int_item(udia_avplist_t *src, char *avp_name, int *dst);
int get_avp_time_item(udia_avplist_t *src, char *avp_name, time_t *dst);

/* Add AVP */
int add_avp_str_item(udia_avplist_t *avplist, char *avp_name, char *value);
int add_avp_octet_item(udia_avplist_t *src, char *avp_name, char *data, int data_len);
int add_avp_int_item(udia_avplist_t *avplist, char *avp_name, int64_t value);
int add_avp_time_item(udia_avplist_t *avplist, char *avp_name, time_t value);

/* Remove AVP */
int remove_avp_item(udia_avplist_t *avplist, char *avp_name);
int remove_group_userid_item( udia_avplist_t *avplist, char *avp_name);
void ConvStrToAddr(char *str, int ton, int npi, stAddr *addr);


#if 0
/* Set avp for command */
int set_avp_for_ofr_req(uxc_worker_t *worker, udia_msg_t *diamsg, stOFRMsg *eng_msg);
int set_succ_ofa_avp(udia_msg_t *rsp_msg);
int set_fail_ofa_avp(udia_msg_t *rsp_msg, int64_t exp_rst_code);
int remove_avp_for_ofa(udia_avplist_t *avplist);
int add_avp_exp_rst(udia_avplist_t *avplist, int64_t exp_rst_code);
int add_avp_sm_dlvy_fail_cause(udia_avplist_t *avplist, int fail_cause, char *diagnostic_info);

/* Decode avp to enginge msg */
int decode_avp_submit_sm_rp_ui(udia_avp_t *avp_sm_rp_ui);
int encode_avp_submit_sm_rp_ui(udia_avp_t *avp_sm_rp_ui);

#endif

/*********************************/
/* 		OFR Message Format 		 */
/*********************************/
/*
	 < MO-Forward-Short-Message-Request > 
	 	::= < Diameter Header: 8388645, REQ, PXY, 16777313 > 
		 < Session-Id >
		 [ Vendor-Specific-Application-Id ] 
		 { Auth-Session-State }
		 { Origin-Host }
		 { Origin-Realm }
		 [ Destination-Host ]
		 { Destination-Realm }
		 { SC-Address }
		 [ OFR-Flags ]			//TODO Check
		*[ Supported-Features ]
		 { User-Identifier }
		 { SM-RP-UI }
		 [ SMSMI-Correlation-ID ] 
		 [ SM-Delivery-Outcome ] 
        *[ AVP ]
		*[ Proxy-Info ]
		*[ Route-Record ]
*/
/*********************************/
/* 		OFA Message Format 		 */
/*********************************/
/*
	 < MO-Forward-Short-Message-Request > 
	 	::= < Diameter Header: 8388645, PXY, 16777313 >
	 	 < Session-Id >
	 	 [ Vendor-Specific-Application-Id ] 
		 [ Result-Code ]
	 	 [ Experimental-Result ]
	 	 { Auth-Session-State }
	 	 { Origin-Host }
	 	 { Origin-Realm }
		*[ Supported-Features ]
		 [ SM-Delivery- Failure-Cause ] 
		 [ SM-RP-UI ]
		*[ AVP ]
		*[ Failed-AVP ]
		*[ Proxy-Info ]
		*[ Route-Record ]
*/
