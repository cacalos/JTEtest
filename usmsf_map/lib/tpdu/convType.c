#include <stdio.h>
#include <string.h>

#include <iXtypes.h>
#include <ASN/asn_smsc.h>

#define TBCD_TO_CHAR(bcd, ch)\
		if(bcd <= 9)\
			ch = bcd + '0';\
		else {\
			switch (bcd) {\
				case 10:\
					ch = '*';\
					break;\
				case 11:\
					ch = '#';\
					break;\
				case 12:\
				case 13:\
				case 14:\
					ch = bcd + 'a'- 12;\
					break;\
				default:\
					break;\
			}\
		}

#define ERROR_ADDRESS_ILLEGAL_LENGTH	-1

/*------------- Convert ISDN-AddressString to Address type -------------------*/

int ConvISDNStringToAddress(ISDN_AddressString *isdn, stAddr *addr)
{
	int               i;
	unsigned char     val;

	bzero((void *)addr, sizeof(stAddr));

	if(isdn->length > 15)
		return IXERR;

	addr->ton = (isdn->value[0] & 0x70) >> 4;
	addr->npi = isdn->value[0] & 0x0f;
	addr->len = 0;

	for(i=1; i < isdn->length; i++) 
	{
		val = isdn->value[i] & 0x0f;
		TBCD_TO_CHAR(val, addr->min[addr->len]);
		addr->len++;

		val = (isdn->value[i] & 0xf0) >> 4;
		if(val == 0x0f) break;
		TBCD_TO_CHAR(val, addr->min[addr->len]);
		addr->len++;
	}

	return IXOK;
}

/*-------------- Convert Address to FTN(CallBack)String-------------------------*/
int ConvAddressToCBString(stAddr *addr, FTN_AddressString *isdn)
{
	int                  i;

	bzero((void *)isdn, sizeof(FTN_AddressString));

	isdn->value[0] = 0x80 | addr->ton << 4 | addr->npi;
	isdn->length++;

	if(addr->len > 20)
		addr->len = 20;

	for(i = 0; i < addr->len; i++)
    {
		switch(addr->min[i])
        {
			case '*':
				isdn->value[i/2+1] = 10;
				break;
			case '#':
				isdn->value[i/2+1] = 11;
				break;
			case 'a':
			case 'b':
			case 'c':
				isdn->value[i/2+1] = addr->min[i] - 'a' + 12;
				break;
			default:
				isdn->value[i/2+1] = addr->min[i] - '0';
				break;
		}

		i++;
		isdn->length++;
		if(i == addr->len)
            break;

		switch(addr->min[i])
        {
			case '*':
				isdn->value[i/2+1] |= 10 << 4;
				break;
			case '#':
				isdn->value[i/2+1] |= 11 << 4;
				break;
			case 'a':
			case 'b':
			case 'c':
				isdn->value[i/2+1] |= (addr->min[i] - 'a' + 12) << 4;
				break;
			default:
				isdn->value[i/2+1] |= (addr->min[i] - '0') << 4;
				break;
		}
	}

	if( i%2 == 1)
		isdn->value[i/2+1] |= 0xf0;

	return IXOK;
}


/*----------- Convert Address type to ISDN-AddressString ---------------------*/

int ConvAddressToISDNString(stAddr *addr, ISDN_AddressString *isdn)
{
	int                  i;

	bzero((void *)isdn, sizeof(ISDN_AddressString));

	isdn->value[0] = 0x80 | addr->ton << 4 | addr->npi;
	isdn->length++;

	/* sjkim : 3GPP 규격에 ISDNString 길이는 9. 따라서 16이상의 길이는  수용할 수 없다.*/
	if(addr->len > 16)
        return IXERR;

	for(i = 0; i < addr->len; i++)
    {
		switch(addr->min[i])
        {
			case '*':
				isdn->value[i/2+1] = 10;
				break;
			case '#':
				isdn->value[i/2+1] = 11;
				break;
			case 'a':
			case 'b':
			case 'c':
				isdn->value[i/2+1] = addr->min[i] - 'a' + 12;
				break;
			default:
				isdn->value[i/2+1] = addr->min[i] - '0';
				break;
		}

		i++;
		isdn->length++;
		if(i == addr->len)
            break;

		switch(addr->min[i])
        {
			case '*':
				isdn->value[i/2+1] |= 10 << 4;
				break;
			case '#':
				isdn->value[i/2+1] |= 11 << 4;
				break;
			case 'a':
			case 'b':
			case 'c':
				isdn->value[i/2+1] |= (addr->min[i] - 'a' + 12) << 4;
				break;
			default:
				isdn->value[i/2+1] |= (addr->min[i] - '0') << 4;
				break;
		}
	}

	if( i%2 == 1)
		isdn->value[i/2+1] |= 0xf0;

	return IXOK;
}

