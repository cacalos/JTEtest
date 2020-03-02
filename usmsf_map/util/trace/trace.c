
#include <signal.h>
#include <unistd.h>
#include <ctype.h>
//#include <isam.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <iXGCA.h>
#include <iXTrace.h>

//#include <ua_newmmdb.h>
#include <ua_sysdef.h>
#include <ua_macro.h>
#include <ua_ompib.h>
#include <iXLog.h>

#include <stdlib.h>

int gIndex;
char ptFname[256];

int             gLogId;


void sigHandler(int sig);
void printTrace(void);
void EndProc(int sigint);
int procGlobalTrace(int addOnlyFlag);
int procMdnTrace(int argc, char **argv, int argind, int addOnlyFlag);
int showGlobTrace(int addOnlyFlag);
int showTrace( char *min, int addOnlyFlag);

void sigHandler(int sig)
{
	printf("\nSTOP>Global Trace Ends\n");
	resetGlobalTrace();

//	if(strlen(ptFname) > 0)
//	    unlink(ptFname);

	exit(0);
}

void swaptime(time_t org_time, char *time_str,int start)
{
	struct tm *tm_ptr;
	int i;

	i = org_time;
	org_time = i - (start * 24 * 3600) ;
	tm_ptr = localtime(&org_time);

	sprintf(time_str, "%d/%.2d/%.2d %.2d:%.2d:%.2d",
			tm_ptr->tm_year+1900,
			tm_ptr->tm_mon+1,
			tm_ptr->tm_mday,
			tm_ptr->tm_hour,
			tm_ptr->tm_min,
			tm_ptr->tm_sec);
}

void printTrace()
{
    int 			i, diff;
    stTraceShm   	msg;    
	time_t			now;
	char			tmptime[20];

    bzero((void *)&msg,sizeof(stTraceShm));    
    GetTraceMin(&msg);
	now = time(0);

    if(msg.reg_count ==0)
    {
        printf("\nFAIL> No Trace Address !!!\n");
		return;
    }
    else
    {
		printf(">> MAP TRACE INFO (%d) <<\n", msg.reg_count);
		printf("-------------------------------------------------------------------------\n");
		printf(" No.  Level  Until                 NUMBER\n");
		printf("-------------------------------------------------------------------------\n");

        for(i = 0; i < msg.reg_count; i++)
		{
			memset(&tmptime, 0, 20);
			swaptime(msg.trace[i].time, tmptime, 0);
			if ( (diff = msg.trace[i].time - now) > 0) 
			{
				printf(" %2d   %5d  %19s   %s\n",
					i, msg.trace[i].level, tmptime, msg.trace[i].addr.min);
			}
		}
        
		printf("-------------------------------------------------------------------------\n");
    }
}    



void EndProc(int sigint)
{
    exit(0);
}

char *usage = "Usage: trace [MDN [duration [level]] | off {all | index | MDN | proc}]\n\
  ex) trace 821031112222 10    : trace '821031112222' for 10 minutes\n\
      trace off 821031112222   : trace off '821031112222' \n\
      trace -p 821031112222    : trace stdout stdout\n";
  //trace -p 821031112222    : Print Trace Info \n\

