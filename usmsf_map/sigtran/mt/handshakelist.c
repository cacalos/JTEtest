#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include <ua_log.h>
#include <ua_syslib.h>

#include <SS7/ss7_resq.h>

stHandShakeListShm      *gpHandShakeList;

int InitHandShakeListShm()
{
	int flag;

	if((gpHandShakeList = (stHandShakeListShm*)shm_create( "HANDSHAKELIST",
					sizeof(stHandShakeListShm), &flag)) == (stHandShakeListShm*)-1)
	{
		uaLog(L_CRT,
				"Open handshakeList : shmat error:%s", strerror(errno));
		return IXERR;
	}
	else
		uaLog(L_CRT, "Open Success HandshakeList");

	if ( flag ) {
		memset( gpHandShakeList, 0, sizeof(stHandShakeListShm));
	}

	gpHandShakeList->end = 0;
	gpHandShakeList->on_off = 1; //v201

	return IXOK;
}

int InsertHandShakeInfo(stHandShakeInfo *info)
{
	if(IS_HANDSHAKELIST_FULL(gpHandShakeList->end))
	{
		/* Max HandShake List ITEM reached */
		uaLog(L_CRT, "HandShakeList Table full error!!");
		return IXERR;
	}

	memcpy((void *)&gpHandShakeList->table[gpHandShakeList->end], (void *)info, sizeof(stHandShakeInfo));
	gpHandShakeList->end++;

	return IXOK;
}

int HandShakeInfo_compare(const stHandShakeInfo *info1, const stHandShakeInfo *info2)
{
	if (strlen(info2->isdn) == 0)
		return 1;

	return strncmp(info1->isdn, info2->isdn, strlen(info2->isdn));
}

int IsHandShakeFuncOn() //v201
{
	return gpHandShakeList->on_off;
}

int IsHandShakeListMsg(stHandShakeInfo *info)
{
	int                 addr_len, i ;
	stHandShakeInfo     node;

	addr_len = strlen(info->isdn);
	if(addr_len > DEFAULT_ADDR_LEN || addr_len <= 0) {
		return IXERR;
	}

	bzero((void*)&node, sizeof(stHandShakeInfo));
	strcpy(node.isdn, info->isdn);

	for(i = 0; i < gpHandShakeList->end; i++)
	{
		if(strcmp(node.isdn, gpHandShakeList->table[i].isdn) == 0)
		{
			gpHandShakeList->table[i].acn_version = info->acn_version;
			return IXOK;
		}
	}

	return IXERR;
}

int GetHandShakeList(stHandShakeInfo *info)
{
	int                 addr_len, i;
	stHandShakeInfo     node;

	addr_len = strlen(info->isdn);
	if(addr_len > DEFAULT_ADDR_LEN || addr_len <= 0) {
		return IXERR;
	}

	bzero((void*)&node, sizeof(stHandShakeInfo));
	strcpy(node.isdn, info->isdn);

	for(i = 0; i < gpHandShakeList->end; i++)
	{
		if(strcmp(node.isdn, gpHandShakeList->table[i].isdn) == 0)
		{
			info->acn_version = gpHandShakeList->table[i].acn_version;
			return IXOK;
		}
	}

	return IXERR;
}

int GetAllHandShakeList(stHandShakeInfo *info, int *count)
{
	int      i, cnt;

	cnt = 0;

	for(i = 0; i < gpHandShakeList->end && i < MAX_HANDSHAKE_LIST; i++) {
		memcpy(&info[cnt++], &gpHandShakeList->table[i], sizeof(stHandShakeInfo));
	}

	*count = cnt;

	return IXOK;
}
