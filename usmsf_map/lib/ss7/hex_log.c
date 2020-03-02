#ifndef USIGTRAN
#include <ainCommon.h>
#include <TCAP_ccitt.h>
#include <TCAP_ext.h>
#include <TCAP_errors.h>
#endif

#include <stdio.h>
#include <ASN/asn_smsc.h>

#include <iXtypes.h>
#include <iXMapOp.h>
#include <SS7/ix7map.h>
#include <SS7/ss7_resq.h>

#include <iXss7Trace.h>

#include <ua_log.h>
#include <SS7/map2.h>
#include <iXCauseCode.h>

#define ERR_CODE(a)     case CC_##a : return #a;

char *getErrCodeNameGSM( int code);

typedef struct {
	int tag;
	char *name;
} TagNameType;

#define	GMAP_PARA(para)		{ tag_##para, #para }

TagNameType winParaTagList[] = {
	{ 	0x30, "SEQUENCE"},
	{ 	0x31, "SET"},
	GMAP_PARA(MIN),
	GMAP_PARA(ESN),
	GMAP_PARA(NOTIND),
	GMAP_PARA(MDN),
	GMAP_PARA(IMSI),
	GMAP_PARA(CAPABILITY),
	GMAP_PARA(new_CAPABILITY),
	GMAP_PARA(BEARERDATA),
	GMAP_PARA(TELESERVICEID),
	GMAP_PARA(CHARGEIND),
	GMAP_PARA(DESTADDR),
	GMAP_PARA(MESSAGECOUNT),
	GMAP_PARA(ORIGDESTADDR),
	GMAP_PARA(ORIGDESTSUBADDR),
	GMAP_PARA(ORIGORIGADDR),
	GMAP_PARA(ORIGORIGSUBADDR),
	GMAP_PARA(ORIGADDR),
	GMAP_PARA(CAUSECODE),
	GMAP_PARA(PROFILE),
	GMAP_PARA(ADENIEDREASON),
	GMAP_PARA(SMSADDRESS),
	GMAP_PARA(NOTIMDN),
	GMAP_PARA(CPND1),
};

extern SendRoutingInfoForSM_V3		sendRoutingInfoForSM_V3;
extern SendRoutingInfoForSM_V2		sendRoutingInfoForSM_V2;
extern MO_ForwardSM_V3				mo_forwardSM_V3;
extern MT_ForwardSM_V3				mt_forwardSM_V3;
extern ForwardSM_V2					forwardSM_V2;
extern ReportSM_DeliveryStatus_V3	reportSM_DeliveryStatus_V3;
extern ReportSM_DeliveryStatus_V2	reportSM_DeliveryStatus_V2;
extern InformServiceCentre_V3		informServiceCentre_V3;
extern InformServiceCentre_V2		informServiceCentre_V2;
extern AlertServiceCentre			alertServiceCentre;

char *myOssPrintPDU( char *str, OssGlobal *w, int pduNum, void *msg);
char *getEncScheme( int enc);
char *getNumberingPlan( int np);
char *getTranslation( int tt);
char *getAddrNature( int nature);
char *coder_getParaName( int tag);
char *getOpName( char *op_name, int op_code);

int decodeGSMParas(char *buff, unsigned char *para_str, int para_len)
{
	make_str_hex(buff, para_str, para_len, 5, 10);
	return IXOK;
}

int MinTraceMap( char *fName, char *funName, int lNum, stAddr *addr, 
		unsigned char *paraPtr, int paraLen, 
		struct ossGlobal *world, int pdu, void *msg)
{
    char   buf[4096];

    if(addr == NULL || fName == NULL)
        return IXERR;

	memset( buf, 0, sizeof(buf) );

	/* decode */
	if ( world) {
		myOssPrintPDU( buf, world, pdu, msg);
	} 
	else {
		getPrintFormat( sizeof(buf), buf, paraLen, paraPtr);
	}

	if ( strlen(buf) > 0) 
		MinTrace( fName, funName, lNum, addr, "%s\n", buf);

