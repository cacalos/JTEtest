
#include <time.h>
#include <TPDU/BitUtil.h>
#include <TPDU/TPDU.h>
#include <ua_log.h>
#include <iXtypes.h>


char GetTPDUMessageType(byte *Packet, int nFrom)    
{
    int          Type, subType;
    
    Type = GetBits(Packet[0], 0, 2);

    switch(Type)
    {
        case 0: //00
            Type = (nFrom == DIRECTION_SC_MS) ? TPDU_SMS_DELIVER 
                : TPDU_SMS_DELIVER_REPORT;
            break;

        case 1: //01
            Type =  (nFrom == DIRECTION_SC_MS) ? TPDU_SMS_SUBMIT_REPORT 
                : TPDU_SMS_SUBMIT;
            break;

        case 2: //10
            Type =  (nFrom == DIRECTION_SC_MS) ? TPDU_SMS_STATUS_REPORT 
                : TPDU_SMS_COMMAND;
            break;

        case 3: //11
            Type = TPDU_SMS_HNETSTOP;
            break;

        default :
            Type = -1;
            break;
    }

    return Type;
}


int DecodeTPDU(_TPDU *tpdu, byte *Packet, int PacketSize, int nFrom,
               boolean isRPError)
{
    int               size = -1;

    bzero((void *)tpdu, sizeof(_TPDU));

    tpdu->MessageType = GetTPDUMessageType(Packet, nFrom);
    
    switch(tpdu->MessageType)
    {
        case TPDU_SMS_DELIVER:
            size = DecodeSMSDeliver(&(tpdu->Union.SMSDeliver), Packet,
                PacketSize);
            break ;
                
        case TPDU_SMS_DELIVER_REPORT:
            size = DecodeSMSDeliverReport(
                (byte *)&(tpdu->Union.SMSDeliverReport), 
                Packet, PacketSize, isRPError);
            break ;
                
        case TPDU_SMS_SUBMIT:
            size = DecodeSMSSubmit((byte *)&(tpdu->Union.SMSSubmit), 
                Packet, PacketSize);
            break ;
                
        case TPDU_SMS_SUBMIT_REPORT:
            size = DecodeSMSSubmitReport(
                (byte *)&(tpdu->Union.SMSSubmitReport), 
                Packet, PacketSize, isRPError);
            break ;
                
        case TPDU_SMS_STATUS_REPORT:
            size = DecodeSMSStatusReport(
                (byte *)&(tpdu->Union.SMSStatusReport), Packet, PacketSize);
            break ;
                
        case TPDU_SMS_COMMAND:
            size = DecodeSMSCommand((byte *)&(tpdu->Union.SMSCommand), 
                Packet, PacketSize);
            break ;

        default :
            size = -1;
            break;
    }
    
    return size;
}


int EncodeTPDU(byte *Packet, _TPDU *tpdu, int nFrom, boolean isRPError)
{
    int             Size = -1;

    switch(tpdu->MessageType)
    {
        case TPDU_SMS_DELIVER:
            Size = EncodeSMSDeliver(Packet, (byte *)&(tpdu->Union.SMSDeliver));
            break;
                
        case TPDU_SMS_DELIVER_REPORT:
            Size = EncodeSMSDeliverReport(Packet, 
                (byte *)&(tpdu->Union.SMSDeliverReport), isRPError);
            break;
                
        case TPDU_SMS_SUBMIT:
            Size = EncodeSMSSubmit(Packet, (byte *)&(tpdu->Union.SMSSubmit));
            break;
                
        case TPDU_SMS_SUBMIT_REPORT:
            Size = EncodeSMSSubmitReport(Packet, 
                (byte *)&(tpdu->Union.SMSSubmitReport), isRPError);
            break ;
                
        case TPDU_SMS_STATUS_REPORT:
            Size = EncodeSMSStatusReport(Packet, 
                (byte *)&(tpdu->Union.SMSStatusReport));
            break ;
                
        case TPDU_SMS_COMMAND:
            Size = EncodeSMSCommand(Packet, (byte *)&(tpdu->Union.SMSCommand));
            break;

        default :
            Size = -1;
            break;
    }
    
    return Size;
}


int EncodeAddress(byte *EncodingData, int AddressLength, int TypeOfNumber,
                  int NumberingPlanID, byte *AddressValue)
{
    int len;

    EncodingData[0] = AddressLength;
    EncodingData[1] = (SetBits(0, 7, 1, 1) 
                        | SetBits(0, 4, 3, TypeOfNumber) 
                        | SetBits(0, 0, 4, NumberingPlanID));
    len = SetAddrSemiOctet(&EncodingData[2], AddressValue, AddressLength,
        TPDU_TRUE);

    return len+1 + 1;
}


int DecodeAddress(byte *EncodedData, int *AddressLength, int *TypeOfNumber,
                  int *NumberingPlanID, byte *AddressValue)
{
    int          i;
	int			addrLen=0;

    *TypeOfNumber    = GetBits(EncodedData[1], 4, 3);
    *NumberingPlanID = GetBits(EncodedData[1], 0, 4);

    if(EncodedData[0] > 20)
        return TPDU_DEC_ERR_ADDRLEN;


	if(  *TypeOfNumber  ==   TON_ALPHA_NUMERIC )
	{
		uaLog(L_INFO,"Delivery Adress AlphaNumeric %d , %d, %d" ,  *TypeOfNumber  , *NumberingPlanID, EncodedData[0]);
		/* Modified by dduckk, R210, 20160302, change new api */
		//*AddressLength = Decode7BitPack(&EncodedData[2], AddressValue, 0 , EncodedData[0]); 
		*AddressLength = Decode7BitPackNew(&EncodedData[2], AddressValue, EncodedData[0]); 
		addrLen = EncodedData[0];
	}
	else {
		addrLen = *AddressLength = GetSemiOctet(&EncodedData[2], AddressValue, EncodedData[0],
				TPDU_TRUE);

		for(i = 0; i < *AddressLength; i++)
			if(AddressValue[i] == 10+'0') 
				AddressValue[i] = '*';
			else if(AddressValue[i] == 11+'0')
				AddressValue[i] = '#';
	}

    //return (*AddressLength);
    return addrLen;
}


int AnalysisProtocolID(byte ProtocolID)
{
    switch(GetBits(ProtocolID, 6, 2))
    {
        case 0: //bit 7,6 = 0 0       
            break;

        case 1: //bit 7,6 = 0 1       
            break;

        case 2: //bit 7,6 = 1 0       
            break;

        case 3: //bit 7,6 = 1 1       
            break;
    }
}


int EncodeTimeZone(int TimeZone)
{
    if(TimeZone < 0)
    {
        TimeZone = -TimeZone;
        /* TimeZone = ((TimeZone/10) | 0x08) | ((TimeZone % 10) << 4); */
        TimeZone = (TimeZone/10) |  ((TimeZone % 10) << 4);
    }
    else
        TimeZone = ((TimeZone/10) | 0x08 ) | ((TimeZone%10)<<4);

    return TimeZone;
}


int DecodeTimeZone(int TimeZone)
{
    if(GetBits(TimeZone, 3, 1) == 1) //negative
    {
        TimeZone = SetBits(TimeZone, 3, 1, 0);
        TimeZone = -( ((TimeZone & 0x0F) *10) + ((TimeZone >> 4) & 0x0F) );
    }
    else
        TimeZone = ((TimeZone & 0x0F) *10) + ((TimeZone >> 4) & 0x0F);

    return TimeZone;
}


int EncodeServiceCenterTimeStamp(byte *EncodingData, int Year, int Month,
                                 int Day, int Hour, int Minute, int Second,
                                 int TimeZone)
{
    char             Temp[20];
    int              Size;

    Year %= 100;
    sprintf(Temp, "%02d%02d%02d%02d%02d%02d",
        Year, Month, Day, Hour, Minute, Second);  
    
    Size = SetSemiOctet((byte *)EncodingData, (byte *)Temp, 12, TPDU_TRUE); 
    EncodingData[Size] = (byte)EncodeTimeZone(TimeZone);

    return Size+1;
}


