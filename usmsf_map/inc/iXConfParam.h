
#include <iXtypes.h>

#ifndef _IX_CP_INCLUDED
#define _IX_CP_INCLUDED

#define CP_REC_ARR                100

#define IS_CP_FULL(X) !((X) < CP_REC_ARR)
#define IS_CP_EMPTY(X) ((X) <= 0)

/*==================================================================
    CP Information Structure
===================================================================*/

#define CP_CHARGE_INDI           "CHARGE_INDI"
#define CP_DEF_PERIOD            "DEF_EXPIRE"
#define CP_DEF_PROFILE           "DEF_PROFILE"
#define CP_DPP_ENG_TIME          "DPP_ENG_TIME"
#define CP_DPP_SS7_TIME          "DPP_DIA_TIME"
#define CP_FIRST_SGSN            "FIRST_MTF_NODE"
#define CP_INBH_RETRY      		 "INBH_RETRY"
#define CP_INBH_SLEEP      		 "INBH_SLEEP"
#define CP_INBH_TIMEOUT		     "INBH_TIMEOUT"
#define CP_INCOMING_TIME         "INCOMING_TIME"

#define CP_MAX_UD_CDMA           "MAX_UD_CDMA"
#define CP_MAX_UD_GSM            "MAX_UD_GSM"
#define CP_MO_FLOW_CTRL          "MO_FLOW_CTRL"
#define CP_MSG_CNT               "MSG_CNT"
#define CP_NPS_ENG_TIME          "NPS_ENG_TIME"
#define CP_NPS_TCP_TIME          "NPS_TCP_TIME"
#define CP_REQ_ENG_TIME          "REQ_ENG_TIME"
#define CP_REQ_SS7_TIME          "REQ_DIA_TIME"
#define CP_ROUTING_SCCP          "ROUTING_SCCP"
#define CP_SMSC_NUMBER           "SMSC_NUMBER"

#define CP_SUPPORT_GPRS          "SUPPORT_GPRS"
#define CP_SVR_ENG_TIME          "SVR_ENG_TIME"
#define CP_SVR_SMPP_TIME         "SVR_SMPP_TIME"
#define CP_SYSINFO_INTERVAL      "SYSINFO_INTERVAL"
#define CP_WINGS_ENG_TIME        "WINGS_ENG_TIME"
#define CP_WINGS_TCP_TIME        "WINGS_TCP_TIME"
#define CP_RIP_INFO              "RIP_INFO"
#define CP_PREFIX_INFO           "PREFIX_INFO"
#define CP_NODE_INFO             "NODE_INFO"
#define CP_DELAY_ENG_TIME        "DELAY_ENG_TIME"
#define CP_NPS_SYSINFO           "NPS_SYSINFO"
#define CP_SCP_SYSINFO           "SCP_SYSINFO"
#define CP_SMPP_SYSINFO          "SMPP_SYSINFO"
#define CP_NPS_SLEEP      		 "NPS_SLEEP"
#define CP_SCP_SLEEP      		 "SCP_SLEEP"
#define CP_HLR_DELAY_ENG_TIME    "HLR_DELAY_ENG_TIME"
#define CP_MAX_RETRY		     "MAX_RETRY"
#define CP_DB_POOL_SIZE		     "DB_POOL_SIZE"
#define CP_MAX_UD_CDMA_BEFORE    "MAX_UD_CDMA_BEFORE"
#define CP_SIG_RETURN_OPT        "SIG_RETURN_OPT"
#define CP_DPC_CTRL_OPT          "DPC_CTRL_OPT"
#define CP_SNDACK_CTRL           "SND_ACK_CTRL"
#define CP_PFX_STAT_CTRL         "PFX_STAT_CTRL"
#define CP_ROME_GROUP            "ROME_GROUP"
#define CP_UDL_LENGTH_LIMIT      "UDL_LENGTH_LIMIT"
#define CP_DB_SELECT			 "DB_SELECT"
#define CP_MSG_DUMP_IND			 "MSG_DUMP_IND"
#define CP_MO_DUMP_FLOW          "MO_DUMP_FLOW"
#define CP_SYSTEM_ID             "SYSTEM_ID"
#define CP_CONCAT_CHRG_RC        "CONCAT_CHRG_RC"
#define CP_TELE_UD_CTRL          "TELE_UD_CTRL"
#define CP_SMSF_ENG_TIME		 "SMSF_ENG_TIME" //v430
#define CP_SMSF_TCP_TIME		 "SMSF_TCP_TIME" //v430
#define CP_SMSF_SYSINFO   		 "SMSF_SYSINFO"  //v430
#define CP_SMSF_SLEEP   		 "SMSF_SLEEP"    //v430
#define CP_SMSF_CTRL	   		 "SMSF_CTRL"     //v430
#define CP_REG_SMS_DEST          "REG_SMS_DEST"  //v443
#define CP_REG_SMS_GID           "REG_SMS_GID"   //v443
#define CP_SBMT_DUMP_FLOW        "SBMT_DUMP_FLOW"//v450
#define CP_DUMP_DURATION         "DUMP_DURATION" //v450
#define CP_DEFAULT_DURATION      "DEFAULT_DURATION" //v450
#define CP_DEFAULT_AUTO_DUMP     "AUTO_DUMP_ON_OFF" //v450
#define CP_STORE_TEXT            "STORE_TEXT"   
#define CP_CHRG_FLAG             "CHRG_FLAG"   	//v480
#define CP_ROME_CHRG             "ROME_CHRG"   	//v480

