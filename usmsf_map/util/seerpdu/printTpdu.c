
#include <iXtypes.h>
#include <TPDU/TPDU.h>


void printTpdu_userDataHeader(stUDH *header)
{
    int             i, j;
    stEI           *pei;

    printf("\tUDH Length              :[%d]\n", header->Length);
    printf("\tUDH EI Cnt              :[%d]\n", header->eiCnt);

    for(i = 0, pei = header->ei; i < header->eiCnt; i++, pei++)
    {
        printf("\tUDH EI                  :tag[0x%02X] len[0x%02X] value[", 
            pei->ID, pei->Length);

        for(j = 0; j < pei->Length; j++)
            printf("%02X ", pei->Data[j]);
            
        printf("]\n");
    }
}


void printTpdu_userData(TUserData *data, byte headerIndi)
{
    int i;
    int temp;

    if(headerIndi==1)
    {
        printf("\tUDH Len                 :[%d]\n", data->Length);
        printTpdu_userDataHeader(&data->udh);
    }

    printf("\tUserDataDataLength      :[%d]\n", data->DataLength);
    if(data->DataLength >=5 && data->Data[data->DataLength-5]=='$')
    {
        memcpy((void*)&temp, (void*)&(data->Data[data->DataLength-4]), 4);
        printf("\tsmscMsgId               :[%d]\n", temp);
        data->DataLength -= 5;
    }
    printHexaString2(data->Data, data->DataLength);
    printf("\n");
    
}


void printTpdu_deliver(TSMSDeliver *tpdu)
{
	char	encode;

	encode = GetEncodeFromDcs(tpdu->dcs);
	
    printf("\t[DELIVER]\n");
    printf("\tMessageTypeIndicator    :[%d]\n", tpdu->MsgTypeID);
    printf("\tMoreMsgToSend           :[%d]\n", tpdu->MoreMsgToSend);
    printf("\tReplyPath               :[%d]\n", tpdu->ReplyPath);
    printf("\tUDH Indicator           :[%d]\n", tpdu->udhId);
    printf("\tStatusReportIndicator   :[%d]\n", tpdu->StatusReportID);
    printf("\tOA[len]                 :[%d]\n", tpdu->OriginatingAddr.len);
    printf("\tOA[ton]                 :[%d]\n", tpdu->OriginatingAddr.ton);
    printf("\tOA[npi]                 :[%d]\n", tpdu->OriginatingAddr.npi);
    printf("\tOA[address]             :[%s]\n", tpdu->OriginatingAddr.min);
    printf("\tProtocolIdentifier      :[0x%02X]\n", tpdu->pid);
    printf("\tDataCodingScheme        :[0x%02X][%s]\n", tpdu->dcs,
		encode == ENCODE_7BIT_GSM ? "GSM7BIT":(encode == ENCODE_8BIT ? "GSM8BIT":"UCS2"));
    printf("\tTimeStamp               :Y[%d] M[%d] D[%d]\n \
                                H[%d] M[%d] S[%d] zone[%d]\n", 
                                        tpdu->TimeStamp.Year,
                                        tpdu->TimeStamp.Month,
                                        tpdu->TimeStamp.Day,
                                        tpdu->TimeStamp.Hour,
                                        tpdu->TimeStamp.Min,
                                        tpdu->TimeStamp.Sec,
                                        (char)tpdu->TimeStamp.TimeZone);

    printf("\tUserDataLength          :[%d]\n", tpdu->UserDataLength);
    printTpdu_userData(&tpdu->UserData, tpdu->udhId);
    printf("\n");
}


