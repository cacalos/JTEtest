//-------------------------------------------------------------------//
//      okh's BitUtil ver.1                                          //
//-------------------------------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <ua_log.h>
#include "TPDU/okhTypes.h"
#include "TPDU/BitUtil.h" 


int GetSemiOctet(byte *Source, byte *Dest, int nLength, boolean isCharacter) //nLength = Dest ByteNumber = Source SemiOctetNumber 
{
    int i;
    int Character;

    Character = isCharacter ? '0' : 0;

    for(i=0; i<nLength; i++)
    {
        if((i%2) == 0) 
			Dest[i] = (Source[i/2] & 0x0F) + Character;
        else 
			Dest[i] = ((Source[i/2] >> 4) & 0x0F) + Character;
    }

    return i;
}


int GetAddrSemiOctet(byte *Source, byte *Dest, int nLength,
                     boolean isCharacter)
{
    int i, j;
    int Character;

    Character = isCharacter ? '0' : 0;

    for(i = 0, j = 0; i < nLength; i++)
    {
        Dest[j++] = (Source[i] & 0x0F) + Character;
        if((Source[i] & 0xF0) != 0xF0)
            Dest[j++] = ((Source[i] & 0xF0) >> 4) + Character;
    }
    Dest[j] = 0;

    return j;
}


/* nLength = Data Length = SemiOctetNumber */
int SetSemiOctet(byte *Source, byte *Data, int nDataLength, boolean isCharacter)
{
    int i;
    int Character;

    Character = isCharacter ? '0' : 0;
    
    for(i=0; i<nDataLength; i++)
    {
        if((i%2) == 0) Source[i/2] = Data[i]- Character;
        else Source[i/2] |= (Data[i]- Character) << 4;
    }

    if((i%2) != 0) Source[i++/2] |= 0xF0;

    return i/2; // return : number of octet (contain semioctet)
}


int SetAddrSemiOctet(byte *Source, byte *Data, int nDataLength,
                     boolean isCharacter)
{
    int i, j;
    int Character;

    Character = isCharacter ? '0' : 0;
    
    for(i = 0; i < nDataLength; i++)
    {
        if((i%2) == 0)
            Source[i/2] = Data[i] - Character;
        else
            Source[i/2] |= (Data[i] - Character) << 4;
    }

    if((i%2) != 0) Source[i++/2] |= 0xF0;

    return i/2;
}


void PrintBits(byte *Data, int nByte)
{
    int i,j;

    for(i=0; i< nByte; i++)
    {
        printf("[%3d] ", i);
        for(j=0; j<8; j++)
        {
            if(j==4) printf(" ");
            printf("%2d", GetBits(Data[i], 7-j, 1));
        }
        printf("  [%03d][%02X]", Data[i], Data[i]);
        if(!isascii(Data[i]) || iscntrl(Data[i])) printf("[]");
        else printf("[%c]", Data[i]);
        printf("\n");
    }
    printf("\n");
}    


void _okPrintBitField(TBits *Bits) 
{
    printf("%d %d %d %d %d %d %d %d\n",
            Bits->bit_7, Bits->bit_6, Bits->bit_5,
            Bits->bit_4, Bits->bit_3, Bits->bit_2,
            Bits->bit_1, Bits->bit_0);
}


void PrintAllBitField(byte *Data, int nByte)
{
    int i;

    for(i=0; i< nByte; i++)
    {
        _okPrintBitField((TBits *)&Data[i]);
    }
}


void PrintData(char *Data, int nByteSize)
{
    int i;

    for(i=0; i<nByteSize; i++)
    {
        printf("%02X ", (byte)Data[i]);
    }

    printf("\n");
}


int ConvertEndian_Int(int num)
{
    int i, nTemp;

    for(i=0; i<sizeof(int); i++)
    {
        nTemp = (nTemp<<8) | ((num >> 8*i) & ~(~0 << 8));   
    }

    return nTemp;
}


short ConvertEndian_Short(short num)
{
    int i;
    short nTemp;

    for(i=0; i<sizeof(short); i++)
    {
        nTemp = (nTemp<<8) | ((num >> 8*i) & ~(~0 << 8));   
    }

    return nTemp;
}


int IsBigEndianSystem(void)
{
    int Value=0x00FF;
    char *p = (char *)&Value;

    return p[0] ? 0 : 1;
}

