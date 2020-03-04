
#include <iXtypes.h>
#include <RPDU/RPDU.h>

int seePrintRpdu(_RPDU *rpdu)
{
	int         i, len, tLen;
	char		buf[256];

	printf( "[RP MESSAGE]\n\
      Type        : %d (%s, %s)\n\
      Reference   : %d",
			rpdu->MessageType,
			rpdu->MessageType == RPDU_RP_DATA  ? "RP_DATA" :
			rpdu->MessageType == RPDU_RP_ERROR ? "RP_ERROR" :
			rpdu->MessageType == RPDU_RP_ACK   ? "RP_ACK" :
			rpdu->MessageType == RPDU_RP_SMMA  ? "RP_SMMA" : "RP_RESERVED",
			rpdu->direction == DIRECTION_MS_N ? "MS --> N" : "N --> MS",
			rpdu->MessageReference);

	if(rpdu->MessageType == RPDU_RP_DATA)
	{
		printf("\n\
      Orig MIN    : %s\n\
           LEN    : %d\n\
           TON    : %d\n\
           NPI    : %d\n\
      Dest MIN    : %s\n\
           LEN    : %d\n\
           TON    : %d\n\
           NPI    : %d\n\
      Data Length : %d\n",
			rpdu->Union.rData.OrigAddr.len == 0 ? " " : rpdu->Union.rData.OrigAddr.min,
			rpdu->Union.rData.OrigAddr.len == 0 ? 0 : rpdu->Union.rData.OrigAddr.len,
			rpdu->Union.rData.OrigAddr.len == 0 ? 0 : rpdu->Union.rData.OrigAddr.ton,
			rpdu->Union.rData.OrigAddr.len == 0 ? 0 : rpdu->Union.rData.OrigAddr.npi,
			rpdu->Union.rData.DestAddr.len == 0 ? " " : rpdu->Union.rData.DestAddr.min,
			rpdu->Union.rData.DestAddr.len == 0 ? 0 : rpdu->Union.rData.DestAddr.len,
			rpdu->Union.rData.DestAddr.len == 0 ? 0 : rpdu->Union.rData.DestAddr.ton,
			rpdu->Union.rData.DestAddr.len == 0 ? 0 : rpdu->Union.rData.DestAddr.npi,
			rpdu->Union.rData.RpDataLength);
		for(i = 0; i < rpdu->Union.rData.RpDataLength; i++)
			printf("%02X", rpdu->Union.rData.RpUserData[i]); 
	}
	else if(rpdu->MessageType == RPDU_RP_ACK)
	{
	}
	else if(rpdu->MessageType == RPDU_RP_ERROR)
	{
		printf("\n\
      LEN         : %d\n\ 				
      CauseCode   : %d\n\
      Diagnostic  : %d\n",  rpdu->Union.rError.CauseCode.len, 
	  		rpdu->Union.rError.CauseCode.cause, rpdu->Union.rError.CauseCode.diagnostic);
	}
	else if(rpdu->MessageType == RPDU_RP_SMMA)
	{
	}

	printf("\n\n");

	return 1;
}

