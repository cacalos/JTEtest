#include <ainCommon.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/un.h>
#include <limits.h>
#include <malloc.h>
#include <strings.h>

#include "iXtypes.h"
#include "ua_log.h"
#include "ix7map.h"

#include <TCAP_ccitt.h>
#include <TCAP_errors.h>
#include <TCAP_ext.h>
#include "iXCauseCode.h"

#define MAX_FD                  127

extern  HP_DLL_IF int           tc_errno;


int build_componentSim(int CnxId, tc_component_type type, int inv_id, int link_id,
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
        printf("Error in TCX_alloc_component: %s\n",
            tc_error_text[tc_errno]);
        if(tc_errno == TCE_MEMORY_ERROR)
            return -2;
        else
            return -1;
    }

    /* allocate one param buffer of PARAM_BUFFER_SIZE octets */
    if(TCX_alloc_buffer(&param_ptr, PARAM_BUFFER_SIZE) == -1)
    {
        printf("Error in TCX_alloc_buffer: %s\n",
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

    PrintSS7_ComponentSim(comp_ptr);

    if((len = TCX_put_component(CnxId, user_id, prov_id, comp_ptr)) == -1)
    {
        printf("TCX_put_component(CnxId:%d, user_id:%d, prov_id:%d, comp_ptr)...\n",
            CnxId, user_id, prov_id);
        printf("Error in TCX_put_component: %s\n", tc_error_text[tc_errno]);

        /* This component cannot be chained in API */
        if(TCX_free_components(comp_ptr) == -1)
            printf("Error in TCX_free_components: %s\n",
                tc_error_text[tc_errno]);
        else
            printf("TCX_free_components SUCCESS\n");

        return -1;
    }

    return len;
}


int send_messageSim(int CnxId, tc_primitive_type p_type, tc_dialog_portion *dp, tc_address *dest_addr, tc_address *orig_addr, int uid, int pid)
{
    int send_err;
    tcx_primitive primitive;

    bzero((void *)&primitive, sizeof(tcx_primitive));

    primitive.p_type = p_type;
    primitive.service_quality.use_default_values = TC_YES;
/*
    primitive.service_quality.use_default_values = TC_NO;
    primitive.service_quality.sccp_return_option = TC_NO;
    primitive.service_quality.sccp_use_extended_data = TC_NO;
    primitive.service_quality.sccp_importance = TCX_IMPORTANCE_LOW;
    primitive.service_quality.sccp_sequence_control = 0;
*/

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

    PrintSS7_PrimitiveSim(&primitive);

    if(TCX_send(CnxId, NULL, &primitive, NULL) == -1)
    {
        printf("Error in TCX_send(): %d,%s\n",
            tc_errno, tc_error_text[tc_errno]);
        send_err = tc_errno;
        if(TCX_flush_components(CnxId, uid, pid) == -1)
            printf("Error in TCX_flush_component: %d,%s\n",
                tc_errno, tc_error_text[tc_errno]);
        inc_tc_err_cnt();
    }
    else
        send_err = 0;

    return send_err;
}