int Encode7BitPackAddress(byte *Octet, byte *Septet, int BitOffset, int Size)
{
    int i=0, j=0;
    int EncodedSize;

    if(Size <= 0)
        return 0;

    /* 추후 수정 필요함 , 성능 고려 */
#if 0
	for(i = 0; i < Size; i++)
	    Octet[i] = convAsciiToGsm(Octet[i]);
#endif

    EncodedSize = Encoded7BitPackSize(Size, BitOffset); 
	uaLog(L_INFO , "Encode Size %d " , EncodedSize);

    if(BitOffset != 0)
    {
        Septet[i] |= Octet[j] << BitOffset;
        i++; j++;
        BitOffset = (8-BitOffset)%7;
    }

    for(; i<EncodedSize-1; i++, j++)
    {
        if(BitOffset == 0) 
        {
            Septet[i] = Octet[j] | (Octet[j+1] << 7); 
            j++;
        }
        else
            Septet[i] = (Octet[j-1] >> BitOffset) | (Octet[j] << 7-BitOffset); 

        BitOffset = (BitOffset+1) % 7;
    }

    if(BitOffset==0) j++;

	uaLog(L_INFO , "BitOffset %d j = %d " , BitOffset , j );
    if(j==Size)
    {
        Septet[i++] = Octet[j-1] >> BitOffset;
    }
    else
    {
        Septet[i++] = (Octet[j-1] >> BitOffset) | (Octet[j] << 7-BitOffset);
    }

    return i; //Number of Octet
}

/* Size = Number of Octet */
int Encode7BitPack(byte *Octet, byte *Septet, int BitOffset, int Size)
{
    int i=0, j=0;
    int EncodedSize;

    if(Size <= 0)
        return 0;

    /* 추후 수정 필요함 , 성능 고려 */
#if 0
	for(i = 0; i < Size; i++)
	    Octet[i] = convAsciiToGsm(Octet[i]);
#endif

    EncodedSize = Encoded7BitPackSize(Size, BitOffset); 
	uaLog(L_INFO , "Encode Size %d " , EncodedSize);

    if(BitOffset != 0)
    {
        Septet[i] |= Octet[j] << BitOffset;
        i++; j++;
        BitOffset = (8-BitOffset)%7;
    }

    for(; i<EncodedSize-1; i++, j++)
    {
        if(BitOffset == 0) 
        {
            Septet[i] = Octet[j] | (Octet[j+1] << 7); 
            j++;
        }
        else
            Septet[i] = (Octet[j-1] >> BitOffset) | (Octet[j] << 7-BitOffset); 

        BitOffset = (BitOffset+1) % 7;
    }

    if(BitOffset==0) j++;

	uaLog(L_INFO , "BitOffset %d j = %d " , BitOffset , j );
    if(j==Size)
    {
        Septet[i++] = Octet[j-1] >> BitOffset;
    }
    else
    {
        Septet[i++] = (Octet[j-1] >> BitOffset) | (Octet[j] << 7-BitOffset);
    }

    return i; //Number of Octet
}


int Encode7BitAsciiPack(byte *Octet, byte *Septet, int BitOffset, int Size)
{
    int            i = 0, j = 0;
    int            EncodedSize;

    if(Size <= 0)
        return 0;

    for(i = 0; i < Size; i++, BitOffset--)
    {
        if(BitOffset != 1)
        {
            Septet[j++] |= (Octet[i]& 0x7F) >> BitOffset - 1;
            Septet[j] = Octet[i] << 9 - BitOffset;
        }
        else
        {
            Septet[j++] |= (Octet[i++] & 0x7F);
            Septet[j] = Octet[i] << 1;
            BitOffset = 8;
        }
    }

    return i; //Number of Octet
}


/* GSM 7bit의 decode function */
int Decode7BitPack(byte *Septet, byte *Octet, int BitOffset, int Size)
{
    int                  i, j;
    int                  DecodedSize;

    DecodedSize = Size;

    for(i=0, j=0; i<DecodedSize; i++, j++, BitOffset--)
    {
        Octet[i] = ((Septet[j] >> BitOffset) | (Septet[j+1] << 8-BitOffset)) 
					& 0x7F;
        if(BitOffset == 0) 
        {
            j--;
            BitOffset = 8;
        }
#if 0
		Octet[i] = convGsmToAscii(Octet[i]);
#endif
    }

    return i;
}

/* Added by dduckk, R210, 20160302, GSM 7bit의 decode function */
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

/* ASCII 7bit의 decode function */
int Decode7BitAsciiPack(byte *Septet, byte *Octet, int BitOffset, int Size)
{
    int             i, j;
    int             DecodedSize;

    DecodedSize = Size;

    for(i = 0, j = 0; i < DecodedSize; j++, BitOffset--)
    {
        if(BitOffset != 1)
        {
            Octet[j] = (Septet[i] << BitOffset - 1) & 0x7F;
            Octet[j] |= Septet[++i] >> 9 - BitOffset;
        }
        else
        {
            Octet[j++] = (Septet[i++] & 0x7F);
            Octet[j] = Septet[i] >> 1;
            BitOffset = 8;
        }
    }

    return i;
}
