

//#include <ainCommon.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
//#include <TCAP_ccitt.h>
//#include <TCAP_errors.h>

#include <iXtypes.h>
//#include <iXMoQ.h>
#include <SS7/ix7map.h>
#include <SS7/map2.h>


/* TCAP string을 분석하여 하나의 parameter의                          */
/* tag code값, parameter길이, parameter값(contents)을 구한다.         */
/*                                                                    */
/* tag code는 확장된 것 같이 분석할 수 있다.                          */
/* 단 tag code의 최대 길이는 4이다.  그 이상일 때는 error로 처리한다. */
/*                                                                    */
/* return : 분석한 string의 길이. tag code part, para length part,    */
/*    para contents part의길이 전체를 합한 값.                        */
/*    분석한 값을 "result"에 담아준다.                                */

int getOnePara(unsigned char *str, stOnePara *result)
{
    int                tag_code=0, tag_code_len, para_len;
    unsigned char     *ptr;
    unsigned char      ESN[4];

    ptr = str;

    if(*ptr != 0x9F)
    {
        /* this tag code is NOT in extension form */
        tag_code = *ptr;
        ptr++;
    }
    else
    {
        /* *ptr == 0x9F                                                      */
        /* Tag Code가 2자리 이상일 경우에는 1번째 바이트가 항상 9f로 시작    */
        /* 두번째 바이트 부터는 첫번째 비트가 '1'일경우에는 확장이 됨을 의미 */
        /* 그러므로 0x80과 &를 해서 '0'가 나오면 더 이상 확장이 되지않음을   */
        /*  의미                                                             */

        tag_code = 0x9F;
        tag_code_len = 1;

        while (1)
        {
            ptr++;
            tag_code_len++;
            tag_code <<= 8;
            tag_code |= *ptr;
			/* modified by twkim 2003.06.19 ver 0.0.8 [capability]
            if((*ptr & 0x80) == 0)
                break;
			*/

			if ((*ptr & 0x80) == 0 || tag_code_len == 3)
				break;
        }
        ptr++;
    }

    /* now, it's length part */
    if(*ptr < 0x80)     /* if the MSB is 0,  the length is in short form */
        para_len = *ptr;
    else                /* if the MSB is 1,  the length is in long form  */
    {
        if(*ptr != 0x81)
        {
            return -2;

            /* long form with more than 1-byte length. */
            /* 즉 para 길이가 255보다 크다는 의미이다. */
            /* 여기서는 이를 지원하지 않는다.          */

            /* 다음은 2byte이상의 long form처리 부분이다. */
            /*
            int    len, k;
            len = *ptr & 0x7F;
            for(k=0, para_len=0; k<len; k++)
            {
                ptr++;
                para_len <<= 8;
                para_len |= *ptr;
            }
            */
        }
        else
        {
            ptr++;
            para_len = *ptr;
        }
    }

    /* parameter contents part */
    ptr++;
    if (para_len > MAX_PARAMETER_LEN)
        para_len = MAX_PARAMETER_LEN;

    memcpy(result->paraData, ptr, para_len);
    result->paraLen = para_len;
    result->tagCode = tag_code;

    return (para_len + (int) (ptr - str));
}


