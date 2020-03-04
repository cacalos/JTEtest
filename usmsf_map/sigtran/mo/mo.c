#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <signal.h>

#include <ua_log.h>
#include <ua_sysdef.h>
#include <ua_syslib.h>
#include <ua_oam_type.h>

#include <sigtran_util.h>

#include <ASN/asn_smsc.h>
#include <SS7/ix7map.h>
#include <SS7/ss7_resq.h>

#include <TPDU/TPDU.h>
#include <RPDU/RPDU.h>
#include <RPDU/okhTypes.h>
#include <iXLog.h>
#include <iXCauseCode.h>
#include <iXMoQ.h>
#include <smsf_msg.h>
#if 0
#include <iXMoQ.h>
#include <iXMtQ.h>
#include <iXMSC.h>
#include <iXSGSN.h>
#include <iXEngine.h>
#endif

#include "mo.h"


#define INC_DIAG_ID_OUT(a) (((a+1) >= MAX_DIAG_ID_MO) ? (a=1) : (a++))

#if 0
/*----- Config Value --------*/
int 				  MyPC;
int 				  MySSN 			 = 8;
int                   Recv_wait_msec     = 9;        
#endif

/*----- Common Value ---------*/
extern int            Send_Burst;
extern int            Send_Interval;

/* Global 변수 정의 */  
int                   cnx_fail_times = 0;

/* Internal */
int                   is_send_mode = TRUE;
static int            errQueueFlag = ERROR_STATE_INIT;

/* OSS Global */
OssBuf                param;
struct ossGlobal      w, *world = &w;
int myOssPrint( OssGlobal *w, const char *format, ... );

int gLogId;

/* for SIGTRAN */
UTcap                    *gTcapInfo;

/* for real time stat */
unsigned int        gSendCnt = 0;
unsigned int        gRcvAckCnt = 0;
unsigned int        gRcvNackCnt = 0;
unsigned int        gTimeOutCnt = 0;

#define	MAX_SEND_BURST	100
static int		  maxBurst = MAX_SEND_BURST;

void see_results() 
{
    //prn_tc_err_cnt();
    prn_prim_cnt();
    prn_comp_cnt();
}


void closeProc()
{
    close_shm();

    see_results();
    uaLog(L_CRT, "-----  %s  Ends  -----", _MODULE_NAME);
    exit(0);
}

#if 0
int GetMTFconf(char *file)
{
    char               buf[64];

    if(getConf(file, "MY_PCODE", buf) < 0)
    {
        uaLog(L_CRT,
            "Conf: can't find 'MY_PCODE' item in <%s>", file);
        return IXERR;
    }
    else
        MyPC = (int)atoi(buf);

    if(getConf(file, "MY_SSN", buf) < 0)
    {
        uaLog(L_CRT,
            "Conf: can't find 'MY_SSN' item in <%s>", file);
    }
    else
        MySSN = (int)atoi(buf);

    return IXOK;
}
#endif

int main(int argc, char *argv[])
{
    int               i;
    int               recv_res;
    int               res;
    int               seccnt = 0;
    int               msg_per_sec=0;
    int               mtfTime;
    char              confFileName[128];
    char             *configPtr;
	char	          fname[MAX_PATH_NAME];
	char 	         *env;
	int               errCnxFlag = ERROR_STATE_INIT;
	int				  mySsn;

	ua_changeCoreDir(_MODULE_NAME);

	GET_SYS_HOME_ENV(env);
	sprintf( fname, "%s/log/%s/%s", env, _MODULE_NAME, _MODULE_NAME);

	gLogId = LOG_open( fname,
			LOG_MODE_LIMIT_SIZE | LOG_FORMAT_TIME_MSEC |
			LOG_FORMAT_CATEGORY | LOG_FORMAT_SRC_FILE | LOG_FLAG_EXT_CTRL|
			LOG_FLAG_STDOUT | LOG_FLAG_THREAD_SAFE );

	if ( gLogId < 0) {
		fprintf( stderr, "LOG_open: E=%d", gLogId); 
		return -1; 
	}

	LOG_setFileLimitOption(gLogId, 1024*1024*20, 10);

	proc_heartInit( _MODULE_NAME);

    uaLog(L_CRT, "+++++ %s Starts +++++", _MODULE_NAME);

    signal(SIGINT,  (void (*)(int))closeProc);
    signal(SIGTERM, (void (*)(int))closeProc);
	
#if 0
    configPtr = getenv("SMS_CONFIG_DIR");
    if(configPtr == NULL)
    {
        uaLog(L_CRT, "Can't get environment variable '%s'",
            "SMS_CONFIG_DIR");
        closeProc();
    }
    else
    {
        sprintf(confFileName, "%s/%s", configPtr, CONF_FILE_SS7);
        res = GetMTFconf(confFileName);
        if(res == IXERR)
        {
            uaLog(L_CRT,
                "Can't find important data in config file");
            closeProc();
        }
    }
#endif

    sleep(1);

    if(OpenGCA() == IXERR)
    {
        uaLog(L_CRT, "Can't open GCA !!!");
        closeProc();
    }

	OpenProxyQ();
	OpenMoQ();
	OpenStatQ();

    //open_shm();

	if ((gTcapInfo = initSigtran( argc, argv, _MODULE_NAME)) == 0) {
		uaLog( L_CRT, "InitSigtran failed");
		closeProc(0);
	}

    /* all iXss7xx processes contain following sentence */
    ossinit(world, map_protocol);
	ossSetUserPrint( world, stdout, myOssPrint);

    if(InitMoResponseQ() < 0)
        closeProc();

    srand((int)getpid());

	initMOFstat();

//	getMtfTime(&mtfTime);
    while (1)
    {
		proc_heartBeat();

        sendInvokes(500);

        recv_res = recvResponse(9);

        if(sec_ellapsed(1) == IXOK)
        {
			int rsc1, rsc2;

			rsc1 = GetMoQLen();
			rsc2 = GetNumMoResQ(); 

			proc_setRscUsage( rsc1, rsc2);

			if ( rsc1 > 0 || rsc2 > 0)
				uaLog( L_INFO, "MOF Q:%d MTF Res Q:%d", rsc1, rsc2);

            is_send_mode = TRUE;

			//getMtfTime(&mtfTime);
			mtfTime = 10;
            if( CheckTimeOut(mtfTime) == IXOK)
                mark_time_out();
			
			//getMySSN(&mySsn);
			mySsn = 8;

            sigSearchHashTable(gTcapInfo, 20, mySsn);

            seccnt++;
            if((seccnt % 5) == 0)
			{
                /* userId table에서 유효기간 지난 레코드 삭제 */
                CheckDiagIDinTable(mtfTime+2);
			}

            if(seccnt >= 100)
                seccnt = 0;

			if(gSendCnt + gRcvNackCnt + gRcvAckCnt + gTimeOutCnt > 0) {
				uaLog(L_CRT, "[Snd Msg] Cnt:%d, [Rcv Resp] Ack:%d, Nack:%d, TimeOut:%d",
						gSendCnt, gRcvAckCnt, gRcvNackCnt, gTimeOutCnt);
				gSendCnt = gRcvAckCnt = gRcvNackCnt = gTimeOutCnt = 0;
			}

			updateMOFstat();
        }
    }

    closeProc();
	return 0;
}


