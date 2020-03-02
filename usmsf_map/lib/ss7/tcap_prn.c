
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
#include <SS7/status.h>

#ifdef USIGTRAN
#else
#include <ainCommon.h>
#include <TCAP_ccitt.h>
#include <TCAP_ext.h>
#include <TCAP_errors.h>
#endif

#define    NUM_SCCP_ST    5

char *prim_name[FLOW_CTRL_NUM_PRIM] = {
    "UNI", 
    "BEGIN",
    "CONTINUE",
    "END", 
    "U_ABORT",
    "P_ABORT", 
    "NOTICE", 
    "MGT",
    "SCCP_USER_STATUS",
    "SCCP_PC_STATUS", 
    "SCCP_N_COORD",
    "SCCP_N_COORD_RES",
    "NO_PRIMITIVE", 
    "SWITCH_STARTED",
    "SWITCH_DONE"
};

char *comp_name[FLOW_CTRL_NUM_COMP] = {
    "INVOKE", 
    "RESULT_L",
    "RESULT_NL",
    "U_ERROR",
    "L_CANCEL",
    "U_CANCEL", 
    "L_REJECT",
    "R_REJECT",
    "U_REJECT" 
};

char *sccp_st_name[NUM_SCCP_ST] = {
    "INACTIVE", 
    "CONGESTED", 
    "ACCESSIBLE", 
    "RESTARTING", 
    "UNCONGESTED"
};


#ifndef USIGTRAN
int prn_prim_name(int prim_type)
{
    if(prim_type < 0 || prim_type > FLOW_CTRL_NUM_PRIM - 1)
    {
        uaLog(L_MAJ, "Err : primitive type WRONG! -- %d",
            prim_type);
        return IXERR;
    }

    uaLog(L_MAJ, "primitive type= %2d, %s",
        prim_type, prim_name[prim_type]);
    return IXOK;
}


int get_prim_name(char *name, int prim_type)
{
    if(prim_type < 0 || prim_type > FLOW_CTRL_NUM_PRIM - 1)
    {
        *name = 0;
        return IXERR;
    }

    strcpy(name, prim_name[prim_type]);
    return IXOK;
}


int prn_comp_name(int comp_type)
{
    if(comp_type < 0 || comp_type > FLOW_CTRL_NUM_COMP - 1)
    {
        uaLog(L_MAJ, "Err : component type WRONG! -- %d",
            comp_type);
        return IXERR;
    }

    uaLog(L_MAJ, "component type= %2d, %s",
        comp_type, comp_name[comp_type]);
    return IXOK;
}


int get_comp_name(char *name, int comp_type)
{
    if(comp_type < 0 || comp_type > FLOW_CTRL_NUM_COMP - 1)
    {
        *name = 0;
        return IXERR;
    }

    strcpy(name, comp_name[comp_type]);
    return IXOK;
}
#endif

int    cong_cnt   = 0;
int    uncong_cnt = 0;

#ifndef USIGTRAN
int prn_sccp_user_st(tcx_primitive *prim)
{
	int pc = prim->tc_primitive_option.tc_ustatus.associatedPC; 
	int ssn = prim->tc_primitive_option.tc_ustatus.affectedSSN;
	int status = prim->tc_primitive_option.tc_ustatus.status;

    if( status == SCCP_UIS)
        uaLog(L_MAJ, "PC: %d, SSN: %d --> IN SERVICE", pc, ssn);
    else if( status == SCCP_UOS)
        uaLog(L_MAJ, "PC: %d, SSN: %d --> OUT OF SERVICE", pc, ssn);

    return IXOK;
}


int prn_sccp_st(tcx_primitive *prim)
{
    int    pc;
    int    sccp_status;

    sccp_status = prim->tc_primitive_option.tc_pcstatus.status;
    pc = prim->tc_primitive_option.tc_pcstatus.destConcerned;
    if(sccp_status < 0 || sccp_status > NUM_SCCP_ST - 1)
    {
        uaLog(L_MAJ, "SCCP PC Status (PC: %d) --> %d", 
            pc, sccp_status);
        return IXERR;
    }

    if(sccp_status == SCCP_CONGESTED)
        cong_cnt++;
    else if(sccp_status == SCCP_UNCONGESTED)
        uncong_cnt++;

    uaLog(L_MAJ, "PC: %d --> %s", pc, sccp_st_name[sccp_status]);
    return IXOK;
}


int prn_comp_vals(struct tc_component *comp, char *msg)
{
    if(comp == NULL)
        return IXERR;

    uaLog(L_MAJ,
        "%sComp=%2d %s, inv=%2d, link=%2d, op_t=%d, op=%d, timer=%d",
        msg, comp->c_type, comp_name[comp->c_type], comp->invoke_id,
        comp->linked_id, comp->operation.tag, comp->operation.datas[0],
        comp->timer.tv_sec);
    return IXOK;
}


int prn_prim_vals(tcx_primitive *prim, char *msg)
{
    int    p_type;
    int    p_id, u_id, inv_id;

    if(prim == NULL)
        return IXERR;

    p_type = TC_P_TYPE(prim);
    p_id   = TC_P_PROVIDER_ID(prim);
    u_id   = TC_P_USER_ID(prim);

    uaLog(L_MIN, "%sPrim:%2d, %s, p_id:%2d, u_id:%2d", 
        msg, p_type, prim_name[p_type], p_id, u_id);
    return IXOK;
}


int prn_prim_addrs(tcx_primitive *prim, char *msg)
{
    if(prim == NULL)
        return IXERR;

    uaLog(L_MIN, "%sFrom %4d, %2d --->  To %4d, %2d",
        msg, TC_P_O_ADDR(prim).pc_value, TC_P_O_ADDR(prim).ssn,
        TC_P_D_ADDR(prim).pc_value, TC_P_D_ADDR(prim).ssn);
    return IXOK;
}


