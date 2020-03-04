#include "diaib.h"
#include "trc_util.h"
#include "diaib_trace.h"

#define DIAIB_COMPLETE_LINE	"-------------- COMPLETED"

static void print_call_info(stAddr* target_addr, char* trc_h, stAddr *orig, stAddr *imsi, char* orig_node);
static void print_call_result(stAddr* target_addr, char* trc_h, stAddr *orig, stAddr *imsi, int cc_code, char *orig_node);
static void print_call_avp(udia_msg_t *stackmsg, stAddr *target_addr);
//static void print_octet_str(stAddr* target_addr, char *name, int len, char *oct_str);

void print_send_call_trace(udia_msg_t *dia_msg, stAddr *orig, stAddr *imsi)
{
	char        *dest_host;
	udia_err_t  err;

	if(is_trace_on()) {
		dest_host = udia_msg_get_dest_host(dia_msg, &err);

		if(orig != NULL)
		{
			print_call_info( orig, TRC_DIA_SEND_MSG_HEAD, orig, imsi, dest_host );
			print_call_avp( dia_msg, orig );
		}

		if( imsi != NULL ) {
			print_call_info( imsi, TRC_DIA_SEND_MSG_HEAD, orig, imsi, dest_host );
			print_call_avp( dia_msg, imsi);
		}
	}

}

void print_rcv_call_trace(udia_msg_t *dia_msg, stAddr *orig, stAddr *imsi, int cc_code)
{
	char        *orig_host;
	udia_err_t  err;

	if(is_trace_on()) {
		orig_host = udia_msg_get_orig_host(dia_msg, &err);

		if(orig != NULL)
		{
			print_call_result( orig, TRC_DIA_RECV_MSG_HEAD, orig, imsi, cc_code, orig_host );
			print_call_avp( dia_msg, orig );
		}

		if(imsi != NULL ) {
			print_call_result( imsi, TRC_DIA_RECV_MSG_HEAD, orig, imsi, cc_code, orig_host);
			print_call_avp( dia_msg, imsi );
		}
	}

}

void set_addr_mintrace_flag(stAddr *dest, stAddr *orig, stAddr *imsi)
{
    /* Set Trace flag */
    if( dest && IsThisMinTrace( dest ) > 0 )
        set_trace_flag(dest->min, 1);
    else if( orig && IsThisMinTrace( orig ) > 0 )
        set_trace_flag(orig->min, 1);
    else if( imsi && IsThisMinTrace( imsi ) > 0 )
        set_trace_flag(imsi->min, 1);
    else
        set_trace_flag(NULL, 0);
}

static void print_call_info(stAddr* target_addr, char* trc_h, stAddr *orig, stAddr *imsi, char* orig_node)
{
    ux_mutex_t          *trc_mutex = get_diaib_trc_mutex();

    ux_mutex_lock(trc_mutex);
    MinTrace( LPOS, target_addr,
"\n\
%s\n\
\tNODE        :\t[%s]\n\
\tIMSI        :\t[%s]\n\
\tOrig Addr   :\t[%s]",
        trc_h, orig_node, imsi->min, orig->min);
    ux_mutex_unlock(trc_mutex);
}

static void print_call_result(stAddr* target_addr, char* trc_h, stAddr *orig, stAddr *imsi, int cc_code, char *orig_node)
{
    ux_mutex_t          *trc_mutex = get_diaib_trc_mutex();

    ux_mutex_lock(trc_mutex);
	MinTrace( LPOS, target_addr,
"\
%s\n\
\tNODE        :\t[%s]\n\
\tIMSI        :\t[%s]\n\
\tOrig Addr   :\t[%s]\n\
\tResult      :\t[%s(%d)]",
			trc_h, orig_node, imsi->min, orig->min,
			cc_code == 0 ? "S" : "F", cc_code);
    ux_mutex_unlock(trc_mutex);
}

static void print_call_avp(udia_msg_t *stackmsg, stAddr *target_addr)
{
	char        trc_buff[MAX_TRC_BUFFER_SIZE];
    const char  *sep_line = "--------------------------------------------------------------------------------------------------";
    ux_mutex_t  *trc_mutex = get_diaib_trc_mutex();

#define MAX_PRINT_BUFFER_SIZE   2400
    ux_mutex_lock(trc_mutex);
	sprint_dia_msg_to_buff( trc_buff, NULL, MAX_PRINT_BUFFER_SIZE, stackmsg);
    MinTrace( LPOS, target_addr, "\t%s\n\t%s\n\t%s", sep_line, trc_buff, sep_line);
    ux_mutex_unlock(trc_mutex);
}
#if 0
static void print_octet_str(stAddr* target_addr, char *name, int len, char *oct_str)
{
	int			i;
	char		buff[MAX_OCTET_BUFFER_SIZE];
	char		*ptr = buff ;
	const char 	*sep_line = "------------------------------------------------------------";
	
	for( i = 0; i < len; i++){
		if( i > 0 && (i % 20) == 0 ){
			sprintf(ptr, "\n");
			ptr += strlen(ptr);
		}

		sprintf( ptr, "%02X ", (unsigned char)oct_str[i] );
		ptr += strlen(ptr);
	}
	
	MinTrace( LPOS, target_addr, "\n%s\n%s\n%s\n%s", 
			name, sep_line, buff, sep_line); 
}
#endif
