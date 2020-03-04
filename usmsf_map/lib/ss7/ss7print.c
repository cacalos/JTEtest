
#include <iXtypes.h>
#include <ua_log.h>


#ifndef USIGTRAN
#include <TCAP_ccitt.h>
#include <TCAP_errors.h>
#include <TCAP_ext.h>
#endif


int PrintHexStr(int len, unsigned char *s, int mod)
{
    int             i;
    char            buf[1024], *ptr = buf;

    if(len < 1 || s == NULL)
        return IXERR;

    if(len > 256)
        len = 256;

    for(i = 0; i < len; i++)
    {
        if(i % 5 == 0)
            sprintf(ptr, "\t%02X", s[i]);
        else
            sprintf(ptr, " %02X", s[i]);
        ptr += strlen(ptr);
        *ptr = 0;
        if(i % 15 == 14)
        {
            uaLog( L_INFO, "%s", buf);
            ptr = buf;
        }
    }

    if(i % 15 != 0)
        uaLog( L_INFO, "%s", buf);

    return IXOK;
}


#ifndef USIGTRAN
#define TC_BOOL_STR(a)	(a==TC_YES)?"TC_YES":"TC_NO"

int PrintSS7_Primitive(tcx_primitive *primitive)
{
    int             i;
    int             gtLen;
    char            buf[1024];
    char            str[64];

    uaLog(L_INFO, "--- Primitive %s ---", P_TypeToStr(primitive->p_type));


	if ( primitive->p_type >= TC_UNI && primitive->p_type <= TC_NOTICE ) {
		if(primitive->service_quality.use_default_values == TC_NO)
		{
			uaLog(L_INFO,
				"sccp_option : return=%s ext_data=%s class=%d importance=%d,%s seq_ctrl=%d",
				TC_BOOL_STR(primitive->service_quality.sccp_return_option),
				TC_BOOL_STR(primitive->service_quality.sccp_use_extended_data),
				primitive->service_quality.sccp_service_class,
				primitive->service_quality.sccp_use_extended_data,
				primitive->service_quality.sccp_use_extended_data == 0 ?
					"TCX_IMPORTANCE_LOW" :
				primitive->service_quality.sccp_use_extended_data == 1 ?
					"TCX_IMPORTANCE_MEDIUN" :
				primitive->service_quality.sccp_use_extended_data == 2 ?
					"TCX_IMPORTANCE_HIGH" :
					"UNKNOWN",
				primitive->service_quality.sccp_sequence_control);
		}

		getAddrStr( buf, &primitive->o_address);
		uaLog( L_INFO, "orig addr : %s", buf);

		getAddrStr( buf, &primitive->d_address);
		uaLog( L_INFO, "dest addr : %s", buf);

		uaLog(L_INFO, "user_dialogue_id=%d provider_dialogue_id=%d",
			primitive->user_dialogue_id,
			primitive->provider_dialogue_id);

#ifdef TCAP_WHITE
		if(primitive->dialog_portion.dlg_info_present == TC_YES)
		{
			buf[0] = 0;
			if(primitive->dialog_portion.application_context_name.length > 0)
			{
				hex2str( primitive->dialog_portion.application_context_name.data, 
					primitive->dialog_portion.application_context_name.length,
					buf, sizeof(buf));
			}
			uaLog(L_INFO, "app context : len=%d '%s'H",
				primitive->dialog_portion.application_context_name.length, buf);

			buf[0] = 0;
			if(primitive->dialog_portion.user_information.length > 0)
			{
				hex2str( primitive->dialog_portion.user_information.data, 
					primitive->dialog_portion.user_information.length,
					buf, sizeof(buf));
			}
			uaLog(L_INFO, "user info : len=%d '%s'H",
				primitive->dialog_portion.user_information.length, buf);
		}

		if((primitive->p_type == TC_U_ABORT || primitive->p_type == TC_P_ABORT) &&
			primitive->dialog_portion.dlg_info_present == TC_YES)
		{
			uaLog(L_INFO, "dialog_portion.abort_reason : \"%s\"",
				primitive->dialog_portion.abort_reason == AC_name_not_supported ?
					"AC_name_not_supported" :
				primitive->dialog_portion.abort_reason == user_specific ?
					"user_specific" :
					"unknown");
		}
		else
			uaLog(L_INFO, "dialog_portion.abort_reason : NONE");
	}
#endif

    if(primitive->p_type == TC_P_ABORT)
    {
        uaLog(L_INFO, "tc_primitive_option.p_abort_cause : [%d: %s]",
            primitive->tc_primitive_option.p_abort_cause,
            PAbortCauseToStr(primitive->tc_primitive_option.p_abort_cause));
    }
    else if(primitive->p_type == SCCP_USER_STATUS)
    {
        uaLog( L_INFO, "tc_ustatus.status : %s",
			(primitive->tc_primitive_option.tc_ustatus.status == SCCP_UIS) ?
            "SCCP_UIS   IN_SERVICE": "SCCP_UOS   OUT_OF_SERVICE");

        uaLog( L_INFO, "tc_ustatus.associatedPC = %d",
            primitive->tc_primitive_option.tc_ustatus.associatedPC);

        uaLog( L_INFO, "tc_ustatus.affectedSSN = %d",
            primitive->tc_primitive_option.tc_ustatus.affectedSSN);
    }
    else if(primitive->p_type == SCCP_PC_STATUS)
    {
        uaLog( L_INFO, "tc_pcstatus.status = %s",
           PStatusToStr(primitive->tc_primitive_option.tc_pcstatus.status));
        uaLog( L_INFO, "tc_pcstatus.destConcerned = %d",
            primitive->tc_primitive_option.tc_pcstatus.destConcerned);
    }

    return IXOK;
}


