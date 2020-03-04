#!/bin/sh

#if [ $# -lt 1 ] ; then
#    echo "usage: $0 system_group"
#    exit -1
#fi

system_group="FEP"

mmc_file_path=${UASYS_HOME}/log/dbdata/mmc
mkdir -p $mmc_file_path

user_levels=
user_levels=$user_levels"MMC_GUEST "
user_levels=$user_levels"MMC_NORMAL "
user_levels=$user_levels"MMC_SUBSCRIBER "
user_levels=$user_levels"MMC_SUPER "

mmc_table="CF_mmc_group"

for level in $user_levels ; do
	outfile=$mmc_file_path/$system_group.MMC_GROUP.$level.mmc

	echo "# make mmc_group file: "$outfile
    ResetMMC -l | grep $level | awk '{ print $2 }' > $outfile

	if [ $? -ne 0 ] ; then
		echo "Failed to make mmc group file"
		exit $?
	fi
done


echo
outfile=$mmc_file_path/$system_group.MMC_INFO.XML.mmc
echo "# make mmc_info file: "$outfile

ResetMMC -x
if [ $? -ne 0 ] ; then
	echo "Failed to make mmc info file"
	exit $?
fi
cp -f cmd.xml $outfile
rm -f cmd.xml

echo
outfile=$mmc_file_path/$system_group.MMC_CMD.JSON.mmc
echo "# make mmc_info JSON file: "$outfile

ResetMMC -j
if [ $? -ne 0 ] ; then
	echo "Failed to make mmc info JSON file"
	exit $?
fi
cp -f cmd.json $outfile
rm -f cmd.json

echo
outfile=$mmc_file_path/$system_group.MPLIST.HOST.mmc
echo "# make mplist_info file: "$outfile

myhostname=`ResetMMC -m`
echo "MPLIST_INFO : GROUP($system_group), HOST($myhostname)"
echo "$myhostname" > host_info
cp -f host_info $outfile
rm -f host_info

echo 
echo "Success update mmc info."

