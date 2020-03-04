#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <RPDU/RPDU.h>

int MakeRPDU(
		char msgType, char direction, int cc, stAddr *addr,  
		char *tpdu, int tpdu_len, unsigned char refNo,
		int *rpdu_len, char *rpdu_data)
{
	int 					len = 0;
	char 					buf[512], type[16];
	char 					smscName[128];
	_RPDU					rpdu;

	if(msgType == MSG_DATA)
		strcpy(type, "RP-DATA");
	else if(cc != 0)
		strcpy(type, "RP-ERROR");
	else
		strcpy(type, "RP-ACK");

	uaLog(L_INFO, "Make RPDU, type[%s], direction[%s], tpdu len[%d], msgRef[%d] ", 
			type, direction == DIRECTION_N_MS ? "SMSC-->UE" : "UE-->SMSC",
			tpdu_len, refNo);

	memset(&rpdu, 0, sizeof(_RPDU));
	memset(buf, 0, sizeof(buf));

	rpdu.direction = direction;
	rpdu.MessageReference = refNo;

	if(msgType == MSG_DATA)
	{
		rpdu.MessageType = RPDU_RP_DATA;

		if(direction == DIRECTION_N_MS)
		{
			if(addr->len > 0)
			{
				memcpy(&rpdu.Union.rData.OrigAddr, addr, sizeof(stAddr));
			}
			else
			{
				strcpy(smscName, "821012345678");
				rpdu.Union.rData.OrigAddr.ton = TON_INTERNATIONAL;
				rpdu.Union.rData.OrigAddr.npi = NPI_E164;
				strcpy((void *)rpdu.Union.rData.OrigAddr.min, smscName);
				rpdu.Union.rData.OrigAddr.len = strlen((void *)rpdu.Union.rData.OrigAddr.min);
			}
		}
		else 
		{
			rpdu.Union.rData.DestAddr.ton = addr->ton;
			rpdu.Union.rData.DestAddr.npi = addr->npi;
			if(addr->len > 0) 
			{
				strcpy((void *)rpdu.Union.rData.DestAddr.min, smscName);
				rpdu.Union.rData.DestAddr.len = strlen((void *)rpdu.Union.rData.DestAddr.min);
			}
		}
		rpdu.Union.rData.RpDataLength = tpdu_len;
		memcpy(rpdu.Union.rData.RpUserData, tpdu, tpdu_len);
	}
	else
	{
		if(cc != 0)
		{
			rpdu.MessageType = RPDU_RP_ERROR;

			rpdu.Union.rError.RpDataLength = 0;
			rpdu.Union.rError.CauseCode.len = 1;
			rpdu.Union.rError.CauseCode.cause = GetRPErrorCauseCode(cc);
			rpdu.Union.rError.CauseCode.diagnostic = 0;
		}
		else
		{
			rpdu.MessageType = RPDU_RP_ACK;
			rpdu.Union.rAck.RpDataLength = 0;
		}
	}

	len = EncodeRPDU((void *)buf, &rpdu, RPDU_FALSE);
	if(len < 0)
	{
		uaLog(L_CRT, "EncodeRPDU() Fail, " );
		return IXERR;
	}

	memcpy(rpdu_data, buf, len);
	*rpdu_len = len;

	return IXOK;
}