void printTpdu_deliverReport(TSMSDeliverReport *tpdu)
{
	char	encode;

	encode = GetEncodeFromDcs(tpdu->dcs);

    printf("\t[DELIVERREPORT]\n");
    
    printf("\tMessageTypeIndicator    :[%d]\n", tpdu->MessageTypeID);
    printf("\tUDH Indicator           :[%d]\n", tpdu->udhId);
    printf("\tFailureCause            :[%d]\n", tpdu->FailureCause);
    printf("\tParameterIndicator      :PID[%d] DCS[%d] UDL[%d]\n", 
                                        tpdu->ParameterID.isPIDPresent,
                                        tpdu->ParameterID.isDCSPresent,
                                        tpdu->ParameterID.isUDLPresent);
    if(tpdu->ParameterID.isPIDPresent)
        printf("\tProtocolIdentifier      :[0x%02X]\n", tpdu->pid);
    if(tpdu->ParameterID.isDCSPresent)
        printf("\tDataCodingScheme        :[0x%02X][%s]\n", tpdu->dcs,
		encode == ENCODE_7BIT_GSM ? "GSM7BIT":(encode == ENCODE_8BIT ? "GSM8BIT":"UCS2"));

    if(tpdu->ParameterID.isUDLPresent)
    {
        printf("\tUserDataLength          :[%d]\n", tpdu->UserDataLength);
        printTpdu_userData(&tpdu->UserData, tpdu->udhId);
    }
    printf("\n");
}


void printTpdu_submit(TSMSSubmit *tpdu)
{
    int		i;
	char	encode;

	encode = GetEncodeFromDcs(tpdu->dcs);

    printf("\t[SUBMIT]\n");

    printf("\tMessageTypeIndicator    :[%d]\n", tpdu->MessageTypeID);
    printf("\tRejectDuplicates        :[%d]\n", tpdu->RejectDuplicates);
    printf("\tValidityPeriodFormat    :");
    switch(tpdu->ValidityPeriodFormat)
    {
        case TPDU_VPF_NOT_PRESENT :
            printf("[VPF_NOT_PRESENT]\n");
            break;
        case TPDU_VPF_ENHANCED :
            printf("[VPF_ENHANCED]\n");
            for(i=0; i<7; i++)
                printf(" %02X", tpdu->ValidityPeriodEnhanced[i]);
            printf("\n");
            break;
        case TPDU_VPF_RELATIVE :
            printf("[VPF_RELATIVE] : ");
            printf("[%02X]\n", tpdu->ValidityRelative);
            break;
        case TPDU_VPF_ABSOLUTE :
            printf("[VPF_ABSOLUTE]\n");
            printf(" \
                                Y[%d] M[%d] D[%d]\n \
                                H[%d] M[%d] S[%d] zone[%d]\n",
                        tpdu->ValidityPeriodAbsolute.Year,
                        tpdu->ValidityPeriodAbsolute.Month,
                        tpdu->ValidityPeriodAbsolute.Day,
                        tpdu->ValidityPeriodAbsolute.Hour,
                        tpdu->ValidityPeriodAbsolute.Min,
                        tpdu->ValidityPeriodAbsolute.Sec,
                        (char)tpdu->ValidityPeriodAbsolute.TimeZone);
            break;

    }


    printf("\tReplyPath               :[%d]\n", tpdu->ReplyPath);
    printf("\tUDH Indicator           :[%d]\n", tpdu->udhId);
    printf("\tStatusReportRequest     :[%d]\n", tpdu->StatusReportRequest);
    printf("\tMessageReference        :[%d]\n", tpdu->MessageReference);
    printf("\tDA[len]                 :[%d]\n", tpdu->DestinationAddr.len);
    printf("\tDA[ton]                 :[%d]\n", tpdu->DestinationAddr.ton);
    printf("\tDA[npi]                 :[%d]\n", tpdu->DestinationAddr.npi);
    printf("\tDA[address]             :[%s]\n", tpdu->DestinationAddr.min);
    printf("\tProtocolIdentifier      :[0x%02X]\n", tpdu->pid);
    printf("\tDataCodingScheme        :[0x%02X][%s]\n", tpdu->dcs, 
		encode == ENCODE_7BIT_GSM ? "GSM7BIT":(encode == ENCODE_8BIT ? "GSM8BIT":"UCS2"));
    printf("\tUserDataLength          :[%d]\n", tpdu->UserDataLength);
    printTpdu_userData(&tpdu->UserData, tpdu->udhId); 
    printf("\n");
}