/* send MOF or MTF invoke */
int sendInvokes( int msg_num)
{
    int               cnt = 0;
    int               res, ret;
    int               sent_cnt = 0;
    int               provId, userId, invId;
    //int        		  diagId;
    static int        diagId = 0;
    unsigned char     acn_version;
    int               tmpInt;
	static			  msg_suspend = FALSE;
	int 			  cnt1, cnt2;
	smsf_msg_t 		  rcvMsg;
	stMoMsg 		  moMsg;
	_RPDU 			  rpdu;

	int mySsn;

	//getMySSN(&mySsn);
	mySsn = 8;

    while(cnt < maxBurst)
    {
        cnt++;

		if(msg_suspend == FALSE)
		{
			memset(&rcvMsg, 0, sizeof(smsf_msg_t));
        	res = GetMoMsg(&rcvMsg);
        	if(res != IXOK)
            	break;
		}

#if 0
		if(moMsg.tcapTransFlag == TCAP_CANCEL_CONTINUE)
		{
			ret = DeleteHashTable(&moMsg.dest, &provId, &userId, &invId);
			if(ret == IXOK)
			{
				/* Abort를 해주지 않으면 영원히 삭제되지 안는다. 단, TC_CONTINUE */
				/* 에 대해서만 시행한다. */
				sig_sendTCUAbort(gTcapInfo, userId, provId, mySsn);
			}
			continue;
		}
#endif
		if(strlen(rcvMsg.supi) == 0 || strlen(rcvMsg.gpsi) == 0) {
			uaLog(L_CRT, "IMSI or ORIG length is zero, imsi len[%d], orig len[%d]",
					strlen(rcvMsg.supi), strlen(rcvMsg.gpsi));
			continue;
		}

		if(strlen(rcvMsg.my_isdn) == 0 && rcvMsg.my_pc == 0) {
			uaLog(L_CRT, "Does not exist SMSF(ORIG) MAP Address info, imsi[%s], orig[%s]",
					rcvMsg.supi, rcvMsg.gpsi);
			continue;
		}

		if(strlen(rcvMsg.smsc_isdn) == 0 && rcvMsg.smsc_pc == 0) {
			uaLog(L_CRT, "Does not exist SMSC(DEST) MAP Address info, imsi[%s], orig[%s]",
					rcvMsg.supi, rcvMsg.gpsi);
			continue;
		}
		else {
			checkSmscList(rcvMsg.smsc_isdn);
		}

		if(rcvMsg.data_len < 1) {
			uaLog(L_CRT, "MO Data length is zero, imsi imsi[%s], orig[%d]",
					rcvMsg.supi, rcvMsg.gpsi);
			continue;
		}

		uaLog(L_MIN, "RECV SMSF_MSG - SUPI:%s, GPSI:%s, SMSF Node[%s - %d,%d], SMSC Node[%s - %d,%d], RTYPE:%d, LEN:%d", 
				rcvMsg.supi, rcvMsg.gpsi, rcvMsg.my_isdn, rcvMsg.my_pc, rcvMsg.my_ssn, 
				rcvMsg.smsc_isdn, rcvMsg.smsc_pc, rcvMsg.smsc_ssn, rcvMsg.routing_type, rcvMsg.data_len);

		memset(&rpdu, 0, sizeof(_RPDU));
		memset(&moMsg, 0, sizeof(stMoMsg));

		ret = DecodeRPDU(&rpdu, rcvMsg.data, rcvMsg.data_len, DIRECTION_MS_SC);
		if(ret < 0)
		{
			uaLog(L_CRT, "DecodeRPDU() fail, supi[%s], gpsi[%s]", rcvMsg.supi, rcvMsg.gpsi);
			continue;
		}

		moMsg.orig.len = sprintf(moMsg.orig.min, "%s", rcvMsg.gpsi);
		moMsg.orig.ton = TON_UNKNOWN;
		moMsg.orig.npi = NPI_E164;
		moMsg.imsi.len = sprintf(moMsg.imsi.min, "%s", rcvMsg.supi);
		moMsg.imsi.ton = TON_IMSI;
		moMsg.imsi.npi = NPI_IMSI;

		moMsg.origNode.pCode = rcvMsg.my_pc;
		moMsg.origNode.ssn = rcvMsg.my_ssn;
		if(strlen(rcvMsg.my_isdn) > 0)
			strcpy(moMsg.origNode.isdn, rcvMsg.my_isdn);

		moMsg.destNode.pCode = rcvMsg.smsc_pc;
		moMsg.destNode.ssn = rcvMsg.smsc_ssn;
		moMsg.destNode.nodeType = NODE_SMSC;
		if(strlen(rcvMsg.smsc_isdn) > 0)
			strcpy(moMsg.destNode.isdn, rcvMsg.smsc_isdn);

		moMsg.data_len = rpdu.Union.rData.RpDataLength;
		if(moMsg.data_len > 0)
			memcpy(moMsg.data, rpdu.Union.rData.RpUserData, moMsg.data_len);

		INC_DIAG_ID_OUT(diagId);

		setTraceModeMo( diagId, &moMsg.orig, NULL, &moMsg.imsi);
		
		if ( isInTrace( diagId, 1)) 
			MinTrace(LPOS, getTraceNum(diagId),
"=====>> MOF Invoke =====>>\n\
Orig Addr   : %s\n\
IMSI        : %s\n\
Node        : %s - %d(H'%X)",
					moMsg.orig.min,
					moMsg.imsi.min,
					strlen(moMsg.destNode.isdn) == 0 ? "Unknown" :
					moMsg.destNode.isdn,
					moMsg.destNode.pCode, moMsg.destNode.pCode);

		uaLog(L_MIN, "from AMF:: REF_NO:%d, ORIG:%s, IMSI:%s, RPDATA_LEN : %d, Node[%s - %d(%02X'H),%d]", 
				moMsg.msgRef, moMsg.orig.min, moMsg.imsi.min, moMsg.data_len,
				moMsg.destNode.isdn, moMsg.destNode.pCode, moMsg.destNode.pCode, moMsg.destNode.ssn);

		/* insert the msg into response q */
		ret = insertMoResQ(diagId, &moMsg);
		if(ret != IXOK)
		{
			is_send_mode = FALSE;
			break;
		}

		acn_version = MAP_VERSION_3;

		ret = DeleteHashTable(&moMsg.imsi, &provId, &userId, &invId);
		if(ret == IXOK)
		{
			if(SetDiagIDinTable(userId, diagId) != IXOK)
			{
				uaLog(L_CRT,
						"\tSetDiagTable fail. orig[%s] imsi[%s] node[%s - %d(%02X'H)]",
						moMsg.orig.min, moMsg.imsi.min,
						moMsg.destNode.isdn, moMsg.destNode.pCode,
						moMsg.destNode.pCode);
				sendErrToEngine(diagId, CC_LOCAL_ERROR, MAP_VERSION_N);
				SetDone(diagId);
				continue;
			}

			res = sendMofInvoke(diagId, userId, provId, invId, &moMsg, UTCAP_CONTINUE, acn_version);

		}
		else
		{
			userId = diagId;
			if(SetDiagIDinTable(userId, diagId) != IXOK)
			{
				uaLog(L_CRT,
						"\tSetDiagTable fail. orig[%s] imsi[%s] node[%s - %d(%02X'H)]",
						moMsg.orig.min, moMsg.imsi.min,
						moMsg.destNode.isdn, moMsg.destNode.pCode,
						moMsg.destNode.pCode);
				sendErrToEngine(diagId, CC_LOCAL_ERROR, MAP_VERSION_N);
				SetDone(diagId);
				continue;
			}

			res = sendMofInvoke(diagId, userId, 0, INVOKE_ID_MOF, &moMsg, UTCAP_BEGIN, acn_version);
		}

		if(res == IXOK)
		{
			msg_suspend = FALSE;

			sent_cnt++;
			gSendCnt++;

			inc_mof_send_succ(&moMsg.destNode.isdn);

			if ( isInTrace( diagId, 1))
				MinTrace(LPOS, getTraceNum(diagId), "\tMOF Invoke Success");

			uaLog( L_INFO, "MOF Sent. diagid:%d", diagId);
		}
		else  /* IXERR */
		{
			is_send_mode = FALSE;

			if ( isInTrace( diagId, 1))
				MinTrace(LPOS, getTraceNum(diagId), "\tMOF Invoke Failed"); 

			uaLog( L_MAJ, "MOF Invoke fail uid=%d pid=%d diagId=%d", diagId, userId, provId);

			sendErrToEngine(diagId, CC_LOCAL_ERROR, MAP_VERSION_N );

			if( tmpInt > 0  && userId != tmpInt)
				sig_sendTCUAbort(gTcapInfo, userId, provId, mySsn);

			SetDone(diagId);

			break;
		}
	}
	maxBurst = burstControl_new( maxBurst, DEFAULT_BURST_VALUE, msg_suspend, GetMoQLen());

	return sent_cnt;
}

