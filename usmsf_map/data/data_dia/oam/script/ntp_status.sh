#!/usr/bin/sh

OAM_DATA=${UASYS_HOME}/data/oam/logstat
mkdir -p $OAM_DATA

NTP_STATUS_FILE=$OAM_DATA/ntp_status.sts
TMP_FILE=$OAM_DATA/ntp_status.tmp

result=`systemctl is-active chronyd | grep -v inactive | grep active | wc -l`

if [ "0" == $result ] ; then
	echo "FAILURE" > $TMP_FILE
else
	echo "OK" > $TMP_FILE
fi

echo "END_DATA" >> $TMP_FILE

mv -f $TMP_FILE $NTP_STATUS_FILE
