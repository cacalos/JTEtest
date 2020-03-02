#include <iXCauseCode.h>
#include <RPDU/rpdu_err.h>
#include <iXtypes.h>

int IsNotSuppAsciiToGsm(unsigned char code)
{
    if( (0x00 < code && code  < 0x20) ||
         0x7f < code)
        return IXOK;
    else
        return IXERR;
}

int ConvRpErrToCauseCode(unsigned char rpErrCode)
{
    switch(rpErrCode)
    {
        case RP_UNASSIGNED_NUMBER :
            return CC_RP_UNASSIGNED_NUMBER;
        case RP_OPERATOR_DETERMINED_BARRING :
            return CC_RP_OPERATOR_DETERMINED_BARRING;
        case RP_CALL_BARRED :
            return CC_RP_CALL_BARRED;
        case RP_RESERVED :
            return CC_RP_RESERVED;
        case RP_SM_TRANSFER_REJECTED :
            return CC_RP_SM_TRANSFER_REJECTED;
        case RP_MEMORY_CAPACITY_EXCEEDED :
            return CC_RP_MEMORY_CAPACITY_EXCEEDED;
        case RP_DESTINATION_OUT_OF_ORDER :
            return CC_RP_DESTINATION_OUT_OF_ORDER;
        case RP_UNIDENTIFIED_SUBSCRIBER :
            return CC_RP_UNIDENTIFIED_SUBSCRIBER;
        case RP_FACILITY_REJECTED :
            return CC_RP_FACILITY_REJECTED;
        case RP_UNKNOWN_SUBSCRIBER :
            return CC_RP_UNKNOWN_SUBSCRIBER;
        case RP_NETWORK_OUT_OF_ORDER :
            return CC_RP_NETWORK_OUT_OF_ORDER;
        case RP_TEMPORARY_FAILURE :
            return CC_RP_TEMPORARY_FAILURE;
        case RP_CONGESTION :
            return CC_RP_CONGESTION;
        case RP_RESOURCES_UNAVAILABLE :
            return CC_RP_RESOURCES_UNAVAILABLE;
        case RP_REQUESTED_FACILITY_NOT_SUBSCRIBE :
            return CC_RP_REQUESTED_FACILITY_NOT_SUBSCRIBE;
        case RP_REQUESTED_FACILITY_NOT_IMPLEMENTED :
            return CC_RP_REQUESTED_FACILITY_NOT_IMPLEMENTED;
        case RP_INVALID_SM_TRANSFER_REFERENCE_VALUE :
            return CC_RP_INVALID_SM_TRANSFER_REF_VALUE;
        case RP_SEMANTICALLY_INCORRECT_MESSAGE :
            return CC_RP_SEMANTICALLY_INCORRECT_MESSAGE;
        case RP_INVALID_MANDATORY_INFORMATION :
            return CC_RP_INVALID_MANDATORY_INFORMATION;
        case RP_MESSAGE_TYPE_NON_EXISTENT :
            return CC_RP_MESSAGE_TYPE_NON_EXISTENT;
        case RP_MESSAGE_NOT_COMPATIBLE :
            return CC_RP_MESSAGE_NOT_COMPATIBLE;
        case RP_INFORMATION_ELEMENT_NON_EXISTENT :
            return CC_RP_INFO_ELEMENT_NON_EXISTENT;
        case RP_PROTOCOL_ERROR_UNSPECIFIED :
            return CC_RP_PROTOCOL_ERROR_UNSPECIFIED;
        case RP_INTERWORKING_UNSPECIFIED :
            return CC_RP_INTERWORKING_UNSPECIFIED;
        default :
			return CC_RP_PROTOCOL_ERROR_UNSPECIFIED;
	}
}

int GetRPErrorCauseCode(int cc)
{
    switch(cc)
    {
		case CC_INVALID_SME_ADDR :
			return RP_UNIDENTIFIED_SUBSCRIBER;
		case CC_NOT_SC_SUBSCRIBER :
			return RP_UNKNOWN_SUBSCRIBER;
		case CC_SC_CONGESTION :
			return RP_CONGESTION;
        case CC_RP_CALL_BARRED :
            return RP_CALL_BARRED;
        default :
            return RP_PROTOCOL_ERROR_UNSPECIFIED;
    }
}

