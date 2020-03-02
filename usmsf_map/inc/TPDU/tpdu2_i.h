#ifndef TPDU2_IH
#define TPDU2_IH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __TYPE_BYTE_
#define __TYPE_BYTE_
    typedef unsigned char byte;
#endif

//------------------------------------------
#define TPDU_ELEMENT_ID                                           3000  //
#define TPDU_ELEMENT_LENGTH                                       3001  //
#define TPDU_ELEMENT_DATA                                         3002  //

//------------------------------------------
#define TPDU_DATACODINGSCHEME_CODINGGROUP                         4000  //
#define TPDU_DATACODINGSCHEME_ISCOMPRESSED                        4001  //
#define TPDU_DATACODINGSCHEME_ISCLASS                             4002  //
#define TPDU_DATACODINGSCHEME_ALPHABET                            4003  //
#define TPDU_DATACODINGSCHEME_CLASS                               4004  //

//------------------------------------------
#define TPDU_USERDATAHEADER_LENGTH                               14000  //
#define TPDU_USERDATAHEADER_ELEMENTCOUNT                         14001  //
#define TPDU_USERDATAHEADER_ELEMENT                              14002  //

//------------------------------------------
#define TPDU_USERDATA_LENGTH                                     19000  //
#define TPDU_USERDATA_USERDATAHEADER                             19001  //
#define TPDU_USERDATA_DATALENGTH                                 19002  //
#define TPDU_USERDATA_DATA                                       19003  //

//------------------------------------------
#define TPDU_TIMESTAMP_YEAR                                       7000  //
#define TPDU_TIMESTAMP_MONTH                                      7001  //
#define TPDU_TIMESTAMP_DAY                                        7002  //
#define TPDU_TIMESTAMP_HOUR                                       7003  //
#define TPDU_TIMESTAMP_MIN                                        7004  //
#define TPDU_TIMESTAMP_SEC                                        7005  //
#define TPDU_TIMESTAMP_TIMEZONE                                   7006  //

//------------------------------------------
#define TPDU_ADDRESS_MIN                                          5000  //
#define TPDU_ADDRESS_TON                                          5001  //
#define TPDU_ADDRESS_NPI                                          5002  //
#define TPDU_ADDRESS_LEN                                          5003  //
#define TPDU_ADDRESS_RESERVED                                     5004  //

//------------------------------------------
#define TPDU_PARAMETER_ISPIDPRESENT                              10000  //
#define TPDU_PARAMETER_ISDCSPRESENT                              10001  //
#define TPDU_PARAMETER_ISUDLPRESENT                              10002  //

//------------------------------------------
#define TPDU_SMSDELIVER_MSGTYPEID                                37000  //Message Type
#define TPDU_SMSDELIVER_MOREMSGTOSEND                            37001  //
#define TPDU_SMSDELIVER_REPLYPATH                                37002  //
#define TPDU_SMSDELIVER_USERDATAHEADERID                         37003  //
#define TPDU_SMSDELIVER_STATUSREPORTID                           37004  //
#define TPDU_SMSDELIVER_ORIGINATINGADDR                          37005  //
#define TPDU_SMSDELIVER_PROTOCOLID                               37006  //
#define TPDU_SMSDELIVER_DATACODINGSCHEME                         37007  //
#define TPDU_SMSDELIVER_TIMESTAMP                                37008  //
#define TPDU_SMSDELIVER_USERDATALENGTH                           37009  //
#define TPDU_SMSDELIVER_USERDATA                                 37010  //

//------------------------------------------
#define TPDU_SMSDELIVERREPORT_MESSAGETYPEID                       1000  //
#define TPDU_SMSDELIVERREPORT_USERDATAHEADERID                    1001  //
#define TPDU_SMSDELIVERREPORT_FAILURECAUSE                        1002  //
#define TPDU_SMSDELIVERREPORT_PARAMETERID                         1003  //
#define TPDU_SMSDELIVERREPORT_PROTOCOLID                          1004  //
#define TPDU_SMSDELIVERREPORT_DATACODINGSCHEME                    1005  //
#define TPDU_SMSDELIVERREPORT_USERDATALENGTH                      1006  //
#define TPDU_SMSDELIVERREPORT_USERDATA                            1007  //

