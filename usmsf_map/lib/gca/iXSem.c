
#include <sys/sem.h>

#include <iXtypes.h>
#include <ua_log.h>
#include <iXSem.h>
#include <errno.h>

int    gSemId;
int    gMMSemId;
extern int errno;
extern char gLogModulName[];

/*
int OpenSem()
{
    if((gSemId = semget(IXGCA_SEM_KEY, MAX_SEM_SIZE, 0)) < 0)
    {
		if ( errno == ENOENT)
			return CreateSem();

        uaLog(L_CRT, "Open Semaphore Error key: %d: %s",
            IXGCA_SEM_KEY, strerror(errno));

        return IXERR;
    }

    return IXOK;
}
*/

int P(int id)
{                 
    struct sembuf   p_buf;

    p_buf.sem_num = id;
    p_buf.sem_op  = -1;
    p_buf.sem_flg = SEM_UNDO;

    if(semop(gSemId, &p_buf, 1) == IXERR)
    {
		if (errno == EINVAL)
		{
//			if (OpenSem() != IXOK)
//			{
//				uaLog(L_CRT, "P(gSemId = %d) failed:%s(%d)", 
//					gSemId, strerror(errno), errno);
//				return IXERR;
//			}
		}
        /* 다시 한번더 retry 함 */
        sleep(1);
        if(semop(gSemId, &p_buf, 1) == IXERR)
        {
            uaLog(L_CRT, "P(gSemId = %d) failed:%s(%d)", 
                gSemId, strerror(errno), errno);
            return IXERR;
        }
        else
            return IXOK;
    }
    else
        return IXOK;
}


int V(int id)
{
    struct sembuf   v_buf;

    v_buf.sem_num = id;
    v_buf.sem_op  = 1;
    v_buf.sem_flg = SEM_UNDO;

    return ((semop(gSemId, &v_buf, 1) < 0) ? IXERR : IXOK);
}

int CreateSem()
{
    int             i;

    if((gSemId = semget(IXGCA_SEM_KEY, MAX_SEM_SIZE, 0666|IPC_CREAT)) < 0)
    {
        uaLog(L_CRT, "Create Semaphore Error key: %d:%s",
            IXGCA_SEM_KEY, strerror(errno));
        return IXERR;
    }
    else
    {
        for(i = 0; i < MAX_SEM_SIZE; i++)
        {
            if(semctl(gSemId, i, SETVAL, 1) == IXERR)
            {
                uaLog(L_CRT, "CreateSem:%s", strerror(errno));
                return IXERR;
            }
        }
    }
	return IXOK;
}


int RmSem()
{
    return(semctl(gSemId, 0, IPC_RMID, (struct semid_ds *)0));
}
