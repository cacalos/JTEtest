/*************************************************************/
/* Copyright (C) 2016 OSS Nokalva, Inc.  All rights reserved.*/
/*************************************************************/

/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC.
 * AND MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.
 * THIS FILE MAY NOT BE DISTRIBUTED. */

/* Generated for: UANGEL Corporation, Sungnam-shi, Korea - license 8634 for Solaris */
/* Abstract syntax: map_protocol */
/* Created: Mon May  2 19:03:56 2016 */
/* ASN.1 compiler version: 8.6.1 */
/* Runtime version is unknown */
/* Compiler operating system: Solaris 2.3 or later */
/* Compiler machine type: SPARC */
/* Target operating system: Linux with 64-bit support */
/* Target machine type: AMD64 */
/* C compiler options required: -m64 */
/* ASN.1 compiler options and file names specified:
 * -headerfile asn_smsc.h -output asn_smsc -ber -root -compat unbndbit
 * asn1dflt.linux-amd64 x880.asn Q773.asn asn_smsc_oper.asn asn_smsc.asn
 * app_context.asn map_protocol.asn
 */

#define    OSS_SOED_BER
#include   "osstype.h"
#include   "asn_smsc.h"

InvokeId noInvokeId = {
    absent_chosen, {0}
};

static ERROR _v1 = {
        errorCode_present,
        0,
        0,
        0,
        {local_chosen, {0}}
    };

#if !defined(OSS_SPARTAN_AWARE) || ((OSS_SPARTAN_AWARE + 0) < 2)
static ObjectSetEntry _v0[] = {
    {NULL, &_v1}
};
#else /* OSS_SPARTAN_AWARE >= 2 */
static ObjectSetEntry _v0[] = {
    {NULL, &_v1, NULL, NULL}
};
#endif /* !OSS_SPARTAN_AWARE || OSS_SPARTAN_AWARE < 2 */

OPERATION emptyBind = {
    synchronous_present,
    0,
    0,
    0,
    0,
    0,
    _v0,
    NULL,
    TRUE,
    0,
    0,
    0,
    {0, {0}}
};

OPERATION emptyUnbind = {
    synchronous_present,
    0,
    0,
    0,
    0,
    0,
    NULL,
    NULL,
    TRUE,
    0,
    0,
    0,
    {0, {0}}
};

ERROR refuse = {
    errorCode_present,
    0,
    0,
    0,
    {local_chosen, {0}}
};

OPERATION no_op = {
    alwaysReturns_present | operationCode_present,
    0,
    0,
    0,
    0,
    0,
    NULL,
    NULL,
    0,
    FALSE,
    0,
    0,
    {local_chosen, {0}}
};

ObjectID dialogue_as_id = {
    7,
    { 0x00, 0x11, 0x86, 0x05, 0x01, 0x01, 0x01 }
};

ObjectID uniDialogue_as_id = {
    7,
    { 0x00, 0x11, 0x86, 0x05, 0x01, 0x02, 0x01 }
};

const int maxNumOfCCBS_Requests = 5;

const int maxUSSD_StringLength = 160;

const int maxNumOfSS = 30;

const int maxNumOfBasicServiceGroups = 13;

const int maxEventSpecification = 2;

SS_Code allSS = {
    1,
    {
        0x00
    }
};

SS_Code allLineIdentificationSS = {
    1,
    {
        0x10
    }
};

SS_Code clip = {
    1,
    {
        0x11
    }
};

SS_Code clir = {
    1,
    {
        0x12
    }
};

SS_Code colp = {
    1,
    {
        0x13
    }
};

SS_Code colr = {
    1,
    {
        0x14
    }
};

SS_Code mci = {
    1,
    {
        0x15
    }
};

SS_Code allNameIdentificationSS = {
    1,
    {
        0x18
    }
};

SS_Code cnap = {
    1,
    {
        0x19
    }
};

SS_Code allForwardingSS = {
    1,
    {
        0x20
    }
};

SS_Code cfu = {
    1,
    {
        0x21
    }
};

SS_Code allCondForwardingSS = {
    1,
    {
        0x28
    }
};

SS_Code cfb = {
    1,
    {
        0x29
    }
};

SS_Code cfnry = {
    1,
    {
        0x2A
    }
};

SS_Code cfnrc = {
    1,
    {
        0x2B
    }
};

SS_Code cd = {
    1,
    {
        0x24
    }
};

SS_Code allCallOfferingSS = {
    1,
    {
        0x30
    }
};

SS_Code ect = {
    1,
    {
        0x31
    }
};

SS_Code mah = {
    1,
    {
        0x32
    }
};

SS_Code allCallCompletionSS = {
    1,
    {
        0x40
    }
};

SS_Code cw = {
    1,
    {
        0x41
    }
};

SS_Code hold = {
    1,
    {
        0x42
    }
};

SS_Code ccbs_A = {
    1,
    {
        0x43
    }
};

SS_Code ccbs_B = {
    1,
    {
        0x44
    }
};

SS_Code mc = {
    1,
    {
        0x45
    }
};

SS_Code allMultiPartySS = {
    1,
    {
        0x50
    }
};

SS_Code multiPTY = {
    1,
    {
        0x51
    }
};

SS_Code allCommunityOfInterest_SS = {
    1,
    {
        0x60
    }
};

SS_Code cug = {
    1,
    {
        0x61
    }
};

SS_Code allChargingSS = {
    1,
    {
        0x70
    }
};

SS_Code aoci = {
    1,
    {
        0x71
    }
};

SS_Code aocc = {
    1,
    {
        0x72
    }
};

SS_Code allAdditionalInfoTransferSS = {
    1,
    {
        0x80
    }
};

SS_Code uus1 = {
    1,
    {
        0x81
    }
};

SS_Code uus2 = {
    1,
    {
        0x82
    }
};

SS_Code uus3 = {
    1,
    {
        0x83
    }
};

SS_Code allBarringSS = {
    1,
    {
        0x90
    }
};

SS_Code barringOfOutgoingCalls = {
    1,
    {
        0x91
    }
};

SS_Code baoc = {
    1,
    {
        0x92
    }
};

SS_Code boic = {
    1,
    {
        0x93
    }
};

SS_Code boicExHC = {
    1,
    {
        0x94
    }
};

SS_Code barringOfIncomingCalls = {
    1,
    {
        0x99
    }
};

SS_Code baic = {
    1,
    {
        0x9A
    }
};

SS_Code bicRoam = {
    1,
    {
        0x9B
    }
};

SS_Code allPLMN_specificSS = {
    1,
    {
        0xF0
    }
};

SS_Code plmn_specificSS_1 = {
    1,
    {
        0xF1
    }
};

SS_Code plmn_specificSS_2 = {
    1,
    {
        0xF2
    }
};

SS_Code plmn_specificSS_3 = {
    1,
    {
        0xF3
    }
};

SS_Code plmn_specificSS_4 = {
    1,
    {
        0xF4
    }
};

SS_Code plmn_specificSS_5 = {
    1,
    {
        0xF5
    }
};

SS_Code plmn_specificSS_6 = {
    1,
    {
        0xF6
    }
};

SS_Code plmn_specificSS_7 = {
    1,
    {
        0xF7
    }
};

SS_Code plmn_specificSS_8 = {
    1,
    {
        0xF8
    }
};

SS_Code plmn_specificSS_9 = {
    1,
    {
        0xF9
    }
};

SS_Code plmn_specificSS_A = {
    1,
    {
        0xFA
    }
};

SS_Code plmn_specificSS_B = {
    1,
    {
        0xFB
    }
};

SS_Code plmn_specificSS_C = {
    1,
    {
        0xFC
    }
};

SS_Code plmn_specificSS_D = {
    1,
    {
        0xFD
    }
};

SS_Code plmn_specificSS_E = {
    1,
    {
        0xFE
    }
};

SS_Code plmn_specificSS_F = {
    1,
    {
        0xFF
    }
};

SS_Code allCallPrioritySS = {
    1,
    {
        0xA0
    }
};

SS_Code emlpp = {
    1,
    {
        0xA1
    }
};

SS_Code allLCSPrivacyException = {
    1,
    {
        0xB0
    }
};

SS_Code universal = {
    1,
    {
        0xB1
    }
};

SS_Code callrelated = {
    1,
    {
        0xB2
    }
};

SS_Code callunrelated = {
    1,
    {
        0xB3
    }
};

SS_Code plmnoperator = {
    1,
    {
        0xB4
    }
};

SS_Code allMOLR_SS = {
    1,
    {
        0xC0
    }
};

SS_Code basicSelfLocation = {
    1,
    {
        0xC1
    }
};

SS_Code autonomousSelfLocation = {
    1,
    {
        0xC2
    }
};

SS_Code transferToThirdParty = {
    1,
    {
        0xC3
    }
};

const int maxNumOfMobilityTriggers = 10;

const int maxNumOfCamelTDPData = 10;

const int MAP_SM_DataTypes_maxISDN_SubaddressLength = 21;

const int maxNumOfTeleservices = 20;

const int maxNumOfDP_AnalysedInfoCriteria = 10;

const int maxNumOfCAMEL_O_CauseValueCriteria = 5;

const int maxNumOfCAMEL_T_CauseValueCriteria = 5;

const int maxNumOfISDN_AddressDigits = 15;

const int maxNumOfCamelDestinationNumbers = 10;

const int maxNumOfCamelDestinationNumberLengths = 3;

const int maxNumOfCamelBasicServiceCriteria = 5;

const int maxNumOfCamelSSEvents = 10;

const int maxNumOfExt_BasicServiceGroups = 32;

const int maxAddressLength = 20;

const int maxISDN_AddressLength = 9;

const int maxFTN_AddressLength = 15;

const int MAP_CommonDataTypes_maxISDN_SubaddressLength = 21;

const int maxSignalInfoLength = 200;

AlertingPattern alertingLevel_0 = {
    1,
    {
        0x00
    }
};

AlertingPattern alertingLevel_1 = {
    1,
    {
        0x01
    }
};

AlertingPattern alertingLevel_2 = {
    1,
    {
        0x02
    }
};

AlertingPattern alertingCategory_1 = {
    1,
    {
        0x04
    }
};

AlertingPattern alertingCategory_2 = {
    1,
    {
        0x05
    }
};

AlertingPattern alertingCategory_3 = {
    1,
    {
        0x06
    }
};

AlertingPattern alertingCategory_4 = {
    1,
    {
        0x07
    }
};

AlertingPattern alertingCategory_5 = {
    1,
    {
        0x08
    }
};

const int maxNumOfHLR_Id = 50;

const EMLPP_Priority priorityLevelA = 6;

const EMLPP_Priority priorityLevelB = 5;

const EMLPP_Priority priorityLevel0 = 0;

const EMLPP_Priority priorityLevel1 = 1;

const EMLPP_Priority priorityLevel2 = 2;

const EMLPP_Priority priorityLevel3 = 3;

const EMLPP_Priority priorityLevel4 = 4;

const int maxNumOfMC_Bearers = 7;

TeleserviceCode allTeleservices = {
    1,
    {
        0x00
    }
};

TeleserviceCode allSpeechTransmissionServices = {
    1,
    {
        0x10
    }
};

TeleserviceCode telephony = {
    1,
    {
        0x11
    }
};

TeleserviceCode emergencyCalls = {
    1,
    {
        0x12
    }
};

TeleserviceCode allShortMessageServices = {
    1,
    {
        0x20
    }
};

TeleserviceCode shortMessageMT_PP = {
    1,
    {
        0x21
    }
};

TeleserviceCode shortMessageMO_PP = {
    1,
    {
        0x22
    }
};

TeleserviceCode allFacsimileTransmissionServices = {
    1,
    {
        0x60
    }
};

TeleserviceCode facsimileGroup3AndAlterSpeech = {
    1,
    {
        0x61
    }
};

TeleserviceCode automaticFacsimileGroup3 = {
    1,
    {
        0x62
    }
};

TeleserviceCode facsimileGroup4 = {
    1,
    {
        0x63
    }
};

TeleserviceCode allDataTeleservices = {
    1,
    {
        0x70
    }
};

TeleserviceCode allTeleservices_ExeptSMS = {
    1,
    {
        0x80
    }
};

TeleserviceCode allVoiceGroupCallServices = {
    1,
    {
        0x90
    }
};

TeleserviceCode voiceGroupCall = {
    1,
    {
        0x91
    }
};

TeleserviceCode voiceBroadcastCall = {
    1,
    {
        0x92
    }
};

TeleserviceCode allPLMN_specificTS = {
    1,
    {
        0xD0
    }
};

TeleserviceCode plmn_specificTS_1 = {
    1,
    {
        0xD1
    }
};

TeleserviceCode plmn_specificTS_2 = {
    1,
    {
        0xD2
    }
};

TeleserviceCode plmn_specificTS_3 = {
    1,
    {
        0xD3
    }
};

TeleserviceCode plmn_specificTS_4 = {
    1,
    {
        0xD4
    }
};

TeleserviceCode plmn_specificTS_5 = {
    1,
    {
        0xD5
    }
};

TeleserviceCode plmn_specificTS_6 = {
    1,
    {
        0xD6
    }
};

TeleserviceCode plmn_specificTS_7 = {
    1,
    {
        0xD7
    }
};

TeleserviceCode plmn_specificTS_8 = {
    1,
    {
        0xD8
    }
};

TeleserviceCode plmn_specificTS_9 = {
    1,
    {
        0xD9
    }
};

TeleserviceCode plmn_specificTS_A = {
    1,
    {
        0xDA
    }
};

TeleserviceCode plmn_specificTS_B = {
    1,
    {
        0xDB
    }
};

TeleserviceCode plmn_specificTS_C = {
    1,
    {
        0xDC
    }
};

TeleserviceCode plmn_specificTS_D = {
    1,
    {
        0xDD
    }
};

TeleserviceCode plmn_specificTS_E = {
    1,
    {
        0xDE
    }
};

TeleserviceCode plmn_specificTS_F = {
    1,
    {
        0xDF
    }
};

BearerServiceCode allBearerServices = {
    1,
    {
        0x00
    }
};

BearerServiceCode allDataCDA_Services = {
    1,
    {
        0x10
    }
};

BearerServiceCode dataCDA_300bps = {
    1,
    {
        0x11
    }
};

BearerServiceCode dataCDA_1200bps = {
    1,
    {
        0x12
    }
};

BearerServiceCode dataCDA_1200_75bps = {
    1,
    {
        0x13
    }
};

BearerServiceCode dataCDA_2400bps = {
    1,
    {
        0x14
    }
};

BearerServiceCode dataCDA_4800bps = {
    1,
    {
        0x15
    }
};

BearerServiceCode dataCDA_9600bps = {
    1,
    {
        0x16
    }
};

BearerServiceCode general_dataCDA = {
    1,
    {
        0x17
    }
};

BearerServiceCode allDataCDS_Services = {
    1,
    {
        0x18
    }
};

BearerServiceCode dataCDS_1200bps = {
    1,
    {
        0x1A
    }
};

BearerServiceCode dataCDS_2400bps = {
    1,
    {
        0x1C
    }
};

BearerServiceCode dataCDS_4800bps = {
    1,
    {
        0x1D
    }
};

BearerServiceCode dataCDS_9600bps = {
    1,
    {
        0x1E
    }
};

BearerServiceCode general_dataCDS = {
    1,
    {
        0x1F
    }
};

BearerServiceCode allPadAccessCA_Services = {
    1,
    {
        0x20
    }
};

BearerServiceCode padAccessCA_300bps = {
    1,
    {
        0x21
    }
};

BearerServiceCode padAccessCA_1200bps = {
    1,
    {
        0x22
    }
};

BearerServiceCode padAccessCA_1200_75bps = {
    1,
    {
        0x23
    }
};

BearerServiceCode padAccessCA_2400bps = {
    1,
    {
        0x24
    }
};

BearerServiceCode padAccessCA_4800bps = {
    1,
    {
        0x25
    }
};

BearerServiceCode padAccessCA_9600bps = {
    1,
    {
        0x26
    }
};

BearerServiceCode general_padAccessCA = {
    1,
    {
        0x27
    }
};

BearerServiceCode allDataPDS_Services = {
    1,
    {
        0x28
    }
};

BearerServiceCode dataPDS_2400bps = {
    1,
    {
        0x2C
    }
};

BearerServiceCode dataPDS_4800bps = {
    1,
    {
        0x2D
    }
};

BearerServiceCode dataPDS_9600bps = {
    1,
    {
        0x2E
    }
};

BearerServiceCode general_dataPDS = {
    1,
    {
        0x2F
    }
};

BearerServiceCode allAlternateSpeech_DataCDA = {
    1,
    {
        0x30
    }
};

BearerServiceCode allAlternateSpeech_DataCDS = {
    1,
    {
        0x38
    }
};

BearerServiceCode allSpeechFollowedByDataCDA = {
    1,
    {
        0x40
    }
};

BearerServiceCode allSpeechFollowedByDataCDS = {
    1,
    {
        0x48
    }
};

BearerServiceCode allDataCircuitAsynchronous = {
    1,
    {
        0x50
    }
};

BearerServiceCode allAsynchronousServices = {
    1,
    {
        0x60
    }
};

BearerServiceCode allDataCircuitSynchronous = {
    1,
    {
        0x58
    }
};

BearerServiceCode allSynchronousServices = {
    1,
    {
        0x68
    }
};

BearerServiceCode allPLMN_specificBS = {
    1,
    {
        0xD0
    }
};

BearerServiceCode plmn_specificBS_1 = {
    1,
    {
        0xD1
    }
};

BearerServiceCode plmn_specificBS_2 = {
    1,
    {
        0xD2
    }
};

BearerServiceCode plmn_specificBS_3 = {
    1,
    {
        0xD3
    }
};

BearerServiceCode plmn_specificBS_4 = {
    1,
    {
        0xD4
    }
};

BearerServiceCode plmn_specificBS_5 = {
    1,
    {
        0xD5
    }
};

BearerServiceCode plmn_specificBS_6 = {
    1,
    {
        0xD6
    }
};

BearerServiceCode plmn_specificBS_7 = {
    1,
    {
        0xD7
    }
};

BearerServiceCode plmn_specificBS_8 = {
    1,
    {
        0xD8
    }
};

BearerServiceCode plmn_specificBS_9 = {
    1,
    {
        0xD9
    }
};

BearerServiceCode plmn_specificBS_A = {
    1,
    {
        0xDA
    }
};

BearerServiceCode plmn_specificBS_B = {
    1,
    {
        0xDB
    }
};

BearerServiceCode plmn_specificBS_C = {
    1,
    {
        0xDC
    }
};

BearerServiceCode plmn_specificBS_D = {
    1,
    {
        0xDD
    }
};

BearerServiceCode plmn_specificBS_E = {
    1,
    {
        0xDE
    }
};

BearerServiceCode plmn_specificBS_F = {
    1,
    {
        0xDF
    }
};

const int maxNumOfPrivateExtensions = 10;

ObjectID ktf_origservicetype_id = {
    10,
    { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x01 }
};

MAP_EXTENSION ktf_origservicetype = {
    ExtensionType_present,
    120,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x01 }
    },
    1L
};

ObjectID ktf_destservicetype_id = {
    10,
    { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x0B }
};

MAP_EXTENSION ktf_destservicetype = {
    ExtensionType_present,
    121,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x0B }
    },
    2L
};

ObjectID ktf_extmsisdn_id = {
    10,
    { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x0F }
};

MAP_EXTENSION ktf_extmisdntype = {
    ExtensionType_present,
    122,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x0F }
    },
    3L
};

ObjectID ktf_extoriginalnum_id = {
    10,
    { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x2D }
};

MAP_EXTENSION ktf_extoriginalnumtype = {
    ExtensionType_present,
    123,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x2D }
    },
    14L
};

ObjectID ktf_showregion_id = {
    10,
    { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x1A }
};

MAP_EXTENSION ktf_showregiontype = {
    ExtensionType_present,
    124,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x1A }
    },
    4L
};

ObjectID ktf_ueindicator = {
    10,
    { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x29 }
};

MAP_EXTENSION ktf_uetype = {
    ExtensionType_present,
    125,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x29 }
    },
    5L
};

ObjectID kt_roamparty = {
    10,
    { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x03 }
};

MAP_EXTENSION ktRoamParty = {
    ExtensionType_present,
    126,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x03 }
    },
    15L
};

ObjectID kt_IpsmgwSvcInfo = {
    10,
    { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x3D }
};

MAP_EXTENSION ktIpsmgwSvcType = {
    ExtensionType_present,
    127,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x3D }
    },
    17L
};

ObjectID kt_DestAddrForSMData = {
    10,
    { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x3E }
};

MAP_EXTENSION ktDestAddrForSM = {
    ExtensionType_present,
    128,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x3E }
    },
    18L
};

ObjectID kt_RetryIndForSM = {
    10,
    { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x3F }
};

MAP_EXTENSION ktRetryIndForSM = {
    ExtensionType_present,
    129,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x3F }
    },
    19L
};

ObjectID ktBarringReason = {
    10,
    { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x2E }
};

MAP_EXTENSION ktfBarringServiceReason = {
    ExtensionType_present,
    130,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x2E }
    },
    16L
};

ObjectID skmin_id = {
    6,
    { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x02 }
};

MAP_EXTENSION skminExt = {
    ExtensionType_present,
    131,
    {
        6,
        { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x02 }
    },
    8L
};

ObjectID skesn_id = {
    6,
    { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x08 }
};

MAP_EXTENSION skesnExt = {
    ExtensionType_present,
    132,
    {
        6,
        { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x08 }
    },
    9L
};

ObjectID sKSmsCapa_id = {
    6,
    { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x0B }
};

MAP_EXTENSION sKSmsCapaExt = {
    ExtensionType_present,
    133,
    {
        6,
        { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x0B }
    },
    10L
};

ObjectID sKOriginatingSFI_id = {
    6,
    { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x06 }
};

MAP_EXTENSION skOriginatingSFIExt = {
    ExtensionType_present,
    134,
    {
        6,
        { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x06 }
    },
    6L
};

ObjectID sKTSMSRoamingIndicator_id = {
    6,
    { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x1C }
};

MAP_EXTENSION sKTSMSRoamingIndicatorExt = {
    ExtensionType_present,
    135,
    {
        6,
        { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x1C }
    },
    7L
};

ObjectID sKTSMSAccessDeniedReason_id = {
    6,
    { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x24 }
};

MAP_EXTENSION sKTSMSAccessDeniedReasonExt = {
    ExtensionType_present,
    136,
    {
        6,
        { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x24 }
    },
    12L
};

ObjectID sKTSMSRoamingPMN_id = {
    6,
    { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x27 }
};

MAP_EXTENSION sKTSMSRoamingPMNExt = {
    ExtensionType_present,
    137,
    {
        6,
        { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x27 }
    },
    13L
};

ObjectID secondaryMSISDN_id = {
    6,
    { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x04 }
};

MAP_EXTENSION secondaryMSISDN = {
    ExtensionType_present,
    138,
    {
        6,
        { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x04 }
    },
    11L
};

ObjectID mobileDomainId = {
    3,
    { 0x04, 0x00, 0x00 }
};

ObjectID gsm_NetworkId = {
    4,
    { 0x04, 0x00, 0x00, 0x01 }
};

ObjectID gsm_AccessId = {
    4,
    { 0x04, 0x00, 0x00, 0x02 }
};

ObjectID gsm_OperationAndMaintenanceId = {
    4,
    { 0x04, 0x00, 0x00, 0x03 }
};

ObjectID gsm_MessagingId = {
    4,
    { 0x04, 0x00, 0x00, 0x04 }
};

const CommonComponentId ac_Id = 0;

const CommonComponentId as_Id = 1;

const CommonComponentId ase_Id = 2;

const CommonComponentId moduleId = 3;

const CommonComponentId er_Id = 4;

ObjectID map_ac = {
    5,
    { 0x04, 0x00, 0x00, 0x01, 0x00 }
};

ObjectID shortMsgGatewayContext_v3 = {
    7,
    { 0x04, 0x00, 0x00, 0x01, 0x00, 0x14, 0x03 }
};

ObjectID shortMsgGatewayContext_v2 = {
    7,
    { 0x04, 0x00, 0x00, 0x01, 0x00, 0x14, 0x02 }
};

ObjectID shortMsgMO_RelayContext_v3 = {
    7,
    { 0x04, 0x00, 0x00, 0x01, 0x00, 0x15, 0x03 }
};

ObjectID shortMsgMO_RelayContext_v2 = {
    7,
    { 0x04, 0x00, 0x00, 0x01, 0x00, 0x15, 0x02 }
};

ObjectID shortMsgMT_RelayContext_v3 = {
    7,
    { 0x04, 0x00, 0x00, 0x01, 0x00, 0x19, 0x03 }
};

ObjectID shortMsgMT_RelayContext_v2 = {
    7,
    { 0x04, 0x00, 0x00, 0x01, 0x00, 0x19, 0x02 }
};

ObjectID shortMsgAlertContext_v2 = {
    7,
    { 0x04, 0x00, 0x00, 0x01, 0x00, 0x17, 0x02 }
};

ObjectID mwdMngtContext_v3 = {
    7,
    { 0x04, 0x00, 0x00, 0x01, 0x00, 0x18, 0x03 }
};

ObjectID mwdMngtContext_v2 = {
    7,
    { 0x04, 0x00, 0x00, 0x01, 0x00, 0x18, 0x02 }
};

ObjectID anyTimeInfoHandlingContext_v3 = {
    7,
    { 0x04, 0x00, 0x00, 0x01, 0x00, 0x2B, 0x03 }
};

SendRoutingInfoForSM_V3 sendRoutingInfoForSM_V3 = {
    localValue_chosen, {0}
};

SendRoutingInfoForSM_V2 sendRoutingInfoForSM_V2 = {
    localValue_chosen, {0}
};

MO_ForwardSM_V3 mo_forwardSM_V3 = {
    localValue_chosen, {0}
};

MT_ForwardSM_V3 mt_forwardSM_V3 = {
    localValue_chosen, {0}
};

ReportSM_DeliveryStatus_V3 reportSM_DeliveryStatus_V3 = {
    localValue_chosen, {0}
};

ReportSM_DeliveryStatus_V2 reportSM_DeliveryStatus_V2 = {
    localValue_chosen, {0}
};

InformServiceCentre_V3 informServiceCentre_V3 = {
    localValue_chosen, {0}
};

InformServiceCentre_V2 informServiceCentre_V2 = {
    localValue_chosen, {0}
};

ReadyForSM readyForSM = {
    localValue_chosen, {0}
};

ForwardSM_V2 forwardSM_V2 = {
    localValue_chosen, {0}
};

AlertServiceCentre alertServiceCentre = {
    localValue_chosen, {0}
};

SystemFailure systemFailure = {
    localValue_chosen, {0}
};

DataMissing dataMissing = {
    localValue_chosen, {0}
};

UnexpectedDataValue unexpectedDataValue = {
    localValue_chosen, {0}
};

FacilityNotSupported facilityNotSupported = {
    localValue_chosen, {0}
};

IncompatibleTerminal incompatibleTerminal = {
    localValue_chosen, {0}
};

ResourceLimitation resourceLimitation = {
    localValue_chosen, {0}
};

UnknownSubscriber unknownSubscriber = {
    localValue_chosen, {0}
};

NumberChanged numberChanged = {
    localValue_chosen, {0}
};

UnknownMSC unknownMSC = {
    localValue_chosen, {0}
};

UnidentifiedSubscriber unidentifiedSubscriber = {
    localValue_chosen, {0}
};

UnknownEquipment unknownEquipment = {
    localValue_chosen, {0}
};

RoamingNotAllowed roamingNotAllowed = {
    localValue_chosen, {0}
};

IllegalSubscriber illegalSubscriber = {
    localValue_chosen, {0}
};

IllegalEquipment illegalEquipment = {
    localValue_chosen, {0}
};

BearerServiceNotProvisioned bearerServiceNotProvisioned = {
    localValue_chosen, {0}
};

TeleserviceNotProvisioned teleserviceNotProvisioned = {
    localValue_chosen, {0}
};

NoHandoverNumberAvailable noHandoverNumberAvailable = {
    localValue_chosen, {0}
};

SubsequentHandoverFailure subsequentHandoverFailure = {
    localValue_chosen, {0}
};

TargetCellOutsideGroupCallArea targetCellOutsideGroupCallArea = {
    localValue_chosen, {0}
};

TracingBufferFull tracingBufferFull = {
    localValue_chosen, {0}
};

NoRoamingNumberAvailable noRoamingNumberAvailable = {
    localValue_chosen, {0}
};

AbsentSubscriber absentSubscriber = {
    localValue_chosen, {0}
};

BusySubscriber busySubscriber = {
    localValue_chosen, {0}
};

NoSubscriberReply noSubscriberReply = {
    localValue_chosen, {0}
};

CallBarred callBarred = {
    localValue_chosen, {0}
};

ForwardingFailed forwardingFailed = {
    localValue_chosen, {0}
};

OR_NotAllowed or_NotAllowed = {
    localValue_chosen, {0}
};

ForwardingViolation forwardingViolation = {
    localValue_chosen, {0}
};

CUG_Reject cug_Reject = {
    localValue_chosen, {0}
};

ATI_NotAllowed ati_NotAllowed = {
    localValue_chosen, {0}
};

ATSI_NotAllowed atsi_NotAllowed = {
    localValue_chosen, {0}
};

ATM_NotAllowed atm_NotAllowed = {
    localValue_chosen, {0}
};

InformationNotAvailable informationNotAvailable = {
    localValue_chosen, {0}
};

AnyTimeModification anyTimeModification = {
    localValue_chosen, {0}
};

NoGroupCallNumberAvailable noGroupCallNumberAvailable = {
    localValue_chosen, {0}
};

IllegalSS_Operation illegalSS_Operation = {
    localValue_chosen, {0}
};

SS_ErrorStatus ss_ErrorStatus = {
    localValue_chosen, {0}
};

SS_NotAvailable ss_NotAvailable = {
    localValue_chosen, {0}
};

SS_SubscriptionViolation ss_SubscriptionViolation = {
    localValue_chosen, {0}
};

SS_Incompatibility ss_Incompatibility = {
    localValue_chosen, {0}
};

UnknownAlphabet unknownAlphabet = {
    localValue_chosen, {0}
};