void encodeMofExt(struct PrivateExtensionList *privateExt, unsigned char camelSvcType, unsigned short smsIndicator,
		unsigned char *encBufExt, int encBufExtSize) 
{
	char 						flag = 0;
	char 						smsInd[2];
	KTF_ORIGSERVICETYPE 		ktfService;

	uaLog(L_INFO, "set extension, smsIndicator : %d, camel : %d", smsIndicator, camelSvcType);

	memset(&ktfService, 0x00, sizeof(KTF_ORIGSERVICETYPE));

	ktfService.bit_mask |= smsIndicator_present;
	memcpy((void *)ktfService.smsIndicator.value, &smsIndicator, 2);
	//		sprintf(ktfService.smsIndicator.value, "%02x", smsIndicator);
	ktfService.smsIndicator.length = 2;

	ktfService.bit_mask |= camelServiceType_present;
	ktfService.camelServiceType = camelSvcType;

//	privateExt->value.bit_mask |= extType_present;
	privateExt->value.bit_mask = extType_present;
	privateExt->value.extId = ktf_origservicetype_id;
	//privateExt->value.extType.pduNum = KTF_ORIGSERVICETYPE_PDU;
	privateExt->value.extType.pduNum = 0;
	privateExt->value.extType.decoded = 0;
	privateExt->next = NULL;

	param.length = encBufExtSize;
	param.value = encBufExt;

	if (ossEncode(world, KTF_ORIGSERVICETYPE_PDU, &ktfService, &param))
	{
		uaLog(L_CRT,"ossEncode error: %s\n", ossGetErrMsg(world));
		privateExt->value.extType.length = 0;
	}
	else {
		privateExt->value.extType.length = param.length;
		memcpy(encBufExt, param.value, param.length);
		privateExt->value.extType.encoded = param.value;
	}
}

