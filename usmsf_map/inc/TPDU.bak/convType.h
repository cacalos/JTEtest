#ifndef __CONV_TYPE_H_
#define __CONV_TYPE_H_
int ConvISDNStringToAddress(ISDN_AddressString *isdn, stAddr *addr);
int ConvAddressToCBString(stAddr *addr, FTN_AddressString *isdn);
int ConvAddressToISDNString(stAddr *addr, ISDN_AddressString *isdn);
int ConvAddressToAddressString(stAddr *addr, AddressString *adstr);
int ConvAddressStringToAddress(AddressString *adstr, stAddr *addr);
int ConvStrToAddressString(int len, char *str, AddressString *adstr);
int ConvAddressStringToStr(AddressString *adstr, int *len, char *str);
int ConvAddressToCenterAddress(stAddr *addr, AddressString *addrSC);
int ConvIMSIToAddress(IMSI *imsi, stAddr *addr);
int ConvAddressToIMSI(stAddr *addr, IMSI *imsi);
#endif