int DecodeServiceCenterTimeStamp(byte *EncodedData, int *Year, int *Month,
                                 int *Day, int *Hour, int *Minute, int *Second,
                                 int *TimeZone)
{
    char             Temp[20];
    int              Size;

    Size      = GetSemiOctet((byte *)EncodedData, (byte *)Temp, 12, TPDU_FALSE);
    *Year     = Temp[0] * 10 + Temp[1];
    *Month    = Temp[2] * 10 + Temp[3];
    *Day      = Temp[4] * 10 + Temp[5];
    *Hour     = Temp[6] * 10 + Temp[7];
    *Minute   = Temp[8] * 10 + Temp[9];
    *Second   = Temp[10] * 10 + Temp[11];
    *TimeZone = DecodeTimeZone(EncodedData[6]);

    return Size+2;
}


int EncodeServiceCenterTimeStamp_tm(char *EncodingData, struct tm *t,
                                    int TimeZone)
{
    char          Temp[20];

    sprintf(Temp, "%02d%02d%02d%02d%02d%02d%02d", 
        t->tm_year%100, t->tm_mon+1, t->tm_mday, 
        t->tm_hour, t->tm_min, t->tm_sec, EncodeTimeZone(TimeZone));  

    return SetSemiOctet((byte *)EncodingData, (byte *)Temp, 14, TPDU_TRUE); 
}


int DecodeServiceCenterTimeStamp_tm(char *EncodedData, struct tm *t,
                                    int *TimeZone)
{
    char              Temp[20];
    int               Return;

    Return = GetSemiOctet((byte *)EncodedData, (byte *)Temp, 14, TPDU_FALSE); 
    t->tm_year   = Temp[0] * 10 + Temp[1];
    t->tm_mon    = Temp[2] * 10 + Temp[3] -1;
    t->tm_mday   = Temp[4] * 10 + Temp[5];
    t->tm_hour   = Temp[6] * 10 + Temp[7];
    t->tm_min    = Temp[8] * 10 + Temp[9];
    t->tm_sec    = Temp[10] * 10 + Temp[11];
    *TimeZone    = DecodeTimeZone(Temp[12] * 10 + Temp[13]);

    return Return;
}


int CountTLVElement(byte *Data, int TotalSize)
{
    int           i, Length;

    for(i = 0, Length = 0; Length < TotalSize; i++)
        Length += (Data[Length+1]+2);    

    return i;
}


int SetTLVElement(byte *EncodingData, int Tag, int Length, byte *Value)
{
    if(Length < 0 || Length > ELEMENT_DATALEN)
        return 0;

    EncodingData[0] = Tag;
    EncodingData[1] = Length;
    memcpy(&EncodingData[2], Value, Length);

    return Length + 2;
}


int GetTLVElement(byte *Data, int *Tag, int *Length, byte *Value, int Position)
{
    int i, Offset, tLength;

    for(i=0, Offset=0; i<Position; i++)
    {
        *Tag = Data[Offset];
        *Length = Data[Offset+1];
        Offset += (*Length)+2; 
    }

    memcpy(Value, &Data[Offset - *Length], *Length);

    return Offset;
}


byte EncodeParameterIndicator(boolean isPIDPresent, boolean isDCSPresent, boolean isUDLPresent)
{
    byte ParameterIndicator;

    ParameterIndicator = SetBits(ParameterIndicator, 0, 1, isPIDPresent);
    ParameterIndicator = SetBits(ParameterIndicator, 1, 1, isDCSPresent);
    ParameterIndicator = SetBits(ParameterIndicator, 2, 1, isUDLPresent);
 
    return ParameterIndicator;
} 


int GetElements(byte *InputData, byte *OutputData, int InputDataSize)
{
    int                  i;
    int                  Tag, Length;
    stUDH               *udh = (stUDH *)OutputData;
    stEI                *ei = udh->ei;
    int                  total = 0;

    udh->eiCnt = CountTLVElement(InputData, InputDataSize);
    for(i = 0; i < udh->eiCnt; i++)
    {
        total = GetTLVElement(InputData, &Tag, &Length, 
            (byte *)ei[i].Data, i+1);
        if(total > InputDataSize)
            return -1;

        ei[i].ID = Tag;
        ei[i].Length = Length;
        total += (Length+2);
    }    
    
    return udh->eiCnt;
}


int SetElements(byte *OutputData, byte *InputData, int eiCnt)
{
    int             i, TotalLength;
    stEI           *ei = (stEI *)InputData;

    for(i = 0, TotalLength = 0; i < eiCnt; i++)
    {        
        TotalLength += SetTLVElement(&OutputData[TotalLength],
            ei[i].ID, ei[i].Length, ei[i].Data);
    }

    return TotalLength;
}


/* 05/10/12 sjkim add : Only use Submit(because USIM Submit) */
int DecodeUserDataSubmit(TUserData *UserData, byte *EncodedData, int DataSize,
        int DataCodingScheme, boolean isContainHeader)
{
    int            i, ret;
    int            HeaderLength = 0;
    int            MessageLength = 0;
    int            FillBitCount;
    unsigned char  encode;


#if 0
    if(DataSize > MAX_SIZE_TP_UD)
        return TPDU_DEC_ERR_UDLMAX;
#endif
    if(DataSize > MAX_SIZE_TP_UD)
	{
    	encode = GetEncodeFromDcs(DataCodingScheme);

		if(encode == ENCODE_7BIT_ASCII 
				|| encode == ENCODE_7BIT_GSM
				|| Check7BitDCS(DataCodingScheme) == ENCODE_7BIT_GSM)
		{
			if(DataSize > MAX_SIZE_TP_UD + 20)
				return TPDU_DEC_ERR_UDLMAX;
		}
		else
        	return TPDU_DEC_ERR_UDLMAX;
	}

    if(DataSize == 0)
    {
        UserData->DataLength = 0;
        UserData->udh.Length = 0;
        UserData->udh.eiCnt = 0;
        return 0;
    }

    HeaderLength = -1;

#if 0
	/* 05/10/10 sjkim add : check iei is USIM or Not */
    if(isContainHeader == TPDU_TRUE)
    {
		stUDH		tmpUdh;
		int			tmpHeaderLength;

		memset( &tmpUdh, 0, sizeof(stUDH) );
        tmpHeaderLength = EncodedData[0];

        if(tmpHeaderLength >= DataSize)
            return TPDU_DEC_ERR_UDHL;

        tmpUdh.Length = tmpHeaderLength;
        ret = GetElements(&EncodedData[1], 
                    (byte *)&(tmpUdh), tmpHeaderLength);

        if(ret < 0) //decode error header element 
            return TPDU_DEC_ERR_IEL;

		for( int i=0; i < tmpUdh.eiCnt; i++ )
		{
			/* USIM Tag */
			if( tmpUdh.ei[i].ID >= ELEMENT_USIM_DOWN_START &&
				tmpUdh.ei[i].ID <= ELEMENT_USIM_DOWN_END )
			{
				isContainHeader = TPDU_FALSE;
				*pid = PID_SPECIAL_SIM_DOWN;
				uaLog(L_MAJ, "USIM Tag Found :%2X (i=%d)", tmpUdh.ei[i].ID, i);
				break;
			}
		}
    }
	/* end */
#endif


    if(isContainHeader == TPDU_TRUE)
    {
        HeaderLength = EncodedData[0];

        if(HeaderLength >= DataSize)
            return TPDU_DEC_ERR_UDHL;

        UserData->udh.Length = HeaderLength;
        ret = GetElements(&EncodedData[1], 
                    (byte *)&(UserData->udh), HeaderLength);

        if(ret < 0) //decode error header element 
            return TPDU_DEC_ERR_IEL;
    }


    encode = GetEncodeFromDcs(DataCodingScheme);
    if(encode == ENCODE_7BIT_GSM 
			|| encode == ENCODE_7BIT_ASCII
			|| Check7BitDCS(DataCodingScheme) == ENCODE_7BIT_GSM)
    {
        FillBitCount = (HeaderLength+1)*8 %7;
        FillBitCount = FillBitCount==0 ? 0 : 7- FillBitCount;

        // number of bits Message
        MessageLength = (DataSize*7) - (HeaderLength+1)*8;

        // number of octets Message
        //MessageLength = (MessageLength+8) / 8;
        MessageLength = (MessageLength / 7);

        if(encode == ENCODE_7BIT_ASCII)
            MessageLength = Decode7BitAsciiPack(&EncodedData[HeaderLength+1], 
                UserData->Data, FillBitCount, MessageLength); 
        else
            MessageLength = Decode7BitPack(&EncodedData[HeaderLength+1], 
                UserData->Data, FillBitCount, MessageLength); 
    }
    else
    {
        MessageLength = DataSize - (HeaderLength+1);    
        memcpy(UserData->Data, &EncodedData[HeaderLength+1], MessageLength);
    }

    UserData->Length = HeaderLength + 1 + MessageLength;
    UserData->DataLength = MessageLength;

    return MessageLength;
}