int sendMofInvoke(int diagId, int userId, int provId, int invId,
                  stMoMsg *to_msg, enum UTcapTransactionType msgType, 
				  unsigned char acn_version)
{
	int						 acn, opCode;
    int                      i;
    int                      ret;
    int                      comp_len = 1;
	USccpAddr				 orig, dest;
    char                    *ptr;
    int                      cpTime;
	int                      pdu;
	void                     *msg;
	unsigned char            routeType , nationalType;
#if 0
	stMSC                    mscInfo;
	stSGSN                   sgsnInfo;
	char                     smscName[CP_STRVAL_SIZE];
	stMscSgsn				mscSgsnInfo;
	stSMSC					smscInfo;
#endif
	stAddr                   imsi;
	struct PrivateExtensionList    privateExt;
	unsigned char            encBuf[1024], tmpBuf[1024];
	_TPDU                   rTPDU;
	int                     acnLen;
	unsigned char           acnStr[12];
	char 					tpduStr[2048];
	MO_ForwardSM_Arg_V3     mof;
	ForwardSM_Arg_V2        fsm;

	param.length = sizeof(encBuf);
	param.value = encBuf;

	if(acn_version == MAP_VERSION_1 || acn_version == MAP_VERSION_2)
	{
		memset(&fsm, 0, sizeof(ForwardSM_Arg_V2));

		ConvStrToAddressString(strlen(to_msg->origNode.isdn) , to_msg->origNode.isdn,
				&fsm.sm_RP_DA.u.serviceCentreAddressDA);
		fsm.sm_RP_DA.choice = serviceCentreAddressDA_chosen;

		ConvAddressToISDNString(&to_msg->orig,
				&fsm.sm_RP_OA.u.msisdn);
		fsm.sm_RP_OA.choice = SM_RP_OA_msisdn_chosen;

		fsm.sm_RP_UI.length = to_msg->data_len;
		if(to_msg->data_len > 0)
			memcpy(&fsm.sm_RP_UI.value, to_msg->data, to_msg->data_len);

		if(acn_version == MAP_VERSION_2)
			acn = ACN_MO_V2;
		else
			acn = ACN_MO_V1;
		opCode = forwardSM_V2.u.localValue;
		ret = ossEncode(world, pdu = ForwardSM_Arg_V2_PDU, msg = &fsm, &param);
	}
	else
	{
		memset(&mof, 0, sizeof(MO_ForwardSM_Arg_V3));

		ConvStrToAddressString(strlen(to_msg->origNode.isdn) , to_msg->origNode.isdn,
            &mof.sm_RP_DA.u.serviceCentreAddressDA);
		mof.sm_RP_DA.choice = serviceCentreAddressDA_chosen;

		/* SM_RP_OA */
		ConvAddressToISDNString(&to_msg->orig,
				&mof.sm_RP_OA.u.msisdn);
		mof.sm_RP_OA.choice = SM_RP_OA_msisdn_chosen;

		mof.sm_RP_UI.length = to_msg->data_len;
		if(to_msg->data_len > 0)
			memcpy(&mof.sm_RP_UI.value, to_msg->data, to_msg->data_len);

		acn = ACN_MO_V3;
		opCode = mo_forwardSM_V3.u.localValue;
		ret = ossEncode(world, pdu = MO_ForwardSM_Arg_V3_PDU, msg = &mof, &param);
	}

    if(ret)
    {
        uaLog(L_CRT, "ossEncode error: %s", ossGetErrMsg(world));
        return IXERR;
    }

    if(msgType == UTCAP_CONTINUE)
    {
        invId = invId + 1;
        if(invId > 255)
            invId = 1;
    }

    bzero((void*)&dest, sizeof(dest));
    bzero((void*)&orig, sizeof(orig));

	setRouteAddr(to_msg->routeType, &dest, &orig, to_msg->origNode.pCode, to_msg->origNode.ssn, to_msg->origNode.isdn,
			to_msg->destNode.pCode, to_msg->destNode.ssn,
			to_msg->destNode.isdn, NULL, NODE_SMSC);
	
	cpTime = 5;
    //getMtfTime(&cpTime);

    if(msgType == UTCAP_CONTINUE)		/* add provId to continue */
        ret = sig_sendContinueInvoke( gTcapInfo, opCode, userId, &orig, &dest, 
				cpTime, param.value, param.length, invId, provId);
    else {
		ret = sig_sendBeginInvoke( gTcapInfo, opCode, userId, &orig, &dest, 
				cpTime, param.value, param.length, acn, NULL);
	}

    if(ret == 0 )
    {
		if ( isInTrace( diagId, 1)) 
		{
			MakeACN(&acnLen, acnStr, acn);

			sig_minTraceTcapComplex(LPOS, getTraceNum( diagId), TCAP_SEND, 
					msgType, -1, userId, 
					acnStr, acnLen, 0,
					&orig, &dest,
					UTCAP_COMP_INVOKE, opCode, invId, 
					param.value, param.length); 

			MinTraceMap(LPOS, getTraceNum( diagId), 0, 0, world, pdu, msg);

			uaLog(L_INFO, "pdu = %d", pdu);
			/* decode TPDU */
#if 0
			if(pdu == MO_ForwardSM_Arg_V3_PDU)
			{
				ret = DecodeTPDU(&rTPDU, mof.sm_RP_UI.value,
						mof.sm_RP_UI.length, DIRECTION_MS_SC,
						TPDU_FALSE);
				if ( ret >= 0) {
					printTpdu( &rTPDU, tpduStr);
					MinTrace( LPOS, getTraceNum( diagId), "TPDU\n%s", tpduStr);
				}
				else {
					MinTrace( LPOS, getTraceNum( diagId), 
							"TPDU decoding failed");
				}
			}
#endif
		}		

        uaLog(L_INFO, "Diag Sent userId=%d diagId=%d", userId, diagId);
        return IXOK;
    }
    else
    {
        uaLog(L_MAJ, "sig_sendBeginInvoke NEGATIVE(ret=%d)", ret );
        return IXERR;
    }
	return IXOK;
}

