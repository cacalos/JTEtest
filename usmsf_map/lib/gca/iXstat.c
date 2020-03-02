#include	<iXstat.h>
#include	<ua_sysdef.h>
#include	<ua_syslib.h>

int         statQid = MSGQUEUE_INIT_VALUE;
key_t       statKey = MSGQUEUE_INIT_VALUE;
int         sndSize = sizeof(stStatMsg);
int         rcvSize = sizeof(stStatMsg) - sizeof(long);


void OpenStatQ()
{
    statKey = msgq_getProcKey( "UASTAT");
    if ( statKey < 0) {
        uaLog( L_CRT, "MSG Q KEY not found for UASTAT");
        return ;
    }

    statQid = msgget( statKey, 0666 | IPC_CREAT | IPC_EXCL);
    if(statQid < 0)
    {
        if(errno == EEXIST)
        {
            statQid = msgget( statKey, 0);
        }
    }

    if(statQid < 0)
    {
        uaLog(L_MAJ,
                "OpenStatQ : cannot open msg Q of server.");
        perror("msgget");
        return ;
    }
}

int GetStatMsg(stStatMsg *msg)
{
    int         i;

    for(i = 0; i < MSGSEND_MAX_RETRY; i++)
    {
        if(msgrcv(statQid, msg, rcvSize, 1, IPC_NOWAIT | MSG_NOERROR ) < 0)
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

int InsStatQMsg(char *pstMsg)
{
    int             nSnd, i;

	for(i = 0; i < STAT_MAX_RETRY; i++)
	{
		nSnd = msgsnd(statQid, (void *)pstMsg, sndSize, IPC_NOWAIT);
		if(nSnd < 0)
		{
			if(errno != EAGAIN)
			{
				uaLog(L_MAJ,  "FATAL: msgsnd E=%d", errno);
				return IXERR;
			}
		}
		else
			break;
	}

    return IXOK;
}
