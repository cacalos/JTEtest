
#include <time.h>
#include <RPDU/BitUtil.h>
#include <RPDU/RPDU.h>
#include <RPDU/RPDU.h>
#include <ua_log.h>
#include <iXtypes.h>


char GetRPDUMessageType(byte *Packet, int nFrom)    
{
    int          Type, subType;
    
    Type = GetBits(Packet[0], 0, 3);

    switch(Type)
    {
        case 0: //000
            Type = (nFrom == DIRECTION_MS_N) ? RPDU_RP_DATA 
                : RPDU_RP_RESERVED;
            break;

        case 1: //001
            Type =  (nFrom == DIRECTION_MS_N) ? RPDU_RP_RESERVED 
                : RPDU_RP_DATA;
            break;

        case 2: //010
            Type =  (nFrom == DIRECTION_MS_N) ? RPDU_RP_ACK 
                : RPDU_RP_RESERVED;
            break;

        case 3: //011
            Type =  (nFrom == DIRECTION_MS_N) ? RPDU_RP_RESERVED 
                : RPDU_RP_ACK;
            break;

        case 4: //100
            Type =  (nFrom == DIRECTION_MS_N) ? RPDU_RP_ERROR 
                : RPDU_RP_RESERVED;
            break;

        case 5: //101
            Type =  (nFrom == DIRECTION_MS_N) ? RPDU_RP_RESERVED 
                : RPDU_RP_ERROR;
            break;

        case 6: //110
            Type =  (nFrom == DIRECTION_MS_N) ? RPDU_RP_SMMA 
                : RPDU_RP_RESERVED;
            break;

        default :
            Type = -1;
            break;
    }

    return Type;
}

int EncodeRpAddress(byte *EncodingData, int AddressLength, int TypeOfNumber,
		int NumberingPlanID, byte *AddressValue)
{
	int 	len, fillCnt;
	char	bitSh;

	if(TypeOfNumber == TON_ALPHA_NUMERIC)
	{
		len = Encode7BitPack((byte *)AddressValue, &EncodingData[2], 0, AddressLength);

		bitSh = EncodingData[(2) + (len-1)] >> 4;

		if(bitSh == 0X00)
			fillCnt = 1;
		EncodingData[0] = AddressLength+1;
	}
	else
	{
		ConvStrToBCD((byte *)AddressValue, AddressLength, &EncodingData[2], &len);
		EncodingData[0] = len+1;
	}

	EncodingData[1] = (SetBits(0, 7, 1, 1)
			| SetBits(0, 4, 3, TypeOfNumber)
			| SetBits(0, 0, 4, NumberingPlanID));

	return len + 2;
}

int DecodeRpAddress(byte *EncodedData, int *AddressLength, int *TypeOfNumber,
                  int *NumberingPlanID, byte *AddressValue)
{
    int          i, len = 0, charLen = 0;

    *TypeOfNumber    = GetBits(EncodedData[1], 4, 3);
    *NumberingPlanID = GetBits(EncodedData[1], 0, 4);

    if(EncodedData[0] > 20)
        return TPDU_DEC_ERR_ADDRLEN;

	len = EncodedData[0];

	if( *TypeOfNumber == TON_ALPHA_NUMERIC )
	{
		*AddressLength = Decode7BitPackNew(&EncodedData[2], AddressValue, EncodedData[0]);
		charLen = (EncodedData[0]+1)/2 + 2;

		uaLog(L_INFO,"ton:%d, npi:%d, len:%d Encode[0]:%d" ,  *TypeOfNumber  , *NumberingPlanID, charLen, *AddressLength);

		return charLen;
		
	}
	else 
	{
		ConvBCDtoStr(&EncodedData[2], len-1, AddressValue, AddressLength);
		return len+1;
	}
}

int DecodeRPDU(_RPDU *rpdu, byte *Packet, int PacketSize, int nFrom)
{
    int               size = -1;

    bzero((void *)rpdu, sizeof(_RPDU));

	rpdu->direction = nFrom;
    rpdu->MessageType = GetRPDUMessageType(Packet, nFrom);
	rpdu->MessageReference = Packet[1];
    
    switch(rpdu->MessageType)
    {
		case RPDU_RP_DATA :
			size = DecodeRpData((byte *)&(rpdu->Union.rData), nFrom, Packet, PacketSize);
            break ;

		case RPDU_RP_ACK :
			size = DecodeRpAck((byte *)&(rpdu->Union.rAck), nFrom, Packet, PacketSize);
			break;
                
		case RPDU_RP_ERROR :
			size = DecodeRpError((byte *)&(rpdu->Union.rError), nFrom, Packet, PacketSize);
			break;

		case RPDU_RP_SMMA :
			size = 0;
			break;

        default :
            size = -1;
            break;
    }
    
    return size;
}

int DecodeRpData(RpData *rData, int nFrom, byte *Packet, int PacketSize)
{
	byte			   	AddressValue[64];
	int              	TypeOfNumber, NumberingPlanID, AddressLength;
	byte				userDataLength = 0;
	int					offset;
	int					Size = 0;

	offset = 2;

	if(nFrom == DIRECTION_MS_N) // MO인 경우 Orig는 NULL
	{
		offset++;
		Size = DecodeRpAddress((byte *)&Packet[offset], &AddressLength,
				&TypeOfNumber, &NumberingPlanID, AddressValue);
		if(Size < 0)
			return Size;
		offset += Size;
	}
	else // MT인 경우 Dest는 NULL
	{
		Size = DecodeRpAddress((byte *)&Packet[offset], &AddressLength,
				&TypeOfNumber, &NumberingPlanID, AddressValue);
		if(Size < 0)
			return Size;
		offset += Size;
		offset++;
	}

	userDataLength = rData->RpDataLength = Packet[offset++];
	memcpy(&(rData->RpUserData), &Packet[offset], userDataLength);

	if(nFrom == DIRECTION_MS_N)
	{
		Address_StructSetInOut(&(rData->DestAddr),
				AddressValue,                       //,byte min[20]
				TypeOfNumber,                       //,byte *ton
				NumberingPlanID,                    //,byte *npi
				AddressLength,                      //,byte *len
				'\0');                              //,byte *reserved);
	}
	else
	{
		Address_StructSetInOut(&(rData->OrigAddr),
				AddressValue,                       //,byte min[20]
				TypeOfNumber,                       //,byte *ton
				NumberingPlanID,                    //,byte *npi
				AddressLength,                      //,byte *len
				'\0');                              //,byte *reserved);
	}

	return sizeof(RpData);
}