int recvResponse(int waitTime)
{
    struct timeval timeout;
    int selectRc, rval2, isComp, compNum, rCnt;
    int maxFd = 0;
	int diagId;
    bool isActive;
	int	 acnVersion;		

	UTcapPrimitive prim ;
	UTcapComponents comp ;

	rCnt = 0;

	do {

		timeout.tv_sec = 0;
		timeout.tv_usec = 100000;   /* 100 msec */

        selectRc = utcap_select( gTcapInfo, 0, NULL, NULL, NULL, &timeout, &isActive);

        if(isActive)
        {
            int i, isComp;
            int msgType, userDid, provId;

            rval2 = utcap_recv(gTcapInfo, (void*)&prim, &isComp, &compNum);
			if ( rval2 < 0) {
                uaLog( L_MAJ, "utcap_recv() failed : ec=%d", u_ec());
                return -1;
            }
    
            rCnt ++; 

            isComp = rval2;
			sig_printPrimitive(&prim);

            msgType = prim.u.datInd.msgType;
            userDid = prim.u.datInd.suDlgId;                 
            provId = prim.u.datInd.spDlgId;                  

            /* Diag ID 가 테이블에 없다는 의미는 이미 timeout등에 의해 삭제된 */
            /* transaction에 대해 뒤늦게 응답이 왔다는 의미이므로 무시한다. */
            if(userDid != 0 && (diagId = getDiagId( userDid)) < 0) 
            {
				uaLog(L_CRT, 
                  "Recv: No such uid in Diag Table, p_type[%d] uid[%d] pid[%d]",
					msgType, userDid, provId);
				gRcvNackCnt++;
				continue;
			}

			if(!(prim.type == UTcapPrimitiveType_DAT_IND &&
				 (prim.u.datInd.msgType == UTCAP_END ||
				  prim.u.datInd.msgType == UTCAP_CONTINUE))) {

				uaLog( L_INFO, "Invalid PrimType" );
				gRcvNackCnt++;
			    procPrim( &prim, diagId);
				continue;
			}


			if( msgType != UTCAP_END && msgType != UTCAP_CONTINUE)
			{
				sig_minTraceTcap( LPOS,getTraceNum(diagId), &prim, &comp, TCAP_RECV);
				uaLog( L_INFO, "Invalid msgType" );
				gRcvNackCnt++;
				procPrim(&prim, diagId);
				continue;
			}

			uaLog(L_MIN,  "New Msg Received %s isComp=%d compNum=%d",       
					  UTCAP_TRANSACTION_STR( prim.u.datInd.msgType), 
					  isComp, compNum);                         
			
			Print_Primitive(&prim);

            for( i=0; i< compNum; i++)
            {
                rval2 = utcap_getComp( gTcapInfo, userDid, provId, &comp);
                if ( rval2 < 0)
				{
					gRcvNackCnt++;
                    uaLog( L_MAJ, "utcap_getComp failed E=%d", rval2);
				}
                else
				{
					Print_Component(&comp);
                    handleMoResult( &prim, &comp, userDid, provId, diagId);
				}
            }
        }

        if ( selectRc < 0) {
            if ( errno == EINTR) continue;
            uaLog( L_MAJ, "%s", ustr_errnof("utcap_select err="));
            return -1;
        }
    }while( isActive > 0 && rCnt <= maxBurst);
}


int handleMoResult(UTcapPrimitive *prim, UTcapComponents *comp, 
                    int userId, int provId, int diagId)
{
	stMoMsg *to_msg;
	int		acn;
	int		ret;

	to_msg = (stMoMsg *)GetMoQelmt(diagId);
	if(to_msg == NULL)
	{
		if( prim->u.datInd.msgType == UTCAP_END && 
            prim->u.datInd.msgType == UTCAP_CONTINUE)
			uaLog(L_MAJ, "DIAG_ID wrong! -- %d", diagId);
		gRcvNackCnt++;
        return -1;
	}

	sig_printComponent(comp);

    acn = sig_checkACN(&prim->u.datInd.dlgEv) ;

	uaLog(L_INFO, "acn is %d, diagId[%d]", acn, diagId);

#if 0
	if(acn == IS_ACN_NOT_SET)
		;
	else if(to_msg->destNode.nodeType == NODE_MSC || to_msg->destNode.nodeType == NODE_SGSN)
	{
		if(acn == ACN_MT_V1)
			UpdateMscSgsnAcnVersion(to_msg->destNode.isdn, MAP_VERSION_1);
		else if(acn == ACN_MT_V2)
			UpdateMscSgsnAcnVersion(to_msg->destNode.isdn, MAP_VERSION_2);
		else if(acn == ACN_MT_V3)
			UpdateMscSgsnAcnVersion(to_msg->destNode.isdn, MAP_VERSION_3);
	}
	else if(to_msg->destNode.nodeType == NODE_SMSC)
	{
		if(acn == ACN_MO_V1)
			UpdateSMSCAcnVersion(to_msg->destNode.isdn, MAP_VERSION_1);
		else if(acn == ACN_MO_V2)
			UpdateSMSCAcnVersion(to_msg->destNode.isdn, MAP_VERSION_2);
		else if(acn == ACN_MO_V3)
			UpdateSMSCAcnVersion(to_msg->destNode.isdn, MAP_VERSION_3);
	}
#endif
	
	if( isInTrace(diagId, 1)) {
		sig_minTraceTcap( LPOS, getTraceNum(diagId), prim, comp, TCAP_RECV);
	}

	if(comp->compType != UTCAP_COMP_RET_RES_L && 
	   comp->compType != UTCAP_COMP_ERROR)
	{
		uaLog( L_INFO, "Invalid compType" );
		gRcvNackCnt++;
		procComp(comp, diagId);
        return -1;
	}

	if(comp->compType == UTCAP_COMP_RET_RES_L )
		ret = handleResult( diagId, prim, comp, to_msg);
	else if(comp->compType == UTCAP_COMP_ERROR)
		ret = handleError( diagId, prim, comp, to_msg);

    return ret ;
}


