#include <usrg/utcap.h>
#include <uxlib/ux_util.h>
#include <iXtypes.h>
#include <iXLog.h>
#include <RPDU/RPDU.h>

void see_results() ;
void closeProc( int sig);
int GetInconf(char *file);
int MakeDiagnosticInfo(unsigned char *str, char fcs);
int send_response(int msg_send);
int recvIncomingMsg();
int procComp( UTcapPrimitive *prim, UTcapComponents *comp);
int procPrim( UTcapPrimitive *primitive);
int InitInResponseQ();
int GetInQelmt(int diagId, stMtResponseQ *inRes);
int allocInResQ( void);
int setTraceModeIN( int diagId, stAddr *orig, stAddr *dest);
int isInTrace( int diagId, int level);
stAddr *getTraceNum( int diagId);
int getNodeIndex( int diagId);
int setNodeIndex( int diagId, char *addr);
int insertInResQ(int diag_id, int u_id, int prov_id, int inv_id, unsigned char acn, USccpAddr *dstAddr, USccpAddr *srcAddr, char isMMS, stAddr *addr, stNodeNumber *node);
      
int SetDone(unsigned char msgRef, char *supi);
int CheckTimeOut(int timeOut);

int isdn_compare(const char *node1, const char *node2);
int GetIndexHLRisdnTab(char *isdn);
int GetIndexMSCisdnTab(char *isdn);
int GetIndexSGSNisdnTab(char *isdn);
int GetIndexSMSCisdnTab(char *isdn);

int mo_flow_ctrl();
int printInStat();
int updateStat();

int init_resq_data(void);
int remove_resq_data(unsigned char msgRef, char *supi);
int resq_data_count(void);
stMtResponseQ *get_resq_data(unsigned char msgRef, stAddr *addr);
stMtResponseQ *add_resq_data_for_trace(int diag_id, int trace, int level, stAddr *addr);
int add_resq_data(int diag_id, int u_id, int prov_id, int inv_id, unsigned char acn, USccpAddr *dstAddr, USccpAddr *srcAddr, char isMMS, stAddr *addr, unsigned char msgRef, stNodeNumber *node);
                    
int handleMtResGsm(stMtResponseQ *inRes, char *diag_id);
int handleMtErrGsm(stMtResponseQ *inRes, int cc, _RPDU *rpdu, char *diag_id);
