
#ifndef __TPDU_H__
#define __TPDU_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>

#include <iXtypes.h>
#include <TPDU/okhTypes.h>
#include <TPDU/tpdu2_i.h>
#include <TPDU/BitUtil.h>
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

// msg direction
#define DIRECTION_SC_MS             1
#define DIRECTION_MS_SC             2

// msg type
#define TPDU_SMS_DELIVER            1
#define TPDU_SMS_DELIVER_REPORT     2
#define TPDU_SMS_SUBMIT             3
#define TPDU_SMS_SUBMIT_REPORT      4
#define TPDU_SMS_STATUS_REPORT      5
#define TPDU_SMS_COMMAND            6
#define TPDU_SMS_HNETSTOP           7

//Data Coding Scheme : class
#define	TPDU_DCS_CLASS_0			0
#define	TPDU_DCS_CLASS_1			1
#define	TPDU_DCS_CLASS_2			2
#define	TPDU_DCS_CLASS_3			3

//Data Coding Scheme : alphabet
#define	TPDU_DCS_ALPHA_7			0
#define	TPDU_DCS_ALPHA_8			1
#define	TPDU_DCS_ALPHA_UCS2			2
#define TPDU_DCS_ALPHA_OTHER        3
#define TPDU_DCS_SHORTCUT			24

//Validity Period Format
#define TPDU_VPF_NOT_PRESENT		0
#define TPDU_VPF_ENHANCED			1
#define TPDU_VPF_RELATIVE			2
#define TPDU_VPF_ABSOLUTE			3

/* tag in elements of user data */
#define TPDU_ELEMENT_TAG_CONCATE_LONG		  0x08
#define TPDU_ELEMENT_TAG_CONCATE_SHORT        0X00
#define TPDU_ELEMENT_TAG_SPECIAL_VMN          0x01

typedef struct
{
	char MessageType;          /* TPDU_SMS_DELIVER            1 */
                               /* TPDU_SMS_DELIVER_REPORT     2 */
                               /* TPDU_SMS_SUBMIT             3 */
                               /* TPDU_SMS_SUBMIT_REPORT      4 */
                               /* TPDU_SMS_STATUS_REPORT      5 */
                               /* TPDU_SMS_COMMAND            6 */
	union
	{
		TSMSDeliver			SMSDeliver;
		TSMSDeliverReport 	SMSDeliverReport;
		TSMSSubmit 			SMSSubmit;
		TSMSSubmitReport 	SMSSubmitReport;
		TSMSStatusReport 	SMSStatusReport;
		TSMSCommand 		SMSCommand;
	}Union;

}_TPDU;


#ifndef _OAM_API_PROTYPE_H_

char GetTPDUMessageType(byte *Packet, int nFrom);
int DecodeTPDU(_TPDU *tpdu, byte *Packet, int PacketSize, int nFrom, boolean isRPError);
int EncodeTPDU(byte *Packet, _TPDU *tpdu, int nFrom, boolean isRPError);
int EncodeAddress(byte *EncodingData, int AddressLength, int TypeOfNumber, int NumberingPlanID, byte *AddressValue);
int DecodeAddress(byte *EncodedData, int *AddressLength, int *TypeOfNumber, int *NumberingPlanID, byte *AddressValue);
int AnalysisProtocolID(byte ProtocolID);
int EncodeTimeZone(int TimeZone);
int DecodeTimeZone(int TimeZone);
int EncodeServiceCenterTimeStamp(byte *EncodingData, int Year, int Month, int Day, int Hour, int Minute, int Second, int TimeZone);
int DecodeServiceCenterTimeStamp(byte *EncodedData, int *Year, int *Month, int *Day, int *Hour, int *Minute, int *Second, int *TimeZone);
int EncodeServiceCenterTimeStamp_tm(char *EncodingData, struct tm *t, int TimeZone);
int DecodeServiceCenterTimeStamp_tm(char *EncodedData, struct tm *t, int *TimeZone);
int CountTLVElement(byte *Data, int TotalSize);
byte EncodeParameterIndicator(boolean isPIDPresent, boolean isDCSPresent, boolean isUDLPresent);
int GetElements(byte *InputData, byte *OutputData, int InputDataSize);
int SetElements(byte *OutputData, byte *InputData, int elCnt);
int DecodeValidityPeriod(byte *EncodedData, byte *OutStruct, byte ValidityPeriodFormat);
int EncodeValidityPeriod(byte *EncodingData, byte *InputStruct, byte ValidityPeriodFormat);

int DecodeSMSDeliver(TSMSDeliver *SMSDeliver, byte *Packet, int PacketSize);
int EncodeSMSDeliver(byte *OutPacket, byte *InData);
int DecodeSMSDeliverReport(byte *OutStruct, byte *Packet, int PacketSize, boolean isRPError);
int EncodeSMSDeliverReport(byte *OutPacket, byte *InputData, boolean isRPError);
int DecodeSMSSubmit(byte *OutStruct, byte *Packet, int PacketSize);
int EncodeSMSSubmit(byte *OutPacket, byte *InputStruct);
int DecodeSMSSubmitReport(byte *OutStruct, byte *Packet, int PacketSize, boolean isRPError);
int EncodeSMSSubmitReport(byte *OutPacket, byte *InputStruct, boolean isRPError);
int DecodeSMSStatusReport(byte *OutStruct, byte *Packet, int PacketSize);
int EncodeSMSStatusReport(byte *OutPacket, byte *InputStruct);
int DecodeSMSCommand(byte *OutStruct, byte *Packet, int PacketSize);
int EncodeSMSCommand(byte *OutPacket, byte *InputStruct);

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
int ConvUserData3Gto2G(char *userData3, unsigned char dataLen3,
		        char *userData2, unsigned char *dataLen2,
				        unsigned char *encode);
#endif /* _OAM_API_PROTYPE_H_ */

#endif