int DecodeUserData(TUserData *UserData, byte *EncodedData, int DataSize,
        int DataCodingScheme, boolean isContainHeader )
{
    int            i, ret;
    int            HeaderLength = 0;
    int            MessageLength = 0;
    int            FillBitCount;
    unsigned char  encode;


    if(DataSize > MAX_SIZE_TP_UD)
	{
		encode = GetEncodeFromDcs(DataCodingScheme);
		if(encode == ENCODE_7BIT_GSM 
				|| ENCODE_7BIT_ASCII
				|| Check7BitDCS(DataCodingScheme) == ENCODE_7BIT_GSM)
		{
			if(DataSize > MAX_SIZE_TP_UD + 20)
				return TPDU_DEC_ERR_UDLMAX;
		}
		else
        	return TPDU_DEC_ERR_UDLMAX;
	}

    if(DataSize == 0)
    {
        UserData->DataLength = 0;
        UserData->udh.Length = 0;
        UserData->udh.eiCnt = 0;
        return 0;
    }

    HeaderLength = -1;

    if(isContainHeader == TPDU_TRUE)
    {
        HeaderLength = EncodedData[0];

        if(HeaderLength >= DataSize)
            return TPDU_DEC_ERR_UDHL;

        UserData->udh.Length = HeaderLength;
        ret = GetElements(&EncodedData[1], 
                    (byte *)&(UserData->udh), HeaderLength);

        if(ret < 0) //decode error header element 
            return TPDU_DEC_ERR_IEL;
    }


    encode = GetEncodeFromDcs(DataCodingScheme);
    if(encode == ENCODE_7BIT_GSM 
			|| encode == ENCODE_7BIT_ASCII
			|| Check7BitDCS(DataCodingScheme) == ENCODE_7BIT_GSM)
    {
        FillBitCount = (HeaderLength+1)*8 %7;
        FillBitCount = FillBitCount==0 ? 0 : 7- FillBitCount;

        // number of bits Message
        MessageLength = (DataSize*7) - (HeaderLength+1)*8;

        // number of octets Message
        //MessageLength = (MessageLength+8) / 8;
        MessageLength = (MessageLength / 7);

        if(encode == ENCODE_7BIT_ASCII)
            MessageLength = Decode7BitAsciiPack(&EncodedData[HeaderLength+1], 
                UserData->Data, FillBitCount, MessageLength); 
        else
            MessageLength = Decode7BitPack(&EncodedData[HeaderLength+1], 
                UserData->Data, FillBitCount, MessageLength); 

		 uaLog(L_INFO , "DECODE GSM_7BIT MessageLength %d ", MessageLength);
    }
    else
    {
        MessageLength = DataSize - (HeaderLength+1);    
        memcpy(UserData->Data, &EncodedData[HeaderLength+1], MessageLength);
    }

    UserData->Length = HeaderLength + 1 + MessageLength;
    UserData->DataLength = MessageLength;

    return MessageLength;
}



int EncodeUserData(byte *EncodingData, TUserData *UserData,
        byte DataCodingScheme, boolean isContainHeader)
{
    int                   i;
    int                   HeaderLength = 0; 
    int                   MessageLength = 0;
    int                   FillBitCount;
    int                   UserDataLength = 0;
    unsigned char         encode;

    HeaderLength = -1;
    if(isContainHeader == TPDU_TRUE)
    {
        HeaderLength = SetElements(&EncodingData[1], 
            (byte *)(UserData->udh.ei), 
            UserData->udh.eiCnt);
        EncodingData[0] = HeaderLength;
    }

    encode = GetEncodeFromDcs(DataCodingScheme);

    if(encode == ENCODE_7BIT_GSM
			|| Check7BitDCS(DataCodingScheme) == ENCODE_7BIT_GSM)
    {
        FillBitCount = (HeaderLength+1)*8 %7;
        FillBitCount = FillBitCount==0 ? 0 : 7- FillBitCount;

        MessageLength = Encode7BitPack(UserData->Data, 
            &EncodingData[HeaderLength+1], FillBitCount, 
            UserData->DataLength);

        UserDataLength = ((HeaderLength+1)*8 + FillBitCount) /7; 
        UserDataLength += UserData->DataLength;
//        UserDataLength += (UserData->DataLength*8)/7;
    }
    else if(encode == ENCODE_7BIT_ASCII)
    {
        FillBitCount = (HeaderLength+1)*8 %7;
        FillBitCount = FillBitCount==0 ? 0 : 7- FillBitCount;

        MessageLength = Encode7BitAsciiPack(UserData->Data,
            &EncodingData[HeaderLength+1], FillBitCount,
            UserData->DataLength);

        UserDataLength = ((HeaderLength+1)*8 + FillBitCount) /7; 
        UserDataLength += UserData->DataLength;
    }
    else
    {
        memcpy(&EncodingData[HeaderLength+1], UserData->Data, 
            UserData->DataLength);
        MessageLength  = UserData->DataLength;
        UserDataLength = (HeaderLength +1) + MessageLength;
    }
    
    return UserDataLength;
}


int DecodeSMSDeliver(TSMSDeliver *SMSDeliver, byte *Packet, int PacketSize)
{
    byte               mti, mms, sri, udhi, rp;
    int                AddressLength, ton, npi;
    byte               AddressValue[256];
    byte               pid, dcs, encode;
    byte               ServiceCenterTimeStamp[7];
    int                Year, Month, Day, Hour, Minute, Second, TimeZone;
    int                UserDataLength = 0;
    boolean            isSeptetSize, isContainHeader;
    int                MessageLength = 0;
    int                Size = 0, Offset;
    
    Offset = 0;
    mti    = GetBits(Packet[Offset], 0, 2);
    mms    = GetBits(Packet[Offset], 2, 1);
    sri    = GetBits(Packet[Offset], 5, 1);
    udhi   = GetBits(Packet[Offset], 6, 1);
    isContainHeader = udhi;
    rp     = GetBits(Packet[Offset], 7, 1);
    Offset++;

    Size = DecodeAddress((byte *)&Packet[Offset], &AddressLength, 
                            &ton, &npi, AddressValue);
    if(Size < 0) return Size;

	if(ton == TON_ALPHA_NUMERIC)
//		Offset += Size -1;
		Offset += (Size+1)/2 +2;
	else
    	Offset += ((Size+1)/2 + 2);

    pid = Packet[Offset++];
    dcs = Packet[Offset++];

    Size = DecodeServiceCenterTimeStamp((byte *)&Packet[Offset], 
                            &Year, &Month, &Day, 
                            &Hour, &Minute, &Second, &TimeZone);
    Offset += (Size+1)/2;

    encode = GetEncodeFromDcs(dcs);

    UserDataLength = Packet[Offset++];

    if(UserDataLength > MAX_SIZE_TP_UD)
	{
		if(encode == ENCODE_7BIT_GSM 
				|| encode == ENCODE_7BIT_ASCII
				|| Check7BitDCS(dcs) == ENCODE_7BIT_GSM)
		{
			if(UserDataLength > MAX_SIZE_TP_UD + 20)
				return TPDU_DEC_ERR_IEL;
		}
		else
        	return TPDU_DEC_ERR_UDLMAX;
	}


    Size = (encode == ENCODE_7BIT_GSM 
			|| encode == ENCODE_7BIT_ASCII 
			|| Check7BitDCS(dcs) == ENCODE_7BIT_GSM) ? (UserDataLength*7 +7)/8 : UserDataLength;

	SMSDeliver->RawDataLength = UserDataLength; //by Charge
	memcpy(SMSDeliver->RawData, (void *)&Packet[Offset], Size); //by Charge

    MessageLength = DecodeUserData(&(SMSDeliver->UserData), 
        (byte *)&Packet[Offset], UserDataLength, dcs, isContainHeader);

    if(MessageLength < 0)
	{
		/* for debug */
		uaLog(L_CRT, "MessageLength(%d)", MessageLength);
        return MessageLength;
	}

    TimeStamp_StructSetInOut(&(SMSDeliver->TimeStamp),
                Year,         //,int Year
                Month,         //,byte Month
                Day,         //,byte Day
                Hour,         //,byte Hour
                Minute,     //,byte Min
                Second,     //byte Sec
                TimeZone);     //,byte TimeZone);

    Address_StructSetInOut(&(SMSDeliver->OriginatingAddr),
                AddressValue,     //,byte min[20]
                ton,             //,byte ton
                npi,             //,byte npi
                AddressLength,     //,byte len
                1 );             //,byte reserved);

    SMSDeliver_StructSetInOut(SMSDeliver,
                mti,                             //,byte MsgTypeID
                mms,                             //byte MoreMsgToSend
                rp,                             //,byte ReplyPath
                udhi,                             //,byte udhId
                sri,                             //,byte StatusReportID
                &(SMSDeliver->OriginatingAddr), //,TAddress *OriginatingAddr
                pid,                             //,byte pid
                dcs,                             //,byte dcs
                &(SMSDeliver->TimeStamp),         //,TTimeStamp *TimeStamp
//                MessageLength,
				UserDataLength,
                &(SMSDeliver->UserData));         //,TUserData *UserData);

    return sizeof(TSMSDeliver);
}