int main(int argc, char *argv[])
{
    int             i, argind;
    int             index, addOnlyFlag;
    stTraceShm      msg;
	stAddr          addr;
	addOnlyFlag = 0;

	char            *env, fname[512];

	GET_SYS_HOME_ENV(env);
	sprintf( fname, "%s/log/%s/%s", env, _MODULE_NAME, _MODULE_NAME);
//	sprintf( fname, "%s/%s/%s", env, _MODULE_NAME, _MODULE_NAME);



	gLogId = LOG_open( fname,
			LOG_MODE_CHANGE_DAILY | LOG_FORMAT_DATE | LOG_FORMAT_TIME_MSEC |
			LOG_FORMAT_CATEGORY );

	if ( gLogId < 0) {
		fprintf( stderr, "LOG_open: E=%d", gLogId);
		return -1;
	}
	LOG_isOn( gLogId, 0);


	signal(SIGINT, sigHandler);

   if(OpenGCA() != IXOK)
    {
        fprintf(stderr, "OpenGCA fail!!\n");
        exit(0);
    }

    OpenTraceShm();

	memset((void*)ptFname, 0x00, sizeof(ptFname));

    if(argc == 1)
    {
        printTrace();

        exit(0);
    }
                
    if(strcasecmp(argv[1], "off") == 0 || strcmp(argv[1], "OFF") == 0)
    {
        if(argc != 3)
        {
			printf("%s", usage);
            exit(0);
        }
        
        // -------- Off All ----  --------------------------
        if(strcmp(argv[2], "all") == 0 || strcmp(argv[2], "ALL") == 0)
        {
            InitTraceShm();
			printf("\nStop ALL MAP TRACE\n");
        }
        // -------- Off by Index  --------------------------        
		else if(atoi(argv[2]) >= 0 && atoi(argv[2]) < 5) // index
        {
			char mdn[32];
            index = IsExistIndex(atoi(argv[2]));     
            if(index >= 0) {
                ClearTrace_IndexShm(index, mdn);
				printf("\nSUCCESS>Stop MAP TRACE\n  MDN = %s\n", mdn);
			}
            else
                printf("FAIL> Trace index %d does not found\n", index);
        }
        // -------- Off by Addr  --------------------------        
        else if(strcmp(argv[2], "proc") == 0 || strcmp(argv[2], "PROC") == 0) {
			resetGlobalTrace();
			printf("\nSUCCESS>Stop PROC TRACE\n\n");
		}
		else
        {
			char mdn[32];

            strcpy(addr.min, argv[2]);
            addr.len = strlen(addr.min);
            addr.ton = TON_NATIONAL;
			addr.npi = NPI_E164;

            index = IsExistAddr(addr.min);    
            if(index >= 0)
            {
                ClearTrace_IndexShm(index, mdn);
				printf("\nSUCCESS>Stop MAP TRACE\n  MDN = %s\n", addr.min);
            }
			else 
				printf("\nFAIL>\nMDN %s NOT FOUND\n", addr.min);
        }

        exit(0);
    }

	if ( strcmp( argv[1], "-a") == 0) {
		/* -a flag가 붙으면 trace할 번호를 추가만 하고 tail을 걸지는 않는다
		 * */
		addOnlyFlag = 1;
		argind = 2; 
	}
	else if ( strcmp(argv[1], "-p") == 0) {

		argind = 2; 
	}
	else argind = 1; 

	if( argc > argind + 3)
	{
		printf("%s", usage);
		exit(0);
	}

	mkdirs("/tmp/trace", 0755);

	if(strcmp(argv[1], "proc") == 0) {
		printf("\nSUCCESS>Global Trace Begins\n");
		procGlobalTrace(addOnlyFlag);
	}
	else  procMdnTrace(argc, argv, argind, addOnlyFlag);
}

int procGlobalTrace(int addOnlyFlag)
{
	setGlobalTrace();
    showGlobTrace(addOnlyFlag);
	return 0;
}

int procMdnTrace(int argc, char **argv, int argind, int addOnlyFlag)
{
    char            buf[256];
	int				level, i, duration;
    stAddr          addr;

	/* get MDN number */
    if(strlen(argv[argind]) > DEFAULT_ADDR_LEN)
    {
        printf("Invalid ADDR: %s\n", argv[argind]);
		printf("%s", usage);
        exit(0);
    }

    strcpy(addr.min, argv[argind]);
    addr.len = strlen(addr.min);
    addr.ton = TON_NATIONAL;
	addr.npi = NPI_E164;

    for(i = 0; i < addr.len; i++)
    {
        if(!isdigit(argv[argind][i]) && argv[argind][i] != '#' &&
			argv[argind][i] != '*')
        {
            printf("Invalid ADDR: %s\n", addr.min);
            printf("%s", usage);
            exit(0);
        }
    }

	/* get duration */
	if ( argc > argind+1)
		duration = atoi(argv[argind+1]);
//	else duration = time(0) + 60;	/* default trace duration : 60 second */
	else duration = 3600;	/* default trace duration : 60 second */

	/* get level */
	if ( argc > argind+2)
		level = atoi(argv[argind+2]);
	else level = 1;	/* default trace level : 1 */

//    if ( ProcessStoreAddr(addr.min, duration*60, level) != IXOK) {
	printf("Duration : %d\n", duration);
    if ( ProcessStoreAddr(addr.min, duration, level) != IXOK) {
		printf("FAIL> Trace table is full.\n");
		exit(0);
	}

	if (strcmp(argv[1], "-p") == 0 ) {
			printf("\nSUCCESS>\nStart MAP TRACE\n\
MDN      = %s\n\
DURATION = %d seconds\n\
LEVEL    = %d\n", addr.min, duration, level);

			signal(SIGINT,  EndProc);
			signal(SIGTERM, EndProc);

			showTrace( addr.min, addOnlyFlag);
	}

    EndProc(0);
	return 0;
}