    return IXOK;
}

#ifndef USIGTRAN
int MinTraceTcap(char *fName, char *funName, int lNum, stAddr *addr, int sent, 
	int primType, int provId, int userId, 
	unsigned char *acn, int acnLen, int abortReason,
	tc_address *orig, tc_address *dest,
	int compType, int opcode, int invId, unsigned char *paraPtr, int paraLen)
{
    char    buff[2000];
    char    p_name[20], c_name[20];
    char    op_name[48];
	char 	origAddr[128], destAddr[128];
	char 	para[1024];
	char	appContxt[128];
	char	ext[80];
	char *ptr;
	int i;
	const char *lineStr = "-----------------------------------------------------------\n";

    if(addr == NULL || fName == NULL)
        return IXERR;

    get_prim_name(p_name, primType);
    get_comp_name(c_name, compType);

	/* get address string */
	getAddrStr( origAddr, orig);
	getAddrStr( destAddr, dest);

    if( acnLen > 0) {
		ptr = appContxt;

		for(i = 0; i < acnLen; i++)
		{
			sprintf(ptr, "%02X ", (unsigned char)acn[i]);
			ptr += strlen(ptr);
		}

		sprintf( ptr, "(%s)", getACName( CheckACN( 1, acn, acnLen)));
	}
	else {
		sprintf( appContxt, "None");
	}

	para[0] = 0;
    if( paraLen > 0) {
		ptr = para;

		strcpy( ptr, lineStr);
		ptr += strlen(ptr);

		for(i = 0; i < paraLen; i++)
		{
			if( i> 0 && (i % 20) == 0) {
				sprintf(ptr, "\n");
				ptr+= strlen(ptr);
			}

			sprintf(ptr, "%02X ", (unsigned char)paraPtr[i]);
			ptr += strlen(ptr);
		}

		sprintf( ptr, "\n%s", lineStr);
	}

	if ( primType == TC_U_ABORT || primType == TC_P_ABORT ) {
		MinTrace( fName, funName, lNum, addr, 
"--- TCAP %s : %s %s ---\n\
Orig Addr  : %s\n\
Dest Addr  : %s\n\
DiagID     : user=%d prov=%d\n\
AppContxt  : %s\n\
Reason     : %s\n",
			sent ? "SENT":"RECV", p_name, c_name, 
			origAddr, destAddr,
			userId, provId, appContxt,
            abortReason == AC_name_not_supported ?
                "AC_name_not_supported" :
            abortReason == user_specific ?
                "user_specific" :
                "unknown");

		return IXOK;
	}

	/* add extra info */
	switch ( compType ) {
	case TC_U_ERROR: 
		sprintf( ext, "Error code : %d   3G:%s\n", 
			opcode, getErrCodeNameGSM(opcode));
		break;
	case TC_INVOKE :
	case TC_RESULT_L :
	case TC_RESULT_NL :
		if ( paraLen > 0) {
			getOpName( op_name, opcode);
			sprintf( ext, "OP code    : %d  (H'%x)  %s\n",
				opcode, opcode, op_name);
		}
		else ext[0] = 0;

		break;
	default:
		ext[0] = 0;
		break;
	}

	MinTrace( fName, funName, lNum, addr, 
"--- TCAP %s : %s %s ---\n\
Orig Addr  : %s\n\
Dest Addr  : %s\n\
%s\
Invoke ID  : %d\n\
DiagID     : user=%d prov=%d\n\
AppContxt  : %s\n\
ParaLength : %d\n%s",
		sent ? "SENT":"RECV", p_name, c_name, 
		origAddr, destAddr,
		ext,
		invId, userId, provId, appContxt,
		paraLen, (paraLen>0)?para:"");

    return IXOK;
}
#endif


/*---- for Printf TC_R_REJECT, TC_L_REJECT info.
  ---- Problem Code */
char *reject_type[4] =
    {"GENERAL", "INVOKE", "RETURN_RESULT", "RETURN_ERROR"};

