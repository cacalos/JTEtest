
#ifndef _CAUSE_CODE_H_INCLUDE_
#define _CAUSE_CODE_H_INCLUDE_

/* FCS */
#define MAX_FCS_COUNT                            256

#define FCS_NO_ERROR                             0x00

#define FCS_TELEMATIC_NOT_SUPPORTED              0x80       /* O   */
#define FCS_SM_TYPE_0_NOT_SUPPORTED              0x81       /* O T */
#define FCS_CANNOT_REPLACE_SM                    0x82       /* O T */
#define FCS_UNSPECIFIED_TP_PID_ERROR             0x8F       /* O T */

#define FCS_DCS_NOT_SUPPORTED                    0x90       /* O   */
#define FCS_MSG_CLASS_NOT_SUPPORTED              0x91       /*   T */
#define FCS_UNSPECIFIED_TP_DCS_ERROR             0x9F       /* O T */

#define FCS_CMD_CANNOT_BE_ACTIONED               0xA0       /* O   */
#define FCS_CMD_UNSUPPORTED                      0xA1       /* O   */
#define FCS_UNSPECIFIED_TP_CMD_ERROR             0xAF       /* O   */

#define FCS_TPDU_NOT_SUPPORTED                   0xB0       /* O T */

#define FCS_SC_BUSY                              0xC0       /* O   */
#define FCS_NO_SC_SUBSCRIPTION                   0xC1       /* O   */
#define FCS_SC_SYSTEM_FAILURE                    0xC2       /* O   */
#define FCS_INVALID_SME_ADDRESS                  0xC3       /* O   */
#define FCS_DEST_SME_BARRED                      0xC4       /* O   */
#define FCS_SM_REJECTED_DUPLICATE_SM             0xC5       /* O   */
#define FCS_TP_VPF_NOT_SUPPORTED                 0xC6       /* O   */
#define FCS_TP_VP_NOT_SUPPORTED                  0xC7       /* O   */

#define FCS_USIM_SMS_STORAGE_FULL                0xD0       /*   T */
#define FCS_NO_SMS_STORAGE_IN_USIM               0xD1       /*   T */
#define FCS_ERROR_IN_MS                          0xD2       /*   T */
#define FCS_MEMORY_CAPACITY_EXCEEDED             0xD3       /*   T */
#define FCS_USIM_APP_TOOLKIT_BUSY                0xD4       /*   T */
#define FCS_USIM_DATA_DOWNLOAD_ERROR             0xD5       /*   T */

#define FCS_UNSPECIFIED_ERROR_CAUSE              0xFF       /* O T */

/* Error Type */
#define USIM_ERROR_TYPE_ANSI     0x01
#define USIM_ERROR_TYPE_CDMA     0x02
#define USIM_ERROR_TYPE_GSM      0x03
#define USIM_ERROR_TYPE_LOCAL    0x04

/* HTTP ERROR */
#define HTTP_ERROR_TEMPORARY_REDIRECT	307
#define HTTP_ERROR_BAD_REQUEST 			400
#define HTTP_ERROR_FORBIDDEN			403
#define HTTP_ERROR_NOT_FOUND 			404
#define HTTP_ERROR_NOT_ALLOWED 			405
#define HTTP_ERROR_NOT_IMPLEMENTED 		501
#define HTTP_ERROR_SERVICE_UNAVAIABLE 	503
#define HTTP_ERROR_GATEWAY_TIMEOUT 		504

#define ATTEMPTING_TO_REACH_UE				800
#define N1_N2_TRANSFER_INITIATED			801
#define WAITING_FOR_ASYNCHRONOUS_TRANSFER	802
#define	UE_NOT_RESPONDING					803
#define	N1_MSG_NOT_TRANSFERRED				804
#define	UE_NOT_REACHABLE_FOR_SESSION		805
/* CC */
#define MAX_CC_COUNT                             256

// Common CC [1000 ~ 1255] ---------------------------------------------
#define CC_RECV_INVOKE_UNKNOWN_OP                1001
#define CC_RECV_INVALID_OPCODE                   1002
#define CC_RECV_PARA_ERROR                       1003
#define CC_RECV_EC_ERROR                         1004
#define CC_RECV_UNKNOWN_COMP                     1005
#define CC_RECV_UNKNOWN_PRIM                     1006
#define CC_RECV_INVALID_ACN                      1007
#define CC_RECV_ACN_ERROR                        1008