USSD_Busy ussd_Busy = {
    localValue_chosen, {0}
};

PW_RegistrationFailure pw_RegistrationFailure = {
    localValue_chosen, {0}
};

NegativePW_Check negativePW_Check = {
    localValue_chosen, {0}
};

NumberOfPW_AttemptsViolation numberOfPW_AttemptsViolation = {
    localValue_chosen, {0}
};

ShortTermDenial shortTermDenial = {
    localValue_chosen, {0}
};

LongTermDenial longTermDenial = {
    localValue_chosen, {0}
};

SubscriberBusyForMT_SMS subscriberBusyForMT_SMS = {
    localValue_chosen, {0}
};

SM_DeliveryFailure sm_DeliveryFailure = {
    localValue_chosen, {0}
};

MessageWaitingListFull messageWaitingListFull = {
    localValue_chosen, {0}
};

AbsentSubscriberSM absentsubscriberSM = {
    localValue_chosen, {0}
};

UnauthorizedRequestingNetwork unauthorizedRequestingNetwork = {
    localValue_chosen, {0}
};

UnauthorizedLCSClient unauthorizedLCSClient = {
    localValue_chosen, {0}
};

PositionMethodFailure positionMethodFailure = {
    localValue_chosen, {0}
};

UnknownOrUnreachableLCSClient unknownOrUnreachableLCSClient = {
    localValue_chosen, {0}
};

MM_EventNotSupported mm_EventNotSupported = {
    localValue_chosen, {0}
};

SecureTransportError secureTransportError = {
    localValue_chosen, {0}
};

static ossBoolean _v2 = TRUE;

static ossBoolean _v3 = FALSE;

static unsigned char _v5[] = {
    0x80
};
static _bit1 _v4 = {
    1,
    _v5
};

static struct _bit1 _v6 = {
    1,
    _v5
};

static struct _bit1 _v7 = {
    1,
    _v5
};

static MAP_EXTENSION _v8 = {
    ExtensionType_present,
    120,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x01 }
    },
    1L
};

static MAP_EXTENSION _v9 = {
    ExtensionType_present,
    121,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x0B }
    },
    2L
};

static MAP_EXTENSION _v10 = {
    ExtensionType_present,
    122,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x0F }
    },
    3L
};

static MAP_EXTENSION _v11 = {
    ExtensionType_present,
    124,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x1A }
    },
    4L
};

static MAP_EXTENSION _v12 = {
    ExtensionType_present,
    125,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x29 }
    },
    5L
};

static MAP_EXTENSION _v13 = {
    ExtensionType_present,
    134,
    {
        6,
        { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x06 }
    },
    6L
};

static MAP_EXTENSION _v14 = {
    ExtensionType_present,
    135,
    {
        6,
        { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x1C }
    },
    7L
};

static MAP_EXTENSION _v15 = {
    ExtensionType_present,
    131,
    {
        6,
        { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x02 }
    },
    8L
};

static MAP_EXTENSION _v16 = {
    ExtensionType_present,
    132,
    {
        6,
        { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x08 }
    },
    9L
};

static MAP_EXTENSION _v17 = {
    ExtensionType_present,
    133,
    {
        6,
        { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x0B }
    },
    10L
};

static MAP_EXTENSION _v18 = {
    ExtensionType_present,
    138,
    {
        6,
        { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x04 }
    },
    11L
};

static MAP_EXTENSION _v19 = {
    ExtensionType_present,
    136,
    {
        6,
        { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x24 }
    },
    12L
};

static MAP_EXTENSION _v20 = {
    ExtensionType_present,
    137,
    {
        6,
        { 0x03, 0xA3, 0x18, 0x00, 0x00, 0x27 }
    },
    13L
};

static MAP_EXTENSION _v21 = {
    ExtensionType_present,
    123,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x2D }
    },
    14L
};

static MAP_EXTENSION _v22 = {
    ExtensionType_present,
    126,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x03 }
    },
    15L
};

static MAP_EXTENSION _v23 = {
    ExtensionType_present,
    130,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x2E }
    },
    16L
};

static MAP_EXTENSION _v24 = {
    ExtensionType_present,
    127,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x3D }
    },
    17L
};

static MAP_EXTENSION _v25 = {
    ExtensionType_present,
    128,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x3E }
    },
    18L
};

static MAP_EXTENSION _v26 = {
    ExtensionType_present,
    129,
    {
        10,
        { 0x2B, 0x06, 0x01, 0x04, 0x01, 0xF0, 0x2C, 0x14, 0x0A, 0x3F }
    },
    19L
};

static InvokeId _v27 = {
    absent_chosen, {0}
};


#if !defined(OSS_SPARTAN_AWARE) || ((OSS_SPARTAN_AWARE + 0) < 2)
static ObjectSetEntry const ExtensionSet[] = {
    {&ExtensionSet[1], &_v8},
    {&ExtensionSet[2], &_v9},
    {&ExtensionSet[3], &_v10},
    {&ExtensionSet[4], &_v11},
    {&ExtensionSet[5], &_v12},
    {&ExtensionSet[6], &_v13},
    {&ExtensionSet[7], &_v14},
    {&ExtensionSet[8], &_v15},
    {&ExtensionSet[9], &_v16},
    {&ExtensionSet[10], &_v17},
    {&ExtensionSet[11], &_v18},
    {&ExtensionSet[12], &_v19},
    {&ExtensionSet[13], &_v20},
    {&ExtensionSet[14], &_v21},
    {&ExtensionSet[15], &_v22},
    {&ExtensionSet[16], &_v23},
    {&ExtensionSet[17], &_v24},
    {&ExtensionSet[18], &_v25},
    {NULL, &_v26}
};

#else /* OSS_SPARTAN_AWARE >= 2 */

#if ((OSS_SPARTAN_AWARE + 0) > 12)
static ObjectSetEntry const ExtensionSet[] = {
    {(ObjectSetEntry *)&ExtensionSet[1], &_v8, NULL, NULL},
    {(ObjectSetEntry *)&ExtensionSet[2], &_v9, (ObjectSetEntry *)&ExtensionSet[0], NULL},
    {(ObjectSetEntry *)&ExtensionSet[3], &_v10, (ObjectSetEntry *)&ExtensionSet[1], NULL},
    {(ObjectSetEntry *)&ExtensionSet[4], &_v11, (ObjectSetEntry *)&ExtensionSet[2], NULL},
    {(ObjectSetEntry *)&ExtensionSet[5], &_v12, (ObjectSetEntry *)&ExtensionSet[3], NULL},
    {(ObjectSetEntry *)&ExtensionSet[6], &_v13, (ObjectSetEntry *)&ExtensionSet[4], NULL},
    {(ObjectSetEntry *)&ExtensionSet[7], &_v14, (ObjectSetEntry *)&ExtensionSet[5], NULL},
    {(ObjectSetEntry *)&ExtensionSet[8], &_v15, (ObjectSetEntry *)&ExtensionSet[6], NULL},
    {(ObjectSetEntry *)&ExtensionSet[9], &_v16, (ObjectSetEntry *)&ExtensionSet[7], NULL},
    {(ObjectSetEntry *)&ExtensionSet[10], &_v17, (ObjectSetEntry *)&ExtensionSet[8], NULL},
    {(ObjectSetEntry *)&ExtensionSet[11], &_v18, (ObjectSetEntry *)&ExtensionSet[9], NULL},
    {(ObjectSetEntry *)&ExtensionSet[12], &_v19, (ObjectSetEntry *)&ExtensionSet[10], NULL},
    {(ObjectSetEntry *)&ExtensionSet[13], &_v20, (ObjectSetEntry *)&ExtensionSet[11], NULL},
    {(ObjectSetEntry *)&ExtensionSet[14], &_v21, (ObjectSetEntry *)&ExtensionSet[12], NULL},
    {(ObjectSetEntry *)&ExtensionSet[15], &_v22, (ObjectSetEntry *)&ExtensionSet[13], NULL},
    {(ObjectSetEntry *)&ExtensionSet[16], &_v23, (ObjectSetEntry *)&ExtensionSet[14], NULL},
    {(ObjectSetEntry *)&ExtensionSet[17], &_v24, (ObjectSetEntry *)&ExtensionSet[15], NULL},
    {(ObjectSetEntry *)&ExtensionSet[18], &_v25, (ObjectSetEntry *)&ExtensionSet[16], NULL},
    {NULL, &_v26, (ObjectSetEntry *)&ExtensionSet[17], NULL}
};
#else /* OSS_SPARTAN_AWARE <= 12 */
static ObjectSetEntry const ExtensionSet[] = {
    {(ObjectSetEntry *)&ExtensionSet[1], &_v8, NULL},
    {(ObjectSetEntry *)&ExtensionSet[2], &_v9, (ObjectSetEntry *)&ExtensionSet[0]},
    {(ObjectSetEntry *)&ExtensionSet[3], &_v10, (ObjectSetEntry *)&ExtensionSet[1]},
    {(ObjectSetEntry *)&ExtensionSet[4], &_v11, (ObjectSetEntry *)&ExtensionSet[2]},
    {(ObjectSetEntry *)&ExtensionSet[5], &_v12, (ObjectSetEntry *)&ExtensionSet[3]},
    {(ObjectSetEntry *)&ExtensionSet[6], &_v13, (ObjectSetEntry *)&ExtensionSet[4]},
    {(ObjectSetEntry *)&ExtensionSet[7], &_v14, (ObjectSetEntry *)&ExtensionSet[5]},
    {(ObjectSetEntry *)&ExtensionSet[8], &_v15, (ObjectSetEntry *)&ExtensionSet[6]},
    {(ObjectSetEntry *)&ExtensionSet[9], &_v16, (ObjectSetEntry *)&ExtensionSet[7]},
    {(ObjectSetEntry *)&ExtensionSet[10], &_v17, (ObjectSetEntry *)&ExtensionSet[8]},
    {(ObjectSetEntry *)&ExtensionSet[11], &_v18, (ObjectSetEntry *)&ExtensionSet[9]},
    {(ObjectSetEntry *)&ExtensionSet[12], &_v19, (ObjectSetEntry *)&ExtensionSet[10]},
    {(ObjectSetEntry *)&ExtensionSet[13], &_v20, (ObjectSetEntry *)&ExtensionSet[11]},
    {(ObjectSetEntry *)&ExtensionSet[14], &_v21, (ObjectSetEntry *)&ExtensionSet[12]},
    {(ObjectSetEntry *)&ExtensionSet[15], &_v22, (ObjectSetEntry *)&ExtensionSet[13]},
    {(ObjectSetEntry *)&ExtensionSet[16], &_v23, (ObjectSetEntry *)&ExtensionSet[14]},
    {(ObjectSetEntry *)&ExtensionSet[17], &_v24, (ObjectSetEntry *)&ExtensionSet[15]},
    {(ObjectSetEntry *)&ExtensionSet[18], &_v25, (ObjectSetEntry *)&ExtensionSet[16]},
    {NULL, &_v26, (ObjectSetEntry *)&ExtensionSet[17]}
};
#endif /* (OSS_SPARTAN_AWARE + 0) > 12 */

static unsigned short const _oss_OSet_info[] =  {
    4
};
#endif /* !OSS_SPARTAN_AWARE || OSS_SPARTAN_AWARE < 2 */

#ifdef OSS_SPARTAN_AWARE
#if ((OSS_SPARTAN_AWARE + 0) >= 3)
extern void _oss_run_SOED_on_AMD64_LINUX_64_BIT(void);
static void _oss_post_init(struct ossGlobal *world);
#endif /* OSS_SPARTAN_AWARE >= 3 */
#endif /* OSS_SPARTAN_AWARE */

#ifdef OSS_SPARTAN_AWARE
#if ((OSS_SPARTAN_AWARE + 0) >= 12)
static unsigned char _privateFlags[] = {0x01,0x00};
#endif /* OSS_SPARTAN_AWARE >= 12 */
#endif /* OSS_SPARTAN_AWARE */

static void _ossinit_map_protocol(struct ossGlobal *world) {
    noInvokeId.u.absent = 0;
    _v1.errorCode.u.local = -1;
    refuse.errorCode.u.local = -1;
    no_op.operationCode.u.local = -1;
    sendRoutingInfoForSM_V3.u.localValue = 45;
    sendRoutingInfoForSM_V2.u.localValue = 45;
    mo_forwardSM_V3.u.localValue = 46;
    mt_forwardSM_V3.u.localValue = 44;
    reportSM_DeliveryStatus_V3.u.localValue = 47;
    reportSM_DeliveryStatus_V2.u.localValue = 47;
    informServiceCentre_V3.u.localValue = 63;
    informServiceCentre_V2.u.localValue = 63;
    readyForSM.u.localValue = 66;
    forwardSM_V2.u.localValue = 46;
    alertServiceCentre.u.localValue = 64;
    systemFailure.u.localValue = 34;
    dataMissing.u.localValue = 35;
    unexpectedDataValue.u.localValue = 36;
    facilityNotSupported.u.localValue = 21;
    incompatibleTerminal.u.localValue = 28;
    resourceLimitation.u.localValue = 51;
    unknownSubscriber.u.localValue = 1;
    numberChanged.u.localValue = 44;
    unknownMSC.u.localValue = 3;
    unidentifiedSubscriber.u.localValue = 5;
    unknownEquipment.u.localValue = 7;
    roamingNotAllowed.u.localValue = 8;
    illegalSubscriber.u.localValue = 9;
    illegalEquipment.u.localValue = 12;
    bearerServiceNotProvisioned.u.localValue = 10;
    teleserviceNotProvisioned.u.localValue = 11;
    noHandoverNumberAvailable.u.localValue = 25;
    subsequentHandoverFailure.u.localValue = 26;
    targetCellOutsideGroupCallArea.u.localValue = 42;
    tracingBufferFull.u.localValue = 40;
    noRoamingNumberAvailable.u.localValue = 39;
    absentSubscriber.u.localValue = 27;
    busySubscriber.u.localValue = 45;
    noSubscriberReply.u.localValue = 46;
    callBarred.u.localValue = 13;
    forwardingFailed.u.localValue = 47;
    or_NotAllowed.u.localValue = 48;
    forwardingViolation.u.localValue = 14;
    cug_Reject.u.localValue = 15;
    ati_NotAllowed.u.localValue = 49;
    atsi_NotAllowed.u.localValue = 60;
    atm_NotAllowed.u.localValue = 61;
    informationNotAvailable.u.localValue = 62;
    anyTimeModification.u.localValue = 65;
    noGroupCallNumberAvailable.u.localValue = 50;
    illegalSS_Operation.u.localValue = 16;
    ss_ErrorStatus.u.localValue = 17;
    ss_NotAvailable.u.localValue = 18;
    ss_SubscriptionViolation.u.localValue = 19;
    ss_Incompatibility.u.localValue = 20;
    unknownAlphabet.u.localValue = 71;
    ussd_Busy.u.localValue = 72;
    pw_RegistrationFailure.u.localValue = 37;
    negativePW_Check.u.localValue = 38;
    numberOfPW_AttemptsViolation.u.localValue = 43;
    shortTermDenial.u.localValue = 29;
    longTermDenial.u.localValue = 30;
    subscriberBusyForMT_SMS.u.localValue = 31;
    sm_DeliveryFailure.u.localValue = 32;
    messageWaitingListFull.u.localValue = 33;
    absentsubscriberSM.u.localValue = 6;
    unauthorizedRequestingNetwork.u.localValue = 52;
    unauthorizedLCSClient.u.localValue = 53;
    positionMethodFailure.u.localValue = 54;
    unknownOrUnreachableLCSClient.u.localValue = 58;
    mm_EventNotSupported.u.localValue = 59;
    secureTransportError.u.localValue = 4;
    _v27.u.absent = 0;
#ifdef OSS_SPARTAN_AWARE
#if ((OSS_SPARTAN_AWARE + 0) >= 3)
    _oss_run_SOED_on_AMD64_LINUX_64_BIT();
#endif /* OSS_SPARTAN_AWARE >= 3 */
#endif /* OSS_SPARTAN_AWARE */
#ifdef OSS_SPARTAN_AWARE
#if ((OSS_SPARTAN_AWARE + 0) >= 12)
    ossPrivateSetMoreFlags(world, 12, _privateFlags);
#endif /* OSS_SPARTAN_AWARE >= 12 */
#endif /* OSS_SPARTAN_AWARE */
    ossLinkBer(world);
#if !defined(OSS_SPARTAN_AWARE) || ((OSS_SPARTAN_AWARE + 0) < 8)
    ossLinkConstraint(world);
#else  /* OSS_SPARTAN_AWARE < 8 */
    ossLinkConstraintSpartanAware8(world);
#endif /* OSS_SPARTAN_AWARE < 8 */
#ifdef OSS_SPARTAN_AWARE
    ossLinkCmpValue(world);
#if ((OSS_SPARTAN_AWARE + 0) >= 2)
    ossInitObjectSetInfo(world, (unsigned short *)_oss_OSet_info);
#endif /* OSS_SPARTAN_AWARE >= 2 */
#endif /* OSS_SPARTAN_AWARE */

#ifdef OSS_SPARTAN_AWARE
#if ((OSS_SPARTAN_AWARE + 0) >= 3)
    _oss_post_init(world);
#endif /* OSS_SPARTAN_AWARE >= 3 */
#endif /* OSS_SPARTAN_AWARE */
}

static const struct {
    short length;
    char value[11];
} _v29 = { 10, "0123456789"};
static unsigned short const _v30 = 4;
static unsigned short const _v40 = 8;
static unsigned short const _v48 = 3;
static unsigned short const _v54 = 1;
static unsigned short const _v63 = 1;
static unsigned short const _v73 = 1;
static unsigned short const _v75 = 1;
static Priority const _v81 = 0;
static unsigned short const _v94 = 1;
static unsigned short const _v96 = 1;
static unsigned short const _v98 = 1;
static unsigned short const _v100 = 1;
static unsigned short const _v121 = 1;
static unsigned short const _v127 = 1;
static unsigned short const _v168 = 1;
static unsigned short const _v172 = 1;
static const struct {
    short length;
    char value[11];
} _v227 = { 10, "0123456789"};
static unsigned short const _v228 = 4;
static unsigned short const _v254 = 1;
static unsigned short const _v280 = 1;
static unsigned short const _v353 = 4;
static unsigned short const _v372 = 4;
static unsigned short const _v392 = 3;
static unsigned short const _v398 = 8;
static unsigned short const _v419 = 3;
static unsigned short const _v425 = 7;
static unsigned short const _v427 = 5;
static unsigned short const _v448 = 2;

static unsigned int const _v517[9] = {
  0, 1, 2, 3, 4, 5, 6, 7, 8
};
static unsigned int const _v485[5] = {
  1, 2, 11, 12, 14
};
static unsigned int const _v508[4] = {
  0, 1, 5, 7
};
static unsigned char const _v480[4] = {
  0x0, 0x0, 0x0, 0x7
};
static unsigned int const _v477[4] = {
  1, 2, 3, 4
};
static unsigned int const _v494[3] = {13, 14, INT_MAX};
static unsigned int const _v471[3] = {0, 1, 30};
static unsigned int const _v514[2] = {3, INT_MAX};
static unsigned int const _v512[2] = {2, INT_MAX};
static unsigned int const _v506[2] = {0, 3};
static unsigned int const _v490[2] = {4, INT_MAX};
static unsigned short const _v447[2] = {2, 2};
static unsigned short const _v446[2] = {0, 255};
static unsigned short const _v444[2] = {1, 10};
static unsigned short const _v443[2] = {1, 7};
static unsigned short const _v441[2] = {2, 7};
static unsigned short const _v439[2] = {1, 5};
static unsigned short const _v438[2] = {1, 1};
static unsigned short const _v429[2] = {5, 5};
static unsigned short const _v428[2] = {7, 7};
static unsigned short const _v423[2] = {1, 20};
static unsigned short const _v422[2] = {1, 9};
static unsigned short const _v421[2] = {3, 8};
static unsigned short const _v420[2] = {3, 3};
static unsigned short const _v417[2] = {1, 4};
static unsigned short const _v413[2] = {1, 1000};
static unsigned short const _v411[2] = {0, 127};
static unsigned short const _v409[2] = {1, 127};
static unsigned short const _v407[2] = {8, 8};
static unsigned short const _v385[2] = {6, 16};
static unsigned short const _v374[2] = {4, 4};
static unsigned short const _v362[2] = {30, 600};
static unsigned short const _v359[2] = {9, 255};
static unsigned short const _v347[2] = {1, 12};
static unsigned short const _v346[2] = {0, 10};
static unsigned short const _v336[2] = {1, 8};
static unsigned short const _v334[2] = {0, 4};
static unsigned short const _v329[2] = {1, 100};
static unsigned short const _v327[2] = {1, 21};
static unsigned short const _v309[2] = {1, 3};
static unsigned short const _v308[2] = {1, 15};
static unsigned int const _v298[2] = {0, INT_MAX};
static unsigned short const _v286[2] = {1, 16};
static unsigned short const _v264[2] = {1, 32};
static unsigned short const _v217[2] = {4, 32};
static unsigned short const _v215[2] = {15, 32};
static unsigned short const _v191[2] = {2, 32};
static unsigned short const _v189[2] = {1, 200};
static unsigned short const _v185[2] = {1, 2};
static unsigned short const _v174[2] = {1, 13};
static unsigned short const _v170[2] = {1, 160};
static unsigned short const _v147[2] = {0, 15};
static unsigned short const _v135[2] = {5, 30};
static short const _v86[2] = {-128, 127};
static unsigned int const _v82[2] = {0, UINT_MAX};
static unsigned short const _v80[2] = {0, 9};
static unsigned short const _v58[2] = {1, 24};
static unsigned short const _v46[2] = {0, SHRT_MAX};
static unsigned short const _v44[2] = {5, 7};
static unsigned short const _v42[2] = {1, 50};
static unsigned short const _v34[2] = {1, 30};
static unsigned int const _v525[1] = {INT_MAX};
static unsigned char const _v504[1] = {0x7};
static unsigned int const _v493[1] = {12};
static unsigned char const _v483[1] = {0x7f};
static unsigned char const _v481[1] = {0xf};
static unsigned char const _v476[1] = {0x3f};

static const unsigned short _pduarray[] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
    31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
    41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
    61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
    71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
    81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
    91, 92, 93, 94, 95, 96, 97, 98, 99, 100,
    101, 102, 103, 104, 105, 106, 107, 108, 109, 110,
    111, 112, 113, 114, 115, 116, 117, 118, 119, 120,
    121, 122, 123, 124, 125, 126, 127, 128, 129, 130,
    131, 132, 133, 134, 135, 136, 137, 138, 139, 140,
    141, 142, 143, 144, 145, 146, 147, 148, 149, 150,
    151, 152, 153, 154, 155, 156, 157, 158, 159, 160,
    161, 162, 163, 164, 165, 166, 167, 168, 169, 170,
    171, 172, 173, 174, 175, 176, 177, 178, 179, 180,
    181, 182, 183, 184, 185, 186, 187, 188, 189, 190,
    191, 192, 193, 194, 195, 196, 197, 0
};