char *reject_cause[16] = {
    "UNRECOG_COMPONENT",
    "MISTYPED_COMPONENT",
    "BADLY_STRUCTURED_COMPONENT",
    "DUPLICATE_INVOKE_ID",
    "UNRECOGNIZED_OPERATION",
    "MISTYPED_PARAMETER",
    "RESOURCE_LIMITATION",
    "INITIATING_RELEASE",
    "UNRECOGNIZED_LINKED_ID",
    "LINKED_RESPONSE_UNEXPECTED",
    "UNEXPECTED_LINKED_OPERATION",
    "UNRECOGNIZED_INVOKE_ID",
    "RETURN_RESULT_UNEXPECTED",
    "RETURN_ERROR_UNEXPECTED",
    "UNRECOGNIZED_ERROR",
    "UNEXPECTED_ERROR"
} ;

char *Unknown2 = "Unknown";

#if 0
int fprn_prim_comp_tpdu(char *desc_msg, stAddr *addr, int cc)
{
	int           ret;
    time_t        tm;
    FILE         *fp;
    char         *logdir;
    char          fname[256];
    char          buff[2000];
    char          buf[30];


    time(&tm);
    strftime(buff, 10, "%Y%m%d", localtime(&tm));

    logdir = getenv("SMS_LOG_DIR");
    if(logdir == NULL)
        sprintf(fname, "/tmp/.iXMapOpErr%s", buff);
    else
        sprintf(fname, "%s/.iXMapOpErr%s", logdir, buff);

    if((fp = fopen(fname, "a+")) == NULL)
    { 
        uaLog(L_CRT,
            "Cannot write the file for Link Status Logging : %s", fname);
        return IXERR;
    }

    time(&tm);
    strftime(buf, 24, "%Y/%m/%d %H:%M:%S", localtime(&tm));
    fprintf(fp, "=== TIME:  %s \n", buf);

	fprintf(fp,
"\n\t---- TPDU Mesg -----\n\
\tFrom MSISDN : [%s]\n\
\tError Code  : [%d]\n\
\tError Reason: %s\n\
\tError Msg   : %s\n",
	addr->min, cc,
		cc == TPDU_DEC_ERR_UDL ? "TPDU_DEC_ERR_UDL" :
		cc == TPDU_DEC_ERR_UDLMAX ? "TPDU_DEC_ERR_UDLMAX" :
		cc == TPDU_DEC_ERR_UDHL ? "TPDU_DEC_ERR_UDHL" :
		cc == TPDU_DEC_ERR_IEL ? "TPDU_DEC_ERR_IEL" :
		cc == TPDU_DEC_ERR_ADDRLEN ? "TPDU_DEC_ERR_ADDRLEN" :
		cc == TPDU_DEC_ERR_VPF ? "TPDU_DEC_ERR_VPF" : "UNKNOWN",
		desc_msg);

	fflush(fp);
	fclose(fp);
 
	return IXOK;
}
#endif

