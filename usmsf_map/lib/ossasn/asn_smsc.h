/*************************************************************/
/* Copyright (C) 2016 OSS Nokalva, Inc.  All rights reserved.*/
/*************************************************************/

/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC.
 * AND MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.
 * THIS FILE MAY NOT BE DISTRIBUTED. */

/* Generated for: UANGEL Corporation, Sungnam-shi, Korea - license 8634 for Solaris */
/* Abstract syntax: map_protocol */
/* Created: Fri Feb  5 14:05:16 2016 */
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

#ifndef OSS_map_protocol
#define OSS_map_protocol

#include "ossasn1.h"

#define          Remote_Operations_Generic_ROS_PDUs_Reject_PDU 1
#define          NoInvokeId_PDU 2
#define          MessageType_PDU 3
#define          DialoguePDU_PDU 4
#define          RLRQ_apdu_PDU 5
#define          RLRE_apdu_PDU 6
#define          UniDialoguePDU_PDU 7
#define          SendRoutingInfoForSM_V3_PDU 8
#define          SendRoutingInfoForSM_V2_PDU 9
#define          MO_ForwardSM_V3_PDU 10
#define          MT_ForwardSM_V3_PDU 11
#define          ForwardSM_V2_PDU 12
#define          ReportSM_DeliveryStatus_V3_PDU 13
#define          ReportSM_DeliveryStatus_V2_PDU 14
#define          AlertServiceCentre_PDU 15
#define          InformServiceCentre_V3_PDU 16
#define          InformServiceCentre_V2_PDU 17
#define          ReadyForSM_PDU 18
#define          AnyTimeModification_PDU 19
#define          RegisterSS_Arg_PDU 20
#define          SS_ForBS_Code_PDU 21
#define          InterrogateSS_Res_PDU 22
#define          USSD_Arg_PDU 23
#define          USSD_Res_PDU 24
#define          MAP_SS_DataTypes_Password_PDU 25
#define          GuidanceInfo_PDU 26
#define          SS_List_PDU 27
#define          SS_InfoList_PDU 28
#define          SS_InvocationNotificationArg_PDU 29
#define          SS_InvocationNotificationRes_PDU 30
#define          RegisterCC_EntryArg_PDU 31
#define          RegisterCC_EntryRes_PDU 32
#define          EraseCC_EntryArg_PDU 33
#define          EraseCC_EntryRes_PDU 34
#define          TeleserviceList_PDU 35
#define          AnyTimeModificationArg_PDU 36
#define          AnyTimeModificationRes_PDU 37
#define          RoutingInfoForSM_Arg_V3_PDU 38
#define          RoutingInfoForSM_Arg_V2_PDU 39
#define          RoutingInfoForSM_Res_V3_PDU 40
#define          RoutingInfoForSM_Res_V2_PDU 41
#define          MO_ForwardSM_Arg_V3_PDU 42
#define          MO_ForwardSM_Res_V3_PDU 43
#define          MT_ForwardSM_Arg_V3_PDU 44
#define          ForwardSM_Arg_V2_PDU 45
#define          MT_ForwardSM_Res_V3_PDU 46
#define          ReportSM_DeliveryStatusArg_V3_PDU 47
#define          ReportSM_DeliveryStatusRes_V3_PDU 48
#define          ReportSM_DeliveryStatusArg_V2_PDU 49
#define          ReportSM_DeliveryStatusRes_V2_PDU 50
#define          AlertServiceCentreArg_PDU 51
#define          InformServiceCentreArg_V3_PDU 52
#define          InformServiceCentreArg_V2_PDU 53
#define          ReadyForSM_Arg_PDU 54
#define          ReadyForSM_Res_PDU 55
#define          RoamingNotAllowedParam_PDU 56
#define          CallBarredParam_PDU 57
#define          CUG_RejectParam_PDU 58
#define          SS_IncompatibilityCause_PDU 59
#define          PW_RegistrationFailureCause_PDU 60
#define          SM_DeliveryFailureCause_PDU 61
#define          AbsentSubscriberSM_Param_PDU 62
#define          SystemFailureParam_PDU 63
#define          DataMissingParam_PDU 64
#define          UnexpectedDataParam_PDU 65
#define          FacilityNotSupParam_PDU 66
#define          OR_NotAllowedParam_PDU 67
#define          UnknownSubscriberParam_PDU 68
#define          NumberChangedParam_PDU 69
#define          UnidentifiedSubParam_PDU 70
#define          IllegalSubscriberParam_PDU 71
#define          IllegalEquipmentParam_PDU 72
#define          BearerServNotProvParam_PDU 73
#define          TeleservNotProvParam_PDU 74
#define          TracingBufferFullParam_PDU 75
#define          NoRoamingNbParam_PDU 76
#define          AbsentSubscriberParam_PDU 77
#define          BusySubscriberParam_PDU 78
#define          NoSubscriberReplyParam_PDU 79
#define          ForwardingViolationParam_PDU 80
#define          ForwardingFailedParam_PDU 81
#define          ATI_NotAllowedParam_PDU 82
#define          ATSI_NotAllowedParam_PDU 83
#define          ATM_NotAllowedParam_PDU 84
#define          IllegalSS_OperationParam_PDU 85
#define          SS_NotAvailableParam_PDU 86
#define          SS_SubscriptionViolationParam_PDU 87
#define          InformationNotAvailableParam_PDU 88
#define          SubBusyForMT_SMS_Param_PDU 89
#define          MessageWaitListFullParam_PDU 90
#define          ResourceLimitationParam_PDU 91
#define          NoGroupCallNbParam_PDU 92
#define          IncompatibleTerminalParam_PDU 93
#define          ShortTermDenialParam_PDU 94
#define          LongTermDenialParam_PDU 95
#define          UnauthorizedRequestingNetwork_Param_PDU 96
#define          UnauthorizedLCSClient_Param_PDU 97
#define          PositionMethodFailure_Param_PDU 98
#define          UnknownOrUnreachableLCSClient_Param_PDU 99
#define          MM_EventNotSupported_Param_PDU 100
#define          TargetCellOutsideGCA_Param_PDU 101
#define          SecureTransportErrorParam_PDU 102
#define          Ext_ExternalSignalInfo_PDU 103
#define          AccessNetworkSignalInfo_PDU 104
#define          Identity_PDU 105
#define          ASCI_CallReference_PDU 106
#define          SubscriberId_PDU 107
#define          IMEI_PDU 108
#define          HLR_List_PDU 109
#define          GlobalCellId_PDU 110
#define          NAEA_PreferredCI_PDU 111
#define          MAP_CommonDataTypes_SubscriberIdentity_PDU 112
#define          LCSClientExternalID_PDU 113
#define          LCSClientInternalID_PDU 114
#define          CellGlobalIdOrServiceAreaIdOrLAI_PDU 115
#define          MAP_CommonDataTypes_Ext_BasicServiceCode_PDU 116
#define          EMLPP_Info_PDU 117
#define          MC_SS_Info_PDU 118
#define          AgeOfLocationInformation_PDU 119
#define          KTF_ORIGSERVICETYPE_PDU 120
#define          KTF_DESTSERVICETYPE_PDU 121
#define          KTF_EXTMSISDNTYPE_PDU 122
#define          KTF_EXTORIGINALNUMTYPE_PDU 123
#define          KTF_SHOWREGIONTYPE_PDU 124
#define          KTF_UEINDICATORTYPE_PDU 125
#define          KT_ROAMPARTYTYPE_PDU 126
#define          KT_IPSMGWSVCINFO_PDU 127
#define          KT_DESTADDRFORSMDATA_PDU 128
#define          KT_RETRYINDFORSM_PDU 129
#define          KtfBarringServiceReason_PDU 130
#define          SKMIN_PDU 131
#define          SKESN_PDU 132
#define          SKSMSCapability_PDU 133
#define          SKOriginatingSFI_PDU 134
#define          SKTSMSRoamingIndicator_PDU 135
#define          SKTSMSAccessDeniedReason_PDU 136
#define          SKTSMSRoamingPMN_PDU 137
#define          MSISDN_PDU 138
#define          SecureTransportArg_PDU 139
#define          SecureTransportRes_PDU 140
#define          SystemFailure_PDU 141
#define          DataMissing_PDU 142
#define          UnexpectedDataValue_PDU 143
#define          FacilityNotSupported_PDU 144
#define          IncompatibleTerminal_PDU 145
#define          ResourceLimitation_PDU 146
#define          UnknownSubscriber_PDU 147
#define          NumberChanged_PDU 148
#define          UnknownMSC_PDU 149
#define          UnidentifiedSubscriber_PDU 150
#define          UnknownEquipment_PDU 151
#define          RoamingNotAllowed_PDU 152
#define          IllegalSubscriber_PDU 153
#define          IllegalEquipment_PDU 154
#define          BearerServiceNotProvisioned_PDU 155
#define          TeleserviceNotProvisioned_PDU 156
#define          NoHandoverNumberAvailable_PDU 157
#define          SubsequentHandoverFailure_PDU 158
#define          TargetCellOutsideGroupCallArea_PDU 159
#define          TracingBufferFull_PDU 160
#define          NoRoamingNumberAvailable_PDU 161
#define          AbsentSubscriber_PDU 162
#define          BusySubscriber_PDU 163
#define          NoSubscriberReply_PDU 164
#define          CallBarred_PDU 165
#define          ForwardingViolation_PDU 166
#define          ForwardingFailed_PDU 167
#define          CUG_Reject_PDU 168
#define          OR_NotAllowed_PDU 169
#define          ATI_NotAllowed_PDU 170
#define          ATSI_NotAllowed_PDU 171
#define          ATM_NotAllowed_PDU 172
#define          InformationNotAvailable_PDU 173
#define          IllegalSS_Operation_PDU 174
#define          SS_ErrorStatus_PDU 175
#define          SS_NotAvailable_PDU 176
#define          SS_SubscriptionViolation_PDU 177
#define          SS_Incompatibility_PDU 178
#define          UnknownAlphabet_PDU 179
#define          USSD_Busy_PDU 180
#define          PW_RegistrationFailure_PDU 181
#define          NegativePW_Check_PDU 182
#define          NumberOfPW_AttemptsViolation_PDU 183
#define          ShortTermDenial_PDU 184
#define          LongTermDenial_PDU 185
#define          SubscriberBusyForMT_SMS_PDU 186
#define          SM_DeliveryFailure_PDU 187
#define          MessageWaitingListFull_PDU 188
#define          AbsentSubscriberSM_PDU 189
#define          NoGroupCallNumberAvailable_PDU 190
#define          UnauthorizedRequestingNetwork_PDU 191
#define          UnauthorizedLCSClient_PDU 192
#define          PositionMethodFailure_PDU 193
#define          UnknownOrUnreachableLCSClient_PDU 194
#define          MM_EventNotSupported_PDU 195
#define          SecureTransportError_PDU 196
#define          CommonComponentId_PDU 197
#define          ExtensionSet_OSET 1         /* Class is MAP-EXTENSION */

typedef struct ObjectID {
    unsigned short  length;
    unsigned char   value[10];
} ObjectID;

typedef struct Any {
    unsigned long   length;
    unsigned char   *value;
} Any;

typedef struct External {
    unsigned char   bit_mask;
#       define      direct_reference_present 0x80
#       define      indirect_reference_present 0x40
    ObjectID        direct_reference;  /* optional; set in bit_mask
                                        * direct_reference_present if present */
    int             indirect_reference;  /* optional; set in bit_mask
                                          * indirect_reference_present if
                                          * present */
    char            *data_value_descriptor;  /* NULL for not present */
    struct {
        unsigned short  choice;
#           define      single_ASN1_type_chosen 1
#           define      octet_aligned_chosen 2
#           define      arbitrary_chosen 3
        union {
            OpenType        single_ASN1_type;  /* to choose, set choice to
                                                * single_ASN1_type_chosen */
            struct External_octet_aligned {
                unsigned int    length;
                unsigned char   *value;
            } octet_aligned;  /* to choose, set choice to
                               * octet_aligned_chosen */
            struct External_arbitrary {
                unsigned int    length;  /* number of significant bits */
                unsigned char   *value;
            } arbitrary;  /* to choose, set choice to arbitrary_chosen */
        } u;
    } encoding;
} External;

typedef unsigned int    Priority;

typedef struct Code {
    unsigned short  choice;
#       define      local_chosen 1
#       define      global_chosen 2
    union {
        int             local;  /* to choose, set choice to local_chosen */
        ObjectID        global;  /* to choose, set choice to global_chosen */
    } u;
} Code;

/* EXPORTS */
/* 	Code, */
/* 	ROS-OBJECT-CLASS, */
/* 	OPERATION, */
/* 	CONTRACT, */
/* 	OPERATION-PACKAGE */
/* ; */

/* exports everything */
typedef struct OPERATION {
    unsigned short  bit_mask;
#       define      ArgumentType_present 0x8000
#       define      argumentTypeOptional_present 0x4000
#       define      resultResult_present 0x2000
#       define      ResultType_present 0x1000
#       define      resultTypeOptional_present 0x0800
#       define      synchronous_present 0x0400
#       define      alwaysReturns_present 0x0200
#       define      InvokePriority_present 0x0100
#       define      ResultPriority_present 0x0080
#       define      operationCode_present 0x0040
    unsigned short  ArgumentType;  /* optional; set in bit_mask
                                    * ArgumentType_present if present */
    ossBoolean      argumentTypeOptional;  /* optional; set in bit_mask
                                            * argumentTypeOptional_present if
                                            * present */
    ossBoolean      resultResult;  /* resultResult_present not set in bit_mask
                                    * implies value is TRUE */
    unsigned short  ResultType;  /* optional; set in bit_mask ResultType_present
                                  * if present */
    ossBoolean      resultTypeOptional;  /* optional; set in bit_mask
                                          * resultTypeOptional_present if
                                          * present */
    ObjectSetEntry  *Errors;  /* NULL for not present */
    ObjectSetEntry  *Linked;  /* NULL for not present */
    ossBoolean      synchronous;  /* synchronous_present not set in bit_mask
                                   * implies value is FALSE */
    ossBoolean      alwaysReturns;  /* alwaysReturns_present not set in bit_mask
                                     * implies value is TRUE */
    unsigned short  InvokePriority;  /* optional; set in bit_mask
                                      * InvokePriority_present if present */
    unsigned short  ResultPriority;  /* optional; set in bit_mask
                                      * ResultPriority_present if present */
    Code            operationCode;  /* optional; set in bit_mask
                                     * operationCode_present if present */
} OPERATION;

typedef struct ERROR {
    unsigned char   bit_mask;
#       define      ParameterType_present 0x80
#       define      parameterTypeOptional_present 0x40
#       define      ErrorPriority_present 0x20
#       define      errorCode_present 0x10
    unsigned short  ParameterType;  /* optional; set in bit_mask
                                     * ParameterType_present if present */
    ossBoolean      parameterTypeOptional;  /* optional; set in bit_mask
                                             * parameterTypeOptional_present if
                                             * present */
    unsigned short  ErrorPriority;  /* optional; set in bit_mask
                                     * ErrorPriority_present if present */
    Code            errorCode;  /* optional; set in bit_mask errorCode_present
                                 * if present */
} ERROR;

typedef struct InvokeId {
    unsigned short  choice;
#       define      present_chosen 1
#       define      absent_chosen 2
    union {
        int             present;  /* to choose, set choice to present_chosen */
        Nulltype        absent;  /* to choose, set choice to absent_chosen */
    } u;
} InvokeId;

typedef int             Remote_Operations_Generic_ROS_PDUs_GeneralProblem;
#define                     unrecognizedPDU 0
#define                     mistypedPDU 1
#define                     badlyStructuredPDU 2

typedef int             Remote_Operations_Generic_ROS_PDUs_InvokeProblem;
#define                     duplicateInvocation 0
#define                     unrecognizedOperltion 1
#define                     mistypedArgument 2
#define                     Remote_Operations_Generic_ROS_PDUs_InvokeProblem_resourceLimitation 3
#define                     releaseInProgress 4
#define                     unrecognizedLinkedId 5
#define                     linkdeResponseUnexpected 6
#define                     Remote_Operations_Generic_ROS_PDUs_InvokeProblem_unexpectedLinkedOperation 7

typedef int             Remote_Operations_Generic_ROS_PDUs_ReturnResultProblem;
#define                     ReturnResultProblem_unrecognisedInvocation 0
#define                     resultResponseUnexpected 1
#define                     mistypedResult 2

typedef int             Remote_Operations_Generic_ROS_PDUs_ReturnErrorProblem;
#define                     ReturnErrorProblem_unrecognisedInvocation 0
#define                     errorResponseUnexpected 1
#define                     Remote_Operations_Generic_ROS_PDUs_ReturnErrorProblem_unrecognizedError 2
#define                     Remote_Operations_Generic_ROS_PDUs_ReturnErrorProblem_unexpectedError 3
#define                     unexpectedParameter 4

typedef struct Remote_Operations_Generic_ROS_PDUs_Reject {/* must conform to the above definition */
    InvokeId        invokeId;
    struct {
        unsigned short  choice;
#           define      general_chosen 1
#           define      problem_invoke_chosen 2
#           define      returnResult_chosen 3
#           define      problem_returnError_chosen 4
        union {
            Remote_Operations_Generic_ROS_PDUs_GeneralProblem general;  /* to
                                      * choose, set choice to general_chosen */
            Remote_Operations_Generic_ROS_PDUs_InvokeProblem invoke;  /* to
                                   * choose, set choice to
                                   * problem_invoke_chosen */
            Remote_Operations_Generic_ROS_PDUs_ReturnResultProblem returnResult;                                        /* to choose, set choice to
                                         * returnResult_chosen */
            Remote_Operations_Generic_ROS_PDUs_ReturnErrorProblem returnError;                                          /* to choose, set choice to
                                         * problem_returnError_chosen */
        } u;
    } problem;
} Remote_Operations_Generic_ROS_PDUs_Reject;

typedef InvokeId        NoInvokeId;

/* Transaction Portion fields */
typedef struct TCAPMessages_OperationCode {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} TCAPMessages_OperationCode;

typedef struct TCAPMessages_ErrorCode {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} TCAPMessages_ErrorCode;

/* NOTE - When the Abort Message is generated by the Transaction sublayer, a p-Abort Cause must be */
/* present.The u-abortCause may be generated by the component sublayer in which case it is an ABRT */
/* APDU, or by the TC-User in which case it could be either an ABRT APDU or data in some user-defined */
/* abstract syntax. */
typedef External        DialoguePortion;

typedef short           InvokeIdType;

/* The Components are sequences of data elements. */
typedef struct Invoke {
    unsigned char   bit_mask;
#       define      linkedID_present 0x80
#       define      Invoke_parameter_present 0x40
    InvokeIdType    invokeID;
    InvokeIdType    linkedID;  /* optional; set in bit_mask linkedID_present if
                                * present */
    TCAPMessages_OperationCode operationCode;
    Any             parameter;  /* optional; set in bit_mask
                                 * Invoke_parameter_present if present */
} Invoke;

/* ANY is filled by the single ASN.1 data type following the keyword PARAMETER or the keyword ARGUMENT */
/* in the type definition of a particular operation. */
typedef struct ReturnResult {
    unsigned char   bit_mask;
#       define      result_present 0x80
    InvokeIdType    invokeID;
    struct {
        TCAPMessages_OperationCode operationCode;
        Any             parameter;
    } result;  /* optional; set in bit_mask result_present if present */
} ReturnResult;

/* ANY is filled by the single ASN.1 data type following the keyword RESULT in the type definition */
/* of a particular operation. */
typedef struct ReturnError {
    unsigned char   bit_mask;
#       define      ReturnError_parameter_present 0x80
    InvokeIdType    invokeID;
    TCAPMessages_ErrorCode errorCode;
    Any             parameter;  /* optional; set in bit_mask
                                 * ReturnError_parameter_present if present */
} ReturnError;

/* PROBLEMS */
typedef int             TCAPMessages_GeneralProblem;
#define                     unrecognizedComponent 0
#define                     mistypedComponent 1
#define                     badlyStructuredComponent 2

typedef int             TCAPMessages_InvokeProblem;
#define                     duplicateInvokeID 0
#define                     unrecognizedOperation 1
#define                     InvokeProblem_mistypedParameter 2
#define                     TCAPMessages_InvokeProblem_resourceLimitation 3
#define                     initiatingRelease 4
#define                     unrecognizedLinkedID 5
#define                     linkedResponseUnexpected 6
#define                     TCAPMessages_InvokeProblem_unexpectedLinkedOperation 7

typedef int             TCAPMessages_ReturnResultProblem;
#define                     ReturnResultProblem_unrecognizedInvokeID 0
#define                     returnResultUnexpected 1
#define                     ReturnResultProblem_mistypedParameter 2

typedef int             TCAPMessages_ReturnErrorProblem;
#define                     ReturnErrorProblem_unrecognizedInvokeID 0
#define                     returnErrorUnexpected 1
#define                     TCAPMessages_ReturnErrorProblem_unrecognizedError 2
#define                     TCAPMessages_ReturnErrorProblem_unexpectedError 3
#define                     ReturnErrorProblem_mistypedParameter 4

/* ANY is filled by the single ASN.1 data type following the keyword PARAMETER in the type definition */
/* of a particular error. */
typedef struct TCAPMessages_Reject {
    struct {
        unsigned short  choice;
#           define      derivable_chosen 1
#           define      not_derivable_chosen 2
        union {
            InvokeIdType    derivable;  /* to choose, set choice to
                                         * derivable_chosen */
            Nulltype        not_derivable;  /* to choose, set choice to
                                             * not_derivable_chosen */
        } u;
    } invokeID;
    struct {
        unsigned short  choice;
#           define      generalProblem_chosen 1
#           define      invokeProblem_chosen 2
#           define      returnResultProblem_chosen 3
#           define      returnErrorProblem_chosen 4
        union {
            TCAPMessages_GeneralProblem generalProblem;  /* to choose, set
                                           * choice to generalProblem_chosen */
            TCAPMessages_InvokeProblem invokeProblem;  /* to choose, set choice
                                                   * to invokeProblem_chosen */
            TCAPMessages_ReturnResultProblem returnResultProblem;  /* to choose,
                                   * set choice to returnResultProblem_chosen */
            TCAPMessages_ReturnErrorProblem returnErrorProblem;  /* to choose,
                                   * set choice to returnErrorProblem_chosen */
        } u;
    } problem;
} TCAPMessages_Reject;

/* Component Portion fields */

/* COMPONENT TYPE. Recommendation X.229 defines four Application Protocol Data Units (APDUs). */
/* TCAP adds returnResultNotLast to allow for the segmentation of a result. */
typedef struct Component {
    unsigned short  choice;
#       define      Component_invoke_chosen 1
#       define      returnResultLast_chosen 2
#       define      Component_returnError_chosen 3
#       define      reject_chosen 4
#       define      returnResultNotLast_chosen 5
    union {
        Invoke          invoke;  /* to choose, set choice to
                                  * Component_invoke_chosen */
        ReturnResult    returnResultLast;  /* to choose, set choice to
                                            * returnResultLast_chosen */
        ReturnError     returnError;  /* to choose, set choice to
                                       * Component_returnError_chosen */
        TCAPMessages_Reject reject;  /* to choose, set choice to
                                      * reject_chosen */
        ReturnResult    returnResultNotLast;  /* to choose, set choice to
                                               * returnResultNotLast_chosen */
    } u;
} Component;

/* COMPONENT PORTION. The last field in the transaction portion of the TCAP message is the Component Portion. */
/* The Component Portion may be absent. */

/* bhtak 2003/12/15 set MAX as 4 */
/* ComponentPortion ::=	[APPLICATION 12]	IMPLICIT SEQUENCE SIZE (1..MAX) OF Component */
typedef struct ComponentPortion {
    unsigned short  count;
    Component       value[4];
} ComponentPortion;

typedef struct Unidirectional {
    unsigned char   bit_mask;
#       define      Unidirectional_dialoguePortion_present 0x80
    DialoguePortion dialoguePortion;  /* optional; set in bit_mask
                                       * Unidirectional_dialoguePortion_present
                                       * if present */
    ComponentPortion components;
} Unidirectional;

/* The dialogue portion carries the dialogue control PDUs as value of the external data type. */
/* The direct reference should be set to { ccitt recommendation q 773 as (1) dialogue-as (1) version (1) } */
/* if structured dialogue is used and to { ccitt recommendation q 773 as (1) unidialogue-as (2) version (1) } */
/* if unstructured dialogue is used or any user defined abstract syntax name when only user information */
/* is carried (e.g. when user information is sent in a 1988 Abort message). */
typedef struct OrigTransactionID {
    unsigned short  length;
    unsigned char   value[4];
} OrigTransactionID;

typedef struct Begin {
    unsigned char   bit_mask;
#       define      Begin_dialoguePortion_present 0x80
#       define      Begin_components_present 0x40
    OrigTransactionID otid;
    DialoguePortion dialoguePortion;  /* optional; set in bit_mask
                                       * Begin_dialoguePortion_present if
                                       * present */
    ComponentPortion components;  /* optional; set in bit_mask
                                   * Begin_components_present if present */
} Begin;

typedef struct DestTransactionID {
    unsigned short  length;
    unsigned char   value[4];
} DestTransactionID;

typedef struct End {
    unsigned char   bit_mask;
#       define      End_dialoguePortion_present 0x80
#       define      End_components_present 0x40
    DestTransactionID dtid;
    DialoguePortion dialoguePortion;  /* optional; set in bit_mask
                                       * End_dialoguePortion_present if
                                       * present */
    ComponentPortion components;  /* optional; set in bit_mask
                                   * End_components_present if present */
} End;

typedef struct Continue {
    unsigned char   bit_mask;
#       define      Continue_dialoguePortion_present 0x80
#       define      Continue_components_present 0x40
    OrigTransactionID otid;
    DestTransactionID dtid;
    DialoguePortion dialoguePortion;  /* optional; set in bit_mask
                                       * Continue_dialoguePortion_present if
                                       * present */
    ComponentPortion components;  /* optional; set in bit_mask
                                   * Continue_components_present if present */
} Continue;

typedef int             P_AbortCause;
#define                     unrecognizedMessageType 0
#define                     unrecognizedTransactionID 1
#define                     badlyFormattedTransactionPortion 2
#define                     incorrectTransactionPortion 3
#define                     P_AbortCause_resourceLimitation 4

typedef struct Abort {
    unsigned char   bit_mask;
#       define      Abort_reason_present 0x80
    DestTransactionID dtid;
    struct {
        unsigned short  choice;
#           define      p_abortCause_chosen 1
#           define      u_abortCause_chosen 2
        union {
            P_AbortCause    p_abortCause;  /* to choose, set choice to
                                            * p_abortCause_chosen */
            DialoguePortion u_abortCause;  /* to choose, set choice to
                                            * u_abortCause_chosen */
        } u;
    } reason;  /* optional; set in bit_mask Abort_reason_present if present */
} Abort;

typedef struct MessageType {
    unsigned short  choice;
#       define      unidirectional_chosen 1
#       define      begin_chosen 2
#       define      end_chosen 3
#       define      MessageType_continue_chosen 4
#       define      abort_chosen 5
    union {
        Unidirectional  unidirectional;  /* to choose, set choice to
                                          * unidirectional_chosen */
        Begin           begin;  /* to choose, set choice to begin_chosen */
        End             end;  /* to choose, set choice to end_chosen */
        Continue        MessageType_continue;  /* to choose, set choice to
                                               * MessageType_continue_chosen */
        Abort           abort;  /* to choose, set choice to abort_chosen */
    } u;
} MessageType;

