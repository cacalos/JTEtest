#include <sigtran_util.h>

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

#include <ua_log.h>
#include <ua_sysdef.h>
#include <ua_syslib.h>
#include <ua_oam_type.h>
#include <ua_mtype.h>

//#include <Config.h>
#include <iXCauseCode.h>
//#include <iXConfParam.h>
#include <ASN/asn_smsc.h>
#include <SS7/ix7map.h>
#include <SS7/ss7_resq.h>
#include <SS7/links.h>
#include <SS7/map2.h>
#include <RPDU/RPDU.h>
#include <smsf_msg.h>


#include <iXss7Trace.h>
#include <iXTrace.h>
#include <iXMapOp.h>

//#include <iXEngine.h>

#include "mt.h"

#define INC_DIAG_ID_MT  (((gDiagId+1) >= MAX_DIAG_ID_MT) ? (gDiagId=1) : (gDiagId++))

#define	IX_CONT	2
#define CONF_FILE_MO          "uamo.conf"
#define MAX_INQ_BURST         100

static int					maxBurst = MAX_INQ_BURST;

//extern int            tc_errno;
//extern char          *tc_error_text[];

extern long           timezone;

#if 0
/*----- Config Value ---------*/
int                   MyPC;
int                   MySSN              = 8;
int                   Link_usage         = 80;
int                   Recv_wait_msec     = 9;        
#endif

unsigned int            gSendCnt = 0;
unsigned int            gMtfSendCnt = 0;
unsigned int            gMtfAckSendCnt = 0;
unsigned int            gMtfNackSendCnt = 0;
unsigned int            gSriSendCnt = 0;
unsigned int            gSriCnt = 0;
unsigned int            gMtfCnt = 0;
unsigned int            gAlertCnt = 0;
unsigned int		 	gSriAck = 0;
unsigned int			gSriNack = 0;
unsigned int			gMtfAck = 0;
unsigned int			gMtfNack = 0;

unsigned int			gRecvMoCnt = 0;

/* Global 변수 정의 */  
int                   cnx_fail_times = 0;

/* Internal */
int                   is_send_mode = TRUE;
static int            errQueueFlag = ERROR_STATE_INIT;

/* OSS Global */
OssBuf                param;
OssBuf                infParam;
struct ossGlobal      w, *world = &w;
struct ossGlobal      w2, *world2 = &w2;
int gLogId;
char 					gHostname[32];

/* SIGTRAN variables */
UTcap *gTcapInfo;

/* function prototypes */
int myOssPrint( OssGlobal *w, const char *format, ... );
void closeProc(int);

static int				gDiagId = 1;

void see_results() 
{
    //prn_tc_err_cnt();
    prn_prim_cnt();
    prn_comp_cnt();
}


void closeProc( int sig)
{
    uaLog(L_CRT, "SIGNAL %d RECEIVED", sig);
    close_shm();

    see_results();
    uaLog(L_CRT, "----- %s  Ends  -----", _MODULE_NAME);
    exit(0);
}

#if 0
int GetInconf(char *file)
{
    int                fail = 0;
    char               buf[64];

    if(getConf(file, "MY_PCODE", buf) < 0)
    {
        uaLog(L_CRT, "Conf: can't find 'MY_PCODE' item in <%s>",
            file);
        fail = 1;
    }
    else
        MyPC = (int)atoi(buf);

    if(getConf(file, "MY_SSN", buf) < 0)
    {
        uaLog(L_CRT, "Conf: can't find 'MY_SSN' item in <%s>",
            file);
    }
    else
        MySSN = (int)atoi(buf);


    if(fail)
        return IXERR;
    return IXOK;
}
#endif

int main(int argc, char *argv[])
{
    int               i, ret, cpTime;
    int               seccnt = 0;
    int               cnxId = -1;
    char              confFileName[128];
    int               tmp_noti_timeout;
    int               tmp_mo_timeout;
    char             *configPtr;
	char	          fname[MAX_PATH_NAME];
	char 	         *env;
	static int        errCnxFlag = ERROR_STATE_INIT;
	int               lcnxId;

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

	gethostname( gHostname, sizeof(gHostname));
#if 0
    configPtr = getenv("SMS_CONFIG_DIR");
    if(configPtr == NULL)
    {
        uaLog(L_CRT, "Can't get environment variable '%s'",
            "SMS_CONFIG_DIR");
        closeProc(0);
    }
    else
    {
        sprintf(confFileName, "%s/%s", configPtr, CONF_FILE_SS7);
        ret = GetInconf(confFileName);
        if(ret == IXERR)
        {
            uaLog(L_CRT,
                "Can't find important data in config file");
            closeProc(0);
        }
    }
#endif

 	if((gTcapInfo = initSigtran( argc, argv, _MODULE_NAME)) == 0) {
		uaLog( L_CRT, "InitSigtran failed");
		closeProc(0);
	}

    sleep(1);

    if(OpenGCA() == IXERR)
    {
        uaLog(L_CRT, "Can't open GCA !!!");
        closeProc(0);
    }

	OpenMtQ();
	OpenProxyQ();
	OpenStatQ();

    /* all iXss7xx processes contain following sentence */
    ossinit(world, map_protocol);
    ossinit(world2, map_protocol);
	ossSetDecodingFlags(world, NOCONSTRAIN|NOTRAPPING);
	ossSetDecodingFlags(world2, NOCONSTRAIN|NOTRAPPING);
	ossSetUserPrint( world, stdout, myOssPrint);
	ossSetUserPrint( world2, stdout, myOssPrint);

	/*
    if(InitMtResponseQ() < 0)
        closeProc(0);
	*/

	InitHandShakeListShm();

	initMTFstat();

    while (1)
    {
		proc_heartBeat();

		recvIncomingMsg();

		send_response(10);

        if(sec_ellapsed(1) == IXOK)
        {
			/*
			cpTime = 50;
			//getIncomingTime(&cpTime);
            CheckTimeOut(cpTime);
			mms_check_timeout(cpTime+5);
			*/

			if(gSriCnt+gMtfCnt+gSriSendCnt+gMtfAckSendCnt+gMtfNackSendCnt > 0)
			{
				uaLog(L_CRT, "[Rcv]SRI:%d, MTF:%d, [Snd]SRI_Resp:%d, MTF_Resp S:%d F:%d",
						gSriCnt, gMtfCnt, gSriSendCnt, gMtfAckSendCnt, gMtfNackSendCnt);
				gSriCnt = gMtfCnt = gSriSendCnt = gMtfAckSendCnt = gMtfNackSendCnt = 0;
			}
			gRecvMoCnt = 0;

			//updateInStat();
			updateMTFstat();
        }
    }

    closeProc(0);
	return 0;
}



