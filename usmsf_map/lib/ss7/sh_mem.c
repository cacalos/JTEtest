
#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

#include <iXtypes.h>
#include <ua_log.h>

#include <errno.h>

//#define SHM_KEY        (0x48900)
#define SHM_KEY        (0x79455) 
#define SHM_PERM       (0770)


int create_shm(int size)
{
    int        shmid;

    shmid = shmget(SHM_KEY, size, (SHM_PERM | IPC_CREAT));
    if(shmid < 0)
        uaLog(L_MAJ, "shm with key %d creat fail !", SHM_KEY);
    uaLog(L_MAJ, "shm with key %d created!", SHM_KEY);
    return shmid;
}


int remove_shm(int shmid)
{
    int        res;

    res = shmctl(shmid, IPC_RMID, 0);
    if(res < 0)
    {
        uaLog(L_MAJ, "shm (id=%d) remove fail !", shmid);
        return -1;
    } 
    uaLog(L_MAJ, "shm (id=%d) removed !", shmid);
    return res;
}


int get_shm_id()
{
    int        shmid;
    int        res;

    shmid = shmget(SHM_KEY, 0, 0);
    if(shmid < 0)
    {
        uaLog(L_MAJ, "shm with key %d NOT found!", SHM_KEY);
        return -1;
    }
    uaLog(L_MAJ, "shm with key %d found. ID= %d !",
        SHM_KEY, shmid);

    return shmid;
}


char *use_shm(int shmid)
{
    char        *ptr;

    ptr = (char *)shmat(shmid, 0, 0);
    if(ptr == (char *)-1)
    {
        uaLog(L_MAJ, "shm attach fail %d !"  , errno);
        return (char *)0;
    } 
    uaLog(L_MAJ, "shm (addr=%X) attached!", ptr);
    return ptr;
}


int release_shm(char *ptr)
{
    int        res;

    res = shmdt(ptr);
    if(res < 0)
    {
        uaLog(L_MAJ, "shm dettach fail !");
        return IXERR;
    } 
    uaLog(L_MAJ, "shm (addr=%X) dettached!", ptr);
    return IXOK;
}