int showGlobTrace(int addOnlyFlag)
{
	char fname[128];
	FILE *fp = NULL;
	struct stat sinfo;
	int fsize;
	char buf[128];
	char *env;
	time_t now;
	struct tm timer;

	GET_SYS_HOME_ENV( env);

	now = time(0);
	localtime_r( &now, &timer);

    sprintf( fname, "%s/log/maptrc/%s", env, GLOBAL_TRACE_FILE);

    strcpy(ptFname, fname);

#if 0
	// v400 removed by jhjung 
	if ( stat( fname, &sinfo) < 0) {
		/* make file */
		ua_mkdirWithFilePath( fname);

		if ((fp = fopen( fname, "w")) == NULL) {
			printf("Fail to open file %s errno=%s\n", 
				fname, strerror(errno));
			return -1;
		}
		fclose(fp);
		fp = NULL;

		printf("[INFO] open file fname %s\n", fname);
	}
#endif

	/* v400 added by jhjung  */
	if ( stat( fname, &sinfo) < 0) {
		/* make file */
		ua_mkdirWithFilePath( fname);
	}

	if ((fp = fopen( fname, "w")) == NULL) {
		printf("Fail to open file %s errno=%s\n", 
				fname, strerror(errno));
		return -1;
	}
	fclose(fp);
	fp = NULL;
	/* end add */

	if ( addOnlyFlag) {
		return 0;
	}

	while(1) {
		if ( stat( fname, &sinfo) >= 0) {

			/* open file */
			if ( fp == NULL) {
				if ((fp = fopen( fname, "r")) == NULL) {
					printf("Fail to open file %s errno=%s\n", 
						fname, strerror(errno));
					return -1;
				}

				/* get initial size */
				fsize = sinfo.st_size;
				fseek( fp, fsize, SEEK_SET);
			}
			else if ( sinfo.st_size > fsize) {
				/* read file line by line */
				while( fgets( buf, sizeof(buf), fp) != NULL) {
					printf("%s", buf);
				}
			}
		}

		sleep(1);
	}
}

int showTrace( char *min, int addOnlyFlag)
{
	char fname[128];
	FILE *fp = NULL;
	struct stat sinfo;
	int fsize;
	char buf[128];
	char *env;
	time_t now;
	struct tm timer;
//    char           *homePtr;

//	GET_SYS_HOME_ENV( env);
	env = getenv("TRACE_HOME_ENV_NAME");
	if ( env == NULL) {
		printf("Get Env Fail");
		return;
	}


	now = time(0);
	localtime_r( &now, &timer);
/*
    sprintf( fname, "%s/log/maptrc/%02d/%02d/trc_%s.%04d%02d%02d", 
		env, timer.tm_mon+1, timer.tm_mday, min, 
		timer.tm_year+1900, timer.tm_mon+1, timer.tm_mday);
*/
   sprintf( fname, "%s/%04d%02d%02d_%s", 
		env,timer.tm_year+1900, timer.tm_mon+1, timer.tm_mday, min);

	if ( stat( fname, &sinfo) < 0) {
		/* make file */
		ua_mkdirWithFilePath( fname);

		if ((fp = fopen( fname, "w")) == NULL) {
			printf("Fail to open file %s errno=%s\n", 
				fname, strerror(errno));
			return -1;
		}
		fclose(fp);
		fp = NULL;
	}

	if ( addOnlyFlag) {
		return 0;
	}

	while(1) {
		if ( stat( fname, &sinfo) >= 0) {

			/* open file */
			if ( fp == NULL) {
				if ((fp = fopen( fname, "r")) == NULL) {
					printf("Fail to open file %s errno=%s\n", 
						fname, strerror(errno));
					return -1;
				}

				/* get initial size */
				fsize = sinfo.st_size;
				fseek( fp, fsize, SEEK_SET);
			}
			else if ( sinfo.st_size > fsize) {
				/* read file line by line */
				while( fgets( buf, sizeof(buf), fp) != NULL) {
					printf(" %s", buf);
				}
			}
		}

		sleep(1);
	}
}


int mkdirs(const char *path, mode_t mode)
{
	char tmp_path[2048];
	const char *tmp = path;
	int len = 0;
	int ret;

	if(path == NULL || strlen(path) >= 2048)
	{
		return -1;
	}

	while((tmp == strchr(tmp, '/')) != NULL ) {
		len = tmp -path;
		tmp++;
		if(len == 0) {
			continue;
		}

		strncpy(tmp_path, path, len);
		tmp_path[len] = 0x00;

		if((ret = mkdir(tmp_path, mode)) == -1) {
			if(errno != EEXIST) {
				return -1;
			}
		}
		
	}

	return mkdir(path, mode);

}


