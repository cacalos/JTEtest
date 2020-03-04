#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TPDU/tpdu2_i.h"

//--------------------------------------------------------
//
//   SWAP4(int)
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int _SWAP4(int Value)
{
   int Temp;

   Temp=(Value<<24)  & 0xFF000000;
   Temp|=(Value<<8)  & 0x00FF0000;
   Temp|=(Value>>8)  & 0x0000FF00;
   Temp|=(Value>>24) & 0x000000FF;

   return Temp;
}

//--------------------------------------------------------
//
//   SWAP2(short)
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int _SWAP2(int Value)
{
   int Temp;

   Temp=(Value<<8) & 0xFF00;
   Temp|=(Value>>8) & 0x00FF;

   return Temp;
}


int Element_StructSetInOut(stEI *Struct
		,byte ID
		,byte Length
		,byte Data[140])
{

	Struct->ID=ID;
	Struct->Length=Length;
	memcpy((char *)Struct->Data,(char *)Data,Length*1);

	return sizeof(stEI);
}


int UserDataHeader_StructSetInOut(stUDH *Struct, int Length,
        int eiCnt, stEI ei[70])
{
	Struct->Length = Length;
	Struct->eiCnt = eiCnt;
	if(ei != NULL)
        memcpy((char *)Struct->ei, (char *)ei, eiCnt*142);

	return sizeof(stUDH);
}


int UserData_StructSetInOut(TUserData *Struct
		,int Length
		,stUDH *udh
		,int DataLength
		,byte Data[140])
{

	Struct->Length=Length;
	if(udh!=NULL) Struct->udh=*udh;
	Struct->DataLength=DataLength;
	memcpy((char *)Struct->Data,(char *)Data,DataLength*1);

	return sizeof(TUserData);
}

//--------------------------------------------------------
//
//   TimeStamp_StructSetInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int TimeStamp_StructSetInOut(TTimeStamp *Struct
		,int Year
		,byte Month
		,byte Day
		,byte Hour
		,byte Min
		,byte Sec
		,byte TimeZone)
{

	Struct->Year=Year;
	Struct->Month=Month;
	Struct->Day=Day;
	Struct->Hour=Hour;
	Struct->Min=Min;
	Struct->Sec=Sec;
	Struct->TimeZone=TimeZone;

	return sizeof(TTimeStamp);
}

//--------------------------------------------------------
//
//   Address_StructSetInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int Address_StructSetInOut(TAddress *Struct
		,byte min[20]
		,byte ton
		,byte npi
		,byte len
		,byte reserved)
{

	memcpy((char *)Struct->min,(char *)min,len*1);
	Struct->ton=ton;
	Struct->npi=npi;
	Struct->len=len;
    /*
	Struct->reserved=reserved;
    */

	return sizeof(TAddress);
}

//--------------------------------------------------------
//
//   Parameter_StructSetInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int Parameter_StructSetInOut(TParameter *Struct
		,int isPIDPresent
		,int isDCSPresent
		,int isUDLPresent)
{

	Struct->isPIDPresent=isPIDPresent;
	Struct->isDCSPresent=isDCSPresent;
	Struct->isUDLPresent=isUDLPresent;

	return sizeof(TParameter);
}

//--------------------------------------------------------
//
//   SMSDeliver_StructSetInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
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
		,TUserData *UserData)
{

	Struct->MsgTypeID=MsgTypeID;
	Struct->MoreMsgToSend=MoreMsgToSend;
	Struct->ReplyPath=ReplyPath;
	Struct->udhId=udhId;
	Struct->StatusReportID=StatusReportID;
	if(OriginatingAddr!=NULL) Struct->OriginatingAddr=*OriginatingAddr;
	Struct->pid = pid;
	Struct->dcs = dcs;
	if(TimeStamp!=NULL) Struct->TimeStamp=*TimeStamp;
	Struct->UserDataLength=UserDataLength;
	if(UserData!=NULL) Struct->UserData=*UserData;

	return sizeof(TSMSDeliver);
}