typedef struct User_information {
    unsigned short  count;
    External        value[1];
} User_information;

typedef struct _bit1 {
    unsigned int    length;  /* number of significant bits */
    unsigned char   *value;
} _bit1;
#define                     version1 0x80
#define                     version1_byte 0

typedef struct AARQ_apdu {
    unsigned char   bit_mask;
#       define      AARQ_apdu_protocol_version_present 0x80
#       define      AARQ_apdu_user_information_present 0x40
    _bit1           protocol_version;  /* AARQ_apdu_protocol_version_present not
                                   * set in bit_mask implies value is
                                   * { version1 } */
    ObjectID        application_context_name;
    User_information user_information;  /* optional; set in bit_mask
                                         * AARQ_apdu_user_information_present if
                                         * present */
} AARQ_apdu;

typedef int             Associate_result;
#define                     accepted 0
#define                     reject_permanent 1

typedef struct Associate_source_diagnostic {
    unsigned short  choice;
#       define      dialogue_service_user_chosen 1
#       define      dialogue_service_provider_chosen 2
    union {
        int             dialogue_service_user;  /* to choose, set choice to
                                              * dialogue_service_user_chosen */
#           define      dialogue_service_user_null 0
#           define      dialogue_service_user_no_reason_given 1
#           define      application_context_name_not_supported 2
        int             dialogue_service_provider;  /* to choose, set choice to
                                          * dialogue_service_provider_chosen */
#           define      dialogue_service_provider_null 0
#           define      dialogue_service_provider_no_reason_given 1
#           define      no_common_dialogue_portion 2
    } u;
} Associate_source_diagnostic;

typedef struct AARE_apdu {
    unsigned char   bit_mask;
#       define      AARE_apdu_protocol_version_present 0x80
#       define      AARE_apdu_user_information_present 0x40
    _bit1           protocol_version;  /* AARE_apdu_protocol_version_present not
                                   * set in bit_mask implies value is
                                   * { version1 } */
#       define      version1_1 0x80
#       define      version1_1_byte 0
    ObjectID        application_context_name;
    Associate_result result;
    Associate_source_diagnostic result_source_diagnostic;
    User_information user_information;  /* optional; set in bit_mask
                                         * AARE_apdu_user_information_present if
                                         * present */
} AARE_apdu;

typedef int             ABRT_source;
#define                     ABRT_source_dialogue_service_user 0
#define                     ABRT_source_dialogue_service_provider 1

typedef struct ABRT_apdu {
    unsigned char   bit_mask;
#       define      ABRT_apdu_user_information_present 0x80
    ABRT_source     abort_source;
    User_information user_information;  /* optional; set in bit_mask
                                         * ABRT_apdu_user_information_present if
                                         * present */
} ABRT_apdu;

typedef struct DialoguePDU {
    unsigned short  choice;
#       define      dialogueRequest_chosen 1
#       define      dialogueResponse_chosen 2
#       define      dialogueAbort_chosen 3
    union {
        AARQ_apdu       dialogueRequest;  /* to choose, set choice to
                                           * dialogueRequest_chosen */
        AARE_apdu       dialogueResponse;  /* to choose, set choice to
                                            * dialogueResponse_chosen */
        ABRT_apdu       dialogueAbort;  /* to choose, set choice to
                                         * dialogueAbort_chosen */
    } u;
} DialoguePDU;

/* Release-request-reason is currently not used. */
/* It is included for completeness only. */
typedef int             Release_request_reason;
#define                     Release_request_reason_normal 0
#define                     urgent 1
#define                     Release_request_reason_user_defined 30

/* RLRQ PDU is currently not used. */
/* It is included for completeness only. */
typedef struct RLRQ_apdu {
    unsigned char   bit_mask;
#       define      RLRQ_apdu_reason_present 0x80
#       define      RLRQ_apdu_user_information_present 0x40
    Release_request_reason reason;  /* optional; set in bit_mask
                                     * RLRQ_apdu_reason_present if present */
    User_information user_information;  /* optional; set in bit_mask
                                         * RLRQ_apdu_user_information_present if
                                         * present */
} RLRQ_apdu;

/* Release-response-reason is currently not used. */
/* It is included for completeness only. */
typedef int             Release_response_reason;
#define                     Release_response_reason_normal 0
#define                     not_finished 1
#define                     Release_response_reason_user_defined 30

/* RLRE PDU is currently not used. */
/* It is included for completeness only */
typedef struct RLRE_apdu {
    unsigned char   bit_mask;
#       define      RLRE_apdu_reason_present 0x80
#       define      RLRE_apdu_user_information_present 0x40
    Release_response_reason reason;  /* optional; set in bit_mask
                                      * RLRE_apdu_reason_present if present */
    User_information user_information;  /* optional; set in bit_mask
                                         * RLRE_apdu_user_information_present if
                                         * present */
} RLRE_apdu;

typedef struct AUDT_apdu {
    unsigned char   bit_mask;
#       define      AUDT_apdu_protocol_version_present 0x80
#       define      AUDT_apdu_user_information_present 0x40
    _bit1           protocol_version;  /* AUDT_apdu_protocol_version_present not
                                   * set in bit_mask implies value is
                                   * { version1 } */
#       define      version1_2 0x80
#       define      version1_2_byte 0
    ObjectID        application_context_name;
    User_information user_information;  /* optional; set in bit_mask
                                         * AUDT_apdu_user_information_present if
                                         * present */
} AUDT_apdu;

typedef struct UniDialoguePDU {
    unsigned short  choice;
#       define      unidialoguePDU_chosen 1
    union {
        AUDT_apdu       unidialoguePDU;  /* to choose, set choice to
                                          * unidialoguePDU_chosen */
    } u;
} UniDialoguePDU;

/* added by cjy V2 */
typedef struct SendRoutingInfoForSM_V3 {                           /*Timer m */
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} SendRoutingInfoForSM_V3;

typedef struct SendRoutingInfoForSM_V2 {              /*Timer m */
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} SendRoutingInfoForSM_V2;

typedef struct MO_ForwardSM_V3 {                           /*Timer ml */
		/* optional */
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} MO_ForwardSM_V3;

typedef struct MT_ForwardSM_V3 {                           /*Timer ml */
		/* optional */
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} MT_ForwardSM_V3;

typedef struct ForwardSM_V2 {                              /*Timer ml */
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} ForwardSM_V2;

typedef struct ReportSM_DeliveryStatus_V3 {                        /*Timer s */
		/* optional */
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} ReportSM_DeliveryStatus_V3;

typedef struct ReportSM_DeliveryStatus_V2 {            /*Timer s */
        /* optional */
        /* storedMSISDN must be absent in version 1 */
        /* storedMSISDN must be present in version greater 1 */
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} ReportSM_DeliveryStatus_V2;

typedef struct AlertServiceCentre {                                /*Timer s */
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} AlertServiceCentre;

typedef struct InformServiceCentre_V3 {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} InformServiceCentre_V3;                            /*Timer s */

typedef struct InformServiceCentre_V2 {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} InformServiceCentre_V2;                            /*Timer s */

typedef struct ReadyForSM {                                /*Timer m */
		/* optional */
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} ReadyForSM;

typedef struct AnyTimeModification {              /*Timer m by Charge */
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} AnyTimeModification;

typedef struct SS_Code {
    unsigned short  length;
    unsigned char   value[1];
} SS_Code;

typedef struct BearerServiceCode {
    unsigned short  length;
    unsigned char   value[1];
} BearerServiceCode;

typedef struct TeleserviceCode {
    unsigned short  length;
    unsigned char   value[1];
} TeleserviceCode;

	/* Refers to Location Area Identification defined in TS GSM 03.03. */
	/* The internal structure is defined as follows: */
	/* octet 1 bits 4321	Mobile Country Code 1st digit */
	/*         bits 8765	Mobile Country Code 2nd digit */
	/* octet 2 bits 4321	Mobile Country Code 3rd digit */
	/*         bits 8765	Mobile Network Code 3rd digit */
	/*			or filler (1111) for 2 digit MNCs */
	/* octet 3 bits 4321	Mobile Network Code 1st digit */
	/*         bits 8765	Mobile Network Code 2nd digit */
	/* octets 4 and 5	Location Area Code according to TS GSM 04.08 */

/* data types for subscriber management */
typedef struct BasicServiceCode {
    unsigned short  choice;
#       define      bearerService_chosen 1
#       define      teleservice_chosen 2
    union {
        BearerServiceCode bearerService;  /* to choose, set choice to
                                           * bearerService_chosen */
        TeleserviceCode teleservice;  /* to choose, set choice to
                                       * teleservice_chosen */
    } u;
} BasicServiceCode;

	/* This type (Telephony Binary Coded Decimal String) is used to */
	/* represent several digits from 0 through 9, *, #, a, b, c, two */
	/* digits per octet, each digit encoded 0000 to 1001 (0 to 9), */
	/* 1010 (*), 1011 (#), 1100 (a), 1101 (b) or 1110 (c); 1111 used */
	/* as filler when there is an odd number of digits. */

	/* bits 8765 of octet n encoding digit 2n */
	/* bits 4321 of octet n encoding digit 2(n-1) +1 */
typedef struct AddressString {
    unsigned short  length;
    unsigned char   value[20];
} AddressString;

typedef struct MAP_CommonDataTypes_ISDN_SubaddressString {
    unsigned short  length;
    unsigned char   value[21];
} MAP_CommonDataTypes_ISDN_SubaddressString;

typedef unsigned short  NoReplyConditionTime;

typedef unsigned short  EMLPP_Priority;

typedef unsigned short  MC_Bearers;

typedef struct RegisterSS_Arg {
    unsigned char   bit_mask;
#       define      RegisterSS_Arg_basicService_present 0x80
#       define      RegisterSS_Arg_forwardedToNumber_present 0x40
#       define      RegisterSS_Arg_forwardedToSubaddress_present 0x20
#       define      RegisterSS_Arg_noReplyConditionTime_present 0x10
#       define      RegisterSS_Arg_defaultPriority_present 0x08
#       define      RegisterSS_Arg_nbrUser_present 0x04
#       define      RegisterSS_Arg_longFTN_Supported_present 0x02
    SS_Code         ss_Code;
    BasicServiceCode basicService;  /* optional; set in bit_mask
                                     * RegisterSS_Arg_basicService_present if
                                     * present */
    AddressString   forwardedToNumber;  /* optional; set in bit_mask
                                  * RegisterSS_Arg_forwardedToNumber_present if
                                  * present */
    MAP_CommonDataTypes_ISDN_SubaddressString forwardedToSubaddress;  
                                  /* optional; set in bit_mask
                              * RegisterSS_Arg_forwardedToSubaddress_present if
                              * present */
    NoReplyConditionTime noReplyConditionTime;  /* optional; set in bit_mask
                               * RegisterSS_Arg_noReplyConditionTime_present if
                               * present */
    EMLPP_Priority  defaultPriority;  /* extension #1; optional; set in bit_mask
                                       * RegisterSS_Arg_defaultPriority_present
                                       * if present */
    MC_Bearers      nbrUser;  /* extension #2; optional; set in bit_mask
                               * RegisterSS_Arg_nbrUser_present if present */
    Nulltype        longFTN_Supported;  /* extension #3; optional; set in
                                   * bit_mask
                                   * RegisterSS_Arg_longFTN_Supported_present if
                                   * present */
} RegisterSS_Arg;

typedef struct ForwardingInfo {
    unsigned char   bit_mask;
#       define      ForwardingInfo_ss_Code_present 0x80
    SS_Code         ss_Code;  /* optional; set in bit_mask
                               * ForwardingInfo_ss_Code_present if present */
    struct ForwardingFeatureList *forwardingFeatureList;
} ForwardingInfo;

	/* bit 8: notification to forwarding party */
	/*	0  no notification */
	/*	1  notification */

	/* bit 7: redirecting presentation */
	/*	0 no presentation  */
	/*	1  presentation */

	/* bit 6: notification to calling party */
	/*	0  no notification */
	/*	1  notification */

	/* bit 5: 0 (unused) */

	/* bits 43: forwarding reason */
	/*	00  ms not reachable */
	/*	01  ms busy */
	/*	10  no reply */
	/*	11  unconditional when used in a SRI Result, */
	/*	    or call deflection when used in a RCH Argument */
	/* bits 21: 00 (unused) */
typedef struct CallBarringInfo {
    unsigned char   bit_mask;
#       define      CallBarringInfo_ss_Code_present 0x80
    SS_Code         ss_Code;  /* optional; set in bit_mask
                               * CallBarringInfo_ss_Code_present if present */
    struct CallBarringFeatureList *callBarringFeatureList;
} CallBarringInfo;

typedef struct SS_Status {
    unsigned short  length;
    unsigned char   value[1];
} SS_Status;

typedef enum MAP_SS_DataTypes_CliRestrictionOption {
    MAP_SS_DataTypes_CliRestrictionOption_permanent = 0,
    MAP_SS_DataTypes_CliRestrictionOption_temporaryDefaultRestricted = 1,
    MAP_SS_DataTypes_CliRestrictionOption_temporaryDefaultAllowed = 2
} MAP_SS_DataTypes_CliRestrictionOption;

typedef enum MAP_SS_DataTypes_OverrideCategory {
    MAP_SS_DataTypes_OverrideCategory_overrideEnabled = 0,
    MAP_SS_DataTypes_OverrideCategory_overrideDisabled = 1
} MAP_SS_DataTypes_OverrideCategory;

typedef struct SS_SubscriptionOption {
    unsigned short  choice;
#       define      cliRestrictionOption_chosen 1
#       define      overrideCategory_chosen 2
    union {
        MAP_SS_DataTypes_CliRestrictionOption cliRestrictionOption;  /* to
                                   * choose, set choice to
                                   * cliRestrictionOption_chosen */
        MAP_SS_DataTypes_OverrideCategory overrideCategory;  /* to choose, set
                                         * choice to overrideCategory_chosen */
    } u;
} SS_SubscriptionOption;

typedef struct SS_Data {
    unsigned char   bit_mask;
#       define      SS_Data_ss_Code_present 0x80
#       define      SS_Data_ss_Status_present 0x40
#       define      ss_SubscriptionOption_present 0x20
#       define      basicServiceGroupList_present 0x10
#       define      SS_Data_defaultPriority_present 0x08
#       define      SS_Data_nbrUser_present 0x04
    SS_Code         ss_Code;  /* optional; set in bit_mask
                               * SS_Data_ss_Code_present if present */
    SS_Status       ss_Status;  /* optional; set in bit_mask
                                 * SS_Data_ss_Status_present if present */
    SS_SubscriptionOption ss_SubscriptionOption;  /* optional; set in bit_mask
                                             * ss_SubscriptionOption_present if
                                             * present */
    struct BasicServiceGroupList *basicServiceGroupList;  /* optional; set in
                                   * bit_mask basicServiceGroupList_present if
                                   * present */
    EMLPP_Priority  defaultPriority;  /* extension #1; optional; set in bit_mask
                                       * SS_Data_defaultPriority_present if
                                       * present */
    MC_Bearers      nbrUser;  /* extension #2; optional; set in bit_mask
                               * SS_Data_nbrUser_present if present */
} SS_Data;

typedef struct SS_Info {
    unsigned short  choice;
#       define      forwardingInfo_chosen 1
#       define      callBarringInfo_chosen 2
#       define      ss_Data_chosen 3
    union {
        ForwardingInfo  forwardingInfo;  /* to choose, set choice to
                                          * forwardingInfo_chosen */
        CallBarringInfo callBarringInfo;  /* to choose, set choice to
                                           * callBarringInfo_chosen */
        SS_Data         ss_Data;  /* to choose, set choice to ss_Data_chosen */
    } u;
} SS_Info;

typedef struct ISDN_AddressString {
    unsigned short  length;
    unsigned char   value[9];
} ISDN_AddressString;

	/* bits 8765: 0000 (unused) */
	/* bits 4321: Used to convey the "P bit","R bit","A bit" and "Q bit", */
	/*		    representing supplementary service state information */
	/*		    as defined in TS GSM 03.11 */

	/* bit 4: "Q bit" */

	/* bit 3: "P bit" */

	/* bit 2: "R bit" */

	/* bit 1: "A bit" */
typedef struct ForwardingOptions {
    unsigned short  length;
    unsigned char   value[1];
} ForwardingOptions;

typedef struct FTN_AddressString {
    unsigned short  length;
    unsigned char   value[15];
} FTN_AddressString;

typedef struct ForwardingFeature {
    unsigned char   bit_mask;
#       define      ForwardingFeature_basicService_present 0x80
#       define      ForwardingFeature_ss_Status_present 0x40
#       define      ForwardingFeature_forwardedToNumber_present 0x20
#       define      ForwardingFeature_forwardedToSubaddress_present 0x10
#       define      ForwardingFeature_forwardingOptions_present 0x08
#       define      ForwardingFeature_noReplyConditionTime_present 0x04
#       define      ForwardingFeature_longForwardedToNumber_present 0x02
    BasicServiceCode basicService;  /* optional; set in bit_mask
                                     * ForwardingFeature_basicService_present if
                                     * present */
    SS_Status       ss_Status;  /* optional; set in bit_mask
                                 * ForwardingFeature_ss_Status_present if
                                 * present */
    ISDN_AddressString forwardedToNumber;  /* optional; set in bit_mask
                               * ForwardingFeature_forwardedToNumber_present if
                               * present */
    MAP_CommonDataTypes_ISDN_SubaddressString forwardedToSubaddress;  
                                  /* optional; set in bit_mask
                           * ForwardingFeature_forwardedToSubaddress_present if
                           * present */
    ForwardingOptions forwardingOptions;  /* optional; set in bit_mask
                               * ForwardingFeature_forwardingOptions_present if
                               * present */
    NoReplyConditionTime noReplyConditionTime;  /* optional; set in bit_mask
                            * ForwardingFeature_noReplyConditionTime_present if
                            * present */
    FTN_AddressString longForwardedToNumber;  /* extension #1; optional; set in
                                   * bit_mask
                           * ForwardingFeature_longForwardedToNumber_present if
                           * present */
} ForwardingFeature;

typedef struct ForwardingFeatureList {
    struct ForwardingFeatureList *next;
    ForwardingFeature value;
} *ForwardingFeatureList;

typedef struct CallBarringFeature {
    unsigned char   bit_mask;
#       define      CallBarringFeature_basicService_present 0x80
#       define      CallBarringFeature_ss_Status_present 0x40
    BasicServiceCode basicService;  /* optional; set in bit_mask
                                     * CallBarringFeature_basicService_present
                                     * if present */
    SS_Status       ss_Status;  /* optional; set in bit_mask
                                 * CallBarringFeature_ss_Status_present if
                                 * present */
} CallBarringFeature;

typedef struct CallBarringFeatureList {
    struct CallBarringFeatureList *next;
    CallBarringFeature value;
} *CallBarringFeatureList;

typedef struct SS_ForBS_Code {
    unsigned char   bit_mask;
#       define      SS_ForBS_Code_basicService_present 0x80
#       define      SS_ForBS_Code_longFTN_Supported_present 0x40
    SS_Code         ss_Code;
    BasicServiceCode basicService;  /* optional; set in bit_mask
                                     * SS_ForBS_Code_basicService_present if
                                     * present */
    Nulltype        longFTN_Supported;  /* extension #1; optional; set in
                                   * bit_mask
                                   * SS_ForBS_Code_longFTN_Supported_present if
                                   * present */
} SS_ForBS_Code;

typedef unsigned short  MaxMC_Bearers;

typedef struct GenericServiceInfo {
    unsigned char   bit_mask;
#       define      GenericServiceInfo_cliRestrictionOption_present 0x80
#       define      maximumEntitledPriority_present 0x40
#       define      GenericServiceInfo_defaultPriority_present 0x20
#       define      ccbs_FeatureList_present 0x10
#       define      nbrSB_present 0x08
#       define      GenericServiceInfo_nbrUser_present 0x04
#       define      nbrSN_present 0x02
    SS_Status       ss_Status;
    MAP_SS_DataTypes_CliRestrictionOption cliRestrictionOption;  /* optional;
                                   * set in bit_mask
                           * GenericServiceInfo_cliRestrictionOption_present if
                           * present */
    EMLPP_Priority  maximumEntitledPriority;  /* extension #1; optional; set in
                                   * bit_mask maximumEntitledPriority_present if
                                   * present */
    EMLPP_Priority  defaultPriority;  /* extension #2; optional; set in bit_mask
                                * GenericServiceInfo_defaultPriority_present if
                                * present */
    struct CCBS_FeatureList *ccbs_FeatureList;  /* extension #3; optional; set
                                   * in bit_mask ccbs_FeatureList_present if
                                   * present */
    MaxMC_Bearers   nbrSB;  /* extension #4; optional; set in bit_mask
                             * nbrSB_present if present */
    MC_Bearers      nbrUser;  /* extension #5; optional; set in bit_mask
                               * GenericServiceInfo_nbrUser_present if
                               * present */
    MC_Bearers      nbrSN;  /* extension #6; optional; set in bit_mask
                             * nbrSN_present if present */
} GenericServiceInfo;

typedef unsigned short  CCBS_Index;

typedef struct CCBS_Feature {
    unsigned char   bit_mask;
#       define      CCBS_Feature_ccbs_Index_present 0x80
#       define      CCBS_Feature_b_subscriberNumber_present 0x40
#       define      b_subscriberSubaddress_present 0x20
#       define      basicServiceGroup_present 0x10
    CCBS_Index      ccbs_Index;  /* optional; set in bit_mask
                                  * CCBS_Feature_ccbs_Index_present if
                                  * present */
    ISDN_AddressString b_subscriberNumber;  /* optional; set in bit_mask
                                   * CCBS_Feature_b_subscriberNumber_present if
                                   * present */
    MAP_CommonDataTypes_ISDN_SubaddressString b_subscriberSubaddress;  
                                  /* optional; set in bit_mask
                                   * b_subscriberSubaddress_present if
                                   * present */
    BasicServiceCode basicServiceGroup;  /* optional; set in bit_mask
                                          * basicServiceGroup_present if
                                          * present */
} CCBS_Feature;

typedef struct CCBS_FeatureList {
    struct CCBS_FeatureList *next;
    CCBS_Feature    value;
} *CCBS_FeatureList;

typedef struct InterrogateSS_Res {
    unsigned short  choice;
#       define      ss_Status_chosen 1
#       define      basicServiceGroupList_chosen 2
#       define      forwardingFeatureList_chosen 3
#       define      genericServiceInfo_chosen 4
    union {
        SS_Status       ss_Status;  /* to choose, set choice to
                                     * ss_Status_chosen */
        struct BasicServiceGroupList *basicServiceGroupList;  /* to choose, set
                                    * choice to basicServiceGroupList_chosen */
        struct ForwardingFeatureList *forwardingFeatureList;  /* to choose, set
                                    * choice to forwardingFeatureList_chosen */
        GenericServiceInfo genericServiceInfo;  /* to choose, set choice to
                                                 * genericServiceInfo_chosen */
    } u;
} InterrogateSS_Res;

typedef struct USSD_DataCodingScheme {
    unsigned short  length;
    unsigned char   value[1];
} USSD_DataCodingScheme;

	/* The structure of the USSD-DataCodingScheme is defined by */
	/* the Cell Broadcast Data Coding Scheme as described in */
	/* TS GSM 03.38 */
typedef struct USSD_String {
    unsigned short  length;
    unsigned char   value[160];
} USSD_String;

	/* exception handling: */
	/* For AccessNetworkSignalInfo sequences containing this parameter with any */
	/* other value than the ones listed the receiver shall ignore the whole */
	/* AccessNetworkSignalInfo sequence. */
typedef struct AlertingPattern {
    unsigned short  length;
    unsigned char   value[1];
} AlertingPattern;

typedef struct USSD_Arg {
    unsigned char   bit_mask;
#       define      alertingPattern_present 0x80
#       define      USSD_Arg_msisdn_present 0x40
    USSD_DataCodingScheme ussd_DataCodingScheme;
    USSD_String     ussd_String;
    AlertingPattern alertingPattern;  /* extension #1; optional; set in bit_mask
                                       * alertingPattern_present if present */
    ISDN_AddressString msisdn;  /* extension #2; optional; set in bit_mask
                                 * USSD_Arg_msisdn_present if present */
} USSD_Arg;

typedef struct USSD_Res {
    USSD_DataCodingScheme ussd_DataCodingScheme;
    USSD_String     ussd_String;
} USSD_Res;

typedef char            MAP_SS_DataTypes_Password[5];

typedef enum GuidanceInfo {
    enterPW = 0,
    enterNewPW = 1,
    enterNewPW_Again = 2
} GuidanceInfo;

	/* How this information is really delivered to the subscriber */
	/* (display, announcement, ...) is not part of this */
	/* specification. */
typedef struct SS_List {
    struct SS_List  *next;
    SS_Code         value;
} *SS_List;

typedef struct SS_InfoList {
    struct SS_InfoList *next;
    SS_Info         value;
} *SS_InfoList;

typedef struct BasicServiceGroupList {
    struct BasicServiceGroupList *next;
    BasicServiceCode value;
} *BasicServiceGroupList;

	/* all other values of Alerting Category are reserved */
	/* Alerting categories are defined in GSM 02.07 */

/* data types for numbering and identification */
typedef struct IMSI {
    unsigned short  length;
    unsigned char   value[8];
} IMSI;

	/* Unsupported private extensions shall be discarded if received. */
typedef struct PCS_Extensions {
    char            placeholder;
} PCS_Extensions;

	/* The length of the Object Identifier shall not exceed 16 octets and the */
	/* number of components of the Object Identifier shall not exceed 16 */
/* data types */
typedef struct ExtensionContainer {
    unsigned char   bit_mask;
#       define      privateExtensionList_present 0x80
#       define      pcs_Extensions_present 0x40
    struct PrivateExtensionList *privateExtensionList;  /* optional; set in
                                   * bit_mask privateExtensionList_present if
                                   * present */
    PCS_Extensions  pcs_Extensions;  /* optional; set in bit_mask
                                      * pcs_Extensions_present if present */
} ExtensionContainer;

typedef enum CCBS_RequestState {
    request = 0,
    recall = 1,
    ccbs_RequestState_active = 2,
    completed = 3,
    suspended = 4,
    frozen = 5,
    ccbs_RequestState_deleted = 6
} CCBS_RequestState;

typedef struct SS_InvocationNotificationArg {
    unsigned char   bit_mask;
#       define      ss_EventSpecification_present 0x80
#       define      SS_InvocationNotificationArg_extensionContainer_present 0x40
#       define      SS_InvocationNotificationArg_b_subscriberNumber_present 0x20
#       define      ccbs_RequestState_present 0x10
    IMSI            imsi;
    ISDN_AddressString msisdn;
    SS_Code         ss_Event;
	/* The following SS-Code values are allowed : */
	/* ect		SS-Code ::= '00110001'B */
	/* multiPTY	SS-Code ::= '01010001'B */
	/* cd		SS-Code ::= '00100100'B */
	/* ccbs		SS-Code ::= '01000100'B */
    struct SS_EventSpecification *ss_EventSpecification;  /* optional; set in
                                   * bit_mask ss_EventSpecification_present if
                                   * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                   * SS_InvocationNotificationArg_extensionContainer_present if
                   * present */
    ISDN_AddressString b_subscriberNumber;  /* extension #1; optional; set in
                                   * bit_mask
                   * SS_InvocationNotificationArg_b_subscriberNumber_present if
                   * present */
    CCBS_RequestState ccbs_RequestState;  /* extension #2; optional; set in
                                   * bit_mask ccbs_RequestState_present if
                                   * present */
} SS_InvocationNotificationArg;