int DecodeRpAck(RpAck *rAck, int nFrom, byte *Packet, int PacketSize)
{
	int					offset;
	byte				userDataLength = 0;

	offset = 2;
	if(PacketSize > 2)
	{
		rAck->ElementId = Packet[offset++];
		userDataLength = rAck->RpDataLength = Packet[offset++];
		memcpy(&(rAck->RpUserData), &Packet[offset], userDataLength);
	}

	return sizeof(RpAck);
}


int DecodeRpError(RpError *rError, int nFrom, byte *Packet, int PacketSize)
{
	int					offset, len, errLen = 0, cc = 0;
	byte				userDataLength = 0;


	offset = 2;

	/* Deleted by dduckk, R202, 20151013 */
	//rError->CauseCode.ElementId = Packet[offset++];
	rError->CauseCode.len = errLen = Packet[offset++];
	rError->CauseCode.cause = Packet[offset++];
	if(errLen > 1)
	{
		rError->CauseCode.diagnostic = Packet[offset++];	
	}

	if(PacketSize > offset)
	{
		/* Added by dduckk, R210, 20160303, ElementID 추가 */
		rError->ElementId = Packet[offset++];
		userDataLength = rError->RpDataLength = Packet[offset++];
		memcpy(&(rError->RpUserData), &Packet[offset], userDataLength);
	}

	return sizeof(RpError);
}


int EncodeRPDU(byte *Packet, _RPDU *rpdu, boolean isRPError)
{
	int				len, Size = -1;
	int				offset = 0;

	Packet[offset++] = EncodeMessageTypeIndicator(rpdu->direction, rpdu->MessageType);
	Packet[offset++] = rpdu->MessageReference;

	if(rpdu->MessageType == RPDU_RP_DATA)
	{
		if(rpdu->direction == DIRECTION_MS_N) // MO인 경우 Orig는 NULL
		{
			offset++;
			len = EncodeRpAddress(&Packet[offset], rpdu->Union.rData.DestAddr.len, rpdu->Union.rData.DestAddr.ton, 
					rpdu->Union.rData.DestAddr.npi, rpdu->Union.rData.DestAddr.min);
			offset += len;
		}
		else
		{
			len = EncodeRpAddress(&Packet[offset], rpdu->Union.rData.OrigAddr.len, rpdu->Union.rData.OrigAddr.ton, 
					rpdu->Union.rData.OrigAddr.npi, rpdu->Union.rData.OrigAddr.min);
			offset += len;
			offset++;	// Dest
		}

		Packet[offset++] = rpdu->Union.rData.RpDataLength;
		memcpy(&Packet[offset], rpdu->Union.rData.RpUserData, rpdu->Union.rData.RpDataLength);
		offset += rpdu->Union.rData.RpDataLength;
		Size = offset;
	}
	else if(rpdu->MessageType == RPDU_RP_ACK)
	{
		/* Modified by dduckk, R210, 20160303, RP-Data-Length가 있을 때 설정하도록 변경 */
		if(rpdu->Union.rAck.RpDataLength > 0){
			Packet[offset++] = rpdu->Union.rAck.ElementId;
			Packet[offset++] = rpdu->Union.rAck.RpDataLength;
			memcpy(&Packet[offset], rpdu->Union.rAck.RpUserData, rpdu->Union.rAck.RpDataLength);
			offset += rpdu->Union.rAck.RpDataLength;
		}
		Size = offset;
	}
	else if(rpdu->MessageType == RPDU_RP_ERROR)
	{
		/* Deleted by dduckk, R202, 20151013 */
		//Packet[offset++] = rpdu->Union.rError.CauseCode.ElementId;
		Packet[offset++] = rpdu->Union.rError.CauseCode.len;
		Packet[offset++] = rpdu->Union.rError.CauseCode.cause;
		if(rpdu->Union.rError.CauseCode.len == 2)
			Packet[offset++] = rpdu->Union.rError.CauseCode.diagnostic;
		Size = offset;
	}
	else if(rpdu->MessageType == RPDU_RP_SMMA)
	{
		Size = offset;
	}
	else
	{
		uaLog(L_CRT, "Messge Type is Unknown(%d)", rpdu->MessageType);
		Size = -1;
	}

	return Size;
}

int EncodeMessageTypeIndicator(int direction, char type)
{
	char value = 0;

	switch(type)
	{
		case RPDU_RP_DATA :
			if(direction == DIRECTION_MS_N)
				value = 0;
			else
				value = 1;
			break;
		case RPDU_RP_ACK :
			if(direction == DIRECTION_MS_N)
				value = 2;
			else
				value = 3;
			break;
		case RPDU_RP_ERROR :
			if(direction == DIRECTION_MS_N)
				value = 4;
			else
				value = 5;
			break;
		case RPDU_RP_SMMA :
			value = 6;
			break;
		default :
			uaLog(L_CRT, "RP_DATA Type is Unknwon(%d)", type);
			value = 7;
			break;
	}

	return value;
}