/* return  0 : Decoding, Point Code & SSN */
/* return  1 : Decoding, ISDN Number      */
/* return -1 : Decoding Fail              */
int decode_SMS_ADDR(unsigned char *str, int len, stNodeNumber *node)
{
    int            ret;
    int            len_min;
    int            high4, low4;
    int            one, two;
    char           MIN[DEFAULT_ADDR_LEN+1];

    bzero((void *)node, sizeof(stNodeNumber));

    high4 = str[2] >> 4;
    low4 = str[2] & 0x0F;

    /* [2] E.164 [3] X.121 [7] Private Number */
    if(high4 == 2 || high4 == 3 || high4 == 7)
    {
        if(low4 == 1) /* [1] BCD */
        {
            len_min = str[3];
/* RGW는 착신 Addres가 없다.
            if(len_min > DEFAULT_ADDR_LEN || len_min < DEFAULT_MIN_ADDR_LEN)
*/
            if(len_min > DEFAULT_ADDR_LEN || len_min < 0)
                return -1;
            ret = decode_MIN(str+4, len_min, MIN);
            strcpy(node->isdn, MIN);

			if(ret == -1)
				return -1;
			else 
				return 1;  /* return 1 : ISDN Number Include */
        }
    }
    else if(high4 == 13) /* [13] SS7 PC & SSN */
    {
        if(low4 == 3) /* [3] Octet String */
        {
            node->ssn = str[6];

            one = str[4];
            two = str[3];

            /* Turn off International/National Indicator bit */
            one = one & 0x3F;
            node->pCode = (one << 8) | two;

            return 0;  /* return 0 : Point Code & SSN Include */
        }
    }

    return -1;
}

int decode_FWDREQ_ADDR(unsigned char *str, int len, 
		               unsigned char *svcId, char *fwdAddr)
{
    int            ret;
    int            len_min;
    int            high4, low4;
    int            one, two;
    char           MIN[DEFAULT_ADDR_LEN+1];

    high4 = str[2] >> 4;
    low4 = str[2] & 0x0F;

	*svcId = str[3];  /* Forwarding Service ID */

    /* [2] E.164 [3] X.121 [7] Private Number */
#ifdef _INTERNATIONAL
/* E.164 를 사용해야 맞는 값이다. 하지만, KTF에서는 해당값을 사용하지 않아, 
   어떠한 값이 올라올지 알수가 없다, 따라서 체크하지 않는다 *

    if(high4 == 2 || high4 == 3 || high4 == 7)
    {
*/
        if(low4 == 1) * [1] BCD 
        {
#endif
            len_min = str[4];

            if(len_min > DEFAULT_ADDR_LEN || len_min < DEFAULT_MIN_ADDR_LEN)
                return -1;
            ret = decode_MIN(str+5, len_min, MIN);
            strcpy(fwdAddr, MIN);

            return ret;
#ifdef _INTERNATIONAL
        }
    }
    return -1;
#endif
}

/* GMAP 6.5.2.81
    MIN
    tag = 0x88
    len = 5, 10
*/

int decode_MIN(unsigned char *str, int len, unsigned char *min)
{
    int    i;

    *min = 0;

    if(len > DEFAULT_ADDR_LEN)
        return -1;

    for(i = 0; i < len; i++)
    {
		/* 05/07/28 convert '0x0b(;) -> *' for KTF */
	    if((*str&0x0F) == 0x0d || (*str&0x0F) == 0x0b )
		    *min++ = '*';
	    else if((*str&0x0F) == 0x0e || (*str&0x0F) == 0x0c)
		    *min++ = '#';
        else
            *min++ = (*str & 0x0F) + '0';
        i++;
        if(i >= len)
            break;
       
	    if((*str>>4) == 0x0d || (*str>>4) == 0x0b)
		    *min++ = '*';
	    else if((*str>>4) == 0x0e || (*str>>4) == 0x0c)
		    *min++ = '#';
        else
            *min++ = (*str >> 4) + '0';

        str++;
    }
    *min = 0;

    return 0;
}

int decode_MDN(unsigned char *str, stAddr *mdn)
{
	int     i;
	unsigned char    *pMdn, len;

	pMdn = (unsigned char *)mdn->min;

	*pMdn = 0;

	if ((len * 2) > DEFAULT_ADDR_LEN)
		return -1;

	str += 3;

	len = *str++;
	for (i = 0; i < len; i++)
	{
		/* 05/07/28 convert '0x0b(;) -> *' for KTF */
	    if((*str&0x0F) == 0x0d || (*str&0x0F) == 0x0b)
		    *pMdn++ = '*';
        else if((*str&0x0F) == 0x0e || (*str&0x0F) == 0x0c)
		    *pMdn++ = '#';
        else 
		    *pMdn++ = (*str & 0x0F) + '0';
		i++;
		if (i >= len)
			break;

        if((*str>>4) == 0x0d || (*str>>4) == 0x0b)
		    *pMdn++ = '*';
        else if((*str>>4) == 0x0e || (*str>>4) == 0x0c)
		    *pMdn++ = '#';
        else
		    *pMdn++ = (*str >> 4) + '0';
		str++;
	}
	*pMdn = 0;

	mdn->len = strlen(mdn->min);

	return 0;
}