#ifndef USIGTRAN
int fprn_prim_comp(char *desc_msg, tcx_primitive *prim, tcx_component *comp,
				unsigned char msg_type)
{
    int           ret;
    char          buff[2000];
    char          buf[30];
    char          p_name[20], c_name[20];
    int           OP;
    int           p_type, p_id, u_id;
    char         *ptr1, *ptr2;
    time_t        tm;
    FILE         *fp;
    char         *logdir;
    char          fname[256];
    char          op_code[20];
    char          op_name[20];

    if(prim == NULL)
        return IXERR;
    if(comp == NULL)
        return IXERR;

    time(&tm);
    strftime(buff, 10, "%Y%m%d", localtime(&tm));

    logdir = getenv("SMS_LOG_DIR");
    if(logdir == NULL)
        sprintf(fname, "/tmp/.iXMapOpErr%s", buff);
    else
        sprintf(fname, "%s/.iXMapOpErr%s", logdir, buff);

    if((fp = fopen(fname, "a+")) == NULL)
    { 
        uaLog(L_CRT,
            "Cannot write the file for Link Status Logging : %s", fname);
        return IXERR;
    }

    time(&tm);
    strftime(buf, 24, "%Y/%m/%d %H:%M:%S", localtime(&tm));
    fprintf(fp, "=== TIME:  %s \n", buf);

    if(desc_msg != NULL)
        fprintf(fp, "Error Description: %s\n", desc_msg);

    memset(buff, 0, 2000);
    p_type = TC_P_TYPE(prim);
    p_id = TC_P_PROVIDER_ID(prim);
    u_id = TC_P_USER_ID(prim);

    get_prim_name(p_name, TC_P_TYPE(prim));
    get_comp_name(c_name, comp->c_type);

    if(comp->operation.length == 0)
        *op_code = 0;
    else
        make_str_hex2(op_code, comp->operation.datas, comp->operation.length,
            10, 10);

    if(comp->operation.length == 1)
    {
        OP = comp->operation.datas[0];
        if(OP == sendRoutingInfoForSM_V3.u.localValue ||
		   OP == sendRoutingInfoForSM_V2.u.localValue)
            strcpy(op_name, "SRI");
        else if(OP == mt_forwardSM_V3.u.localValue)
            strcpy(op_name, "MTF");
        else if(OP == mo_forwardSM_V3.u.localValue)
            strcpy(op_name, "MOF");
        else if(OP == forwardSM_V2.u.localValue)
            strcpy(op_name, "MOF");
        else if(OP == reportSM_DeliveryStatus_V3.u.localValue ||
				OP == reportSM_DeliveryStatus_V2.u.localValue)
            strcpy(op_name, "REPORT");
        else if(OP == alertServiceCentre.u.localValue)
            strcpy(op_name, "ALERT");
        else if(OP == informServiceCentre_V3.u.localValue ||
				OP == informServiceCentre_V2.u.localValue)
            strcpy(op_name, "INFORM");
        else if(OP == MAP_OP_SMSDPP)
            strcpy(op_name, "SMDPP");
        else if(OP == MAP_OP_SMSREQ)
            strcpy(op_name, "SMREQ");
        else if(OP == MAP_OP_SMSNOT)
            strcpy(op_name, "SMNOT");
        else
            strcpy(op_name, "Unknown!");
    }
    else if(comp->operation.length == 0)
        strcpy(op_name, "None");
    else
        strcpy(op_name, "Unknown!");

    fprintf(fp,
"\n\t---- TCAP Mesg -----\n\
\tFrom PC= [%d(H'%X)], SSN= [%d]\n\
\tTO   PC= [%d(H'%X)], SSN= [%d]\n\
\tPrimitive  : %s\n\
\tComponent  : %s\n\
\tInvoke ID  : [%d, H'%X]\n\
\tOP code    : %s [H' %s]\n\
\tUser DiagID: [%d]\n\
\tProv DiagID: [%d]\n\
\tPara Len   : [%d]\n",
            TC_P_O_ADDR(prim).pc_value, TC_P_O_ADDR(prim).pc_value,
            TC_P_O_ADDR(prim).ssn,
            TC_P_D_ADDR(prim).pc_value, TC_P_D_ADDR(prim).pc_value,
            TC_P_D_ADDR(prim).ssn,
            p_name, c_name, 
            comp->invoke_id, comp->invoke_id,
            op_name, op_code, 
            u_id, p_id,
            comp->parameter->actual_length);

    if(comp->c_type == TC_L_REJECT || comp->c_type == TC_R_REJECT)
    {
        /* reject type */
        if(comp->problem_code.identifier < 4)
            ptr1 = reject_type[comp->problem_code.identifier];
        else
            ptr1 = Unknown2;

        /* reject cause */
        if(comp->problem_code.code < 16) 
            ptr2 = reject_cause[comp->problem_code.code];
        else
            ptr2 = Unknown2;

        fprintf(fp,
        "\n\t---- REJECT (Problem Code) -----\n\
\tReject Type : %d = %s\n\
\tReject Cause: %d = %s\n",comp->problem_code.identifier, ptr1,
             comp->problem_code.code, ptr2);
    }

    if(comp->parameter->actual_length > 0)
    {
        make_str_hex(buff, comp->parameter->bufferp,
            comp->parameter->actual_length, 5, 10);

        fprintf(fp, "\t--- Paramter Contents ---%s\n\n", buff);

        memset(buff, 0, 2000);
		if (msg_type == MSG_TYPE_CDMA)
		{
			decodeSmsParas(buff, (unsigned char *)comp->parameter->bufferp,
				comp->parameter->actual_length);
			fprintf(fp, "\t--- Paramter Decoding ---\n%s", buff);
		}
		else if (msg_type == MSG_TYPE_GSM)
		{
			decodeGSMParas(buff, (unsigned char *)comp->parameter->bufferp,
				comp->parameter->actual_length);
			fprintf(fp, "\t--- Paramter raw ---\n%s", buff);
		}
		else
		{
			bzero((void *)buff, sizeof(buff));
		}
    }

    /* close log file */
    fclose(fp);

    return IXOK;
}
#endif

