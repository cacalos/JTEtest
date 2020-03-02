
#define MAX_HASH_INDEX               100

typedef struct stHashTable          *pstHashTable;
typedef struct stHashTable {
    stAddr               dest;
    time_t               sentTime;
    int                  dialog_id;
    int                  invoke_id;
    int                  user_id;
    pstHashTable         next;
} stHashTable;