//--------------------------------------------------------
//
//   SMSDeliverReport_StructSetInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int SMSDeliverReport_StructSetInOut(TSMSDeliverReport *Struct
		,byte MessageTypeID
		,byte udhId
		,byte FailureCause
		,TParameter *ParameterID
		,byte pid
		,byte dcs
		,byte UserDataLength
		,TUserData *UserData)
{

	Struct->MessageTypeID=MessageTypeID;
	Struct->udhId=udhId;
	Struct->FailureCause=FailureCause;
	if(ParameterID!=NULL) Struct->ParameterID=*ParameterID;
	Struct->pid = pid;
	Struct->dcs = dcs;
	Struct->UserDataLength=UserDataLength;
	if(UserData!=NULL) Struct->UserData=*UserData;

	return sizeof(TSMSDeliverReport);
}


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
		,char *rawData)
{

	Struct->MessageTypeID=MessageTypeID;
	Struct->RejectDuplicates=RejectDuplicates;
	Struct->ValidityPeriodFormat=ValidityPeriodFormat;
	Struct->ReplyPath=ReplyPath;
	Struct->udhId=udhId;
	Struct->StatusReportRequest=StatusReportRequest;
	Struct->MessageReference=MessageReference;
	if(DestinationAddr!=NULL) Struct->DestinationAddr=*DestinationAddr;
	Struct->pid = pid;
	Struct->dcs = dcs;
	Struct->ValidityRelative=ValidityRelative;
	if(ValidityPeriodAbsolute!=NULL) Struct->ValidityPeriodAbsolute=*ValidityPeriodAbsolute;
	memcpy((char *)Struct->ValidityPeriodEnhanced,(char *)ValidityPeriodEnhanced,7*1);
	Struct->UserDataLength=UserDataLength;
	if(UserData!=NULL) Struct->UserData=*UserData;
	memcpy((char *)Struct->RawData, (char *)rawData, 200);
	
	return sizeof(TSMSSubmit);
}

//--------------------------------------------------------
//
//   SMSSubmitReport_StructSetInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int SMSSubmitReport_StructSetInOut(TSMSSubmitReport *Struct
		,byte MessageTypeID
		,byte udhId
		,byte FailureCause
		,TParameter *ParameterID
		,TTimeStamp *TimeStamp
		,byte pid
		,byte dcs
		,byte UserDataLength
		,TUserData *UserData)
{

	Struct->MessageTypeID=MessageTypeID;
	Struct->udhId=udhId;
	Struct->FailureCause=FailureCause;
	if(ParameterID!=NULL) Struct->ParameterID=*ParameterID;
	if(TimeStamp!=NULL) Struct->TimeStamp=*TimeStamp;
	Struct->pid = pid;
	Struct->dcs = dcs;
	Struct->UserDataLength=UserDataLength;
	if(UserData!=NULL) Struct->UserData=*UserData;

	return sizeof(TSMSSubmitReport);
}

//--------------------------------------------------------
//
//   SMSStatusReport_StructSetInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
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
		,TUserData *UserData)
{

	Struct->MessageTypeID=MessageTypeID;
	Struct->udhId=udhId;
	Struct->MoreMessagesToSend=MoreMessagesToSend;
	Struct->StatusReportQualifier=StatusReportQualifier;
	Struct->MessageReference=MessageReference;
	if(RecipientAddr!=NULL) Struct->RecipientAddr=*RecipientAddr;
	if(TimeStamp!=NULL) Struct->TimeStamp=*TimeStamp;
	if(DischargeTime!=NULL) Struct->DischargeTime=*DischargeTime;
	Struct->Status=Status;
	if(ParameterID!=NULL) Struct->ParameterID=*ParameterID;
	Struct->pid = pid;
	Struct->dcs = dcs;
	Struct->UserDataLength=UserDataLength;
	if(UserData!=NULL) Struct->UserData=*UserData;

	return sizeof(TSMSStatusReport);
}

//--------------------------------------------------------
//
//   SMSCommand_StructSetInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
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
		,byte CommandData[157])
{

	Struct->MessageTypeID=MessageTypeID;
	Struct->udhId=udhId;
	Struct->StatusReportRequest=StatusReportRequest;
	Struct->MessageReference=MessageReference;
	Struct->pid = pid;
	Struct->CommandType=CommandType;
	Struct->MessageNumber=MessageNumber;
	if(DestinationAddr!=NULL) Struct->DestinationAddr=*DestinationAddr;
	Struct->CommandDataLength=CommandDataLength;
	memcpy((char *)Struct->CommandData,(char *)CommandData,CommandDataLength*1);

	return sizeof(TSMSCommand);
}


int Element_StructGetInOut(stEI *Struct
		,byte *ID
		,byte *Length
		,byte Data[140])
{

	if(ID!=NULL) *ID=Struct->ID;
	if(Length!=NULL) *Length=Struct->Length;
	if(Data!=NULL) memcpy((char *)Data,(char *)Struct->Data,Struct->Length*1);

	return sizeof(stEI);
}


int UserDataHeader_StructGetInOut(stUDH *Struct, int *Length,
        int *eiCnt, stEI ei[70])
{
	if(Length != NULL)       *Length=Struct->Length;
	if(eiCnt != NULL) *eiCnt=Struct->eiCnt;
	if(ei != NULL)
        memcpy((char *)ei, (char *)Struct->ei,
            Struct->eiCnt*142);

	return sizeof(stUDH);
}


