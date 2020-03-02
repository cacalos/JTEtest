#ifndef _DIAIB_AVP_UTIL_MAIN_H
#define _DIAIB_AVP_UTIL_MAIN_H

#include <udia/udia_avps.h>

#include "dia_avp_util.h"
#include "diaib.h"
#include "diaib_config.h"

int remove_avp_for_tfa(int result_code, udia_avplist_t *avplist);
int set_avp_ofr_RP_DA( udia_avplist_t *avp_list, char *isdn);
int set_avp_ofr_RP_OA( udia_avplist_t *avp_list, stAddr *orig, stAddr *orig_imsi);
int set_avp_ofr_RP_UI( udia_avplist_t *avp_list, char *data, int len);
int set_avp_node_info( udia_avplist_t *avp_list, char *host, char *realm);
int set_avp_session_id( udia_avplist_t *avp_list );
int set_avp_basic(udia_avplist_t *avp_list, int interface);
int get_thread_idx_from_session_id(char *session_id);

int check_sc_address(udia_avplist_t *avp_list, smsf_msg_t *mt_msg, stAddr *smscAddr);
int get_dia_msg_for_resp_msg(udia_msg_t *diamsg, char *session_id, char *orig_realm, char *dest_realm,
                char *orig_host,  char *dest_host);
int set_avp_for_tfa_ack(udia_msg_t *diamsg, char *session_id, char *orig_realm, char *orig_host);
int set_avp_for_tfa_nack(udia_msg_t *diamsg, char *session_id, char *orig_realm, char *orig_host, int causeCode);
int set_fail_tfa_avp(udia_avplist_t *avplist, int exp_rst_code);
int add_avp_exp_rst(udia_avplist_t  *avplist, int exp_rst_code);

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
#endif