//------------------------------------------
#define TPDU_SMSSUBMIT_MESSAGETYPEID                              2000  //
#define TPDU_SMSSUBMIT_REJECTDUPLICATES                           2001  //
#define TPDU_SMSSUBMIT_VALIDITYPERIODFORMAT                       2002  //
#define TPDU_SMSSUBMIT_REPLYPATH                                  2003  //
#define TPDU_SMSSUBMIT_USERDATAHEADERID                           2004  //
#define TPDU_SMSSUBMIT_STATUSREPORTREQUEST                        2005  //
#define TPDU_SMSSUBMIT_MESSAGEREFERENCE                           2006  //
#define TPDU_SMSSUBMIT_DESTINATIONADDR                            2007  //
#define TPDU_SMSSUBMIT_PROTOCOLID                                 2008  //
#define TPDU_SMSSUBMIT_DATACODINGSCHEME                           2009  //
#define TPDU_SMSSUBMIT_VALIDITYRELATIVE                           2010  //
#define TPDU_SMSSUBMIT_VALIDITYPERIODABSOLUTE                     2011  //
#define TPDU_SMSSUBMIT_VALIDITYPERIODENHANCED                     2012  //
#define TPDU_SMSSUBMIT_USERDATALENGTH                             2013  //
#define TPDU_SMSSUBMIT_USERDATA                                   2014  //

//------------------------------------------
#define TPDU_SMSSUBMITREPORT_MESSAGETYPEID                        6000  //
#define TPDU_SMSSUBMITREPORT_USERDATAHEADERID                     6001  //
#define TPDU_SMSSUBMITREPORT_FAILURECAUSE                         6002  //
#define TPDU_SMSSUBMITREPORT_PARAMETERID                          6003  //
#define TPDU_SMSSUBMITREPORT_TIMESTAMP                            6004  //
#define TPDU_SMSSUBMITREPORT_PROTOCOLID                           6005  //
#define TPDU_SMSSUBMITREPORT_DATACODINGSCHEME                     6006  //
#define TPDU_SMSSUBMITREPORT_USERDATALENGTH                       6007  //
#define TPDU_SMSSUBMITREPORT_USERDATA                             6008  //

//------------------------------------------
#define TPDU_SMSSTATUSREPORT_MESSAGETYPEID                        8000  //
#define TPDU_SMSSTATUSREPORT_USERDATAHEADERID                     8001  //
#define TPDU_SMSSTATUSREPORT_MOREMESSAGESTOSEND                   8002  //
#define TPDU_SMSSTATUSREPORT_STATUSREPORTQUALIFIER                8003  //
#define TPDU_SMSSTATUSREPORT_MESSAGEREFERENCE                     8004  //
#define TPDU_SMSSTATUSREPORT_RECIPIENTADDR                        8005  //
#define TPDU_SMSSTATUSREPORT_TIMESTAMP                            8006  //
#define TPDU_SMSSTATUSREPORT_DISCHARGETIME                        8007  //
#define TPDU_SMSSTATUSREPORT_STATUS                               8008  //
#define TPDU_SMSSTATUSREPORT_PARAMETERID                          8009  //
#define TPDU_SMSSTATUSREPORT_PROTOCOLID                           8010  //
#define TPDU_SMSSTATUSREPORT_DATACODINGSCHEME                     8011  //
#define TPDU_SMSSTATUSREPORT_USERDATALENGTH                       8012  //
#define TPDU_SMSSTATUSREPORT_USERDATA                             8013  //

