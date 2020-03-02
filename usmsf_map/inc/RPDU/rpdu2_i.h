#ifndef RPDU2_IH
#define RPDU2_IH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __TYPE_BYTE_
#define __TYPE_BYTE_
    typedef unsigned char byte;
#endif

typedef struct {
	byte		  ElementId;		// added by dduckk, 20150225
	byte		  len;
	byte		  cause;
	byte		  diagnostic;
} RpCause;


typedef struct {
    byte          min[25];            //[InOut]    
    byte          ton;                //[InOut]    
    byte          npi;                //[InOut]    
    byte          len;                //[InOut]    
} RAddress;


typedef struct {
    RAddress      OrigAddr;          //[InOut]    
    RAddress      DestAddr;          //[InOut]    
    byte          RpDataLength;      //[InOut]    
	byte		  RpUserData[233];
} RpData;

typedef struct {
	byte		  ElementId;
    byte          RpDataLength;       //[InOut]    
	byte		  RpUserData[233];
} RpAck;

typedef struct {
	RpCause		  CauseCode;
	byte		  ElementId; 		  /* Added by dduckk, R210, 20160303, ElementID Ãß°¡ */
    byte          RpDataLength;       //[InOut]    
	byte		  RpUserData[233];
} RpError;


#if 0 		// dduckk 20150206, duplicated TPDU library
int Address_StructSetInOut(RAddress *Struct
        ,byte min[20]
        ,byte ton
        ,byte npi
        ,byte len
        ,byte reserved);

//--------------------------------------------------------
//
//   _StructGet
//   2001-05-24 11:57:44
//
//--------------------------------------------------------

int Address_StructGetInOut(RAddress *Struct
        ,byte min[20]
        ,byte *ton
        ,byte *npi
        ,byte *len
        ,byte *reserved);
//--------------------------------------------------------
//
//   _StructClear
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int Address_StructClearInOut(RAddress *Struct);
//--------------------------------------------------------
//
//   _StructToScreen
//   2001-05-24 11:57:44
//
//--------------------------------------------------------
int Address_StructToScreenInOut(RAddress *Struct);

#endif		// dduckk

#endif