#define CP_AUTO_DUMP_USE		 "AUTO_DUMP_USE"
#define CP_AUTO_BACKUP_USAGE	 "AUTO_BACKUP_USAGE"
#define CP_AUTO_RECOVERY_USAGE   "AUTO_RECOVERY_USAGE"
#define CP_AUTO_RECOVERY_CNT	 "AUTO_RECOVERY_CNT"

/*
#define CP_UCS_SMCI_ON_OFF       "UCS_SMCI_ON_OFF"	//v470   
#define CP_UCS_SMPP_ON_OFF       "UCS_SMPP_ON_OFF"  //v470 
#define CP_UCS_WINGS_ON_OFF      "UCS_WINGS_ON_OFF" //v470  
#define CP_UCS_SMSF_ON_OFF       "UCS_SMSF_ON_OFF"  //v470 
#define CP_QOR_ON_OFF       	 "QOR_ON_OFF"  		//v470 
#define CP_DCS_MATCH_CHAR     	 "DCS_MATCH_CHAR"   //v470
*/


/* Index */
//#define CP_INDEX_MAX_NUM               36
#define CP_INDEX_CHARGE_INDI           0
#define CP_INDEX_DEF_PERIOD            1
#define CP_INDEX_DEF_PROFILE           2
#define CP_INDEX_DPP_ENG_TIME          3
#define CP_INDEX_DPP_SS7_TIME          4
#define CP_INDEX_FIRST_SGSN            5
#define CP_INDEX_INBH_RETRY      	   6
#define CP_INDEX_INBH_SLEEP      	   7
#define CP_INDEX_INBH_TIMEOUT		   8
#define CP_INDEX_INCOMING_TIME         9
#define CP_INDEX_MAX_UD_CDMA           10
#define CP_INDEX_MAX_UD_GSM            11
#define CP_INDEX_MO_FLOW_CTRL          12
#define CP_INDEX_MSG_CNT               13
#define CP_INDEX_NPS_ENG_TIME          14
#define CP_INDEX_NPS_TCP_TIME          15
#define CP_INDEX_REQ_ENG_TIME          16
#define CP_INDEX_REQ_SS7_TIME          17
#define CP_INDEX_ROUTING_SCCP          18
#define CP_INDEX_SMSC_NUMBER           19
#define CP_INDEX_SUPPORT_GPRS          20
#define CP_INDEX_SVR_ENG_TIME          21
#define CP_INDEX_SVR_SMPP_TIME         22
#define CP_INDEX_SYSINFO_INTERVAL      23
#define CP_INDEX_WINGS_ENG_TIME        24
#define CP_INDEX_WINGS_TCP_TIME        25
#define CP_INDEX_DELAY_ENG_TIME        26
#define CP_INDEX_NPS_SYSINFO           27
#define CP_INDEX_SCP_SYSINFO           28
#define CP_INDEX_SMPP_SYSINFO          29
#define CP_INDEX_NPS_SLEEP      	   30   /* 재접속, 주기 */
#define CP_INDEX_SCP_SLEEP      	   31   /* 재접속, 주기 */
#define CP_INDEX_RIP_INFO              32
#define CP_INDEX_PREFIX_INFO           33
#define CP_INDEX_HLR_DELAY_ENG_TIME    34	/* Pending시 HLR로의 delay 주기   */
#define CP_INDEX_MAX_RETRY             35	/* v302 sjlee MAX_RETRY 횟수 설정 */
#define CP_INDEX_DB_POOL_SIZE          36	/* v302 sjlee MAX_RETRY 횟수 설정 */
#define CP_INDEX_MAX_UD_CDMA_BEFORE    37	/* User Data Length Check         */
#define CP_INDEX_SIG_RETURN_OPT        38	/* Sigtran Return Option          */
#define CP_INDEX_DPC_CTRL_OPT          39	/* dpc Control On/Off Option      */
#define CP_INDEX_SNDACK_CTRL           40	/* sndAck Control On/Off Option   */
#define CP_INDEX_PFX_STAT_CTRL         41	/* Prefix Stat store On/Off Option*/
#define CP_INDEX_ROME_GROUP            42	/* ROME Group Id Option			  */
#define CP_INDEX_UDL_LENGTH_LIMIT      43	/* UserDataLength Limit Option    */
#define CP_INDEX_DB_SELECT             44	/* DB select option*/
#define CP_INDEX_AUTO_DUMP_USE         45	/* Auto Dump Option */
#define CP_INDEX_AUTO_BACKUP_USAGE     46	/* Auto Backup Usage */
#define CP_INDEX_SYSTEM_ID             47	/* v390 added by jhjung 20090204 System ID for reference number */
#define CP_INDEX_CONCAT_CHRG_RC        48   /* v420 */
#define CP_INDEX_TELE_UD_CTRL          49	/* v420 added by jhjung telematics subparam ud exeption */
#define CP_INDEX_SMSF_ENG_TIME         50	//430
#define CP_INDEX_SMSF_TCP_TIME         51	//430
#define CP_INDEX_SMSF_SYSINFO          52	//430
#define CP_INDEX_SMSF_SLEEP   	       53	//430
#define CP_INDEX_SMSF_CTRL             54	//430
#define CP_INDEX_REG_SMS_DEST          55	//443 destination address for iphone registration
#define CP_INDEX_REG_SMS_GID           56	//443 esme group id for iphone registration
#define CP_INDEX_AUTO_RECOVERY_USAGE   57	/* Auto Recovery Usage */
#define CP_INDEX_AUTO_RECOVERY_CNT     58	/* Auto Recovery Count */
#define CP_INDEX_DEFAULT_DURATION      59	//450
#define CP_INDEX_DEFAULT_AUTO_DUMP     60	//450
#define CP_INDEX_STORE_TEXT			   61	//450
#define CP_INDEX_CHRG_FLAG			   62	//480
#define CP_INDEX_ROME_CHRG			   63 	//480