int send_error3( UTcapPrimitive *prim, UTcapComponents *comp,
                unsigned char acn, int errCode, int dfc, char fcs, stNodeNumber *node, stAddr *imsi)
{
    int                      ret;
    int                      comp_len;
    SystemFailureParam       sf;
    UnexpectedDataParam      ud;
    SM_DeliveryFailureCause  df;
    DataMissingParam         dm;
	UnknownSubscriberParam 	 usp;
	UnidentifiedSubParam     uif;
	unsigned char encBuf[1024];
	int pdu;
	void *msg;

    if(prim == NULL || comp == NULL)
        return IXERR;

	uaLog(L_MIN, "send_erro3_uerror [%d], node[%s]", errCode, node->isdn);

    param.length = sizeof(encBuf);
    param.value = encBuf;

    if(errCode == CC_SYSTEM_FAILURE)
    {
        bzero((void *)&sf, sizeof(SystemFailureParam));
        sf.choice = networkResource_chosen;
        sf.u.networkResource = dfc;

        if(ossEncode(world, pdu = SystemFailureParam_PDU, msg = &sf, &param))
        {
            uaLog(L_CRT, "ossEncode error: %s",
                ossGetErrMsg(world));
            return IXERR;
        }
    }
    else if(errCode == CC_UNEXPECTED_DATA_VALUE)
    {
        bzero((void *)&ud, sizeof(UnexpectedDataParam));

        if(ossEncode(world, pdu = UnexpectedDataParam_PDU, msg = &ud, &param))
        {
            uaLog(L_CRT, "ossEncode error: %s",
                ossGetErrMsg(world));
            return IXERR;
        }
    }
    else if(errCode == CC_SM_DELIVERY_FAILURE)
    {
        bzero((void *)&df, sizeof(SM_DeliveryFailureCause));

        df.sm_EnumeratedDeliveryFailureCause = dfc;
        if(ossEncode(world, pdu = SM_DeliveryFailureCause_PDU, msg = &df, &param))
        {
            uaLog(L_CRT, "ossEncode error: %s",
                ossGetErrMsg(world));
            return IXERR;
        }
    }
    else if(errCode == CC_DATA_MISSING)
    {
        bzero((void *)&dm, sizeof(DataMissingParam));

        if(ossEncode(world, pdu = DataMissingParam_PDU, msg = &dm, &param))
        {
            uaLog(L_CRT, "ossEncode error: %s",
                ossGetErrMsg(world));
            return IXERR;
        }
    }
    else if(errCode == CC_UNKNOWN_SUBSCRIBER) /* added by comus 2007/05/14 */
    {
        bzero((void *)&usp, sizeof(UnknownSubscriberParam));

        if(ossEncode(world, pdu = UnknownSubscriberParam_PDU, msg = &usp, &param))
        {
            uaLog(L_CRT, "ossEncode error: %s",
                ossGetErrMsg(world));
            return IXERR;
        }
    } 
    else if(errCode == CC_UNIDENTIFIED_SUBSCRIBER) 
    {
        bzero((void *)&uif, sizeof(UnidentifiedSubParam));

        if(ossEncode(world, pdu = UnidentifiedSubParam_PDU, msg = &uif, &param))
        {
            uaLog(L_CRT, "ossEncode error: %s",
                ossGetErrMsg(world));
            return IXERR;
        }
    } 
	else  /* added by comus 2007/05/14 */
	{
		uaLog(L_CRT, "Undefined Error code [%d], Check Error code(send_error3)", errCode);
		return IXERR;
	}

	ret = sig_sendEndError( gTcapInfo, acn, prim, comp, errCode - 3000, param.value, param.length);
    if(ret == 0)
    {
		//int dlgId = UTCAP_PROV_DIAG_ID(prim);
		int dlgId = prim->u.datInd.suDlgId;


		setTraceMode(NULL, NULL, imsi);
		if ( IS_IN_TRACE( 1)) {
			sig_minTraceTcap(LPOS, &gTraceAddr, prim, comp, TCAP_SEND);

			MinTraceMap(LPOS, &gTraceAddr, 0, 0, world, pdu, msg);
		}

		/* get stat */
		switch( comp->opCode.string[0]) 
		{
			case MAP_OP_MTForwardSM :
				inc_mtf_send_nack(node->isdn);
				break;
			default :
				uaLog( L_MIN, "unknown opcode %d for stat", comp->opCode.string[0]);
				break;
		}

		uaLog(L_MIN, "Diag %4d Nack Sent", prim->u.datInd.spDlgId);
		gMtfNackSendCnt++;

        return IXOK;
    }

	uaLog(L_CRT, "sig_sendEndError failed E=%d", ret);
	return IXERR;
}


int MakeDiagnosticInfo(unsigned char *str, char fcs)
{
    int                      length;
    time_t                   now;
    struct tm                ptm;
    char                     ch1, ch2;

    length = 0;
    str[length] = 0x00;    /* TP-MTI */

    str[length] = fcs;
    length++;

    str[length] = 0x00;    /* headerIndi */
    length++;

    tzset();
    time(&now);
    localtime_r(&now, &ptm);

    ch1 = (ptm.tm_year % 100) / 10;
    ch2 = ptm.tm_year % 10;
    str[length] = ch1 | (ch2 << 4);
    length++;

    ch1 = (ptm.tm_mon+1) / 10;
    ch2 = (ptm.tm_mon+1) % 10;
    str[length] = ch1 | (ch2 << 4);
    length++;

    ch1 = ptm.tm_mday / 10;
    ch2 = ptm.tm_mday % 10;
    str[length] = ch1 | (ch2 << 4);
    length++;

    ch1 = ptm.tm_hour / 10;
    ch2 = ptm.tm_hour % 10;
    str[length] = ch1 | (ch2 << 4);
    length++;

    ch1 = ptm.tm_min / 10;
    ch2 = ptm.tm_min % 10;
    str[length] = ch1 | (ch2 << 4);
    length++;

    ch1 = ptm.tm_sec / 10;
    ch2 = ptm.tm_sec % 10;
    str[length] = ch1 | (ch2 << 4);
    length++;

    str[length] = EncodeTimeZone((int)timezone / 900) & 0xFF;
    length++;

    return length;
}