char *myOssPrintPDU( char *str, OssGlobal *w, int pduNum, void *msg)
{
	str[0] = 0;

	w->userVar = str;
	ossPrintPDU( w, pduNum, msg);

	printf("ossPrintPDU Len=%d pdu=%d\n", strlen(str), pduNum );
	return str;
}

int myOssPrint( OssGlobal *w, const char *format, ... )
{
	va_list     args;
	char *str;

	str = (char*)w->userVar;
	va_start(args, format);
	vsprintf( str, format, args);
	va_end(args);

	w->userVar = str + strlen(str);

	return 0;
}

#ifndef USIGTRAN
int getAddrStr( char *str, tc_address *addr)
{
	switch( addr->type) {
	case NO_TC_ADDRESS:
		sprintf( str, "No Address");
		break;
	case DEFAULT_LPC:
		sprintf( str, "Default LPC");
		break;
	case DPC:
		sprintf( str, "PC=%d (H'%x)", addr->pc_value, addr->pc_value);
		break;
	case DPC_SSN:
		sprintf( str, "PC=%d (H'%x)  SSN=%d (H'%x)", 
			addr->pc_value, addr->pc_value,
			addr->ssn, addr->ssn);
		break;
	case GT: 
		getGtStr( str, &addr->gt);
		break;
	case GT_SSN:
		getGtStr( str, &addr->gt);
		sprintf( &str[strlen(str)], "  SSN=%d (H'%x)", addr->ssn, addr->ssn);
		break;
	case GT_DPC: 
		getGtStr( str, &addr->gt);
		sprintf( &str[strlen(str)], "  PC=%d (H'%x)", 
			addr->pc_value, addr->pc_value);
		break;
	case GT_DPC_SSN:
		getGtStr( str, &addr->gt);
		sprintf( &str[strlen(str)], "  PC=%d (H'%x)  SSN=%d (H'%x)", 
			addr->pc_value, addr->pc_value,
			addr->ssn, addr->ssn);
		break;
	case SSN :
		sprintf( str, "SSN=%d (H'%x)", addr->ssn, addr->ssn);
		break;
	}

	return 0;
}

int getGtStr( char *str, tc_global_title *gt)
{
	int i;
	char *cp;

	switch( gt->gtIndicator) {
	case tc_no_gt :
		strcpy( str, "No GT");
		return 0;
	case tc_gt_type1 :
		sprintf( str, "ADDR=%s  NAI=%s",
			gt->digit, getAddrNature(gt->nature));
		break;
	case tc_gt_type2 :
		sprintf( str, "ADDR=%s  TT=%s",
			gt->digit, getTranslation(gt->translation));
		break;
	case tc_gt_type3 :
		sprintf( str, "ADDR=%s  TT=%s  NP=%s  ENC=%s",
			gt->digit, getTranslation(gt->translation), 
			getNumberingPlan(gt->numbering), 
			getEncScheme(gt->encoding));
		break;
	case tc_gt_type4 :
		sprintf( str, "ADDR=%s  NAI=%s  TT=%s  NP=%s  ENC=%s",
			gt->digit, getAddrNature(gt->nature), 
			getTranslation(gt->translation), 
			getNumberingPlan(gt->numbering), 
			getEncScheme(gt->encoding));
		break;
	}

	return 0;
}

