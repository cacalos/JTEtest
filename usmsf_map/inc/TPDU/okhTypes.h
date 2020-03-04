
#ifndef __OKH_TYPES_H__
#define __OKH_TYPES_H__

typedef enum { TPDU_FALSE, TPDU_TRUE } boolean; 


#ifndef __TYPE_BYTE_
#define __TYPE_BYTE_
	typedef unsigned char byte;
#endif

	#ifndef _SYSTEM_LITTLE_ENDIAN
		typedef struct __bit_field
		{
			unsigned bit_7 : 1;
			unsigned bit_6 : 1;
			unsigned bit_5 : 1;
			unsigned bit_4 : 1;
			unsigned bit_3 : 1;
			unsigned bit_2 : 1;
			unsigned bit_1 : 1;
			unsigned bit_0 : 1;
		} TBits;

	#else
		typedef struct __bit_field
		{
			unsigned bit_0 : 1;
			unsigned bit_1 : 1;
			unsigned bit_2 : 1;
			unsigned bit_3 : 1;
			unsigned bit_4 : 1;
			unsigned bit_5 : 1;
			unsigned bit_6 : 1;
			unsigned bit_7 : 1;
		} TBits;
	#endif

typedef struct
{
	int Tag;
	int Length;
	byte *Value;
} TLV_t;

#endif
