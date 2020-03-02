
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/shm.h>
#include <iXtypes.h>
#include <iXGCA.h>
#include <iXSem.h>


#include <ua_log.h>
#include <ua_sysdef.h>
#include <ua_syslib.h>

stGCA   *gpstGCA=0;

int CreateGCA()
{
	int    ret;

	if(shmget(IXGCA_SHM_KEY, sizeof(stGCA), 0666|IPC_CREAT|IPC_EXCL) < 0)
	{
		uaLog( L_MAJ,  "shmget error key=0x%x size=%d :%s",
				IXGCA_SHM_KEY, sizeof(stGCA), strerror(errno));
		return IXERR;
	}
/*
	if((ret = CreateSem()) < 0)
	{
		uaLog( L_MAJ,  "Create semaphore error, err:%d", ret);
		return IXERR;
	}
*/
	if(OpenGCA() != IXOK)
	{
		uaLog( L_MAJ,  "shmat error:%s", strerror(errno));
		/* perror("Open GCA: shmat error"); */
		return IXERR;
	}

	bzero(gpstGCA, sizeof(stGCA));
	uaLog( L_MAJ,  "Creating GCA & Openning GCA Success.......");
	return IXOK;
}

int ClearGCA()
{
    bzero((void *)gpstGCA, sizeof(stGCA));
    return IXOK;
}
                       
int RmShm(int shmid)
{
    int     ret;

    if((ret = shmctl(shmid,IPC_RMID,(struct shmid_ds *)0)) < 0)
        uaLog(L_CRT, "reshm error:%s", strerror(errno));

    return ret;
}

/* wings 가입자 테이블 추가 */
int OpenGCA()
{
    int    	ret, flag;

	gpstGCA = shm_create( "IXGCA", sizeof(stGCA), &flag);
	if ( gpstGCA == (void*)-1) {
		uaLog(L_CRT, "Fail to create GCA SHM");
		return IXERR;
	}

	if ( flag ) {
		/* shm is created now */
		memset( gpstGCA, 0, sizeof(stGCA));
	}


#if 0
	if ( sms_openStatShm() < 0) {
		uaLog( L_CRT, "sms_openStatShm() failed");
		return IXERR;
	}
#endif


	OpenAllShm();

	
    return IXOK;
}

int OpenGCAShm()
{
	int    ret;

	if((ret = shmget(IXGCA_SHM_KEY, sizeof(stGCA), 0)) < 0) {
		uaLog( L_MAJ,  "shmget error key=0x%x size=%d :%s",
				IXGCA_SHM_KEY, sizeof(stGCA), strerror(errno));
	}

	return ret;
}

/* 										*/
/*  05/10/12 sjkim add 					*/
/*  GCA Open by "gcactrl -c"			*/
/*  this func init VAD, SCP stat value  */
/*                                     	*/    
int OpenGCAByCtrl()
{
    int    	ret, flag;

	gpstGCA = shm_create( "IXGCA", sizeof(stGCA), &flag);
	if ( gpstGCA == (void*)-1) {
		uaLog(L_CRT, "Fail to create GCA SHM");
		return IXERR;
	}

	if ( flag ) {
		/* shm is created now */
		memset( gpstGCA, 0, sizeof(stGCA));
	}

#if 0
	if ( sms_openStatShm() < 0) {
		uaLog( L_CRT, "sms_openStatShm() failed");
		return IXERR;
	}
#endif


	OpenAllShm();

	return IXOK;

}

void Display_Error(char *pApi)
{
	uaLog(L_CRT, "%s open fail" ) ;
	exit(-1) ;
}

int OpenAllShm()
{
	int shmid = OpenGCAShm();

	if(shmid < 0)
	{
		return CreateGCA();
	}

	if((gpstGCA = (stGCA *)shmat( shmid, (char *)0, 0)) == (stGCA *)-1)
	{
		uaLog( L_MAJ,  "Open GCA:shmat error:%s",
				strerror(errno));
		return IXERR;
	}

//	if( OpenSem() == IXERR )        Display_Error("Sem") ;

//    OpenSem();
    OpenTraceShm();

    return IXOK;
}






/* wings 가입자 테이블 추가 */
int CloseGCA()
{
    int ret;
    
    ret = shmdt(gpstGCA);
    
    if(ret != 0)
    {
        uaLog(L_CRT, "GCA close shmdt fail:%s",
            strerror(errno));
        return IXERR;
    }

    return IXOK;
}


stGCA           *GetGCAp()         { return gpstGCA;                }
stTraceShm      *GetTracep()       { return &(gpstGCA->trace);      }