int PrintSS7_Component(tcx_component  *comp_ptr)
{
    uaLog(L_INFO, "--- Component %s ---", C_TypeToStr(comp_ptr->c_type));
    uaLog(L_INFO, "class=%d inv_id=%d linked_id=%d",
        comp_ptr->op_class, comp_ptr->invoke_id, comp_ptr->linked_id);

    if(comp_ptr->c_type == TC_INVOKE || comp_ptr->c_type == TC_RESULT_L ||
       comp_ptr->c_type == TC_RESULT_NL)
    {
        uaLog(L_INFO, "operation tag=%s(%d) len=%d code=%d(H'%x)", 
            OperationTagToStr(comp_ptr->operation.tag),
            comp_ptr->operation.tag,
            comp_ptr->operation.length,
            comp_ptr->operation.datas[0],
            comp_ptr->operation.datas[0]);
    }

    if(comp_ptr->c_type != TC_L_REJECT)
        uaLog(L_INFO, "timer : [sec:%d, usec:%d]",
            comp_ptr->timer.tv_sec, comp_ptr->timer.tv_usec);

    uaLog(L_INFO, "para len=%d", comp_ptr->parameter->actual_length);

    if(comp_ptr->parameter->actual_length > 0)
    {
        PrintHexStr(comp_ptr->parameter->actual_length,
            (unsigned char *)comp_ptr->parameter->bufferp, 0);
    }

    if(comp_ptr->c_type == TC_U_ERROR)
    {
        uaLog(L_INFO, "error.tag %s(%d)  len=%d",
            ErrorTagToStr(comp_ptr->error.tag), comp_ptr->error.tag,
            comp_ptr->error.length);

        if(comp_ptr->error.length > 0)
        {
            PrintHexStr(comp_ptr->error.length, comp_ptr->error.datas, 0);
        }
    }

    if(comp_ptr->c_type == TC_U_REJECT || comp_ptr->c_type == TC_L_REJECT ||
       comp_ptr->c_type == TC_R_REJECT || comp_ptr->c_type == TC_U_ABORT ||
       comp_ptr->c_type == TC_P_ABORT)
    {
        uaLog(L_INFO, "problem_code : [%d: %d(%s)]",
            comp_ptr->problem_code.identifier,
            comp_ptr->problem_code.code,
            PBCodeToStr(comp_ptr->problem_code.code));
    }

    if(comp_ptr->next_component == NULL)
        uaLog(L_INFO, "comp_ptr->next_component : NULL");
    else
        uaLog(L_INFO, "comp_ptr->next_component : Continue");

    return IXOK;
}


int PrintSS7(tcx_primitive *primitive, tcx_component *comp_ptr)
{
    PrintSS7_Primitive(primitive);
    PrintSS7_Component(comp_ptr);
    return IXOK;
}
#endif

