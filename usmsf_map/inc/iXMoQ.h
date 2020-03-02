#include <iXtypes.h>

#ifndef _IX_MO_Q_INCLUDED
#define _IX_MO_Q_INCLUDED

typedef struct _stMoMsg {
	stAddr 			orig;
	stAddr 			imsi;
	char 			amfId[DEFAULT_AMFID_LEN];
	char 			msgRef;
	stNodeNumber    origNode;
	stNodeNumber    destNode;
	char 			routeType;
	int				data_len;
	char 			data[250];
} stMoMsg;

#endif
