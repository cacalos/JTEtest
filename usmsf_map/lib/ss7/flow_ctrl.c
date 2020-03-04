
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <sys/time.h>

#include <ua_log.h>
#include <SS7/links.h>

#define MAX_S_BURST                  (12)
#define MIN_S_BURST                  (2)

#define MAX_S_INTERVAL               (50000)
#define MIN_S_INTERVAL               (5000)

#define SEC_BETWEEN_INCS             (6)
#define SEC_BETWEEN_DECS             (2)

#define INTERVAL_INC_RATE            ((float) 1.09)    
#define INTERVAL_INC_RATE2           ((float) 1.05)    
#define INTERVAL_DEC_RATE            ((float) 0.97)    

#define SEC_NO_CONGEST               (15)
#define SEC_BY_TM_OUT                (5)
#define MAX_ERLANG                   (80)

int Max_Burst                  = MAX_S_BURST;

int Send_Burst                 = 4;
int Send_Interval              = 10000;

int act_max_B                  = 0;
int max_msgPsec                = 0;
int msgPersec                  = 0;
int act_min_I                  = 50000;

int Max_Erlang                 = MAX_ERLANG;

int Time_Out                   = 0;

/*--- link status ----*/
int Link_Usage                 = 0;
int Max_TX                     = 0;
int Avg_Usage                  = 0;
int NumLinks                   = 0;
int NumLinks_Act               = 0;

int min_sent_msg; 


void set_max_burst(int num_links)
{
    static int        pre_num_links;

    if(num_links != pre_num_links)
    {
        pre_num_links = num_links;
        Max_Burst = (num_links ) + (num_links >> 1);
        Send_Burst = 4;
        Send_Interval = 10000;
        if(Send_Burst > Max_Burst)
            Send_Burst = Max_Burst;

        act_max_B   = 0;
        act_min_I   = 50000;
        max_msgPsec = 0;
    }
}


void set_max_erlang(int max)
{
    Max_Erlang = max;
}


void mark_time_out()
{
    Time_Out = 1;
}


int do_flow_ctrl(int inc_dec, int num_sent_msg)
{
    int            gap;
    int            can_inc_B;
    time_t         now;
    static time_t  last_inc,  /* the time when the flow was increased last */
                   last_dec,  /* the time when the flow was decreased last */
                   last_dec2,
                   last_dec3; /* the time when the flow was decreased last */
    static time_t  last_congest; /* time when a congestion happened last */
    static time_t  last_timeout; /* time when last */

    time(&now);
    if(inc_dec == DEC_FLOW)
    {
        /*----------------- Decrease Flow----------------- */
        last_congest = now;

        if(act_max_B >= Send_Burst)
        {
            act_max_B--;
            max_msgPsec = (int)((float)max_msgPsec * (float)0.8);
        }

        gap = (int)((int)now - (int)last_dec);

        if(gap < SEC_BETWEEN_DECS)
            return 0;

        last_dec = now;
        if(gap > SEC_NO_CONGEST)
        {
            dec_burst();
            inc_interval();
        }
        else
        {
            dec_burst();
            inc_interval();
        }

        return (DEC_FLOW);
    }
    else if(inc_dec == INC_FLOW)
    {
        /*----------------- Increase Flow----------------- */
        msgPersec = num_sent_msg;

        if(Link_Usage > Max_Erlang + 6)
        {
            last_inc = now;

            if((int)(now - last_dec2) < 5)
                return 0;
            last_dec2 = now;
            dec_burst();
        }
        else if(Link_Usage > Max_Erlang + 3)
        {
            last_inc = now;
            if((int)(now - last_dec2) < 5)
                return 0;

            last_dec2 = now;
            inc_interval();
        }

        if(num_sent_msg > max_msgPsec)
        {
            max_msgPsec = num_sent_msg;
            act_max_B = Send_Burst;
            act_min_I = Send_Interval;
        }

        min_sent_msg = (int)((float)max_msgPsec * (float)0.80);

        uaLog(L_CRT, "M=%d[%d] B=%d I=%d Lk:%d %d T:%d",
            num_sent_msg, max_msgPsec, Send_Burst, Send_Interval,
            Max_Erlang, Link_Usage, min_sent_msg);

        gap = (int)((int)now - (int)last_congest);
        if(gap < SEC_NO_CONGEST)
            return 0;

        gap = (int)((int)now - (int)last_inc);
        if(gap < SEC_BETWEEN_INCS)
            return 0;

        /*-- found a problem when link_usage == 0 */
        if(Link_Usage >= Max_Erlang - 4)
            return 0;

        if(Send_Burst >= act_max_B && Send_Interval <= act_min_I)
            if(num_sent_msg < min_sent_msg)
                return 0;

        can_inc_B = 1;

        if(Link_Usage >= Max_Erlang - 5)
            can_inc_B = 0;

        last_inc = now;

        if(can_inc_B == 0)
            dec_interval();
        else
        {
            if(inc_burst() == 0)
                dec_interval();
            else
                inc_interval();
        }
        return (INC_FLOW);
    }
    return -1;
}


