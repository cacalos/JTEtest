
#ifndef _SS7_MAP2_H_INCLUDED_
#define _SS7_MAP2_H_INCLUDED_

#ifndef USIGTRAN
#include <TCAP_common.h>
#endif

#define MAX_BD_LEN                   200

#define SMS_ADDR_PC                  1
#define SMS_ADDR_ISDN                2

#ifndef MAX_PARAMETER_LEN
#define MAX_PARAMETER_LEN 			240
#endif

typedef struct _stOnePara {
    int                 tagCode;   /* Only support until 4-length tag code */
    int                 paraLen;
    unsigned char       paraData[MAX_PARAMETER_LEN];
} stOnePara;

/* encdMthd */
#define ENCD_OCTET                       0
#define ENCD_UNSPECIFIED                 0
#define ENCD_IS_95_EXT                   1
#define ENCD_ASC_7_BIT                   2
#define ENCD_IA5                         3
#define ENCD_KSC_5601                    16

/* Type of Digit */
#define TYPE_OF_DIGIT_NOT				0X00
#define TYPE_OF_DIGIT_CALLED			0X01
#define TYPE_OF_DIGIT_CALLING			0x02
#define TYPE_OF_DIGIT_CINT				0x03
#define TYPE_OF_DIGIT_ROUTING			0x04
#define TYPE_OF_DIGIT_BILLING			0x05
#define TYPE_OF_DIGIT_DEST				0x06
#define TYPE_OF_DIGIT_LATA				0x07

/* Encoding */
#define ENCODING_NOT					0x00
#define ENCODING_BCD					0X01
#define ENCODING_IA5					0x02
#define ENCODING_OCTET					0x03

/* Numbering Plan */
#define NUM_PLAN_NOT					0x00
#define NUM_PLAN_ISDN					0X10
#define NUM_PLAN_E164					0X20

/* SMSRequest Operation */
#define tag_MIN                      0x000088
#define tag_ESN                      0x000089
#define tag_NOTIND                   0x009f6d
/* added by twkim 2003.08.07 ver 0.1.0     */
#define tag_MDN						 0x009f5d
#define tag_IMSI                     0x9f8172
/* added by twkim 2003.05.22 ver 0.0.7     */
#define tag_CAPABILITY				 0x9fff8f
#define tag_new_CAPABILITY			 0x9fff3f
/* added by sjkim 2005.03.30 ver 2.0.1(KTF SPAM) */
#define tag_CPND1                    0x009f50

/* SMDeliveryPointtoPoint Operation */
#define tag_BEARERDATA               0x009f69
#define tag_TELESERVICEID            0x009f74
#define tag_CHARGEIND                0x009f6a
#define tag_DESTADDR                 0x009f6b
#define tag_MESSAGECOUNT             0x009f6c
#define tag_ORIGDESTADDR             0x009f6e
#define tag_ORIGDESTSUBADDR          0x009f6f
#define tag_ORIGORIGADDR             0x009f70
#define tag_ORIGORIGSUBADDR          0x009f71
#define tag_ORIGADDR                 0x009f72
#define tag_CAUSECODE                0x9f8119
#define tag_NUMPORTABILITYINFO       0x9fff08
#define tag_PROFILE                  0x9fff40
#define tag_INTELLIGENTSUBINDI       0x9fff5d
#define tag_FWDREQADDR               0x9fff7f


/* SMSNotification Operation */
#define tag_ADENIEDREASON            0x9f8118
#define tag_SMSADDRESS               0x009f68
#define tag_NOTIMDN                  0x009f5d

/* Common Operation */
#define tag_SERVICEINDICATOR         0x9f8141


/* SMSDPP Operation */
#define tagLen_BEARERDATA            2
#define tagLen_TELESERVICEID         2
#define tagLen_CHARGEIND             2
#define tagLen_DESTADDR              2
#define tagLen_MESSAGECOUNT          2
#define tagLen_ORIGDESTADDR          2
#define tagLen_ORIGDESTSUBADDR       2
#define tagLen_ORIGORIGADDR          2
#define tagLen_ORIGORIGSUBADDR       2
#define tagLen_ORIGADDR              2
#define tagLen_CAUSECODE             3
#define tagLen_ADENIEDREASON         3
#define tagLen_SMSADDRESS            2
#define tagLen_PROFILE               3

/* SMSDPP */
#define tag_BEARERDATA_one           0x9f
#define tag_BEARERDATA_two           0x69

#define tag_TELESERVICEID_one        0x9f
#define tag_TELESERVICEID_two        0x74

#define tag_CHARGEIND_one            0x9f
#define tag_CHARGEIND_two            0x6a

#define tag_DESTADDR_one             0x9f
#define tag_DESTADDR_two             0x6b

#define tag_MESSAGECOUNT_one         0x9f
#define tag_MESSAGECOUNT_two         0x6c

#define tag_ORIGDESTADDR_one         0x9e
#define tag_ORIGDESTADDR_two         0x6e

#define tag_ORIGDESTSUBADDR_one      0x9f
#define tag_ORIGDESTSUBADDR_two      0x6f

#define tag_ORIGORIGADDR_one         0x9f
#define tag_ORIGORIGADDR_two         0x70