int send_response(int msg_send)
{
    int                         ret, cc = 0;
    int                         cnt = 0;
	smsf_msg_t 					resp;
    stMtResponseQ               mtRes;
    char                        origIsdn[DEFAULT_ADDR_LEN+1];
	_RPDU						rpdu;
	
    while(cnt < maxBurst)
    {
		cnt++;

		memset(&resp, 0, sizeof(smsf_msg_t));
        ret = GetMtMsg(&resp);
        if(ret != IXOK)
            break;

		if(strlen(resp.supi) < 1 && resp.data_len < 1)
		{
			uaLog(L_CRT, "IMSI is NULL or data_len is zero, [%d, %d]", strlen(resp.supi), resp.data_len);
			continue;
		}

		uaLog(L_MIN, "RECV SMSF_MSG - SUPI:%s, LEN:%d, CC:%d, diagId:%s",
                resp.supi, resp.data_len, resp.causeCode, resp.diag_id);

		if(resp.causeCode == 0)
		{
			memset(&rpdu, 0, sizeof(_RPDU));
			ret = DecodeRPDU(&rpdu, resp.data, resp.data_len, DIRECTION_MS_N);
			if(ret > 0 && (rpdu.MessageType != RPDU_RP_ACK && rpdu.MessageType != RPDU_RP_ERROR))
			{
				uaLog(L_CRT, "DecodeRPDU() fail, ret = %d, MsgType = %d", ret, rpdu.MessageType);
				continue;
			}
		}

		memset(&mtRes, 0, sizeof(stMtResponseQ));
		mtRes.acn = resp.acn;
		mtRes.prov_id = resp.prov_id;
		mtRes.inv_id = resp.inv_id;
		strcpy(mtRes.node.isdn, resp.smsc_node);

		/*
        ret = GetMtQelmt(rpdu.MessageReference, resp.supi, &mtRes);
        if(ret == IXERR)
        {
            uaLog(L_CRT, "No ResQ Msg msgRef[%d], supi[%s]", 
					rpdu.MessageReference, resp.supi);
            continue;
        }
        else
            uaLog(L_INFO, "ResQ Msg msgRef[%d], supi[%s]", rpdu.MessageReference, resp.supi);
		*/	

		if(resp.causeCode > 0 || rpdu.MessageType == RPDU_RP_ERROR)
		{
			ret = handleMtErrGsm( &mtRes, resp.causeCode, &rpdu, resp.diag_id);
		}
		else
		{
			ret = handleMtResGsm( &mtRes, resp.diag_id);
		}

//		SetDone(rpdu.MessageReference, resp.supi);

#if 0
        if( ( inRes.select & IN_RES_Q_MO_SELECT) ||
            ( inRes.select & IN_RES_Q_MT_SELECT) )
            strcpy(origIsdn, inRes.u.mt.u.data.origNode.isdn);
        else
            bzero((void *)origIsdn, sizeof(origIsdn));
#endif
    }

	maxBurst = burstControl_new(maxBurst, MAX_INQ_BURST, FALSE, GetMtQLen());
    return IXOK;
}



int recvIncomingMsg()
{ 
    int                     i;
	int						inv_id, diagId;
    int                     ret, res, com_ret;
    unsigned char           acn;

    stNodeNumber       node;
    stAddr             isdn;
	/*
    stMscSgsn          nodeInfo;
    stSMSC             smscInfo;
	*/

	int more, nRead;
	fd_set readFds;
	struct timeval timeout;
	int selectRc, rval2, isComp, compNum, rCnt;
	int maxFd = 0;
	bool isActive = 0;
	UTcapPrimitive prim;
	UTcapComponents comp;
	UTcapPrimitive_DAT_IND *ind;
	int mySsn;

	stHandShakeInfo         info;

	rCnt = 0;
	//getMySSN(&mySsn);
	mySsn = 8;
	do {
		maxFd = 0;
		timeout.tv_sec = 0;
		timeout.tv_usec = 10000;	/* 100 msec -> 10 msec */

		FD_ZERO( &readFds);

		selectRc = utcap_select( gTcapInfo, 0, NULL, NULL, NULL, &timeout, &isActive);

		if ( isActive) 
		{
			int i, isComp;
			int userDid, provId;

			/* read messages incoming from TCAP */
			rval2 = utcap_recv( gTcapInfo, (void*)&prim, &isComp, &compNum);

			if ( rval2 < 0) {
				uaLog( L_CRT, "utcap_recv() failed : ec=%d", u_ec());
				return -1;
			}

			rCnt ++;

			isComp = rval2;

			sig_printPrimitive(&prim);

			if( prim.type != UTcapPrimitiveType_DAT_IND ) {
				uaLog( L_MAJ, "Invalid PRIMITIVE %d", prim.type);
				continue;
			}

			ind = &( prim.u.datInd);
			userDid = ind->suDlgId;
			provId = ind->spDlgId;

			if( !(ind->msgType == UTCAP_BEGIN || ind->msgType == UTCAP_CONTINUE )) {
				procPrim( &prim);
				continue;
			}

			diagId = gDiagId;

			sig_getNodeNumber( &node, &ind->srcAddr);

			if(strlen(node.isdn) > 0)
				checkSmscList(node.isdn);
			
			uaLog(L_INFO , "node pCode %d ssn %d type %d  isdn %s, diagId=%d, user_id=%d, prov_id=%d", 
							node.pCode , node.ssn , node.nodeType , node.isdn, diagId, userDid, provId);

			acn = CheckACN( ind->dlgEv.pres, 
					ind->dlgEv.apConName.string, 
					ind->dlgEv.apConName.len);

			uaLog(L_MIN,  "New Msg Received %s isComp=%d compNum=%d acn=%d\n\
					acnName=[0x%x:0x%x:0x%x:0x%x:0x%x:0x%x:0x%x] acnLen=%d",
					UTCAP_TRANSACTION_STR( ind->msgType), isComp, compNum, 
					acn, ind->dlgEv.apConName.string[0], 
					ind->dlgEv.apConName.string[1],
					ind->dlgEv.apConName.string[2],
					ind->dlgEv.apConName.string[3],
					ind->dlgEv.apConName.string[4],
					ind->dlgEv.apConName.string[5],
					ind->dlgEv.apConName.string[6],
					ind->dlgEv.apConName.len );

			if(ind->msgType == UTCAP_CONTINUE && acn == IS_ACN_NOT_SET )
			{
				memset(&info, 0, sizeof(stHandShakeInfo));
				strcpy(info.isdn, node.isdn);

				uaLog(L_INFO, "Continue Invoke, [%s, %d, %d]", node.isdn, provId, acn);
				if(IsHandShakeFuncOn() && GetHandShakeList(&info) == IXOK) {
					acn = info.acn_version;
					uaLog(L_INFO, "CONTINUE INVOKE, ACN Set[0x%x], ISDN[%s]", acn, info.isdn);
				}
			}

			if(compNum == 0) {
				/* check routine  */
				/* Exclude component ack message */
				rval2 = sig_sendResultNotComp(gTcapInfo, acn, ind->spDlgId, &prim
						, UTCAP_CONTINUE);

				if(rval2 < 0) {
					uaLog(L_CRT, "sig_sendEndResultNotComp fail ");
				} else {
					uaLog(L_INFO, ">>> NOT COMPONENT ACK Sent dlgId[%d]", diagId);
				}

				if(IsHandShakeFuncOn() == IXOK)
				{
					memset(&info, 0, sizeof(stHandShakeInfo));

					strcpy(info.isdn, node.isdn);
					info.acn_version = acn;
					if(IsHandShakeListMsg(&info) != IXOK)
					{
						if(InsertHandShakeInfo(&info) != IXOK)
							uaLog(L_MAJ, "Insert Fail to HandShake List, info[%s, 0x%x]", info.isdn, info.acn_version);
						else
							uaLog(L_INFO, "Insert Success to HandShake List, info[%s, 0x%x]", info.isdn, info.acn_version);

					}
					else
						uaLog(L_INFO, "Check HandShake list info:[%s, 0x%x]", info.isdn, info.acn_version);
				}

				continue;
			}


			for( i=0; i< compNum; i++) 
			{
				rval2 = utcap_getComp( gTcapInfo, userDid, provId, &comp);
				if ( rval2 < 0) {
					uaLog( L_MAJ, "utcap_getComp failed E=%d", rval2);
					continue;
				}
				
				sig_printComponent(&comp);

				/* 1) if ACN is normal or Ver2, pass
				   2) check primitive and check component error */
				if(acn == ACN_GW_V2 || acn == ACN_GW_V3 || 
				   acn == ACN_MT_V2 || acn == ACN_MT_V3 || 
                  (acn == IS_ACN_NOT_SET &&
                   	(comp.opCode.string[0] == MAP_OP_FwdSM ||
                   	comp.opCode.string[0] == MAP_OP_FwdSM ||
                   	comp.opCode.string[0] == MAP_OP_MtFwdSM )))
                    ;
                else
                {
					int len;
					unsigned char acnStr[12];

					Print_Primitive(prim);
					Print_Component(comp);

					uaLog(L_CRT, "Refuse Message %x opCode %d", acn, comp.opCode.string[0]);

					ret = sig_sendTCUAbort( gTcapInfo, ind->suDlgId, ind->spDlgId, mySsn);
                    if(ret == 0) {
						continue;
					}
                    else
                    {
						uaLog(L_CRT, "sig_sendUAbort failed E=%d", ret);
                        return IXERR;
					}
                }


//				UpdateAcvVersionNego( &node , acn ) ;   

                if(comp.compType != UTCAP_COMP_INVOKE)
                {
                    procComp( &prim, &comp);
                    continue;
                }

				/* if op_code's len is not 1, error */
                if(comp.opCode.len != 1)
                {
                    uaLog(L_MAJ, "No OP received!");
                    if(com_ret != IXOK)
                    {
                        if(node.nodeType == NODE_MSC ||
                                node.nodeType == NODE_HLR ||
                                node.nodeType == NODE_SMSC ||
                                node.nodeType == NODE_SGSN)
                        {
							if (node.nodeType == NODE_MSC) ;

                            send_error3( &prim, &comp, acn,
                                CC_SYSTEM_FAILURE, 0, FCS_NO_ERROR, &node, NULL);
							uaLog(L_CRT, " Not found component len %d, send_error[%d] ",  
									comp.opCode.len, CC_SYSTEM_FAILURE);
                        }
                    }
                    continue;
                }

#if 0
				switch(comp.opCode.string[0]) {
					default :
						setNodeIndex( diagId, node.isdn);
						break;
				}
#endif

				inv_id = comp.invokeId.pres ? comp.invokeId.octet : 0;

				if(comp.opCode.string[0] == mt_forwardSM_V3.u.localValue)
				{
					acn = ACN_MT_V3;
					ret = handleMT( &comp, &prim, diagId, 
							&node, &isdn, inv_id, acn);
					gMtfCnt++;
					gRecvMoCnt++;
					continue;
				}
				else if (comp.opCode.string[0] == forwardSM_V2.u.localValue) 
				{
					acn = ACN_MT_V2;
					ret = handleMT( &comp, &prim, diagId, 
							&node, &isdn, inv_id, acn);
					gMtfCnt++;
					gRecvMoCnt++;
					continue;
				}
                else   /* Unknwon Op Code */ 
                {
					inc_mtf_recv_fail(node.isdn);

					uaLog(L_CRT, "Received Msg, diagId[%d], send_error[%d]", diagId, CC_UNEXPECTED_DATA_VALUE);
					send_error3( &prim, &comp, acn,
							CC_UNEXPECTED_DATA_VALUE, 0, FCS_NO_ERROR, &node, NULL);
					continue;
                }
			}
		}
	} while( isActive > 0 && rCnt <= maxBurst);


    return IXOK;
}