#define    YIELD_SEC    (10)
/*-----
    yield the link usage to another process (TCAP application)
    for the balanced use of the links
------*/
int yield_link()
{
    int            gap;
    time_t         now;
    static time_t  last_yield;     /* time when a yield happened last */

    time(&now);
    gap = now - last_yield;
    if(gap < YIELD_SEC)
        return 0;

    if(Link_Usage < Max_Erlang - 10)
        return 0;
    
    last_yield = now;
    dec_burst();
    return 1;
}


int inc_interval() 
{
    if(Send_Interval >=  Max_Burst)
        return 0;

    Send_Interval = (int)((float)Send_Interval * INTERVAL_INC_RATE);

    if(Send_Interval > Max_Burst)
        Send_Interval = Max_Burst;

    return 1;
}


int dec_interval()
{
    if(Send_Interval <= MIN_S_INTERVAL)
        return 0;

    Send_Interval = (int)((float)Send_Interval * INTERVAL_DEC_RATE);

    if(Send_Interval < MIN_S_INTERVAL)
        Send_Interval = MIN_S_INTERVAL;

    return 1;
}


int inc_burst()
{
    if(Send_Burst >= Max_Burst)
        return 0;

    Send_Burst++;
    if(Send_Burst > Max_Burst)
        Send_Burst = Max_Burst;

    return 1;
}


int dec_burst()
{
    if(Send_Burst <= MIN_S_BURST)      /* 2 */
        return 0;

    Send_Burst--;
    if(Send_Burst < MIN_S_BURST)
        Send_Burst = MIN_S_BURST;

    return 1;
}

/* insert                                     */
/*


int read_Link_Usage()
{
	char         *logdir;
	char         fname[256];
	char         buf[256];
	char         tmp[64];
	FILE         *fp;
	time_t       tm;

	logdir = getenv("SMS_LOG_DIR");
	if (logdir == NULL)
		sprintf(fname, "/tmp/.LinkLoad2");
	else
		sprintf(fname, "%s/.LinkLoad2", logdir);

	if ((fp = fopen(fname, "r")) == NULL)
	{
		LogPrint(gProc, "Cannot read the file for Link Status Logging : %s",
			fname);
		return -1;
	}

	fscanf(fp, "%d %d %d %d", &NumLinks, &NumLinks_Act, &Max_TX, &Avg_Usage);

	Link_Usage = (int)((Max_TX + Avg_Usage) >> 1);
	set_max_burst(NumLinks_Act);

	fclose(fp);
	return 0;
}

int do_wr_flctrl(int flag)
{
	FlowCtrlSt   f;
	f.sendB = Send_Burst;
	f.sendI = Send_Interval;
	f.numLink = NumLinks_Act;
	f.trgMsg = min_sent_msg;
	f.maxSent = max_msgPsec;
	f.LUseMax = Max_Erlang;
	f.LUse = Link_Usage;
	f.msgPsec = msgPersec;
	wr_shm_flctrl(&f, flag);

	return 0;
}
*/

int       shmid;
char     *shm_addr;

char     *use_shm(int);        /* in my lib */


int open_shm()
{
    shmid = get_shm_id();

    if(shmid < 0)
        shmid = create_shm(sizeof(stLinkInfo));

    if(shmid < 0)
        return -1;

    shm_addr = use_shm(shmid);
    bzero((void *)shm_addr, sizeof(stLinkInfo));

    return shmid;
}


int read_shm()
{
    stLinkInfo    link_info;

    if(shmid < 0)
        open_shm();

    if(shmid >= 0 && shm_addr != (char *)0)
    {
        memcpy(&link_info, shm_addr, sizeof(stLinkInfo));

        NumLinks = link_info.num_links_all ;
        NumLinks_Act = link_info.num_links_act ;
        Max_TX = link_info.max_tx;
        Avg_Usage = link_info.avg_tx ;
        Link_Usage = (int)((Max_TX + Avg_Usage) >> 1);

        set_max_burst(NumLinks_Act);

        return 0;
    }
    else
        return -1;
}