int handleResult( int diagId, 
                  UTcapPrimitive *prim, 
                  UTcapComponents *comp, 
                  stMoMsg *to_msg)
{
	unsigned char             decBuf[1024];
	char 					  buf[512];
    MO_ForwardSM_Res_V3       *mof;
	int                       userId, p_type, provId, ret, pduNum, len = 0;
	int 					  mySsn;
	smsf_msg_t 				  respMsg;
	_RPDU 					  rpdu;

	memset(&respMsg, 0, sizeof(smsf_msg_t));
	memset(&rpdu, 0, sizeof(_RPDU));

	userId = prim->u.datInd.suDlgId ;
	p_type = prim->u.datInd.msgType ;
	provId = prim->u.datInd.spDlgId ;

	uaLog(L_INFO, "Receive MOF Ack, diagId=%u, orig=%s, imsi=%s, node=%s",
			diagId, to_msg->orig.min, to_msg->imsi.min, to_msg->destNode.isdn);
	gRcvAckCnt++;

    if(comp->bufLen > 0)
	{
	    param.length = (long)comp->bufLen;
		param.value = (unsigned char *)comp->cpBuf;

		pduNum = MO_ForwardSM_Res_V3_PDU;
		mof   = (MO_ForwardSM_Res_V3 *)decBuf;
		ossSetDecodingLength(world, sizeof(decBuf));
		if(ossDecode(world, &pduNum, &param, (void **)&mof))
		{
			uaLog(L_MAJ, "ossDecode MO_ForwardSM_Res_V3_PDU");
			uaLog(L_MAJ, "ERROR : (%s)", ossGetErrMsg(world));
		}
    }

	if ( isInTrace( diagId, 1)) {
		MinTraceMap(LPOS, getTraceNum( diagId),
			(unsigned char *)comp->cpBuf, (int)comp->bufLen, 0, 0, 0);
	}

	respMsg.msg_type = MO_RESP;
	strcpy(respMsg.supi, to_msg->imsi.min);
	strcpy(respMsg.gpsi, to_msg->orig.min);
 
	ret = MakeRPDU(MSG_RESP, DIRECTION_N_MS, 0, NULL, NULL, 0, to_msg->msgRef, &respMsg.data_len, respMsg.data);
    if(ret != IXOK)
    {
        uaLog(L_CRT, "MakeRPDU(), Make RP-ACK fail, orig[%s], imsi[%s]", to_msg->orig.min, to_msg->imsi.min);
        return IXERR;
    } 

	ret = InsProxyQMsg(&respMsg, MTYPE_RESP);

	if(ret == IXERR)
	{
		ua_sndConsolMsg((unsigned char *)"S6142", "SIGOUT", 0,
			SAMD_ALARM_MINOR, "Proxy Q full. Result lost.");
		errQueueFlag = ERROR_STATE_ERROR;
		uaLog(L_MAJ, "Insert Proxy QMsg fail, ret=%d", ret);
		return -1;
	}
	else if (errQueueFlag == ERROR_STATE_ERROR)
	{
#if 0
		ua_sndConsolMsg((unsigned char *)"S6142", "SIGOUT", 0,
			SAMD_ALARM_NORMAL, "%s Q normal.", to_msg->select == MOF_MSG ? "MO":"MT");
#endif
		uaLog(L_INFO, "Insert ProxyQ succ, orig[%s], imsi[%s]", to_msg->orig.min, to_msg->imsi.min);
		errQueueFlag = SAMD_ALARM_NORMAL;
	}

	inc_mof_resp_ack(to_msg->destNode.isdn);

	if ( isInTrace( diagId, 1)) {

		MinTrace(LPOS, getTraceNum(diagId),
"<<===== MOF Return Result <<=====\n\
MSG REF     : %d\n\
ORIG        : %s\n\
IMSI        : %s\n\
NODE        : %s - %d(H'%X)\n\
Status      : S\n\
Positive Result from %s",
			to_msg->msgRef,
			to_msg->orig.min,
			to_msg->imsi.min,
			strlen(to_msg->destNode.isdn) == 0 ? "Unknown" :
				to_msg->destNode.isdn,
			to_msg->destNode.pCode, to_msg->destNode.pCode,
			to_msg->destNode.isdn);
	}

	uaLog(L_INFO, "MOF: Diag %4d Acked  Q:%d", diagId, GetNumMoResQ());
	
	SetDone(diagId);

	return 0;
}