int UserData_StructGetInOut(TUserData *Struct
		,int *Length
		,stUDH *udh
		,int *DataLength
		,byte Data[140])
{

	if(Length!=NULL) *Length=Struct->Length;
	if(udh!=NULL) *udh=Struct->udh;
	if(DataLength!=NULL) *DataLength=Struct->DataLength;
	if(Data!=NULL) memcpy((char *)Data,(char *)Struct->Data,Struct->DataLength*1);

	return sizeof(TUserData);
}

//--------------------------------------------------------
//
//   TimeStamp_StructGetInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int TimeStamp_StructGetInOut(TTimeStamp *Struct
		,int *Year
		,byte *Month
		,byte *Day
		,byte *Hour
		,byte *Min
		,byte *Sec
		,byte *TimeZone)
{

	if(Year!=NULL) *Year=Struct->Year;
	if(Month!=NULL) *Month=Struct->Month;
	if(Day!=NULL) *Day=Struct->Day;
	if(Hour!=NULL) *Hour=Struct->Hour;
	if(Min!=NULL) *Min=Struct->Min;
	if(Sec!=NULL) *Sec=Struct->Sec;
	if(TimeZone!=NULL) *TimeZone=Struct->TimeZone;

	return sizeof(TTimeStamp);
}

//--------------------------------------------------------
//
//   Address_StructGetInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int Address_StructGetInOut(TAddress *Struct
		,byte min[20]
		,byte *ton
		,byte *npi
		,byte *len
		,byte *reserved)
{

	if(min!=NULL) memcpy((char *)min,(char *)Struct->min,Struct->len*1);
	if(ton!=NULL) *ton=Struct->ton;
	if(npi!=NULL) *npi=Struct->npi;
	if(len!=NULL) *len=Struct->len;
    /*
	if(reserved!=NULL) *reserved=Struct->reserved;
    */

	return sizeof(TAddress);
}

//--------------------------------------------------------
//
//   Parameter_StructGetInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int Parameter_StructGetInOut(TParameter *Struct
		,int *isPIDPresent
		,int *isDCSPresent
		,int *isUDLPresent)
{

	if(isPIDPresent!=NULL) *isPIDPresent=Struct->isPIDPresent;
	if(isDCSPresent!=NULL) *isDCSPresent=Struct->isDCSPresent;
	if(isUDLPresent!=NULL) *isUDLPresent=Struct->isUDLPresent;

	return sizeof(TParameter);
}

//--------------------------------------------------------
//
//   SMSDeliver_StructGetInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
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
		,TUserData *UserData)
{

	if(MsgTypeID != NULL)       *MsgTypeID=Struct->MsgTypeID;
	if(MoreMsgToSend != NULL)   *MoreMsgToSend=Struct->MoreMsgToSend;
	if(ReplyPath != NULL)       *ReplyPath=Struct->ReplyPath;
	if(udhId != NULL)           *udhId=Struct->udhId;
	if(StatusReportID != NULL)  *StatusReportID=Struct->StatusReportID;
	if(OriginatingAddr != NULL) *OriginatingAddr=Struct->OriginatingAddr;
	if(pid != NULL)             *pid = Struct->pid;
	if(dcs != NULL)             *dcs = Struct->dcs;
	if(TimeStamp != NULL)       *TimeStamp=Struct->TimeStamp;
	if(UserDataLength != NULL)  *UserDataLength=Struct->UserDataLength;
	if(UserData != NULL)        *UserData=Struct->UserData;

	return sizeof(TSMSDeliver);
}