char *getAddrNature( int nature)
{
	switch( nature) {
	case tc_subscriber_nb :
		return "SUBS";
	case tc_national_nb : 
		return "NAT";
	case tc_international_nb :
		return "INTL";
	}
	return "unknown";
}

char *getTranslation( int tt)
{
	switch( tt) {
	case tc_t_unused: 
		return "UNUSED";
	case tc_t_internetwork: 
		return "INTRWRK";
	case tc_t_networkspecific :
		return "NET_SPEC";
	}
	return "unknown";
}

char *getNumberingPlan( int np)
{
	switch( np) {
	case tc_unknown_num: 
		return "UNKNOWN";
	case tc_num_isdn: 
		return "NUM_ISDN";
	case tc_num_userdata: 
		return "NUM_USRDATA";
	case tc_num_telex: 
		return "NUM_TELEX";
	case tc_num_maritime_mobile: 
		return "NUM_MAR_MOB";
	case tc_land_mobile: 
		return "LAND_MOB";
	case tc_isdn_mobile:
		return "ISDN_MOB";
	}
	return "unknown";
}

char *getEncScheme( int enc)
{
	switch( enc) {
	case tc_unknown_encode : 
		return "UNKNOWN";
	case tc_bcd_odd : 
		return "BCD_ODD";
	case tc_bcd_even :
		return "BCD_EVEN";
	}
	return "UNKNOWN";
}

#endif



/*
    convert encoded string to printable format

    tag    length  data
    FFFFFF [00] XX XX XX XX
*/
int getPrintFormat( int dstLen, char *dst, int strLen, unsigned char *str)
{
    int idx = 0, totalIdx = 0;
    int tag, len, strLength;
    unsigned char *data;

	dst[0] = 0;
    while(1) {
        if ((idx = CODER_getTLV( strLen - totalIdx, (unsigned char*)(str + totalIdx), &tag, &len, &data)) == 0) 
            break;

		if ( idx < 0) {
			uaLog( L_MAJ, "Invalid encoded string");
			return -1;
		}

		totalIdx += idx;

		strLength = strlen(dst);
		coder_sprintPara( 0, dstLen - strLength, &dst[strLength], tag, len, data);
    }

    return 0;
}

int CODER_getTLV( int srcLen, unsigned char *src, int *tag, int *len, unsigned char **data)
{
    unsigned char *cp;
    int tagLen, i, lenLen;
	int constructed;

	if ( srcLen == 0) return 0;

    cp = src;

    /* get tag */
    tagLen = 1;
    *tag = *cp;

	constructed = *cp & 0x20;	/* check if the tag is constructed or not */

    if ( (*cp & 0x1f) == 0x1f) {
        cp ++;
        /* this is 2 byte tag */
        tagLen = 2;
        *tag = ((*tag) << 8 ) | *cp;
        if ( *cp & 0x80) {
            cp ++;
            tagLen = 3;
            /* this is 3 byte tag */
            *tag = ((*tag) << 8 ) | *cp;
        }
    }

	/* check length */
	srcLen -= tagLen;
	if ( srcLen <= 0) return -1;

    cp ++;

    /* get length */
	if ( *cp == 0x80) {
		int t, l, len2;
		unsigned char *p;

		/* indefinite length form */
		if ( constructed == 0) {
			/* indefinite length form is used only for constructed tag */
			return -1;
		}

		/* get length : find EOC */
		lenLen = 0;
		while(1) {
			if ( (len2 = CODER_getTLV( srcLen -1 - lenLen, cp+1 +lenLen, &t, &l, &p)) < 0) 
				return -1;
			if ( t == 0 && l == 0) {
				/* if the tag and length are zero, it's EOC */
				break;
			}
			lenLen += len2;
		}

		*len = lenLen;	/* length of value */
		lenLen += 3;	/* length of total length */
	}
	else if ( *cp & 0x80) {
		/* long form */
		lenLen = *cp & 0x7f;
		*len = 0;
		cp ++;

		/* check length */
		if ( srcLen +1 <= lenLen) return -1;

		for( i=0; i< lenLen; i++) {
			*len = ((*len) * 256) + (*cp);
			cp ++;
		}
		lenLen ++;	/* bhtak 2003/12/16 increase lenLen */
	}
	else {
		/* short form */
		*len = *cp ++;
		lenLen = 1;
	}

	/* check length */
	srcLen -= lenLen;
	if ( srcLen < 0) return -1;
	
	if ( srcLen == 0) {
		*data = 0;
		return tagLen + lenLen;
	}

    /* get data */
    *data = cp;

    return tagLen + lenLen + *len;
}


