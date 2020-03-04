#ifndef _IX_TYPES_INCLUDED
#define _IX_TYPES_INCLUDED

#include <ua_syslib.h>
#include <time.h>


#define IXOK		 			1
#define NOTOK 					0
#define IXERR 					-1

#define IXFALSE                  0
#define IXTRUE                   1

#define ONE_CHAR_LEN             1
#define TWO_SHORT_LEN            2
#define FOUR_INT_LEN             4

#define DEFAULT_ADDR_LEN         24
#define DEFAULT_NAME_LEN         20                    /* Node Name */
#define DEFAULT_ISDN_LEN         DEFAULT_ADDR_LEN
#define DEFAULT_PCODE_LEN        FOUR_INT_LEN          /* Point Code */
#define DEFAULT_SSN_LEN          ONE_CHAR_LEN          /* SubSystem Number */
#define DEFAULT_DESC_LEN         30                    /* Description */
#define DEFAULT_NAME_LEN         20                    /* Node Name */
#define DEFAULT_PREFIX_LEN       DEFAULT_ADDR_LEN      /* Prefix Length */
#define DEFAULT_MIN_LEN          10                    /* for MIN */
#define DEFAULT_CB_LEN           26                 /*   20 -> 26 */
#define DEFAULT_IPADDR_LEN       15
#define DEFAULT_MIN_ADDR_LEN     1                     /* 1 digits at least */

#define DEFAULT_ISDN_ARR         256
#define DEFAULT_ESME_ARR         512

#define DEFAULT_DIA_HOST         64
#define DEFAULT_DIA_REALM        64
#define DIA_ISDN_SIZE			 DEFAULT_ISDN_LEN+1

#define DEFAULT_AMFID_LEN		 64

#define DEFAULT_PREFIX_ARR       1000

#define Q_WRONG                 -2

#define MSG_MTYPE_NORMAL            1
#define MSGQUEUE_INIT_VALUE		   -1
#define MSGSEND_MAX_RETRY			3

#define DEFAULT_BURST_VALUE			50

/* momt */
#define MOMT_MO_MSG                        0
#define MOMT_MT_MSG                        1
#define MOMT_OTHER_MSG                     2

/* encode */
#define ENCODE_UNKNOWN                     0
#define ENCODE_7BIT_ASCII                  1
#define ENCODE_7BIT_GSM                    2
#define ENCODE_UCS2                        3
#define ENCODE_8BIT                        4
#define ENCODE_KSC5601                     5
#define ENCODE_USIM                        6
#define ENCODE_UCS2_UNCOMP                 7
#define ENCODE_IA5                         8
#define ENCODE_FOREIGN                     9

#define DEFAULT_ASN1CHOP_SIZE   300

/* information element tag */
#define ELEMENT_CONCAT_8BIT_REF            0x00
#define ELEMENT_SPECIAL_SMS_INDI           0x01
#define ELEMENT_VALUE_NOT_USED             0x03
#define ELEMENT_APP_PORT_ADDR_8BIT         0x04
#define ELEMENT_APP_PORT_ADDR_16BIT        0x05
#define ELEMENT_SMSC_CONTROL_PARAM         0x06
#define ELEMENT_UDH_SOURCE_INDI            0x07
#define ELEMENT_CONCAT_16BIT_REF           0x08
#define ELEMENT_WIRELESS_CONTROL           0x09
#define ELEMENT_TEXT_FORMATTING            0x0A
#define ELEMENT_PREDEFINED_SOUND           0x0B
#define ELEMENT_USER_DEFINED_SOUND         0x0C
#define ELEMENT_PREDEFINED_ANIMATION       0x0D
#define ELEMENT_LARGE_ANIMATION            0x0E
#define ELEMENT_SMALL_ANIMATION            0x0F
#define ELEMENT_LARGE_PICTURE              0x10
#define ELEMENT_SMALL_PICTURE              0x11
#define ELEMENT_VARIABLE_PICTURE           0x12
#define ELEMENT_RFC822_EMAIL_HEADER        0x20
#define ELEMENT_REPLY_ADDRESS              0x22
#define ELEMENT_SPECIAL_ENCODING           0xFC
#define ELEMENT_CALLBACK_NUMBER            0x50
#define ELEMENT_HNET_SESSION_INFO          0x60
#define ELEMENT_HNET_RESPONSE_TYPE         0x61
#define ELEMENT_HNET_REPLY_OPT             0x62
#define ELEMENT_HNET_RESPONSE_CODE         0x63
#define ELEMENT_KT_SERVICE_CODE            0xC0 
#define ELEMENT_READ_CONFIRM_SVC           0x44
#define ELEMENT_USIM_DOWN_START            0x70
#define ELEMENT_USIM_DOWN_END              0x7F