#define CP_RIP_INFO_UNKNOWN            0
#define CP_RIP_INFO_LOCAL              1
#define CP_RIP_INFO_OTHER              2

#define CP_PREFIX_INFO_UNKNOWN         0
#define CP_PREFIX_INFO_ODD             1
#define CP_PREFIX_INFO_EVEN            2
#define CP_PREFIX_INFO_BOTH            3

#define CP_CHARGE_INDI_NOT_USED   0
#define CP_CHARGE_INDI_NO_CHARGE  1
#define CP_CHARGE_INDI_ORIG       2
#define CP_CHARGE_INDI_DEST       3

#define CP_MSG_DUMP_SET_NOT_USED		0
#define CP_MSG_DUMP_SET_MO				0x01
#define CP_MSG_DUMP_SET_SBMT			0x02
#define CP_MSG_DUMP_SET_MO_SBMT			0x03

#define CP_ROUTING_BY_PC          0
#define CP_ROUTING_BY_GT          1

#define CP_INIT_SMSC_NUMBER       0
#define CP_INIT_REQ_ENG_TIME      20
#define CP_INIT_DPP_ENG_TIME      50
#define CP_INIT_SVR_ENG_TIME      20
#define CP_INIT_REQ_SS7_TIME      10
#define CP_INIT_DPP_SS7_TIME      40
#define CP_INIT_RED_SS7_TIME      10
#define CP_INIT_INCOMING_TIME     20
#define CP_INIT_SVR_SMPP_TIME     10
#define CP_INIT_DEF_PROFILE       0
#define CP_INIT_DEF_PERIOD        86400
#define CP_INIT_MAX_UD_CDMA       88
#define CP_INIT_MAX_UD_GSM        140
#define CP_INIT_SUPPORT_GPRS      IXTRUE
#define CP_INIT_MSG_CNT           IXFALSE
#define CP_INIT_CHARGE_INDI       CP_CHARGE_INDI_NOT_USED
#define CP_INIT_ROUTING_SCCP      CP_ROUTING_BY_PC
#define CP_INIT_MO_FLOW_CTRL     100
#define CP_INIT_NPS_ENG_TIME      20
#define CP_INIT_NPS_TCP_TIME      10
#define CP_INIT_WINGS_ENG_TIME    20
#define CP_INIT_WINGS_TCP_TIME    10
#define CP_INIT_SYSINFO_INTERVAL  	  60    
#define CP_INIT_INBH_TIMEOUT	  10
#define CP_INIT_INBH_RETRY    	  3	 
#define CP_INIT_INBH_SLEEP   	  5	 
#define CP_INIT_FIRST_SGSN		  0
#define CP_INIT_DELAY_ENG_TIME    3
#define CP_INIT_NPS_SYSINFO       60
#define CP_INIT_SCP_SYSINFO       60 
#define CP_INIT_SMPP_SYSINFO      3600 //v540 60->3600 
#define CP_INIT_NPS_SLEEP   	  5	 
#define CP_INIT_SCP_SLEEP   	  5	 
#define CP_INIT_HLR_DELAY_ENG_TIME    2
#define CP_INIT_SMSF_ENG_TIME     20
#define CP_INIT_SMSF_TCP_TIME     5
#define CP_INIT_SMSF_SLEEP   	  10
#define CP_INIT_SMSF_SYSINFO 	  60
#define CP_INIT_REG_SMS_DEST 	  0              //v443
#define CP_INIT_REG_SMS_GID 	  0              //v443
#define CP_INIT_SBMT_DUMP_FLOW    0             //v450
#define CP_INIT_DUMP_DURATION     0             //v450
#define CP_INIT_DEFAULT_DURATION  3600          //v450
#define CP_INIT_AUTO_DUMP_IND  	  0 	         //v450