typedef struct SS_InvocationNotificationRes {
    unsigned char   bit_mask;
#       define      SS_InvocationNotificationRes_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                   * SS_InvocationNotificationRes_extensionContainer_present if
                   * present */
} SS_InvocationNotificationRes;

typedef struct SS_EventSpecification {
    struct SS_EventSpecification *next;
    AddressString   value;
} *SS_EventSpecification;

typedef struct ServiceIndicator {
    unsigned short  length;  /* number of significant bits */
    unsigned char   *value;
} ServiceIndicator;
#define                     clir_invoked 0x80
#define                     clir_invoked_byte 0
#define                     camel_invoked 0x40
#define                     camel_invoked_byte 0

	/* This NamedValue represents the theoretical maximum number of */
	/* octets which are available to carry a single data type, */
	/* without requiring segmentation to cope with the network layer */
	/* service. However, the actual maximum size available for a data */
	/* type may be lower, especially when other information elements */
	/* have to be included in the same component. */
typedef enum ProtocolId {
    gsm_0408 = 1,
    ProtocolId_gsm_0806 = 2,
    gsm_BSSMAP = 3,
	/* Value 3 is reserved and must not be used */
    ets_300102_1 = 4
} ProtocolId;

typedef struct SignalInfo {
    unsigned short  length;
    unsigned char   value[200];
} SignalInfo;

typedef struct ExternalSignalInfo {
    unsigned char   bit_mask;
#       define      ExternalSignalInfo_extensionContainer_present 0x80
    ProtocolId      protocolId;
    SignalInfo      signalInfo;
	/* Information about the internal structure is given in */
	/* subclause 7.6.9. */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                             * ExternalSignalInfo_extensionContainer_present if
                             * present */
	/* extensionContainer must not be used in version 2 */
} ExternalSignalInfo;

typedef struct CCBS_Data {
    unsigned char   bit_mask;
#       define      serviceIndicator_present 0x80
    CCBS_Feature    ccbs_Feature;
    ISDN_AddressString translatedB_Number;
    ServiceIndicator serviceIndicator;  /* optional; set in bit_mask
                                         * serviceIndicator_present if
                                         * present */
    ExternalSignalInfo callInfo;
    ExternalSignalInfo networkSignalInfo;
} CCBS_Data;

typedef struct RegisterCC_EntryArg {
    unsigned char   bit_mask;
#       define      ccbs_Data_present 0x80
    SS_Code         ss_Code;
    CCBS_Data       ccbs_Data;  /* optional; set in bit_mask ccbs_Data_present
                                 * if present */
} RegisterCC_EntryArg;

	/* exception handling: */
	/* bits 2 to 31 shall be ignored if received and not understood */
typedef struct RegisterCC_EntryRes {
    unsigned char   bit_mask;
#       define      ccbs_Feature_present 0x80
    CCBS_Feature    ccbs_Feature;  /* optional; set in bit_mask
                                    * ccbs_Feature_present if present */
} RegisterCC_EntryRes;

typedef struct EraseCC_EntryArg {
    unsigned char   bit_mask;
#       define      EraseCC_EntryArg_ccbs_Index_present 0x80
    SS_Code         ss_Code;
    CCBS_Index      ccbs_Index;  /* optional; set in bit_mask
                                  * EraseCC_EntryArg_ccbs_Index_present if
                                  * present */
} EraseCC_EntryArg;

typedef struct EraseCC_EntryRes {
    unsigned char   bit_mask;
#       define      EraseCC_EntryRes_ss_Status_present 0x80
    SS_Code         ss_Code;
    SS_Status       ss_Status;  /* optional; set in bit_mask
                                 * EraseCC_EntryRes_ss_Status_present if
                                 * present */
} EraseCC_EntryRes;

/*	LocationInfo, */
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//*- */
typedef enum MAP_SM_DataTypes_CliRestrictionOption {
    MAP_SM_DataTypes_CliRestrictionOption_permanent = 0,
    MAP_SM_DataTypes_CliRestrictionOption_temporaryDefaultRestricted = 1,
    MAP_SM_DataTypes_CliRestrictionOption_temporaryDefaultAllowed = 2
} MAP_SM_DataTypes_CliRestrictionOption;

typedef struct CallWaitingData {
    unsigned char   bit_mask;
#       define      CallWaitingData_notificationToCSE_present 0x80
    struct Ext_CwFeatureList *cwFeatureList;
    Nulltype        notificationToCSE;  /* optional; set in bit_mask
                                 * CallWaitingData_notificationToCSE_present if
                                 * present */
} CallWaitingData;

/* Only values 5-30 are used. */
/* Values in the ranges 1-4 and 31-100 are reserved for future use */
/* If received: */
/*      values 1-4 shall be mapped on to value 5 */
/*      values 31-100 shall be mapped on to value 30 */
typedef struct MAP_SM_DataTypes_Ext_SS_Status {
    unsigned short  length;
    unsigned char   value[5];
} MAP_SM_DataTypes_Ext_SS_Status;

typedef struct CallHoldData {
    unsigned char   bit_mask;
#       define      CallHoldData_notificationToCSE_present 0x80
    MAP_SM_DataTypes_Ext_SS_Status ss_Status;
    Nulltype        notificationToCSE;  /* optional; set in bit_mask
                                    * CallHoldData_notificationToCSE_present if
                                    * present */
} CallHoldData;

typedef enum MAP_SM_DataTypes_OverrideCategory {
    MAP_SM_DataTypes_OverrideCategory_overrideEnabled = 0,
    MAP_SM_DataTypes_OverrideCategory_overrideDisabled = 1
} MAP_SM_DataTypes_OverrideCategory;

typedef struct ClipData {
    unsigned char   bit_mask;
#       define      ClipData_notificationToCSE_present 0x80
    MAP_SM_DataTypes_Ext_SS_Status ss_Status;
    MAP_SM_DataTypes_OverrideCategory overrideCategory;
    Nulltype        notificationToCSE;  /* optional; set in bit_mask
                                         * ClipData_notificationToCSE_present if
                                         * present */
} ClipData;

	/* This type is used to represent the code identifying a single */
	/* teleservice, a group of teleservices, or all teleservices. The */
	/* services are defined in TS GSM 02.03. */
	/* The internal structure is defined as follows: */

	/* OCTET 1: */
	/* bits 87654321: group (bits 8765) and specific service */
	/* (bits 4321) */

	/* OCTETS 2-5: reserved for future use. If received the */
    /* Ext-TeleserviceCode shall be */
 	/* treated according to the exception handling defined for the */
	/* operation that uses this type. */

	/* Ext-TeleserviceCode includes all values defined for TeleserviceCode. */
typedef struct MAP_SM_DataTypes_Ext_BearerServiceCode {
    unsigned short  length;
    unsigned char   value[5];
} MAP_SM_DataTypes_Ext_BearerServiceCode;

/* The receiving entity shall not check the format of a number in */
/* the dialled number list */
typedef struct MAP_SM_DataTypes_Ext_TeleserviceCode {
    unsigned short  length;
    unsigned char   value[5];
} MAP_SM_DataTypes_Ext_TeleserviceCode;

typedef struct MAP_SM_DataTypes_Ext_BasicServiceCode {
    unsigned short  choice;
#       define      MAP_SM_DataTypes_Ext_BasicServiceCode_ext_BearerService_chosen 1
#       define      MAP_SM_DataTypes_Ext_BasicServiceCode_ext_Teleservice_chosen 2
    union {
        MAP_SM_DataTypes_Ext_BearerServiceCode ext_BearerService;  /* to choose,
                                   * set choice to
            * MAP_SM_DataTypes_Ext_BasicServiceCode_ext_BearerService_chosen */
        MAP_SM_DataTypes_Ext_TeleserviceCode ext_Teleservice;  /* to choose, set
                                   * choice to
              * MAP_SM_DataTypes_Ext_BasicServiceCode_ext_Teleservice_chosen */
    } u;
} MAP_SM_DataTypes_Ext_BasicServiceCode;

typedef struct Ext_CwFeature {
    MAP_SM_DataTypes_Ext_BasicServiceCode basicService;
    MAP_SM_DataTypes_Ext_SS_Status ss_Status;
} Ext_CwFeature;

typedef struct Ext_CwFeatureList {
    struct Ext_CwFeatureList *next;
    Ext_CwFeature   value;
} *Ext_CwFeatureList;

typedef struct EctData {
    unsigned char   bit_mask;
#       define      EctData_notificationToCSE_present 0x80
    MAP_SM_DataTypes_Ext_SS_Status ss_Status;
    Nulltype        notificationToCSE;  /* optional; set in bit_mask
                                         * EctData_notificationToCSE_present if
                                         * present */
} EctData;

typedef struct ClirData {
    unsigned char   bit_mask;
#       define      ClirData_cliRestrictionOption_present 0x80
#       define      ClirData_notificationToCSE_present 0x40
    MAP_SM_DataTypes_Ext_SS_Status ss_Status;
    MAP_SM_DataTypes_CliRestrictionOption cliRestrictionOption;  /* optional;
                                   * set in bit_mask
                                   * ClirData_cliRestrictionOption_present if
                                   * present */
    Nulltype        notificationToCSE;  /* optional; set in bit_mask
                                         * ClirData_notificationToCSE_present if
                                         * present */
} ClirData;

typedef struct ODB_GeneralData {
    unsigned short  length;  /* number of significant bits */
    unsigned char   *value;
} ODB_GeneralData;
#define                     allOG_CallsBarred 0x80
#define                     allOG_CallsBarred_byte 0
#define                     internationalOGCallsBarred 0x40
#define                     internationalOGCallsBarred_byte 0
#define                     internationalOGCallsNotToHPLMN_CountryBarred 0x20
#define                     internationalOGCallsNotToHPLMN_CountryBarred_byte 0
#define                     premiumRateInformationOGCallsBarred 0x10
#define                     premiumRateInformationOGCallsBarred_byte 0
#define                     premiumRateEntertainementOGCallsBarred 0x08
#define                     premiumRateEntertainementOGCallsBarred_byte 0
#define                     ss_AccessBarred 0x04
#define                     ss_AccessBarred_byte 0
#define                     interzonalOGCallsBarred 0x02
#define                     interzonalOGCallsBarred_byte 0
#define                     interzonalOGCallsNotToHPLMN_CountryBarred 0x01
#define                     interzonalOGCallsNotToHPLMN_CountryBarred_byte 0
#define                     interzonalOGCallsAndInternationalOGCallsNotToHPLMN_CountryBarred 0x80
#define                     interzonalOGCallsAndInternationalOGCallsNotToHPLMN_CountryBarred_byte 1
#define                     allECT_Barred 0x40
#define                     allECT_Barred_byte 1
#define                     chargeableECT_Barred 0x20
#define                     chargeableECT_Barred_byte 1
#define                     internationalECT_Barred 0x10
#define                     internationalECT_Barred_byte 1
#define                     interzonalECT_Barred 0x08
#define                     interzonalECT_Barred_byte 1
#define                     doublyChargeableECT_Barred 0x04
#define                     doublyChargeableECT_Barred_byte 1
#define                     multipleECT_Barred 0x02
#define                     multipleECT_Barred_byte 1
#define                     allPacketOrientedServicesBarred 0x01
#define                     allPacketOrientedServicesBarred_byte 1
#define                     roamerAccessToHPLMN_AP_Barred 0x80
#define                     roamerAccessToHPLMN_AP_Barred_byte 2
#define                     roamerAccessToVPLMN_AP_Barred 0x40
#define                     roamerAccessToVPLMN_AP_Barred_byte 2
#define                     roamingOutsidePLMNOG_CallsBarred 0x20
#define                     roamingOutsidePLMNOG_CallsBarred_byte 2
#define                     allIC_CallsBarred 0x10
#define                     allIC_CallsBarred_byte 2
#define                     roamingOutsidePLMNIC_CallsBarred 0x08
#define                     roamingOutsidePLMNIC_CallsBarred_byte 2
#define                     roamingOutsidePLMNICountryIC_CallsBarred 0x04
#define                     roamingOutsidePLMNICountryIC_CallsBarred_byte 2
#define                     roamingOutsidePLMN_Barred 0x02
#define                     roamingOutsidePLMN_Barred_byte 2
#define                     roamingOutsidePLMN_CountryBarred 0x01
#define                     roamingOutsidePLMN_CountryBarred_byte 2
#define                     registrationAllCF_Barred 0x80
#define                     registrationAllCF_Barred_byte 3
#define                     registrationCFNotToHPLMN_Barred 0x40
#define                     registrationCFNotToHPLMN_Barred_byte 3
#define                     registrationInterzonalCF_Barred 0x20
#define                     registrationInterzonalCF_Barred_byte 3
#define                     registrationInterzonalCFNotToHPLMN_Barred 0x10
#define                     registrationInterzonalCFNotToHPLMN_Barred_byte 3
#define                     registrationInternationalCF_Barred 0x08
#define                     registrationInternationalCF_Barred_byte 3

/* exception handling: reception of unknown bit assignments in the */
/* ODB-GeneralData type shall be treated like unsupported ODB-GeneralData */
/* When the ODB-GeneralData type is removed from the HLR for a given subscriber, */
/* in NoteSubscriberDataModified operation sent toward the gsmSCF */
/* all bits shall be set to ¡°O¡°. */
typedef struct ODB_HPLMN_Data {
    unsigned short  length;  /* number of significant bits */
    unsigned char   *value;
} ODB_HPLMN_Data;
#define                     plmn_SpecificBarringType1 0x80
#define                     plmn_SpecificBarringType1_byte 0
#define                     plmn_SpecificBarringType2 0x40
#define                     plmn_SpecificBarringType2_byte 0
#define                     plmn_SpecificBarringType3 0x20
#define                     plmn_SpecificBarringType3_byte 0
#define                     plmn_SpecificBarringType4 0x10
#define                     plmn_SpecificBarringType4_byte 0

typedef struct ODB_Data {
    unsigned char   bit_mask;
#       define      odb_HPLMN_Data_present 0x80
#       define      ODB_Data_extensionContainer_present 0x40
    ODB_GeneralData odb_GeneralData;
    ODB_HPLMN_Data  odb_HPLMN_Data;  /* optional; set in bit_mask
                                      * odb_HPLMN_Data_present if present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                                       * ODB_Data_extensionContainer_present if
                                       * present */
} ODB_Data;

typedef struct ODB_Info {
    unsigned char   bit_mask;
#       define      ODB_Info_notificationToCSE_present 0x80
#       define      ODB_Info_extensionContainer_present 0x40
    ODB_Data        odb_Data;
    Nulltype        notificationToCSE;  /* optional; set in bit_mask
                                         * ODB_Info_notificationToCSE_present if
                                         * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                                       * ODB_Info_extensionContainer_present if
                                       * present */
} ODB_Info;

typedef enum ModificationInstruction {
    deactivate = 0,
    activate = 1
} ModificationInstruction;

typedef struct ModificationRequestFor_ECT_Info {
    unsigned char   bit_mask;
#       define      ModificationRequestFor_ECT_Info_ss_Status_present 0x80
#       define      ModificationRequestFor_ECT_Info_modifyNotificationToCSE_present 0x40
#       define      ModificationRequestFor_ECT_Info_extensionContainer_present 0x20
    MAP_SM_DataTypes_Ext_SS_Status ss_Status;  /* optional; set in bit_mask
                         * ModificationRequestFor_ECT_Info_ss_Status_present if
                         * present */
    ModificationInstruction modifyNotificationToCSE;  /* optional; set in
                                   * bit_mask
           * ModificationRequestFor_ECT_Info_modifyNotificationToCSE_present if
           * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                * ModificationRequestFor_ECT_Info_extensionContainer_present if
                * present */
} ModificationRequestFor_ECT_Info;

typedef struct ModificationRequestFor_CLIP_Info {
    unsigned char   bit_mask;
#       define      ModificationRequestFor_CLIP_Info_ss_Status_present 0x80
#       define      overrideCategory_present 0x40
#       define      ModificationRequestFor_CLIP_Info_modifyNotificationToCSE_present 0x20
#       define      ModificationRequestFor_CLIP_Info_extensionContainer_present 0x10
    MAP_SM_DataTypes_Ext_SS_Status ss_Status;  /* optional; set in bit_mask
                        * ModificationRequestFor_CLIP_Info_ss_Status_present if
                        * present */
    MAP_SM_DataTypes_OverrideCategory overrideCategory;  /* optional; set in
                                   * bit_mask overrideCategory_present if
                                   * present */
    ModificationInstruction modifyNotificationToCSE;  /* optional; set in
                                   * bit_mask
          * ModificationRequestFor_CLIP_Info_modifyNotificationToCSE_present if
          * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
               * ModificationRequestFor_CLIP_Info_extensionContainer_present if
               * present */
} ModificationRequestFor_CLIP_Info;

typedef struct ModificationRequestFor_CH_Info {
    unsigned char   bit_mask;
#       define      ModificationRequestFor_CH_Info_ss_Status_present 0x80
#       define      ModificationRequestFor_CH_Info_modifyNotificationToCSE_present 0x40
#       define      ModificationRequestFor_CH_Info_extensionContainer_present 0x20
    MAP_SM_DataTypes_Ext_SS_Status ss_Status;  /* optional; set in bit_mask
                          * ModificationRequestFor_CH_Info_ss_Status_present if
                          * present */
    ModificationInstruction modifyNotificationToCSE;  /* optional; set in
                                   * bit_mask
            * ModificationRequestFor_CH_Info_modifyNotificationToCSE_present if
            * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                 * ModificationRequestFor_CH_Info_extensionContainer_present if
                 * present */
} ModificationRequestFor_CH_Info;

typedef struct ModificationRequestFor_CLIR_Info {
    unsigned char   bit_mask;
#       define      ModificationRequestFor_CLIR_Info_ss_Status_present 0x80
#       define      ModificationRequestFor_CLIR_Info_cliRestrictionOption_present 0x40
#       define      ModificationRequestFor_CLIR_Info_modifyNotificationToCSE_present 0x20
#       define      ModificationRequestFor_CLIR_Info_extensionContainer_present 0x10
    MAP_SM_DataTypes_Ext_SS_Status ss_Status;  /* optional; set in bit_mask
                        * ModificationRequestFor_CLIR_Info_ss_Status_present if
                        * present */
    MAP_SM_DataTypes_CliRestrictionOption cliRestrictionOption;  /* optional;
                                   * set in bit_mask
             * ModificationRequestFor_CLIR_Info_cliRestrictionOption_present if
             * present */
    ModificationInstruction modifyNotificationToCSE;  /* optional; set in
                                   * bit_mask
          * ModificationRequestFor_CLIR_Info_modifyNotificationToCSE_present if
          * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
               * ModificationRequestFor_CLIR_Info_extensionContainer_present if
               * present */
} ModificationRequestFor_CLIR_Info;

typedef struct ModificationRequestFor_CW_Info {
    unsigned char   bit_mask;
#       define      ModificationRequestFor_CW_Info_basicService_present 0x80
#       define      ModificationRequestFor_CW_Info_ss_Status_present 0x40
#       define      ModificationRequestFor_CW_Info_modifyNotificationToCSE_present 0x20
#       define      ModificationRequestFor_CW_Info_extensionContainer_present 0x10
    MAP_SM_DataTypes_Ext_BasicServiceCode basicService;  /* optional; set in
                                   * bit_mask
                       * ModificationRequestFor_CW_Info_basicService_present if
                       * present */
    MAP_SM_DataTypes_Ext_SS_Status ss_Status;  /* optional; set in bit_mask
                          * ModificationRequestFor_CW_Info_ss_Status_present if
                          * present */
    ModificationInstruction modifyNotificationToCSE;  /* optional; set in
                                   * bit_mask
            * ModificationRequestFor_CW_Info_modifyNotificationToCSE_present if
            * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                 * ModificationRequestFor_CW_Info_extensionContainer_present if
                 * present */
} ModificationRequestFor_CW_Info;

typedef struct ModificationRequestFor_CSG {
    unsigned char   bit_mask;
#       define      ModificationRequestFor_CSG_modifyNotificationToCSE_present 0x80
#       define      ModificationRequestFor_CSG_extensionContainer_present 0x40
    ModificationInstruction modifyNotificationToCSE;  /* optional; set in
                                   * bit_mask
                * ModificationRequestFor_CSG_modifyNotificationToCSE_present if
                * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                     * ModificationRequestFor_CSG_extensionContainer_present if
                     * present */
} ModificationRequestFor_CSG;

typedef struct Ext_ForwardingInfoFor_CSE {
    unsigned char   bit_mask;
#       define      Ext_ForwardingInfoFor_CSE_extensionContainer_present 0x80
    SS_Code         ss_Code;
    struct Ext_ForwFeatureList *forwardingFeatureList;
    Nulltype        notificationToCSE;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                      * Ext_ForwardingInfoFor_CSE_extensionContainer_present if
                      * present */
} Ext_ForwardingInfoFor_CSE;

typedef char            MAP_SM_DataTypes_Password[5];

	/*  notificationToCSE and csi-Active shall not be present when GPRS-CSI is sent to SGSN. */
	/*  They may only be included in ATSI/ATM ack/NSDC message. */
	/*  GPRS-CamelTDPData and  camelCapabilityHandling shall be present in */
	/*  the GPRS-CSI sequence. */
	/*  If GPRS-CSI is segmented, gprs-CamelTDPDataList and camelCapabilityHandling shall be */
	/*  present in the first segment */
typedef unsigned short  WrongPasswordAttemptsCounter;

typedef struct Ext_CallBarringInfoFor_CSE {
    unsigned char   bit_mask;
#       define      Ext_CallBarringInfoFor_CSE_extensionContainer_present 0x80
    SS_Code         ss_Code;
    struct Ext_CallBarFeatureList *callBarringFeatureList;
    MAP_SM_DataTypes_Password password;
    WrongPasswordAttemptsCounter wrongPasswordAttemptsCounter;
    Nulltype        notificationToCSE;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                     * Ext_CallBarringInfoFor_CSE_extensionContainer_present if
                     * present */
} Ext_CallBarringInfoFor_CSE;

typedef struct Ext_SS_InfoFor_CSE {
    unsigned short  choice;
#       define      forwardingInfoFor_CSE_chosen 1
#       define      callBarringInfoFor_CSE_chosen 2
    union {
        Ext_ForwardingInfoFor_CSE forwardingInfoFor_CSE;  /* to choose, set
                                    * choice to forwardingInfoFor_CSE_chosen */
        Ext_CallBarringInfoFor_CSE callBarringInfoFor_CSE;  /* to choose, set
                                   * choice to callBarringInfoFor_CSE_chosen */
    } u;
} Ext_SS_InfoFor_CSE;

	/* This type is used to represent the code identifying a single */
	/* bearer service, a group of bearer services, or all bearer */
	/* services. The services are defined in TS GSM 02.02. */
	/* The internal structure is defined as follows: */
	/**/
	/* OCTET 1: */
	/* plmn-specific bearer services: */
	/* bits 87654321: defined by the HPLMN operator */
	/**/
	/* rest of bearer services: */
	/* bit 8: 0 (unused) */
	/* bits 7654321: group (bits 7654), and rate, if applicable */
	/* (bits 321) */

	/* OCTETS 2-5: reserved for future use. If received the */
    /* Ext-TeleserviceCode shall be */
	/* treated according to the exception handling defined for the */
	/* operation that uses this type. */

	/* Ext-BearerServiceCode includes all values defined for BearerServiceCode. */
typedef struct MAP_SM_DataTypes_ISDN_SubaddressString {
    unsigned short  length;
    unsigned char   value[21];
} MAP_SM_DataTypes_ISDN_SubaddressString;

typedef struct Ext_ForwOptions {
    unsigned short  length;
    unsigned char   value[5];
} Ext_ForwOptions;

	/* OCTET 1: */

	/*  bit 8: notification to forwarding party */
	/*  0  no notification */
	/*  1  notification */

	/*  bit 7: redirecting presentation */
	/*  0 no presentation  */
	/*  1  presentation */

	/*  bit 6: notification to calling party */
	/*  0  no notification */
	/*  1  notification */

	/*  bit 5: 0 (unused) */

	/*  bits 43: forwarding reason */
	/*  00  ms not reachable */
	/*  01  ms busy */
	/*  10  no reply */
	/*  11  unconditional */

	/* bits 21: 00 (unused) */

	/* OCTETS 2-5: reserved for future use. They shall be discarded if */
	/* received and not understood. */
typedef unsigned short  Ext_NoRepCondTime;

typedef struct Ext_ForwFeature {
    unsigned char   bit_mask;
#       define      Ext_ForwFeature_basicService_present 0x80
#       define      Ext_ForwFeature_forwardedToNumber_present 0x40
#       define      Ext_ForwFeature_forwardedToSubaddress_present 0x20
#       define      Ext_ForwFeature_forwardingOptions_present 0x10
#       define      Ext_ForwFeature_noReplyConditionTime_present 0x08
#       define      Ext_ForwFeature_extensionContainer_present 0x04
#       define      Ext_ForwFeature_longForwardedToNumber_present 0x02
    MAP_SM_DataTypes_Ext_BasicServiceCode basicService;  /* optional; set in
                                   * bit_mask
                                   * Ext_ForwFeature_basicService_present if
                                   * present */
    MAP_SM_DataTypes_Ext_SS_Status ss_Status;
    ISDN_AddressString forwardedToNumber;  /* optional; set in bit_mask
                                 * Ext_ForwFeature_forwardedToNumber_present if
                                 * present */
	/* When this data type is sent from an HLR which supports CAMEL Phase 2 */
		/* to a VLR that supports CAMEL Phase 2 the VLR shall not check the */
		/* format of the number */
    MAP_SM_DataTypes_ISDN_SubaddressString forwardedToSubaddress;  /* optional;
                                   * set in bit_mask
                             * Ext_ForwFeature_forwardedToSubaddress_present if
                             * present */
    Ext_ForwOptions forwardingOptions;  /* optional; set in bit_mask
                                 * Ext_ForwFeature_forwardingOptions_present if
                                 * present */
    Ext_NoRepCondTime noReplyConditionTime;  /* optional; set in bit_mask
                              * Ext_ForwFeature_noReplyConditionTime_present if
                              * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                                * Ext_ForwFeature_extensionContainer_present if
                                * present */
    FTN_AddressString longForwardedToNumber;  /* extension #1; optional; set in
                                   * bit_mask
                             * Ext_ForwFeature_longForwardedToNumber_present if
                             * present */
} Ext_ForwFeature;

typedef struct Ext_ForwFeatureList {
    struct Ext_ForwFeatureList *next;
    Ext_ForwFeature value;
} *Ext_ForwFeatureList;