int handleError(int diagId,
                UTcapPrimitive *prim,
                UTcapComponents *comp,
                stMoMsg *to_msg)
{
#if 0
    stMoMsg                    moResult;
    stMtMsg                    mtResult;
#endif
	smsf_msg_t 				   moResp;
    AbsentSubscriberSM_Param   *absent;
    SM_DeliveryFailureCause    *dfc;
	unsigned char              decBuf[1024];
	void                       *msg;
	int                        ret, errCode, userId, pduNum, pos;
	_RPDU 					   rpdu;

	userId = prim->u.datInd.suDlgId ;

	gRcvNackCnt++;

	ret = sig_decodeError(&errCode, comp);
	if(ret == IXERR)
	{
		uaLog(L_MAJ, "TC_U_ERROR: Error Code Decode Fail");

		if ( isInTrace( diagId, 1)) 
			MinTrace(LPOS, getTraceNum( diagId),
				"\t Result from Node [%s] OP EC Error",
				to_msg->destNode.isdn);

		uaLog(L_MAJ, "MTF: Diag %4d local error",
			diagId);

		sendErrToEngine(diagId, CC_RECV_EC_ERROR, MAP_VERSION_N);
		SetDone(diagId);
		return -1;
	}

	errCode += 3000;

	inc_mof_resp_nack(to_msg->destNode.isdn);

	uaLog(L_MAJ,
		"Receive MOF Nack, orig=%s, imsi=%s, cc=%d, len=%d, node=%s",
		to_msg->orig.min, to_msg->imsi.min, errCode, comp->bufLen, to_msg->destNode.isdn);

    if(comp->bufLen > 0 && 
		(errCode == CC_ABSENT_SUBSCRIBER_SM || 
		 errCode == CC_SM_DELIVERY_FAILURE))
    {
        param.length = (long)comp->bufLen;
        param.value = (unsigned char *)comp->cpBuf;

        if(errCode == CC_ABSENT_SUBSCRIBER_SM)
        {
            absent = (AbsentSubscriberSM_Param*)decBuf;
            pduNum = AbsentSubscriberSM_Param_PDU;
            ossSetDecodingLength( world, sizeof(decBuf));
            ret = ossDecode(world, &pduNum, &param, (void **)&absent);
            msg = absent;
        }
        else if(errCode == CC_SM_DELIVERY_FAILURE)
        {
            dfc = (SM_DeliveryFailureCause*)decBuf;
            pduNum = SM_DeliveryFailureCause_PDU;
            ossSetDecodingLength( world, sizeof(decBuf));
            ret = ossDecode(world, &pduNum, &param, (void **)&dfc);
            msg = dfc;
        }

        if(ret)
        {
            if(errCode == CC_ABSENT_SUBSCRIBER_SM)
                uaLog(L_MAJ, "ossDecode AbsentSubscriberSM_Param_PDU");
            else if(errCode == CC_SM_DELIVERY_FAILURE)
                uaLog(L_MAJ, "ossDecode MT_ForwardSM_Res_PDU");

            uaLog(L_MAJ, " ERROR : (%s)", ossGetErrMsg(world));

            if ( isInTrace( diagId, 1))
                MinTrace(LPOS, getTraceNum( diagId),
                    "\t Result from %s [%s] Para Error",
                    to_msg->destNode.nodeType == NODE_MSC ? "MSC" :
                    to_msg->destNode.nodeType == NODE_SGSN ? "SGSN" :
					to_msg->destNode.nodeType == NODE_SMSC ?
                        "SMSC" : "Unknown",
                    to_msg->destNode.isdn);

            uaLog(L_MAJ, "MOF: Diag %4d Para error", diagId);

			sendErrToEngine(diagId, errCode, MAP_VERSION_N);
            SetDone(diagId);
            return -1;
        }

        if ( isInTrace( diagId, 1))
            MinTraceMap(LPOS, getTraceNum( diagId), 0, 0, world, pduNum, msg);

        if(errCode == CC_SM_DELIVERY_FAILURE)
        {
            if(dfc->sm_EnumeratedDeliveryFailureCause == SM_EnumeratedDeliveryFailureCause_memoryCapacityExceeded)
            {
				errCode = CC_MCEF;
            }
			else if (dfc->sm_EnumeratedDeliveryFailureCause == equipmentProtocolError )
			{
				errCode = CC_PROTOCOL_ERR;
			}
			else if (dfc->sm_EnumeratedDeliveryFailureCause == equipmentNotSM_Equipped)
			{
				errCode = CC_NOT_SM_EQUIPPED;
			}
			else if (dfc->sm_EnumeratedDeliveryFailureCause == unknownServiceCentre)
			{
				errCode = CC_UNKNOWN_SC;
			}
			else if (dfc->sm_EnumeratedDeliveryFailureCause == sc_Congestion)
			{
				errCode = CC_SC_CONGESTION;
			}
			else if (dfc->sm_EnumeratedDeliveryFailureCause == invalidSME_Address)
			{
				errCode = CC_INVALID_SME_ADDR;
			}
			else if (dfc->sm_EnumeratedDeliveryFailureCause == subscriberNotSC_Subscriber)
			{
				errCode = CC_NOT_SC_SUBSCRIBER;
			}
			//mtResult.u.resp.dfc = dfc->sm_EnumeratedDeliveryFailureCause;
        }
    }

	memset(&moResp, 0, sizeof(smsf_msg_t));

	moResp.msg_type = MO_RESP;
	strcpy(moResp.supi, to_msg->imsi.min);
	strcpy(moResp.gpsi, to_msg->orig.min);
	
	ret = MakeRPDU(MSG_RESP, DIRECTION_N_MS, errCode, NULL, NULL, 0, to_msg->msgRef, &moResp.data_len, moResp.data);
	if(ret != IXOK)
	{
		uaLog(L_CRT, "MakeRPDU(), Make RP-ACK fail, orig[%s], imsi[%s]", to_msg->orig.min, to_msg->imsi.min);
		return IXERR;
	}

	ret = InsProxyQMsg(&moResp, MTYPE_RESP);

	if(ret == IXERR)
	{
		ua_sndConsolMsg((unsigned char *)"S6142", "SIGOUT", 0,
			SAMD_ALARM_MINOR, "ProxyQ full. Result lost.");
		errQueueFlag = ERROR_STATE_ERROR;
		uaLog(L_MAJ, "Insert ProxyQ fail, ret=%d", ret);
		return -1;
	}
	else if (errQueueFlag == ERROR_STATE_ERROR)
	{
		ua_sndConsolMsg((unsigned char *)"S6142", "SIGOUT", 0,
			SAMD_ALARM_NORMAL, "Proxy Q normal.");
		errQueueFlag = ERROR_STATE_NORMAL;
	}

	if ( isInTrace( diagId, 1)) 
	{
		MinTrace(LPOS, getTraceNum(diagId),
"<<===== MOF Return Result <<=====\n\
MSG REF     : %d\n\
Node        : %s - %d(H'%X)\n\
CC          : %d\n\
Negative Result from %s", 
			to_msg->msgRef,
			strlen(to_msg->destNode.isdn) == 0 ? "Unknown" : to_msg->destNode.isdn,
			to_msg->destNode.pCode, to_msg->destNode.pCode, errCode,
			to_msg->destNode.isdn);
	}

	uaLog(L_MAJ, "MOF: Diag %4d Nacked", diagId);
	SetDone(diagId);
	
	return 0;
}

