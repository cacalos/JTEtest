#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include <ua_log.h>

//#include <iXMtQ.h>
#include <smsf_msg.h>
#include <iXSem.h>

int         mtQid = MSGQUEUE_INIT_VALUE;
key_t       mtKey = MSGQUEUE_INIT_VALUE;
int         sndMt = sizeof(smsf_msg_t);
int         rcvMt = sizeof(smsf_msg_t)-sizeof(long);

void OpenMtQ()
{
    mtKey = msgq_getProcKey( "SIGMT");
    if ( mtKey < 0) {
        uaLog( L_CRT, "MSG Q KEY not found for SIGMT");
        return ;
    }

    mtQid = msgget( mtKey, 0666 | IPC_CREAT | IPC_EXCL);
    if(mtQid < 0)
    {
        if(errno == EEXIST)
        {
            /* À½õµ */
            mtQid = msgget( mtKey, 0);
        }
    }

    if(mtQid < 0)
    {
        uaLog(L_MAJ,
                "OpenMtQ : cannot open msg Q of server.");
        perror("msgget");
        return ;
    }
}

int GetMtMsg(smsf_msg_t *msg)
{
    int         i, ret;

    for(i = 0; i < MSGSEND_MAX_RETRY; i++)
    {
        if(msgrcv(mtQid, msg, rcvMt, 0, IPC_NOWAIT | MSG_NOERROR ) < 0)
        {
            if(errno == ENOMSG)      /* there's no message */
                return NOTOK;
            else
            {
                uaLog(L_CRT,  "FATAL: IN msg msgrcv E=%d", errno);
                return IXERR;
            }
        }
        else
            break;
    }

    return IXOK;
}

int GetMtQLen()
{
    struct   msqid_ds msqstat;

    if(msgctl(mtQid, IPC_STAT, &msqstat) < 0)
    {
        uaLog(L_MAJ,  "FATAL: IN msg msgctl E=%d", errno);
        return 0;
    }

    return msqstat.msg_qnum;
}

int InitMtQ()
{
    struct   msqid_ds msqstat;

    if(msgctl(mtQid, IPC_STAT, &msqstat) < 0)
    {
        uaLog(L_MAJ,  "FATAL: MO msgctl E=%d", errno);
        return 0;
    }

    msqstat.msg_qnum = 0;
    return msgctl(mtQid, IPC_SET, &msqstat);
}