int handleMT(
	UTcapComponents *comp, 
	UTcapPrimitive *prim,
	int diagId,
    stNodeNumber *node,
	stAddr		*isdn,
	int inv_id,
	int acn )
{
	int 					res, ret, flowCnt = 0, isMMS = MMS_FALSE;
	int 					user_id, prov_id;
	int						pduNum;
    ForwardSM_Arg_V2       *ossmo2;
	MT_ForwardSM_Arg_V3		*ossmt3;
	stAddr                  errAddr, smscAddr, imsiAddr, origAddr, chkAddr;
    char                    fcs = 0;
	void 					*msgPtr;
	unsigned char 			decBuf[2048];
	char 					tpduStr[1024];
	UTcapPrimitive_DAT_IND *ind;
#ifdef YTL_SMSG
	unsigned short          res_select ;
#else
	char					res_select;
#endif
	static unsigned char 	msgRef = 0;
	smsf_msg_t 			 	smsfMsg;

	ind = &(prim->u.datInd);
	user_id = ind->suDlgId;
	prov_id = ind->spDlgId;

	memset(&smsfMsg, 0, sizeof(smsf_msg_t));
	memset(&imsiAddr, 0, sizeof(stAddr));
	memset(&origAddr, 0, sizeof(stAddr));
	memset(&chkAddr, 0, sizeof(stAddr));

	if(acn == ACN_MT_V3) 
	{
		uaLog(L_INFO, "Operation: mt_forwardSM_V3");

		param.length = (long)comp->bufLen;
		param.value = (unsigned char *)comp->cpBuf;

		pduNum = MT_ForwardSM_Arg_V3_PDU;
		ossmt3 = (MT_ForwardSM_Arg_V3 *)decBuf;
		ossSetDecodingLength( world, sizeof(decBuf));
		if(ossDecode(world, &pduNum, &param, (void **)&ossmt3))
		{
			uaLog(L_CRT, "ossDecode MT_Arg_V3 PDU, send_error[%d]", CC_UNEXPECTED_DATA_VALUE);
			uaLog(L_CRT, " ERROR : (%s)", ossGetErrMsg(world));

			inc_mtf_recv_fail(node->isdn);
			send_error3( prim, comp, acn,
				CC_UNEXPECTED_DATA_VALUE, 0, FCS_NO_ERROR, node, NULL);
			return 0;
		}
		msgPtr = ossmt3;

		if(ossmt3->sm_RP_OA.choice & SM_RP_OA_msisdn_chosen) {
			uaLog(L_CRT, "MTF's RP_OA is not type SC_Address");
			send_error3( prim, comp, acn,
				CC_UNEXPECTED_DATA_VALUE, 0, FCS_NO_ERROR, node, NULL);
			return 0;
		}

		if(ossmt3->sm_RP_OA.choice & serviceCentreAddressOA_chosen) 
		{
			ConvAddressStringToAddress(
					&ossmt3->sm_RP_OA.u.serviceCentreAddressOA, &smscAddr);
		}

		if(ossmt3->sm_RP_DA.choice & SM_RP_DA_imsi_chosen) 
		{
			ConvIMSIToAddress(&ossmt3->sm_RP_DA.u.imsi, &imsiAddr);
		} 

		/* If MMS field is set, response send CONTINUE reslut */
		if(ossmt3->bit_mask & MT_ForwardSM_Arg_V3_moreMessagesToSend_present)
			isMMS = MMS_TRUE;

		if(imsiAddr.len == 0)
		{
			uaLog(L_CRT, "Does not exist IMSI field in MTF Msg, origNode[%s]", smscAddr.min); 
			return IXERR;
		}

		uaLog(L_INFO,
			"Receive Mt_V3 Msg from [pCode:%d, isdn:%s] bit_mask:0x%x(mms:%d)",
			node->pCode,
			strlen(node->isdn) == 0 ? "Unknown" : node->isdn, ossmt3->bit_mask, isMMS);

	}
	else 
	{
		/* Add func for MAP version 2 Msg*/
	}

	memcpy(&chkAddr, &smscAddr, sizeof(stAddr));
	
	if( strlen(node->isdn) == 0) {
		checkSmscList(smscAddr.min);
		strcpy(node->isdn, smscAddr.min);
	}

	msgRef++;

	smsfMsg.msg_type = MT_MSG;
	smsfMsg.isMMS = isMMS;
	strncpy(smsfMsg.supi, imsiAddr.min, imsiAddr.len);

	ret = MakeRPDU(MSG_DATA, DIRECTION_N_MS, smsfMsg.causeCode, &chkAddr, 
			ossmt3->sm_RP_UI.value, ossmt3->sm_RP_UI.length, msgRef, 
			&smsfMsg.data_len, smsfMsg.data);
	if(ret != IXOK || smsfMsg.data_len < 1)
	{
		uaLog(L_CRT, "MakeRPDU() fail, origNode[%s], imsi[%s]", smscAddr.min, imsiAddr.min);
		return IXERR;
	}

	uaLog(L_INFO, "MT_ForwardSM: NODE[%s-%d.%d], IMSI[%s], msgRef[%d]",
			node->isdn, node->pCode, node->ssn, imsiAddr.min, msgRef);

	setTraceMode(NULL, NULL, &imsiAddr);

	if ( IS_IN_TRACE( 1)) {
		sig_minTraceTcap(LPOS, &gTraceAddr, prim, comp, TCAP_RECV);
		MinTraceMap(LPOS, &gTraceAddr, 0, 0,
				world, pduNum, msgPtr);
		/*
		printTpdu( &rTPDU, tpduStr);
		MinTrace(LPOS, getTraceNum(diagId), "TPDU\n%s", tpduStr);
		*/
	}

	if ( IS_IN_TRACE( 1)) {
		char subParaStr[200];
		int	remain;

		/* 05/18 sjkim : for subPara Log */
		memset(subParaStr, 0, sizeof(subParaStr));

		MinTrace(LPOS, &gTraceAddr,
				"<<===== MT_ForwardSM_Arg Recved <<=====\n\
NODE              : %s - %s(H'%X) SSN:%d \n\
Dest Addr(IMSI)   : %s\n\
TPDU Type         : %s\n\
Sub Para          : %s",
"SMSC",
				node->isdn, node->pCode, node->ssn,
				imsiAddr.min, 
				"TPDU_SMS_DELIVER", subParaStr );
	}


	/*
	if(insertMtResQ(diagId, user_id, prov_id, inv_id,
				acn, &prim->u.datInd.dstAddr, &prim->u.datInd.srcAddr,
				isMMS, &imsiAddr, msgRef, node) != IXOK)
	{
		// Q is full...
		uaLog(L_CRT, "Response Insert Fail!!!, Diag id =%d, IMSI[%s], send_error[%d]", 
				diagId, imsiAddr.min, CC_SYSTEM_FAILURE);
		ShowQStatus();
		inc_mtf_recv_fail(node->isdn);
		send_error3( prim, comp, acn,
				CC_SYSTEM_FAILURE, sc_Congestion, FCS_NO_ERROR, node, &imsiAddr);
		return 0;
	}

	uaLog(L_INFO, "InsertInResQ(), diagId[%d], IMSI[%s]", diagId, imsiAddr.min);
	*/

	smsfMsg.acn = acn;
	smsfMsg.prov_id = prov_id;
	smsfMsg.inv_id = inv_id;
	strcpy(smsfMsg.smsc_node, node->isdn);
	sprintf(smsfMsg.diag_id, "%s-%d", gHostname, diagId);

	ret = InsProxyQMsg(&smsfMsg, MTYPE_MT);
	if(ret == IXERR)
	{
		errQueueFlag = ERROR_STATE_ERROR;
		uaLog(L_CRT, "Insert Fail ProxyQ fail, diagId[%d], IMSI[%s], send_error[%d]", 
				diagId, imsiAddr.min, CC_SYSTEM_FAILURE);

		inc_mtf_recv_fail(node->isdn);
		send_error3( prim, comp, acn,
				CC_SYSTEM_FAILURE, sc_Congestion, FCS_NO_ERROR, node, &imsiAddr);
		//SetDone(msgRef, imsiAddr.min);
	}
	else
	{

		uaLog(L_INFO, "InsProxyQMsg() success, diagId[%s], IMSI[%s], len[%d]",
				smsfMsg.diag_id, imsiAddr.min, smsfMsg.data_len); 
		inc_mtf_recv_succ(node->isdn);
		char buff[1024];
		int remain;

		memset(buff, 0, sizeof(buff));

		MakeStrHexa(buff, smsfMsg.data, smsfMsg.data_len, &remain, 100, 100);
		uaLog(L_DBG, "smsfMsg data : \n\%s", buff);
	}
	INC_DIAG_ID_MT;

	return 1;

}