#define DUALACT_MESG_LOCAL    0x01
#define DUALACT_MESG_OTHER    0x02

/* country code */
#define COUNTRY_CODE_KOREA      "82"
#define COUNTRY_CODE_ADD         0
#define COUNTRY_CODE_TRIM        1

#define TON_UNKNOWN				 0
#define TON_INTERNATIONAL        1
#define TON_NATIONAL             2
#define TON_NETWORK              3
#define TON_SUBSCRIBER           4  
#define TON_ALPHA_NUMERIC        5
#define TON_ABBREVIATED          6  /*  SMCI 규격 참조 (3.1.2) */
/* Local define */
#define TON_IMSI 				 10
#define TON_MSID_MIN             18  /* MIN,  호처리 관련없음 */
#define TON_MSID_IMSI            19  /* IMSI, 호처리 관련없음 */
//#define TON_SVC_SECRET             23  /* Secret, need NOTI */
#define TON_STATUS_REPORT        30  /* v600, status report msg. by Raon */
#define TON_DEVICE_REPORT        32
#define TON_DEVICE_REPORT_IMSI   33
#define TON_SVC_END              34  /* last */
#define TON_ALL                  255

#define NPI_UNKNOWN              0
#define NPI_E164                 1
#define NPI_X121                 3   /*  KTF Specific           */
#define NPI_F69                  4   /*  <--                    */
#define NPI_E212                 6   /*  <--                    */
#define NPI_NATIONAL             8   /*  <--                    */
#define NPI_PRIVATE              9   /*  SMCI 규격 참조 (3.1.2) */
/* Local define */
#define NPI_IMSI 				 10
#define NPI_STATUS_REPORT        30      /* v600, status report msg. by Raon */
#define NPI_DEVICE_REPORT        32
#define NPI_DEVICE_REPORT_IMSI   33
#define NPI_SVC_END              34      /* last */
#define NPI_ALL                  255

#define NODE_UNKNOWN                 0
#define NODE_HLR                     1
#define NODE_SMSC                    2
#define NODE_INBH                    3
#define NODE_MSC                     4
#define NODE_SGSN                    6
#define NODE_ESME                    9
#define NODE_LOCAL                   10
#define NODE_ABNORMAL                11
#define NODE_IPMG                    12 //v510
#define NODE_IPSMGW                  13 //v600 by Nersion. (이거 추가해도 영향도 없는지 check)
#define NODE_MME                     14
#define NODE_GROUP                   15

#define ROUTE_PC                 0
#define ROUTE_SYSTEM_GT          1
#define ROUTE_MSISDN_GT          2
#define ROUTE_IMSI_GT            3

/* map version */
#define MAP_VERSION_N                      -1
#define MAP_VERSION_0                      0
#define MAP_VERSION_1                      1
#define MAP_VERSION_2                      2
#define MAP_VERSION_3                      3

/* SMPP version*/
#define CNX_Q_SMPP_VER_3            0x33
#define CNX_Q_SMPP_VER_4            0x34

/* Added by sjlee 2006-08-31 v260: NETWORK TYPE */
#define NETWORK_CDMA  2
#define NETWORK_WCDMA 3
#define NETWORK_IPMG  4

#define ERROR_STATE_INIT         0
#define ERROR_STATE_NORMAL       1
#define ERROR_STATE_ERROR        2

#define MTYPE_RESP      100
#define MTYPE_MT        101

typedef unsigned char   uint8_t;

typedef struct _stAddr {
	char      min[DEFAULT_ADDR_LEN+1];  /* Address                      */
	char      ton;                      /* Type of Number               */
	char      npi;                      /* Numbering Plan Indicator     */
	char      len;                      /* addr length                  */
} stAddr;


typedef struct _stNodeNumber {
	int                   pCode;
	unsigned char         ssn;
	unsigned char         nodeType;
	char                  isdn[DEFAULT_ISDN_LEN+1];
} stNodeNumber; /* 28 B */

/* Function Definition */
unsigned char GetEncodeFromDcs(unsigned char dcs);
int Conv7BitASCto7BitGSM2(char *origData, unsigned char origDataLen, char *convData, short *newDataLen);
int Conv7BitASCto7BitGSM(char *origData, unsigned char origDataLen, char *newData, unsigned char *newDataLen);
int MakeRPDU(char msgType, char direction, int cc, stAddr *addr, char *tpdu, int tpdu_len, unsigned char refNo,
        int *rpdu_len, char *rpdu_data);
int ConvRpErrToCauseCode(unsigned char rpErrCode);

#endif