typedef struct RequestedServingNode {
    unsigned short  length;  /* number of significant bits */
    unsigned char   *value;
} RequestedServingNode;
#define                     mmeAndSgsn 0x80
#define                     mmeAndSgsn_byte 0

	/* OCTET 1: */
	/**/
	/* bits 8765: 0000 (unused) */
	/* bits 4321: Used to convey the "P bit","R bit","A bit" and "Q bit", */
	/*          representing supplementary service state information */
	/*          as defined in TS GSM 03.11 */

	/* bit 4: "Q bit" */

	/* bit 3: "P bit" */

	/* bit 2: "R bit" */

	/* bit 1: "A bit" */

	/* OCTETS 2-5: reserved for future use. They shall be discarded if */
	/* received and not understood. */

	/* data types for geographic location */
typedef struct CauseValue {
    unsigned short  length;
    unsigned char   value[1];
} CauseValue;

/* Type extracted from Cause parameter in ITU-T Recommendation Q.763. */
/* For the use of cause value refer to ITU-T Recommendation Q.850. */
typedef struct MAP_SM_DataTypes_SubscriberIdentity {
    unsigned short  choice;
#       define      MAP_SM_DataTypes_SubscriberIdentity_imsi_chosen 1
#       define      MAP_SM_DataTypes_SubscriberIdentity_msisdn_chosen 2
    union {
        IMSI            imsi;  /* to choose, set choice to
                           * MAP_SM_DataTypes_SubscriberIdentity_imsi_chosen */
        ISDN_AddressString msisdn;  /* to choose, set choice to
                         * MAP_SM_DataTypes_SubscriberIdentity_msisdn_chosen */
    } u;
} MAP_SM_DataTypes_SubscriberIdentity;

/*  This type is used to indicate a Mobility Management event. */
/*  Actions for the following M-Code values are defined in CAMEL Phase 3: */
/**/
/*  Location-update-in-same-VLR MM-Code ::= '00000000'B */
/*  Location-update-to-other-VLR    MM-Code ::= '00000001'B */
/*  IMSI-Attach MM-Code ::= '00000010'B */
/*  MS-initiated-IMSI-Detach    MM-Code ::= '00000011'B */
/*  Network-initiated-IMSI-Detach   MM-Code ::= '00000100'B */
/**/
/*  If any other MM-code is received in M-CSI, then that MM-code shall be */
/*  ignored. */
typedef unsigned short  CamelCapabilityHandling;

typedef struct GPRS_CSI {
    unsigned char   bit_mask;
#       define      gprs_CamelTDPDataList_present 0x80
#       define      GPRS_CSI_camelCapabilityHandling_present 0x40
#       define      GPRS_CSI_extensionContainer_present 0x20
#       define      GPRS_CSI_notificationToCSE_present 0x10
#       define      GPRS_CSI_csi_Active_present 0x08
    struct GPRS_CamelTDPDataList *gprs_CamelTDPDataList;  /* optional; set in
                                   * bit_mask gprs_CamelTDPDataList_present if
                                   * present */
    CamelCapabilityHandling camelCapabilityHandling;  /* optional; set in
                                   * bit_mask
                                   * GPRS_CSI_camelCapabilityHandling_present if
                                   * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                                       * GPRS_CSI_extensionContainer_present if
                                       * present */
    Nulltype        notificationToCSE;  /* optional; set in bit_mask
                                         * GPRS_CSI_notificationToCSE_present if
                                         * present */
    Nulltype        csi_Active;  /* optional; set in bit_mask
                                  * GPRS_CSI_csi_Active_present if present */
} GPRS_CSI;

typedef struct Ext_CallBarringFeature {
    unsigned char   bit_mask;
#       define      Ext_CallBarringFeature_basicService_present 0x80
#       define      Ext_CallBarringFeature_extensionContainer_present 0x40
    MAP_SM_DataTypes_Ext_BasicServiceCode basicService;  /* optional; set in
                                   * bit_mask
                                   * Ext_CallBarringFeature_basicService_present
                                   * if present */
    MAP_SM_DataTypes_Ext_SS_Status ss_Status;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                         * Ext_CallBarringFeature_extensionContainer_present if
                         * present */
} Ext_CallBarringFeature;

typedef struct Ext_CallBarFeatureList {
    struct Ext_CallBarFeatureList *next;
    Ext_CallBarringFeature value;
} *Ext_CallBarFeatureList;

typedef enum RequestedCAMEL_SubscriptionInfo {
    o_CSI = 0,
    t_CSI = 1,
    vt_CSI = 2,
    tif_CSI = 3,
    gprs_CSI = 4,
    sms_CSI = 5,
    ss_CSI = 6,
    m_CSI = 7,
    d_csi = 8
} RequestedCAMEL_SubscriptionInfo;

typedef struct ModificationRequestFor_CSI {
    unsigned char   bit_mask;
#       define      ModificationRequestFor_CSI_modifyNotificationToCSE_present 0x80
#       define      modifyCSI_State_present 0x40
#       define      ModificationRequestFor_CSI_extensionContainer_present 0x20
    RequestedCAMEL_SubscriptionInfo requestedCamel_SubscriptionInfo;
    ModificationInstruction modifyNotificationToCSE;  /* optional; set in
                                   * bit_mask
                * ModificationRequestFor_CSI_modifyNotificationToCSE_present if
                * present */
    ModificationInstruction modifyCSI_State;  /* optional; set in bit_mask
                                               * modifyCSI_State_present if
                                               * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                     * ModificationRequestFor_CSI_extensionContainer_present if
                     * present */
} ModificationRequestFor_CSI;

typedef unsigned int    ServiceKey;

typedef struct M_CSI {
    unsigned char   bit_mask;
#       define      M_CSI_extensionContainer_present 0x80
#       define      M_CSI_notificationToCSE_present 0x40
#       define      M_CSI_csi_Active_present 0x20
    struct MobilityTriggers *mobilityTriggers;
    ServiceKey      serviceKey;
    ISDN_AddressString gsmSCF_Address;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                                             * M_CSI_extensionContainer_present
                                             * if present */
    Nulltype        notificationToCSE;  /* optional; set in bit_mask
                                         * M_CSI_notificationToCSE_present if
                                         * present */
    Nulltype        csi_Active;  /* optional; set in bit_mask
                                  * M_CSI_csi_Active_present if present */
} M_CSI;

	/*  notificationToCSE and csi-Active shall not be present when M-CSI is sent to VLR. */
	/*  They may only be included in ATSI/ATM ack/NSDC message. */
typedef struct O_CSI {
    unsigned char   bit_mask;
#       define      O_CSI_extensionContainer_present 0x80
#       define      O_CSI_camelCapabilityHandling_present 0x40
#       define      O_CSI_notificationToCSE_present 0x20
#       define      O_CSI_csiActive_present 0x10
    struct O_BcsmCamelTDPDataList *o_BcsmCamelTDPDataList;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                                             * O_CSI_extensionContainer_present
                                             * if present */
    CamelCapabilityHandling camelCapabilityHandling;  /* extension #1; optional;
                                   * set in bit_mask
                                   * O_CSI_camelCapabilityHandling_present if
                                   * present */
    Nulltype        notificationToCSE;  /* extension #2; optional; set in
                                   * bit_mask O_CSI_notificationToCSE_present if
                                   * present */
    Nulltype        csiActive;  /* extension #3; optional; set in bit_mask
                                 * O_CSI_csiActive_present if present */
} O_CSI;

	/*  notificationtoCSE and csiActive shall not be present when O-CSI is sent to VLR/GMSC. */
	/*  They may only be included in ATSI/ATM ack/NSDC message. */
typedef struct D_CSI {
    unsigned char   bit_mask;
#       define      dp_AnalysedInfoCriteriaList_present 0x80
#       define      D_CSI_camelCapabilityHandling_present 0x40
#       define      D_CSI_extensionContainer_present 0x20
#       define      D_CSI_notificationToCSE_present 0x10
#       define      D_CSI_csi_Active_present 0x08
    struct DP_AnalysedInfoCriteriaList *dp_AnalysedInfoCriteriaList;  
                                  /* optional; set in bit_mask
                                   * dp_AnalysedInfoCriteriaList_present if
                                   * present */
    CamelCapabilityHandling camelCapabilityHandling;  /* optional; set in
                                   * bit_mask
                                   * D_CSI_camelCapabilityHandling_present if
                                   * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                                             * D_CSI_extensionContainer_present
                                             * if present */
    Nulltype        notificationToCSE;  /* optional; set in bit_mask
                                         * D_CSI_notificationToCSE_present if
                                         * present */
    Nulltype        csi_Active;  /* optional; set in bit_mask
                                  * D_CSI_csi_Active_present if present */
} D_CSI;

	/*  Csi-active shall not be present when D-CSI is sent to VLR/GMSC. */
	/*  It may only be included in ATSI/ATM ack/NSDC message. */
	/*  DP-AnalysedInfoCriteria and  camelCapabilityHandling shall be present in */
	/*  the D-CSI sequence. */
	/*  If D-CSI is segmented, dp-AnalysedInfoCriteriaList and camelCapabilityHandling shall be */
	/*  present in the first segment */
typedef struct T_CSI {
    unsigned char   bit_mask;
#       define      T_CSI_extensionContainer_present 0x80
#       define      T_CSI_camelCapabilityHandling_present 0x40
#       define      T_CSI_notificationToCSE_present 0x20
#       define      T_CSI_csi_Active_present 0x10
    struct T_BcsmCamelTDPDataList *t_BcsmCamelTDPDataList;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                                             * T_CSI_extensionContainer_present
                                             * if present */
    CamelCapabilityHandling camelCapabilityHandling;  /* extension #1; optional;
                                   * set in bit_mask
                                   * T_CSI_camelCapabilityHandling_present if
                                   * present */
    Nulltype        notificationToCSE;  /* extension #2; optional; set in
                                   * bit_mask T_CSI_notificationToCSE_present if
                                   * present */
    Nulltype        csi_Active;  /* extension #3; optional; set in bit_mask
                                  * T_CSI_csi_Active_present if present */
} T_CSI;

typedef struct SS_CamelData {
    unsigned char   bit_mask;
#       define      SS_CamelData_extensionContainer_present 0x80
#       define      SS_CamelData_notificationToCSE_present 0x40
#       define      SS_CamelData_csiActive_present 0x20
    struct SS_EventList *ss_EventList;
    ISDN_AddressString gsmSCF_Address;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                                   * SS_CamelData_extensionContainer_present if
                                   * present */
    Nulltype        notificationToCSE;  /* extension #1; optional; set in
                                   * bit_mask
                                   * SS_CamelData_notificationToCSE_present if
                                   * present */
    Nulltype        csiActive;  /* extension #2; optional; set in bit_mask
                                 * SS_CamelData_csiActive_present if present */
} SS_CamelData;

	/*  notificationToCSE and csi-Active shall not be present when VT-CSI/T-CSI is sent */
	/*  to VLR/GMSC. */
	/*  They may only be included in ATSI/ATM ack/NSDC message. */
typedef struct SS_CSI {
    unsigned char   bit_mask;
#       define      SS_CSI_extensionContainer_present 0x80
#       define      SS_CSI_notificationToCSE_present 0x40
#       define      SS_CSI_csi_Active_present 0x20
    SS_CamelData    ss_CamelData;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                                             * SS_CSI_extensionContainer_present
                                             * if present */
    Nulltype        notificationToCSE;  /* extension #1; optional; set in
                                   * bit_mask SS_CSI_notificationToCSE_present
                                   * if present */
    Nulltype        csi_Active;  /* extension #2; optional; set in bit_mask
                                  * SS_CSI_csi_Active_present if present */
		/*  notificationToCSE and csi-Active shall not be present when SS-CSI is sent to VLR. */
		/*  They may only be included in ATSI/ATM ack/NSDC message. */
} SS_CSI;

/* exception handling: */
/* reception of values in range 2-31 shall be treated as "continueTransaction" */
/* reception of values greater than 31 shall be treated as "releaseTransaction" */
typedef enum GPRS_TriggerDetectionPoint {
    attach = 1,
    attachChangeOfPosition = 2,
    pdp_ContextEstablishment = 11,
    pdp_ContextEstablishmentAcknowledgement = 12,
    pdp_ContextChangeOfPosition = 14
} GPRS_TriggerDetectionPoint;

typedef enum DefaultGPRS_Handling {
    DefaultGPRS_Handling_continueTransaction = 0,
    DefaultGPRS_Handling_releaseTransaction = 1
} DefaultGPRS_Handling;

/*  GPRS-CamelTDPDataList shall not contain more than one instance of */
/*  GPRS-CamelTDPData containing the same value for gprs-TriggerDetectionPoint. */
typedef struct GPRS_CamelTDPData {
    unsigned char   bit_mask;
#       define      GPRS_CamelTDPData_extensionContainer_present 0x80
    GPRS_TriggerDetectionPoint gprs_TriggerDetectionPoint;
    ServiceKey      serviceKey;
    ISDN_AddressString gsmSCF_Address;
    DefaultGPRS_Handling defaultSessionHandling;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                              * GPRS_CamelTDPData_extensionContainer_present if
                              * present */
} GPRS_CamelTDPData;

typedef struct GPRS_CamelTDPDataList {
    struct GPRS_CamelTDPDataList *next;
    GPRS_CamelTDPData value;
} *GPRS_CamelTDPDataList;

typedef struct MM_Code {
    unsigned short  length;
    unsigned char   value[1];
} MM_Code;

/* exception handling: */
/* For GPRS-CamelTDPData sequences containing this parameter with any */
/* other value than the ones listed the receiver shall ignore the whole */
typedef struct MobilityTriggers {
    struct MobilityTriggers *next;
    MM_Code         value;
} *MobilityTriggers;

/* value 1 = CAMEL phase 1, */
/* value 2 = CAMEL phase 2, */
/* value 3 = CAMEL Phase 3: */
/* reception of values greater than 3 shall be treated as CAMEL phase 3. */
typedef struct SMS_CSI {
    unsigned char   bit_mask;
#       define      sms_CAMEL_TDP_DataList_present 0x80
#       define      SMS_CSI_camelCapabilityHandling_present 0x40
#       define      SMS_CSI_extensionContainer_present 0x20
#       define      SMS_CSI_notificationToCSE_present 0x10
#       define      SMS_CSI_csi_Active_present 0x08
    struct SMS_CAMEL_TDP_DataList *sms_CAMEL_TDP_DataList;  /* optional; set in
                                   * bit_mask sms_CAMEL_TDP_DataList_present if
                                   * present */
    CamelCapabilityHandling camelCapabilityHandling;  /* optional; set in
                                   * bit_mask
                                   * SMS_CSI_camelCapabilityHandling_present if
                                   * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                                        * SMS_CSI_extensionContainer_present if
                                        * present */
    Nulltype        notificationToCSE;  /* optional; set in bit_mask
                                         * SMS_CSI_notificationToCSE_present if
                                         * present */
    Nulltype        csi_Active;  /* optional; set in bit_mask
                                  * SMS_CSI_csi_Active_present if present */
} SMS_CSI;

	/*  notificationToCSE and csi-Active shall not be present when SMS-CSI is sent to VLR/SGSN. */
	/*  They may only be included in ATSI/ATM ack/NSDC message. */
	/*  SMS-CAMEL-TDP-Data and  camelCapabilityHandling shall be present in */
	/*  the SMS-CSI sequence. */
	/*  If SMS-CSI is segmented, sms-CAMEL-TDP-DataList and camelCapabilityHandling shall be */
	/*  present in the first segment */
typedef struct CAMEL_SubscriptionInfo {
    unsigned short  bit_mask;
#       define      o_CSI_present 0x8000
#       define      o_BcsmCamelTDP_CriteriaList_present 0x4000
#       define      d_CSI_present 0x2000
#       define      t_CSI_present 0x1000
#       define      t_BCSM_CAMEL_TDP_CriteriaList_present 0x0800
#       define      vt_CSI_present 0x0400
#       define      vt_BCSM_CAMEL_TDP_CriteriaList_present 0x0200
#       define      tif_CSI_present 0x0100
#       define      tif_CSI_NotificationToCSE_present 0x0080
#       define      gprs_CSI_present 0x0040
#       define      sms_CSI_present 0x0020
#       define      ss_CSI_present 0x0010
#       define      m_CSI_present 0x0008
#       define      CAMEL_SubscriptionInfo_extensionContainer_present 0x0004
    O_CSI           o_CSI;  /* optional; set in bit_mask o_CSI_present if
                             * present */
    struct O_BcsmCamelTDPCriteriaList *o_BcsmCamelTDP_CriteriaList;  
                                  /* optional; set in bit_mask
                                   * o_BcsmCamelTDP_CriteriaList_present if
                                   * present */
    D_CSI           d_CSI;  /* optional; set in bit_mask d_CSI_present if
                             * present */
    T_CSI           t_CSI;  /* optional; set in bit_mask t_CSI_present if
                             * present */
    struct T_BCSM_CAMEL_TDP_CriteriaList *t_BCSM_CAMEL_TDP_CriteriaList;  
                                        /* optional; set in bit_mask
                                         * t_BCSM_CAMEL_TDP_CriteriaList_present
                                         * if present */
    T_CSI           vt_CSI;  /* optional; set in bit_mask vt_CSI_present if
                              * present */
    struct T_BCSM_CAMEL_TDP_CriteriaList *vt_BCSM_CAMEL_TDP_CriteriaList;  
                                        /* optional; set in bit_mask
                                    * vt_BCSM_CAMEL_TDP_CriteriaList_present if
                                    * present */
    Nulltype        tif_CSI;  /* optional; set in bit_mask tif_CSI_present if
                               * present */
    Nulltype        tif_CSI_NotificationToCSE;  /* optional; set in bit_mask
                                         * tif_CSI_NotificationToCSE_present if
                                         * present */
    GPRS_CSI        gprs_CSI;  /* optional; set in bit_mask gprs_CSI_present if
                                * present */
    SMS_CSI         sms_CSI;  /* optional; set in bit_mask sms_CSI_present if
                               * present */
    SS_CSI          ss_CSI;  /* optional; set in bit_mask ss_CSI_present if
                              * present */
    M_CSI           m_CSI;  /* optional; set in bit_mask m_CSI_present if
                             * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                         * CAMEL_SubscriptionInfo_extensionContainer_present if
                         * present */
} CAMEL_SubscriptionInfo;

/* exception handling: */
/* reception of values in range 2-31 shall be treated as "continueCall" */
/* reception of values greater than 31 shall be treated as "releaseCall" */
typedef enum O_BcsmTriggerDetectionPoint {
    collectedInfo = 2,
    routeSelectFailure = 4
} O_BcsmTriggerDetectionPoint;

typedef enum DefaultCallHandling {
    continueCall = 0,
    releaseCall = 1
} DefaultCallHandling;

typedef struct O_BcsmCamelTDPData {
    unsigned char   bit_mask;
#       define      O_BcsmCamelTDPData_extensionContainer_present 0x80
    O_BcsmTriggerDetectionPoint o_BcsmTriggerDetectionPoint;
    ServiceKey      serviceKey;
    ISDN_AddressString gsmSCF_Address;
    DefaultCallHandling defaultCallHandling;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                             * O_BcsmCamelTDPData_extensionContainer_present if
                             * present */
} O_BcsmCamelTDPData;

typedef struct O_BcsmCamelTDPDataList {
    struct O_BcsmCamelTDPDataList *next;
    O_BcsmCamelTDPData value;
} *O_BcsmCamelTDPDataList;

typedef enum T_BcsmTriggerDetectionPoint {
    termAttemptAuthorized = 12,
    tBusy = 13,
    tNoAnswer = 14
} T_BcsmTriggerDetectionPoint;

/*- T-BcsmCamelTDPDataList shall not contain more than one instance of */
/*- T-BcsmCamelTDPData containing the same value for t-BcsmTriggerDetectionPoint. */
/*- For CAMEL Phase 2, this means that only one instance of T-BcsmCamelTDPData is allowed */
/*- with t-BcsmTriggerDetectionPoint being equal to DP12. */
/*- For CAMEL Phase 3, more TDP's are allowed. */
typedef struct T_BcsmCamelTDPData {
    unsigned char   bit_mask;
#       define      T_BcsmCamelTDPData_extensionContainer_present 0x80
    T_BcsmTriggerDetectionPoint t_BcsmTriggerDetectionPoint;
    ServiceKey      serviceKey;
    ISDN_AddressString gsmSCF_Address;
    DefaultCallHandling defaultCallHandling;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                             * T_BcsmCamelTDPData_extensionContainer_present if
                             * present */
} T_BcsmCamelTDPData;

/*  notificationToCSE and csiActive shall not be present when SS-CSI is sent to VLR. */
/*  They may only be included in ATSI/ATM Ack message. */
typedef struct T_BcsmCamelTDPDataList {
    struct T_BcsmCamelTDPDataList *next;
    T_BcsmCamelTDPData value;
} *T_BcsmCamelTDPDataList;

typedef enum SMS_TriggerDetectionPoint {
    sms_CollectedInfo = 1
} SMS_TriggerDetectionPoint;

/*  exception handling: */
/*  For SMS-CAMEL-TDP-Data sequences containing this parameter with any */
/*  other value than the ones listed the receiver shall ignore the whole */
/*  SMS-CAMEL-TDP-Data sequence. */
typedef enum DefaultSMS_Handling {
    DefaultSMS_Handling_continueTransaction = 0,
    DefaultSMS_Handling_releaseTransaction = 1
} DefaultSMS_Handling;

/*  SMS-CAMEL-TDP-DataList shall not contain more than one instance of */
/*  SMS-CAMEL-TDP-Data containing the same value for sms-TriggerDetectionPoint. */
typedef struct SMS_CAMEL_TDP_Data {
    unsigned char   bit_mask;
#       define      SMS_CAMEL_TDP_Data_extensionContainer_present 0x80
    SMS_TriggerDetectionPoint sms_TriggerDetectionPoint;
    ServiceKey      serviceKey;
    ISDN_AddressString gsmSCF_Address;
    DefaultSMS_Handling defaultSMS_Handling;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                             * SMS_CAMEL_TDP_Data_extensionContainer_present if
                             * present */
} SMS_CAMEL_TDP_Data;

/* exception handling: */
/* For T-BcsmCamelTDPData sequences containing this parameter with any other */
/* value than the ones listed above, the receiver shall ignore the whole */
/* T-BcsmCamelTDPData sequence. */
typedef struct SMS_CAMEL_TDP_DataList {
    struct SMS_CAMEL_TDP_DataList *next;
    SMS_CAMEL_TDP_Data value;
} *SMS_CAMEL_TDP_DataList;

typedef struct DP_AnalysedInfoCriterium {
    unsigned char   bit_mask;
#       define      DP_AnalysedInfoCriterium_extensionContainer_present 0x80
    ISDN_AddressString dialledNumber;
    ServiceKey      serviceKey;
    ISDN_AddressString gsmSCF_Address;
    DefaultCallHandling defaultCallHandling;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                       * DP_AnalysedInfoCriterium_extensionContainer_present if
                       * present */
} DP_AnalysedInfoCriterium;

/*  exception handling: */
/*  reception of values in range 2-31 shall be treated as "continueTransaction" */
/*  reception of values greater than 31 shall be treated as "releaseTransaction" */
typedef struct DP_AnalysedInfoCriteriaList {
    struct DP_AnalysedInfoCriteriaList *next;
    DP_AnalysedInfoCriterium value;
} *DP_AnalysedInfoCriteriaList;

typedef enum MatchType {
    inhibiting = 0,
    enabling = 1
} MatchType;

typedef struct DestinationNumberCriteria {
    unsigned char   bit_mask;
#       define      destinationNumberList_present 0x80
#       define      destinationNumberLengthList_present 0x40
    MatchType       matchType;
    struct DestinationNumberList *destinationNumberList;  /* optional; set in
                                   * bit_mask destinationNumberList_present if
                                   * present */
    struct DestinationNumberLengthList *destinationNumberLengthList;  
                                  /* optional; set in bit_mask
                                   * destinationNumberLengthList_present if
                                   * present */
	/* one or both of destinationNumberList and destinationNumberLengthList */
	/* shall be present */
} DestinationNumberCriteria;

typedef struct DestinationNumberList {
    struct DestinationNumberList *next;
    ISDN_AddressString value;
} *DestinationNumberList;

typedef struct DestinationNumberLengthList {
    struct DestinationNumberLengthList *next;
    unsigned short  value;
} *DestinationNumberLengthList;

typedef enum CallTypeCriteria {
    forwarded = 0,
    notForwarded = 1
} CallTypeCriteria;

typedef struct O_CauseValueCriteria {
    struct O_CauseValueCriteria *next;
    CauseValue      value;
} *O_CauseValueCriteria;

typedef struct T_CauseValueCriteria {
    struct T_CauseValueCriteria *next;
    CauseValue      value;
} *T_CauseValueCriteria;

typedef struct BasicServiceCriteria {
    struct BasicServiceCriteria *next;
    MAP_SM_DataTypes_Ext_BasicServiceCode value;
} *BasicServiceCriteria;

typedef struct TeleserviceList {
    struct TeleserviceList *next;
    MAP_SM_DataTypes_Ext_TeleserviceCode value;
} *TeleserviceList;

typedef struct O_BcsmCamelTDP_Criteria {
    unsigned char   bit_mask;
#       define      destinationNumberCriteria_present 0x80
#       define      O_BcsmCamelTDP_Criteria_basicServiceCriteria_present 0x40
#       define      callTypeCriteria_present 0x20
#       define      o_CauseValueCriteria_present 0x10
#       define      O_BcsmCamelTDP_Criteria_extensionContainer_present 0x08
    O_BcsmTriggerDetectionPoint o_BcsmTriggerDetectionPoint;
    DestinationNumberCriteria destinationNumberCriteria;  /* optional; set in
                                   * bit_mask destinationNumberCriteria_present
                                   * if present */
    struct BasicServiceCriteria *basicServiceCriteria;  /* optional; set in
                                   * bit_mask
                      * O_BcsmCamelTDP_Criteria_basicServiceCriteria_present if
                      * present */
    CallTypeCriteria callTypeCriteria;  /* optional; set in bit_mask
                                         * callTypeCriteria_present if
                                         * present */
    struct O_CauseValueCriteria *o_CauseValueCriteria;  /* extension #1;
                                   * optional; set in bit_mask
                                   * o_CauseValueCriteria_present if present */
    ExtensionContainer extensionContainer;  /* extension #2; optional; set in
                                   * bit_mask
                        * O_BcsmCamelTDP_Criteria_extensionContainer_present if
                        * present */
} O_BcsmCamelTDP_Criteria;

/* exception handling: */
/* For O-BcsmCamelTDPData sequences containing this parameter with any */
/* other value than the ones listed the receiver shall ignore the whole */
/* O-BcsmCamelTDPDatasequence. */
/* For O-BcsmCamelTDP-Criteria sequences containing this parameter with any */
/* other value than the ones listed the receiver shall ignore the whole */
/* O-BcsmCamelTDP-Criteria sequence. */
typedef struct O_BcsmCamelTDPCriteriaList {
    struct O_BcsmCamelTDPCriteriaList *next;
    O_BcsmCamelTDP_Criteria value;
} *O_BcsmCamelTDPCriteriaList;