#define CC_FLOWCTRL                              1010
#define CC_NETCONGEST                            1011
#define CC_HLR_FLOWCTRL                          1012
#define CC_3GMSC_FLOWCTRL                        1013
#define CC_2GMSC_FLOWCTRL                        1014
#define CC_MME_FLOWCTRL                          1015

#define CC_RECV_PABORT                           1020
#define CC_RECV_UABORT                           1021
#define CC_RECV_REJECT                           1022
#define CC_RECV_CONTINUE                         1023
#define CC_RECV_CANCEL                           1024

#define CC_UERROR_NO_PARAM                       1030
#define CC_UERROR_UNRECOG_MIN                    1031 /* WARNS!! use 'CC_UERROR_UNRECOG_MIN_FOR_CDMA' for CDMA CC */
#define CC_UERROR_UNRECOG_ESN                    1032
#define CC_UERROR_MIN_HLR_MISMATCH               1033
#define CC_UERROR_OP_SEQ_PROBLEM                 1034
#define CC_UERROR_RESOURCE_SHORTAGE              1035
#define CC_UERROR_OP_NOT_SUPPORTED               1036
#define CC_UERROR_TRUNK_UNAVAIL                  1037
#define CC_UERROR_PARAM_ERROR                    1038
#define CC_UERROR_SYSTEM_FAILURE                 1039
#define CC_UERROR_UNREG_PARAM_VALUE              1040
#define CC_UERROR_FEATURE_INACTIVE               1041
#define CC_UERROR_MISSING_PARAM                  1042

#define CC_NODE_NOT_FOUND                        1050
#define CC_ENGINE_TIMEOUT                        1051
#define CC_SS7_TIMEOUT                           1052
#define CC_ESME_TIMEOUT                          1053
#define CC_ESME_NOT_CONNECTED                    1054
#define CC_ESME_TEMPARARY_ERR                    1055
#define CC_ESME_PERMANENT_ERR                    1056
#define CC_ESME_REJECT                           1057
#define CC_ESME_OTHER_ERROR                      1058

#define CC_NO_ROUTE_CANC                         1070
#define CC_ADMIN_CANC                            1071
#define CC_SOURCE_CANC                           1072
#define CC_ADMIN_BARRED                          1073

#define CC_ACN_ERROR                             1080
#define CC_UNREGISTERED_NODE                     1081

#define CC_LOCAL_ERROR                           1090
#define CC_NPS_PORTED_OUT                        1091
#define CC_NPS_RD_KTFMSISDN_MISMATCH             1092
#define CC_NPS_OTHER_RD_IN_KTF                   1093
#define CC_GCS_SERVICE_SENT                      1094  /* GCS Service    */
#define CC_2N2_SERVICE_SENT                      1095  /* Two-Number-Two */
#define CC_GCS_SERVICE_ERROR                     1096
#define CC_2N2_SERVICE_ERROR                     1097
#define CC_LETTER_SERVICE_SENT                   1098
#define CC_LETTER_SERVICE_ERROR                  1099
#define CC_OTHER_SERVICE_SENT                    1100
#define CC_MSGMANAGER_BLOCK                      1101 
#define CC_SCP_FNS_NOTFOUND                      1102 
#define CC_UNKNOWN                               1103
/* 05/09/08 sjkim add : for SECRET_SVC */
#define CC_SECRET_SERVICE_SENT                   1104
#define CC_SECRET_SERVICE_ERROR					 1105

/* 05/10/04 sjkim : invalid SMSC routing */
#define CC_SMSC_MISMATCH						 1106

/* 06/01/17 sjkim : R.I */
#define CC_OUTBOUND_ROAMING						 1107
/* 06/03/31 sjlee : for SCP RESULT */
#define CC_SCP_PAUSE  							 1108
#define CC_SCP_INTERCEPTION    				     1109
#define CC_2PHONE_SENT							 1110
#define CC_2PHONE_ERROR							 1111
#define CC_RETRY_ACTION_DISCARD	 			     1112
#define CC_UDHI_DUPLICATION_DISCARD	 			 1113
/* 08/06/30 v360 sjlee:call forward */
#define CC_CALL_FORWARD_SENT					 1114
#define CC_CALL_FORWARD_ERROR	     			 1115
#define CC_CALL_FORWARD_SOURCE_CANC    			 1116
#define CC_DB_POOL_SIZE_OVER    			 	 1117

