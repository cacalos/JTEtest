#include <iXCauseCode.h>
#include <ix7map.h>
#include <map2.h>
#include <ua_log.h>
#include <iXLog.h>

#include <sigtran_util.h>


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
	GMAP_PARA(CAPABILITY),
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
	GMAP_PARA(ADENIEDREASON),
	GMAP_PARA(SMSADDRESS),
};

/* function prototypes */
char *coder_getParaName( int tag);



char *addr2str( unsigned char *addr, char *str)
{
	switch ( addr[0] ) {
	case 0x43 :
		sprintf( str, "PC=H'%02x%02x  SSN=H'%x", addr[1], addr[2], addr[3]);
		break;
	/*
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
	*/
	}

	return str;
}


int addr2pc( unsigned char *addr, int *pc, int *ssn)
{
	if ( addr[0] == 0x43 ) {
		if ( pc ) *pc = addr[1]*256 + addr[2];
		if ( ssn ) *ssn = addr[3];
	}

	return -1;
}

#if 0
int minTraceTcap(char *fName, char *funName, int lNum, 
	stAddr *addr, AtifSleeMsgType *msg, int sent)
{
    char    buff[2000];
    /*char    p_name[20], c_name[20]; */
    char    op_name[48];
	char 	para[1024];
	char	appContxt[128];
	char	ext[80];
	char	origAddr[32], destAddr[32];
	char *ptr;
	unsigned char *paraPtr;
	int i;
	const char *lineStr = "-----------------------------------------------------------\n";

    if(addr == NULL || fName == NULL)
        return IXERR;

    if(IsThisMinTrace(addr) != IXOK)
        return 0;

	/*
    strcpy(p_name, (char *)TCAP_DLG_STR(msg->dlgMode));
    strcpy(c_name, (char *)TCAP_COMP_STR(msg->compMode));
	*/

	/* get address string */
	addr2str( msg->orig, origAddr);
	addr2str( msg->dest, destAddr);

    if( msg->paraLen > 0) {
		strcpy( ptr, lineStr);
		ptr += strlen(ptr);

		for(i = 0; i < msg->paraLen; i++)
		{
			if( i> 0 && (i % 20) == 0) {
				sprintf(ptr, "\n");
				ptr+= strlen(ptr);
			}

			sprintf(ptr, "%02X ", (unsigned char)msg->parameter[i]);
			ptr += strlen(ptr);
		}

		sprintf( ptr, "\n%s", lineStr);
	}

	if ( msg->dlgMode == TCAP_DLG_ABORT) {
		MinTrace( fName, funName, lNum, addr, 
"--- TCAP %s : %d %d ---\n\
Orig Addr  : %s\n\
Dest Addr  : %s\n\
DiagID     : %d\n",
			sent ? "SENT":"RECV", msg->dlgMode, msg->compMode,
			origAddr, destAddr, msg->usrDid);

		return IXOK;
	}

	/* add extra info */
	switch ( msg->compMode ) {
	case TCAP_COMP_ERROR: 
		sprintf( ext, "Error code : %d   (%s)\n", 
			msg->opcode, getErrCodeNameCDMA(msg->opcode));
		break;
	case TCAP_COMP_INVOKE :
	case TCAP_COMP_RESULT :
		if ( msg->paraLen > 0) {
			getOpName( op_name, msg->opcode);
			sprintf( ext, "OP code    : %d  (H'%x)  %s\n",
				msg->opcode, msg->opcode, op_name);
		}
		else ext[0] = 0;

		break;
	default:
		ext[0] = 0;
		break;
	}

	MinTrace( fName, funName, lNum, addr, 
"--- TCAP %s : %d %d ---\n\
Orig Addr  : %s\n\
Dest Addr  : %s\n\
%s\
Invoke ID  : %d\n\
DiagID     : %d\n\
ParaLength : %d\n%s",
		sent ? "SENT":"RECV", msg->dlgMode, msg->compMode,
		origAddr, destAddr,
		ext,
		msg->iid, msg->usrDid, 
		msg->paraLen, (msg->paraLen>0)?para:"");

    return IXOK;
}
#endif



#define	ERR_CODE(a)		case a : return #a ;

char *getOpName( char *op_name, int op_code)
{
	switch (op_code ) {
	case MAP_OP_SMSREQ:
		strcpy(op_name, "SMSREQ");
		break;
	case MAP_OP_SMSDPP:
		strcpy(op_name, "SMSDPP");
		break;
	case MAP_OP_SMSNOT:
		strcpy(op_name, "SMSNOTI");
		break;
	case MAP_OP_AlertSvcCenter :
		strcpy(op_name, "ALERT_SVC_CENTER");
		break;
	case MAP_OP_MoFwdSM	:
		strcpy(op_name, "MO_FWD_SM");
		break;
	case MAP_OP_MtFwdSM :
		strcpy(op_name, "MT_FWD_SM");
		break;
	case MAP_OP_ReportSM :
		strcpy(op_name, "REPORT_SM");
		break;
	case MAP_OP_InformSvcCenter :
		strcpy(op_name, "INFORM_SVC_CENTER");
		break;
	case MAP_OP_ReadyForSM :
		strcpy(op_name, "READY_FOR_SM");
		break;
	case MAP_OP_SRIforSM :
		strcpy(op_name, "SRI_FOR_SM");
		break;
	case MAP_OP_AnyTimeModification : //added by Charge
		strcpy(op_name, "ATM");
		break;
	default:
		strcpy(op_name, "Unknown!");
		break;
	}

	return op_name;
}

