
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include <iXtypes.h>
#include <TPDU/TPDU.h>
#include <ASN/asn_smsc.h>

#define MAX_BUFFER_SIZE	2048


int main(int argc, char *argv[])
{
	int                  len;
	int                  nFrom;
	int                  tpduType;
	int                  elementCnt;
	char                 temp[10];
	byte                 buffer[MAX_BUFFER_SIZE];
	unsigned char        fcs;
	_TPDU                tpdu;
	boolean              isRPError = TPDU_FALSE;

	bzero((void *)buffer, sizeof(buffer));
	bzero((void *)&tpdu, sizeof(_TPDU));

	printf("\tsee tpdu v0.1\n");

	printf("choose  [from 1:sc 2:ms] == "); 
	fgets(temp, sizeof(temp), stdin);
	if(atoi(temp)==1) 
		nFrom = DIRECTION_SC_MS;
	else
		nFrom = DIRECTION_MS_SC;

	printf("\ninput hexa decimal string [end == ctrl+D] : ");
	len = makeDataFromHexaString2(stdin, buffer);
	printf("\n\nDATA LENGTH : [%d]\n", len);
	tpduType = GetTPDUMessageType((byte *)buffer, nFrom);
	if( (tpduType == TPDU_SMS_DELIVER_REPORT)
		|| (tpduType == TPDU_SMS_SUBMIT_REPORT) )
	{
		printf("isRPError [true|false] :  "); 
		fgets(temp, sizeof(temp), stdin);
		isRPError = (!strncasecmp(temp, "true", 4)) ? TPDU_TRUE : TPDU_FALSE;
	}

	len = DecodeTPDU(&tpdu, (byte *)buffer, len, nFrom, isRPError);
	if(len < 0) 
	{
		printf("\nerror ret[%d]\n", len);
		exit(EXIT_FAILURE);
	}

	printTpdu(&tpdu);

	if(checkTpdu(&tpdu, &fcs) != IXOK)
	{
		printf("\ncheckTpdu Error!! fcs[%d]\n", fcs);
		exit(EXIT_FAILURE);
	}
	printf("\ncheckTpdu Success!!\n");

	if(argc > 1)
	{
		printf("\n### after checkTpdu ###\n");
		printTpdu(&tpdu);
		printf("\n#######################\n");
	}

	exit(EXIT_SUCCESS);
}