int decode_CHR_INDI(unsigned char *str, int len,
		unsigned char *chargIndi)
{
    *chargIndi = *str;
	return 0;
}

int decode_SMS_PROFILE(unsigned char *str, int len, char *profile)
{
	int      i;

	for (i = 0; i < len && i < 3; i++)
		profile[i] = str[i];

	return 0;
}

int decode_INTELI_SUBINDI(unsigned char *str, int len,
		unsigned char *inteliIndi)
{
    *inteliIndi = *str;
	return 0;
}

int decode_NPINFO(unsigned char *str, int len,
		unsigned char *npInfo)
{
	*npInfo = *str;
	return 0;
}

int decode_SERVICEINDI(unsigned char *str, int len,
		unsigned char *svcIndi)
{
	*svcIndi =  *str;
	return 0;
}






/*    GMAP 6.5.2.63
    ESN
    tag = 0x89
    len = 1
*/

int write_ESN(unsigned char *ptr, unsigned char *esn)
{
    *ptr++ = tag_ESN;
    *ptr++ = 4;
    memcpy(ptr, esn, 4);
    return (6);
}

int write_IMSI(unsigned char *ptr, stAddr *msid)
{
	int		i, len = 0, iLen = 0;

	*ptr++ = tag_IMSI_one;
	*ptr++ = tag_IMSI_two;
	*ptr++ = tag_IMSI_thr;
	len += 3;

	iLen = msid->len;

	if (msid->len > 15)
		iLen = 15;

	*ptr++ = 8;   /* IMSI Length */
	len++;
	for(i = 0; i < iLen; i++)
	{
		switch(msid->min[i])
		{
			case '*':
				ptr[i/2] = 10;
				break;
			case '#':
				ptr[i/2] = 11;
				break;
			case 'a':
			case 'b':
			case 'c':
				ptr[i/2] = msid->min[i] - 'a' + 12;
				break;
			default:
				ptr[i/2] = msid->min[i] - '0';
				break;
		}

		i++;
		len++;
		if (i == iLen)
			break;

		switch(msid->min[i])
		{
			case '*':
				ptr[i/2] |= 10 << 4;
				break;
			case '#':
				ptr[i/2] |= 11 << 4;
				break;
			case 'a':
			case 'b':
			case 'c':
				ptr[i/2] |= (msid->min[i] - 'a' + 12) << 4;
				break;
			default:
				ptr[i/2] |= (msid->min[i] - '0') << 4;
				break;
		}
	}

	if (i % 2 == 1)
		ptr[i/2] |= 0xf0;

	return len;
}

/* min이 10자리가 되지 않으면 앞쪽에 0을 추가하여 10자리로 맞추어 줌 */
int write_MIN(unsigned char *ptr, int defLen, unsigned char *min)
{
    int                 i;
    unsigned char       num;
    unsigned char       str[DEFAULT_ADDR_LEN+1];
    unsigned char      *pstr;
    int                 len;

    *ptr++ = tag_MIN;  /* tag */

    *ptr++ = 5;        /* length */

    len = strlen((char *)min);
    strcpy((char *)str, (char *)min);

    if(len < defLen)
    {
        for(i = 0; i < (defLen - len); i++)
            str[len+i] = '0' + 15;
        str[defLen] = 0x00;
    }
    else if(len > defLen)
    {
        for(i = 0; i < defLen; i++)
            str[i] = min[(len-defLen)+i];
        str[defLen] = 0x00;
    }

    pstr = str;
    /* tag contents part */
    for(i = 0; i < defLen; )
    {
        num = *pstr - '0';
        *ptr = num;
        pstr++;

        if(++i >= defLen)
            break;

        num = *pstr - '0';
        *ptr = *ptr | (num << 4);
        pstr++;

        ptr++;
        i++;
    }
    return 7;      /* tag(1) + len(1) + val(5) */
}