//------------------------------------------
#define TPDU_SMSCOMMAND_MESSAGETYPEID                             9000  //
#define TPDU_SMSCOMMAND_USERDATAHEADERID                          9001  //
#define TPDU_SMSCOMMAND_STATUSREPORTREQUEST                       9002  //
#define TPDU_SMSCOMMAND_MESSAGEREFERENCE                          9003  //
#define TPDU_SMSCOMMAND_PROTOCOLID                                9004  //
#define TPDU_SMSCOMMAND_COMMANDTYPE                               9005  //
#define TPDU_SMSCOMMAND_MESSAGENUMBER                             9006  //
#define TPDU_SMSCOMMAND_DESTINATIONADDR                           9007  //
#define TPDU_SMSCOMMAND_COMMANDDATALENGTH                         9008  //
#define TPDU_SMSCOMMAND_COMMANDDATA                               9009  //

#define ELEMENT_DATALEN 140

typedef struct _stEI {
    byte          ID;                 //[InOut]    
    byte          Length;             //[InOut]    
    byte          Data[ELEMENT_DATALEN];          //[InOut]    
} stEI;


typedef struct _stUDH {
    int           Length;             //[InOut]    
    int           eiCnt;       //[InOut]    
    stEI          ei[70];        //[InOut]    
} stUDH;


typedef struct {
    int           Length;             //[InOut]    
    stUDH         udh;     //[InOut]    
    int           DataLength;         //[InOut]    
//    byte          Data[140];          //[InOut]    
    byte          Data[160];          //[InOut]    
} TUserData;


typedef struct {
    int           Year;               //[InOut]    
    byte          Month;              //[InOut]    
    byte          Day;                //[InOut]    
    byte          Hour;               //[InOut]    
    byte          Min;                //[InOut]    
    byte          Sec;                //[InOut]    
    char          TimeZone;           //[InOut]    
} TTimeStamp;


typedef struct {
    byte          min[25];            //[InOut]    
    byte          ton;                //[InOut]    
    byte          npi;                //[InOut]    
    byte          len;                //[InOut]    
} TAddress;


typedef struct {
    int           isPIDPresent;       //[InOut]    
    int           isDCSPresent;       //[InOut]    
    int           isUDLPresent;       //[InOut]    
} TParameter;


typedef struct {
    byte          MsgTypeID;          //[InOut]    Message Type
    byte          MoreMsgToSend;      //[InOut]    
    byte          ReplyPath;          //[InOut]    
    byte          udhId;   //[InOut]    
    byte          StatusReportID;     //[InOut]    
    TAddress      OriginatingAddr;    //[InOut]    
    byte          pid;         //[InOut]    
    byte          dcs;   //[InOut]    
    TTimeStamp    TimeStamp;          //[InOut]    
    byte          UserDataLength;     //[InOut]    
    TUserData     UserData;           //[InOut]    
	byte          RawDataLength;      //[Out] by Charge  
	char          RawData[200];       //[Out] by Charge 
} TSMSDeliver;


typedef struct {
    byte          MessageTypeID;      //[InOut]    
    byte          udhId;   //[InOut]    
    byte          FailureCause;       //[InOut]    
    TParameter    ParameterID;        //[InOut]    
    byte          pid;         //[InOut]    
    byte          dcs;   //[InOut]    
    byte          UserDataLength;     //[InOut]    
    TUserData     UserData;           //[InOut]    
} TSMSDeliverReport;


typedef struct {
    byte          MessageTypeID;      //[InOut]    
    byte          RejectDuplicates;   //[InOut]    
    byte          ValidityPeriodFormat;//[InOut]    
    byte          ReplyPath;          //[InOut]    
    byte          udhId;   //[InOut]    
    byte          StatusReportRequest;//[InOut]    
    byte          MessageReference;   //[InOut]    
    TAddress      DestinationAddr;    //[InOut]    
    byte          pid;         //[InOut]    
    byte          dcs;   //[InOut]    
    byte          ValidityRelative;   //[InOut]    
    TTimeStamp    ValidityPeriodAbsolute;//[InOut]    
    byte          ValidityPeriodEnhanced[7];//[InOut]    
    byte          UserDataLength;     //[InOut]    
    TUserData     UserData;           //[InOut]    
	byte          RawDataLength;      //[Out] by Charge  
	char          RawData[200];       //[Out] by Charge 
	//char		  rawData[200];		  //[InOut]
} TSMSSubmit;