//--------------------------------------------------------
//
//   SMSDeliverReport_StructGetInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int SMSDeliverReport_StructGetInOut(TSMSDeliverReport *Struct
		,byte *MessageTypeID
		,byte *udhId
		,byte *FailureCause
		,TParameter *ParameterID
		,byte *pid
		,byte *dcs
		,byte *UserDataLength
		,TUserData *UserData)
{

	if(MessageTypeID!=NULL) *MessageTypeID=Struct->MessageTypeID;
	if(udhId!=NULL) *udhId=Struct->udhId;
	if(FailureCause!=NULL) *FailureCause=Struct->FailureCause;
	if(ParameterID!=NULL) *ParameterID=Struct->ParameterID;
	if(pid!=NULL) *pid=Struct->pid;
	if(dcs!=NULL) *dcs=Struct->dcs;
	if(UserDataLength!=NULL) *UserDataLength=Struct->UserDataLength;
	if(UserData!=NULL) *UserData=Struct->UserData;

	return sizeof(TSMSDeliverReport);
}


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
		,TUserData *UserData)
{

	if(MessageTypeID!=NULL) *MessageTypeID=Struct->MessageTypeID;
	if(RejectDuplicates!=NULL) *RejectDuplicates=Struct->RejectDuplicates;
	if(ValidityPeriodFormat!=NULL) *ValidityPeriodFormat=Struct->ValidityPeriodFormat;
	if(ReplyPath!=NULL) *ReplyPath=Struct->ReplyPath;
	if(udhId!=NULL) *udhId=Struct->udhId;
	if(StatusReportRequest!=NULL) *StatusReportRequest=Struct->StatusReportRequest;
	if(MessageReference!=NULL) *MessageReference=Struct->MessageReference;
	if(DestinationAddr!=NULL) *DestinationAddr=Struct->DestinationAddr;
	if(pid!=NULL) *pid=Struct->pid;
	if(dcs!=NULL) *dcs=Struct->dcs;
	if(ValidityRelative!=NULL) *ValidityRelative=Struct->ValidityRelative;
	if(ValidityPeriodAbsolute!=NULL) *ValidityPeriodAbsolute=Struct->ValidityPeriodAbsolute;
	if(ValidityPeriodEnhanced!=NULL) memcpy((char *)ValidityPeriodEnhanced,(char *)Struct->ValidityPeriodEnhanced,7*1);
	if(UserDataLength!=NULL) *UserDataLength=Struct->UserDataLength;
	if(UserData!=NULL) *UserData=Struct->UserData;

	return sizeof(TSMSSubmit);
}

//--------------------------------------------------------
//
//   SMSSubmitReport_StructGetInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int SMSSubmitReport_StructGetInOut(TSMSSubmitReport *Struct
		,byte *MessageTypeID
		,byte *udhId
		,byte *FailureCause
		,TParameter *ParameterID
		,TTimeStamp *TimeStamp
		,byte *pid
		,byte *dcs
		,byte *UserDataLength
		,TUserData *UserData)
{

	if(MessageTypeID!=NULL) *MessageTypeID=Struct->MessageTypeID;
	if(udhId!=NULL) *udhId=Struct->udhId;
	if(FailureCause!=NULL) *FailureCause=Struct->FailureCause;
	if(ParameterID!=NULL) *ParameterID=Struct->ParameterID;
	if(TimeStamp!=NULL) *TimeStamp=Struct->TimeStamp;
	if(pid!=NULL) *pid=Struct->pid;
	if(dcs!=NULL) *dcs=Struct->dcs;
	if(UserDataLength!=NULL) *UserDataLength=Struct->UserDataLength;
	if(UserData!=NULL) *UserData=Struct->UserData;

	return sizeof(TSMSSubmitReport);
}


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
		,TUserData *UserData)
{

	if(MessageTypeID!=NULL) *MessageTypeID=Struct->MessageTypeID;
	if(udhId!=NULL) *udhId=Struct->udhId;
	if(MoreMessagesToSend!=NULL) *MoreMessagesToSend=Struct->MoreMessagesToSend;
	if(StatusReportQualifier!=NULL) *StatusReportQualifier=Struct->StatusReportQualifier;
	if(MessageReference!=NULL) *MessageReference=Struct->MessageReference;
	if(RecipientAddr!=NULL) *RecipientAddr=Struct->RecipientAddr;
	if(TimeStamp!=NULL) *TimeStamp=Struct->TimeStamp;
	if(DischargeTime!=NULL) *DischargeTime=Struct->DischargeTime;
	if(Status!=NULL) *Status=Struct->Status;
	if(ParameterID!=NULL) *ParameterID=Struct->ParameterID;
	if(pid!=NULL) *pid=Struct->pid;
	if(dcs!=NULL) *dcs=Struct->dcs;
	if(UserDataLength!=NULL) *UserDataLength=Struct->UserDataLength;
	if(UserData!=NULL) *UserData=Struct->UserData;

	return sizeof(TSMSStatusReport);
}

//--------------------------------------------------------
//
//   SMSCommand_StructGetInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
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
		,byte CommandData[157])
{

	if(MessageTypeID!=NULL) *MessageTypeID=Struct->MessageTypeID;
	if(udhId!=NULL) *udhId=Struct->udhId;
	if(StatusReportRequest!=NULL) *StatusReportRequest=Struct->StatusReportRequest;
	if(MessageReference!=NULL) *MessageReference=Struct->MessageReference;
	if(pid != NULL) *pid=Struct->pid;
	if(CommandType!=NULL) *CommandType=Struct->CommandType;
	if(MessageNumber!=NULL) *MessageNumber=Struct->MessageNumber;
	if(DestinationAddr!=NULL) *DestinationAddr=Struct->DestinationAddr;
	if(CommandDataLength!=NULL) *CommandDataLength=Struct->CommandDataLength;
	if(CommandData!=NULL) memcpy((char *)CommandData,(char *)Struct->CommandData,Struct->CommandDataLength*1);

	return sizeof(TSMSCommand);
}


