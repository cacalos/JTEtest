#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include <ua_log.h>

//#include <iXMoQ.h>
#include <smsf_msg.h>
#include <iXSem.h>

int         MoQid = MSGQUEUE_INIT_VALUE;
key_t       moKey = MSGQUEUE_INIT_VALUE;
int         sndMo = sizeof(smsf_msg_t);
int         rcvMo = sizeof(smsf_msg_t)-sizeof(long);

void OpenMoQ()
{
    moKey = msgq_getProcKey( "SIGMO");
    if ( moKey < 0) {
        uaLog( L_CRT, "MSG Q KEY not found for SIGMO");
        return ;
    }

    MoQid = msgget( moKey, 0666 | IPC_CREAT | IPC_EXCL);
    if(MoQid < 0)
    {
        if(errno == EEXIST)
        {
            /* À½õµ */
            MoQid = msgget( moKey, 0);
        }
    }

    if(MoQid < 0)
    {
        uaLog(L_MAJ,
                "OpenMoQ : cannot open msg Q of server.");
        perror("msgget");
        return ;
    }
}

int GetMoMsg(smsf_msg_t *msg)
{
    int         i;

    for(i = 0; i < MSGSEND_MAX_RETRY; i++)
    {
        if(msgrcv(MoQid, msg, rcvMo, 0, IPC_NOWAIT | MSG_NOERROR ) < 0)
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

int GetMoQLen()
{
    struct   msqid_ds msqstat;

    if(msgctl(MoQid, IPC_STAT, &msqstat) < 0)
    {
        uaLog(L_MAJ,  "FATAL: IN msg msgctl E=%d", errno);
        return 0;
    }

    return msqstat.msg_qnum;
}

int InitMoQ()
{
    struct   msqid_ds msqstat;

    if(msgctl(MoQid, IPC_STAT, &msqstat) < 0)
    {
        uaLog(L_MAJ,  "FATAL: MO msgctl E=%d", errno);
        return 0;
    }

    msqstat.msg_qnum = 0;
    return msgctl(MoQid, IPC_SET, &msqstat);
}