/*-------------- Convert Address to AddressString -------------------------*/

int ConvAddressToAddressString(stAddr *addr, AddressString *adstr)
{
	int 		i = 0;

	bzero((void *)adstr, sizeof(AddressString));

	if(addr->len > DEFAULT_ADDR_LEN)
        return IXERR;

	adstr->value[0] = 0x80 | addr->ton << 4 | addr->npi;
	adstr->length++;

	for(i = 0; i < addr->len; i++) 
	{
		switch(addr->min[i])
        {
			case '*':
				adstr->value[i/2+1] = 10;
				break;
			case '#':
				adstr->value[i/2+1] = 11;
				break;
			case 'a':
			case 'b':
			case 'c':
				adstr->value[i/2+1] = addr->min[i] - 'a' + 12;
				break;
			default:
				adstr->value[i/2+1] = addr->min[i] - '0';
				break;
		}

		i++;
		adstr->length++;
		if(i == addr->len)
            break;

		switch(addr->min[i])
        {
			case '*':
				adstr->value[i/2+1] |= 10 << 4;
				break;
			case '#':
				adstr->value[i/2+1] |= 11 << 4;
				break;
			case 'a':
			case 'b':
			case 'c':
				adstr->value[i/2+1] |= (addr->min[i] - 'a' + 12) << 4;
				break;
			default:
				adstr->value[i/2+1] |= (addr->min[i] - '0') << 4;
				break;
		}
	}

	if(i%2 == 1)
		adstr->value[i/2+1] |= 0xf0;

	return IXOK;
}


int ConvAddressStringToAddress(AddressString *adstr, stAddr *addr)
{
	int               i;
	unsigned char     val;

	bzero((void *)addr, sizeof(stAddr));

	if(adstr->length > 20)
		return IXERR;

	addr->ton = (adstr->value[0] & 0x70) >> 4;
	addr->npi = adstr->value[0] & 0x0f;
	addr->len = 0;

	for(i = 1; i < adstr->length; i++) 
	{
		val = adstr->value[i] & 0x0f;
		TBCD_TO_CHAR(val, addr->min[addr->len]);
		addr->len++;

		val = (adstr->value[i] & 0xf0) >> 4;
		if(val == 0x0f)
            break;
		TBCD_TO_CHAR(val, addr->min[addr->len]);
		addr->len++;
	}

	return IXOK;
}


/*-------------- Convert Address to AddressString -------------------------*/

int ConvStrToAddressString(int len, char *str, AddressString *adstr)
{
	int           i;
    char          ch;

	bzero((void *)adstr, sizeof(AddressString));

	if(len > 40 || len < 0)
        return IXERR;

	for(i = 0; i < len; i++)
    {
		switch(str[i])
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
				ch = str[i] - '0';
				break;
			case '*':
				ch = 10;
				break;
			case '#':
				ch = 11;
				break;
			case 'a':
			case 'b':
			case 'c':
				ch = str[i] - 'a' + 12;
				break;
			default:
                adstr->length = i/2;
                return 1;
		}
        adstr->value[i/2] = ch;

		i++;
		if(i == len)
        {
            adstr->value[i/2] |= 0xF0;
            adstr->length = i/2 + 1;
            return 1;
        }

		switch(str[i])
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
				ch = str[i] - '0';
				break;
			case '*':
				ch = 10;
				break;
			case '#':
				ch = 11;
				break;
			case 'a':
			case 'b':
			case 'c':
				ch = str[i] - 'a' + 12;
				break;
			default:
                adstr->length = i/2 + 1;
                return 1;
		}

        adstr->value[i/2] = (adstr->value[i/2] & 0x0F) | (ch << 4);
	}

    adstr->length = i/2;
	return IXOK;
}


/*-------------- Convert AddressString to Address -------------------------*/