void write_shm(int NumLinks, int NumLinks_Ack, int max_tx, int max_rx,
                   int avg_tx, int avg_rx)
{
    stLinkInfo   link_info;

    if(shmid >= 0 && shm_addr != (char *)0)
    {
        link_info.num_links_all = NumLinks;
        link_info.num_links_act = NumLinks_Act;
        link_info.max_tx = max_tx;
        link_info.max_rx = max_rx;
        link_info.avg_tx = avg_tx;
        link_info.avg_rx = avg_rx;

        memcpy(shm_addr, &link_info, sizeof(stLinkInfo));
    }
}


void close_shm()
{
    release_shm(shm_addr);
    shm_addr = 0;
    shmid = -1;
}

/*
void wr_shm_msgnum(MsgNumSt *p, int flag)
{
	int offset;

	if (p == NULL || shmid < 0 || shm_addr == (char *)0)
		return -1;

	if (flag == 1)
		offset = sizeof(Link_Info);
	else if (flag == 2)
		offset = sizeof(Link_Info) + SIZE_REQ;
	else
		offset = sizeof(Link_Info) + SIZE_REQ * 2;

	memcpy(shm_addr+offset, p, sizeof(MsgNumSt));
}

void wr_shm_flctrl(FlowCtrlSt *p, int flag)
{
	int offset;

	if (p == NULL || shmid < 0 || shm_addr == (char *)0)
		return -1;

	if (flag == 1)
		offset = sizeof(Link_Info) + sizeof(MsgNumSt);
	else if (flag == 2)
		offset = sizeof(Link_Info) + sizeof(MsgNumSt) + SIZE_REQ;
	else
		offset = sizeof(Link_Info) + sizeof(MsgNumSt) + SIZE_REQ * 2;

	memcpy(shm_addr+offset, p, sizeof(FlowCtrlSt));
}

void wr_shm_myq(MyQSt *p, int flag)
{
    int offset;

    if(p == NULL || shmid < 0 || shm_addr == (char *)0)
        return -1;

    if(flag == 1)
        offset = sizeof(Link_Info) + sizeof(MsgNumSt) + sizeof(FlowCtrlSt);
    else if(flag == 2)
        offset = sizeof(Link_Info)  + sizeof(MsgNumSt) + sizeof(FlowCtrlSt)
            + SIZE_REQ;
    else
        offset = sizeof(Link_Info)  + sizeof(MsgNumSt) + sizeof(FlowCtrlSt)
            + SIZE_REQ*2;

    memcpy(shm_addr+offset, p, sizeof(MyQSt));
}

void wr_shm_tcapinfo(int *err, int *prim, int *comp, int cong, int uncong, int flag)
{
    int offset;

    if(shmid < 0 || shm_addr == (char *)0)
        return -1;

    if(flag == 1)
        offset = sizeof(Link_Info) + sizeof(MsgNumSt) +
                sizeof(FlowCtrlSt) + sizeof(MyQSt);
    else if(flag == 2)
        offset = sizeof(Link_Info)  + sizeof(MsgNumSt) +
                sizeof(FlowCtrlSt) + sizeof(MyQSt)+ SIZE_REQ;
    else if(flag == 3)
        offset = sizeof(Link_Info)  + sizeof(MsgNumSt) +
                sizeof(FlowCtrlSt) + sizeof(MyQSt)+ SIZE_REQ*2;
    else
        offset = sizeof(Link_Info)  + sizeof(NotiMoSt)+ SIZE_REQ*3;

    memcpy(shm_addr+offset, err, sizeof(int) * 21);
    memcpy(shm_addr+offset+sizeof(int)*21, prim, sizeof(int) * 15);
    memcpy(shm_addr+offset+sizeof(int)*36, comp, sizeof(int) * 9);
    memcpy(shm_addr+offset+sizeof(int)*45, &cong, sizeof(int) * 1);
}

void wr_shm_NOTImsgnum(NotiMoSt *p)
{
    int offset;

    if(p == NULL || shmid < 0 || shm_addr == (char *)0)
        return -1;

    offset = sizeof(Link_Info) + SIZE_REQ*3;

    memcpy(shm_addr+offset, p, sizeof(NotiMoSt));
}

*/
