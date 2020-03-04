#ifndef __CHECKTPDU_H__
#define __CHECKTPDU_H__

#include <TPDU/TPDU.h>

int checkTpdu_status(byte st, byte *fcs);
int checkTpdu_VP(byte vpf, byte *value, byte *fcs);
int checkTpdu_HeaderElement(stEI *pei);
int checkTpdu_UserData(int headerIndi, TUserData *userData, byte *fcs);
int checkTpdu(_TPDU *tpdu, byte *fcs);
int checkTpdu_pid(byte pid, byte *causeCode);
int checkTpdu_dcs(byte *dcs, byte *causeCode);
int checkTpdu_commandType(byte commandType, byte srr, byte *causeCode);

#endif
