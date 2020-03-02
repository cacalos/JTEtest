#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/un.h>
#include <limits.h>
#include <malloc.h>
#include <strings.h>

#include <iXtypes.h>
#include <ua_log.h>
#include <SS7/ix7map.h>

#include <iXCauseCode.h>
#include <errno.h>

#include <ua_log.h>
#include <ua_syslib.h>
#include <ua_macro.h>
#include <ua_sysdef.h>




#ifdef USIGTRAN
#include <sigtran_util.h>

#else
#include <ainCommon.h>
#include <TCAP_ccitt.h>
#include <TCAP_errors.h>
#include <TCAP_ext.h>
#define MAX_FD                  127
extern  HP_DLL_IF int           tc_errno;
extern  int errno;

#endif



int sleep_micro_sec(int m_sec)
{
    struct timeval     timeout;

    timeout.tv_sec = 0;
    timeout.tv_usec = m_sec;
    select(0, 0, 0, 0, &timeout);
    return IXOK;
}


#ifdef USIGTRAN

int getUErrorCode(UTcapComponents *comp_ptr, int *err_code)
{
	switch (comp_ptr->errorCode.string[0])
	{
		case 0x81 : *err_code = CC_UERROR_UNRECOG_MIN;
				break;
		case 0x82 : *err_code = CC_UERROR_UNRECOG_ESN;
				break;
		case 0x83 : *err_code = CC_UERROR_MIN_HLR_MISMATCH;
				break;
		case 0x84 : *err_code = CC_UERROR_OP_SEQ_PROBLEM;
				break;
		case 0x85 : *err_code = CC_UERROR_RESOURCE_SHORTAGE;
				break;
		case 0x86 : *err_code = CC_UERROR_OP_NOT_SUPPORTED;
				break;
		case 0x87 : *err_code = CC_UERROR_TRUNK_UNAVAIL;
				break;
		case 0x88 : *err_code = CC_UERROR_PARAM_ERROR;
				break;
		case 0x89 : *err_code = CC_UERROR_SYSTEM_FAILURE;
				break;
		case 0x8a : *err_code = CC_UERROR_UNREG_PARAM_VALUE;
				break;
		case 0x8b : *err_code = CC_UERROR_FEATURE_INACTIVE;
				break;
		case 0x8c : *err_code = CC_UERROR_MISSING_PARAM;
				break;
		default : *err_code = CC_UERROR_NO_PARAM;
				break;
	}

	return IXOK;
}

#else

int connection_handler(char *StackName, int ossn, tcx_sccp_service sccp_service,
                       TC_BOOL isActive, int ai, int ii)
{
    int                  cnxId;
    tcx_application_info AppliInfo;
    struct timeval       timeout;
    char *tmp;
    char *env;
    char hostname[3][32];

    gethostname( hostname[0], sizeof(hostname[0]));

    /* bhtak 2004/10/8
        Dual ACT mode에서는 HOST A, B에서 instance id가 달라야 한다.
        sys.conf에서 HOST1, HOST2의 host name을 읽어와서 현재 호스트 이름과
        비교하여 실행 중인 시스템이 A인지 B인지 확인한다.
        만약 B라면 instance id + 10을 한다.
    */
    GET_SYS_HOME_ENV(env);

    if ( (tmp = cfg_getSecConf( env, PROC_CONF_FILE, "[SYSTEM]", "HOST1")) == (char*)-1) {
        uaLog( L_CRT, "Configuration Name 'HOST1' not found");
        return -1;
    }
    strcpy( hostname[1], tmp);

    if ( (tmp = cfg_getSecConf( env, PROC_CONF_FILE, "[SYSTEM]", "HOST2")) == (char*)-1) {
        uaLog( L_CRT, "Configuration Name 'HOST2' not found");
        return -1;
    }
    strcpy( hostname[2], tmp);

    if ( strcmp( hostname[0], hostname[1]) == 0) {
        /* this is HOST 1 */
    }
    else if ( strcmp( hostname[0], hostname[2]) == 0) {
        /* this is HOST 2
            instance id에 10을 더한다.
        */
        ii += 10;
    }
    else {
        uaLog( L_CRT, "Invalid HOST name %s HOST1=%s HOST2=%s",
            hostname[0], hostname[1], hostname[2]);
        return -1;
    }



    AppliInfo.mode           = TCX_CNX_OVERWRITE;
    AppliInfo.application_id = ai;
    AppliInfo.instance_id    = ii;

    /* Set TCX_open timeout */
    timeout.tv_sec  = 3;
    timeout.tv_usec = 0;

    cnxId = TCX_open(StackName,      /* ClassName                    */
                     TCX_TCAP_STD,   /* not used                     */
                     ossn,           /* subSystem Number             */
                     TC_YES,         /* enable comp. layer           */
                     isActive,       /* accept new dialogue          */
                     &AppliInfo,     /* appli. Info                  */
                     sccp_service,   /* SCCP layer service           */
                     &timeout);      /* registration timeout         */

    if(cnxId == -1)
        uaLog(L_CRT, "Error during TCX_open,reason: %s, %d",
            tc_error_text[tc_errno], tc_errno);
    else
        uaLog(L_MAJ,
            "Connection to SS7 Stack opened with cnxid %d", cnxId);

    return cnxId;
}