int procComp( UTcapPrimitive *prim, UTcapComponents *comp)
{
	/*
    fprn_prim_comp("AlertMo: Recv wrong component ", primitive, component,
		MSG_TYPE_UNKNOWN);
		*/
    return IXOK;
}


int procPrim( UTcapPrimitive *primitive)
{
	UTcapPrimitive_DAT_IND *ind;
	int mySsn;


	ind = &(primitive->u.datInd);
    switch (ind->msgType)
    {
        case UTCAP_NULL:
            /* SendTCUAbort2(TC_P_PROVIDER_ID(primitive)); */
			//getMySSN(&mySsn);
			mySsn = 8;
			sig_sendTCUAbort( gTcapInfo, ind->suDlgId, ind->spDlgId, mySsn);
            break;

        case UTCAP_U_ABORT:
            //prn_other_prim(primitive);
            break;

        case UTCAP_P_ABORT:
            //prn_other_prim(primitive);
            break;

        case UTCAP_NOTICE:
            //prn_other_prim(primitive);
            break;

        default :
            break;
    }
    return IXOK;
}

int handleMtErrGsm(stMtResponseQ *inRes, int cc, _RPDU *rpdu, char *diag_id)
{
    int                         parameterLen;
    char                        parameter[MAX_PARAMETER_LEN];
	int 						ret;
	unsigned char 				encBuf[1024];
	void 						*msg;
	int 						pdu, errCode = 0;
	int 						diagnostic = 0;
	SM_DeliveryFailureCause dfc;
	FacilityNotSupParam fns;
	SystemFailureParam sf;
	UnexpectedDataParam ud;
	IllegalSubscriberParam illegalSub;
	AbsentSubscriberSM_Param absentSub;
	AbsentSubscriberParam absentSubParam;
	UnidentifiedSubParam     uif;
	CallBarredParam			 callBarred;
	UnknownSubscriberParam 	 usp;

	param.length = sizeof(encBuf);
	param.value = encBuf;

	if(cc == CC_FLOWCTRL || cc == CC_NETCONGEST || cc == CC_SS7_TIMEOUT)
		cc = CC_SYSTEM_FAILURE;

	if(rpdu->Union.rError.CauseCode.cause > 0) {
		cc = ConvRpErrToCauseCode(rpdu->Union.rError.CauseCode.cause);

		switch(cc)
		{
			case CC_RP_MEMORY_CAPACITY_EXCEEDED :
				cc = CC_MCEF;
				break;
			case CC_RP_INVALID_SM_TRANSFER_REF_VALUE :
			case CC_RP_SEMANTICALLY_INCORRECT_MESSAGE :
			case CC_RP_INVALID_MANDATORY_INFORMATION :
			case CC_RP_MESSAGE_TYPE_NON_EXISTENT :
			case CC_RP_MESSAGE_NOT_COMPATIBLE :
			case CC_RP_INFO_ELEMENT_NON_EXISTENT :
			case CC_RP_PROTOCOL_ERROR_UNSPECIFIED :
			default :
				cc = CC_PROTOCOL_ERR;
		}
	}
	inc_mtf_send_nack(inRes->node.isdn);

	if(cc == CC_SM_DELIVERY_FAILURE || cc == CC_RP_MEMORY_CAPACITY_EXCEEDED || 
			(cc >= CC_MCEF && cc <= CC_NOT_SM_EQUIPPED))
	{
		if(cc == CC_RP_MEMORY_CAPACITY_EXCEEDED)
			rpdu->Union.rError.CauseCode.diagnostic = SM_EnumeratedDeliveryFailureCause_memoryCapacityExceeded;

		if(cc >= CC_MCEF && cc <= CC_NOT_SM_EQUIPPED)
			rpdu->Union.rError.CauseCode.diagnostic = cc - CC_MCEF;

		bzero((void *)&dfc, sizeof(SM_DeliveryFailureCause));
		dfc.sm_EnumeratedDeliveryFailureCause = rpdu->Union.rError.CauseCode.diagnostic;
		if(rpdu->Union.rError.CauseCode.diagnostic == CC_MCEF || rpdu->Union.rError.CauseCode.diagnostic == CC_RP_MEMORY_CAPACITY_EXCEEDED)
		{
			dfc.diagnosticInfo.length = (unsigned short)
				MakeDiagnosticInfo(dfc.diagnosticInfo.value, FCS_MEMORY_CAPACITY_EXCEEDED);
			if(dfc.diagnosticInfo.length > 0)
				dfc.bit_mask |= diagnosticInfo_present;
		}

		if(ossEncode(world, (pdu = SM_DeliveryFailureCause_PDU), (msg = &dfc), &param))
		{
			uaLog(L_CRT, "ossEncode error: %s", ossGetErrMsg(world));
			return IX_CONT;
		}
	}
	else if(cc == CC_FACILITY_NOT_SUPPORTED)
	{
		bzero((void *)&fns, sizeof(FacilityNotSupParam));

		if(ossEncode(world, (pdu = FacilityNotSupParam_PDU), (msg = &fns), &param))
		{
			uaLog(L_CRT, "ossEncode error: %s", ossGetErrMsg(world));
			return IX_CONT;
		}
	}
	else if(cc == CC_SYSTEM_FAILURE)
	{
		bzero((void *)&sf, sizeof(SystemFailureParam));
		sf.choice = networkResource_chosen;
		sf.u.networkResource = controllingMSC;

		if(ossEncode(world, (pdu = SystemFailureParam_PDU), (msg = &sf), &param))
		{
			uaLog(L_CRT, "ossEncode error: %s", ossGetErrMsg(world));
			return IX_CONT;
		}
	}
	else if(cc == CC_UNEXPECTED_DATA_VALUE)
	{
		bzero((void *)&ud, sizeof(UnexpectedDataParam));

		if(ossEncode(world, (pdu = UnexpectedDataParam_PDU), (msg = &ud), &param))
		{
			uaLog(L_CRT, "ossEncode error: %s", ossGetErrMsg(world));
			return IX_CONT;
		}
	} 
	else if(cc == CC_ILLEGAL_SUBSCRIBER) 
	{
		bzero((void *)&illegalSub, sizeof(IllegalSubscriberParam));

		if(ossEncode(world, (pdu = IllegalSubscriberParam_PDU), (msg = &illegalSub), &param))
		{
			uaLog(L_CRT, "ossEncode error: %s", ossGetErrMsg(world));
			return IX_CONT;
		}

	}
	else if(cc == CC_ABSENT_SUBSCRIBER_SM)
	{
		bzero((void *)&absentSub, sizeof(AbsentSubscriberSM_Param));
		absentSub.bit_mask |=
			AbsentSubscriberSM_Param_absentSubscriberDiagnosticSM_present;
		absentSub.absentSubscriberDiagnosticSM = rpdu->Union.rError.CauseCode.diagnostic;

		if(ossEncode(world, (pdu = AbsentSubscriberSM_Param_PDU), (msg = &absentSub), &param))
		{
			uaLog(L_CRT, "ossEncode error: %s", ossGetErrMsg(world));
			return IX_CONT;
		}
	} 
	else if(cc == CC_ABSENT_SUBSCRIBER)
	{
		bzero((void *)&absentSubParam, sizeof(AbsentSubscriberParam));

		absentSubParam.bit_mask |=
			absentSubscriberReason_present;
		absentSubParam.absentSubscriberReason= rpdu->Union.rError.CauseCode.diagnostic;


		if(ossEncode(world, (pdu = AbsentSubscriberParam_PDU), (msg = &absentSubParam), &param))
		{
			uaLog(L_CRT, "ossEncode error: %s", ossGetErrMsg(world));
			return IX_CONT;
		}
	} 
    else if(cc == CC_UNIDENTIFIED_SUBSCRIBER) 
    {
        bzero((void *)&uif, sizeof(UnidentifiedSubParam));

        if(ossEncode(world, pdu = UnidentifiedSubParam_PDU, msg = &uif, &param))
        {
            uaLog(L_CRT, "ossEncode error: %s", ossGetErrMsg(world));
            return IXERR;
        }
    } 
	else if(cc == CC_CALL_BARRED)
	{
		bzero((void *)&callBarred, sizeof(CallBarredParam));

		callBarred.choice |= callBarringCause_chosen;
		callBarred.u.callBarringCause = barringServiceActive;

		if(ossEncode(world, pdu = CallBarredParam_PDU, msg = &callBarred, &param))
		{
            uaLog(L_CRT, "ossEncode error: %s", ossGetErrMsg(world));
            return IXERR;
		}
	}
	/* added by dduckk, 20150803 
	   UDA 결과가 "5001 USER UNKNOWN" 일때, UNKNOWN_SUBSCRIBER 에러 처리
	 */
    else if(cc == CC_UNKNOWN_SUBSCRIBER) /* added by comus 2007/05/14 */
    {
        bzero((void *)&usp, sizeof(UnknownSubscriberParam));

        if(ossEncode(world, pdu = UnknownSubscriberParam_PDU, msg = &usp, &param))
        {
            uaLog(L_CRT, "ossEncode error: %s", ossGetErrMsg(world));
            return IXERR;
        }
    } 
	else if(cc > 0 && cc < 1000)
	{
		switch(cc)
		{
			case ATTEMPTING_TO_REACH_UE :
			case N1_N2_TRANSFER_INITIATED :
			case WAITING_FOR_ASYNCHRONOUS_TRANSFER :
			case UE_NOT_RESPONDING :
			case N1_MSG_NOT_TRANSFERRED :
				cc = CC_NPR3G_CS;
				break;
			case UE_NOT_REACHABLE_FOR_SESSION :
				cc = CC_DEREGISTED_NON_GPRS;
				break;
			case HTTP_ERROR_FORBIDDEN :
			case HTTP_ERROR_NOT_FOUND :
				cc = CC_NPR3G_CS;
				break;
			case HTTP_ERROR_NOT_ALLOWED :
				cc = CC_CALL_BARRED;
				break;
			case HTTP_ERROR_TEMPORARY_REDIRECT :
			case HTTP_ERROR_BAD_REQUEST :
			case HTTP_ERROR_NOT_IMPLEMENTED :
			case HTTP_ERROR_SERVICE_UNAVAIABLE :
			case HTTP_ERROR_GATEWAY_TIMEOUT :
			default :
				cc = CC_NPR3G_CS;
				break;
		}

		if(cc != CC_CALL_BARRED)
		{
			bzero((void *)&absentSub, sizeof(AbsentSubscriberSM_Param));
			diagnostic = cc - 3170;
			absentSub.bit_mask |=
				AbsentSubscriberSM_Param_absentSubscriberDiagnosticSM_present;
			absentSub.absentSubscriberDiagnosticSM = diagnostic;

			if(ossEncode(world, (pdu = AbsentSubscriberSM_Param_PDU), (msg = &absentSub), &param))
			{
				uaLog(L_CRT, "ossEncode error: %s", ossGetErrMsg(world));
				return IX_CONT;
			}
		}
	}
	else 
	{
		uaLog(L_MAJ, "Undefined encode error code [%d]", cc);

		bzero((void *)&sf, sizeof(SystemFailureParam));
		sf.choice = networkResource_chosen;
		sf.u.networkResource = plmn;

		if(ossEncode(world, (pdu = SystemFailureParam_PDU), (msg = &sf), &param))
		{
			uaLog(L_CRT, "ossEncode error: %s", ossGetErrMsg(world));
			return IX_CONT;
		}
	}

	cc -= 3000;
	ret = sig_sendEndErrorComplex( gTcapInfo, inRes->acn, inRes->prov_id, 
			inRes->inv_id, 0, cc, param.value, param.length);

	setTraceMode(NULL, NULL, &inRes->imsi);
	if(ret == 0)
	{
		if ( IS_IN_TRACE( 1)) {
			/*
			int acnLen;
			unsigned char acnStr[12];

			MakeACN( &acnLen, acnStr, inRes->acn);
			sig_minTraceTcapComplex(LPOS, &gTraceAddr, TCAP_SEND, 
				UTCAP_END, inRes->prov_id, 1, 
				acnStr, acnLen, 0,
				&inRes->srcAddr, &inRes->dstAddr,
				UTCAP_COMP_ERROR, cc, inRes->inv_id, 
				param.value, param.length);
			*/

			MinTraceMap(LPOS, &gTraceAddr, 0, 0,
				world, pdu, msg);


			MinTrace(LPOS, &gTraceAddr,
					"MTF Response(NACK - %d) : %s %4d %4d Sent", 
					cc, diag_id, inRes->prov_id, inRes->inv_id );
		}
	
		gMtfNackSendCnt++;
		uaLog(L_MAJ, "MTF Response(NACK - %d) : %s %4d %4d Sent", 
			cc, diag_id, inRes->prov_id, inRes->inv_id );
		return IX_CONT;
	}
	else
	{
		uaLog(L_MAJ, "MTF Response(NACK - %d) : %s %4d %4d sendEndErr fail(E=%d)", 
			cc, diag_id, inRes->prov_id, inRes->inv_id, ret );
		return IXERR;
	}

	return 0;
}


