#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <iconv.h>

//#include <iXtypes.h>
//#include <iXEngine.h>
#include <SS7/ix7map.h>
#include <sigtran_util.h>
#include <iXLog.h>
#include <iXCauseCode.h>
#include <TPDU/tpdu2_i.h>
#include <TPDU/TPDU.h>

#include <ASN/asn_smsc.h>

#define CVRT_DCS_CP949              "CP949"
#define CVRT_DCS_UCS2BE             "UCS-2BE"

#define TPDU_ELEMENT_TAG_APP_PORT_16          0x05
#define TPDU_ELEMENT_TAG_CALLBACK             0x22

#define MT_CONF_FILE_PATH           "./sendmt3.conf"
#define PARAM_BUFFER_SIZE            1024

#define APP_ID_HLR3                  2
#define APP_ID_HLR2                  3
#define APP_ID_MSC3                  4
#define APP_ID_MSC2                  5
#define APP_ID_SGSN                  6
#define APP_ID_SMSC                  7

#define INS_ID_NODE                  1
#define INS_ID_ALERT                 2
#define INS_ID_MO                    3

#define ADDRESS_NUM_SIZE             25

int                   MyPC;
int                   MySSN          = 8;
char 				  MyGT[100];
int 				  orig_type = 1;
char                  StackName[20]  = "SS7_Stack";
int                   SendCount;

int                   DestPC;
int                   DestSSN;
int                   gMapVersion = 3;
int                   gContCnt = 0  ; 

/* OSS Global */
OssBuf                param;
struct ossGlobal      w, *world = &w;
unsigned short		  gOsfi = 0;
unsigned char		  gRoamingInd = 0;

int     ud_chk, check = 0;

int     gPID;
int     gDCS;
char    gUD[512];
char    maxUD[4096];
int     gUDLen = 0;
int     maxUDLen = 0;
int     nowLen = 0;
int     devideLen = 0;
char    gCBNum[24];

/* for GT */
int                  mflag = 0, sflag = 0;
char                 origMGT[40], destMGT[40];
char                 origSGT[40], destSGT[40];

stAddr gOrigAddr;
#ifdef LINUX
extern char *optarg;
extern int optind;
#endif

static int  first = 1;

unsigned long         gTotalSendNum = 0, gTotalRcvNum = 0, gMaxSendMsg;
int                   gPerformanceMode = 0;
int                   gConcRefNo = 0, gConcTotal = 0, gConcSeqNo = 0;
unsigned short        gSrcPort = 0, gDestPort = 0;


MT_ForwardSM_Arg_V3   G_mo;
char cont_userData[100][600];

/* for sigtran */
UTcap *gTcapInfo;


void CloseProc()
{
	exit(0);
}

int ConvDCS(char *userData, int *dataLen, char *codeFrom, char *codeTo)
{
#define CONV_BUFSIZ     (4096*2)
	int     utfLen = *dataLen;
	char    utfData[CONV_BUFSIZ];

	size_t  inleft, outleft;
	char    *inptr, *outptr;
	size_t  ret;

	static iconv_t  cd = (iconv_t)-1;
	static char     from[64]={0}, to[64]={0};

	if(strcmp(from, codeFrom) != 0 || strcmp(to, codeTo) != 0)
	{
		memset(from, 0x0, sizeof(from));
		memset(to, 0x0, sizeof(to));

		if(cd != (iconv_t)-1)
		{
			iconv_close(cd);
			cd = (iconv_t)-1;
		}
	}
	/* init iconv */
	if(cd == (iconv_t)-1)
	{
		strcpy(from, codeFrom);
		strcpy(to, codeTo);

		if((cd = iconv_open(to, from)) == (iconv_t)-1)
		{
			printf("Conv DCS failed; iconv open fail, from[%s] to[%s] errno[%d]\n", from, to, errno);
			*dataLen = 0;
			userData[0] = NULL;
			return -1;
		}

		printf("iconv open success, from[%s] to[%s] cd[%d]\n", from, to, (int)cd);
	}

	inptr   = userData;
	outptr  = utfData;
	inleft  = utfLen;
	outleft = CONV_BUFSIZ;

	ret = iconv(cd, &inptr, &inleft, &outptr, &outleft);
	if(ret == (size_t)-1)
	{
		printf("Conv DCS failed; iconv fail, from[%s] to[%s] errno[%d] len[%d]\n", from, to, errno, *dataLen);

		*dataLen = 0;
		userData[0] = NULL;
		return -1;
	}
	utfLen = (size_t)CONV_BUFSIZ - outleft;

	*dataLen = utfLen;
	memcpy(userData, utfData, utfLen);
	userData[*dataLen] = '\0';

	return 0;
}

