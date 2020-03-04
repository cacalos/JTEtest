#ifndef	__LIB_UTIL_H_
#define	__LIB_UTIL_H_

#include <iXtypes.h>

#define LOG_ELLAPSE_TIME 3

#define N_PROCCESS_START_TIME_INDEX 21 //index로 21, 22번째 필드.

int getConf(char *file, char *conf, char *data);

int IS_CC_ERR_RANGE(int errCode);
int ConvBCDtoStr(char *bcd, int bcdLen, char *str, int *strLen);
int ConvStrToBCD(char *str, int strLen, char *bcd, int *bcdLen);
int chgCbNumTon(stAddr *addr);
int CheckAddress(stAddr *addr);
int TrimCountryCodeforVMS(stAddr *addr);
int TrimCountryCode(stAddr *addr);
int TrimCountryCodeKeepTON(stAddr *addr);
int TrimCountryCodeString(char *addr);
void ConvTimeFormat(time_t nTime, char *sTime);
int IsNotSuppAsciiToGsm(unsigned char code);
int IsNotSuppGsmToAscii(unsigned char code);
int CheckAbnormalPrefix(stAddr *org, stAddr *dest);
int checkSpecialDigit(stAddr *dest, unsigned char *digit);
void RemoveSpace(char   *data, int len);
int convScpAddrToLocal(char *addr);
int convLocalAddrToScp(char *addr);
int convNodeToCharType(stNodeNumber *node1, unsigned char origMsgType, char *node2);
int convNodeToStType(char *node1, stNodeNumber *node2);
int IsConvPfxType(stAddr *routeDigit , stAddr *dest);
int GetCauseListDescForTrace(int causeNo, char *causeDesc);
int getAbsentSubscriberCcHLR(unsigned short cc);
int getBarredServiceCcHLR(int cc);
int getAbsentSubscriberCcMSC(unsigned short cc);
int getDeliveryFailure(unsigned char cc);
int isAbsentSubscriberForReport(int errCode);
int isDeliveryFailureForReport(int errCode);
int clk_testStart(void);
int clk_testEnd(int nTr);
int MakeStrHexa(char *trg, unsigned char *s, int len, int *remain, int f_cols, int l_cols);
int MakeStrHexaAndShow(const char *data, int dataLen, char *dest, int show);

/* ripinfo.c */
int setDualActInfo(void);
void setRipInfo(int rip);
void setPfxInfo(int pfx);
int getRipInfo(void);
int getPfxInfo(void);
int getRoutePrefix(stAddr *dest);

/* time_op */
int sec_ellapsed(int max_gap);
int sec_ellapsed_mo(int max_gap);
int sec_ellapsed_sbmt(int max_gap);
int m_sec_ellapsed(int msec);
void SleepForAWhile(void);

/* dbinit.c */
int dbInit(void);

/* flow.c */
int msg_flow_ctrl(int msgflowctrl);

/* seq_num.c */
unsigned int getSmeRefNum(unsigned char sysId, unsigned int msgId);

time_t *convInttoTime_t(int itime);
/* convert.c */
int IsEncodedBinaryWith(unsigned char dcs, unsigned char encode);
int IsEncodedMtBinaryWith(unsigned char dcs, unsigned char encode, char momt); //v540
char* GetStrTime_t(time_t time);
time_t GetStrToTime_t(char *timeStr, char *format); //v500
char* GetTime_tToStr(time_t time); //v550
int hex2dec(unsigned char *hex, int hexsize, unsigned char* decstr, unsigned int* dec);

/* types.c */
char* GetStrAddrInfo(stAddr addr);
char* GetStrAddrInfo2(stAddr addr);
char* GetStrMsgTypeInfo(unsigned char msgType);
char* GetStrMoMtInfo(unsigned char momt);
char* GetStrDcsInfo(unsigned char dcs);
char* GetStrEncodeInfo(unsigned char encode);
char* GetStrDcsKeyInfo(unsigned char dcsKey);
char* GetStrOutDcsInfo(unsigned char outDcs);
char* GetStrUeIndicator(unsigned short ueIndicator);
char* GetStrUeType(unsigned char ueType);
char* GetStrSvcInfo(unsigned int vaddSvc);
char* GetStrOrigSvcInfo(unsigned int vaddSvc);
char* GetStrVasSvcInfo(unsigned int vasSvc);
char* GetStrMapSvcInfo(unsigned int mapSvc);
char* GetStrSmsfFlag(unsigned char smsfFlag);                        //v430
char* GetStrCallOrigType(unsigned char callOrigType);                //v430

int GetEncodeName(unsigned char encode, char *name);
int GetFepOpNametoPdu(int operation_name, int msg_type);
char *GetFepOpNameString(int operation_name, int msg_type);

/* print */
int print_log(int bStd, const char* fmt, ...);

int checkRipInfoForDnif(void); //v590 by Nersion. (ixdnif 알람 관련 이슈 사항 방어 로직)

/* v600 by Nersion. */
char *getNodePriorityString(int type);

/* added by Nersion. For NEW KT SMSC */
int getStartTimeFromPid(unsigned int pid, time_t *sTime);
int checkVirtualIp(char *pEnv, char *virtualIp); //for linux

unsigned char Check7BitDCS(unsigned char dcs);

#endif