unsigned char GetEncodeFromDcs(unsigned char dcs)
{
	unsigned char               encode_type;
	char                        codingGroup;
	char                        alpha;

	/* ?¸ì?¨ë??¸ì¦?*/
	if (dcs >= 0xF0 && dcs < 0xF8)
		return ENCODE_FOREIGN;

	codingGroup = (dcs & 0xF0) >> 4;

	switch(codingGroup)
	{
		case 0 :
		case 1 :
		case 3 :
		case 4 :
		case 5 :
		case 6 :
		case 7 :
			alpha = (dcs & 0x0C) >> 2;
			if(alpha == 0)
				encode_type = ENCODE_7BIT_GSM;
			else if(alpha == 1)
				encode_type = ENCODE_8BIT;
			else if(alpha == 2)
				encode_type = ENCODE_UCS2;
			else if(alpha == 3)
				encode_type = ENCODE_KSC5601;
			else
				encode_type = ENCODE_7BIT_GSM;
			break;
		case 2 :
			//?¤제로? COMP?´나 초ê개발 ?¤수로 UNCOMP로 ? ?¹í
			if(dcs == 40) /* UCS2_COMPRESS  0010 1000 */
				encode_type = ENCODE_UCS2_UNCOMP;
			else
				encode_type = ENCODE_7BIT_GSM;
			break;

		case 8 :
		case 9 :
		case 10 :
		case 11 :
		case 12 :
		case 13 :
			encode_type = ENCODE_7BIT_GSM;
			break;

		case 14 :
			encode_type = ENCODE_UCS2;
			break;
		case 15 :
			alpha = (dcs & 0x04) >> 2;
			if(alpha == 0)
				encode_type = ENCODE_7BIT_GSM;
			else
				encode_type = ENCODE_8BIT;
			break;
	}

	return encode_type;
}

int Conv7BitASCto7BitGSM2(char *origData, unsigned char origDataLen, char *newData, short *newDataLen)
{
	int          i, j;

	for (i = 0, j = 0; i < origDataLen; i++)
	{
		if (origData[i] == 0x40)                  /* @ */
			newData[j++] = 0x00;
		else if (origData[i] == 0x24)             /* $ */
			newData[j++] = 0x02;
		else if (origData[i] == 0x5F)             /* _ */
			newData[j++] = 0x11;
		else if (origData[i] == 0x5B)             /* [ */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x3C;
		}
		else if (origData[i] == 0x5C)             /* \ */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x2F;
		}
		else if (origData[i] == 0x5D)             /* ] */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x3E;
		}
		else if (origData[i] == 0x5E)             /*  ^ */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x14;
		}
		else if (origData[i] == 0x7B)             /* { */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x28;
		}
		else if (origData[i] == 0x7C)             /* | */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x40;
		}
		else if (origData[i] == 0x7D)             /* } */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x29;
		}
		else if (origData[i] == 0x7E)             /* ~ */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x3D;
		}
		else if( IsNotSuppAsciiToGsm((unsigned char)origData[i]) == IXOK )  // R.3.9.0  ASCII -> GSM  지??지 ?? 문자??경ì?¤페?´ì처ë

		{
			if(origData[i] == 0x0A || origData[i] == 0x0D)
				newData[j++] = origData[i];
			else
				newData[j++] = 0x20;
		}
		else
			newData[j++] = origData[i];
	}

	*newDataLen = j;

	return IXOK;
}


int ConvStrToBCD(char *str, int strLen, char *bcd, int *bcdLen)
{
    int             i, j;
    char            ch;

    for(i = 0, j = 0; i < strLen; j++)
    {
        bcd[j] = (str[i++] - '0') & 0x0F;
        if(i >= strLen)
            bcd[j] |= 0xF0;
        else
            bcd[j] |= ((str[i++] - '0') << 4);
    }
    *bcdLen = j;

    return IXOK;
}

int ConvBCDtoStr(char *bcd, int bcdLen, char *str, int *strLen)
{
    int            i, j;
    char           ch;

    j = 0;
    for(i = 0; i < bcdLen; i++)
    {
        ch = (bcd[i] & 0x0F) + '0';
        str[j++] = ch;
        ch = (bcd[i] >> 4)&0x0F;
        if(ch == 0x0F)
            break;
        ch += '0';
        str[j++] = ch;
    }
    str[j] = 0;
    *strLen = j;

    return IXOK;
}

