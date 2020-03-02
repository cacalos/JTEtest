
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <TPDU/TPDU.h>
#include <iXtypes.h>

int printHexaStringTpdu(char *data, int dataLen, char *str)
{
    int i, j, len;
    const int cnt = 10;
    unsigned int c[10];
	char *pos;
    char buf[100], *ptr;

	pos = str;
    for(i=0, ptr=buf; i<dataLen; i++)
    {
        sprintf(ptr, " %02X", (unsigned char)data[i]);
        ptr += strlen(ptr);
		
        if(i%cnt == (cnt-1))
        {
            sprintf(ptr, "%2s", " ");
            ptr +=2;
#if 0
            for(j=0; j<cnt; j++)
            {
                if(iscntrl(data[i-(cnt-1)+j]))
                    *(ptr+j) = '.';
                else
                    *(ptr+j) = data[i-(cnt-1)+j];
            }
            *(ptr+j) = '\0';
#endif //modified by seo(19.01.19)

            len = sprintf(pos, "%s\n", buf);
			pos += len;
            ptr = buf;
        }
    }
    
	if(i%cnt != 0)
    {
        int mod = i%cnt;
        for(j=0; j<cnt-mod; j++)
        {
            sprintf(ptr, " %2s", " ");
            ptr += strlen(ptr);
        }
        sprintf(ptr, "%2s", " ");
        ptr +=2;
#if 0
        for(j=0; j<mod; j++)
        {
            if(iscntrl(data[i-mod+j]))
                *(ptr+j) = '.';
            else
                *(ptr+j) = data[i-mod+j];
        }
        *(ptr+j) = '\0';

#endif // modified by seo(19.01.29)
        len = sprintf(pos, "%s\n", buf);
		pos += len;
    }
	return (pos - str);
}

int printTpdu_userDataHeader(stUDH *header, char *userHeader)
{
    int             i, j, len;
	char           *pos;
    stEI           *pei;

	pos = userHeader;
    len = sprintf(pos, "UDH Length              :[%d]\n", header->Length);
	pos += len;
    len = sprintf(pos, "UDH EI Cnt              :[%d]\n", header->eiCnt);
	pos += len;

    for(i = 0, pei = header->ei; i < header->eiCnt; i++, pei++)
    {
        len = sprintf(pos, "UDH EI                  :tag[0x%02X] len[0x%02X] value[", 
            pei->ID, pei->Length);
		pos += len;

        for(j = 0; j < pei->Length; j++)
		{
            len = sprintf(pos, "%02X ", pei->Data[j]);
			pos += len;
		}
            
        len = sprintf(pos, "]\n");
		pos += len;
    }

	return (pos - userHeader);
}


int printTpdu_userData(TUserData *data, byte headerIndi, char *userData)
{
    int             i, len;
    int             temp;
	char           *pos;

	len = 0;
	pos = userData;

    if(headerIndi==1)
    {
        len = sprintf(pos, "UDH Len                 :[%d]\n", data->Length);
		pos += len;
        len = printTpdu_userDataHeader(&data->udh, pos);
		pos += len;
    }

    len = sprintf(pos, "UserDataDataLength      :[%d]\n", data->DataLength);
	pos += len;
    if(data->DataLength >=5 && data->Data[data->DataLength-5]=='$')
    {
        memcpy((void*)&temp, (void*)&(data->Data[data->DataLength-4]), 4);
        len = sprintf(pos, "smscMsgId               :[%d]\n", temp);
        data->DataLength -= 5;
		pos += len;
    }
    len = printHexaStringTpdu((char *)data->Data, data->DataLength, pos);
	pos += len;

	return (pos - userData);
}