static const struct etype _etypearray[] = {
    {10, 0, 0, "ObjectID", 12, 2, 2, 2, 56, 0, 63, 0},
    {-1, 2, 4, "Reject", 16, 2, 0, 0, 72, 0, 12, 0},
    {-1, 20, 21, "NoInvokeId", 8, 2, 2, 4, 72, 2, 13, 2},
    {-1, 20, 26, "MessageType", 296, 5, 2, 8, 8, 4, 13, 0},
    {-1, 20, 37, "DialoguePDU", 136, 3, 2, 8, 8, 9, 13, 0},
    {-1, 44, 46, "RLRQ-apdu", 88, 2, 1, 0, 8, 12, 12, 0},
    {-1, 56, 46, "RLRE-apdu", 88, 2, 1, 0, 8, 14, 12, 0},
    {-1, 20, 58, "UniDialoguePDU", 128, 1, 2, 8, 8, 16, 13, 0},
    {-1, 20, 61, "SendRoutingInfoForSM-V3", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "SendRoutingInfoForSM-V2", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "MO-ForwardSM-V3", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "MT-ForwardSM-V3", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "ForwardSM-V2", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "ReportSM-DeliveryStatus-V3", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "ReportSM-DeliveryStatus-V2", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "AlertServiceCentre", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "InformServiceCentre-V3", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "InformServiceCentre-V2", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "ReadyForSM", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "AnyTimeModification", 16, 2, 2, 4, 8, 17, 13, 0},
    {3, 2, 66, "RegisterSS-Arg", 66, 8, 1, 0, 2076, 19, 12, 0},
    {1, 2, 142, "SS-ForBS-Code", 14, 3, 1, 0, 2076, 27, 12, 0},
    {-1, 20, 158, "InterrogateSS-Res", 40, 4, 2, 8, 8, 30, 13, 0},
    {2, 2, 167, "USSD-Arg", 184, 4, 1, 0, 2076, 34, 12, 0},
    {-1, 2, 185, "USSD-Res", 166, 2, 0, 0, 12, 38, 12, 0},
    {5, 193, 18, "Password", 1, 0, 2, 0, 16600, 0, 24, 3},
    {2, 195, 0, "GuidanceInfo", 4, 0, 4, 0, 24, 1, 58, 0},
    {30, 2, 0, "SS-List", 8, 8, 2, 8, 216, 293, 18, 8},
    {30, 2, 0, "SS-InfoList", 8, 48, 2, 8, 216, 324, 18, 11},
    {2, 2, 197, "SS-InvocationNotificationArg", 80, 7, 1, 0, 2076, 40, 12, 0},
    {-1, 2, 237, "SS-InvocationNotificationRes", 32, 1, 1, 0, 12, 47, 12, 0},
    {-1, 2, 241, "RegisterCC-EntryArg", 568, 2, 1, 0, 12, 48, 12, 0},
    {-1, 2, 249, "RegisterCC-EntryRes", 48, 1, 1, 0, 12, 50, 12, 0},
    {-1, 2, 241, "EraseCC-EntryArg", 8, 2, 1, 0, 12, 51, 12, 0},
    {-1, 2, 241, "EraseCC-EntryRes", 10, 2, 1, 0, 12, 53, 12, 0},
    {20, 2, 0, "TeleserviceList", 8, 8, 2, 8, 216, 409, 18, 14},
    {9, 2, 253, "AnyTimeModificationArg", 680, 16, 2, 0, 2076, 55, 12, 0},
    {6, 2, 499, "AnyTimeModificationRes", 832, 9, 2, 0, 2076, 71, 12, 0},
    {9, 2, 607, "RoutingInfoForSM-Arg-V3", 152, 13, 2, 0, 2076, 80, 12, 0},
    {-1, 2, 749, "RoutingInfoForSM-Arg-V2", 42, 4, 1, 0, 12, 93, 12, 0},
    {1, 2, 765, "RoutingInfoForSM-Res-V3", 1704, 4, 1, 0, 2076, 97, 12, 0},
    {-1, 2, 783, "RoutingInfoForSM-Res-V2", 36, 3, 1, 0, 12, 101, 12, 0},
    {3, 2, 795, "MO-ForwardSM-Arg-V3", 352, 7, 1, 0, 2076, 104, 12, 0},
    {-1, 2, 847, "MO-ForwardSM-Res-V3", 232, 2, 1, 0, 12, 111, 12, 0},
    {5, 2, 857, "MT-ForwardSM-Arg-V3", 352, 10, 1, 0, 2076, 113, 12, 0},
    {-1, 2, 951, "ForwardSM-Arg-V2", 254, 4, 1, 0, 12, 123, 12, 0},
    {1, 2, 979, "MT-ForwardSM-Res-V3", 240, 3, 1, 0, 2076, 127, 12, 0},
    {10, 2, 997, "ReportSM-DeliveryStatusArg-V3", 152, 15, 2, 0, 2076, 130, 12, 0},
    {-1, 2, 847, "ReportSM-DeliveryStatusRes-V3", 40, 2, 1, 0, 12, 145, 12, 0},
    {-1, 2, 1189, "ReportSM-DeliveryStatusArg-V2", 40, 3, 1, 0, 12, 147, 12, 0},
    {-1, 2, 847, "ReportSM-DeliveryStatusRes-V2", 40, 2, 1, 0, 12, 150, 12, 0},
    {-1, 2, 185, "AlertServiceCentreArg", 34, 2, 0, 0, 12, 152, 12, 0},
    {-1, 2, 1201, "InformServiceCentreArg-V3", 40, 3, 1, 0, 12, 154, 12, 0},
    {-1, 2, 1219, "InformServiceCentreArg-V2", 16, 2, 1, 0, 12, 157, 12, 0},
    {-1, 2, 1229, "ReadyForSM-Arg", 56, 6, 1, 0, 12, 159, 12, 0},
    {-1, 2, 237, "ReadyForSM-Res", 32, 1, 1, 0, 12, 165, 12, 0},
    {-1, 2, 1265, "RoamingNotAllowedParam", 32, 2, 1, 0, 12, 166, 12, 0},
    {-1, 20, 1273, "CallBarredParam", 48, 2, 2, 8, 8, 168, 13, 0},
    {-1, 2, 1278, "CUG-RejectParam", 32, 2, 1, 0, 12, 170, 12, 0},
    {-1, 2, 1288, "SS-IncompatibilityCause", 16, 3, 1, 0, 12, 172, 12, 0},
    {2, 195, 0, "PW-RegistrationFailureCause", 4, 0, 4, 0, 24, 6, 58, 0},
    {-1, 2, 1310, "SM-DeliveryFailureCause", 240, 3, 1, 0, 12, 175, 12, 0},
    {1, 2, 1324, "AbsentSubscriberSM-Param", 40, 3, 1, 0, 2076, 178, 12, 0},
    {-1, 20, 1273, "SystemFailureParam", 40, 2, 2, 8, 8, 181, 13, 0},
    {-1, 2, 237, "DataMissingParam", 32, 1, 1, 0, 12, 183, 12, 0},
    {-1, 2, 237, "UnexpectedDataParam", 32, 1, 1, 0, 12, 184, 12, 0},
    {-1, 2, 237, "FacilityNotSupParam", 32, 1, 1, 0, 12, 185, 12, 0},
    {-1, 2, 237, "OR-NotAllowedParam", 32, 1, 1, 0, 12, 186, 12, 0},
    {1, 2, 1342, "UnknownSubscriberParam", 40, 2, 1, 0, 2076, 187, 12, 0},
    {-1, 2, 237, "NumberChangedParam", 32, 1, 1, 0, 12, 189, 12, 0},
    {-1, 2, 237, "UnidentifiedSubParam", 32, 1, 1, 0, 12, 190, 12, 0},
    {-1, 2, 237, "IllegalSubscriberParam", 32, 1, 1, 0, 12, 191, 12, 0},
    {-1, 2, 237, "IllegalEquipmentParam", 32, 1, 1, 0, 12, 192, 12, 0},
    {-1, 2, 237, "BearerServNotProvParam", 32, 1, 1, 0, 12, 193, 12, 0},
    {-1, 2, 237, "TeleservNotProvParam", 32, 1, 1, 0, 12, 194, 12, 0},
    {-1, 2, 237, "TracingBufferFullParam", 32, 1, 1, 0, 12, 195, 12, 0},
    {-1, 2, 237, "NoRoamingNbParam", 32, 1, 1, 0, 12, 196, 12, 0},
    {1, 2, 1352, "AbsentSubscriberParam", 40, 2, 1, 0, 2076, 197, 12, 0},
    {2, 2, 1362, "BusySubscriberParam", 40, 3, 1, 0, 2076, 199, 12, 0},
    {-1, 2, 237, "NoSubscriberReplyParam", 32, 1, 1, 0, 12, 202, 12, 0},
    {-1, 2, 237, "ForwardingViolationParam", 32, 1, 1, 0, 12, 203, 12, 0},
    {-1, 2, 237, "ForwardingFailedParam", 32, 1, 1, 0, 12, 204, 12, 0},
    {-1, 2, 237, "ATI-NotAllowedParam", 32, 1, 1, 0, 12, 205, 12, 0},
    {-1, 2, 237, "ATSI-NotAllowedParam", 32, 1, 1, 0, 12, 206, 12, 0},
    {-1, 2, 237, "ATM-NotAllowedParam", 32, 1, 1, 0, 12, 207, 12, 0},
    {-1, 2, 237, "IllegalSS-OperationParam", 32, 1, 1, 0, 12, 208, 12, 0},
    {-1, 2, 237, "SS-NotAvailableParam", 32, 1, 1, 0, 12, 209, 12, 0},
    {-1, 2, 237, "SS-SubscriptionViolationParam", 32, 1, 1, 0, 12, 210, 12, 0},
    {-1, 2, 237, "InformationNotAvailableParam", 32, 1, 1, 0, 12, 211, 12, 0},
    {1, 2, 1380, "SubBusyForMT-SMS-Param", 40, 2, 1, 0, 2076, 212, 12, 0},
    {-1, 2, 237, "MessageWaitListFullParam", 32, 1, 1, 0, 12, 214, 12, 0},
    {-1, 2, 237, "ResourceLimitationParam", 32, 1, 1, 0, 12, 215, 12, 0},
    {-1, 2, 237, "NoGroupCallNbParam", 32, 1, 1, 0, 12, 216, 12, 0},
    {-1, 2, 237, "IncompatibleTerminalParam", 32, 1, 1, 0, 12, 217, 12, 0},
    {-1, 2, 0, "ShortTermDenialParam", 1, 0, 0, 0, 12, 218, 12, 0},
    {-1, 2, 0, "LongTermDenialParam", 1, 0, 0, 0, 12, 218, 12, 0},
    {-1, 2, 237, "UnauthorizedRequestingNetwork-Param", 32, 1, 1, 0, 12, 218, 12, 0},
    {-1, 2, 1390, "UnauthorizedLCSClient-Param", 32, 2, 1, 0, 12, 219, 12, 0},
    {-1, 2, 1390, "PositionMethodFailure-Param", 32, 2, 1, 0, 12, 221, 12, 0},
    {-1, 2, 237, "UnknownOrUnreachableLCSClient-Param", 32, 1, 1, 0, 12, 223, 12, 0},
    {-1, 2, 237, "MM-EventNotSupported-Param", 32, 1, 1, 0, 12, 224, 12, 0},
    {-1, 2, 237, "TargetCellOutsideGCA-Param", 32, 1, 1, 0, 12, 225, 12, 0},
    {-1, 2, 1400, "SecureTransportErrorParam", 80, 2, 1, 0, 8, 226, 12, 0},
    {-1, 2, 1408, "Ext-ExternalSignalInfo", 240, 3, 1, 0, 12, 228, 12, 0},
    {-1, 2, 1408, "AccessNetworkSignalInfo", 240, 3, 1, 0, 12, 231, 12, 0},
    {-1, 20, 1420, "Identity", 18, 2, 2, 2, 8, 234, 13, 0},
    {8, 1425, 0, "ASCI-CallReference", 2, 0, 2, 2, 216, 0, 21, 17},
    {-1, 20, 1427, "SubscriberId", 12, 2, 2, 2, 8, 236, 13, 0},
    {8, 1425, 0, "IMEI", 2, 0, 2, 2, 216, 0, 21, 20},
    {50, 2, 0, "HLR-List", 8, 16, 2, 8, 216, 664, 18, 23},
    {7, 1425, 0, "GlobalCellId", 2, 0, 2, 2, 216, 0, 21, 26},
    {-1, 2, 241, "NAEA-PreferredCI", 32, 2, 1, 0, 12, 238, 12, 0},
    {-1, 20, 1427, "SubscriberIdentity", 14, 2, 2, 2, 8, 240, 13, 0},
    {-1, 2, 1390, "LCSClientExternalID", 48, 2, 1, 0, 12, 242, 12, 0},
    {INT_MAX, 195, 0, "LCSClientInternalID", 4, 0, 4, 0, 2076, 11, 6, 0},
    {-1, 20, 1427, "CellGlobalIdOrServiceAreaIdOrLAI", 12, 2, 2, 2, 8, 244, 13, 0},
    {-1, 20, 1432, "Ext-BasicServiceCode", 10, 2, 2, 2, 8, 246, 13, 0},
    {-1, 2, 1437, "EMLPP-Info", 32, 3, 1, 0, 12, 248, 12, 0},
    {-1, 2, 1449, "MC-SS-Info", 48, 5, 1, 0, 12, 251, 12, 0},
    {-1, 1469, 0, "AgeOfLocationInformation", 2, 0, 2, 0, 200, 0, 55, 29},
    {-1, 2, 1471, "KTF-ORIGSERVICETYPE", 8, 2, 1, 0, 8, 256, 12, 0},
    {3, 1425, 0, "KTF-DESTSERVICETYPE", 2, 0, 2, 2, 216, 0, 21, 31},
    {9, 1425, 0, "KTF-EXTMSISDNTYPE", 2, 0, 2, 2, 216, 0, 21, 34},
    {9, 1425, 0, "KTF-EXTORIGINALNUMTYPE", 2, 0, 2, 2, 216, 0, 21, 40},
    {1, 1425, 0, "KTF-SHOWREGIONTYPE", 2, 0, 2, 2, 216, 0, 21, 42},
    {16, 1425, 0, "KTF-UEINDICATORTYPE", 2, 0, 2, 2, 216, 0, 21, 45},
    {24, 1425, 0, "KT-ROAMPARTYTYPE", 2, 0, 2, 2, 216, 0, 21, 48},
    {16, 1425, 0, "KT-IPSMGWSVCINFO", 2, 0, 2, 2, 216, 0, 21, 51},
    {9, 1425, 0, "KT-DESTADDRFORSMDATA", 2, 0, 2, 2, 216, 0, 21, 54},
    {1, 1425, 0, "KT-RETRYINDFORSM", 2, 0, 2, 2, 216, 0, 21, 56},
    {INT_MAX, 195, 0, "KtfBarringServiceReason", 4, 0, 4, 0, 2076, 21, 6, 0},
    {5, 1425, 0, "SKMIN", 2, 0, 2, 2, 216, 0, 21, 59},
    {4, 1425, 0, "SKESN", 2, 0, 2, 2, 216, 0, 21, 62},
    {4, 1425, 0, "SKSMSCapability", 2, 0, 2, 2, 216, 0, 21, 65},
    {5, 1425, 0, "SKOriginatingSFI", 2, 0, 2, 2, 216, 0, 21, 68},
    {1, 1425, 0, "SKTSMSRoamingIndicator", 2, 0, 2, 2, 216, 0, 21, 71},
    {1, 1425, 0, "SKTSMSAccessDeniedReason", 2, 0, 2, 2, 216, 0, 21, 74},
    {8, 1425, 0, "SKTSMSRoamingPMN", 2, 0, 2, 2, 216, 0, 21, 77},
    {9, 1425, 0, "MSISDN", 2, 0, 2, 2, 216, 0, 21, 80},
    {-1, 2, 1400, "SecureTransportArg", 80, 2, 1, 0, 8, 226, 12, 0},
    {-1, 2, 1400, "SecureTransportRes", 80, 2, 1, 0, 8, 226, 12, 0},
    {-1, 20, 61, "SystemFailure", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "DataMissing", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "UnexpectedDataValue", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "FacilityNotSupported", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "IncompatibleTerminal", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "ResourceLimitation", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "UnknownSubscriber", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "NumberChanged", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "UnknownMSC", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "UnidentifiedSubscriber", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "UnknownEquipment", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "RoamingNotAllowed", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "IllegalSubscriber", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "IllegalEquipment", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "BearerServiceNotProvisioned", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "TeleserviceNotProvisioned", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "NoHandoverNumberAvailable", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "SubsequentHandoverFailure", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "TargetCellOutsideGroupCallArea", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "TracingBufferFull", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "NoRoamingNumberAvailable", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "AbsentSubscriber", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "BusySubscriber", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "NoSubscriberReply", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "CallBarred", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "ForwardingViolation", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "ForwardingFailed", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "CUG-Reject", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "OR-NotAllowed", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "ATI-NotAllowed", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "ATSI-NotAllowed", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "ATM-NotAllowed", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "InformationNotAvailable", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "IllegalSS-Operation", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "SS-ErrorStatus", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "SS-NotAvailable", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "SS-SubscriptionViolation", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "SS-Incompatibility", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "UnknownAlphabet", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "USSD-Busy", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "PW-RegistrationFailure", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "NegativePW-Check", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "NumberOfPW-AttemptsViolation", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "ShortTermDenial", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "LongTermDenial", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "SubscriberBusyForMT-SMS", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "SM-DeliveryFailure", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "MessageWaitingListFull", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "AbsentSubscriberSM", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "NoGroupCallNumberAvailable", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "UnauthorizedRequestingNetwork", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "UnauthorizedLCSClient", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "PositionMethodFailure", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "UnknownOrUnreachableLCSClient", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "MM-EventNotSupported", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "SecureTransportError", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 1469, 0, "CommonComponentId", 2, 0, 2, 0, 200, 0, 55, 82},
    {-1, 20, 0, "Any", 16, 0, 8, 8, 40, 0, 10, 0},
    {10, 0, 0, "ObjectID", 12, 2, 2, 2, 56, 0, 63, 0},
    {-1, 1469, 0, NULL, 4, 0, 4, 0, 8, 0, 0, 0},
    {0, 1481, 7, NULL, 1, 0, 8, 0, 9, 0, 24, 0},
    {-1, 1483, 0, NULL, 32, 0, 0, 0, 8, 0, 51, 0},
    {-1, 1485, 0, "External_octet_aligned", 16, 0, 4, 8, 40, 0, 20, 0},
    {-1, 1487, 0, "External_arbitrary", 16, 0, 4, 8, 40, 0, 3, 0},
    {-1, 20, 1489, NULL, 40, 3, 2, 8, 8, 258, 13, 0},
    {-1, 1496, 1498, "External", 72, 4, 1, 0, 40, 261, 12, 0},
    {-1, 1469, 0, "Priority", 4, 0, 4, 0, 200, 0, 55, 84},
    {-1, 1469, 0, NULL, 4, 0, 4, 0, 8, 0, 0, 0},
    {-1, 20, 61, "Code", 16, 2, 2, 4, 8, 265, 13, 0},
    {-1, 20, 0, NULL, 2, 0, 0, 0, 8, 0, 50, 0},
    {-1, 1542, 0, NULL, 1, 0, 0, 0, 8, 0, 8, 0},
    {-1, 20, 0, "ERROR", 24, 4, 1, 0, 9, 267, 49, 0},
    {-1, 20, 0, "OPERATION", 56, 12, 2, 0, 9, 271, 49, 0},
    {-1, 20, 0, "OPERATION", 56, 12, 2, 0, 8, 271, 49, 0},
    {-1, 20, 0, "ERROR", 24, 4, 1, 0, 8, 267, 49, 0},
    {-1, 1544, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 20, 21, "InvokeId", 8, 2, 2, 4, 8, 2, 13, 0},
    {-1, 1469, 0, "GeneralProblem", 4, 0, 4, 0, 8, 29, 0, 0},
    {-1, 1469, 0, "InvokeProblem", 4, 0, 4, 0, 8, 34, 0, 0},
    {-1, 1469, 0, "ReturnResultProblem", 4, 0, 4, 0, 8, 44, 0, 0},
    {-1, 1469, 0, "ReturnErrorProblem", 4, 0, 4, 0, 8, 49, 0, 0},
    {-1, 1483, 0, "GeneralProblem", 4, 0, 4, 0, 8, 29, 0, 0},
    {-1, 1485, 0, "InvokeProblem", 4, 0, 4, 0, 8, 34, 0, 0},
    {-1, 1487, 0, "ReturnResultProblem", 4, 0, 4, 0, 8, 44, 0, 0},
    {-1, 1546, 0, "ReturnErrorProblem", 4, 0, 4, 0, 8, 49, 0, 0},
    {-1, 20, 1548, NULL, 8, 4, 2, 4, 8, 283, 13, 0},
    {-1, 20, 61, "OperationCode", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "ErrorCode", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 1557, 1498, "DialoguePortion", 72, 4, 1, 0, 8, 261, 12, 0},
    {-1, 1469, 0, "InvokeIdType", 2, 0, 2, 0, 200, 0, 0, 86},
    {-1, 1483, 0, "InvokeIdType", 2, 0, 2, 0, 200, 0, 0, 88},
    {-1, 20, 0, "Any", 16, 0, 8, 8, 40, 0, 10, 0},
    {-1, 2, 1560, "Invoke", 40, 4, 1, 0, 8, 287, 12, 0},
    {-1, 2, 1580, NULL, 32, 2, 0, 0, 8, 291, 12, 0},
    {-1, 2, 1588, "ReturnResult", 40, 2, 1, 0, 8, 293, 12, 0},
    {-1, 20, 0, "Any", 16, 0, 8, 8, 40, 0, 10, 0},
    {-1, 2, 1596, "ReturnError", 40, 3, 1, 0, 8, 295, 12, 0},
    {-1, 1469, 0, "GeneralProblem", 4, 0, 4, 0, 8, 56, 0, 0},
    {-1, 1469, 0, "InvokeProblem", 4, 0, 4, 0, 8, 61, 0, 0},
    {-1, 1469, 0, "ReturnResultProblem", 4, 0, 4, 0, 8, 71, 0, 0},
    {-1, 1469, 0, "ReturnErrorProblem", 4, 0, 4, 0, 8, 76, 0, 0},
    {-1, 20, 21, NULL, 4, 2, 2, 2, 8, 298, 13, 0},
    {-1, 1483, 0, "GeneralProblem", 4, 0, 4, 0, 8, 56, 0, 0},
    {-1, 1485, 0, "InvokeProblem", 4, 0, 4, 0, 8, 61, 0, 0},
    {-1, 1487, 0, "ReturnResultProblem", 4, 0, 4, 0, 8, 71, 0, 0},
    {-1, 1546, 0, "ReturnErrorProblem", 4, 0, 4, 0, 8, 76, 0, 0},
    {-1, 20, 1548, NULL, 8, 4, 2, 4, 8, 300, 13, 0},
    {-1, 2, 4, "Reject", 12, 2, 0, 0, 8, 304, 12, 0},
    {-1, 1485, 1560, "Invoke", 40, 4, 1, 0, 8, 287, 12, 0},
    {-1, 1487, 1588, "ReturnResult", 40, 2, 1, 0, 8, 293, 12, 0},
    {-1, 1546, 1596, "ReturnError", 40, 3, 1, 0, 8, 295, 12, 0},
    {-1, 1608, 4, "Reject", 12, 2, 0, 0, 8, 304, 12, 0},
    {-1, 1610, 1588, "ReturnResult", 40, 2, 1, 0, 8, 293, 12, 0},
    {-1, 20, 1612, "Component", 48, 5, 2, 8, 8, 306, 13, 0},
    {4, 1623, 0, "ComponentPortion", 2, 48, 2, 8, 216, 254, 17, 90},
    {-1, 2, 1625, "Unidirectional", 280, 2, 1, 0, 8, 311, 12, 0},
    {4, 1635, 0, "OrigTransactionID", 2, 0, 2, 2, 216, 0, 21, 93},
    {-1, 2, 1637, "Begin", 280, 3, 1, 0, 8, 313, 12, 0},
    {4, 1651, 0, "DestTransactionID", 2, 0, 2, 2, 216, 0, 21, 96},
    {-1, 2, 1653, "End", 280, 3, 1, 0, 8, 316, 12, 0},
    {-1, 2, 1667, "Continue", 288, 4, 1, 0, 8, 319, 12, 0},
    {-1, 1685, 0, "P-AbortCause", 4, 0, 4, 0, 8, 83, 0, 0},
    {-1, 20, 1687, NULL, 80, 2, 2, 8, 8, 323, 13, 0},
    {-1, 2, 1692, "Abort", 88, 2, 1, 0, 8, 325, 12, 0},
    {-1, 1702, 1625, "Unidirectional", 280, 2, 1, 0, 8, 311, 12, 0},
    {-1, 44, 1637, "Begin", 280, 3, 1, 0, 8, 313, 12, 0},
    {-1, 1704, 1653, "End", 280, 3, 1, 0, 8, 316, 12, 0},
    {-1, 1706, 1667, "Continue", 288, 4, 1, 0, 8, 319, 12, 0},
    {-1, 1708, 1692, "Abort", 88, 2, 1, 0, 8, 325, 12, 0},
    {1, 1710, 0, "User-information", 2, 72, 2, 8, 216, 206, 17, 99},
    {-1, 1483, 0, "_bit1", 16, 0, 4, 8, 40, 90, 3, 0},
    {10, 1712, 0, "ObjectID", 12, 2, 2, 2, 56, 0, 63, 0},
    {-1, 1715, 1717, "AARQ-apdu", 120, 3, 1, 0, 8, 327, 12, 0},
    {-1, 1469, 0, "Associate-result", 4, 0, 4, 0, 8, 93, 0, 0},
    {-1, 1731, 0, NULL, 4, 0, 4, 0, 8, 97, 0, 0},
    {-1, 1734, 0, NULL, 4, 0, 4, 0, 8, 102, 0, 0},
    {-1, 20, 1737, "Associate-source-diagnostic", 8, 2, 2, 4, 8, 330, 13, 0},
    {-1, 1483, 0, "", 16, 0, 4, 8, 40, 90, 3, 0},
    {10, 1712, 0, "ObjectID", 12, 2, 2, 2, 56, 0, 63, 0},
    {-1, 1734, 0, "Associate-result", 4, 0, 4, 0, 8, 93, 0, 0},
    {-1, 1546, 1737, "Associate-source-diagnostic", 8, 2, 2, 4, 8, 330, 13, 0},
    {-1, 1702, 1742, "AARE-apdu", 128, 5, 1, 0, 8, 332, 12, 0},
    {-1, 1469, 0, "ABRT-source", 4, 0, 4, 0, 8, 107, 0, 0},
    {-1, 1483, 0, "ABRT-source", 4, 0, 4, 0, 8, 107, 0, 0},
    {-1, 1704, 1764, "ABRT-apdu", 88, 2, 1, 0, 8, 337, 12, 0},
    {-1, 1469, 0, "Release-request-reason", 4, 0, 4, 0, 8, 111, 0, 0},
    {-1, 1483, 0, "Release-request-reason", 4, 0, 4, 0, 8, 111, 0, 0},
    {-1, 1469, 0, "Release-response-reason", 4, 0, 4, 0, 8, 116, 0, 0},
    {-1, 1483, 0, "Release-response-reason", 4, 0, 4, 0, 8, 116, 0, 0},
    {-1, 1483, 0, "", 16, 0, 4, 8, 40, 90, 3, 0},
    {10, 1712, 0, "ObjectID", 12, 2, 2, 2, 56, 0, 63, 0},
    {-1, 1715, 1717, "AUDT-apdu", 120, 3, 1, 0, 8, 339, 12, 0},
    {1, 1425, 0, "SS-Code", 2, 0, 2, 2, 216, 0, 21, 102},
    {1, 1425, 0, "BearerServiceCode", 2, 0, 2, 2, 216, 0, 21, 105},
    {1, 1425, 0, "TeleserviceCode", 2, 0, 2, 2, 216, 0, 21, 108},
    {1, 1487, 0, "BearerServiceCode", 2, 0, 2, 2, 216, 0, 21, 111},
    {1, 1546, 0, "TeleserviceCode", 2, 0, 2, 2, 216, 0, 21, 113},
    {-1, 20, 1432, "BasicServiceCode", 6, 2, 2, 2, 8, 342, 13, 0},
    {20, 1425, 0, "AddressString", 2, 0, 2, 2, 216, 0, 21, 115},
    {21, 1425, 0, "ISDN-SubaddressString", 2, 0, 2, 2, 216, 0, 21, 117},
    {-1, 1469, 0, "NoReplyConditionTime", 2, 0, 2, 0, 200, 0, 55, 120},
    {-1, 1469, 0, "EMLPP-Priority", 2, 0, 2, 0, 200, 0, 55, 122},
    {-1, 1469, 0, "MC-Bearers", 2, 0, 2, 0, 200, 0, 55, 124},
    {20, 1608, 0, "AddressString", 2, 0, 2, 2, 216, 0, 21, 126},
    {21, 1772, 0, "ISDN-SubaddressString", 2, 0, 2, 2, 216, 0, 21, 128},
    {-1, 1774, 0, "NoReplyConditionTime", 2, 0, 2, 0, 200, 0, 55, 130},
    {-1, 1610, 0, "EMLPP-Priority", 2, 0, 2, 0, 200, 0, 55, 132},
    {-1, 1776, 0, "MC-Bearers", 2, 0, 2, 0, 200, 0, 55, 134},
    {-1, 1778, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 2, 847, "ForwardingInfo", 16, 2, 1, 0, 12, 344, 12, 0},
    {-1, 2, 847, "CallBarringInfo", 16, 2, 1, 0, 12, 346, 12, 0},
    {1, 1425, 0, "SS-Status", 2, 0, 2, 2, 216, 0, 21, 136},
    {2, 195, 0, "CliRestrictionOption", 4, 0, 4, 0, 24, 121, 58, 0},
    {1, 195, 0, "OverrideCategory", 4, 0, 4, 0, 24, 126, 58, 0},
    {2, 1487, 0, "CliRestrictionOption", 4, 0, 4, 0, 24, 121, 58, 0},
    {1, 1485, 0, "OverrideCategory", 4, 0, 4, 0, 24, 126, 58, 0},
    {-1, 20, 1780, "SS-SubscriptionOption", 8, 2, 2, 4, 8, 348, 13, 0},
    {1, 1608, 0, "SS-Status", 2, 0, 2, 2, 216, 0, 21, 139},
    {-1, 1774, 0, "MC-Bearers", 2, 0, 2, 0, 200, 0, 55, 141},
    {2, 2, 1785, "SS-Data", 40, 6, 1, 0, 2076, 350, 12, 0},
    {-1, 1483, 847, "ForwardingInfo", 16, 2, 1, 0, 12, 344, 12, 0},
    {-1, 1485, 847, "CallBarringInfo", 16, 2, 1, 0, 12, 346, 12, 0},
    {2, 1546, 1785, "SS-Data", 40, 6, 1, 0, 2076, 350, 12, 0},
    {-1, 20, 1845, "SS-Info", 48, 3, 2, 8, 8, 356, 13, 0},
    {9, 1425, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 143},
    {1, 1425, 0, "ForwardingOptions", 2, 0, 2, 2, 216, 0, 21, 145},
    {15, 1425, 0, "FTN-AddressString", 2, 0, 2, 2, 216, 0, 21, 148},
    {1, 1608, 0, "SS-Status", 2, 0, 2, 2, 216, 0, 21, 152},
    {9, 1774, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 154},
    {21, 1776, 0, "ISDN-SubaddressString", 2, 0, 2, 2, 216, 0, 21, 156},
    {1, 1772, 0, "ForwardingOptions", 2, 0, 2, 2, 216, 0, 21, 158},
    {-1, 1610, 0, "NoReplyConditionTime", 2, 0, 2, 0, 200, 0, 55, 160},
    {15, 1778, 0, "FTN-AddressString", 2, 0, 2, 2, 216, 0, 21, 162},
    {1, 2, 1852, "ForwardingFeature", 72, 7, 1, 0, 2076, 359, 12, 0},
    {13, 2, 0, "ForwardingFeatureList", 8, 72, 2, 8, 216, 334, 18, 164},
    {1, 1608, 0, "SS-Status", 2, 0, 2, 2, 216, 0, 21, 167},
    {-1, 2, 1924, "CallBarringFeature", 12, 2, 1, 0, 12, 366, 12, 0},
    {13, 2, 0, "CallBarringFeatureList", 8, 16, 2, 8, 216, 337, 18, 169},
    {-1, 1608, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1469, 0, "MaxMC-Bearers", 2, 0, 2, 0, 200, 0, 55, 172},
    {-1, 1483, 0, "EMLPP-Priority", 2, 0, 2, 0, 200, 0, 55, 174},
    {-1, 1485, 0, "EMLPP-Priority", 2, 0, 2, 0, 200, 0, 55, 176},
    {5, 1487, 0, "CCBS-FeatureList", 8, 48, 2, 8, 216, 353, 18, 178},
    {-1, 1546, 0, "MaxMC-Bearers", 2, 0, 2, 0, 200, 0, 55, 181},
    {-1, 1608, 0, "MC-Bearers", 2, 0, 2, 0, 200, 0, 55, 183},
    {-1, 1774, 0, "MC-Bearers", 2, 0, 2, 0, 200, 0, 55, 185},
    {6, 2, 1936, "GenericServiceInfo", 32, 8, 1, 0, 2076, 368, 12, 0},
    {-1, 1469, 0, "CCBS-Index", 2, 0, 2, 0, 200, 0, 55, 187},
    {-1, 1483, 0, "CCBS-Index", 2, 0, 2, 0, 200, 0, 55, 189},
    {9, 1485, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 191},
    {21, 1487, 0, "ISDN-SubaddressString", 2, 0, 2, 2, 216, 0, 21, 193},
    {-1, 1546, 1432, "BasicServiceCode", 6, 2, 2, 2, 8, 342, 13, 0},
    {-1, 2, 2010, "CCBS-Feature", 46, 4, 1, 0, 12, 376, 12, 0},
    {5, 2, 0, "CCBS-FeatureList", 8, 48, 2, 8, 216, 353, 18, 195},
    {1, 1483, 0, "SS-Status", 2, 0, 2, 2, 216, 0, 21, 197},
    {13, 1487, 0, "BasicServiceGroupList", 8, 8, 2, 8, 216, 298, 18, 199},
    {13, 1546, 0, "ForwardingFeatureList", 8, 72, 2, 8, 216, 334, 18, 202},
    {6, 1608, 1936, "GenericServiceInfo", 32, 8, 1, 0, 2076, 368, 12, 0},
    {1, 1425, 0, "USSD-DataCodingScheme", 2, 0, 2, 2, 216, 0, 21, 204},
    {160, 1425, 0, "USSD-String", 2, 0, 2, 2, 216, 0, 21, 207},
    {1, 1425, 0, "AlertingPattern", 2, 0, 2, 2, 216, 0, 21, 210},
    {9, 1483, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 213},
    {13, 2, 0, "BasicServiceGroupList", 8, 8, 2, 8, 216, 298, 18, 215},
    {8, 1425, 0, "IMSI", 2, 0, 2, 2, 216, 0, 21, 217},
    {-1, 2, 0, "PCS-Extensions", 1, 0, 0, 0, 12, 218, 12, 0},
    {10, 1483, 0, "PrivateExtensionList", 8, 48, 2, 8, 216, 826, 18, 220},
    {-1, 1485, 0, "PCS-Extensions", 1, 0, 0, 0, 12, 218, 12, 0},
    {-1, 2, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {6, 195, 0, "CCBS-RequestState", 4, 0, 4, 0, 24, 130, 58, 0},
    {8, 1483, 0, "IMSI", 2, 0, 2, 2, 216, 0, 21, 223},
    {9, 1485, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 225},
    {1, 1487, 0, "SS-Code", 2, 0, 2, 2, 216, 0, 21, 227},
    {2, 1546, 0, "SS-EventSpecification", 8, 24, 2, 8, 216, 299, 18, 229},
    {-1, 1608, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {9, 1774, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 232},
    {6, 1772, 0, "CCBS-RequestState", 4, 0, 4, 0, 24, 130, 58, 0},
    {2, 2, 0, "SS-EventSpecification", 8, 24, 2, 8, 216, 299, 18, 234},
    {32, 2038, 0, "ServiceIndicator", 16, 0, 2, 8, 216, 139, 3, 236},
    {4, 195, 0, "ProtocolId", 4, 0, 4, 0, 24, 143, 58, 0},
    {200, 1425, 0, "SignalInfo", 2, 0, 2, 2, 216, 0, 21, 239},
    {-1, 2, 1408, "ExternalSignalInfo", 240, 3, 1, 0, 12, 382, 12, 0},
    {-1, 1483, 2010, "CCBS-Feature", 46, 4, 1, 0, 12, 376, 12, 0},
    {9, 1485, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 242},
    {32, 1487, 0, "ServiceIndicator", 16, 0, 2, 8, 216, 139, 3, 244},
    {-1, 1546, 1408, "ExternalSignalInfo", 240, 3, 1, 0, 12, 382, 12, 0},
    {-1, 1608, 1408, "ExternalSignalInfo", 240, 3, 1, 0, 12, 382, 12, 0},
    {-1, 2, 2040, "CCBS-Data", 560, 5, 1, 0, 12, 385, 12, 0},
    {1, 1483, 0, "SS-Code", 2, 0, 2, 2, 216, 0, 21, 246},
    {-1, 1485, 2040, "CCBS-Data", 560, 5, 1, 0, 12, 385, 12, 0},
    {-1, 1483, 2010, "CCBS-Feature", 46, 4, 1, 0, 12, 376, 12, 0},
    {1, 1483, 0, "SS-Code", 2, 0, 2, 2, 216, 0, 21, 248},
    {-1, 1485, 0, "CCBS-Index", 2, 0, 2, 0, 200, 0, 55, 250},
    {1, 1483, 0, "SS-Code", 2, 0, 2, 2, 216, 0, 21, 252},
    {1, 1485, 0, "SS-Status", 2, 0, 2, 2, 216, 0, 21, 254},
    {2, 195, 0, "CliRestrictionOption", 4, 0, 4, 0, 24, 121, 58, 0},
    {32, 1485, 0, "Ext-CwFeatureList", 8, 24, 2, 8, 216, 415, 18, 256},
    {-1, 1487, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 2, 2062, "CallWaitingData", 24, 2, 1, 0, 12, 390, 12, 0},
    {5, 1425, 0, "Ext-SS-Status", 2, 0, 2, 2, 216, 0, 21, 259},
    {5, 1485, 0, "Ext-SS-Status", 2, 0, 2, 2, 216, 0, 21, 262},
    {-1, 1487, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 2, 2062, "CallHoldData", 12, 2, 1, 0, 12, 392, 12, 0},
    {1, 195, 0, "OverrideCategory", 4, 0, 4, 0, 24, 126, 58, 0},
    {5, 1485, 0, "Ext-SS-Status", 2, 0, 2, 2, 216, 0, 21, 264},
    {1, 1487, 0, "OverrideCategory", 4, 0, 4, 0, 24, 126, 58, 0},
    {-1, 1546, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 2, 2070, "ClipData", 20, 3, 1, 0, 12, 394, 12, 0},
    {5, 1425, 0, "Ext-BearerServiceCode", 2, 0, 2, 2, 216, 0, 21, 266},
    {5, 1425, 0, "Ext-TeleserviceCode", 2, 0, 2, 2, 216, 0, 21, 269},
    {5, 1487, 0, "Ext-BearerServiceCode", 2, 0, 2, 2, 216, 0, 21, 272},
    {5, 1546, 0, "Ext-TeleserviceCode", 2, 0, 2, 2, 216, 0, 21, 274},
    {-1, 20, 1432, "Ext-BasicServiceCode", 10, 2, 2, 2, 8, 397, 13, 0},
    {-1, 1485, 1432, "Ext-BasicServiceCode", 10, 2, 2, 2, 8, 397, 13, 0},
    {5, 1487, 0, "Ext-SS-Status", 2, 0, 2, 2, 216, 0, 21, 276},
    {-1, 2, 2062, "Ext-CwFeature", 18, 2, 0, 0, 12, 399, 12, 0},
    {32, 2, 0, "Ext-CwFeatureList", 8, 24, 2, 8, 216, 415, 18, 278},
    {5, 1485, 0, "Ext-SS-Status", 2, 0, 2, 2, 216, 0, 21, 280},
    {-1, 1487, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 2, 2062, "EctData", 12, 2, 1, 0, 12, 401, 12, 0},
    {5, 1485, 0, "Ext-SS-Status", 2, 0, 2, 2, 216, 0, 21, 282},
    {2, 1487, 0, "CliRestrictionOption", 4, 0, 4, 0, 24, 121, 58, 0},
    {-1, 1546, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 2, 2082, "ClirData", 20, 3, 1, 0, 12, 403, 12, 0},
    {32, 2038, 0, "ODB-GeneralData", 16, 0, 2, 8, 216, 149, 3, 284},
    {32, 2038, 0, "ODB-HPLMN-Data", 16, 0, 2, 8, 216, 180, 3, 287},
    {-1, 2, 2096, "ODB-Data", 64, 3, 1, 0, 12, 406, 12, 0},
    {-1, 2, 2110, "ODB-Info", 104, 3, 1, 0, 12, 409, 12, 0},
    {1, 195, 0, "ModificationInstruction", 4, 0, 4, 0, 24, 186, 58, 0},
    {5, 1483, 0, "Ext-SS-Status", 2, 0, 2, 2, 216, 0, 21, 290},
    {1, 1485, 0, "ModificationInstruction", 4, 0, 4, 0, 24, 186, 58, 0},
    {-1, 1487, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 2, 2124, "ModificationRequestFor-ECT-Info", 40, 3, 1, 0, 12, 412, 12, 0},
    {5, 1483, 0, "Ext-SS-Status", 2, 0, 2, 2, 216, 0, 21, 292},
    {1, 1485, 0, "OverrideCategory", 4, 0, 4, 0, 24, 126, 58, 0},
    {1, 1487, 0, "ModificationInstruction", 4, 0, 4, 0, 24, 186, 58, 0},
    {-1, 1546, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 2, 2010, "ModificationRequestFor-CLIP-Info", 48, 4, 1, 0, 12, 415, 12, 0},
    {5, 1483, 0, "Ext-SS-Status", 2, 0, 2, 2, 216, 0, 21, 294},
    {1, 1485, 0, "ModificationInstruction", 4, 0, 4, 0, 24, 186, 58, 0},
    {-1, 1487, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 2, 2124, "ModificationRequestFor-CH-Info", 40, 3, 1, 0, 12, 419, 12, 0},
    {5, 1483, 0, "Ext-SS-Status", 2, 0, 2, 2, 216, 0, 21, 296},
    {2, 1485, 0, "CliRestrictionOption", 4, 0, 4, 0, 24, 121, 58, 0},
    {1, 1487, 0, "ModificationInstruction", 4, 0, 4, 0, 24, 186, 58, 0},
    {-1, 1546, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 2, 2010, "ModificationRequestFor-CLIR-Info", 48, 4, 1, 0, 12, 422, 12, 0},
    {-1, 1483, 1432, "Ext-BasicServiceCode", 10, 2, 2, 2, 8, 397, 13, 0},
    {5, 1485, 0, "Ext-SS-Status", 2, 0, 2, 2, 216, 0, 21, 298},
    {1, 1487, 0, "ModificationInstruction", 4, 0, 4, 0, 24, 186, 58, 0},
    {-1, 1546, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 2, 2010, "ModificationRequestFor-CW-Info", 48, 4, 1, 0, 12, 426, 12, 0},
    {1, 1483, 0, "ModificationInstruction", 4, 0, 4, 0, 24, 186, 58, 0},
    {-1, 1485, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 2, 1390, "ModificationRequestFor-CSG", 32, 2, 1, 0, 12, 430, 12, 0},
    {1, 1483, 0, "SS-Code", 2, 0, 2, 2, 216, 0, 21, 300},
    {32, 1485, 0, "Ext-ForwFeatureList", 8, 120, 2, 8, 216, 482, 18, 302},
    {-1, 1487, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1546, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 2, 749, "Ext-ForwardingInfoFor-CSE", 48, 4, 1, 0, 12, 432, 12, 0},
    {5, 193, 18, "Password", 1, 0, 2, 0, 16600, 0, 24, 305},
    {-1, 1469, 0, "WrongPasswordAttemptsCounter", 2, 0, 2, 0, 200, 0, 55, 310},
    {1, 1483, 0, "SS-Code", 2, 0, 2, 2, 216, 0, 21, 312},
    {32, 1485, 0, "Ext-CallBarFeatureList", 8, 48, 2, 8, 216, 497, 18, 314},
    {5, 1487, 18, "Password", 1, 0, 2, 0, 16600, 0, 24, 317},
    {-1, 1546, 0, "WrongPasswordAttemptsCounter", 2, 0, 2, 0, 200, 0, 55, 319},
    {-1, 1608, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1774, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 2, 2142, "Ext-CallBarringInfoFor-CSE", 56, 6, 1, 0, 12, 436, 12, 0},
    {-1, 1483, 749, "Ext-ForwardingInfoFor-CSE", 48, 4, 1, 0, 12, 432, 12, 0},
    {-1, 1485, 2142, "Ext-CallBarringInfoFor-CSE", 56, 6, 1, 0, 12, 436, 12, 0},
    {-1, 20, 1427, "Ext-SS-InfoFor-CSE", 64, 2, 2, 8, 8, 442, 13, 0},
    {21, 1425, 0, "ISDN-SubaddressString", 2, 0, 2, 2, 216, 0, 21, 321},
    {5, 1425, 0, "Ext-ForwOptions", 2, 0, 2, 2, 216, 0, 21, 324},
    {-1, 1469, 0, "Ext-NoRepCondTime", 2, 0, 2, 0, 200, 0, 55, 327},
    {5, 1608, 0, "Ext-SS-Status", 2, 0, 2, 2, 216, 0, 21, 329},
    {9, 1774, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 331},
    {21, 1776, 0, "ISDN-SubaddressString", 2, 0, 2, 2, 216, 0, 21, 333},
    {5, 1772, 0, "Ext-ForwOptions", 2, 0, 2, 2, 216, 0, 21, 335},
    {-1, 1610, 0, "Ext-NoRepCondTime", 2, 0, 2, 0, 200, 0, 55, 337},
    {-1, 1778, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {15, 2166, 0, "FTN-AddressString", 2, 0, 2, 2, 216, 0, 21, 339},
    {1, 2, 2168, "Ext-ForwFeature", 120, 8, 1, 0, 2076, 444, 12, 0},
    {32, 2, 0, "Ext-ForwFeatureList", 8, 120, 2, 8, 216, 482, 18, 341},
    {8, 2038, 0, "RequestedServingNode", 16, 0, 2, 8, 216, 190, 3, 343},
    {1, 1425, 0, "CauseValue", 2, 0, 2, 2, 216, 0, 21, 346},
    {8, 1483, 0, "IMSI", 2, 0, 2, 2, 216, 0, 21, 349},
    {9, 1485, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 351},
    {-1, 20, 1427, "SubscriberIdentity", 14, 2, 2, 2, 8, 452, 13, 0},
    {-1, 1469, 0, "CamelCapabilityHandling", 2, 0, 2, 0, 200, 0, 55, 353},
    {10, 1483, 0, "GPRS-CamelTDPDataList", 8, 56, 2, 8, 216, 539, 18, 355},
    {-1, 1485, 0, "CamelCapabilityHandling", 2, 0, 2, 0, 200, 0, 55, 358},
    {-1, 1487, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 1546, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1608, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 2, 2234, "GPRS-CSI", 56, 5, 1, 0, 12, 454, 12, 0},
    {5, 1608, 0, "Ext-SS-Status", 2, 0, 2, 2, 216, 0, 21, 360},
    {-1, 2, 2274, "Ext-CallBarringFeature", 48, 3, 1, 0, 12, 459, 12, 0},
    {32, 2, 0, "Ext-CallBarFeatureList", 8, 48, 2, 8, 216, 497, 18, 362},
    {8, 195, 0, "RequestedCAMEL-SubscriptionInfo", 4, 0, 4, 0, 24, 193, 58, 0},
    {8, 1483, 0, "RequestedCAMEL-SubscriptionInfo", 4, 0, 4, 0, 24, 193, 58, 0},
    {1, 1485, 0, "ModificationInstruction", 4, 0, 4, 0, 24, 186, 58, 0},
    {1, 1487, 0, "ModificationInstruction", 4, 0, 4, 0, 24, 186, 58, 0},
    {-1, 1546, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 2, 2290, "ModificationRequestFor-CSI", 40, 4, 1, 0, 12, 462, 12, 0},
    {-1, 1469, 0, "ServiceKey", 4, 0, 4, 0, 200, 0, 55, 364},
    {9, 1483, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 366},
    {-1, 1485, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 1487, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1546, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 2, 2312, "M-CSI", 64, 6, 1, 0, 12, 466, 12, 0},
    {-1, 1483, 0, "CamelCapabilityHandling", 2, 0, 2, 0, 200, 0, 55, 368},
    {-1, 1485, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1487, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {3, 2, 2342, "O-CSI", 48, 5, 1, 0, 2076, 472, 12, 0},
    {10, 1483, 0, "DP-AnalysedInfoCriteriaList", 8, 64, 2, 8, 216, 586, 18, 370},
    {-1, 1485, 0, "CamelCapabilityHandling", 2, 0, 2, 0, 200, 0, 55, 373},
    {-1, 1487, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 1546, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1608, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 2, 2234, "D-CSI", 56, 5, 1, 0, 12, 477, 12, 0},
    {-1, 1483, 0, "CamelCapabilityHandling", 2, 0, 2, 0, 200, 0, 55, 375},
    {-1, 1485, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1487, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {3, 2, 2342, "T-CSI", 48, 5, 1, 0, 2076, 482, 12, 0},
    {-1, 1483, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 1485, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1487, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {2, 2, 2374, "SS-CamelData", 64, 5, 1, 0, 2076, 487, 12, 0},
    {-1, 1483, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1485, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {2, 2, 2400, "SS-CSI", 104, 4, 1, 0, 2076, 492, 12, 0},
    {INT_MAX, 195, 0, "GPRS-TriggerDetectionPoint", 4, 0, 4, 0, 2076, 204, 6, 0},
    {INT_MAX, 195, 0, "DefaultGPRS-Handling", 4, 0, 4, 0, 2076, 214, 6, 0},
    {INT_MAX, 1483, 0, "GPRS-TriggerDetectionPoint", 4, 0, 4, 0, 2076, 204, 6, 0},
    {-1, 1485, 0, "ServiceKey", 4, 0, 4, 0, 200, 0, 55, 377},
    {9, 1487, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 379},
    {INT_MAX, 1546, 0, "DefaultGPRS-Handling", 4, 0, 4, 0, 2076, 214, 6, 0},
    {-1, 1608, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 2, 1449, "GPRS-CamelTDPData", 56, 5, 1, 0, 12, 496, 12, 0},
    {10, 2, 0, "GPRS-CamelTDPDataList", 8, 56, 2, 8, 216, 539, 18, 381},
    {1, 1425, 0, "MM-Code", 2, 0, 2, 2, 216, 0, 21, 383},
    {10, 2, 0, "MobilityTriggers", 8, 8, 2, 8, 216, 541, 18, 386},
    {10, 1483, 0, "SMS-CAMEL-TDP-DataList", 8, 56, 2, 8, 216, 584, 18, 389},
    {-1, 1485, 0, "CamelCapabilityHandling", 2, 0, 2, 0, 200, 0, 55, 392},
    {-1, 1487, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 1546, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1608, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 2, 2234, "SMS-CSI", 56, 5, 1, 0, 12, 501, 12, 0},
    {3, 1483, 2342, "O-CSI", 48, 5, 1, 0, 2076, 472, 12, 0},
    {10, 1485, 0, "O-BcsmCamelTDPCriteriaList", 8, 80, 2, 8, 216, 605, 18, 394},
    {-1, 1487, 2234, "D-CSI", 56, 5, 1, 0, 12, 477, 12, 0},
    {3, 1546, 2342, "T-CSI", 48, 5, 1, 0, 2076, 482, 12, 0},
    {10, 1608, 0, "T-BCSM-CAMEL-TDP-CriteriaList", 8, 24, 2, 8, 216, 609, 18, 397},
    {3, 1774, 2342, "T-CSI", 48, 5, 1, 0, 2076, 482, 12, 0},
    {10, 1772, 0, "T-BCSM-CAMEL-TDP-CriteriaList", 8, 24, 2, 8, 216, 609, 18, 400},
    {-1, 1610, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1776, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1778, 2234, "GPRS-CSI", 56, 5, 1, 0, 12, 454, 12, 0},
    {-1, 2166, 2234, "SMS-CSI", 56, 5, 1, 0, 12, 501, 12, 0},
    {2, 2422, 2400, "SS-CSI", 104, 4, 1, 0, 2076, 492, 12, 0},
    {-1, 2424, 2312, "M-CSI", 64, 6, 1, 0, 12, 466, 12, 0},
    {-1, 2426, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 2, 2428, "CAMEL-SubscriptionInfo", 544, 14, 2, 0, 12, 506, 12, 0},
    {INT_MAX, 195, 0, "O-BcsmTriggerDetectionPoint", 4, 0, 4, 0, 2076, 221, 6, 0},
    {INT_MAX, 195, 0, "DefaultCallHandling", 4, 0, 4, 0, 2076, 228, 6, 0},
    {9, 1483, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 402},
    {INT_MAX, 1485, 0, "DefaultCallHandling", 4, 0, 4, 0, 2076, 228, 6, 0},
    {-1, 1487, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 2, 2666, "O-BcsmCamelTDPData", 56, 5, 1, 0, 12, 520, 12, 0},
    {10, 2, 0, "O-BcsmCamelTDPDataList", 8, 56, 2, 8, 216, 569, 18, 404},
    {INT_MAX, 195, 0, "T-BcsmTriggerDetectionPoint", 4, 0, 4, 0, 2076, 235, 6, 0},
    {9, 1483, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 407},
    {INT_MAX, 1485, 0, "DefaultCallHandling", 4, 0, 4, 0, 2076, 228, 6, 0},
    {-1, 1487, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 2, 2666, "T-BcsmCamelTDPData", 56, 5, 1, 0, 12, 525, 12, 0},
    {10, 2, 0, "T-BcsmCamelTDPDataList", 8, 56, 2, 8, 216, 575, 18, 409},
    {INT_MAX, 195, 0, "SMS-TriggerDetectionPoint", 4, 0, 4, 0, 2076, 243, 6, 0},
    {INT_MAX, 195, 0, "DefaultSMS-Handling", 4, 0, 4, 0, 2076, 214, 6, 0},
    {INT_MAX, 1483, 0, "SMS-TriggerDetectionPoint", 4, 0, 4, 0, 2076, 243, 6, 0},
    {-1, 1485, 0, "ServiceKey", 4, 0, 4, 0, 200, 0, 55, 412},
    {9, 1487, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 414},
    {INT_MAX, 1546, 0, "DefaultSMS-Handling", 4, 0, 4, 0, 2076, 214, 6, 0},
    {-1, 1608, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 2, 1449, "SMS-CAMEL-TDP-Data", 56, 5, 1, 0, 12, 530, 12, 0},
    {10, 2, 0, "SMS-CAMEL-TDP-DataList", 8, 56, 2, 8, 216, 584, 18, 416},
    {-1, 2, 2686, "DP-AnalysedInfoCriterium", 64, 5, 1, 0, 12, 535, 12, 0},
    {10, 2, 0, "DP-AnalysedInfoCriteriaList", 8, 64, 2, 8, 216, 586, 18, 418},
    {1, 195, 0, "MatchType", 4, 0, 4, 0, 24, 249, 58, 0},
    {1, 1483, 0, "MatchType", 4, 0, 4, 0, 24, 249, 58, 0},
    {10, 1485, 0, "DestinationNumberList", 8, 16, 2, 8, 216, 325, 18, 420},
    {3, 1487, 0, "DestinationNumberLengthList", 8, 8, 2, 8, 216, 594, 18, 423},
    {-1, 2, 2706, "DestinationNumberCriteria", 24, 3, 1, 0, 12, 540, 12, 0},
    {10, 2, 0, "DestinationNumberList", 8, 16, 2, 8, 216, 325, 18, 426},
    {-1, 1469, 0, NULL, 2, 0, 2, 0, 200, 0, 55, 428},
    {3, 2, 0, "DestinationNumberLengthList", 8, 8, 2, 8, 216, 594, 18, 430},
    {1, 195, 0, "CallTypeCriteria", 4, 0, 4, 0, 24, 253, 58, 0},
    {5, 2, 0, "O-CauseValueCriteria", 8, 8, 2, 8, 216, 485, 18, 432},
    {5, 2, 0, "T-CauseValueCriteria", 8, 8, 2, 8, 216, 485, 18, 435},
    {5, 2, 0, "BasicServiceCriteria", 8, 16, 2, 8, 216, 412, 18, 438},
    {-1, 1483, 2706, "DestinationNumberCriteria", 24, 3, 1, 0, 12, 540, 12, 0},
    {5, 1485, 0, "BasicServiceCriteria", 8, 16, 2, 8, 216, 412, 18, 441},
    {1, 1487, 0, "CallTypeCriteria", 4, 0, 4, 0, 24, 253, 58, 0},
    {5, 1546, 0, "O-CauseValueCriteria", 8, 8, 2, 8, 216, 485, 18, 443},
    {-1, 1608, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {2, 2, 2720, "O-BcsmCamelTDP-Criteria", 80, 6, 1, 0, 2076, 543, 12, 0},
    {10, 2, 0, "O-BcsmCamelTDPCriteriaList", 8, 80, 2, 8, 216, 605, 18, 445},
    {5, 1483, 0, "BasicServiceCriteria", 8, 16, 2, 8, 216, 412, 18, 447},
    {5, 1485, 0, "T-CauseValueCriteria", 8, 8, 2, 8, 216, 485, 18, 449},
    {-1, 2, 2764, "T-BCSM-CAMEL-TDP-Criteria", 24, 3, 1, 0, 12, 549, 12, 0},
    {10, 2, 0, "T-BCSM-CAMEL-TDP-CriteriaList", 8, 24, 2, 8, 216, 609, 18, 451},
    {10, 2, 0, "SS-EventList", 8, 8, 2, 8, 216, 293, 18, 453},
    {1, 1483, 0, "SS-Code", 2, 0, 2, 2, 216, 0, 21, 456},
    {-1, 1485, 1432, "Ext-BasicServiceCode", 10, 2, 2, 2, 8, 397, 13, 0},
    {5, 1487, 0, "Ext-SS-Status", 2, 0, 2, 2, 216, 0, 21, 458},
    {20, 1546, 0, "AddressString", 2, 0, 2, 2, 216, 0, 21, 460},
    {21, 1608, 0, "ISDN-SubaddressString", 2, 0, 2, 2, 216, 0, 21, 462},
    {-1, 1774, 0, "Ext-NoRepCondTime", 2, 0, 2, 0, 200, 0, 55, 464},
    {1, 1772, 0, "ModificationInstruction", 4, 0, 4, 0, 24, 186, 58, 0},
    {-1, 1610, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 2, 2778, "ModificationRequestFor-CF-Info", 104, 8, 1, 0, 12, 552, 12, 0},
    {1, 1483, 0, "SS-Code", 2, 0, 2, 2, 216, 0, 21, 466},
    {-1, 1485, 1432, "Ext-BasicServiceCode", 10, 2, 2, 2, 8, 397, 13, 0},
    {5, 1487, 0, "Ext-SS-Status", 2, 0, 2, 2, 216, 0, 21, 468},
    {5, 1546, 18, "Password", 1, 0, 2, 0, 16600, 0, 24, 470},
    {-1, 1608, 0, "WrongPasswordAttemptsCounter", 2, 0, 2, 0, 200, 0, 55, 472},
    {1, 1774, 0, "ModificationInstruction", 4, 0, 4, 0, 24, 186, 58, 0},
    {-1, 1772, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 2, 2852, "ModificationRequestFor-CB-Info", 64, 7, 1, 0, 12, 560, 12, 0},
    {1, 1483, 0, "ModificationInstruction", 4, 0, 4, 0, 24, 186, 58, 0},
    {-1, 1485, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 2, 1390, "ModificationRequestFor-IP-SM-GW-Data", 32, 2, 1, 0, 12, 567, 12, 0},
    {-1, 1483, 2096, "ODB-Data", 64, 3, 1, 0, 12, 406, 12, 0},
    {1, 1485, 0, "ModificationInstruction", 4, 0, 4, 0, 24, 186, 58, 0},
    {-1, 1487, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 2, 2124, "ModificationRequestFor-ODB-data", 104, 3, 1, 0, 12, 569, 12, 0},
    {-1, 1483, 1427, "SubscriberIdentity", 14, 2, 2, 2, 8, 452, 13, 0},
    {9, 1485, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 474},
    {-1, 1487, 2778, "ModificationRequestFor-CF-Info", 104, 8, 1, 0, 12, 552, 12, 0},
    {-1, 1546, 2852, "ModificationRequestFor-CB-Info", 64, 7, 1, 0, 12, 560, 12, 0},
    {-1, 1608, 2290, "ModificationRequestFor-CSI", 40, 4, 1, 0, 12, 462, 12, 0},
    {-1, 1774, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 1772, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1610, 2124, "ModificationRequestFor-ODB-data", 104, 3, 1, 0, 12, 569, 12, 0},
    {-1, 1776, 1390, "ModificationRequestFor-IP-SM-GW-Data", 32, 2, 1, 0, 12, 567, 12, 0},
    {8, 1778, 0, "RequestedServingNode", 16, 0, 2, 8, 216, 190, 3, 476},
    {-1, 2166, 1390, "ModificationRequestFor-CSG", 32, 2, 1, 0, 12, 430, 12, 0},
    {-1, 2422, 2010, "ModificationRequestFor-CW-Info", 48, 4, 1, 0, 12, 426, 12, 0},
    {-1, 2424, 2010, "ModificationRequestFor-CLIP-Info", 48, 4, 1, 0, 12, 415, 12, 0},
    {-1, 2426, 2010, "ModificationRequestFor-CLIR-Info", 48, 4, 1, 0, 12, 422, 12, 0},
    {-1, 2910, 2124, "ModificationRequestFor-CH-Info", 40, 3, 1, 0, 12, 419, 12, 0},
    {-1, 2912, 2124, "ModificationRequestFor-ECT-Info", 40, 3, 1, 0, 12, 412, 12, 0},
    {-1, 1483, 1427, "Ext-SS-InfoFor-CSE", 64, 2, 2, 8, 8, 442, 13, 0},
    {-1, 1485, 2428, "CAMEL-SubscriptionInfo", 544, 14, 2, 0, 12, 506, 12, 0},
    {-1, 1487, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 1546, 2110, "ODB-Info", 104, 3, 1, 0, 12, 409, 12, 0},
    {-1, 1608, 2062, "CallWaitingData", 24, 2, 1, 0, 12, 390, 12, 0},
    {-1, 1774, 2062, "CallHoldData", 12, 2, 1, 0, 12, 392, 12, 0},
    {-1, 1772, 2070, "ClipData", 20, 3, 1, 0, 12, 394, 12, 0},
    {-1, 1610, 2082, "ClirData", 20, 3, 1, 0, 12, 403, 12, 0},
    {-1, 1776, 2062, "EctData", 12, 2, 1, 0, 12, 401, 12, 0},
    {-1, 1469, 0, "SM-RP-MTI", 2, 0, 2, 0, 200, 0, 55, 478},
    {12, 1425, 0, "SM-RP-SMEA", 2, 0, 2, 2, 216, 0, 21, 480},
    {INT_MAX, 195, 0, "SM-DeliveryNotIntended", 4, 0, 4, 0, 2076, 257, 6, 0},
    {8, 1425, 0, "HLR-Id", 2, 0, 2, 2, 216, 0, 21, 483},
    {-1, 1425, 0, "SIP-URI", 16, 0, 4, 8, 8, 0, 20, 0},
    {8, 1483, 0, "HLR-Id", 2, 0, 2, 2, 216, 0, 21, 485},
    {-1, 1485, 0, "SIP-URI", 16, 0, 4, 8, 8, 0, 20, 0},
    {-1, 1487, 0, "SIP-URI", 16, 0, 4, 8, 8, 0, 20, 0},
    {-1, 2, 2124, "CorrelationID", 48, 3, 1, 0, 8, 572, 12, 0},
    {9, 1483, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 487},
    {-1, 1485, 0, NULL, 1, 0, 0, 0, 8, 0, 8, 0},
    {20, 1487, 0, "AddressString", 2, 0, 2, 2, 216, 0, 21, 489},
    {-1, 1772, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 1610, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1776, 0, "SM-RP-MTI", 2, 0, 2, 0, 200, 0, 55, 491},
    {12, 1778, 0, "SM-RP-SMEA", 2, 0, 2, 2, 216, 0, 21, 493},
    {INT_MAX, 2166, 0, "SM-DeliveryNotIntended", 4, 0, 4, 0, 2076, 257, 6, 0},
    {-1, 2422, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {8, 2424, 0, "IMSI", 2, 0, 2, 2, 216, 0, 21, 495},
    {-1, 2910, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 2426, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 2912, 2124, "CorrelationID", 48, 3, 1, 0, 8, 572, 12, 0},
    {9, 1483, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 497},
    {-1, 1485, 0, NULL, 1, 0, 0, 0, 8, 0, 8, 0},
    {20, 1487, 0, "AddressString", 2, 0, 2, 2, 216, 0, 21, 499},
    {1, 1546, 0, "TeleserviceCode", 2, 0, 2, 2, 216, 0, 21, 501},
    {4, 1425, 0, "LMSI", 2, 0, 2, 2, 216, 0, 21, 503},
    {9, 1483, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 506},
    {9, 1485, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 508},
    {-1, 20, 1427, "Additional-Number", 14, 2, 2, 2, 8, 575, 13, 0},
    {255, 1425, 0, "DiameterIdentity", 2, 0, 2, 2, 216, 0, 21, 510},
    {255, 1483, 0, "DiameterIdentity", 2, 0, 2, 2, 216, 0, 21, 513},
    {255, 1485, 0, "DiameterIdentity", 2, 0, 2, 2, 216, 0, 21, 515},
    {-1, 2, 241, "NetworkNodeDiameterAddress", 516, 2, 0, 0, 8, 577, 12, 0},
    {9, 1485, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 517},
    {-1, 1774, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1772, 1427, "Additional-Number", 14, 2, 2, 2, 8, 575, 13, 0},
    {-1, 1610, 241, "NetworkNodeDiameterAddress", 516, 2, 0, 0, 8, 577, 12, 0},
    {-1, 1776, 241, "NetworkNodeDiameterAddress", 516, 2, 0, 0, 8, 577, 12, 0},
    {-1, 1778, 1427, "Additional-Number", 14, 2, 2, 2, 8, 575, 13, 0},
    {-1, 2166, 241, "NetworkNodeDiameterAddress", 516, 2, 0, 0, 8, 577, 12, 0},
    {-1, 2422, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {7, 2, 2914, "LocationInfoWithLMSI-V3", 1632, 10, 2, 0, 2076, 579, 12, 0},
    {-1, 1469, 0, "SM-DeliveryTimerValue", 2, 0, 2, 0, 200, 0, 55, 519},
    {-1, 2, 1437, "IP-SM-GW-Guidance", 32, 3, 1, 0, 12, 589, 12, 0},
    {7, 1483, 2914, "LocationInfoWithLMSI-V3", 1632, 10, 2, 0, 2076, 579, 12, 0},
    {-1, 1608, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 1774, 1437, "IP-SM-GW-Guidance", 32, 3, 1, 0, 12, 589, 12, 0},
    {9, 1483, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 521},
    {9, 1485, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 523},
    {-1, 20, 1427, "LocationInfo", 14, 2, 2, 2, 8, 592, 13, 0},
    {-1, 2, 3026, "LocationInfoWithLMSI-V2", 22, 2, 1, 0, 12, 594, 12, 0},
    {-1, 1483, 3026, "LocationInfoWithLMSI-V2", 22, 2, 1, 0, 12, 594, 12, 0},
    {-1, 1487, 0, NULL, 1, 0, 0, 0, 8, 0, 8, 0},
    {8, 1483, 0, "IMSI", 2, 0, 2, 2, 216, 0, 21, 525},
    {4, 1485, 0, "LMSI", 2, 0, 2, 2, 216, 0, 21, 527},
    {9, 1546, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 529},
    {20, 1608, 0, "AddressString", 2, 0, 2, 2, 216, 0, 21, 531},
    {-1, 1774, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 20, 3036, "SM-RP-DA", 24, 5, 2, 2, 8, 596, 13, 0},
    {9, 1487, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 533},
    {20, 1608, 0, "AddressString", 2, 0, 2, 2, 216, 0, 21, 535},
    {-1, 1774, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 20, 3047, "SM-RP-OA", 24, 3, 2, 2, 8, 601, 13, 0},
    {2, 195, 0, "SM-DeliveryOutcome", 4, 0, 4, 0, 24, 264, 58, 0},
    {-1, 1483, 2124, "CorrelationID", 48, 3, 1, 0, 8, 572, 12, 0},
    {2, 1485, 0, "SM-DeliveryOutcome", 4, 0, 4, 0, 24, 264, 58, 0},
    {4, 1425, 0, "Time", 2, 0, 2, 2, 216, 0, 21, 537},
    {-1, 1483, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1485, 2124, "CorrelationID", 48, 3, 1, 0, 8, 572, 12, 0},
    {4, 1487, 0, "Time", 2, 0, 2, 2, 216, 0, 21, 540},
    {4, 1483, 0, "Time", 2, 0, 2, 2, 216, 0, 21, 542},
    {-1, 1469, 0, "AbsentSubscriberDiagnosticSM", 2, 0, 2, 0, 200, 0, 55, 544},
    {-1, 1483, 0, "AbsentSubscriberDiagnosticSM", 2, 0, 2, 0, 200, 0, 55, 546},
    {-1, 1485, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 1487, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1546, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {2, 1608, 0, "SM-DeliveryOutcome", 4, 0, 4, 0, 24, 264, 58, 0},
    {-1, 1774, 0, "AbsentSubscriberDiagnosticSM", 2, 0, 2, 0, 200, 0, 55, 548},
    {-1, 1772, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {2, 1610, 0, "SM-DeliveryOutcome", 4, 0, 4, 0, 24, 264, 58, 0},
    {-1, 1776, 0, "AbsentSubscriberDiagnosticSM", 2, 0, 2, 0, 200, 0, 55, 550},
    {8, 1778, 0, "IMSI", 2, 0, 2, 2, 216, 0, 21, 552},
    {-1, 2166, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 2422, 2124, "CorrelationID", 48, 3, 1, 0, 8, 572, 12, 0},
    {16, 2038, 0, "MW-Status", 2, 0, 2, 0, 216, 269, 1, 554},
    {1, 195, 0, "AlertReason", 4, 0, 4, 0, 24, 276, 58, 0},
    {8, 1483, 0, "IMSI", 2, 0, 2, 2, 216, 0, 21, 557},
    {-1, 1485, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {3, 195, 0, "RoamingNotAllowedCause", 4, 0, 4, 0, 24, 280, 58, 0},
    {1, 195, 0, "CallBarringCause", 4, 0, 4, 0, 24, 284, 58, 0},
    {-1, 1485, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {1, 2, 3054, "ExtensibleCallBarredParam", 40, 3, 1, 0, 2076, 604, 12, 0},
    {7, 195, 0, "CUG-RejectCause", 4, 0, 4, 0, 24, 288, 58, 0},
    {1, 1485, 0, "SS-Code", 2, 0, 2, 2, 216, 0, 21, 559},
    {1, 1608, 0, "SS-Status", 2, 0, 2, 2, 216, 0, 21, 561},
    {6, 195, 0, "SM-EnumeratedDeliveryFailureCause", 4, 0, 4, 0, 24, 294, 58, 0},
    {-1, 1483, 0, "AbsentSubscriberDiagnosticSM", 2, 0, 2, 0, 200, 0, 55, 563},
    {7, 195, 0, "NetworkResource", 4, 0, 4, 0, 24, 303, 58, 0},
    {-1, 2, 1278, "ExtensibleSystemFailureParam", 32, 2, 1, 0, 12, 607, 12, 0},
    {INT_MAX, 195, 0, "UnknownSubscriberDiagnostic", 4, 0, 4, 0, 2076, 313, 6, 0},
    {INT_MAX, 195, 0, "AbsentSubscriberReason", 4, 0, 4, 0, 2076, 321, 6, 0},
    {INT_MAX, 1483, 0, "AbsentSubscriberReason", 4, 0, 4, 0, 2076, 321, 6, 0},
    {-1, 1483, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 1485, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {INT_MAX, 195, 0, "UnauthorizedLCSClient-Diagnostic", 4, 0, 4, 0, 2076, 330, 6, 0},
    {INT_MAX, 1483, 0, "UnauthorizedLCSClient-Diagnostic", 4, 0, 4, 0, 2076, 330, 6, 0},
    {-1, 1485, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {INT_MAX, 195, 0, "PositionMethodFailure-Diagnostic", 4, 0, 4, 0, 2076, 340, 6, 0},
    {INT_MAX, 1483, 0, "PositionMethodFailure-Diagnostic", 4, 0, 4, 0, 2076, 340, 6, 0},
    {-1, 1485, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 20, 61, "OperationCode", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 20, 61, "ErrorCode", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 1483, 61, "OperationCode", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 1485, 61, "ErrorCode", 16, 2, 2, 4, 8, 17, 13, 0},
    {-1, 1487, 0, NULL, 1, 0, 0, 0, 8, 0, 5, 0},
    {-1, 20, 1489, "OriginalComponentIdentifier", 20, 3, 2, 4, 8, 609, 13, 0},
    {3, 1425, 0, "PLMN-Id", 2, 0, 2, 2, 216, 0, 21, 565},
    {2, 195, 0, "ProtectionMode", 4, 0, 4, 0, 24, 354, 58, 0},
    {-1, 1469, 0, "EncryptionAlgorithmIdentifier", 2, 0, 2, 0, 200, 0, 55, 568},
    {INT_MAX, 195, 0, "ModeOfOperation", 4, 0, 4, 0, 2076, 359, 6, 0},
    {-1, 1469, 0, "EncryptionKeyVersionNumber", 2, 0, 2, 0, 200, 0, 55, 570},
    {8, 1425, 0, "InitialisationVector", 2, 0, 2, 2, 216, 0, 21, 572},
    {-1, 1469, 0, "HashAlgorithmIdentifier", 2, 0, 2, 0, 200, 0, 55, 575},
    {-1, 1469, 0, "HashKeyVersionNumber", 2, 0, 2, 0, 200, 0, 55, 577},
    {2, 1483, 0, "ProtectionMode", 4, 0, 4, 0, 24, 354, 58, 0},
    {-1, 1485, 0, "EncryptionAlgorithmIdentifier", 2, 0, 2, 0, 200, 0, 55, 579},
    {INT_MAX, 1487, 0, "ModeOfOperation", 4, 0, 4, 0, 2076, 359, 6, 0},
    {-1, 1546, 0, "EncryptionKeyVersionNumber", 2, 0, 2, 0, 200, 0, 55, 581},
    {8, 1608, 0, "InitialisationVector", 2, 0, 2, 2, 216, 0, 21, 583},
    {-1, 1774, 0, "HashAlgorithmIdentifier", 2, 0, 2, 0, 200, 0, 55, 585},
    {-1, 1772, 0, "HashKeyVersionNumber", 2, 0, 2, 0, 200, 0, 55, 587},
    {-1, 2, 3072, "SecurityHeader", 60, 9, 1, 0, 12, 612, 12, 0},
    {1000, 1425, 0, "ProtectedPayload", 16, 0, 2, 8, 216, 0, 20, 589},
    {INT_MAX, 195, 0, "Ext-ProtocolId", 4, 0, 4, 0, 2076, 368, 6, 0},
    {INT_MAX, 195, 0, "AccessNetworkProtocolId", 4, 0, 4, 0, 2076, 374, 6, 0},
    {-1, 2, 185, "IMSI-WithLMSI", 16, 2, 0, 0, 12, 621, 12, 0},
    {4, 1425, 0, "TMSI", 2, 0, 2, 2, 216, 0, 21, 592},
    {8, 1483, 0, "IMSI", 2, 0, 2, 2, 216, 0, 21, 595},
    {4, 1485, 0, "TMSI", 2, 0, 2, 2, 216, 0, 21, 597},
    {3, 1425, 0, "NAEA-CIC", 2, 0, 2, 2, 216, 0, 21, 599},
    {3, 1483, 0, "NAEA-CIC", 2, 0, 2, 2, 216, 0, 21, 602},
    {-1, 1485, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {8, 1483, 0, "IMSI", 2, 0, 2, 2, 216, 0, 21, 604},
    {9, 1485, 0, "ISDN-AddressString", 2, 0, 2, 2, 216, 0, 21, 606},
    {20, 1483, 0, "AddressString", 2, 0, 2, 2, 216, 0, 21, 608},
    {-1, 1485, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {7, 1425, 0, "CellGlobalIdOrServiceAreaIdFixedLength", 2, 0, 2, 2, 216, 0, 21, 610},
    {5, 1425, 0, "LAIFixedLength", 2, 0, 2, 2, 216, 0, 21, 613},
    {7, 1483, 0, "CellGlobalIdOrServiceAreaIdFixedLength", 2, 0, 2, 2, 216, 0, 21, 616},
    {5, 1485, 0, "LAIFixedLength", 2, 0, 2, 2, 216, 0, 21, 618},
    {5, 1425, 0, "Ext-BearerServiceCode", 2, 0, 2, 2, 216, 0, 21, 620},
    {5, 1425, 0, "Ext-TeleserviceCode", 2, 0, 2, 2, 216, 0, 21, 623},
    {5, 1487, 0, "Ext-BearerServiceCode", 2, 0, 2, 2, 216, 0, 21, 626},
    {5, 1546, 0, "Ext-TeleserviceCode", 2, 0, 2, 2, 216, 0, 21, 628},
    {5, 1425, 0, "Ext-SS-Status", 2, 0, 2, 2, 216, 0, 21, 630},
    {1, 1483, 0, "SS-Code", 2, 0, 2, 2, 216, 0, 21, 633},
    {5, 1485, 0, "Ext-SS-Status", 2, 0, 2, 2, 216, 0, 21, 635},
    {-1, 1487, 0, "MaxMC-Bearers", 2, 0, 2, 0, 200, 0, 55, 637},
    {-1, 1546, 0, "MC-Bearers", 2, 0, 2, 0, 200, 0, 55, 639},
    {-1, 1608, 1390, "ExtensionContainer", 24, 2, 1, 0, 12, 380, 12, 0},
    {-1, 1469, 0, NULL, 8, 0, 8, 0, 8, 0, 0, 0},
    {-1, 20, 0, "MAP-EXTENSION", 24, 3, 1, 0, 8, 623, 49, 0},
    {10, 0, 0, "ObjectID", 12, 2, 2, 2, 120, 0, 63, 641},
    {-1, 20, 0, NULL, 32, 0, 0, 0, 72, 0, 51, 642},
    {-1, 2, 3154, "PrivateExtension", 48, 2, 1, 0, 264, 626, 12, 0},
    {10, 2, 0, "PrivateExtensionList", 8, 48, 2, 8, 216, 826, 18, 645},
    {-1, 1469, 0, NULL, 2, 0, 2, 0, 200, 0, 55, 647},
    {2, 1425, 0, NULL, 2, 0, 2, 2, 216, 0, 21, 649}
};

static const struct ConstraintEntry _econstraintarray[] = {
    {0, 0, (void *)0},
    {0, 0, (void *)0},
    {0, 1, (void *)&_v27},
    {5, 14, (void *)_v374},
    {1, 11, (void *)6},
    {0, 6, (void *)7},
    {0, 5, (void *)&_v29},
    {0, 1, (void *)&_v30},
    {5, 14, (void *)_v34},
    {0, 6, (void *)10},
    {0, 3, (void *)_v34},
    {5, 14, (void *)_v34},
    {0, 6, (void *)13},
    {0, 3, (void *)_v34},
    {5, 14, (void *)_v423},
    {0, 6, (void *)16},
    {0, 3, (void *)_v423},
    {5, 14, (void *)_v336},
    {0, 6, (void *)19},
    {0, 3, (void *)_v336},
    {5, 14, (void *)_v407},
    {0, 6, (void *)22},
    {0, 1, (void *)&_v40},
    {5, 14, (void *)_v42},
    {0, 6, (void *)25},
    {0, 3, (void *)_v42},
    {5, 14, (void *)_v44},
    {0, 6, (void *)28},
    {0, 3, (void *)_v44},
    {5, 14, (void *)_v46},
    {0, 3, (void *)_v46},
    {5, 14, (void *)_v420},
    {0, 6, (void *)33},
    {0, 1, (void *)&_v48},
    {5, 14, (void *)_v422},
    {1, 11, (void *)37},
    {0, 6, (void *)38},
    {0, 6, (void *)39},
    {0, 3, (void *)_v422},
    {0, 3, (void *)_v423},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v438},
    {0, 6, (void *)44},
    {0, 1, (void *)&_v54},
    {5, 14, (void *)_v286},
    {0, 6, (void *)47},
    {0, 3, (void *)_v286},
    {5, 14, (void *)_v58},
    {0, 6, (void *)50},
    {0, 3, (void *)_v58},
    {5, 14, (void *)_v286},
    {0, 6, (void *)53},
    {0, 3, (void *)_v286},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v438},
    {0, 6, (void *)58},
    {0, 1, (void *)&_v63},
    {5, 14, (void *)_v439},
    {0, 6, (void *)61},
    {0, 3, (void *)_v439},
    {5, 14, (void *)_v417},
    {0, 6, (void *)64},
    {0, 3, (void *)_v417},
    {5, 14, (void *)_v417},
    {0, 6, (void *)67},
    {0, 3, (void *)_v417},
    {5, 14, (void *)_v439},
    {0, 6, (void *)70},
    {0, 3, (void *)_v439},
    {5, 14, (void *)_v438},
    {0, 6, (void *)73},
    {0, 1, (void *)&_v73},
    {5, 14, (void *)_v438},
    {0, 6, (void *)76},
    {0, 1, (void *)&_v75},
    {5, 14, (void *)_v336},
    {0, 6, (void *)79},
    {0, 3, (void *)_v336},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v80},
    {0, 3, (void *)_v80},
    {5, 15, (void *)&_v81},
    {0, 3, (void *)_v82},
    {5, 14, (void *)_v86},
    {0, 3, (void *)_v86},
    {5, 14, (void *)_v86},
    {0, 3, (void *)_v86},
    {5, 14, (void *)_v417},
    {0, 6, (void *)92},
    {0, 3, (void *)_v417},
    {5, 14, (void *)_v417},
    {0, 6, (void *)95},
    {0, 3, (void *)_v417},
    {5, 14, (void *)_v417},
    {0, 6, (void *)98},
    {0, 3, (void *)_v417},
    {5, 14, (void *)_v438},
    {0, 6, (void *)101},
    {0, 1, (void *)&_v94},
    {5, 14, (void *)_v438},
    {0, 6, (void *)104},
    {0, 1, (void *)&_v96},
    {5, 14, (void *)_v438},
    {0, 6, (void *)107},
    {0, 1, (void *)&_v98},
    {5, 14, (void *)_v438},
    {0, 6, (void *)110},
    {0, 1, (void *)&_v100},
    {5, 14, (void *)_v438},
    {0, 11, (void *)106},
    {5, 14, (void *)_v438},
    {0, 11, (void *)109},
    {5, 14, (void *)_v423},
    {0, 11, (void *)37},
    {5, 14, (void *)_v327},
    {0, 6, (void *)119},
    {0, 3, (void *)_v327},
    {5, 14, (void *)_v135},
    {0, 3, (void *)_v135},
    {5, 14, (void *)_v147},
    {0, 3, (void *)_v147},
    {5, 14, (void *)_v443},
    {0, 3, (void *)_v443},
    {5, 14, (void *)_v423},
    {0, 11, (void *)37},
    {5, 14, (void *)_v327},
    {0, 11, (void *)118},
    {5, 14, (void *)_v135},
    {0, 3, (void *)_v135},
    {5, 14, (void *)_v147},
    {0, 3, (void *)_v147},
    {5, 14, (void *)_v443},
    {0, 3, (void *)_v443},
    {5, 14, (void *)_v438},
    {0, 6, (void *)138},
    {0, 1, (void *)&_v121},
    {5, 14, (void *)_v438},
    {0, 11, (void *)137},
    {5, 14, (void *)_v443},
    {0, 3, (void *)_v443},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v438},
    {0, 6, (void *)147},
    {0, 1, (void *)&_v127},
    {5, 14, (void *)_v308},
    {1, 11, (void *)37},
    {0, 6, (void *)151},
    {0, 3, (void *)_v308},
    {5, 14, (void *)_v438},
    {0, 11, (void *)137},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v327},
    {0, 11, (void *)118},
    {5, 14, (void *)_v438},
    {0, 11, (void *)146},
    {5, 14, (void *)_v135},
    {0, 3, (void *)_v135},
    {5, 14, (void *)_v308},
    {0, 11, (void *)149},
    {5, 14, (void *)_v174},
    {0, 6, (void *)166},
    {0, 3, (void *)_v174},
    {5, 14, (void *)_v438},
    {0, 11, (void *)137},
    {5, 14, (void *)_v174},
    {0, 6, (void *)171},
    {0, 3, (void *)_v174},
    {5, 14, (void *)_v441},
    {0, 3, (void *)_v441},
    {5, 14, (void *)_v147},
    {0, 3, (void *)_v147},
    {5, 14, (void *)_v147},
    {0, 3, (void *)_v147},
    {5, 14, (void *)_v439},
    {0, 6, (void *)180},
    {0, 3, (void *)_v439},
    {5, 14, (void *)_v441},
    {0, 3, (void *)_v441},
    {5, 14, (void *)_v443},
    {0, 3, (void *)_v443},
    {5, 14, (void *)_v443},
    {0, 3, (void *)_v443},
    {5, 14, (void *)_v439},
    {0, 3, (void *)_v439},
    {5, 14, (void *)_v439},
    {0, 3, (void *)_v439},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v327},
    {0, 11, (void *)118},
    {5, 14, (void *)_v439},
    {0, 11, (void *)179},
    {5, 14, (void *)_v438},
    {0, 11, (void *)137},
    {5, 14, (void *)_v174},
    {0, 6, (void *)201},
    {0, 3, (void *)_v174},
    {5, 14, (void *)_v174},
    {0, 11, (void *)165},
    {5, 14, (void *)_v438},
    {0, 6, (void *)206},
    {0, 1, (void *)&_v168},
    {5, 14, (void *)_v170},
    {0, 6, (void *)209},
    {0, 3, (void *)_v170},
    {5, 14, (void *)_v438},
    {0, 6, (void *)212},
    {0, 1, (void *)&_v172},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v174},
    {0, 11, (void *)200},
    {5, 14, (void *)_v421},
    {0, 6, (void *)219},
    {0, 3, (void *)_v421},
    {5, 14, (void *)_v444},
    {0, 6, (void *)222},
    {0, 3, (void *)_v444},
    {5, 14, (void *)_v421},
    {0, 11, (void *)218},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v438},
    {0, 11, (void *)103},
    {5, 14, (void *)_v185},
    {0, 6, (void *)231},
    {0, 3, (void *)_v185},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v185},
    {0, 11, (void *)230},
    {5, 14, (void *)_v191},
    {0, 6, (void *)238},
    {0, 3, (void *)_v191},
    {5, 14, (void *)_v189},
    {0, 6, (void *)241},
    {0, 3, (void *)_v189},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v191},
    {0, 11, (void *)237},
    {5, 14, (void *)_v438},
    {0, 11, (void *)103},
    {5, 14, (void *)_v438},
    {0, 11, (void *)103},
    {5, 14, (void *)_v439},
    {0, 3, (void *)_v439},
    {5, 14, (void *)_v438},
    {0, 11, (void *)103},
    {5, 14, (void *)_v438},
    {0, 11, (void *)137},
    {5, 14, (void *)_v264},
    {0, 6, (void *)258},
    {0, 3, (void *)_v264},
    {5, 14, (void *)_v439},
    {0, 6, (void *)261},
    {0, 3, (void *)_v439},
    {5, 14, (void *)_v439},
    {0, 11, (void *)260},
    {5, 14, (void *)_v439},
    {0, 11, (void *)260},
    {5, 14, (void *)_v439},
    {0, 6, (void *)268},
    {0, 3, (void *)_v439},
    {5, 14, (void *)_v439},
    {0, 6, (void *)271},
    {0, 3, (void *)_v439},
    {5, 14, (void *)_v439},
    {0, 11, (void *)267},
    {5, 14, (void *)_v439},
    {0, 11, (void *)270},
    {5, 14, (void *)_v439},
    {0, 11, (void *)260},
    {5, 14, (void *)_v264},
    {0, 11, (void *)257},
    {5, 14, (void *)_v439},
    {0, 11, (void *)260},
    {5, 14, (void *)_v439},
    {0, 11, (void *)260},
    {5, 14, (void *)_v215},
    {0, 6, (void *)286},
    {0, 3, (void *)_v215},
    {5, 14, (void *)_v217},
    {0, 6, (void *)289},
    {0, 3, (void *)_v217},
    {5, 14, (void *)_v439},
    {0, 11, (void *)260},
    {5, 14, (void *)_v439},
    {0, 11, (void *)260},
    {5, 14, (void *)_v439},
    {0, 11, (void *)260},
    {5, 14, (void *)_v439},
    {0, 11, (void *)260},
    {5, 14, (void *)_v439},
    {0, 11, (void *)260},
    {5, 14, (void *)_v438},
    {0, 11, (void *)103},
    {5, 14, (void *)_v264},
    {0, 6, (void *)304},
    {0, 3, (void *)_v264},
    {5, 14, (void *)_v374},
    {1, 11, (void *)308},
    {0, 6, (void *)309},
    {0, 5, (void *)&_v227},
    {0, 1, (void *)&_v228},
    {5, 14, (void *)_v334},
    {0, 3, (void *)_v334},
    {5, 14, (void *)_v438},
    {0, 11, (void *)103},
    {5, 14, (void *)_v264},
    {0, 6, (void *)316},
    {0, 3, (void *)_v264},
    {5, 14, (void *)_v374},
    {0, 11, (void *)306},
    {5, 14, (void *)_v334},
    {0, 3, (void *)_v334},
    {5, 14, (void *)_v327},
    {0, 6, (void *)323},
    {0, 3, (void *)_v327},
    {5, 14, (void *)_v439},
    {0, 6, (void *)326},
    {0, 3, (void *)_v439},
    {5, 14, (void *)_v329},
    {0, 3, (void *)_v329},
    {5, 14, (void *)_v439},
    {0, 11, (void *)260},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v327},
    {0, 11, (void *)322},
    {5, 14, (void *)_v439},
    {0, 11, (void *)325},
    {5, 14, (void *)_v329},
    {0, 3, (void *)_v329},
    {5, 14, (void *)_v308},
    {0, 11, (void *)149},
    {5, 14, (void *)_v264},
    {0, 11, (void *)303},
    {5, 14, (void *)_v336},
    {0, 6, (void *)345},
    {0, 3, (void *)_v336},
    {5, 14, (void *)_v438},
    {0, 6, (void *)348},
    {0, 1, (void *)&_v254},
    {5, 14, (void *)_v421},
    {0, 11, (void *)218},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v286},
    {0, 3, (void *)_v286},
    {5, 14, (void *)_v444},
    {0, 6, (void *)357},
    {0, 3, (void *)_v444},
    {5, 14, (void *)_v286},
    {0, 3, (void *)_v286},
    {5, 14, (void *)_v439},
    {0, 11, (void *)260},
    {5, 14, (void *)_v264},
    {0, 11, (void *)315},
    {5, 14, (void *)_v298},
    {0, 3, (void *)_v298},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v286},
    {0, 3, (void *)_v286},
    {5, 14, (void *)_v444},
    {0, 6, (void *)372},
    {0, 3, (void *)_v444},
    {5, 14, (void *)_v286},
    {0, 3, (void *)_v286},
    {5, 14, (void *)_v286},
    {0, 3, (void *)_v286},
    {5, 14, (void *)_v298},
    {0, 11, (void *)365},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v444},
    {0, 11, (void *)356},
    {5, 14, (void *)_v438},
    {0, 6, (void *)385},
    {0, 1, (void *)&_v280},
    {5, 14, (void *)_v444},
    {0, 6, (void *)388},
    {0, 3, (void *)_v444},
    {5, 14, (void *)_v444},
    {0, 6, (void *)391},
    {0, 3, (void *)_v444},
    {5, 14, (void *)_v286},
    {0, 3, (void *)_v286},
    {5, 14, (void *)_v444},
    {0, 6, (void *)396},
    {0, 3, (void *)_v444},
    {5, 14, (void *)_v444},
    {0, 6, (void *)399},
    {0, 3, (void *)_v444},
    {5, 14, (void *)_v444},
    {0, 11, (void *)398},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v444},
    {0, 6, (void *)406},
    {0, 3, (void *)_v444},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v444},
    {0, 6, (void *)411},
    {0, 3, (void *)_v444},
    {5, 14, (void *)_v298},
    {0, 11, (void *)365},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v444},
    {0, 11, (void *)390},
    {5, 14, (void *)_v444},
    {0, 11, (void *)371},
    {5, 14, (void *)_v444},
    {0, 6, (void *)422},
    {0, 3, (void *)_v444},
    {5, 14, (void *)_v309},
    {0, 6, (void *)425},
    {0, 3, (void *)_v309},
    {5, 14, (void *)_v444},
    {0, 11, (void *)421},
    {5, 14, (void *)_v308},
    {0, 3, (void *)_v308},
    {5, 14, (void *)_v309},
    {0, 11, (void *)424},
    {5, 14, (void *)_v439},
    {0, 6, (void *)434},
    {0, 3, (void *)_v439},
    {5, 14, (void *)_v439},
    {0, 6, (void *)437},
    {0, 3, (void *)_v439},
    {5, 14, (void *)_v439},
    {0, 6, (void *)440},
    {0, 3, (void *)_v439},
    {5, 14, (void *)_v439},
    {0, 11, (void *)439},
    {5, 14, (void *)_v439},
    {0, 11, (void *)433},
    {5, 14, (void *)_v444},
    {0, 11, (void *)395},
    {5, 14, (void *)_v439},
    {0, 11, (void *)439},
    {5, 14, (void *)_v439},
    {0, 11, (void *)436},
    {5, 14, (void *)_v444},
    {0, 11, (void *)398},
    {5, 14, (void *)_v444},
    {0, 6, (void *)455},
    {0, 3, (void *)_v444},
    {5, 14, (void *)_v438},
    {0, 11, (void *)103},
    {5, 14, (void *)_v439},
    {0, 11, (void *)260},
    {5, 14, (void *)_v423},
    {0, 11, (void *)37},
    {5, 14, (void *)_v327},
    {0, 11, (void *)322},
    {5, 14, (void *)_v329},
    {0, 3, (void *)_v329},
    {5, 14, (void *)_v438},
    {0, 11, (void *)103},
    {5, 14, (void *)_v439},
    {0, 11, (void *)260},
    {5, 14, (void *)_v374},
    {0, 11, (void *)306},
    {5, 14, (void *)_v334},
    {0, 3, (void *)_v334},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v336},
    {0, 11, (void *)344},
    {5, 14, (void *)_v346},
    {0, 3, (void *)_v346},
    {5, 14, (void *)_v347},
    {0, 6, (void *)482},
    {0, 3, (void *)_v347},
    {5, 14, (void *)_v421},
    {0, 11, (void *)218},
    {5, 14, (void *)_v421},
    {0, 11, (void *)218},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v423},
    {0, 11, (void *)37},
    {5, 14, (void *)_v346},
    {0, 3, (void *)_v346},
    {5, 14, (void *)_v347},
    {0, 11, (void *)481},
    {5, 14, (void *)_v421},
    {0, 11, (void *)218},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v423},
    {0, 11, (void *)37},
    {5, 14, (void *)_v438},
    {0, 11, (void *)109},
    {5, 14, (void *)_v374},
    {0, 6, (void *)505},
    {0, 1, (void *)&_v353},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v359},
    {0, 6, (void *)512},
    {0, 3, (void *)_v359},
    {5, 14, (void *)_v359},
    {0, 11, (void *)511},
    {5, 14, (void *)_v359},
    {0, 11, (void *)511},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v362},
    {0, 3, (void *)_v362},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v421},
    {0, 11, (void *)218},
    {5, 14, (void *)_v374},
    {0, 11, (void *)504},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v423},
    {0, 11, (void *)37},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v423},
    {0, 11, (void *)37},
    {5, 14, (void *)_v374},
    {0, 6, (void *)539},
    {0, 1, (void *)&_v372},
    {5, 14, (void *)_v374},
    {0, 11, (void *)538},
    {5, 14, (void *)_v374},
    {0, 11, (void *)538},
    {5, 14, (void *)_v446},
    {0, 3, (void *)_v446},
    {5, 14, (void *)_v446},
    {0, 3, (void *)_v446},
    {5, 14, (void *)_v446},
    {0, 3, (void *)_v446},
    {5, 14, (void *)_v446},
    {0, 3, (void *)_v446},
    {5, 14, (void *)_v421},
    {0, 11, (void *)218},
    {5, 14, (void *)_v385},
    {0, 6, (void *)556},
    {0, 3, (void *)_v385},
    {5, 14, (void *)_v421},
    {0, 11, (void *)218},
    {5, 14, (void *)_v438},
    {0, 11, (void *)103},
    {5, 14, (void *)_v438},
    {0, 11, (void *)137},
    {5, 14, (void *)_v446},
    {0, 3, (void *)_v446},
    {5, 14, (void *)_v420},
    {0, 6, (void *)567},
    {0, 1, (void *)&_v392},
    {5, 14, (void *)_v409},
    {0, 3, (void *)_v409},
    {5, 14, (void *)_v411},
    {0, 3, (void *)_v411},
    {5, 14, (void *)_v407},
    {0, 6, (void *)574},
    {0, 1, (void *)&_v398},
    {5, 14, (void *)_v409},
    {0, 3, (void *)_v409},
    {5, 14, (void *)_v411},
    {0, 3, (void *)_v411},
    {5, 14, (void *)_v409},
    {0, 3, (void *)_v409},
    {5, 14, (void *)_v411},
    {0, 3, (void *)_v411},
    {5, 14, (void *)_v407},
    {0, 11, (void *)573},
    {5, 14, (void *)_v409},
    {0, 3, (void *)_v409},
    {5, 14, (void *)_v411},
    {0, 3, (void *)_v411},
    {5, 14, (void *)_v413},
    {0, 6, (void *)591},
    {0, 3, (void *)_v413},
    {5, 14, (void *)_v417},
    {0, 6, (void *)594},
    {0, 3, (void *)_v417},
    {5, 14, (void *)_v421},
    {0, 11, (void *)218},
    {5, 14, (void *)_v417},
    {0, 11, (void *)593},
    {5, 14, (void *)_v420},
    {0, 6, (void *)601},
    {0, 1, (void *)&_v419},
    {5, 14, (void *)_v420},
    {0, 11, (void *)600},
    {5, 14, (void *)_v421},
    {0, 11, (void *)218},
    {5, 14, (void *)_v422},
    {0, 11, (void *)35},
    {5, 14, (void *)_v423},
    {0, 11, (void *)37},
    {5, 14, (void *)_v428},
    {0, 6, (void *)612},
    {0, 1, (void *)&_v425},
    {5, 14, (void *)_v429},
    {0, 6, (void *)615},
    {0, 1, (void *)&_v427},
    {5, 14, (void *)_v428},
    {0, 11, (void *)611},
    {5, 14, (void *)_v429},
    {0, 11, (void *)614},
    {5, 14, (void *)_v439},
    {0, 6, (void *)622},
    {0, 3, (void *)_v439},
    {5, 14, (void *)_v439},
    {0, 6, (void *)625},
    {0, 3, (void *)_v439},
    {5, 14, (void *)_v439},
    {0, 11, (void *)621},
    {5, 14, (void *)_v439},
    {0, 11, (void *)624},
    {5, 14, (void *)_v439},
    {0, 6, (void *)632},
    {0, 3, (void *)_v439},
    {5, 14, (void *)_v438},
    {0, 11, (void *)103},
    {5, 14, (void *)_v439},
    {0, 11, (void *)631},
    {5, 14, (void *)_v441},
    {0, 3, (void *)_v441},
    {5, 14, (void *)_v443},
    {0, 3, (void *)_v443},
    {0, 16, (void *)0x270},
    {0, 17, (void *)0x2840283},
    {0, 18, (void *)0x2700272},
    {0, 16, (void *)0x26f},
    {5, 14, (void *)_v444},
    {0, 11, (void *)221},
    {5, 14, (void *)_v446},
    {0, 3, (void *)_v446},
    {5, 14, (void *)_v447},
    {0, 6, (void *)651},
    {0, 1, (void *)&_v448}
};