int ConvAddressStringToStr(AddressString *adstr, int *len, char *str)
{
	int       i;
    char      ch;

	if(adstr->length > 20 || adstr->length < 0)
    {
        str[0] = 0;
        return IXERR;
    }

	for(i = 0; i < adstr->length; i++)
    {
        ch = adstr->value[i] & 0x0F;
		switch(ch)
        {
            case 0 :
            case 1 :
            case 2 :
            case 3 :
            case 4 :
            case 5 :
            case 6 :
            case 7 :
            case 8 :
            case 9 :
                str[i*2] = ch + '0';
                break;

            case 10 :
                str[i*2] = '*';
                break;

            case 11 :
                str[i*2] = '#';
                break;

            case 12 :
            case 13 :
            case 14 :
                str[i*2] = ch - 12 + 'a';
                break;

			default:
				*len = i * 2;
                str[*len] = 0;
				return 1;
		}

        ch = (adstr->value[i] & 0xF0) >> 4;
		switch(ch)
        {
            case 0 :
            case 1 :
            case 2 :
            case 3 :
            case 4 :
            case 5 :
            case 6 :
            case 7 :
            case 8 :
            case 9 :
                str[i*2+1] = ch + '0';
                break;

            case 10 :
                str[i*2+1] = '*';
                break;

            case 11 :
                str[i*2+1] = '#';
                break;

            case 12 :
            case 13 :
            case 14 :
                str[i*2+1] = ch - 12 + 'a';
                break;

			default:
				*len = i * 2 + 1;
                str[*len] = 0;
				return 1;
		}
	}

    *len = i * 2;
    str[*len] = 0;

	return IXOK;
}

/*-------- Convert Address to Service Center Addresstype ---------*/
int ConvAddressToCenterAddress(stAddr *addr, AddressString *addrSC)
{
	int				i, len, isLBS;
	unsigned char	ch;

	bzero(addrSC, sizeof(AddressString));
	addrSC->length = 0;

	for (i = 0, isLBS = 0, len = 0; i < addr->len; i++)
	{
		ch = addr->min[i];
		switch (ch)
		{
			case '*':
				ch = 0x0a;
				break;
			case '#':
				ch = 0x0b;
				break;
			case 'a':
				ch = 0x0c;
				break;
			case 'b':
				ch = 0x0d;
				break;
			case 'c':
				ch = 0x0e;
				break;
			default:
				ch = ch - '0';
				break;
		}

		if(isLBS == 0)
			addrSC->value[len] |= ch;
		else
			addrSC->value[len++] |= (ch << 4);

		isLBS = ~isLBS;
	}

	if(isLBS)
		addrSC->value[len] |= 0xf0;

	addrSC->length = isLBS ? len+1 : len;

	return IXOK;
}


/*-------- Convert IMSI (TBCD-String(3~8) to Address type -------------------*/
int ConvIMSIToAddress(IMSI *imsi, stAddr *addr)
{
	int               i;
	unsigned char     val;

	bzero(addr, sizeof(stAddr));

	if(imsi->length > 15)
		return IXERR;

	addr->len = 0;

	for(i = 0; i < imsi->length; i++) 
	{
		val = imsi->value[i] & 0x0f;
		TBCD_TO_CHAR(val, addr->min[addr->len]);
		addr->len++;

		val = (imsi->value[i] & 0xf0) >> 4;
		if(val == 0x0f)
            break;
		TBCD_TO_CHAR(val, addr->min[addr->len]);
		addr->len++;
	}

	return IXOK;
}


/*----------- Convert Address type to IMSI ---------------------*/
int ConvAddressToIMSI(stAddr *addr, IMSI *imsi)
{
	int            i;

	bzero(imsi, sizeof(IMSI));

	if(addr->len > 15)
        return IXERR;

	for(i = 0; i < addr->len; i++)
    {
		switch(addr->min[i])
        {
			case '*':
				imsi->value[i/2] = 10;
				break;
			case '#':
				imsi->value[i/2] = 11;
				break;
			case 'a':
			case 'b':
			case 'c':
				imsi->value[i/2] = addr->min[i] - 'a' + 12;
				break;
			default:
				imsi->value[i/2] = addr->min[i] - '0';
				break;
		}

		i++;
		imsi->length++;
		if(i == addr->len)
            break;

		switch(addr->min[i])
        {
			case '*':
				imsi->value[i/2] |= 10 << 4;
				break;
			case '#':
				imsi->value[i/2] |= 11 << 4;
				break;
			case 'a':
			case 'b':
			case 'c':
				imsi->value[i/2] |= (addr->min[i] - 'a' + 12) << 4;
				break;
			default:
				imsi->value[i/2] |= (addr->min[i] - '0') << 4;
				break;
		}
	}

	if(i % 2 == 1)
		imsi->value[i/2] |= 0xf0;

	return (1);
}

