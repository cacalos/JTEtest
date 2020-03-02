/*************************************************************/
/* Copyright (C) 2017 OSS Nokalva, Inc.  All rights reserved.*/
/*************************************************************/

/* THIS FILE IS PROPRIETARY MATERIAL OF OSS NOKALVA, INC.
 * AND MAY BE USED ONLY BY DIRECT LICENSEES OF OSS NOKALVA, INC.
 * THIS FILE MAY NOT BE DISTRIBUTED. */

/* Generated for: UANGEL Corporation, Sungnam-shi, Korea - license 8634 for Solaris */
/* Abstract syntax: map_protocol */
/* Created: Thu Mar  9 13:36:24 2017 */
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
 * app_context.asn skwin.asn gmap.asn map_protocol.asn
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
#define          AnalyzedInformationArg_PDU 198
#define          AnalyzedInformationRes_PDU 199
#define          SeizeResourceArg_PDU 200
#define          SeizeResourceRes_PDU 201
#define          PageRequestArg_PDU 202
#define          PageRequestRes_PDU 203
#define          CallStateRequestArg_PDU 204
#define          CallStateRequestRes_PDU 205
#define          ConnectResourceArg_PDU 206
#define          SRFDirectiveArg_PDU 207
#define          SRFDirectiveRes_PDU 208
#define          CallResultReportArg_PDU 209
#define          ConnectionFailureReportArg_PDU 210
#define          WinResetTimerArg_PDU 211
#define          CallControlDirectiveArg_PDU 212
#define          CallControlDirectiveRes_PDU 213
#define          WIN_TriggerList_PDU 214
#define          RegistrationNotificationArg_PDU 215
#define          RegistrationNotificationRes_PDU 216
#define          RegistrationCancellationArg_PDU 217
#define          RegistrationCancellationRes_PDU 218
#define          LocationRequestArg_PDU 219
#define          LocationRequestRes_PDU 220
#define          RoutingRequestArg_PDU 221
#define          RoutingRequestRes_PDU 222
#define          FeatureRequestArg_PDU 223
#define          FeatureRequestRes_PDU 224
#define          AuthenticationDirectiveArg_PDU 225
#define          AuthenticationDirectiveRes_PDU 226
#define          AuthenticationRequestArg_PDU 227
#define          AuthenticationRequestRes_PDU 228
#define          BaseStationChallengeArg_PDU 229
#define          BaseStationChallengeRes_PDU 230
#define          AuthenticationStatusReportArg_PDU 231
#define          AuthenticationStatusReportRes_PDU 232
#define          CountRequestArg_PDU 233
#define          CountRequestRes_PDU 234
#define          GMapAuthenticationFailureReportArg_PDU 235
#define          GMapAuthenticationFailureReportRes_PDU 236
#define          MobilePositionCapability_PDU 237
#define          OriginationRequestArg_PDU 238
#define          OriginationRequestRes_PDU 239
#define          RemoteUserInteractionDirectiveArg_PDU 240
#define          RemoteUserInteractionDirectiveRes_PDU 241
#define          InformationDirectiveArg_PDU 242
#define          InformationDirectiveRes_PDU 243
#define          TransferToNumberRequestArg_PDU 244
#define          TransferToNumberRequestRes_PDU 245
#define          MSInactiveArg_PDU 246
#define          MSInactiveRes_PDU 247
#define          UnreliableRoamerDataDirectiveArg_PDU 248
#define          QualificationRequestArg_PDU 249
#define          QualificationRequestRes_PDU 250
#define          QualificationDirectiveArg_PDU 251
#define          QualificationDirectiveRes_PDU 252
#define          OTASPRequestArg_PDU 253
#define          OTASPRequestRes_PDU 254
#define          GMapActivateTraceModeArg_PDU 255
#define          GMapActivateTraceModeRes_PDU 256
#define          GMapDeactivateTraceModeArg_PDU 257
#define          GMapDeactivateTraceModeRes_PDU 258
#define          ReportTraceSubscriberActivityArg_PDU 259
#define          ReportTraceSubscriberActivityRes_PDU 260
#define          TraceStateNotificationArg_PDU 261
#define          TraceStateNotificationRes_PDU 262
#define          ServiceRequestArg_PDU 263
#define          ServiceRequestRes_PDU 264
#define          ServiceInfoDirectiveArg_PDU 265
#define          TiisErrorReportArg_PDU 266
#define          MailProfileDirectiveArg_PDU 267
#define          MailProfileDirectiveRes_PDU 268
#define          MailStateNotificationArg_PDU 269
#define          MailStateNotificationRes_PDU 270
#define          CallDataRequestArg_PDU 271
#define          CallDataRequestRes_PDU 272
#define          LocationVerificationArg_PDU 273
#define          LocationVerificationRes_PDU 274
#define          LCSParameterRequestArg_PDU 275
#define          LCSParameterRequestRes_PDU 276
#define          InterSystemPositionRequestArg_PDU 277
#define          InterSystemPositionRequestRes_PDU 278
#define          GeoPositionRequestArg_PDU 279
#define          GeoPositionRequestRes_PDU 280
#define          NumberPortabilityRequestArg_PDU 281
#define          NumberPortabilityRequestRes_PDU 282
#define          GMapSmsReqArg_PDU 283
#define          GMapSmsReqRes_PDU 284
#define          GMapSmsNotArg_PDU 285
#define          GMapSmsDppArg_PDU 286
#define          GMapSmsDppRes_PDU 287
#define          GMapGwSmsDppArg_PDU 288
#define          GMapGwSmsDppRes_PDU 289
#define          GMapGwSmsNotiArg_PDU 290
#define          GMapGwSmsNotiRes_PDU 291
#define          GMapGwSmppArg_PDU 292
#define          GMapGwSmppRes_PDU 293
#define          KtRoamingIndForSM_null_PDU 294
#define          KtReportSMRelayIndForSM_null_PDU 295
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
typedef struct TCAPMessages_ReturnResult {
    unsigned char   bit_mask;
#       define      result_present 0x80
    InvokeIdType    invokeID;
    struct {
        TCAPMessages_OperationCode operationCode;
        Any             parameter;
    } result;  /* optional; set in bit_mask result_present if present */
} TCAPMessages_ReturnResult;

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
        TCAPMessages_ReturnResult returnResultLast;  /* to choose, set choice to
                                                   * returnResultLast_chosen */
        ReturnError     returnError;  /* to choose, set choice to
                                       * Component_returnError_chosen */
        TCAPMessages_Reject reject;  /* to choose, set choice to
                                      * reject_chosen */
        TCAPMessages_ReturnResult returnResultNotLast;  /* to choose, set choice
                                             * to returnResultNotLast_chosen */
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

typedef struct MAP_SS_DataTypes_ServiceIndicator {
    unsigned short  length;  /* number of significant bits */
    unsigned char   *value;
} MAP_SS_DataTypes_ServiceIndicator;
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
#       define      CCBS_Data_serviceIndicator_present 0x80
    CCBS_Feature    ccbs_Feature;
    ISDN_AddressString translatedB_Number;
    MAP_SS_DataTypes_ServiceIndicator serviceIndicator;  /* optional; set in
                                   * bit_mask CCBS_Data_serviceIndicator_present
                                   * if present */
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
/*	DiameterIdentity, */
/*	Time, */
/*	NetworkNodeDiameterAddress, */
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
#       define      ModificationRequestFor_CB_Info_password_present 0x20
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
                           * ModificationRequestFor_CB_Info_password_present if
                           * present */
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

	/* this parameter contains an address field which is encoded */
	/* as defined in GSM 03.40. An address field contains 3 elements : */
	/* 		address-length */
	/* 		type-of-address */
	/* 		address-value */
typedef enum SM_DeliveryNotIntended {
    onlyIMSI_requested = 0,
    onlyMCC_MNC_requested = 1
} SM_DeliveryNotIntended;

	/*	Refers to International Mobile Station Equipment Identity */
	/*	and Software Version Number (SVN) defined in TS GSM 03.03. */
	/*	If the SVN is not present the last octet shall contain the */
	/*	digit 0 and a filler. */
	/*	If present the SVN shall be included in the last octet. */
typedef IMSI            HLR_Id;

typedef struct SIP_URI {
    unsigned int    length;
    unsigned char   *value;
} SIP_URI;

