#ifndef	DIDLIB_H__
#define	DIDLIB_H__

int did_init( int maxCid);
int did_alloc(void);
int did_free( int id);
int did_getAllocListFirst(void);
int did_getAllocLen(void);
int did_checkValid(void);

#endif