/* Diameter Cause code */
#define CC_DIAMETER_ROUND_AUTH                   1120
#define CC_DIAMETER_PROTOCOL_ERR                 1121
#define CC_DIAMETER_UNABLE_TO_DELIVER            1122
#define CC_DIAMETER_REALM_NOT_SERVED             1123
#define CC_DIAMETER_TOO_BUSY                     1124
#define CC_DIAMETER_LOOP_DETECTED                1125
#define CC_DIAMETER_REDIRECT_INDICATION          1126
#define CC_DIAMETER_APPLICATION_UNSUPPORTED      1127
#define CC_DIAMETER_INVALID_HDR_BITS             1128
#define CC_DIAMETER_INVALID_AVP_BITS             1129
#define CC_DIAMETER_UNKNOWN_PEER                 1130
#define CC_DIAMETER_AUTHENTICATION_REJECTED      1131
#define CC_DIAMETER_OUT_OF_SPACE                 1132
#define CC_DIAMETER_ELECTION_LOST                1133
#define CC_DIAMETER_END_USER_SERVICE_DENIED      1134
#define CC_DIAMETER_ERROR_USER_UNKNOWN           1135
#define CC_DIAMETER_UNKNOWN_SESSION_ID           1136
#define CC_DIAMETER_AUTHORIZATION_REJECTED       1137
#define CC_DIAMETER_INVALID_AVP_VALUE            1138
#define CC_DIAMETER_MISSING_AVP                  1139
#define CC_DIAMETER_RESOURCES_EXCEEDED           1140
#define CC_DIAMETER_CONTRADICTING_AVPS           1141
#define CC_DIAMETER_AVP_NOT_ALLOWED              1142
#define CC_DIAMETER_NO_COMMON_APPLICATION        1143
#define CC_DIAMETER_UNSUPPORTED_VERSION          1144
#define CC_DIAMETER_UNABLE_TO_COMPLY             1145
#define CC_DIAMETER_INVALID_BIT_IN_HEADER        1146
#define CC_DIAMETER_INVALID_AVP_LENGTH           1147
#define CC_DIAMETER_INVALID_MESSAGE_LENGTH       1148
#define CC_DIAMETER_INVALID_AVP_BIT_COMBO        1149
#define CC_DIAMETER_NO_COMMON_SECURITY           1150

/* 3GPP 29.338 Defined */
#define CC_DIAMETER_USER_UNKNOWN                 1160
#define CC_DIAMETER_ERROR_ABSENT_USER            1161
#define CC_DIAMETER_ERROR_USER_BUSY_FOR_MT_SMS   1162
#define CC_DIAMETER_ERROR_FACILITY_NOT_SUPPORTED 1163
#define CC_DIAMETER_ERROR_ILLEGAL_USER           1164
#define CC_DIAMETER_ERROR_ILLEGAL_EQUIPMENT      1165
#define CC_DIAMETER_ERROR_SM_DELIVERY_FAILURE    1166
#define CC_DIAMETER_ERROR_SERVICE_NOT_SUBSCRIBE  1167
#define CC_DIAMETER_ERROR_SERVICE_BARRED         1168
#define CC_DIAMETER_ERROR_MWD_LIST_FULL          1169
#define CC_DIAMETER_COMMAND_UNSUPPORTED          1170
/* 3GPP End */
#define CC_DIAMETER_INTERNAL_ERROR               1180
#define CC_DIAMETER_TIMEOUT                      1181
#define CC_DIAMETER_PEER_DISCONNECTED            1182
#define CC_DIAMETER_TRANSIENT_ERROR              1183
#define CC_DIAMETER_PERIMENTAL_ERROR             1184
#define CC_DIAMETER_EXPERIMENTAL_ERROR           1185
/* Diameter End */
#define CC_UDL_LENGTH_OVER_DISCARD   		 	 1191