int Decode7BitPackNew(const unsigned char* pSrc, char* pDst, int nSrcLength)
{
    int nSrc;
    int nDst;
    int nByte;
    int nLength=0;
    unsigned char nLeft;
    char *pStart = pDst;

    nSrc = 0;
    nDst = 0;

    nByte = 0;
    nLeft = 0;

    nLength = (nSrcLength+1)/2;
    while(nSrc<nLength)
    {
        *pDst = ((*pSrc << nByte) | nLeft) & 0x7f;
        nLeft = *pSrc >> (7-nByte);

        pDst++;
        nDst++;
        nByte++;

        if(nByte == 7)
        {
            *pDst = nLeft;

            pDst++;
            nDst++;

            nByte = 0;
            nLeft = 0;
        }

        pSrc++;
        nSrc++;
    }

    *pDst = '\0';
    return strlen(pStart);
}

unsigned char Check7BitDCS(unsigned char dcs)
{
	unsigned char               encode;
	char                        alpha;

	if(dcs < 0xF0 || dcs >= 0xF8)
		return ENCODE_UNKNOWN;

	alpha = (dcs & 0x0C) >> 2;

	if(alpha == 0)
		encode = ENCODE_7BIT_GSM;
	else if(alpha == 1)
		encode = ENCODE_8BIT;
	else
		return ENCODE_UNKNOWN;

	return encode;
}

int Conv7BitASCto7BitGSM(char *origData, unsigned char origDataLen, char *newData, unsigned char *newDataLen)
{
	int i,j;

	for(i=0, j=0; i<origDataLen; i++)
	{
		if (origData[i] == 0x40)                  /* @ */
			newData[j++] = 0x00;
		else if (origData[i] == 0x24)             /* $ */
			newData[j++] = 0x02;
		else if (origData[i] == 0x5F)             /* _ */
			newData[j++] = 0x11;
		else if (origData[i] == 0x5B)             /* [ */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x3C;
		}
		else if (origData[i] == 0x5C)             /* \ */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x2F;
		}
		else if (origData[i] == 0x5D)             /* ] */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x3E;
		}
		else if (origData[i] == 0x5E)             /*  ^ */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x14;
		}
		else if (origData[i] == 0x7B)             /* { */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x28;
		}
		else if (origData[i] == 0x7C)             /* | */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x40;
		}
		else if (origData[i] == 0x7D)             /* } */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x29;
		}
		else if (origData[i] == 0x7E)             /* ~ */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x3D;
		}
		else if( IsNotSuppAsciiToGsm((unsigned char)origData[i]) == IXOK )  // R.3.9.0  ASCII -> GSM  지??지 ?? 문자??경ì?¤페?´ì처ë
		{
			if(origData[i] == 0x0A || origData[i] == 0x0D)
				newData[j++] = origData[i];
			else
				newData[j++] = 0x20;
		}
		else
			newData[j++] = origData[i];
	}

	*newDataLen = j;

	return IXOK;
}

#if 0
int Conv7BitASCto7BitGSM(char *origData, unsigned int origDataLen,
        char *newData, unsigned int *newDataLen)
{
    int          i, j;

    for (i = 0, j = 0; i < origDataLen; i++)
    {
        if (origData[i] == 0x40)                  /* @ */
			newData[j++] = 0x00;
		else if (origData[i] == 0x24)             /* $ */
			newData[j++] = 0x02;
		else if (origData[i] == 0x5F)             /* _ */
			newData[j++] = 0x11;
		else if (origData[i] == 0x5B)             /* [ */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x3C;
		}
		else if (origData[i] == 0x5C)             /* \ */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x2F;
		}
		else if (origData[i] == 0x5D)             /* ] */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x3E;
		}
		else if (origData[i] == 0x5E)             /*  ^ */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x14;
		}
		else if (origData[i] == 0x7B)             /* { */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x28;
		}
		else if (origData[i] == 0x7C)             /* | */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x40;
		}
		else if (origData[i] == 0x7D)             /* } */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x29;
		}
		else if (origData[i] == 0x7E)             /* ~ */
		{
			newData[j++] = 0x1B;
			newData[j++] = 0x3D;
		}
		else if(IsNotSuppAsciiToGsm((unsigned char)origData[i]) == IXOK)
		{
			if(origData[i] == 0x0A || origData[i] == 0x0D)
				newData[j++] = origData[i];
			else
				uaLog(L_INFO ,"Unsupported char %x", origData[i] );
		}
		else
			newData[j++] = origData[i];
	}

	*newDataLen = j;

	return IXOK;
}
#endif

