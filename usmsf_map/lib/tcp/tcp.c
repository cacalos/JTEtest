#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <strings.h>
#include <setjmp.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/un.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/errno.h>
#include <iXtypes.h>
#include <ua_log.h>
#include <iXConfParam.h>
#include <iXUtil.h>
#include <iXTCP.h>

#define Q_DEPTH            5

void sig_alarm_mng(int signo)
{
	uaLog(L_DBG, "call alarm, connection is blocking");
    return ;
}

/* Find ETH index for IPV6. */ 
int FindInet6EthIndex(char *ip_addr)
{
	int        scope_id = -1;
	char                local_addrs[128];
	struct ifaddrs      *addrs, *loops;
	int                 len=0, i;
	

	if(ip_addr == NULL)
	{
		uaLog(L_CRT, "ip_addr is NULL");
		return IXERR;
	}

	if(getifaddrs(&addrs) < 0)
	{
		uaLog(L_CRT, "getifaddrs() is fail");
		return IXERR;
	}

	//loops == NULL, break .
	for(loops = addrs; loops ; loops = loops->ifa_next)
	{
		//find AF_INET6 ETH.
		if(loops->ifa_addr && loops->ifa_addr->sa_family==AF_INET6)
		{
			//get ipaddr.
			getnameinfo(loops->ifa_addr, sizeof(struct sockaddr_in6), local_addrs,sizeof(local_addrs), NULL, 0, NI_NUMERICHOST);
			len = strlen(local_addrs);

			for(i=0;i< len; i++)
			{
				//interface name split.
				if(local_addrs[i] == '%')
				{
					local_addrs[i] = '\0';
					break;
				}
			}
			
			//ip_addr?? convert? to upper ??? hm... 
			if(strcmp(local_addrs, ip_addr) == 0)
			{
				scope_id = if_nametoindex(loops->ifa_name);
				break;
			}
		}
	}
	
	//always free addr list.
	freeifaddrs(addrs);

	if(scope_id < 0)
	{
		uaLog(L_CRT, "Can't Find <%s> in INTERFACE LIST - IPV6", ip_addr);
		return IXERR;
	}
	
	return scope_id;
}

/* Added by Nersion. IPV6 Open Server */
int OpenInet6TCPSrv(char *ip_addr, int port, int all_open)
{
	//AF_INET6
    int                    opt;
    int                    sock;
	int 				   ret;
	struct sockaddr_in6	   addr;

	if(ip_addr == NULL)
	{
		uaLog(L_CRT, "ip_addr is NULL");
		return IXERR;
	}

	memset(&addr, 0x00, sizeof(addr));

	addr.sin6_family = AF_INET6;
	addr.sin6_port = htons(port);

	if(all_open == IXOK)
		addr.sin6_addr = in6addr_any;
	else
	{
		inet_pton(AF_INET6, ip_addr, (void *)&addr.sin6_addr);
		ret = FindInet6EthIndex(ip_addr);
		if(ret < 0)
			return IXERR;
		addr.sin6_scope_id = ret;
	}

    if((sock = socket(AF_INET6, SOCK_STREAM, 0)) < 0)
    {
        uaLog(L_CRT, "socket() fail... errno[%d:%s]", errno, strerror(errno));
        return IXERR;
    }

	opt = 1;
    
	if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, 4) < 0)
    {
        uaLog(L_CRT, "setsockopt() fail... errno[%d:%s]", errno, strerror(errno));
        close(sock); //20191211
        return IXERR;
    }

    if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        uaLog(L_CRT, "bind() fail... errno[%d:%s] port[%d]", errno, strerror(errno), port);
        close(sock);
        return IXERR;
    }

    if(listen(sock, Q_DEPTH) < 0)
    {
        uaLog(L_CRT, "listen() fail... errno[%d:%s]", errno, strerror(errno));
        close(sock);
        return IXERR;
    }

    return sock;
}


int OpenInetTCPSrv(char *ip_addr, int port)
{
    int                    opt;
    int                    sock;
    struct sockaddr_in     addr;

    bzero((char *)&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if(ip_addr != NULL)
        addr.sin_addr.s_addr = inet_addr(ip_addr);
    else
        addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        uaLog(L_CRT, "socket() fail... errno[%d:%s]", errno, strerror(errno));
        return -1;
    }

    opt = 1;
    if(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, 4) < 0)
    {
        uaLog(L_CRT, "setsockopt() fail... errno[%d:%s]", errno, strerror(errno));
        close(sock); //20191211
        return -1;
    }

    if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        uaLog(L_CRT, "bind() fail... errno[%d:%s]", errno, strerror(errno));
        close(sock);
        return -1;
    }

    if(listen(sock, Q_DEPTH) < 0)
    {
        uaLog(L_CRT, "listen() fail... errno[%d:%s]", errno, strerror(errno));
        close(sock);
        return -1;
    }

    return sock;
}