int prn_paras(tcx_component *comp, char *msg)
{
    if(comp == NULL)
        return IXERR;
    uaLog(L_MIN, "msg: %s", msg);
    prn_str_hex(comp->parameter->bufferp, comp->parameter->actual_length);
    return IXOK;
}

#endif



int prim_count[FLOW_CTRL_NUM_PRIM];
int comp_count[FLOW_CTRL_NUM_COMP];

int init_prim_cnt()
{
    int    i;

    for(i = 0; i < FLOW_CTRL_NUM_PRIM; i++)
        prim_count[i] = 0;    
    return IXOK;
}


int init_comp_cnt()
{
    int    i;

    for(i = 0; i < FLOW_CTRL_NUM_COMP; i++)
        comp_count[i] = 0;
    return IXOK;
}


int inc_prim_cnt(int prim)
{
    if(prim < 0 || prim > FLOW_CTRL_NUM_PRIM - 1)
        return IXERR;
    prim_count[prim]++;
    return IXOK;
}


int prn_prim_cnt()
{
    int    i;

    uaLog(L_CRT, "---- Prim statistics");
    uaLog(L_CRT,
        "\n\t\t=== Congest : %d times\n\t\t=== Uncongest : %d times",
        cong_cnt, uncong_cnt);
    for(i = 0; i < FLOW_CTRL_NUM_PRIM; i++)
    {
        if(prim_count[i])
            uaLog(L_CRT, "prim %20s\t-- %3d",
                prim_name[i], prim_count[i]);
    }
    uaLog(L_CRT, "---- End of Prim statistics\n");
    return IXOK;
}


int inc_comp_cnt(int comp)
{
    if(comp < 0 || comp > FLOW_CTRL_NUM_COMP - 1)
        return IXERR;
    comp_count[comp]++;
    return IXOK;
}


int prn_comp_cnt()
{
    int    i;

    uaLog(L_CRT, "---- Comp statistics");
    for(i = 0; i < FLOW_CTRL_NUM_COMP; i++)
    {
        if(comp_count[i])
            uaLog(L_CRT, "comp %20s\t-- %3d",
                comp_name[i], comp_count[i]);
    }
    uaLog(L_CRT, "---- End of Comp statistics\n");
    return IXOK;
}


char *notice_reason[8] = {
    "TC_NOTRANSLATION_NATURE",
    "TC_NOTRANSLATION_SPECIFIC",
    "TC_SUBSYSTEM_CONGESTION",
    "TC_SUBSYSTEM_FAILURE",
    "TC_UNEQUIPPED_USER",
    "TC_NETWORK_FAILURE",
    "TC_NETWORK_CONGESTION",
    "TC_UNQUALIFIED"
};

char *abort_reason[7] = { 
    "TC_UNRECOG_MSG_TYPE",
    "TC_UNRECOG_TRANSACTION_ID",
    "TC_BAD_FMT_TRANS_PORTION",
    "TC_INCORRECT_TRANS_PORTION",
    "TC_RESOURCE_LIMITATION ",
    "TC_ABNORMAL_DIALOGUE",
    "TC_NO_COMMON_DIALOGUE_PORTION"
};


#ifndef USIGTRAN
int prn_other_prim(tcx_primitive *prim)
{
    int    p_type;
    int    cause;
    char  *unknown = "Unknown", *desc;

    if(prim == NULL)
        return IXOK;

    p_type = TC_P_TYPE(prim);
    switch (p_type)
    {
        case TC_P_ABORT:
            cause = prim->tc_primitive_option.p_abort_cause;
            if(cause >=0 && cause < 7)
                desc = abort_reason[cause];
            else
                desc = unknown;
            uaLog(L_CRT, "recv TC_P_ABORT: cause=[%d], %s",
                cause, desc);
            break;

        case TC_U_ABORT:
            uaLog(L_CRT, "recv TC_U_ABORT: cause=%s",
                prim->tc_primitive_option.u_abort_cause.datas); 
            break;

        case TC_NOTICE:
            cause = prim->tc_primitive_option.report_cause;
            if(cause >=0 && cause < 8)
                desc = notice_reason[cause];
            else
                desc = unknown;
            uaLog(L_CRT, "recv TC_NOTICE: cause=[%d], %s",
                cause, desc);
            break;
    }
    return IXOK;
}


/* refer "TCAP_errors.h" for error code 
DIR: /opt/HP-AIN/SS7_WBB/include
*/

int tc_err_cnt[FLOW_CTRL_NUM_TC_ERR_CNT];

int init_tc_err_cnt()
{
    memset(tc_err_cnt, 0, sizeof(int) * FLOW_CTRL_NUM_TC_ERR_CNT);
    return IXOK;
}


int inc_tc_err_cnt()
{
    if(tc_errno < 0 || tc_errno > FLOW_CTRL_NUM_TC_ERR_CNT - 1)
        return IXERR;

    tc_err_cnt[tc_errno]++;
    return IXOK;
}


int prn_tc_err_cnt()
{
    int    i;

    uaLog(L_MAJ, "---- TC error statistics");
    for(i = 0; i < FLOW_CTRL_NUM_TC_ERR_CNT; i++)
    {
        if(tc_err_cnt[i])
            uaLog(L_MAJ, "TC errno [%d]: %d times, %s", 
                i, tc_err_cnt[i], tc_error_text[i]);
    }
    uaLog(L_MAJ, "---- End of TC error statistics\n");
    return IXOK;
}
#endif

