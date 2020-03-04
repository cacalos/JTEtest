
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/dir.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <ua_log.h>
#include <iXtypes.h>
#include <iXUtil.h>
/* 하아.. KT SMSC는 SMCI/SMPP의 경우 New Session Bind 요청시, MAX Session 초과시에는
   Old Session (가장 오래된) 을 KILL 때리고, New Session의 연결 요청을 허용해주는
   괴랄한 로직이 존재한다.
   HP-UX 에서는 API로 프로세스의 기동 시간을 확인 할 수 있는데, 리눅스는 얄짤없이 /proc/[pid]/stat
   을 읽어서 확인해야 하나 부다...
*/

int getStartTimeFromPid(unsigned int pid, time_t *sTime)
{
	int len = 0;
	char path[128], buff[1024]; //buff was cat /proc/[pid]/stat ... buffer. 딱 한라인~ 1024 넘기기 힘들어여~~
	char *ptr = NULL;
	FILE *fp = NULL;
	struct stat st;

	sprintf(path, "/proc/%u", pid);

	if(stat(path, &st) < 0)
	{
		uaLog(L_CRT, "Can't Find PID<%u> Information", pid);
		return IXERR;
	}

	//존재하는거면 읽음되여
	//귀찮으니까 다시 sprintf
	sprintf(path, "/proc/%u/stat", pid);

	if((fp = fopen(path, "r")) == NULL)
	{
		uaLog(L_CRT, "FILE Open Fail [%s]", path);
		return IXERR;
	}

	len = sizeof(buff) - 1; //NULL exception? 해주는게 맞나?
	//read line
	if((ptr = fgets(buff, len, fp)) == NULL)
	{
		uaLog(L_CRT, "Read Fail [%s]", path);
		fclose(fp);
		return IXERR;
	}

	//22번째 필드가 starttime 인데,, 확인해보니까 OS 기동시간 이후 time 인거 같은데?? 꼬라지가 밀리세컨드 같은데...
	//index로는 21번째겠죠? 0부터 시작이니까.. 자세한 사항은 man proc 으로 stat 파트를 읽어보도록 허자.

	uaLog(L_DBG, "Read Buffer [%s]", buff);

	len = 0;
	ptr = strtok(buff, " "); //Space 로 split 친다.
//	uaLog(L_DBG, "[%02d] %s", len++, ptr);
	len++;
	while((ptr = strtok(NULL, " ")) != NULL)
	{
		if(len == N_PROCCESS_START_TIME_INDEX) //21 then
		{
			*sTime = atoll(ptr); 
			uaLog(L_DBG, "TIME GET !!! [%s, %lu]", ptr, *sTime);
			fclose(fp);
			return IXOK;
		}

//		uaLog(L_DBG, "[%02d] %s", len++, ptr);
		len++;
	}

	

	fclose(fp);

	return IXERR;
}