int EncodeSMSDeliver(byte *OutPacket, byte *InData)
{
    int Offset;
    int Size=0; 
    byte mti, mms, sri, udhi, rp;
    byte AddressLength, ton, npi;
    byte AddressValue[256];
    byte pid, dcs, encode;
    byte ServiceCenterTimeStamp[7];
    int Year;
    byte Month, Day, Hour, Minute, Second, TimeZone;
    int UserDataLength=0;
    boolean isSeptetSize, isContainHeader;
    byte HeaderElementArray[200];
    int eiCnt;
    byte InputUserDataMessage[200];
    int InputUserDataMessageSize;
    TSMSDeliver *SMSDeliver = (TSMSDeliver *)InData;
    
    TimeStamp_StructGetInOut(&(SMSDeliver->TimeStamp),
        &Year, &Month, &Day, &Hour, &Minute, &Second, &TimeZone);

    Address_StructGetInOut(&(SMSDeliver->OriginatingAddr),
                AddressValue,     //,byte min[20]
                &ton,             //,byte *ton
                &npi,             //,byte *npi
                &AddressLength, //,byte *len
                NULL);             //,byte *reserved);

    SMSDeliver_StructGetInOut((TSMSDeliver *)InData,
                &mti,     //,byte *MsgTypeID
                &mms,     //,byte *MoreMsgToSend
                &rp,     //,byte *ReplyPath
                &udhi,     //,byte *udhId
                &sri,     //,byte *StatusReportID
                NULL,     //TAddress *OriginatingAddr
                &pid,     //,byte *ProtocolID
                &dcs,     //,byte *DataCodingScheme
                NULL,     //,TTimeStamp *TimeStamp
                NULL,     //,byte *UserDataLength
                NULL);     //,TUserData *UserData);


    Offset=0;
    OutPacket[Offset] = 0x00; //SetBits(OutPacket[Offset], 0, 2, mti);
    OutPacket[Offset] = SetBits(OutPacket[Offset], 2, 1, mms);
    OutPacket[Offset] = SetBits(OutPacket[Offset], 5, 1, sri);

    if(SMSDeliver->UserData.udh.eiCnt == 0)
        udhi = 0;

    OutPacket[Offset] = SetBits(OutPacket[Offset], 6, 1, udhi); isContainHeader = udhi;
    OutPacket[Offset] = SetBits(OutPacket[Offset], 7, 1, rp);
    Offset++;

    Size = EncodeAddress(&OutPacket[Offset], 
                            AddressLength, ton, npi, AddressValue);
    Offset += Size;
    OutPacket[Offset++] = pid;
    OutPacket[Offset++] = dcs;
    
    encode = GetEncodeFromDcs(dcs);

    Offset += EncodeServiceCenterTimeStamp(&OutPacket[Offset], 
        Year, Month, Day, Hour, Minute, Second, (char)TimeZone); 

    OutPacket[Offset] = EncodeUserData(&OutPacket[Offset+1], 
        &(SMSDeliver->UserData), dcs, isContainHeader);

    return (encode == ENCODE_7BIT_GSM 
			|| encode == ENCODE_7BIT_ASCII
			|| Check7BitDCS(dcs) == ENCODE_7BIT_GSM)
        ? Offset + (OutPacket[Offset]*7+7)/8  +1
        : Offset + OutPacket[Offset] +1;
}


int DecodeSMSDeliverReport(byte *OutStruct, byte *Packet, int PacketSize,
        boolean isRPError)
{
    int                   Offset, Size;
    byte                  MessageTypeIndicator;
    byte                  UserDataLength = 0;
    byte                  FailureCause;
    byte                  pid, dcs, encode;
    byte                  udhi;
    byte                  MessageLength = 0;
    boolean               isPIDPresent, isDCSPresent, isUDLPresent;
    boolean               isContainHeader;
    TSMSDeliverReport    *SMSDeliverReport = (TSMSDeliverReport *)OutStruct;

    Offset = 0;
    MessageTypeIndicator = GetBits(Packet[Offset], 0, 2);
    isContainHeader = udhi = GetBits(Packet[Offset], 6, 1);
    Offset++;

    if(isRPError)
        FailureCause = Packet[Offset++];

    //Parameter Indicator
    isPIDPresent = GetBits(Packet[Offset], 0, 1);
    isDCSPresent = GetBits(Packet[Offset], 1, 1);
    isUDLPresent = GetBits(Packet[Offset], 2, 1);

    if(GetBits(Packet[Offset], 7, 1) == 1) 
        Offset++;

    Offset++;
    
    if(isPIDPresent)
        pid = Packet[Offset++];
    else
        pid = 0x00;

    if(isDCSPresent)
        dcs = Packet[Offset++];
    else
        dcs = 0x00;

    encode = GetEncodeFromDcs(dcs);

    UserDataLength = MessageLength = 0;
    if(isUDLPresent)
    {
        UserDataLength = Packet[Offset++];

#if 0
    if(UserDataLength > MAX_SIZE_TP_UD)
        return TPDU_DEC_ERR_UDLMAX;
#endif

		if(UserDataLength > MAX_SIZE_TP_UD)
		{
			if(encode == ENCODE_7BIT_GSM 
					|| encode == ENCODE_7BIT_ASCII
					|| Check7BitDCS(dcs) == ENCODE_7BIT_GSM)
			{
				if(UserDataLength > MAX_SIZE_TP_UD + 20)
					return TPDU_DEC_ERR_IEL;
			}
			else
				return TPDU_DEC_ERR_UDLMAX;
		}

		Size = (encode == ENCODE_7BIT_GSM 
				|| encode == ENCODE_7BIT_ASCII 
				|| Check7BitDCS(dcs) == ENCODE_7BIT_GSM) ? (UserDataLength*7 +7)/8 : UserDataLength;

        if(Size != PacketSize-Offset)
            return TPDU_DEC_ERR_UDL;

        MessageLength = DecodeUserData(&(SMSDeliverReport->UserData), 
            (byte *)&Packet[Offset], UserDataLength, dcs, isContainHeader);
        if(MessageLength < 0)
            return MessageLength;
    }

    Parameter_StructSetInOut(&(SMSDeliverReport->ParameterID),
        isPIDPresent, isDCSPresent, isUDLPresent);

    SMSDeliverReport_StructSetInOut(SMSDeliverReport,
        MessageTypeIndicator, udhi, FailureCause,
        &(SMSDeliverReport->ParameterID), pid, dcs, UserDataLength,
        &(SMSDeliverReport->UserData));

    return sizeof(TSMSDeliverReport);
}