/* sjkim add : CallBack */
int write_CPND1(unsigned char *ptr, char *cpnd )
{
	int		i, len = 0, numOfDigit = 0;
	unsigned char bcd;

	*ptr++ = 0x9F;
	*ptr++ = tag_CPND1_two;
	numOfDigit = strlen(cpnd);
	if ( numOfDigit > (DEFAULT_CB_LEN-2) ) numOfDigit = DEFAULT_CB_LEN-2;
	len = ((numOfDigit % 2) == 0 ? numOfDigit / 2 : (numOfDigit / 2) + 1)
		+ 4;
	*ptr++ = len;
	/* type of digit */
	*ptr++ = TYPE_OF_DIGIT_CALLING;
	/* Nature of Number */
	*ptr++ = 0x00;
	/*Numbering Play & Encoding */
	*ptr++ = (NUM_PLAN_E164 | ENCODING_BCD);
	/* Number of Digits */
	*ptr++ = numOfDigit;

	for (i = 0; i < numOfDigit; i++)
	{
		bcd = cpnd[i++];
		if (isdigit(bcd))
			*ptr = bcd - '0';
		else if (bcd == '*')
			*ptr = 0x0d;
		else if (bcd == '#')
			*ptr = 0x0e;
		else
			*ptr = bcd - '0';

		if (i >= numOfDigit)
		{
			*ptr &= 0x0f;
			break;
		}

		bcd = cpnd[i];
		if (isdigit(bcd))
			*ptr++ |= ((bcd - '0') << 4);
		else if (bcd == '*')
			*ptr++ |= 0xd0;
		else if (bcd == '#')
			*ptr++ |= 0xe0;
		else
			*ptr++ |= ((bcd - '0') << 4);
	}

	return len+3;
}



int write_MDN(unsigned char *ptr, char *mdn)
{
	int		i, len = 0, numOfDigit = 0;
	unsigned char bcd;

	*ptr++ = 0x9F;
	*ptr++ = tag_MDN_two;
	numOfDigit = strlen(mdn);
	if (numOfDigit > 15) numOfDigit = 15;
	len = ((numOfDigit % 2) == 0 ? numOfDigit / 2 : (numOfDigit / 2) + 1)
		+ 4;
	*ptr++ = len;
	/* type of digit */
	*ptr++ = TYPE_OF_DIGIT_CALLED;
	/* Nature of Number */
	*ptr++ = 0x00;
	/*Numbering Play & Encoding */
	*ptr++ = (NUM_PLAN_E164 | ENCODING_BCD);
	/* Number of Digits */
	*ptr++ = numOfDigit;

	for (i = 0; i < numOfDigit; i++)
	{
		bcd = mdn[i++];
		if (isdigit(bcd))
			*ptr = bcd - '0';
		else if (bcd == '*')
			*ptr = 0x0d;
		else if (bcd == '#')
			*ptr = 0x0e;
		else
			*ptr = bcd - '0';

		if (i >= numOfDigit)
		{
			*ptr &= 0x0f;
			break;
		}

		bcd = mdn[i];
		if (isdigit(bcd))
			*ptr++ |= ((bcd - '0') << 4);
		else if (bcd == '*')
			*ptr++ |= 0xd0;
		else if (bcd == '#')
			*ptr++ |= 0xe0;
		else
			*ptr++ |= ((bcd - '0') << 4);
	}

    /* modified by knd, v121
       return 값에는 실제 value length와 함께 tag와 length의 길이도 같이
       포함되어야 한다.
	return len;
    */
	return len+3;
}

