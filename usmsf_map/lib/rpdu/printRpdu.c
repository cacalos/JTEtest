
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <RPDU/RPDU.h>
#include <RPDU/rpdu_err.h>
#include <iXtypes.h>

int printHexaStringRpdu(char *data, int dataLen, char *str)
{
    int i, j, len;
    const int cnt = 10;
    unsigned int c[10];
	char *pos;
    char buf[100], *ptr;

	pos = str;
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

            len = sprintf(pos, "%s\n", buf);
			pos += len;
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

        len = sprintf(pos, "%s\n", buf);
		pos += len;
    }

	return (pos - str);
}

int printRpdu(_RPDU *rpdu, char *str)
{
	int 		i, len, tLen;
	char 		*pos;

	pos = str;

	tLen = sprintf(pos, "[RP MESSAGE]\n\
Type                : %d-%s(%s)\n\
Reference           : %d",
		rpdu->MessageType,
		rpdu->MessageType == RPDU_RP_DATA  ? "RP_DATA" :
		rpdu->MessageType == RPDU_RP_ERROR ? "RP_ERROR" :
		rpdu->MessageType == RPDU_RP_ACK   ? "RP_ACK" :
		rpdu->MessageType == RPDU_RP_SMMA  ? "RP_SMMA" : "RP_RESERVED",
		rpdu->direction == DIRECTION_MS_N ? "MS --> N" : "N --> MS",
		rpdu->MessageReference);

	if(rpdu->MessageType == RPDU_RP_DATA)
	{
		pos += tLen;
		tLen = sprintf(pos,"\n\
Originator Address  : %s\n\
Destination Address : %s\n\
Data Length         : %d\n\
Data                : \n",
			rpdu->Union.rData.OrigAddr.len == 0 ? " " : (void *)rpdu->Union.rData.OrigAddr.min,
			rpdu->Union.rData.DestAddr.len == 0 ? " " : (void *)rpdu->Union.rData.DestAddr.min,
			rpdu->Union.rData.RpDataLength);

		pos += tLen;
		for(i = 0; i < rpdu->Union.rData.RpDataLength; i++) 
		{
			pos += sprintf(pos, "%02X", rpdu->Union.rData.RpUserData[i]);
		}
	}
	else if(rpdu->MessageType == RPDU_RP_ACK)
	{
		if(rpdu->Union.rAck.RpDataLength > 0)
		{
			pos += tLen;
			tLen = sprintf(pos,"\n\
Element ID          : 0x%X\n\
Data Length         : %d\n\
Data                : \n",
				rpdu->Union.rAck.ElementId,
				rpdu->Union.rAck.RpDataLength);

			pos += tLen;
			for(i = 0; i < rpdu->Union.rAck.RpDataLength; i++) 
			{
				pos += sprintf(pos, "%02X", rpdu->Union.rAck.RpUserData[i]);
			}
		}
	}
	else if(rpdu->MessageType == RPDU_RP_ERROR)
	{
		pos += tLen;
		tLen = sprintf(pos,"\n\
Error Cause Code    : 0x%X(%s)\n\
Diagnostic          : %d\n\
Data Length         : %d\n\
Data                : \n",
			rpdu->Union.rError.CauseCode.cause, RPDU_ERROR_STR(rpdu->Union.rError.CauseCode.cause),
			rpdu->Union.rError.CauseCode.diagnostic,
			rpdu->Union.rError.RpDataLength);

		if(rpdu->Union.rError.RpDataLength > 0)
		{
			pos += tLen;
			for(i = 0; i < rpdu->Union.rError.RpDataLength; i++) 
			{
				pos += sprintf(pos, "%02X", rpdu->Union.rError.RpUserData[i]);
			}
		}
	}
	else if(rpdu->MessageType == RPDU_RP_SMMA)
	{
	}

	return 1;
}

