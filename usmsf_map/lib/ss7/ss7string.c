
#include <time.h>

#include <TCAP_common.h>
#include <TCAP_ccitt.h>
#include <TCAP_ext.h>


char *AddressTypeToStr(int type)
{
    return type == 0 ? "NO_TC_ADDRESS" :
           type == 1 ? "DEFAULT_LPC"   :
           type == 2 ? "DPC"           :
           type == 3 ? "DPC_SSN"       :
           type == 4 ? "GT"            :
           type == 5 ? "GT_SSN"        :
           type == 6 ? "GT_DPC"        :
           type == 7 ? "GT_DPC_SSN"    :
           type == 8 ? "SSN"           :
                       "UNKNOWN";
}


char *P_TypeToStr(int p_type)
{
    return p_type == TC_UNI           ? "TC_UNI"           :
           p_type == TC_BEGIN         ? "TC_BEGIN"         :
           p_type == TC_CONTINUE      ? "TC_CONTINUE"      :
           p_type == TC_END           ? "TC_END"           :
           p_type == TC_U_ABORT       ? "TC_U_ABORT"       :
           p_type == TC_P_ABORT       ? "TC_P_ABORT"       :
           p_type == TC_NOTICE        ? "TC_NOTICE"        :
           p_type == MGT              ? "MGT"              :
           p_type == SCCP_USER_STATUS ? "SCCP_USER_STATUS" :
           p_type == SCCP_PC_STATUS   ? "SCCP_PC_STATUS"   :
           p_type == SCCP_N_COORD     ? "SCCP_N_COORD"     :
           p_type == SCCP_N_COORD_RES ? "SCCP_N_COORD_RES" :
           p_type == NO_PRIMITIVE     ? "NO_PRIMITIVE"     :
           p_type == SWITCH_STARTED   ? "SWITCH_STARTED"   :
           p_type == SWITCH_DONE      ? "SWITCH_DONE"      :
                                        "UNKNOWN";
}


char * C_TypeToStr(int c_type)
{
    return c_type == TC_INVOKE    ? "TC_INVOKE"    :
           c_type == TC_RESULT_L  ? "TC_RESULT_L"  :
           c_type == TC_RESULT_NL ? "TC_RESULT_NL" :
           c_type == TC_U_ERROR   ? "TC_U_ERROR"   :
           c_type == TC_L_CANCEL  ? "TC_L_CANCEL"  :
           c_type == TC_U_CANCEL  ? "TC_U_CANCEL"  :
           c_type == TC_L_REJECT  ? "TC_L_REJECT"  :
           c_type == TC_R_REJECT  ? "TC_R_REJECT"  :
           c_type == TC_U_REJECT  ? "TC_U_REJECT"  :
                                    "UNKNOWN";
}


char *PStatusToStr(int status)
{
    return status == SCCP_INAC        ? "SCCP_INAC"        :
           status == SCCP_CONGESTED   ? "SCCP_CONGESTED"   :
           status == SCCP_ACCESSIBLE  ? "SCCP_ACCESSIBLE"  :
           status == SCCP_RESTARTING  ? "SCCP_RESTARTING"  :
           status == SCCP_UNCONGESTED ? "SCCP_UNCONGESTED" :
                                        "UNKNOWN";
}


char *PAbortCauseToStr(int cause)
{
    return cause == TC_UNRECOG_MSG_TYPE        ? "TC_UNRECOG_MSG_TYPE"        :
           cause == TC_UNRECOG_TRANSACTION_ID  ? "TC_UNRECOG_TRANSACTION_ID"  :
           cause == TC_BAD_FMT_TRANS_PORTION   ? "TC_BAD_FMT_TRANS_PORTION"   :
           cause == TC_INCORRECT_TRANS_PORTION ? "TC_INCORRECT_TRANS_PORTION" :
           cause == TC_RESOURCE_LIMITATION     ? "TC_RESOURCE_LIMITATION"     :
           cause == TC_ABNORMAL_DIALOGUE       ? "TC_ABNORMAL_DIALOGUE"       :
           cause == TC_NO_COMMON_DIALOGUE_PORTION ?
                               "TC_NO_COMMON_DIALOGUE_PORTION" :
                               "UNKNOWN";
}


char *OperationTagToStr(int tag)
{
    return tag == LOCAL_TYPE  ? "LOCAL_TYPE"  :
           tag == GLOBAL_TYPE ? "GLOBAL_TYPE" :
                                "UNKNOWN";
}


char *ErrorTagToStr(int tag)
{
    return tag == LOCAL_TYPE  ? "LOCAL_TYPE"  :
           tag == GLOBAL_TYPE ? "GLOBAL_TYPE" :
                                "UNKNOWN";
}


char *PBCodeToStr(int code)
{
    return code == UNRECOG_COMPONENT           ? "UNRECOG_COMPONENT"           :
           code == MISTYPED_COMPONENT          ? "MISTYPED_COMPONENT"          :
           code == BADLY_STRUCTURED_COMPONENT  ? "BADLY_STRUCTURED_COMPONENT"  :
           code == DUPLICATE_INVOKE_ID         ? "DUPLICATE_INVOKE_ID"         :
           code == UNRECOGNIZED_OPERATION      ? "UNRECOGNIZED_OPERATION"      :
           code == MISTYPED_PARAMETER          ? "MISTYPED_PARAMETER"          :
           code == RESOURCE_LIMITATION         ? "RESOURCE_LIMITATION"         :
           code == INITIATING_RELEASE          ? "INITIATING_RELEASE"          :
           code == UNRECOGNIZED_LINKED_ID      ? "UNRECOGNIZED_LINKED_ID"      :
           code == LINKED_RESPONSE_UNEXPECTED  ? "LINKED_RESPONSE_UNEXPECTED"  :
           code == UNEXPECTED_LINKED_OPERATION ? "UNEXPECTED_LINKED_OPERATION" :
           code == UNRECOGNIZED_INVOKE_ID      ? "UNRECOGNIZED_INVOKE_ID"      :
           code == RETURN_RESULT_UNEXPECTED    ? "RETURN_RESULT_UNEXPECTED"    :
           code == RETURN_ERROR_UNEXPECTED     ? "RETURN_ERROR_UNEXPECTED"     :
           code == UNRECOGNIZED_ERROR          ? "UNRECOGNIZED_ERROR"          :
           code == UNEXPECTED_ERROR            ? "UNEXPECTED_ERROR"            :
                                                 "UNKNOWN";
}