int write_BearerData(unsigned char *ptr, unsigned char *BD, int bd_len)
{
    int    long_form = 0;

    *ptr++ = 0x9F;
    *ptr++ = tag_BEARERDATA_two;

    if(bd_len < 128)
        *ptr++ = bd_len;
    else
    {
        if(bd_len > MAX_BD_LEN)
            bd_len = MAX_BD_LEN;
        *ptr++ = 0x81;
        *ptr++ = bd_len;
        long_form = 1; 
    }

    memcpy(ptr, BD, bd_len);
    return (3 + long_form + bd_len);
}

int write_CHR_IND(unsigned char *ptr, int charge_ind)
{
    *ptr++ = 0x9F;
    *ptr++ = tag_CHARGEIND_two;
    *ptr++ = 1;
    *ptr = charge_ind;
    return 4;
}


int write_MSG_CNT(unsigned char *ptr, int msg_cnt)
{
    *ptr++ = 0x9F;
    *ptr++ = tag_MESSAGECOUNT_two;
    *ptr++ = 1;
    *ptr = msg_cnt;
    return 4;
}


int write_NOTI_IND(unsigned char *ptr, int not_ind)
{
    *ptr++ = 0x9F;
    *ptr++ = tag_NOTIND_two;
    *ptr++ = 1;
    *ptr = not_ind; /* Notify when available */
    return 4;
}


/* SMS_AccessDeniedReason parameter */
/* tag = 0x9f8118,  len = 1         */
int write_ACCDENY(unsigned char *ptr, int acc_deny_reason)
{
    *ptr++ = 0x9F;
    *ptr++ = tag_ACCDENY_two;
    *ptr++ = tag_ACCDENY_thr;
    *ptr++ = 1;
    *ptr   = acc_deny_reason; 
        /* Postponed : not reachable, notification wil be sent */
    return 5;
}


/* SMS_CauseCode parameter */
/* tag = 0x9f8119, len = 1 */
int write_CAUSE_CODE(unsigned char *ptr, int causecode)
{
    *ptr++ = 0x9F;
    *ptr++ = tag_CAUSECODE_two;
    *ptr++ = tag_CAUSECODE_thr;
    *ptr++ = 1;
    *ptr   = causecode; 
    return 5;
}

int write_TI(unsigned char *ptr, unsigned short TI)
{
    *ptr++ = 0x9F;
    *ptr++ = tag_TELESERVICEID_two;
    *ptr++ = 2;
    *ptr++ = TI >> 8;
    *ptr = TI & 0xFF;
    return 5;
}

int write_SMS_ADDR(unsigned char *ptr, int tag_code, stNodeNumber *node,
                   int isdn_pc)
{
    int                i;
    int                min_len, bytes_MIN;
    unsigned char      one_octet, num;
    char               *min;
    int                pc;

    pc = node->pCode;

    *ptr++ = 0x9F;
    *ptr++ = (unsigned char)tag_code;

    if(isdn_pc == SMS_ADDR_PC)
    {
        *ptr++ = 7;
        *ptr++ = 0;       /* Type of Digits == 0 : Don't care         */
        *ptr++ = 1;       /* Nature of Number == 1 : national         */
        *ptr++ = 0xD3;    /* Numbering Plan == 0x0D (13), high 4-bits */
                          /*   : SS7 PC & SSN                         */
                          /* Encoding == 0x03 (3), low 4-bits         */
                          /*   : octet                                */

        pc = pc | 0x8000; /* International / National Indicator */

        *ptr = pc & 0xFF;     /* low-order byte */
        *(ptr+1) = pc >> 8;   /* high-oder byte */

        ptr += 2;
        *ptr++ = 0;
        *ptr   = node->ssn;            /* subsystem #. MSC-8, HLR-6, MC-11 */

        return 10;
    }
    else if(isdn_pc == SMS_ADDR_ISDN)
    {
        min = node->isdn;
        min_len = strlen(node->isdn);
        bytes_MIN = min_len >> 1;

        if(min_len % 2 != 0)
            bytes_MIN++;

        /* the length of para contents */
        *ptr++ = bytes_MIN + 4;

        *ptr++ = 0;        /* Type of Digits == 0 : Don't care */
        *ptr++ = 1;        /* Nature of Number == 1 : national */
        *ptr++ = 0x21;     /* Numbering Plan == 2, high 4-bits */
                           /*   : Telephony Numbering          */
                           /* Encoding == 1, low 4-bits        */
                           /*   : BCD                          */

        *ptr++ = min_len;                   /* Number of Digits */

        for(i = 0; i < min_len; i++)        /* encode MIN in BCD format */
        {
		    if(*min == '*')
			    num = 0x0d;
            else if(*min == '#')
			    num = 0x0e;
            else 
			    num = *min - '0';

            *ptr = num;
            min++;
            i++;

            if(i >= min_len)
                break;

		    if(*min == '*')
			    num = 0x0d;
            else if(*min == '#')
			    num = 0x0e;
            else 
			    num = *min - '0';

            *ptr = *ptr | (num << 4);
            ptr++;
            min++;
        }

        return (bytes_MIN + 7);
    }

    return 0;
}