int Element_StructClearInOut(stEI *Struct)
{

	Struct->ID=0;
	Struct->Length=0;
	memset((char *)Struct->Data,0,140*1);

	return sizeof(stEI);
}


int UserDataHeader_StructClearInOut(stUDH *Struct)
{
	Struct->Length=0;
	Struct->eiCnt=0;
	{ int i; for(i=0;i<70;i++) Element_StructClearInOut(&Struct->ei[i]); }

	return sizeof(stUDH);
}


int UserData_StructClearInOut(TUserData *Struct)
{

	Struct->Length=0;
	UserDataHeader_StructClearInOut(&Struct->udh);
	Struct->DataLength=0;
	memset((char *)Struct->Data,0,140*1);

	return sizeof(TUserData);
}


int TimeStamp_StructClearInOut(TTimeStamp *Struct)
{

	Struct->Year=0;
	Struct->Month=0;
	Struct->Day=0;
	Struct->Hour=0;
	Struct->Min=0;
	Struct->Sec=0;
	Struct->TimeZone=0;

	return sizeof(TTimeStamp);
}

//--------------------------------------------------------
//
//   Address_StructClearInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int Address_StructClearInOut(TAddress *Struct)
{

	memset((char *)Struct->min,0,20*1);
	Struct->ton=0;
	Struct->npi=0;
	Struct->len=0;
    /*
	Struct->reserved=0;
    */

	return sizeof(TAddress);
}

//--------------------------------------------------------
//
//   Parameter_StructClearInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int Parameter_StructClearInOut(TParameter *Struct)
{

	Struct->isPIDPresent=0;
	Struct->isDCSPresent=0;
	Struct->isUDLPresent=0;

	return sizeof(TParameter);
}

//--------------------------------------------------------
//
//   SMSDeliver_StructClearInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int SMSDeliver_StructClearInOut(TSMSDeliver *Struct)
{

	Struct->MsgTypeID=0;
	Struct->MoreMsgToSend=0;
	Struct->ReplyPath=0;
	Struct->udhId=0;
	Struct->StatusReportID=0;
	Address_StructClearInOut(&Struct->OriginatingAddr);
	Struct->pid = 0x00;
	Struct->dcs = 0x00;
	TimeStamp_StructClearInOut(&Struct->TimeStamp);
	Struct->UserDataLength=0;
	UserData_StructClearInOut(&Struct->UserData);

	return sizeof(TSMSDeliver);
}

//--------------------------------------------------------
//
//   SMSDeliverReport_StructClearInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int SMSDeliverReport_StructClearInOut(TSMSDeliverReport *Struct)
{

	Struct->MessageTypeID=0;
	Struct->udhId=0;
	Struct->FailureCause=0;
	Parameter_StructClearInOut(&Struct->ParameterID);
	Struct->pid=0;
	Struct->dcs = 0x00;
	Struct->UserDataLength=0;
	UserData_StructClearInOut(&Struct->UserData);

	return sizeof(TSMSDeliverReport);
}

//--------------------------------------------------------
//
//   SMSSubmit_StructClearInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int SMSSubmit_StructClearInOut(TSMSSubmit *Struct)
{

	Struct->MessageTypeID=0;
	Struct->RejectDuplicates=0;
	Struct->ValidityPeriodFormat=0;
	Struct->ReplyPath=0;
	Struct->udhId=0;
	Struct->StatusReportRequest=0;
	Struct->MessageReference=0;
	Address_StructClearInOut(&Struct->DestinationAddr);
	Struct->pid=0;
	Struct->dcs = 0x00;
	Struct->ValidityRelative=0;
	TimeStamp_StructClearInOut(&Struct->ValidityPeriodAbsolute);
	memset((char *)Struct->ValidityPeriodEnhanced,0,7*1);
	Struct->UserDataLength=0;
	UserData_StructClearInOut(&Struct->UserData);

	return sizeof(TSMSSubmit);
}

//--------------------------------------------------------
//
//   SMSSubmitReport_StructClearInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int SMSSubmitReport_StructClearInOut(TSMSSubmitReport *Struct)
{

	Struct->MessageTypeID=0;
	Struct->udhId=0;
	Struct->FailureCause=0;
	Parameter_StructClearInOut(&Struct->ParameterID);
	TimeStamp_StructClearInOut(&Struct->TimeStamp);
	Struct->pid=0;
	Struct->dcs = 0x00;
	Struct->UserDataLength=0;
	UserData_StructClearInOut(&Struct->UserData);

	return sizeof(TSMSSubmitReport);
}