/*
	convert PC+SSN to address string
*/
int pc2addr( int pc, int ssn, unsigned char *addr)
{
	addr[0] = 0x43;
	addr[1] = pc % 256;
	addr[2] = pc / 256;
	addr[3] = ssn;

	return 0;
}


int minTraceHex(
		char *fName, char *funName, int lNum, stAddr *addr, char *cmt,
		unsigned char *s, int len)
{
    int    i;
    char   buf[4096], *ptr = buf;

    if(addr == NULL || fName == NULL)
        return IXERR;

	/*
    if(IsThisMinTrace(addr) != IXOK)
        return IXERR;
		*/

    if(len < 1 || s == NULL)
        return IXERR;

	strcpy( ptr, cmt);
    ptr += strlen(ptr);

	strcpy( ptr, "-----------------------------------------------------------\n");
    ptr += strlen(ptr);

    for(i = 0; i < len; i++)
    {
		sprintf(ptr, "%02X ", (unsigned char)s[i]);
        ptr += strlen(ptr);

        if(i % 20 == 19) {
            sprintf(ptr, "\n");
            ptr+= strlen(ptr);
        }
    }

	strcpy( ptr, "\n-----------------------------------------------------------\n");

    MinTrace( fName, funName, lNum, addr, "%s", buf);

    return IXOK;
}

int minTraceMap( char *fName, char *funName, int lNum, stAddr *addr, 
		unsigned char *paraPtr, int paraLen)
{
    char   buf[4096];

	/*
    if(addr == NULL || fName == NULL)
        return IXERR;
		*/

	/* decode */
	getPrintFormat( sizeof(buf), buf, paraLen, paraPtr);
	printf("%s\n", buf);

	/*
	if ( strlen(buf) > 0) 
		MinTrace( fName, funName, lNum, addr, "%s\n", buf);
		*/

    return IXOK;
}




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


int getUErrorCode(UTcapComponents *comp_ptr, int *err_code)
{
    switch (comp_ptr->errorCode.string[0])
    {
        case 0x81 : *err_code = CC_UERROR_UNRECOG_MIN;
                break;
        case 0x82 : *err_code = CC_UERROR_UNRECOG_ESN;
                break;
        case 0x83 : *err_code = CC_UERROR_MIN_HLR_MISMATCH;
                break;
        case 0x84 : *err_code = CC_UERROR_OP_SEQ_PROBLEM;
                break;
        case 0x85 : *err_code = CC_UERROR_RESOURCE_SHORTAGE;
                break;
        case 0x86 : *err_code = CC_UERROR_OP_NOT_SUPPORTED;
                break;
        case 0x87 : *err_code = CC_UERROR_TRUNK_UNAVAIL;
                break;
        case 0x88 : *err_code = CC_UERROR_PARAM_ERROR;
                break;
        case 0x89 : *err_code = CC_UERROR_SYSTEM_FAILURE;
                break;
        case 0x8a : *err_code = CC_UERROR_UNREG_PARAM_VALUE; 
                break;
        case 0x8b : *err_code = CC_UERROR_FEATURE_INACTIVE;
                break;
        case 0x8c : *err_code = CC_UERROR_MISSING_PARAM;
                break;
        default : *err_code = CC_UERROR_NO_PARAM;
                break;
    }
    return IXOK;
}


/*
	usage : percent of Q
*/
int burstControl( int burst, int suspendMode, int usage )
{

	if( suspendMode )
		burst -= 10;
	else 
	{
		if( usage > 40 )
		{
			if( burst < 150 ) burst = 150;
			burst += usage;
		}
		else if( usage > 10 )
			burst += 10 + usage;
		else
			burst -= 5;
	}

	if( burst < 50 ) 
		burst = 50;
	
	if( burst > 500 ) 
		burst = 500;

	return burst;
}

#define MAX_BURST 1000
int burstControl_new(int burst, int initBurst, int suspendMode, int currQNum )
{
	static int prevQNum = 0, cnt = 0, cnt1 = 0;

	if(prevQNum = 0) {
		prevQNum = currQNum;
	}

	if( suspendMode )
		burst -= 10;
	else 
	{
		if((currQNum - prevQNum) > 50) { /* Queue에 쌓이는 경우 */
			burst += 30;
			uaLog(L_MIN, "Max Burst increase[%d]....", burst);
		} else if(prevQNum - currQNum > 30 ) { /* 쌓이지 않고 남는 경우 */
			if(cnt < 2) cnt++;
			else {
				burst -= 10;
				cnt = 0;
				uaLog(L_MIN, "Max Burst decrease[%d]....", burst);
			}
		}
		else {
			if(cnt1 < 30) cnt1++;
			else if(burst > initBurst && currQNum < 50) {
				burst -= 10;
				cnt1 = 0;
				uaLog(L_MIN, "Max Burst decrease[%d]....", burst);
			}
		}
	}

	if( burst < initBurst )
		burst = initBurst;

	if( burst > MAX_BURST )
		burst = MAX_BURST;

	prevQNum = currQNum;

	return burst;
}
