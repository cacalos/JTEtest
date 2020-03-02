#include <time.h>
#include <ua_log.h>
#include <errno.h>
#include <didlib.h>

#define	ALLOC_LIST_FIRST	0
#define	ALLOC_LIST_LAST		1

#define	FREE_LIST_FIRST		2
#define	FREE_LIST_LAST		3



typedef struct {
	time_t	allocTime;
	int		prev;
	int		next;
} CidType;

CidType *gCidTable;
int gMaxCid = 0;

int gnAlloc;

int did_init( int maxCid)
{
	int i;

	if ( maxCid < 10) {
		uaLog( L_CRT, "Too small table size %d", maxCid);
		return -1;
	}

	gCidTable = (CidType*)malloc( sizeof(CidType)*maxCid);	
	if ( gCidTable == (CidType*)0) {
		uaLog( L_CRT, "malloc failed size=%d E=%d",  
			sizeof(CidType)*maxCid, errno);
		return -1;
	}

	gMaxCid = maxCid;

	/* make free list */
	for( i=4; i< maxCid; i++) {
		gCidTable[i].allocTime = 0;
		gCidTable[i].next = i+1;
		gCidTable[i].prev = i-1;
	}

	gCidTable[4].prev = FREE_LIST_FIRST;
	gCidTable[FREE_LIST_FIRST].prev = -1;
	gCidTable[FREE_LIST_FIRST].next = 4;

	gCidTable[i-1].next = FREE_LIST_LAST;
	gCidTable[FREE_LIST_LAST].prev = i-1;
	gCidTable[FREE_LIST_LAST].next = -1;

	/* make alloc list */
	gCidTable[ALLOC_LIST_FIRST].prev = -1;
	gCidTable[ALLOC_LIST_FIRST].next = ALLOC_LIST_LAST;

	gCidTable[ALLOC_LIST_LAST].prev = ALLOC_LIST_FIRST;
	gCidTable[ALLOC_LIST_LAST].next = -1;


	gnAlloc = 0;

	return 0;
}

int did_alloc()
{
	
	int id;

	/*
	printf("gnAlloc=%d free=%d \n", gnAlloc, gFreeList);
	*/

	/* get did */
	id = gCidTable[FREE_LIST_FIRST].next;

	if ( id < 0 || id == FREE_LIST_LAST) {
		uaLog( L_CRT, "Cid table is full. id[%d]", id);
		return -1;
	}

	rmFromList( id);
	insToList( id, ALLOC_LIST_LAST);

	gCidTable[id].allocTime = time(0);

	gnAlloc ++;

	return id;
}

int did_free( int id)
{
	if ( id <= FREE_LIST_LAST || id >= gMaxCid) {
		uaLog( L_CRT, "Invalid did %d", id);
		return -1;
	}

	if ( gCidTable[id].allocTime == 0) {
		/* double free case */
		uaLog( L_MAJ, "ID %d is freed already", id);
		return -1;
	}

	rmFromList( id);
	insToList( id, FREE_LIST_LAST);

	gCidTable[id].allocTime = 0;

	gnAlloc --;

	return 0;
}

int rmFromList( int id)
{
	int prev, next;

	/* remove this id from free list */
	prev = gCidTable[id].prev;
	next = gCidTable[id].next;

	if ( prev >= 0) gCidTable[prev].next = next;
	if ( next >= 0) gCidTable[next].prev = prev;

	return id;
}


int insToList( int id, int pivot)
{
	int prev;

	/* insert before pivot */
	prev = gCidTable[pivot].prev;

	gCidTable[prev].next = id;
	gCidTable[id].prev = prev;

	gCidTable[id].next = pivot;
	gCidTable[pivot].prev = id;

	return 0;
}

int did_getAllocListFirst()
{
	if (  gCidTable[ALLOC_LIST_FIRST].next == ALLOC_LIST_LAST)
		return -1;
	return gCidTable[ALLOC_LIST_FIRST].next ;
}

int did_getAllocLen()
{
	return gnAlloc;
}


int did_checkValid()
{
	int *table;
	int i;
	int id;
	int n;

	if ( gMaxCid <= 0) return 0;

	table = (int*)malloc( sizeof(int)*gMaxCid);
	if ( table == 0) {
		uaLog( L_CRT, "malloc failed size=%d E=%d",  sizeof(int)*gMaxCid, errno);
	}

	/* initialize table */
	for( i=0; i< gMaxCid; i++) {
		table[i] = 0;
	}

	/* check alloc list */
	n = 0;
	id = gCidTable[ALLOC_LIST_FIRST].next;
	while( id >= 0) {
		table[id] |= 1;
		id = gCidTable[id].next;
		n ++;
	}

	if ( n-1 != gnAlloc) {
		printf("nAlloc is not valid %d %d", n, gnAlloc);
	}


	id = gCidTable[ALLOC_LIST_LAST].prev;
	while( id >= 0) {
		table[id] |= 2;
		id = gCidTable[id].prev;
	}

	/* check free list */
	n = 0;
	id = gCidTable[FREE_LIST_FIRST].next;
	while( id >= 0) {
		table[id] |= 4;
		id = gCidTable[id].next;
		n++;
	}

	printf( "nAlloc=%d nFree=%d\n", gnAlloc, n);

	id = gCidTable[FREE_LIST_LAST].prev;
	while( id >= 0) {
		table[id] |= 8;
		id = gCidTable[id].prev;
	}

	for( i=4; i< gMaxCid; i++) {
		if ( table[i] == 0) {
			printf("id %d not marked\n", i);
		}

		if ( !(table[i] == 3 || table[i] == 12)) {
			printf("id %d not valid. value=%d\n", i, table[i]);
		}
	}

	free( table);

	return 0;
}
