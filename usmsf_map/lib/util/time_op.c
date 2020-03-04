
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/un.h>

#include <sys/time.h>
#include <sys/times.h>
#include <time.h>

#include <iXtypes.h>

#define ENGINE_WAIT_TIME                   70000

int sec_ellapsed(int max_gap)
{
    int                gap;
    static time_t      first, second;

    time(&second);
    gap = (int)(second - first);
    if(max_gap <= gap)
    {
        first = second;
        return IXOK;
    }
    else
        return IXERR;
}


int m_sec_ellapsed(int msec)
{
    int              c, d, gap;
    long             n_sec, n_usec;
    static long      sec, usec;
    struct timeval   now;
    struct timezone  tz;

    gettimeofday(&now, &tz);
    n_sec = now.tv_sec;
    n_usec = now.tv_usec;    
    c = (int) ((long)n_sec - (long)sec);
    d = (int) ((long)n_usec - (long)usec);
    gap = c * 1000000 + d;

    if(sec == 0 || gap >= msec)
    {
        sec = n_sec;
        usec = n_usec;
        return IXOK;
    }
    else
        return IXERR;
}


void SleepForAWhile()
{
    struct timeval    waitTime;

    waitTime.tv_sec = 0;
    waitTime.tv_usec = ENGINE_WAIT_TIME;

    select(0, 0, 0, 0, &waitTime);
}


int EncodeTimeZone(int TimeZone)
{
    if(TimeZone < 0)
    {
        TimeZone = -TimeZone;
        /* TimeZone = ((TimeZone/10) | 0x08) | ((TimeZone % 10) << 4); */
        TimeZone = (TimeZone/10) |  ((TimeZone % 10) << 4);
    }
    else
        TimeZone = ((TimeZone/10) | 0x08 ) | ((TimeZone%10)<<4);

    return TimeZone;
}