void printTpdu_submitReport(TSMSSubmitReport *tpdu)
{
	char	encode;

	encode = GetEncodeFromDcs(tpdu->dcs);

    printf("\t[SUBMITREPORT]\n");

    printf("\tMessageTypeIndicator    :[%d]\n", tpdu->MessageTypeID);
    printf("\tUDH Indicator           :[%d]\n", tpdu->udhId);
    printf("\tFailureCause            :[%d]\n", tpdu->FailureCause);
    printf("\tParameterIndicator      :PID[%d] DCS[%d] UDL[%d]\n", 
                                        tpdu->ParameterID.isPIDPresent,
                                        tpdu->ParameterID.isDCSPresent,
                                        tpdu->ParameterID.isUDLPresent);
    printf("\tTimeStamp               :Y[%d] M[%d] D[%d]\n \
                                H[%d] M[%d] S[%d] zone[%d]\n", 
                                        tpdu->TimeStamp.Year,
                                        tpdu->TimeStamp.Month,
                                        tpdu->TimeStamp.Day,
                                        tpdu->TimeStamp.Hour,
                                        tpdu->TimeStamp.Min,
                                        tpdu->TimeStamp.Sec,
                                        (char)tpdu->TimeStamp.TimeZone);

    if(tpdu->ParameterID.isPIDPresent)
        printf("\tProtocolIdentifier      :[0x%02X]\n", tpdu->pid);
    if(tpdu->ParameterID.isDCSPresent)
        printf("\tDataCodingScheme        :[0x%02X][%s]\n", tpdu->dcs,
		encode == ENCODE_7BIT_GSM ? "GSM7BIT":(encode == ENCODE_8BIT ? "GSM8BIT":"UCS2"));

    if(tpdu->ParameterID.isUDLPresent)
    {
        printf("\tUserDataLength          :[%d]\n", tpdu->UserDataLength);
        printTpdu_userData(&tpdu->UserData, tpdu->udhId);
    }

    printf("\n");
}


void printTpdu_statusReport(TSMSStatusReport *tpdu)
{
	char 	encode;

	encode = GetEncodeFromDcs(tpdu->dcs);
	
    printf("\t[STATUSREPORT]\n");

    printf("\tMessageTypeIndicator    :[%d]\n", tpdu->MessageTypeID);
    printf("\tUDH Indicator           :[%d]\n", tpdu->udhId);
    printf("\tMoreMsgsToSend          :[%d]\n", tpdu->MoreMessagesToSend);
    printf("\tStatusReportQualifier   :[%d]\n", tpdu->StatusReportQualifier);
    printf("\tMessageReference        :[%d]\n", tpdu->MessageReference);
    printf("\tRecipientAddr[len]      :[%d]\n", tpdu->RecipientAddr.len);
    printf("\tRecipientAddr[ton]      :[%d]\n", tpdu->RecipientAddr.ton);
    printf("\tRecipientAddr[npi]      :[%d]\n", tpdu->RecipientAddr.npi);
    printf("\tRecipientAddr[address]  :[%s]\n", tpdu->RecipientAddr.min);
    printf("\tTimeStamp               :Y[%d] M[%d] D[%d]\n \
                                H[%d] M[%d] S[%d] zone[%d]\n", 
                                        tpdu->TimeStamp.Year,
                                        tpdu->TimeStamp.Month,
                                        tpdu->TimeStamp.Day,
                                        tpdu->TimeStamp.Hour,
                                        tpdu->TimeStamp.Min,
                                        tpdu->TimeStamp.Sec,
                                        (char)tpdu->TimeStamp.TimeZone);

    printf("\tDischargeTime           :Y[%d] M[%d] D[%d]\n \
                                H[%d] M[%d] S[%d] zone[%d]\n", 
                                        tpdu->DischargeTime.Year,
                                        tpdu->DischargeTime.Month,
                                        tpdu->DischargeTime.Day,
                                        tpdu->DischargeTime.Hour,
                                        tpdu->DischargeTime.Min,
                                        tpdu->DischargeTime.Sec,
                                        (char)tpdu->DischargeTime.TimeZone);
	printf("\tStatus                  :[%d]\n", tpdu->Status);

    printf("\tParameterIndicator      :PID[%d] DCS[%d] UDL[%d]\n", 
                                        tpdu->ParameterID.isPIDPresent,
                                        tpdu->ParameterID.isDCSPresent,
                                        tpdu->ParameterID.isUDLPresent);

    if(tpdu->ParameterID.isPIDPresent)
        printf("\tProtocolIdentifier      :[0x%02X]\n", tpdu->pid);
    if(tpdu->ParameterID.isDCSPresent)
        printf("\tDataCodingScheme        :[0x%02X][%s]\n", tpdu->dcs,
			encode == ENCODE_7BIT_GSM ? "GSM7BIT":(encode == ENCODE_8BIT ? "GSM8BIT":"UCS2"));

    if(tpdu->ParameterID.isUDLPresent)
    {
        printf("\tUserDataLength          :[%d]\n", tpdu->UserDataLength);
        printTpdu_userData(&tpdu->UserData, tpdu->udhId);
    }
    printf("\n");

    
}


