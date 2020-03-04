
#include <iXtypes.h>
#include <ua_log.h>

#include <TCAP_ccitt.h>
#include <TCAP_errors.h>
#include <TCAP_ext.h>


int PrintHexStrSim(int len, unsigned char *s, int mod)
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
            printf("%s", buf);
            ptr = buf;
        }
    }

    if(i % 15 != 0)
        printf("%s\n", buf);

    return IXOK;
}


int PrintSS7_PrimitiveSim(tcx_primitive *primitive)
{
    int             i;
    int             gtLen;
    char            buf[1024];
    char            str[64];

    printf( "\t---------- Primitive ------------\n");
    printf(
        "\tprimitive->p_type : [%s]\n", P_TypeToStr(primitive->p_type));

    printf(
        "\tprimitive->service_quality.use_default_values : [%s]\n",
        primitive->service_quality.use_default_values == TC_YES ? "TC_YES"
                                                                : "TC_NO");
    if(primitive->service_quality.use_default_values == TC_NO)
    {
        printf(
            "\tprimitive->service_quality.sccp_return_option : [%s]\n",
            primitive->service_quality.sccp_return_option == TC_YES ?
            "TC_YES" : "TC_NO");
        printf(
            "\tprimitive->service_quality.sccp_use_extended_data : [%s]\n",
            primitive->service_quality.sccp_use_extended_data == TC_YES ?
            "TC_YES" : "TC_NO");
        printf(
            "\tprimitive->service_quality.sccp_service_class : [%d]\n",
            primitive->service_quality.sccp_service_class);
        printf(
            "\tprimitive->service_quality.sccp_importance : [%d, %s]\n",
            primitive->service_quality.sccp_use_extended_data,
            primitive->service_quality.sccp_use_extended_data == 0 ?
                "TCX_IMPORTANCE_LOW" :
            primitive->service_quality.sccp_use_extended_data == 1 ?
                "TCX_IMPORTANCE_MEDIUN" :
            primitive->service_quality.sccp_use_extended_data == 2 ?
                "TCX_IMPORTANCE_HIGH" :
                "UNKNOWN");
        printf(
            "\tprimitive->service_quality.sccp_sequence_control : [%d]\n",
            primitive->service_quality.sccp_sequence_control);
    }

    printf( "\tprimitive->d_address.type : [%s]\n",
        AddressTypeToStr(primitive->d_address.type));

    gtLen = 0;
    switch(primitive->d_address.type)
    {
        case GT :
            printf(
                "\tprimitive->d_address.gt.routeOnGt : %s\n",
                primitive->d_address.gt.routeOnGt == TC_YES ? "YES" : "NO");
            printf(
                "\tprimitive->d_address.gt.gtIndicator : %d\n",
                primitive->d_address.gt.gtIndicator);
            printf(
                "\tprimitive->d_address.gt.translation : %d\n",
                primitive->d_address.gt.translation);
            printf(
                "\tprimitive->d_address.gt.numbering : %d\n",
                primitive->d_address.gt.numbering);
            printf(
                "\tprimitive->d_address.gt.encoding : %d\n",
                primitive->d_address.gt.encoding);
            printf(
                "\tprimitive->d_address.gt.nature : %d\n",
                primitive->d_address.gt.nature);
            printf( "\tprimitive->d_address.gt.digit : %s\n",
                primitive->d_address.gt.digit);
            break;
        case GT_SSN :
            printf(
                "\tprimitive->d_address.gt.routeOnGt : %s\n",
                primitive->d_address.gt.routeOnGt == TC_YES ? "YES" : "NO");
            printf(
                "\tprimitive->d_address.gt.gtIndicator : %d\n",
                primitive->d_address.gt.gtIndicator);
            printf(
                "\tprimitive->d_address.gt.translation : %d\n",
                primitive->d_address.gt.translation);
            printf(
                "\tprimitive->d_address.gt.numbering : %d\n",
                primitive->d_address.gt.numbering);
            printf(
                "\tprimitive->d_address.gt.encoding : %d\n",
                primitive->d_address.gt.encoding);
            printf(
                "\tprimitive->d_address.gt.nature : %d\n",
                primitive->d_address.gt.nature);
            printf( "\tprimitive->d_address.gt.digit : %s\n",
                primitive->d_address.gt.digit);
            printf( "\tprimitive->d_address.ssn : [%d]\n",
                primitive->d_address.ssn);
            break;
        case GT_DPC_SSN :
            printf(
                "\tprimitive->d_address.gt.routeOnGt : %s\n",
                primitive->d_address.gt.routeOnGt == TC_YES ? "YES" : "NO");
            printf(
                "\tprimitive->d_address.gt.gtIndicator : %d\n",
                primitive->d_address.gt.gtIndicator);
            printf(
                "\tprimitive->d_address.gt.translation : %d\n",
                primitive->d_address.gt.translation);
            printf(
                "\tprimitive->d_address.gt.numbering : %d\n",
                primitive->d_address.gt.numbering);
            printf(
                "\tprimitive->d_address.gt.encoding : %d\n",
                primitive->d_address.gt.encoding);
            printf(
                "\tprimitive->d_address.gt.nature : %d\n",
                primitive->d_address.gt.nature);
            printf( "\tprimitive->d_address.gt.digit : %s\n",
                primitive->d_address.gt.digit);
           printf( "\tprimitive->d_address.pc_value : [%d]\n",
                primitive->d_address.pc_value);
            printf( "\tprimitive->d_address.ssn : [%d]\n",
                primitive->d_address.ssn);
            break;
        case DPC :
            printf(
                "\tprimitive->d_address.pc_value : [%d]\n",
                primitive->d_address.pc_value);
            break;
        case DPC_SSN :
            printf(
                "\tprimitive->d_address.pc_value : [%d]\n",
                primitive->d_address.pc_value);
            printf( "\tprimitive->d_address.ssn : [%d]\n",
                primitive->d_address.ssn);
            break;
        default :
            printf( "\tDest Addr Type : %d\n",
                primitive->d_address.type);
            break;
    }

    printf( "\tprimitive->o_address.type : [%s]\n",
        AddressTypeToStr(primitive->o_address.type));
    gtLen = 0;
    switch(primitive->o_address.type)
    {
        case GT :
            printf(
                "\tprimitive->o_address.gt.routeOnGt : %s\n",
                primitive->o_address.gt.routeOnGt == TC_YES ? "YES" : "NO");
            printf(
                "\tprimitive->o_address.gt.gtIndicator : %d\n",
                primitive->o_address.gt.gtIndicator);
            printf(
                "\tprimitive->o_address.gt.translation : %d\n",
                primitive->o_address.gt.translation);
            printf(
                "\tprimitive->o_address.gt.numbering : %d\n",
                primitive->o_address.gt.numbering);
            printf(
                "\tprimitive->o_address.gt.encoding : %d\n",
                primitive->o_address.gt.encoding);
            printf(
                "\tprimitive->o_address.gt.nature : %d\n",
                primitive->o_address.gt.nature);
            printf( "\tprimitive->o_address.gt.digit : %s\n",
                primitive->o_address.gt.digit);
            break;
        case GT_SSN :
            printf(
                "\tprimitive->o_address.gt.routeOnGt : %s\n",
                primitive->o_address.gt.routeOnGt == TC_YES ? "YES" : "NO");
            printf(
                "\tprimitive->o_address.gt.gtIndicator : %d\n",
                primitive->o_address.gt.gtIndicator);
            printf(
                "\tprimitive->o_address.gt.translation : %d\n",
                primitive->o_address.gt.translation);
            printf(
                "\tprimitive->o_address.gt.numbering : %d\n",
                primitive->o_address.gt.numbering);
            printf(
                "\tprimitive->o_address.gt.encoding : %d\n",
                primitive->o_address.gt.encoding);
            printf(
                "\tprimitive->o_address.gt.nature : %d\n",
                primitive->o_address.gt.nature);
            printf( "\tprimitive->o_address.ssn : [%d]\n",
                primitive->o_address.ssn);
            printf( "\tprimitive->o_address.gt.digit : %s\n",
                primitive->o_address.gt.digit);
            printf( "\tprimitive->o_address.ssn : [%d]\n",
                primitive->d_address.ssn);
            break;
        case GT_DPC_SSN :
            printf(
                "\tprimitive->o_address.gt.routeOnGt : %s\n",
                primitive->o_address.gt.routeOnGt == TC_YES ? "YES" : "NO");
            printf(
                "\tprimitive->o_address.gt.gtIndicator : %d\n",
                primitive->o_address.gt.gtIndicator);
            printf(
                "\tprimitive->o_address.gt.translation : %d\n",
                primitive->o_address.gt.translation);
            printf(
                "\tprimitive->o_address.gt.numbering : %d\n",
                primitive->o_address.gt.numbering);
            printf(
                "\tprimitive->o_address.gt.encoding : %d\n",
                primitive->o_address.gt.encoding);
            printf(
                "\tprimitive->o_address.gt.nature : %d\n",
                primitive->o_address.gt.nature);
            printf( "\tprimitive->o_address.ssn : [%d]\n",
                primitive->o_address.ssn);
            printf( "\tprimitive->o_address.gt.digit : %s\n",
                primitive->o_address.gt.digit);
           printf( "\tprimitive->o_address.pc_value : [%d]\n",
                primitive->d_address.pc_value);
            printf( "\tprimitive->o_address.ssn : [%d]\n",
                primitive->d_address.ssn);
            break;
        case DPC :
            printf(
                "\tprimitive->o_address.pc_value : [%d]\n",
                primitive->o_address.pc_value);
            break;
        case DPC_SSN :
            printf(
                "\tprimitive->o_address.pc_value : [%d]\n",
                primitive->o_address.pc_value);
            printf( "\tprimitive->o_address.ssn : [%d]\n",
                primitive->o_address.ssn);
            break;
        default :
            printf( "\tOrig Addr Type : %d\n",
                primitive->o_address.type);
            break;
    }

    printf( "\tprimitive->user_dialogue_id : [%d]\n",
        primitive->user_dialogue_id);
    printf( "\tprimitive->provider_dialogue_id : [%d]\n",
        primitive->provider_dialogue_id);

#ifdef TCAP_WHITE
    printf(
        "\tprimitive->dialog_portion.dlg_info_present : [%d]\n",
        primitive->dialog_portion.dlg_info_present);
    if(primitive->dialog_portion.dlg_info_present == TC_YES)
    {
        printf(
         "\tprimitive->dialog_portion.application_context_name.length : [%d]\n",
            primitive->dialog_portion.application_context_name.length);
        if(primitive->dialog_portion.application_context_name.length > 0)
        {
            printf(
               "\tprimitive->dialog_portion.application_context_name.data :\n");
          PrintHexStrSim(primitive->dialog_portion.application_context_name.length,
                (unsigned char *)
                primitive->dialog_portion.application_context_name.data,
                0);
        }
        printf(
            "\tprimitive->dialog_portion.user_information.length : [%d]\n",
            primitive->dialog_portion.user_information.length);
        if(primitive->dialog_portion.user_information.length > 0)
        {
            printf(
                "\tprimitive->dialog_portion.user_information.data :\n");
            PrintHexStrSim(primitive->dialog_portion.user_information.length,
               (unsigned char *)primitive->dialog_portion.user_information.data,
                0);
        }
    }

    if((primitive->p_type == TC_U_ABORT || primitive->p_type == TC_P_ABORT) &&
        primitive->dialog_portion.dlg_info_present == TC_YES)
    {
        printf(
            "\tprimitive->dialog_portion.abort_reason : \"%s\"\n",
            primitive->dialog_portion.abort_reason == AC_name_not_supported ?
                "AC_name_not_supported" :
            primitive->dialog_portion.abort_reason == user_specific ?
                "user_specific" :
                "unknown");
    }
    else
        printf(
            "\tprimitive->dialog_portion.abort_reason : NONE\n");
#endif

    if(primitive->p_type == TC_P_ABORT)
    {
        printf(
            "\tprimitive->tc_primitive_option.p_abort_cause : [%d: %s]\n",
            primitive->tc_primitive_option.p_abort_cause,
            PAbortCauseToStr(primitive->tc_primitive_option.p_abort_cause));
    }
    else if(primitive->p_type == SCCP_USER_STATUS)
    {
        strcpy(buf, "\tprimitive->tc_primitive_option.tc_ustatus.status");
        if(primitive->tc_primitive_option.tc_ustatus.status == SCCP_UIS)
            sprintf(str, " : [%s, %s]", "SCCP_UIS", "IN_SERVICE");
        else
            sprintf(str, " : [%s, %s]", "SCCP_UOS", "OUTOF_SERVICE");
        strcat(buf, str);
        printf( "%s\n", buf);

        strcpy(buf,
            "\tprimitive->tc_primitive_option.tc_ustatus.associatedPC");
        sprintf(str, " : [%d]",
            primitive->tc_primitive_option.tc_ustatus.associatedPC);
        strcat(buf, str);
        printf( "%s\n", buf);

        strcpy(buf,
            "\tprimitive->tc_primitive_option.tc_ustatus.affectedSSN");
        sprintf(str, " : [%d]\n",
            primitive->tc_primitive_option.tc_ustatus.affectedSSN);
        strcat(buf, str);
        printf( "%s\n", buf);
    }
    else if(primitive->p_type == SCCP_PC_STATUS)
    {
        strcpy(buf, "\tprimitive->tc_primitive_option.tc_pcstatus.status");
        sprintf(str, " : [%s]\n",
           PStatusToStr(primitive->tc_primitive_option.tc_pcstatus.status));
        strcat(buf, str);
        printf( "%s\n", buf);

        strcpy(buf,
            "\tprimtive->tc_primitive_option.tc_pcstatus.destConcerned");
        sprintf(str, " : [%d]\n",
            primitive->tc_primitive_option.tc_pcstatus.destConcerned);
        strcat(buf, str);
        printf( "%s\n", buf);
    }

    printf( "\t------------------------------\n");

    return IXOK;
}


