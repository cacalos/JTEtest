
#ifndef _IX_SEM_INCLUDED
#define _IX_SEM_INCLUDED

#include <stdio.h>
#include <errno.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#include <iXtypes.h>

//#define IXGCA_SEM_KEY             0xE301
#define IXGCA_SEM_KEY     0x79457

#define MAX_SEM_SIZE             (MAX_SEM_ID)

enum {
	IXTRACE_SEM_ID = 0,            

	MAPSTAT_SEM_ID,
	ERR_STAT_SEM_ID,

	IXCP_SEM_ID, 
	MAX_SEM_ID
};



#endif    /* _IX_SEM_INCLUDED */

