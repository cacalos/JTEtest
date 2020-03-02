
#define DEC_FLOW    (1)
#define INC_FLOW    (2)

typedef struct _stLinkList {
    int        addr[3];
    int        state;
    int        txload;
    int        rxload;
} stLinkList;


typedef struct _stLinkInfo {
    int        num_links_all;
    int        num_links_act;
    int        max_tx;
    int        avg_tx;
    int        max_rx;
    int        avg_rx;
} stLinkInfo;