typedef struct T_BCSM_CAMEL_TDP_Criteria {
    unsigned char   bit_mask;
#       define      T_BCSM_CAMEL_TDP_Criteria_basicServiceCriteria_present 0x80
#       define      t_CauseValueCriteria_present 0x40
    T_BcsmTriggerDetectionPoint t_BCSM_TriggerDetectionPoint;
    struct BasicServiceCriteria *basicServiceCriteria;  /* optional; set in
                                   * bit_mask
                    * T_BCSM_CAMEL_TDP_Criteria_basicServiceCriteria_present if
                    * present */
    struct T_CauseValueCriteria *t_CauseValueCriteria;  /* optional; set in
                                   * bit_mask t_CauseValueCriteria_present if
                                   * present */
} T_BCSM_CAMEL_TDP_Criteria;

typedef struct T_BCSM_CAMEL_TDP_CriteriaList {
    struct T_BCSM_CAMEL_TDP_CriteriaList *next;
    T_BCSM_CAMEL_TDP_Criteria value;
} *T_BCSM_CAMEL_TDP_CriteriaList;

typedef struct SS_EventList {
    struct SS_EventList *next;
    SS_Code         value;
} *SS_EventList;

/* Actions for the following SS-Code values are defined in CAMEL Phase 3: */
/* ect      SS-Code ::= '00110001'B */
/* multiPTY SS-Code ::= '01010001'B */
/* cd       SS-Code ::= '00100100'B */
/* ccbs     SS-Code ::= '01000100'B */
/* all other SS codes shall be ignored */
typedef struct ModificationRequestFor_CF_Info {
    unsigned char   bit_mask;
#       define      ModificationRequestFor_CF_Info_basicService_present 0x80
#       define      ModificationRequestFor_CF_Info_ss_Status_present 0x40
#       define      ModificationRequestFor_CF_Info_forwardedToNumber_present 0x20
#       define      ModificationRequestFor_CF_Info_forwardedToSubaddress_present 0x10
#       define      ModificationRequestFor_CF_Info_noReplyConditionTime_present 0x08
#       define      ModificationRequestFor_CF_Info_modifyNotificationToCSE_present 0x04
#       define      ModificationRequestFor_CF_Info_extensionContainer_present 0x02
    SS_Code         ss_Code;
    MAP_SM_DataTypes_Ext_BasicServiceCode basicService;  /* optional; set in
                                   * bit_mask
                       * ModificationRequestFor_CF_Info_basicService_present if
                       * present */
    MAP_SM_DataTypes_Ext_SS_Status ss_Status;  /* optional; set in bit_mask
                          * ModificationRequestFor_CF_Info_ss_Status_present if
                          * present */
    AddressString   forwardedToNumber;  /* optional; set in bit_mask
                  * ModificationRequestFor_CF_Info_forwardedToNumber_present if
                  * present */
    MAP_SM_DataTypes_ISDN_SubaddressString forwardedToSubaddress;  /* optional;
                                   * set in bit_mask
              * ModificationRequestFor_CF_Info_forwardedToSubaddress_present if
              * present */
    Ext_NoRepCondTime noReplyConditionTime;  /* optional; set in bit_mask
               * ModificationRequestFor_CF_Info_noReplyConditionTime_present if
               * present */
    ModificationInstruction modifyNotificationToCSE;  /* optional; set in
                                   * bit_mask
            * ModificationRequestFor_CF_Info_modifyNotificationToCSE_present if
            * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                 * ModificationRequestFor_CF_Info_extensionContainer_present if
                 * present */
} ModificationRequestFor_CF_Info;

typedef struct ModificationRequestFor_CB_Info {
    unsigned char   bit_mask;
#       define      ModificationRequestFor_CB_Info_basicService_present 0x80
#       define      ModificationRequestFor_CB_Info_ss_Status_present 0x40
#       define      password_present 0x20
#       define      wrongPasswordAttemptsCounter_present 0x10
#       define      ModificationRequestFor_CB_Info_modifyNotificationToCSE_present 0x08
#       define      ModificationRequestFor_CB_Info_extensionContainer_present 0x04
    SS_Code         ss_Code;
    MAP_SM_DataTypes_Ext_BasicServiceCode basicService;  /* optional; set in
                                   * bit_mask
                       * ModificationRequestFor_CB_Info_basicService_present if
                       * present */
    MAP_SM_DataTypes_Ext_SS_Status ss_Status;  /* optional; set in bit_mask
                          * ModificationRequestFor_CB_Info_ss_Status_present if
                          * present */
    MAP_SM_DataTypes_Password password;  /* optional; set in bit_mask
                                          * password_present if present */
    WrongPasswordAttemptsCounter wrongPasswordAttemptsCounter;  /* optional; set
                                   * in bit_mask
                                   * wrongPasswordAttemptsCounter_present if
                                   * present */
    ModificationInstruction modifyNotificationToCSE;  /* optional; set in
                                   * bit_mask
            * ModificationRequestFor_CB_Info_modifyNotificationToCSE_present if
            * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                 * ModificationRequestFor_CB_Info_extensionContainer_present if
                 * present */
} ModificationRequestFor_CB_Info;

	/* exception handling: reception of unknown bit assignments in the */
	/* ODB-HPLMN-Data type shall be treated like unsupported ODB-HPLMN-Data */
	/* When the ODB-HPLMN-Data type is removed from the HLR for a given subscriber, */
	/* in NoteSubscriberDataModified operation sent toward the gsmSCF */
	/* all bits shall be set to ¡°O¡°. */
typedef struct ModificationRequestFor_IP_SM_GW_Data {
    unsigned char   bit_mask;
#       define      modifyRegistrationStatus_present 0x80
#       define      ModificationRequestFor_IP_SM_GW_Data_extensionContainer_present 0x40
    ModificationInstruction modifyRegistrationStatus;  /* optional; set in
                                   * bit_mask modifyRegistrationStatus_present
                                   * if present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
           * ModificationRequestFor_IP_SM_GW_Data_extensionContainer_present if
           * present */
} ModificationRequestFor_IP_SM_GW_Data;

typedef struct ModificationRequestFor_ODB_data {
    unsigned char   bit_mask;
#       define      odb_data_present 0x80
#       define      ModificationRequestFor_ODB_data_modifyNotificationToCSE_present 0x40
#       define      ModificationRequestFor_ODB_data_extensionContainer_present 0x20
    ODB_Data        odb_data;  /* optional; set in bit_mask odb_data_present if
                                * present */
    ModificationInstruction modifyNotificationToCSE;  /* optional; set in
                                   * bit_mask
           * ModificationRequestFor_ODB_data_modifyNotificationToCSE_present if
           * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                * ModificationRequestFor_ODB_data_extensionContainer_present if
                * present */
} ModificationRequestFor_ODB_data;

typedef struct AnyTimeModificationArg {
    unsigned short  bit_mask;
#       define      modificationRequestFor_CF_Info_present 0x8000
#       define      modificationRequestFor_CB_Info_present 0x4000
#       define      modificationRequestFor_CSI_present 0x2000
#       define      AnyTimeModificationArg_extensionContainer_present 0x1000
#       define      AnyTimeModificationArg_longFTN_Supported_present 0x0800
#       define      modificationRequestFor_ODB_data_present 0x0400
#       define      modificationRequestFor_IP_SM_GW_Data_present 0x0200
#       define      activationRequestForUE_reachability_present 0x0100
#       define      modificationRequestFor_CSG_present 0x0080
#       define      modificationRequestFor_CW_Data_present 0x0040
#       define      modificationRequestFor_CLIP_Data_present 0x0020
#       define      modificationRequestFor_CLIR_Data_present 0x0010
#       define      modificationRequestFor_HOLD_Data_present 0x0008
#       define      modificationRequestFor_ECT_Data_present 0x0004
    MAP_SM_DataTypes_SubscriberIdentity subscriberIdentity;
    ISDN_AddressString gsmSCF_Address;
    ModificationRequestFor_CF_Info modificationRequestFor_CF_Info;  
                                  /* optional; set in bit_mask
                                   * modificationRequestFor_CF_Info_present if
                                   * present */
    ModificationRequestFor_CB_Info modificationRequestFor_CB_Info;  
                                  /* optional; set in bit_mask
                                   * modificationRequestFor_CB_Info_present if
                                   * present */
    ModificationRequestFor_CSI modificationRequestFor_CSI;  /* optional; set in
                                   * bit_mask modificationRequestFor_CSI_present
                                   * if present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                         * AnyTimeModificationArg_extensionContainer_present if
                         * present */
    Nulltype        longFTN_Supported;  /* optional; set in bit_mask
                          * AnyTimeModificationArg_longFTN_Supported_present if
                          * present */
    ModificationRequestFor_ODB_data modificationRequestFor_ODB_data;  
                                  /* extension #1; optional; set in bit_mask
                                   * modificationRequestFor_ODB_data_present if
                                   * present */
    ModificationRequestFor_IP_SM_GW_Data modificationRequestFor_IP_SM_GW_Data;                                          /* extension #2; optional; set in
                                   * bit_mask
                              * modificationRequestFor_IP_SM_GW_Data_present if
                              * present */
    RequestedServingNode activationRequestForUE_reachability;  /* extension #3;
                                   * optional; set in bit_mask
                                   * activationRequestForUE_reachability_present
                                   * if present */
    ModificationRequestFor_CSG modificationRequestFor_CSG;  /* extension #4;
                                   * optional; set in bit_mask
                                   * modificationRequestFor_CSG_present if
                                   * present */
    ModificationRequestFor_CW_Info modificationRequestFor_CW_Data;  
                                  /* extension #5; optional; set in bit_mask
                                   * modificationRequestFor_CW_Data_present if
                                   * present */
    ModificationRequestFor_CLIP_Info modificationRequestFor_CLIP_Data;  
                                  /* extension #6; optional; set in bit_mask
                                   * modificationRequestFor_CLIP_Data_present if
                                   * present */
    ModificationRequestFor_CLIR_Info modificationRequestFor_CLIR_Data;  
                                  /* extension #7; optional; set in bit_mask
                                   * modificationRequestFor_CLIR_Data_present if
                                   * present */
    ModificationRequestFor_CH_Info modificationRequestFor_HOLD_Data;  
                                  /* extension #8; optional; set in bit_mask
                                   * modificationRequestFor_HOLD_Data_present if
                                   * present */
    ModificationRequestFor_ECT_Info modificationRequestFor_ECT_Data;  
                                  /* extension #9; optional; set in bit_mask
                                   * modificationRequestFor_ECT_Data_present if
                                   * present */
} AnyTimeModificationArg;

typedef struct AnyTimeModificationRes {
    unsigned short  bit_mask;
#       define      ss_InfoFor_CSE_present 0x8000
#       define      camel_SubscriptionInfo_present 0x4000
#       define      AnyTimeModificationRes_extensionContainer_present 0x2000
#       define      odb_Info_present 0x1000
#       define      cw_Data_present 0x0800
#       define      ch_Data_present 0x0400
#       define      clip_Data_present 0x0200
#       define      clir_Data_present 0x0100
#       define      ect_data_present 0x0080
    Ext_SS_InfoFor_CSE ss_InfoFor_CSE;  /* optional; set in bit_mask
                                         * ss_InfoFor_CSE_present if present */
    CAMEL_SubscriptionInfo camel_SubscriptionInfo;  /* optional; set in bit_mask
                                            * camel_SubscriptionInfo_present if
                                            * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                         * AnyTimeModificationRes_extensionContainer_present if
                         * present */
    ODB_Info        odb_Info;  /* extension #1; optional; set in bit_mask
                                * odb_Info_present if present */
    CallWaitingData cw_Data;  /* extension #2; optional; set in bit_mask
                               * cw_Data_present if present */
    CallHoldData    ch_Data;  /* extension #3; optional; set in bit_mask
                               * ch_Data_present if present */
    ClipData        clip_Data;  /* extension #4; optional; set in bit_mask
                                 * clip_Data_present if present */
    ClirData        clir_Data;  /* extension #5; optional; set in bit_mask
                                 * clir_Data_present if present */
    EctData         ect_data;  /* extension #6; optional; set in bit_mask
                                * ect_data_present if present */
} AnyTimeModificationRes;

typedef unsigned short  SM_RP_MTI;

	/* 0 SMS Deliver */
	/* 1 SMS Status Report */
	/* other values are reserved for future use and shall be discarded if */
	/* received */
typedef struct SM_RP_SMEA {
    unsigned short  length;
    unsigned char   value[12];
} SM_RP_SMEA;

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//*- */
typedef struct RoutingInfoForSM_Arg_V3 {
    unsigned char   bit_mask;
#       define      RoutingInfoForSM_Arg_V3_extensionContainer_present 0x80
#       define      RoutingInfoForSM_Arg_V3_gprsSupportIndicator_present 0x40
#       define      sm_RP_MTI_present 0x20
#       define      sm_RP_SMEA_present 0x10
    ISDN_AddressString msisdn;
    ossBoolean      sm_RP_PRI;
    AddressString   serviceCentreAddress;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                        * RoutingInfoForSM_Arg_V3_extensionContainer_present if
                        * present */
    Nulltype        gprsSupportIndicator;  /* extension #1; optional; set in
                                   * bit_mask
                      * RoutingInfoForSM_Arg_V3_gprsSupportIndicator_present if
                      * present */
	/* gprsSupportIndicator is set only if the SMS-GMSC supports */
	/* receiving of two numbers from the HLR */
    SM_RP_MTI       sm_RP_MTI;  /* extension #2; optional; set in bit_mask
                                 * sm_RP_MTI_present if present */
    SM_RP_SMEA      sm_RP_SMEA;  /* extension #3; optional; set in bit_mask
                                  * sm_RP_SMEA_present if present */
} RoutingInfoForSM_Arg_V3;

typedef struct RoutingInfoForSM_Arg_V2 {
    unsigned char   bit_mask;
#       define      teleservice_present 0x80
    ISDN_AddressString msisdn;
    ossBoolean      sm_RP_PRI;
    AddressString   serviceCentreAddress;
    TeleserviceCode teleservice;  /* optional; set in bit_mask
                                   * teleservice_present if present */
    /* teleservice must be absent in version greater 1 */
} RoutingInfoForSM_Arg_V2;

typedef struct LMSI {
    unsigned short  length;
    unsigned char   value[4];
} LMSI;

typedef struct Additional_Number {
    unsigned short  choice;
#       define      Additional_Number_msc_Number_chosen 1
#       define      sgsn_Number_chosen 2
    union {
        ISDN_AddressString msc_Number;  /* to choose, set choice to
                                       * Additional_Number_msc_Number_chosen */
        ISDN_AddressString sgsn_Number;  /* to choose, set choice to
                                          * sgsn_Number_chosen */
    } u;
} Additional_Number;

typedef struct LocationInfoWithLMSI_V3 {
    unsigned char   bit_mask;
#       define      LocationInfoWithLMSI_V3_lmsi_present 0x80
#       define      LocationInfoWithLMSI_V3_extensionContainer_present 0x40
#       define      gprsNodeIndicator_present 0x20
#       define      additional_Number_present 0x10
    ISDN_AddressString networkNode_Number;
    LMSI            lmsi;  /* optional; set in bit_mask
                            * LocationInfoWithLMSI_V3_lmsi_present if present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                        * LocationInfoWithLMSI_V3_extensionContainer_present if
                        * present */
    Nulltype        gprsNodeIndicator;  /* extension #1; optional; set in
                                   * bit_mask gprsNodeIndicator_present if
                                   * present */
	/* gprsNodeIndicator is set only if the SGSN number is sent as the */
	/* Network Node Number */
    Additional_Number additional_Number;  /* extension #2; optional; set in
                                   * bit_mask additional_Number_present if
                                   * present */
	/* NetworkNode-number can be either msc-number or sgsn-number */
} LocationInfoWithLMSI_V3;

	/* this parameter contains an address field which is encoded */
	/* as defined in GSM 03.40. An address field contains 3 elements : */
	/* 		address-length */
	/* 		type-of-address */
	/* 		address-value */
typedef struct RoutingInfoForSM_Res_V3 {
    unsigned char   bit_mask;
#       define      RoutingInfoForSM_Res_V3_extensionContainer_present 0x80
    IMSI            imsi;
    LocationInfoWithLMSI_V3 locationInfoWithLMSI_V3;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                        * RoutingInfoForSM_Res_V3_extensionContainer_present if
                        * present */
} RoutingInfoForSM_Res_V3;

typedef struct LocationInfo {
    unsigned short  choice;
#       define      LocationInfo_roamingNumber_chosen 1
#       define      LocationInfo_msc_Number_chosen 2
    union {
        ISDN_AddressString roamingNumber;  /* to choose, set choice to
                                         * LocationInfo_roamingNumber_chosen */
        ISDN_AddressString msc_Number;  /* to choose, set choice to
                                         * LocationInfo_msc_Number_chosen */
    } u;
} LocationInfo;

typedef struct LocationInfoWithLMSI_V2 {
    unsigned char   bit_mask;
#       define      LocationInfoWithLMSI_V2_lmsi_present 0x80
    LocationInfo    locationInfo;
    LMSI            lmsi;  /* optional; set in bit_mask
                            * LocationInfoWithLMSI_V2_lmsi_present if present */
} LocationInfoWithLMSI_V2;

typedef struct RoutingInfoForSM_Res_V2 {
    unsigned char   bit_mask;
#       define      mwd_Set_present 0x80
    IMSI            imsi;
    LocationInfoWithLMSI_V2 locationInfoWithLMSI_V2;
    ossBoolean      mwd_Set;  /* optional; set in bit_mask mwd_Set_present if
                               * present */
    /* mwd-Set must be absent in vertion greater 1 */
} RoutingInfoForSM_Res_V2;

typedef struct SM_RP_DA {
    unsigned short  choice;
#       define      SM_RP_DA_imsi_chosen 1
#       define      lmsi_chosen 2
#       define      SM_RP_DA_roamingNumber_chosen 3
#       define      serviceCentreAddressDA_chosen 4
#       define      noSM_RP_DA_chosen 5
    union {
        IMSI            imsi;  /* to choose, set choice to
                                * SM_RP_DA_imsi_chosen */
        LMSI            lmsi;  /* to choose, set choice to lmsi_chosen */
        ISDN_AddressString roamingNumber;  /* to choose, set choice to
                                            * SM_RP_DA_roamingNumber_chosen */
        AddressString   serviceCentreAddressDA;  /* to choose, set choice to
                                             * serviceCentreAddressDA_chosen */
        Nulltype        noSM_RP_DA;  /* to choose, set choice to
                                      * noSM_RP_DA_chosen */
    } u;
} SM_RP_DA;

typedef struct SM_RP_OA {
    unsigned short  choice;
#       define      SM_RP_OA_msisdn_chosen 1
#       define      serviceCentreAddressOA_chosen 2
#       define      noSM_RP_OA_chosen 3
    union {
        ISDN_AddressString msisdn;  /* to choose, set choice to
                                     * SM_RP_OA_msisdn_chosen */
        AddressString   serviceCentreAddressOA;  /* to choose, set choice to
                                             * serviceCentreAddressOA_chosen */
        Nulltype        noSM_RP_OA;  /* to choose, set choice to
                                      * noSM_RP_OA_chosen */
    } u;
} SM_RP_OA;

	/* additional-number can be either msc-number or sgsn-number */
	/* if received networkNode-number is msc-number then the 	*/
	/* additional number is sgsn-number */
	/* if received networkNode-number is sgsn-number then the */
	/* additional number is msc-number */
typedef struct MO_ForwardSM_Arg_V3 {
    unsigned char   bit_mask;
#       define      MO_ForwardSM_Arg_V3_extensionContainer_present 0x80
#       define      MO_ForwardSM_Arg_V3_imsi_present 0x40
    SM_RP_DA        sm_RP_DA;
    SM_RP_OA        sm_RP_OA;
    SignalInfo      sm_RP_UI;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                            * MO_ForwardSM_Arg_V3_extensionContainer_present if
                            * present */
    IMSI            imsi;  /* extension #1; optional; set in bit_mask
                            * MO_ForwardSM_Arg_V3_imsi_present if present */
} MO_ForwardSM_Arg_V3;

typedef struct MO_ForwardSM_Res_V3 {
    unsigned char   bit_mask;
#       define      MO_ForwardSM_Res_V3_sm_RP_UI_present 0x80
#       define      MO_ForwardSM_Res_V3_extensionContainer_present 0x40
    SignalInfo      sm_RP_UI;  /* optional; set in bit_mask
                                * MO_ForwardSM_Res_V3_sm_RP_UI_present if
                                * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                            * MO_ForwardSM_Res_V3_extensionContainer_present if
                            * present */
} MO_ForwardSM_Res_V3;

typedef struct MT_ForwardSM_Arg_V3 {
    unsigned char   bit_mask;
#       define      MT_ForwardSM_Arg_V3_moreMessagesToSend_present 0x80
#       define      MT_ForwardSM_Arg_V3_extensionContainer_present 0x40
    SM_RP_DA        sm_RP_DA;
    SM_RP_OA        sm_RP_OA;
    SignalInfo      sm_RP_UI;
    Nulltype        moreMessagesToSend;  /* optional; set in bit_mask
                            * MT_ForwardSM_Arg_V3_moreMessagesToSend_present if
                            * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                            * MT_ForwardSM_Arg_V3_extensionContainer_present if
                            * present */
} MT_ForwardSM_Arg_V3;

typedef struct ForwardSM_Arg_V2 {
    unsigned char   bit_mask;
#       define      ForwardSM_Arg_V2_moreMessagesToSend_present 0x80
    SM_RP_DA        sm_RP_DA;
    SM_RP_OA        sm_RP_OA;
    SignalInfo      sm_RP_UI;
    Nulltype        moreMessagesToSend;  /* optional; set in bit_mask
                               * ForwardSM_Arg_V2_moreMessagesToSend_present if
                               * present */
	/* moreMessageToSend must be absent in version 1 */
} ForwardSM_Arg_V2;

typedef struct MT_ForwardSM_Res_V3 {
    unsigned char   bit_mask;
#       define      MT_ForwardSM_Res_V3_sm_RP_UI_present 0x80
#       define      MT_ForwardSM_Res_V3_extensionContainer_present 0x40
    SignalInfo      sm_RP_UI;  /* optional; set in bit_mask
                                * MT_ForwardSM_Res_V3_sm_RP_UI_present if
                                * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                            * MT_ForwardSM_Res_V3_extensionContainer_present if
                            * present */
} MT_ForwardSM_Res_V3;

typedef enum SM_DeliveryOutcome {
    SM_DeliveryOutcome_memoryCapacityExceeded = 0,
    SM_DeliveryOutcome_absentSubscriber = 1,
    successfulTransfer = 2
} SM_DeliveryOutcome;

	/* if received, additionalAbsentSubscriberDiagnosticSM */
	/* is for GPRS and absentSubscriberDiagnosticSM is */
	/* for non-GPRS */
typedef unsigned short  AbsentSubscriberDiagnosticSM;

typedef struct ReportSM_DeliveryStatusArg_V3 {
    unsigned short  bit_mask;
#       define      ReportSM_DeliveryStatusArg_V3_absentSubscriberDiagnosticSM_present 0x8000
#       define      ReportSM_DeliveryStatusArg_V3_extensionContainer_present 0x4000
#       define      ReportSM_DeliveryStatusArg_V3_gprsSupportIndicator_present 0x2000
#       define      deliveryOutcomeIndicator_present 0x1000
#       define      additionalSM_DeliveryOutcome_present 0x0800
#       define      ReportSM_DeliveryStatusArg_V3_additionalAbsentSubscriberDiagnosticSM_present 0x0400
#       define      ip_sm_gw_Indicator_present 0x0200
#       define      ip_sm_gw_sm_deliveryOutcome_present 0x0100
#       define      ip_sm_gw_absentSubscriberDiagnosticSM_present 0x0080
#       define      ReportSM_DeliveryStatusArg_V3_imsi_present 0x0040
    ISDN_AddressString msisdn;
    AddressString   serviceCentreAddress;
    SM_DeliveryOutcome sm_DeliveryOutcome;
    AbsentSubscriberDiagnosticSM absentSubscriberDiagnosticSM;  /* optional; set
                                   * in bit_mask
        * ReportSM_DeliveryStatusArg_V3_absentSubscriberDiagnosticSM_present if
        * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                  * ReportSM_DeliveryStatusArg_V3_extensionContainer_present if
                  * present */
    Nulltype        gprsSupportIndicator;  /* extension #1; optional; set in
                                   * bit_mask
                * ReportSM_DeliveryStatusArg_V3_gprsSupportIndicator_present if
                * present */
	/* gprsSupportIndicator is set only if the SMS-GMSC supports */
	/* handling of two delivery outcomes */
    Nulltype        deliveryOutcomeIndicator;  /* extension #2; optional; set in
                                   * bit_mask deliveryOutcomeIndicator_present
                                   * if present */
	/* DeliveryOutcomeIndicator is set when the SM-DeliveryOutcome */
	/* is for GPRS */
    SM_DeliveryOutcome additionalSM_DeliveryOutcome;  /* extension #3; optional;
                                   * set in bit_mask
                                   * additionalSM_DeliveryOutcome_present if
                                   * present */
	/* If received, additionalSM-DeliveryOutcome is for GPRS */
	/* If DeliveryOutcomeIndicator is set, then AdditionalSM-DeliveryOutcome shall be absent */
    AbsentSubscriberDiagnosticSM additionalAbsentSubscriberDiagnosticSM;  
                                        /* extension #4; optional; set in
                                   * bit_mask
    * ReportSM_DeliveryStatusArg_V3_additionalAbsentSubscriberDiagnosticSM_present if
    * present */
	/* If received additionalAbsentSubscriberDiagnosticSM is for GPRS */
	/* If DeliveryOutcomeIndicator is set, then AdditionalAbsentSubscriberDiagnosticSM */
	/* shall be absent */
    Nulltype        ip_sm_gw_Indicator;  /* extension #5; optional; set in
                                   * bit_mask ip_sm_gw_Indicator_present if
                                   * present */
	/* the ip-sm-gw indicator indicates by its presence that sm-deliveryOutcome */
	/* is for delivery via IMS */
	/* If present, deliveryOutcomeIndicator shall be absent. */
    SM_DeliveryOutcome ip_sm_gw_sm_deliveryOutcome;  /* extension #6; optional;
                                   * set in bit_mask
                                   * ip_sm_gw_sm_deliveryOutcome_present if
                                   * present */
	/* If received ip-sm-gw-sm-deliveryOutcome is for delivery via IMS */
	/* If ip-sm-gw-Indicator is set, then ip-sm-gw-sm-deliveryOutcome shall be absent */
    AbsentSubscriberDiagnosticSM ip_sm_gw_absentSubscriberDiagnosticSM;  
                                  /* extension #7; optional; set in bit_mask
                             * ip_sm_gw_absentSubscriberDiagnosticSM_present if
                             * present */
	/* If received ip-sm-gw-sm-absentSubscriberDiagnosticSM is for delivery via IMS */
	/* If ip-sm-gw-Indicator is set, then ip-sm-gw-sm-absentSubscriberDiagnosticSM */
	/* shall be absent */
    IMSI            imsi;  /* extension #8; optional; set in bit_mask
                            * ReportSM_DeliveryStatusArg_V3_imsi_present if
                            * present */
} ReportSM_DeliveryStatusArg_V3;

