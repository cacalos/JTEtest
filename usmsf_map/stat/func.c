#include <signal.h>
#include <errno.h>
#include <sys/msg.h>
#include <signal.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdarg.h> 
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include <ua_log.h>
#include <ua_sysdef.h>
#include <ua_syslib.h>

#include <iXGCA.h>
#include <iXstat.h>

#include <iXUtil.h>

#include "stat_func.h"

extern int  	diaCnt;
extern int 		smscCnt;

extern stDIAstat  	gpDiaStat[MAX_SMSC_LIST]; 
extern stSMSCstat  	gpSmscStat[MAX_SMSC_LIST]; 

char            gStattime[30];

#define MAX_LOG_LINE_SIZE       20000

char *statConvTime(time_t time_value)
{
	static char strBuff[64];
	struct tm   lTime;

	localtime_r(&time_value, &lTime);
	strftime(strBuff, 60, "%Y/%m/%u_%H:%M:%S", &lTime);
	
	return strBuff;
}


/* File Write API */
int OpenAllFileFd(char *statfile, char *name)
{
	int         fd;
	char        filename[128];

	/* File FD Open */
	bzero(filename, sizeof(filename));
	sprintf(filename, statfile, name);

	/* open file */
	fd = open( filename, O_RDWR|O_CREAT|O_APPEND, 0666 );
	if ( fd < 0 ) {
		uaLog( L_CRT, "openFile : open(%s) failed : errno = %u %s\n", filename, errno , strerror(errno) );
		return IXERR;
	}

	/* close on exec*/
	/* make it close fd after exec */
	if( (fcntl( fd, F_SETFD, FD_CLOEXEC)) < 0)
		uaLog( L_CRT, "openFile : fcntl(%u) failed : errno = %u\n", fd, errno );

	strcpy(statfile, filename);

	return fd;
}

void NewFileName(char *statfile, char *name)
{
	char 		filename[128];

	/* File FD Open */
	bzero(filename, sizeof(filename));
	sprintf(filename, statfile, name);

	strcpy(statfile, filename);
}

/* Over Write API */
int OpenAllFileFdWithOverWrite(char *statfile, char *name)
{   
	int         fd;
	char        filename[128];

	/* File FD Open */
	bzero(filename, sizeof(filename));
	sprintf(filename, statfile, name);

	/* open file */ 
	fd = open( filename, O_RDWR|O_CREAT|O_TRUNC, 0666 );
	if ( fd < 0 ) { 
		uaLog( L_CRT, "openFile : open(%s) failed : errno = %u %s\n", filename, errno , strerror(errno) );
		return IXERR;
	}           

	/* close on exec*/
	/* make it close fd after exec */ 
	if( (fcntl( fd, F_SETFD, FD_CLOEXEC)) < 0)
		uaLog( L_CRT, "openFile : fcntl(%u) failed : errno = %u\n", fd, errno );

	return fd;
}

int WriteFileFdForStatWithoutN(int fd, char *fmt, ...)
{
	char            *cp;
	char            buf[MAX_LOG_LINE_SIZE];
	va_list         args;
	struct iovec    vec[1];

	if(fd < 0)
		return IXERR;

	cp = buf;

	va_start(args, fmt);
	vsprintf(cp, fmt, args);
	va_end(args);

	bzero(vec, sizeof(vec));
	vec[0].iov_base = buf;
	vec[0].iov_len = strlen(buf);

	return writev(fd, vec, sizeof(vec)/sizeof(struct iovec));
}

int WriteFileFdForStatWithN(int fd, char *fmt, ...)
{
	char            *cp;
	char            buf[MAX_LOG_LINE_SIZE];
	va_list         args;
//	int             len=0;
	struct iovec    vec[2];

	if(fd < 0)
		return IXERR;

	cp = buf;

	va_start(args, fmt);
	vsprintf(cp, fmt, args);
	va_end(args);

	bzero(vec, sizeof(vec));
	vec[0].iov_base = buf;
	vec[0].iov_len = strlen(buf);
	vec[1].iov_base = "\n";
	vec[1].iov_len = 1;

	return writev(fd, vec, sizeof(vec)/sizeof(struct iovec));
}

