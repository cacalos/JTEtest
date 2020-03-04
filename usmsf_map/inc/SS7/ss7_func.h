#ifndef _SS7_FUNC_H_
#define _SS7_FUNC_H_

#include <SS7/map2.h>
#include <iXtypes.h>
#if 0
#include <iXMoQ.h>
#include <iXNotiQ.h>
#include <iXReqQ.h>
#include <iXDppQ.h>
#include <iXDPPQ.h>
#include <iXSMGSQ.h>
#include <iXSmgsQ.h>
#endif

/* sh_mem.c */
int create_shm(int size);
int remove_shm(int shmid);
int get_shm_id(void);
char *use_shm(int shmid);
int release_shm(char *ptr);

#if 0
/* map_funcs.c */
int getOnePara(unsigned char *str, stOnePara *result);
int decode_SMS_ADDR(unsigned char *str, int len, stNodeNumber *node);
int decode_MIN(unsigned char *str, int len, unsigned char *min);
int decode_MDN(unsigned char *str, stAddr *mdn);
int decode_SMS_PROFILE(unsigned char *str, int len, char *profile);
int decode_CHR_INDI(unsigned char *str, int len, unsigned char *chargIndi);
int decode_NPINFO(unsigned char *str, int len, unsigned char *npInfo);
int decode_FWDREQ_ADDR(unsigned char *str, int len, unsigned char *svcId, char *fwdAddr);
int decode_INTELI_SUBINDI(unsigned char *str, int len, unsigned char *inteliIndi);
int decodeSmsParas(char *buff, unsigned char *para_str, int para_len);

int write_ESN(unsigned char *ptr, unsigned char *esn);
int write_IMSI(unsigned char *ptr, stAddr *msid);
int write_MIN(unsigned char *ptr, int defLen, unsigned char *min);
int write_CPND1(unsigned char *ptr, char *cpnd );
int write_MDN(unsigned char *ptr, char *mdn);
int write_BearerData(unsigned char *ptr, unsigned char *BD, int bd_len);
int write_CHR_IND(unsigned char *ptr, int charge_ind);
int write_MSG_CNT(unsigned char *ptr, int msg_cnt);
int write_NOTI_IND(unsigned char *ptr, int not_ind);
int write_ACCDENY(unsigned char *ptr, int acc_deny_reason);
int write_CAUSE_CODE(unsigned char *ptr, int causecode);
int write_TI(unsigned char *ptr, unsigned short TI);
int write_FWDREQ_ADDR(unsigned char *ptr,  unsigned char svcId, char *fwdAddr);
int write_SMS_PROFILE(unsigned char *ptr,  unsigned char *profile);
int write_INTELI_SUBINDI(unsigned char *ptr, unsigned char inteliIndi);
int write_NPINFO(unsigned char *ptr, unsigned char npInfo);
int write_SERVICEINDI(unsigned char *ptr, unsigned char svcIndi);
int write_SMS_ADDR(unsigned char *ptr, int tag_code, stNodeNumber *node, int isdn_pc);

int DecodeLMSMsg(unsigned char *msg, unsigned char len, stMoMsg *mo_msg);
int DecodeMsg(unsigned char *msg, unsigned char len, stMoMsg *mo_msg);
int DecodeFeature(unsigned char *msg, unsigned char len);
#endif
int print637(unsigned char *msg, int len, char *trcStr);

/* bin_hexa.c */
int get_hex_data(unsigned char *str);
int hex_to_byte(char c1, char c2);
int prn_str_hex(unsigned char *s, int len);
int prn_str_bin(unsigned char *str, int len);
int prn_bin(char c);
int prn_char(unsigned char *s, int len);
int prn_2char(unsigned short *s, int len);
int make_str_hex(unsigned char *trg, unsigned char *s, int len, int f_cols, int l_cols);


#if 0
/* sigin map2.c */
int decodeSmsNoti(unsigned char *para_str, int para_len, stNotiMsg *notiMsg);
int decodeSmsDppMo(unsigned char *para_str, int para_len, stMoMsg *moMsg);
int makeSmdppResPara(unsigned char *buf, int set_or_seq, int causecode);
int makeSmsnotResPara(unsigned char *buf, int set_or_seq, int causecode);
int makeSmsDppInvPara(unsigned char *buf, int set_or_seq, stDPPMsg *to_msc);
int decodeSmsDppResult(unsigned char *para_str, int para_len, stDppMsg *result);
int decodeSmsReqResult(unsigned char *para_str, int para_len, stReqMsg *result);
int makeSmsReqInvPara(unsigned char *buf, int set_or_seq, stAddr *mdn_addr, unsigned char noti_ind, char *cBNum );
int makeSmsDppInvPara2(unsigned char *buf, int set_or_seq, stSMGSMsg *to_smsc);
int makeSmsNotiInvPara2(unsigned char *buf, int set_or_seq, stSMGSMsg *to_smsc);
int decodeSmgsResult(unsigned char *para_str, int para_len, stSmgsMsg *result);
#endif

int do_flow_ctrl(int inc_dec, int num_sent_msg);
void mark_time_out(void);

int prn_prim_name(int prim_type);
int get_prim_name(char *name, int prim_type);
int prn_comp_name(int comp_type);
int get_comp_name(char *name, int comp_type);
int init_prim_cnt(void);
int init_comp_cnt(void);
int inc_prim_cnt(int prim);
int prn_prim_cnt(void);
int inc_comp_cnt(int comp);
int prn_comp_cnt(void);
int init_tc_err_cnt(void);
int inc_tc_err_cnt(void);
int prn_tc_err_cnt(void);

#endif /* _SS7_FUNC_H_ */