/* KTF Specific Parameter */
int write_FWDREQ_ADDR(unsigned char *ptr,  unsigned char svcId, char *fwdAddr)
{
    int                i;
    int                min_len, bytes_MIN;
    unsigned char      one_octet, num;
    char               *min;

    *ptr++ = tag_FWDREQADDR_one; 
    *ptr++ = tag_FWDREQADDR_two;
    *ptr++ = tag_FWDREQADDR_thr;


    min = fwdAddr;
    min_len = strlen(fwdAddr);
    bytes_MIN = min_len >> 1;

    if(min_len % 2 != 0)
        bytes_MIN++;

   /* the length of para contents */
   *ptr++ = bytes_MIN + 5;

   *ptr++ = 0;        /* Type of Digits == 0 : Don't care */
   *ptr++ = 1;        /* Nature of Number == 1 : national */
   *ptr++ = 0x21;     /* Numbering Plan == 2, high 4-bits */
                           /*   : Telephony Numbering          */
                           /* Encoding == 1, low 4-bits        */
                           /*   : BCD                          */
   *ptr++ = svcId;    /* Forwarding Service ID */
                      /* Good Change Service, Two-Number-Two */

   *ptr++ = min_len;                   /* Number of Digits */
	for(i = 0; i < min_len; i++)        /* encode MIN in BCD format */
	{
		if(*min == '*')
			num = 0x0d;
		else if(*min == '#')
			num = 0x0e;
		else 
			num = *min - '0';

		*ptr = num;
		min++;
		i++;

		if(i >= min_len)
			break;

		if(*min == '*')
			num = 0x0d;
		else if(*min == '#')
			num = 0x0e;
		else 
			num = *min - '0';

		*ptr = *ptr | (num << 4);
		ptr++;
		min++;
    }
    return (bytes_MIN + 9);
}

int write_SMS_PROFILE(unsigned char *ptr,  unsigned char *profile)
{
    *ptr++ = tag_PROFILE_one;
    *ptr++ = tag_PROFILE_two;
    *ptr++ = tag_PROFILE_thr;
    *ptr++ = 3;
	*ptr++ = profile[0];
	*ptr++ = profile[1];
	*ptr++ = profile[2];

	return 7;
}

int write_INTELI_SUBINDI(unsigned char *ptr, unsigned char inteliIndi)
{
	*ptr++ = tag_INTELLIGENTSUBINDI_one;
	*ptr++ = tag_INTELLIGENTSUBINDI_two;
	*ptr++ = tag_INTELLIGENTSUBINDI_thr;
	*ptr++ = 1;
	*ptr   = inteliIndi;

	return 5;
}

