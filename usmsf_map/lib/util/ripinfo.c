#include <unistd.h>
#include <stdio.h>
#include <ua_log.h>
#include <ua_sysdef.h>
#include <ua_syslib.h>
#include <iXConfParam.h>
//#include <iXDualAct.h>
#include <iXUtil.h>

int    ripInfo;
int    pfxInfo;

int checkVirtualIp(char *pEnv, char *virtualIp)
{
#ifdef LINUX
	//char *cmd = "/sbin/ifconfig";
	char *cmd = "ip a";
#else
	char *cmd = "netstat -in";                                                                                  
#endif
	char *pTmp;
	char temp[3][32], buf[256], addr[32];                                                                       
	FILE *fp = NULL;                                                                                            

	/* set virtual ip status */
	if ((pTmp = cfg_getSecConf(pEnv, PROC_CONF_FILE, "[SYSTEM]", "VIRTUAL_IP")) == NULL) {
		uaLog( L_CRT, "VIRTUAL_IP not found in the section [SYSTEM] of file '%s'", PROC_CONF_FILE);             
		return IXERR;                                                                                           
	}
	strcpy( virtualIp, pTmp);                                                                                   

	fp = popen(cmd, "r");                                                                                       
	if(fp == NULL) {
		uaLog( L_CRT, "popen(%s) error E=%d", cmd, errno);                                                      
		return IXERR;                                                                                           
	}                                                                                                           

	while(fgets(buf, sizeof(buf), fp) != NULL) {                                                                
#ifdef LINUX
		//if(strstr(buf, " addr:") != NULL) {                                                                   
		if(strstr(buf, "inet ") != NULL) {                                                                      

			sscanf(buf, "%s %s", temp[0], addr);
			if(strstr(addr, virtualIp) != NULL) {                                                               
				pclose(fp);
				return IXOK;                                                                                    
			}                                                                                                   
		}                                                                                                       
#else   
		sscanf( buf, "%s %s %s %s", temp[0], temp[1], temp[2], addr);                                           
		if ( strcmp( addr, virtualIp) == 0) {                                                                   
			pclose(fp);
			return IXOK;
		}
#endif
	}

	pclose(fp);
	return NOTOK;
}

int setDualActInfo()
{
    char *pEnv;
    char *pTmp;
    char virtualIp[32];
    int found;
    char hostname[32];

      /* set virtual ip status */
    GET_SYS_HOME_ENV(pEnv);

	found = checkVirtualIp(pEnv, virtualIp);

    if (found == IXOK) 
    {
        setRipInfo(CP_RIP_INFO_LOCAL);
        uaLog( L_INFO, "Virutal IP %s is found", virtualIp);
        uaLog( L_INFO, "RIP Information : LOCAL");
    }
    else 
    {
        setRipInfo(CP_RIP_INFO_OTHER);
        uaLog( L_INFO, "Virutal IP %s is not found", virtualIp);
        uaLog( L_INFO, "RIP Information : OTHER");
    }

    /* set distribution method */
    gethostname( hostname, sizeof(hostname));
 
    if ((pTmp = cfg_getSecConf(pEnv, PROC_CONF_FILE, "[SYSTEM]", "HOST1")) == NULL) {
        uaLog( L_CRT, "HOST1 not found in the section [SYSTEM] of file '%s'", PROC_CONF_FILE);
        return IXERR;
    }
    if ( strcmp( hostname, pTmp) == 0) {
        /* this is HOST 1 */
        setPfxInfo(CP_PREFIX_INFO_EVEN);
        uaLog( L_INFO, "This machine '%s' is HOST1. Set distribution mode as EVEN", hostname);
    }
    else {
 
        if ((pTmp = cfg_getSecConf(pEnv, PROC_CONF_FILE, "[SYSTEM]", "HOST2")) == NULL) {
            uaLog( L_CRT, "HOST2 not found in the section [SYSTEM] of file '%s'", PROC_CONF_FILE);
            return IXERR;
        }
        if ( strcmp( hostname, pTmp) == 0) {
            /* this is HOST 2 */
            setPfxInfo(CP_PREFIX_INFO_ODD);
            uaLog( L_INFO, "This machine '%s' is HOST2. Set distribution mode as ODD", hostname);
        }
        else {
            setPfxInfo(CP_PREFIX_INFO_BOTH);
             uaLog( L_INFO, "Unregistered host name, current pfx status is both %s", hostname);
             return NOTOK;
        }
    }
    return IXOK;
}

void setRipInfo(int rip)
{
    ripInfo = rip;
}

void setPfxInfo(int pfx)
{
    pfxInfo = pfx;
}

int getRipInfo()
{
    return ripInfo;
}

int getPfxInfo()
{
    return pfxInfo;
}

int getRoutePrefix(stAddr *dest)
{
    int len, prefix_info;
 
    prefix_info = getPfxInfo();
    len = strlen(dest->min);

    if(len == 0)
        return DUALACT_MESG_LOCAL; /* 에러 발생, 로컬에서 처리 하도록 함 */
 
    if(prefix_info == CP_PREFIX_INFO_BOTH  ||
       (pfxInfo == CP_PREFIX_INFO_EVEN && (dest->min[len-1]%2 == 0 || dest->min[len-1] == '#'))  ||
       (pfxInfo == CP_PREFIX_INFO_ODD  && (dest->min[len-1]%2 != 0 || dest->min[len-1] == '*')))
        return DUALACT_MESG_LOCAL;
    else
        return DUALACT_MESG_OTHER;
}

/* v590 by Nersion. For DNIF */
int checkRipInfoForDnif()
{
    char *pEnv;
    char virtualIp[32];
    int found;

      /* set virtual ip status */
    GET_SYS_HOME_ENV(pEnv);

#if 0
    if ((pTmp = cfg_getSecConf(pEnv, PROC_CONF_FILE, "[SYSTEM]", "VIRTUAL_IP")) == NULL) {
        uaLog( L_CRT, "VIRTUAL_IP not found in the section [SYSTEM] of file '%s'", PROC_CONF_FILE);
        return IXERR;
    }
    strcpy( virtualIp, pTmp);
    uaLog( L_INFO, "Virtual IP = %s", virtualIp);
 
    fp = popen( cmd, "r");
    if ( fp == NULL) {
        uaLog( L_CRT, "popen(%s) error E=%d", cmd, errno);
        return IXERR;
    }
    found = NOTOK;
    while( fgets( buf, sizeof(buf), fp) != NULL) {
        sscanf( buf, "%s %s %s %s", a[0], a[1], a[2], addr);
        if ( strcmp( addr, virtualIp) == 0) {
            found = IXOK;
            break;
        }
    }
    pclose(fp);
#endif
	found = checkVirtualIp(pEnv, virtualIp);

    if (found == IXOK)
    {
        uaLog( L_INFO, "Virutal IP %s is found", virtualIp);
        uaLog( L_INFO, "RIP Information : LOCAL");
		return IXOK;
    }

	uaLog( L_INFO, "Virutal IP %s is not found", virtualIp);
	uaLog( L_INFO, "RIP Information : OTHER");
	return IXERR;
}