int EncodeSMSDeliverReport(byte *OutPacket, byte *InputData, boolean isRPError)
{
    int Offset;
    byte MessageTypeIndicator;
    byte UserDataLength=0;
    byte FailureCause;
    byte pid, dcs, encode;
    byte udhi;
    boolean isPIDPresent, isDCSPresent, isUDLPresent, isContainHeader;
    TSMSDeliverReport *SMSDeliverReport = (TSMSDeliverReport *)InputData;

    Parameter_StructGetInOut(&(SMSDeliverReport->ParameterID),
                        (int *)&isPIDPresent, //int *isPIDPresent
                        (int *)&isDCSPresent, //int *isDCSPresent
                        (int *)&isUDLPresent); //int *isUDLPresent);
    
    SMSDeliverReport_StructGetInOut(SMSDeliverReport,
                        &MessageTypeIndicator, //,byte *MessageTypeID
                        &udhi, //,byte *udhId
                        &FailureCause, //,byte *FailureCause
                        NULL, //,TParameter *ParameterID
                        &pid, //,byte *ProtocolID
                        &dcs, //,byte *DataCodingScheme
                        &UserDataLength, //,byte *UserDataLength
                        NULL); //,TUserData *UserData);

    if(SMSDeliverReport->UserData.udh.eiCnt == 0)
        udhi = 0;

    isContainHeader = udhi;

    Offset = 0;
    OutPacket[Offset] = 0x00;
    OutPacket[Offset] = SetBits(OutPacket[Offset], 6, 1,udhi);
    Offset++;

    if(isRPError)
        OutPacket[Offset++] = FailureCause;

    OutPacket[Offset++] = EncodeParameterIndicator(isPIDPresent, isDCSPresent,
        isUDLPresent);
    
    if(isPIDPresent)
        OutPacket[Offset++] = pid; 

    if(isDCSPresent)
        OutPacket[Offset++] = dcs;

    encode = GetEncodeFromDcs(dcs);

    if(isUDLPresent)
    {
        UserDataLength = EncodeUserData(&OutPacket[Offset+1], 
            &(SMSDeliverReport->UserData), dcs, isContainHeader);
        OutPacket[Offset] = UserDataLength;        
    }

    return (encode == ENCODE_7BIT_GSM 
			|| encode == ENCODE_7BIT_ASCII 
			|| Check7BitDCS(dcs) == ENCODE_7BIT_GSM)
        ? Offset + (UserDataLength*7+7)/8 +1
        : Offset + UserDataLength +1;
}


int DecodeValidityPeriod(byte *EncodedData, byte *OutStruct,
        byte ValidityPeriodFormat)
{
    int Size=-1;
    int Year;
    int Month, Day, Hour, Minute, Second, TimeZone;

    switch(ValidityPeriodFormat)
    {
        case TPDU_VPF_NOT_PRESENT :
                Size=0;
                break;

        case TPDU_VPF_ENHANCED :
                Size = 7;
                break;

        case TPDU_VPF_RELATIVE :
                OutStruct[0] = EncodedData[0];
                Size = 1;
                break;

        case TPDU_VPF_ABSOLUTE :
                DecodeServiceCenterTimeStamp(EncodedData, 
                                        &Year, &Month, &Day, 
                                        &Hour, &Minute, &Second, &TimeZone); 
                Size = 7;
                break;
    }

    return Size;
}


int EncodeValidityPeriod(byte *EncodingData, byte *InputStruct,
        byte ValidityPeriodFormat)
{
    int Size= -1;
    int Year, Month, Day, Hour, Minute, Second, TimeZone;

    switch(ValidityPeriodFormat)
    {
        case TPDU_VPF_NOT_PRESENT :
            Size=0;
            break;

        case TPDU_VPF_ENHANCED :
            Size = 7;
            break;

        case TPDU_VPF_RELATIVE :
            EncodingData[0] = InputStruct[0];
            Size = 1;
            break;

        case TPDU_VPF_ABSOLUTE :
            Size = 7;
            EncodeServiceCenterTimeStamp(EncodingData, Year, Month, Day, 
                Hour, Minute, Second, TimeZone); 
    }

    return Size;
}


int DecodeSMSSubmit(byte *OutStruct, byte *Packet, int PacketSize)
{
    int                  Offset;
    int                  Size = 0;
    byte                 MessageTypeIndicator;
    int                  UserDataLength = 0;
	int					 tmpDataLength = 0;
    byte                 FailureCause;
    byte                 pid, dcs, encode;
    byte                 udhi;
    boolean              isContainHeader;
    byte                 RejectDuplicates;
    byte                 ValidityPeriodFormat;
    byte                 ReplyPath;
    byte                 StatusReportRequest;
    byte                 MessageReference;
    byte                 ValidityPeriodRelative;
    byte                 ValidityPeriodEnhanced[7];
    TTimeStamp           ValidityPeriodAbsolute;
    byte                 TempValidityPeriod[20];
    int                  TypeOfNumber, NumberingPlanID, AddressLength;
    byte                 AddressValue[100];
    int                  Year, Month, Day, Hour, Minute, Second, TimeZone;
    byte                 Temp[100];
    TSMSSubmit          *SMSSubmit = (TSMSSubmit *)OutStruct;

    memset(Temp, 0x0, sizeof(Temp));

    Offset = 0;
    MessageTypeIndicator    = GetBits(Packet[Offset], 0, 2);
    RejectDuplicates        = GetBits(Packet[Offset], 2, 1);
    ValidityPeriodFormat    = GetBits(Packet[Offset], 3, 2);
    ReplyPath               = GetBits(Packet[Offset], 7, 1);
    isContainHeader         = udhi 
                            = GetBits(Packet[Offset], 6, 1);
    StatusReportRequest     = GetBits(Packet[Offset], 5, 1);
    Offset++;

    MessageReference = Packet[Offset++];
     
    Size = DecodeAddress((byte *)&Packet[Offset], &AddressLength,
        &TypeOfNumber, &NumberingPlanID, AddressValue);
    if(Size < 0)
        return Size;
    Offset += ((Size+1)/2 +2);

    pid = Packet[Offset++];
    dcs = Packet[Offset++];

    switch(ValidityPeriodFormat)
    {
        case TPDU_VPF_NOT_PRESENT :
            Size = 0;                
            break;

        case TPDU_VPF_ENHANCED :
            Size = 7;
            memcpy(ValidityPeriodEnhanced, &Packet[Offset], Size);
            break;

        case TPDU_VPF_RELATIVE :
            ValidityPeriodRelative = Packet[Offset];
            Size = 1;
            break;

        case TPDU_VPF_ABSOLUTE :
            DecodeServiceCenterTimeStamp(&Packet[Offset], &Year, &Month, &Day, 
                &Hour, &Minute, &Second, &TimeZone); 
            Size = 7;
            TimeStamp_StructSetInOut(&(SMSSubmit->ValidityPeriodAbsolute),
                Year, Month, Day, Hour, Minute, Second, TimeZone);
            break;
        
        default :
            return TPDU_DEC_ERR_VPF;
    }

    Offset += Size;

    UserDataLength = Packet[Offset++];

    encode = GetEncodeFromDcs(dcs);

#if 0
    if(UserDataLength > MAX_SIZE_TP_UD)
        return TPDU_DEC_ERR_UDLMAX;
#endif

	if(UserDataLength > MAX_SIZE_TP_UD)
	{
		if(encode == ENCODE_7BIT_GSM 
				|| encode == ENCODE_7BIT_ASCII
				|| Check7BitDCS(dcs) == ENCODE_7BIT_GSM)
		{
			if(UserDataLength > MAX_SIZE_TP_UD + 20)
				return TPDU_DEC_ERR_IEL;
		}
		else
			return TPDU_DEC_ERR_UDLMAX;
	}

	Size = (encode == ENCODE_7BIT_GSM 
			|| encode == ENCODE_7BIT_ASCII 
			|| Check7BitDCS(dcs) == ENCODE_7BIT_GSM) ? (UserDataLength*7 +7)/8 : UserDataLength;
    if(Size != PacketSize-Offset)
	{
		uaLog(L_CRT, "DecodeSubmit Size(%d), PacketSize(%d)", Size, PacketSize);
        return TPDU_DEC_ERR_UDL;
	}
	SMSSubmit->RawDataLength = UserDataLength; //by Charge
	memcpy(SMSSubmit->RawData, (void *)&Packet[Offset], Size); //by Charge

    UserDataLength = DecodeUserDataSubmit(&(SMSSubmit->UserData),
    	(byte *)&Packet[Offset], UserDataLength, dcs, isContainHeader);

    if(tmpDataLength < 0)
        return tmpDataLength;

    Address_StructSetInOut(&(SMSSubmit->DestinationAddr),
        AddressValue, TypeOfNumber, NumberingPlanID, AddressLength, '\0');

    SMSSubmit_StructSetInOut(SMSSubmit, MessageTypeIndicator, RejectDuplicates,
        ValidityPeriodFormat, ReplyPath, udhi,
        StatusReportRequest, MessageReference, &(SMSSubmit->DestinationAddr),
        pid, dcs, ValidityPeriodRelative, &(SMSSubmit->ValidityPeriodAbsolute),
        ValidityPeriodEnhanced, UserDataLength, &(SMSSubmit->UserData), SMSSubmit->RawData);

    return sizeof(TSMSSubmit);
}