int write_NPINFO(unsigned char *ptr, unsigned char npInfo)
{
	*ptr++ = tag_NUMPORTABILITYINFO_one;
	*ptr++ = tag_NUMPORTABILITYINFO_two;
	*ptr++ = tag_NUMPORTABILITYINFO_thr;
	*ptr++ = 1;
	*ptr   = npInfo;

	return 5;
}

int write_SERVICEINDI(unsigned char *ptr, unsigned char svcIndi)
{
	*ptr++ = tag_SERVICEINDICATOR_one;
	*ptr++ = tag_SERVICEINDICATOR_two;
	*ptr++ = tag_SERVICEINDICATOR_thr;
	*ptr++ = 1;
	*ptr++ = svcIndi;

	return 5;
}


int decodeSmsParas(char *buff, unsigned char *para_str, int para_len)
{
    stOnePara        onePr;    
    unsigned char   *ptr;
    char            *trg;
    char             hex_buf[2000];
    int              bytes = 0;
    int              decoded_n;
    int              res;
    int              val, esn, TI;
    unsigned char    min[25];
    stNodeNumber     node;
	stAddr           stMDN;
	unsigned short   osfi;

    if(para_len < 1)
        return IXOK;

    trg = buff;
    ptr = para_str;

    memset(hex_buf, 0, 2000);

    if(*ptr == SEQ_TAG)
    {
        sprintf(trg, "\tSEQ_TAG=H'%X\n", SEQ_TAG);
        trg += strlen(trg);
        ptr++;
    }
    else if(*ptr == SET_TAG)
    {
        sprintf(trg, "\tSET_TAG=H'%X\n", SET_TAG);
        trg += strlen(trg);
        ptr++;
    }
    else
    {
        sprintf(trg, "\tOnly one para.!\n");
        trg += strlen(trg);
    }

    if((int)ptr != (int)para_str)
    {
        if(*ptr < 0x80)
            ptr++;
        else
        {
            if(*ptr != 0x81)
                return -1;
            ptr += 2;
        }
    }

    bytes = (int)((int)ptr - (int)para_str);

    while(bytes < para_len)
    {
        decoded_n = getOnePara(ptr, &onePr);
        if(decoded_n < 0)
            return IXERR;
        bytes += decoded_n;
        ptr += decoded_n;

        sprintf(trg, "\n\tTag:H'%X\tLen:%d\t", onePr.tagCode, onePr.paraLen);
        trg += strlen(trg);

        switch (onePr.tagCode)
        {
            case tag_ESN:
                memcpy(&esn, onePr.paraData, 4);
                sprintf(trg, "ESN: %04X\n", esn);
                trg += strlen(trg);
                break;

            case tag_MIN:
                decode_MIN(onePr.paraData, onePr.paraLen*2,
                    (unsigned char *)min);
                sprintf(trg, "MIN: %s\n", min);
                trg += strlen(trg);
                break;

            case tag_BEARERDATA:
                sprintf(trg, "BearerData\n");
                trg += strlen(trg);
                break;

            case tag_ADENIEDREASON:
                sprintf(trg, "Acces Denied Reason: %d\n", onePr.paraData[0]);
                trg += strlen(trg);
                break;

            case tag_NOTIND:
                sprintf(trg, "Noti Ind: %d\n", onePr.paraData[0]);
                trg += strlen(trg);
                break;

            case tag_CAUSECODE:
                sprintf(trg, "Cause Code: %d\n",
                    (unsigned char)onePr.paraData[0]);
                trg += strlen(trg);
                break;

            case tag_CHARGEIND:
                sprintf(trg, "Charge Ind: %d\n", onePr.paraData[0]);
                trg += strlen(trg);
                break;

            case tag_MESSAGECOUNT:
                sprintf(trg, "Message Count: %d\n", onePr.paraData[0]);
                trg += strlen(trg);
                break;

            case tag_TELESERVICEID:
                TI = (int)((int)onePr.paraData[0] << 8);
                TI |= (int)onePr.paraData[1];
                sprintf(trg, "TI : %d\n", TI);
                trg += strlen(trg);
                break;

            case tag_SMSADDRESS:
                bzero((void *)&node, sizeof(stNodeNumber));
                res = decode_SMS_ADDR(onePr.paraData, onePr.paraLen, &node);
                if(res < 0)
                {
                    sprintf(trg, "Invalid SMS ADDR!\n");
                    trg += strlen(trg);

                    make_str_hex(hex_buf, onePr.paraData, onePr.paraLen,
                        5, 10);
                    sprintf(trg, "\tData: %s\n", hex_buf);
                    trg += strlen(trg);
                    return ERR_PARAM_INVALID_VAL;
                }
                sprintf(trg, "SMSADDRESS: ISDN=%s, PC=%d, SSN=%d\n",
                    node.isdn, node.pCode, node.ssn);
                trg += strlen(trg);
                break;

            case tag_DESTADDR :
                bzero((void *)&node, sizeof(stNodeNumber));
                decode_SMS_ADDR(onePr.paraData, onePr.paraLen, &node);
                sprintf(trg, "Dest Addr = %s\n", node.isdn);
                trg += strlen(trg);
                break;

			/* added by twkim 2003.09.23 min & mdn 분리로 인하여 */
			case tag_NOTIMDN :
				bzero((void *)&stMDN, sizeof(stAddr));
				decode_MDN(onePr.paraData, &stMDN);
				stMDN.ton = TON_NATIONAL;
				stMDN.npi = NPI_E164;
				sprintf(trg, "Dest MDN = %s\n", stMDN.min);
				trg += strlen(trg);
				break;
			/* end of addition                                   */

            case tag_ORIGADDR :
                bzero((void *)&node, sizeof(stNodeNumber));
                decode_SMS_ADDR(onePr.paraData, onePr.paraLen, &node);
                sprintf(trg, "Orig Addr = %s\n", node.isdn);
                trg += strlen(trg);
                break;

            case tag_ORIGORIGADDR :
                bzero((void *)&node, sizeof(stNodeNumber));
                decode_SMS_ADDR(onePr.paraData, onePr.paraLen, &node);
                sprintf(trg, "Orig Orig Addr = %s\n", node.isdn);
                trg += strlen(trg);
                break;

            case tag_ORIGORIGSUBADDR :
                bzero((void *)&node, sizeof(stNodeNumber));
                decode_SMS_ADDR(onePr.paraData, onePr.paraLen, &node);
                sprintf(trg, "Orig Orig SubAddr = %s\n", node.isdn);
                trg += strlen(trg);
                break;

            case tag_ORIGDESTADDR :
                bzero((void *)&node, sizeof(stNodeNumber));
                decode_SMS_ADDR(onePr.paraData, onePr.paraLen, &node);
                sprintf(trg, "Orig Dest Addr = %s\n", node.isdn);
                trg += strlen(trg);
                break;

            case tag_ORIGDESTSUBADDR :
                bzero((void *)&node, sizeof(stNodeNumber));
                decode_SMS_ADDR(onePr.paraData, onePr.paraLen, &node);
                sprintf(trg, "Orig Dest SubAddr = %s\n", node.isdn);
                trg += strlen(trg);
                break;

			case tag_PROFILE:
				decode_SMS_PROFILE(onePr.paraData, onePr.paraLen, hex_buf);
				make_str_hex(hex_buf, onePr.paraData, onePr.paraLen, 5, 10);
				sprintf(trg, "Dest MDN = %d\n", hex_buf);
				trg += strlen(trg);
				break;

            default:
                sprintf(trg, "Unknown!\n");
                trg += strlen(trg);
                break;
        }

        make_str_hex(hex_buf, onePr.paraData, onePr.paraLen, 5, 10);
        sprintf(trg, "\tData: %s\n", hex_buf);
        trg += strlen(trg);

    }

    sprintf(trg, "\tParameter Len=%d, Decoded=%d\n", para_len, bytes);
        trg += strlen(trg);
    return IXOK;
}

