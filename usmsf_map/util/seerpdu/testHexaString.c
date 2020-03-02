#include <stdio.h>
#include <string.h>
#include <ctype.h>


//-----------------------------------------------------
// input ==> buffer
//-----------------------------------------------------
int makeDataFromHexaString(const char *inString, unsigned char *data)
{
	int i,len;
	int isLSB;
	int ch;
	int temp;

	for(i=0, len=0, isLSB=0; ; i++)
	{
		ch = inString[i];

		if(ch == '\0') 		break;
		if( ! isalnum(ch)) 	continue;
		if(isalpha(ch)) 
			if( (ch>'f') || (ch>'F' && ch<'A')) continue;

		temp = isdigit(ch) 
					? '0' 
					: isupper(ch) ? 'A'-10 : 'a'-10;

		ch -= temp;

		if(isLSB==0)	
			data[len] = (unsigned char)(ch << 4);
		else
			data[len++] |= (unsigned char)(ch & 0x0F);

		isLSB = ~isLSB;
	}

	return isLSB ? len+1 : len;
}

//-----------------------------------------------------
// input ==> stream
//-----------------------------------------------------
int makeDataFromHexaString2(FILE *stream, unsigned char *data)
{
	int i,len;
	int isLSB;
	int ch;
	int temp;

	for(i=0, len=0, isLSB=0; ; i++)
	{
		ch = fgetc(stream);

		if(ch == EOF) 		break;
		if( ! isalnum(ch)) 	continue;
		if(isalpha(ch)) 
			if( (ch>'f') || (ch>'F' && ch<'A')) continue;

		temp = isdigit(ch) 
					? '0' 
					: isupper(ch) ? 'A'-10 : 'a'-10;

		ch -= temp;

		if(isLSB==0)	
			data[len] = (unsigned char)(ch << 4);
		else
			data[len++] |= (unsigned char)(ch & 0x0F);

		isLSB = ~isLSB;
	}

	return isLSB ? len+1 : len;
}


//---------------------------------------------------------
void printHexaString2(const char *data, int dataLen)
{
    int i, j;
    const int cnt = 10;
    unsigned int c[10];
    char buf[100], *ptr;

//    if(dataLen > MAX_BUFFER_SIZE) dataLen = MAX_BUFFER_SIZE;

    for(i=0, ptr=buf; i<dataLen; i++)
    {
        sprintf(ptr, " %02X", (unsigned char)data[i]);
        ptr += strlen(ptr);
        if(i%cnt == (cnt-1))
        {
            sprintf(ptr, "%2s", " ");
            ptr +=2;
            for(j=0; j<cnt; j++)
            {
                if(iscntrl(data[i-(cnt-1)+j]))
                    *(ptr+j) = '.';
                else
                    *(ptr+j) = data[i-(cnt-1)+j];
            }
            *(ptr+j) = '\0';

            printf("\t%s\n", buf);
            ptr = buf;
        }
    }

    if(i%cnt != 0)
    {
        int mod = i%cnt;
        for(j=0; j<cnt-mod; j++)
        {
            sprintf(ptr, " %2s", " ");
            ptr += strlen(ptr);
        }
        sprintf(ptr, "%2s", " ");
        ptr +=2;

        for(j=0; j<mod; j++)
        {
            if(iscntrl(data[i-mod+j]))
                *(ptr+j) = '.';
            else
                *(ptr+j) = data[i-mod+j];
        }
        *(ptr+j) = '\0';

        printf("\t%s\n", buf);
    }
}




#if 0

//-----------------------------------------------------
void main(int argc, char *argv[])
{
	int len;
	int i;
	char buf[1024];
	unsigned char data[1024];

	bzero(data, sizeof(data));
	printf("input hexa decimal string : ");
	fgets(buf, sizeof(buf), stdin);
	len = makeDataFromHexaString(buf, data);
	printf("len = [%d]\n", len);
	for(i=0; i < len; i++)
		printf("%02X ", data[i]);
	printf("\n");

	bzero(data, sizeof(data));
	printf("input hexa decimal string2 [end == ctrl+D] : ");
	len = makeDataFromHexaString2(stdin, data);
	printf("len = [%d]\n", len);
	for(i=0; i < len; i++)
		printf("%02X ", data[i]);
	printf("\n");

	printf("[%s]\n", data);
}

#endif
