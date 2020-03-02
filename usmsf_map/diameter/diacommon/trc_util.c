#include <uxlib/ux_string.h>
#include <uxlib/ux_log.h>

#include <udia/udia_avps.h>

#include "uxcutor/uxc_trace.h"
#include "uxcutor/uxc_xcutor.h"
#include "trc_util.h"

#define MAX_TRC_BUFFER_SIZE 20480
#define MAX_LOG_PRINT_SIZE	2048
#define DEF_LOG_DEFAULT_FMT	UDIA_MSGFMT_DEFAULT|UDIA_MSGFMT_FULLCMD
#define DEF_AVP_DEFAULT_FMT	DEF_LOG_DEFAULT_FMT|UDIA_MSGFMT_AVPCODE|UDIA_MSGFMT_AVPLEN
#define DEF_AVP_HEXA_FMT	DEF_AVP_DEFAULT_FMT|UDIA_MSGFMT_HEXVAL

static int _sprint_avplist(udia_avplist_t *avplist, char *buffer, char *rpui, int size);
static int _sprint_avp(udia_avp_t *avp, int level, int ntabs, char* buffer, int size);


int set_trace_flag(char *trc_num, int is_on)
//int set_trace_flag(uxc_worker_t *worker, char *trc_num, int is_on)
{
	uxc_xcutor_t 		*xcutor = uxc_xcutor_instance();
	uxc_workermgr_t 	*wkmgr = uxc_xcutor_get_wkmgr(xcutor);
	uxc_worker_t 		*worker = uxc_workermgr_current_worker(wkmgr);
	uxc_tracer_t* 		tracer = uxc_worker_get_tracer(worker);

	if(is_on) 
		uxc_tracer_turn_on(tracer, trc_num, UX_FALSE, UX_LOG_LEVEL_TRACE);
	else
		uxc_tracer_turn_off(tracer);

	return 0;
}

int is_trace_on()
{
	uxc_xcutor_t 		*xcutor = uxc_xcutor_instance();
	uxc_workermgr_t 	*wkmgr = uxc_xcutor_get_wkmgr(xcutor);
	uxc_worker_t 		*worker = uxc_workermgr_current_worker(wkmgr);
	uxc_tracer_t* 		tracer = uxc_worker_get_tracer(worker);

	return uxc_tracer_is_trace( tracer);
}

void ex_dia_msg_trc(char *src_file, int src_line, uxc_worker_t *worker, udia_msg_t *stackmsg)
{
	char 	buffer[MAX_TRC_BUFFER_SIZE];
	int		size, len = 0, rv;

	size = MAX_TRC_BUFFER_SIZE;

	len = sprintf(buffer,    "\n-----------------------------------------------------------------------------------------------\n");
	len += udia_msg_sprint_hdr( stackmsg, DEF_LOG_DEFAULT_FMT, buffer+len, size-len);
	rv = snprintf( buffer+len, (size > len) ? size-len : 0, "\n");
	len += (rv >= 0) ? rv : 1;
	len += sprintf(buffer+len, "-----------------------------------------------------------------------------------------------\n");
	len += udia_avplist_sprint( udia_msg_get_root(stackmsg), DEF_LOG_DEFAULT_FMT, 3, buffer+len, size-len);
	len += sprintf(buffer+len, "\n-----------------------------------------------------------------------------------------------\n");

	uxc_trace(UX_LOG_DEFAULT, (UXC_TRACE_LEVEL(0) | UX_LOG_LEVEL_TRACE), UX_DFLT_USER_LEVEL, src_file, src_line, "%s", buffer);
}

void sprint_dia_msg_to_buff(char *buffer, char *rpui, int buffer_size, udia_msg_t *stackmsg)
{
	int 	len = 0, rv;
	int		size = buffer_size;

	len += udia_msg_sprint_hdr( stackmsg, DEF_LOG_DEFAULT_FMT, buffer+len, size-len);
	rv = snprintf( buffer+len, (size > len) ? size-len : 0, "\n");
	len += (rv >= 0) ? rv : 1;
	len += _sprint_avplist( udia_msg_get_root(stackmsg), buffer+len, rpui, size-len);
}

void sprint_dia_avp_to_buff(char *buffer, char *rpui, int buffer_size, udia_msg_t *stackmsg)
{
	int 	len = 0;
	int		size = buffer_size;

	len += _sprint_avplist( udia_msg_get_root(stackmsg), buffer+len, rpui, size-len);
}

