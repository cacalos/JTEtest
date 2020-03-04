void see_results() ;
void closeProc();
int GetMTFconf(char *file);
int sendInvokes( int msg_num);
int sendMofInvoke(int diagId, int userId, int provId, int invId,
                  stMoMsg *to_msg, enum UTcapTransactionType msgType,
                  unsigned char acn_version);
int recvFromMSC_SGSN(int waitTime);
int handleMTFResult(UTcapPrimitive *prim, 
                    UTcapComponents *comp, 
                    int userId, 
                    int provId, 
                    int diagId);
int handleResult( int diagId, 
                  UTcapPrimitive *prim, 
                  UTcapComponents *comp, 
                  stMoMsg *to_msc);
int handleError(int diagId,
                UTcapPrimitive *prim,
                UTcapComponents *comp,
                stMoMsg *to_msc);
int sendErrToEngine(int diagId, int err_code, char acnVer);
int procComp(UTcapComponents *comp, int diagId);

int procPrim(UTcapPrimitive *prim, int diagId);

int sccp_user_st(UTcapPrimitive *prim);
int sccp_st(UTcapPrimitive *prim);
int GetNumMtfResQ();
int setNodeIndex( int diagId, char *isdn);
int CleanMtfQ();
int ShowQStatus();
int GetDiagIDinTable(int user_id, int *diag_id);
int isdn_compare(char *node1, char *node2);
int GetIndexMSCisdnTab(char *isdn);
int GetIndexSGSNisdnTab(char *isdn);
int initMTFstat() ;
int updateMTFstat() ;
int inc_mtf_send_succ( int diagId, stNodeNumber *node);
int inc_mtf_send_fail( int diagId, stNodeNumber *node);
int inc_mtf_send_ack( int diagId, stNodeNumber *node);
int inc_mtf_send_nack( int diagId, int ecode, stNodeNumber *node);
int inc_mtf_send_time( int diagId, stNodeNumber *node);
int on_node(char *isdn);
int cong_node(char *isdn);
int off_node(char *isdn);
int status_node(char *isdn);

int InitMtfResponseQ(void);
int GetNumOutResQ();
stMoMsg *GetOutQelmt(int diagId);
int GetMtfQsts(int diagId);
int allocMtfResQ( void);
int insertMtfResQ(int diagId, stMoMsg *new_msg);
int getNodeIndex( int diagId , char *netIdx);
int setMscSgsnIndex( int diagId, char *isdn);
int setTraceModeMTF( int diagId, stAddr *orig, stAddr *dest);
int isInTrace( int diagId, int level) ;
int SetDone(int diagId);
int CheckTimeOut(int timeOut);
void prn_mtfResQ(int diagId);
int getDiagId(int userId);
int SetDiagIDinTable(int userId, int diagId);
int UnsetDiagIDinTable(int userId);
int CheckDiagIDinTable(int sec);
int isOverFlowTrafficForOUT(stNodeNumber *node);


int init_resq_data();
stMoResponseQ *add_resq_data_for_trace(int diag_id, int trace, int level, stAddr *addr);
int add_resq_data(int diag_id, int status, void *new_msg);
stMoResponseQ *get_resq_data(int diag_id);
int remove_resq_data(int diag_id);
int resq_data_count();
void check_timeout(int timeOut, int *gTimeOutCnt);