/* v560 by Nersion. SME_AUTH_FAIL */
#define CC_RP_UNASSIGNED_NUMBER                  1215
#define CC_RP_OPERATOR_DETERMINED_BARRING        1216
#define CC_RP_CALL_BARRED                        1217
#define CC_RP_RESERVED                           1218
#define CC_RP_SM_TRANSFER_REJECTED               1219
#define CC_RP_MEMORY_CAPACITY_EXCEEDED           1220
#define CC_RP_DESTINATION_OUT_OF_ORDER           1221
#define CC_RP_UNIDENTIFIED_SUBSCRIBER            1222
#define CC_RP_FACILITY_REJECTED                  1223
#define CC_RP_UNKNOWN_SUBSCRIBER                 1224
#define CC_RP_NETWORK_OUT_OF_ORDER               1225
#define CC_RP_TEMPORARY_FAILURE                  1226
#define CC_RP_CONGESTION                         1227
#define CC_RP_RESOURCES_UNAVAILABLE              1228
#define CC_RP_REQUESTED_FACILITY_NOT_SUBSCRIBE   1229
#define CC_RP_REQUESTED_FACILITY_NOT_IMPLEMENTED 1230
#define CC_RP_INVALID_SM_TRANSFER_REF_VALUE      1231
#define CC_RP_SEMANTICALLY_INCORRECT_MESSAGE     1232
#define CC_RP_INVALID_MANDATORY_INFORMATION      1233
#define CC_RP_MESSAGE_TYPE_NON_EXISTENT          1234
#define CC_RP_MESSAGE_NOT_COMPATIBLE             1235
#define CC_RP_INFO_ELEMENT_NON_EXISTENT          1236
#define CC_RP_PROTOCOL_ERROR_UNSPECIFIED         1237
#define CC_RP_INTERWORKING_UNSPECIFIED           1238


//smpp lastfailreReason mapping causecode
//Local Error은 256을 넘을 수 없음 SMPP 매핑용으로 따로 하나 더 만들어서 사용함.
#define CC_NOTI_REQ_FOR_UE_DISCARD_MAPPING		 1256 	
#define CC_CALL_DIRECTION_OUTBOUND_ROAMING		 1257	//1257 -> 1212
#define CC_CALL_DIRECTION_RETRY_ACTION_REQ		 1258	//1258 -> 1213
#define CC_SMPP_MAPPING_PAD_CANC                 1260   /*added for v460 PAD terminal*/
#define CC_SMPP_MAPPING_UDL_OVER                 1261   /*added for v470 UDL OVER*/
#define CC_SMPP_MAPPING_SME_AUTH_FAIL			 1262   /*added for v560 SME_AUTH_FAIL by Nersion. 일단 가칭으로.. */
//end smpp lastfailreReason mapping causecode

//2G CC [2000 ~ 2255]----------------------------------------------------------
#define CC_ADDRESS_VACANT                        2000
#define CC_ADDR_TRANS_FAILURE                    2001
#define CC_NW_RESOURCE_SHORTAGE                  2002
#define CC_NETWORK_FAILURE                       2003
#define CC_INVAILD_TELESERVICEID                 2004

#define CC_OTHER_NETWORK_PROBLEM                 2005
#define CC_NO_PAGE_RESPONSE                      2032
#define CC_DESTINATION_BUSY                      2033
#define CC_NO_ACKMOWLEDGEMENT                    2034
#define CC_DEST_RESOURCE_SHORTAGE                2035

#define CC_SMS_DELIVERY_POSTPHONE                2036
#define CC_DEST_OUT_OF_SERVICE                   2037
#define CC_DESTINATION_NO_LONGER                 2038
#define CC_OTHER_TERMINAL_PROBLEM                2039
#define CC_RADIO_IF_RESOURCE_SHORT               2064

#define CC_RADIO_IF_INCOMPATIBILITY              2065
#define CC_OTHER_RADIO_IF_PROBLEM                2066
#define CC_INCODING_PROBLEM                      2096
#define CC_SMS_ORIGINATION_DENIED                2097
#define CC_SMS_TERMINATION_DENIED                2098	/* 20 */

#define CC_SUPPL_SVC_NOT_SUPPORTED               2099
#define CC_SMS_NOT_SUPPORTED                     2100
#define CC_MISSING_EXPECTED_PARA                 2102
#define CC_MISSING_MANDATORY_PARA                2103
#define CC_UNRECOGNIZED_PARA_VALUE               2104

#define CC_UNEXPECTED_PARA_VALUE                 2105
#define CC_USER_DATA_SIZE_ERROR                  2106
#define CC_OTHER_GENERAL_PROBLEM                 2107
#define CC_2G_USER_DATA_SIZE_EXCEED              2191 /* Added for v302 */
#define CC_ADR_DENIED                            2201
#define CC_ADR_POSTPHONE                         2202