int sendErrToEngine(int diagId, int err_code, char acnVer)
{
    int          ret;
	smsf_msg_t 	 respMsg;
	stMoMsg 	 *to_msg;

    to_msg = (stMoMsg *)GetMoQelmt(diagId);
    if(to_msg == NULL)
        return IXERR;

    if(err_code == CC_SS7_TIMEOUT)
    {
		inc_mof_send_time(to_msg->destNode.isdn);

        uaLog(L_CRT, "Timeout:%s, Node:%s(%s), MsgRef:%d",
            to_msg->orig.min,
            to_msg->destNode.isdn,
            to_msg->destNode.nodeType == NODE_MSC ? "MSC" :
            to_msg->destNode.nodeType == NODE_SGSN ? "SGSN" : 
			to_msg->destNode.nodeType == NODE_SMSC ? "SMSC" : "Unknown",
            to_msg->msgRef);

		if ( isInTrace( diagId, 1))
			MinTrace(LPOS, getTraceNum( diagId),
"<<===== MOF Return Result <<=====\n\
MSG REF    : %d\n\
Node       : %s - %d(H'%X)\n\
Error Code : %d",
				to_msg->msgRef,
				strlen(to_msg->destNode.isdn) == 0 ? "Unknown" : to_msg->destNode.isdn,
				to_msg->destNode.pCode, to_msg->destNode.pCode, err_code);

    }
    else if(err_code == CC_FLOWCTRL || err_code == CC_LOCAL_ERROR)
    {
        inc_mof_send_fail( to_msg->destNode.isdn);
    }
    else
    {
		inc_mof_resp_nack( to_msg->destNode.isdn);

		if ( isInTrace( diagId, 1)) {
			MinTrace(LPOS, getTraceNum( diagId),
"<<===== MOF Return Result <<=====\n\
MSG REF    : %d\n\
NODE       : %s - %d(H'%X)\n\
Error Code : %d",
				to_msg->msgRef,
				strlen(to_msg->destNode.isdn) == 0 ? "Unknown" : to_msg->destNode.isdn,
				to_msg->destNode.pCode, to_msg->destNode.pCode, err_code);
		}
    }

	memset(&respMsg, 0, sizeof(smsf_msg_t));
	respMsg.msg_type = MO_RESP;
	strcpy(respMsg.supi, to_msg->imsi.min);
	strcpy(respMsg.gpsi, to_msg->orig.min);

	ret = MakeRPDU(MSG_RESP, DIRECTION_N_MS, err_code, NULL, NULL, 0, to_msg->msgRef, &respMsg.data_len, respMsg.data);
    if(ret != IXOK)
    {
        uaLog(L_CRT, "MakeRPDU():Make RP-ACK fail, orig[%s], imsi[%s]", to_msg->orig.min, to_msg->imsi.min);
        return IXERR;
    }

	ret = InsProxyQMsg(&respMsg, MTYPE_RESP);

    uaLog(L_MAJ, "Node=%s, MsgRef=%d, ORIG=%s, IMSI=%s, CC=%d", 
        to_msg->destNode.isdn, to_msg->msgRef, to_msg->orig.min, to_msg->imsi.min, err_code);

    if(ret == IXERR)
    {
		ua_sndConsolMsg((unsigned char *)"S6142", "SIGMO", 0,
			SAMD_ALARM_MINOR, "Proxy Q full. Result lost.");
		errQueueFlag = ERROR_STATE_ERROR;
        uaLog(L_MAJ, "Insert ProxyQ fail, ret=%d, orig[%s], msgRef[%u]", 
				ret, to_msg->orig.min, to_msg->msgRef);
    }
	else if (errQueueFlag == ERROR_STATE_ERROR)
	{
		ua_sndConsolMsg((unsigned char *)"S6142", "SIGMO", 0,
			SAMD_ALARM_NORMAL, "Proxy Q normal.");
		errQueueFlag = ERROR_STATE_NORMAL;
	}

    return IXOK;
}


int procComp(UTcapComponents *comp, int diagId)
{
    int        err_code;
	int mySsn;

	//getMySSN(&mySsn);
	mySsn = 8;

    if(comp->compType == UTCAP_COMP_REJ_LOCAL  || 
       comp->compType == UTCAP_COMP_REJ_REMOTE ||
       comp->compType == UTCAP_COMP_REJ_USR)
        err_code = CC_RECV_REJECT;
	else if(comp->compType == UTCAP_COMP_CANCEL) {
		//sig_sendTCUAbort(gTcapInfo, comp->suDlgId, comp->spDlgId , mySsn);
		err_code = CC_SS7_TIMEOUT;
	}

    else
        err_code = CC_RECV_UNKNOWN_COMP;

    sendErrToEngine(diagId, err_code, MAP_VERSION_N);
#if 0
    fprn_prim_comp("MTF: Recv wrong component ", primitive, component, MSG_TYPE_GSM);
#endif
    SetDone(diagId);

    return IXOK;
}


int procPrim(UTcapPrimitive *prim, int diagId)
{
	int                       err_code, isACN, ret;
	stMoMsg                  *moMsg;
	UTcapPrimitive_DAT_IND    *ind;
	int mySsn;

	//getMySSN(&mySsn);
	mySsn = 8;

	ind = &(prim->u.datInd);
    uaLog( L_MAJ, "Invalid primitive %s", UTCAP_TRANSACTION_STR(ind->msgType));

    switch (ind->msgType)
    {
        case UTCAP_NULL:
            sig_sendTCUAbort(gTcapInfo, ind->suDlgId, ind->spDlgId, mySsn);
            UnsetDiagIDinTable(ind->suDlgId);
            break;

        case UTCAP_P_ABORT:
            //prn_other_prim(prim);
            err_code = CC_RECV_PABORT;
            sendErrToEngine(diagId, err_code, MAP_VERSION_N);
            SetDone(diagId);
            break;

        case UTCAP_U_ABORT:
            moMsg = (stMoMsg *)GetMoQelmt(diagId);
			/* NULL 인 경우 예외 처리 
			   by comus 2007/08/29
			 */
			if(moMsg == NULL) return IXERR;

#if 0
            isACN = sig_checkACN(&prim->u.datInd.dlgEv) ;
            if(isACN == IS_ACN_NOT_SET)
                err_code = CC_RECV_UABORT;
            else  
			{
				if((ret = UpdateACNOnTable(mtfMsg->destNode.nodeType, 
						         mtfMsg->destNode.isdn, mtfMsg->cvtAcnFlag, isACN)) != IXERR)
					err_code = CC_RECV_ACN_ERROR;
				else
                    err_code = CC_RECV_UABORT;
			}

			if(err_code == CC_RECV_ACN_ERROR)
			{
				uaLog(L_MIN, "Map Version Nego and Retransmission, dest[%s], orig[%s], msgId[%u], ACN[%d]",
							mtfMsg->dest.min, mtfMsg->orig.min, mtfMsg->msgId, mtfMsg->cvtAcnFlag);
						
				if(InsSigOutQMsg(mtfMsg) != IXOK)
				{
					uaLog(L_CRT, "Insert Fail SIGOUT Q, dest[%s], orig[%s], msgId[%u]",
							mtfMsg->dest.min, mtfMsg->orig.min, mtfMsg->msgId);
				}
				SetDone(diagId);
			}
			else
			{
#endif
				//prn_other_prim(prim);
				sendErrToEngine(diagId, err_code, ret);
				SetDone(diagId);
//			}
            break;

		case UTCAP_NOTICE:
			sig_sendTCUAbort(gTcapInfo, ind->suDlgId, ind->spDlgId , mySsn);
			err_code = CC_SS7_TIMEOUT;
			sendErrToEngine(ind->suDlgId, err_code ,  MAP_VERSION_N);
			SetDone(ind->suDlgId);

            break;
    }
    return IXOK;
}


