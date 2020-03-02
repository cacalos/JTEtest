
#ifndef _SS7_IX7MAP_H_
#define _SS7_IX7MAP_H_

#ifndef USIGTRAN
#include <TCAP_ext.h>
#endif

#define NETWORK_NODE_0_PCNT          0
#define NETWORK_NODE_25_PCNT         25
#define NETWORK_NODE_50_PCNT         50
#define NETWORK_NODE_75_PCNT         75 
#define NETWORK_NODE_100_PCNT        100

#define NETWORK_NODE_ON              NETWORK_NODE_100_PCNT
#define NETWORK_NODE_CONG            NETWORK_NODE_0_PCNT
#define NETWORK_NODE_OFF             NETWORK_NODE_0_PCNT

/* Parameter Sequence Tag */
#define NO_TAG                       0x00
#define SEQ_TAG                      0x30
#define SET_TAG                      0x31

/* Operation Code for 2G */
#define MAP_OP_SMSDPP               0x35
#define MAP_OP_SMSNOT               0x36
#define MAP_OP_SMSREQ               0x37
#define	MAP_OP_AlertSvcCenter		64	
#define	MAP_OP_MoFwdSM				46	
#define	MAP_OP_MtFwdSM				44	
#define	MAP_OP_ReportSM				47	
#define	MAP_OP_InformSvcCenter		63	
#define	MAP_OP_ReadyForSM			66	
#define	MAP_OP_FwdSM				46	
#define	MAP_OP_SRIforSM				45	
#define	MAP_OP_AnyTimeModification  65 //added by Charge

/* application_id */
#define APPLICATION_ID_SRI           1
#define APPLICATION_ID_REQ           1
#define APPLICATION_ID_MTF           1
#define APPLICATION_ID_DPP           1
#define APPLICATION_ID_IN            1
#define APPLICATION_ID_SMGS          1
#define APPLICATION_ID_ALARM         1 //added by cjy

/* instance_id */
#define INSTANCE_ID_SRI              1
#define INSTANCE_ID_REQ              2
#define INSTANCE_ID_MTF              3
#define INSTANCE_ID_DPP              4
#define INSTANCE_ID_IN               5
#define INSTANCE_ID_SMGS             6
#define INSTANCE_ID_ALARM            7 //added by cjy
#define INSTANCE_ID_OTHER_SSN		 8 //added by ksj


/* sjkim : KTF ssn info(use for message incomming at dispatcher) */
#define KTF_CDMA_SSN				 11
#define KTF_WCDMA_SSN				  8


/* Invoke ID 값 정의 */
#define INVOKE_ID_SRI                1
#define INVOKE_ID_REQ                1
#define INVOKE_ID_MTF                1
#define INVOKE_ID_MOF                1
#define INVOKE_ID_DPP                1
#define INVOKE_ID_SMGS               1

/* Operation Code 길이 */
#define OPCODE_LEN_SRI               1
#define OPCODE_LEN_REPORT            1
#define OPCODE_LEN_INFORM            1
#define OPCODE_LEN_MTF               1
#define OPCODE_LEN_MO                1
#define OPCODE_LEN_ALERT             1
#define OPCODE_LEN_REQ               1
#define OPCODE_LEN_DPP               1

#define UNSUPPORTED_ACN_VERSION      MAP_VERSION_1

#define IS_ACN_NOT_SET               0x00
#define IS_ACN_FAIL                  0xFF

#define ACN_GW                       0x10
#define ACN_MT                       0x20
#define ACN_MO                       0x30
#define ACN_ALERT                    0x40
#define ACN_ATM                      0x50 //added by Charge

#define ACN_V1                       0x01
#define ACN_V2                       0x02
#define ACN_V3                       0x03

#define ACN_GW_V1                    0x11
#define ACN_MT_V1                    0x21
#define ACN_MO_V1                    0x31
#define ACN_ALERT_V1                 0x41
#define ACN_GW_V2                    0x12
#define ACN_MT_V2                    0x22
#define ACN_MO_V2                    0x32
#define ACN_ALERT_V2                 0x42
#define ACN_GW_V3                    0x13
#define ACN_MT_V3                    0x23
#define ACN_MO_V3                    0x33
#define ACN_READY_V3                 0X41
#define ACN_ATM_V3                   0X51 //added by Charge

/* MAP Parameter  정의 */
#define PARAM_BUFFER_SIZE            1024

/* TCAP Connection Open Error시 재 Open 시도하기 전 Sleep하는 시간 */
#define OPEN_ERROR_SLEEP             1

#endif     /* _SS7_IX7MAP_H_ */

