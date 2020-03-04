#include <sys/types.h>
#include <unistd.h>

#include <uxcutor/uxc_ipcmsg.h>
#include <ua_log.h>

#include <smsf_msg.h>
#include <iXtypes.h>

int         proxyQid = MSGQUEUE_INIT_VALUE;
key_t       proxyKey = MSGQUEUE_INIT_VALUE;
int         sndMSG = sizeof(uxc_ixpc_t)+sizeof(smsf_msg_t);
int         rcvMSG = sizeof(uxc_ixpc_t)+sizeof(smsf_msg_t);

void OpenProxyQ()
{
    proxyKey = msgq_getProcKey( "MSGPROXY");
    if ( proxyKey < 0) {
        uaLog( L_CRT, "MSG Q KEY not found for SMSFIF");
        return ;
    }

    proxyQid = msgget( proxyKey, 0666 | IPC_CREAT | IPC_EXCL);
    if(proxyQid < 0)
    {
        if(errno == EEXIST)
        {
            /* ?½õµ */
            proxyQid = msgget( proxyKey, 0);
        }
    }

    if(proxyQid < 0)
    {
        uaLog(L_MAJ,
                "OpenProxyQ : cannot open msg Q of server.");
        perror("msgget");
        return ;
    }
}


int InsProxyQMsg(char *pstMsg, int mType)
{
    int             nSnd, i;
    uxc_ipcmsg_t    ipcmsg;

    memset(&ipcmsg, 0x00, sndMSG);
    memcpy(ipcmsg.data, pstMsg, sizeof(smsf_msg_t));
    ipcmsg.header.srcProcId = getpid();
    ipcmsg.header.srcSubSysId = 0;
    ipcmsg.header.msgId = mType;
    ipcmsg.header.cmdId = -1;
    ipcmsg.header.userData = 0;
    ipcmsg.header.srcQid = proxyQid;
    ipcmsg.header.dstQid = proxyQid;
    ipcmsg.header.length = sizeof(smsf_msg_t);
    ipcmsg.mtype = mType;

    for(i = 0; i < MSGSEND_MAX_RETRY; i++)
    {
        nSnd = msgsnd(proxyQid, (void *)&ipcmsg, sndMSG, IPC_NOWAIT);
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
