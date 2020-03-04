#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TPDU/tpdu2_i.h"

//--------------------------------------------------------
//
//   SWAP4(int)
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int _SWAP4(int Value)
{
   int Temp;

   Temp=(Value<<24)  & 0xFF000000;
   Temp|=(Value<<8)  & 0x00FF0000;
   Temp|=(Value>>8)  & 0x0000FF00;
   Temp|=(Value>>24) & 0x000000FF;

   return Temp;
}

//--------------------------------------------------------
//
//   SWAP2(short)
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int _SWAP2(int Value)
{
   int Temp;

   Temp=(Value<<8) & 0xFF00;
   Temp|=(Value>>8) & 0x00FF;

   return Temp;
}


//--------------------------------------------------------
//
//   Address_StructSetInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int Address_StructSetInOut(TAddress *Struct
		,byte min[20]
		,byte ton
		,byte npi
		,byte len
		,byte reserved)
{

	memcpy((char *)Struct->min,(char *)min,len*1);
	Struct->ton=ton;
	Struct->npi=npi;
	Struct->len=len;
    /*
	Struct->reserved=reserved;
    */

	return sizeof(TAddress);
}


//--------------------------------------------------------
//
//   Address_StructGetInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int Address_StructGetInOut(TAddress *Struct
		,byte min[20]
		,byte *ton
		,byte *npi
		,byte *len
		,byte *reserved)
{

	if(min!=NULL) memcpy((char *)min,(char *)Struct->min,Struct->len*1);
	if(ton!=NULL) *ton=Struct->ton;
	if(npi!=NULL) *npi=Struct->npi;
	if(len!=NULL) *len=Struct->len;
    /*
	if(reserved!=NULL) *reserved=Struct->reserved;
    */

	return sizeof(TAddress);
}



//--------------------------------------------------------
//
//   Address_StructClearInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int Address_StructClearInOut(TAddress *Struct)
{

	memset((char *)Struct->min,0,20*1);
	Struct->ton=0;
	Struct->npi=0;
	Struct->len=0;
    /*
	Struct->reserved=0;
    */

	return sizeof(TAddress);
}


//--------------------------------------------------------
//
//   Address_StructToScreenInOut
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int Address_StructToScreenInOut(TAddress *Struct)
{
	printf("------------------------------------------------------\n");
	printf("Address_StructToScreenInOut(....)\n");
	printf("------------------------------------------------------\n");

	{ int i; for(i=0;i<Struct->len;i++) printf("min[%d] : %02X\n", i, Struct->min[i] & 0xFF);}
	printf("ton : %02X\n",  Struct->ton & 0xFF);
	printf("npi : %02X\n",  Struct->npi & 0xFF);
	printf("len : %02X\n",  Struct->len & 0xFF);
    /*
	printf("reserved : %02X\n",  Struct->reserved & 0xFF);
    */

	printf("------------------------------------------------------\n");
	return sizeof(TAddress);
}