int handleMtResGsm(stMtResponseQ *inRes, char *diag_id)
{
	int ret, resultType;

	resultType = UTCAP_END;

	if(inRes->isMMS == MMS_TRUE) 
	{
		ret = sig_sendContinueResultComplex( gTcapInfo, inRes->acn, inRes->prov_id, 
				inRes->inv_id, MAP_OP_MtFwdSM, 0, 0);
		uaLog(L_MIN, "Send CONTINUE RESULT, IMSI[%s], %s-%4d-%4d", 
				inRes->imsi.min, diag_id, inRes->prov_id, inRes->inv_id);
		resultType = UTCAP_CONTINUE; 
	}
	else
		ret = sig_sendEndResultComplex( gTcapInfo, inRes->acn, inRes->prov_id, 
				inRes->inv_id, MAP_OP_MtFwdSM, 0, 0);

	setTraceMode(NULL, NULL, &inRes->imsi);

	if(ret == 0)
	{
		/*
		if ( IS_IN_TRACE( 1)) {
			int acnLen;
			unsigned char acnStr[12];

			MakeACN( &acnLen, acnStr, inRes->acn);

			sig_minTraceTcapComplex(LPOS, &gTraceAddr, TCAP_SEND, 
				resultType, inRes->prov_id, 1, 
				acnStr, acnLen, 0, &inRes->dstAddr, &inRes->srcAddr,
				UTCAP_COMP_RET_RES_L, MAP_OP_MoFwdSM, inRes->inv_id, 0, 0);
		}
		*/

		inc_mtf_send_ack(inRes->node.isdn);

		uaLog(L_INFO, "MTF_SM Response(ACK) : %s %4d %4d Sent", 
				diag_id, inRes->prov_id, inRes->inv_id );

		if ( IS_IN_TRACE( 1)) {
			MinTrace(LPOS, &gTraceAddr, 
					"MTF_SM Response(ACK-%s) : %s %4d %4d Sent", 
					resultType == UTCAP_CONTINUE ? "CONTINUE":"END",
					diag_id, inRes->prov_id, inRes->inv_id );
		}

		gMtfAckSendCnt++;
		return IX_CONT;
	}
	else
	{
		inc_mtf_resp_time(inRes->node.isdn);
		uaLog(L_MAJ, "MT NACK : %s %4d %4d sendResult Fail(E=%d)", 
				diag_id, inRes->prov_id, inRes->inv_id, ret );
		if ( IS_IN_TRACE( 1)) {
			MinTrace(LPOS, &gTraceAddr, "MTF_SM Response(Send Fail) : %s %4d %4d Send Fail", 
					diag_id, inRes->prov_id, inRes->inv_id );
		}

		gMtfNackSendCnt++;
		return IXERR;
	}

	return 0;
}            


