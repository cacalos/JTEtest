
#define FLOW_CTRL_PROC_SRI                1
#define FLOW_CTRL_PROC_MTF                2
#define FLOW_CTRL_PROC_IN                 3


/* TC ERR CNT : integer array, size=21 */
/* PRIM    15 * sizeof(int) */
/* COMP 9 * sizeof (int) */
/* cong, uncong : 2 int */

#define FLOW_CTRL_NUM_TC_ERR_CNT                21
#define FLOW_CTRL_NUM_PRIM                      15
#define FLOW_CTRL_NUM_COMP                       9
#define FLOW_CTRL_NUM_CONG                       1
#define FLOW_CTRL_NUM_UNCONG                     1
#define FLOW_CTRL_NUM_TCAP_INFO   (FLOW_CTRL_NUM_TC_ERR_CNT + \
                                   FLOW_CTRL_NUM_PRIM + \
                                   FLOW_CTRL_NUM_COMP + \
                                   FLOW_CTRL_NUM_CONG + \
                                   FLOW_CTRL_NUM_UNCONG)

#define pFLOW_CTRL_TC_ERR_CNT  0
#define pFLOW_CTRL_PRIM       (pFLOW_CTRL_TC_ERR_CNT + FLOW_CTRL_NUM_TC_ERR_CNT)
#define pFLOW_CTRL_COMP       (pFLOW_CTRL_PRIM       + FLOW_CTRL_NUM_PRIM)
#define pFLOW_CTRL_CONG       (pFLOW_CTRL_COMP       + FLOW_CTRL_NUM_COMP)
#define pFLOW_CTRL_UNCONG     (pFLOW_CTRL_CONG       + FLOW_CTRL_NUM_CONG)

#define FLOW_CTRL_PROC_SIZE_SRI      (sizeof(stMsgNumSriShm) + \
    sizeof(stFlowCtrlShm) + sizeof(stResCountShm) + \
    sizeof(int)*FLOW_CTRL_NUM_TCAP_INFO)

#define FLOW_CTRL_PROC_SIZE_MTF      (sizeof(stMsgNumMtfShm) + \
    sizeof(stFlowCtrlShm) + sizeof(stResCountShm) + \
    sizeof(int)*FLOW_CTRL_NUM_TCAP_INFO)

#define FLOW_CTRL_PROC_SIZE_IN  (sizeof(stMsgNumAlertMoShm) + \
    sizeof(stFlowCtrlShm) + sizeof(stResCountShm) + \
    sizeof(int)*FLOW_CTRL_NUM_TCAP_INFO)

#define FLOW_CTRL_PROC_SIZE_INFO     (FLOW_CTRL_PROC_SIZE_SRI +\
    FLOW_CTRL_PROC_SIZE_MTF + FLOW_CTRL_PROC_SIZE_IN)    

