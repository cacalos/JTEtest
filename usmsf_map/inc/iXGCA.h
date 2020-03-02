
#include <iXSem.h>
#include <iXTrace.h>
#include <iXLog.h>
#if 0
#include <iXMapStat.h>
#endif


#ifndef _IX_GCA_INCLUDED
#define _IX_GCA_INCLUDED

/* bhtak 2004/7/5 define in sys.conf
#define IXGCA_SHM_KEY    0x30200
*/
#define IXGCA_SHM_KEY 0x10328

#define msgid_inc(P) __sync_add_and_fetch((P), 1)

typedef struct {
    stTraceShm        trace;

    char              oamSeId;
} stGCA;

int CloseGCA();
#endif    /* _IX_GCA_INCLUDED    */

