#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <sys/shm.h>

#include <ua_sysdef.h>

#include <SS7/ss7_resq.h>
#include <SS7/ix7map.h>

char *cfg_getSecConf(char *pEnv,char *file,char *section,char *title);
int     gSysBase = 0;

int main(int argc, char *argv[])
{
	int                     i, key, shmid, ret, cnt = 0;
	char                    *pTmp, *pEnv;
	stHandShakeListShm      *list;
	char                    buf[16];
	char                    mode = 0;

	if(argc == 2) {
		if(strncmp(argv[1], "-c", 2) == 0)
			mode = 1;
		else if(strncmp(argv[1], "on", 2) == 0)
			mode = 2;
		else if(strncmp(argv[1], "off", 3) == 0)
			mode = 3;
		else
		{
			printf("seeHsList -c(clear) / on / off \n");
			exit(0);
		}
	}
	else if(argc > 2)
	{
		printf("seeHsList -c(clear) / on / off \n");
		exit(0);
	}

	GET_SYS_HOME_ENV(pEnv);

	if (!gSysBase) {
		gSysBase = getSysBase(pEnv);
	}

	if ((pTmp = cfg_getSecConf(pEnv, PROC_CONF_FILE, "[SHM_KEY]", "HANDSHAKELIST")) == NULL) {
		uaLog(  L_MIN, "get SHMKEY failed");
		exit(0);
	}

	key = strtol(pTmp, ( char **) 0, 0) + gSysBase;

	if((shmid = shmget(key, sizeof(stHandShakeListShm), 0666)) < 0) {
		printf("shmget error key=0x%x size=%d :%s\n",
				key, sizeof(stHandShakeListShm), strerror(errno));
		exit(0);
	}

	if((list = (stHandShakeListShm *)shmat( shmid, (char *)0, 0)) == (stHandShakeListShm *)-1)
	{
		printf("Open HS List:shmat error:%s\n", strerror(errno));
		exit(0);
	}

	if(mode == 1)
	{
		printf("All Handshkae List is cleared(%d-->0)\n", list->end);
		list->end = 0;
	}
	else if(mode == 2)
	{
		list->on_off = 1;
		printf("Handshkae Function ON\n");
	}
	else if(mode == 3)
	{
		list->on_off = 0;
		list->end = 0;
		printf("Handshkae Function OFF\n");
	}
	else
	{
		printf("Function Switch : %s\n", list->on_off == 1 ? "ON" : "OFF");
		printf("========================================================\n");
		printf(" %-4s %-15s     %s\n", "NUM", "ISDN", "VER");
		printf("--------------------------------------------------------\n");
		for(i = 0; i < list->end; i++) {
			sprintf(buf, "%s",  list->table[i].acn_version == IS_ACN_NOT_SET    ? "ACN_NOT_SET" :
					list->table[i].acn_version == ACN_MO_V2         ? "ACN_MO_V2"   :
					list->table[i].acn_version == ACN_MO_V3         ? "ACN_MO_V3"   :
					list->table[i].acn_version == ACN_MT_V2         ? "ACN_MT_V2"   :
					list->table[i].acn_version == ACN_MT_V3         ? "ACN_MT_V3"   :
					list->table[i].acn_version == ACN_ALERT_V2      ? "ACN_ALERT_V3": "UNKNOWN");
			printf(" %-4d  %-15s        %s\n", i+1, list->table[i].isdn, buf);
		}
		printf("--------------------------------------------------------\n");
		printf(" All Handshkae List Count ==> %d\n", list->end);
		printf("========================================================\n");
	}

	exit(1);
}