//--------------------------------------------------------
//
//   SMSStatusReport_StructClearInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int SMSStatusReport_StructClearInOut(TSMSStatusReport *Struct)
{

	Struct->MessageTypeID=0;
	Struct->udhId=0;
	Struct->MoreMessagesToSend=0;
	Struct->StatusReportQualifier=0;
	Struct->MessageReference=0;
	Address_StructClearInOut(&Struct->RecipientAddr);
	TimeStamp_StructClearInOut(&Struct->TimeStamp);
	TimeStamp_StructClearInOut(&Struct->DischargeTime);
	Struct->Status=0;
	Parameter_StructClearInOut(&Struct->ParameterID);
	Struct->pid=0;
	Struct->dcs = 0x00;
	Struct->UserDataLength=0;
	UserData_StructClearInOut(&Struct->UserData);

	return sizeof(TSMSStatusReport);
}

//--------------------------------------------------------
//
//   SMSCommand_StructClearInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int SMSCommand_StructClearInOut(TSMSCommand *Struct)
{

	Struct->MessageTypeID=0;
	Struct->udhId=0;
	Struct->StatusReportRequest=0;
	Struct->MessageReference=0;
	Struct->pid = 0;
	Struct->CommandType=0;
	Struct->MessageNumber=0;
	Address_StructClearInOut(&Struct->DestinationAddr);
	Struct->CommandDataLength=0;
	memset((char *)Struct->CommandData,0,157*1);

	return sizeof(TSMSCommand);
}


int Element_StructToScreenInOut(stEI *Struct)
{
	printf("------------------------------------------------------\n");
	printf("Element_StructToScreenInOut(....)\n");
	printf("------------------------------------------------------\n");

	printf("ID : %02X\n",  Struct->ID & 0xFF);
	printf("Length : %02X\n",  Struct->Length & 0xFF);
	{ int i; for(i=0;i<Struct->Length;i++) printf("Data[%d] : %02X\n", i, Struct->Data[i] & 0xFF);}

	printf("------------------------------------------------------\n");
	return sizeof(stEI);
}


int UserDataHeader_StructToScreenInOut(stUDH *Struct)
{
	printf("------------------------------------------------------\n");
	printf("UserDataHeader_StructToScreenInOut(....)\n");
	printf("------------------------------------------------------\n");

	printf("Length : %d\n",  Struct->Length & 0xFFFF);
	printf("ElementCount : %d\n",  Struct->eiCnt & 0xFFFF);
	{ int i; for(i=0;i<Struct->eiCnt;i++) Element_StructToScreenInOut(&Struct->ei[i]); }

	printf("------------------------------------------------------\n");
	return sizeof(stUDH);
}


int UserData_StructToScreenInOut(TUserData *Struct)
{
	printf("------------------------------------------------------\n");
	printf("UserData_StructToScreenInOut(....)\n");
	printf("------------------------------------------------------\n");

	printf("Length : %d\n",  Struct->Length & 0xFFFF);
	UserDataHeader_StructToScreenInOut(&Struct->udh);
	printf("DataLength : %d\n",  Struct->DataLength & 0xFFFF);
	{ int i; for(i=0;i<Struct->DataLength;i++) printf("Data[%d] : %02X\n", i, Struct->Data[i] & 0xFF);}

	printf("------------------------------------------------------\n");
	return sizeof(TUserData);
}

//--------------------------------------------------------
//
//   TimeStamp_StructToScreenInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int TimeStamp_StructToScreenInOut(TTimeStamp *Struct)
{
	printf("------------------------------------------------------\n");
	printf("TimeStamp_StructToScreenInOut(....)\n");
	printf("------------------------------------------------------\n");

	printf("Year : %d\n",  Struct->Year & 0xFFFF);
	printf("Month : %02X\n",  Struct->Month & 0xFF);
	printf("Day : %02X\n",  Struct->Day & 0xFF);
	printf("Hour : %02X\n",  Struct->Hour & 0xFF);
	printf("Min : %02X\n",  Struct->Min & 0xFF);
	printf("Sec : %02X\n",  Struct->Sec & 0xFF);
	printf("TimeZone : %02X\n",  Struct->TimeZone & 0xFF);

	printf("------------------------------------------------------\n");
	return sizeof(TTimeStamp);
}