static const struct efield _efieldarray[] = {
    {0, 217, -1, 381, 2},
    {8, 226, -1, 382, 2},
    {4, 208, -1, 383, 2},
    {4, 216, -1, 384, 2},
    {8, 265, -1, 385, 2},
    {8, 266, -1, 386, 2},
    {8, 267, -1, 387, 2},
    {8, 268, -1, 388, 2},
    {8, 269, -1, 389, 2},
    {8, 273, -1, 390, 2},
    {8, 282, -1, 391, 2},
    {8, 285, -1, 392, 2},
    {4, 287, 0, 393, 3},
    {8, 270, 1, 394, 3},
    {4, 289, 0, 393, 3},
    {8, 270, 1, 394, 3},
    {8, 292, -1, 395, 2},
    {4, 208, -1, 396, 2},
    {4, 0, -1, 397, 2},
    {2, 293, -1, 398, 2},
    {6, 298, 0, 399, 3},
    {12, 304, 1, 400, 3},
    {34, 305, 2, 401, 3},
    {58, 306, 3, 402, 3},
    {60, 307, 4, 403, 11},
    {62, 308, 5, 404, 11},
    {64, 309, 6, 405, 11},
    {2, 293, -1, 398, 2},
    {6, 298, 0, 399, 3},
    {12, 339, 1, 405, 11},
    {8, 355, -1, 406, 2},
    {8, 356, -1, 407, 2},
    {8, 357, -1, 408, 2},
    {8, 358, -1, 409, 2},
    {2, 359, -1, 410, 2},
    {6, 360, -1, 411, 2},
    {168, 361, 0, 412, 11},
    {172, 362, 1, 413, 11},
    {0, 359, -1, 410, 2},
    {4, 360, -1, 411, 2},
    {2, 370, -1, 414, 2},
    {12, 371, -1, 413, 2},
    {24, 372, -1, 415, 2},
    {32, 373, 0, 416, 3},
    {40, 374, 1, 417, 3},
    {64, 375, 2, 418, 11},
    {76, 376, 3, 419, 11},
    {8, 368, 0, 417, 3},
    {2, 388, -1, 398, 2},
    {8, 389, 0, 420, 3},
    {2, 390, 0, 421, 3},
    {2, 391, -1, 398, 2},
    {6, 392, 0, 422, 3},
    {2, 393, -1, 398, 2},
    {6, 394, 0, 406, 3},
    {2, 636, -1, 423, 2},
    {16, 637, -1, 424, 2},
    {32, 638, 0, 425, 3},
    {136, 639, 1, 426, 3},
    {200, 640, 2, 427, 3},
    {240, 641, 3, 417, 3},
    {264, 642, 4, 405, 3},
    {272, 643, 5, 428, 11},
    {376, 644, 6, 429, 11},
    {408, 645, 7, 430, 11},
    {424, 646, 8, 431, 11},
    {456, 647, 9, 432, 11},
    {504, 648, 10, 433, 11},
    {552, 649, 11, 434, 11},
    {600, 650, 12, 435, 11},
    {640, 651, 13, 436, 11},
    {8, 652, 0, 437, 3},
    {72, 653, 1, 438, 3},
    {616, 654, 2, 417, 3},
    {640, 655, 3, 439, 11},
    {744, 656, 4, 440, 11},
    {768, 657, 5, 441, 11},
    {780, 658, 6, 442, 11},
    {800, 659, 7, 443, 11},
    {820, 660, 8, 444, 11},
    {2, 670, -1, 413, 2},
    {14, 671, -1, 445, 2},
    {16, 672, -1, 446, 2},
    {40, 673, 0, 417, 3},
    {64, 674, 1, 447, 11},
    {66, 675, 2, 448, 11},
    {68, 676, 3, 449, 11},
    {84, 677, 4, 450, 11},
    {88, 678, 5, 451, 11},
    {90, 679, 6, 414, 11},
    {100, 680, 7, 452, 11},
    {101, 681, 8, 453, 11},
    {104, 682, 9, 454, 11},
    {2, 683, -1, 413, 2},
    {14, 684, -1, 445, 2},
    {16, 685, -1, 446, 2},
    {38, 686, 0, 455, 3},
    {2, 364, -1, 414, 2},
    {16, 706, -1, 456, 2},
    {1648, 707, 0, 417, 3},
    {1672, 708, 1, 457, 11},
    {2, 364, -1, 414, 2},
    {12, 713, -1, 458, 2},
    {34, 714, 0, 459, 3},
    {2, 720, -1, 460, 2},
    {26, 724, -1, 461, 2},
    {50, 380, -1, 462, 2},
    {256, 368, 0, 417, 3},
    {280, 364, 1, 414, 11},
    {296, 726, 2, 454, 11},
    {344, 727, 3, 463, 11},
    {2, 380, 0, 462, 3},
    {208, 368, 1, 417, 3},
    {2, 720, -1, 460, 2},
    {26, 724, -1, 461, 2},
    {50, 380, -1, 462, 2},
    {252, 216, 0, 464, 3},
    {256, 368, 1, 417, 3},
    {280, 704, 2, 465, 11},
    {282, 728, 3, 466, 11},
    {288, 729, 4, 467, 11},
    {296, 730, 5, 454, 11},
    {344, 731, 6, 468, 11},
    {2, 720, -1, 460, 2},
    {26, 724, -1, 461, 2},
    {50, 380, -1, 462, 2},
    {252, 216, 0, 464, 3},
    {2, 380, 0, 462, 3},
    {208, 368, 1, 417, 3},
    {232, 732, 2, 469, 11},
    {2, 325, -1, 413, 2},
    {14, 299, -1, 446, 2},
    {36, 725, -1, 463, 2},
    {40, 734, 0, 470, 3},
    {48, 735, 1, 417, 3},
    {72, 736, 2, 447, 11},
    {73, 737, 3, 471, 11},
    {76, 738, 4, 472, 11},
    {80, 739, 5, 473, 11},
    {82, 740, 6, 474, 11},
    {84, 741, 7, 475, 11},
    {88, 742, 8, 476, 11},
    {90, 743, 9, 414, 11},
    {100, 744, 10, 453, 11},
    {104, 745, 11, 454, 11},
    {2, 325, 0, 477, 3},
    {16, 368, 1, 417, 3},
    {2, 325, -1, 413, 2},
    {14, 299, -1, 446, 2},
    {36, 725, 0, 463, 3},
    {2, 325, 0, 413, 3},
    {16, 368, 1, 417, 3},
    {0, 325, -1, 413, 2},
    {12, 299, -1, 446, 2},
    {2, 325, 0, 477, 3},
    {14, 746, 1, 478, 3},
    {16, 368, 2, 417, 3},
    {2, 325, 0, 477, 3},
    {14, 746, 1, 478, 3},
    {2, 748, -1, 414, 2},
    {12, 747, -1, 479, 2},
    {16, 216, 0, 480, 3},
    {24, 368, 1, 417, 3},
    {48, 749, 2, 481, 3},
    {50, 728, 3, 482, 3},
    {8, 368, 0, 417, 3},
    {4, 750, -1, 483, 2},
    {8, 368, 0, 417, 3},
    {8, 751, -1, 484, 2},
    {8, 753, -1, 485, 2},
    {4, 754, 0, 486, 3},
    {8, 368, 1, 417, 3},
    {2, 755, 0, 398, 3},
    {6, 298, 1, 399, 3},
    {12, 756, 2, 406, 3},
    {4, 757, -1, 487, 2},
    {8, 380, 0, 488, 3},
    {216, 368, 1, 417, 3},
    {2, 733, 0, 470, 3},
    {8, 368, 1, 417, 3},
    {32, 758, 2, 473, 11},
    {8, 759, -1, 489, 2},
    {8, 760, -1, 490, 2},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {32, 761, 1, 491, 11},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {32, 763, 1, 492, 11},
    {8, 368, 0, 417, 3},
    {32, 764, 1, 493, 11},
    {33, 765, 2, 494, 11},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {32, 216, 1, 495, 11},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {4, 767, 0, 496, 3},
    {8, 768, 1, 417, 3},
    {4, 770, 0, 497, 3},
    {8, 771, 1, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {8, 368, 0, 417, 3},
    {4, 793, -1, 498, 2},
    {64, 794, 0, 499, 3},
    {4, 795, -1, 500, 2},
    {8, 380, -1, 501, 2},
    {216, 368, 0, 417, 3},
    {4, 796, -1, 502, 2},
    {8, 380, -1, 501, 2},
    {216, 368, 0, 417, 3},
    {2, 364, -1, 414, 2},
    {2, 797, -1, 503, 2},
    {2, 799, -1, 414, 2},
    {2, 800, -1, 504, 2},
    {2, 802, -1, 505, 2},
    {8, 803, 0, 417, 3},
    {2, 804, -1, 414, 2},
    {2, 805, -1, 413, 2},
    {2, 806, 0, 506, 3},
    {24, 807, 1, 417, 3},
    {2, 810, -1, 507, 2},
    {2, 811, -1, 508, 2},
    {2, 814, -1, 509, 2},
    {2, 815, -1, 510, 2},
    {2, 302, -1, 511, 2},
    {4, 302, -1, 403, 2},
    {8, 368, 0, 417, 3},
    {2, 817, -1, 398, 2},
    {6, 818, -1, 406, 2},
    {14, 819, -1, 512, 2},
    {16, 820, -1, 404, 2},
    {24, 821, 0, 417, 3},
    {2, 828, 0, 513, 3},
    {4, 829, 1, 514, 3},
    {8, 202, -1, 515, 2},
    {8, 203, -1, 516, 2},
    {8, 204, -1, 517, 2},
    {2, 199, 0, 518, 3},
    {16, 200, 1, 519, 3},
    {24, 201, -1, 520, 3},
    {32, 205, -1, 521, 2},
    {4, 208, -1, 522, 2},
    {4, 0, -1, 523, 2},
    {2, 210, 0, 524, 3},
    {4, 211, 1, 525, 3},
    {6, 207, 2, 526, 11},
    {8, 209, 3, 527, 67},
    {2, 210, 0, 528, 3},
    {4, 211, 1, 529, 3},
    {5, 211, 2, 530, 7},
    {6, 210, 3, 532, 3},
    {8, 211, 4, 533, 3},
    {16, 212, -1, 534, 131},
    {24, 213, -1, 535, 131},
    {32, 211, 5, 536, 7},
    {33, 211, 6, 538, 7},
    {34, 207, 7, 540, 11},
    {36, 207, 8, 541, 11},
    {40, 209, 9, 542, 67},
    {4, 222, -1, 543, 2},
    {4, 223, -1, 544, 2},
    {4, 224, -1, 545, 2},
    {4, 225, -1, 546, 2},
    {2, 230, -1, 547, 2},
    {4, 231, 0, 548, 3},
    {8, 227, -1, 542, 2},
    {24, 232, 1, 549, 3},
    {0, 227, -1, 542, 2},
    {16, 232, -1, 549, 2},
    {2, 230, -1, 547, 2},
    {8, 234, 0, 550, 3},
    {2, 230, -1, 547, 2},
    {4, 228, -1, 527, 2},
    {24, 236, 0, 549, 3},
    {2, 230, -1, 551, 2},
    {2, 216, -1, 552, 2},
    {4, 243, -1, 553, 2},
    {4, 244, -1, 554, 2},
    {4, 245, -1, 555, 2},
    {4, 246, -1, 556, 2},
    {0, 242, -1, 547, 2},
    {4, 247, -1, 382, 2},
    {8, 249, -1, 544, 2},
    {8, 250, -1, 557, 2},
    {8, 251, -1, 546, 2},
    {8, 252, -1, 558, 2},
    {8, 253, -1, 559, 2},
    {8, 229, 0, 560, 3},
    {80, 255, -1, 561, 2},
    {2, 257, -1, 562, 2},
    {8, 229, 0, 560, 3},
    {80, 255, 1, 561, 3},
    {2, 259, -1, 563, 2},
    {8, 229, 0, 560, 3},
    {80, 255, 1, 561, 3},
    {2, 257, -1, 562, 2},
    {8, 259, -1, 563, 2},
    {16, 229, 0, 560, 3},
    {88, 255, 1, 561, 3},
    {8, 262, -1, 564, 2},
    {8, 229, -1, 565, 2},
    {2, 259, -1, 563, 2},
    {8, 263, 0, 393, 3},
    {8, 271, 0, 566, 7},
    {24, 272, -1, 568, 2},
    {40, 270, 1, 394, 3},
    {4, 275, -1, 569, 2},
    {4, 276, -1, 570, 2},
    {8, 278, 0, 571, 7},
    {24, 279, -1, 568, 2},
    {36, 280, -1, 550, 2},
    {40, 281, -1, 573, 2},
    {48, 270, 1, 394, 3},
    {4, 284, -1, 574, 2},
    {8, 270, 0, 394, 3},
    {8, 290, 0, 575, 7},
    {24, 291, -1, 568, 2},
    {40, 270, 1, 394, 3},
    {2, 296, -1, 577, 2},
    {2, 297, -1, 455, 2},
    {2, 293, 0, 398, 3},
    {8, 335, -1, 408, 2},
    {2, 293, 0, 398, 3},
    {8, 338, -1, 578, 2},
    {4, 315, -1, 579, 2},
    {4, 316, -1, 580, 2},
    {2, 293, 0, 398, 3},
    {6, 318, 1, 406, 3},
    {12, 317, 2, 581, 3},
    {24, 363, 3, 407, 3},
    {32, 302, 4, 403, 11},
    {34, 319, 5, 404, 11},
    {8, 321, -1, 582, 2},
    {8, 322, -1, 583, 2},
    {8, 323, -1, 584, 2},
    {2, 298, 0, 399, 3},
    {8, 328, 1, 406, 3},
    {12, 329, 2, 400, 3},
    {24, 330, 3, 401, 3},
    {48, 331, 4, 585, 3},
    {52, 332, 5, 402, 3},
    {54, 333, 6, 586, 11},
    {2, 298, 0, 399, 3},
    {8, 336, 1, 406, 3},
    {2, 312, -1, 406, 2},
    {8, 313, 0, 579, 3},
    {12, 341, 1, 587, 11},
    {14, 342, 2, 403, 11},
    {16, 343, 3, 588, 11},
    {24, 344, 4, 512, 11},
    {26, 345, 5, 404, 11},
    {28, 346, 6, 589, 11},
    {2, 349, 0, 422, 3},
    {4, 350, 1, 418, 3},
    {16, 351, 2, 590, 3},
    {40, 352, 3, 591, 3},
    {8, 366, 0, 592, 3},
    {16, 367, 1, 593, 3},
    {4, 379, -1, 594, 2},
    {8, 380, -1, 501, 2},
    {216, 368, 0, 417, 3},
    {2, 382, -1, 421, 2},
    {48, 383, -1, 595, 2},
    {64, 384, 0, 596, 3},
    {80, 385, -1, 597, 2},
    {320, 386, -1, 598, 2},
    {8, 396, -1, 599, 2},
    {16, 397, 0, 600, 3},
    {2, 400, -1, 406, 2},
    {10, 401, 0, 600, 3},
    {2, 404, -1, 406, 2},
    {12, 405, -1, 580, 2},
    {16, 406, 0, 600, 3},
    {2, 410, -1, 509, 2},
    {2, 411, -1, 510, 2},
    {0, 413, -1, 399, 2},
    {10, 414, -1, 406, 2},
    {2, 417, -1, 406, 2},
    {10, 418, 0, 600, 3},
    {2, 420, -1, 406, 2},
    {12, 421, 0, 579, 3},
    {16, 422, 1, 600, 3},
    {8, 424, -1, 601, 2},
    {24, 425, 0, 602, 3},
    {40, 368, 1, 417, 3},
    {8, 426, -1, 603, 2},
    {72, 216, 0, 600, 3},
    {80, 368, 1, 417, 3},
    {2, 429, 0, 406, 3},
    {12, 430, 1, 604, 3},
    {16, 431, 2, 417, 3},
    {2, 433, 0, 406, 3},
    {12, 434, 1, 580, 3},
    {16, 435, 2, 604, 3},
    {24, 436, 3, 417, 3},
    {2, 438, 0, 406, 3},
    {12, 439, 1, 604, 3},
    {16, 440, 2, 417, 3},
    {2, 442, 0, 406, 3},
    {12, 443, 1, 579, 3},
    {16, 444, 2, 604, 3},
    {24, 445, 3, 417, 3},
    {2, 447, 0, 399, 3},
    {12, 448, 1, 406, 3},
    {20, 449, 2, 604, 3},
    {24, 450, 3, 417, 3},
    {4, 452, 0, 604, 3},
    {8, 453, 1, 417, 3},
    {2, 455, -1, 398, 2},
    {8, 456, -1, 408, 2},
    {16, 457, -1, 600, 2},
    {24, 458, 0, 417, 3},
    {2, 462, -1, 398, 2},
    {8, 463, -1, 578, 2},
    {16, 464, -1, 605, 2},
    {22, 465, -1, 606, 2},
    {24, 466, -1, 600, 2},
    {32, 467, 0, 417, 3},
    {8, 469, -1, 607, 2},
    {8, 470, -1, 608, 2},
    {2, 412, 0, 399, 3},
    {12, 475, -1, 406, 2},
    {20, 476, 1, 400, 3},
    {32, 477, 2, 401, 3},
    {56, 478, 3, 585, 3},
    {64, 479, 4, 402, 3},
    {72, 480, 5, 417, 3},
    {96, 481, 6, 586, 11},
    {2, 486, -1, 414, 2},
    {2, 487, -1, 413, 2},
    {8, 490, 0, 609, 3},
    {16, 491, 1, 610, 3},
    {24, 492, 2, 417, 3},
    {48, 493, 3, 600, 3},
    {49, 494, 4, 611, 3},
    {2, 412, 0, 399, 3},
    {12, 496, -1, 406, 2},
    {24, 368, 1, 417, 3},
    {4, 500, -1, 612, 2},
    {8, 501, 0, 604, 3},
    {12, 502, 1, 613, 3},
    {16, 503, 2, 417, 3},
    {8, 542, -1, 614, 2},
    {16, 505, -1, 615, 2},
    {20, 506, -1, 424, 2},
    {32, 507, 0, 417, 3},
    {56, 508, 1, 600, 3},
    {57, 509, 2, 611, 3},
    {8, 570, -1, 616, 2},
    {16, 368, 0, 417, 3},
    {40, 511, 1, 610, 11},
    {42, 512, 2, 600, 11},
    {43, 513, 3, 617, 11},
    {8, 515, 0, 618, 3},
    {16, 516, 1, 610, 3},
    {24, 517, 2, 417, 3},
    {48, 518, 3, 600, 3},
    {49, 519, 4, 611, 3},
    {8, 576, -1, 619, 2},
    {16, 368, 0, 417, 3},
    {40, 521, 1, 610, 11},
    {42, 522, 2, 600, 11},
    {43, 523, 3, 611, 11},
    {8, 611, -1, 620, 2},
    {16, 325, -1, 424, 2},
    {32, 525, 0, 417, 3},
    {56, 526, 1, 600, 11},
    {57, 527, 2, 617, 11},
    {8, 528, -1, 621, 2},
    {72, 368, 0, 417, 3},
    {96, 529, 1, 600, 11},
    {97, 530, 2, 611, 11},
    {4, 534, -1, 622, 2},
    {8, 535, -1, 615, 2},
    {12, 536, -1, 424, 2},
    {24, 537, -1, 623, 2},
    {32, 538, 0, 417, 3},
    {8, 543, 0, 624, 3},
    {16, 544, 1, 610, 3},
    {24, 545, 2, 417, 3},
    {48, 546, 3, 600, 3},
    {49, 547, 4, 611, 3},
    {8, 549, 0, 625, 3},
    {56, 550, 1, 626, 3},
    {64, 551, 2, 627, 3},
    {120, 552, 3, 628, 3},
    {168, 553, 4, 629, 3},
    {176, 554, 5, 630, 3},
    {224, 555, 6, 631, 3},
    {232, 556, 7, 632, 3},
    {233, 557, 8, 633, 3},
    {240, 558, 9, 634, 3},
    {296, 559, 10, 635, 3},
    {352, 560, 11, 636, 3},
    {456, 561, 12, 637, 3},
    {520, 562, 13, 417, 3},
    {4, 564, -1, 638, 2},
    {8, 505, -1, 615, 2},
    {12, 566, -1, 424, 2},
    {24, 567, -1, 639, 2},
    {32, 568, 0, 417, 3},
    {4, 571, -1, 640, 2},
    {8, 505, -1, 615, 2},
    {12, 572, -1, 424, 2},
    {24, 573, -1, 639, 2},
    {32, 574, 0, 417, 3},
    {4, 579, -1, 641, 2},
    {8, 580, -1, 615, 2},
    {12, 581, -1, 424, 2},
    {24, 582, -1, 642, 2},
    {32, 583, 0, 417, 3},
    {2, 325, -1, 643, 2},
    {16, 505, -1, 615, 2},
    {20, 325, -1, 424, 2},
    {32, 565, -1, 639, 2},
    {40, 368, 0, 417, 3},
    {4, 589, -1, 644, 2},
    {8, 590, 0, 645, 3},
    {16, 591, 1, 646, 3},
    {4, 564, -1, 638, 2},
    {8, 600, 0, 647, 3},
    {32, 601, 1, 648, 3},
    {40, 602, 2, 649, 3},
    {48, 603, 3, 650, 11},
    {56, 604, 4, 417, 11},
    {4, 571, -1, 651, 2},
    {8, 607, 0, 648, 3},
    {16, 608, 1, 652, 3},
    {2, 612, -1, 398, 2},
    {6, 613, 0, 399, 3},
    {16, 614, 1, 406, 3},
    {24, 615, 2, 400, 3},
    {46, 616, 3, 401, 3},
    {70, 617, 4, 402, 3},
    {72, 618, 5, 604, 3},
    {80, 619, 6, 417, 3},
    {2, 621, -1, 398, 2},
    {6, 622, 0, 399, 3},
    {16, 623, 1, 406, 3},
    {24, 624, 2, 605, 3},
    {30, 625, 3, 606, 3},
    {32, 626, 4, 604, 3},
    {40, 627, 5, 417, 3},
    {4, 629, 0, 653, 3},
    {8, 630, 1, 417, 3},
    {8, 632, 0, 654, 3},
    {72, 633, 1, 604, 3},
    {80, 634, 2, 417, 3},
    {2, 666, 0, 655, 3},
    {16, 667, 1, 656, 3},
    {32, 668, -1, 657, 2},
    {2, 688, -1, 658, 2},
    {2, 689, -1, 659, 2},
    {0, 692, -1, 660, 2},
    {258, 693, -1, 661, 2},
    {2, 695, -1, 662, 2},
    {14, 687, 0, 663, 3},
    {24, 368, 1, 417, 3},
    {48, 696, 2, 664, 11},
    {50, 697, 3, 665, 11},
    {64, 698, 4, 666, 11},
    {580, 699, 5, 667, 11},
    {1096, 700, 6, 668, 11},
    {1110, 701, 7, 669, 11},
    {1626, 702, 8, 670, 11},
    {2, 704, -1, 671, 2},
    {4, 704, -1, 672, 2},
    {8, 368, 0, 417, 3},
    {2, 709, -1, 673, 2},
    {2, 710, -1, 658, 2},
    {2, 711, -1, 674, 2},
    {16, 687, 0, 663, 3},
    {2, 715, -1, 414, 2},
    {2, 716, -1, 663, 2},
    {2, 717, -1, 673, 2},
    {2, 718, -1, 675, 2},
    {2, 719, -1, 676, 2},
    {2, 721, -1, 413, 2},
    {2, 722, -1, 677, 2},
    {2, 723, -1, 678, 2},
    {4, 751, 0, 484, 3},
    {8, 368, 1, 417, 3},
    {32, 752, 2, 679, 11},
    {4, 759, 0, 489, 3},
    {8, 368, 1, 417, 3},
    {4, 774, -1, 542, 2},
    {4, 775, -1, 527, 2},
    {4, 776, -1, 680, 2},
    {4, 777, -1, 681, 2},
    {24, 778, -1, 682, 2},
    {32, 786, 0, 683, 3},
    {36, 787, 1, 684, 3},
    {40, 788, 2, 685, 3},
    {44, 789, 3, 686, 3},
    {46, 790, 4, 687, 3},
    {56, 791, 5, 688, 3},
    {58, 792, 6, 689, 3},
    {0, 364, -1, 414, 2},
    {10, 687, -1, 663, 2},
    {2, 210, 0, 690, 3},
    {4, 0, -1, 691, 2},
    {16, 822, -1, 692, 66},
    {2, 824, -1, 693, 18},
    {16, 825, 0, 694, 3}
};

#ifdef OSS_SPARTAN_AWARE
#if ((OSS_SPARTAN_AWARE + 0) > 12)
typedef struct ExtParms {
    int           versId;
    const void    *xparm[7];
} ExtParms;
static ExtParms const extParms = {
    27,
    {NULL, NULL, NULL, NULL, (void *)0, (void *)0, (void *)8}
};
#endif /* OSS_SPARTAN_AWARE  > 12 */
#endif /* OSS_SPARTAN_AWARE */

static void * const _enamearray[] = {
    (void *)0,
    (void *)0x3, (void *)_v517,
    (void *)"enterPW", (void *)"enterNewPW", (void *)"enterNewPW-Again",
    (void *)0x3, (void *)_v517,
    (void *)"undetermined", (void *)"invalidFormat", (void *)"newPasswordsMismatch",
    (void *)0x5, (void *)_v517,
    (void *)"broadcastService", (void *)"o-andM-HPLMN", (void *)"o-andM-VPLMN", (void *)"anonymousLocation", (void *)"targetMSsubscribedService",
    (void *)0x1, (void *)_v525,
    (void *)"oss-unknown-enumerator",
    (void *)0x3, (void *)_v517,
    (void *)"snbd1", (void *)"snbd2", (void *)"snd",
    (void *)0x1, (void *)_v525, (void *)"oss-unknown-enumerator",
    (void *)0x3, (void *)_v517,
    (void *)"unrecognizedPDU", (void *)"mistypedPDU", (void *)"badlyStructuredPDU",
    (void *)0x8, (void *)_v517,
    (void *)"duplicateInvocation", (void *)"unrecognizedOperltion", (void *)"mistypedArgument", (void *)"resourceLimitation", (void *)"releaseInProgress",
    (void *)"unrecognizedLinkedId", (void *)"linkdeResponseUnexpected", (void *)"unexpectedLinkedOperation",
    (void *)0x3, (void *)_v517,
    (void *)"unrecognisedInvocation", (void *)"resultResponseUnexpected", (void *)"mistypedResult",
    (void *)0x5, (void *)_v517,
    (void *)"unrecognisedInvocation", (void *)"errorResponseUnexpected", (void *)"unrecognizedError", (void *)"unexpectedError", (void *)"unexpectedParameter",
    (void *)0x3, (void *)_v517,
    (void *)"unrecognizedComponent", (void *)"mistypedComponent", (void *)"badlyStructuredComponent",
    (void *)0x8, (void *)_v517,
    (void *)"duplicateInvokeID", (void *)"unrecognizedOperation", (void *)"mistypedParameter", (void *)"resourceLimitation", (void *)"initiatingRelease",
    (void *)"unrecognizedLinkedID", (void *)"linkedResponseUnexpected", (void *)"unexpectedLinkedOperation",
    (void *)0x3, (void *)_v517,
    (void *)"unrecognizedInvokeID", (void *)"returnResultUnexpected", (void *)"mistypedParameter",
    (void *)0x5, (void *)_v517,
    (void *)"unrecognizedInvokeID", (void *)"returnErrorUnexpected", (void *)"unrecognizedError", (void *)"unexpectedError", (void *)"mistypedParameter",
    (void *)0x5, (void *)_v517,
    (void *)"unrecognizedMessageType", (void *)"unrecognizedTransactionID", (void *)"badlyFormattedTransactionPortion", (void *)"incorrectTransactionPortion", (void *)"resourceLimitation",
    (void *)0x10001, (void *)_v483,
    (void *)"version1",
    (void *)0x2, (void *)_v517,
    (void *)"accepted", (void *)"reject-permanent",
    (void *)0x3, (void *)_v517,
    (void *)"null", (void *)"no-reason-given", (void *)"application-context-name-not-supported",
    (void *)0x3, (void *)_v517,
    (void *)"null", (void *)"no-reason-given", (void *)"no-common-dialogue-portion",
    (void *)0x2, (void *)_v517,
    (void *)"dialogue-service-user", (void *)"dialogue-service-provider",
    (void *)0x3, (void *)_v471,
    (void *)"normal", (void *)"urgent", (void *)"user-defined",
    (void *)0x3, (void *)_v471,
    (void *)"normal", (void *)"not-finished", (void *)"user-defined",
    (void *)0x3, (void *)_v517,
    (void *)"permanent", (void *)"temporaryDefaultRestricted", (void *)"temporaryDefaultAllowed",
    (void *)0x2, (void *)_v517,
    (void *)"overrideEnabled", (void *)"overrideDisabled",
    (void *)0x7, (void *)_v517,
    (void *)"request", (void *)"recall", (void *)"ccbs-RequestState-active", (void *)"completed", (void *)"suspended",
    (void *)"frozen", (void *)"ccbs-RequestState-deleted",
    (void *)0x10002, (void *)_v476,
    (void *)"clir-invoked", (void *)"camel-invoked",
    (void *)0x4, (void *)_v477,
    (void *)"gsm-0408", (void *)"gsm-0806", (void *)"gsm-BSSMAP", (void *)"ets-300102-1",
    (void *)0x4001d, (void *)_v480,
    (void *)"allOG-CallsBarred", (void *)"internationalOGCallsBarred", (void *)"internationalOGCallsNotToHPLMN-CountryBarred", (void *)"premiumRateInformationOGCallsBarred", (void *)"premiumRateEntertainementOGCallsBarred",
    (void *)"ss-AccessBarred", (void *)"interzonalOGCallsBarred", (void *)"interzonalOGCallsNotToHPLMN-CountryBarred", (void *)"interzonalOGCallsAndInternationalOGCallsNotToHPLMN-CountryBarred", (void *)"allECT-Barred",
    (void *)"chargeableECT-Barred", (void *)"internationalECT-Barred", (void *)"interzonalECT-Barred", (void *)"doublyChargeableECT-Barred", (void *)"multipleECT-Barred",
    (void *)"allPacketOrientedServicesBarred", (void *)"roamerAccessToHPLMN-AP-Barred", (void *)"roamerAccessToVPLMN-AP-Barred", (void *)"roamingOutsidePLMNOG-CallsBarred", (void *)"allIC-CallsBarred",
    (void *)"roamingOutsidePLMNIC-CallsBarred", (void *)"roamingOutsidePLMNICountryIC-CallsBarred", (void *)"roamingOutsidePLMN-Barred", (void *)"roamingOutsidePLMN-CountryBarred", (void *)"registrationAllCF-Barred",
    (void *)"registrationCFNotToHPLMN-Barred", (void *)"registrationInterzonalCF-Barred", (void *)"registrationInterzonalCFNotToHPLMN-Barred", (void *)"registrationInternationalCF-Barred",
    (void *)0x10004, (void *)_v481,
    (void *)"plmn-SpecificBarringType1", (void *)"plmn-SpecificBarringType2", (void *)"plmn-SpecificBarringType3", (void *)"plmn-SpecificBarringType4",
    (void *)0x2, (void *)_v517,
    (void *)"deactivate", (void *)"activate",
    (void *)0x10001, (void *)_v483,
    (void *)"mmeAndSgsn",
    (void *)0x9, (void *)_v517,
    (void *)"o-CSI", (void *)"t-CSI", (void *)"vt-CSI", (void *)"tif-CSI", (void *)"gprs-CSI",
    (void *)"sms-CSI", (void *)"ss-CSI", (void *)"m-CSI", (void *)"d-csi",
    (void *)0x5, (void *)_v485,
    (void *)"attach", (void *)"attachChangeOfPosition", (void *)"pdp-ContextEstablishment", (void *)"pdp-ContextEstablishmentAcknowledgement", (void *)"pdp-ContextChangeOfPosition",
    (void *)0x1, (void *)_v525,
    (void *)"oss-unknown-enumerator",
    (void *)0x2, (void *)_v517,
    (void *)"continueTransaction", (void *)"releaseTransaction",
    (void *)0x1, (void *)_v525, (void *)"oss-unknown-enumerator",
    (void *)0x1, (void *)_v512,
    (void *)"collectedInfo",
    (void *)0x2, (void *)_v490, (void *)"routeSelectFailure", (void *)"oss-unknown-enumerator",
    (void *)0x2, (void *)_v517,
    (void *)"continueCall", (void *)"releaseCall",
    (void *)0x1, (void *)_v525, (void *)"oss-unknown-enumerator",
    (void *)0x1, (void *)_v493,
    (void *)"termAttemptAuthorized",
    (void *)0x3, (void *)_v494, (void *)"tBusy", (void *)"tNoAnswer", (void *)"oss-unknown-enumerator",
    (void *)0x1, (void *)_v485,
    (void *)"sms-CollectedInfo",
    (void *)0x1, (void *)_v525, (void *)"oss-unknown-enumerator",
    (void *)0x2, (void *)_v517,
    (void *)"inhibiting", (void *)"enabling",
    (void *)0x2, (void *)_v517,
    (void *)"forwarded", (void *)"notForwarded",
    (void *)0x2, (void *)_v517,
    (void *)"onlyIMSI-requested", (void *)"onlyMCC-MNC-requested",
    (void *)0x1, (void *)_v525, (void *)"oss-unknown-enumerator",
    (void *)0x3, (void *)_v517,
    (void *)"memoryCapacityExceeded", (void *)"absentSubscriber", (void *)"successfulTransfer",
    (void *)0x10005, (void *)_v504,
    (void *)"sc-AddressNotIncluded", (void *)"mnrf-Set", (void *)"mcef-Set", (void *)"mnrg-Set", (void *)"unri-Set",
    (void *)0x2, (void *)_v517,
    (void *)"ms-Present", (void *)"memoryAvailable",
    (void *)0x2, (void *)_v506,
    (void *)"plmnRoamingNotAllowed", (void *)"operatorDeterminedBarring",
    (void *)0x2, (void *)_v517,
    (void *)"barringServiceActive", (void *)"operatorBarring",
    (void *)0x4, (void *)_v508,
    (void *)"incomingCallsBarredWithinCUG", (void *)"subscriberNotMemberOfCUG", (void *)"requestedBasicServiceViolatesCUG-Constraints", (void *)"calledPartySS-InteractionViolation",
    (void *)0x7, (void *)_v517,
    (void *)"memoryCapacityExceeded", (void *)"equipmentProtocolError", (void *)"equipmentNotSM-Equipped", (void *)"unknownServiceCentre", (void *)"sc-Congestion",
    (void *)"invalidSME-Address", (void *)"subscriberNotSC-Subscriber",
    (void *)0x8, (void *)_v517,
    (void *)"plmn", (void *)"hlr", (void *)"vlr", (void *)"pvlr", (void *)"controllingMSC",
    (void *)"vmsc", (void *)"eir", (void *)"rss",
    (void *)0x2, (void *)_v517,
    (void *)"imsiUnknown", (void *)"gprsSubscriptionUnknown",
    (void *)0x2, (void *)_v512, (void *)"npdbMismatch", (void *)"oss-unknown-enumerator",
    (void *)0x3, (void *)_v517,
    (void *)"imsiDetach", (void *)"restrictedArea", (void *)"noPageResponse",
    (void *)0x2, (void *)_v514, (void *)"purgedMS", (void *)"oss-unknown-enumerator",
    (void *)0x5, (void *)_v517,
    (void *)"noAdditionalInformation", (void *)"clientNotInMSPrivacyExceptionList", (void *)"callToClientNotSetup", (void *)"privacyOverrideNotApplicable", (void *)"disallowedByLocalRegulatoryRequirements",
    (void *)0x1, (void *)_v525,
    (void *)"oss-unknown-enumerator",
    (void *)0x9, (void *)_v517,
    (void *)"congestion", (void *)"insufficientResources", (void *)"insufficientMeasurementData", (void *)"inconsistentMeasurementData", (void *)"locationProcedureNotCompleted",
    (void *)"locationProcedureNotSupportedByTargetMS", (void *)"qoSNotAttainable", (void *)"positionMethodNotAvailableInNetwork", (void *)"positionMethodNotAvailableInLocationArea",
    (void *)0x1, (void *)_v525, (void *)"oss-unknown-enumerator",
    (void *)0x3, (void *)_v517,
    (void *)"noProtection", (void *)"integrityAuthenticity", (void *)"confidentialityIntegrityAuthenticity",
    (void *)0x4, (void *)_v517,
    (void *)"ecb", (void *)"cbc", (void *)"cfb", (void *)"ofb",
    (void *)0x1, (void *)_v525, (void *)"oss-unknown-enumerator",
    (void *)0x1, (void *)_v485,
    (void *)"ets-300356",
    (void *)0x1, (void *)_v525, (void *)"oss-unknown-enumerator",
    (void *)0x2, (void *)_v485,
    (void *)"gsm-0806", (void *)"ts3G-25413",
    (void *)0x1, (void *)_v525, (void *)"oss-unknown-enumerator",
    (void *)"invokeId",
    (void *)"problem",
    (void *)"present",
    (void *)"absent",
    (void *)"unidirectional",
    (void *)"begin",
    (void *)"end",
    (void *)"continue",
    (void *)"abort",
    (void *)"dialogueRequest",
    (void *)"dialogueResponse",
    (void *)"dialogueAbort",
    (void *)"reason",
    (void *)"user-information",
    (void *)"unidialoguePDU",
    (void *)"localValue",
    (void *)"globalValue",
    (void *)"ss-Code",
    (void *)"basicService",
    (void *)"forwardedToNumber",
    (void *)"forwardedToSubaddress",
    (void *)"noReplyConditionTime",
    (void *)"defaultPriority",
    (void *)"nbrUser",
    (void *)"longFTN-Supported",
    (void *)"ss-Status",
    (void *)"basicServiceGroupList",
    (void *)"forwardingFeatureList",
    (void *)"genericServiceInfo",
    (void *)"ussd-DataCodingScheme",
    (void *)"ussd-String",
    (void *)"alertingPattern",
    (void *)"msisdn",
    (void *)"imsi",
    (void *)"ss-Event",
    (void *)"ss-EventSpecification",
    (void *)"extensionContainer",
    (void *)"b-subscriberNumber",
    (void *)"ccbs-RequestState",
    (void *)"ccbs-Data",
    (void *)"ccbs-Feature",
    (void *)"ccbs-Index",
    (void *)"subscriberIdentity",
    (void *)"gsmSCF-Address",
    (void *)"modificationRequestFor-CF-Info",
    (void *)"modificationRequestFor-CB-Info",
    (void *)"modificationRequestFor-CSI",
    (void *)"modificationRequestFor-ODB-data",
    (void *)"modificationRequestFor-IP-SM-GW-Data",
    (void *)"activationRequestForUE-reachability",
    (void *)"modificationRequestFor-CSG",
    (void *)"modificationRequestFor-CW-Data",
    (void *)"modificationRequestFor-CLIP-Data",
    (void *)"modificationRequestFor-CLIR-Data",
    (void *)"modificationRequestFor-HOLD-Data",
    (void *)"modificationRequestFor-ECT-Data",
    (void *)"ss-InfoFor-CSE",
    (void *)"camel-SubscriptionInfo",
    (void *)"odb-Info",
    (void *)"cw-Data",
    (void *)"ch-Data",
    (void *)"clip-Data",
    (void *)"clir-Data",
    (void *)"ect-data",
    (void *)"sm-RP-PRI",
    (void *)"serviceCentreAddress",
    (void *)"gprsSupportIndicator",
    (void *)"sm-RP-MTI",
    (void *)"sm-RP-SMEA",
    (void *)"sm-deliveryNotIntended",
    (void *)"ip-sm-gwGuidanceIndicator",
    (void *)"t4-Trigger-Indicator",
    (void *)"singleAttemptDelivery",
    (void *)"correlationID",
    (void *)"teleservice",
    (void *)"locationInfoWithLMSI-V3",
    (void *)"ip-sm-gwGuidance",
    (void *)"locationInfoWithLMSI-V2",
    (void *)"mwd-Set",
    (void *)"sm-RP-DA",
    (void *)"sm-RP-OA",
    (void *)"sm-RP-UI",
    (void *)"sm-DeliveryOutcome",
    (void *)"moreMessagesToSend",
    (void *)"smDeliveryTimer",
    (void *)"smDeliveryStartTime",
    (void *)"smsOverIP-OnlyIndicator",
    (void *)"maximumRetransmissionTime",
    (void *)"requestedRetransmissionTime",
    (void *)"absentSubscriberDiagnosticSM",
    (void *)"deliveryOutcomeIndicator",
    (void *)"additionalSM-DeliveryOutcome",
    (void *)"additionalAbsentSubscriberDiagnosticSM",
    (void *)"ip-sm-gw-Indicator",
    (void *)"ip-sm-gw-sm-deliveryOutcome",
    (void *)"ip-sm-gw-absentSubscriberDiagnosticSM",
    (void *)"storedMSISDN",
    (void *)"mw-Status",
    (void *)"alertReason",
    (void *)"alertReasonIndicator",
    (void *)"additionalAlertReasonIndicator",
    (void *)"maximumUeAvailabilityTime",
    (void *)"roamingNotAllowedCause",
    (void *)"callBarringCause",
    (void *)"extensibleCallBarredParam",
    (void *)"cug-RejectCause",
    (void *)"sm-EnumeratedDeliveryFailureCause",
    (void *)"diagnosticInfo",
    (void *)"networkResource",
    (void *)"extensibleSystemFailureParam",
    (void *)"unknownSubscriberDiagnostic",
    (void *)"absentSubscriberReason",
    (void *)"ccbs-Possible",
    (void *)"ccbs-Busy",
    (void *)"gprsConnectionSuspended",
    (void *)"unauthorizedLCSClient-Diagnostic",
    (void *)"positionMethodFailure-Diagnostic",
    (void *)"securityHeader",
    (void *)"protectedPayload",
    (void *)"ext-ProtocolId",
    (void *)"signalInfo",
    (void *)"accessNetworkProtocolId",
    (void *)"imsi-WithLMSI",
    (void *)"tmsi",
    (void *)"naea-PreferredCIC",
    (void *)"externalAddress",
    (void *)"cellGlobalIdOrServiceAreaIdFixedLength",
    (void *)"laiFixedLength",
    (void *)"ext-BearerService",
    (void *)"ext-Teleservice",
    (void *)"maximumentitledPriority",
    (void *)"nbrSB",
    (void *)"camelServiceType",
    (void *)"smsIndicator",
    (void *)"single-ASN1-type",
    (void *)"octet-aligned",
    (void *)"arbitrary",
    (void *)"direct-reference",
    (void *)"indirect-reference",
    (void *)"data-value-descriptor",
    (void *)"encoding",
    (void *)"local",
    (void *)"global",
    (void *)"ParameterType",
    (void *)"parameterTypeOptional",
    (void *)"ErrorPriority",
    (void *)"errorCode",
    (void *)"ArgumentType",
    (void *)"argumentTypeOptional",
    (void *)"resultResult", (void *)&_v2,
    (void *)"ResultType",
    (void *)"resultTypeOptional",
    (void *)"Errors",
    (void *)"Linked",
    (void *)"synchronous", (void *)&_v3,
    (void *)"alwaysReturns", (void *)&_v2,
    (void *)"InvokePriority",
    (void *)"ResultPriority",
    (void *)"operationCode",
    (void *)"general",
    (void *)"invoke",
    (void *)"returnResult",
    (void *)"returnError",
    (void *)"invokeID",
    (void *)"linkedID",
    (void *)"parameter",
    (void *)"result",
    (void *)"derivable",
    (void *)"not-derivable",
    (void *)"generalProblem",
    (void *)"invokeProblem",
    (void *)"returnResultProblem",
    (void *)"returnErrorProblem",
    (void *)"returnResultLast",
    (void *)"reject",
    (void *)"returnResultNotLast",
    (void *)"dialoguePortion",
    (void *)"components",
    (void *)"otid",
    (void *)"dtid",
    (void *)"p-abortCause",
    (void *)"u-abortCause",
    (void *)"protocol-version", (void *)&_v4,
    (void *)"application-context-name",
    (void *)"dialogue-service-user",
    (void *)"dialogue-service-provider",
    (void *)"protocol-version", (void *)&_v6,
    (void *)"result-source-diagnostic",
    (void *)"abort-source",
    (void *)"protocol-version", (void *)&_v7,
    (void *)"bearerService",
    (void *)"callBarringFeatureList",
    (void *)"cliRestrictionOption",
    (void *)"overrideCategory",
    (void *)"ss-SubscriptionOption",
    (void *)"forwardingInfo",
    (void *)"callBarringInfo",
    (void *)"ss-Data",
    (void *)"forwardingOptions",
    (void *)"longForwardedToNumber",
    (void *)"maximumEntitledPriority",
    (void *)"ccbs-FeatureList",
    (void *)"nbrSN",
    (void *)"b-subscriberSubaddress",
    (void *)"basicServiceGroup",
    (void *)"privateExtensionList",
    (void *)"pcs-Extensions",
    (void *)"protocolId",
    (void *)"translatedB-Number",
    (void *)"serviceIndicator",
    (void *)"callInfo",
    (void *)"networkSignalInfo",
    (void *)"cwFeatureList",
    (void *)"notificationToCSE",
    (void *)"odb-GeneralData",
    (void *)"odb-HPLMN-Data",
    (void *)"odb-Data",
    (void *)"modifyNotificationToCSE",
    (void *)"password",
    (void *)"wrongPasswordAttemptsCounter",
    (void *)"forwardingInfoFor-CSE",
    (void *)"callBarringInfoFor-CSE",
    (void *)"gprs-CamelTDPDataList",
    (void *)"camelCapabilityHandling",
    (void *)"csi-Active",
    (void *)"requestedCamel-SubscriptionInfo",
    (void *)"modifyCSI-State",
    (void *)"mobilityTriggers",
    (void *)"serviceKey",
    (void *)"o-BcsmCamelTDPDataList",
    (void *)"csiActive",
    (void *)"dp-AnalysedInfoCriteriaList",
    (void *)"t-BcsmCamelTDPDataList",
    (void *)"ss-EventList",
    (void *)"ss-CamelData",
    (void *)"gprs-TriggerDetectionPoint",
    (void *)"defaultSessionHandling",
    (void *)"sms-CAMEL-TDP-DataList",
    (void *)"o-CSI",
    (void *)"o-BcsmCamelTDP-CriteriaList",
    (void *)"d-CSI",
    (void *)"t-CSI",
    (void *)"t-BCSM-CAMEL-TDP-CriteriaList",
    (void *)"vt-CSI",
    (void *)"vt-BCSM-CAMEL-TDP-CriteriaList",
    (void *)"tif-CSI",
    (void *)"tif-CSI-NotificationToCSE",
    (void *)"gprs-CSI",
    (void *)"sms-CSI",
    (void *)"ss-CSI",
    (void *)"m-CSI",
    (void *)"o-BcsmTriggerDetectionPoint",
    (void *)"defaultCallHandling",
    (void *)"t-BcsmTriggerDetectionPoint",
    (void *)"sms-TriggerDetectionPoint",
    (void *)"defaultSMS-Handling",
    (void *)"dialledNumber",
    (void *)"matchType",
    (void *)"destinationNumberList",
    (void *)"destinationNumberLengthList",
    (void *)"destinationNumberCriteria",
    (void *)"basicServiceCriteria",
    (void *)"callTypeCriteria",
    (void *)"o-CauseValueCriteria",
    (void *)"t-BCSM-TriggerDetectionPoint",
    (void *)"t-CauseValueCriteria",
    (void *)"modifyRegistrationStatus",
    (void *)"odb-data",
    (void *)"hlr-id",
    (void *)"sip-uri-A",
    (void *)"sip-uri-B",
    (void *)"msc-Number",
    (void *)"sgsn-Number",
    (void *)"diameter-Name",
    (void *)"diameter-Realm",
    (void *)"networkNode-Number",
    (void *)"lmsi",
    (void *)"gprsNodeIndicator",
    (void *)"additional-Number",
    (void *)"networkNodeDiameterAddress",
    (void *)"additionalNetworkNodeDiameterAddress",
    (void *)"thirdNumber",
    (void *)"thirdNetworkNodeDiameterAddress",
    (void *)"imsNodeIndicator",
    (void *)"minimumDeliveryTimeValue",
    (void *)"recommendedDeliveryTimeValue",
    (void *)"roamingNumber",
    (void *)"locationInfo",
    (void *)"serviceCentreAddressDA",
    (void *)"noSM-RP-DA",
    (void *)"serviceCentreAddressOA",
    (void *)"noSM-RP-OA",
    (void *)"unauthorisedMessageOriginator",
    (void *)"userInfo",
    (void *)"originalComponentIdentifier",
    (void *)"sendingPLMN-Id",
    (void *)"protectionMode",
    (void *)"encryptionAlgorithmIdentifier",
    (void *)"modeOfOperation",
    (void *)"encryptionKeyVersionNumber",
    (void *)"initialisationVector",
    (void *)"hashAlgorithmIdentifier",
    (void *)"hashKeyVersionNumber",
    (void *)"ExtensionType",
    (void *)"extensionId",
    (void *)"_oss_unique_index",
    (void *)"extId",
    (void *)"extType"
};

static const Etag _tagarray[] = {
    1, 0x0006, 1, 0x0010, 6, 11, 2, 0x0002, 1, 0x0005,
    1, 4, 0x8000, 2, 0x8001, 2, 0x8002, 2, 0x8003, 2,
    0, 2, 0x0002, 1, 0x0005, 2, 5, 0x4001, 1, 0x4002,
    2, 0x4004, 3, 0x4005, 4, 0x4007, 5, 3, 0x4000, 1,
    0x4001, 2, 0x4004, 3, 1, 0x4002, 48, 53, 2, 0x8000,
    1, 0x801e, 2, 1, 0x801e, 2, 1, 0x4003, 1, 0x4000,
    1, 2, 0x0002, 1, 0x0006, 2, 74, 77, 94, 107,
    118, 127, 134, 139, 1, 0x0004, 1, 8, 0x8002, 2,
    0x8003, 2, 0x8004, 3, 0x8005, 5, 0x8006, 4, 0x8007, 6,
    0x8008, 7, 0x8009, 8, 6, 0x8004, 3, 0x8005, 5, 0x8006,
    4, 0x8007, 6, 0x8008, 7, 0x8009, 8, 5, 0x8005, 5,
    0x8006, 4, 0x8007, 6, 0x8008, 7, 0x8009, 8, 4, 0x8005,
    5, 0x8007, 6, 0x8008, 7, 0x8009, 8, 3, 0x8007, 6,
    0x8008, 7, 0x8009, 8, 2, 0x8008, 7, 0x8009, 8, 1,
    0x8009, 8, 145, 148, 155, 1, 0x0004, 1, 3, 0x8002,
    2, 0x8003, 2, 0x8004, 3, 1, 0x8004, 3, 4, 0x8000,
    1, 0x8002, 2, 0x8003, 3, 0x8004, 4, 171, 174, 177,
    182, 1, 0x0004, 1, 1, 0x0004, 2, 2, 0x0004, 3,
    0x8000, 4, 1, 0x8000, 4, 187, 190, 1, 0x0004, 1,
    1, 0x0004, 2, 1, 0x0012, 1, 0x000a, 204, 207, 210,
    213, 222, 229, 234, 1, 0x8000, 1, 1, 0x8001, 2,
    1, 0x8002, 3, 4, 0x8003, 4, 0x8004, 5, 0x8005, 6,
    0x8006, 7, 3, 0x8004, 5, 0x8005, 6, 0x8006, 7, 2,
    0x8005, 6, 0x8006, 7, 1, 0x8006, 7, 238, 1, 0x0010,
    1, 243, 246, 1, 0x8000, 1, 1, 0x8001, 2, 250,
    1, 0x8000, 1, 269, 272, 275, 304, 331, 356, 379,
    400, 419, 436, 451, 464, 475, 484, 491, 496, 1,
    0x8000, 1, 1, 0x8001, 2, 14, 0x8002, 3, 0x8003, 4,
    0x8004, 5, 0x8005, 6, 0x8006, 7, 0x8007, 8, 0x8008, 9,
    0x8009, 10, 0x800a, 11, 0x800b, 12, 0x800c, 13, 0x800d, 14,
    0x800e, 15, 0x800f, 16, 13, 0x8003, 4, 0x8004, 5, 0x8005,
    6, 0x8006, 7, 0x8007, 8, 0x8008, 9, 0x8009, 10, 0x800a,
    11, 0x800b, 12, 0x800c, 13, 0x800d, 14, 0x800e, 15, 0x800f,
    16, 12, 0x8004, 5, 0x8005, 6, 0x8006, 7, 0x8007, 8,
    0x8008, 9, 0x8009, 10, 0x800a, 11, 0x800b, 12, 0x800c, 13,
    0x800d, 14, 0x800e, 15, 0x800f, 16, 11, 0x8005, 6, 0x8006,
    7, 0x8007, 8, 0x8008, 9, 0x8009, 10, 0x800a, 11, 0x800b,
    12, 0x800c, 13, 0x800d, 14, 0x800e, 15, 0x800f, 16, 10,
    0x8006, 7, 0x8007, 8, 0x8008, 9, 0x8009, 10, 0x800a, 11,
    0x800b, 12, 0x800c, 13, 0x800d, 14, 0x800e, 15, 0x800f, 16,
    9, 0x8007, 8, 0x8008, 9, 0x8009, 10, 0x800a, 11, 0x800b,
    12, 0x800c, 13, 0x800d, 14, 0x800e, 15, 0x800f, 16, 8,
    0x8008, 9, 0x8009, 10, 0x800a, 11, 0x800b, 12, 0x800c, 13,
    0x800d, 14, 0x800e, 15, 0x800f, 16, 7, 0x8009, 10, 0x800a,
    11, 0x800b, 12, 0x800c, 13, 0x800d, 14, 0x800e, 15, 0x800f,
    16, 6, 0x800a, 11, 0x800b, 12, 0x800c, 13, 0x800d, 14,
    0x800e, 15, 0x800f, 16, 5, 0x800b, 12, 0x800c, 13, 0x800d,
    14, 0x800e, 15, 0x800f, 16, 4, 0x800c, 13, 0x800d, 14,
    0x800e, 15, 0x800f, 16, 3, 0x800d, 14, 0x800e, 15, 0x800f,
    16, 2, 0x800e, 15, 0x800f, 16, 1, 0x800f, 16, 508,
    527, 544, 559, 572, 583, 592, 599, 604, 9, 0x8000,
    1, 0x8001, 2, 0x8002, 3, 0x8003, 4, 0x8004, 5, 0x8005,
    6, 0x8006, 7, 0x8007, 8, 0x8008, 9, 8, 0x8001, 2,
    0x8002, 3, 0x8003, 4, 0x8004, 5, 0x8005, 6, 0x8006, 7,
    0x8007, 8, 0x8008, 9, 7, 0x8002, 3, 0x8003, 4, 0x8004,
    5, 0x8005, 6, 0x8006, 7, 0x8007, 8, 0x8008, 9, 6,
    0x8003, 4, 0x8004, 5, 0x8005, 6, 0x8006, 7, 0x8007, 8,
    0x8008, 9, 5, 0x8004, 5, 0x8005, 6, 0x8006, 7, 0x8007,
    8, 0x8008, 9, 4, 0x8005, 6, 0x8006, 7, 0x8007, 8,
    0x8008, 9, 3, 0x8006, 7, 0x8007, 8, 0x8008, 9, 2,
    0x8007, 8, 0x8008, 9, 1, 0x8008, 9, 620, 623, 626,
    629, 650, 669, 686, 701, 714, 725, 734, 741, 746,
    1, 0x8000, 1, 1, 0x8001, 2, 1, 0x8002, 3, 10,
    0x8006, 4, 0x8007, 5, 0x8008, 6, 0x8009, 7, 0x800a, 8,
    0x800b, 9, 0x800c, 10, 0x800d, 12, 0x800e, 11, 0x800f, 13,
    9, 0x8007, 5, 0x8008, 6, 0x8009, 7, 0x800a, 8, 0x800b,
    9, 0x800c, 10, 0x800d, 12, 0x800e, 11, 0x800f, 13, 8,
    0x8008, 6, 0x8009, 7, 0x800a, 8, 0x800b, 9, 0x800c, 10,
    0x800d, 12, 0x800e, 11, 0x800f, 13, 7, 0x8009, 7, 0x800a,
    8, 0x800b, 9, 0x800c, 10, 0x800d, 12, 0x800e, 11, 0x800f,
    13, 6, 0x800a, 8, 0x800b, 9, 0x800c, 10, 0x800d, 12,
    0x800e, 11, 0x800f, 13, 5, 0x800b, 9, 0x800c, 10, 0x800d,
    12, 0x800e, 11, 0x800f, 13, 4, 0x800c, 10, 0x800d, 12,
    0x800e, 11, 0x800f, 13, 3, 0x800d, 12, 0x800e, 11, 0x800f,
    13, 2, 0x800d, 12, 0x800f, 13, 1, 0x800f, 13, 753,
    756, 759, 762, 1, 0x8000, 1, 1, 0x8001, 2, 1,
    0x8002, 3, 1, 0x8003, 4, 769, 772, 775, 780, 1,
    0x0004, 1, 1, 0x8000, 2, 2, 0x8004, 3, 0x8005, 4,
    1, 0x8005, 4, 786, 789, 792, 1, 0x0004, 1, 1,
    0x8000, 2, 1, 0x8002, 3, 802, 813, 820, 823, 832,
    839, 844, 5, 0x8000, 1, 0x8001, 1, 0x8003, 1, 0x8004,
    1, 0x8005, 1, 3, 0x8002, 2, 0x8004, 2, 0x8005, 2,
    1, 0x0004, 3, 4, 0x0004, 5, 0x0010, 4, 0x8000, 6,
    0x8001, 7, 3, 0x0004, 5, 0x8000, 6, 0x8001, 7, 2,
    0x8000, 6, 0x8001, 7, 1, 0x8001, 7, 849, 854, 2,
    0x0004, 1, 0x0010, 2, 1, 0x0010, 2, 867, 878, 885,
    888, 903, 916, 927, 936, 943, 948, 5, 0x8000, 1,
    0x8001, 1, 0x8003, 1, 0x8004, 1, 0x8005, 1, 3, 0x8002,
    2, 0x8004, 2, 0x8005, 2, 1, 0x0004, 3, 7, 0x0002,
    6, 0x0004, 7, 0x0005, 4, 0x0010, 5, 0x8000, 8, 0x8001,
    9, 0x8002, 10, 6, 0x0002, 6, 0x0004, 7, 0x0010, 5,
    0x8000, 8, 0x8001, 9, 0x8002, 10, 5, 0x0002, 6, 0x0004,
    7, 0x8000, 8, 0x8001, 9, 0x8002, 10, 4, 0x0004, 7,
    0x8000, 8, 0x8001, 9, 0x8002, 10, 3, 0x8000, 8, 0x8001,
    9, 0x8002, 10, 2, 0x8001, 9, 0x8002, 10, 1, 0x8002,
    10, 955, 966, 973, 976, 5, 0x8000, 1, 0x8001, 1,
    0x8003, 1, 0x8004, 1, 0x8005, 1, 3, 0x8002, 2, 0x8004,
    2, 0x8005, 2, 1, 0x0004, 3, 1, 0x0005, 4, 982,
    989, 994, 3, 0x0004, 1, 0x0010, 2, 0x8000, 3, 2,
    0x0010, 2, 0x8000, 3, 1, 0x8000, 3, 1012, 1015, 1018,
    1021, 1046, 1069, 1090, 1109, 1126, 1141, 1154, 1165, 1174,
    1181, 1186, 1, 0x0004, 1, 1, 0x0004, 2, 1, 0x000a,
    3, 12, 0x8000, 4, 0x8001, 5, 0x8002, 6, 0x8003, 7,
    0x8004, 8, 0x8005, 9, 0x8006, 10, 0x8007, 11, 0x8008, 12,
    0x8009, 13, 0x800a, 14, 0x800b, 15, 11, 0x8001, 5, 0x8002,
    6, 0x8003, 7, 0x8004, 8, 0x8005, 9, 0x8006, 10, 0x8007,
    11, 0x8008, 12, 0x8009, 13, 0x800a, 14, 0x800b, 15, 10,
    0x8002, 6, 0x8003, 7, 0x8004, 8, 0x8005, 9, 0x8006, 10,
    0x8007, 11, 0x8008, 12, 0x8009, 13, 0x800a, 14, 0x800b, 15,
    9, 0x8003, 7, 0x8004, 8, 0x8005, 9, 0x8006, 10, 0x8007,
    11, 0x8008, 12, 0x8009, 13, 0x800a, 14, 0x800b, 15, 8,
    0x8004, 8, 0x8005, 9, 0x8006, 10, 0x8007, 11, 0x8008, 12,
    0x8009, 13, 0x800a, 14, 0x800b, 15, 7, 0x8005, 9, 0x8006,
    10, 0x8007, 11, 0x8008, 12, 0x8009, 13, 0x800a, 14, 0x800b,
    15, 6, 0x8006, 10, 0x8007, 11, 0x8008, 12, 0x8009, 13,
    0x800a, 14, 0x800b, 15, 5, 0x8007, 11, 0x8008, 12, 0x8009,
    13, 0x800a, 14, 0x800b, 15, 4, 0x8008, 12, 0x8009, 13,
    0x800a, 14, 0x800b, 15, 3, 0x8009, 13, 0x800a, 14, 0x800b,
    15, 2, 0x800a, 14, 0x800b, 15, 1, 0x800b, 15, 1192,
    1195, 1198, 1, 0x0004, 1, 1, 0x0004, 2, 1, 0x000a,
    3, 1204, 1211, 1216, 3, 0x0003, 2, 0x0004, 1, 0x0010,
    3, 2, 0x0003, 2, 0x0010, 3, 1, 0x0010, 3, 1221,
    1226, 2, 0x0003, 2, 0x0004, 1, 1, 0x0003, 2, 1235,
    1238, 1241, 1250, 1257, 1262, 1, 0x8000, 1, 1, 0x000a,
    2, 4, 0x0004, 6, 0x0005, 3, 0x0010, 4, 0x8001, 5,
    3, 0x0004, 6, 0x0010, 4, 0x8001, 5, 2, 0x0004, 6,
    0x8001, 5, 1, 0x0004, 6, 1267, 1270, 1, 0x000a, 1,
    1, 0x0010, 2, 2, 0x000a, 1, 0x0010, 2, 1280, 1285,
    2, 0x000a, 1, 0x0010, 2, 1, 0x0010, 2, 1291, 1300,
    1307, 4, 0x8001, 1, 0x8002, 2, 0x8003, 2, 0x8004, 3,
    3, 0x8002, 2, 0x8003, 2, 0x8004, 3, 1, 0x8004, 3,
    1313, 1316, 1321, 1, 0x000a, 1, 2, 0x0004, 2, 0x0010,
    3, 1, 0x0010, 3, 1327, 1334, 1339, 3, 0x0002, 1,
    0x0010, 2, 0x8000, 3, 2, 0x0010, 2, 0x8000, 3, 1,
    0x8000, 3, 1344, 1349, 2, 0x000a, 2, 0x0010, 1, 1,
    0x000a, 2, 1354, 1359, 2, 0x0010, 1, 0x8000, 2, 1,
    0x8000, 2, 1365, 1372, 1377, 3, 0x0010, 1, 0x8000, 2,
    0x8001, 3, 2, 0x8000, 2, 0x8001, 3, 1, 0x8001, 3,
    1382, 1387, 2, 0x0005, 2, 0x0010, 1, 1, 0x0005, 2,
    1392, 1397, 2, 0x8000, 1, 0x8001, 2, 1, 0x8001, 2,
    1402, 1405, 1, 0x0010, 1, 1, 0x0004, 2, 1411, 1414,
    1417, 1, 0x000a, 1, 1, 0x0004, 2, 1, 0x0010, 3,
    2, 0x0004, 1, 0x0010, 2, 1, 0x0004, 2, 0x8000, 1,
    0x8001, 2, 2, 0x8002, 1, 0x8003, 2, 1440, 1443, 1446,
    1, 0x0002, 1, 1, 0x0002, 2, 1, 0x0010, 3, 1454,
    1457, 1460, 1463, 1466, 1, 0x8000, 1, 1, 0x8001, 2,
    1, 0x8002, 3, 1, 0x8003, 4, 1, 0x8004, 5, 1,
    0x0002, 1473, 1478, 2, 0x0002, 1, 0x0004, 2, 1, 0x0004,
    2, 1, 0x0007, 1, 0x8000, 1, 0x8001, 1, 0x8002, 3,
    0x8000, 1, 0x8001, 2, 0x8002, 3, 1, 0x0008, 1502, 1515,
    1526, 1535, 6, 0x0002, 2, 0x0006, 1, 0x0007, 3, 0x8000,
    4, 0x8001, 4, 0x8002, 4, 5, 0x0002, 2, 0x0007, 3,
    0x8000, 4, 0x8001, 4, 0x8002, 4, 4, 0x0007, 3, 0x8000,
    4, 0x8001, 4, 0x8002, 4, 3, 0x8000, 4, 0x8001, 4,
    0x8002, 4, 1, 0x0001, 1, 0x0005, 1, 0x8003, 4, 0x8000,
    1, 0x8001, 2, 0x8002, 3, 0x8003, 4, 2, 0x400b, 0x0008,
    1564, 1567, 1574, 1579, 1, 0x0002, 1, 3, 0x0002, 3,
    0x0006, 3, 0x8000, 2, 2, 0x0002, 3, 0x0006, 3, 0,
    1582, 1587, 2, 0x0002, 1, 0x0006, 1, 0, 1590, 1593,
    1, 0x0002, 1, 1, 0x0010, 2, 1599, 1602, 1607, 1,
    0x0002, 1, 2, 0x0002, 2, 0x0006, 2, 0, 1, 0x8004,
    1, 0x8007, 5, 0x8001, 1, 0x8002, 2, 0x8003, 3, 0x8004,
    4, 0x8007, 5, 1, 0x400c, 1627, 1632, 2, 0x400b, 1,
    0x400c, 2, 1, 0x400c, 2, 1, 0x4008, 1640, 1643, 1648,
    1, 0x4008, 1, 2, 0x400b, 2, 0x400c, 3, 1, 0x400c,
    3, 1, 0x4009, 1656, 1659, 1664, 1, 0x4009, 1, 2,
    0x400b, 2, 0x400c, 3, 1, 0x400c, 3, 1671, 1674, 1677,
    1682, 1, 0x4008, 1, 1, 0x4009, 2, 2, 0x400b, 3,
    0x400c, 4, 1, 0x400c, 4, 1, 0x400a, 2, 0x400a, 1,
    0x400b, 2, 1694, 1697, 1, 0x4009, 1, 2, 0x400a, 2,
    0x400b, 2, 1, 0x4001, 1, 0x4004, 1, 0x4005, 1, 0x4007,
    1, 0x801e, 2, 0x8001, 0x0006, 1, 0x4000, 1720, 1725, 1728,
    2, 0x8000, 1, 0x8001, 2, 1, 0x8001, 2, 1, 0x801e,
    3, 2, 0x8001, 0x0002, 2, 0x8002, 0x0002, 2, 0x8001, 1,
    0x8002, 2, 1747, 1752, 1755, 1758, 1761, 2, 0x8000, 1,
    0x8001, 2, 1, 0x8001, 2, 1, 0x8002, 3, 1, 0x8003,
    4, 1, 0x801e, 5, 1766, 1769, 1, 0x8000, 1, 1,
    0x801e, 2, 1, 0x8006, 1, 0x8005, 1, 0x8008, 1, 0x8009,
    2, 0x8001, 2, 0x8002, 1, 1791, 1806, 1819, 1830, 1837,
    1842, 7, 0x0002, 5, 0x0004, 1, 0x0010, 4, 0x8001, 3,
    0x8002, 3, 0x8004, 2, 0x8005, 6, 6, 0x0002, 5, 0x0010,
    4, 0x8001, 3, 0x8002, 3, 0x8004, 2, 0x8005, 6, 5,
    0x0002, 5, 0x0010, 4, 0x8001, 3, 0x8002, 3, 0x8005, 6,
    3, 0x0002, 5, 0x0010, 4, 0x8005, 6, 2, 0x0002, 5,
    0x8005, 6, 1, 0x8005, 6, 3, 0x8000, 1, 0x8001, 2,
    0x8003, 3, 1859, 1876, 1889, 1900, 1909, 1916, 1921, 8,
    0x8002, 1, 0x8003, 1, 0x8004, 2, 0x8005, 3, 0x8006, 5,
    0x8007, 6, 0x8008, 4, 0x8009, 7, 6, 0x8004, 2, 0x8005,
    3, 0x8006, 5, 0x8007, 6, 0x8008, 4, 0x8009, 7, 5,
    0x8005, 3, 0x8006, 5, 0x8007, 6, 0x8008, 4, 0x8009, 7,
    4, 0x8006, 5, 0x8007, 6, 0x8008, 4, 0x8009, 7, 3,
    0x8006, 5, 0x8007, 6, 0x8009, 7, 2, 0x8007, 6, 0x8009,
    7, 1, 0x8009, 7, 1926, 1933, 3, 0x8002, 1, 0x8003,
    1, 0x8004, 2, 1, 0x8004, 2, 1944, 1947, 1962, 1975,
    1986, 1995, 2002, 2007, 1, 0x0004, 1, 7, 0x000a, 2,
    0x8000, 3, 0x8001, 4, 0x8002, 5, 0x8003, 6, 0x8004, 7,
    0x8005, 8, 6, 0x8000, 3, 0x8001, 4, 0x8002, 5, 0x8003,
    6, 0x8004, 7, 0x8005, 8, 5, 0x8001, 4, 0x8002, 5,
    0x8003, 6, 0x8004, 7, 0x8005, 8, 4, 0x8002, 5, 0x8003,
    6, 0x8004, 7, 0x8005, 8, 3, 0x8003, 6, 0x8004, 7,
    0x8005, 8, 2, 0x8004, 7, 0x8005, 8, 1, 0x8005, 8,
    2014, 2023, 2030, 2035, 4, 0x8000, 1, 0x8001, 2, 0x8002,
    3, 0x8003, 4, 3, 0x8001, 2, 0x8002, 3, 0x8003, 4,
    2, 0x8002, 3, 0x8003, 4, 1, 0x8003, 4, 1, 0x0003,
    2045, 2048, 2051, 2056, 2059, 1, 0x8000, 1, 1, 0x8001,
    2, 2, 0x8002, 3, 0x8003, 4, 1, 0x8003, 4, 1,
    0x8004, 5, 2064, 2067, 1, 0x8001, 1, 1, 0x8002, 2,
    2073, 2076, 2079, 1, 0x8001, 1, 1, 0x8002, 2, 1,
    0x8003, 3, 2085, 2088, 2093, 1, 0x8001, 1, 2, 0x8002,
    2, 0x8003, 3, 1, 0x8003, 3, 2099, 2102, 2107, 1,
    0x0003, 1, 2, 0x0003, 2, 0x0010, 3, 1, 0x0010, 3,
    2113, 2116, 2121, 1, 0x0010, 1, 2, 0x0005, 2, 0x0010,
    3, 1, 0x0010, 3, 2127, 2134, 2139, 3, 0x8000, 1,
    0x8001, 2, 0x8002, 3, 2, 0x8001, 2, 0x8002, 3, 1,
    0x8002, 3, 2148, 2151, 2154, 2157, 2160, 2163, 1, 0x8000,
    1, 1, 0x8001, 2, 1, 0x8002, 3, 1, 0x8003, 4,
    1, 0x8004, 5, 1, 0x8005, 6, 1, 0x800a, 2176, 2183,
    2186, 2199, 2210, 2219, 2226, 2231, 3, 0x8002, 1, 0x8003,
    1, 0x8004, 2, 1, 0x8004, 2, 6, 0x8005, 3, 0x8006,
    5, 0x8007, 6, 0x8008, 4, 0x8009, 7, 0x800a, 8, 5,
    0x8006, 5, 0x8007, 6, 0x8008, 4, 0x8009, 7, 0x800a, 8,
    4, 0x8006, 5, 0x8007, 6, 0x8009, 7, 0x800a, 8, 3,
    0x8007, 6, 0x8009, 7, 0x800a, 8, 2, 0x8009, 7, 0x800a,
    8, 1, 0x800a, 8, 2239, 2250, 2259, 2266, 2271, 5,
    0x8000, 1, 0x8001, 2, 0x8002, 3, 0x8003, 4, 0x8004, 5,
    4, 0x8001, 2, 0x8002, 3, 0x8003, 4, 0x8004, 5, 3,
    0x8002, 3, 0x8003, 4, 0x8004, 5, 2, 0x8003, 4, 0x8004,
    5, 1, 0x8004, 5, 2277, 2284, 2287, 3, 0x8002, 1,
    0x8003, 1, 0x8004, 2, 1, 0x8004, 2, 1, 0x0010, 3,
    2294, 2297, 2304, 2309, 1, 0x8000, 1, 3, 0x8001, 2,
    0x8002, 3, 0x8003, 4, 2, 0x8002, 3, 0x8003, 4, 1,
    0x8003, 4, 2318, 2321, 2324, 2327, 2334, 2339, 1, 0x0010,
    1, 1, 0x0002, 2, 1, 0x8000, 3, 3, 0x8001, 4,
    0x8002, 5, 0x8003, 6, 2, 0x8002, 5, 0x8003, 6, 1,
    0x8003, 6, 2347, 2350, 2359, 2366, 2371, 1, 0x0010, 1,
    4, 0x0010, 2, 0x8000, 3, 0x8001, 4, 0x8002, 5, 3,
    0x8000, 3, 0x8001, 4, 0x8002, 5, 2, 0x8001, 4, 0x8002,
    5, 1, 0x8002, 5, 2379, 2382, 2385, 2392, 2397, 1,
    0x0010, 1, 1, 0x0004, 2, 3, 0x8000, 3, 0x8001, 4,
    0x8002, 5, 2, 0x8001, 4, 0x8002, 5, 1, 0x8002, 5,
    2404, 2407, 2414, 2419, 1, 0x0010, 1, 3, 0x0010, 2,
    0x8000, 3, 0x8001, 4, 2, 0x8000, 3, 0x8001, 4, 1,
    0x8001, 4, 1, 0x800b, 1, 0x800c, 1, 0x800d, 2442, 2471,
    2498, 2523, 2546, 2567, 2586, 2603, 2618, 2631, 2642, 2651,
    2658, 2663, 14, 0x8000, 1, 0x8001, 2, 0x8002, 3, 0x8003,
    4, 0x8004, 5, 0x8005, 6, 0x8006, 7, 0x8007, 8, 0x8008,
    9, 0x8009, 10, 0x800a, 11, 0x800b, 12, 0x800c, 13, 0x800d,
    14, 13, 0x8001, 2, 0x8002, 3, 0x8003, 4, 0x8004, 5,
    0x8005, 6, 0x8006, 7, 0x8007, 8, 0x8008, 9, 0x8009, 10,
    0x800a, 11, 0x800b, 12, 0x800c, 13, 0x800d, 14, 12, 0x8002,
    3, 0x8003, 4, 0x8004, 5, 0x8005, 6, 0x8006, 7, 0x8007,
    8, 0x8008, 9, 0x8009, 10, 0x800a, 11, 0x800b, 12, 0x800c,
    13, 0x800d, 14, 11, 0x8003, 4, 0x8004, 5, 0x8005, 6,
    0x8006, 7, 0x8007, 8, 0x8008, 9, 0x8009, 10, 0x800a, 11,
    0x800b, 12, 0x800c, 13, 0x800d, 14, 10, 0x8004, 5, 0x8005,
    6, 0x8006, 7, 0x8007, 8, 0x8008, 9, 0x8009, 10, 0x800a,
    11, 0x800b, 12, 0x800c, 13, 0x800d, 14, 9, 0x8005, 6,
    0x8006, 7, 0x8007, 8, 0x8008, 9, 0x8009, 10, 0x800a, 11,
    0x800b, 12, 0x800c, 13, 0x800d, 14, 8, 0x8006, 7, 0x8007,
    8, 0x8008, 9, 0x8009, 10, 0x800a, 11, 0x800b, 12, 0x800c,
    13, 0x800d, 14, 7, 0x8007, 8, 0x8008, 9, 0x8009, 10,
    0x800a, 11, 0x800b, 12, 0x800c, 13, 0x800d, 14, 6, 0x8008,
    9, 0x8009, 10, 0x800a, 11, 0x800b, 12, 0x800c, 13, 0x800d,
    14, 5, 0x8009, 10, 0x800a, 11, 0x800b, 12, 0x800c, 13,
    0x800d, 14, 4, 0x800a, 11, 0x800b, 12, 0x800c, 13, 0x800d,
    14, 3, 0x800b, 12, 0x800c, 13, 0x800d, 14, 2, 0x800c,
    13, 0x800d, 14, 1, 0x800d, 14, 2671, 2674, 2677, 2680,
    2683, 1, 0x000a, 1, 1, 0x0002, 2, 1, 0x8000, 3,
    1, 0x8001, 4, 1, 0x8002, 5, 2691, 2694, 2697, 2700,
    2703, 1, 0x0004, 1, 1, 0x0002, 2, 1, 0x0004, 3,
    1, 0x000a, 4, 1, 0x0010, 5, 2709, 2712, 2717, 1,
    0x8000, 1, 2, 0x8001, 2, 0x8002, 3, 1, 0x8002, 3,
    2726, 2729, 2740, 2749, 2756, 2761, 1, 0x000a, 1, 5,
    0x8000, 2, 0x8001, 3, 0x8002, 4, 0x8003, 5, 0x8004, 6,
    4, 0x8001, 3, 0x8002, 4, 0x8003, 5, 0x8004, 6, 3,
    0x8002, 4, 0x8003, 5, 0x8004, 6, 2, 0x8003, 5, 0x8004,
    6, 1, 0x8004, 6, 2767, 2770, 2775, 1, 0x000a, 1,
    2, 0x8000, 2, 0x8001, 3, 1, 0x8001, 3, 2786, 2789,
    2804, 2817, 2828, 2837, 2844, 2849, 1, 0x8000, 1, 7,
    0x8001, 2, 0x8002, 3, 0x8003, 4, 0x8004, 5, 0x8005, 6,
    0x8006, 7, 0x8007, 8, 6, 0x8002, 3, 0x8003, 4, 0x8004,
    5, 0x8005, 6, 0x8006, 7, 0x8007, 8, 5, 0x8003, 4,
    0x8004, 5, 0x8005, 6, 0x8006, 7, 0x8007, 8, 4, 0x8004,
    5, 0x8005, 6, 0x8006, 7, 0x8007, 8, 3, 0x8005, 6,
    0x8006, 7, 0x8007, 8, 2, 0x8006, 7, 0x8007, 8, 1,
    0x8007, 8, 2859, 2862, 2875, 2886, 2895, 2902, 2907, 1,
    0x8000, 1, 6, 0x8001, 2, 0x8002, 3, 0x8003, 4, 0x8004,
    5, 0x8005, 6, 0x8006, 7, 5, 0x8002, 3, 0x8003, 4,
    0x8004, 5, 0x8005, 6, 0x8006, 7, 4, 0x8003, 4, 0x8004,
    5, 0x8005, 6, 0x8006, 7, 3, 0x8004, 5, 0x8005, 6,
    0x8006, 7, 2, 0x8005, 6, 0x8006, 7, 1, 0x8006, 7,
    1, 0x800e, 1, 0x800f, 2924, 2927, 2946, 2963, 2978, 2991,
    3002, 3011, 3018, 3023, 1, 0x8001, 1, 9, 0x0004, 2,
    0x0010, 3, 0x8005, 4, 0x8006, 5, 0x8007, 6, 0x8008, 7,
    0x8009, 8, 0x800a, 9, 0x800b, 10, 8, 0x0010, 3, 0x8005,
    4, 0x8006, 5, 0x8007, 6, 0x8008, 7, 0x8009, 8, 0x800a,
    9, 0x800b, 10, 7, 0x8005, 4, 0x8006, 5, 0x8007, 6,
    0x8008, 7, 0x8009, 8, 0x800a, 9, 0x800b, 10, 6, 0x8006,
    5, 0x8007, 6, 0x8008, 7, 0x8009, 8, 0x800a, 9, 0x800b,
    10, 5, 0x8007, 6, 0x8008, 7, 0x8009, 8, 0x800a, 9,
    0x800b, 10, 4, 0x8008, 7, 0x8009, 8, 0x800a, 9, 0x800b,
    10, 3, 0x8009, 8, 0x800a, 9, 0x800b, 10, 2, 0x800a,
    9, 0x800b, 10, 1, 0x800b, 10, 3028, 3033, 2, 0x8000,
    1, 0x8001, 1, 1, 0x0004, 2, 5, 0x8000, 1, 0x8001,
    2, 0x8003, 3, 0x8004, 4, 0x8005, 5, 3, 0x8002, 1,
    0x8004, 2, 0x8005, 3, 3057, 3064, 3069, 3, 0x000a, 1,
    0x0010, 2, 0x8001, 3, 2, 0x0010, 2, 0x8001, 3, 1,
    0x8001, 3, 3081, 3088, 3091, 3106, 3119, 3130, 3139, 3146,
    3151, 3, 0x8000, 1, 0x8001, 1, 0x8002, 1, 1, 0x0004,
    2, 7, 0x8000, 3, 0x8001, 4, 0x8002, 5, 0x8003, 6,
    0x8004, 7, 0x8005, 8, 0x8006, 9, 6, 0x8001, 4, 0x8002,
    5, 0x8003, 6, 0x8004, 7, 0x8005, 8, 0x8006, 9, 5,
    0x8002, 5, 0x8003, 6, 0x8004, 7, 0x8005, 8, 0x8006, 9,
    4, 0x8003, 6, 0x8004, 7, 0x8005, 8, 0x8006, 9, 3,
    0x8004, 7, 0x8005, 8, 0x8006, 9, 2, 0x8005, 8, 0x8006,
    9, 1, 0x8006, 9, 3156, 3159, 1, 0x0006, 1, 0
};

#if !defined(OSS_SPARTAN_AWARE) || ((OSS_SPARTAN_AWARE + 0) <= 5)
typedef struct OSetTableEntry {
    void *a;
    unsigned short b;
    void *c;
    unsigned short d;
} OSetTableEntry;
#endif /* OSS_SPARTAN_AWARE  <= 5 */

static struct OSetTableEntry const _objectsettable[] = {
#if defined(OSS_SPARTAN_AWARE) && ((OSS_SPARTAN_AWARE + 0) > 12)
    {(void *)ExtensionSet, 823, NULL, 0, NULL, -1, -1}
#else
    {(void *)ExtensionSet, 823, NULL, 0}
#endif /* OSS_SPARTAN_AWARE  > 12 */
};


#ifdef OSS_SPARTAN_AWARE
#if ((OSS_SPARTAN_AWARE + 0) >= 3)
static void _oss_post_init(struct ossGlobal *world) {
    static const unsigned char _oss_typeinfo[] = {
        0x00, 0x7a, 0x33, 0xcd, 0x2b, 0x64, 0x45, 0x22, 0x85, 0x13,
        0xc2, 0x79, 0x85, 0x99, 0xc2, 0xb2, 0x37, 0x6b, 0x91, 0x08,
        0x6b, 0x12, 0x6e, 0x0d, 0xf5, 0x41, 0x64, 0x0e, 0x0a, 0xa3,
        0x1a, 0x6f, 0xae, 0xcd, 0x61, 0x9c, 0x2a, 0xe1, 0x5a, 0xd6,
        0x35, 0xf6, 0x81, 0x47, 0xc5, 0x6b, 0xf5, 0x27, 0xf7, 0x6e,
        0x2c, 0x9e, 0x96, 0x84, 0x7b, 0x27, 0xef, 0xfc, 0xbe, 0xfe,
        0x1d, 0xfd, 0x11, 0x02, 0xde, 0xa9, 0x7f, 0xea, 0x11, 0x55,
        0xee, 0x43, 0xfc, 0xc7, 0xc7, 0xaf, 0xe7, 0xbb, 0xa9, 0x8f,
        0xcf, 0xc2, 0x5c, 0xbd, 0xf9, 0xb5, 0xf2, 0x35, 0xc2, 0xd6,
        0xc4, 0x53, 0x6d, 0x99, 0xbb, 0x1d, 0xb7, 0x4e, 0x18, 0x3d,
        0xfc, 0x58, 0xfb, 0x7d, 0x3e, 0x5e, 0x06, 0x86, 0x9d, 0xd4,
        0xd8, 0xc5, 0xf7, 0x7f, 0xec, 0x49, 0x6e, 0x6b, 0x7f, 0x41,
        0xc0, 0x6b, 0x93, 0x74
    };
    ossInitRootContext(world, (unsigned char *)_oss_typeinfo);
#ifdef OSS_SPARTAN_AWARE
#if ((OSS_SPARTAN_AWARE + 0) > 12)
    ossSetExtParms(world, (void *)&extParms);
#endif /* OSS_SPARTAN_AWARE  > 12 */
#endif /* OSS_SPARTAN_AWARE */
}
#endif /* OSS_SPARTAN_AWARE >= 3 */
#endif /* OSS_SPARTAN_AWARE */

static const struct eheader _head = {_ossinit_map_protocol, -1, 15, 2869, 197, 830,
    (unsigned short *)_pduarray, (struct etype *)_etypearray,
    (struct efield *)_efieldarray, (void **)_enamearray, (Etag *)_tagarray,
    (struct ConstraintEntry *)_econstraintarray, NULL, NULL, 0, (void *)_objectsettable, 1};

#ifdef _OSSGETHEADER
void *DLL_ENTRY_FDEF ossGetHeader()
{
    return (void *)&_head;
}
#endif /* _OSSGETHEADER */

void * const map_protocol = (void *)&_head;