void printTpdu_command(TSMSCommand *tpdu)
{
    printf("\t[COMMAND]\n");

    printf("\tMessageTypeIndicator    :[%d]\n", tpdu->MessageTypeID);
    printf("\tUDH Indicator           :[%d]\n", tpdu->udhId);
    printf("\tStatusReportRequest     :[%d]\n", tpdu->StatusReportRequest);
    printf("\tMessageReference        :[%d]\n", tpdu->MessageReference);
    printf("\tProtocolIdentifier      :[0x%02X]\n", tpdu->pid);
    printf("\tCommandType             :[%d]\n", tpdu->CommandType);
    printf("\tCommandType             :[%s]\n", 
                            tpdu->CommandType == 0x00 ? "Enquiry" :
                            tpdu->CommandType == 0x01 ? "Cancel" :
                            tpdu->CommandType == 0x02 ? "Delete" :
                            tpdu->CommandType == 0x03 ? "Enable" : "UNKNOWN");
    printf("\tMessgeNumber            :[%d]\n", tpdu->MessageNumber);
    printf("\tDA[len]                 :[%d]\n", tpdu->DestinationAddr.len);
    printf("\tDA[ton]                 :[%d]\n", tpdu->DestinationAddr.ton);
    printf("\tDA[npi]                 :[%d]\n", tpdu->DestinationAddr.npi);
    printf("\tDA[address]             :[%s]\n", tpdu->DestinationAddr.min);

    printf("\tCommandDataLength       :[%d]\n", tpdu->CommandDataLength);
    printHexaString2(&tpdu->CommandData, tpdu->CommandDataLength); 
    printf("\n");
}


void printTpdu(_TPDU *tpdu)
{
    switch(tpdu->MessageType)
    {
        case TPDU_SMS_DELIVER:
            printTpdu_deliver(&tpdu->Union.SMSDeliver);
            break;

        case TPDU_SMS_DELIVER_REPORT:
            printTpdu_deliverReport(&tpdu->Union.SMSDeliverReport);
            break;

        case TPDU_SMS_SUBMIT:
            printTpdu_submit(&tpdu->Union.SMSSubmit);
            break;
                                                            
        case TPDU_SMS_SUBMIT_REPORT:
            printTpdu_submitReport(&tpdu->Union.SMSSubmitReport);
            break;

        case TPDU_SMS_STATUS_REPORT:
            printTpdu_statusReport(&tpdu->Union.SMSStatusReport);
            break;

        case TPDU_SMS_COMMAND:
            printTpdu_command(&tpdu->Union.SMSCommand);
            break;
                                                            
        default:
            printf("UNKNOWN TPDU\n");
            break;
    }
}