int Sendmo3ConvAddressToISDNString(stAddr *addr, ISDN_AddressString *isdn)
{
	int i;
	int j=0;
	int flag=0;

	if(addr->len > 20) return(-1);

	bzero(isdn, sizeof(ISDN_AddressString));
	isdn->value[0] = 0x80 | addr->ton << 4 | addr->npi;
	isdn->length++;

	for(i=0; i < addr->len; i++) {

		flag = 0;
		switch(addr->min[i]) {
			case '*':
				isdn->value[i/2+1] = 10;
				flag=1;
				break;
			case '#':
				isdn->value[i/2+1] = 11;
				flag=1;
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
		if (i == addr->len) break;

		switch(addr->min[i]) {
			case '*':
				isdn->value[i/2+1] |= 10 << 4;
				flag=1;
				break;
			case '#':
				isdn->value[i/2+1] |= 11 << 4;
				flag=1;
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

		if(flag)
			j++;
	}

	if(j > 5) {
		bzero(isdn, sizeof(ISDN_AddressString));
		return (-1);
	}

	if( i%2 == 1)
		isdn->value[i/2+1] |= 0xf0;

	return(1);
}

int makeAddress(char *destAddr)
{
	int     i, wildCharCount = 0;
	int     divValue, addrNumber, temp;
	static int tailPrefix = 0;
	char    tempAddr[ADDRESS_NUM_SIZE];

	strncpy(tempAddr, destAddr, ADDRESS_NUM_SIZE);

	if(!check)
		tailPrefix++;

	for(i = strlen(tempAddr)-1; i > -1 ; i--) {
		if(tempAddr[i] == '*') {
			wildCharCount++;
		} else {
			tempAddr[i+1] = '\0';
			break;
		}
	}

	if(!strncmp(tempAddr, "82", 2))
	{
		if(strlen(tempAddr) >= 11)  wildCharCount = 0;
		else    strcpy(destAddr, tempAddr);
	} else
	{
		if(strlen(tempAddr) >= 10)  wildCharCount = 0;
		else    strcpy(destAddr, tempAddr);
	}

	if(wildCharCount == 0) {
		printf("\n>>>>> MIN:[%s]\n", destAddr);
		return 0;
	}

	divValue = 1;
	for(i = 0; i < wildCharCount; i++) {
		divValue *= 10;
	}

	if(tailPrefix != 0) {
		addrNumber = tailPrefix % divValue;
	} else {
		addrNumber = 0;
	}

	temp = addrNumber;
	if(temp == 0) temp = 1;
	for(i = 0; i < wildCharCount; i++) {
		temp *= 10;
		if(temp >= divValue) break;

		sprintf(&destAddr[strlen(destAddr)], "0");

	}

	sprintf(&destAddr[strlen(destAddr)], "%d", addrNumber);

	return wildCharCount;
}

int MakeUI(stAddr *orig, SignalInfo *ui)
{
	char                ch1, ch2, encode;
	ISDN_AddressString  isdn;
	struct tm          *ptm;
	time_t              now;
	char                buf[1024];
	TUserData           tpdu;
	boolean             isContainerHeader = 0;

	/* for ucs2 */
	char                userData[4096];
	int                 i, len = 0;

	memset(&tpdu, 0x00, sizeof(TUserData));
	ui->length = 0;
	ui->value[ui->length] = 0x00;   /* TP-MTI */

	if(gConcRefNo > 0 && gConcTotal > 0) {
		ui->value[ui->length] |= 0x40;

		tpdu.udh.Length += 1+1+3;
		tpdu.udh.eiCnt++;
		tpdu.udh.ei[tpdu.udh.eiCnt-1].ID =
			TPDU_ELEMENT_TAG_CONCATE_SHORT;
		tpdu.udh.ei[tpdu.udh.eiCnt-1].Length = 0x03;
		tpdu.udh.ei[tpdu.udh.eiCnt-1].Data[0] = gConcRefNo;
		tpdu.udh.ei[tpdu.udh.eiCnt-1].Data[1] = gConcTotal;
		tpdu.udh.ei[tpdu.udh.eiCnt-1].Data[2] = gConcSeqNo;
		isContainerHeader = 1;
	}

	/* 16bit Port Addressing */
	if(gSrcPort > 0 || gDestPort > 0) {
		ui->value[ui->length] |= 0x40;

		tpdu.udh.Length += 1+1+4;
		tpdu.udh.eiCnt++;
		tpdu.udh.ei[tpdu.udh.eiCnt-1].ID =
			TPDU_ELEMENT_TAG_APP_PORT_16;
		tpdu.udh.ei[tpdu.udh.eiCnt-1].Length = 0x04;
		tpdu.udh.ei[tpdu.udh.eiCnt-1].Data[0] = (gDestPort & 0XFF00) >> 8;
		tpdu.udh.ei[tpdu.udh.eiCnt-1].Data[1] = (gDestPort & 0X00FF);
		tpdu.udh.ei[tpdu.udh.eiCnt-1].Data[2] = (gSrcPort & 0XFF00) >> 8;
		tpdu.udh.ei[tpdu.udh.eiCnt-1].Data[3] = (gSrcPort & 0X00FF);
		isContainerHeader = 1;
	}

	if(gConcRefNo > 0 && gConcTotal > 0 && gConcTotal != gConcSeqNo) 
		ui->value[ui->length++] |= 0x00;  /* Not MMS */
	else
		ui->value[ui->length++] |= 0x04;  /* MMS */

	ui->value[ui->length++] = orig->len;

	Sendmo3ConvAddressToISDNString(orig, &isdn);
	memcpy(&ui->value[ui->length], isdn.value, isdn.length);
	ui->length += isdn.length;

	ui->value[ui->length++] = gPID;

	ui->value[ui->length++] = gDCS;

	tzset();
	time(&now);
	ptm = localtime((time_t *)&now);

	ch1 = (ptm->tm_year % 100) / 10;
	ch2 = ptm->tm_year % 10;
	ui->value[ui->length++] = ch1 | (ch2 << 4);

	ch1 = (ptm->tm_mon+1) / 10;
	ch2 = (ptm->tm_mon+1) % 10;
	ui->value[ui->length++] = ch1 | (ch2 << 4);

	ch1 = ptm->tm_mday / 10;
	ch2 = ptm->tm_mday % 10;
	ui->value[ui->length++] = ch1 | (ch2 << 4);

	ch1 = ptm->tm_hour / 10;
	ch2 = ptm->tm_hour % 10;
	ui->value[ui->length++] = ch1 | (ch2 << 4);
	len++;

	ch1 = ptm->tm_min / 10;
	ch2 = ptm->tm_min % 10;
	ui->value[ui->length++] = ch1 | (ch2 << 4);
	len++;

	ch1 = ptm->tm_sec / 10;
	ch2 = ptm->tm_sec % 10;
	ui->value[ui->length++] = ch1 | (ch2 << 4);
	len++;

	ui->value[ui->length++] = EncodeTimeZone((int)timezone / 900) & 0xFF;
	len++;

	encode = GetEncodeFromDcs(gDCS);
	len = gUDLen;
	memcpy(userData, gUD, len);

	memcpy(tpdu.Data, userData, len);

	tpdu.DataLength = len;

	ui->value[ui->length] = EncodeUserData(&(ui->value[ui->length+1]),
			&tpdu, gDCS, isContainerHeader);

	if(encode == ENCODE_7BIT_GSM ||  encode == ENCODE_7BIT_ASCII)
		ui->length += ((ui->value[ui->length] * 7 + 7) / 8);
	else
		ui->length += ui->value[ui->length];

	ui->length++;

	memcpy(buf, ui->value, ui->length);

	if(!gPerformanceMode) {
		printf("\nTPDU RAW DATA\n");
		for(i=0; i < ui->length; i++) {
			printf(" %02X", (byte)buf[i]);
			if(i+1 % 10 == 0)
				printf("\n");
		}
	}

	return 0;
}


int GetMtConf(char *file)
{
	int len, nTemp;
    char               buf[4096];
	stAddr	addr;
	//stISDN_AddressString isdn;

	bzero((void*)&G_mo, sizeof(G_mo));

    if(ok_getConf(file, "STACK_NAME", buf, false) < 0) return -1;
	strcpy(StackName, buf);

    if(ok_getConf(file, "MY_PCODE", &nTemp, true) < 0) return -1;
	MyPC = nTemp;

    if(ok_getConf(file, "MY_SSN", &nTemp, true) < 0) return -1;
	MySSN = nTemp;

    if(ok_getConf(file, "DEST_PCODE", &nTemp, true) < 0) return -1;
	DestPC = nTemp;

    if(ok_getConf(file, "DEST_SSN", &nTemp, true) < 0) return -1;
	DestSSN = nTemp;

	if(ok_getConf(file, "MAP_VERSION", &nTemp, true) < 0) return -1;
	gMapVersion = nTemp;

    if(ok_getConf(file, "mo.bit_mask", &nTemp, true) < 0) return -1;
	G_mo.bit_mask = nTemp;

    if(ok_getConf(file, "UI_SET", &nTemp, true) < 0) return -1;
	ud_chk = nTemp;

    if(ok_getConf(file, "SEND_COUNT", &nTemp, true) < 0) return -1;
	SendCount = nTemp;

//DA
    if(ok_getConf(file, "mo.sm_RP_DA.choice", &nTemp, true) < 0) return -1;
	G_mo.sm_RP_DA.choice = nTemp;

	if(G_mo.sm_RP_DA.choice == SM_RP_DA_imsi_chosen)
	{
		/*	
		if(ok_getConf(file, "mo.sm_RP_DA.u.imsi.value", buf, false) >= 0)
		{
			len = makeDataFromHexaString(buf, G_mo.sm_RP_DA.u.imsi.value);
			G_mo.sm_RP_DA.u.imsi.length = len;
			printf("\n DEST ADDR = [%s:%s]\n" , buf, G_mo.sm_RP_DA.u.imsi.value ) ;
		}
		else
		*/
		{
			bzero((void*)&addr, sizeof(addr));
			if(ok_getConf(file, "mo.sm_RP_DA.u.imsi.ton", &nTemp, true)<0)
				return -1; 
			addr.ton = nTemp;
			if(ok_getConf(file, "mo.sm_RP_DA.u.imsi.npi", &nTemp, true)<0)
				return -1; 
			addr.npi = nTemp;
			if(ok_getConf(file, "mo.sm_RP_DA.u.imsi.min", buf, false)<0)
				return -1; 
			strcpy(addr.min, buf);
			addr.len = strlen(addr.min);
			ConvAddressToIMSI(&addr, &G_mo.sm_RP_DA.u.imsi);
			//printf("\n DEST ADDR = [%s:%s]\n" , addr, &G_mo.sm_RP_DA.u.imsi.value ) ;
		}
	}
	else if(G_mo.sm_RP_DA.choice == lmsi_chosen)
	{
		if(ok_getConf(file, "mo.sm_RP_DA.u.lmsi.value", buf, false) < 0) return -1;

		len = makeDataFromHexaString(buf, G_mo.sm_RP_DA.u.lmsi.value);
		G_mo.sm_RP_DA.u.lmsi.length = len;
	}
	else if(G_mo.sm_RP_DA.choice == serviceCentreAddressDA_chosen)
	{
		if(ok_getConf(file, 
			"mo.sm_RP_DA.u.serviceCentreAddressDA.value", buf, false) >= 0) 
		{
			len = makeDataFromHexaString(buf, 
						G_mo.sm_RP_DA.u.serviceCentreAddressDA.value);
			G_mo.sm_RP_DA.u.serviceCentreAddressDA.length = len;
		}
		else
		{
			bzero((void*)&addr, sizeof(addr));
			if(ok_getConf(file, 
				"mo.sm_RP_DA.u.serviceCentreAddressDA.ton", &nTemp, true)<0)
				return -1; 
			addr.ton = nTemp;
			if(ok_getConf(file, 
				"mo.sm_RP_DA.u.serviceCentreAddressDA.npi", &nTemp, true)<0)
				return -1; 
			addr.npi = nTemp;
			if(ok_getConf(file, 
				"mo.sm_RP_DA.u.serviceCentreAddressDA.min", buf, false)<0)
				return -1; 
			strcpy(addr.min, buf);
			addr.len = strlen(addr.min);
			len = ConvAddressToAddressString(&addr, 
					&G_mo.sm_RP_DA.u.serviceCentreAddressDA);
		}
	}
	else if(G_mo.sm_RP_DA.choice == noSM_RP_DA_chosen)
	{
		if(ok_getConf(file, "mo.sm_RP_DA.u.noSM_RP_DA", &nTemp, true) < 0) return -1;
		G_mo.sm_RP_DA.u.noSM_RP_DA = nTemp;
	}

//OA
    if(ok_getConf(file, "mo.sm_RP_OA.choice", &nTemp, true) < 0) return -1;
	G_mo.sm_RP_OA.choice = nTemp;

	if(G_mo.sm_RP_OA.choice == SM_RP_OA_msisdn_chosen)
	{
		if(ok_getConf(file, "mo.sm_RP_OA.u.msisdn.value", buf, false) >= 0) 
		{
			len = makeDataFromHexaString(buf, G_mo.sm_RP_OA.u.msisdn.value);
			G_mo.sm_RP_OA.u.msisdn.length = len;
			printf("\n ORIG ADDR = [%s:%s]" , buf, G_mo.sm_RP_OA.u.msisdn.value ) ;
		}
		else
		{
			bzero((void*)&addr, sizeof(addr));
			if(ok_getConf(file, "mo.sm_RP_OA.u.msisdn.ton", &nTemp, true)<0)
				return -1; 
			addr.ton = nTemp;
			if(ok_getConf(file, "mo.sm_RP_OA.u.msisdn.npi", &nTemp, true)<0)
				return -1; 
			addr.npi = nTemp;
			if(ok_getConf(file, "mo.sm_RP_OA.u.msisdn.min", buf, false)<0)
				return -1; 
			strcpy(addr.min, buf);
			addr.len = strlen(addr.min);
			len = ConvAddressToISDNString(&addr, &G_mo.sm_RP_OA.u.msisdn);
		}
	}
	else if(G_mo.sm_RP_OA.choice == serviceCentreAddressOA_chosen)
	{
		if(ok_getConf(file, 
			"mo.sm_RP_OA.u.serviceCentreAddressOA.value", buf, false) >= 0) 
		{
			len = makeDataFromHexaString(buf, G_mo.sm_RP_OA.u.serviceCentreAddressOA.value);
			G_mo.sm_RP_OA.u.serviceCentreAddressOA.length = len;
		}
		else
		{
			bzero((void*)&addr, sizeof(addr));
			if(ok_getConf(file, 
				"mo.sm_RP_OA.u.serviceCentreAddressOA.ton", &nTemp, true)<0)
				return -1; 
			addr.ton = nTemp;
			if(ok_getConf(file, 
				"mo.sm_RP_OA.u.serviceCentreAddressOA.npi", &nTemp, true)<0)
				return -1; 
			addr.npi = nTemp;
			if(ok_getConf(file, 
				"mo.sm_RP_OA.u.serviceCentreAddressOA.min", buf, false)<0)
				return -1; 
			strcpy(addr.min, buf);
			addr.len = strlen(addr.min);
			len = ConvAddressToAddressString(&addr, 
					&G_mo.sm_RP_OA.u.serviceCentreAddressOA);
		}
	}
	else if(G_mo.sm_RP_OA.choice == noSM_RP_OA_chosen)
	{
		if(ok_getConf(file, "mo.sm_RP_OA.noSM_RP_OA", &nTemp, true) < 0) return -1;
		G_mo.sm_RP_OA.u.noSM_RP_OA = nTemp;
	}


	if(ud_chk <  1)
	{
		if(ok_getConf(file, "mo.sm_RP_UI.value", buf, false) < 0) 
		{
			system("clear");
			printf("[mo.sm_RP_UI.value] NOT FOUND!!\n");
			printf("\ninput UI(Hexa String) : ");
			len = makeDataFromHexaString2(stdin, G_mo.sm_RP_UI.value);
			G_mo.sm_RP_UI.length = len;
		}
		else
		{
			len = makeDataFromHexaString(buf, G_mo.sm_RP_UI.value);
			G_mo.sm_RP_UI.length = len;
		}
		check = 0;
	}
	else
	{
		if(ok_getConf(file, "orig.min", &nTemp, true) < 0) 
		{
			printf("Conf: can't find 'dest.min' item <%s>\n", file);
			return -1;
		}
		else
		{
			bzero((void*)&addr, sizeof(addr));
			if(ok_getConf(file, "orig.ton", &nTemp, true) < 0)
				return -1;
			addr.ton = nTemp;
			if(ok_getConf(file, "orig.npi", &nTemp, true) < 0)
				return -1;
			addr.npi = nTemp;
			if(ok_getConf(file, "orig.min", buf, false) < 0)
				return -1;

			strcpy(addr.min, buf);

			makeAddress(addr.min);
			addr.len = strlen(addr.min);

			/* set orig addr for MakeUI */
			memcpy(&gOrigAddr, &addr, sizeof(stAddr));
		}

		if(first)
		{
			if(getConf(file, "PID", buf) < 0) 
			{
				printf("Conf: can't find 'PID' item in <%s>\n", file);
				return -1;
			}
			else
				gPID = atoi(buf);

			if(getConf(file, "DCS", buf) < 0) 
			{
				printf("Conf: can't find 'DCS' item in <%s>\n", file);
				return -1;
			}
			else
				gDCS = atoi(buf);

			if(!check) 
			{
				if(getConf(file, "UD", buf) < 0)
				{
					printf("Conf: can't find 'UD' item in <%s>\n", file);
					return -1;
				}
				else
				{
					strcpy(maxUD, buf);
					maxUDLen = strlen(maxUD);
					printf("\n\nScan UD[%s(%d)]\n", maxUD, maxUDLen);

					char encode = GetEncodeFromDcs(gDCS);
					char           userData[4096] = "\0";
					int            tmpLen = 0;

					if(encode == ENCODE_UCS2) 
					{
						tmpLen = maxUDLen;
						memcpy(userData, maxUD, tmpLen);
						if( ConvDCS(userData, &tmpLen, CVRT_DCS_CP949, CVRT_DCS_UCS2BE) < 0) 
						{
							printf("DCS convert error.\n");
							exit(0);
						}

						if(!gPerformanceMode)
							printf("UCS2 convert success.[%d] --> [%d]\n", gUDLen, tmpLen);

						maxUDLen = tmpLen;
						memcpy(maxUD, userData, tmpLen);
						maxUD[tmpLen] = '\0';
					}
					else if(encode == ENCODE_7BIT_GSM) 
					{
						unsigned short gsmLen = tmpLen;

						Conv7BitASCto7BitGSM(maxUD, maxUDLen, userData, &gsmLen);
						maxUDLen = gsmLen;
						memcpy(maxUD, userData, gsmLen);
						maxUD[gsmLen] = '\0';
					}
				}

				if(getConf(file, "conc_refno", buf) >= 0)
					gConcRefNo = atoi(buf);

				if(getConf(file, "conc_seqno", buf) >= 0)
					gConcSeqNo = atoi(buf);

				if(getConf(file, "conc_total", buf) >= 0)
					gConcTotal = atoi(buf);

				if(getConf(file, "src_port", buf) >= 0)
					gSrcPort = (unsigned short)atoi(buf);

				if(getConf(file, "dest_port", buf) >= 0)
					gDestPort = (unsigned short)atoi(buf);

				printf("[gSrcPort = %u[%x], gDestPort = %u[%x]\n", gSrcPort, gSrcPort, gDestPort, gDestPort);
			}

			if(check) 
			{
				memset(&gUD, 0x00, sizeof(gUD));
				if(gConcSeqNo == gConcTotal) 
				{
					check = 0;
					gUDLen = maxUDLen - nowLen;
					memcpy(gUD, &maxUD[nowLen], gUDLen);
				}
				else 
				{
					memcpy(gUD, &maxUD[nowLen], devideLen);
					gUDLen = devideLen;
				}
			} 
			else
			{
				char encode = GetEncodeFromDcs(gDCS);

				if(encode == ENCODE_UCS2)
					devideLen = 140;
				else if(encode == ENCODE_7BIT_GSM)
					devideLen = 160;
				else
					devideLen = 140;

				printf("%d %d\n", devideLen, maxUDLen);

				if(maxUDLen > devideLen)
				{
					check = 1;
					srand(time(NULL));
					if(gConcRefNo == 0)
						gConcRefNo = fmod(rand(), 254);

					devideLen -= 7; /* conct */

					gConcSeqNo = 1;
					gConcTotal = ceil((double)maxUDLen / devideLen);
					memcpy(gUD, maxUD, devideLen);
					gUDLen = devideLen;
					nowLen = 0;
				}
				else 
				{
					memcpy(gUD, maxUD, maxUDLen);
					gUDLen = maxUDLen;
				}

				if(encode == ENCODE_UCS2) 
				{
					if(devideLen % 2)
						devideLen--;
				}
				else if(encode == ENCODE_7BIT_GSM) 
				{
					if(maxUD[devideLen-1] == 0x1b)
						devideLen--;
				}
			}
		}

		printf("\n >>>>>>>>> MT UI Info = orig:%s ref:%d tot:%d seq:%d udLen:%d check:%d %d\n\n", 
				addr.min, gConcRefNo, gConcTotal,  gConcSeqNo, gUDLen, check);
		MakeUI(&gOrigAddr, &G_mo.sm_RP_UI);
	}

    return 1;
}
int TransMsisdnToLmsi(stAddr addr, LMSI *lmsi)
{
    int           n;
    char          min[11];

    memcpy(min, addr.min, addr.len);
    min[10] = 0;
    n = atoi(min);
    memcpy(lmsi->value, (int *)&n, 4);
    lmsi->length = 4;
    return 1;
}

int SendMt3()
{
	int 							ret, opCode, acn;
    int                            	comp_len;
    stAddr                         	addr;
	ForwardSM_Arg_V2               	fwd;

    USccpAddr						orig, dest;

    param.length = 0;
    param.value = NULL;

	memset(&dest, 0, sizeof(USccpAddr));
	memset(&orig, 0, sizeof(USccpAddr));
	bzero((void *)&addr, sizeof(addr));

	strcpy(addr.min, "976881234444");

	if(mflag)
	{
		sig_makeGT(&dest, destMGT, 0, 0); 
		sig_makeGT(&orig, origMGT, 0, 0);
	} 
	else if(sflag)
	{
		sig_makeGT(&dest, destSGT, 0, DestSSN);
		sig_makeGT(&orig, origSGT, 0, MySSN);
	}
	else
	{
		dest.ind = USccpAddrInd_ROUTE_ON_SSN_PC|USccpAddrInd_PC_PRESENT|USccpAddrInd_SSN_PRESENT;
		dest.pc = DestPC;
		dest.ssn = DestSSN;

		orig.ind = USccpAddrInd_ROUTE_ON_SSN_PC|USccpAddrInd_PC_PRESENT|USccpAddrInd_SSN_PRESENT;
		orig.pc = MyPC;
		orig.ssn = MySSN;
	}

	if(gMapVersion == 3)
	{
		if(ossEncode(world, MT_ForwardSM_Arg_V3_PDU, &G_mo, &param))
		{
			printf("ossEncode error: %s\n", ossGetErrMsg(world));
			return -1;
		}
		opCode  = mt_forwardSM_V3.u.localValue ;
		acn     = ACN_MT_V3 ;
	}
	else
	{
		memcpy(&fwd, &G_mo, sizeof(ForwardSM_Arg_V2));
		if(ossEncode(world, ForwardSM_Arg_V2_PDU, &fwd, &param))
		{
			printf("ossEncode error: %s\n", ossGetErrMsg(world));
			return -1;
		}
		opCode  = forwardSM_V2.u.localValue ;
		if(gMapVersion == 2)
			acn     = ACN_MT_V2;
		else if(gMapVersion == 1)
			acn     = ACN_MT_V1;
		else
			acn     = 0;
	}


	if((ret = sig_sendBeginInvoke(gTcapInfo, opCode, 1, &orig, &dest, 40, (u_char*)param.value, param.length, acn, NULL)) < 0)
	{
		printf("\n [%s] Diag send failed [%d] ", G_mo.sm_RP_DA.u.imsi.value, ret);
		return -1;
	}
	printf("\n [%s] Diag sent" , G_mo.sm_RP_DA.u.imsi.value);

	return IXOK;
}



int receiveFromSMSC()
{
    int                             nCnt = 0 , diagId;
    struct timeval                  timeout;
    int                             selectRc, rval2, compNum, rCnt;
    bool                            isActive;
    UTcapPrimitive                  prim;
    UTcapComponents                 comp;
    time_t                          now ;

    do 
	{
		timeout.tv_sec = 5;
		//timeout.tv_usec = 100000;    /* 100 msec ; 100000->10000 */
		timeout.tv_usec = 0;    /* 10000 msec -> 10 sec */

        selectRc = utcap_select( gTcapInfo, 1, NULL, NULL, NULL, &timeout, &isActive);

        if(isActive)
		{
            int i, isComp;
            int userDid, provId, pType;

            /* read messages incoming from TCAP */
            rval2 = utcap_recv( gTcapInfo, (void*)&prim, &isComp, &compNum);
            if(rval2 < 0)
			{
                printf("utcap_recv() failed : ec=%d", u_ec());
                return -1;
            }

            rCnt ++;

            if(!(prim.type == UTcapPrimitiveType_DAT_IND && prim.u.datInd.msgType == UTCAP_END))
			{
                ProcPrim(&prim);
                continue;
            }

            printf("New Msg Received [%d]th %s isComp=%d compNum=%d", ++nCnt, UTCAP_TRANSACTION_STR( prim.u.datInd.msgType), isComp, compNum);

            pType  = prim.type ;
            userDid    = prim.u.datInd.suDlgId ;
            provId =  prim.u.datInd.spDlgId ;

            printf("[%d] p_type[%s] u_id[%d] prov_id[%d]\n", time(&now), UTCAP_TRANSACTION_STR(pType) , userDid, provId);

            for(i=0; i<compNum; i++)
			{
                rval2 = utcap_getComp(gTcapInfo, userDid, provId, &comp);
                if(rval2 < 0)
				{
                    printf("utcap_getComp failed E=%d", rval2);
                }
                else
				{
					diagId = userDid;

					if(comp.compType != UTCAP_COMP_RET_RES_L && comp.compType != UTCAP_COMP_ERROR && comp.compType != UTCAP_COMP_INVOKE)
					{
						ProcComp(&comp);
						break;
					}
					if(comp.compType == UTCAP_COMP_RET_RES_L || comp.compType == UTCAP_COMP_RET_RES_NL || comp.compType == UTCAP_COMP_INVOKE)
					{
						printf("\n RECEIVED R.R, COMP TYPE [%s]" ,
								comp.compType == UTCAP_COMP_RET_RES_L ? "UTCAP_COMP_RET_RES_L" :
								comp.compType == UTCAP_COMP_RET_RES_NL ? "UTCAP_COMP_RET_RES_NL" :
								comp.compType == UTCAP_COMP_INVOKE ? "UTCAP_COMP_INVOKE" : ""  ) ;
#if 0
						if ( handleREQResult( &prim, &comp) < 0)
							break;
#endif
					}
				}
			}
		}
		else
			printf("select is not active.....\n");

		if(selectRc < 0)
		{
            if(errno == EINTR) 
				continue;
            printf("%s", ustr_errnof("utcap_select err="));
            return -1;
        }
		else if(selectRc == 0)
		{
			printf("time Exceed...... \n");
			return 0;
		}
    }while(isActive > 0 && rCnt <= 100);

    return 1;
}

int ProcComp(UTcapComponents *comp)
{
    int err_code = CC_RECV_UNKNOWN_COMP;

    if(comp->compType == UTCAP_COMP_ERROR)
    {
        err_code = CC_RECV_EC_ERROR;
        printf("\n RECEVIED UTCAP COMP ERROR ....." ) ;
    }
    else if(comp->compType >= UTCAP_COMP_REJ_USR && comp->compType <= UTCAP_COMP_REJ_REMOTE)
    {
        err_code = CC_RECV_REJECT;
        printf("\n RECEIVED UTCAP COMP REJECT RESULT .... " );
    }

    return 0;
}


int ProcPrim(UTcapPrimitive *prim)
{
    int err_code = CC_RECV_UNKNOWN_PRIM;
    UTcapPrimitive_DAT_IND      *ind;

    if(prim->type != UTcapPrimitiveType_DAT_IND)
	{
        printf("RECEIVED INVALID PRIMITIVE TYPE %d", prim->type);
        return -1;
    }

    ind = &(prim->u.datInd);
    printf("INVALID PRIMITIVE TYPE %s", UTCAP_TRANSACTION_STR(ind->msgType));

    return  0;
}


int sec_ellapsed(int sec)
{
    static time_t       old_time = 0;
    time_t              cur_time;

    time(&cur_time);
    if(old_time + sec <= cur_time)
    {
        old_time = cur_time;
        return 1;
    }
    else
        return 0;
}


int main(int argc, char *argv[])
{
    int count, c;
    int Conf_Result;
	int Recv_Result;
	time_t curTime;
	
	ossinit(world, map_protocol);

	mflag = 0; sflag = 0; 
	origMGT[0] =  destMGT[0] =  origSGT[0] =  destSGT[0] = 0;
	
	/* get option */
	while((c = getopt( argc, argv, "m:M:s:S:h")) != EOF)
	{
		switch(c)
		{
			case 'm' :
				strcpy( origMGT, optarg);
				mflag = 1;
				break;
			case 'M' :
				strcpy( destMGT, optarg);
				mflag = 1;
				break;
			case 's' :
				strcpy( origSGT, optarg);
				sflag = 1;
				break;
			case 'S' :
				strcpy( destSGT, optarg);
				sflag = 1;
				break;
			case 'h' :
				printf( "Usage : %s [-m origMSISDN |-M destMSISDN]\n", argv[0]);
				exit(0);
			default :
				mflag = sflag = 0;
		}
	}

	printf("count: %d , argument  : %s , %s\n", argc, argv[0], argv[1]);

	Conf_Result = GetMtConf(MT_CONF_FILE_PATH);

	if(Conf_Result == -1)
		exit(0);

	srand(getpid());

	signal(SIGINT,  (void (*)(int))CloseProc);
	signal(SIGTERM, (void (*)(int))CloseProc);


	if((gTcapInfo = initSigtran(argc, argv, "MT_SIM")) == 0)
	{
		printf("InitSigtran failed");
		CloseProc(0);
	}

	count = 0;
	/* tcap session openÀ» À§ÇØ */
	receiveFromSMSC();

	GetMtConf(MT_CONF_FILE_PATH);

	while(1)
	{
		/*SendMt3_test();*/
		time(&curTime);
		//GetMtConf(MT_CONF_FILE_PATH);

		if(SendMt3() > 0 && SendCount > 0)
		{
			//printf("\n\n\n\n ===>> SendMt3() success......................................................................................\n\n\n\n\n\n");

			Recv_Result = receiveFromSMSC();

			if(Recv_Result == -1)
			{
				printf("\n\n\n\n ===>> Recv() fail : %d......................................................................................\n\n\n\n\n\n",Recv_Result);
				break;
				//continue;
			}
			else if(Recv_Result == 0)
			{
				printf("\n\n\n\n ===>> Recv() Time Exceed : %d......................................................................................\n\n\n\n\n\n",Recv_Result);
				break;
				//continue;
			}

			printf("\n\n\n\n ===>> SendMt3() success : %d......................................................................................\n\n\n\n\n\n",Recv_Result);
			/*
			if(!check)
				exit(0);
			else 
			{
				gConcSeqNo++;
				nowLen += devideLen;
				printf("Set Next Conc Msg seqNo:%d\n", gConcSeqNo); 
				sleep(3);
			}
			*/
			SendCount--;
			if(SendCount == 0)
			{
				printf("\n\n\n\n ===>> SendMt3() End......................................................................................\n\n\n\n\n\n");
				break;
			}
		}
		else
		{
			printf("\n\n\n\n ===>> SendMt3() failed........................................................................................\n\n\n\n\n\n");
			usleep(1);
			sleep(1);
		}

		receiveFromSMSC();
	}

	return 0;
}