typedef struct {
    byte          MessageTypeID;      //[InOut]    
    byte          udhId;   //[InOut]    
    byte          FailureCause;       //[InOut]    
    TParameter    ParameterID;        //[InOut]    
    TTimeStamp    TimeStamp;          //[InOut]    
    byte          pid;         //[InOut]    
    byte          dcs;   //[InOut]    
    byte          UserDataLength;     //[InOut]    
    TUserData     UserData;           //[InOut]    
} TSMSSubmitReport;


typedef struct {
    byte          MessageTypeID;      //[InOut]    
    byte          udhId;   //[InOut]    
    byte          MoreMessagesToSend; //[InOut]    
    byte          StatusReportQualifier;//[InOut]    
    byte          MessageReference;   //[InOut]    
    TAddress      RecipientAddr;      //[InOut]    
    TTimeStamp    TimeStamp;          //[InOut]    
    TTimeStamp    DischargeTime;      //[InOut]    
    byte          Status;             //[InOut]    
    TParameter    ParameterID;        //[InOut]    
    byte          pid;         //[InOut]    
    byte          dcs;   //[InOut]    
    byte          UserDataLength;     //[InOut]    
    TUserData     UserData;           //[InOut]    
} TSMSStatusReport;


typedef struct {
    byte          MessageTypeID;      //[InOut]    
    byte          udhId;   //[InOut]    
    byte          StatusReportRequest;//[InOut]    
    byte          MessageReference;   //[InOut]    
    byte          pid;         //[InOut]    
    byte          CommandType;        //[InOut]    
    byte          MessageNumber;      //[InOut]    
    TAddress      DestinationAddr;    //[InOut]    
    byte          CommandDataLength;  //[InOut]    
    byte          CommandData[157];   //[InOut]    
} TSMSCommand;


typedef union {
    stEI ei;
    byte          dcs;
    stUDH         udh;
    TUserData     UserData;
    TTimeStamp    TimeStamp;
    TAddress      Address;
    TParameter    Parameter;
    TSMSDeliver   SMSDeliver;
    TSMSDeliverReport SMSDeliverReport;
    TSMSSubmit    SMSSubmit;
    TSMSSubmitReport SMSSubmitReport;
    TSMSStatusReport SMSStatusReport;
    TSMSCommand   SMSCommand;
} ITPDU;


int Element_StructSetInOut(stEI *Struct, byte ID, byte Length,
        byte Data[140]);

int UserDataHeader_StructSetInOut(stUDH *Struct, int Length,
        int eiCnt, stEI ei[70]);

int UserData_StructSetInOut(TUserData *Struct
        ,int Length
        ,stUDH *udh
        ,int DataLength
        ,byte Data[140]);
int TimeStamp_StructSetInOut(TTimeStamp *Struct
        ,int Year
        ,byte Month
        ,byte Day
        ,byte Hour
        ,byte Min
        ,byte Sec
        ,byte TimeZone);
int Address_StructSetInOut(TAddress *Struct
        ,byte min[20]
        ,byte ton
        ,byte npi
        ,byte len
        ,byte reserved);
int Parameter_StructSetInOut(TParameter *Struct
        ,int isPIDPresent
        ,int isDCSPresent
        ,int isUDLPresent);
int SMSDeliver_StructSetInOut(TSMSDeliver *Struct
        ,byte MsgTypeID
        ,byte MoreMsgToSend
        ,byte ReplyPath
        ,byte udhId
        ,byte StatusReportID
        ,TAddress *OriginatingAddr
        ,byte pid
        ,byte dcs
        ,TTimeStamp *TimeStamp
        ,byte UserDataLength
        ,TUserData *UserData);
int SMSDeliverReport_StructSetInOut(TSMSDeliverReport *Struct
        ,byte MessageTypeID
        ,byte udhId
        ,byte FailureCause
        ,TParameter *ParameterID
        ,byte pid
        ,byte dcs
        ,byte UserDataLength
        ,TUserData *UserData);