#define CC_ADR_UNAVAILABLE                       2203
#define CC_2PHONE_SUBSCRIBER                     2204 /* Two-Phone Service */
#define CC_2PHONE_REGISTRE_ERROR                 2205 /* Two-Phone Service */
#define CC_S2PHONE_ERROR						 2211 /* Smart-2Phone Service v570 by Nersion. */
#define CC_CDMA_ADR_SPAM						 2252 /* SPAM Denied */
#define CC_CDMA_HLR_PORTED_OUT                   2253 /* 33 */
#define CC_UERROR_UNRECOG_MIN_FOR_CDMA           2254 /* WARNS!!! use this for CDMA CC */


//3G CC  [3000 ~ 3255] -------------------------------------------------------- 
#define CC_UNKNOWN_SUBSCRIBER                    3001
#define CC_UNIDENTIFIED_SUBSCRIBER               3005
#define CC_ABSENT_SUBSCRIBER_SM                  3006
#define CC_ILLEGAL_SUBSCRIBER                    3009
#define CC_TELESERVICE_NOT_PROVISIONED           3011
#define CC_ILLEGALEQUIPMENT                      3012

#define CC_CALL_BARRED                           3013
#define CC_FORWARDING_VIOLATION 				 3014 
#define CC_FACILITY_NOT_SUPPORTED                3021
#define CC_ABSENT_SUBSCRIBER                     3027
#define CC_INCOMPATIBLE_TERMINAL                 3028
#define CC_SUBSCRIBER_BUSY_FOR_MT_SMS            3031

#define CC_SM_DELIVERY_FAILURE                   3032
#define CC_MESSAGE_WAITING_LIST_FULL             3033
#define CC_SYSTEM_FAILURE                        3034
#define CC_DATA_MISSING                          3035
#define CC_UNEXPECTED_DATA_VALUE                 3036

#define CC_BUSY_SUBSCRIBER                       3045
#define CC_NO_SUBSCRIBER_REPLY                   3046
#define CC_RESOURCE_LIMITATION                   3051
#define CC_UNKNOWN_ALPHABET                      3071
#define CC_GSM_HLR_PORTED_OUT                    3090  /* 19 */
#define CC_GSM_ADR_SPAM							 3091  /* 20 */

/* Call Barred Service */
#define CC_HLR_BARRED_SNBD1			             3092  /* 정보제공사업자수신차단 */
#define CC_HLR_BARRED_SNBD2 		             3093  /* M-RBL 수신 차단 */
#define CC_HLR_BARRED_SND 			             3094  /* 특정번호서비스 수신 차단 */

/* Absent Subscriber */
#define CC_HLR_ABSENT_SUBSCRIBER_SM              3099
#define CC_HLR_NPR_MSC                           3100
#define CC_HLR_IMSI_DETACHED                     3101    /* Power Off */
#define CC_HLR_ROAM_RESTRICTION                  3102
#define CC_HLR_DEREGISTERED_NON_GPRS             3103
#define CC_HLR_MS_PURGED_NON_GPRS                3104
#define CC_HLR_NPR_SGSN                          3105
#define CC_HLR_GPRS_DETACHED                     3106
#define CC_HLR_DEREGISTERED_GPRS                 3107
#define CC_HLR_MS_PURGED_GPRS                    3108
#define CC_HLR_UNIDENTIFIED_SUB_MSC              3109
#define CC_HLR_UNIDENTIFIED_SUB_SGSN             3110


#define CC_NPR3G_CS                              3170
#define CC_IMSI_DETACHED                         3171
#define CC_ROAM_RESTRICTION                      3172
#define CC_DEREGISTED_NON_GPRS                   3173
#define CC_PURGED_NON_GPRS                       3174
#define CC_NPR3G_PS                              3175
#define CC_GPRS_DETACHED                         3176
#define CC_DEREGISTED_GPRS                       3177
#define CC_PURGED_GPRS                           3178
#define CC_UNIDENTIFIED_CS                       3179
#define CC_UNIDENTIFIED_PS                       3180

#define CC_MCEF                                  3210
#define CC_PROTOCOL_ERR                          3211
#define CC_NOT_SM_EQUIPPED                       3212
#define CC_UNKNOWN_SC                            3213
#define CC_SC_CONGESTION                         3214
#define CC_INVALID_SME_ADDR                      3215
#define CC_NOT_SC_SUBSCRIBER                     3216

#endif /* _CAUSE_CODE_H_INCLUDE_ */