int OpenInetTCPCli(char *ip_addr, int port)
{
    int                    sock;
    struct sockaddr_in     addr;
	struct sigaction 	   almsig;

    bzero((char *)&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if(ip_addr != NULL)
        addr.sin_addr.s_addr = inet_addr(ip_addr);
    else
        addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        uaLog(L_CRT, "socket() fail... errno[%d:%s]", errno, strerror(errno));
        return -1;
    }

    //signal(SIGALRM, sig_alarm_mng);

	almsig.sa_handler = sig_alarm_mng;
	sigemptyset(&almsig.sa_mask);
	almsig.sa_flags = 0;
	sigaction( SIGALRM, &almsig, NULL);

	alarm(1);
    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        uaLog(L_CRT,
            "connect() fail. ip[%s] port[%d] errno[%d]", ip_addr, port, errno);
        close(sock);
        return -1;
    }
	alarm(0);

	if(sock > 0) {
		uaLog( L_MAJ,
				"connect() success. ip[%s] port[%d] errno[%d]", ip_addr, port, errno);
	}

    return sock;
}


int readn(int fd, char *ptr, size_t nbytes)
{
    int    nleft, nread;

    nleft = nbytes;
    while(nleft > 0)
    {
        nread = read(fd, ptr, nleft);
        if(nread < 0)
            return nread;
        else if(nread == 0)
            break;

        nleft -= nread;
        ptr   += nread;
    }

    return (nbytes-nleft);
}


int writen(int fd, char *ptr, size_t nbytes)
{
    int    nleft, nwritten;

    nleft = nbytes;
    while(nleft > 0)
    {
        nwritten = write(fd, ptr, nleft);
        if(nwritten <= 0)
            return (nwritten);

        nleft -= nwritten;
        ptr   += nwritten;
    }

    return (nbytes-nleft);
}


/*	jtkim, 2002.5.28 */
int readn_r(int fd, char *ptr, size_t nbytes)
{
    int    nleft, nread;

    nleft = nbytes;
    while(nleft > 0)
    {
again:
        if((nread = read(fd, ptr, nleft)) < 0)
        {
            uaLog(L_CRT, "read() fail... sock[%d], errno[%d:%s]",
                fd, errno, strerror(errno));
            if(errno == EINTR)
                goto again;
            else
                return nread;      /* error, return < 0 */
		}
        else if(nread == 0)
            break; /* EOF */

        nleft -= nread;
        ptr   += nread;
    }

    return (nbytes-nleft);
}

void setSocketOpt(int sock)
{
    struct  linger  linger;
    int     sockOpt, ret;

    sockOpt = 1;
    ret = setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (void *)&sockOpt, 4);
    if(ret < 0)
        uaLog(L_CRT, "[%05d]Setting TCP option failed!, ret(%d)", getpid(), ret);
 
    linger.l_onoff = 1;
    linger.l_linger = 0;
 
    ret = setsockopt(sock, SOL_SOCKET, SO_LINGER, (char *)&linger,
            sizeof(linger));
    if(ret < 0)
        uaLog(L_CRT, "[%5d]Setting linger option failed!", getpid());
}

fd_set checkSocket(int *sock, int count, long sec, long usec)
{
    int             i, ret, maxfd;
    fd_set          readMask;
    struct timeval  timeOut;
 
    FD_ZERO(&readMask);
	maxfd = 0;

    for(i = 0; i < count; i++)
    {
	    if(sock[i] >= 0)
		{
		    FD_SET(sock[i], &readMask);
			if(maxfd <= sock[i])
			    maxfd = sock[i]+1;
        }
    }
 
	if(sec <= 0 && usec <= 0)
		usec = ESME_SOCKET_DEFAULT_TIMEOUT;

	timeOut.tv_sec  = sec;
	timeOut.tv_usec = usec;
 
    if((ret = select(maxfd, &readMask, 0, 0, &timeOut)) < 0)
        FD_ZERO(&readMask);
 
    return readMask;
}

int SendEsmeMsg(int sock, char *msg, int len)
{
    return writen(sock, msg, len);
}

int openOtherSideSocket(char *ipAddr, int port)
{
    static  time_t first, second;
    int     gap;
 //   int     sock, ripInfo, pfxInfo;
    int     sock, ripInfo;
 
    time(&second);
    gap = (int)(second-first);

	if(gap < 5)
	{
	    return IXERR;
	}

     ripInfo = getRipInfo();
   //  getCpPfxInfo(&pfxInfo);
    if(ripInfo == CP_RIP_INFO_OTHER)
	{
		uaLog(L_INFO, "[%05d]RIP = OTHER ... IP[%s] Port[%d]", getpid(), ipAddr, port);
        return IXERR;
	}

//	if(ripInfo == CP_RIP_INFO_LOCAL && pfxInfo != CP_PREFIX_INFO_BOTH) 
	if(ripInfo == CP_RIP_INFO_LOCAL) //2019-12-11 
	{
        first = second;

        sock = OpenInetTCPCli(ipAddr, port);
        if (sock <= 0)
        {
            uaLog(L_CRT, "[%05d]Connect fail ... IP[%s] Port[%d]",
                getpid(), ipAddr, port);
            return IXERR;
        }

        setSocketOpt(sock);

        uaLog(L_CRT, "[%05d]Other Side Connection Open Success!(%s %d)", 
		                                            getpid(), ipAddr, port);
        return sock;
	}
	else
	{
		//uaLog(L_DBG, "[%05d]RIP_INFO is not LOCAL... or PFX_INFO is BOTH, ripInfo(%d) pfxInfo(%d)", getpid(), ripInfo, pfxInfo);
		uaLog(L_DBG, "[%05d]RIP_INFO is not LOCAL... or PFX_INFO is BOTH, ripInfo(%d)", getpid(), ripInfo); //2019-12-11
	}

	return IXERR;
}