#define tag_ORIGORIGSUBADDR_one      0x9f
#define tag_ORIGORIGSUBADDR_two      0x71

#define tag_ORIGADDR_one             0x9f
#define tag_ORIGADDR_two             0x72

#define tag_CAUSECODE_one            0x9f
#define tag_CAUSECODE_two            0x81
#define tag_CAUSECODE_thr            0x19

#define tag_NUMPORTABILITYINFO_one   0x9f
#define tag_NUMPORTABILITYINFO_two   0xff
#define tag_NUMPORTABILITYINFO_thr   0x08

#define tag_PROFILE_one              0x9f
#define tag_PROFILE_two              0xff
#define tag_PROFILE_thr              0x40

#define tag_INTELLIGENTSUBINDI_one   0x9f
#define tag_INTELLIGENTSUBINDI_two   0xff
#define tag_INTELLIGENTSUBINDI_thr   0x5d

#define tag_FWDREQADDR_one           0x9f
#define tag_FWDREQADDR_two           0xff
#define tag_FWDREQADDR_thr           0x7f

/* SMS REQ */
#define tag_NOTIND_one               0x9f
#define tag_NOTIND_two               0x6d

/* added by twkim 2003.08.07 ver 0.1.0     */
#define tag_MDN_one					 0x9f
#define tag_MDN_two					 0x5d

/* sjkim add */
#define tag_CPND1_one				 0x9f
#define tag_CPND1_two				 0x50

/* IMSI */
#define tag_IMSI_one                 0x9f
#define tag_IMSI_two                 0x81
#define tag_IMSI_thr                 0x72

/* SMS NOTI */
#define tag_ACCDENY_one              0x9f
#define tag_ACCDENY_two              0x81
#define tag_ACCDENY_thr              0x18

#define tag_SMSADDR_one              0x9f
#define tag_SMSADDR_two              0x68

/* Common */
#define tag_SERVICEINDICATOR_one     0x9f
#define tag_SERVICEINDICATOR_two     0x81
#define tag_SERVICEINDICATOR_thr     0x41

/*  TCAP RETURN ERROR (Faulty parameter) */
#define tag_FAULTY_PARA              0x9A

/*  TCAP RETURN ERROR Component, Codes */
#define RESOURCE_SHORTAGE            0x85
#define OP_NOT_SUPPORTED             0x86
#define PARAMETER_ERROR              0x88
#define PARA_VAL_ERR                 0x8A
#define MISSING_PARA                 0x8C


#define MAX_BEARER_LEN                     255

#define MAP_PARAM_NONE                     0
#define MAP_PARAM_BD                       1
#define MAP_PARAM_TID                      2
#define MAP_PARAM_ESN                      3
#define MAP_PARAM_MIN                      4
#define MAP_PARAM_CHARGE_IND               5
#define MAP_PARAM_DA                       6
#define MAP_PARAM_MSG_CNT                  7
#define MAP_PARAM_NOTI_IND                 8
#define MAP_PARAM_ODA                      9
#define MAP_PARAM_ODSUBA                   10
#define MAP_PARAM_OOA                      11
#define MAP_PARAM_OOSUBA                   12
#define MAP_PARAM_OA                       13
#define MAP_PARAM_ADDR_ADR                 14
#define MAP_PARAM_CC                       15
#define MAP_PARAM_MDN					   16
#define MAP_PARAM_PROFILE                  17

#define ERR_NO_PARAM                      -50000
#define ERR_INVALID_LONG_FORM             -50001
#define ERR_PARAM_DUPLI                   -50002
#define ERR_PARAM_NO_BD                   -50010
#define ERR_PARAM_NO_TID                  -50011
#define ERR_PARAM_NO_DST                  -50012
#define ERR_PARAM_NO_ESN                  -50013
#define ERR_PARAM_MISSING_PARAM           -50014
#define ERR_PARAM_INVALID_SEQ             -50020
#define ERR_PARAM_NOT_USED_TAG            -50021
#define ERR_PARAM_UNKNOWN_TAG             -50022
#define ERR_PARAM_INVALID_LEN             -50023
#define ERR_PARAM_INVALID_VAL             -50024
#define ERR_BD_TOO_BIG                    -50030
#define ERR_BD_INVALID_SUBPARA_SEQ        -50031
#define ERR_BD_UNKNOWN_SUBPARA_ID         -50032
#define ERR_BD_INVALID_SUBPARA_LEN        -50033
#define ERR_BD_INVALID_MSG_TYPE           -50034
#define ERR_BD_NOT_SUPPORT_VALUE          -50035
#define ERR_BD_WRONG_CHARI                -50036
#define ERR_BD_NOT_ALLOWED_ID             -50037
#define ERR_BD_INVALID_SUBPARA_VAL        -50038
#define ERR_TI_INVALID_LEN                -50040
#define ERR_ESN_INVALID_LEN               -50041
#define ERR_MIN_INVALID_LEN               -50042
#define ERR_MAP_UNKNOWN_OP                -50050
#define ERR_MAP_INVALID_COMP              -50051
#define ERR_MAP_UNKNOWN_ERR               -50099

#endif  /* _SS7_MAP2_H_INCLUDED_ */