int SMSSubmit_StructSetInOut(TSMSSubmit *Struct
        ,byte MessageTypeID
        ,byte RejectDuplicates
        ,byte ValidityPeriodFormat
        ,byte ReplyPath
        ,byte udhId
        ,byte StatusReportRequest
        ,byte MessageReference
        ,TAddress *DestinationAddr
        ,byte pid
        ,byte dcs
        ,byte ValidityRelative
        ,TTimeStamp *ValidityPeriodAbsolute
        ,byte ValidityPeriodEnhanced[7]
        ,byte UserDataLength
        ,TUserData *UserData
		,char rawData[200]);
int SMSSubmitReport_StructSetInOut(TSMSSubmitReport *Struct
        ,byte MessageTypeID
        ,byte udhId
        ,byte FailureCause
        ,TParameter *ParameterID
        ,TTimeStamp *TimeStamp
        ,byte pid
        ,byte dcs
        ,byte UserDataLength
        ,TUserData *UserData);
int SMSStatusReport_StructSetInOut(TSMSStatusReport *Struct
        ,byte MessageTypeID
        ,byte udhId
        ,byte MoreMessagesToSend
        ,byte StatusReportQualifier
        ,byte MessageReference
        ,TAddress *RecipientAddr
        ,TTimeStamp *TimeStamp
        ,TTimeStamp *DischargeTime
        ,byte Status
        ,TParameter *ParameterID
        ,byte pid
        ,byte dcs
        ,byte UserDataLength
        ,TUserData *UserData);
int SMSCommand_StructSetInOut(TSMSCommand *Struct
        ,byte MessageTypeID
        ,byte udhId
        ,byte StatusReportRequest
        ,byte MessageReference
        ,byte pid
        ,byte CommandType
        ,byte MessageNumber
        ,TAddress *DestinationAddr
        ,byte CommandDataLength
        ,byte CommandData[157]);
//--------------------------------------------------------
//
//   _StructGet
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int Element_StructGetInOut(stEI *Struct
        ,byte *ID
        ,byte *Length
        ,byte Data[140]);

int UserDataHeader_StructGetInOut(stUDH *Struct
        ,int *Length
        ,int *eiCnt
        ,stEI ei[70]);
int UserData_StructGetInOut(TUserData *Struct
        ,int *Length
        ,stUDH *udh
        ,int *DataLength
        ,byte Data[140]);
int TimeStamp_StructGetInOut(TTimeStamp *Struct
        ,int *Year
        ,byte *Month
        ,byte *Day
        ,byte *Hour
        ,byte *Min
        ,byte *Sec
        ,byte *TimeZone);
int Address_StructGetInOut(TAddress *Struct
        ,byte min[20]
        ,byte *ton
        ,byte *npi
        ,byte *len
        ,byte *reserved);
int Parameter_StructGetInOut(TParameter *Struct
        ,int *isPIDPresent
        ,int *isDCSPresent
        ,int *isUDLPresent);
int SMSDeliver_StructGetInOut(TSMSDeliver *Struct
        ,byte *MsgTypeID
        ,byte *MoreMsgToSend
        ,byte *ReplyPath
        ,byte *udhId
        ,byte *StatusReportID
        ,TAddress *OriginatingAddr
        ,byte *pid
        ,byte *dcs
        ,TTimeStamp *TimeStamp
        ,byte *UserDataLength
        ,TUserData *UserData);
int SMSDeliverReport_StructGetInOut(TSMSDeliverReport *Struct
        ,byte *MessageTypeID
        ,byte *udhId
        ,byte *FailureCause
        ,TParameter *ParameterID
        ,byte *pid
        ,byte *dcs
        ,byte *UserDataLength
        ,TUserData *UserData);