static int _sprint_avplist(udia_avplist_t *avplist, char *buffer, char *rpui, int size)
{
	int wlen, j; 
	int level	= 2;
	int ntabs	= 0;
	udia_avp_t *avp;
	
	if(avplist == NULL) {
		udia_log(UXL_MIN, "udia_avplist_sprint : avplist is NULL\n");
		return -1;
	}

	avp = udia_avplist_first(avplist);
	if(size < 0) size = 0;
	wlen = 0;
	j = 0;
	while( avp && j < udia_avplist_get_count(avplist) ) {
		const char *avp_name = udia_avp_get_name(avp);

		if( strcmp( "SM-RP-UI", avp_name) != 0 )
		{
			if( wlen && wlen < size ) buffer[wlen++] = '\n';
			wlen += _sprint_avp(avp, level, ntabs, buffer+wlen, size-wlen);
			//wlen += udia_avp_sprint(avp, level, ntabs, buffer+wlen, size-wlen);
		}
		else
		{
//			_sprint_avp(avp, level, ntabs, rpui, size); //2019.06.19 modified by seo
			_sprint_avp(avp, level, ntabs, buffer, size);
		}

		avp = udia_avplist_next(avplist, avp);
		++j;
	}
	if( avp && j >= udia_avplist_get_count(avplist)) {
		udia_log(UXL_MIN, "Detected infinite loop!! - avplist may be broken."
				" avp=%s,%p", 
				(udia_avp_get_avpdef(avp) && udia_avp_get_name(avp)) ? udia_avp_get_name(avp)  : "null",
				avp);
	}

	if( wlen < size ) buffer[wlen] = '\0';
	else if(size > 0) buffer[size-1] = '\0';

	return wlen;
}

static int _sprint_avp(udia_avp_t *avp, int level, int ntabs, char* buffer, int size)
{
	int             i = 0, avptype, avpcnt, wlen = 0;
	int             avp_len = udia_avp_get_buflen(avp);
	const char      *avp_name = udia_avp_get_name(avp);
	udia_avphdr_t   *hdr = udia_avp_get_hdr(avp);

	wlen += udia_util_sprint_tabs(buffer, size, ntabs, 0); // todo

	if( level >= 3 ) {
		wlen += snprintf(buffer+wlen, (size > wlen) ? size-wlen : 0,
				"%-30s (%5u) (%5u,0x%02x) [h:%3u,d:%3d]",
				avp_name, hdr->code, hdr->vendor_id,
				(int)hdr->flag.value, hdr->length, avp_len);
	} else {
		if( udia_avp_get_avpdef(avp) ) {
			wlen += snprintf(buffer+wlen, (size > wlen) ? size-wlen : 0, "%-30s", avp_name);
		} else {
			wlen += snprintf(buffer+wlen, (size > wlen) ? size-wlen : 0,
					"%-30s (%5u) (%5u), ", avp_name, hdr->code, hdr->vendor_id);
		}
	}

	avptype = udia_avp_get_type(avp);
	if(avptype == UDIA_AVPTYPE_GROUPED)
	{
		udia_avplist_t *sublist;

		if(udia_avp_get_avplist(avp, &sublist) == UDIA_SUCCESS)
		{
			udia_avp_t *subavp = udia_avplist_first(sublist);

			if(udia_avp_get_code(avp) == UDIA_AVP_EXPERIMENT)
				wlen += _sprint_avp(subavp, level, ntabs+1, buffer+wlen, size-wlen);
			else
			{
				avpcnt = udia_avplist_get_count(sublist);
				wlen += snprintf(buffer+wlen, (size > wlen) ? size-wlen : 0, " { ");
				for(i = 0; i < avpcnt && subavp; i++)
				{
					wlen += snprintf(buffer+wlen, (size > wlen) ? size-wlen : 0, "\n");
					wlen += _sprint_avp(subavp, level, ntabs+1, buffer+wlen, size-wlen);
					subavp = udia_avplist_next(sublist, subavp);
				}
				wlen += udia_util_sprint_tabs(buffer+wlen, size, ntabs, 0); // todo
				wlen += snprintf(buffer+wlen, (size > wlen) ? size-wlen : 0, " } ");
			}
		}

	}
	else
	{
		wlen += snprintf(buffer+wlen, (size > wlen) ? size-wlen : 0, " = ");
		wlen += udia_avp_sprint_data(avp, level, ntabs, buffer+wlen, size-wlen);
	}

	return wlen;
}
#if 0
static int _sprint_spl_avp(udia_avp_t *avp, int level, int ntabs, char* buffer, int size)
{
	int wlen = 0;
	const char *avp_name = udia_avp_get_name(avp);

	if( strncmp("User-Identifier", avp_name, 15) == 0
			|| strncmp( "SM-RP-UI", avp_name, 10) == 0 )
		wlen += udia_avp_sprint(avp, DEF_AVP_HEXA_FMT, ntabs, buffer+wlen, size-wlen);
	else
		wlen += udia_avp_sprint(avp, DEF_AVP_DEFAULT_FMT, ntabs, buffer+wlen, size-wlen);

	return wlen;
}
#endif 
