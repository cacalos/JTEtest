#ifndef __BITUTIL_H__
#define __BITUTIL_H__

#include "okhTypes.h"

/* Modify .. to Macro Version */
/*
unsigned GetBits(unsigned Source, int nBitPosition, int nGetBitCount);
unsigned SetBits(unsigned Source, int nBitPosition, int nSetBitCount, unsigned Data);
*/
// Macro Version
#define GetBits(Source, nBitPosition, nGetBitCount) \
			( ((unsigned)(Source) >> (nBitPosition)) \
				& ~(~0 << (nGetBitCount)) \
			)
#define SetBits(Source, nBitPosition, nSetBitCount, Data) \
			( ((unsigned)(Source) & ~( ~(~0 << (nSetBitCount)) << (nBitPosition))) \
				| ((unsigned)(Data) << (nBitPosition)) \
			)

//InputSize = Number of Octets , Output = Number of Octets(contain Septets)
#define Encoded7BitPackSize(InputSize, BitOffset) ( ((InputSize)*7+(BitOffset))/8 + (((InputSize)*7+(BitOffset))%8 != 0) )
//InputSize = Number of Octets(contain Septets) , Output = Number of Octets
#define Decoded7BitPackSize(InputSize, BitOffset) ( ((InputSize)*8-(BitOffset))/7 ) 

int GetSemiOctet(byte *Source, byte *Dest, int nLength, boolean isCharacter); //nLength = Dest ByteNumber = Source SemiOctetNumber
int SetSemiOctet(byte *Source, byte *Data, int nDataLength, boolean isCharacter); //nLength = Data Length = SemiOctetNumber
void PrintBits(byte *Data, int nByte);
void _okPrintBitField(TBits *Bits) ;
void PrintAllBitField(byte *Data, int nByte);
void PrintData(char *Data, int nByteSize);
int ConvertEndian_Int(int num);
short ConvertEndian_Short(short num);
int IsBigEndianSystem(void);

#endif
