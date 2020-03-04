
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include <iXtypes.h>
#include <RPDU/RPDU.h>
#include <TPDU/TPDU.h>
#include <TPDU/checkTpdu.h>
#include <ASN/asn_smsc.h>

#define MAX_BUFFER_SIZE	2048


int main(int argc, char *argv[])
{
	int                  len;
	int                  nFrom;
	int                  rpduType;
	int                  elementCnt;
	char                 temp[10];
	byte                 buffer[MAX_BUFFER_SIZE];
	unsigned char        fcs;
	_RPDU                rpdu;
	_TPDU                tpdu;

	bzero((void *)buffer, sizeof(buffer));
	bzero((void *)&rpdu, sizeof(_RPDU));

	printf("\tsee rpdu v0.1\n");

	printf("choose  [from 1:sc 2:ms] == "); 
	fgets(temp, sizeof(temp), stdin);
	if(atoi(temp)==1) 
		nFrom = DIRECTION_N_MS;
	else
		nFrom = DIRECTION_MS_N;

	printf("\ninput hexa decimal string [end == ctrl+D] : ");
	len = makeDataFromHexaString2(stdin, buffer);
	printf("\n\nDATA LENGTH : [%d]\n\n", len);
	rpduType = GetRPDUMessageType((byte *)buffer, nFrom);

	len = DecodeRPDU(&rpdu, (byte *)buffer, len, nFrom);
	if(len < 0) 
	{
		printf("\nerror ret[%d]\n", len);
		exit(EXIT_FAILURE);
	}

	printf("\n >>>>>>>> RPDU Decoding Result \n\n");
	seePrintRpdu(&rpdu);

	if(rpduType == RPDU_RP_DATA) 
	{
		len = DecodeTPDU(&tpdu, (byte *)rpdu.Union.rData.RpUserData, rpdu.Union.rData.RpDataLength, nFrom, 0);
		if(len < 0)
		{
			printf("\nerror ret[%d]\n", len);
			exit(EXIT_FAILURE);
		}

		printf("\n >>>>>>>> TPDU Decoding Result \n\n");
		printTpdu(&tpdu);
	}


	if(argc > 1)
	{
		printf("\n### after checkRpdu ###\n");
		seePrintRpdu(&rpdu);
		printf("\n#######################\n");
	}

	exit(EXIT_SUCCESS);
}

