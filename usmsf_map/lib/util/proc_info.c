
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
/* �Ͼ�.. KT SMSC�� SMCI/SMPP�� ��� New Session Bind ��û��, MAX Session �ʰ��ÿ���
   Old Session (���� ������) �� KILL ������, New Session�� ���� ��û�� ������ִ�
   ������ ������ �����Ѵ�.
   HP-UX ������ API�� ���μ����� �⵿ �ð��� Ȯ�� �� �� �ִµ�, �������� ��©���� /proc/[pid]/stat
   �� �о Ȯ���ؾ� �ϳ� �δ�...
*/

int getStartTimeFromPid(unsigned int pid, time_t *sTime)
{
	int len = 0;
	char path[128], buff[1024]; //buff was cat /proc/[pid]/stat ... buffer. �� �Ѷ���~ 1024 �ѱ�� ����~~
	char *ptr = NULL;
	FILE *fp = NULL;
	struct stat st;

	sprintf(path, "/proc/%u", pid);

	if(stat(path, &st) < 0)
	{
		uaLog(L_CRT, "Can't Find PID<%u> Information", pid);
		return IXERR;
	}

	//�����ϴ°Ÿ� �����ǿ�
	//�������ϱ� �ٽ� sprintf
	sprintf(path, "/proc/%u/stat", pid);

	if((fp = fopen(path, "r")) == NULL)
	{
		uaLog(L_CRT, "FILE Open Fail [%s]", path);
		return IXERR;
	}

	len = sizeof(buff) - 1; //NULL exception? ���ִ°� �³�?
	//read line
	if((ptr = fgets(buff, len, fp)) == NULL)
	{
		uaLog(L_CRT, "Read Fail [%s]", path);
		fclose(fp);
		return IXERR;
	}

	//22��° �ʵ尡 starttime �ε�,, Ȯ���غ��ϱ� OS �⵿�ð� ���� time �ΰ� ������?? �������� �и������� ������...
	//index�δ� 21��°����? 0���� �����̴ϱ�.. �ڼ��� ������ man proc ���� stat ��Ʈ�� �о���� ����.

	uaLog(L_DBG, "Read Buffer [%s]", buff);

	len = 0;
	ptr = strtok(buff, " "); //Space �� split ģ��.
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