//--------------------------------------------------------
//
//   Address_StructToScreenInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int Address_StructToScreenInOut(TAddress *Struct)
{
	printf("------------------------------------------------------\n");
	printf("Address_StructToScreenInOut(....)\n");
	printf("------------------------------------------------------\n");

	{ int i; for(i=0;i<Struct->len;i++) printf("min[%d] : %02X\n", i, Struct->min[i] & 0xFF);}
	printf("ton : %02X\n",  Struct->ton & 0xFF);
	printf("npi : %02X\n",  Struct->npi & 0xFF);
	printf("len : %02X\n",  Struct->len & 0xFF);
    /*
	printf("reserved : %02X\n",  Struct->reserved & 0xFF);
    */

	printf("------------------------------------------------------\n");
	return sizeof(TAddress);
}

//--------------------------------------------------------
//
//   Parameter_StructToScreenInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int Parameter_StructToScreenInOut(TParameter *Struct)
{
	printf("------------------------------------------------------\n");
	printf("Parameter_StructToScreenInOut(....)\n");
	printf("------------------------------------------------------\n");

	printf("isPIDPresent : %d\n",  Struct->isPIDPresent & 0xFFFF);
	printf("isDCSPresent : %d\n",  Struct->isDCSPresent & 0xFFFF);
	printf("isUDLPresent : %d\n",  Struct->isUDLPresent & 0xFFFF);

	printf("------------------------------------------------------\n");
	return sizeof(TParameter);
}

//--------------------------------------------------------
//
//   SMSDeliver_StructToScreenInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int SMSDeliver_StructToScreenInOut(TSMSDeliver *Struct)
{
	printf("------------------------------------------------------\n");
	printf("SMSDeliver_StructToScreenInOut(....)\n");
	printf("------------------------------------------------------\n");

	printf("MsgTypeID : %02X\n",  Struct->MsgTypeID & 0xFF);
	printf("MoreMsgToSend : %02X\n",  Struct->MoreMsgToSend & 0xFF);
	printf("ReplyPath : %02X\n",  Struct->ReplyPath & 0xFF);
	printf("UDH Id : %02X\n",  Struct->udhId & 0xFF);
	printf("StatusReportID : %02X\n",  Struct->StatusReportID & 0xFF);
	Address_StructToScreenInOut(&Struct->OriginatingAddr);
	printf("pid        : %02X\n",  Struct->pid);
	printf("dcs        : %02X\n",  Struct->dcs);
	TimeStamp_StructToScreenInOut(&Struct->TimeStamp);
	printf("UserDataLength : %02X\n",  Struct->UserDataLength & 0xFF);
	UserData_StructToScreenInOut(&Struct->UserData);

	printf("------------------------------------------------------\n");
	return sizeof(TSMSDeliver);
}

//--------------------------------------------------------
//
//   SMSDeliverReport_StructToScreenInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int SMSDeliverReport_StructToScreenInOut(TSMSDeliverReport *Struct)
{
	printf("------------------------------------------------------\n");
	printf("SMSDeliverReport_StructToScreenInOut(....)\n");
	printf("------------------------------------------------------\n");

	printf("MessageTypeID : %02X\n",  Struct->MessageTypeID & 0xFF);
	printf("UDH Id : %02X\n",  Struct->udhId & 0xFF);
	printf("FailureCause : %02X\n",  Struct->FailureCause & 0xFF);
	Parameter_StructToScreenInOut(&Struct->ParameterID);
	printf("pid        : %02X\n",  Struct->pid);
	printf("dcs        : %02X\n",  Struct->dcs);
	printf("UserDataLength : %02X\n",  Struct->UserDataLength & 0xFF);
	UserData_StructToScreenInOut(&Struct->UserData);

	printf("------------------------------------------------------\n");
	return sizeof(TSMSDeliverReport);
}

//--------------------------------------------------------
//
//   SMSSubmit_StructToScreenInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int SMSSubmit_StructToScreenInOut(TSMSSubmit *Struct)
{
	printf("------------------------------------------------------\n");
	printf("SMSSubmit_StructToScreenInOut(....)\n");
	printf("------------------------------------------------------\n");

	printf("MessageTypeID : %02X\n",  Struct->MessageTypeID & 0xFF);
	printf("RejectDuplicates : %02X\n",  Struct->RejectDuplicates & 0xFF);
	printf("ValidityPeriodFormat : %02X\n",  Struct->ValidityPeriodFormat & 0xFF);
	printf("ReplyPath : %02X\n",  Struct->ReplyPath & 0xFF);
	printf("UDH Id : %02X\n",  Struct->udhId & 0xFF);
	printf("StatusReportRequest : %02X\n",  Struct->StatusReportRequest & 0xFF);
	printf("MessageReference : %02X\n",  Struct->MessageReference & 0xFF);
	Address_StructToScreenInOut(&Struct->DestinationAddr);
	printf("pid        : %02X\n",  Struct->pid);
	printf("dcs        : %02X\n",  Struct->dcs);
	printf("ValidityRelative : %02X\n",  Struct->ValidityRelative & 0xFF);
	TimeStamp_StructToScreenInOut(&Struct->ValidityPeriodAbsolute);
	{ int i; for(i=0;i<7;i++) printf("ValidityPeriodEnhanced[%d] : %02X\n", i, Struct->ValidityPeriodEnhanced[i] & 0xFF);}
	printf("UserDataLength : %02X\n",  Struct->UserDataLength & 0xFF);
	UserData_StructToScreenInOut(&Struct->UserData);

	printf("------------------------------------------------------\n");
	return sizeof(TSMSSubmit);
}

