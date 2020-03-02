#ifndef	IXSS7TRACE_H__

#ifdef USIGTRAN
// dduckk change header
//#include <usigtran/utcap.h>
#include <usrg/utcap.h>
#else
#include <TCAP_common.h>
#include <TCAP_ccitt.h>
#endif

#define	ACN_PARA(p)	(p)->dlg_info_present == TC_YES, (unsigned char*)(p)->application_context_name.data, (p)->application_context_name.length
#define	DLG_PARA(p)	(unsigned char*)(p)->application_context_name.data, (p)->dlg_info_present == TC_NO ? 0 :  (p)->application_context_name.length, (p)->dlg_info_present == TC_NO ? 0 : (p)->abort_reason
#define	PRIM_PARA(p)	TC_P_TYPE(p), TC_P_PROVIDER_ID(p), TC_P_USER_ID(p), DLG_PARA(&(p)->dialog_portion), &TC_P_O_ADDR(p), &TC_P_D_ADDR(p)
#define	COMP_PARA(c)	(c)->c_type, ((c)->c_type == TC_INVOKE || (c)->c_type == TC_RESULT_L) ? ((c)->operation.length == 1 ? (c)->operation.datas[0] : 0) : ((c)->c_type == TC_U_ERROR) ? (c)->error.datas[0]:0, (c)->invoke_id, (unsigned char*)(c)->parameter->bufferp, (c)->parameter->actual_length 

#define	NO_COMP_PARA	-1, 0, 0, 0, 0
#define	NO_DLG_PARA		0, 0, 0

#ifndef USIGTRAN
int MinTraceTcap(char *fName, char *funName, int lNum, stAddr *addr, int sent, 
	int primType, int provId, int userId, 
	unsigned char *acn, int acnLen, int abortReason, 
	tc_address *orig, tc_address *dest,
	int compType, int opcode, int invId, unsigned char *paraPtr, int paraLen);
#else
int MinTraceTcap(char *fName, char *funName, int lNum, stAddr *addr, int sent, 
	int primType, int provId, int userId, 
	unsigned char *acn, int acnLen, int abortReason, 
	USccpAddr *orig, USccpAddr *dest,
	int compType, int opcode, int invId, unsigned char *paraPtr, int paraLen);
#endif

char *getACName( int acnIdx);
int CheckACN( int dlgFlag, unsigned char *acn, int len);

#endif