int printTpdu_deliver(TSMSDeliver *tpdu, char *str)
{
	int              len, tLen;
	char             *pos;
	char             userData[1024];
	char			 encode;
	pos = str;

	encode = GetEncodeFromDcs(tpdu->dcs);
	
    len = printTpdu_userData(&tpdu->UserData, tpdu->udhId, userData);
    tLen = sprintf(pos, "[DELIVER]\n\
MessageTypeIndicator    : %d\n\
MoreMsgToSend           : %d\n\
ReplyPath               : %d\n\
UDH Indicator           : %d\n\
StatusReportIndicator   : %d\n\
OA[len]                 : %d\n\
OA[ton]                 : %d\n\
OA[npi]                 : %d\n\
OA[address]             : %s\n\
ProtocolIdentifier      : 0x%02X\n\
DataCodingScheme        : 0x%02X [%s]\n\
TimeStamp               : %04d/%02d/%02d %02d:%02d:%02d  zone=%d\n\
UserDataLength          : %d\n%s", 
	tpdu->MsgTypeID,
	tpdu->MoreMsgToSend,
	tpdu->ReplyPath,
	tpdu->udhId,
	tpdu->StatusReportID,
	tpdu->OriginatingAddr.len,
	tpdu->OriginatingAddr.ton,
	tpdu->OriginatingAddr.npi,
	tpdu->OriginatingAddr.min,
	tpdu->pid,
	tpdu->dcs,
	encode == ENCODE_7BIT_GSM ? "GSM7BIT":(encode == ENCODE_8BIT ? "GSM8BIT":" "),
	//ENCODE_STR(encode),
	tpdu->TimeStamp.Year+2000,
	tpdu->TimeStamp.Month,
	tpdu->TimeStamp.Day,
	tpdu->TimeStamp.Hour,
	tpdu->TimeStamp.Min,
	tpdu->TimeStamp.Sec,
	(char)tpdu->TimeStamp.TimeZone,
	tpdu->UserDataLength,userData);

	return (len + tLen);
}

#if 0
void printTpdu_deliverReport(TSMSDeliverReport *tpdu)
{
    printf("[DELIVERREPORT]\n");
    
    printf("MessageTypeIndicator    :[%d]\n", tpdu->MessageTypeID);
    printf("UDH Indicator           :[%d]\n", tpdu->udhId);
    printf("FailureCause            :[%d]\n", tpdu->FailureCause);
    printf("ParameterIndicator      :PID[%d] DCS[%d] UDL[%d]\n", 
                                        tpdu->ParameterID.isPIDPresent,
                                        tpdu->ParameterID.isDCSPresent,
                                        tpdu->ParameterID.isUDLPresent);
    if(tpdu->ParameterID.isPIDPresent)
        printf("ProtocolIdentifier      :[0x%02X]\n", tpdu->pid);
    if(tpdu->ParameterID.isDCSPresent)
        printf("DataCodingScheme        :[0x%02X]\n", tpdu->dcs);

    if(tpdu->ParameterID.isUDLPresent)
    {
        printf("UserDataLength          :[%d]\n", tpdu->UserDataLength);
        printTpdu_userData(&tpdu->UserData, tpdu->udhId);
    }
    printf("\n");
}
#endif

