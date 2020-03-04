//add by okh
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <TPDU/okhTypes.h>

//---------------------------------------------------------
//
//---------------------------------------------------------
void RTrim(char *szString)
{
    int nLen, i;
    nLen = strlen(szString);

    for(i=nLen-1; (i>=0) && ((szString[i]==' ') || (szString[i]=='\t')); i--);

    szString[i+1] = '\0';
}

//---------------------------------------------------------
//
//---------------------------------------------------------
void LTrim(char *szString)
{
    int nLen, i, pos;
    nLen = strlen(szString);

    for(i=0; (i<nLen) && ((szString[i]==' ') || (szString[i]=='\t')); i++);
    pos =i;
    for( ; i<nLen; i++)
    {
        szString[i-pos] = szString[i];
    }

    szString[nLen-pos] = '\0';
}

//---------------------------------------------------------
//
//---------------------------------------------------------
void Trim(char *szString)
{
    RTrim(szString);
    LTrim(szString);
}

//---------------------------------------------------------
//
//---------------------------------------------------------
//szString에 Token 에 해당하는 문자가 몇개 들어있는지 카운트하는 함수
int TokenCount(char *szString, char Token)
{
    int i;
    int nTokenCount=0;

    for(i=0; szString[i] != '\0'; i++)
    {
        if(szString[i] == Token)    nTokenCount++;
    }

    return nTokenCount;
}

//---------------------------------------------------------
//
//---------------------------------------------------------
char *Split(char *szString, char Token, int nOffset, char *szResult)
{
    int Count=0;
    int i=0;
    int j=0;

    if(nOffset ==0)
    {
        for(j=0; (szString[i+j] != Token) && (szString[i+j] != '\0'); j++)
        {
            szResult[j] = szString[i+j];
        }
        szResult[j] = '\0';
        return &szString[i];
    }


   
    for(i=0; szString[i] != '\0'; i++)
    //while(szString[i++] != '\0')
    {
        if(szString[i] == Token) Count++;
        if(Count == nOffset)
        {
            for(j=0; (szString[i+1+j] != Token) && (szString[i+1+j] != '\0'); j++)
            {
                szResult[j] = szString[i+1+j];
            }
            szResult[j] = '\0';

            return &szString[i];
        }

    }

    return NULL;
}


//---------------------------------------------------------
//
//---------------------------------------------------------
int getConf(char *file, char *conf, char *data)
{
	FILE      *fp;
	char      buf[4096];
	char      *ptr;
	char	  tag[100];

	if((fp = fopen(file, "r")) == NULL)
	{
		printf("[Error] %s file open\n", file);
		return -1;
	}

	while(fgets(buf, 4096, fp) != NULL)
	{
		if(buf[0] == '#' || buf[0] == '\n')
            continue;

        ptr = &buf[strlen(buf)-1];
        if(*ptr == '\n') *ptr =  '\0';

        Split(buf, '=', 0, tag);
        Trim(tag);
        if(strcasecmp(tag, conf) == 0)
        {
            Split(buf, '=', 1, data);
            Trim(data);

            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    printf("[%s] tag not found", conf);
    return -1;
}

//---------------------------------------------------------
//
//---------------------------------------------------------
int ok_getConf(char *fileName, char *conf, void *data, int isNumber)
{
	char buf[1024];
	int nTemp;
	int ret;

	if ((ret = getConf(fileName, conf, buf)) < 0)
	{
		printf("[X] CONFIG LOAD FAIL :  [%s]\n", conf);
		return -1;
	}
			
	if(isNumber == TPDU_TRUE)
	{
		sscanf(buf, "%i", &nTemp);
		*(int *)data = nTemp;

		//printf("[O] CONFIG LOAD SUCCESS :  [%s]=[%d]", conf, *(int *)data);
	}
	else
	{
		strcpy((char *)data, buf);
		//printf("[O] CONFIG LOAD SUCCESS :  [%s]=[%s]", conf, (char *)data);
	}

	return 0;
}

//    ret = cb_getConf(fileName, CBS_CONFIG_MAX_TIME_CONNECT, &nTemp, TPDU_TRUE);
 //   if(ret == 0)    statPtr->cnxTime = nTemp;


//---------------------------------------------------------
//FormatDateTime의 새버전
//---------------------------------------------------------
int formatTime(char *outString, int maxsize, char *format)
{
    time_t curr;
    struct  tm *tm;

    time(&curr);

    tm = localtime(&curr);
    if(tm == NULL)
    {
        printf("[X] LOCALTIME ERROR!!");
        outString[0] = '\0';
        return -1;
    }
    strftime(outString, maxsize, format, tm);

    return 0;
}

//---------------------------------------------------------
//
//---------------------------------------------------------
int myDump(unsigned char *data, int len, char *output)
{
    int i;
    char buf[10];

    output[0]='\0';
    for(i=0; i<len; i++)
    {
        sprintf(buf, "%02X ", data[i]);
        strcat(output, buf);

        if(((i%10)==9)) output[(i+1)*3-1] = '\n';
    }

    return strlen(output);
}