typedef struct ReportSM_DeliveryStatusRes_V3 {
    unsigned char   bit_mask;
#       define      ReportSM_DeliveryStatusRes_V3_storedMSISDN_present 0x80
#       define      ReportSM_DeliveryStatusRes_V3_extensionContainer_present 0x40
    ISDN_AddressString storedMSISDN;  /* optional; set in bit_mask
                        * ReportSM_DeliveryStatusRes_V3_storedMSISDN_present if
                        * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                  * ReportSM_DeliveryStatusRes_V3_extensionContainer_present if
                  * present */
} ReportSM_DeliveryStatusRes_V3;

typedef struct ReportSM_DeliveryStatusArg_V2 {
    unsigned char   bit_mask;
#       define      sm_DeliveryOutcome_present 0x80
    ISDN_AddressString msisdn;
    AddressString   serviceCentreAddress;
    SM_DeliveryOutcome sm_DeliveryOutcome;  /* optional; set in bit_mask
                                             * sm_DeliveryOutcome_present if
                                             * present */
    /* sm-DeliveryOutcome must be absent in version 1 */
    /* sm-DeliveryOutcome must be present in version greater 1 */
} ReportSM_DeliveryStatusArg_V2;

typedef struct ReportSM_DeliveryStatusRes_V2 {
    unsigned char   bit_mask;
#       define      ReportSM_DeliveryStatusRes_V2_msisdn_present 0x80
#       define      ReportSM_DeliveryStatusRes_V2_extensionContainer_present 0x40
    ISDN_AddressString msisdn;  /* optional; set in bit_mask
                                 * ReportSM_DeliveryStatusRes_V2_msisdn_present
                                 * if present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                  * ReportSM_DeliveryStatusRes_V2_extensionContainer_present if
                  * present */
} ReportSM_DeliveryStatusRes_V2;

typedef struct AlertServiceCentreArg {
    ISDN_AddressString msisdn;
    AddressString   serviceCentreAddress;
} AlertServiceCentreArg;

typedef unsigned short  MW_Status;
#define                     sc_AddressNotIncluded 0x8000
#define                     mnrf_Set 0x4000
#define                     mcef_Set 0x2000
#define                     mnrg_Set 0x1000
#define                     mnri_Set 0x0800

typedef struct InformServiceCentreArg_V3 {
    unsigned char   bit_mask;
#       define      InformServiceCentreArg_V3_storedMSISDN_present 0x80
#       define      InformServiceCentreArg_V3_mw_Status_present 0x40
#       define      InformServiceCentreArg_V3_extensionContainer_present 0x20
    ISDN_AddressString storedMSISDN;  /* optional; set in bit_mask
                            * InformServiceCentreArg_V3_storedMSISDN_present if
                            * present */
    MW_Status       mw_Status;  /* optional; set in bit_mask
                                 * InformServiceCentreArg_V3_mw_Status_present
                                 * if present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                      * InformServiceCentreArg_V3_extensionContainer_present if
                      * present */
} InformServiceCentreArg_V3;

typedef struct InformServiceCentreArg_V2 {
    unsigned char   bit_mask;
#       define      InformServiceCentreArg_V2_storedMSISDN_present 0x80
#       define      InformServiceCentreArg_V2_mw_Status_present 0x40
    ISDN_AddressString storedMSISDN;  /* optional; set in bit_mask
                            * InformServiceCentreArg_V2_storedMSISDN_present if
                            * present */
    MW_Status       mw_Status;  /* optional; set in bit_mask
                                 * InformServiceCentreArg_V2_mw_Status_present
                                 * if present */
} InformServiceCentreArg_V2;

typedef enum AlertReason {
    ms_Present = 0,
    memoryAvailable = 1
} AlertReason;

	/* exception handling: */
	/* bits 4 to 15 shall be ignored if received and not understood */
typedef struct ReadyForSM_Arg {
    unsigned char   bit_mask;
#       define      alertReasonIndicator_present 0x80
#       define      ReadyForSM_Arg_extensionContainer_present 0x40
    IMSI            imsi;
    AlertReason     alertReason;
    Nulltype        alertReasonIndicator;  /* optional; set in bit_mask
                                            * alertReasonIndicator_present if
                                            * present */
	/* alertReasonIndicator is set only when the alertReason */
	/* sent to HLR is for GPRS */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                                 * ReadyForSM_Arg_extensionContainer_present if
                                 * present */
} ReadyForSM_Arg;

typedef struct ReadyForSM_Res {
    unsigned char   bit_mask;
#       define      ReadyForSM_Res_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                                 * ReadyForSM_Res_extensionContainer_present if
                                 * present */
} ReadyForSM_Res;

typedef enum RoamingNotAllowedCause {
    plmnRoamingNotAllowed = 0,
    operatorDeterminedBarring = 3
} RoamingNotAllowedCause;

typedef struct RoamingNotAllowedParam {
    unsigned char   bit_mask;
#       define      RoamingNotAllowedParam_extensionContainer_present 0x80
    RoamingNotAllowedCause roamingNotAllowedCause;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                         * RoamingNotAllowedParam_extensionContainer_present if
                         * present */
} RoamingNotAllowedParam;

typedef enum CallBarringCause {
    barringServiceActive = 0,
    operatorBarring = 1
} CallBarringCause;

typedef struct ExtensibleCallBarredParam {
    unsigned char   bit_mask;
#       define      callBarringCause_present 0x80
#       define      ExtensibleCallBarredParam_extensionContainer_present 0x40
#       define      unauthorisedMessageOriginator_present 0x20
    CallBarringCause callBarringCause;  /* optional; set in bit_mask
                                         * callBarringCause_present if
                                         * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                      * ExtensibleCallBarredParam_extensionContainer_present if
                      * present */
    Nulltype        unauthorisedMessageOriginator;  /* extension #1; optional;
                                   * set in bit_mask
                                   * unauthorisedMessageOriginator_present if
                                   * present */
} ExtensibleCallBarredParam;

typedef struct CallBarredParam {
    unsigned short  choice;
#       define      callBarringCause_chosen 1
#       define      extensibleCallBarredParam_chosen 2
    union {
        CallBarringCause callBarringCause;  /* to choose, set choice to
                                             * callBarringCause_chosen */
	/* call BarringCause must not be used in version 3 */
        ExtensibleCallBarredParam extensibleCallBarredParam;  /* to choose, set
                                   * choice to
                                   * extensibleCallBarredParam_chosen */
	/* extensibleCallBarredParam must not be used in version <3 */
    } u;
} CallBarredParam;

typedef enum CUG_RejectCause {
    incomingCallsBarredWithinCUG = 0,
    subscriberNotMemberOfCUG = 1,
    requestedBasicServiceViolatesCUG_Constraints = 5,
    calledPartySS_InteractionViolation = 7
} CUG_RejectCause;

typedef struct CUG_RejectParam {
    unsigned char   bit_mask;
#       define      cug_RejectCause_present 0x80
#       define      CUG_RejectParam_extensionContainer_present 0x40
    CUG_RejectCause cug_RejectCause;  /* optional; set in bit_mask
                                       * cug_RejectCause_present if present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                                * CUG_RejectParam_extensionContainer_present if
                                * present */
} CUG_RejectParam;

typedef struct SS_IncompatibilityCause {
    unsigned char   bit_mask;
#       define      SS_IncompatibilityCause_ss_Code_present 0x80
#       define      SS_IncompatibilityCause_basicService_present 0x40
#       define      SS_IncompatibilityCause_ss_Status_present 0x20
    SS_Code         ss_Code;  /* optional; set in bit_mask
                               * SS_IncompatibilityCause_ss_Code_present if
                               * present */
    BasicServiceCode basicService;  /* optional; set in bit_mask
                              * SS_IncompatibilityCause_basicService_present if
                              * present */
    SS_Status       ss_Status;  /* optional; set in bit_mask
                                 * SS_IncompatibilityCause_ss_Status_present if
                                 * present */
} SS_IncompatibilityCause;

typedef enum PW_RegistrationFailureCause {
    undetermined = 0,
    invalidFormat = 1,
    newPasswordsMismatch = 2
} PW_RegistrationFailureCause;

typedef enum SM_EnumeratedDeliveryFailureCause {
    SM_EnumeratedDeliveryFailureCause_memoryCapacityExceeded = 0,
    equipmentProtocolError = 1,
    equipmentNotSM_Equipped = 2,
    unknownServiceCentre = 3,
    sc_Congestion = 4,
    invalidSME_Address = 5,
    subscriberNotSC_Subscriber = 6
} SM_EnumeratedDeliveryFailureCause;

typedef struct SM_DeliveryFailureCause {
    unsigned char   bit_mask;
#       define      diagnosticInfo_present 0x80
#       define      SM_DeliveryFailureCause_extensionContainer_present 0x40
    SM_EnumeratedDeliveryFailureCause sm_EnumeratedDeliveryFailureCause;
    SignalInfo      diagnosticInfo;  /* optional; set in bit_mask
                                      * diagnosticInfo_present if present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                        * SM_DeliveryFailureCause_extensionContainer_present if
                        * present */
} SM_DeliveryFailureCause;

typedef struct AbsentSubscriberSM_Param {
    unsigned char   bit_mask;
#       define      AbsentSubscriberSM_Param_absentSubscriberDiagnosticSM_present 0x80
#       define      AbsentSubscriberSM_Param_extensionContainer_present 0x40
#       define      AbsentSubscriberSM_Param_additionalAbsentSubscriberDiagnosticSM_present 0x20
    AbsentSubscriberDiagnosticSM absentSubscriberDiagnosticSM;  /* optional; set
                                   * in bit_mask
             * AbsentSubscriberSM_Param_absentSubscriberDiagnosticSM_present if
             * present */
	/* AbsentSubscriberDiagnosticSM can be either for non-GPRS */
	/* or for GPRS */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                       * AbsentSubscriberSM_Param_extensionContainer_present if
                       * present */
    AbsentSubscriberDiagnosticSM additionalAbsentSubscriberDiagnosticSM;  
                                        /* extension #1; optional; set in
                                   * bit_mask
   * AbsentSubscriberSM_Param_additionalAbsentSubscriberDiagnosticSM_present if
   * present */
} AbsentSubscriberSM_Param;

	/* Refers to Cell Global Identification defined in TS GSM 03.03. */
	/* The internal structure is defined as follows: */
	/* octet 1 bits 4321	Mobile Country Code 1st digit */
	/*         bits 8765	Mobile Country Code 2nd digit */
	/* octet 2 bits 4321	Mobile Country Code 3rd digit */
	/*         bits 8765	Mobile Network Code 3rd digit */
	/*			or filler (1111) for 2 digit MNCs */
	/* octet 3 bits 4321	Mobile Network Code 1st digit */
	/*         bits 8765	Mobile Network Code 2nd digit */
	/* octets 4 and 5	Location Area Code according to TS GSM 04.08 */
	/* octets 6 and 7	Cell Identity (CI) according to TS GSM 04.08 */
typedef enum NetworkResource {
    plmn = 0,
    hlr = 1,
    vlr = 2,
    pvlr = 3,
    controllingMSC = 4,
    vmsc = 5,
    eir = 6,
    rss = 7
} NetworkResource;

typedef struct ExtensibleSystemFailureParam {
    unsigned char   bit_mask;
#       define      networkResource_present 0x80
#       define      ExtensibleSystemFailureParam_extensionContainer_present 0x40
    NetworkResource networkResource;  /* optional; set in bit_mask
                                       * networkResource_present if present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                   * ExtensibleSystemFailureParam_extensionContainer_present if
                   * present */
} ExtensibleSystemFailureParam;

	/* AbsentSubscriberDiagnosticSM values are defined in ETS 300 536 (GSM 03.40) */
typedef struct SystemFailureParam {
    unsigned short  choice;
#       define      networkResource_chosen 1
#       define      extensibleSystemFailureParam_chosen 2
    union {
        NetworkResource networkResource;  /* to choose, set choice to
                                           * networkResource_chosen */
	/* networkResource must not be used in version 3 */
        ExtensibleSystemFailureParam extensibleSystemFailureParam;  /* to
                                   * choose, set choice to
                                   * extensibleSystemFailureParam_chosen */
	/* extensibleSystemFailureParam must not be used in version <3 */
    } u;
} SystemFailureParam;

typedef struct DataMissingParam {
    unsigned char   bit_mask;
#       define      DataMissingParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                               * DataMissingParam_extensionContainer_present if
                               * present */
} DataMissingParam;

typedef struct UnexpectedDataParam {
    unsigned char   bit_mask;
#       define      UnexpectedDataParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                            * UnexpectedDataParam_extensionContainer_present if
                            * present */
} UnexpectedDataParam;

typedef struct FacilityNotSupParam {
    unsigned char   bit_mask;
#       define      FacilityNotSupParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                            * FacilityNotSupParam_extensionContainer_present if
                            * present */
} FacilityNotSupParam;

typedef struct OR_NotAllowedParam {
    unsigned char   bit_mask;
#       define      OR_NotAllowedParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                             * OR_NotAllowedParam_extensionContainer_present if
                             * present */
} OR_NotAllowedParam;

typedef enum UnknownSubscriberDiagnostic {
    imsiUnknown = 0,
    gprsSubscriptionUnknown = 1,
    npdbMismatch = 2
} UnknownSubscriberDiagnostic;

typedef struct UnknownSubscriberParam {
    unsigned char   bit_mask;
#       define      UnknownSubscriberParam_extensionContainer_present 0x80
#       define      unknownSubscriberDiagnostic_present 0x40
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                         * UnknownSubscriberParam_extensionContainer_present if
                         * present */
    UnknownSubscriberDiagnostic unknownSubscriberDiagnostic;  /* extension #1;
                                   * optional; set in bit_mask
                                   * unknownSubscriberDiagnostic_present if
                                   * present */
} UnknownSubscriberParam;

	/* if unknown values are received in 	*/
	/* unknownSubscriberDiagnostic they shall be discarded */
typedef struct NumberChangedParam {
    unsigned char   bit_mask;
#       define      NumberChangedParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                             * NumberChangedParam_extensionContainer_present if
                             * present */
} NumberChangedParam;

typedef struct UnidentifiedSubParam {
    unsigned char   bit_mask;
#       define      UnidentifiedSubParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                           * UnidentifiedSubParam_extensionContainer_present if
                           * present */
} UnidentifiedSubParam;

typedef struct IllegalSubscriberParam {
    unsigned char   bit_mask;
#       define      IllegalSubscriberParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                         * IllegalSubscriberParam_extensionContainer_present if
                         * present */
} IllegalSubscriberParam;

typedef struct IllegalEquipmentParam {
    unsigned char   bit_mask;
#       define      IllegalEquipmentParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                          * IllegalEquipmentParam_extensionContainer_present if
                          * present */
} IllegalEquipmentParam;

typedef struct BearerServNotProvParam {
    unsigned char   bit_mask;
#       define      BearerServNotProvParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                         * BearerServNotProvParam_extensionContainer_present if
                         * present */
} BearerServNotProvParam;

typedef struct TeleservNotProvParam {
    unsigned char   bit_mask;
#       define      TeleservNotProvParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                           * TeleservNotProvParam_extensionContainer_present if
                           * present */
} TeleservNotProvParam;

typedef struct TracingBufferFullParam {
    unsigned char   bit_mask;
#       define      TracingBufferFullParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                         * TracingBufferFullParam_extensionContainer_present if
                         * present */
} TracingBufferFullParam;

typedef struct NoRoamingNbParam {
    unsigned char   bit_mask;
#       define      NoRoamingNbParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                               * NoRoamingNbParam_extensionContainer_present if
                               * present */
} NoRoamingNbParam;

typedef enum AbsentSubscriberReason {
    imsiDetach = 0,
    restrictedArea = 1,
    noPageResponse = 2,
    purgedMS = 3
} AbsentSubscriberReason;

typedef struct AbsentSubscriberParam {
    unsigned char   bit_mask;
#       define      AbsentSubscriberParam_extensionContainer_present 0x80
#       define      absentSubscriberReason_present 0x40
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                          * AbsentSubscriberParam_extensionContainer_present if
                          * present */
    AbsentSubscriberReason absentSubscriberReason;  /* extension #1; optional;
                                   * set in bit_mask
                                   * absentSubscriberReason_present if
                                   * present */
} AbsentSubscriberParam;

/* exception handling: at reception of other values than the ones listed the */
/* AbsentSubscriberReason shall be ignored. */
/* The AbsentSubscriberReason: purgedMS is defined for the Super-Charger feature */
/* (see TS 23.116). If this value is received in a Provide Roaming Number response */
/* it shall be mapped to the AbsentSubscriberReason: imsiDetach in the Send Routeing */
/* Information response */
typedef struct BusySubscriberParam {
    unsigned char   bit_mask;
#       define      BusySubscriberParam_extensionContainer_present 0x80
#       define      ccbs_Possible_present 0x40
#       define      ccbs_Busy_present 0x20
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                            * BusySubscriberParam_extensionContainer_present if
                            * present */
    Nulltype        ccbs_Possible;  /* extension #1; optional; set in bit_mask
                                     * ccbs_Possible_present if present */
    Nulltype        ccbs_Busy;  /* extension #2; optional; set in bit_mask
                                 * ccbs_Busy_present if present */
} BusySubscriberParam;

typedef struct NoSubscriberReplyParam {
    unsigned char   bit_mask;
#       define      NoSubscriberReplyParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                         * NoSubscriberReplyParam_extensionContainer_present if
                         * present */
} NoSubscriberReplyParam;

typedef struct ForwardingViolationParam {
    unsigned char   bit_mask;
#       define      ForwardingViolationParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                       * ForwardingViolationParam_extensionContainer_present if
                       * present */
} ForwardingViolationParam;

typedef struct ForwardingFailedParam {
    unsigned char   bit_mask;
#       define      ForwardingFailedParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                          * ForwardingFailedParam_extensionContainer_present if
                          * present */
} ForwardingFailedParam;

typedef struct ATI_NotAllowedParam {
    unsigned char   bit_mask;
#       define      ATI_NotAllowedParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                            * ATI_NotAllowedParam_extensionContainer_present if
                            * present */
} ATI_NotAllowedParam;

typedef struct ATSI_NotAllowedParam {
    unsigned char   bit_mask;
#       define      ATSI_NotAllowedParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                           * ATSI_NotAllowedParam_extensionContainer_present if
                           * present */
} ATSI_NotAllowedParam;

typedef struct ATM_NotAllowedParam {
    unsigned char   bit_mask;
#       define      ATM_NotAllowedParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                            * ATM_NotAllowedParam_extensionContainer_present if
                            * present */
} ATM_NotAllowedParam;

typedef struct IllegalSS_OperationParam {
    unsigned char   bit_mask;
#       define      IllegalSS_OperationParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                       * IllegalSS_OperationParam_extensionContainer_present if
                       * present */
} IllegalSS_OperationParam;

typedef struct SS_NotAvailableParam {
    unsigned char   bit_mask;
#       define      SS_NotAvailableParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                           * SS_NotAvailableParam_extensionContainer_present if
                           * present */
} SS_NotAvailableParam;

typedef struct SS_SubscriptionViolationParam {
    unsigned char   bit_mask;
#       define      SS_SubscriptionViolationParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                  * SS_SubscriptionViolationParam_extensionContainer_present if
                  * present */
} SS_SubscriptionViolationParam;

typedef struct InformationNotAvailableParam {
    unsigned char   bit_mask;
#       define      InformationNotAvailableParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                   * InformationNotAvailableParam_extensionContainer_present if
                   * present */
} InformationNotAvailableParam;

typedef struct SubBusyForMT_SMS_Param {
    unsigned char   bit_mask;
#       define      SubBusyForMT_SMS_Param_extensionContainer_present 0x80
#       define      gprsConnectionSuspended_present 0x40
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                         * SubBusyForMT_SMS_Param_extensionContainer_present if
                         * present */
    Nulltype        gprsConnectionSuspended;  /* extension #1; optional; set in
                                   * bit_mask gprsConnectionSuspended_present if
                                   * present */
} SubBusyForMT_SMS_Param;

	/* If GprsConnectionSuspended is not understood it shall */
	/* be discarded */
typedef struct MessageWaitListFullParam {
    unsigned char   bit_mask;
#       define      MessageWaitListFullParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                       * MessageWaitListFullParam_extensionContainer_present if
                       * present */
} MessageWaitListFullParam;

typedef struct ResourceLimitationParam {
    unsigned char   bit_mask;
#       define      ResourceLimitationParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                        * ResourceLimitationParam_extensionContainer_present if
                        * present */
} ResourceLimitationParam;

typedef struct NoGroupCallNbParam {
    unsigned char   bit_mask;
#       define      NoGroupCallNbParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                             * NoGroupCallNbParam_extensionContainer_present if
                             * present */
} NoGroupCallNbParam;

typedef struct IncompatibleTerminalParam {
    unsigned char   bit_mask;
#       define      IncompatibleTerminalParam_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                      * IncompatibleTerminalParam_extensionContainer_present if
                      * present */
} IncompatibleTerminalParam;

typedef struct ShortTermDenialParam {
    char            placeholder;
} ShortTermDenialParam;

typedef struct LongTermDenialParam {
    char            placeholder;
} LongTermDenialParam;

typedef struct UnauthorizedRequestingNetwork_Param {
    unsigned char   bit_mask;
#       define      UnauthorizedRequestingNetwork_Param_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
            * UnauthorizedRequestingNetwork_Param_extensionContainer_present if
            * present */
} UnauthorizedRequestingNetwork_Param;

typedef enum UnauthorizedLCSClient_Diagnostic {
    noAdditionalInformation = 0,
    clientNotInMSPrivacyExceptionList = 1,
    callToClientNotSetup = 2,
    privacyOverrideNotApplicable = 3,
    disallowedByLocalRegulatoryRequirements = 4
} UnauthorizedLCSClient_Diagnostic;

typedef struct UnauthorizedLCSClient_Param {
    unsigned char   bit_mask;
#       define      unauthorizedLCSClient_Diagnostic_present 0x80
#       define      UnauthorizedLCSClient_Param_extensionContainer_present 0x40
    UnauthorizedLCSClient_Diagnostic unauthorizedLCSClient_Diagnostic;  
                                  /* optional; set in bit_mask
                                   * unauthorizedLCSClient_Diagnostic_present if
                                   * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                    * UnauthorizedLCSClient_Param_extensionContainer_present if
                    * present */
} UnauthorizedLCSClient_Param;

typedef enum PositionMethodFailure_Diagnostic {
    congestion = 0,
    insufficientResources = 1,
    insufficientMeasurementData = 2,
    inconsistentMeasurementData = 3,
    locationProcedureNotCompleted = 4,
    locationProcedureNotSupportedByTargetMS = 5,
    qoSNotAttainable = 6,
    positionMethodNotAvailableInNetwork = 7,
    positionMethodNotAvailableInLocationArea = 8
} PositionMethodFailure_Diagnostic;

/*	exception handling: */
/*	any unrecognized value shall be ignored */
typedef struct PositionMethodFailure_Param {
    unsigned char   bit_mask;
#       define      positionMethodFailure_Diagnostic_present 0x80
#       define      PositionMethodFailure_Param_extensionContainer_present 0x40
    PositionMethodFailure_Diagnostic positionMethodFailure_Diagnostic;  
                                  /* optional; set in bit_mask
                                   * positionMethodFailure_Diagnostic_present if
                                   * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                    * PositionMethodFailure_Param_extensionContainer_present if
                    * present */
} PositionMethodFailure_Param;

/*	exception handling: */
/*	any unrecognized value shall be ignored */
typedef struct UnknownOrUnreachableLCSClient_Param {
    unsigned char   bit_mask;
#       define      UnknownOrUnreachableLCSClient_Param_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
            * UnknownOrUnreachableLCSClient_Param_extensionContainer_present if
            * present */
} UnknownOrUnreachableLCSClient_Param;

typedef struct MM_EventNotSupported_Param {
    unsigned char   bit_mask;
#       define      MM_EventNotSupported_Param_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                     * MM_EventNotSupported_Param_extensionContainer_present if
                     * present */
} MM_EventNotSupported_Param;

typedef struct TargetCellOutsideGCA_Param {
    unsigned char   bit_mask;
#       define      TargetCellOutsideGCA_Param_extensionContainer_present 0x80
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                     * TargetCellOutsideGCA_Param_extensionContainer_present if
                     * present */
} TargetCellOutsideGCA_Param;

typedef struct MAP_ST_DataTypes_OperationCode {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} MAP_ST_DataTypes_OperationCode;

typedef struct MAP_ST_DataTypes_ErrorCode {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} MAP_ST_DataTypes_ErrorCode;

typedef struct OriginalComponentIdentifier {
    unsigned short  choice;
#       define      operationCode_chosen 1
#       define      errorCode_chosen 2
#       define      userInfo_chosen 3
    union {
        MAP_ST_DataTypes_OperationCode operationCode;  /* to choose, set choice
                                                   * to operationCode_chosen */
        MAP_ST_DataTypes_ErrorCode errorCode;  /* to choose, set choice to
                                                * errorCode_chosen */
        Nulltype        userInfo;  /* to choose, set choice to
                                    * userInfo_chosen */
    } u;
} OriginalComponentIdentifier;

/* for a CAMEL phase 3 PLMN operator client, the value targetMSsubscribedService shall be used */
typedef struct PLMN_Id {
    unsigned short  length;
    unsigned char   value[3];
} PLMN_Id;

	/* In protection mode 0 (noProtection) the ProtectedPayload carries the transfer */
		/* syntax value of the component parameter identified by the */
		/* originalComponentIdentifier. */
	/* In protection mode 1 (integrityAuthenticity) the protectedPayload carries 4 */
		/* octets TVP, followed by the transfer syntax value of the component */
		/* parameter identified by the originalComponentIdentifier, followed by */
		/* the integrity check value. */
		/* The integrity check value is the result of applying the hash algorithm */
		/* to the concatenation of TVP, transfer syntax value of the SecurityHeader, */
		/* transfer syntax value of the component parameter. */
	/* In protection mode 2 (confidentialityIntegrityAuthenticity) the protected */
		/* payload carries 4 octets TVP, followed by the encrypted transfer syntax */
		/* value of the component parameter identified by the */
		/* originalComponentIdentifier, followed by the integrity check value. */
		/* The integrity check value is the result of applying the hash algorithm */
		/* to the concatenation of TVP, transfer syntax value of the SecurityHeader, */
		/* encrypted transfer syntax value of the component parameter. */
	/* See 33.102. */
	/* The length of the protectedPayload is adjusted according to the capabilities of */
	/* the lower protocol layers */
typedef enum ProtectionMode {
    noProtection = 0,
    integrityAuthenticity = 1,
    confidentialityIntegrityAuthenticity = 2
} ProtectionMode;

typedef unsigned short  EncryptionAlgorithmIdentifier;

	/* The encryption algorithm corresponding to each value of the Hash Algorithm */
	/* Identifier type is defined in TS 33.102 */
typedef enum ModeOfOperation {
    ecb = 0,
    cbc = 1,
    ModeOfOperation_cfb = 2,
    ofb = 3
} ModeOfOperation;

	/* Modes of operation are defined in ISO/IEC 10116 (1991) */
typedef unsigned short  EncryptionKeyVersionNumber;

typedef struct InitialisationVector {
    unsigned short  length;
    unsigned char   value[8];
} InitialisationVector;

	/* The encryption algorithm corresponding to each value of the Encryption */
	/* Algorithm Identifier type is defined in TS 33.102 */
typedef unsigned short  HashAlgorithmIdentifier;