int PrintSS7_ComponentSim(tcx_component  *comp_ptr)
{
    printf( "\t---------- Component ------------\n");
    printf( "\tcomp_ptr->c_type : [%s]\n",
        C_TypeToStr(comp_ptr->c_type));
    printf( "\tcomp_ptr->op_class : [%d]\n",
        comp_ptr->op_class);
    printf( "\tcomp_ptr->invoke_id : [%d]\n",
        comp_ptr->invoke_id);
    printf( "\tcomp_ptr->linked_id : [%d]\n",
        comp_ptr->linked_id);

    if(comp_ptr->c_type == TC_INVOKE || comp_ptr->c_type == TC_RESULT_L ||
       comp_ptr->c_type == TC_RESULT_NL)
    {
        printf( "\tcomp_ptr->operation.tag : [%s : %d]\n",
            OperationTagToStr(comp_ptr->operation.tag),
            comp_ptr->operation.tag);
        printf( "\tcomp_ptr->operation.length : [%d]\n",
            comp_ptr->operation.length);
        printf( "\tcomp_ptr->operation.datas[0] : [%d]\n",
            comp_ptr->operation.datas[0]);
    }

    if(comp_ptr->c_type != TC_L_REJECT)
        printf( "\tcomp_ptr->timer : [sec:%d, usec:%d]\n",
            comp_ptr->timer.tv_sec, comp_ptr->timer.tv_usec);

    printf( "\tcomp_ptr->parameter.length : [%d]\n",
        comp_ptr->parameter->actual_length);
    if(comp_ptr->parameter->actual_length > 0)
    {
        printf( "\tcomp_ptr->parameter.datas :\n");
        PrintHexStrSim(comp_ptr->parameter->actual_length,
            (unsigned char *)comp_ptr->parameter->bufferp, 0);
    }

    if(comp_ptr->c_type == TC_U_ERROR)
    {
        printf( "\tcomp_ptr->error.tag : [%s : %d]\n",
            ErrorTagToStr(comp_ptr->error.tag), comp_ptr->error.tag);
        printf( "\tcomp_ptr->error.length : [%d]\n",
            comp_ptr->error.length);
        if(comp_ptr->error.length > 0)
        {
            printf( "\tcomp_ptr->error.datas :\n");
            PrintHexStrSim(comp_ptr->error.length, comp_ptr->error.datas,
                0);
        }
    }

    if(comp_ptr->c_type == TC_U_REJECT || comp_ptr->c_type == TC_L_REJECT ||
       comp_ptr->c_type == TC_R_REJECT || comp_ptr->c_type == TC_U_ABORT ||
       comp_ptr->c_type == TC_P_ABORT)
    {
        printf( "\tcomp_ptr->problem_code : [%d: %d(%s)]\n",
            comp_ptr->problem_code.identifier,
            comp_ptr->problem_code.code,
            PBCodeToStr(comp_ptr->problem_code.code));
    }

    if(comp_ptr->next_component == NULL)
        printf( "\tcomp_ptr->next_component : NULL\n");
    else
        printf( "\tcomp_ptr->next_component : Continue\n");

    printf( "\t------------------------------\n");
    return IXOK;
}


int PrintSS7Sim(tcx_primitive *primitive, tcx_component *comp_ptr)
{
    PrintSS7_PrimitiveSim(primitive);
    PrintSS7_ComponentSim(comp_ptr);
    return IXOK;
}