int EncodeGsmErrorParam(int *pduNum, void **msg, int errcode,
        int resource, unsigned char acn, int dfc, int fcs,
        unsigned char *buf, int bufLen)
{
    static CallBarredParam          bar;
    static SystemFailureParam       sf;
    static SM_DeliveryFailureCause  sm_dfc;
 
    param.value = buf;
    param.length = bufLen;
 
    switch( errcode) {
        case CC_CALL_BARRED:
            bzero((void *)&bar, sizeof(CallBarredParam));
            bar.choice |= callBarringCause_present;
            bar.u.callBarringCause = operatorBarring;
 
            if(ossEncode(world, (*pduNum = CallBarredParam_PDU), (*msg = &bar), &param)) {
                printf("ossEncode error: %s\n", ossGetErrMsg(world));
                return IXERR;
            }
            break;
 
        case CC_SYSTEM_FAILURE:
            bzero((void *)&sf, sizeof(SystemFailureParam));
            sf.choice |= networkResource_chosen;
            sf.u.networkResource = resource;
 
            if(ossEncode(world, (*pduNum = SystemFailureParam_PDU), (*msg = &sf), &param)) {
                uaLog(L_CRT, "ossEncode error: %s", ossGetErrMsg(world));
                return IXERR;
            }
            break;
 
        case CC_SM_DELIVERY_FAILURE:
            bzero((void *)&sm_dfc, sizeof(SM_DeliveryFailureCause));
            sm_dfc.sm_EnumeratedDeliveryFailureCause = dfc;
       if( acn != ACN_MT_V1 &&         /* only version 2 or 3 */
                fcs != FCS_NO_ERROR) {
                sm_dfc.diagnosticInfo.length = (unsigned short)
                    MakeDiagnosticInfo(sm_dfc.diagnosticInfo.value, fcs);
                if(sm_dfc.diagnosticInfo.length > 0)
                    sm_dfc.bit_mask |= diagnosticInfo_present;
            }
 
            if(ossEncode(world, (*pduNum = SM_DeliveryFailureCause_PDU), (*msg = &sm_dfc), &param)) {
                uaLog(L_CRT, "ossEncode error: %s", ossGetErrMsg(world));
                return IXERR;
            }
            break;
 
        default:
            param.value = NULL;
            param.length = 0;
 
    }
    return IXOK;
}