typedef unsigned short  HashKeyVersionNumber;

	/* The protectedPayload carries the result of applying the security function */
	/* defined in 3G TS 33.102 to the encoding of the result of the securely */
	/* transported operation */
typedef struct SecurityHeader {
    unsigned char   bit_mask;
#       define      protectionMode_present 0x80
#       define      encryptionAlgorithmIdentifier_present 0x40
#       define      modeOfOperation_present 0x20
#       define      encryptionKeyVersionNumber_present 0x10
#       define      initialisationVector_present 0x08
#       define      hashAlgorithmIdentifier_present 0x04
#       define      hashKeyVersionNumber_present 0x02
    OriginalComponentIdentifier originalComponentIdentifier;
    PLMN_Id         sendingPLMN_Id;
    ProtectionMode  protectionMode;  /* optional; set in bit_mask
                                      * protectionMode_present if present */
    EncryptionAlgorithmIdentifier encryptionAlgorithmIdentifier;  /* optional;
                                   * set in bit_mask
                                   * encryptionAlgorithmIdentifier_present if
                                   * present */
    ModeOfOperation modeOfOperation;  /* optional; set in bit_mask
                                       * modeOfOperation_present if present */
    EncryptionKeyVersionNumber encryptionKeyVersionNumber;  /* optional; set in
                                   * bit_mask encryptionKeyVersionNumber_present
                                   * if present */
    InitialisationVector initialisationVector;  /* optional; set in bit_mask
                                                 * initialisationVector_present
                                                 * if present */
    HashAlgorithmIdentifier hashAlgorithmIdentifier;  /* optional; set in
                                   * bit_mask hashAlgorithmIdentifier_present if
                                   * present */
    HashKeyVersionNumber hashKeyVersionNumber;  /* optional; set in bit_mask
                                                 * hashKeyVersionNumber_present
                                                 * if present */
} SecurityHeader;

typedef struct ProtectedPayload {
    unsigned short  length;
    unsigned char   *value;
} ProtectedPayload;

typedef struct SecureTransportErrorParam {
    unsigned char   bit_mask;
#       define      protectedPayload_present 0x80
    SecurityHeader  securityHeader;
    ProtectedPayload protectedPayload;  /* optional; set in bit_mask
                                         * protectedPayload_present if
                                         * present */
} SecureTransportErrorParam;
	/* The protectedPayload carries the result of applying the security function */
	/* defined in 3G TS 33.102 to the encoding of the securely transported error */
	/* parameter */

typedef enum Ext_ProtocolId {
    ets_300356 = 1
} Ext_ProtocolId;

typedef struct Ext_ExternalSignalInfo {
    unsigned char   bit_mask;
#       define      Ext_ExternalSignalInfo_extensionContainer_present 0x80
    Ext_ProtocolId  ext_ProtocolId;
    SignalInfo      signalInfo;
	/* Information about the internal structure is given in */
	/* subclause 7.6.9.10 */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                         * Ext_ExternalSignalInfo_extensionContainer_present if
                         * present */
} Ext_ExternalSignalInfo;

typedef enum AccessNetworkProtocolId {
    AccessNetworkProtocolId_gsm_0806 = 1,
    ts3G_25413 = 2
} AccessNetworkProtocolId;

/* exception handling: */
/* For Ext-ExternalSignalInfo sequences containing this parameter with any */
/* other value than the ones listed the receiver shall ignore the whole */
/* Ext-ExternalSignalInfo sequence. */
typedef struct AccessNetworkSignalInfo {
    unsigned char   bit_mask;
#       define      AccessNetworkSignalInfo_extensionContainer_present 0x80
    AccessNetworkProtocolId accessNetworkProtocolId;
    SignalInfo      signalInfo;
	/* Information about the internal structure is given in */
	/* subclause 7.6.9.4 */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                        * AccessNetworkSignalInfo_extensionContainer_present if
                        * present */
} AccessNetworkSignalInfo;

typedef struct IMSI_WithLMSI {
    IMSI            imsi;
    LMSI            lmsi;
	/* a special value 00000000 indicates that the LMSI is not in use */
} IMSI_WithLMSI;

	/* digits of MCC, MNC, MSIN are concatenated in this order. */
typedef struct Identity {
    unsigned short  choice;
#       define      Identity_imsi_chosen 1
#       define      imsi_WithLMSI_chosen 2
    union {
        IMSI            imsi;  /* to choose, set choice to
                                * Identity_imsi_chosen */
        IMSI_WithLMSI   imsi_WithLMSI;  /* to choose, set choice to
                                         * imsi_WithLMSI_chosen */
    } u;
} Identity;

typedef struct ASCI_CallReference {
    unsigned short  length;
    unsigned char   value[8];
} ASCI_CallReference;

	/* digits of VGCS/VBC-area,Group-ID are concatenated in this order. */
typedef struct TMSI {
    unsigned short  length;
    unsigned char   value[4];
} TMSI;

typedef struct SubscriberId {
    unsigned short  choice;
#       define      SubscriberId_imsi_chosen 1
#       define      tmsi_chosen 2
    union {
        IMSI            imsi;  /* to choose, set choice to
                                * SubscriberId_imsi_chosen */
        TMSI            tmsi;  /* to choose, set choice to tmsi_chosen */
    } u;
} SubscriberId;

typedef struct IMEI {
    unsigned short  length;
    unsigned char   value[8];
} IMEI;

	/*	Refers to International Mobile Station Equipment Identity */
	/*	and Software Version Number (SVN) defined in TS GSM 03.03. */
	/*	If the SVN is not present the last octet shall contain the */
	/*	digit 0 and a filler. */
	/*	If present the SVN shall be included in the last octet. */
typedef IMSI            HLR_Id;

	/* leading digits of IMSI, i.e. (MCC, MNC, leading digits of */
	/* MSIN) forming HLR Id defined in TS GSM 03.03. */
typedef struct HLR_List {
    struct HLR_List *next;
    HLR_Id          value;
} *HLR_List;

typedef struct GlobalCellId {
    unsigned short  length;
    unsigned char   value[7];
} GlobalCellId;

typedef struct NAEA_CIC {
    unsigned short  length;
    unsigned char   value[3];
} NAEA_CIC;

typedef struct NAEA_PreferredCI {
    unsigned char   bit_mask;
#       define      NAEA_PreferredCI_extensionContainer_present 0x80
    NAEA_CIC        naea_PreferredCIC;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                               * NAEA_PreferredCI_extensionContainer_present if
                               * present */
} NAEA_PreferredCI;

	/* The internal structure is defined by the Carrier Identification */
	/* parameter in ANSI T1.113.3. Carrier codes between "000" and "999" may */
	/* be encoded as 3 digits using "000" to "999" or as 4 digits using */
	/* "0000" to "0999". Carrier codes between "1000" and "9999" are encoded */
	/* using 4 digits. */
typedef struct MAP_CommonDataTypes_SubscriberIdentity {
    unsigned short  choice;
#       define      MAP_CommonDataTypes_SubscriberIdentity_imsi_chosen 1
#       define      MAP_CommonDataTypes_SubscriberIdentity_msisdn_chosen 2
    union {
        IMSI            imsi;  /* to choose, set choice to
                        * MAP_CommonDataTypes_SubscriberIdentity_imsi_chosen */
        ISDN_AddressString msisdn;  /* to choose, set choice to
                      * MAP_CommonDataTypes_SubscriberIdentity_msisdn_chosen */
    } u;
} MAP_CommonDataTypes_SubscriberIdentity;

typedef struct LCSClientExternalID {
    unsigned char   bit_mask;
#       define      externalAddress_present 0x80
#       define      LCSClientExternalID_extensionContainer_present 0x40
    AddressString   externalAddress;  /* optional; set in bit_mask
                                       * externalAddress_present if present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                            * LCSClientExternalID_extensionContainer_present if
                            * present */
} LCSClientExternalID;

typedef enum LCSClientInternalID {
    broadcastService = 0,
    o_andM_HPLMN = 1,
    o_andM_VPLMN = 2,
    anonymousLocation = 3,
    targetMSsubscribedService = 4
} LCSClientInternalID;

typedef struct CellGlobalIdOrServiceAreaIdFixedLength {
    unsigned short  length;
    unsigned char   value[7];
} CellGlobalIdOrServiceAreaIdFixedLength;

	/* Refers to Cell Global Identification or Service Are Identification */
	/* defined in 3G TS 23.003. */
	/* The internal structure is defined as follows: */
	/* octet 1 bits 4321	Mobile Country Code 1st digit */
	/*         bits 8765	Mobile Country Code 2nd digit */
	/* octet 2 bits 4321	Mobile Country Code 3rd digit */
	/*         bits 8765	Mobile Network Code 3rd digit */
	/*			or filler (1111) for 2 digit MNCs */
	/* octet 3 bits 4321	Mobile Network Code 1st digit */
	/*         bits 8765	Mobile Network Code 2nd digit */
	/* octets 4 and 5	Location Area Code according to 3G TS 24.008 */
	/* octets 6 and 7	Cell Identity (CI) value or */
	/* 			Service Area Code (SAC) value */
	/*			according to 3G TS 23.003 */
typedef struct LAIFixedLength {
    unsigned short  length;
    unsigned char   value[5];
} LAIFixedLength;

	/* digits of MCC, MNC, are concatenated in this order. */

/* data types for CAMEL */
typedef struct CellGlobalIdOrServiceAreaIdOrLAI {
    unsigned short  choice;
#       define      cellGlobalIdOrServiceAreaIdFixedLength_chosen 1
#       define      laiFixedLength_chosen 2
    union {
        CellGlobalIdOrServiceAreaIdFixedLength cellGlobalIdOrServiceAreaIdFixedLength;                                  /* to choose, set choice to
                             * cellGlobalIdOrServiceAreaIdFixedLength_chosen */
        LAIFixedLength  laiFixedLength;  /* to choose, set choice to
                                          * laiFixedLength_chosen */
    } u;
} CellGlobalIdOrServiceAreaIdOrLAI;

	/* This type is used to represent the code identifying a single */
	/* bearer service, a group of bearer services, or all bearer */
	/* services. The services are defined in TS GSM 02.02. */
	/* The internal structure is defined as follows: */
	/**/
	/* plmn-specific bearer services: */
	/* bits 87654321: defined by the HPLMN operator */

	/* rest of bearer services: */
	/* bit 8: 0 (unused) */
	/* bits 7654321: group (bits 7654), and rate, if applicable */
	/* (bits 321) */
typedef struct MAP_BS_Code_Ext_BearerServiceCode {
    unsigned short  length;
    unsigned char   value[5];
} MAP_BS_Code_Ext_BearerServiceCode;

	/* This type is used to represent the code identifying a single */
	/* teleservice, a group of teleservices, or all teleservices. The */
	/* services are defined in TS GSM 02.03. */
	/* The internal structure is defined as follows: */

	/* bits 87654321: group (bits 8765) and specific service */
	/* (bits 4321) */
typedef struct MAP_TS_Code_Ext_TeleserviceCode {
    unsigned short  length;
    unsigned char   value[5];
} MAP_TS_Code_Ext_TeleserviceCode;

typedef struct MAP_CommonDataTypes_Ext_BasicServiceCode {
    unsigned short  choice;
#       define      MAP_CommonDataTypes_Ext_BasicServiceCode_ext_BearerService_chosen 1
#       define      MAP_CommonDataTypes_Ext_BasicServiceCode_ext_Teleservice_chosen 2
    union {
        MAP_BS_Code_Ext_BearerServiceCode ext_BearerService;  /* to choose, set
                                   * choice to
         * MAP_CommonDataTypes_Ext_BasicServiceCode_ext_BearerService_chosen */
        MAP_TS_Code_Ext_TeleserviceCode ext_Teleservice;  /* to choose, set
                                   * choice to
           * MAP_CommonDataTypes_Ext_BasicServiceCode_ext_Teleservice_chosen */
    } u;
} MAP_CommonDataTypes_Ext_BasicServiceCode;

typedef struct EMLPP_Info {
    unsigned char   bit_mask;
#       define      EMLPP_Info_extensionContainer_present 0x80
    EMLPP_Priority  maximumentitledPriority;
    EMLPP_Priority  defaultPriority;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                                     * EMLPP_Info_extensionContainer_present if
                                     * present */
} EMLPP_Info;

typedef struct MAP_CommonDataTypes_Ext_SS_Status {
    unsigned short  length;
    unsigned char   value[5];
} MAP_CommonDataTypes_Ext_SS_Status;

typedef struct MC_SS_Info {
    unsigned char   bit_mask;
#       define      MC_SS_Info_extensionContainer_present 0x80
    SS_Code         ss_Code;
    MAP_CommonDataTypes_Ext_SS_Status ss_Status;
    MaxMC_Bearers   nbrSB;
    MC_Bearers      nbrUser;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                                     * MC_SS_Info_extensionContainer_present if
                                     * present */
} MC_SS_Info;

	/* OCTET 1: */
	/**/
	/* bits 8765: 0000 (unused) */
	/* bits 4321: Used to convey the "P bit","R bit","A bit" and "Q bit", */
	/*		    representing supplementary service state information */
	/*		    as defined in TS GSM 03.11 */

	/* bit 4: "Q bit" */

	/* bit 3: "P bit" */

	/* bit 2: "R bit" */

	/* bit 1: "A bit" */

	/* OCTETS 2-5: reserved for future use. They shall be discarded if */
	/* received and not understood. */

	/* data types for geographic location */
typedef unsigned short  AgeOfLocationInformation;
/* the value represents the elapsed time in minutes since the last */
/* network contact of the mobile station (i.e. the actuality of the */
/* location information). */
/* value "0" indicates that the MS is currently in contact with the */
/*           network */
/* value "32767" indicates that the location information is at least */
/*               32767 minutes old */

/* IOC for private MAP extensions */
typedef struct MAP_EXTENSION {
    unsigned char   bit_mask;
#       define      ExtensionType_present 0x80
    unsigned short  ExtensionType;  /* optional; set in bit_mask
                                     * ExtensionType_present if present */
    ObjectID        extensionId;
    long            _oss_unique_index;
} MAP_EXTENSION;

typedef struct PrivateExtension {
    unsigned char   bit_mask;
#       define      extType_present 0x80
    ObjectID        extId;
    OpenType        extType;  /* optional; set in bit_mask extType_present if
                               * present */
} PrivateExtension;

typedef struct PrivateExtensionList {
    struct PrivateExtensionList *next;
    PrivateExtension value;
} *PrivateExtensionList;

/* KTF extensions */
typedef struct KTF_ORIGSERVICETYPE {
    unsigned char   bit_mask;
#       define      camelServiceType_present 0x80
#       define      smsIndicator_present 0x40
    unsigned short  camelServiceType;  /* optional; set in bit_mask
                                        * camelServiceType_present if present */
    struct {
        unsigned short  length;
        unsigned char   value[2];
    } smsIndicator;  /* optional; set in bit_mask smsIndicator_present if
                      * present */
} KTF_ORIGSERVICETYPE;

typedef struct KTF_DESTSERVICETYPE {
    unsigned short  length;
    unsigned char   value[3];
} KTF_DESTSERVICETYPE;

typedef ISDN_AddressString KTF_EXTMSISDNTYPE;

typedef ISDN_AddressString KTF_EXTORIGINALNUMTYPE;

typedef struct KTF_SHOWREGIONTYPE {
    unsigned short  length;
    unsigned char   value[1];
} KTF_SHOWREGIONTYPE;

typedef struct KTF_UEINDICATORTYPE {
    unsigned short  length;
    unsigned char   value[16];
} KTF_UEINDICATORTYPE;

/*KT-ROAMPARTYTYPE ::= SEQUENCE { */
/*  ktRoamparty     OCTET STRING(SIZE(1..24)) OPTIONAL */
/*} */
/*KT-ROAMPARTYTYPE ::= OCTET STRING (SIZE (1..16)) OPTIONAL */
typedef struct KT_ROAMPARTYTYPE {
    unsigned short  length;
    unsigned char   value[24];
} KT_ROAMPARTYTYPE;

typedef struct KT_IPSMGWSVCINFO {
    unsigned short  length;
    unsigned char   value[16];
} KT_IPSMGWSVCINFO;

typedef ISDN_AddressString KT_DESTADDRFORSMDATA;

typedef struct KT_RETRYINDFORSM {
    unsigned short  length;
    unsigned char   value[1];
} KT_RETRYINDFORSM;

typedef enum KtfBarringServiceReason {
    snbd1 = 0,
    snbd2 = 1,
    snd = 2
} KtfBarringServiceReason;

/* SKT extension */
typedef struct SKMIN {
    unsigned short  length;
    unsigned char   value[5];
} SKMIN;

typedef struct SKESN {
    unsigned short  length;
    unsigned char   value[4];
} SKESN;

typedef struct SKSMSCapability {
    unsigned short  length;
    unsigned char   value[4];
} SKSMSCapability;

typedef struct SKOriginatingSFI {
    unsigned short  length;
    unsigned char   value[5];
} SKOriginatingSFI;

typedef struct SKTSMSRoamingIndicator {
    unsigned short  length;
    unsigned char   value[1];
} SKTSMSRoamingIndicator;

typedef struct SKTSMSAccessDeniedReason {
    unsigned short  length;
    unsigned char   value[1];
} SKTSMSAccessDeniedReason;

typedef struct SKTSMSRoamingPMN {
    unsigned short  length;
    unsigned char   value[8];
} SKTSMSRoamingPMN;

typedef ISDN_AddressString MSISDN;

typedef struct SecureTransportArg {
    unsigned char   bit_mask;
#       define      protectedPayload_present 0x80
    SecurityHeader  securityHeader;
    ProtectedPayload protectedPayload;  /* optional; set in bit_mask
                                         * protectedPayload_present if
                                         * present */
} SecureTransportArg;

	/* The protectedPayload carries the result of applying the security function */
	/* defined in 3G TS 33.102 to the encoding of the argument of the securely */
	/* transported operation */
typedef struct SecureTransportRes {
    unsigned char   bit_mask;
#       define      protectedPayload_present 0x80
    SecurityHeader  securityHeader;
    ProtectedPayload protectedPayload;  /* optional; set in bit_mask
                                         * protectedPayload_present if
                                         * present */
} SecureTransportRes;

	/* generic errors */
	/* identification and numbering errors */
	/* subscription errors */
	/* handover errors */
	/* operation and maintenance errors */
	/* call handling errors */
	/* any time interrogation errors */
	/* any time information handling errors */
	/* supplementary service errors */
	/* short message service errors */
	/* Group Call errors */
	/* location service errors */
	/* Mobility Management errors */
	/* Secure transport errors */
/* generic errors */
typedef struct SystemFailure {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} SystemFailure;

		/* optional */
typedef struct DataMissing {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} DataMissing;

		/* optional */
		/* dataMissingParam must not be used in version <3 */
typedef struct UnexpectedDataValue {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} UnexpectedDataValue;

		/* optional */
		/* unexpectedDataParam must not be used in version <3 */
typedef struct FacilityNotSupported {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} FacilityNotSupported;

		/* optional */
		/* facilityNotSupParam must not be used in version <3 */
typedef struct IncompatibleTerminal {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} IncompatibleTerminal;

		/* optional */
typedef struct ResourceLimitation {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} ResourceLimitation;

		/* optional */

/* identification and numbering errors */
typedef struct UnknownSubscriber {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} UnknownSubscriber;

		/* optional */
		/* unknownSubscriberParam must not be used in version <3 */
typedef struct NumberChanged {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} NumberChanged;

		/* optional */
typedef struct UnknownMSC {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} UnknownMSC;

typedef struct UnidentifiedSubscriber {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} UnidentifiedSubscriber;

		/* optional */
		/* unidentifiedSubParam must not be used in version <3 */
typedef struct UnknownEquipment {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} UnknownEquipment;

/* subscription errors */
typedef struct RoamingNotAllowed {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} RoamingNotAllowed;

typedef struct IllegalSubscriber {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} IllegalSubscriber;

		/* optional */
		/* illegalSubscriberParam must not be used in version <3 */
typedef struct IllegalEquipment {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} IllegalEquipment;

		/* optional */
		/* illegalEquipmentParam must not be used in version <3 */
typedef struct BearerServiceNotProvisioned {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} BearerServiceNotProvisioned;

		/* optional */
		/* bearerServNotProvParam must not be used in version <3 */
typedef struct TeleserviceNotProvisioned {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} TeleserviceNotProvisioned;

		/* optional */
		/* teleservNotProvParam must not be used in version <3 */

/* handover errors */
typedef struct NoHandoverNumberAvailable {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} NoHandoverNumberAvailable;

typedef struct SubsequentHandoverFailure {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} SubsequentHandoverFailure;

typedef struct TargetCellOutsideGroupCallArea {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} TargetCellOutsideGroupCallArea;

		/* optional */

/* operation and maintenance errors */
typedef struct TracingBufferFull {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} TracingBufferFull;

		/* optional */

/* call handling errors */
typedef struct NoRoamingNumberAvailable {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} NoRoamingNumberAvailable;

		/* optional */
typedef struct AbsentSubscriber {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} AbsentSubscriber;

		/* optional */
		/* absentSubscriberParam must not be used in version <3 */
typedef struct BusySubscriber {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} BusySubscriber;

		/* optional */
typedef struct NoSubscriberReply {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} NoSubscriberReply;

		/* optional */
typedef struct CallBarred {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} CallBarred;

		/* optional */
typedef struct ForwardingViolation {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} ForwardingViolation;

		/* optional */
typedef struct ForwardingFailed {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} ForwardingFailed;

		/* optional */
typedef struct CUG_Reject {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} CUG_Reject;

		/* optional */
typedef struct OR_NotAllowed {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} OR_NotAllowed;

		/* optional */

/* any time interrogation errors */
typedef struct ATI_NotAllowed {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} ATI_NotAllowed;

		/* optional */

/* any time information handling errors */
typedef struct ATSI_NotAllowed {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} ATSI_NotAllowed;

		/* optional */
typedef struct ATM_NotAllowed {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} ATM_NotAllowed;

        /* optional */
typedef struct InformationNotAvailable {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} InformationNotAvailable;

		/* optional */

/* supplementary service errors */
typedef struct IllegalSS_Operation {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} IllegalSS_Operation;

		/* optional */
		/* illegalSS-OperationParam must not be used in version <3 */
typedef struct SS_ErrorStatus {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} SS_ErrorStatus;

		/* optional */
typedef struct SS_NotAvailable {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} SS_NotAvailable;

		/* optional */
		/* ss-NotAvailableParam must not be used in version <3 */
typedef struct SS_SubscriptionViolation {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} SS_SubscriptionViolation;

		/* optional */
		/* ss-NotAvailableParam must not be used in version <3 */
typedef struct SS_Incompatibility {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} SS_Incompatibility;

		/* optional */
typedef struct UnknownAlphabet {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} UnknownAlphabet;

typedef struct USSD_Busy {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} USSD_Busy;

typedef struct PW_RegistrationFailure {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} PW_RegistrationFailure;

typedef struct NegativePW_Check {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} NegativePW_Check;

typedef struct NumberOfPW_AttemptsViolation {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} NumberOfPW_AttemptsViolation;

typedef struct ShortTermDenial {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} ShortTermDenial;

		/* optional */
typedef struct LongTermDenial {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} LongTermDenial;

		/* optional */

/* short message service errors */
typedef struct SubscriberBusyForMT_SMS {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} SubscriberBusyForMT_SMS;

		/* optional */
typedef struct SM_DeliveryFailure {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} SM_DeliveryFailure;

typedef struct MessageWaitingListFull {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} MessageWaitingListFull;

		/* optional */
typedef struct AbsentSubscriberSM {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} AbsentSubscriberSM;

		/* optional */

/* Group Call errors */
typedef struct NoGroupCallNumberAvailable {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} NoGroupCallNumberAvailable;

		/* optional */

/* location service errors */
typedef struct UnauthorizedRequestingNetwork {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} UnauthorizedRequestingNetwork;

		/* optional */
typedef struct UnauthorizedLCSClient {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} UnauthorizedLCSClient;

		/* optional */
typedef struct PositionMethodFailure {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} PositionMethodFailure;

		/* optional */
typedef struct UnknownOrUnreachableLCSClient {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} UnknownOrUnreachableLCSClient;

		/* optional */
typedef struct MM_EventNotSupported {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} MM_EventNotSupported;

		/* optional */

	/* Secure transport errors */
typedef struct SecureTransportError {
    unsigned short  choice;
#       define      localValue_chosen 1
#       define      globalValue_chosen 2
    union {
        int             localValue;  /* to choose, set choice to
                                      * localValue_chosen */
        ObjectID        globalValue;  /* to choose, set choice to
                                       * globalValue_chosen */
    } u;
} SecureTransportError;

	/* Common Component Ids for structuring Mobile subdomains */
typedef unsigned short  CommonComponentId;

#ifndef _OSSNOVALUES

extern InvokeId noInvokeId;

extern OPERATION emptyBind;

extern OPERATION emptyUnbind;

extern ERROR refuse;

extern OPERATION no_op;

/* abstract syntax name for structured dialogue APDUs */
extern ObjectID dialogue_as_id;

/* Abstract syntax name for unstructured dialogue APDUs */
extern ObjectID uniDialogue_as_id;

extern const int maxNumOfCCBS_Requests;

	/* The structure of the contents of the USSD-String is dependent */
	/* on the USSD-DataCodingScheme as described in TS GSM 03.38. */
extern const int maxUSSD_StringLength;

extern const int maxNumOfSS;

extern const int maxNumOfBasicServiceGroups;

extern const int maxEventSpecification;

	/* This type is used to represent the code identifying a single */
	/* supplementary service, a group of supplementary services, or */
	/* all supplementary services. The services and abbreviations */
	/* used are defined in TS GSM 02.04. The internal structure is */
	/* defined as follows: */
	/**/
	/* bits 87654321: group (bits 8765), and specific service */
	/* (bits 4321) */
extern SS_Code allSS;

	/* reserved for possible future use */
	/* all SS */
extern SS_Code allLineIdentificationSS;

	/* reserved for possible future use */
	/* all line identification SS */
extern SS_Code clip;

	/* calling line identification presentation */
extern SS_Code clir;

	/* calling line identification restriction */
extern SS_Code colp;

	/* connected line identification presentation */
extern SS_Code colr;

	/* connected line identification restriction */
extern SS_Code mci;

	/* reserved for possible future use */
	/* malicious call identification */
extern SS_Code allNameIdentificationSS;

	/* all name identification SS */
extern SS_Code cnap;

	/* calling name presentation */

	/* SS-Codes '00011010'B to '00011111'B are reserved for future */
	/* NameIdentification Supplementary Service use. */
extern SS_Code allForwardingSS;

	/* all forwarding SS */
extern SS_Code cfu;

	/* call forwarding unconditional */
extern SS_Code allCondForwardingSS;

	/* all conditional forwarding SS */
extern SS_Code cfb;

	/* call forwarding on mobile subscriber busy */
extern SS_Code cfnry;

	/* call forwarding on no reply */
extern SS_Code cfnrc;

	/* call forwarding on mobile subscriber not reachable */
extern SS_Code cd;

	/* call deflection */
extern SS_Code allCallOfferingSS;

	/* reserved for possible future use */
	/* all call offering SS includes also all forwarding SS */
extern SS_Code ect;

		/* explicit call transfer */
extern SS_Code mah;

	/* reserved for possible future use */
	/* mobile access hunting */