/* v302 sjlee add*/
#define CP_INIT_MAX_RETRY         30
#define CP_INIT_DB_POOL_SIZE      128
/* Add end */

#define CP_INIT_MAX_UD_CDMA_BEFORE 105
#define CP_INIT_SIG_RETURN_OPT     0
#define CP_INIT_DPC_CTRL_OPT       0
#define CP_INIT_SNDACK_CTRL        0
#define CP_INIT_PFX_STAT_CTRL      0
#define CP_INIT_STORE_TEXT         0
#define CP_INIT_ROME_GROUP        99
#define CP_INIT_UDL_LENGTH_LIMIT  90 
#define CP_INIT_DB_SELECT         0
#define CP_INIT_MSG_DUMP_IND      0
#define CP_INIT_MO_DUMP_FLOW      0
#define CP_INIT_SYSTEM_ID		  0
#define CP_INIT_CONCAT_CHRG_RC    0
#define CP_INIT_TELE_UD_CTRL      0
#define CP_INIT_SMSF_CTRL         1
#define CP_INIT_UCS_SMCI_OPT      0			//v470
#define CP_INIT_UCS_SMPP_OPT      0			//v470
#define CP_INIT_UCS_WINGS_OPT     0			//v470
#define CP_INIT_UCS_SMSF_OPT      0			//v470
#define CP_INIT_ESME_QOR_OPT      0			//v470
#define CP_INIT_DCS_MATCH_CHAR    0x3f		//v470
#define CP_INIT_CHRG_FLAG		  0			//v480
#define CP_INIT_ROME_CHRG		  0			//v480
#define CP_INIT_AUTO_DUMP_USE     0
#define CP_INIT_AUTO_BACKUP_USAGE 		50
#define CP_INIT_AUTO_RECOVERY_USAGE 	40
#define CP_INIT_AUTO_RECOVERY_CNT	  	50

#define CP_FIRST_SGSN_MSC		  1
#define CP_FIRST_SGSN_SGSN		  2

#define CP_INDEX_LEN              4
#define CP_NAME_LEN               DEFAULT_NAME_LEN
#define CP_STRVAL_LEN             DEFAULT_ADDR_LEN
#define CP_INTVAL_LEN             FOUR_INT_LEN

#define CP_INDEX_SIZE            4 
#define CP_NAME_SIZE             (CP_NAME_LEN+1)
#define CP_STRVAL_SIZE           (CP_STRVAL_LEN+1)
#define CP_INTVAL_SIZE           (CP_INTVAL_LEN)