/*
   print constructed parameter
   */
int coder_sprintPara( int depth, int bufLen, char *buf, int tag, int len, unsigned char *data)
{
	int idx, totalIdx;
	int i, paraLen, strLen;
	char *paraName, *dst;
	unsigned char *para;

	if ( bufLen < 45 + 3*len) {
		strcpy( buf, "...");
		return -1;
	}

	dst = buf;

	for( i=0; i< depth; i++) {
		*dst++ = ' ';
		*dst++ = ' ';
	}

	paraName = coder_getParaName( tag);

	if ( isSimpleTag( tag)) {
		/* normal parameter */
		sprintf( dst, "%-6x %-20s : ", tag, (paraName)?(paraName):"");
		dst += strlen(dst);

		for( i=0; i< len; i++) {
			if ( i > 0 && (i%15) == 0) {
				memset( dst, ' ', depth*2 + 33);
				dst += depth*2 + 33;
			}

			sprintf( dst, "%02x ", data[i]);
			dst += 3;
		}

		strcpy( dst, "\n");

		return 0;
	}

	/* constructed parameter */
	sprintf( dst, "%-6x %s {\n", tag, (paraName)?(paraName):"");
	dst += strlen(dst);

	totalIdx = 0;
    while(1) {
        if ((idx = CODER_getTLV( len - totalIdx, (data + totalIdx), &tag, &paraLen, &para)) == 0) 
            break;
		if ( idx < 0) {
			uaLog( L_MAJ, "Invalid encoded string");
			return -1;
		}

		totalIdx += idx;

		strLen = strlen(buf);
		coder_sprintPara( depth+1, bufLen - strLen, dst, tag, paraLen, para);
		dst += strlen(dst);
    }

	for( i=0; i< depth; i++) {
		*dst ++ = ' ';
		*dst ++ = ' ';
	}
	strcpy( dst, "}\n");
	
	return 0;
}

char *coder_getParaName( int tag)
{
	static int sorted = 0;
	TagNameType *found, key;
	int cmpTag( const void*, const void*);

	if ( sorted == 0) {
		/* sort tag name list */
		qsort( winParaTagList, sizeof(winParaTagList)/sizeof(TagNameType), sizeof(TagNameType), cmpTag);
		sorted = 1;
	}

	/* find parameter name */
	key.tag = tag;
	found = bsearch( &key, winParaTagList, sizeof(winParaTagList)/sizeof(TagNameType), sizeof(TagNameType), cmpTag);
	if ( found) return found->name;

	return 0;
}

int cmpTag( const void* a, const void* b)
{
	return ((const TagNameType*)a)->tag - ((const TagNameType*)b)->tag;
}

int isSimpleTag( int tag)
{
	if ( tag <= 0xff) {
		/* one byte tag */
		return !( tag & 0x20);
	}
	else if ( tag <= 0xffff) {
		/* two bytes tag */
		return !( tag & 0x2000);
	}

	/* three bytes tag */
	return !( tag & 0x200000);
}