int build_component(int CnxId, tc_component_type type, int inv_id, int link_id,
                    int user_id, int prov_id, tc_operation *operation,
                    time_t timeout, int param_length, char *param_datas,
                    tc_error *error)
{
    int                  len;
    tcx_component       *comp_ptr;
    tcx_buffer          *param_ptr;

    /* allocate one component */
    if(TCX_alloc_component(&comp_ptr, 1) == -1)
    {
        uaLog(L_CRT, "Error in TCX_alloc_component: %s",
            tc_error_text[tc_errno]);
        if(tc_errno == TCE_MEMORY_ERROR)
            return -2;
        else
            return -1;
    }

    /* allocate one param buffer of PARAM_BUFFER_SIZE octets */
    if(TCX_alloc_buffer(&param_ptr, PARAM_BUFFER_SIZE) == -1)
    {
        uaLog(L_CRT, "Error in TCX_alloc_buffer: %s",
            tc_error_text[tc_errno]);
        if(tc_errno == TCE_MEMORY_ERROR)
            return -2;
        else
            return -1;
    }

    bzero((void *)comp_ptr, sizeof(tcx_component));

    comp_ptr->c_type = type;
    comp_ptr->op_class = 1;

    comp_ptr->invoke_id = inv_id;
    comp_ptr->linked_id = link_id;
    memcpy(&comp_ptr->operation, operation, sizeof(tc_operation));

    comp_ptr->timer.tv_sec = timeout;
    comp_ptr->timer.tv_usec = 0;

    param_ptr->actual_length = param_length;
    memcpy(param_ptr->bufferp, param_datas, param_length);

    comp_ptr->parameter = param_ptr;

    if(error != NULL)
        memcpy(&comp_ptr->error, error, sizeof(tc_error));
    else
        bzero((void *)&comp_ptr->error, sizeof(tc_error));

    comp_ptr->next_component = NULL;

    PrintSS7_Component(comp_ptr);

    if((len = TCX_put_component(CnxId, user_id, prov_id, comp_ptr)) == -1)
    {
        uaLog(L_CRT,
            "TCX_put_component(CnxId:%d, user_id:%d, prov_id:%d, comp_ptr)...",
            CnxId, user_id, prov_id);
        uaLog(L_CRT, "Error in TCX_put_component: %s",
            tc_error_text[tc_errno]);

/*
        if(TCX_free_buffer(param_ptr) == -1)
            uaLog(L_CRT, "Error in TCX_free_buffer: %s",
                tc_error_text[tc_errno]);
*/

        /* This component cannot be chained in API */
        if(TCX_free_components(comp_ptr) == -1)
            uaLog(L_CRT, "Error in TCX_free_components: %s",
                tc_error_text[tc_errno]);
        else
            uaLog(L_MAJ, "TCX_free_components SUCCESS");

        return -1;
    }

/*
    if(TCX_free_buffer(param_ptr) == -1)
        uaLog(L_CRT, "Error in TCX_free_buffer: %s",
            tc_error_text[tc_errno]);
*/

    return len;
}



int getUErrorCode(tcx_component *comp_ptr, int *err_code)
{
	switch (comp_ptr->error.datas[0])
	{
		case 0x81 : *err_code = CC_UERROR_UNRECOG_MIN;
				break;
		case 0x82 : *err_code = CC_UERROR_UNRECOG_ESN;
				break;
		case 0x83 : *err_code = CC_UERROR_MIN_HLR_MISMATCH;
				break;
		case 0x84 : *err_code = CC_UERROR_OP_SEQ_PROBLEM;
				break;
		case 0x85 : *err_code = CC_UERROR_RESOURCE_SHORTAGE;
				break;
		case 0x86 : *err_code = CC_UERROR_OP_NOT_SUPPORTED;
				break;
		case 0x87 : *err_code = CC_UERROR_TRUNK_UNAVAIL;
				break;
		case 0x88 : *err_code = CC_UERROR_PARAM_ERROR;
				break;
		case 0x89 : *err_code = CC_UERROR_SYSTEM_FAILURE;
				break;
		case 0x8a : *err_code = CC_UERROR_UNREG_PARAM_VALUE;
				break;
		case 0x8b : *err_code = CC_UERROR_FEATURE_INACTIVE;
				break;
		case 0x8c : *err_code = CC_UERROR_MISSING_PARAM;
				break;
		default : *err_code = CC_UERROR_NO_PARAM;
				break;
	}

	return IXOK;
}

