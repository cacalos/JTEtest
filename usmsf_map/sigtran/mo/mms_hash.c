
#include <stdio.h>

#include <iXtypes.h>
#include <ua_log.h>
#include <SS7/hash.h>
#include <sigtran_util.h>

pstHashTable   gHashIndex[MAX_HASH_INDEX];


int InitHashTable()
{
	int i;

    for(i = 0; i < MAX_HASH_INDEX; i++)
        gHashIndex[i] = NULL;

    return IXOK;
}


int GetHashIndex(stAddr *dest)
{
    if(dest->len < 2)
        return -1;
    return ((dest->min[dest->len -2] - '0') * 10 +
            (dest->min[dest->len -1] - '0'));
}


int InsertHashTable(stAddr *dest, int dialog_id, int user_id, int inv_id)
{
    int               slot;
    time_t            now;
    pstHashTable      tmp, ind; 

    slot = GetHashIndex(dest);
    if(slot < 0 || slot >= MAX_HASH_INDEX)
    {
        uaLog(L_CRT,
            "InsertHashTable(): Invalid slot[%d] dest[%s %d %d %d]",
            slot, dest->min, dest->ton, dest->npi, dest->len);
        return IXERR;
    }

    ind = gHashIndex[slot];
    if(ind == NULL)
    {
        tmp = (pstHashTable)malloc(sizeof(struct stHashTable));
        if(tmp == NULL)
        {
            uaLog(L_CRT,
                "InsertHashTable(): malloc() fail... dest[%s]", dest->min);
            return IXERR;
        }

        memcpy(&tmp->dest, dest, sizeof(stAddr));
        time(&now);
        tmp->sentTime = now;
        tmp->dialog_id = dialog_id;
        tmp->user_id = user_id;
        tmp->invoke_id = inv_id;
        tmp->next = NULL;
        gHashIndex[slot] = tmp;
        return IXOK;
    }

    while(ind->next != NULL)
    {
        if(ind->dest.len == dest->len &&
          !strncmp(ind->dest.min, dest->min, dest->len))
            return NOTOK;
        ind = ind->next;
    }

    if(ind->dest.len == dest->len &&
      !strncmp(ind->dest.min, dest->min, dest->len))
        return NOTOK;

    tmp = (pstHashTable)malloc(sizeof(struct stHashTable));
    if(tmp == NULL)
    {
        uaLog(L_CRT,
            "InsertHashTable(): malloc() fail... dest[%s]", dest->min);
        return IXERR;
    }

    memcpy(&tmp->dest, dest, sizeof(stAddr));
    time(&now);
    tmp->sentTime = now;
    tmp->dialog_id = dialog_id;
    tmp->user_id = user_id;
    tmp->invoke_id = inv_id;
    tmp->next = NULL;

    ind->next = tmp;
    return IXOK;
}


int DeleteHashTable(stAddr *dest, int *dialog_id, int *user_id, int *inv_id)
{
    int            slot;
    pstHashTable   tmp, ind;

    slot = GetHashIndex(dest);
    if(slot < 0 || slot >= MAX_HASH_INDEX)
    {
        uaLog(L_CRT,
            "DeleteHashTable(): Invalid slot[%d] dest[%d %d %d %d]",
            slot, dest->min, dest->ton, dest->npi, dest->len);
        return IXERR;
    }

    ind = gHashIndex[slot];
    if(ind == NULL)
        return NOTOK;

    if(ind->dest.len == dest->len &&
      !strncmp(ind->dest.min, dest->min, dest->len))
    {
        gHashIndex[slot] = ind->next;
        ind->next = NULL;
        *dialog_id = ind->dialog_id;
        *user_id = ind->user_id;
        *inv_id = ind->invoke_id;
        free(ind);
        return IXOK;
    }

    tmp = ind;
    ind = ind->next;
    while(ind != NULL)
    {
        if(ind->dest.len == dest->len &&
          !strncmp(ind->dest.min, dest->min, dest->len))
        {
            *dialog_id = ind->dialog_id;
            *user_id = ind->user_id;
            *inv_id = ind->invoke_id;
            tmp->next = ind->next;
            /* tmp->next = NULL;*/
            free(ind);
            return IXOK;
        }
        tmp = ind;
        ind = ind->next;
    }

    return NOTOK;
}

/*
int SearchHashTable(int CnxId, time_t secs)
{
    int          i;
    time_t       now;
    pstHashTable ind;

    time(&now);
    for(i = 0; i < MAX_HASH_INDEX; i++)
    {
        ind = gHashIndex[i];
        if(ind == NULL)
            continue;

        if(now >= (ind->sentTime + secs))
        {
            gHashIndex[i] = ind->next;
            ind->next = NULL;
            SendTCUAbort(CnxId, ind->user_id, ind->dialog_id);
            free(ind);
            i--;
        }
    }
    return IXOK;
}
*/

int sigSearchHashTable(UTcap *gTcapInfo, time_t secs, int ssn)
{
    int          i;
    time_t       now;
    pstHashTable ind;

    time(&now);
    for(i = 0; i < MAX_HASH_INDEX; i++)
    {
        ind = gHashIndex[i];
        if(ind == NULL)
            continue;

        if(now >= (ind->sentTime + secs))
        {
            gHashIndex[i] = ind->next;
            ind->next = NULL;
            sig_sendTCUAbort( gTcapInfo, ind->user_id, ind->dialog_id, ssn) ;
            free(ind);
            i--;
        }
    }
    return IXOK;
}