int printTpdu_submit(TSMSSubmit *tpdu, char *str)
{
	int              i, len, tLen;
	char             *pos;
	char             userData[1024];
	char			 encode;

	pos = str;
    tLen = printTpdu_userData(&tpdu->UserData, tpdu->udhId, userData); 

	encode = GetEncodeFromDcs(tpdu->dcs);

    len = sprintf(pos, "[SUBMIT]\n\
MessageTypeIndicator    : %d\n\
RejectDuplicates        : %d\n\
ValidityPeriodFormat    :", tpdu->MessageTypeID, tpdu->RejectDuplicates);
	pos += len;

    switch(tpdu->ValidityPeriodFormat)
    {
        case TPDU_VPF_NOT_PRESENT :
            len = sprintf(pos, "[VPF_NOT_PRESENT]\n");
			pos += len;
            break;
        case TPDU_VPF_ENHANCED :
            len = sprintf(pos, "[VPF_ENHANCED]\n");
			pos += len;
            for(i=0; i<7; i++)
			{
                len = sprintf(pos, " %02X", tpdu->ValidityPeriodEnhanced[i]);
				pos += len;
			}
			sprintf(pos, "\n");
			pos += len;
            break;
        case TPDU_VPF_RELATIVE :
            len = sprintf(pos, "[VPF_RELATIVE] : \
[%02X]\n", tpdu->ValidityRelative);
			pos += len;
            break;
        case TPDU_VPF_ABSOLUTE :
            len = sprintf(pos, "[VPF_ABSOLUTE]\n\
                          Y[%d] M[%d] D[%d]\n\
                          H[%d] M[%d] S[%d] zone[%d]\n",
                        tpdu->ValidityPeriodAbsolute.Year,
                        tpdu->ValidityPeriodAbsolute.Month,
                        tpdu->ValidityPeriodAbsolute.Day,
                        tpdu->ValidityPeriodAbsolute.Hour,
                        tpdu->ValidityPeriodAbsolute.Min,
                        tpdu->ValidityPeriodAbsolute.Sec,
                        (char)tpdu->ValidityPeriodAbsolute.TimeZone);
			pos += len;
            break;

    }

    len = sprintf(pos, "ReplyPath               : %d\n\
UDH Indicator           : %d\n\
StatusReportRequest     : %d\n\
MessageReference        : %d\n\
DA[len]                 : %d\n\
DA[ton]                 : %d\n\
DA[npi]                 : %d\n\
DA[address]             : %s\n\
ProtocolIdentifier      : 0x%02X\n\
DataCodingScheme        : 0x%02X [%s]\n\
UserDataLength          : %d\n%s", 
	tpdu->ReplyPath,
	tpdu->udhId,
	tpdu->StatusReportRequest,
	tpdu->MessageReference,
	tpdu->DestinationAddr.len,
	tpdu->DestinationAddr.ton,
	tpdu->DestinationAddr.npi,
	tpdu->DestinationAddr.min,
	tpdu->pid,
	tpdu->dcs,
	encode == ENCODE_7BIT_GSM ? "GSM7BIT":(encode == ENCODE_8BIT ? "GSM8BIT":"UCS2"),
	//ENCODE_STR(encode),
	tpdu->UserDataLength,userData);

	return (len + tLen);
}


#if 0
void printTpdu_submitReport(TSMSSubmitReport *tpdu)
{
    printf("[SUBMITREPORT]\n");

    printf("MessageTypeIndicator    :[%d]\n", tpdu->MessageTypeID);
    printf("UDH Indicator           :[%d]\n", tpdu->udhId);
    printf("FailureCause            :[%d]\n", tpdu->FailureCause);
    printf("ParameterIndicator      :PID[%d] DCS[%d] UDL[%d]\n", 
                                        tpdu->ParameterID.isPIDPresent,
                                        tpdu->ParameterID.isDCSPresent,
                                        tpdu->ParameterID.isUDLPresent);
    printf("TimeStamp               :Y[%d] M[%d] D[%d]\n \
                                H[%d] M[%d] S[%d] zone[%d]\n", 
                                        tpdu->TimeStamp.Year,
                                        tpdu->TimeStamp.Month,
                                        tpdu->TimeStamp.Day,
                                        tpdu->TimeStamp.Hour,
                                        tpdu->TimeStamp.Min,
                                        tpdu->TimeStamp.Sec,
                                        (char)tpdu->TimeStamp.TimeZone);

    if(tpdu->ParameterID.isPIDPresent)
        printf("ProtocolIdentifier      :[0x%02X]\n", tpdu->pid);
    if(tpdu->ParameterID.isDCSPresent)
        printf("DataCodingScheme        :[0x%02X]\n", tpdu->dcs);

    if(tpdu->ParameterID.isUDLPresent)
    {
        printf("UserDataLength          :[%d]\n", tpdu->UserDataLength);
        printTpdu_userData(&tpdu->UserData, tpdu->udhId);
    }

    printf("\n");
}
#endif