typedef struct CorrelationID {
    unsigned char   bit_mask;
#       define      hlr_id_present 0x80
#       define      sip_uri_A_present 0x40
    HLR_Id          hlr_id;  /* optional; set in bit_mask hlr_id_present if
                              * present */
    SIP_URI         sip_uri_A;  /* optional; set in bit_mask sip_uri_A_present
                                 * if present */
    SIP_URI         sip_uri_B;
} CorrelationID;

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//*- */
typedef struct RoutingInfoForSM_Arg_V3 {
    unsigned short  bit_mask;
#       define      RoutingInfoForSM_Arg_V3_extensionContainer_present 0x8000
#       define      RoutingInfoForSM_Arg_V3_gprsSupportIndicator_present 0x4000
#       define      sm_RP_MTI_present 0x2000
#       define      sm_RP_SMEA_present 0x1000
#       define      sm_deliveryNotIntended_present 0x0800
#       define      ip_sm_gwGuidanceIndicator_present 0x0400
#       define      RoutingInfoForSM_Arg_V3_imsi_present 0x0200
#       define      t4_Trigger_Indicator_present 0x0100
#       define      RoutingInfoForSM_Arg_V3_singleAttemptDelivery_present 0x0080
#       define      RoutingInfoForSM_Arg_V3_correlationID_present 0x0040
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
    SM_DeliveryNotIntended sm_deliveryNotIntended;  /* extension #4; optional;
                                   * set in bit_mask
                                   * sm_deliveryNotIntended_present if
                                   * present */
    Nulltype        ip_sm_gwGuidanceIndicator;  /* extension #5; optional; set
                                   * in bit_mask
                                   * ip_sm_gwGuidanceIndicator_present if
                                   * present */
    IMSI            imsi;  /* extension #6; optional; set in bit_mask
                            * RoutingInfoForSM_Arg_V3_imsi_present if present */
    Nulltype        t4_Trigger_Indicator;  /* extension #7; optional; set in
                                   * bit_mask t4_Trigger_Indicator_present if
                                   * present */
    Nulltype        singleAttemptDelivery;  /* extension #8; optional; set in
                                   * bit_mask
                     * RoutingInfoForSM_Arg_V3_singleAttemptDelivery_present if
                     * present */
    CorrelationID   correlationID;  /* extension #9; optional; set in bit_mask
                             * RoutingInfoForSM_Arg_V3_correlationID_present if
                             * present */
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

typedef struct DiameterIdentity {
    unsigned short  length;
    unsigned char   value[255];
} DiameterIdentity;

		/* Octets are coded according to IETF RFC 3588 [139] */
typedef struct NetworkNodeDiameterAddress {
    DiameterIdentity diameter_Name;
    DiameterIdentity diameter_Realm;
} NetworkNodeDiameterAddress;

typedef struct LocationInfoWithLMSI_V3 {
    unsigned short  bit_mask;
#       define      LocationInfoWithLMSI_V3_lmsi_present 0x8000
#       define      LocationInfoWithLMSI_V3_extensionContainer_present 0x4000
#       define      gprsNodeIndicator_present 0x2000
#       define      additional_Number_present 0x1000
#       define      networkNodeDiameterAddress_present 0x0800
#       define      additionalNetworkNodeDiameterAddress_present 0x0400
#       define      thirdNumber_present 0x0200
#       define      thirdNetworkNodeDiameterAddress_present 0x0100
#       define      imsNodeIndicator_present 0x0080
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
    NetworkNodeDiameterAddress networkNodeDiameterAddress;  /* extension #3;
                                   * optional; set in bit_mask
                                   * networkNodeDiameterAddress_present if
                                   * present */
    NetworkNodeDiameterAddress additionalNetworkNodeDiameterAddress;  
                                  /* extension #4; optional; set in bit_mask
                              * additionalNetworkNodeDiameterAddress_present if
                              * present */
    Additional_Number thirdNumber;  /* extension #5; optional; set in bit_mask
                                     * thirdNumber_present if present */
    NetworkNodeDiameterAddress thirdNetworkNodeDiameterAddress;  /* extension
                                   * #6; optional; set in bit_mask
                                   * thirdNetworkNodeDiameterAddress_present if
                                   * present */
    Nulltype        imsNodeIndicator;  /* extension #7; optional; set in
                                   * bit_mask imsNodeIndicator_present if
                                   * present */
	/* gprsNodeIndicator and imsNodeIndicator shall not both be present. */
	/* additionalNumber and thirdNumber shall not both contain the same type of number */
} LocationInfoWithLMSI_V3;

			/* octets are coded as defined in IETF RFC 3261 */
typedef unsigned short  SM_DeliveryTimerValue;

typedef struct IP_SM_GW_Guidance {
    unsigned char   bit_mask;
#       define      IP_SM_GW_Guidance_extensionContainer_present 0x80
    SM_DeliveryTimerValue minimumDeliveryTimeValue;
    SM_DeliveryTimerValue recommendedDeliveryTimeValue;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                              * IP_SM_GW_Guidance_extensionContainer_present if
                              * present */
} IP_SM_GW_Guidance;

typedef struct RoutingInfoForSM_Res_V3 {
    unsigned char   bit_mask;
#       define      RoutingInfoForSM_Res_V3_extensionContainer_present 0x80
#       define      ip_sm_gwGuidance_present 0x40
    IMSI            imsi;
    LocationInfoWithLMSI_V3 locationInfoWithLMSI_V3;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                        * RoutingInfoForSM_Res_V3_extensionContainer_present if
                        * present */
    IP_SM_GW_Guidance ip_sm_gwGuidance;  /* extension #1; optional; set in
                                   * bit_mask ip_sm_gwGuidance_present if
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

typedef enum SM_DeliveryOutcome {
    SM_DeliveryOutcome_memoryCapacityExceeded = 0,
    SM_DeliveryOutcome_absentSubscriber = 1,
    successfulTransfer = 2
} SM_DeliveryOutcome;

	/* additional-number can be either msc-number or sgsn-number */
	/* if received networkNode-number is msc-number then the 	*/
	/* additional number is sgsn-number */
	/* if received networkNode-number is sgsn-number then the */
	/* additional number is msc-number */
typedef struct MO_ForwardSM_Arg_V3 {
    unsigned char   bit_mask;
#       define      MO_ForwardSM_Arg_V3_extensionContainer_present 0x80
#       define      MO_ForwardSM_Arg_V3_imsi_present 0x40
#       define      MO_ForwardSM_Arg_V3_correlationID_present 0x20
#       define      MO_ForwardSM_Arg_V3_sm_DeliveryOutcome_present 0x10
    SM_RP_DA        sm_RP_DA;
    SM_RP_OA        sm_RP_OA;
    SignalInfo      sm_RP_UI;
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                            * MO_ForwardSM_Arg_V3_extensionContainer_present if
                            * present */
    IMSI            imsi;  /* extension #1; optional; set in bit_mask
                            * MO_ForwardSM_Arg_V3_imsi_present if present */
    CorrelationID   correlationID;  /* extension #2; optional; set in bit_mask
                                     * MO_ForwardSM_Arg_V3_correlationID_present
                                     * if present */
    SM_DeliveryOutcome sm_DeliveryOutcome;  /* extension #3; optional; set in
                                   * bit_mask
                            * MO_ForwardSM_Arg_V3_sm_DeliveryOutcome_present if
                            * present */
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

	/* content of DiameterIdentity is defined in IETF RFC 3588 [139] */
typedef struct Time {
    unsigned short  length;
    unsigned char   value[4];
} Time;

typedef struct MT_ForwardSM_Arg_V3 {
    unsigned char   bit_mask;
#       define      MT_ForwardSM_Arg_V3_moreMessagesToSend_present 0x80
#       define      MT_ForwardSM_Arg_V3_extensionContainer_present 0x40
#       define      smDeliveryTimer_present 0x20
#       define      smDeliveryStartTime_present 0x10
#       define      smsOverIP_OnlyIndicator_present 0x08
#       define      MT_ForwardSM_Arg_V3_correlationID_present 0x04
#       define      maximumRetransmissionTime_present 0x02
    SM_RP_DA        sm_RP_DA;
    SM_RP_OA        sm_RP_OA;
    SignalInfo      sm_RP_UI;
    Nulltype        moreMessagesToSend;  /* optional; set in bit_mask
                            * MT_ForwardSM_Arg_V3_moreMessagesToSend_present if
                            * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                            * MT_ForwardSM_Arg_V3_extensionContainer_present if
                            * present */
    SM_DeliveryTimerValue smDeliveryTimer;  /* extension #1; optional; set in
                                   * bit_mask smDeliveryTimer_present if
                                   * present */
    Time            smDeliveryStartTime;  /* extension #2; optional; set in
                                   * bit_mask smDeliveryStartTime_present if
                                   * present */
    Nulltype        smsOverIP_OnlyIndicator;  /* extension #3; optional; set in
                                   * bit_mask smsOverIP_OnlyIndicator_present if
                                   * present */
    CorrelationID   correlationID;  /* extension #4; optional; set in bit_mask
                                     * MT_ForwardSM_Arg_V3_correlationID_present
                                     * if present */
    Time            maximumRetransmissionTime;  /* extension #5; optional; set
                                   * in bit_mask
                                   * maximumRetransmissionTime_present if
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
#       define      requestedRetransmissionTime_present 0x20
    SignalInfo      sm_RP_UI;  /* optional; set in bit_mask
                                * MT_ForwardSM_Res_V3_sm_RP_UI_present if
                                * present */
    ExtensionContainer extensionContainer;  /* optional; set in bit_mask
                            * MT_ForwardSM_Res_V3_extensionContainer_present if
                            * present */
    Time            requestedRetransmissionTime;  /* extension #1; optional; set
                                   * in bit_mask
                                   * requestedRetransmissionTime_present if
                                   * present */
} MT_ForwardSM_Res_V3;

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
#       define      ReportSM_DeliveryStatusArg_V3_singleAttemptDelivery_present 0x0020
#       define      ReportSM_DeliveryStatusArg_V3_correlationID_present 0x0010
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
    Nulltype        singleAttemptDelivery;  /* extension #9; optional; set in
                                   * bit_mask
               * ReportSM_DeliveryStatusArg_V3_singleAttemptDelivery_present if
               * present */
    CorrelationID   correlationID;  /* extension #10; optional; set in bit_mask
                       * ReportSM_DeliveryStatusArg_V3_correlationID_present if
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
#       define      ReportSM_DeliveryStatusArg_V2_sm_DeliveryOutcome_present 0x80
    ISDN_AddressString msisdn;
    AddressString   serviceCentreAddress;
    SM_DeliveryOutcome sm_DeliveryOutcome;  /* optional; set in bit_mask
                  * ReportSM_DeliveryStatusArg_V2_sm_DeliveryOutcome_present if
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
#define                     unri_Set 0x0800

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

/* v600 end of added */

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

typedef struct BCDDigits {
    unsigned short  length;
    unsigned char   value[20];
} BCDDigits;

typedef struct PartyName {
    unsigned short  length;
    unsigned char   value[17];
} PartyName;

typedef struct Subaddress {
    unsigned short  length;
    unsigned char   value[21];
} Subaddress;

typedef struct BillingID {
    unsigned short  length;
    unsigned char   value[7];
} BillingID; /* 0x81 */

/* change parameter name of 'Digits' to 'WinDigits' because it conflicts with CAMEL */
typedef BCDDigits       WinDigits; /* 0x84 */

typedef struct MSCID {
    unsigned short  length;
    unsigned char   value[3];
} MSCID; /* 0x95 */

typedef struct TransactionCapability {
    unsigned short  length;
    unsigned char   value[2];
} TransactionCapability; /* 9f7b */

typedef struct TriggerType {
    unsigned short  length;
    unsigned char   value[1];
} TriggerType; /* 9f8217 */

typedef struct TriggerCapability {
    unsigned short  length;
    unsigned char   value[3];
} TriggerCapability; /* 9f8215 */

typedef struct DetectionPointType {
    unsigned short  length;
    unsigned char   value[1];
} DetectionPointType; /* 9f8201 */

typedef struct WINOperationsCapability {
    unsigned short  length;
    unsigned char   value[2];
} WINOperationsCapability; /* 9f8219 */

typedef struct WINCapability {    /* bf8218 */
    TriggerCapability triggerCapability;
    WINOperationsCapability winOperationsCapability;
} WINCapability;

typedef struct CallingPartyName {
    unsigned short  length;
    unsigned char   value[17];
} CallingPartyName;       /* 9f8173 */

/* bhtak 2002/2/26 parameter tag is not valid */
typedef BCDDigits       CallingPartyNumberDigits1; /* 9f50 */

typedef BCDDigits       CallingPartyNumberDigits2; /* 9f51 */

/* CallingPartyNumberDigits1	::= [ 81 ] BCDDigits 9f51 */
/* CallingPartyNumberDigits2	::= [ 16381 ] BCDDigits 9fff7d */
typedef Subaddress      CallingPartySubaddress; /* 9f54 */

typedef struct ConferenceCallingIndicator {
    unsigned short  length;
    unsigned char   value[1];
} ConferenceCallingIndicator; /* 9f8109 */

typedef struct SystemMyTypeCode {
    unsigned short  length;
    unsigned char   value[1];
} SystemMyTypeCode; /* 96 */

typedef struct ElectronicSerialNumber {
    unsigned short  length;
    unsigned char   value[4];
} ElectronicSerialNumber; /* 89 */

typedef struct LocationAreaID {
    unsigned short  length;
    unsigned char   value[2];
} LocationAreaID; /* 9f21 */

typedef BCDDigits       MobileDirectoryNumber; /* 9f5d */

typedef struct MobileIdentificationNumber {
    unsigned short  length;
    unsigned char   value[5];
} MobileIdentificationNumber; /* 88 */

typedef BCDDigits       MSCIdentificationNumber; /* 9f5e */

typedef struct OneTimeFeatureIndicator {
    unsigned short  length;
    unsigned char   value[6];
} OneTimeFeatureIndicator; /* 9f61 */

typedef enum PreferredLanguageIndicator { /* 9f8113 */
    PreferredLanguageIndicator_unspecified = 0,
    english = 1,
    french = 2,
    spanish = 3,
    german = 4,
    portuguese = 5,
    korean = 6,
    japanese = 7
} PreferredLanguageIndicator;

typedef BCDDigits       RedirectingNumberDigits; /* 9f64 */

typedef PartyName       RedirectingPartyName; /* 9f8175 */

typedef Subaddress      RedirectingSubaddress; /* 9f66 */

typedef struct ServingCellID {
    unsigned short  length;
    unsigned char   value[2];
} ServingCellID; /* 82 */

typedef struct TerminatingAccessType {
    unsigned short  length;
    unsigned char   value[1];
} TerminatingAccessType; /* 9f77 */

typedef struct PC_SSN {
    unsigned short  length;
    unsigned char   value[5];
} PC_SSN; /* 9f20 */

typedef struct CallDateTime {
    unsigned short  length;
    unsigned char   value[7];
} CallDateTime; /* 9fff42 */

typedef struct CDMAServiceOption {
    unsigned short  length;
    unsigned char   value[2];
} CDMAServiceOption; /*9f812f */

/*size, value size use ?  */
/*where tag?  specific?  */
/*cap.asn me?? */

/* Opcode 0x40 */
typedef struct AnalyzedInformationArg {
    unsigned int    bit_mask;
#       define      AnalyzedInformationArg_systemMyTypeCode_present 0x80000000
#       define      AnalyzedInformationArg_electronicSerialNumber_present 0x40000000
#       define      AnalyzedInformationArg_locationAreaId_present 0x20000000
#       define      AnalyzedInformationArg_mobileIdentificationNumber_present 0x10000000
#       define      AnalyzedInformationArg_servingCellId_present 0x08000000
#       define      AnalyzedInformationArg_cdmaServiceOption_present 0x04000000
#       define      AnalyzedInformationArg_triggerType_present 0x02000000
#       define      AnalyzedInformationArg_callingPartyName_present 0x01000000
#       define      AnalyzedInformationArg_callingPartyNumberDigits1_present 0x00800000
#       define      AnalyzedInformationArg_callingPartyNumberDigits2_present 0x00400000
#       define      AnalyzedInformationArg_callingPartySubaddress_present 0x00200000
#       define      AnalyzedInformationArg_conferenceCallingIndicator_present 0x00100000
#       define      AnalyzedInformationArg_mobileDirectoryNumber_present 0x00080000
#       define      mSCIdentificationNumber_present 0x00040000
#       define      AnalyzedInformationArg_oneTimeFeatureIndicator_present 0x00020000
#       define      AnalyzedInformationArg_preferredLanguageIndicator_present 0x00010000
#       define      AnalyzedInformationArg_redirectingNumberDigits_present 0x00008000
#       define      AnalyzedInformationArg_redirectingPartyName_present 0x00004000
#       define      AnalyzedInformationArg_redirectingSubaddress_present 0x00002000
#       define      terminatingAccessType_present 0x00001000
    BillingID       billingId;     /* 0x81 */
    WinDigits       digits; /* 0x84						*/
    MSCID           mscId; /* 0x95 */
    TransactionCapability transactionCapability; /* 0x9f7b */
    WINCapability   winCapability; /* 0xbf8218 */
    SystemMyTypeCode systemMyTypeCode;  /* optional; set in bit_mask
                           * AnalyzedInformationArg_systemMyTypeCode_present if
                           * present */
                                        /* 96 */
    ElectronicSerialNumber electronicSerialNumber;  /* optional; set in bit_mask
                     * AnalyzedInformationArg_electronicSerialNumber_present if
                     * present */
                                                    /* 89 */
    LocationAreaID  locationAreaId;  /* optional; set in bit_mask
                             * AnalyzedInformationArg_locationAreaId_present if
                             * present */
                                     /* 9f21 */
    MobileIdentificationNumber mobileIdentificationNumber;  /* optional; set in
                                   * bit_mask
                 * AnalyzedInformationArg_mobileIdentificationNumber_present if
                 * present */
                                                            /* 88 */
    ServingCellID   servingCellId;  /* optional; set in bit_mask
                              * AnalyzedInformationArg_servingCellId_present if
                              * present */
                                    /* 82 */
    CDMAServiceOption cdmaServiceOption;  /* optional; set in bit_mask
                          * AnalyzedInformationArg_cdmaServiceOption_present if
                          * present */
                                          /* 9f812f	*/
    TriggerType     triggerType;  /* optional; set in bit_mask
                                   * AnalyzedInformationArg_triggerType_present
                                   * if present */
    CallingPartyName callingPartyName;  /* optional; set in bit_mask
                           * AnalyzedInformationArg_callingPartyName_present if
                           * present */
    CallingPartyNumberDigits1 callingPartyNumberDigits1;  /* optional; set in
                                   * bit_mask
                  * AnalyzedInformationArg_callingPartyNumberDigits1_present if
                  * present */
    CallingPartyNumberDigits2 callingPartyNumberDigits2;  /* optional; set in
                                   * bit_mask
                  * AnalyzedInformationArg_callingPartyNumberDigits2_present if
                  * present */
    CallingPartySubaddress callingPartySubaddress;  /* optional; set in bit_mask
                     * AnalyzedInformationArg_callingPartySubaddress_present if
                     * present */
    ConferenceCallingIndicator conferenceCallingIndicator;  /* optional; set in
                                   * bit_mask
                 * AnalyzedInformationArg_conferenceCallingIndicator_present if
                 * present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                      * AnalyzedInformationArg_mobileDirectoryNumber_present if
                      * present */
    MSCIdentificationNumber mSCIdentificationNumber;  /* optional; set in
                                   * bit_mask mSCIdentificationNumber_present if
                                   * present */
    OneTimeFeatureIndicator oneTimeFeatureIndicator;  /* optional; set in
                                   * bit_mask
                    * AnalyzedInformationArg_oneTimeFeatureIndicator_present if
                    * present */
    PreferredLanguageIndicator preferredLanguageIndicator;  /* optional; set in
                                   * bit_mask
                 * AnalyzedInformationArg_preferredLanguageIndicator_present if
                 * present */
    RedirectingNumberDigits redirectingNumberDigits;  /* optional; set in
                                   * bit_mask
                    * AnalyzedInformationArg_redirectingNumberDigits_present if
                    * present */
    RedirectingPartyName redirectingPartyName;  /* optional; set in bit_mask
                       * AnalyzedInformationArg_redirectingPartyName_present if
                       * present */
    RedirectingSubaddress redirectingSubaddress;  /* optional; set in bit_mask
                      * AnalyzedInformationArg_redirectingSubaddress_present if
                      * present */
    TerminatingAccessType terminatingAccessType;  /* optional; set in bit_mask
                                             * terminatingAccessType_present if
                                             * present */
} AnalyzedInformationArg;

typedef struct AccessDeniedReason {
    unsigned short  length;
    unsigned char   value[1];
} AccessDeniedReason;  /* 94 */

/*  AccessDeniedReason 			::= [20] ENUMERATED { */
/*	not-used(0), */
/*	unassigned-directory-number(1), */
/*	inactive(2), */
/*	busy(3), */
/*	termination-denied(4), */
/*	no-page-response(5), */
/*	unavailable(6), */
/*	service-rejected-by-ms(7), */
/*	service-rejected-by-the-system(8), */
/*	service-type-mismatch(9), */
/*	service-denied(10), */
/*	change-number(13), */
/*	auto-answer(14), */
/*	delinquent-of-stopen(15), */
/*	ported-out(-3),		*/
/* ... */
/* } */
typedef enum ActionCode {           /* 9f8100 */
    ActionCode_not_used = 0,
    continue_procesing = 1,
    disconnect_call = 2,
    disconnect_call_leg = 3,
    conference_call_drop_last_party = 4,
    bridge_legs_to_conference_call = 5,
    drop_leg_on_busy_or_routing_failure = 6,
    disconnect_all_call_leg = 7,
    attach_msc_to_otaf = 8,
    initiate_RegistrationNotification = 9,
    generate_public_encryption_values = 10,
    generate_a_key = 11,
    perform_ssdupdate_procedure = 12,
    perform_reauthentication_procedure = 13,
    release_TRN = 14,
    commit_a_key = 15,
    release_resources = 16,
    record_new_msid = 17,
    allocate_resources = 18,
    generate_authentication_signature = 19,
    do_not_wait_for_ms_user_level_response = 20
} ActionCode;

typedef struct AnnouncementCode {
    unsigned short  length;
    unsigned char   value[4];
} AnnouncementCode; /* 9f4c */

typedef struct AnnouncementList {
    unsigned short  count;
    AnnouncementCode value[2];
} AnnouncementList; /* bf8102 */

typedef BCDDigits       CarrierDigits; /* 9f56 */

typedef struct DisplayText {
    unsigned short  length;
    unsigned char   value[24];
} DisplayText; /* 9f8174 */

typedef BCDDigits       DMH_AccountCodeDigits; /* 9f810c */

typedef BCDDigits       DMH_AlternateBillingDigits; /* 9f810d */

typedef BCDDigits       DMH_BillingDigits; /* 9f810e */

typedef struct DMH_RedirectionIndicator {
    unsigned short  length;
    unsigned char   value[1];
} DMH_RedirectionIndicator; /* 9f58 */

/*DMH-RedirectionIndicator	::= [88] ENUMERATED { 9f58 */
/*  not-specified(0), */
/*  cfu(1), */
/*  cfb(2), */
/*  cfna(3), */
/*  cfo(4), */
/*  cd-unspecified(5), */
/*  cd-pstn(6), */
/*  cd-private(7), */
/*  pstn-tandem(8), */
/*  private-tandem(9), */
/*  busy(10), */
/*  inactive(11), */
/*  unassigned(12), */
/*  termination-denied(13), */
/*  cd-failure(14), */
/*  ect(15), */
/*  mah(16), */
/*  fa(17), */
/*  abandoned-callleg(18), */
/*  pca-call-refuesed(19), */
/*  sca-call-refused(20), */
/*  dialogue(21), */
/*  cfd(22), */
/*  cd-local(23), */
/*  voice-mail-retrival(24), */
/*  selective-terminatiion-billing(243), */
/*  ... */
/*} */
typedef struct NoAnswerTime {
    unsigned short  length;
    unsigned char   value[1];
} NoAnswerTime; /* 9f60 */

typedef struct ResumePIC {
    unsigned short  length;
    unsigned char   value[1];
} ResumePIC; /* 9f820a */

typedef BCDDigits       RoutingDigits; /* 9f8116 */

typedef BCDDigits       DestinationDigits; /* 9f57 */

typedef struct LegInformation {
    unsigned short  length;
    unsigned char   value[4];
} LegInformation; /* 9f8110 */

typedef enum TerminationTreatment { /*9f79 */
    TerminationTreatment_not_used = 0,
    ms_termination = 1,
    voice_mail_storage = 2,
    voice_mail_retrieval = 3,
    dialog_termination = 4
} TerminationTreatment;

typedef struct AlertCode {
    unsigned short  length;
    unsigned char   value[2];
} AlertCode; /* 9f4b */

typedef BCDDigits       VoiceMailboxPIN; /* 9f811f */

typedef BCDDigits       VoiceMailboxNumber; /* 9f8120 */

typedef struct TerminationTriggers {
    unsigned short  length;
    unsigned char   value[2];
} TerminationTriggers; /* 9f7a */

typedef struct IntersystemTermination { /* bf59 */
    unsigned short  bit_mask;
#       define      IntersystemTermination_accessDeniedReason_present 0x8000
#       define      IntersystemTermination_billingId_present 0x4000
#       define      IntersystemTermination_carrierDigits_present 0x2000
#       define      IntersystemTermination_electronicSerialNumber_present 0x1000
#       define      IntersystemTermination_legInformation_present 0x0800
#       define      IntersystemTermination_mobileDirectoryNumber_present 0x0400
#       define      IntersystemTermination_mobileIdentificationNumber_present 0x0200
#       define      IntersystemTermination_mscIdentificationNumber_present 0x0100
#       define      IntersystemTermination_routingDigits_present 0x0080
#       define      IntersystemTermination_terminationTriggers_present 0x0040
    DestinationDigits destinationDigits;
    MSCID           mscId;
    AccessDeniedReason accessDeniedReason;  /* optional; set in bit_mask
                         * IntersystemTermination_accessDeniedReason_present if
                         * present */
    BillingID       billingId;  /* optional; set in bit_mask
                                 * IntersystemTermination_billingId_present if
                                 * present */
    CarrierDigits   carrierDigits;  /* optional; set in bit_mask
                              * IntersystemTermination_carrierDigits_present if
                              * present */
    ElectronicSerialNumber electronicSerialNumber;  /* optional; set in bit_mask
                     * IntersystemTermination_electronicSerialNumber_present if
                     * present */
    LegInformation  legInformation;  /* optional; set in bit_mask
                             * IntersystemTermination_legInformation_present if
                             * present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                      * IntersystemTermination_mobileDirectoryNumber_present if
                      * present */
    MobileIdentificationNumber mobileIdentificationNumber;  /* optional; set in
                                   * bit_mask
                 * IntersystemTermination_mobileIdentificationNumber_present if
                 * present */
    MSCIdentificationNumber mscIdentificationNumber;  /* optional; set in
                                   * bit_mask
                    * IntersystemTermination_mscIdentificationNumber_present if
                    * present */
    RoutingDigits   routingDigits;  /* optional; set in bit_mask
                              * IntersystemTermination_routingDigits_present if
                              * present */
    TerminationTriggers terminationTriggers;  /* optional; set in bit_mask
                        * IntersystemTermination_terminationTriggers_present if
                        * present */
} IntersystemTermination;

typedef struct LocalTermination { /* bf5b */
    unsigned short  bit_mask;
#       define      LocalTermination_terminationTreatment_present 0x8000
#       define      LocalTermination_alertCode_present 0x4000
#       define      LocalTermination_carrierDigits_present 0x2000
#       define      LocalTermination_destinationDigits_present 0x1000
#       define      LocalTermination_legInformation_present 0x0800
#       define      LocalTermination_mobileDirectoryNumber_present 0x0400
#       define      LocalTermination_oneTimeFeatureIndicator_present 0x0200
#       define      LocalTermination_routingDigits_present 0x0100
#       define      LocalTermination_terminationTriggers_present 0x0080
#       define      voiceMailboxPin_present 0x0040
#       define      voiceMailboxNumber_present 0x0020
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    TerminationTreatment terminationTreatment;  /* optional; set in bit_mask
                             * LocalTermination_terminationTreatment_present if
                             * present */
    AlertCode       alertCode;  /* optional; set in bit_mask
                                 * LocalTermination_alertCode_present if
                                 * present */
    CarrierDigits   carrierDigits;  /* optional; set in bit_mask
                                     * LocalTermination_carrierDigits_present if
                                     * present */
    DestinationDigits destinationDigits;  /* optional; set in bit_mask
                                * LocalTermination_destinationDigits_present if
                                * present */
    LegInformation  legInformation;  /* optional; set in bit_mask
                                      * LocalTermination_legInformation_present
                                      * if present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                            * LocalTermination_mobileDirectoryNumber_present if
                            * present */
    OneTimeFeatureIndicator oneTimeFeatureIndicator;  /* optional; set in
                                   * bit_mask
                          * LocalTermination_oneTimeFeatureIndicator_present if
                          * present */
    RoutingDigits   routingDigits;  /* optional; set in bit_mask
                                     * LocalTermination_routingDigits_present if
                                     * present */
    TerminationTriggers terminationTriggers;  /* optional; set in bit_mask
                              * LocalTermination_terminationTriggers_present if
                              * present */
    VoiceMailboxPIN voiceMailboxPin;  /* optional; set in bit_mask
                                       * voiceMailboxPin_present if present */
    VoiceMailboxNumber voiceMailboxNumber;  /* optional; set in bit_mask
                                             * voiceMailboxNumber_present if
                                             * present */
} LocalTermination;

typedef struct PSTNTermination { /* bf5f*/
    unsigned char   bit_mask;
#       define      PSTNTermination_carrierDigits_present 0x80
#       define      PSTNTermination_electronicSerialNumber_present 0x40
#       define      PSTNTermination_legInformation_present 0x20
#       define      PSTNTermination_mobileIdentificationNumber_present 0x10
#       define      PSTNTermination_routingDigits_present 0x08
#       define      PSTNTermination_terminationTriggers_present 0x04
    DestinationDigits destinationDigits;
    CarrierDigits   carrierDigits;  /* optional; set in bit_mask
                                     * PSTNTermination_carrierDigits_present if
                                     * present */
    ElectronicSerialNumber electronicSerialNumber;  /* optional; set in bit_mask
                            * PSTNTermination_electronicSerialNumber_present if
                            * present */
    LegInformation  legInformation;  /* optional; set in bit_mask
                                      * PSTNTermination_legInformation_present
                                      * if present */
    MobileIdentificationNumber mobileIdentificationNumber;  /* optional; set in
                                   * bit_mask
                        * PSTNTermination_mobileIdentificationNumber_present if
                        * present */
    RoutingDigits   routingDigits;  /* optional; set in bit_mask
                                     * PSTNTermination_routingDigits_present if
                                     * present */
    TerminationTriggers terminationTriggers;  /* optional; set in bit_mask
                               * PSTNTermination_terminationTriggers_present if
                               * present */
} PSTNTermination;

typedef BCDDigits       DestinationAddress;  /* 9f6b */

typedef struct WIN_trigger { /* bf821a */
    unsigned char   bit_mask;
#       define      detectionPointType_present 0x80
    TriggerType     triggerType;
    DetectionPointType detectionPointType;  /* optional; set in bit_mask
                                             * detectionPointType_present if
                                             * present */
} WIN_trigger;

typedef struct WIN_triggerList {
    struct WIN_triggerList *next;
    WIN_trigger     value;
} *WIN_triggerList; /* bf821b */

typedef struct TerminationType { /* bf78 */
    unsigned short  choice;
#       define      intersystemTermination_chosen 1
#       define      localTermination_chosen 2
#       define      pstnTermination_chosen 3
    union {
        IntersystemTermination intersystemTermination;  /* to choose, set choice
                                          * to intersystemTermination_chosen */
        LocalTermination localTermination;  /* to choose, set choice to
                                             * localTermination_chosen */
        PSTNTermination pstnTermination;  /* to choose, set choice to
                                           * pstnTermination_chosen */
    } u;
} TerminationType;

/* TerminationList : bf78 */
typedef struct TerminationList {
    unsigned short  count;
    TerminationType value[10];
} TerminationList;

/* SKT's GMAP Spec. explicitly show the definitions: */
/* u before CHOICE is added to prevent warning */
typedef struct TriggerList {            /* bf8216 */
    DestinationAddress destinationAddress;
    struct {
        unsigned short  choice;
#           define      win_trigger_chosen 1
#           define      win_triggerList_chosen 2
        union {
            WIN_trigger     win_trigger;  /* to choose, set choice to
                                           * win_trigger_chosen */
            struct WIN_triggerList *win_triggerList;  /* to choose, set choice
                                                 * to win_triggerList_chosen */
        } u;
    } choice;
} TriggerList;

typedef struct TriggerAddressList {
    struct TriggerAddressList *next;
    TriggerList     value;
} *TriggerAddressList; /* bf8214 */

typedef struct CallTimeAndReport {
    unsigned short  length;
    unsigned char   value[3];
} CallTimeAndReport; /* 9fff3f */

typedef struct AnalyzedInformationRes {
    unsigned int    bit_mask;
#       define      AnalyzedInformationRes_accessDeniedReason_present 0x80000000
#       define      AnalyzedInformationRes_actionCode_present 0x40000000
#       define      AnalyzedInformationRes_announcementList_present 0x20000000
#       define      AnalyzedInformationRes_carrierDigits_present 0x10000000
#       define      AnalyzedInformationRes_conferenceCallingIndicator_present 0x08000000
#       define      AnalyzedInformationRes_digits_present 0x04000000
#       define      AnalyzedInformationRes_displayText_present 0x02000000
#       define      AnalyzedInformationRes_dmh_AccountCodeDigits_present 0x01000000
#       define      AnalyzedInformationRes_dmh_AlternateBillingDigits_present 0x00800000
#       define      AnalyzedInformationRes_dmh_BillingDigits_present 0x00400000
#       define      AnalyzedInformationRes_dmh_RedirectionIndicator_present 0x00200000
#       define      AnalyzedInformationRes_noAnswerTime_present 0x00100000
#       define      AnalyzedInformationRes_oneTimeFeatureIndicator_present 0x00080000
#       define      AnalyzedInformationRes_redirectingNumberDigits_present 0x00040000
#       define      AnalyzedInformationRes_resumePIC_present 0x00020000
#       define      AnalyzedInformationRes_routingDigits_present 0x00010000
#       define      AnalyzedInformationRes_terminationTriggers_present 0x00008000
#       define      AnalyzedInformationRes_triggerAddressList_present 0x00004000
#       define      callTimeAndReport_present 0x00002000
    AccessDeniedReason accessDeniedReason;  /* optional; set in bit_mask
                         * AnalyzedInformationRes_accessDeniedReason_present if
                         * present */
    ActionCode      actionCode;  /* optional; set in bit_mask
                                  * AnalyzedInformationRes_actionCode_present if
                                  * present */
    AnnouncementList announcementList;  /* optional; set in bit_mask
                           * AnalyzedInformationRes_announcementList_present if
                           * present */
    CarrierDigits   carrierDigits;  /* optional; set in bit_mask
                              * AnalyzedInformationRes_carrierDigits_present if
                              * present */
    ConferenceCallingIndicator conferenceCallingIndicator;  /* optional; set in
                                   * bit_mask
                 * AnalyzedInformationRes_conferenceCallingIndicator_present if
                 * present */
    WinDigits       digits;  /* optional; set in bit_mask
                              * AnalyzedInformationRes_digits_present if
                              * present */
    DisplayText     displayText;  /* optional; set in bit_mask
                                   * AnalyzedInformationRes_displayText_present
                                   * if present */
    DMH_AccountCodeDigits dmh_AccountCodeDigits;  /* optional; set in bit_mask
                      * AnalyzedInformationRes_dmh_AccountCodeDigits_present if
                      * present */
    DMH_AlternateBillingDigits dmh_AlternateBillingDigits;  /* optional; set in
                                   * bit_mask
                 * AnalyzedInformationRes_dmh_AlternateBillingDigits_present if
                 * present */
    DMH_BillingDigits dmh_BillingDigits;  /* optional; set in bit_mask
                          * AnalyzedInformationRes_dmh_BillingDigits_present if
                          * present */
    DMH_RedirectionIndicator dmh_RedirectionIndicator;  /* optional; set in
                                   * bit_mask
                   * AnalyzedInformationRes_dmh_RedirectionIndicator_present if
                   * present */
    NoAnswerTime    noAnswerTime;  /* optional; set in bit_mask
                               * AnalyzedInformationRes_noAnswerTime_present if
                               * present */
    OneTimeFeatureIndicator oneTimeFeatureIndicator;  /* optional; set in
                                   * bit_mask
                    * AnalyzedInformationRes_oneTimeFeatureIndicator_present if
                    * present */
    RedirectingNumberDigits redirectingNumberDigits;  /* optional; set in
                                   * bit_mask
                    * AnalyzedInformationRes_redirectingNumberDigits_present if
                    * present */
    ResumePIC       resumePIC;  /* optional; set in bit_mask
                                 * AnalyzedInformationRes_resumePIC_present if
                                 * present */
    RoutingDigits   routingDigits;  /* optional; set in bit_mask
                              * AnalyzedInformationRes_routingDigits_present if
                              * present */
    struct TerminationList *terminationList;  /* NULL for not present */
    TerminationTriggers terminationTriggers;  /* optional; set in bit_mask
                        * AnalyzedInformationRes_terminationTriggers_present if
                        * present */
    struct TriggerAddressList *triggerAddressList;  /* optional; set in bit_mask
                         * AnalyzedInformationRes_triggerAddressList_present if
                         * present */
    CallTimeAndReport callTimeAndReport;  /* optional; set in bit_mask
                                           * callTimeAndReport_present if
                                           * present */
} AnalyzedInformationRes;

typedef struct PrivateSpecializedResource {
    unsigned short  length;
    unsigned char   value[1];
} PrivateSpecializedResource;    /* bf8209 ³»ºÎ¿¡¼­ ´Ù½Ã ÂüÁ¶µÊ */

typedef struct SpecializedResource {
    unsigned short  length;
    unsigned char   value[2];
} SpecializedResource; /* 9f8213 */

typedef struct SRFCapability {      /* bf8212 */
    unsigned short  choice;
#       define      privateSpecializedResource_chosen 1
#       define      specializedResource_chosen 2
    union {
        PrivateSpecializedResource privateSpecializedResource;  /* to choose,
                                   * set choice to
                                   * privateSpecializedResource_chosen */
        SpecializedResource specializedResource;  /* to choose, set choice to
                                                * specializedResource_chosen */
    } u;
} SRFCapability;

/* SRFCapability´Â 0x9FFF89·Î Á¤ÀÇµÈ GMAP 1.2¸¦ µû¸¥´Ù. */
/* SRFCapability´Â ResourceType »óÀ§ 6ºñÆ® + NeedOrHave ÇÏÀ§ 2ºñÆ®·Î ±¸¼ºµÈ´Ù. */
/* NeedOrHave´Â 1-required, 2-desired, 0-notused °ªÀ» °®´Â´Ù. */
/* SRFCapability ::= [16265] OCTET STRING (SIZE(1..2))	9fff89 */
typedef struct SeizeResourceArg {
    unsigned char   bit_mask;
#       define      preferredlanguageIndicator_present 0x80
#       define      privateSpecializedResource_present 0x40
#       define      specializedResource_present 0x20
#       define      srfCapability_present 0x10
    PreferredLanguageIndicator preferredlanguageIndicator;  /* optional; set in
                                   * bit_mask preferredlanguageIndicator_present
                                   * if present */
    PrivateSpecializedResource privateSpecializedResource;  /* optional; set in
                                   * bit_mask privateSpecializedResource_present
                                   * if present */
    SpecializedResource specializedResource;  /* optional; set in bit_mask
                                               * specializedResource_present if
                                               * present */
    SRFCapability   srfCapability;  /* optional; set in bit_mask
                                     * srfCapability_present if present */
} SeizeResourceArg;

/* SeizeResourceRes ::= WinDigits */

/* bhtak 2002/2/26 change definition */
typedef struct SeizeResourceRes {
    WinDigits       digits;
} SeizeResourceRes;

typedef struct PageRequestArg {
    unsigned char   bit_mask;
#       define      PageRequestArg_mobileDirectoryNumber_present 0x80
#       define      PageRequestArg_mobileIdentificationNumber_present 0x40
#       define      PageRequestArg_electronicSerialNumber_present 0x20
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                              * PageRequestArg_mobileDirectoryNumber_present if
                              * present */
    MobileIdentificationNumber mobileIdentificationNumber;  /* optional; set in
                                   * bit_mask
                         * PageRequestArg_mobileIdentificationNumber_present if
                         * present */
    ElectronicSerialNumber electronicSerialNumber;  /* optional; set in bit_mask
                             * PageRequestArg_electronicSerialNumber_present if
                             * present */
} PageRequestArg;

typedef struct PageRequestRes {
    unsigned char   bit_mask;
#       define      PageRequestRes_accessDeniedReason_present 0x80
#       define      PageRequestRes_mscId_present 0x40
#       define      pc_ssn_present 0x20
#       define      PageRequestRes_locationAreaId_present 0x10
    AccessDeniedReason accessDeniedReason;  /* optional; set in bit_mask
                                 * PageRequestRes_accessDeniedReason_present if
                                 * present */
    MSCID           mscId;  /* optional; set in bit_mask
                             * PageRequestRes_mscId_present if present */
    PC_SSN          pc_ssn;  /* optional; set in bit_mask pc_ssn_present if
                              * present */
    LocationAreaID  locationAreaId;  /* optional; set in bit_mask
                                      * PageRequestRes_locationAreaId_present if
                                      * present */
} PageRequestRes;

typedef struct CallStateRequestArg {
    unsigned char   bit_mask;
#       define      CallStateRequestArg_callingPartyNumberDigits1_present 0x80
#       define      CallStateRequestArg_mobileIdentificationNumber_present 0x40
    BillingID       billingId;
    CallingPartyNumberDigits1 callingPartyNumberDigits1;  /* optional; set in
                                   * bit_mask
                     * CallStateRequestArg_callingPartyNumberDigits1_present if
                     * present */
    MobileIdentificationNumber mobileIdentificationNumber;  /* optional; set in
                                   * bit_mask
                    * CallStateRequestArg_mobileIdentificationNumber_present if
                    * present */
} CallStateRequestArg;

typedef struct CallStateRequestRes {
    unsigned char   bit_mask;
#       define      CallStateRequestRes_accessDeniedReason_present 0x80
#       define      callStartTime_present 0x40
    AccessDeniedReason accessDeniedReason;  /* optional; set in bit_mask
                            * CallStateRequestRes_accessDeniedReason_present if
                            * present */
    CallDateTime    callStartTime;  /* optional; set in bit_mask
                                     * callStartTime_present if present */
} CallStateRequestRes;

typedef struct ConnectResourceArg {
    unsigned char   bit_mask;
#       define      ConnectResourceArg_carrierDigits_present 0x80
#       define      ConnectResourceArg_routingDigits_present 0x40
    WinDigits       destination;
    CarrierDigits   carrierDigits;  /* optional; set in bit_mask
                                     * ConnectResourceArg_carrierDigits_present
                                     * if present */
    RoutingDigits   routingDigits;  /* optional; set in bit_mask
                                     * ConnectResourceArg_routingDigits_present
                                     * if present */
} ConnectResourceArg;

typedef struct DigitCollectionControl {
    unsigned short  length;
    unsigned char   value[16];
} DigitCollectionControl; /* 9f810b */

typedef struct ScriptName {
    unsigned short  length;
    unsigned char   value[6];
} ScriptName;    /* 9f820c */

typedef struct ScriptArgument {
    unsigned short  length;
    unsigned char   value[96];
} ScriptArgument;   /* 9f820b */

typedef struct ExecuteScript {      /* bf8202 */
    unsigned char   bit_mask;
#       define      scriptArgument_present 0x80
    ScriptName      scriptName;
    ScriptArgument  scriptArgument;  /* optional; set in bit_mask
                                      * scriptArgument_present if present */
} ExecuteScript;

typedef struct ExecuteScriptList {
    unsigned int    length;
    unsigned char   *value;
} ExecuteScriptList; /* 9fff3e */

typedef struct SRFDirectiveArg {
    unsigned char   bit_mask;
#       define      SRFDirectiveArg_announcementList_present 0x80
#       define      digitCollectionControl_present 0x40
#       define      executeScript_present 0x20
#       define      SRFDirectiveArg_executeScriptList_present 0x10
    AnnouncementList announcementList;  /* optional; set in bit_mask
                                  * SRFDirectiveArg_announcementList_present if
                                  * present */
    DigitCollectionControl digitCollectionControl;  /* optional; set in bit_mask
                                            * digitCollectionControl_present if
                                            * present */
    ExecuteScript   executeScript;  /* optional; set in bit_mask
                                     * executeScript_present if present */
    ExecuteScriptList executeScriptList;  /* optional; set in bit_mask
                                 * SRFDirectiveArg_executeScriptList_present if
                                 * present */
} SRFDirectiveArg;

typedef struct ScriptResult {
    unsigned short  length;
    unsigned char   value[96];
} ScriptResult;   /* 9f820d */

/* ScriptResult tag °ªÀÌ 0x9fff87ÀÎµ¥ ÀÌ °ªÀº ºñÁ¤»óÀûÀÎ tag °ªÀ¸·Î OSS Åø·Î */
/* ÀÎÄÚµùÀÌ ºÒ°¡´ÉÇÏ´Ù. */
typedef struct SRFDirectiveRes {
    unsigned char   bit_mask;
#       define      dialed_present 0x80
#       define      scriptResult_present 0x40
#       define      SRFDirectiveRes_executeScriptList_present 0x20
    WinDigits       dialed;  /* optional; set in bit_mask dialed_present if
                              * present */
    ScriptResult    scriptResult;  /* optional; set in bit_mask
                                    * scriptResult_present if present */
    ExecuteScriptList executeScriptList;  /* optional; set in bit_mask
                                 * SRFDirectiveRes_executeScriptList_present if
                                 * present */
} SRFDirectiveRes;

typedef struct CallResultReportArg {
    unsigned char   bit_mask;
#       define      CallResultReportArg_accessDeniedReason_present 0x80
#       define      CallResultReportArg_callingPartyNumberDigits1_present 0x40
#       define      CallResultReportArg_dmh_AccountCodeDigits_present 0x20
#       define      CallResultReportArg_dmh_AlternateBillingDigits_present 0x10
#       define      CallResultReportArg_dmh_BillingDigits_present 0x08
#       define      CallResultReportArg_dmh_RedirectionIndicator_present 0x04
#       define      CallResultReportArg_mobileIdentificationNumber_present 0x02
#       define      CallResultReportArg_cdmaServiceOption_present 0x01
    WinDigits       dialed;
    WinDigits       destination;
    MSCID           mscId;
    CallDateTime    callStartTime;
    CallDateTime    callEndTime;
    AccessDeniedReason accessDeniedReason;  /* optional; set in bit_mask
                            * CallResultReportArg_accessDeniedReason_present if
                            * present */
    CallingPartyNumberDigits1 callingPartyNumberDigits1;  /* optional; set in
                                   * bit_mask
                     * CallResultReportArg_callingPartyNumberDigits1_present if
                     * present */
    DMH_AccountCodeDigits dmh_AccountCodeDigits;  /* optional; set in bit_mask
                         * CallResultReportArg_dmh_AccountCodeDigits_present if
                         * present */
    DMH_AlternateBillingDigits dmh_AlternateBillingDigits;  /* optional; set in
                                   * bit_mask
                    * CallResultReportArg_dmh_AlternateBillingDigits_present if
                    * present */
    DMH_BillingDigits dmh_BillingDigits;  /* optional; set in bit_mask
                             * CallResultReportArg_dmh_BillingDigits_present if
                             * present */
    DMH_RedirectionIndicator dmh_RedirectionIndicator;  /* optional; set in
                                   * bit_mask
                      * CallResultReportArg_dmh_RedirectionIndicator_present if
                      * present */
    MobileIdentificationNumber mobileIdentificationNumber;  /* optional; set in
                                   * bit_mask
                    * CallResultReportArg_mobileIdentificationNumber_present if
                    * present */
    CDMAServiceOption cdmaServiceOption;  /* optional; set in bit_mask
                             * CallResultReportArg_cdmaServiceOption_present if
                             * present */
} CallResultReportArg;

typedef struct FailureType {
    unsigned short  length;
    unsigned char   value[1];
} FailureType; /* 9f8204 */

typedef struct TimeOfDay {
    unsigned short  length;
    unsigned char   value[3];
} TimeOfDay; /* 9fff3b */

typedef struct GMapFailureCause {
    unsigned short  length;
    unsigned char   value[2];
} GMapFailureCause; /* 9f8203 */

typedef struct ConnectionFailureReportArg {
    unsigned char   bit_mask;
#       define      timeOfDay_present 0x80
#       define      failureCause_present 0x40
    FailureType     failureType;
    TimeOfDay       timeOfDay;  /* optional; set in bit_mask timeOfDay_present
                                 * if present */
    GMapFailureCause failureCause;  /* optional; set in bit_mask
                                     * failureCause_present if present */
} ConnectionFailureReportArg;

/* change name because it conflicts with CAMEL */
typedef struct WinTimerID {
    unsigned short  length;
    unsigned char   value[1];
} WinTimerID; /* 9fff3c */

typedef struct WinTimerValue {
    unsigned short  length;
    unsigned char   value[2];
} WinTimerValue; /* 9fff3d */

typedef struct WinResetTimerArg {
    unsigned char   bit_mask;
#       define      timerId_present 0x80
#       define      timerValue_present 0x40
    WinTimerID      timerId;  /* optional; set in bit_mask timerId_present if
                               * present */
    WinTimerValue   timerValue;  /* optional; set in bit_mask timerValue_present
                                  * if present */
} WinResetTimerArg;

/* bhtak 2001/12/3 add new operation */
typedef struct CallControlDirectiveArg {
    unsigned char   bit_mask;
#       define      CallControlDirectiveArg_actionCode_present 0x80
#       define      CallControlDirectiveArg_displayText_present 0x40
    BillingID       billingId;
    MSCID           mscId;
    MobileIdentificationNumber mobileIdentificationNumber;
    ActionCode      actionCode;  /* optional; set in bit_mask
                                  * CallControlDirectiveArg_actionCode_present
                                  * if present */
/*	AnnouncementList			AnnouncementList, */
    DisplayText     displayText;  /* optional; set in bit_mask
                                   * CallControlDirectiveArg_displayText_present
                                   * if present */
/*	dmh_accountCodeDigits */
/*	dmh_alternateBillingDigits */
/*	dmh_billingDigits */
/*	dmh_redirectionIndicator */
/*	electronicSerialNumber */
/*	mobileDirectoryNumber */
/*	preferredLanguageIndicator */
/*	terminationList */
/*	triggerAddressList */
} CallControlDirectiveArg;

typedef struct CallStatus {
    unsigned short  length;
    unsigned char   value[1];
} CallStatus;        /* 9f8236 */

typedef struct CallControlDirectiveRes {
    unsigned char   bit_mask;
#       define      callStatus_present 0x80
    CallStatus      callStatus;  /* optional; set in bit_mask callStatus_present
                                  * if present */
} CallControlDirectiveRes;

/* for context-specific tag value calculation */
/**/
/* 9fffXX   -> 16256(0x3F80) + XX */
/* 9fXX     -> XX */
/* 9f8YXX   -> Y x 128 + XX     */
/* 8X       -> X                */
/* 9X       -> 16 + X */
/* 9FCE10   -> 10000 */
/* naming conventions for sequence member */
/* type : BillingID -> instance : billingId */
/* type : MSCID -> instance : mscId */

/* invalid tag number list */
/* */
/* in ReportTraceSubscriberActivityArg */
/* MobileDirectoryNumberCalled */
/* MobileDirectoryNumberCalling */
/* ElectronicSerialNumberCalling */
/* CallDateTimeHookOff */
/* CallDateTimeHookOn */
/* CallDateTimeCallStart */
/* CallDateTimeCallEnd */
/**/
/* in SMSRequestRes */
/* SMS-Capability 9fff8f ( > 9fff7f) , use 9f8119 instead */
/**/

/**/
/**/
/**/
/* GMAP Parameter Definitions */
/**/
/**/
/**/
typedef struct NumberString {
    unsigned short  length;
    unsigned char   value[20];
} NumberString; /* Header + 16 IA5 character */

typedef enum AuthorizationDenied { /* 8d */
    AuthorizationDenied_not_used = 0,
    delinquent_account = 1,
    invalid_serial_number = 2,
    stolen_unit = 3,
    duplicate_unit = 4,
    unassigned_directory_number = 5,
    AuthorizationDenied_unspecified = 6,
    multiple_access = 7,
    not_authorized_for_msc = 8,
    AuthorizationDenied_missing_authentication_parameters = 9,
    AuthorizationDenied_terminalType_mismatch = 10
} AuthorizationDenied;

typedef struct AuthorizationPeriod {
    unsigned short  length;
    unsigned char   value[2];
} AuthorizationPeriod; /* 8e */

typedef struct QualificationInformationCode {
    unsigned short  length;
    unsigned char   value[1];
} QualificationInformationCode; /* 91 */

typedef struct RedirectionReason {
    unsigned short  length;
    unsigned char   value[1];
} RedirectionReason; /* 93 */

 /* RedirectionReason				::= [19] ENUMERATED  {   93 */
 /*   busy(1), */
 /*   no-answer(2), */
 /*   unconditional(3), */
 /*   no-page-response(4), */
 /*   unavailable(5), */
 /*   unroutable(6), */
 /*   call-accepted(7), */
 /*   call-refused(8), */

 /*   vms-ruting-request(14), */
 /*   fms-ruting-request(15), */
 /*   cw-no-answer(16), */
 /*   ... */
 /* } */
typedef enum OriginationIndicator {               /* 97 */
    OriginationIndicator_not_used = 0,
    prior_agreement = 1,
    origination_denied = 2,
    local_call_only = 3,
    selected_npa_nxx = 4,
    selected_npa_nxx_local_call_only = 5,
    world_zone1 = 6,
    international_calls = 7,
    single_npa_nxx_xxxx = 8
} OriginationIndicator;

typedef enum TerminationRestrictionCode {               /* 98 */
    TerminationRestrictionCode_not_used = 0,
    termination_denied = 1,
    unrestricted = 2,
    restrictedPaidCall = 3
} TerminationRestrictionCode;

typedef struct CallingFeaturesIndicator {
    unsigned short  length;
    unsigned char   value[5];
} CallingFeaturesIndicator; /* 99 */

typedef struct SystemAccessType {
    unsigned short  length;
    unsigned char   value[1];
} SystemAccessType; /* 9f22 */

typedef struct CallHistoryCount {
    unsigned short  length;
    unsigned char   value[1];
} CallHistoryCount; /* 9f26 */

typedef struct ReportType {
    unsigned short  length;
    unsigned char   value[1];
} ReportType; /* 9f2c */

typedef struct TerminalType {
    unsigned short  length;
    unsigned char   value[1];
} TerminalType; /* 9f2f */

typedef struct SystemCapabilities {
    unsigned short  length;
    unsigned char   value[1];
} SystemCapabilities; /* 9f31 */

typedef struct ExtendedMSCID {
    unsigned short  length;
    unsigned char   value[4];
} ExtendedMSCID; /* 9f35 */

typedef struct ControlChannelData {
    unsigned short  length;
    unsigned char   value[1];
} ControlChannelData; /* 9f37 */

typedef struct SystemAccessData {
    unsigned short  length;
    unsigned char   value[5];
} SystemAccessData; /* 9f38 */

typedef struct CancellationDenied {
    unsigned short  length;
    unsigned char   value[1];
} CancellationDenied; /* 9f39 */

typedef struct BorderCellAccess {
    unsigned short  length;
    unsigned char   value[1];
} BorderCellAccess; /* 9f3a */

typedef struct ReceivedSignalQuality {
    unsigned short  length;
    unsigned char   value[1];
} ReceivedSignalQuality; /* 9f48 */

typedef struct DeregistrationType {
    unsigned short  length;
    unsigned char   value[1];
} DeregistrationType; /* 9f49 */

typedef struct AuthenticationCapability {
    unsigned short  length;
    unsigned char   value[1];
} AuthenticationCapability; /* 9f4e */

typedef NumberString    CallingPartyNumberString1; /* 9f52 */

typedef NumberString    CallingPartyNumberString2; /* 9f53 */

typedef struct AvailabilityType {
    unsigned short  length;
    unsigned char   value[1];
} AvailabilityType; /* 9f5a */

typedef struct MessageWaitingNotificationCount {
    unsigned short  length;
    unsigned char   value[10];
} MessageWaitingNotificationCount; /* 9f5c */

typedef struct OriginationTriggers {
    unsigned short  length;
    unsigned char   value[4];
} OriginationTriggers; /* 9f62 */

typedef BCDDigits       SenderIdentificationNumber; /* 9f67 */

typedef BCDDigits       SMS_Address; /* 9f68 */

typedef struct SMS_OriginationRestrictions {
    unsigned short  length;
    unsigned char   value[1];
} SMS_OriginationRestrictions; /* 9f73 */

typedef struct SMS_TerminationRestrictions {
    unsigned short  length;
    unsigned char   value[1];
} SMS_TerminationRestrictions; /* 9f75 */

typedef Nulltype        SMS_MessageWaitingIndicator; /* 9f76 */

typedef struct TerminationAccessType {
    unsigned short  length;
    unsigned char   value[1];
} TerminationAccessType; /* 9f77 */

/**//**//**//**//*- */
/* FROM 9f8100 */
/**//**//**//**//*- */
typedef struct AlertResult {
    unsigned short  length;
    unsigned char   value[1];
} AlertResult; /* 9f8101 */

typedef struct GeographicAuthorization {
    unsigned short  length;
    unsigned char   value[1];
} GeographicAuthorization; /* 9f810f */

typedef struct MessageWaitingNotificationType {
    unsigned short  length;
    unsigned char   value[1];
} MessageWaitingNotificationType; /* 9f8111 */

typedef struct PACAIndicator {
    unsigned short  length;
    unsigned char   value[1];
} PACAIndicator; /* 9f8112 */

typedef BCDDigits       RestrictionDigits; /* 9f8115 */

typedef BCDDigits       SPINIPIN; /* 9f811a */

typedef struct SPINITriggers {
    unsigned short  length;
    unsigned char   value[4];
} SPINITriggers; /* 9f811b */

typedef struct ConditionallyDeniedReason {
    unsigned short  length;
    unsigned char   value[1];
} ConditionallyDeniedReason; /* 9f8122 */

typedef struct GroupInformation {
    unsigned short  length;
    unsigned char   value[4];
} GroupInformation; /* 9f8123 */

typedef struct DeniedAuthorizationPeriod {
    unsigned short  length;
    unsigned char   value[1];
} DeniedAuthorizationPeriod; /* 9f8127 */

typedef WinDigits       PilotNumber; /* 9f8128 */

typedef struct PilotBillingID {
    unsigned short  length;
    unsigned char   value[7];
} PilotBillingID; /* 9f8129 */

typedef struct CDMAServiceOptionList {
    unsigned short  count;
    CDMAServiceOption value[6];
} CDMAServiceOptionList; /*9f8130 */

typedef struct ControlChannelMode {
    unsigned short  length;
    unsigned char   value[1];
} ControlChannelMode; /* 9f8147 */

typedef struct CDMARedirectRecord {
    unsigned short  length;
    unsigned char   value[4];
} CDMARedirectRecord; /* 9f8165 */

typedef struct CDMANetworkIdentification {
    unsigned short  length;
    unsigned char   value[2];
} CDMANetworkIdentification; /* 9f8168 */

typedef struct ServiceRedirectionCause {
    unsigned short  length;
    unsigned char   value[1];
} ServiceRedirectionCause; /* 9f816d */

typedef struct ServiceRedirectionInfo {
    unsigned short  length;
    unsigned char   value[1];
} ServiceRedirectionInfo; /* 9f816e */

typedef struct RoamingIndication {
    unsigned short  length;
    unsigned char   value[1];
} RoamingIndication; /* 9f816f */

typedef struct GMAPIMSI {
    unsigned short  length;
    unsigned char   value[8];
} GMAPIMSI; /* 9f8172 */

typedef struct ServiceID {
    unsigned short  length;
    unsigned char   value[2];
} ServiceID; /* 9f8176 */

typedef struct Change {
    unsigned short  length;
    unsigned char   value[1];
} Change; /* 9f8178 */

typedef struct DataID {
    unsigned short  length;
    unsigned char   value[1];
} DataID; /* 9f817b */

typedef struct DataValue {
    unsigned short  length;
    unsigned char   value[1];
} DataValue; /* 9f8200 */

/*LGT */
typedef BCDDigits       LCSBillingID;  /* 9f826f */

typedef BCDDigits       MPCID;  /* 9f8273 */

typedef struct WIN_Trigger { /* bf821a */
    unsigned char   bit_mask;
#       define      detectionPointType_present 0x80
    TriggerType     triggerType;
    DetectionPointType detectionPointType;  /* optional; set in bit_mask
                                             * detectionPointType_present if
                                             * present */
} WIN_Trigger;

typedef struct WIN_TriggerList {
    struct WIN_TriggerList *next;
    WIN_Trigger     value;
} *WIN_TriggerList; /* bf821b */

typedef BCDDigits       MSC_Address; /* 9f821c */

typedef struct DataAccessElement { /* bf8179 */
    unsigned char   bit_mask;
#       define      change_present 0x80
#       define      dataValue_present 0x40
    DataID          dataId;
    Change          change;  /* optional; set in bit_mask change_present if
                              * present */
    DataValue       dataValue;  /* optional; set in bit_mask dataValue_present
                                 * if present */
} DataAccessElement;

typedef struct DataAccessElementList {
    struct DataAccessElementList *next;
    DataAccessElement value;
} *DataAccessElementList; /* bf817a */

/**/
/* FROM 9fff00 */
/**/
typedef struct AdditionalServiceInformation {
    unsigned short  length;
    unsigned char   value[4];
} AdditionalServiceInformation; /* 9fff31, more than size 1 */

typedef struct MultiServiceID {
    unsigned short  length;
    unsigned char   value[4];
} MultiServiceID; /* 9fff32, more than size 2 */

typedef struct SuppressServiceInformation {
    unsigned short  length;
    unsigned char   value[1];
} SuppressServiceInformation; /* 9fff34 */

typedef BCDDigits       RoutingDigits2; /* 9fff35 */

typedef struct TerminatingServiceFeaturesIndicator {
    unsigned short  length;
    unsigned char   value[1];
} TerminatingServiceFeaturesIndicator; /* 9fff39 */

typedef struct OriginatingServiceFeaturesIndicator {
    unsigned short  length;
    unsigned char   value[5];
} OriginatingServiceFeaturesIndicator; /* 9fff3a */

typedef struct ChargingCategory {
    unsigned short  length;
    unsigned char   value[1];
} ChargingCategory; /* 9fff46 */

typedef struct VerifyChargingEndTime {
    unsigned short  length;
    unsigned char   value[6];
} VerifyChargingEndTime; /* 9fff4d */

typedef struct VerifyChargingIndicator {
    unsigned short  length;
    unsigned char   value[1];
} VerifyChargingIndicator; /* 9fff4e */

typedef struct VerifyChargingStartTime {
    unsigned short  length;
    unsigned char   value[6];
} VerifyChargingStartTime; /* 9fff4f */

/* TRACE */
typedef struct ReportPeriod {
    unsigned short  length;
    unsigned char   value[2];
} ReportPeriod; /* 9fff52 */

typedef enum MailStateFlag { /* 9fff64 */
    no_more_new_mail = 0,
    new_mail_exist = 1
} MailStateFlag;

typedef struct AuthenticationAttemptPoint {
    unsigned short  length;
    unsigned char   value[1];
} AuthenticationAttemptPoint; /* 9fff6a */

typedef struct AuthenticationPeriodCount {
    unsigned short  length;
    unsigned char   value[1];
} AuthenticationPeriodCount; /* 9fff6b */

typedef enum GMAP_Protocol_ReturnResult { /* 9fff6c */
    ok = 0,
    nok = 1
} GMAP_Protocol_ReturnResult;

typedef struct Alert {
    unsigned short  length;
    unsigned char   value[1];
} Alert; /* 9fff6d */

typedef struct ResultReason {
    unsigned short  length;
    unsigned char   value[2];
} ResultReason; /* 9fff6e */

typedef struct FileName {
    unsigned short  length;
    unsigned char   value[32];
} FileName; /* 9fff6f */

typedef struct CallingFeaturesIndicator2 {
    unsigned short  length;
    unsigned char   value[4];
} CallingFeaturesIndicator2; /* 9fff7d */

/**/
/**/
/**/
/* GMAP Operation Definitions */
/**/
/**/
/**/
typedef struct RegistrationNotificationArg {
    unsigned int    bit_mask;
#       define      RegistrationNotificationArg_imsi_present 0x80000000
#       define      RegistrationNotificationArg_availabilityType_present 0x40000000
#       define      borderCellAccess_present 0x20000000
#       define      RegistrationNotificationArg_controlChannelData_present 0x10000000
#       define      extendedMSCID_present 0x08000000
#       define      RegistrationNotificationArg_locationAreaId_present 0x04000000
#       define      msc_address_present 0x02000000
#       define      RegistrationNotificationArg_pc_SSN_present 0x01000000
#       define      RegistrationNotificationArg_receivedSignalQuality_present 0x00800000
#       define      reportType_present 0x00400000
#       define      RegistrationNotificationArg_senderIdentificationNumber_present 0x00200000
#       define      RegistrationNotificationArg_sms_address_present 0x00100000
#       define      RegistrationNotificationArg_sms_MessageWaitingIndicator_present 0x00080000
#       define      RegistrationNotificationArg_systemAccessData_present 0x00040000
#       define      RegistrationNotificationArg_systemAccessType_present 0x00020000
#       define      RegistrationNotificationArg_systemCapabilities_present 0x00010000
#       define      RegistrationNotificationArg_terminalType_present 0x00008000
#       define      RegistrationNotificationArg_transactionCapability_present 0x00004000
#       define      RegistrationNotificationArg_winCapability_present 0x00002000
#       define      RegistrationNotificationArg_cdmaNetworkIdentification_present 0x00001000
#       define      RegistrationNotificationArg_controlChannelMode_present 0x00000800
#       define      RegistrationNotificationArg_serviceRedirectionCause_present 0x00000400
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    MSCID           mscId;
    QualificationInformationCode qualificationInformationCode;
    SystemMyTypeCode systemMyTypeCode;
    GMAPIMSI        imsi;  /* optional; set in bit_mask
                            * RegistrationNotificationArg_imsi_present if
                            * present */
    AvailabilityType availabilityType;  /* optional; set in bit_mask
                      * RegistrationNotificationArg_availabilityType_present if
                      * present */
    BorderCellAccess borderCellAccess;  /* optional; set in bit_mask
                                         * borderCellAccess_present if
                                         * present */
    ControlChannelData controlChannelData;  /* optional; set in bit_mask
                    * RegistrationNotificationArg_controlChannelData_present if
                    * present */
    ExtendedMSCID   extendedMSCID;  /* optional; set in bit_mask
                                     * extendedMSCID_present if present */
    LocationAreaID  locationAreaId;  /* optional; set in bit_mask
                        * RegistrationNotificationArg_locationAreaId_present if
                        * present */
    MSC_Address     msc_address;  /* optional; set in bit_mask
                                   * msc_address_present if present */
    PC_SSN          pc_SSN;  /* optional; set in bit_mask
                              * RegistrationNotificationArg_pc_SSN_present if
                              * present */
    ReceivedSignalQuality receivedSignalQuality;  /* optional; set in bit_mask
                 * RegistrationNotificationArg_receivedSignalQuality_present if
                 * present */
    ReportType      reportType;  /* optional; set in bit_mask reportType_present
                                  * if present */
    SenderIdentificationNumber senderIdentificationNumber;  /* optional; set in
                                   * bit_mask
            * RegistrationNotificationArg_senderIdentificationNumber_present if
            * present */
    SMS_Address     sms_address;  /* optional; set in bit_mask
                           * RegistrationNotificationArg_sms_address_present if
                           * present */
    SMS_MessageWaitingIndicator sms_MessageWaitingIndicator;  /* optional; set
                                   * in bit_mask
           * RegistrationNotificationArg_sms_MessageWaitingIndicator_present if
           * present */
    SystemAccessData systemAccessData;  /* optional; set in bit_mask
                      * RegistrationNotificationArg_systemAccessData_present if
                      * present */
    SystemAccessType systemAccessType;  /* optional; set in bit_mask
                      * RegistrationNotificationArg_systemAccessType_present if
                      * present */
    SystemCapabilities systemCapabilities;  /* optional; set in bit_mask
                    * RegistrationNotificationArg_systemCapabilities_present if
                    * present */
    TerminalType    terminalType;  /* optional; set in bit_mask
                          * RegistrationNotificationArg_terminalType_present if
                          * present */
    TransactionCapability transactionCapability;  /* optional; set in bit_mask
                 * RegistrationNotificationArg_transactionCapability_present if
                 * present */
    WINCapability   winCapability;  /* optional; set in bit_mask
                         * RegistrationNotificationArg_winCapability_present if
                         * present */
    CDMANetworkIdentification cdmaNetworkIdentification;  /* optional; set in
                                   * bit_mask
             * RegistrationNotificationArg_cdmaNetworkIdentification_present if
             * present */
    ControlChannelMode controlChannelMode;  /* optional; set in bit_mask
                    * RegistrationNotificationArg_controlChannelMode_present if
                    * present */
    ServiceRedirectionCause serviceRedirectionCause;  /* optional; set in
                                   * bit_mask
               * RegistrationNotificationArg_serviceRedirectionCause_present if
               * present */
} RegistrationNotificationArg;

typedef struct TraceType {
    unsigned short  length;
    unsigned char   value[1];
} TraceType; /* 9fff51 */

typedef struct RegistrationNotificationRes {
    unsigned char   bit_mask[7];
#       define      RegistrationNotificationRes_authorizationDenied_present 0x80
#       define      RegistrationNotificationRes_authorizationDenied_present_byte 0
#       define      RegistrationNotificationRes_authorizationPeriod_present 0x40
#       define      RegistrationNotificationRes_authorizationPeriod_present_byte 0
#       define      RegistrationNotificationRes_controlChannelData_present 0x20
#       define      RegistrationNotificationRes_controlChannelData_present_byte 0
#       define      RegistrationNotificationRes_deniedAuthorizationPeriod_present 0x10
#       define      RegistrationNotificationRes_deniedAuthorizationPeriod_present_byte 0
#       define      RegistrationNotificationRes_digits_present 0x08
#       define      RegistrationNotificationRes_digits_present_byte 0
#       define      RegistrationNotificationRes_mscId_present 0x04
#       define      RegistrationNotificationRes_mscId_present_byte 0
#       define      RegistrationNotificationRes_authenticationCapability_present 0x02
#       define      RegistrationNotificationRes_authenticationCapability_present_byte 0
#       define      RegistrationNotificationRes_authenticationAttemptPoint_present 0x01
#       define      RegistrationNotificationRes_authenticationAttemptPoint_present_byte 0
#       define      RegistrationNotificationRes_authenticationPeriodCount_present 0x80
#       define      RegistrationNotificationRes_authenticationPeriodCount_present_byte 1
#       define      RegistrationNotificationRes_callingFeaturesIndicator_present 0x40
#       define      RegistrationNotificationRes_callingFeaturesIndicator_present_byte 1
#       define      RegistrationNotificationRes_carrierDigits_present 0x20
#       define      RegistrationNotificationRes_carrierDigits_present_byte 1
#       define      RegistrationNotificationRes_dmh_AccountCodeDigits_present 0x10
#       define      RegistrationNotificationRes_dmh_AccountCodeDigits_present_byte 1
#       define      RegistrationNotificationRes_dmh_AlternateBillingDigits_present 0x08
#       define      RegistrationNotificationRes_dmh_AlternateBillingDigits_present_byte 1
#       define      RegistrationNotificationRes_dmh_BillingDigits_present 0x04
#       define      RegistrationNotificationRes_dmh_BillingDigits_present_byte 1
#       define      RegistrationNotificationRes_geographicAuthorization_present 0x02
#       define      RegistrationNotificationRes_geographicAuthorization_present_byte 1
#       define      RegistrationNotificationRes_messageWaitingNotificationCount_present 0x01
#       define      RegistrationNotificationRes_messageWaitingNotificationCount_present_byte 1
#       define      RegistrationNotificationRes_messageWaitingNotificationType_present 0x80
#       define      RegistrationNotificationRes_messageWaitingNotificationType_present_byte 2
#       define      RegistrationNotificationRes_mobileDirectoryNumber_present 0x40
#       define      RegistrationNotificationRes_mobileDirectoryNumber_present_byte 2
#       define      RegistrationNotificationRes_originationIndicator_present 0x20
#       define      RegistrationNotificationRes_originationIndicator_present_byte 2
#       define      RegistrationNotificationRes_originationTriggers_present 0x10
#       define      RegistrationNotificationRes_originationTriggers_present_byte 2
#       define      RegistrationNotificationRes_pacIndicator_present 0x08
#       define      RegistrationNotificationRes_pacIndicator_present_byte 2
#       define      RegistrationNotificationRes_preferredLanguageIndicator_present 0x04
#       define      RegistrationNotificationRes_preferredLanguageIndicator_present_byte 2
#       define      RegistrationNotificationRes_restrictionDigits_present 0x02
#       define      RegistrationNotificationRes_restrictionDigits_present_byte 2
#       define      RegistrationNotificationRes_routingDigits_present 0x01
#       define      RegistrationNotificationRes_routingDigits_present_byte 2
#       define      RegistrationNotificationRes_sms_OriginationRestrictions_present 0x80
#       define      RegistrationNotificationRes_sms_OriginationRestrictions_present_byte 3
#       define      RegistrationNotificationRes_sms_TerminationRestrictions_present 0x40
#       define      RegistrationNotificationRes_sms_TerminationRestrictions_present_byte 3
#       define      RegistrationNotificationRes_spiniPin_present 0x20
#       define      RegistrationNotificationRes_spiniPin_present_byte 3
#       define      RegistrationNotificationRes_spiniTriggers_present 0x10
#       define      RegistrationNotificationRes_spiniTriggers_present_byte 3
#       define      RegistrationNotificationRes_terminationRestrictionCode_present 0x08
#       define      RegistrationNotificationRes_terminationRestrictionCode_present_byte 3
#       define      RegistrationNotificationRes_terminationTriggers_present 0x04
#       define      RegistrationNotificationRes_terminationTriggers_present_byte 3
#       define      RegistrationNotificationRes_triggerAddressList_present 0x02
#       define      RegistrationNotificationRes_triggerAddressList_present_byte 3
#       define      RegistrationNotificationRes_cdmaServiceOptionList_present 0x01
#       define      RegistrationNotificationRes_cdmaServiceOptionList_present_byte 3
#       define      RegistrationNotificationRes_callingFeaturesIndicator2_present 0x80
#       define      RegistrationNotificationRes_callingFeaturesIndicator2_present_byte 4
#       define      RegistrationNotificationRes_originatingServiceFeaturesIndicator_present 0x40
#       define      RegistrationNotificationRes_originatingServiceFeaturesIndicator_present_byte 4
#       define      RegistrationNotificationRes_terminatingServiceFeaturesIndicator_present 0x20
#       define      RegistrationNotificationRes_terminatingServiceFeaturesIndicator_present_byte 4
#       define      RegistrationNotificationRes_routingDigits2_present 0x10
#       define      RegistrationNotificationRes_routingDigits2_present_byte 4
#       define      RegistrationNotificationRes_receivedSignalQuality_present 0x08
#       define      RegistrationNotificationRes_receivedSignalQuality_present_byte 4
#       define      RegistrationNotificationRes_senderIdentificationNumber_present 0x04
#       define      RegistrationNotificationRes_senderIdentificationNumber_present_byte 4
#       define      RegistrationNotificationRes_sms_MessageWaitingIndicator_present 0x02
#       define      RegistrationNotificationRes_sms_MessageWaitingIndicator_present_byte 4
#       define      RegistrationNotificationRes_systemAccessData_present 0x01
#       define      RegistrationNotificationRes_systemAccessData_present_byte 4
#       define      RegistrationNotificationRes_chargingCategory_present 0x80
#       define      RegistrationNotificationRes_chargingCategory_present_byte 5
#       define      RegistrationNotificationRes_verifyChargingIndicator_present 0x40
#       define      RegistrationNotificationRes_verifyChargingIndicator_present_byte 5
#       define      RegistrationNotificationRes_verifyChargingStartTime_present 0x20
#       define      RegistrationNotificationRes_verifyChargingStartTime_present_byte 5
#       define      RegistrationNotificationRes_verifyChargingEndTime_present 0x10
#       define      RegistrationNotificationRes_verifyChargingEndTime_present_byte 5
#       define      traceType_present 0x08
#       define      traceType_present_byte 5
#       define      RegistrationNotificationRes_reportPeriod_present 0x04
#       define      RegistrationNotificationRes_reportPeriod_present_byte 5
#       define      mailStateFlag_present 0x02
#       define      mailStateFlag_present_byte 5
#       define      RegistrationNotificationRes_cdmaRedirectRecord_present 0x01
#       define      RegistrationNotificationRes_cdmaRedirectRecord_present_byte 5
#       define      RegistrationNotificationRes_serviceRedirectionInfo_present 0x80
#       define      RegistrationNotificationRes_serviceRedirectionInfo_present_byte 6
#       define      RegistrationNotificationRes_roamingIndication_present 0x40
#       define      RegistrationNotificationRes_roamingIndication_present_byte 6
    SystemMyTypeCode systemMyTypeCode;
    AuthorizationDenied authorizationDenied;  /* optional; set in bit_mask
                   * RegistrationNotificationRes_authorizationDenied_present if
                   * present */
    AuthorizationPeriod authorizationPeriod;  /* optional; set in bit_mask
                   * RegistrationNotificationRes_authorizationPeriod_present if
                   * present */
    ControlChannelData controlChannelData;  /* optional; set in bit_mask
                    * RegistrationNotificationRes_controlChannelData_present if
                    * present */
    DeniedAuthorizationPeriod deniedAuthorizationPeriod;  /* optional; set in
                                   * bit_mask
             * RegistrationNotificationRes_deniedAuthorizationPeriod_present if
             * present */
    WinDigits       digits;  /* optional; set in bit_mask
                              * RegistrationNotificationRes_digits_present if
                              * present */
    MSCID           mscId;  /* optional; set in bit_mask
                             * RegistrationNotificationRes_mscId_present if
                             * present */
    AuthenticationCapability authenticationCapability;  /* optional; set in
                                   * bit_mask
              * RegistrationNotificationRes_authenticationCapability_present if
              * present */
    AuthenticationAttemptPoint authenticationAttemptPoint;  /* optional; set in
                                   * bit_mask
            * RegistrationNotificationRes_authenticationAttemptPoint_present if
            * present */
    AuthenticationPeriodCount authenticationPeriodCount;  /* optional; set in
                                   * bit_mask
             * RegistrationNotificationRes_authenticationPeriodCount_present if
             * present */
    CallingFeaturesIndicator callingFeaturesIndicator;  /* optional; set in
                                   * bit_mask
              * RegistrationNotificationRes_callingFeaturesIndicator_present if
              * present */
    CarrierDigits   carrierDigits;  /* optional; set in bit_mask
                         * RegistrationNotificationRes_carrierDigits_present if
                         * present */
    DMH_AccountCodeDigits dmh_AccountCodeDigits;  /* optional; set in bit_mask
                 * RegistrationNotificationRes_dmh_AccountCodeDigits_present if
                 * present */
    DMH_AlternateBillingDigits dmh_AlternateBillingDigits;  /* optional; set in
                                   * bit_mask
            * RegistrationNotificationRes_dmh_AlternateBillingDigits_present if
            * present */
    DMH_BillingDigits dmh_BillingDigits;  /* optional; set in bit_mask
                     * RegistrationNotificationRes_dmh_BillingDigits_present if
                     * present */
    GeographicAuthorization geographicAuthorization;  /* optional; set in
                                   * bit_mask
               * RegistrationNotificationRes_geographicAuthorization_present if
               * present */
    MessageWaitingNotificationCount messageWaitingNotificationCount;  
                                  /* optional; set in bit_mask
       * RegistrationNotificationRes_messageWaitingNotificationCount_present if
       * present */
    MessageWaitingNotificationType messageWaitingNotificationType;  
                                  /* optional; set in bit_mask
        * RegistrationNotificationRes_messageWaitingNotificationType_present if
        * present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                 * RegistrationNotificationRes_mobileDirectoryNumber_present if
                 * present */
    OriginationIndicator originationIndicator;  /* optional; set in bit_mask
                  * RegistrationNotificationRes_originationIndicator_present if
                  * present */
    OriginationTriggers originationTriggers;  /* optional; set in bit_mask
                   * RegistrationNotificationRes_originationTriggers_present if
                   * present */
    PACAIndicator   pacIndicator;  /* optional; set in bit_mask
                          * RegistrationNotificationRes_pacIndicator_present if
                          * present */
    PreferredLanguageIndicator preferredLanguageIndicator;  /* optional; set in
                                   * bit_mask
            * RegistrationNotificationRes_preferredLanguageIndicator_present if
            * present */
    RestrictionDigits restrictionDigits;  /* optional; set in bit_mask
                     * RegistrationNotificationRes_restrictionDigits_present if
                     * present */
    RoutingDigits   routingDigits;  /* optional; set in bit_mask
                         * RegistrationNotificationRes_routingDigits_present if
                         * present */
    SMS_OriginationRestrictions sms_OriginationRestrictions;  /* optional; set
                                   * in bit_mask
           * RegistrationNotificationRes_sms_OriginationRestrictions_present if
           * present */
    SMS_TerminationRestrictions sms_TerminationRestrictions;  /* optional; set
                                   * in bit_mask
           * RegistrationNotificationRes_sms_TerminationRestrictions_present if
           * present */
    SPINIPIN        spiniPin;  /* optional; set in bit_mask
                                * RegistrationNotificationRes_spiniPin_present
                                * if present */
    SPINITriggers   spiniTriggers;  /* optional; set in bit_mask
                         * RegistrationNotificationRes_spiniTriggers_present if
                         * present */
    TerminationRestrictionCode terminationRestrictionCode;  /* optional; set in
                                   * bit_mask
            * RegistrationNotificationRes_terminationRestrictionCode_present if
            * present */
    TerminationTriggers terminationTriggers;  /* optional; set in bit_mask
                   * RegistrationNotificationRes_terminationTriggers_present if
                   * present */
    struct TriggerAddressList *triggerAddressList;  /* optional; set in bit_mask
                    * RegistrationNotificationRes_triggerAddressList_present if
                    * present */
    CDMAServiceOptionList cdmaServiceOptionList;  /* optional; set in bit_mask
                 * RegistrationNotificationRes_cdmaServiceOptionList_present if
                 * present */
    CallingFeaturesIndicator2 callingFeaturesIndicator2;  /* optional; set in
                                   * bit_mask
             * RegistrationNotificationRes_callingFeaturesIndicator2_present if
             * present */
    OriginatingServiceFeaturesIndicator originatingServiceFeaturesIndicator;  
                                        /* optional; set in bit_mask
   * RegistrationNotificationRes_originatingServiceFeaturesIndicator_present if
   * present */
    TerminatingServiceFeaturesIndicator terminatingServiceFeaturesIndicator;  
                                        /* optional; set in bit_mask
   * RegistrationNotificationRes_terminatingServiceFeaturesIndicator_present if
   * present */
    RoutingDigits2  routingDigits2;  /* optional; set in bit_mask
                        * RegistrationNotificationRes_routingDigits2_present if
                        * present */
    ReceivedSignalQuality receivedSignalQuality;  /* optional; set in bit_mask
                 * RegistrationNotificationRes_receivedSignalQuality_present if
                 * present */
    SenderIdentificationNumber senderIdentificationNumber;  /* optional; set in
                                   * bit_mask
            * RegistrationNotificationRes_senderIdentificationNumber_present if
            * present */
    SMS_MessageWaitingIndicator sms_MessageWaitingIndicator;  /* optional; set
                                   * in bit_mask
           * RegistrationNotificationRes_sms_MessageWaitingIndicator_present if
           * present */
    SystemAccessData systemAccessData;  /* optional; set in bit_mask
                      * RegistrationNotificationRes_systemAccessData_present if
                      * present */
    ChargingCategory chargingCategory;  /* optional; set in bit_mask
                      * RegistrationNotificationRes_chargingCategory_present if
                      * present */
    VerifyChargingIndicator verifyChargingIndicator;  /* optional; set in
                                   * bit_mask
               * RegistrationNotificationRes_verifyChargingIndicator_present if
               * present */
    VerifyChargingStartTime verifyChargingStartTime;  /* optional; set in
                                   * bit_mask
               * RegistrationNotificationRes_verifyChargingStartTime_present if
               * present */
    VerifyChargingEndTime verifyChargingEndTime;  /* optional; set in bit_mask
                 * RegistrationNotificationRes_verifyChargingEndTime_present if
                 * present */
    TraceType       traceType;  /* optional; set in bit_mask traceType_present
                                 * if present */
    ReportPeriod    reportPeriod;  /* optional; set in bit_mask
                          * RegistrationNotificationRes_reportPeriod_present if
                          * present */
    MailStateFlag   mailStateFlag;  /* optional; set in bit_mask
                                     * mailStateFlag_present if present */
    CDMARedirectRecord cdmaRedirectRecord;  /* optional; set in bit_mask
                    * RegistrationNotificationRes_cdmaRedirectRecord_present if
                    * present */
    ServiceRedirectionInfo serviceRedirectionInfo;  /* optional; set in bit_mask
                * RegistrationNotificationRes_serviceRedirectionInfo_present if
                * present */
    RoamingIndication roamingIndication;  /* optional; set in bit_mask
                     * RegistrationNotificationRes_roamingIndication_present if
                     * present */
} RegistrationNotificationRes;

typedef struct CancellationType {
    unsigned short  length;
    unsigned char   value[1];
} CancellationType; /* 9f55 */

typedef struct RegistrationCancellationArg {
    unsigned char   bit_mask;
#       define      cancellationType_present 0x80
#       define      RegistrationCancellationArg_controlChannelData_present 0x40
#       define      RegistrationCancellationArg_receivedSignalQuality_present 0x20
#       define      RegistrationCancellationArg_senderIdentificationNumber_present 0x10
#       define      RegistrationCancellationArg_systemAccessData_present 0x08
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    CancellationType cancellationType;  /* optional; set in bit_mask
                                         * cancellationType_present if
                                         * present */
    ControlChannelData controlChannelData;  /* optional; set in bit_mask
                    * RegistrationCancellationArg_controlChannelData_present if
                    * present */
    ReceivedSignalQuality receivedSignalQuality;  /* optional; set in bit_mask
                 * RegistrationCancellationArg_receivedSignalQuality_present if
                 * present */
    SenderIdentificationNumber senderIdentificationNumber;  /* optional; set in
                                   * bit_mask
            * RegistrationCancellationArg_senderIdentificationNumber_present if
            * present */
    SystemAccessData systemAccessData;  /* optional; set in bit_mask
                      * RegistrationCancellationArg_systemAccessData_present if
                      * present */
} RegistrationCancellationArg;

typedef struct RegistrationCancellationRes {
    unsigned char   bit_mask;
#       define      RegistrationCancellationRes_callHistoryCount_present 0x80
#       define      cancellationDenied_present 0x40
#       define      RegistrationCancellationRes_controlChannelData_present 0x20
#       define      RegistrationCancellationRes_receivedSignalQuality_present 0x10
#       define      RegistrationCancellationRes_sms_MessageWaitingIndicator_present 0x08
#       define      RegistrationCancellationRes_systemAccessData_present 0x04
#       define      RegistrationCancellationRes_authenticationPeriodCount_present 0x02
    CallHistoryCount callHistoryCount;  /* optional; set in bit_mask
                      * RegistrationCancellationRes_callHistoryCount_present if
                      * present */
    CancellationDenied cancellationDenied;  /* optional; set in bit_mask
                                             * cancellationDenied_present if
                                             * present */
    ControlChannelData controlChannelData;  /* optional; set in bit_mask
                    * RegistrationCancellationRes_controlChannelData_present if
                    * present */
    ReceivedSignalQuality receivedSignalQuality;  /* optional; set in bit_mask
                 * RegistrationCancellationRes_receivedSignalQuality_present if
                 * present */
    SMS_MessageWaitingIndicator sms_MessageWaitingIndicator;  /* optional; set
                                   * in bit_mask
           * RegistrationCancellationRes_sms_MessageWaitingIndicator_present if
           * present */
    SystemAccessData systemAccessData;  /* optional; set in bit_mask
                      * RegistrationCancellationRes_systemAccessData_present if
                      * present */
    AuthenticationPeriodCount authenticationPeriodCount;  /* optional; set in
                                   * bit_mask
             * RegistrationCancellationRes_authenticationPeriodCount_present if
             * present */
} RegistrationCancellationRes;

typedef struct LocationRequestArg {
    unsigned int    bit_mask;
#       define      LocationRequestArg_callingPartyNumberDigits1_present 0x80000000
#       define      LocationRequestArg_callingPartyNumberDigits2_present 0x40000000
#       define      LocationRequestArg_callingPartySubaddress_present 0x20000000
#       define      LocationRequestArg_mscIdentificationNumber_present 0x10000000
#       define      LocationRequestArg_pc_SSN_present 0x08000000
#       define      LocationRequestArg_redirectingNumberDigits_present 0x04000000
#       define      LocationRequestArg_redirectingSubaddress_present 0x02000000
#       define      LocationRequestArg_senderIdentificationNumber_present 0x01000000
#       define      LocationRequestArg_terminationAccessType_present 0x00800000
#       define      LocationRequestArg_transactionCapability_present 0x00400000
#       define      LocationRequestArg_callingPartyName_present 0x00200000
#       define      LocationRequestArg_redirectingPartyName_present 0x00100000
#       define      LocationRequestArg_triggerType_present 0x00080000
#       define      LocationRequestArg_winCapability_present 0x00040000
#       define      LocationRequestArg_cdmaServiceOption_present 0x00020000
#       define      LocationRequestArg_locationAreaId_present 0x00010000
#       define      LocationRequestArg_displayText_present 0x00008000
#       define      LocationRequestArg_originatingServiceFeaturesIndicator_present 0x00004000
    BillingID       billingId;
    WinDigits       digits;
    MSCID           mscId;
    SystemMyTypeCode systemMyTypeCode;
    CallingPartyNumberDigits1 callingPartyNumberDigits1;  /* optional; set in
                                   * bit_mask
                      * LocationRequestArg_callingPartyNumberDigits1_present if
                      * present */
    CallingPartyNumberDigits2 callingPartyNumberDigits2;  /* optional; set in
                                   * bit_mask
                      * LocationRequestArg_callingPartyNumberDigits2_present if
                      * present */
    CallingPartySubaddress callingPartySubaddress;  /* optional; set in bit_mask
                         * LocationRequestArg_callingPartySubaddress_present if
                         * present */
    MSCIdentificationNumber mscIdentificationNumber;  /* optional; set in
                                   * bit_mask
                        * LocationRequestArg_mscIdentificationNumber_present if
                        * present */
    PC_SSN          pc_SSN;  /* optional; set in bit_mask
                              * LocationRequestArg_pc_SSN_present if present */
    RedirectingNumberDigits redirectingNumberDigits;  /* optional; set in
                                   * bit_mask
                        * LocationRequestArg_redirectingNumberDigits_present if
                        * present */
    RedirectingSubaddress redirectingSubaddress;  /* optional; set in bit_mask
                          * LocationRequestArg_redirectingSubaddress_present if
                          * present */
    SenderIdentificationNumber senderIdentificationNumber;  /* optional; set in
                                   * bit_mask
                     * LocationRequestArg_senderIdentificationNumber_present if
                     * present */
    TerminationAccessType terminationAccessType;  /* optional; set in bit_mask
                          * LocationRequestArg_terminationAccessType_present if
                          * present */
    TransactionCapability transactionCapability;  /* optional; set in bit_mask
                          * LocationRequestArg_transactionCapability_present if
                          * present */
    CallingPartyName callingPartyName;  /* optional; set in bit_mask
                               * LocationRequestArg_callingPartyName_present if
                               * present */
    RedirectingPartyName redirectingPartyName;  /* optional; set in bit_mask
                           * LocationRequestArg_redirectingPartyName_present if
                           * present */
    TriggerType     triggerType;  /* optional; set in bit_mask
                                   * LocationRequestArg_triggerType_present if
                                   * present */
    WINCapability   winCapability;  /* optional; set in bit_mask
                                     * LocationRequestArg_winCapability_present
                                     * if present */
    CDMAServiceOption cdmaServiceOption;  /* optional; set in bit_mask
                              * LocationRequestArg_cdmaServiceOption_present if
                              * present */
    LocationAreaID  locationAreaId;  /* optional; set in bit_mask
                                 * LocationRequestArg_locationAreaId_present if
                                 * present */
    DisplayText     displayText;  /* optional; set in bit_mask
                                   * LocationRequestArg_displayText_present if
                                   * present */
    OriginatingServiceFeaturesIndicator originatingServiceFeaturesIndicator;  
                                        /* optional; set in bit_mask
            * LocationRequestArg_originatingServiceFeaturesIndicator_present if
            * present */
} LocationRequestArg;

typedef NumberString    RedirectingNumberString; /* 9f65 */

typedef struct LocationRequestRes {
    unsigned int    bit_mask;
#       define      LocationRequestRes_accessDeniedReason_present 0x80000000
#       define      LocationRequestRes_announcementList_present 0x40000000
#       define      LocationRequestRes_callingPartyNumberString1_present 0x20000000
#       define      LocationRequestRes_callingPartyNumberString2_present 0x10000000
#       define      LocationRequestRes_digitsCarrier_present 0x08000000
#       define      LocationRequestRes_digitsDest_present 0x04000000
#       define      LocationRequestRes_dmh_AccountCodeDigits_present 0x02000000
#       define      LocationRequestRes_dmh_AlternateBillingDigits_present 0x01000000
#       define      LocationRequestRes_dmh_BillingDigits_present 0x00800000
#       define      LocationRequestRes_dmh_RedirectionIndicator_present 0x00400000
#       define      LocationRequestRes_groupInformation_present 0x00200000
#       define      LocationRequestRes_mobileDirectoryNumber_present 0x00100000
#       define      LocationRequestRes_noAnswerTime_present 0x00080000
#       define      LocationRequestRes_oneTimeFeatureIndicator_present 0x00040000
#       define      LocationRequestRes_pc_SSN_present 0x00020000
#       define      LocationRequestRes_redirectingNumberDigits_present 0x00010000
#       define      LocationRequestRes_redirectingNumberString_present 0x00008000
#       define      LocationRequestRes_redirectingSubaddress_present 0x00004000
#       define      LocationRequestRes_routingDigits_present 0x00002000
#       define      LocationRequestRes_terminationTriggers_present 0x00001000
#       define      LocationRequestRes_displayText_present 0x00000800
#       define      LocationRequestRes_triggerAddressList_present 0x00000400
#       define      LocationRequestRes_cdmaServiceOption_present 0x00000200
#       define      LocationRequestRes_originatingServiceFeaturesIndicator_present 0x00000100
#       define      LocationRequestRes_terminatingServiceFeaturesIndicator_present 0x00000080
#       define      suppressServiceInformation_present 0x00000040
#       define      LocationRequestRes_imsi_present 0x00000020
  /* NOTE: */
  /* in GMAP spec. digitsCarrier and digitsDest have the same tag values. */
  /* we changes the digitsCarrier tag with  one of CarrierDigits, and use the structere in application */
  /* for the encoded msg. it is necessary to change the tag value manually. */
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    MSCID           mscId;
    AccessDeniedReason accessDeniedReason;  /* optional; set in bit_mask
                             * LocationRequestRes_accessDeniedReason_present if
                             * present */
    AnnouncementList announcementList;  /* optional; set in bit_mask
                               * LocationRequestRes_announcementList_present if
                               * present */
    CallingPartyNumberString1 callingPartyNumberString1;  /* optional; set in
                                   * bit_mask
                      * LocationRequestRes_callingPartyNumberString1_present if
                      * present */
    CallingPartyNumberString2 callingPartyNumberString2;  /* optional; set in
                                   * bit_mask
                      * LocationRequestRes_callingPartyNumberString2_present if
                      * present */
    CarrierDigits   digitsCarrier;  /* optional; set in bit_mask
                                     * LocationRequestRes_digitsCarrier_present
                                     * if present */
                                    /* see NOTE above */
    WinDigits       digitsDest;  /* optional; set in bit_mask
                                  * LocationRequestRes_digitsDest_present if
                                  * present */
    DMH_AccountCodeDigits dmh_AccountCodeDigits;  /* optional; set in bit_mask
                          * LocationRequestRes_dmh_AccountCodeDigits_present if
                          * present */
    DMH_AlternateBillingDigits dmh_AlternateBillingDigits;  /* optional; set in
                                   * bit_mask
                     * LocationRequestRes_dmh_AlternateBillingDigits_present if
                     * present */
    DMH_BillingDigits dmh_BillingDigits;  /* optional; set in bit_mask
                              * LocationRequestRes_dmh_BillingDigits_present if
                              * present */
    DMH_RedirectionIndicator dmh_RedirectionIndicator;  /* optional; set in
                                   * bit_mask
                       * LocationRequestRes_dmh_RedirectionIndicator_present if
                       * present */
    GroupInformation groupInformation;  /* optional; set in bit_mask
                               * LocationRequestRes_groupInformation_present if
                               * present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                          * LocationRequestRes_mobileDirectoryNumber_present if
                          * present */
    NoAnswerTime    noAnswerTime;  /* optional; set in bit_mask
                                    * LocationRequestRes_noAnswerTime_present if
                                    * present */
    OneTimeFeatureIndicator oneTimeFeatureIndicator;  /* optional; set in
                                   * bit_mask
                        * LocationRequestRes_oneTimeFeatureIndicator_present if
                        * present */
    PC_SSN          pc_SSN;  /* optional; set in bit_mask
                              * LocationRequestRes_pc_SSN_present if present */
    RedirectingNumberDigits redirectingNumberDigits;  /* optional; set in
                                   * bit_mask
                        * LocationRequestRes_redirectingNumberDigits_present if
                        * present */
    RedirectingNumberString redirectingNumberString;  /* optional; set in
                                   * bit_mask
                        * LocationRequestRes_redirectingNumberString_present if
                        * present */
    RedirectingSubaddress redirectingSubaddress;  /* optional; set in bit_mask
                          * LocationRequestRes_redirectingSubaddress_present if
                          * present */
    RoutingDigits   routingDigits;  /* optional; set in bit_mask
                                     * LocationRequestRes_routingDigits_present
                                     * if present */
    struct TerminationList *terminationList;  /* NULL for not present */
    TerminationTriggers terminationTriggers;  /* optional; set in bit_mask
                            * LocationRequestRes_terminationTriggers_present if
                            * present */
    DisplayText     displayText;  /* optional; set in bit_mask
                                   * LocationRequestRes_displayText_present if
                                   * present */
    struct TriggerAddressList *triggerAddressList;  /* optional; set in bit_mask
                             * LocationRequestRes_triggerAddressList_present if
                             * present */
    CDMAServiceOption cdmaServiceOption;  /* optional; set in bit_mask
                              * LocationRequestRes_cdmaServiceOption_present if
                              * present */
    OriginatingServiceFeaturesIndicator originatingServiceFeaturesIndicator;  
                                        /* optional; set in bit_mask
            * LocationRequestRes_originatingServiceFeaturesIndicator_present if
            * present */
    TerminatingServiceFeaturesIndicator terminatingServiceFeaturesIndicator;  
                                        /* optional; set in bit_mask
            * LocationRequestRes_terminatingServiceFeaturesIndicator_present if
            * present */
    SuppressServiceInformation suppressServiceInformation;  /* optional; set in
                                   * bit_mask suppressServiceInformation_present
                                   * if present */
    GMAPIMSI        imsi;  /* optional; set in bit_mask
                            * LocationRequestRes_imsi_present if present */
} LocationRequestRes;

/**/
/* the fields marked as 'not used in SKT' is commented out, */
/* because the bit_mask becomes array when the # of files is greater than 32 */
/* where it is troublesome for coding... */
/**/
typedef struct RoutingRequestArg {
    unsigned int    bit_mask;
#       define      RoutingRequestArg_alertCode_present 0x80000000
#       define      RoutingRequestArg_callingPartyNumberString1_present 0x40000000
#       define      RoutingRequestArg_callingPartyNumberString2_present 0x20000000
#       define      RoutingRequestArg_callingPartySubaddress_present 0x10000000
#       define      RoutingRequestArg_destinationDigits_present 0x08000000
#       define      RoutingRequestArg_legInformation_present 0x04000000
#       define      RoutingRequestArg_locationAreaId_present 0x02000000
#       define      RoutingRequestArg_mobileDirectoryNumber_present 0x01000000
#       define      RoutingRequestArg_mscIdentificationNumber_present 0x00800000
#       define      RoutingRequestArg_noAnswerTime_present 0x00400000
#       define      RoutingRequestArg_oneTimeFeatureIndicator_present 0x00200000
#       define      RoutingRequestArg_pc_SSN_present 0x00100000
#       define      RoutingRequestArg_pilotNumber_present 0x00080000
#       define      RoutingRequestArg_redirectingNumberString_present 0x00040000
#       define      RoutingRequestArg_redirectingSubaddress_present 0x00020000
#       define      RoutingRequestArg_senderIdentificationNumber_present 0x00010000
#       define      RoutingRequestArg_terminationTreatment_present 0x00008000
#       define      RoutingRequestArg_terminationTriggers_present 0x00004000
#       define      RoutingRequestArg_callingPartyName_present 0x00002000
#       define      RoutingRequestArg_displayText_present 0x00001000
#       define      RoutingRequestArg_triggerAddressList_present 0x00000800
#       define      RoutingRequestArg_cdmaServiceOption_present 0x00000400
#       define      RoutingRequestArg_callingPartyNumberDigits1_present 0x00000200
#       define      RoutingRequestArg_callingPartyNumberDigits2_present 0x00000100
#       define      RoutingRequestArg_redirectingNumberDigits_present 0x00000080
#       define      RoutingRequestArg_originatingServiceFeaturesIndicator_present 0x00000040
#       define      RoutingRequestArg_imsi_present 0x00000020
    BillingID       billingId;
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    MSCID           mscId;
    SystemMyTypeCode systemMyTypeCode;
    AlertCode       alertCode;  /* optional; set in bit_mask
                                 * RoutingRequestArg_alertCode_present if
                                 * present */
    CallingPartyNumberString1 callingPartyNumberString1;  /* optional; set in
                                   * bit_mask
                       * RoutingRequestArg_callingPartyNumberString1_present if
                       * present */
    CallingPartyNumberString2 callingPartyNumberString2;  /* optional; set in
                                   * bit_mask
                       * RoutingRequestArg_callingPartyNumberString2_present if
                       * present */
    CallingPartySubaddress callingPartySubaddress;  /* optional; set in bit_mask
                          * RoutingRequestArg_callingPartySubaddress_present if
                          * present */
    DestinationDigits destinationDigits;  /* optional; set in bit_mask
                               * RoutingRequestArg_destinationDigits_present if
                               * present */
/* not used in SKT : dmh-AccountCodeDigits         DMH-AccountCodeDigits           OPTIONAL, */
/* not used in SKT : dmh-AlternateBillingDigits    DMH-AlternateBillingDigits      OPTIONAL, */
/* not used in SKT : dmh-BillingDigits             DMH-BillingDigits               OPTIONAL, */
    LegInformation  legInformation;  /* optional; set in bit_mask
                                      * RoutingRequestArg_legInformation_present
                                      * if present */
    LocationAreaID  locationAreaId;  /* optional; set in bit_mask
                                      * RoutingRequestArg_locationAreaId_present
                                      * if present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                           * RoutingRequestArg_mobileDirectoryNumber_present if
                           * present */
    MSCIdentificationNumber mscIdentificationNumber;  /* optional; set in
                                   * bit_mask
                         * RoutingRequestArg_mscIdentificationNumber_present if
                         * present */
    NoAnswerTime    noAnswerTime;  /* optional; set in bit_mask
                                    * RoutingRequestArg_noAnswerTime_present if
                                    * present */
    OneTimeFeatureIndicator oneTimeFeatureIndicator;  /* optional; set in
                                   * bit_mask
                         * RoutingRequestArg_oneTimeFeatureIndicator_present if
                         * present */
    PC_SSN          pc_SSN;  /* optional; set in bit_mask
                              * RoutingRequestArg_pc_SSN_present if present */
/* not used in SKT : pilotBillingId                PilotBillingID                  OPTIONAL, */
    PilotNumber     pilotNumber;  /* optional; set in bit_mask
                                   * RoutingRequestArg_pilotNumber_present if
                                   * present */
    RedirectingNumberString redirectingNumberString;  /* optional; set in
                                   * bit_mask
                         * RoutingRequestArg_redirectingNumberString_present if
                         * present */
    RedirectingSubaddress redirectingSubaddress;  /* optional; set in bit_mask
                           * RoutingRequestArg_redirectingSubaddress_present if
                           * present */
    SenderIdentificationNumber senderIdentificationNumber;  /* optional; set in
                                   * bit_mask
                      * RoutingRequestArg_senderIdentificationNumber_present if
                      * present */
    TerminationTreatment terminationTreatment;  /* optional; set in bit_mask
                            * RoutingRequestArg_terminationTreatment_present if
                            * present */
    TerminationTriggers terminationTriggers;  /* optional; set in bit_mask
                             * RoutingRequestArg_terminationTriggers_present if
                             * present */
/* not used in SKT : voiceMailboxNumber            VoiceMailboxNumber              OPTIONAL, */
/* not used in SKT : voiceMailboxPin               VoiceMailboxPIN                 OPTIONAL, */
    CallingPartyName callingPartyName;  /* optional; set in bit_mask
                                * RoutingRequestArg_callingPartyName_present if
                                * present */
    DisplayText     displayText;  /* optional; set in bit_mask
                                   * RoutingRequestArg_displayText_present if
                                   * present */
    struct TriggerAddressList *triggerAddressList;  /* optional; set in bit_mask
                              * RoutingRequestArg_triggerAddressList_present if
                              * present */
/* not used in SKT : redirectingPartyName          RedirectingPartyName            OPTIONAL, */
    CDMAServiceOption cdmaServiceOption;  /* optional; set in bit_mask
                               * RoutingRequestArg_cdmaServiceOption_present if
                               * present */
    CallingPartyNumberDigits1 callingPartyNumberDigits1;  /* optional; set in
                                   * bit_mask
                       * RoutingRequestArg_callingPartyNumberDigits1_present if
                       * present */
    CallingPartyNumberDigits2 callingPartyNumberDigits2;  /* optional; set in
                                   * bit_mask
                       * RoutingRequestArg_callingPartyNumberDigits2_present if
                       * present */
    RedirectingNumberDigits redirectingNumberDigits;  /* optional; set in
                                   * bit_mask
                         * RoutingRequestArg_redirectingNumberDigits_present if
                         * present */
    OriginatingServiceFeaturesIndicator originatingServiceFeaturesIndicator;  
                                        /* optional; set in bit_mask
             * RoutingRequestArg_originatingServiceFeaturesIndicator_present if
             * present */
    GMAPIMSI        imsi;  /* optional; set in bit_mask
                            * RoutingRequestArg_imsi_present if present */
} RoutingRequestArg;

typedef struct RoutingRequestRes {
    unsigned char   bit_mask;
#       define      RoutingRequestRes_accessDeniedReason_present 0x80
#       define      RoutingRequestRes_billingId_present 0x40
#       define      RoutingRequestRes_conditionallyDeniedReason_present 0x20
#       define      RoutingRequestRes_digits_present 0x10
#       define      RoutingRequestRes_mscIdentificationNumber_present 0x08
#       define      RoutingRequestRes_pc_SSN_present 0x04
#       define      RoutingRequestRes_cdmaServiceOption_present 0x02
    MSCID           mscId;
    AccessDeniedReason accessDeniedReason;  /* optional; set in bit_mask
                              * RoutingRequestRes_accessDeniedReason_present if
                              * present */
    BillingID       billingId;  /* optional; set in bit_mask
                                 * RoutingRequestRes_billingId_present if
                                 * present */
    ConditionallyDeniedReason conditionallyDeniedReason;  /* optional; set in
                                   * bit_mask
                       * RoutingRequestRes_conditionallyDeniedReason_present if
                       * present */
    WinDigits       digits;  /* optional; set in bit_mask
                              * RoutingRequestRes_digits_present if present */
    MSCIdentificationNumber mscIdentificationNumber;  /* optional; set in
                                   * bit_mask
                         * RoutingRequestRes_mscIdentificationNumber_present if
                         * present */
    PC_SSN          pc_SSN;  /* optional; set in bit_mask
                              * RoutingRequestRes_pc_SSN_present if present */
    CDMAServiceOption cdmaServiceOption;  /* optional; set in bit_mask
                               * RoutingRequestRes_cdmaServiceOption_present if
                               * present */
} RoutingRequestRes;

typedef struct CallingFeaturesIndicator3 {
    unsigned short  length;
    unsigned char   value[4];
} CallingFeaturesIndicator3; /* 9fff7e */

typedef struct FeatureRequestArg {
    unsigned short  bit_mask;
#       define      FeatureRequestArg_billingId_present 0x8000
#       define      FeatureRequestArg_callingPartyNumberDigits1_present 0x4000
#       define      FeatureRequestArg_callingPartyNumberDigits2_present 0x2000
#       define      FeatureRequestArg_callingPartySubaddress_present 0x1000
#       define      FeatureRequestArg_conferenceCallingIndicator_present 0x0800
#       define      FeatureRequestArg_mobileDirectoryNumber_present 0x0400
#       define      FeatureRequestArg_mscId_present 0x0200
#       define      FeatureRequestArg_mscIdentificationNumber_present 0x0100
#       define      FeatureRequestArg_oneTimeFeatureIndicator_present 0x0080
#       define      FeatureRequestArg_pc_SSN_present 0x0040
#       define      FeatureRequestArg_senderIdentificationNumber_present 0x0020
#       define      FeatureRequestArg_transactionCapability_present 0x0010
#       define      FeatureRequestArg_callingPartyName_present 0x0008
    WinDigits       digits;
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    BillingID       billingId;  /* optional; set in bit_mask
                                 * FeatureRequestArg_billingId_present if
                                 * present */
    CallingPartyNumberDigits1 callingPartyNumberDigits1;  /* optional; set in
                                   * bit_mask
                       * FeatureRequestArg_callingPartyNumberDigits1_present if
                       * present */
    CallingPartyNumberDigits2 callingPartyNumberDigits2;  /* optional; set in
                                   * bit_mask
                       * FeatureRequestArg_callingPartyNumberDigits2_present if
                       * present */
    CallingPartySubaddress callingPartySubaddress;  /* optional; set in bit_mask
                          * FeatureRequestArg_callingPartySubaddress_present if
                          * present */
    ConferenceCallingIndicator conferenceCallingIndicator;  /* optional; set in
                                   * bit_mask
                      * FeatureRequestArg_conferenceCallingIndicator_present if
                      * present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                           * FeatureRequestArg_mobileDirectoryNumber_present if
                           * present */
    MSCID           mscId;  /* optional; set in bit_mask
                             * FeatureRequestArg_mscId_present if present */
    MSCIdentificationNumber mscIdentificationNumber;  /* optional; set in
                                   * bit_mask
                         * FeatureRequestArg_mscIdentificationNumber_present if
                         * present */
    OneTimeFeatureIndicator oneTimeFeatureIndicator;  /* optional; set in
                                   * bit_mask
                         * FeatureRequestArg_oneTimeFeatureIndicator_present if
                         * present */
    PC_SSN          pc_SSN;  /* optional; set in bit_mask
                              * FeatureRequestArg_pc_SSN_present if present */
    SenderIdentificationNumber senderIdentificationNumber;  /* optional; set in
                                   * bit_mask
                      * FeatureRequestArg_senderIdentificationNumber_present if
                      * present */
    TransactionCapability transactionCapability;  /* optional; set in bit_mask
                           * FeatureRequestArg_transactionCapability_present if
                           * present */
    CallingPartyName callingPartyName;  /* optional; set in bit_mask
                                * FeatureRequestArg_callingPartyName_present if
                                * present */
} FeatureRequestArg;

typedef enum FeatureResult {   /* 92 */
    FeatureResult_not_used = 0,
    unsuccessful = 1,
    successful = 2
} FeatureResult;

typedef struct FeatureRequestRes {
    unsigned short  bit_mask;
#       define      FeatureRequestRes_accessDeniedReason_present 0x8000
#       define      FeatureRequestRes_actionCode_present 0x4000
#       define      FeatureRequestRes_announcementList_present 0x2000
#       define      FeatureRequestRes_callingPartyNumberString1_present 0x1000
#       define      FeatureRequestRes_digits_present 0x0800
#       define      FeatureRequestRes_dmh_RedirectionIndicator_present 0x0400
#       define      FeatureRequestRes_mobileDirectoryNumber_present 0x0200
#       define      FeatureRequestRes_noAnswerTime_present 0x0100
#       define      FeatureRequestRes_oneTimeFeatureIndicator_present 0x0080
#       define      FeatureRequestRes_pacIndicator_present 0x0040
#       define      FeatureRequestRes_pilotNumber_present 0x0020
#       define      FeatureRequestRes_redirectingNumberDigits_present 0x0010
#       define      FeatureRequestRes_routingDigits_present 0x0008
#       define      FeatureRequestRes_terminationTriggers_present 0x0004
#       define      callingFeaturesIndicator3_present 0x0002
#       define      FeatureRequestRes_originatingServiceFeaturesIndicator_present 0x0001
    FeatureResult   featureResult;
    AccessDeniedReason accessDeniedReason;  /* optional; set in bit_mask
                              * FeatureRequestRes_accessDeniedReason_present if
                              * present */
    ActionCode      actionCode;  /* optional; set in bit_mask
                                  * FeatureRequestRes_actionCode_present if
                                  * present */
    AnnouncementList announcementList;  /* optional; set in bit_mask
                                * FeatureRequestRes_announcementList_present if
                                * present */
    CallingPartyNumberString1 callingPartyNumberString1;  /* optional; set in
                                   * bit_mask
                       * FeatureRequestRes_callingPartyNumberString1_present if
                       * present */
    WinDigits       digits;  /* optional; set in bit_mask
                              * FeatureRequestRes_digits_present if present */
    DMH_RedirectionIndicator dmh_RedirectionIndicator;  /* optional; set in
                                   * bit_mask
                        * FeatureRequestRes_dmh_RedirectionIndicator_present if
                        * present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                           * FeatureRequestRes_mobileDirectoryNumber_present if
                           * present */
    NoAnswerTime    noAnswerTime;  /* optional; set in bit_mask
                                    * FeatureRequestRes_noAnswerTime_present if
                                    * present */
    OneTimeFeatureIndicator oneTimeFeatureIndicator;  /* optional; set in
                                   * bit_mask
                         * FeatureRequestRes_oneTimeFeatureIndicator_present if
                         * present */
    PACAIndicator   pacIndicator;  /* optional; set in bit_mask
                                    * FeatureRequestRes_pacIndicator_present if
                                    * present */
    PilotNumber     pilotNumber;  /* optional; set in bit_mask
                                   * FeatureRequestRes_pilotNumber_present if
                                   * present */
    RedirectingNumberDigits redirectingNumberDigits;  /* optional; set in
                                   * bit_mask
                         * FeatureRequestRes_redirectingNumberDigits_present if
                         * present */
    RoutingDigits   routingDigits;  /* optional; set in bit_mask
                                     * FeatureRequestRes_routingDigits_present
                                     * if present */
    struct TerminationList *terminationList;  /* NULL for not present */
    TerminationTriggers terminationTriggers;  /* optional; set in bit_mask
                             * FeatureRequestRes_terminationTriggers_present if
                             * present */
    CallingFeaturesIndicator3 callingFeaturesIndicator3;  /* optional; set in
                                   * bit_mask callingFeaturesIndicator3_present
                                   * if present */
    OriginatingServiceFeaturesIndicator originatingServiceFeaturesIndicator;  
                                        /* optional; set in bit_mask
             * FeatureRequestRes_originatingServiceFeaturesIndicator_present if
             * present */
} FeatureRequestRes;

/* Authentication: AuthenticationDirective, AuthenticationRequest, BaseStationChallenge, AuthenticationStatusReport, CountRequest, AuthenticationFailureReport */
typedef struct AuthenticationResponseUniqueChallenge {
    unsigned short  length;
    unsigned char   value[3];
} AuthenticationResponseUniqueChallenge; /* 9f25 */

typedef struct CDMAPrivateLongCodeMask {
    unsigned short  length;
    unsigned char   value[6];
} CDMAPrivateLongCodeMask; /* 9f43 */

typedef enum DenyAccess {            /*9f32 */
    DenyAccess_not_used = 0,
    DenyAccess_unspecified = 1,
    ssd_update_failure = 2,
    count_update_failure = 3,
    unique_challenge_failure = 4,
    authr_mismatch = 5,
    count_mismatch = 6,
    process_collision = 7,
    DenyAccess_missing_authentication_parameters = 8,
    DenyAccess_terminalType_mismatch = 9,
    min_or_esn_authorization_failure = 10
} DenyAccess;

typedef struct RandomVariableSSD {
    unsigned short  length;
    unsigned char   value[7];
} RandomVariableSSD; /* 9f2a */

typedef struct RandomVariableUniqueChallenge {
    unsigned short  length;
    unsigned char   value[3];
} RandomVariableUniqueChallenge; /* 9f2b */

typedef enum GMAP_Protocol_ServiceIndicator {         /* 9f8141 */
    undefined_service = 0,
    cdma_otasp_service = 1,
    tdma_otasp_service = 2,
    cdma_otapa_service = 3,
    cdma_position_determination_service = 4,
    amps_position_determination_service = 5
} GMAP_Protocol_ServiceIndicator;

typedef struct SignalingMessageEncryptionKey {
    unsigned short  length;
    unsigned char   value[8];
} SignalingMessageEncryptionKey; /* 9f2d */

typedef enum UpdateCount {            /* 9f33 */
    UpdateCount_not_used = 0,
    update_count = 1
} UpdateCount;

typedef struct AuthenticationDirectiveArg {
    unsigned short  bit_mask;
#       define      AuthenticationDirectiveArg_authenticationResponseUniqueChallenge_present 0x8000
#       define      AuthenticationDirectiveArg_cdmaPrivateLongCodeMask_present 0x4000
#       define      AuthenticationDirectiveArg_denyAccess_present 0x2000
#       define      AuthenticationDirectiveArg_locationAreaId_present 0x1000
#       define      AuthenticationDirectiveArg_randomVariableSSD_present 0x0800
#       define      AuthenticationDirectiveArg_randomVariableUniqueChallenge_present 0x0400
#       define      AuthenticationDirectiveArg_serviceIndicator_present 0x0200
#       define      signalingMessageEncryptionKey_present 0x0100
#       define      AuthenticationDirectiveArg_updateCount_present 0x0080
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    AuthenticationResponseUniqueChallenge authenticationResponseUniqueChallenge;                                        /* optional; set in bit_mask
  * AuthenticationDirectiveArg_authenticationResponseUniqueChallenge_present if
  * present */
    CDMAPrivateLongCodeMask cdmaPrivateLongCodeMask;  /* optional; set in
                                   * bit_mask
                * AuthenticationDirectiveArg_cdmaPrivateLongCodeMask_present if
                * present */
    DenyAccess      denyAccess;  /* optional; set in bit_mask
                             * AuthenticationDirectiveArg_denyAccess_present if
                             * present */
    LocationAreaID  locationAreaId;  /* optional; set in bit_mask
                         * AuthenticationDirectiveArg_locationAreaId_present if
                         * present */
                                     /* not specified in OTA */
    RandomVariableSSD randomVariableSSD;  /* optional; set in bit_mask
                      * AuthenticationDirectiveArg_randomVariableSSD_present if
                      * present */
    RandomVariableUniqueChallenge randomVariableUniqueChallenge;  /* optional;
                                   * set in bit_mask
          * AuthenticationDirectiveArg_randomVariableUniqueChallenge_present if
          * present */
    GMAP_Protocol_ServiceIndicator serviceIndicator;  /* optional; set in
                                   * bit_mask
                       * AuthenticationDirectiveArg_serviceIndicator_present if
                       * present */
    SignalingMessageEncryptionKey signalingMessageEncryptionKey;  /* optional;
                                   * set in bit_mask
                                   * signalingMessageEncryptionKey_present if
                                   * present */
    UpdateCount     updateCount;  /* optional; set in bit_mask
                            * AuthenticationDirectiveArg_updateCount_present if
                            * present */
} AuthenticationDirectiveArg;

typedef struct AuthenticationDirectiveRes {
    char            placeholder;
} AuthenticationDirectiveRes;

typedef struct ConfidentialityModes {
    unsigned short  length;
    unsigned char   value[1];
} ConfidentialityModes; /* 9f27 */

typedef struct AuthenticationData {
    unsigned short  length;
    unsigned char   value[3];
} AuthenticationData;        /* 9f8121 */

typedef struct AuthenticationResponse {
    unsigned short  length;
    unsigned char   value[3];
} AuthenticationResponse;         /* 9f23 */

typedef struct RandomVariable {
    unsigned short  length;
    unsigned char   value[4];
} RandomVariable;      /* 9f28 */

typedef struct RoamingID {
    unsigned short  length;
    unsigned char   value[5];
} RoamingID; /* 9fff7f */

typedef struct AuthenticationRequestArg {
    unsigned short  bit_mask;
#       define      AuthenticationRequestArg_authenticationData_present 0x8000
#       define      AuthenticationRequestArg_authenticationResponse_present 0x4000
#       define      AuthenticationRequestArg_callHistoryCount_present 0x2000
#       define      confidentialityModes_present 0x1000
#       define      AuthenticationRequestArg_digits_present 0x0800
#       define      AuthenticationRequestArg_pc_SSN_present 0x0400
#       define      AuthenticationRequestArg_randomVariable_present 0x0200
#       define      AuthenticationRequestArg_senderIdentificationNumber_present 0x0100
#       define      AuthenticationRequestArg_terminalType_present 0x0080
#       define      AuthenticationRequestArg_cdmaNetworkIdentification_present 0x0040
#       define      AuthenticationRequestArg_controlChannelMode_present 0x0020
#       define      AuthenticationRequestArg_serviceRedirectionCause_present 0x0010
#       define      AuthenticationRequestArg_transactionCapability_present 0x0008
#       define      AuthenticationRequestArg_roamingID_present 0x0004
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    MSCID           mscId;
    SystemAccessType systemAccessType;
    SystemCapabilities systemCapabilities;
    AuthenticationData authenticationData;  /* optional; set in bit_mask
                       * AuthenticationRequestArg_authenticationData_present if
                       * present */
    AuthenticationResponse authenticationResponse;  /* optional; set in bit_mask
                   * AuthenticationRequestArg_authenticationResponse_present if
                   * present */
    CallHistoryCount callHistoryCount;  /* optional; set in bit_mask
                         * AuthenticationRequestArg_callHistoryCount_present if
                         * present */
    ConfidentialityModes confidentialityModes;  /* optional; set in bit_mask
                                                 * confidentialityModes_present
                                                 * if present */
    WinDigits       digits;  /* optional; set in bit_mask
                              * AuthenticationRequestArg_digits_present if
                              * present */
    PC_SSN          pc_SSN;  /* optional; set in bit_mask
                              * AuthenticationRequestArg_pc_SSN_present if
                              * present */
    RandomVariable  randomVariable;  /* optional; set in bit_mask
                           * AuthenticationRequestArg_randomVariable_present if
                           * present */
    SenderIdentificationNumber senderIdentificationNumber;  /* optional; set in
                                   * bit_mask
               * AuthenticationRequestArg_senderIdentificationNumber_present if
               * present */
    TerminalType    terminalType;  /* optional; set in bit_mask
                             * AuthenticationRequestArg_terminalType_present if
                             * present */
    CDMANetworkIdentification cdmaNetworkIdentification;  /* optional; set in
                                   * bit_mask
                * AuthenticationRequestArg_cdmaNetworkIdentification_present if
                * present */
    ControlChannelMode controlChannelMode;  /* optional; set in bit_mask
                       * AuthenticationRequestArg_controlChannelMode_present if
                       * present */
    ServiceRedirectionCause serviceRedirectionCause;  /* optional; set in
                                   * bit_mask
                  * AuthenticationRequestArg_serviceRedirectionCause_present if
                  * present */
    TransactionCapability transactionCapability;  /* optional; set in bit_mask
                    * AuthenticationRequestArg_transactionCapability_present if
                    * present */
    RoamingID       roamingID;  /* optional; set in bit_mask
                                 * AuthenticationRequestArg_roamingID_present if
                                 * present */
} AuthenticationRequestArg;

typedef struct AuthenticationAlgorithmVersion {
    unsigned short  length;
    unsigned char   value[1];
} AuthenticationAlgorithmVersion; /* 9f4d */

typedef struct SharedSecretData {
    unsigned short  length;
    unsigned char   value[16];
} SharedSecretData; /* 9f2e */

typedef struct SignallingMessageEncryptionKey {
    unsigned short  length;
    unsigned char   value[8];
} SignallingMessageEncryptionKey; /* 9f2d */

typedef struct SSDNotShared {
    unsigned short  length;
    unsigned char   value[1];
} SSDNotShared; /* 9f34 */

typedef struct VoicePrivacyMask {
    unsigned short  length;
    unsigned char   value[66];
} VoicePrivacyMask; /* 9f30 */

typedef struct DataKey {
    unsigned short  length;
    unsigned char   value[4];
} DataKey; /* 9f8157 */

typedef struct AuthenticationRequestRes {
    unsigned short  bit_mask;
#       define      authenticationAlgorithmVersion_present 0x8000
#       define      AuthenticationRequestRes_authenticationResponseUniqueChallenge_present 0x4000
#       define      AuthenticationRequestRes_callHistoryCount_present 0x2000
#       define      AuthenticationRequestRes_cdmaPrivateLongCodeMask_present 0x1000
#       define      AuthenticationRequestRes_denyAccess_present 0x0800
#       define      AuthenticationRequestRes_randomVariableSSD_present 0x0400
#       define      AuthenticationRequestRes_randomVariableUniqueChallenge_present 0x0200
#       define      AuthenticationRequestRes_sharedSecretData_present 0x0100
#       define      signallingMessageEncryptionKey_present 0x0080
#       define      AuthenticationRequestRes_ssdNotShared_present 0x0040
#       define      AuthenticationRequestRes_updateCount_present 0x0020
#       define      voicePrivacyMask_present 0x0010
#       define      dataKey_present 0x0008
#       define      AuthenticationRequestRes_cdmaRedirectRecord_present 0x0004
#       define      AuthenticationRequestRes_roamingIndication_present 0x0002
#       define      AuthenticationRequestRes_serviceRedirectionInfo_present 0x0001
    AuthenticationAlgorithmVersion authenticationAlgorithmVersion;  
                                  /* optional; set in bit_mask
                                   * authenticationAlgorithmVersion_present if
                                   * present */
    AuthenticationResponseUniqueChallenge authenticationResponseUniqueChallenge;                                        /* optional; set in bit_mask
    * AuthenticationRequestRes_authenticationResponseUniqueChallenge_present if
    * present */
    CallHistoryCount callHistoryCount;  /* optional; set in bit_mask
                         * AuthenticationRequestRes_callHistoryCount_present if
                         * present */
    CDMAPrivateLongCodeMask cdmaPrivateLongCodeMask;  /* optional; set in
                                   * bit_mask
                  * AuthenticationRequestRes_cdmaPrivateLongCodeMask_present if
                  * present */
    DenyAccess      denyAccess;  /* optional; set in bit_mask
                                  * AuthenticationRequestRes_denyAccess_present
                                  * if present */
    RandomVariableSSD randomVariableSSD;  /* optional; set in bit_mask
                        * AuthenticationRequestRes_randomVariableSSD_present if
                        * present */
    RandomVariableUniqueChallenge randomVariableUniqueChallenge;  /* optional;
                                   * set in bit_mask
            * AuthenticationRequestRes_randomVariableUniqueChallenge_present if
            * present */
    SharedSecretData sharedSecretData;  /* optional; set in bit_mask
                         * AuthenticationRequestRes_sharedSecretData_present if
                         * present */
    SignallingMessageEncryptionKey signallingMessageEncryptionKey;  
                                  /* optional; set in bit_mask
                                   * signallingMessageEncryptionKey_present if
                                   * present */
    SSDNotShared    ssdNotShared;  /* optional; set in bit_mask
                             * AuthenticationRequestRes_ssdNotShared_present if
                             * present */
    UpdateCount     updateCount;  /* optional; set in bit_mask
                              * AuthenticationRequestRes_updateCount_present if
                              * present */
    VoicePrivacyMask voicePrivacyMask;  /* optional; set in bit_mask
                                         * voicePrivacyMask_present if
                                         * present */
    DataKey         dataKey;  /* optional; set in bit_mask dataKey_present if
                               * present */
    CDMARedirectRecord cdmaRedirectRecord;  /* optional; set in bit_mask
                       * AuthenticationRequestRes_cdmaRedirectRecord_present if
                       * present */
    RoamingIndication roamingIndication;  /* optional; set in bit_mask
                        * AuthenticationRequestRes_roamingIndication_present if
                        * present */
    ServiceRedirectionInfo serviceRedirectionInfo;  /* optional; set in bit_mask
                   * AuthenticationRequestRes_serviceRedirectionInfo_present if
                   * present */
} AuthenticationRequestRes;

typedef struct RandomVariableBaseStation {
    unsigned short  length;
    unsigned char   value[4];
} RandomVariableBaseStation; /* 9f29 */

typedef struct AuthenticationResponseBaseStation {
    unsigned short  length;
    unsigned char   value[3];
} AuthenticationResponseBaseStation; /* 9f24 */

typedef struct BaseStationChallengeArg {
    unsigned char   bit_mask;
#       define      BaseStationChallengeArg_serviceIndicator_present 0x80
#       define      BaseStationChallengeArg_roamingID_present 0x40
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    RandomVariableBaseStation randomVariableBaseStation;
    GMAP_Protocol_ServiceIndicator serviceIndicator;  /* optional; set in
                                   * bit_mask
                          * BaseStationChallengeArg_serviceIndicator_present if
                          * present */
    RoamingID       roamingID;  /* optional; set in bit_mask
                                 * BaseStationChallengeArg_roamingID_present if
                                 * present */
                                /* not specified in OTA */
} BaseStationChallengeArg;

typedef struct BaseStationChallengeRes {
    AuthenticationResponseBaseStation authenticationResponseBaseStation;
} BaseStationChallengeRes;

typedef enum CountUpdateReport {            /* 9f810a */
    CountUpdateReport_not_used = 0,
    count_update_not_attempted = 1,
    count_update_no_response = 2,
    count_update_successful = 3
} CountUpdateReport;

typedef enum SignalingMessageEncryptionReport {            /* 9f8142 */
    SignalingMessageEncryptionReport_not_used = 0,
    sme_enabling_not_attempted = 1,
    sme_enabling_no_response = 2,
    sme_is_enabled = 3,
    sme_enabling_failed = 4
} SignalingMessageEncryptionReport;

typedef enum SSDUpdateReport {            /* 9f811c */
    SSDUpdateReport_not_used = 0,
    ssd_update_not_attempted = 1,
    ssd_update_no_response = 2,
    ssd_update_successful = 3,
    ssd_update_failed = 4
} SSDUpdateReport;

typedef enum UniqueChallengeReport {            /* 9f7c */
    UniqueChallengeReport_not_used = 0,
    unique_challenge_not_attempted = 1,
    unique_challenge_no_response = 2,
    unique_challenge_successful = 3,
    unique_challenge_failed = 4
} UniqueChallengeReport;

typedef enum VoicePrivacyReport {            /* 9f8144 */
    VoicePrivacyReport_not_used = 0,
    vp_not_attempted = 1,
    vp_no_response = 2,
    vp_is_active = 3,
    vp_failed = 4
} VoicePrivacyReport;

typedef struct AuthenticationStatusReportArg {
    unsigned char   bit_mask;
#       define      countUpdateReport_present 0x80
#       define      AuthenticationStatusReportArg_serviceIndicator_present 0x40
#       define      AuthenticationStatusReportArg_signalingMessageEncryptionReport_present 0x20
#       define      AuthenticationStatusReportArg_ssdUpdatereport_present 0x10
#       define      AuthenticationStatusReportArg_uniqueChallengeReport_present 0x08
#       define      AuthenticationStatusReportArg_voicePrivacyReport_present 0x04
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    SystemCapabilities systemCapabilities;
    CountUpdateReport countUpdateReport;  /* optional; set in bit_mask
                                           * countUpdateReport_present if
                                           * present */
    GMAP_Protocol_ServiceIndicator serviceIndicator;  /* optional; set in
                                   * bit_mask
                    * AuthenticationStatusReportArg_serviceIndicator_present if
                    * present */
    SignalingMessageEncryptionReport signalingMessageEncryptionReport;  
                                  /* optional; set in bit_mask
    * AuthenticationStatusReportArg_signalingMessageEncryptionReport_present if
    * present */
    SSDUpdateReport ssdUpdatereport;  /* optional; set in bit_mask
                     * AuthenticationStatusReportArg_ssdUpdatereport_present if
                     * present */
    UniqueChallengeReport uniqueChallengeReport;  /* optional; set in bit_mask
               * AuthenticationStatusReportArg_uniqueChallengeReport_present if
               * present */
    VoicePrivacyReport voicePrivacyReport;  /* optional; set in bit_mask
                  * AuthenticationStatusReportArg_voicePrivacyReport_present if
                  * present */
} AuthenticationStatusReportArg;

typedef struct AuthenticationStatusReportRes {
    unsigned char   bit_mask;
#       define      AuthenticationStatusReportRes_authenticationResponseUniqueChallenge_present 0x80
#       define      AuthenticationStatusReportRes_denyAccess_present 0x40
#       define      AuthenticationStatusReportRes_randomVariableSSD_present 0x20
#       define      AuthenticationStatusReportRes_randomVariableUniqueChallenge_present 0x10
#       define      AuthenticationStatusReportRes_updateCount_present 0x08
    AuthenticationResponseUniqueChallenge authenticationResponseUniqueChallenge;                                        /* optional; set in bit_mask
   * AuthenticationStatusReportRes_authenticationResponseUniqueChallenge_present if
   * present */
    DenyAccess      denyAccess;  /* optional; set in bit_mask
                          * AuthenticationStatusReportRes_denyAccess_present if
                          * present */
    RandomVariableSSD randomVariableSSD;  /* optional; set in bit_mask
                   * AuthenticationStatusReportRes_randomVariableSSD_present if
                   * present */
    RandomVariableUniqueChallenge randomVariableUniqueChallenge;  /* optional;
                                   * set in bit_mask
       * AuthenticationStatusReportRes_randomVariableUniqueChallenge_present if
       * present */
    UpdateCount     updateCount;  /* optional; set in bit_mask
                         * AuthenticationStatusReportRes_updateCount_present if
                         * present */
} AuthenticationStatusReportRes;

typedef struct CountRequestArg {
    unsigned char   bit_mask;
#       define      CountRequestArg_senderIdentificationNumber_present 0x80
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    SenderIdentificationNumber senderIdentificationNumber;  /* optional; set in
                                   * bit_mask
                        * CountRequestArg_senderIdentificationNumber_present if
                        * present */
} CountRequestArg;

typedef struct CountRequestRes {
    unsigned char   bit_mask;
#       define      CountRequestRes_callHistoryCount_present 0x80
    CallHistoryCount callHistoryCount;  /* optional; set in bit_mask
                                  * CountRequestRes_callHistoryCount_present if
                                  * present */
} CountRequestRes;

typedef struct CallHistoryCountExpected {
    unsigned short  length;
    unsigned char   value[1];
} CallHistoryCountExpected; /* 9f4f */

typedef struct GMapAuthenticationFailureReportArg {
    unsigned char   bit_mask;
#       define      GMapAuthenticationFailureReportArg_callHistoryCount_present 0x80
#       define      callHistoryCountExpected_present 0x40
#       define      GMapAuthenticationFailureReportArg_mscId_present 0x20
#       define      GMapAuthenticationFailureReportArg_senderIdentificationNumber_present 0x10
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    ReportType      reportType;
    SystemAccessType systemAccessType;
    SystemCapabilities systemCapabilities;
    CallHistoryCount callHistoryCount;  /* optional; set in bit_mask
               * GMapAuthenticationFailureReportArg_callHistoryCount_present if
               * present */
    CallHistoryCountExpected callHistoryCountExpected;  /* optional; set in
                                   * bit_mask callHistoryCountExpected_present
                                   * if present */
    MSCID           mscId;  /* optional; set in bit_mask
                             * GMapAuthenticationFailureReportArg_mscId_present
                             * if present */
  /*reportType                  	ReportType, */
    SenderIdentificationNumber senderIdentificationNumber;  /* optional; set in
                                   * bit_mask
     * GMapAuthenticationFailureReportArg_senderIdentificationNumber_present if
     * present */
} GMapAuthenticationFailureReportArg;

typedef struct GMapAuthenticationFailureReportRes {
    unsigned short  bit_mask;
#       define      authnticationAlgorithmVersion_present 0x8000
#       define      GMapAuthenticationFailureReportRes_authenticationResponseUniqueChallenge_present 0x4000
#       define      GMapAuthenticationFailureReportRes_callHistoryCount_present 0x2000
#       define      GMapAuthenticationFailureReportRes_denyAccess_present 0x1000
#       define      GMapAuthenticationFailureReportRes_randomVariableSSD_present 0x0800
#       define      GMapAuthenticationFailureReportRes_randomVariableUniqueChallenge_present 0x0400
#       define      GMapAuthenticationFailureReportRes_sharedSecretData_present 0x0200
#       define      GMapAuthenticationFailureReportRes_ssdNotShared_present 0x0100
#       define      GMapAuthenticationFailureReportRes_terminalType_present 0x0080
#       define      GMapAuthenticationFailureReportRes_updateCount_present 0x0040
    AuthenticationAlgorithmVersion authnticationAlgorithmVersion;  /* optional;
                                   * set in bit_mask
                                   * authnticationAlgorithmVersion_present if
                                   * present */
    AuthenticationResponseUniqueChallenge authenticationResponseUniqueChallenge;                                        /* optional; set in bit_mask
        * GMapAuthenticationFailureReportRes_authenticationResponseUniqueChallenge_present if
        * present */
    CallHistoryCount callHistoryCount;  /* optional; set in bit_mask
               * GMapAuthenticationFailureReportRes_callHistoryCount_present if
               * present */
    DenyAccess      denyAccess;  /* optional; set in bit_mask
                     * GMapAuthenticationFailureReportRes_denyAccess_present if
                     * present */
    RandomVariableSSD randomVariableSSD;  /* optional; set in bit_mask
              * GMapAuthenticationFailureReportRes_randomVariableSSD_present if
              * present */
    RandomVariableUniqueChallenge randomVariableUniqueChallenge;  /* optional;
                                   * set in bit_mask
  * GMapAuthenticationFailureReportRes_randomVariableUniqueChallenge_present if
  * present */
    SharedSecretData sharedSecretData;  /* optional; set in bit_mask
               * GMapAuthenticationFailureReportRes_sharedSecretData_present if
               * present */
    SSDNotShared    ssdNotShared;  /* optional; set in bit_mask
                   * GMapAuthenticationFailureReportRes_ssdNotShared_present if
                   * present */
    TerminalType    terminalType;  /* optional; set in bit_mask
                   * GMapAuthenticationFailureReportRes_terminalType_present if
                   * present */
    UpdateCount     updateCount;  /* optional; set in bit_mask
                    * GMapAuthenticationFailureReportRes_updateCount_present if
                    * present */
} GMapAuthenticationFailureReportRes;

/* SMS */
typedef struct SMS_NotificationIndicator {
    unsigned short  length;
    unsigned char   value[1];
} SMS_NotificationIndicator; /* 9f6d */

typedef struct SMSRequestArg {
    unsigned char   bit_mask;
#       define      SMSRequestArg_mobileIdentificationNumber_present 0x80
#       define      SMSRequestArg_mobileDirectoryNumber_present 0x40
#       define      SMSRequestArg_electronicSerialNumber_present 0x20
#       define      SMSRequestArg_serviceIndicator_present 0x10
#       define      SMSRequestArg_sms_notificationIndicator_present 0x08
    MobileIdentificationNumber mobileIdentificationNumber;  /* optional; set in
                                   * bit_mask
                          * SMSRequestArg_mobileIdentificationNumber_present if
                          * present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                               * SMSRequestArg_mobileDirectoryNumber_present if
                               * present */
    ElectronicSerialNumber electronicSerialNumber;  /* optional; set in bit_mask
                              * SMSRequestArg_electronicSerialNumber_present if
                              * present */
    GMAP_Protocol_ServiceIndicator serviceIndicator;  /* optional; set in
                                   * bit_mask
                                   * SMSRequestArg_serviceIndicator_present if
                                   * present */
    SMS_NotificationIndicator sms_notificationIndicator;  /* optional; set in
                                   * bit_mask
                           * SMSRequestArg_sms_notificationIndicator_present if
                           * present */
} SMSRequestArg;

typedef struct SMS_AccessDeniedReason {
    unsigned short  length;
    unsigned char   value[1];
} SMS_AccessDeniedReason; /* 9f8118 */

/**/
/*  jdlee 2003/6/03  tags are not valid. */
/*  these tags(9f8119) are defined temporarily. */
/**/
typedef struct SMS_Capability {
    unsigned short  length;
    unsigned char   value[2];
} SMS_Capability; /* 9fff8f */

/**/
/* jdlee 2003/6/03  tags are not valid */
typedef BCDDigits       SMS_Address2; /* 9fff38 */

typedef struct SMS_SubscriberType {
    unsigned short  length;
    unsigned char   value[1];
} SMS_SubscriberType; /* 9fff21 */

typedef struct SMSRequestRes {
    unsigned char   bit_mask;
#       define      SMSRequestRes_electronicSerialNumber_present 0x80
#       define      SMSRequestRes_sms_accessDeniedReason_present 0x40
#       define      SMSRequestRes_sms_address_present 0x20
#       define      sms_address2_present 0x10
#       define      SMSRequestRes_mobileIdentificationNumber_present 0x08
#       define      SMSRequestRes_mobileDirectoryNumber_present 0x04
#       define      sms_capability_present 0x02
#       define      sms_subscriberType_present 0x01
    ElectronicSerialNumber electronicSerialNumber;  /* optional; set in bit_mask
                              * SMSRequestRes_electronicSerialNumber_present if
                              * present */
    SMS_AccessDeniedReason sms_accessDeniedReason;  /* optional; set in bit_mask
                              * SMSRequestRes_sms_accessDeniedReason_present if
                              * present */
    SMS_Address     sms_address;  /* optional; set in bit_mask
                                   * SMSRequestRes_sms_address_present if
                                   * present */
    SMS_Address2    sms_address2;  /* optional; set in bit_mask
                                    * sms_address2_present if present */
    MobileIdentificationNumber mobileIdentificationNumber;  /* optional; set in
                                   * bit_mask
                          * SMSRequestRes_mobileIdentificationNumber_present if
                          * present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                               * SMSRequestRes_mobileDirectoryNumber_present if
                               * present */
    SMS_Capability  sms_capability;  /* optional; set in bit_mask
                                      * sms_capability_present if present */
    SMS_SubscriberType sms_subscriberType;  /* optional; set in bit_mask
                                             * sms_subscriberType_present if
                                             * present */
                                            /* ¼¼´ë°£ ¹øÈ£ ÀÌµ¿ ±â´ÉÀ» À§ÇØ Ãß°¡µÊ bhtak 2005/6/1 */
} SMSRequestRes;

typedef struct MobilePositionCapability {
    unsigned short  length;
    unsigned char   value[2];
} MobilePositionCapability;   /* 9f8220 */

/* PositionRequestType ::= [289] OCTET STRING (SIZE(1))  9f8221 */
/* GeoPositionRequestArg ::= SET { */
/*  	positionRequestType			PositionRequestType, */
/*  	mobilePositionCapability	MobilePositionCapability 	OPTIONAL, */
/*  	mscId						MSCID 						OPTIONAL */
/* } */

/* PositionResult ::= [290] OCTET STRING( SIZE(1))  9f8222 */

/* */
/* GeoPositionRequestRes ::= SET { */
/* 	positionResult		PositionResult, */
/* 	positionInformation	PositionInformation	OPTIONAL */
/* } */
/* */
/* InterSystemPositionRequestArg ::= SET { */
/* 	positionRequestType			PositionRequestType, */
/* 	lcsBillingID				[1] OCTET STRING( SIZE(6))	OPTIONAL, */
/* 	mobileIdentificationNumber 	MobileIdentificationNumber	OPTIONAL, */
/* 	positionQoS					[2] OCTET STRING( SIZE(1))	OPTIONAL */
/* } */

/* InterSystemPositionRequestRes ::= SET { */
/* 	positionResult 		PositionResult				OPTIONAL, */
/* 	lcsBillingID		[1] OCTET STRING( SIZE(6))	OPTIONAL, */
/* 	mobilePositionCapability	MobilePositionCapability 	OPTIONAL, */
/* 	mscId						MSCID 						OPTIONAL, */
/* 	positionInformation	PositionInformation			OPTIONAL, */
/* 	servingCellId		[2] OCTET STRING( SIZE(1))	OPTIONAL */
/* } */
typedef struct SMSNotificationArg {
    unsigned char   bit_mask;
#       define      SMSNotificationArg_mobileDirectoryNumber_present 0x80
#       define      SMSNotificationArg_sms_accessDeniedReason_present 0x40
#       define      SMSNotificationArg_sms_address_present 0x20
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                          * SMSNotificationArg_mobileDirectoryNumber_present if
                          * present */
    SMS_AccessDeniedReason sms_accessDeniedReason;  /* optional; set in bit_mask
                         * SMSNotificationArg_sms_accessDeniedReason_present if
                         * present */
    SMS_Address     sms_address;  /* optional; set in bit_mask
                                   * SMSNotificationArg_sms_address_present if
                                   * present */
} SMSNotificationArg;

typedef struct OriginationRequestArg {
    unsigned short  bit_mask;
#       define      OriginationRequestArg_callingPartyNumberDigits1_present 0x8000
#       define      OriginationRequestArg_callingPartyNumberDigits2_present 0x4000
#       define      OriginationRequestArg_callingPartySubaddress_present 0x2000
#       define      OriginationRequestArg_mobileDirectoryNumber_present 0x1000
#       define      OriginationRequestArg_mscIdentificationNumber_present 0x0800
#       define      OriginationRequestArg_oneTimeFeatureIndicator_present 0x0400
#       define      OriginationRequestArg_pc_SSN_present 0x0200
#       define      OriginationRequestArg_senderIdentificationNumber_present 0x0100
#       define      OriginationRequestArg_callingPartyName_present 0x0080
#       define      OriginationRequestArg_locationAreaId_present 0x0040
#       define      OriginationRequestArg_servingCellId_present 0x0020
#       define      OriginationRequestArg_triggerType_present 0x0010
#       define      OriginationRequestArg_winCapability_present 0x0008
#       define      OriginationRequestArg_cdmaServiceOption_present 0x0004
#       define      OriginationRequestArg_preferredLanguageIndicator_present 0x0002
    BillingID       billingId;
    WinDigits       digits;
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    MSCID           mscId;
    OriginationTriggers originationTriggers;
    TransactionCapability transactionCapability;
    CallingPartyNumberDigits1 callingPartyNumberDigits1;  /* optional; set in
                                   * bit_mask
                   * OriginationRequestArg_callingPartyNumberDigits1_present if
                   * present */
    CallingPartyNumberDigits2 callingPartyNumberDigits2;  /* optional; set in
                                   * bit_mask
                   * OriginationRequestArg_callingPartyNumberDigits2_present if
                   * present */
    CallingPartySubaddress callingPartySubaddress;  /* optional; set in bit_mask
                      * OriginationRequestArg_callingPartySubaddress_present if
                      * present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                       * OriginationRequestArg_mobileDirectoryNumber_present if
                       * present */
    MSCIdentificationNumber mscIdentificationNumber;  /* optional; set in
                                   * bit_mask
                     * OriginationRequestArg_mscIdentificationNumber_present if
                     * present */
    OneTimeFeatureIndicator oneTimeFeatureIndicator;  /* optional; set in
                                   * bit_mask
                     * OriginationRequestArg_oneTimeFeatureIndicator_present if
                     * present */
    PC_SSN          pc_SSN;  /* optional; set in bit_mask
                              * OriginationRequestArg_pc_SSN_present if
                              * present */
    SenderIdentificationNumber senderIdentificationNumber;  /* optional; set in
                                   * bit_mask
                  * OriginationRequestArg_senderIdentificationNumber_present if
                  * present */
    CallingPartyName callingPartyName;  /* optional; set in bit_mask
                            * OriginationRequestArg_callingPartyName_present if
                            * present */
    LocationAreaID  locationAreaId;  /* optional; set in bit_mask
                              * OriginationRequestArg_locationAreaId_present if
                              * present */
    ServingCellID   servingCellId;  /* optional; set in bit_mask
                               * OriginationRequestArg_servingCellId_present if
                               * present */
    TriggerType     triggerType;  /* optional; set in bit_mask
                                   * OriginationRequestArg_triggerType_present
                                   * if present */
    WINCapability   winCapability;  /* optional; set in bit_mask
                               * OriginationRequestArg_winCapability_present if
                               * present */
    CDMAServiceOption cdmaServiceOption;  /* optional; set in bit_mask
                           * OriginationRequestArg_cdmaServiceOption_present if
                           * present */
    PreferredLanguageIndicator preferredLanguageIndicator;  /* optional; set in
                                   * bit_mask
                  * OriginationRequestArg_preferredLanguageIndicator_present if
                  * present */
} OriginationRequestArg;

typedef struct OriginationRequestRes {
    unsigned int    bit_mask;
#       define      OriginationRequestRes_accessDeniedReason_present 0x80000000
#       define      OriginationRequestRes_actionCode_present 0x40000000
#       define      OriginationRequestRes_announcementList_present 0x20000000
#       define      OriginationRequestRes_callingPartyNumberString1_present 0x10000000
#       define      OriginationRequestRes_callingPartyNumberString2_present 0x08000000
#       define      OriginationRequestRes_callingPartySubaddress_present 0x04000000
#       define      OriginationRequestRes_carrierDigits_present 0x02000000
#       define      OriginationRequestRes_digits_present 0x01000000
#       define      OriginationRequestRes_dmh_AccountCodeDigits_present 0x00800000
#       define      OriginationRequestRes_dmh_AlternateBillingDigits_present 0x00400000
#       define      OriginationRequestRes_dmh_BillingDigits_present 0x00200000
#       define      OriginationRequestRes_dmh_RedirectionIndicator_present 0x00100000
#       define      OriginationRequestRes_groupInformation_present 0x00080000
#       define      OriginationRequestRes_mobileDirectoryNumber_present 0x00040000
#       define      OriginationRequestRes_noAnswerTime_present 0x00020000
#       define      OriginationRequestRes_oneTimeFeatureIndicator_present 0x00010000
#       define      OriginationRequestRes_pilotNumber_present 0x00008000
#       define      OriginationRequestRes_redirectingNumberDigits_present 0x00004000
#       define      OriginationRequestRes_redirectingNumberString_present 0x00002000
#       define      OriginationRequestRes_redirectingSubaddress_present 0x00001000
#       define      OriginationRequestRes_routingDigits_present 0x00000800
#       define      OriginationRequestRes_terminationTriggers_present 0x00000400
#       define      OriginationRequestRes_displayText_present 0x00000200
#       define      OriginationRequestRes_triggerAddressList_present 0x00000100
#       define      OriginationRequestRes_resumePIC_present 0x00000080
    AccessDeniedReason accessDeniedReason;  /* optional; set in bit_mask
                          * OriginationRequestRes_accessDeniedReason_present if
                          * present */
    ActionCode      actionCode;  /* optional; set in bit_mask
                                  * OriginationRequestRes_actionCode_present if
                                  * present */
    AnnouncementList announcementList;  /* optional; set in bit_mask
                            * OriginationRequestRes_announcementList_present if
                            * present */
    CallingPartyNumberString1 callingPartyNumberString1;  /* optional; set in
                                   * bit_mask
                   * OriginationRequestRes_callingPartyNumberString1_present if
                   * present */
    CallingPartyNumberString2 callingPartyNumberString2;  /* optional; set in
                                   * bit_mask
                   * OriginationRequestRes_callingPartyNumberString2_present if
                   * present */
    CallingPartySubaddress callingPartySubaddress;  /* optional; set in bit_mask
                      * OriginationRequestRes_callingPartySubaddress_present if
                      * present */
    CarrierDigits   carrierDigits;  /* optional; set in bit_mask
                               * OriginationRequestRes_carrierDigits_present if
                               * present */
    WinDigits       digits;  /* optional; set in bit_mask
                              * OriginationRequestRes_digits_present if
                              * present */
    DMH_AccountCodeDigits dmh_AccountCodeDigits;  /* optional; set in bit_mask
                       * OriginationRequestRes_dmh_AccountCodeDigits_present if
                       * present */
    DMH_AlternateBillingDigits dmh_AlternateBillingDigits;  /* optional; set in
                                   * bit_mask
                  * OriginationRequestRes_dmh_AlternateBillingDigits_present if
                  * present */
    DMH_BillingDigits dmh_BillingDigits;  /* optional; set in bit_mask
                           * OriginationRequestRes_dmh_BillingDigits_present if
                           * present */
    DMH_RedirectionIndicator dmh_RedirectionIndicator;  /* optional; set in
                                   * bit_mask
                    * OriginationRequestRes_dmh_RedirectionIndicator_present if
                    * present */
    GroupInformation groupInformation;  /* optional; set in bit_mask
                            * OriginationRequestRes_groupInformation_present if
                            * present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                       * OriginationRequestRes_mobileDirectoryNumber_present if
                       * present */
    NoAnswerTime    noAnswerTime;  /* optional; set in bit_mask
                                    * OriginationRequestRes_noAnswerTime_present
                                    * if present */
    OneTimeFeatureIndicator oneTimeFeatureIndicator;  /* optional; set in
                                   * bit_mask
                     * OriginationRequestRes_oneTimeFeatureIndicator_present if
                     * present */
    PilotNumber     pilotNumber;  /* optional; set in bit_mask
                                   * OriginationRequestRes_pilotNumber_present
                                   * if present */
    RedirectingNumberDigits redirectingNumberDigits;  /* optional; set in
                                   * bit_mask
                     * OriginationRequestRes_redirectingNumberDigits_present if
                     * present */
    RedirectingNumberString redirectingNumberString;  /* optional; set in
                                   * bit_mask
                     * OriginationRequestRes_redirectingNumberString_present if
                     * present */
    RedirectingSubaddress redirectingSubaddress;  /* optional; set in bit_mask
                       * OriginationRequestRes_redirectingSubaddress_present if
                       * present */
    RoutingDigits   routingDigits;  /* optional; set in bit_mask
                               * OriginationRequestRes_routingDigits_present if
                               * present */
    TerminationTriggers terminationTriggers;  /* optional; set in bit_mask
                         * OriginationRequestRes_terminationTriggers_present if
                         * present */
    struct TerminationList *terminationList;  /* NULL for not present */
    DisplayText     displayText;  /* optional; set in bit_mask
                                   * OriginationRequestRes_displayText_present
                                   * if present */
    struct TriggerAddressList *triggerAddressList;  /* optional; set in bit_mask
                          * OriginationRequestRes_triggerAddressList_present if
                          * present */
    ResumePIC       resumePIC;  /* optional; set in bit_mask
                                 * OriginationRequestRes_resumePIC_present if
                                 * present */
} OriginationRequestRes;

typedef struct RemoteUserInteractionDirectiveArg {
    unsigned char   bit_mask;
#       define      RemoteUserInteractionDirectiveArg_digits_present 0x80
    AnnouncementList announcementList;
    DigitCollectionControl digitCollectionControl;
    WinDigits       digits;  /* optional; set in bit_mask
                              * RemoteUserInteractionDirectiveArg_digits_present
                              * if present */
} RemoteUserInteractionDirectiveArg;

typedef struct RemoteUserInteractionDirectiveRes {
    unsigned char   bit_mask;
#       define      RemoteUserInteractionDirectiveRes_digits_present 0x80
    WinDigits       digits;  /* optional; set in bit_mask
                              * RemoteUserInteractionDirectiveRes_digits_present
                              * if present */
} RemoteUserInteractionDirectiveRes;

typedef struct InformationDirectiveArg {
    unsigned short  bit_mask;
#       define      InformationDirectiveArg_alertCode_present 0x8000
#       define      InformationDirectiveArg_announcementList_present 0x4000
#       define      InformationDirectiveArg_callingPartyNumberString1_present 0x2000
#       define      InformationDirectiveArg_callingPartyNumberString2_present 0x1000
#       define      InformationDirectiveArg_callingPartySubaddress_present 0x0800
#       define      InformationDirectiveArg_redirectingNumberString_present 0x0400
#       define      InformationDirectiveArg_redirectingSubaddress_present 0x0200
#       define      InformationDirectiveArg_senderIdentificationNumber_present 0x0100
#       define      InformationDirectiveArg_displayText_present 0x0080
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    AlertCode       alertCode;  /* optional; set in bit_mask
                                 * InformationDirectiveArg_alertCode_present if
                                 * present */
    AnnouncementList announcementList;  /* optional; set in bit_mask
                          * InformationDirectiveArg_announcementList_present if
                          * present */
    CallingPartyNumberString1 callingPartyNumberString1;  /* optional; set in
                                   * bit_mask
                 * InformationDirectiveArg_callingPartyNumberString1_present if
                 * present */
    CallingPartyNumberString2 callingPartyNumberString2;  /* optional; set in
                                   * bit_mask
                 * InformationDirectiveArg_callingPartyNumberString2_present if
                 * present */
    CallingPartySubaddress callingPartySubaddress;  /* optional; set in bit_mask
                    * InformationDirectiveArg_callingPartySubaddress_present if
                    * present */
    RedirectingNumberString redirectingNumberString;  /* optional; set in
                                   * bit_mask
                   * InformationDirectiveArg_redirectingNumberString_present if
                   * present */
    RedirectingSubaddress redirectingSubaddress;  /* optional; set in bit_mask
                     * InformationDirectiveArg_redirectingSubaddress_present if
                     * present */
    SenderIdentificationNumber senderIdentificationNumber;  /* optional; set in
                                   * bit_mask
                * InformationDirectiveArg_senderIdentificationNumber_present if
                * present */
    DisplayText     displayText;  /* optional; set in bit_mask
                                   * InformationDirectiveArg_displayText_present
                                   * if present */
} InformationDirectiveArg;

typedef struct InformationDirectiveRes {
    unsigned char   bit_mask;
#       define      alertResult_present 0x80
    AlertResult     alertResult;  /* optional; set in bit_mask
                                   * alertResult_present if present */
} InformationDirectiveRes;

typedef struct TransferToNumberRequestArg {
    unsigned short  bit_mask;
#       define      TransferToNumberRequestArg_billingId_present 0x8000
#       define      TransferToNumberRequestArg_groupInformation_present 0x4000
#       define      TransferToNumberRequestArg_legInformation_present 0x2000
#       define      TransferToNumberRequestArg_mscIdentificationNumber_present 0x1000
#       define      TransferToNumberRequestArg_pilotBillingId_present 0x0800
#       define      TransferToNumberRequestArg_pilotNumber_present 0x0400
#       define      TransferToNumberRequestArg_transactionCapability_present 0x0200
#       define      TransferToNumberRequestArg_senderIdentificationNumber_present 0x0100
#       define      TransferToNumberRequestArg_cdmaServiceOption_present 0x0080
#       define      TransferToNumberRequestArg_callingPartyName_present 0x0040
#       define      TransferToNumberRequestArg_callingPartyNumberDigits1_present 0x0020
#       define      TransferToNumberRequestArg_callingPartyNumberDigits2_present 0x0010
#       define      TransferToNumberRequestArg_callingPartySubaddress_present 0x0008
#       define      TransferToNumberRequestArg_originatingServiceFeaturesIndicator_present 0x0004
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    RedirectionReason redirectionReason;
    SystemMyTypeCode systemMyTypeCode;
    BillingID       billingId;  /* optional; set in bit_mask
                                 * TransferToNumberRequestArg_billingId_present
                                 * if present */
    GroupInformation groupInformation;  /* optional; set in bit_mask
                       * TransferToNumberRequestArg_groupInformation_present if
                       * present */
    LegInformation  legInformation;  /* optional; set in bit_mask
                         * TransferToNumberRequestArg_legInformation_present if
                         * present */
    MSCIdentificationNumber mscIdentificationNumber;  /* optional; set in
                                   * bit_mask
                * TransferToNumberRequestArg_mscIdentificationNumber_present if
                * present */
    PilotBillingID  pilotBillingId;  /* optional; set in bit_mask
                         * TransferToNumberRequestArg_pilotBillingId_present if
                         * present */
    PilotNumber     pilotNumber;  /* optional; set in bit_mask
                            * TransferToNumberRequestArg_pilotNumber_present if
                            * present */
    TransactionCapability transactionCapability;  /* optional; set in bit_mask
                  * TransferToNumberRequestArg_transactionCapability_present if
                  * present */
    SenderIdentificationNumber senderIdentificationNumber;  /* optional; set in
                                   * bit_mask
             * TransferToNumberRequestArg_senderIdentificationNumber_present if
             * present */
    CDMAServiceOption cdmaServiceOption;  /* optional; set in bit_mask
                      * TransferToNumberRequestArg_cdmaServiceOption_present if
                      * present */
    CallingPartyName callingPartyName;  /* optional; set in bit_mask
                       * TransferToNumberRequestArg_callingPartyName_present if
                       * present */
    CallingPartyNumberDigits1 callingPartyNumberDigits1;  /* optional; set in
                                   * bit_mask
              * TransferToNumberRequestArg_callingPartyNumberDigits1_present if
              * present */
    CallingPartyNumberDigits2 callingPartyNumberDigits2;  /* optional; set in
                                   * bit_mask
              * TransferToNumberRequestArg_callingPartyNumberDigits2_present if
              * present */
    CallingPartySubaddress callingPartySubaddress;  /* optional; set in bit_mask
                 * TransferToNumberRequestArg_callingPartySubaddress_present if
                 * present */
    OriginatingServiceFeaturesIndicator originatingServiceFeaturesIndicator;  
                                        /* optional; set in bit_mask
    * TransferToNumberRequestArg_originatingServiceFeaturesIndicator_present if
    * present */
} TransferToNumberRequestArg;

typedef struct TransferToNumberRequestRes {
    unsigned int    bit_mask;
#       define      TransferToNumberRequestRes_accessDeniedReason_present 0x80000000
#       define      TransferToNumberRequestRes_actionCode_present 0x40000000
#       define      TransferToNumberRequestRes_announcementList_present 0x20000000
#       define      TransferToNumberRequestRes_callingPartyNumberString1_present 0x10000000
#       define      TransferToNumberRequestRes_callingPartyNumberString2_present 0x08000000
#       define      TransferToNumberRequestRes_callingPartySubaddress_present 0x04000000
#       define      TransferToNumberRequestRes_digitsCarrier_present 0x02000000
#       define      TransferToNumberRequestRes_dmh_AccountCodeDigits_present 0x01000000
#       define      TransferToNumberRequestRes_dmh_AlternateBillingDigits_present 0x00800000
#       define      TransferToNumberRequestRes_dmh_BillingDigits_present 0x00400000
#       define      TransferToNumberRequestRes_dmh_RedirectionIndicator_present 0x00200000
#       define      TransferToNumberRequestRes_groupInformation_present 0x00100000
#       define      TransferToNumberRequestRes_mobileDirectoryNumber_present 0x00080000
#       define      TransferToNumberRequestRes_noAnswerTime_present 0x00040000
#       define      TransferToNumberRequestRes_redirectingNumberDigits_present 0x00020000
#       define      TransferToNumberRequestRes_redirectingNumberString_present 0x00010000
#       define      TransferToNumberRequestRes_redirectingSubaddress_present 0x00008000
#       define      TransferToNumberRequestRes_terminationTriggers_present 0x00004000
#       define      TransferToNumberRequestRes_displayText_present 0x00002000
  /* NOTE: */
  /* in GMAP spec. digitsCarrier and digitsDest have the same tag values. */
  /* we changes the digitsCarrier tag with  one of CarrierDigit, and use the structere in application */
  /* for the encoded msg. it is necessary to change the tag value manually. */
    WinDigits       digitsDest;
    AccessDeniedReason accessDeniedReason;  /* optional; set in bit_mask
                     * TransferToNumberRequestRes_accessDeniedReason_present if
                     * present */
    ActionCode      actionCode;  /* optional; set in bit_mask
                             * TransferToNumberRequestRes_actionCode_present if
                             * present */
    AnnouncementList announcementList;  /* optional; set in bit_mask
                       * TransferToNumberRequestRes_announcementList_present if
                       * present */
    CallingPartyNumberString1 callingPartyNumberString1;  /* optional; set in
                                   * bit_mask
              * TransferToNumberRequestRes_callingPartyNumberString1_present if
              * present */
    CallingPartyNumberString2 callingPartyNumberString2;  /* optional; set in
                                   * bit_mask
              * TransferToNumberRequestRes_callingPartyNumberString2_present if
              * present */
    CallingPartySubaddress callingPartySubaddress;  /* optional; set in bit_mask
                 * TransferToNumberRequestRes_callingPartySubaddress_present if
                 * present */
    CarrierDigits   digitsCarrier;  /* optional; set in bit_mask
                          * TransferToNumberRequestRes_digitsCarrier_present if
                          * present */
                                    /* see NOTE above */
    DMH_AccountCodeDigits dmh_AccountCodeDigits;  /* optional; set in bit_mask
                  * TransferToNumberRequestRes_dmh_AccountCodeDigits_present if
                  * present */
    DMH_AlternateBillingDigits dmh_AlternateBillingDigits;  /* optional; set in
                                   * bit_mask
             * TransferToNumberRequestRes_dmh_AlternateBillingDigits_present if
             * present */
    DMH_BillingDigits dmh_BillingDigits;  /* optional; set in bit_mask
                      * TransferToNumberRequestRes_dmh_BillingDigits_present if
                      * present */
    DMH_RedirectionIndicator dmh_RedirectionIndicator;  /* optional; set in
                                   * bit_mask
               * TransferToNumberRequestRes_dmh_RedirectionIndicator_present if
               * present */
    GroupInformation groupInformation;  /* optional; set in bit_mask
                       * TransferToNumberRequestRes_groupInformation_present if
                       * present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                  * TransferToNumberRequestRes_mobileDirectoryNumber_present if
                  * present */
    NoAnswerTime    noAnswerTime;  /* optional; set in bit_mask
                           * TransferToNumberRequestRes_noAnswerTime_present if
                           * present */
    RedirectingNumberDigits redirectingNumberDigits;  /* optional; set in
                                   * bit_mask
                * TransferToNumberRequestRes_redirectingNumberDigits_present if
                * present */
    RedirectingNumberString redirectingNumberString;  /* optional; set in
                                   * bit_mask
                * TransferToNumberRequestRes_redirectingNumberString_present if
                * present */
    RedirectingSubaddress redirectingSubaddress;  /* optional; set in bit_mask
                  * TransferToNumberRequestRes_redirectingSubaddress_present if
                  * present */
    struct TerminationList *terminationList;  /* NULL for not present */
    TerminationTriggers terminationTriggers;  /* optional; set in bit_mask
                    * TransferToNumberRequestRes_terminationTriggers_present if
                    * present */
    DisplayText     displayText;  /* optional; set in bit_mask
                            * TransferToNumberRequestRes_displayText_present if
                            * present */
} TransferToNumberRequestRes;

typedef struct MSInactiveArg {
    unsigned char   bit_mask;
#       define      MSInactiveArg_callHistoryCount_present 0x80
#       define      deregistrationType_present 0x40
#       define      MSInactiveArg_locationAreaId_present 0x20
#       define      MSInactiveArg_senderIdentificationNumber_present 0x10
#       define      MSInactiveArg_sms_MessageWaitingIndicator_present 0x08
#       define      MSInactiveArg_authenticationPeriodCount_present 0x04
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    CallHistoryCount callHistoryCount;  /* optional; set in bit_mask
                                    * MSInactiveArg_callHistoryCount_present if
                                    * present */
    DeregistrationType deregistrationType;  /* optional; set in bit_mask
                                             * deregistrationType_present if
                                             * present */
    LocationAreaID  locationAreaId;  /* optional; set in bit_mask
                                      * MSInactiveArg_locationAreaId_present if
                                      * present */
    SenderIdentificationNumber senderIdentificationNumber;  /* optional; set in
                                   * bit_mask
                          * MSInactiveArg_senderIdentificationNumber_present if
                          * present */
    SMS_MessageWaitingIndicator sms_MessageWaitingIndicator;  /* optional; set
                                   * in bit_mask
                         * MSInactiveArg_sms_MessageWaitingIndicator_present if
                         * present */
    AuthenticationPeriodCount authenticationPeriodCount;  /* optional; set in
                                   * bit_mask
                           * MSInactiveArg_authenticationPeriodCount_present if
                           * present */
} MSInactiveArg;

typedef struct MSInactiveRes {
    char            placeholder;
} MSInactiveRes;

typedef struct UnreliableRoamerDataDirectiveArg {
    unsigned char   bit_mask;
#       define      UnreliableRoamerDataDirectiveArg_mscId_present 0x80
#       define      UnreliableRoamerDataDirectiveArg_senderIdentificationNumber_present 0x40
    MSCID           mscId;  /* optional; set in bit_mask
                             * UnreliableRoamerDataDirectiveArg_mscId_present if
                             * present */
    SenderIdentificationNumber senderIdentificationNumber;  /* optional; set in
                                   * bit_mask
       * UnreliableRoamerDataDirectiveArg_senderIdentificationNumber_present if
       * present */
} UnreliableRoamerDataDirectiveArg;

typedef struct QualificationRequestArg {
    unsigned short  bit_mask;
#       define      QualificationRequestArg_mobileDirectoryNumber_present 0x8000
#       define      QualificationRequestArg_mscId_present 0x4000
#       define      QualificationRequestArg_senderIdentificationNumber_present 0x2000
#       define      QualificationRequestArg_systemAccessType_present 0x1000
#       define      QualificationRequestArg_transactionCapability_present 0x0800
#       define      QualificationRequestArg_cdmaNetworkIdentification_present 0x0400
#       define      QualificationRequestArg_controlChannelMode_present 0x0200
#       define      QualificationRequestArg_serviceRedirectionCause_present 0x0100
#       define      QualificationRequestArg_terminalType_present 0x0080
#       define      QualificationRequestArg_winCapability_present 0x0040
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    QualificationInformationCode qualificationInformationCode;
    SystemMyTypeCode systemMyTypeCode;
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                     * QualificationRequestArg_mobileDirectoryNumber_present if
                     * present */
    MSCID           mscId;  /* optional; set in bit_mask
                             * QualificationRequestArg_mscId_present if
                             * present */
    SenderIdentificationNumber senderIdentificationNumber;  /* optional; set in
                                   * bit_mask
                * QualificationRequestArg_senderIdentificationNumber_present if
                * present */
    SystemAccessType systemAccessType;  /* optional; set in bit_mask
                          * QualificationRequestArg_systemAccessType_present if
                          * present */
    TransactionCapability transactionCapability;  /* optional; set in bit_mask
                     * QualificationRequestArg_transactionCapability_present if
                     * present */
    CDMANetworkIdentification cdmaNetworkIdentification;  /* optional; set in
                                   * bit_mask
                 * QualificationRequestArg_cdmaNetworkIdentification_present if
                 * present */
    ControlChannelMode controlChannelMode;  /* optional; set in bit_mask
                        * QualificationRequestArg_controlChannelMode_present if
                        * present */
    ServiceRedirectionCause serviceRedirectionCause;  /* optional; set in
                                   * bit_mask
                   * QualificationRequestArg_serviceRedirectionCause_present if
                   * present */
    TerminalType    terminalType;  /* optional; set in bit_mask
                              * QualificationRequestArg_terminalType_present if
                              * present */
    WINCapability   winCapability;  /* optional; set in bit_mask
                             * QualificationRequestArg_winCapability_present if
                             * present */
} QualificationRequestArg;

typedef struct QualificationRequestRes {
    unsigned char   bit_mask[6];
#       define      QualificationRequestRes_authorizationDenied_present 0x80
#       define      QualificationRequestRes_authorizationDenied_present_byte 0
#       define      QualificationRequestRes_authorizationPeriod_present 0x40
#       define      QualificationRequestRes_authorizationPeriod_present_byte 0
#       define      QualificationRequestRes_deniedAuthorizationPeriod_present 0x20
#       define      QualificationRequestRes_deniedAuthorizationPeriod_present_byte 0
#       define      QualificationRequestRes_digits_present 0x10
#       define      QualificationRequestRes_digits_present_byte 0
#       define      QualificationRequestRes_mscId_present 0x08
#       define      QualificationRequestRes_mscId_present_byte 0
#       define      QualificationRequestRes_authenticationCapability_present 0x04
#       define      QualificationRequestRes_authenticationCapability_present_byte 0
#       define      QualificationRequestRes_authenticationAttemptPoint_present 0x02
#       define      QualificationRequestRes_authenticationAttemptPoint_present_byte 0
#       define      QualificationRequestRes_authenticationPeriodCount_present 0x01
#       define      QualificationRequestRes_authenticationPeriodCount_present_byte 0
#       define      QualificationRequestRes_callingFeaturesIndicator_present 0x80
#       define      QualificationRequestRes_callingFeaturesIndicator_present_byte 1
#       define      QualificationRequestRes_carrierDigits_present 0x40
#       define      QualificationRequestRes_carrierDigits_present_byte 1
#       define      QualificationRequestRes_dmh_AccountCodeDigits_present 0x20
#       define      QualificationRequestRes_dmh_AccountCodeDigits_present_byte 1
#       define      QualificationRequestRes_dmh_AlternateBillingDigits_present 0x10
#       define      QualificationRequestRes_dmh_AlternateBillingDigits_present_byte 1
#       define      QualificationRequestRes_dmh_BillingDigits_present 0x08
#       define      QualificationRequestRes_dmh_BillingDigits_present_byte 1
#       define      QualificationRequestRes_geographicAuthorization_present 0x04
#       define      QualificationRequestRes_geographicAuthorization_present_byte 1
#       define      QualificationRequestRes_messageWaitingNotificationCount_present 0x02
#       define      QualificationRequestRes_messageWaitingNotificationCount_present_byte 1
#       define      QualificationRequestRes_messageWaitingNotificationType_present 0x01
#       define      QualificationRequestRes_messageWaitingNotificationType_present_byte 1
#       define      QualificationRequestRes_mobileDirectoryNumber_present 0x80
#       define      QualificationRequestRes_mobileDirectoryNumber_present_byte 2
#       define      QualificationRequestRes_originationIndicator_present 0x40
#       define      QualificationRequestRes_originationIndicator_present_byte 2
#       define      QualificationRequestRes_originationTriggers_present 0x20
#       define      QualificationRequestRes_originationTriggers_present_byte 2
#       define      QualificationRequestRes_pacIndicator_present 0x10
#       define      QualificationRequestRes_pacIndicator_present_byte 2
#       define      QualificationRequestRes_preferredLanguageIndicator_present 0x08
#       define      QualificationRequestRes_preferredLanguageIndicator_present_byte 2
#       define      QualificationRequestRes_restrictionDigits_present 0x04
#       define      QualificationRequestRes_restrictionDigits_present_byte 2
#       define      QualificationRequestRes_routingDigits_present 0x02
#       define      QualificationRequestRes_routingDigits_present_byte 2
#       define      QualificationRequestRes_sms_OriginationRestrictions_present 0x01
#       define      QualificationRequestRes_sms_OriginationRestrictions_present_byte 2
#       define      QualificationRequestRes_sms_TerminationRestrictions_present 0x80
#       define      QualificationRequestRes_sms_TerminationRestrictions_present_byte 3
#       define      QualificationRequestRes_spiniPin_present 0x40
#       define      QualificationRequestRes_spiniPin_present_byte 3
#       define      QualificationRequestRes_spiniTriggers_present 0x20
#       define      QualificationRequestRes_spiniTriggers_present_byte 3
#       define      QualificationRequestRes_terminationRestrictionCode_present 0x10
#       define      QualificationRequestRes_terminationRestrictionCode_present_byte 3
#       define      QualificationRequestRes_terminationTriggers_present 0x08
#       define      QualificationRequestRes_terminationTriggers_present_byte 3
#       define      QualificationRequestRes_triggerAddressList_present 0x04
#       define      QualificationRequestRes_triggerAddressList_present_byte 3
#       define      QualificationRequestRes_cdmaServiceOptionList_present 0x02
#       define      QualificationRequestRes_cdmaServiceOptionList_present_byte 3
#       define      QualificationRequestRes_callingFeaturesIndicator2_present 0x01
#       define      QualificationRequestRes_callingFeaturesIndicator2_present_byte 3
#       define      QualificationRequestRes_originatingServiceFeaturesIndicator_present 0x80
#       define      QualificationRequestRes_originatingServiceFeaturesIndicator_present_byte 4
#       define      QualificationRequestRes_terminatingServiceFeaturesIndicator_present 0x40
#       define      QualificationRequestRes_terminatingServiceFeaturesIndicator_present_byte 4
#       define      QualificationRequestRes_routingDigits2_present 0x20
#       define      QualificationRequestRes_routingDigits2_present_byte 4
#       define      QualificationRequestRes_chargingCategory_present 0x10
#       define      QualificationRequestRes_chargingCategory_present_byte 4
#       define      QualificationRequestRes_verifyChargingIndicator_present 0x08
#       define      QualificationRequestRes_verifyChargingIndicator_present_byte 4
#       define      QualificationRequestRes_verifyChargingStartTime_present 0x04
#       define      QualificationRequestRes_verifyChargingStartTime_present_byte 4
#       define      QualificationRequestRes_verifyChargingEndTime_present 0x02
#       define      QualificationRequestRes_verifyChargingEndTime_present_byte 4
#       define      QualificationRequestRes_cdmaRedirectRecord_present 0x01
#       define      QualificationRequestRes_cdmaRedirectRecord_present_byte 4
#       define      QualificationRequestRes_serviceRedirectionInfo_present 0x80
#       define      QualificationRequestRes_serviceRedirectionInfo_present_byte 5
#       define      QualificationRequestRes_roamingIndication_present 0x40
#       define      QualificationRequestRes_roamingIndication_present_byte 5
    SystemMyTypeCode systemMyTypeCode;
    AuthorizationDenied authorizationDenied;  /* optional; set in bit_mask
                       * QualificationRequestRes_authorizationDenied_present if
                       * present */
    AuthorizationPeriod authorizationPeriod;  /* optional; set in bit_mask
                       * QualificationRequestRes_authorizationPeriod_present if
                       * present */
    DeniedAuthorizationPeriod deniedAuthorizationPeriod;  /* optional; set in
                                   * bit_mask
                 * QualificationRequestRes_deniedAuthorizationPeriod_present if
                 * present */
    WinDigits       digits;  /* optional; set in bit_mask
                              * QualificationRequestRes_digits_present if
                              * present */
    MSCID           mscId;  /* optional; set in bit_mask
                             * QualificationRequestRes_mscId_present if
                             * present */
    AuthenticationCapability authenticationCapability;  /* optional; set in
                                   * bit_mask
                  * QualificationRequestRes_authenticationCapability_present if
                  * present */
    AuthenticationAttemptPoint authenticationAttemptPoint;  /* optional; set in
                                   * bit_mask
                * QualificationRequestRes_authenticationAttemptPoint_present if
                * present */
    AuthenticationPeriodCount authenticationPeriodCount;  /* optional; set in
                                   * bit_mask
                 * QualificationRequestRes_authenticationPeriodCount_present if
                 * present */
    CallingFeaturesIndicator callingFeaturesIndicator;  /* optional; set in
                                   * bit_mask
                  * QualificationRequestRes_callingFeaturesIndicator_present if
                  * present */
    CarrierDigits   carrierDigits;  /* optional; set in bit_mask
                             * QualificationRequestRes_carrierDigits_present if
                             * present */
    DMH_AccountCodeDigits dmh_AccountCodeDigits;  /* optional; set in bit_mask
                     * QualificationRequestRes_dmh_AccountCodeDigits_present if
                     * present */
    DMH_AlternateBillingDigits dmh_AlternateBillingDigits;  /* optional; set in
                                   * bit_mask
                * QualificationRequestRes_dmh_AlternateBillingDigits_present if
                * present */
    DMH_BillingDigits dmh_BillingDigits;  /* optional; set in bit_mask
                         * QualificationRequestRes_dmh_BillingDigits_present if
                         * present */
    GeographicAuthorization geographicAuthorization;  /* optional; set in
                                   * bit_mask
                   * QualificationRequestRes_geographicAuthorization_present if
                   * present */
    MessageWaitingNotificationCount messageWaitingNotificationCount;  
                                  /* optional; set in bit_mask
           * QualificationRequestRes_messageWaitingNotificationCount_present if
           * present */
    MessageWaitingNotificationType messageWaitingNotificationType;  
                                  /* optional; set in bit_mask
            * QualificationRequestRes_messageWaitingNotificationType_present if
            * present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                     * QualificationRequestRes_mobileDirectoryNumber_present if
                     * present */
    OriginationIndicator originationIndicator;  /* optional; set in bit_mask
                      * QualificationRequestRes_originationIndicator_present if
                      * present */
    OriginationTriggers originationTriggers;  /* optional; set in bit_mask
                       * QualificationRequestRes_originationTriggers_present if
                       * present */
    PACAIndicator   pacIndicator;  /* optional; set in bit_mask
                              * QualificationRequestRes_pacIndicator_present if
                              * present */
    PreferredLanguageIndicator preferredLanguageIndicator;  /* optional; set in
                                   * bit_mask
                * QualificationRequestRes_preferredLanguageIndicator_present if
                * present */
    RestrictionDigits restrictionDigits;  /* optional; set in bit_mask
                         * QualificationRequestRes_restrictionDigits_present if
                         * present */
    RoutingDigits   routingDigits;  /* optional; set in bit_mask
                             * QualificationRequestRes_routingDigits_present if
                             * present */
    SMS_OriginationRestrictions sms_OriginationRestrictions;  /* optional; set
                                   * in bit_mask
               * QualificationRequestRes_sms_OriginationRestrictions_present if
               * present */
    SMS_TerminationRestrictions sms_TerminationRestrictions;  /* optional; set
                                   * in bit_mask
               * QualificationRequestRes_sms_TerminationRestrictions_present if
               * present */
    SPINIPIN        spiniPin;  /* optional; set in bit_mask
                                * QualificationRequestRes_spiniPin_present if
                                * present */
    SPINITriggers   spiniTriggers;  /* optional; set in bit_mask
                             * QualificationRequestRes_spiniTriggers_present if
                             * present */
    TerminationRestrictionCode terminationRestrictionCode;  /* optional; set in
                                   * bit_mask
                * QualificationRequestRes_terminationRestrictionCode_present if
                * present */
    TerminationTriggers terminationTriggers;  /* optional; set in bit_mask
                       * QualificationRequestRes_terminationTriggers_present if
                       * present */
    struct TriggerAddressList *triggerAddressList;  /* optional; set in bit_mask
                        * QualificationRequestRes_triggerAddressList_present if
                        * present */
    CDMAServiceOptionList cdmaServiceOptionList;  /* optional; set in bit_mask
                     * QualificationRequestRes_cdmaServiceOptionList_present if
                     * present */
    CallingFeaturesIndicator2 callingFeaturesIndicator2;  /* optional; set in
                                   * bit_mask
                 * QualificationRequestRes_callingFeaturesIndicator2_present if
                 * present */
    OriginatingServiceFeaturesIndicator originatingServiceFeaturesIndicator;  
                                        /* optional; set in bit_mask
       * QualificationRequestRes_originatingServiceFeaturesIndicator_present if
       * present */
    TerminatingServiceFeaturesIndicator terminatingServiceFeaturesIndicator;  
                                        /* optional; set in bit_mask
       * QualificationRequestRes_terminatingServiceFeaturesIndicator_present if
       * present */
    RoutingDigits2  routingDigits2;  /* optional; set in bit_mask
                            * QualificationRequestRes_routingDigits2_present if
                            * present */
    ChargingCategory chargingCategory;  /* optional; set in bit_mask
                          * QualificationRequestRes_chargingCategory_present if
                          * present */
    VerifyChargingIndicator verifyChargingIndicator;  /* optional; set in
                                   * bit_mask
                   * QualificationRequestRes_verifyChargingIndicator_present if
                   * present */
    VerifyChargingStartTime verifyChargingStartTime;  /* optional; set in
                                   * bit_mask
                   * QualificationRequestRes_verifyChargingStartTime_present if
                   * present */
    VerifyChargingEndTime verifyChargingEndTime;  /* optional; set in bit_mask
                     * QualificationRequestRes_verifyChargingEndTime_present if
                     * present */
    CDMARedirectRecord cdmaRedirectRecord;  /* optional; set in bit_mask
                        * QualificationRequestRes_cdmaRedirectRecord_present if
                        * present */
    ServiceRedirectionInfo serviceRedirectionInfo;  /* optional; set in bit_mask
                    * QualificationRequestRes_serviceRedirectionInfo_present if
                    * present */
    RoamingIndication roamingIndication;  /* optional; set in bit_mask
                         * QualificationRequestRes_roamingIndication_present if
                         * present */
} QualificationRequestRes;

typedef struct QualificationDirectiveArg {
    unsigned char   bit_mask[5];
#       define      QualificationDirectiveArg_authorizationDenied_present 0x80
#       define      QualificationDirectiveArg_authorizationDenied_present_byte 0
#       define      QualificationDirectiveArg_authorizationPeriod_present 0x40
#       define      QualificationDirectiveArg_authorizationPeriod_present_byte 0
#       define      QualificationDirectiveArg_digitsDest_present 0x20
#       define      QualificationDirectiveArg_digitsDest_present_byte 0
#       define      QualificationDirectiveArg_locationAreaId_present 0x10
#       define      QualificationDirectiveArg_locationAreaId_present_byte 0
#       define      QualificationDirectiveArg_authenticationCapability_present 0x08
#       define      QualificationDirectiveArg_authenticationCapability_present_byte 0
#       define      QualificationDirectiveArg_authenticationAttemptPoint_present 0x04
#       define      QualificationDirectiveArg_authenticationAttemptPoint_present_byte 0
#       define      QualificationDirectiveArg_authenticationPeriodCount_present 0x02
#       define      QualificationDirectiveArg_authenticationPeriodCount_present_byte 0
#       define      QualificationDirectiveArg_callingFeaturesIndicator_present 0x01
#       define      QualificationDirectiveArg_callingFeaturesIndicator_present_byte 0
#       define      QualificationDirectiveArg_carrierDigits_present 0x80
#       define      QualificationDirectiveArg_carrierDigits_present_byte 1
#       define      QualificationDirectiveArg_dmh_AccountCodeDigits_present 0x40
#       define      QualificationDirectiveArg_dmh_AccountCodeDigits_present_byte 1
#       define      QualificationDirectiveArg_dmh_AlternateBillingDigits_present 0x20
#       define      QualificationDirectiveArg_dmh_AlternateBillingDigits_present_byte 1
#       define      QualificationDirectiveArg_dmh_BillingDigits_present 0x10
#       define      QualificationDirectiveArg_dmh_BillingDigits_present_byte 1
#       define      QualificationDirectiveArg_geographicAuthorization_present 0x08
#       define      QualificationDirectiveArg_geographicAuthorization_present_byte 1
#       define      QualificationDirectiveArg_messageWaitingNotificationCount_present 0x04
#       define      QualificationDirectiveArg_messageWaitingNotificationCount_present_byte 1
#       define      QualificationDirectiveArg_messageWaitingNotificationType_present 0x02
#       define      QualificationDirectiveArg_messageWaitingNotificationType_present_byte 1
#       define      QualificationDirectiveArg_mobileDirectoryNumber_present 0x01
#       define      QualificationDirectiveArg_mobileDirectoryNumber_present_byte 1
#       define      QualificationDirectiveArg_originationIndicator_present 0x80
#       define      QualificationDirectiveArg_originationIndicator_present_byte 2
#       define      QualificationDirectiveArg_originationTriggers_present 0x40
#       define      QualificationDirectiveArg_originationTriggers_present_byte 2
#       define      QualificationDirectiveArg_pacIndicator_present 0x20
#       define      QualificationDirectiveArg_pacIndicator_present_byte 2
#       define      QualificationDirectiveArg_preferredLanguageIndicator_present 0x10
#       define      QualificationDirectiveArg_preferredLanguageIndicator_present_byte 2
#       define      QualificationDirectiveArg_restrictionDigits_present 0x08
#       define      QualificationDirectiveArg_restrictionDigits_present_byte 2
#       define      QualificationDirectiveArg_routingDigits_present 0x04
#       define      QualificationDirectiveArg_routingDigits_present_byte 2
#       define      QualificationDirectiveArg_sms_OriginationRestrictions_present 0x02
#       define      QualificationDirectiveArg_sms_OriginationRestrictions_present_byte 2
#       define      QualificationDirectiveArg_sms_TerminationRestrictions_present 0x01
#       define      QualificationDirectiveArg_sms_TerminationRestrictions_present_byte 2
#       define      QualificationDirectiveArg_spiniPin_present 0x80
#       define      QualificationDirectiveArg_spiniPin_present_byte 3
#       define      QualificationDirectiveArg_spiniTriggers_present 0x40
#       define      QualificationDirectiveArg_spiniTriggers_present_byte 3
#       define      QualificationDirectiveArg_terminationRestrictionCode_present 0x20
#       define      QualificationDirectiveArg_terminationRestrictionCode_present_byte 3
#       define      QualificationDirectiveArg_terminationTriggers_present 0x10
#       define      QualificationDirectiveArg_terminationTriggers_present_byte 3
#       define      QualificationDirectiveArg_triggerAddressList_present 0x08
#       define      QualificationDirectiveArg_triggerAddressList_present_byte 3
#       define      QualificationDirectiveArg_cdmaServiceOptionList_present 0x04
#       define      QualificationDirectiveArg_cdmaServiceOptionList_present_byte 3
#       define      QualificationDirectiveArg_callingFeaturesIndicator2_present 0x02
#       define      QualificationDirectiveArg_callingFeaturesIndicator2_present_byte 3
#       define      QualificationDirectiveArg_originatingServiceFeaturesIndicator_present 0x01
#       define      QualificationDirectiveArg_originatingServiceFeaturesIndicator_present_byte 3
#       define      QualificationDirectiveArg_terminatingServiceFeaturesIndicator_present 0x80
#       define      QualificationDirectiveArg_terminatingServiceFeaturesIndicator_present_byte 4
#       define      QualificationDirectiveArg_routingDigits2_present 0x40
#       define      QualificationDirectiveArg_routingDigits2_present_byte 4
#       define      QualificationDirectiveArg_chargingCategory_present 0x20
#       define      QualificationDirectiveArg_chargingCategory_present_byte 4
#       define      QualificationDirectiveArg_verifyChargingIndicator_present 0x10
#       define      QualificationDirectiveArg_verifyChargingIndicator_present_byte 4
#       define      QualificationDirectiveArg_verifyChargingStartTime_present 0x08
#       define      QualificationDirectiveArg_verifyChargingStartTime_present_byte 4
#       define      QualificationDirectiveArg_verifyChargingEndTime_present 0x04
#       define      QualificationDirectiveArg_verifyChargingEndTime_present_byte 4
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    QualificationInformationCode qualificationInformationCode;
    SystemMyTypeCode systemMyTypeCode;
    AuthorizationDenied authorizationDenied;  /* optional; set in bit_mask
                     * QualificationDirectiveArg_authorizationDenied_present if
                     * present */
    AuthorizationPeriod authorizationPeriod;  /* optional; set in bit_mask
                     * QualificationDirectiveArg_authorizationPeriod_present if
                     * present */
    WinDigits       digitsDest;  /* optional; set in bit_mask
                                  * QualificationDirectiveArg_digitsDest_present
                                  * if present */
    LocationAreaID  locationAreaId;  /* optional; set in bit_mask
                          * QualificationDirectiveArg_locationAreaId_present if
                          * present */
    AuthenticationCapability authenticationCapability;  /* optional; set in
                                   * bit_mask
                * QualificationDirectiveArg_authenticationCapability_present if
                * present */
    AuthenticationAttemptPoint authenticationAttemptPoint;  /* optional; set in
                                   * bit_mask
              * QualificationDirectiveArg_authenticationAttemptPoint_present if
              * present */
    AuthenticationPeriodCount authenticationPeriodCount;  /* optional; set in
                                   * bit_mask
               * QualificationDirectiveArg_authenticationPeriodCount_present if
               * present */
    CallingFeaturesIndicator callingFeaturesIndicator;  /* optional; set in
                                   * bit_mask
                * QualificationDirectiveArg_callingFeaturesIndicator_present if
                * present */
    CarrierDigits   carrierDigits;  /* optional; set in bit_mask
                           * QualificationDirectiveArg_carrierDigits_present if
                           * present */
    DMH_AccountCodeDigits dmh_AccountCodeDigits;  /* optional; set in bit_mask
                   * QualificationDirectiveArg_dmh_AccountCodeDigits_present if
                   * present */
    DMH_AlternateBillingDigits dmh_AlternateBillingDigits;  /* optional; set in
                                   * bit_mask
              * QualificationDirectiveArg_dmh_AlternateBillingDigits_present if
              * present */
    DMH_BillingDigits dmh_BillingDigits;  /* optional; set in bit_mask
                       * QualificationDirectiveArg_dmh_BillingDigits_present if
                       * present */
    GeographicAuthorization geographicAuthorization;  /* optional; set in
                                   * bit_mask
                 * QualificationDirectiveArg_geographicAuthorization_present if
                 * present */
    MessageWaitingNotificationCount messageWaitingNotificationCount;  
                                  /* optional; set in bit_mask
         * QualificationDirectiveArg_messageWaitingNotificationCount_present if
         * present */
    MessageWaitingNotificationType messageWaitingNotificationType;  
                                  /* optional; set in bit_mask
          * QualificationDirectiveArg_messageWaitingNotificationType_present if
          * present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                   * QualificationDirectiveArg_mobileDirectoryNumber_present if
                   * present */
    OriginationIndicator originationIndicator;  /* optional; set in bit_mask
                    * QualificationDirectiveArg_originationIndicator_present if
                    * present */
    OriginationTriggers originationTriggers;  /* optional; set in bit_mask
                     * QualificationDirectiveArg_originationTriggers_present if
                     * present */
    PACAIndicator   pacIndicator;  /* optional; set in bit_mask
                            * QualificationDirectiveArg_pacIndicator_present if
                            * present */
    PreferredLanguageIndicator preferredLanguageIndicator;  /* optional; set in
                                   * bit_mask
              * QualificationDirectiveArg_preferredLanguageIndicator_present if
              * present */
    RestrictionDigits restrictionDigits;  /* optional; set in bit_mask
                       * QualificationDirectiveArg_restrictionDigits_present if
                       * present */
    RoutingDigits   routingDigits;  /* optional; set in bit_mask
                           * QualificationDirectiveArg_routingDigits_present if
                           * present */
    SMS_OriginationRestrictions sms_OriginationRestrictions;  /* optional; set
                                   * in bit_mask
             * QualificationDirectiveArg_sms_OriginationRestrictions_present if
             * present */
    SMS_TerminationRestrictions sms_TerminationRestrictions;  /* optional; set
                                   * in bit_mask
             * QualificationDirectiveArg_sms_TerminationRestrictions_present if
             * present */
    SPINIPIN        spiniPin;  /* optional; set in bit_mask
                                * QualificationDirectiveArg_spiniPin_present if
                                * present */
    SPINITriggers   spiniTriggers;  /* optional; set in bit_mask
                           * QualificationDirectiveArg_spiniTriggers_present if
                           * present */
    TerminationRestrictionCode terminationRestrictionCode;  /* optional; set in
                                   * bit_mask
              * QualificationDirectiveArg_terminationRestrictionCode_present if
              * present */
    TerminationTriggers terminationTriggers;  /* optional; set in bit_mask
                     * QualificationDirectiveArg_terminationTriggers_present if
                     * present */
    struct TriggerAddressList *triggerAddressList;  /* optional; set in bit_mask
                      * QualificationDirectiveArg_triggerAddressList_present if
                      * present */
    CDMAServiceOptionList cdmaServiceOptionList;  /* optional; set in bit_mask
                   * QualificationDirectiveArg_cdmaServiceOptionList_present if
                   * present */
    CallingFeaturesIndicator2 callingFeaturesIndicator2;  /* optional; set in
                                   * bit_mask
               * QualificationDirectiveArg_callingFeaturesIndicator2_present if
               * present */
    OriginatingServiceFeaturesIndicator originatingServiceFeaturesIndicator;  
                                        /* optional; set in bit_mask
     * QualificationDirectiveArg_originatingServiceFeaturesIndicator_present if
     * present */
    TerminatingServiceFeaturesIndicator terminatingServiceFeaturesIndicator;  
                                        /* optional; set in bit_mask
     * QualificationDirectiveArg_terminatingServiceFeaturesIndicator_present if
     * present */
    RoutingDigits2  routingDigits2;  /* optional; set in bit_mask
                          * QualificationDirectiveArg_routingDigits2_present if
                          * present */
    ChargingCategory chargingCategory;  /* optional; set in bit_mask
                        * QualificationDirectiveArg_chargingCategory_present if
                        * present */
    VerifyChargingIndicator verifyChargingIndicator;  /* optional; set in
                                   * bit_mask
                 * QualificationDirectiveArg_verifyChargingIndicator_present if
                 * present */
    VerifyChargingStartTime verifyChargingStartTime;  /* optional; set in
                                   * bit_mask
                 * QualificationDirectiveArg_verifyChargingStartTime_present if
                 * present */
    VerifyChargingEndTime verifyChargingEndTime;  /* optional; set in bit_mask
                   * QualificationDirectiveArg_verifyChargingEndTime_present if
                   * present */
} QualificationDirectiveArg;

typedef struct QualificationDirectiveRes {
    char            placeholder;
} QualificationDirectiveRes;

typedef enum KeyProtocolVersion {
    KeyProtocolVersion_not_used = 0,
    a_key_generation_not_supported = 1,
    diffie_hellman_with_768bit_modulus_160bit_primitive_160bit_exponents = 2,
    diffie_hellman_with_512bit_modulus_160bit_primitive_160bit_exponents = 3,
    diffie_hellman_with_768bit_modulus_32bit_primitive_160bit_exponents = 4
} KeyProtocolVersion;

typedef struct AKeyProtocolVersion {
    struct AKeyProtocolVersion *next;
    KeyProtocolVersion value;
} *AKeyProtocolVersion; /* 9f8135 */

typedef struct MobileStationMIN {
    unsigned short  length;
    unsigned char   value[5];
} MobileStationMIN;     /* 9f8138 */

typedef struct MobileStationPartialKey {
    unsigned short  length;
    unsigned char   value[4];
} MobileStationPartialKey;    /* 9f8139 */

typedef struct NewlyAssingnedMIN {
    unsigned short  length;
    unsigned char   value[5];
} NewlyAssingnedMIN;     /* 9f813b */

typedef struct BaseStationPartialKey {
    unsigned short  length;
    unsigned char   value[4];
} BaseStationPartialKey;    /* 9f8137 */

typedef struct ModulusValue {
    unsigned short  length;
    unsigned char   value[4];
} ModulusValue;    /* 9f813a */

typedef enum OTASPResultCode {                  /*9f813d */
    accepted_successful = 0,
    rejected_unknown_causer = 1,
    computaion_failure = 2,
    csc_rejected_csc_challenge_failure = 3,
    unrecognized_otasp_call_entry = 4,
    unsupported_AKeyProtocolVersions = 5,
    unable_to_commit = 6
} OTASPResultCode;

typedef struct PrimitiveValue {
    unsigned short  length;
    unsigned char   value[4];
} PrimitiveValue;    /* 9f813e */

typedef struct OTASPRequestArg {
    unsigned short  bit_mask;
#       define      OTASPRequestArg_actionCode_present 0x8000
#       define      OTASPRequestArg_aKeyProtocolVersion_present 0x4000
#       define      OTASPRequestArg_authenticationData_present 0x2000
#       define      OTASPRequestArg_authenticationResponse_present 0x1000
#       define      OTASPRequestArg_callHistoryCount_present 0x0800
#       define      OTASPRequestArg_electronicSerialNumber_present 0x0400
#       define      OTASPRequestArg_mobileIdentificationNumber_present 0x0200
#       define      mobileStationMIN_present 0x0100
#       define      mobileStationPartialKey_present 0x0080
#       define      OTASPRequestArg_mscId_present 0x0040
#       define      newlyAssingnedMIN_present 0x0020
#       define      OTASPRequestArg_randomVariable_present 0x0010
#       define      randomVariableBaseStation_present 0x0008
#       define      OTASPRequestArg_serviceIndicator_present 0x0004
#       define      OTASPRequestArg_systemCapabilities_present 0x0002
    ActionCode      actionCode;  /* optional; set in bit_mask
                                  * OTASPRequestArg_actionCode_present if
                                  * present */
    struct AKeyProtocolVersion *aKeyProtocolVersion;  /* optional; set in
                                   * bit_mask
                                   * OTASPRequestArg_aKeyProtocolVersion_present
                                   * if present */
    AuthenticationData authenticationData;  /* optional; set in bit_mask
                                * OTASPRequestArg_authenticationData_present if
                                * present */
    AuthenticationResponse authenticationResponse;  /* optional; set in bit_mask
                            * OTASPRequestArg_authenticationResponse_present if
                            * present */
    CallHistoryCount callHistoryCount;  /* optional; set in bit_mask
                                  * OTASPRequestArg_callHistoryCount_present if
                                  * present */
    ElectronicSerialNumber electronicSerialNumber;  /* optional; set in bit_mask
                            * OTASPRequestArg_electronicSerialNumber_present if
                            * present */
    MobileIdentificationNumber mobileIdentificationNumber;  /* optional; set in
                                   * bit_mask
                        * OTASPRequestArg_mobileIdentificationNumber_present if
                        * present */
    MobileStationMIN mobileStationMIN;  /* optional; set in bit_mask
                                         * mobileStationMIN_present if
                                         * present */
    MobileStationPartialKey mobileStationPartialKey;  /* optional; set in
                                   * bit_mask mobileStationPartialKey_present if
                                   * present */
    MSCID           mscId;  /* optional; set in bit_mask
                             * OTASPRequestArg_mscId_present if present */
    NewlyAssingnedMIN newlyAssingnedMIN;  /* optional; set in bit_mask
                                           * newlyAssingnedMIN_present if
                                           * present */
    RandomVariable  randomVariable;  /* optional; set in bit_mask
                                      * OTASPRequestArg_randomVariable_present
                                      * if present */
    RandomVariableBaseStation randomVariableBaseStation;  /* optional; set in
                                   * bit_mask randomVariableBaseStation_present
                                   * if present */
    GMAP_Protocol_ServiceIndicator serviceIndicator;  /* optional; set in
                                   * bit_mask
                                   * OTASPRequestArg_serviceIndicator_present if
                                   * present */
    SystemCapabilities systemCapabilities;  /* optional; set in bit_mask
                                * OTASPRequestArg_systemCapabilities_present if
                                * present */
} OTASPRequestArg;

typedef struct OTASPRequestRes {
    unsigned short  bit_mask;
#       define      OTASPRequestRes_aKeyProtocolVersion_present 0x8000
#       define      authenticationResponseBaseStation_present 0x4000
#       define      baseStationPartialKey_present 0x2000
#       define      OTASPRequestRes_denyAccess_present 0x1000
#       define      modulusValue_present 0x0800
#       define      otaspResultCode_present 0x0400
#       define      primitiveValue_present 0x0200
#       define      OTASPRequestRes_signalingMessageEncryptionReport_present 0x0100
#       define      OTASPRequestRes_ssdUpdatereport_present 0x0080
#       define      OTASPRequestRes_uniqueChallengeReport_present 0x0040
#       define      OTASPRequestRes_voicePrivacyReport_present 0x0020
    struct AKeyProtocolVersion *aKeyProtocolVersion;  /* optional; set in
                                   * bit_mask
                                   * OTASPRequestRes_aKeyProtocolVersion_present
                                   * if present */
    AuthenticationResponseBaseStation authenticationResponseBaseStation;  
                                        /* optional; set in bit_mask
                                 * authenticationResponseBaseStation_present if
                                 * present */
    BaseStationPartialKey baseStationPartialKey;  /* optional; set in bit_mask
                                             * baseStationPartialKey_present if
                                             * present */
    DenyAccess      denyAccess;  /* optional; set in bit_mask
                                  * OTASPRequestRes_denyAccess_present if
                                  * present */
    ModulusValue    modulusValue;  /* optional; set in bit_mask
                                    * modulusValue_present if present */
    OTASPResultCode otaspResultCode;  /* optional; set in bit_mask
                                       * otaspResultCode_present if present */
    PrimitiveValue  primitiveValue;  /* optional; set in bit_mask
                                      * primitiveValue_present if present */
    SignalingMessageEncryptionReport signalingMessageEncryptionReport;  
                                  /* optional; set in bit_mask
                  * OTASPRequestRes_signalingMessageEncryptionReport_present if
                  * present */
    SSDUpdateReport ssdUpdatereport;  /* optional; set in bit_mask
                                       * OTASPRequestRes_ssdUpdatereport_present
                                       * if present */
    UniqueChallengeReport uniqueChallengeReport;  /* optional; set in bit_mask
                             * OTASPRequestRes_uniqueChallengeReport_present if
                             * present */
    VoicePrivacyReport voicePrivacyReport;  /* optional; set in bit_mask
                                * OTASPRequestRes_voicePrivacyReport_present if
                                * present */
} OTASPRequestRes;

typedef struct GMapActivateTraceModeArg {
    unsigned char   bit_mask;
#       define      GMapActivateTraceModeArg_reportPeriod_present 0x80
    MobileIdentificationNumber mobileIdentificationNumber;
    ElectronicSerialNumber electronicSerialNumber;
    SystemMyTypeCode systemMyTypeCode;
    PC_SSN          pc_SSN;
    TraceType       traceType;
    ReportPeriod    reportPeriod;  /* optional; set in bit_mask
                             * GMapActivateTraceModeArg_reportPeriod_present if
                             * present */
} GMapActivateTraceModeArg;

typedef struct CallResult {
    unsigned short  length;
    unsigned char   value[1];
} CallResult; /* 9fff53 */

typedef struct Cause {
    unsigned short  length;
    unsigned char   value[2];
} Cause; /* 9fff54 */

typedef enum TracingResult {               /*9fff55 */
    TracingResult_not_used = 0,
    acceptable = 1,
    not_acceptable = 2
} TracingResult;

typedef struct TraceFacilitiesDenied {
    unsigned short  length;
    unsigned char   value[1];
} TraceFacilitiesDenied; /* 9fff56 */

typedef struct TraceResourceProblem {
    unsigned short  length;
    unsigned char   value[1];
} TraceResourceProblem; /* 9fff57 */

typedef struct CallType {
    unsigned short  length;
    unsigned char   value[1];
} CallType; /* 9fff58 */

typedef struct GMapActivateTraceModeRes {
    unsigned char   bit_mask;
#       define      GMapActivateTraceModeRes_traceFacilitiesDenied_present 0x80
#       define      GMapActivateTraceModeRes_traceResourceProblem_present 0x40
    TracingResult   tracingResult;
    TraceFacilitiesDenied traceFacilitiesDenied;  /* optional; set in bit_mask
                    * GMapActivateTraceModeRes_traceFacilitiesDenied_present if
                    * present */
    TraceResourceProblem traceResourceProblem;  /* optional; set in bit_mask
                     * GMapActivateTraceModeRes_traceResourceProblem_present if
                     * present */
} GMapActivateTraceModeRes;

typedef struct GMapDeactivateTraceModeArg {
    MobileIdentificationNumber mobileIdentificationNumber;
    ElectronicSerialNumber electronicSerialNumber;
    SystemMyTypeCode systemMyTypeCode;
    TraceType       traceType;
} GMapDeactivateTraceModeArg;

typedef struct GMapDeactivateTraceModeRes {
    char            placeholder;
} GMapDeactivateTraceModeRes;

/**/
/*  jdlee 2003/4/22  tags are not valid. */
/*  these tags are defined temporarily for duplicated parameters. */
/**/
typedef BCDDigits       MobileDirectoryNumberCalled; /* 9f30 */

typedef BCDDigits       MobileDirectoryNumberCalling; /* 9f31 */

typedef struct ElectronicSerialNumberCalling {
    unsigned short  length;
    unsigned char   value[4];
} ElectronicSerialNumberCalling; /* 8f */

typedef struct CallDateTimeHookOff {
    unsigned short  length;
    unsigned char   value[7];
} CallDateTimeHookOff; /* 9fce13 */

typedef struct CallDateTimeHookOn {
    unsigned short  length;
    unsigned char   value[7];
} CallDateTimeHookOn; /*  9fce14 */

typedef struct CallDateTimeCallStart {
    unsigned short  length;
    unsigned char   value[7];
} CallDateTimeCallStart; /* 9fce15 */

typedef struct CallDateTimeCallEnd {
    unsigned short  length;
    unsigned char   value[7];
} CallDateTimeCallEnd; /*  9fce16 */

/**/
/* jdlee 2003/4/22  tags are not valid */
typedef struct ReportTraceSubscriberActivityArg {
    unsigned short  bit_mask;
#       define      ReportTraceSubscriberActivityArg_locationAreaId_present 0x8000
#       define      callType_present 0x4000
#       define      mobileDirectoryNumberCalling_present 0x2000
#       define      electronicSerialNumberCalling_present 0x1000
#       define      mobileDirectoryNumberCalled_present 0x0800
#       define      ReportTraceSubscriberActivityArg_chargingCategory_present 0x0400
#       define      callResult_present 0x0200
#       define      callDateTimeHookOff_present 0x0100
#       define      callDateTimeHookOn_present 0x0080
#       define      callDateTimeCallStart_present 0x0040
#       define      callDateTimeCallEnd_present 0x0020
#       define      cause_present 0x0010
    MobileIdentificationNumber mobileIdentificationNumber;
    ElectronicSerialNumber electronicSerialNumber;
    SystemMyTypeCode systemMyTypeCode;
    MSCID           mscId;
    TraceType       traceType;
    LocationAreaID  locationAreaId;  /* optional; set in bit_mask
                   * ReportTraceSubscriberActivityArg_locationAreaId_present if
                   * present */
    CallType        callType;  /* optional; set in bit_mask callType_present if
                                * present */
    MobileDirectoryNumberCalling mobileDirectoryNumberCalling;  /* optional; set
                                   * in bit_mask
                                   * mobileDirectoryNumberCalling_present if
                                   * present */
    ElectronicSerialNumberCalling electronicSerialNumberCalling;  /* optional;
                                   * set in bit_mask
                                   * electronicSerialNumberCalling_present if
                                   * present */
    MobileDirectoryNumberCalled mobileDirectoryNumberCalled;  /* optional; set
                                   * in bit_mask
                                   * mobileDirectoryNumberCalled_present if
                                   * present */
    ChargingCategory chargingCategory;  /* optional; set in bit_mask
                 * ReportTraceSubscriberActivityArg_chargingCategory_present if
                 * present */
    CallResult      callResult;  /* optional; set in bit_mask callResult_present
                                  * if present */
    CallDateTimeHookOff callDateTimeHookOff;  /* optional; set in bit_mask
                                               * callDateTimeHookOff_present if
                                               * present */
    CallDateTimeHookOn callDateTimeHookOn;  /* optional; set in bit_mask
                                             * callDateTimeHookOn_present if
                                             * present */
    CallDateTimeCallStart callDateTimeCallStart;  /* optional; set in bit_mask
                                             * callDateTimeCallStart_present if
                                             * present */
    CallDateTimeCallEnd callDateTimeCallEnd;  /* optional; set in bit_mask
                                               * callDateTimeCallEnd_present if
                                               * present */
    Cause           cause;  /* optional; set in bit_mask cause_present if
                             * present */
} ReportTraceSubscriberActivityArg;

typedef struct ReportTraceSubscriberActivityRes {
    unsigned char   bit_mask;
#       define      ReportTraceSubscriberActivityRes_traceFacilitiesDenied_present 0x80
#       define      ReportTraceSubscriberActivityRes_traceResourceProblem_present 0x40
    TracingResult   tracingResult;
    TraceFacilitiesDenied traceFacilitiesDenied;  /* optional; set in bit_mask
            * ReportTraceSubscriberActivityRes_traceFacilitiesDenied_present if
            * present */
    TraceResourceProblem traceResourceProblem;  /* optional; set in bit_mask
             * ReportTraceSubscriberActivityRes_traceResourceProblem_present if
             * present */
} ReportTraceSubscriberActivityRes;

typedef struct TraceStateNotificationArg {
    unsigned char   bit_mask;
#       define      TraceStateNotificationArg_traceFacilitiesDenied_present 0x80
#       define      TraceStateNotificationArg_traceResourceProblem_present 0x40
    MobileIdentificationNumber mobileIdentificationNumber;
    ElectronicSerialNumber electronicSerialNumber;
    SystemMyTypeCode systemMyTypeCode;
    TracingResult   tracingResult;
    TraceFacilitiesDenied traceFacilitiesDenied;  /* optional; set in bit_mask
                   * TraceStateNotificationArg_traceFacilitiesDenied_present if
                   * present */
    TraceResourceProblem traceResourceProblem;  /* optional; set in bit_mask
                    * TraceStateNotificationArg_traceResourceProblem_present if
                    * present */
} TraceStateNotificationArg;

typedef struct TraceStateNotificationRes {
    char            placeholder;
} TraceStateNotificationRes;

typedef struct ServiceRequestArg {
    unsigned char   bit_mask[5];
#       define      ServiceRequestArg_accessDeniedReason_present 0x80
#       define      ServiceRequestArg_accessDeniedReason_present_byte 0
#       define      ServiceRequestArg_availabilityType_present 0x40
#       define      ServiceRequestArg_availabilityType_present_byte 0
#       define      ServiceRequestArg_billingId_present 0x20
#       define      ServiceRequestArg_billingId_present_byte 0
#       define      ServiceRequestArg_callingPartyName_present 0x10
#       define      ServiceRequestArg_callingPartyName_present_byte 0
#       define      ServiceRequestArg_callingPartyNumberDigits1_present 0x08
#       define      ServiceRequestArg_callingPartyNumberDigits1_present_byte 0
#       define      ServiceRequestArg_callingPartyNumberDigits2_present 0x04
#       define      ServiceRequestArg_callingPartyNumberDigits2_present_byte 0
#       define      ServiceRequestArg_callingPartySubaddress_present 0x02
#       define      ServiceRequestArg_callingPartySubaddress_present_byte 0
#       define      ServiceRequestArg_conditionallyDeniedReason_present 0x01
#       define      ServiceRequestArg_conditionallyDeniedReason_present_byte 0
#       define      ServiceRequestArg_digits_present 0x80
#       define      ServiceRequestArg_digits_present_byte 1
#       define      ServiceRequestArg_groupInformation_present 0x40
#       define      ServiceRequestArg_groupInformation_present_byte 1
#       define      ServiceRequestArg_legInformation_present 0x20
#       define      ServiceRequestArg_legInformation_present_byte 1
#       define      ServiceRequestArg_locationAreaId_present 0x10
#       define      ServiceRequestArg_locationAreaId_present_byte 1
#       define      ServiceRequestArg_mobileIdentificationNumber_present 0x08
#       define      ServiceRequestArg_mobileIdentificationNumber_present_byte 1
#       define      ServiceRequestArg_mscId_present 0x04
#       define      ServiceRequestArg_mscId_present_byte 1
#       define      ServiceRequestArg_mscIdentificationNumber_present 0x02
#       define      ServiceRequestArg_mscIdentificationNumber_present_byte 1
#       define      ServiceRequestArg_pc_SSN_present 0x01
#       define      ServiceRequestArg_pc_SSN_present_byte 1
#       define      ServiceRequestArg_redirectionReason_present 0x80
#       define      ServiceRequestArg_redirectionReason_present_byte 2
#       define      ServiceRequestArg_pilotBillingId_present 0x40
#       define      ServiceRequestArg_pilotBillingId_present_byte 2
#       define      ServiceRequestArg_pilotNumber_present 0x20
#       define      ServiceRequestArg_pilotNumber_present_byte 2
#       define      ServiceRequestArg_preferredLanguageIndicator_present 0x10
#       define      ServiceRequestArg_preferredLanguageIndicator_present_byte 2
#       define      ServiceRequestArg_redirectingNumberDigits_present 0x08
#       define      ServiceRequestArg_redirectingNumberDigits_present_byte 2
#       define      ServiceRequestArg_redirectingPartyName_present 0x04
#       define      ServiceRequestArg_redirectingPartyName_present_byte 2
#       define      ServiceRequestArg_redirectingSubaddress_present 0x02
#       define      ServiceRequestArg_redirectingSubaddress_present_byte 2
#       define      ServiceRequestArg_senderIdentificationNumber_present 0x01
#       define      ServiceRequestArg_senderIdentificationNumber_present_byte 2
#       define      ServiceRequestArg_servingCellId_present 0x80
#       define      ServiceRequestArg_servingCellId_present_byte 3
#       define      ServiceRequestArg_systemMyTypeCode_present 0x40
#       define      ServiceRequestArg_systemMyTypeCode_present_byte 3
#       define      ServiceRequestArg_terminationAccessType_present 0x20
#       define      ServiceRequestArg_terminationAccessType_present_byte 3
#       define      ServiceRequestArg_transactionCapability_present 0x10
#       define      ServiceRequestArg_transactionCapability_present_byte 3
#       define      ServiceRequestArg_winCapability_present 0x08
#       define      ServiceRequestArg_winCapability_present_byte 3
#       define      ServiceRequestArg_dataAccessElementList_present 0x04
#       define      ServiceRequestArg_dataAccessElementList_present_byte 3
#       define      ServiceRequestArg_triggerType_present 0x02
#       define      ServiceRequestArg_triggerType_present_byte 3
#       define      ServiceRequestArg_originatingServiceFeaturesIndicator_present 0x01
#       define      ServiceRequestArg_originatingServiceFeaturesIndicator_present_byte 3
#       define      ServiceRequestArg_mobileDirectoryNumber_present 0x80
#       define      ServiceRequestArg_mobileDirectoryNumber_present_byte 4
#       define      multiServiceID_present 0x40
#       define      multiServiceID_present_byte 4
    ServiceID       serviceId;
    AccessDeniedReason accessDeniedReason;  /* optional; set in bit_mask
                              * ServiceRequestArg_accessDeniedReason_present if
                              * present */
    AvailabilityType availabilityType;  /* optional; set in bit_mask
                                * ServiceRequestArg_availabilityType_present if
                                * present */
    BillingID       billingId;  /* optional; set in bit_mask
                                 * ServiceRequestArg_billingId_present if
                                 * present */
    CallingPartyName callingPartyName;  /* optional; set in bit_mask
                                * ServiceRequestArg_callingPartyName_present if
                                * present */
    CallingPartyNumberDigits1 callingPartyNumberDigits1;  /* optional; set in
                                   * bit_mask
                       * ServiceRequestArg_callingPartyNumberDigits1_present if
                       * present */
    CallingPartyNumberDigits2 callingPartyNumberDigits2;  /* optional; set in
                                   * bit_mask
                       * ServiceRequestArg_callingPartyNumberDigits2_present if
                       * present */
    CallingPartySubaddress callingPartySubaddress;  /* optional; set in bit_mask
                          * ServiceRequestArg_callingPartySubaddress_present if
                          * present */
    ConditionallyDeniedReason conditionallyDeniedReason;  /* optional; set in
                                   * bit_mask
                       * ServiceRequestArg_conditionallyDeniedReason_present if
                       * present */
    WinDigits       digits;  /* optional; set in bit_mask
                              * ServiceRequestArg_digits_present if present */
    GroupInformation groupInformation;  /* optional; set in bit_mask
                                * ServiceRequestArg_groupInformation_present if
                                * present */
    LegInformation  legInformation;  /* optional; set in bit_mask
                                      * ServiceRequestArg_legInformation_present
                                      * if present */
    LocationAreaID  locationAreaId;  /* optional; set in bit_mask
                                      * ServiceRequestArg_locationAreaId_present
                                      * if present */
    MobileIdentificationNumber mobileIdentificationNumber;  /* optional; set in
                                   * bit_mask
                      * ServiceRequestArg_mobileIdentificationNumber_present if
                      * present */
    MSCID           mscId;  /* optional; set in bit_mask
                             * ServiceRequestArg_mscId_present if present */
    MSCIdentificationNumber mscIdentificationNumber;  /* optional; set in
                                   * bit_mask
                         * ServiceRequestArg_mscIdentificationNumber_present if
                         * present */
    PC_SSN          pc_SSN;  /* optional; set in bit_mask
                              * ServiceRequestArg_pc_SSN_present if present */
    RedirectionReason redirectionReason;  /* optional; set in bit_mask
                               * ServiceRequestArg_redirectionReason_present if
                               * present */
    PilotBillingID  pilotBillingId;  /* optional; set in bit_mask
                                      * ServiceRequestArg_pilotBillingId_present
                                      * if present */
    PilotNumber     pilotNumber;  /* optional; set in bit_mask
                                   * ServiceRequestArg_pilotNumber_present if
                                   * present */
    PreferredLanguageIndicator preferredLanguageIndicator;  /* optional; set in
                                   * bit_mask
                      * ServiceRequestArg_preferredLanguageIndicator_present if
                      * present */
    RedirectingNumberDigits redirectingNumberDigits;  /* optional; set in
                                   * bit_mask
                         * ServiceRequestArg_redirectingNumberDigits_present if
                         * present */
    RedirectingPartyName redirectingPartyName;  /* optional; set in bit_mask
                            * ServiceRequestArg_redirectingPartyName_present if
                            * present */
    RedirectingSubaddress redirectingSubaddress;  /* optional; set in bit_mask
                           * ServiceRequestArg_redirectingSubaddress_present if
                           * present */
    SenderIdentificationNumber senderIdentificationNumber;  /* optional; set in
                                   * bit_mask
                      * ServiceRequestArg_senderIdentificationNumber_present if
                      * present */
    ServingCellID   servingCellId;  /* optional; set in bit_mask
                                     * ServiceRequestArg_servingCellId_present
                                     * if present */
    SystemMyTypeCode systemMyTypeCode;  /* optional; set in bit_mask
                                * ServiceRequestArg_systemMyTypeCode_present if
                                * present */
    TerminationAccessType terminationAccessType;  /* optional; set in bit_mask
                           * ServiceRequestArg_terminationAccessType_present if
                           * present */
    TransactionCapability transactionCapability;  /* optional; set in bit_mask
                           * ServiceRequestArg_transactionCapability_present if
                           * present */
    WINCapability   winCapability;  /* optional; set in bit_mask
                                     * ServiceRequestArg_winCapability_present
                                     * if present */
    struct DataAccessElementList *dataAccessElementList;  /* optional; set in
                                   * bit_mask
                           * ServiceRequestArg_dataAccessElementList_present if
                           * present */
    TriggerType     triggerType;  /* optional; set in bit_mask
                                   * ServiceRequestArg_triggerType_present if
                                   * present */
    OriginatingServiceFeaturesIndicator originatingServiceFeaturesIndicator;  
                                        /* optional; set in bit_mask
             * ServiceRequestArg_originatingServiceFeaturesIndicator_present if
             * present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                           * ServiceRequestArg_mobileDirectoryNumber_present if
                           * present */
    MultiServiceID  multiServiceID;  /* optional; set in bit_mask
                                      * multiServiceID_present if present */
} ServiceRequestArg;

typedef struct ServiceRequestRes {
    unsigned int    bit_mask;
#       define      ServiceRequestRes_accessDeniedReason_present 0x80000000
#       define      ServiceRequestRes_actionCode_present 0x40000000
#       define      ServiceRequestRes_alertCode_present 0x20000000
#       define      ServiceRequestRes_announcementList_present 0x10000000
#       define      ServiceRequestRes_callingPartyName_present 0x08000000
#       define      ServiceRequestRes_callingPartyNumberString1_present 0x04000000
#       define      ServiceRequestRes_callingPartyNumberString2_present 0x02000000
#       define      ServiceRequestRes_callingPartySubaddress_present 0x01000000
#       define      ServiceRequestRes_carrierDigits_present 0x00800000
#       define      ServiceRequestRes_digits_present 0x00400000
#       define      ServiceRequestRes_displayText_present 0x00200000
#       define      ServiceRequestRes_dmh_AccountCodeDigits_present 0x00100000
#       define      ServiceRequestRes_dmh_AlternateBillingDigits_present 0x00080000
#       define      ServiceRequestRes_dmh_BillingDigits_present 0x00040000
#       define      ServiceRequestRes_dmh_RedirectionIndicator_present 0x00020000
#       define      ServiceRequestRes_groupInformation_present 0x00010000
#       define      ServiceRequestRes_mobileDirectoryNumber_present 0x00008000
#       define      ServiceRequestRes_noAnswerTime_present 0x00004000
#       define      ServiceRequestRes_redirectingNumberDigits_present 0x00002000
#       define      ServiceRequestRes_redirectingNumberString_present 0x00001000
#       define      ServiceRequestRes_redirectingPartyName_present 0x00000800
#       define      ServiceRequestRes_redirectingSubaddress_present 0x00000400
#       define      ServiceRequestRes_resumePIC_present 0x00000200
#       define      ServiceRequestRes_routingDigits_present 0x00000100
#       define      ServiceRequestRes_mscId_present 0x00000080
#       define      ServiceRequestRes_locationAreaId_present 0x00000040
#       define      ServiceRequestRes_returnResult_present 0x00000020
#       define      ServiceRequestRes_alert_present 0x00000010
#       define      ServiceRequestRes_resultReason_present 0x00000008
#       define      fileName_present 0x00000004
#       define      additionalServiceInformation_present 0x00000002
    AccessDeniedReason accessDeniedReason;  /* optional; set in bit_mask
                              * ServiceRequestRes_accessDeniedReason_present if
                              * present */
    ActionCode      actionCode;  /* optional; set in bit_mask
                                  * ServiceRequestRes_actionCode_present if
                                  * present */
    AlertCode       alertCode;  /* optional; set in bit_mask
                                 * ServiceRequestRes_alertCode_present if
                                 * present */
    AnnouncementList announcementList;  /* optional; set in bit_mask
                                * ServiceRequestRes_announcementList_present if
                                * present */
    CallingPartyName callingPartyName;  /* optional; set in bit_mask
                                * ServiceRequestRes_callingPartyName_present if
                                * present */
    CallingPartyNumberString1 callingPartyNumberString1;  /* optional; set in
                                   * bit_mask
                       * ServiceRequestRes_callingPartyNumberString1_present if
                       * present */
    CallingPartyNumberString2 callingPartyNumberString2;  /* optional; set in
                                   * bit_mask
                       * ServiceRequestRes_callingPartyNumberString2_present if
                       * present */
    CallingPartySubaddress callingPartySubaddress;  /* optional; set in bit_mask
                          * ServiceRequestRes_callingPartySubaddress_present if
                          * present */
    CarrierDigits   carrierDigits;  /* optional; set in bit_mask
                                     * ServiceRequestRes_carrierDigits_present
                                     * if present */
    WinDigits       digits;  /* optional; set in bit_mask
                              * ServiceRequestRes_digits_present if present */
    DisplayText     displayText;  /* optional; set in bit_mask
                                   * ServiceRequestRes_displayText_present if
                                   * present */
    DMH_AccountCodeDigits dmh_AccountCodeDigits;  /* optional; set in bit_mask
                           * ServiceRequestRes_dmh_AccountCodeDigits_present if
                           * present */
    DMH_AlternateBillingDigits dmh_AlternateBillingDigits;  /* optional; set in
                                   * bit_mask
                      * ServiceRequestRes_dmh_AlternateBillingDigits_present if
                      * present */
    DMH_BillingDigits dmh_BillingDigits;  /* optional; set in bit_mask
                               * ServiceRequestRes_dmh_BillingDigits_present if
                               * present */
    DMH_RedirectionIndicator dmh_RedirectionIndicator;  /* optional; set in
                                   * bit_mask
                        * ServiceRequestRes_dmh_RedirectionIndicator_present if
                        * present */
    GroupInformation groupInformation;  /* optional; set in bit_mask
                                * ServiceRequestRes_groupInformation_present if
                                * present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                           * ServiceRequestRes_mobileDirectoryNumber_present if
                           * present */
    NoAnswerTime    noAnswerTime;  /* optional; set in bit_mask
                                    * ServiceRequestRes_noAnswerTime_present if
                                    * present */
    RedirectingNumberDigits redirectingNumberDigits;  /* optional; set in
                                   * bit_mask
                         * ServiceRequestRes_redirectingNumberDigits_present if
                         * present */
    RedirectingNumberString redirectingNumberString;  /* optional; set in
                                   * bit_mask
                         * ServiceRequestRes_redirectingNumberString_present if
                         * present */
    RedirectingPartyName redirectingPartyName;  /* optional; set in bit_mask
                            * ServiceRequestRes_redirectingPartyName_present if
                            * present */
    RedirectingSubaddress redirectingSubaddress;  /* optional; set in bit_mask
                           * ServiceRequestRes_redirectingSubaddress_present if
                           * present */
    ResumePIC       resumePIC;  /* optional; set in bit_mask
                                 * ServiceRequestRes_resumePIC_present if
                                 * present */
    RoutingDigits   routingDigits;  /* optional; set in bit_mask
                                     * ServiceRequestRes_routingDigits_present
                                     * if present */
    struct TerminationList *terminationList;  /* NULL for not present */
    MSCID           mscId;  /* optional; set in bit_mask
                             * ServiceRequestRes_mscId_present if present */
    LocationAreaID  locationAreaId;  /* optional; set in bit_mask
                                      * ServiceRequestRes_locationAreaId_present
                                      * if present */
    GMAP_Protocol_ReturnResult returnResult;  /* optional; set in bit_mask
                                    * ServiceRequestRes_returnResult_present if
                                    * present */
    Alert           alert;  /* optional; set in bit_mask
                             * ServiceRequestRes_alert_present if present */
    ResultReason    resultReason;  /* optional; set in bit_mask
                                    * ServiceRequestRes_resultReason_present if
                                    * present */
    FileName        fileName;  /* optional; set in bit_mask fileName_present if
                                * present */
    AdditionalServiceInformation additionalServiceInformation;  /* optional; set
                                   * in bit_mask
                                   * additionalServiceInformation_present if
                                   * present */
} ServiceRequestRes;

typedef struct ServiceInfoDirectiveArg { /* class 4 */
    unsigned int    bit_mask;
#       define      ServiceInfoDirectiveArg_accessDeniedReason_present 0x80000000
#       define      ServiceInfoDirectiveArg_availabilityType_present 0x40000000
#       define      ServiceInfoDirectiveArg_billingId_present 0x20000000
#       define      ServiceInfoDirectiveArg_callingPartyName_present 0x10000000
#       define      ServiceInfoDirectiveArg_callingPartyNumberDigits1_present 0x08000000
#       define      ServiceInfoDirectiveArg_callingPartyNumberDigits2_present 0x04000000
#       define      ServiceInfoDirectiveArg_callingPartySubaddress_present 0x02000000
#       define      ServiceInfoDirectiveArg_conditionallyDeniedReason_present 0x01000000
#       define      ServiceInfoDirectiveArg_digits_present 0x00800000
#       define      ServiceInfoDirectiveArg_locationAreaId_present 0x00400000
#       define      ServiceInfoDirectiveArg_mobileDirectoryNumber_present 0x00200000
#       define      ServiceInfoDirectiveArg_mobileIdentificationNumber_present 0x00100000
#       define      ServiceInfoDirectiveArg_mscId_present 0x00080000
#       define      ServiceInfoDirectiveArg_pc_SSN_present 0x00040000
#       define      ServiceInfoDirectiveArg_redirectionReason_present 0x00020000
#       define      ServiceInfoDirectiveArg_senderIdentificationNumber_present 0x00010000
#       define      ServiceInfoDirectiveArg_servingCellId_present 0x00008000
#       define      ServiceInfoDirectiveArg_systemMyTypeCode_present 0x00004000
#       define      ServiceInfoDirectiveArg_terminationAccessType_present 0x00002000
#       define      ServiceInfoDirectiveArg_transactionCapability_present 0x00001000
#       define      ServiceInfoDirectiveArg_winCapability_present 0x00000800
#       define      ServiceInfoDirectiveArg_dataAccessElementList_present 0x00000400
#       define      ServiceInfoDirectiveArg_triggerType_present 0x00000200
#       define      ServiceInfoDirectiveArg_originatingServiceFeaturesIndicator_present 0x00000100
    ServiceID       serviceId;
    AccessDeniedReason accessDeniedReason;  /* optional; set in bit_mask
                        * ServiceInfoDirectiveArg_accessDeniedReason_present if
                        * present */
    AvailabilityType availabilityType;  /* optional; set in bit_mask
                          * ServiceInfoDirectiveArg_availabilityType_present if
                          * present */
    BillingID       billingId;  /* optional; set in bit_mask
                                 * ServiceInfoDirectiveArg_billingId_present if
                                 * present */
    CallingPartyName callingPartyName;  /* optional; set in bit_mask
                          * ServiceInfoDirectiveArg_callingPartyName_present if
                          * present */
    CallingPartyNumberDigits1 callingPartyNumberDigits1;  /* optional; set in
                                   * bit_mask
                 * ServiceInfoDirectiveArg_callingPartyNumberDigits1_present if
                 * present */
    CallingPartyNumberDigits2 callingPartyNumberDigits2;  /* optional; set in
                                   * bit_mask
                 * ServiceInfoDirectiveArg_callingPartyNumberDigits2_present if
                 * present */
    CallingPartySubaddress callingPartySubaddress;  /* optional; set in bit_mask
                    * ServiceInfoDirectiveArg_callingPartySubaddress_present if
                    * present */
    ConditionallyDeniedReason conditionallyDeniedReason;  /* optional; set in
                                   * bit_mask
                 * ServiceInfoDirectiveArg_conditionallyDeniedReason_present if
                 * present */
    WinDigits       digits;  /* optional; set in bit_mask
                              * ServiceInfoDirectiveArg_digits_present if
                              * present */
    LocationAreaID  locationAreaId;  /* optional; set in bit_mask
                            * ServiceInfoDirectiveArg_locationAreaId_present if
                            * present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                     * ServiceInfoDirectiveArg_mobileDirectoryNumber_present if
                     * present */
    MobileIdentificationNumber mobileIdentificationNumber;  /* optional; set in
                                   * bit_mask
                * ServiceInfoDirectiveArg_mobileIdentificationNumber_present if
                * present */
    MSCID           mscId;  /* optional; set in bit_mask
                             * ServiceInfoDirectiveArg_mscId_present if
                             * present */
    PC_SSN          pc_SSN;  /* optional; set in bit_mask
                              * ServiceInfoDirectiveArg_pc_SSN_present if
                              * present */
    RedirectionReason redirectionReason;  /* optional; set in bit_mask
                         * ServiceInfoDirectiveArg_redirectionReason_present if
                         * present */
    SenderIdentificationNumber senderIdentificationNumber;  /* optional; set in
                                   * bit_mask
                * ServiceInfoDirectiveArg_senderIdentificationNumber_present if
                * present */
    ServingCellID   servingCellId;  /* optional; set in bit_mask
                             * ServiceInfoDirectiveArg_servingCellId_present if
                             * present */
    SystemMyTypeCode systemMyTypeCode;  /* optional; set in bit_mask
                          * ServiceInfoDirectiveArg_systemMyTypeCode_present if
                          * present */
    TerminationAccessType terminationAccessType;  /* optional; set in bit_mask
                     * ServiceInfoDirectiveArg_terminationAccessType_present if
                     * present */
    TransactionCapability transactionCapability;  /* optional; set in bit_mask
                     * ServiceInfoDirectiveArg_transactionCapability_present if
                     * present */
    WINCapability   winCapability;  /* optional; set in bit_mask
                             * ServiceInfoDirectiveArg_winCapability_present if
                             * present */
    struct DataAccessElementList *dataAccessElementList;  /* optional; set in
                                   * bit_mask
                     * ServiceInfoDirectiveArg_dataAccessElementList_present if
                     * present */
    TriggerType     triggerType;  /* optional; set in bit_mask
                                   * ServiceInfoDirectiveArg_triggerType_present
                                   * if present */
    OriginatingServiceFeaturesIndicator originatingServiceFeaturesIndicator;  
                                        /* optional; set in bit_mask
       * ServiceInfoDirectiveArg_originatingServiceFeaturesIndicator_present if
       * present */
} ServiceInfoDirectiveArg;

typedef struct TiisErrorReportArg {
    unsigned char   bit_mask;
#       define      TiisErrorReportArg_returnResult_present 0x80
#       define      TiisErrorReportArg_alert_present 0x40
#       define      TiisErrorReportArg_resultReason_present 0x20
    GMAP_Protocol_ReturnResult returnResult;  /* optional; set in bit_mask
                                   * TiisErrorReportArg_returnResult_present if
                                   * present */
    Alert           alert;  /* optional; set in bit_mask
                             * TiisErrorReportArg_alert_present if present */
    ResultReason    resultReason;  /* optional; set in bit_mask
                                    * TiisErrorReportArg_resultReason_present if
                                    * present */
} TiisErrorReportArg;

/* This is different from ServiceIndicator */
typedef enum ServiceIndicator2 {         /* 9fff61 */
    ServiceIndicator2_not_used = 0,
    vms_registration = 1,
    vms_cancellation = 2,
    vms_service_change = 3,
    fms_registration = 4,
    fms_cancellation = 5,
    fms_service_change = 6,
    vms_display = 7,
    fms_display = 8,
    sms_registration = 9,
    sms_cancellation = 10,
    sms_service_change = 11,
    sms_display = 12,
    vms_sms_registration = 13,
    vms_sms_cancellation = 14
} ServiceIndicator2;

typedef struct MailingClass {
    unsigned short  length;
    unsigned char   value[1];
} MailingClass; /* 9fff62 */

typedef struct GMAP_Protocol_Password {
    unsigned short  length;
    unsigned char   value[2];
} GMAP_Protocol_Password; /* 9fff41 */

typedef struct DeviceNumber {
    unsigned short  length;
    unsigned char   value[1];
} DeviceNumber; /* 9fff63 */

typedef enum SMS_ServiceFlag { /* 9fff78 */
    SMS_ServiceFlag_not_used = 0,
    sms_service_on = 1,
    sms_service_off = 2
} SMS_ServiceFlag;

typedef enum NoUpdateIndicator { /* 9fff7c */
    NoUpdateIndicator_not_used = 0,
    already_allocated_vms = 1,
    not_allocated_vms = 2,
    subscriber_not_usable = 3,
    subscriber_full = 4,
    data_change_fail = 5,
    task_abnormal = 6,
    process_abnormal = 7
} NoUpdateIndicator;

typedef struct MailProfileDirectiveArg {
    unsigned char   bit_mask;
#       define      mailingClass_present 0x80
#       define      MailProfileDirectiveArg_password_present 0x40
#       define      deviceNumber_present 0x20
    MobileIdentificationNumber mobileIdentificationNumber;
    ElectronicSerialNumber electronicSerialNumber;
    ServiceIndicator2 serviceIndicator;
    MailingClass    mailingClass;  /* optional; set in bit_mask
                                    * mailingClass_present if present */
    GMAP_Protocol_Password password;  /* optional; set in bit_mask
                                  * MailProfileDirectiveArg_password_present if
                                  * present */
    DeviceNumber    deviceNumber;  /* optional; set in bit_mask
                                    * deviceNumber_present if present */
} MailProfileDirectiveArg;

typedef struct MailProfileDirectiveRes {
    unsigned char   bit_mask;
#       define      MailProfileDirectiveRes_digits_present 0x80
#       define      MailProfileDirectiveRes_password_present 0x40
#       define      sms_ServiceFlag_present 0x20
#       define      noUpdateIndicator_present 0x10
    WinDigits       digits;  /* optional; set in bit_mask
                              * MailProfileDirectiveRes_digits_present if
                              * present */
    GMAP_Protocol_Password password;  /* optional; set in bit_mask
                                  * MailProfileDirectiveRes_password_present if
                                  * present */
    SMS_ServiceFlag sms_ServiceFlag;  /* optional; set in bit_mask
                                       * sms_ServiceFlag_present if present */
    NoUpdateIndicator noUpdateIndicator;  /* optional; set in bit_mask
                                           * noUpdateIndicator_present if
                                           * present */
} MailProfileDirectiveRes;

typedef struct MailStateNotificationArg {
    MobileIdentificationNumber mobileIdentificationNumber;
    MailStateFlag   mailStateFlag;
} MailStateNotificationArg;

typedef struct MailStateNotificationRes {
    char            placeholder;
} MailStateNotificationRes;

typedef enum UsageIndicator {               /* 98 */
    UsageIndicator_unspecified = 0,
    sent_paidBilling = 1,
    thirdPartyBilling = 2
} UsageIndicator;

typedef struct CallDataRequestArg {
    unsigned char   bit_mask;
#       define      CallDataRequestArg_pc_SSN_present 0x80
    BillingID       billingId;
    WinDigits       digits;
    MSCID           mscId;
    SystemMyTypeCode systemMyTypeCode;
    UsageIndicator  usageIndicator;
    PC_SSN          pc_SSN;  /* optional; set in bit_mask
                              * CallDataRequestArg_pc_SSN_present if present */
} CallDataRequestArg;

typedef struct CallDataRequestRes {
    unsigned char   bit_mask;
#       define      CallDataRequestRes_pc_SSN_present 0x80
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    MSCID           mscId;
    SystemMyTypeCode systemMyTypeCode;
    PC_SSN          pc_SSN;  /* optional; set in bit_mask
                              * CallDataRequestRes_pc_SSN_present if present */
} CallDataRequestRes;

typedef struct LocationVerificationArg {
    MobileIdentificationNumber mobileIdentificationNumber;
    ElectronicSerialNumber electronicSerialNumber;
} LocationVerificationArg;

typedef struct LocationVerificationRes {
    unsigned char   bit_mask;
#       define      LocationVerificationRes_mscId_present 0x80
    MSCID           mscId;  /* optional; set in bit_mask
                             * LocationVerificationRes_mscId_present if
                             * present */
} LocationVerificationRes;

/* For LGT location service */
typedef struct PositionRequestType {
    unsigned short  length;
    unsigned char   value[2];
} PositionRequestType; /* 9f8251 */

typedef struct PositionResult {
    unsigned short  length;
    unsigned char   value[2];
} PositionResult; /* 9f8252 */

typedef struct LCSParameterRequestArg {
    unsigned char   bit_mask;
#       define      LCSParameterRequestArg_mobileDirectoryNumber_present 0x80
#       define      LCSParameterRequestArg_mpcId_present 0x40
#       define      msid_present 0x20
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                      * LCSParameterRequestArg_mobileDirectoryNumber_present if
                      * present */
    MPCID           mpcId;  /* optional; set in bit_mask
                             * LCSParameterRequestArg_mpcId_present if
                             * present */
/*  mpcId						[1] BCDDigits						OPTIONAL, */
    BCDDigits       msid;  /* optional; set in bit_mask msid_present if
                            * present */
} LCSParameterRequestArg;

typedef struct LCSParameterRequestRes {
    unsigned char   bit_mask;
#       define      LCSParameterRequestRes_accessDeniedReason_present 0x80
#       define      LCSParameterRequestRes_electronicSerialNumber_present 0x40
#       define      LCSParameterRequestRes_imsi_present 0x20
#       define      LCSParameterRequestRes_mobileDirectoryNumber_present 0x10
#       define      LCSParameterRequestRes_mobileIdentificationNumber_present 0x08
#       define      LCSParameterRequestRes_mscId_present 0x04
#       define      LCSParameterRequestRes_pc_SSN_present 0x02
    AccessDeniedReason accessDeniedReason;  /* optional; set in bit_mask
                         * LCSParameterRequestRes_accessDeniedReason_present if
                         * present */
    ElectronicSerialNumber electronicSerialNumber;  /* optional; set in bit_mask
                     * LCSParameterRequestRes_electronicSerialNumber_present if
                     * present */
    GMAPIMSI        imsi;  /* optional; set in bit_mask
                            * LCSParameterRequestRes_imsi_present if present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                      * LCSParameterRequestRes_mobileDirectoryNumber_present if
                      * present */
    MobileIdentificationNumber mobileIdentificationNumber;  /* optional; set in
                                   * bit_mask
                 * LCSParameterRequestRes_mobileIdentificationNumber_present if
                 * present */
    MSCID           mscId;  /* optional; set in bit_mask
                             * LCSParameterRequestRes_mscId_present if
                             * present */
    PC_SSN          pc_SSN;  /* optional; set in bit_mask
                              * LCSParameterRequestRes_pc_SSN_present if
                              * present */
} LCSParameterRequestRes;

typedef struct InterSystemPositionRequestArg {
    unsigned char   bit_mask;
#       define      InterSystemPositionRequestArg_actionCode_present 0x80
#       define      InterSystemPositionRequestArg_imsi_present 0x40
    PositionRequestType positionRequestType;
    ActionCode      actionCode;  /* optional; set in bit_mask
                          * InterSystemPositionRequestArg_actionCode_present if
                          * present */
    GMAPIMSI        imsi;  /* optional; set in bit_mask
                            * InterSystemPositionRequestArg_imsi_present if
                            * present */
} InterSystemPositionRequestArg;

typedef struct InterSystemPositionRequestRes {
    unsigned char   bit_mask;
#       define      InterSystemPositionRequestRes_mscId_present 0x80
#       define      InterSystemPositionRequestRes_servingCellId_present 0x40
    PositionResult  positionResult;
    MSCID           mscId;  /* optional; set in bit_mask
                             * InterSystemPositionRequestRes_mscId_present if
                             * present */
    ServingCellID   servingCellId;  /* optional; set in bit_mask
                       * InterSystemPositionRequestRes_servingCellId_present if
                       * present */
} InterSystemPositionRequestRes;

typedef struct GeoPositionRequestArg {
    unsigned char   bit_mask;
#       define      GeoPositionRequestArg_mpcId_present 0x80
#       define      GeoPositionRequestArg_lcsBillingId_present 0x40
#       define      GeoPositionRequestArg_imsi_present 0x20
#       define      GeoPositionRequestArg_mscId_present 0x10
#       define      GeoPositionRequestArg_servingCellId_present 0x08
    MPCID           mpcId;  /* optional; set in bit_mask
                             * GeoPositionRequestArg_mpcId_present if present */
    LCSBillingID    lcsBillingId;  /* optional; set in bit_mask
                                    * GeoPositionRequestArg_lcsBillingId_present
                                    * if present */
    PositionRequestType positionRequestType;
    GMAPIMSI        imsi;  /* optional; set in bit_mask
                            * GeoPositionRequestArg_imsi_present if present */
    MSCID           mscId;  /* optional; set in bit_mask
                             * GeoPositionRequestArg_mscId_present if present */
    ServingCellID   servingCellId;  /* optional; set in bit_mask
                               * GeoPositionRequestArg_servingCellId_present if
                               * present */
} GeoPositionRequestArg;

typedef struct PositionInformation {
    unsigned char   bit_mask;
#       define      generalizedTime_present 0x80
#       define      geographicPosition_present 0x40
#       define      positionSource_present 0x20
#       define      horizontalVelocity_present 0x10
#       define      verticalVelocity_present 0x08
    struct {
        unsigned short  length;
        unsigned char   value[6];
    } generalizedTime;  /* optional; set in bit_mask generalizedTime_present if
                         * present */
                        /* 9f824b */
    struct {
        unsigned short  length;
        unsigned char   value[10];
    } geographicPosition;  /* optional; set in bit_mask
                            * geographicPosition_present if present */
                           /* 9f824d */
    struct {
        unsigned short  length;
        unsigned char   value[1];
    } positionSource;  /* optional; set in bit_mask positionSource_present if
                        * present */
                       /* 9f8253 */
    struct {
        unsigned short  length;
        unsigned char   value[5];
    } horizontalVelocity;  /* optional; set in bit_mask
                            * horizontalVelocity_present if present */
    struct {
        unsigned short  length;
        unsigned char   value[4];
    } verticalVelocity;  /* optional; set in bit_mask verticalVelocity_present
                          * if present */
} PositionInformation;

typedef struct GeoPositionRequestRes {
    unsigned char   bit_mask;
#       define      GeoPositionRequestRes_lcsBillingId_present 0x80
#       define      GeoPositionRequestRes_mscId_present 0x40
#       define      GeoPositionRequestRes_servingCellId_present 0x20
    LCSBillingID    lcsBillingId;  /* optional; set in bit_mask
                                    * GeoPositionRequestRes_lcsBillingId_present
                                    * if present */
    PositionResult  positionResult;
    PositionInformation positionInformation;
    MSCID           mscId;  /* optional; set in bit_mask
                             * GeoPositionRequestRes_mscId_present if present */
    ServingCellID   servingCellId;  /* optional; set in bit_mask
                               * GeoPositionRequestRes_servingCellId_present if
                               * present */
} GeoPositionRequestRes;

/* bhtak 2004/10/19 */
/* add SMSDPP */
typedef struct SMS_BearerData {
    unsigned short  length;
    unsigned char   value[200];
} SMS_BearerData; /* 9f69 */

typedef struct SMS_TeleserviceIdentifier {
    unsigned short  length;
    unsigned char   value[2];
} SMS_TeleserviceIdentifier; /* 9f74 */

typedef struct SMS_ChargeIndicator {
    unsigned short  length;
    unsigned char   value[1];
} SMS_ChargeIndicator; /* 9f6a */

typedef BCDDigits       SMS_DestinationAddress; /* 9f6b */

typedef struct SMS_MessageCount {
    unsigned short  length;
    unsigned char   value[1];
} SMS_MessageCount; /* 9f6c */

typedef BCDDigits       SMS_OriginalDestinationAddress;  /* 9f6e */

typedef BCDDigits       SMS_OriginalDestinationSubaddress;  /* 9f6f */

typedef BCDDigits       SMS_OriginalOriginatingAddress;  /* 9f70 */

typedef BCDDigits       SMS_OriginalOriginatingSubaddress;  /* 9f71 */

typedef BCDDigits       SMS_OriginatingAddress;  /* 9f72 */

/* new parameter is added */
typedef struct SMS_RoamingIndicator {
    unsigned short  length;
    unsigned char   value[1];
} SMS_RoamingIndicator; /* 9fff23 */

typedef struct SMSDeliveryPointToPointArg {
    unsigned short  bit_mask;
#       define      SMSDeliveryPointToPointArg_electronicSerialNumber_present 0x8000
#       define      SMSDeliveryPointToPointArg_mobileIdentificationNumber_present 0x4000
#       define      SMSDeliveryPointToPointArg_sms_chargeIndicator_present 0x2000
#       define      SMSDeliveryPointToPointArg_sms_destinationAddress_present 0x1000
#       define      SMSDeliveryPointToPointArg_sms_messageCount_present 0x0800
#       define      SMSDeliveryPointToPointArg_sms_notificationIndicator_present 0x0400
#       define      SMSDeliveryPointToPointArg_sms_originalDestinationAddress_present 0x0200
#       define      SMSDeliveryPointToPointArg_sms_originalDestinationSubaddress_present 0x0100
#       define      SMSDeliveryPointToPointArg_sms_originalOriginatingAddress_present 0x0080
#       define      SMSDeliveryPointToPointArg_sms_originalOriginatingSubaddress_present 0x0040
#       define      SMSDeliveryPointToPointArg_sms_originatingAddress_present 0x0020
#       define      SMSDeliveryPointToPointArg_originatingServiceFeaturesIndicator_present 0x0010
#       define      SMSDeliveryPointToPointArg_sms_roamingIndicator_present 0x0008
    SMS_BearerData  sms_bearerData;
    SMS_TeleserviceIdentifier sms_teleserviceIdentifier;
    ElectronicSerialNumber electronicSerialNumber;  /* optional; set in bit_mask
                 * SMSDeliveryPointToPointArg_electronicSerialNumber_present if
                 * present */
    MobileIdentificationNumber mobileIdentificationNumber;  /* optional; set in
                                   * bit_mask
             * SMSDeliveryPointToPointArg_mobileIdentificationNumber_present if
             * present */
    SMS_ChargeIndicator sms_chargeIndicator;  /* optional; set in bit_mask
                    * SMSDeliveryPointToPointArg_sms_chargeIndicator_present if
                    * present */
    SMS_DestinationAddress sms_destinationAddress;  /* optional; set in bit_mask
                 * SMSDeliveryPointToPointArg_sms_destinationAddress_present if
                 * present */
    SMS_MessageCount sms_messageCount;  /* optional; set in bit_mask
                       * SMSDeliveryPointToPointArg_sms_messageCount_present if
                       * present */
    SMS_NotificationIndicator sms_notificationIndicator;  /* optional; set in
                                   * bit_mask
              * SMSDeliveryPointToPointArg_sms_notificationIndicator_present if
              * present */
    SMS_OriginalDestinationAddress sms_originalDestinationAddress;  
                                  /* optional; set in bit_mask
         * SMSDeliveryPointToPointArg_sms_originalDestinationAddress_present if
         * present */
    SMS_OriginalDestinationSubaddress sms_originalDestinationSubaddress;  
                                        /* optional; set in bit_mask
      * SMSDeliveryPointToPointArg_sms_originalDestinationSubaddress_present if
      * present */
    SMS_OriginalOriginatingAddress sms_originalOriginatingAddress;  
                                  /* optional; set in bit_mask
         * SMSDeliveryPointToPointArg_sms_originalOriginatingAddress_present if
         * present */
    SMS_OriginalOriginatingSubaddress sms_originalOriginatingSubaddress;  
                                        /* optional; set in bit_mask
      * SMSDeliveryPointToPointArg_sms_originalOriginatingSubaddress_present if
      * present */
    SMS_OriginatingAddress sms_originatingAddress;  /* optional; set in bit_mask
                 * SMSDeliveryPointToPointArg_sms_originatingAddress_present if
                 * present */
    OriginatingServiceFeaturesIndicator originatingServiceFeaturesIndicator;  
                                        /* optional; set in bit_mask
    * SMSDeliveryPointToPointArg_originatingServiceFeaturesIndicator_present if
    * present */
    SMS_RoamingIndicator sms_roamingIndicator;  /* optional; set in bit_mask
                   * SMSDeliveryPointToPointArg_sms_roamingIndicator_present if
                   * present */
} SMSDeliveryPointToPointArg;

typedef struct SMS_CauseCode {
    unsigned short  length;
    unsigned char   value[1];
} SMS_CauseCode; /* 9f8119 */

typedef struct SMSDeliveryPointToPointRes {
    unsigned char   bit_mask;
#       define      sms_bearerData_present 0x80
#       define      sms_causeCode_present 0x40
    SMS_BearerData  sms_bearerData;  /* optional; set in bit_mask
                                      * sms_bearerData_present if present */
    SMS_CauseCode   sms_causeCode;  /* optional; set in bit_mask
                                     * sms_causeCode_present if present */
} SMSDeliveryPointToPointRes;

/* bhtak 2005/3/16 */
/* NumberPortabilityRequest */
typedef struct MSID {
    unsigned short  choice;
#       define      mobileIdentificationNumber_chosen 1
#       define      MSID_imsi_chosen 2
    union {
        MobileIdentificationNumber mobileIdentificationNumber;  /* to choose,
                                   * set choice to
                                   * mobileIdentificationNumber_chosen */
        GMAPIMSI        imsi;  /* to choose, set choice to MSID_imsi_chosen */
    } u;
} MSID;

typedef struct NumberPortabilityRequestArg {
    unsigned char   bit_mask;
#       define      NumberPortabilityRequestArg_callingPartyNumberDigits1_present 0x80
#       define      NumberPortabilityRequestArg_mscId_present 0x40
#       define      msId_present 0x20
    WinDigits       digits;
    CallingPartyNumberDigits1 callingPartyNumberDigits1;  /* optional; set in
                                   * bit_mask
             * NumberPortabilityRequestArg_callingPartyNumberDigits1_present if
             * present */
    MSCID           mscId;  /* optional; set in bit_mask
                             * NumberPortabilityRequestArg_mscId_present if
                             * present */
    MSID            msId;  /* optional; set in bit_mask msId_present if
                            * present */
} NumberPortabilityRequestArg;

typedef struct NumberPortabilityRequestRes {
    unsigned char   bit_mask;
#       define      NumberPortabilityRequestRes_routingDigits_present 0x80
    RoutingDigits   routingDigits;  /* optional; set in bit_mask
                         * NumberPortabilityRequestRes_routingDigits_present if
                         * present */
} NumberPortabilityRequestRes;

/* make aliases */
typedef SMSRequestArg   GMapSmsReqArg;

typedef SMSRequestRes   GMapSmsReqRes;

typedef SMSNotificationArg GMapSmsNotArg;

typedef SMSDeliveryPointToPointArg GMapSmsDppArg;

typedef SMSDeliveryPointToPointRes GMapSmsDppRes;

/* jhnoh 2006/10/09 */
typedef struct SMS_RoamingPmn {
    unsigned short  length;
    unsigned char   value[8];
} SMS_RoamingPmn; /* 9fff1b */

/* GW_SMSDPP for ¼¼´ë°£ ¹øÈ£ ÀÌµ¿¼º */
typedef struct GMapGwSmsDppArg {
    unsigned short  bit_mask;
#       define      GMapGwSmsDppArg_mobileIdentificationNumber_present 0x8000
#       define      GMapGwSmsDppArg_sms_chargeIndicator_present 0x4000
#       define      GMapGwSmsDppArg_sms_destinationAddress_present 0x2000
#       define      GMapGwSmsDppArg_sms_messageCount_present 0x1000
#       define      GMapGwSmsDppArg_sms_notificationIndicator_present 0x0800
#       define      GMapGwSmsDppArg_sms_originalDestinationAddress_present 0x0400
#       define      GMapGwSmsDppArg_sms_originalDestinationSubaddress_present 0x0200
#       define      GMapGwSmsDppArg_sms_originalOriginatingAddress_present 0x0100
#       define      GMapGwSmsDppArg_sms_originalOriginatingSubaddress_present 0x0080
#       define      GMapGwSmsDppArg_sms_originatingAddress_present 0x0040
#       define      GMapGwSmsDppArg_originatingServiceFeaturesIndicator_present 0x0020
#       define      GMapGwSmsDppArg_mscId_present 0x0010
#       define      GMapGwSmsDppArg_sms_roamingIndicator_present 0x0008
#       define      sms_roamingPmn_present 0x0004
    SMS_BearerData  sms_bearerData;
    SMS_TeleserviceIdentifier sms_teleserviceIdentifier;
    MobileIdentificationNumber mobileIdentificationNumber;  /* optional; set in
                                   * bit_mask
                        * GMapGwSmsDppArg_mobileIdentificationNumber_present if
                        * present */
    SMS_ChargeIndicator sms_chargeIndicator;  /* optional; set in bit_mask
                               * GMapGwSmsDppArg_sms_chargeIndicator_present if
                               * present */
    SMS_DestinationAddress sms_destinationAddress;  /* optional; set in bit_mask
                            * GMapGwSmsDppArg_sms_destinationAddress_present if
                            * present */
    SMS_MessageCount sms_messageCount;  /* optional; set in bit_mask
                                  * GMapGwSmsDppArg_sms_messageCount_present if
                                  * present */
    SMS_NotificationIndicator sms_notificationIndicator;  /* optional; set in
                                   * bit_mask
                         * GMapGwSmsDppArg_sms_notificationIndicator_present if
                         * present */
    SMS_OriginalDestinationAddress sms_originalDestinationAddress;  
                                  /* optional; set in bit_mask
                    * GMapGwSmsDppArg_sms_originalDestinationAddress_present if
                    * present */
    SMS_OriginalDestinationSubaddress sms_originalDestinationSubaddress;  
                                        /* optional; set in bit_mask
                 * GMapGwSmsDppArg_sms_originalDestinationSubaddress_present if
                 * present */
    SMS_OriginalOriginatingAddress sms_originalOriginatingAddress;  
                                  /* optional; set in bit_mask
                    * GMapGwSmsDppArg_sms_originalOriginatingAddress_present if
                    * present */
    SMS_OriginalOriginatingSubaddress sms_originalOriginatingSubaddress;  
                                        /* optional; set in bit_mask
                 * GMapGwSmsDppArg_sms_originalOriginatingSubaddress_present if
                 * present */
    SMS_OriginatingAddress sms_originatingAddress;  /* optional; set in bit_mask
                            * GMapGwSmsDppArg_sms_originatingAddress_present if
                            * present */
    OriginatingServiceFeaturesIndicator originatingServiceFeaturesIndicator;  
                                        /* optional; set in bit_mask
               * GMapGwSmsDppArg_originatingServiceFeaturesIndicator_present if
               * present */
    MSCID           mscId;  /* optional; set in bit_mask
                             * GMapGwSmsDppArg_mscId_present if present */
/*	locationAreaId						LocationAreaId			OPTIONAL, */
    SMS_RoamingIndicator sms_roamingIndicator;  /* optional; set in bit_mask
                              * GMapGwSmsDppArg_sms_roamingIndicator_present if
                              * present */
    SMS_RoamingPmn  sms_roamingPmn;  /* optional; set in bit_mask
                                      * sms_roamingPmn_present if present */
} GMapGwSmsDppArg;

typedef struct GW_OperationResult {
    unsigned short  length;
    unsigned char   value[1];
} GW_OperationResult; /* 0x9fff1f */

typedef struct GMapGwSmsDppRes {
    GW_OperationResult gw_operationResult;
} GMapGwSmsDppRes;

typedef struct GMapGwSmsNotiArg {
    unsigned char   bit_mask;
#       define      GMapGwSmsNotiArg_sms_accessDeniedReason_present 0x80
#       define      GMapGwSmsNotiArg_sms_address_present 0x40
#       define      GMapGwSmsNotiArg_mobileDirectoryNumber_present 0x20
    ElectronicSerialNumber electronicSerialNumber;
    MobileIdentificationNumber mobileIdentificationNumber;
    SMS_AccessDeniedReason sms_accessDeniedReason;  /* optional; set in bit_mask
                           * GMapGwSmsNotiArg_sms_accessDeniedReason_present if
                           * present */
    SMS_Address     sms_address;  /* optional; set in bit_mask
                                   * GMapGwSmsNotiArg_sms_address_present if
                                   * present */
    MobileDirectoryNumber mobileDirectoryNumber;  /* optional; set in bit_mask
                            * GMapGwSmsNotiArg_mobileDirectoryNumber_present if
                            * present */
} GMapGwSmsNotiArg;

typedef struct GMapGwSmsNotiRes {
    GW_OperationResult gw_operationResult;
} GMapGwSmsNotiRes;

typedef struct SMPP_Data {
    unsigned short  length;
    unsigned char   value[218];
} SMPP_Data; /* 9fff20 */

typedef struct GMapGwSmppArg {
    unsigned char   bit_mask;
#       define      GMapGwSmppArg_originatingServiceFeaturesIndicator_present 0x80
    SMPP_Data       smppData;
    OriginatingServiceFeaturesIndicator originatingServiceFeaturesIndicator;  
                                        /* optional; set in bit_mask
                 * GMapGwSmppArg_originatingServiceFeaturesIndicator_present if
                 * present */
} GMapGwSmppArg;

typedef struct GMapGwSmppRes {
    GW_OperationResult gw_operationResult;
} GMapGwSmppRes;

typedef Nulltype        KtRoamingIndForSM_null;

typedef Nulltype        KtReportSMRelayIndForSM_null;

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

/* v600 added by Nersion */

/*ktRoamingIndForSMData ::= NULL */
extern ObjectID kt_RoamingIndForSM;

extern MAP_EXTENSION ktRoamingIndForSM;

extern ObjectID kt_ReportSMRelayIndForSM;

extern MAP_EXTENSION ktReportSMRelayIndForSM;

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

extern ObjectID anyTimeInfoHandlingContext_v3;

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