int EncodeSMSSubmit(byte *OutPacket, byte *InputStruct)
{
    int                  Offset;
    int                  Size = 0;

    byte MessageTypeIndicator;
    byte UserDataLength=0;
    byte FailureCause;
    byte pid, dcs, encode;
    byte udhi;
    boolean isContainHeader;
    byte RejectDuplicates;
    byte ValidityPeriodFormat;
    byte ReplyPath;
    byte StatusReportRequest;
    byte MessageReference;
    byte ValidityPeriodRelative;
    byte ValidityPeriodEnhanced[7];
    TTimeStamp ValidityPeriodAbsolute;
    byte TempValidityPeriod[20];
    byte TypeOfNumber, NumberingPlanID, AddressLength;
    byte AddressValue[100];
    int Year;
    byte Month, Day, Hour, Minute, Second, TimeZone;
    byte Temp[100];
    TSMSSubmit *SMSSubmit = (TSMSSubmit *)InputStruct;

    Address_StructGetInOut(&(SMSSubmit->DestinationAddr),
        AddressValue, &TypeOfNumber, &NumberingPlanID, &AddressLength, NULL);

    TimeStamp_StructGetInOut(&(SMSSubmit->ValidityPeriodAbsolute),
        &Year, &Month, &Day, &Hour, &Minute, &Second, &TimeZone);

    SMSSubmit_StructGetInOut(SMSSubmit, &MessageTypeIndicator,
        &RejectDuplicates, &ValidityPeriodFormat, &ReplyPath,
        &udhi, &StatusReportRequest,
        &MessageReference, NULL, &pid, &dcs,
        &ValidityPeriodRelative, NULL, ValidityPeriodEnhanced,
        &UserDataLength, NULL);

    if(SMSSubmit->UserData.udh.eiCnt == 0)
        udhi = 0;
    isContainHeader = udhi;

    memset(Temp, 0x0, sizeof(Temp));

    Offset = 0;
    OutPacket[Offset] = 0x01;
    OutPacket[Offset] = SetBits(OutPacket[Offset], 2, 1, RejectDuplicates);
    OutPacket[Offset] = SetBits(OutPacket[Offset], 3, 2, ValidityPeriodFormat);
    OutPacket[Offset] = SetBits(OutPacket[Offset], 7, 1, ReplyPath);
    OutPacket[Offset] = SetBits(OutPacket[Offset], 6, 1,
        udhi); 
    isContainHeader= udhi; 
    OutPacket[Offset] = SetBits(OutPacket[Offset], 5, 1, StatusReportRequest);
    Offset++;

    OutPacket[Offset++] = MessageReference;

    Size = EncodeAddress(&OutPacket[Offset], AddressLength, TypeOfNumber, 
                                                NumberingPlanID, AddressValue);
    Offset += Size;

    OutPacket[Offset++] = pid;

    OutPacket[Offset++] = dcs;

    encode = GetEncodeFromDcs(dcs);

    switch(ValidityPeriodFormat)
    {
        case TPDU_VPF_ENHANCED :
            Size = 7;
            memcpy(&OutPacket[Offset], ValidityPeriodEnhanced,  Size);
            break;

        case TPDU_VPF_RELATIVE :
            OutPacket[Offset] = ValidityPeriodRelative;
            Size = 1;
            break;

        case TPDU_VPF_ABSOLUTE :
            Size = 7;
            TimeStamp_StructGetInOut(&(SMSSubmit->ValidityPeriodAbsolute),
                &Year, &Month, &Day, &Hour, &Minute, &Second, &TimeZone);
            EncodeServiceCenterTimeStamp(&OutPacket[Offset], Year, Month, Day, 
                Hour, Minute, Second, (char)TimeZone); 
            break;

        case TPDU_VPF_NOT_PRESENT :        
            Size=0;
            break;

        default :
            return TPDU_DEC_ERR_VPF;
    }
    Offset += Size;

    UserDataLength = EncodeUserData(&OutPacket[Offset+1], 
        &(SMSSubmit->UserData), dcs, isContainHeader);
    OutPacket[Offset] = UserDataLength;

    return (encode == ENCODE_7BIT_GSM 
			|| encode == ENCODE_7BIT_ASCII
			|| Check7BitDCS(dcs) == ENCODE_7BIT_GSM)
           ? Offset + (UserDataLength*7+7)/8 +1
           : Offset + UserDataLength +1;
}


int DecodeSMSSubmitReport(byte *OutStruct, byte *Packet, int PacketSize, boolean isRPError)
{
    int Size=0;
    int Offset;
    byte MessageTypeIndicator;
    byte udhi;
    boolean isContainHeader;
    byte FailureCause;
    boolean isPIDPresent, isDCSPresent, isUDLPresent;
    int Year, Month, Day, Hour, Minute, Second, TimeZone;
    byte pid, dcs, encode;
    int UserDataLength=0;
    TSMSSubmitReport *SMSSubmitReport = (TSMSSubmitReport *)OutStruct;

    Offset=0;
    MessageTypeIndicator = GetBits(Packet[Offset], 0, 2);
    isContainHeader = udhi = GetBits(Packet[Offset], 6, 1);
    Offset++;

    if(isRPError)
        FailureCause = Packet[Offset++];

    isPIDPresent = GetBits(Packet[Offset], 0, 1);
    isDCSPresent = GetBits(Packet[Offset], 1, 1);
    isUDLPresent = GetBits(Packet[Offset], 2, 1);

    if(GetBits(Packet[Offset], 7, 1) == 1) 
        Offset++;

    Offset++;
    
    Size = DecodeServiceCenterTimeStamp((byte *)&Packet[Offset], 
                                        &Year, &Month, &Day, 
                                        &Hour, &Minute, &Second, &TimeZone);
    Offset += (Size+1)/2;

    if(isPIDPresent)
        pid = Packet[Offset++];

    if(isDCSPresent)
        dcs = Packet[Offset++];
    else
        dcs = 0x00;

    encode = GetEncodeFromDcs(dcs);

    if(isUDLPresent)
    {
        UserDataLength = Packet[Offset++];

#if 0
        if(UserDataLength > MAX_SIZE_TP_UD) 
            return TPDU_DEC_ERR_UDLMAX;
#endif

		if(UserDataLength > MAX_SIZE_TP_UD)
		{
			if(encode == ENCODE_7BIT_GSM 
					|| encode == ENCODE_7BIT_ASCII
					|| Check7BitDCS(dcs) == ENCODE_7BIT_GSM)
			{
				if(UserDataLength > MAX_SIZE_TP_UD + 20)
					return TPDU_DEC_ERR_IEL;
			}
			else
				return TPDU_DEC_ERR_UDLMAX;
		}

		Size = (encode == ENCODE_7BIT_GSM 
				|| encode == ENCODE_7BIT_ASCII 
				|| Check7BitDCS(dcs) == ENCODE_7BIT_GSM) ? (UserDataLength*7 +7)/8 : UserDataLength;
        if(Size != PacketSize-Offset)
            return TPDU_DEC_ERR_UDL;

        UserDataLength = DecodeUserData(&(SMSSubmitReport->UserData), 
            (byte *)&Packet[Offset], UserDataLength, dcs, isContainHeader);
        if(UserDataLength < 0)
            return UserDataLength;
    }

    Parameter_StructSetInOut(&(SMSSubmitReport->ParameterID),
        isPIDPresent, isDCSPresent, isUDLPresent);

    TimeStamp_StructSetInOut(&(SMSSubmitReport->TimeStamp),
        Year, Month, Day, Hour, Minute, Second, TimeZone);

    SMSSubmitReport_StructSetInOut(SMSSubmitReport, MessageTypeIndicator,
        udhi, FailureCause, &(SMSSubmitReport->ParameterID),
        &(SMSSubmitReport->TimeStamp), pid, dcs, UserDataLength, NULL);

    return sizeof(TSMSSubmitReport);
}