#define pCP_INDEX_SIZE            0
#define pCP_NAME_SIZE            (pCP_INDEX_SIZE+CP_INDEX_SIZE) 
#define pCP_STRVAL_SIZE          (pCP_NAME_SIZE+CP_NAME_SIZE)
#define pCP_INTVAL_SIZE          (pCP_STRVAL_SIZE+CP_STRVAL_SIZE)

#define CP_TOTAL_SIZE            (CP_INDEX_SIZE+CP_NAME_SIZE+CP_STRVAL_SIZE+CP_INTVAL_SIZE)

typedef struct _stCP {
    int             index;
    char            name[CP_NAME_SIZE];
    char            strVal[CP_STRVAL_SIZE];
    int             intVal;
} stCP;

typedef struct _stCPShm {
    int             end;
    stCP            table[CP_REC_ARR];
} stCPShm;

int ConvConfNameToIndex(char *confName, int *index);
int UseProfileIdInCP(unsigned char profileId, char *errStr);
int dbUpdateCPforBackUp(stCP info , char *smscNum);

/* declare gca function */
stCPShm *GetCPp(void);
void OpenCPshm(void);
int	InitCPshm(void);
int CP_compare(const void *, const void *);
int GetCP(char *, stCP *);
int getChargeInd(int *);
int getExpiredTime(int *);
int getDefProfile(int *);
int getDppEngTime(int *);
int getSS7DppTime(int *);
int getFirstTryNode(int *);
int getInbhRetry(int *);
int getInbhSleep(time_t *);
int getInbhTimeout(time_t *);
int getIncomingTime(int *);
int getMaxUDCdma(int *);
int getMaxUDGsm(int *);
int getMoFlow(int *);
int getMsgCnt(int *);
int getNpsEngTime(int *);
int getNpsTcpTime(int *);
int getReqEngTime(int *);
int getSS7ReqTime(int *);
int getRoutingSccp(int *);
int getSmscNumber(char *);
int getSupportGPRS(int *);
int getSvcEngTime(int *);
int getSvcTcpTime(int *);
int getSysInfoInterval(int *);
int getWingsEngTime(int *);
int getWingsTcpTime(int *);
int getDelayEngTime(int *);
int getNpsSysInfo(int *);
int getScpSysInfo(int *);
int getSmppSysInfo(int *);
int getNpsSleep(time_t *);
int getScpSleep(time_t *);
int getHlrDelayEngTime(int *);
int getMaxRetry(int *);
int getDBPoolSize(int *);
int getMaxUDCdmaBefore(int *);
int getSigReturnOpt(uint8_t *);
int getCpRipInfo(int *);
int getCpPfxInfo(int *);
int getDpcCtrlOpt(char *);
int getSndAckCtrl(char *);
int getPfxStatCtrl(char *);
int getRomeGroupId(unsigned char *);
int changeDistributionMethod( int );
int getUdlLimit(void);
int getDbSelect(void);
int getMsgDumpInd(void);
int changeMsgDumpInd(int );
int getMsgFlow(int *);
int getSystemId(void);
int getCpRouteRip(void);
int getCpRoutePrefix(stAddr *);
int getDistributionMethod(void);
int changeVirtualIpStatus( int );
int GetAllCP(stCP *, int *);
int InsertCP(stCP *);
//int getTeleUdCtrl(void);		//removed by gtpark v470
int getSmsfEngTime(int *);
int getSmsfTcpTime(int *);
int getSmsfSysInfo(int *);
int getSmsfSleep(time_t *);
//int getSmsfCtrl(void); removed by gtpark v470
int getRegSmsDest(char* dest);              		//v443
int getRegSmsGid(unsigned char *gid);       		//v443
int getSbmtDumpFlow(int *flow);             		//v450
int getDumpDuration(unsigned int *time);            //v450
int getDefaultDuration(int *time);             		//v450
int checkDurationTime(int dumpInd, int modId);      //v450
int clearCreatingDir(int type);                     //v450
int getAutoDumpInd(int *autoDumpInd);				//v450
int getChrgFlag(int *chrgFlag);						//v480
int getRomeChrg(int *chrgFlag);						//v480
int getAutoDumpUse();
int getAutoRecoveryCnt(int *cnt);
int getAutoRecoveryUsage(int *usage);
int getAutoBackupUsage(int *usage);
//int getStoreText(void);				//v450tb removed by gtpark v470
int insert_cp_list(char *config_file);
int Update_CP_List(stCPShm *cp_list);

#endif    /* _IX_CP_INCLUDED    */
