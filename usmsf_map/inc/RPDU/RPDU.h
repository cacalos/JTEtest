
#ifndef __RPDU_H__
#define __RPDU_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>

#include <iXtypes.h>
#include <RPDU/okhTypes.h>
#include <RPDU/rpdu2_i.h>
#include <RPDU/BitUtil.h>
#include <ASN/asn_smsc.h>

#define MAX_SIZE_TP_UD            	140

// decode error code
#define TPDU_DEC_SUCC				0
#define TPDU_DEC_ERR_UDL			-10
#define TPDU_DEC_ERR_UDLMAX			-11
#define TPDU_DEC_ERR_UDHL			-20
#define TPDU_DEC_ERR_IEL			-21
#define TPDU_DEC_ERR_ADDRLEN		-30
#define TPDU_DEC_ERR_VPF			-40

/* added by dduckk, for RP-Message(RPDU) */
// rpdu direction
#define DIRECTION_N_MS             	1
#define DIRECTION_MS_N				2

// msg type
#define RPDU_RP_DATA            	0
#define RPDU_RP_ACK     			1
#define RPDU_RP_ERROR           	2
#define RPDU_RP_SMMA      			3
#define RPDU_RP_RESERVED			4

#define MSG_DATA 		0
#define MSG_RESP		1

#define RPDU_MSGTYPE_STR(s) \
	(s == RPDU_RP_DATA     ? "RPDU_RP_DATA" :\
	 s == RPDU_RP_ACK      ? "RPDU_RP_ACK":\
	 s == RPDU_RP_ERROR    ? "RPDU_RP_ERROR" :\
	 s == RPDU_RP_SMMA     ? "RPDU_RP_SMMA" :\
	 s == RPDU_RP_RESERVED ? "RPDU_RP_RESERVED" : "UNKNOWN")

typedef struct
{
	char direction;
	char MessageType;          /* RPDU_RP_MO_DATA(M->N)     0 */
							   /* RPDU_RP_MT_DATA(N->M)		1 */
                               /* RPDU_RP_MT_ACK(M->N)		2 */
                               /* RPDU_RP_MO_ACK(N->M)		3 */
                               /* RPDU_RP_MT_ERROR(M->N)    4 */
                               /* RPDU_RP_MO_ERROR(N->M)    5 */
                               /* RPDU_RP_SMMA(M->N)   		6 */
	unsigned char MessageReference;

	union
	{
		RpData				rData;
		RpAck				rAck;
		RpError				rError;
//		RpSMMA				rSma;
	}Union;

}_RPDU;


#ifndef _OAM_API_PROTYPE_H_

char GetRPDUMessageType(byte *Packet, int nFrom);
int DecodeRPDU(_RPDU *tpdu, byte *Packet, int PacketSize, int nFrom);
int EncodeRPDU(byte *Packet, _RPDU *tpdu, boolean isRPError);
int DecodeRpData(RpData *rData, int nFrom, byte *Packet, int PacketSize);
int EncodeRpAddress(byte *EncodingData, int AddressLength, int TypeOfNumber, int NumberingPlanID, byte *AddressValue);
int DecodeRpAddress(byte *EncodedData, int *AddressLength, int *TypeOfNumber, int *NumberingPlanID, byte *AddressValue);
byte EncodeParameterIndicator(boolean isPIDPresent, boolean isDCSPresent, boolean isUDLPresent);
int GetElements(byte *InputData, byte *OutputData, int InputDataSize);
int SetElements(byte *OutputData, byte *InputData, int elCnt);
int EncodeMessageTypeIndicator(int direction, char type);


int ConvISDNStringToAddress(ISDN_AddressString *isdn, stAddr *addr);
int ConvAddressToCBString(stAddr *addr, FTN_AddressString *isdn);
int ConvAddressToISDNString(stAddr *addr, ISDN_AddressString *isdn);
int ConvAddressToAddressString(stAddr *addr, AddressString *adstr);
int ConvAddressStringToAddress(AddressString *adstr, stAddr *addr);
int ConvStrToAddressString(int len, char *str, AddressString *adstr);
int ConvAddressStringToStr(AddressString *adstr, int *len, char *str);
int ConvAddressToCenterAddress(stAddr *addr, AddressString *addrSC);
int ConvIMSIToAddress(IMSI *imsi, stAddr *addr);
int ConvAddressToIMSI(stAddr *addr, IMSI *imsi);
#endif /* _OAM_API_PROTYPE_H_ */

#endif