int EncodeSMSSubmitReport(byte *OutPacket, byte *InputStruct, boolean isRPError)
{
    int Offset;
    byte MessageTypeIndicator;
    byte udhi;
    boolean isContainHeader;
    byte FailureCause;
    boolean isPIDPresent, isDCSPresent, isUDLPresent;
    int Year;
    byte Month, Day, Hour, Minute, Second, TimeZone;
    byte pid, dcs, encode;
    byte UserDataLength=0;
    TSMSSubmitReport *SMSSubmitReport = (TSMSSubmitReport *)InputStruct;

    Parameter_StructGetInOut(&(SMSSubmitReport->ParameterID),
                        (int *)&isPIDPresent, //int *isPIDPresent
                        (int *)&isDCSPresent, //int *isDCSPresent
                        (int *)&isUDLPresent); //int *isUDLPresent);

    TimeStamp_StructGetInOut(&(SMSSubmitReport->TimeStamp),
                        &Year, //,int *Year
                        &Month, //,byte *Month
                        &Day, //,byte *Day
                        &Hour, //,byte *Hour
                        &Minute, //,byte *Min
                        &Second, //,byte *Sec
                        &TimeZone); //,byte *TimeZone);

    SMSSubmitReport_StructGetInOut(SMSSubmitReport,
                        &MessageTypeIndicator, //byte *MessageTypeID
                        &udhi, //byte *udhId
                        &FailureCause, //byte *FailureCause
                        NULL, //TParameter *ParameterID
                        NULL, //TTimeStamp *TimeStamp
                        &pid, //byte *ProtocolID
                        &dcs, //byte *DataCodingScheme
                        &UserDataLength, //byte *UserDataLength
                        NULL); //TUserData *UserData);

    Offset=0;
    OutPacket[Offset] = 0x01;

    if(SMSSubmitReport->UserData.udh.eiCnt == 0)
        udhi = 0;

    OutPacket[Offset] = SetBits(OutPacket[Offset], 6, 1,udhi);
    isContainHeader = udhi;
    Offset++;

    if(isRPError)
        OutPacket[Offset++] = FailureCause;

    OutPacket[Offset++] = EncodeParameterIndicator(isPIDPresent, 
        isDCSPresent, isUDLPresent);
    
    Offset += EncodeServiceCenterTimeStamp(&OutPacket[Offset], 
        Year, Month, Day, Hour, Minute, Second, (char)TimeZone); 

    if(isPIDPresent)
        OutPacket[Offset++] = pid; 

    if(isDCSPresent)
        OutPacket[Offset++] = dcs;

    encode = GetEncodeFromDcs(dcs);

    if(isUDLPresent)
    {
        UserDataLength = EncodeUserData(&OutPacket[Offset+1], 
            &(SMSSubmitReport->UserData), dcs, isContainHeader);
        OutPacket[Offset] = UserDataLength;
        
    }

    return (encode == ENCODE_7BIT_GSM 
			|| encode == ENCODE_7BIT_ASCII
			|| Check7BitDCS(dcs) == ENCODE_7BIT_GSM)
           ? Offset + (UserDataLength*7+7)/8 +1
           : Offset + UserDataLength +1;
}


int DecodeSMSStatusReport(byte *OutStruct, byte *Packet, int PacketSize)
{
    int                Size = 0;
    int                Offset;
    byte               MessageTypeIndicator, udhi;
    byte               MoreMessageToSend, StatusReortQualifier;
    byte               MessageReference;
    int                UserDataLength = 0;
    int                TypeOfNumber, NumberingPlanID, AddressLength;
    byte               AddressValue[100];
    int                Year, Month, Day, Hour, Minute, Second, TimeZone;
    int                Year2, Month2, Day2, Hour2, Minute2, Second2, TimeZone2;
    boolean            isPIDPresent, isDCSPresent, isUDLPresent;
    byte               pid, dcs, encode;
    byte               Status;
    boolean            isContainHeader;
    TSMSStatusReport  *SMSStatusReport = (TSMSStatusReport *)OutStruct;
    
    Offset = 0;
    MessageTypeIndicator  = GetBits(Packet[Offset], 0, 2);
    isContainHeader       = udhi 
                          = GetBits(Packet[Offset], 6, 1);
    MoreMessageToSend     = GetBits(Packet[Offset], 2, 1);
    StatusReortQualifier  = GetBits(Packet[Offset], 5, 1);
    Offset++;

    MessageReference = Packet[Offset++];
     
    Size = DecodeAddress((byte *)&Packet[Offset], &AddressLength, 
        &TypeOfNumber, &NumberingPlanID, AddressValue);
    if(Size < 0)
        return Size;

    Offset += ((Size+1)/2 +2);

    /* SeviceCentre TimeStamp */
    Size = DecodeServiceCenterTimeStamp((byte *)&Packet[Offset], 
                                &Year, &Month, &Day, 
                                &Hour, &Minute, &Second, &TimeZone);    
    Offset += (Size+1)/2;

    /* Discharge Time */
    Size = DecodeServiceCenterTimeStamp((byte *)&Packet[Offset], 
                                &Year2, &Month2, &Day2, 
                                &Hour2, &Minute2, &Second2, &TimeZone2);    
    Offset += (Size+1)/2;

    Status = Packet[Offset++];

    //Parameter Indicator
    isPIDPresent = GetBits(Packet[Offset], 0, 1);
    isDCSPresent = GetBits(Packet[Offset], 1, 1);
    isUDLPresent = GetBits(Packet[Offset], 2, 1);

    if(GetBits(Packet[Offset], 7, 1) == 1) 
        Offset++;

    Offset++;

    if(isPIDPresent)
        pid = Packet[Offset++];
    else
        pid = 0x00;

    if(isDCSPresent)
        dcs = Packet[Offset++];
    else
        dcs = 0x00;

    encode = GetEncodeFromDcs(dcs);

    if(isUDLPresent)
    {
        UserDataLength = Packet[Offset++];

#if 0
        if(UserDataLength > MAX_SIZE_TP_UD) 
            return TPDU_DEC_ERR_UDLMAX;
#endif

		if(UserDataLength > MAX_SIZE_TP_UD)
		{
			if(encode == ENCODE_7BIT_GSM 
					|| encode == ENCODE_7BIT_ASCII
					|| Check7BitDCS(dcs) == ENCODE_7BIT_GSM)
			{
				if(UserDataLength > MAX_SIZE_TP_UD + 20)
					return TPDU_DEC_ERR_IEL;
			}
			else
				return TPDU_DEC_ERR_UDLMAX;
		}

		Size = (encode == ENCODE_7BIT_GSM 
				|| encode == ENCODE_7BIT_ASCII 
				|| Check7BitDCS(dcs) == ENCODE_7BIT_GSM) ? (UserDataLength*7 +7)/8 : UserDataLength;
        if(Size != PacketSize-Offset)
            return TPDU_DEC_ERR_UDL;

        UserDataLength = DecodeUserData(&(SMSStatusReport->UserData), 
            (byte *)&Packet[Offset], UserDataLength, dcs, isContainHeader);

        if(UserDataLength < 0)
            return UserDataLength;
    }

    Address_StructSetInOut(&(SMSStatusReport->RecipientAddr), AddressValue,
        TypeOfNumber, NumberingPlanID, AddressLength, '\0');

    TimeStamp_StructSetInOut(&(SMSStatusReport->TimeStamp),
        Year, Month, Day, Hour, Minute, Second, TimeZone);
    
    TimeStamp_StructSetInOut(&(SMSStatusReport->DischargeTime),
        Year2, Month2, Day2, Hour2, Minute2, Second2, TimeZone2);

    Parameter_StructSetInOut(&(SMSStatusReport->ParameterID),
        isPIDPresent, isDCSPresent, isUDLPresent);

    SMSStatusReport_StructSetInOut(SMSStatusReport, MessageTypeIndicator,
        udhi, MoreMessageToSend, StatusReortQualifier,
        MessageReference, &(SMSStatusReport->RecipientAddr),
        &(SMSStatusReport->TimeStamp), &(SMSStatusReport->DischargeTime),
        Status, &(SMSStatusReport->ParameterID), pid, dcs, UserDataLength,
        &(SMSStatusReport->UserData));

    return sizeof(TSMSStatusReport);
}