int printTpdu_statusReport(TSMSStatusReport *tpdu, char *str)
{
	int				tLen;
	char			*pos;
	char			encode;

	pos = str;

    tLen = sprintf(pos, "[STATUS REPORT]\n\
MessageTypeIndicator    : %d\n\
UDH Indicator           : %d\n\
MoreMsgsToSend          : %d\n\
StatusReportQualifier   : %d\n\
MessageReference        : %d\n\
RecipientAddr[len]      : %d\n\
RecipientAddr[ton]      : %d\n\
RecipientAddr[npi]      : %d\n\
RecipientAddr[address]  : %s\n\
TimeStamp               : %04d/%02d/%02d %02d:%02d:%02d  zone=%d\n\
DischargeTime           : %04d/%02d/%02d %02d:%02d:%02d  zone=%d\n\
Status                  : 0x%X(%s)\n\
ParameterIndicator      : PID[%d] DCS[%d] UDL[%d]",
	 tpdu->MessageTypeID,
	 tpdu->udhId,
	 tpdu->MoreMessagesToSend,
	 tpdu->StatusReportQualifier,
	 tpdu->MessageReference,
	 tpdu->RecipientAddr.len,
	 tpdu->RecipientAddr.ton,
	 tpdu->RecipientAddr.npi,
	 tpdu->RecipientAddr.min,
     tpdu->TimeStamp.Year+2000,
     tpdu->TimeStamp.Month,
     tpdu->TimeStamp.Day,
     tpdu->TimeStamp.Hour,
     tpdu->TimeStamp.Min,
     tpdu->TimeStamp.Sec,
     (char)tpdu->TimeStamp.TimeZone,
     tpdu->DischargeTime.Year+2000,
     tpdu->DischargeTime.Month,
     tpdu->DischargeTime.Day,
     tpdu->DischargeTime.Hour,
     tpdu->DischargeTime.Min,
     tpdu->DischargeTime.Sec,
     (char)tpdu->DischargeTime.TimeZone,
	 tpdu->Status,
	 tpdu->Status == 0?"Short message delivered successfully":"Message expired",
     tpdu->ParameterID.isPIDPresent,
     tpdu->ParameterID.isDCSPresent,
     tpdu->ParameterID.isUDLPresent);

	 return (tLen);
}


#if 0
int printTpdu_command(TSMSCommand *tpdu, char *str)
{
	char             userData[200];
	char             *pos;

	pos = str;

    printHexaStringTpdu(&tpdu->CommandData, tpdu->CommandDataLength,
		userData); 

    sprintf(pos, "[COMMAND]\n\
\tMessageTypeIndicator    :[%d]\n\
\tUDH Indicator           :[%d]\n\
\tStatusReportRequest     :[%d]\n\
\tMessageReference        :[%d]\n\
\tProtocolIdentifier      :[0x%02X]\n\
\tCommandType             :[%d]\n\
\tCommandType             :[%s]\n\
\tMessgeNumber            :[%d]\n\
\tDA[len]                 :[%d]\n\
\tDA[ton]                 :[%d]\n\
\tDA[npi]                 :[%d]\n\
\tDA[address]             :[%s]\n\
\tCommandDataLength       :[%d]\n%s", 
	tpdu->MessageTypeID,
	tpdu->udhId,
	tpdu->StatusReportRequest,
	tpdu->MessageReference,
	tpdu->pid,
	tpdu->CommandType,
    (tpdu->CommandType == 0x00 ? "Enquiry" :
    tpdu->CommandType == 0x01 ? "Cancel" :
    tpdu->CommandType == 0x02 ? "Delete" :
    tpdu->CommandType == 0x03 ? "Enable" : "UNKNOWN"),
	tpdu->MessageNumber,
	tpdu->DestinationAddr.len,
	tpdu->DestinationAddr.ton,
	tpdu->DestinationAddr.npi,
	tpdu->DestinationAddr.min,
	tpdu->CommandDataLength, userData);

	return 1;
}
#endif


int printTpdu(_TPDU *tpdu, char *str)
{
    switch(tpdu->MessageType)
    {
        case TPDU_SMS_DELIVER:
            printTpdu_deliver(&tpdu->Union.SMSDeliver, str);
            break;

#if 0
        case TPDU_SMS_DELIVER_REPORT:
            printTpdu_deliverReport(&tpdu->Union.SMSDeliverReport, str);
            break;
#endif

        case TPDU_SMS_SUBMIT:
            printTpdu_submit(&tpdu->Union.SMSSubmit, str);
            break;
                                                            
        case TPDU_SMS_STATUS_REPORT:
            printTpdu_statusReport(&tpdu->Union.SMSStatusReport, str);
            break;

#if 0
        case TPDU_SMS_SUBMIT_REPORT:
            printTpdu_submitReport(&tpdu->Union.SMSSubmitReport, str);
            break;

        case TPDU_SMS_COMMAND:
            printTpdu_command(&tpdu->Union.SMSCommand, str);
            break;
                                                            
#endif
        default:
			return -1;
    }
	return 1;
}