int SMSSubmit_StructGetInOut(TSMSSubmit *Struct
        ,byte *MessageTypeID
        ,byte *RejectDuplicates
        ,byte *ValidityPeriodFormat
        ,byte *ReplyPath
        ,byte *udhId
        ,byte *StatusReportRequest
        ,byte *MessageReference
        ,TAddress *DestinationAddr
        ,byte *pid
        ,byte *dcs
        ,byte *ValidityRelative
        ,TTimeStamp *ValidityPeriodAbsolute
        ,byte ValidityPeriodEnhanced[7]
        ,byte *UserDataLength
        ,TUserData *UserData);
int SMSSubmitReport_StructGetInOut(TSMSSubmitReport *Struct
        ,byte *MessageTypeID
        ,byte *udhId
        ,byte *FailureCause
        ,TParameter *ParameterID
        ,TTimeStamp *TimeStamp
        ,byte *pid
        ,byte *dcs
        ,byte *UserDataLength
        ,TUserData *UserData);
int SMSStatusReport_StructGetInOut(TSMSStatusReport *Struct
        ,byte *MessageTypeID
        ,byte *udhId
        ,byte *MoreMessagesToSend
        ,byte *StatusReportQualifier
        ,byte *MessageReference
        ,TAddress *RecipientAddr
        ,TTimeStamp *TimeStamp
        ,TTimeStamp *DischargeTime
        ,byte *Status
        ,TParameter *ParameterID
        ,byte *pid
        ,byte *dcs
        ,byte *UserDataLength
        ,TUserData *UserData);
int SMSCommand_StructGetInOut(TSMSCommand *Struct
        ,byte *MessageTypeID
        ,byte *udhId
        ,byte *StatusReportRequest
        ,byte *MessageReference
        ,byte *pid
        ,byte *CommandType
        ,byte *MessageNumber
        ,TAddress *DestinationAddr
        ,byte *CommandDataLength
        ,byte CommandData[157]);
//--------------------------------------------------------
//
//   _StructClear
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int Element_StructClearInOut(stEI *Struct);
int UserDataHeader_StructClearInOut(stUDH *Struct);
int UserData_StructClearInOut(TUserData *Struct);
int TimeStamp_StructClearInOut(TTimeStamp *Struct);
int Address_StructClearInOut(TAddress *Struct);
int Parameter_StructClearInOut(TParameter *Struct);
int SMSDeliver_StructClearInOut(TSMSDeliver *Struct);
int SMSDeliverReport_StructClearInOut(TSMSDeliverReport *Struct);
int SMSSubmit_StructClearInOut(TSMSSubmit *Struct);
int SMSSubmitReport_StructClearInOut(TSMSSubmitReport *Struct);
int SMSStatusReport_StructClearInOut(TSMSStatusReport *Struct);
int SMSCommand_StructClearInOut(TSMSCommand *Struct);
//--------------------------------------------------------
//
//   _StructToScreen
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int Element_StructToScreenInOut(stEI *Struct);
int UserDataHeader_StructToScreenInOut(stUDH *Struct);
int UserData_StructToScreenInOut(TUserData *Struct);
int TimeStamp_StructToScreenInOut(TTimeStamp *Struct);
int Address_StructToScreenInOut(TAddress *Struct);
int Parameter_StructToScreenInOut(TParameter *Struct);
int SMSDeliver_StructToScreenInOut(TSMSDeliver *Struct);
int SMSDeliverReport_StructToScreenInOut(TSMSDeliverReport *Struct);
int SMSSubmit_StructToScreenInOut(TSMSSubmit *Struct);
int SMSSubmitReport_StructToScreenInOut(TSMSSubmitReport *Struct);
int SMSStatusReport_StructToScreenInOut(TSMSStatusReport *Struct);
int SMSCommand_StructToScreenInOut(TSMSCommand *Struct);
//--------------------------------------------------------
//
//   TPDU Interface Functions
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int TPDU_SetField(ITPDU *TPDU, int FieldID, void *Value);
int TPDU_GetField(ITPDU *TPDU, int FieldID, void *Value);
int TPDU_CmpField(ITPDU *TPDU, int FieldID, void *Value);
#endif
