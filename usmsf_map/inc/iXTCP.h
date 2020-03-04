
#ifndef _IX_TCP_INCLUDED
#define _IX_TCP_INCLUDED

#include <stdio.h>
#include <stdlib.h>

//For IPV6
#include <net/if.h>
#include <ifaddrs.h>
#include <netdb.h>



#ifdef _CPP_SOURCE_ONLY_HEADER_
extern "C"
{
#endif

typedef struct _stServerInfo {
	int              Lfd;               /* Local Address */
	int              Rfd;               /* Reallocated Address */
	unsigned short   port;
	char             port_name[24];
} stServerInfo;


/* Dual Act 기능으로, 각각 Child들은 2개의 소켓을 관리한다 */
/* REMOTE : 각각 서버들과의 접속 (VAS, HNET, VMS)          */
/* LOCAL  : Primary <-> Seondary                           */
#define ESME_SOCKET_COUNT           2
#define ESME_SOCKET_REMOTE          0
#define ESME_SOCKET_LOCAL           1

#define ESME_SOCKET_DEFAULT_TIMEOUT 20000 /* v441 */

int     gSock[ESME_SOCKET_COUNT];


int OpenInetTCPSrv(char *ip_addr, int port);
int OpenInetTCPCli(char *ip_addr, int port);
int readn(int fd, char *ptr, size_t nbytes);
int writen(int fd, char *ptr, size_t nbytes);
int readn_r(int fd, char *ptr, size_t nbytes);
fd_set checkSocket(int *sock, int count, long sec, long usec);

void setSocketOpt(int sock);
int SendEsmeMsg(int sock, char *msg, int len);

int openOtherSideSocket(char *ipAddr, int port);

int OpenInet6TCPSrv(char *ip_addr, int port, int all_open);
int FindInet6EthIndex(char *ip_addr);

#define  NPS_CLI_PORTNAME  "NPS.CLIENT"

#ifdef _CPP_SOURCE_ONLY_HEADER_
}
#endif

#endif