char *getOpName( char *op_name, int op_code)
{
	switch (op_code ) {
	case MAP_OP_SendRoutingInfoForSM :
		strcpy(op_name, "SendRoutingInfoForSM");
		break;
	case MAP_OP_MTForwardSM :
		strcpy(op_name, "MTForwardSM");
		break;
	case MAP_OP_MOForwardSM :
		strcpy(op_name, "MOForwardSM");
		break;
	case MAP_OP_ReportSMDeliveryStatus :
		strcpy(op_name, "ReportSMDeliveryStatus");
		break;
	case MAP_OP_AlertServiceCenter :
		strcpy(op_name, "AlertServiceCenter");
		break;
	case MAP_OP_InformServiceCenter :
		strcpy(op_name, "InformServiceCenter");
		break;
	case MAP_OP_SMSREQ:
		strcpy(op_name, "SMSREQ");
		break;
	case MAP_OP_SMSDPP:
		strcpy(op_name, "SMSDPP");
		break;
	case MAP_OP_SMSNOT:
		strcpy(op_name, "SMSNOTI");
		break;
	default:
		strcpy(op_name, "Unknown!");
		break;
	}

	return op_name;
}


char *getErrCodeNameGSM( int code)
{
	if ( code < 3000) code += 3000;

	switch( code ) {

	ERR_CODE(UNKNOWN_SUBSCRIBER)
	ERR_CODE(UNIDENTIFIED_SUBSCRIBER)
	ERR_CODE(ABSENT_SUBSCRIBER_SM)
	ERR_CODE(ILLEGAL_SUBSCRIBER)
	ERR_CODE(TELESERVICE_NOT_PROVISIONED)
	ERR_CODE(ILLEGALEQUIPMENT)

	ERR_CODE(CALL_BARRED)
	ERR_CODE(FACILITY_NOT_SUPPORTED)
	ERR_CODE(ABSENT_SUBSCRIBER)
	ERR_CODE(INCOMPATIBLE_TERMINAL)
	ERR_CODE(SUBSCRIBER_BUSY_FOR_MT_SMS)

	ERR_CODE(SM_DELIVERY_FAILURE)
	ERR_CODE(MESSAGE_WAITING_LIST_FULL)
	ERR_CODE(SYSTEM_FAILURE)
	ERR_CODE(DATA_MISSING)
	ERR_CODE(UNEXPECTED_DATA_VALUE)

	ERR_CODE(BUSY_SUBSCRIBER)
	ERR_CODE(RESOURCE_LIMITATION)
	ERR_CODE(UNKNOWN_ALPHABET)
	ERR_CODE(GSM_HLR_PORTED_OUT)

	ERR_CODE(NPR3G_CS)             
	ERR_CODE(IMSI_DETACHED)        
	ERR_CODE(ROAM_RESTRICTION)     
	ERR_CODE(DEREGISTED_NON_GPRS)  
	ERR_CODE(PURGED_NON_GPRS)      
	ERR_CODE(NPR3G_PS)             
	ERR_CODE(GPRS_DETACHED)        
	ERR_CODE(DEREGISTED_GPRS)      
	ERR_CODE(PURGED_GPRS)          
	ERR_CODE(UNIDENTIFIED_CS)      
	ERR_CODE(UNIDENTIFIED_PS)      

	ERR_CODE(MCEF)             
	ERR_CODE(PROTOCOL_ERR)         
	ERR_CODE(NOT_SM_EQUIPPED)      
	ERR_CODE(UNKNOWN_SC)           
	ERR_CODE(SC_CONGESTION)        
	ERR_CODE(INVALID_SME_ADDR)     
	ERR_CODE(NOT_SC_SUBSCRIBER)    

	}
	return "UNKNOWN";
}	


int isOpCDMA( int opcode) 
{
	switch (opcode ) {
	case MAP_OP_SMSREQ:
	case MAP_OP_SMSDPP:
	case MAP_OP_SMSNOT:
		return 1;
	}

	return 0;
}
