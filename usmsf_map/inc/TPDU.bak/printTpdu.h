#ifndef __PRINT_TPDU_H_
#define __PRINT_TPDU_H_

#include <TPDU/TPDU.h>

int printHexaStringTpdu(char *data, int dataLen, char *str);
int printTpdu_userDataHeader(stUDH *header, char *userHeader);
int printTpdu_userData(TUserData *data, byte headerIndi, char *userData);
int printTpdu_deliver(TSMSDeliver *tpdu, char *str);
void printTpdu_deliverReport(TSMSDeliverReport *tpdu);
int printTpdu_submit(TSMSSubmit *tpdu, char *str);
void printTpdu_submitReport(TSMSSubmitReport *tpdu);
void printTpdu_statusReport(TSMSStatusReport *tpdu);
int printTpdu_command(TSMSCommand *tpdu, char *str);
int printTpdu(_TPDU *tpdu, char *str);

#endif