//--------------------------------------------------------
//
//   SMSSubmitReport_StructToScreenInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int SMSSubmitReport_StructToScreenInOut(TSMSSubmitReport *Struct)
{
	printf("------------------------------------------------------\n");
	printf("SMSSubmitReport_StructToScreenInOut(....)\n");
	printf("------------------------------------------------------\n");

	printf("MessageTypeID : %02X\n",  Struct->MessageTypeID & 0xFF);
	printf("UDH Id : %02X\n",  Struct->udhId & 0xFF);
	printf("FailureCause : %02X\n",  Struct->FailureCause & 0xFF);
	Parameter_StructToScreenInOut(&Struct->ParameterID);
	TimeStamp_StructToScreenInOut(&Struct->TimeStamp);
	printf("pid        : %02X\n",  Struct->pid);
	printf("dcs        : %02X\n",  Struct->dcs);
	printf("UserDataLength : %02X\n",  Struct->UserDataLength & 0xFF);
	UserData_StructToScreenInOut(&Struct->UserData);

	printf("------------------------------------------------------\n");
	return sizeof(TSMSSubmitReport);
}

//--------------------------------------------------------
//
//   SMSStatusReport_StructToScreenInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int SMSStatusReport_StructToScreenInOut(TSMSStatusReport *Struct)
{
	printf("------------------------------------------------------\n");
	printf("SMSStatusReport_StructToScreenInOut(....)\n");
	printf("------------------------------------------------------\n");

	printf("MessageTypeID : %02X\n",  Struct->MessageTypeID & 0xFF);
	printf("UDH Id : %02X\n",  Struct->udhId & 0xFF);
	printf("MoreMessagesToSend : %02X\n",  Struct->MoreMessagesToSend & 0xFF);
	printf("StatusReportQualifier : %02X\n",  Struct->StatusReportQualifier & 0xFF);
	printf("MessageReference : %02X\n",  Struct->MessageReference & 0xFF);
	Address_StructToScreenInOut(&Struct->RecipientAddr);
	TimeStamp_StructToScreenInOut(&Struct->TimeStamp);
	TimeStamp_StructToScreenInOut(&Struct->DischargeTime);
	printf("Status : %02X\n",  Struct->Status & 0xFF);
	Parameter_StructToScreenInOut(&Struct->ParameterID);
	printf("pid        : %02X\n",  Struct->pid);
	printf("dcs        : %02X\n",  Struct->dcs);
	printf("UserDataLength : %02X\n",  Struct->UserDataLength & 0xFF);
	UserData_StructToScreenInOut(&Struct->UserData);

	printf("------------------------------------------------------\n");
	return sizeof(TSMSStatusReport);
}

//--------------------------------------------------------
//
//   SMSCommand_StructToScreenInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int SMSCommand_StructToScreenInOut(TSMSCommand *Struct)
{
	printf("------------------------------------------------------\n");
	printf("SMSCommand_StructToScreenInOut(....)\n");
	printf("------------------------------------------------------\n");

	printf("MessageTypeID : %02X\n",  Struct->MessageTypeID & 0xFF);
	printf("UDH Id : %02X\n",  Struct->udhId & 0xFF);
	printf("StatusReportRequest : %02X\n",  Struct->StatusReportRequest & 0xFF);
	printf("MessageReference : %02X\n",  Struct->MessageReference & 0xFF);
	printf("pid         : %02X\n",  Struct->pid);
	printf("CommandType : %02X\n",  Struct->CommandType & 0xFF);
	printf("MessageNumber : %02X\n",  Struct->MessageNumber & 0xFF);
	Address_StructToScreenInOut(&Struct->DestinationAddr);
	printf("CommandDataLength : %02X\n",  Struct->CommandDataLength & 0xFF);
	{ int i; for(i=0;i<Struct->CommandDataLength;i++) printf("CommandData[%d] : %02X\n", i, Struct->CommandData[i] & 0xFF);}

	printf("------------------------------------------------------\n");
	return sizeof(TSMSCommand);
}