int send_message(int CnxId, tc_primitive_type p_type, tc_dialog_portion *dp,
                 tc_address *dest_addr, tc_address *orig_addr,
                 int uid, int pid)
{
    int                     send_err;
    tcx_primitive           primitive;

    bzero((void *)&primitive, sizeof(tcx_primitive));

    primitive.p_type = p_type;
    primitive.service_quality.use_default_values = TC_YES;

#ifdef TCAP_WHITE
    memcpy(&primitive.dialog_portion, dp, sizeof(tc_dialog_portion));
#endif

    /* Set destination address */
    memcpy(&primitive.d_address, dest_addr, sizeof(tc_address));

    /* Set originating address */
    memcpy(&primitive.o_address, orig_addr, sizeof(tc_address));

    /* Set dialog IDs */
    TC_P_USER_ID(&primitive)     = uid;
    TC_P_PROVIDER_ID(&primitive) = pid;

    PrintSS7_Primitive(&primitive);

    if(TCX_send(CnxId, NULL, &primitive, NULL) == -1)
    {
        uaLog(L_CRT, "Error in TCX_send(): %d,%s\n",
            tc_errno, tc_error_text[tc_errno]);
        send_err = tc_errno;
        if(TCX_flush_components(CnxId, uid, pid) == -1)
            uaLog(L_CRT, "Error in TCX_flush_component: %d,%s",
                tc_errno, tc_error_text[tc_errno]);
        inc_tc_err_cnt();
    }
    else
        send_err = 0;

    return send_err;
}


int exist_to_recv(int cnxId, int secs, int usecs)
{
    int             n, numFd, num_cnx, more, ret;
    int             cnxActive[MAX_FD];
    fd_set          readMask, writeMask, execMask;
    struct timeval  tmout, *time;
	tcx_primitive 	prim;

    FD_ZERO(&readMask);
    FD_ZERO(&writeMask);
    FD_ZERO(&execMask);

    tmout.tv_sec = secs;
    tmout.tv_usec = usecs;

    time = &tmout;

    numFd = TCX_select_mask(0, &readMask, &writeMask, &execMask, &time);

    /* 책에는 int인데 int로 하면 경고가 나오고 fd_set으로 하면 경고가 없다. */ 
    n = select(numFd, &readMask, &writeMask, &execMask, time);
	if ( n < 0 ) {
		switch( errno) {
		case EINTR :
			/* continue processing */
			break;
		default :
			uaLog( L_CRT, "select failed E=%d", errno);
			return IXERR;
		}
	}

    num_cnx = MAX_FD;
	cnxActive[0] = -1;
    TCX_cnx_handler(n, &readMask, &writeMask, &execMask, &num_cnx, cnxActive);

    if(num_cnx <= 0)
        return IXERR;

    if(cnxActive[0] != cnxId) {
		uaLog( L_CRT, "Invalid cnxId=%d active=%d,%d num_cnx=%d", 
			cnxId, cnxActive[0], cnxActive[1], num_cnx);
		/* read messages */
		while ( more > 0) {
			ret = TCX_recv( cnxActive[0], NULL, &prim, NULL, &more);
			if ( ret < 0) {
				uaLog( L_CRT, "TCX_recv failed E=%d", tc_errno);
			}
			else if (ret == 0) 
				break;
			uaLog(L_CRT, "RECVED %s", P_TypeToStr(prim.p_type));
		}

        return IXERR;
	}

    return IXOK;
}


int get_one_component(int CnxId, int user_id, int prov_id, int *inv_id,
                     tcx_component *component)
{
    int                 ret;
    tcx_component      *comp_ptr;

    if(prov_id == 0)
        return IXERR;

    ret = TCX_get_component(CnxId, user_id, prov_id, &comp_ptr);
	if (ret == 0)
		return NOTOK;
	else if (ret == -1)
	{
		uaLog(L_CRT, "Error in TCX_get_component: %s",
			tc_error_text[tc_errno]);
		return IXERR;
	}

    memcpy(component, comp_ptr, sizeof(tcx_component));

    if(TCX_free_components(comp_ptr) == -1)
    {
        uaLog(L_CRT, "Error in TCX_free_component: %s",
            tc_error_text[tc_errno]);
    }

    /* store invoke_id  */
    *inv_id = component->invoke_id;

    return IXOK;
}


int SendTCUAbort(int CnxId, int user_id, int prov_id)
{
    tcx_primitive     Primitive;

    /* TC Service parameter 세팅 */
    Primitive.p_type = TC_U_ABORT;
    Primitive.service_quality.use_default_values = TC_YES;

#ifdef TCAP_WHITE
    TC_P_DLG_INFO_PRESENT(&Primitive) = TC_NO;
#endif

    /* Destination Address 세팅 */
    TC_P_D_ADDR(&Primitive).type = NO_TC_ADDRESS;
    TC_P_O_ADDR(&Primitive).type = NO_TC_ADDRESS;

    TC_P_UABORT(&Primitive).length = 0;

    /* Dailogue Id 세팅 */
    TC_P_USER_ID(&Primitive) = user_id;
    TC_P_PROVIDER_ID(&Primitive) = prov_id;

    if(TCX_send(CnxId, NULL, &Primitive, NULL) == -1)
    {
        uaLog(L_MAJ,
            "SendTCUAbort() Fail: uid[%d] pid[%d] tc_err[%d]",
            user_id, prov_id, tc_errno);
        inc_tc_err_cnt();
    }
    else
        uaLog(L_MAJ, "SendTCUAbort() Succ: uid[%d] pid[%d]",
            user_id, prov_id);

    return IXOK;
}

#endif



/* end of addition */