/* EncodeGsmErrorParam
 * MO/SRI/ALERT/CMD에 대한 error return시에 parameter encoding 수행
 *
 * int      *pduNum         [OUT] PDU number
 * void     **msg           [OUT] Encoded Parameter
 * int      errcode         [IN]  Error Code 
 * int      resource        [IN]  System Failure Parameter encoding시 사용될 network resource (hlr / plmn)
 * unsigned char    acn     [IN]
 * int      dfc             [IN]  SM_DeliveryFailure Parameter encoding시 사용될 failure cause
 * int      fcs             [IN]  
 * unsigned char    *buf    [IN]  PDU를 encoding할 buffer   
 * int      bufLen          [IN]  buffer size
 */

int send_error3_timeout(stMtResponseQ *inRes)
{    
	int                 ret;
	unsigned char       encBuf[1024];
	int                 pdu;
	void                *msg;

	gMtfNackSendCnt++;

	/* encode parameters */
	if( EncodeGsmErrorParam(&pdu, &msg, CC_SYSTEM_FAILURE, plmn, inRes->acn, 0, 0,
				encBuf, sizeof(encBuf)) != IXOK) {
		return IXERR;
	}   

	ret = sig_sendEndErrorComplex( gTcapInfo, inRes->acn, inRes->prov_id,
			inRes->inv_id, 0, CC_SYSTEM_FAILURE-3000,
			param.value, param.length);
	gSendCnt++;

	if(ret == 0)
	{       
		setTraceMode(NULL, NULL, &inRes->imsi);
		if ( IS_IN_TRACE(1)) {
			int acnLen;
			unsigned char acnStr[12];

			/* error 전송, 발착신 주소 변경 */
			MakeACN( &acnLen, acnStr, inRes->acn);
			sig_minTraceTcapComplex(LPOS, &gTraceAddr, TCAP_SEND,
					UTCAP_END, inRes->prov_id, 1,
					acnStr, acnLen, 0,
					&inRes->dstAddr, &inRes->srcAddr,
					UTCAP_COMP_ERROR, 0, inRes->inv_id,
					param.value, param.length);

			MinTraceMap(LPOS, &gTraceAddr, 0, 0, world, pdu, msg);
		}

		gSendCnt++;
		/* CMD에 대해서는 따로 통계 쌓지 않는다. */
		uaLog(L_MIN, "Send Error due to Incoming Timeout, Diag %4d Sent", inRes->diag_id);
		return IXOK;
	}
	else
	{
		uaLog(L_CRT, "Send Error due to Incoming Timeout, sig_sendEndError failed diag_id[%d], ret[%d]",
				inRes->diag_id, ret);
		return IXERR;
	}
}