int EncodeSMSStatusReport(byte *OutPacket, byte *InputStruct)
{
    int Size = 0;
    int Offset;
    byte MessageTypeIndicator;
    byte udhi;
    byte MoreMessageToSend;
    byte StatusReortQualifier;
    byte MessageReference;
    byte UserDataLength = 0;
    byte TypeOfNumber, NumberingPlanID, AddressLength;
    byte AddressValue[100];
    int Year;
    byte Month, Day, Hour, Minute, Second, TimeZone;
    int Year2;
    byte Month2, Day2, Hour2, Minute2, Second2, TimeZone2;
    boolean isPIDPresent, isDCSPresent, isUDLPresent;
    byte pid, dcs, encode;
    byte Status;
    boolean isContainHeader;
    TSMSStatusReport *SMSStatusReport = (TSMSStatusReport *)InputStruct;
    
    Address_StructGetInOut(&(SMSStatusReport->RecipientAddr),
        AddressValue, &TypeOfNumber, &NumberingPlanID, &AddressLength, NULL);

    TimeStamp_StructGetInOut(&(SMSStatusReport->TimeStamp),
        &Year, &Month, &Day, &Hour, &Minute, &Second, &TimeZone);
    
    TimeStamp_StructGetInOut(&(SMSStatusReport->DischargeTime),
        &Year2, &Month2, &Day2, &Hour2, &Minute2, &Second2, &TimeZone2);

    Parameter_StructGetInOut(&(SMSStatusReport->ParameterID),
        (int *)&isPIDPresent, (int *)&isDCSPresent, (int *)&isUDLPresent);

    SMSStatusReport_StructGetInOut(SMSStatusReport, &MessageTypeIndicator,
        &udhi, &MoreMessageToSend, &StatusReortQualifier,
        &MessageReference, NULL, NULL, NULL, &Status, NULL, &pid,
        &dcs, &UserDataLength, NULL);

    Offset = 0;
    OutPacket[Offset] = 0x02;

    if(SMSStatusReport->UserData.udh.eiCnt == 0)
        udhi = 0;

    OutPacket[Offset] = SetBits(OutPacket[Offset], 6, 1, udhi); 
    isContainHeader = udhi;
    OutPacket[Offset] = SetBits(OutPacket[Offset], 2, 1, MoreMessageToSend);
    OutPacket[Offset] = SetBits(OutPacket[Offset], 5, 1, StatusReortQualifier);
    Offset++;

    OutPacket[Offset++] = MessageReference;

    Size = EncodeAddress(&OutPacket[Offset], AddressLength, TypeOfNumber,
        NumberingPlanID, AddressValue);
    Offset += Size;
    Offset += EncodeServiceCenterTimeStamp(&OutPacket[Offset], 
        Year, Month, Day, Hour, Minute, Second, (char)TimeZone);  

    //DischargeTime
    Offset += EncodeServiceCenterTimeStamp(&OutPacket[Offset], 
        Year2, Month2, Day2, Hour2, Minute2, Second2, (char)TimeZone2);

    OutPacket[Offset++] = Status;
    OutPacket[Offset++] = EncodeParameterIndicator(isPIDPresent, 
        isDCSPresent, isUDLPresent);
        
    if(isPIDPresent)
        OutPacket[Offset++] = pid; 

    if(isDCSPresent)
        OutPacket[Offset++] = dcs; 

    dcs = GetEncodeFromDcs(dcs);

    if(isUDLPresent)
    {
        UserDataLength = EncodeUserData(&OutPacket[Offset+1], 
            &(SMSStatusReport->UserData), dcs, isContainHeader);
        OutPacket[Offset] = UserDataLength;
    }

    return (encode == ENCODE_7BIT_GSM 
			|| encode == ENCODE_7BIT_ASCII
			|| Check7BitDCS(dcs) == ENCODE_7BIT_GSM)
        ? Offset + (UserDataLength*7+7)/8 +1
        : Offset + UserDataLength +1;
}


int DecodeSMSCommand(byte *OutStruct, byte *Packet, int PacketSize)
{
    int              Size = 0;
    int              Offset;
    byte             MessageTypeIndicator;
    byte             udhi;
    boolean          isContainHeader;
    byte             StatusReportRequest;
    byte             MessageReference;
    byte             pid;
    byte             CommandType;
    byte             MessageNumber;
    int              TypeOfNumber, NumberingPlanID, AddressLength;
    byte             AddressValue[100];
    byte             CommandDataLength = 0;
    TSMSCommand     *SMSCommand = (TSMSCommand *)OutStruct;
    
    Offset = 0;
    MessageTypeIndicator = GetBits(Packet[Offset], 0, 2);
    isContainHeader = udhi = GetBits(Packet[Offset], 6, 1);
    StatusReportRequest = GetBits(Packet[Offset], 5, 1);
    Offset++;

    MessageReference   = Packet[Offset++];
    pid = Packet[Offset++];
    CommandType        = Packet[Offset++];
    MessageNumber      = Packet[Offset++];

    Size = DecodeAddress((byte *)&Packet[Offset], &AddressLength, 
        &TypeOfNumber, &NumberingPlanID, AddressValue);
    if(Size < 0)
        return Size;
    Offset += ((Size+1)/2 +2);

    CommandDataLength = Packet[Offset++];
    memcpy(&(SMSCommand->CommandData), &Packet[Offset], CommandDataLength);

    Address_StructSetInOut(&(SMSCommand->DestinationAddr),
        AddressValue,                       //,byte min[20]
        TypeOfNumber,                       //,byte *ton
        NumberingPlanID,                    //,byte *npi
        AddressLength,                      //,byte *len
        '\0');                              //,byte *reserved);

    SMSCommand_StructSetInOut(SMSCommand,
        MessageTypeIndicator,               //byte *MessageTypeID
        udhi,            //byte *udhId
        StatusReportRequest,                //byte *StatusReportRequest
        MessageReference,                   //byte *MessageReference
        pid,                                //byte *ProtocolID
        CommandType,                        //byte *CommandType
        MessageNumber,                      //byte *MessageNumber
        &(SMSCommand->DestinationAddr),     //TAddress *DestinationAddr
        CommandDataLength,                  //byte *CommandDataLength
        SMSCommand->CommandData);           //byte CommandData[157]);

    return sizeof(TSMSCommand);
}


int EncodeSMSCommand(byte *OutPacket, byte *InputStruct)
{
    int Size=0;
    int Offset;
    byte MessageTypeIndicator;
    byte udhi;
    boolean isContainHeader;
    byte StatusReportRequest;
    byte MessageReference;
    byte pid;
    byte CommandType;
    byte MessageNumber;
    byte TypeOfNumber, NumberingPlanID, AddressLength;
    byte AddressValue[100];
    byte CommandDataLength=0;

    TSMSCommand *SMSCommand = (TSMSCommand *)InputStruct;
    
    Address_StructGetInOut(&(SMSCommand->DestinationAddr),
                    AddressValue, //,byte min[20]
                    &TypeOfNumber, //,byte *ton
                    &NumberingPlanID, //,byte *npi
                    &AddressLength, //,byte *len
                    NULL); //,byte *reserved);

    SMSCommand_StructGetInOut(SMSCommand,
                    &MessageTypeIndicator, //byte *MessageTypeID
                    &udhi, //byte *udhId
                    &StatusReportRequest, //byte *StatusReportRequest
                    &MessageReference, //byte *MessageReference
                    &pid, //byte *pid
                    &CommandType, //byte *CommandType
                    &MessageNumber, //byte *MessageNumber
                    NULL, //TAddress *DestinationAddr
                    &CommandDataLength, //byte *CommandDataLength
                    NULL); //byte CommandData[157]);

    Offset=0;
    OutPacket[Offset] = 0x02; //SetBits(OutPacket[Offset], 0, 2, MessageTypeIndicator);
    OutPacket[Offset] = SetBits(OutPacket[Offset], 6, 1,udhi);
    isContainHeader=udhi;
    OutPacket[Offset] = SetBits(OutPacket[Offset], 5, 1, StatusReportRequest);
    Offset++;

    OutPacket[Offset++] = MessageReference;
    OutPacket[Offset++] = pid;
    OutPacket[Offset++] = CommandType;
    OutPacket[Offset++] = MessageNumber;

    Size = EncodeAddress(&OutPacket[Offset], AddressLength, TypeOfNumber, 
                        NumberingPlanID, AddressValue);    //DestinationAddress
    Offset += Size;
    
    memcpy(&OutPacket[Offset+1], &(SMSCommand->CommandData), CommandDataLength);
    OutPacket[Offset] = CommandDataLength;
    return Offset + CommandDataLength +1;
}

int seeTpdu(_TPDU *tpdu, char *str)
{
	printTpdu(tpdu, str);
	return IXOK;
}