extern SS_Code allCallCompletionSS;

	/* reserved for possible future use */
	/* all Call completion SS */
extern SS_Code cw;

	/* call waiting */
extern SS_Code hold;

	/* call hold */
extern SS_Code ccbs_A;

	/* completion of call to busy subscribers, originating side */
extern SS_Code ccbs_B;

	/* completion of call to busy subscribers, destination side */
	/* this SS-Code is used only in InsertSubscriberData and DeleteSubscriberData */
extern SS_Code mc;

	/* multicall */
extern SS_Code allMultiPartySS;

	/* reserved for possible future use */
	/* all multiparty SS */
extern SS_Code multiPTY;

	/* multiparty */
extern SS_Code allCommunityOfInterest_SS;

	/* reserved for possible future use */
	/* all community of interest SS */
extern SS_Code cug;

	/* closed user group */
extern SS_Code allChargingSS;

	/* reserved for possible future use */
	/* all charging SS */
extern SS_Code aoci;

	/* advice of charge information */
extern SS_Code aocc;

	/* advice of charge charging */
extern SS_Code allAdditionalInfoTransferSS;

	/* reserved for possible future use */
	/* all additional information transfer SS */
extern SS_Code uus1;

	/* UUS1 user-to-user signalling */
extern SS_Code uus2;

	/* UUS2 user-to-user signalling */
extern SS_Code uus3;

	/* UUS3 user-to-user signalling */
extern SS_Code allBarringSS;

	/* all barring SS */
extern SS_Code barringOfOutgoingCalls;

	/* barring of outgoing calls */
extern SS_Code baoc;

	/* barring of all outgoing calls */
extern SS_Code boic;

	/* barring of outgoing international calls */
extern SS_Code boicExHC;

	/* barring of outgoing international calls except those directed */
	/* to the home PLMN */
extern SS_Code barringOfIncomingCalls;

	/* barring of incoming calls */
extern SS_Code baic;

	/* barring of all incoming calls */
extern SS_Code bicRoam;

	/* barring of incoming calls when roaming outside home PLMN */
	/* Country */
extern SS_Code allPLMN_specificSS;

extern SS_Code plmn_specificSS_1;

extern SS_Code plmn_specificSS_2;

extern SS_Code plmn_specificSS_3;

extern SS_Code plmn_specificSS_4;

extern SS_Code plmn_specificSS_5;

extern SS_Code plmn_specificSS_6;

extern SS_Code plmn_specificSS_7;

extern SS_Code plmn_specificSS_8;

extern SS_Code plmn_specificSS_9;

extern SS_Code plmn_specificSS_A;

extern SS_Code plmn_specificSS_B;

extern SS_Code plmn_specificSS_C;

extern SS_Code plmn_specificSS_D;

extern SS_Code plmn_specificSS_E;

extern SS_Code plmn_specificSS_F;

extern SS_Code allCallPrioritySS;

	/* reserved for possible future use */
	/* all call priority SS */
extern SS_Code emlpp;

	/* enhanced Multilevel Precedence Pre-emption (EMLPP) service */
extern SS_Code allLCSPrivacyException;

	/* all LCS Privacy Exception Classes */
extern SS_Code universal;

	/* allow location by any LCS client */
extern SS_Code callrelated;

	/* allow location by any value added LCS client to which a call */
	/* is established from the target MS */
extern SS_Code callunrelated;

	/* allow location by designated external value added LCS clients */
extern SS_Code plmnoperator;

	/* allow location by designated PLMN operator LCS clients */
extern SS_Code allMOLR_SS;

	/* all Mobile Originating Location Request Classes */
extern SS_Code basicSelfLocation;

	/* allow an MS to request its own location */
extern SS_Code autonomousSelfLocation;

	/* allow an MS to perform self location without interaction */
	/* with the PLMN for a predetermined period of time */
extern SS_Code transferToThirdParty;
	/* allow an MS to request transfer of its location to another LCS client */

extern const int maxNumOfMobilityTriggers;

/* O-BcsmCamelTDPDataList shall not contain more than one instance of */
/* O-BcsmCamelTDPData containing the same value for o-BcsmTriggerDetectionPoint. */
/* For CAMEL Phase 2, this means that only one instance of O-BcsmCamelTDPData is allowed */
/* with o-BcsmTriggerDetectionPoint being equal to DP2. */
extern const int maxNumOfCamelTDPData;

	/* This type is used to represent ISDN subaddresses. */
	/* It is composed of */
	/*	a)	one octet for type of subaddress and odd/even indicator. */
	/*	b)	20 octets for subaddress information. */

	/*	a)	The first octet includes a one bit extension indicator, a */
	/*		3 bits type of subaddress and a one bit odd/even indicator, */
	/*		encoded as follows: */

	/*	bit 8: 1  (no extension) */

	/*	bits 765: type of subaddress */
	/*		000  NSAP (X.213/ISO 8348 AD2) */
	/*		010  User Specified */
	/*		All other values are reserved */

	/*	bit 4: odd/even indicator */
	/*		0  even number of address signals */
	/*		1  odd number of address signals */
	/*		The odd/even indicator is used when the type of subaddress */
	/*		is "user specified" and the coding is BCD. */

	/*	bits 321: 000 (unused) */

	/*	b) Subaddress information. */
	/*	The NSAP X.213/ISO8348AD2 address shall be formatted as specified */
	/*	by octet 4 which contains the Authority and Format Identifier */
	/*	(AFI). The encoding is made according to the "preferred binary */
	/*	encoding" as defined in X.213/ISO834AD2. For the definition */
	/*	of this type of subaddress, see CCITT Rec I.334. */

	/*	For User-specific subaddress, this field is encoded according */
	/*	to the user specification, subject to a maximum length of 20 */
	/*	octets. When interworking with X.25 networks BCD coding should */
	/*	be applied. */
extern const int MAP_SM_DataTypes_maxISDN_SubaddressLength;

extern const int maxNumOfTeleservices;

extern const int maxNumOfDP_AnalysedInfoCriteria;

extern const int maxNumOfCAMEL_O_CauseValueCriteria;

extern const int maxNumOfCAMEL_T_CauseValueCriteria;

extern const int maxNumOfISDN_AddressDigits;

extern const int maxNumOfCamelDestinationNumbers;

extern const int maxNumOfCamelDestinationNumberLengths;

extern const int maxNumOfCamelBasicServiceCriteria;

extern const int maxNumOfCamelSSEvents;

extern const int maxNumOfExt_BasicServiceGroups;

	/* This type is used to represent a number for addressing */
	/* purposes. It is composed of */
	/*	a)	one octet for nature of address, and numbering plan */
	/*		indicator. */
	/*	b)	digits of an address encoded as TBCD-String. */

	/* a)	The first octet includes a one bit extension indicator, a */
	/*		3 bits nature of address indicator and a 4 bits numbering */
	/*		plan indicator, encoded as follows: */

	/* bit 8: 1  (no extension) */

	/* bits 765: nature of address indicator */
	/*	000  unknown */
	/*	001  international number */
	/*	010  national significant number */
	/*	011  network specific number */
	/*	100  subscriber number */
	/*	101  reserved */
	/*	110  abbreviated number */
	/*	111  reserved for extension */

	/* bits 4321: numbering plan indicator */
	/*	0000  unknown */
	/*	0001  ISDN/Telephony Numbering Plan (Rec CCITT E.164) */
	/*	0010  spare */
	/*	0011  data numbering plan (CCITT Rec X.121) */
	/*	0100  telex numbering plan (CCITT Rec F.69) */
	/*	0101  spare */
	/*	0110  land mobile numbering plan (CCITT Rec E.212) */
	/*	0111  spare */
	/*	1000  national numbering plan */
	/*	1001  private numbering plan */
	/*	1111  reserved for extension */

	/*	all other values are reserved. */

	/* b)	The following octets representing digits of an address */
	/*		encoded as a TBCD-STRING. */
extern const int maxAddressLength;

	/* This type is used to represent ISDN numbers. */
extern const int maxISDN_AddressLength;

	/* This type is used to represent forwarded-to numbers. */
extern const int maxFTN_AddressLength;

	/* This type is used to represent ISDN subaddresses. */
	/* It is composed of */
	/*	a)	one octet for type of subaddress and odd/even indicator. */
	/*	b)	20 octets for subaddress information. */

	/*	a)	The first octet includes a one bit extension indicator, a */
	/*		3 bits type of subaddress and a one bit odd/even indicator, */
	/*		encoded as follows: */

	/*	bit 8: 1  (no extension) */

	/*	bits 765: type of subaddress */
	/*		000  NSAP (X.213/ISO 8348 AD2) */
	/*		010  User Specified */
	/*		All other values are reserved */

	/*	bit 4: odd/even indicator */
	/*		0  even number of address signals */
	/*		1  odd number of address signals */
	/*		The odd/even indicator is used when the type of subaddress */
	/*		is "user specified" and the coding is BCD. */

	/*	bits 321: 000 (unused) */

	/*	b) Subaddress information. */
	/*	The NSAP X.213/ISO8348AD2 address shall be formatted as specified */
	/*	by octet 4 which contains the Authority and Format Identifier */
	/*	(AFI). The encoding is made according to the "preferred binary */
	/*	encoding" as defined in X.213/ISO834AD2. For the definition */
	/*	of this type of subaddress, see CCITT Rec I.334. */

	/*	For User-specific subaddress, this field is encoded according */
	/*	to the user specification, subject to a maximum length of 20 */
	/*	octets. When interworking with X.25 networks BCD coding should */
	/*	be applied. */
extern const int MAP_CommonDataTypes_maxISDN_SubaddressLength;

extern const int maxSignalInfoLength;

	/* This type is used to represent Alerting Pattern */

	/*	bits 8765 : 0000 (unused) */

	/*	bits 43 : type of Pattern */
	/*		00 level */
	/*		01 category */
	/*		10 category */
	/*		all other values are reserved. */

	/*	bits 21 : type of alerting */
extern AlertingPattern alertingLevel_0;

extern AlertingPattern alertingLevel_1;

extern AlertingPattern alertingLevel_2;

	/* all other values of Alerting level are reserved */
	/* Alerting Levels are defined in GSM 02.07 */
extern AlertingPattern alertingCategory_1;

extern AlertingPattern alertingCategory_2;

extern AlertingPattern alertingCategory_3;

extern AlertingPattern alertingCategory_4;

extern AlertingPattern alertingCategory_5;

extern const int maxNumOfHLR_Id;

	/* The mapping from the values A,B,0,1,2,3,4 to the integer-value is */
	/* specified as follows where A is the highest and 4 is the lowest */
	/* priority level */
	/* the integer values 7-15 are spare and shall be mapped to value 4 */
extern const EMLPP_Priority priorityLevelA;

extern const EMLPP_Priority priorityLevelB;

extern const EMLPP_Priority priorityLevel0;

extern const EMLPP_Priority priorityLevel1;

extern const EMLPP_Priority priorityLevel2;

extern const EMLPP_Priority priorityLevel3;

extern const EMLPP_Priority priorityLevel4;

extern const int maxNumOfMC_Bearers;

	/* This type is used to represent the code identifying a single */
	/* teleservice, a group of teleservices, or all teleservices. The */
	/* services are defined in TS GSM 02.03. */
	/* The internal structure is defined as follows: */

	/* OCTET 1: */
	/* bits 87654321: group (bits 8765) and specific service */
	/* (bits 4321) */

	/* OCTETS 2-5: reserved for future use. If received the */
    /* Ext-TeleserviceCode shall be */
 	/* treated according to the exception handling defined for the */
	/* operation that uses this type. */

	/* Ext-TeleserviceCode includes all values defined for TeleserviceCode. */
extern TeleserviceCode allTeleservices;

extern TeleserviceCode allSpeechTransmissionServices;

extern TeleserviceCode telephony;

extern TeleserviceCode emergencyCalls;

extern TeleserviceCode allShortMessageServices;

extern TeleserviceCode shortMessageMT_PP;

extern TeleserviceCode shortMessageMO_PP;

extern TeleserviceCode allFacsimileTransmissionServices;

extern TeleserviceCode facsimileGroup3AndAlterSpeech;

extern TeleserviceCode automaticFacsimileGroup3;

extern TeleserviceCode facsimileGroup4;

/* The following non-hierarchical Compound Teleservice Groups */
/* are defined in TS GSM 02.30: */
extern TeleserviceCode allDataTeleservices;

	/* covers Teleservice Groups 'allFacsimileTransmissionServices' */
	/* and 'allShortMessageServices' */
extern TeleserviceCode allTeleservices_ExeptSMS;

	/* covers Teleservice Groups 'allSpeechTransmissionServices' and */
	/* 'allFacsimileTransmissionServices' */
/**/
/* Compound Teleservice Group Codes are only used in call */
/* independent supplementary service operations, i.e. they */
/* are not used in InsertSubscriberData or in */
/* DeleteSubscriberData messages. */
extern TeleserviceCode allVoiceGroupCallServices;

extern TeleserviceCode voiceGroupCall;

extern TeleserviceCode voiceBroadcastCall;

extern TeleserviceCode allPLMN_specificTS;

extern TeleserviceCode plmn_specificTS_1;

extern TeleserviceCode plmn_specificTS_2;

extern TeleserviceCode plmn_specificTS_3;

extern TeleserviceCode plmn_specificTS_4;

extern TeleserviceCode plmn_specificTS_5;

extern TeleserviceCode plmn_specificTS_6;

extern TeleserviceCode plmn_specificTS_7;

extern TeleserviceCode plmn_specificTS_8;

extern TeleserviceCode plmn_specificTS_9;

extern TeleserviceCode plmn_specificTS_A;

extern TeleserviceCode plmn_specificTS_B;

extern TeleserviceCode plmn_specificTS_C;

extern TeleserviceCode plmn_specificTS_D;

extern TeleserviceCode plmn_specificTS_E;

extern TeleserviceCode plmn_specificTS_F;

	/* This type is used to represent the code identifying a single */
	/* bearer service, a group of bearer services, or all bearer */
	/* services. The services are defined in TS GSM 02.02. */
	/* The internal structure is defined as follows: */
	/**/
	/* OCTET 1: */
	/* plmn-specific bearer services: */
	/* bits 87654321: defined by the HPLMN operator */
	/**/
	/* rest of bearer services: */
	/* bit 8: 0 (unused) */
	/* bits 7654321: group (bits 7654), and rate, if applicable */
	/* (bits 321) */

	/* OCTETS 2-5: reserved for future use. If received the */
    /* Ext-TeleserviceCode shall be */
	/* treated according to the exception handling defined for the */
	/* operation that uses this type. */

	/* Ext-BearerServiceCode includes all values defined for BearerServiceCode. */
extern BearerServiceCode allBearerServices;

extern BearerServiceCode allDataCDA_Services;

extern BearerServiceCode dataCDA_300bps;

extern BearerServiceCode dataCDA_1200bps;

extern BearerServiceCode dataCDA_1200_75bps;

extern BearerServiceCode dataCDA_2400bps;

extern BearerServiceCode dataCDA_4800bps;

extern BearerServiceCode dataCDA_9600bps;

extern BearerServiceCode general_dataCDA;

extern BearerServiceCode allDataCDS_Services;

extern BearerServiceCode dataCDS_1200bps;

extern BearerServiceCode dataCDS_2400bps;

extern BearerServiceCode dataCDS_4800bps;

extern BearerServiceCode dataCDS_9600bps;

extern BearerServiceCode general_dataCDS;

extern BearerServiceCode allPadAccessCA_Services;

extern BearerServiceCode padAccessCA_300bps;

extern BearerServiceCode padAccessCA_1200bps;

extern BearerServiceCode padAccessCA_1200_75bps;

extern BearerServiceCode padAccessCA_2400bps;

extern BearerServiceCode padAccessCA_4800bps;

extern BearerServiceCode padAccessCA_9600bps;

extern BearerServiceCode general_padAccessCA;

extern BearerServiceCode allDataPDS_Services;

extern BearerServiceCode dataPDS_2400bps;

extern BearerServiceCode dataPDS_4800bps;

extern BearerServiceCode dataPDS_9600bps;

extern BearerServiceCode general_dataPDS;

extern BearerServiceCode allAlternateSpeech_DataCDA;

extern BearerServiceCode allAlternateSpeech_DataCDS;

extern BearerServiceCode allSpeechFollowedByDataCDA;

extern BearerServiceCode allSpeechFollowedByDataCDS;

/* The following non-hierarchical Compound Bearer Service */
/* Groups are defined in TS GSM 02.30: */
extern BearerServiceCode allDataCircuitAsynchronous;

	/* covers "allDataCDA-Services", "allAlternateSpeech-DataCDA" and */
	/* "allSpeechFollowedByDataCDA" */
extern BearerServiceCode allAsynchronousServices;

	/* covers "allDataCDA-Services", "allAlternateSpeech-DataCDA", */
	/* "allSpeechFollowedByDataCDA" and "allPadAccessCDA-Services" */
extern BearerServiceCode allDataCircuitSynchronous;

	/* covers "allDataCDS-Services", "allAlternateSpeech-DataCDS" and */
	/* "allSpeechFollowedByDataCDS" */
extern BearerServiceCode allSynchronousServices;

	/* covers "allDataCDS-Services", "allAlternateSpeech-DataCDS", */
	/* "allSpeechFollowedByDataCDS" and "allDataPDS-Services" */
/**/
/* Compound Bearer Service Group Codes are only used in call */
/* independent supplementary service operations, i.e. they */
/* are not used in InsertSubscriberData or in */
/* DeleteSubscriberData messages. */
extern BearerServiceCode allPLMN_specificBS;

extern BearerServiceCode plmn_specificBS_1;

extern BearerServiceCode plmn_specificBS_2;

extern BearerServiceCode plmn_specificBS_3;

extern BearerServiceCode plmn_specificBS_4;

extern BearerServiceCode plmn_specificBS_5;

extern BearerServiceCode plmn_specificBS_6;

extern BearerServiceCode plmn_specificBS_7;

extern BearerServiceCode plmn_specificBS_8;

extern BearerServiceCode plmn_specificBS_9;

extern BearerServiceCode plmn_specificBS_A;

extern BearerServiceCode plmn_specificBS_B;

extern BearerServiceCode plmn_specificBS_C;

extern BearerServiceCode plmn_specificBS_D;

extern BearerServiceCode plmn_specificBS_E;

extern BearerServiceCode plmn_specificBS_F;

extern const int maxNumOfPrivateExtensions;

extern ObjectID ktf_origservicetype_id;

extern MAP_EXTENSION ktf_origservicetype;

extern ObjectID ktf_destservicetype_id;

extern MAP_EXTENSION ktf_destservicetype;

extern ObjectID ktf_extmsisdn_id;

extern MAP_EXTENSION ktf_extmisdntype;

extern ObjectID ktf_extoriginalnum_id;

extern MAP_EXTENSION ktf_extoriginalnumtype;

extern ObjectID ktf_showregion_id;

extern MAP_EXTENSION ktf_showregiontype;

extern ObjectID ktf_ueindicator;

extern MAP_EXTENSION ktf_uetype;

extern ObjectID kt_roamparty;

extern MAP_EXTENSION ktRoamParty;

extern ObjectID kt_IpsmgwSvcInfo;

extern MAP_EXTENSION ktIpsmgwSvcType;

extern ObjectID kt_DestAddrForSMData;

extern MAP_EXTENSION ktDestAddrForSM;

extern ObjectID kt_RetryIndForSM;

extern MAP_EXTENSION ktRetryIndForSM;

extern ObjectID ktBarringReason;

extern MAP_EXTENSION ktfBarringServiceReason;

extern ObjectID skmin_id;

extern MAP_EXTENSION skminExt;

extern ObjectID skesn_id;

extern MAP_EXTENSION skesnExt;

extern ObjectID sKSmsCapa_id;

extern MAP_EXTENSION sKSmsCapaExt;

extern ObjectID sKOriginatingSFI_id;

extern MAP_EXTENSION skOriginatingSFIExt;

extern ObjectID sKTSMSRoamingIndicator_id;

extern MAP_EXTENSION sKTSMSRoamingIndicatorExt;

extern ObjectID sKTSMSAccessDeniedReason_id;

extern MAP_EXTENSION sKTSMSAccessDeniedReasonExt;

extern ObjectID sKTSMSRoamingPMN_id;

extern MAP_EXTENSION sKTSMSRoamingPMNExt;

extern ObjectID secondaryMSISDN_id;

extern MAP_EXTENSION secondaryMSISDN;

	/* Mobile DomainId */
extern ObjectID mobileDomainId;

	/* Mobile Subdomains */
extern ObjectID gsm_NetworkId;

extern ObjectID gsm_AccessId;

extern ObjectID gsm_OperationAndMaintenanceId;

extern ObjectID gsm_MessagingId;

extern const CommonComponentId ac_Id;

extern const CommonComponentId as_Id;

extern const CommonComponentId ase_Id;

extern const CommonComponentId moduleId;

extern const CommonComponentId er_Id;

/* EXPORTS everything */
/* application-context-names */
extern ObjectID map_ac;

extern ObjectID shortMsgGatewayContext_v3;

extern ObjectID shortMsgGatewayContext_v2;

extern ObjectID shortMsgMO_RelayContext_v3;

extern ObjectID shortMsgMO_RelayContext_v2;

extern ObjectID shortMsgMT_RelayContext_v3;

extern ObjectID shortMsgMT_RelayContext_v2;

extern ObjectID shortMsgAlertContext_v2;

extern ObjectID mwdMngtContext_v3;

extern ObjectID mwdMngtContext_v2;

/* short message service operation codes */
extern SendRoutingInfoForSM_V3 sendRoutingInfoForSM_V3;

extern SendRoutingInfoForSM_V2 sendRoutingInfoForSM_V2;

extern MO_ForwardSM_V3 mo_forwardSM_V3;

extern MT_ForwardSM_V3 mt_forwardSM_V3;

extern ReportSM_DeliveryStatus_V3 reportSM_DeliveryStatus_V3;

extern ReportSM_DeliveryStatus_V2 reportSM_DeliveryStatus_V2;

extern InformServiceCentre_V3 informServiceCentre_V3;

extern InformServiceCentre_V2 informServiceCentre_V2;

extern ReadyForSM readyForSM;

extern ForwardSM_V2 forwardSM_V2;

extern AlertServiceCentre alertServiceCentre;

/* generic error codes */
extern SystemFailure systemFailure;

extern DataMissing dataMissing;

extern UnexpectedDataValue unexpectedDataValue;

extern FacilityNotSupported facilityNotSupported;

extern IncompatibleTerminal incompatibleTerminal;

extern ResourceLimitation resourceLimitation;

/* identification and numbering error codes */
extern UnknownSubscriber unknownSubscriber;

extern NumberChanged numberChanged;

extern UnknownMSC unknownMSC;

extern UnidentifiedSubscriber unidentifiedSubscriber;

extern UnknownEquipment unknownEquipment;

/* subscription error codes */
extern RoamingNotAllowed roamingNotAllowed;

extern IllegalSubscriber illegalSubscriber;

extern IllegalEquipment illegalEquipment;

extern BearerServiceNotProvisioned bearerServiceNotProvisioned;

extern TeleserviceNotProvisioned teleserviceNotProvisioned;

/* handover error codes */
extern NoHandoverNumberAvailable noHandoverNumberAvailable;

extern SubsequentHandoverFailure subsequentHandoverFailure;

extern TargetCellOutsideGroupCallArea targetCellOutsideGroupCallArea;

/* operation and maintenance error codes */
extern TracingBufferFull tracingBufferFull;

/* call handling error codes */
extern NoRoamingNumberAvailable noRoamingNumberAvailable;

extern AbsentSubscriber absentSubscriber;

extern BusySubscriber busySubscriber;

extern NoSubscriberReply noSubscriberReply;

extern CallBarred callBarred;

extern ForwardingFailed forwardingFailed;

extern OR_NotAllowed or_NotAllowed;

extern ForwardingViolation forwardingViolation;

extern CUG_Reject cug_Reject;

/* any time interrogation error codes */
extern ATI_NotAllowed ati_NotAllowed;

/* any time information handling error codes */
extern ATSI_NotAllowed atsi_NotAllowed;

extern ATM_NotAllowed atm_NotAllowed;

extern InformationNotAvailable informationNotAvailable;

/* any time modification by Charge */
extern AnyTimeModification anyTimeModification;

/* Group Call error codes */
extern NoGroupCallNumberAvailable noGroupCallNumberAvailable;

/* supplementary service error codes */
extern IllegalSS_Operation illegalSS_Operation;

extern SS_ErrorStatus ss_ErrorStatus;

extern SS_NotAvailable ss_NotAvailable;

extern SS_SubscriptionViolation ss_SubscriptionViolation;

extern SS_Incompatibility ss_Incompatibility;

extern UnknownAlphabet unknownAlphabet;

extern USSD_Busy ussd_Busy;

extern PW_RegistrationFailure pw_RegistrationFailure;

extern NegativePW_Check negativePW_Check;

extern NumberOfPW_AttemptsViolation numberOfPW_AttemptsViolation;

extern ShortTermDenial shortTermDenial;

extern LongTermDenial longTermDenial;

/* short message service error codes */
extern SubscriberBusyForMT_SMS subscriberBusyForMT_SMS;

extern SM_DeliveryFailure sm_DeliveryFailure;

extern MessageWaitingListFull messageWaitingListFull;

extern AbsentSubscriberSM absentsubscriberSM;

/* location service error codes */
extern UnauthorizedRequestingNetwork unauthorizedRequestingNetwork;

extern UnauthorizedLCSClient unauthorizedLCSClient;

extern PositionMethodFailure positionMethodFailure;

extern UnknownOrUnreachableLCSClient unknownOrUnreachableLCSClient;

/* Mobility Management error codes */
extern MM_EventNotSupported mm_EventNotSupported;

/* Secure transport error codes */
extern SecureTransportError secureTransportError;
/* The following operation codes are reserved for operations */
/* existing in previous versions of the protocol */

/* Operation Name	AC used	Oper. Code */
/* */
/* sendParameters	map-ac infoRetrieval (14) version1 (1)	localValue:9 */
/* processUnstructuredSS-Data	map-ac networkFunctionalSs (18) version1 (1)	localValue:19 */
/* performHandover	map-ac handoverControl (11) version1 (1)	localValue:28 */
/* performSubsequentHandover	map-ac handoverControl (11) version1 (1)	localValue:30 */
/* noteInternalHandover	map-ac handoverControl (11) version1 (1)	localValue:35 */
/* noteSubscriberPresent	map-ac mwdMngt (24) version1 (1)	localValue:48 */
/* traceSubscriberActivity	map-ac handoverControl (11) version1 (1)	localValue:52 */
/* beginSubscriberActivity	map-ac networkFunctionalSs (18) version1 (1)	localValue:54 */

/* The following error codes are reserved for errors */
/* existing in previous versions of the protocol */

/* Error Name	AC used	Error Code */
/* */
/* unknownBaseStation	map-ac handoverControl (11) version1 (1)	localValue:2 */
/* invalidTargetBaseStation	map-ac handoverControl (11) version1 (1)	localValue:23 */
/* noRadioResourceAvailable	map-ac handoverControl (11) version1 (1)	localValue:24 */

#endif  /* #ifndef _OSSNOVALUES */


extern void * const map_protocol;    /* encoder-decoder control table */
#endif /* OSS_map_protocol */