void ReadMapStat(char *w_statfile, char *statfile)
{
	int             i, ret;
	int             statfd = -1;

	/* SMSC stat */
	if(smscCnt > 0)
	{
		statfd = OpenAllFileFd(w_statfile, "usmsf_map_oper");
		i = 0;

		for( i = 0; i < smscCnt; i++)
		{
			if(strlen(gpSmscStat[i].isdn) > 0)
				WriteFileFdForStatWithoutN(statfd, "%s,", gpSmscStat[i].isdn); 
			else
				continue;

			//OFR
			WriteFileFdForStatWithoutN(statfd, "%u,%u,%u,%u,",
					gpSmscStat[i].mof_send_succ,
					gpSmscStat[i].mof_send_fail,
					gpSmscStat[i].mof_resp_ack,
					gpSmscStat[i].mof_resp_nack + gpSmscStat[i].mof_timeout);

			WriteFileFdForStatWithoutN(statfd, "%u,%u,%u,%u",
					gpSmscStat[i].mtf_recv_succ,
					gpSmscStat[i].mtf_recv_fail,
					gpSmscStat[i].mtf_send_ack,
					gpSmscStat[i].mtf_send_nack + gpSmscStat[i].mtf_timeout);

			WriteFileFdForStatWithoutN(statfd, "\n");
		}
		close(statfd);

		NewFileName(statfile, "usmsf_map_oper");
		rename(w_statfile, statfile);
	}
  
	/* DIA stat */
	if(diaCnt > 0)
	{
		statfd = OpenAllFileFd(w_statfile, "usmsf_map_oper");
		i = 0;

		for( i = 0; i < diaCnt; i++)
		{
			if(strlen(gpDiaStat[i].isdn) > 0)
				WriteFileFdForStatWithoutN(statfd, "%s,", gpDiaStat[i].isdn); 
			else
				continue;

			//OFR
			WriteFileFdForStatWithoutN(statfd, "%u,%u,%u,%u,",
					gpDiaStat[i].ofr_send_succ,
					gpDiaStat[i].ofr_send_fail,
					gpDiaStat[i].ofr_resp_ack,
					gpDiaStat[i].ofr_resp_nack + gpDiaStat[i].ofr_timeout);

			WriteFileFdForStatWithoutN(statfd, "%u,%u,%u,%u",
					gpDiaStat[i].tfr_recv_succ,
					gpDiaStat[i].tfr_recv_fail,
					gpDiaStat[i].tfr_send_ack,
					gpDiaStat[i].tfr_send_nack + gpDiaStat[i].tfr_timeout);

			WriteFileFdForStatWithoutN(statfd, "\n");
		}
		close(statfd);

		NewFileName(statfile, "usmsf_map_oper");
		rename(w_statfile, statfile);
	}

	return;
}



/* Stat Write API */
void StatProc(void *arg)
{
	time_t          timer, now;
	struct tm       ltime;
	char            workFilename[256];
	char            statFilename[256];
	int             period = 10;

	static time_t laststtimer = 0;
	
	struct timeval tvCurrent;
	gettimeofday(&tvCurrent, NULL);
	timer = tvCurrent.tv_sec;

	localtime_r(&timer, &ltime);
	time(&now);

	proc_heartBeat();

	usleep(1000); //이건 왜 먼저하는거야?? 제정신?

	gettimeofday(&tvCurrent, NULL);
	timer = tvCurrent.tv_sec;

	if((timer - laststtimer) >= period)
	{
		uaLog(L_INFO, "Start StatProc()");

		laststtimer = timer;
		timer = timer - period;
		localtime_r(&timer, &ltime);

		bzero(gStattime, sizeof(gStattime));
		strftime(gStattime, 30, "%H:%M:%S", &ltime);

		sprintf(workFilename, "%s/%c%c.%s", getenv("SMS_STAT_DIR"), '%', 's', "ing");
		sprintf(statFilename, "%s/%c%c", getenv("SMS_STAT_DIR"), '%', 's');

		ReadMapStat(workFilename, statFilename);
	}

	gettimeofday(&tvCurrent,NULL);
	timer = tvCurrent.tv_sec;

	return ;
}
