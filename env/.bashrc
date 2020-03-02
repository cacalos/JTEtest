# .bashrc

# Source global definitions
#if [ -f /etc/bashrc ]; then
#	. /etc/bashrc
#fi

# Uncomment the following line if you don't like systemctl's auto-paging feature:
# export SYSTEMD_PAGER=

export GO111MODULE=on
export GOPROXY=direct
export GOSUMDB=off

function sys_env()
{
    export TERM=xterm
	LANG=ko_KR.UTF-8
    export LC_ALL=ko_KR.UTF-8
    export LS_COLORS="ln=01;34:di=01;33:*.gz=01;35:*.Z=01;35:*.tar=01;31:*.c=01;33:*.h=01;33:*.cc=01;33:*.hh=01;33:"
    #export EDITOR="vim -X"
    #export FIGNORE=.o:.bak:.dvi:.aux
    export FIGNORE=.o:.dvi:.aux
    export PKG_HOME=$HOME/home
	export CDPATH=.:..:~:~/src

    PS1="`hostname` [`whoami`{\!} `dirs` ] "
    if [ -t 0 ] ; then
        stty -istrip
        set pass8
        stty intr ^C
        stty erase ^H
        stty kill ^U
        stty echoe
        stty hupcl ixon ixoff -istrip -parenb cs8 echo
    fi
    # sjkim :64ºñ¡¼­´Â/usr/binÀ ¿켱Ç¾ßѴÙ
    export PATH=~/HOME/bin:/usr/bin:/usr/local/bin:/bin:/usr/sbin:~/bin:/usr/bin/X11:/usr/local/samba/bin:/usr/contrib/bin/X11/:/usr/dt/bin:/opt/imake/bin:/usr/contrib/bin:~/HOME/bin:/opt/langtools/bin:/opt/aCC/bin:/opt/audio/bin:/opt/vim/bin:/usr/ccs/bin:/usr/local/mysql/bin:.:..:~/uaoss/uaoam/tools:~/script/:~/hun/script/db_tool:/sbin:$HOME/srg/tools:$HOME/srg/bin:/usr/local/go/bin:$HOME/go/bin

    ulimit -c unlimited
    umask 022
}

function alias_env()
{
	alias   dnif='iXseeRouteTable'
    alias   a=alias
    alias   c=clear
    alias   g='grep'
    alias   m=more
    alias   u=unalias
    alias   cp='cp -i'
    alias   rm='rm -i'
    alias   mv='mv -i'
    alias   cls=clear
    alias   l='ls -al'
    alias   la='ls -a'
    alias   ll='ls -l'
    alias   ls='ls -CsF --color=auto'
    alias   cx='chmod +x'
    alias   lo=logout
    alias   bye=logout
    alias   vt100='export TERM=vt100'
    alias   HP='export TERM=HP'
    alias   hp='export TERM=hpterm'
    alias   ngrep='netstat  -na | grep'
    alias   pgrep='ps -ef | grep'
    alias   cd..='cd ..'
    alias   .='echo $cwd'
    alias   ..='set dot=$cwd ; cd ..'
    alias   ,='cd $dot '
    alias   cdact='cd ~/src/sim/actest'
    alias   cduangin='cd ~/UAHLR/UANGIN'
    alias   cdlogic='cd ~/UANGIN/src/sce/scp/unicbs'
    alias   grc='find . -name "*.c" -print | xargs grep '
    alias   grh='find . -name "*.h" -print | xargs grep '
    alias   grg='find . -name "*.go" -print | xargs grep '
    alias   gra='find . -name "*" -print | xargs grep '
    alias   cdm='cd ~/home/log/maptrc'
    alias   cdl='cd ~/home/log/'
    alias   b='\cp -p *.c tmp'
    alias   gdb='gdb -q'
    #alias   vi='vim -X'
    alias   cube='telnet 192.168.1.114'
    alias   cvu='cvs update'
    alias   l='ls -la'
    alias   pgrep='ps -ef | grep'
    alias   ngrep='netstat -na | grep'
    alias   cdualib='cd ~/UALIB'
    alias   cdoam='cd ~/OAM'
    alias   coam='cd ~/OAM/src'
	alias   cinc='cd ~/UALIB/include'
    alias   cbin='cd ~/HOME/bin'
    alias   clib='cd ~/HOME/lib'
    alias   cdata='cd ~/HOME/data'
    alias   ctrc='cd ~/HOME/log/TRACE'
    alias   cmml='cd ~/HOME/data/MML_INFO'
    alias   clog='cd ~/HOME/log'
    alias   so='source $HOME/.bashrc'
    alias   cvss='cvs -Q status | awk -f ~/scripts/cvsstatus'
    alias   gopps='cd ~/SKTSVC/src/DBSERV/ppserv'
    alias   govpn='cd ~/SKTSVC/src/DBSERV/vpnserv'
    alias   goenv='cd ~/SKTSVC/src/DBSERV/envserv'
    alias   gotrf='cd ~/SKTSVC/src/DBSERV/trfserv'
    alias   gopromo='cd ~/SKTSVC/src/DBSERV/promoserv'
    alias   gomib='cd ~/SKTSVC/src/NE/smscmib'
    alias   gobib='cd ~/SKTSVC/src/NE/smscbib'
    alias   local='cd ~/SKTSVC/local'
    alias   run='source ~/.bashrc'
    alias   goslp='cd ~/UANGIN/src/sce/scp/ckt'
    alias   gone='cd ~/SKTSVC/src/NE'
    alias   include='cd ~/UALIB/include'
    alias   congo='ssh cktip@congoip'
    alias   gopadia='cd ~/UANGEL/UANGN/UXCUTOR/src/padapters/dia'
    alias   godia='cd ~/UANGEL/UANGN/udia'
    alias   godiastack='cd ~/UANGEL/UANGN/udia/src/stack'
    alias   goparad='cd ~/UANGEL/UANGN/UXCUTOR/src/padapters/rad'
    alias   gopirad='cd ~/UANGEL/UANGN/UXCUTOR/src/plugins/uxcpt/rad'
    alias   gorad='cd ~/UANGEL/UANGN/urad'
    alias   goradstack='cd ~/UANGEL/UANGN/urad/src/stack'
    alias   gouxcutor='cd ~/UANGEL/UANGN/UXCUTOR'
    alias   gopcapd='cd ~/TKSM2M_SVC/src/NE/pcapd'
    alias   csrg='cd $USRG_PKG_ROOT/SRG/config'
    alias   goasn='cd ~/UANGEL/UANGN/uasn'
    alias   gotcap='cd ~/UANGEL/UANGN/uxtcap'
    alias   gosim='cd ~/UANGEL/UANGN/UXCIM'
	alias   deldb='mmdb_sql2 uatrnsdb < ~/home/scripts/sql/del_msg'
	alias	sql='mmdb_sql2'
	alias	showalarm='cat $HOME/HOME/log/omsib/rts/omsib.RTS.CURRENT_ALARM.rts'
	alias 	dcore='find . -name "core.*" -print -exec rm -f {} \;'
	alias   cdadif='cd ~/go/src/camel.uangel.com/ua5g/uaimgs'
	alias   cu='cd ~/go/src/uangel.com/usmsf'

}

# User specific aliases and functions
function smsc_env()
{
	export SMSC_HOME=$HOME/home
	export SMS_CONFIG_DIR=$HOME/home/config
	export SMS_DATA_DIR=$HOME/home/data
	export SMS_BILL_DIR=$HOME/home/smcdr
	export SMS_BIN_DIR=$HOME/home/bin
#	export SMS_STAT_DIR=$HOME/home/stat
	export SMS_STAT_DIR=/tmp/stat
	export TRACE_HOME_ENV_NAME=/tmp/trace
	export EM_HOST=localhost:9090

	
	export MCTC_CONFIG_DIR=$HOME/home/data
	export MCTC_STAT_DIR=$HOME/home/stat
	export MCTC_BACKUP_DIR=$HOME/home/mmdb
	export UASYS_HOME_ENV_NAME=$HOME/home
	export STAT_HOME_ENV_NAME=/tmp/stat
	export MCTC_BIN_DIR=$HOME/home/bin

	export SMS_SRC_DIR=$HOME/src
	export SMSC_SRC_HOME=$HOME/src
	export SMS_BINARY_HOME=$HOME/SMSC
	export UANGIN_SRC_HOME=~/UANGN
	export UASYS_DBTYPE=MMDB
	export UASYS_PRODUCT=SMSC
	export UASYS_RELEASE=SMSF
	# Complie option
	export UASYS_64BIT=TRUE
	export UASMSC_SRC_HOME=$HOME/src
	export MMDB_SRC_HOME=$HOME/MMDB/mmdb_core
	export SCHEMA_SRC_HOME=$HOME/MMDB/mmdb_core/etc
	export UALIB_SRC_HOME=$HOME/UANGEL/UALIB
	export UDIA3_STACK_HOME=$HOME/UANGEL/UXCORE/udia/src/stack

	export KTF_SMSC_CONFIG_DIR=$HOME/HOME/data
	export LD_LIBRARY_PATH={$LD_LIBRARY_PATH}:$HOME/home/lib:/usr/local/lib:/usr/local/mysql/lib:/lib64:/usr/lib64

	export LINUX_KERNEL_VERSION=3.10
	export OS_NAME=`uname -s | tr -d '[/ -.]' | tr '[[a-z]]' '[[A-Z]]'`
	export HW_MODEL=`uname -m | tr -d '[/ _.]' | tr '[[a-z]]' '[[A-Z]]'`
	export UASYS_SS7=USIGTRAN
	export SS7TYPE=USIGTRAN
	export SIGTRAN_TYPE=M3UA



	###################################################
	# GO LANG
	###################################################
#	export GOPATH=$HOME/go
	export PATH=$PATH:/usr/local/go/bin:$PATH:$GOPATH/bin
	export GOPATH=$HOME/go

#	source ~/.alias
}

function uangn_env()
{
	###################################################
	#
	#  UANGEL UTAS [SIP AS] DEVELOPMENT ENVIRONMENT
	#
	###################################################

	###################################################
	# CVS Related Environment
	###################################################
	export CVSROOT=:pserver:shseo@192.168.1.13:/data3/cvsroot_uahlr
	alias h='history'
	alias cvu='cvs update -d -P'
	alias cvi='cvs commit'
	alias cva='cvs add'
	alias cvr='cvs remove'
	alias cvd='cvs diff'
	alias cvst='cvs status -v'
	alias cvl='cvs log'

	alias cvsseo='export CVSROOT=:pserver:shseo@192.168.1.13:/data3/cvsroot_uahlr'
	alias cvshlr='export CVSROOT=:pserver:telkom@192.168.1.15:/data3/cvsroot_uahlr'
	alias cvsosa='export CVSROOT=:pserver:hoonji@192.168.1.15:/data3/cvsroot_osa'
	alias cvsngn='export CVSROOT=:pserver:hoonji@192.168.1.15:/data3/cvsroot_ngn'
	alias cvssig='export CVSROOT=:pserver:proto@192.168.1.15:/data3/cvsroot_protocol'
	alias cvsoss='export CVSROOT=:pserver:oss@192.168.1.15:/data3/cvsroot_uahlr'

	###################################################
	# LUA Configuration
	###################################################
	export LUA_HOME=/usr/local
	export LUA_SRC_HOME=$HOME/HOME/lua/script
	export LUA_CPATH="${HOME}/HOME/lua/lib/liblua_?.so;${HOME}/HOME/lua/lib/?.so"
	export LUA_CPATH="${LUA_CPATH};${HOME}/HOME/lib/lib?.so"
	export LUA_CPATH="${LUA_CPATH};/usr/local/lib/lua/5.1/?.so"
	export LUA_PATH="${HOME}/HOME/lua/script/?.lua;${HOME}/HOME/lua/script/?/init.lua"
	export LUA_PATH="${LUA_PATH};${HOME}/HOME/lua/script/ualua/common/?.lua"
	export LUA_PATH="${LUA_PATH};${HOME}/HOME/lua/script/ualua/uxlib/?.lua"
	export LUA_PATH="${LUA_PATH};${HOME}/HOME/lua/script/extlibs/?.lua"
	export LUA_PATH="${LUA_PATH};${HOME}/TKSDRA_SVC/src/dia2ldap/lua/?.lua"
	export LUA_PATH="${LUA_PATH};/usr/local/share/lua/5.1/?.lua;/usr/local/share/lua/5.1/?/init.lua"
	export LUA_PATH="${LUA_PATH};/usr/local/share/luajit-2.0.3/?.lua"
	export LUA_PATH="${LUA_PATH};${HOME}/HOME/lua/script/ualua/uxcutor/?.lua"
	export LUA_CPATH="${LUA_CPATH};/usr/lib64/liblua?.so"
	export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${HOME}/HOME/lua/lib
	export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${USIP_SRC_HOME}/lib

	###################################################
	# UXLIB Configuration
	###################################################
	export UXLIB_SRC_HOME=$HOME/UANGEL/UXCORE/UXLIB
	export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${UXLIB_SRC_HOME}/lib
	alias cuxlib='cd ~/UANGEL/UXCORE/UXLIB/src'

	###################################################
	# UXCUTOR Configuration
	###################################################
	export UXCUTOR_SRC_HOME=$HOME/UANGEL/UXCORE/UXCUTOR

	###################################################
	# USIP Configuration
	###################################################
	export USIP_SRC_HOME=${HOME}/UANGEL/UXCORE/usip

	###################################################
	# UXCSIM Configuration
	###################################################
	export UXCSIM_SRC_HOME=$HOME/UANGEL/UANGN/UXCSIM

	###################################################
	# UDIAMETER Configuration
	###################################################
	export UDIA_SRC_HOME=${HOME}/UANGEL/UXCORE/udia
	export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${UDIA_SRC_HOME}/lib

	###################################################
	# UDIAMETER Configuration
	###################################################
	export UDIA3_SRC_HOME=${HOME}/UANGEL/UXCORE/udia
	export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${UDIA3_SRC_HOME}/lib

	###################################################
	# USMPP Configuration
	###################################################
	export USMPP_SRC_HOME=$HOME/UANGEL/UANGN/usmpp

	###################################################
	# UASN Configuration
	###################################################
	export UASN_SRC_HOME=${HOME}/UANGEL/UANGN/uasn
	export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${UASN_SRC_HOME}/lib

	###################################################
	# UXTCAP Configuration
	###################################################
	export UXTCAP_SRC_HOME=${HOME}/UANGEL/UANGN/uxtcap
	export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${UXTCAP_SRC_HOME}/lib
	
	###################################################
	# ASIF Configuration
	###################################################
	export ASIF_SRC_HOME=${HOME}/UANGEL/UANGN/AsifX
	export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${ASIF_SRC_HOME}/lib

	export SEARCH_GLOBALCTAGS="${SEARCH_GLOBALCTAGS},${HOME}/tools/TAGS/asif.tags"
	export SEARCH_GLOBALETAGS="${SEARCH_GLOBALETAGS},${HOME}/tools/TAGS/asif.etags"

	#########################################################
	# MYSQL Environement
	#########################################################
	export MYSQL_HOME=/usr/local/mysql
	export MYSQL_INCLUDE=$MYSQL_HOME/include
	export MYSQL_LIB=$MYSQL_HOME/lib
	export MYSQL_VERSION=4.1

	export PATH=$PATH:$MYSQL_HOME/bin
	export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${MYSQL_HOME}/lib
}

function uaoam_env()
{
	#########################################################
	#
	# UANGEL OSS EXECUTION ENVIRONMENT
	#
	#########################################################
	export UASYS_HOME=$HOME/HOME

	#########################################################
	# Environement for MySQL
	#########################################################
	#export MYSQL_HOME=
	#export MYSQL_HOME=/usr/local/mysql
	#export MYSQL_INCLUDE=$MYSQL_HOME/include
	#export MYSQL_LIB=$MYSQL_HOME/lib
	#export PATH=${MYSQL_HOME}/bin:${PATH}

	export PATH=${UASYS_HOME}/bin:${PATH}
	export LD_LIBRARY_PATH=${UASYS_HOME}/lib:${LD_LIBRARY_PATH}
	export SHLIB_PATH=${LD_LIBRARY_PATH}

	alias   cbin='cd $UASYS_HOME/bin'
	alias   clib='cd $UASYS_HOME/lib'
	alias   cdata='cd $UASYS_HOME/data'
	alias   clog='cd $UASYS_HOME/log'


	###################################################
	#
	#  UANGEL OSS DEVELOPMENT ENVIRONMENT
	#
	###################################################
	export UAOSS_DEV_HOME=$HOME/uaoss
	export UALIB_DEV_HOME=$UAOSS_DEV_HOME/ualib
	export UAOAM_DEV_HOME=$UAOSS_DEV_HOME/uaoam
	export UAOAM_PROJECT_HOME=$UAOSS_DEV_HOME/project
	export UAOAM_PRODUCT_HOME=$UAOSS_DEV_HOME/product
	export UAOAM_EXTLIB_HOME=$UAOSS_DEV_HOME/extlib

	#export UASYS_PRODUCT=OMP_SERVER
	#export UASYS_RELEASE=COMMON

	export PATH=$PATH:$UAOAM_DEV_HOME/tools

	#########################################################
	# Environement for MySQL
	#########################################################
	export MYSQL_HOME=/usr/local/mysql
	export MYSQL_INCLUDE=$MYSQL_HOME/include
	export MYSQL_LIB=$MYSQL_HOME/lib

	#export PATH=$PATH:$MYSQL_HOME/bin
	#export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${MYSQL_HOME}/lib

	alias cualib='cd $HOME/uaoss/ualib'
	alias cuaoam='cd $HOME/uaoss/uaoam'
	alias cextlib='cd $HOME/uaoss/extlib'
	alias cextpkg='cd $HOME/uaoss/extpkg'

	alias cualibs='cd $UALIB_DEV_HOME/src/ualib'
	alias cualibi='cd $UALIB_DEV_HOME/include/ualib'
	alias cuasock='cd $UALIB_DEV_HOME/src/uasock'
	alias cuasocki='cd $UALIB_DEV_HOME/include/uasock'
	alias cuammc='cd $UALIB_DEV_HOME/src/uammc'
	alias cuammci='cd $UALIB_DEV_HOME/include/uammc'
	alias cuaoamifs='cd $UALIB_DEV_HOME/src/uaoamif'
	alias cuaoamifi='cd $UALIB_DEV_HOME/include/uaoamif'
	alias ctools='cd $UALIB_DEV_HOME/src/tools'

	alias cuaoams='cd $UAOAM_DEV_HOME/libsrc/uaoam'
	alias cuaoami='cd $UAOAM_DEV_HOME/include/uaoam'
	alias cuaxml='cd $UAOAM_DEV_HOME/libsrc/uaxml'
	alias cuaxmli='cd $UAOAM_DEV_HOME/include/uaxml'
	alias cuastat='cd $UAOAM_DEV_HOME/libsrc/uastat'
	alias cuarts='cd $UAOAM_DEV_HOME/libsrc/uarts'
	alias cuartsi='cd $UAOAM_DEV_HOME/include/uarts'
	alias cuamysql='cd $UAOAM_DEV_HOME/libsrc/uamysql'
	alias cuamysqli='cd $UAOAM_DEV_HOME/include/uamysql'
	alias cuacalc='cd $UAOAM_DEV_HOME/libsrc/uacalc'
	alias cuacalci='cd $UAOAM_DEV_HOME/include/uacalc'
	alias cuamhand='cd $UAOAM_DEV_HOME/libsrc/uamhand'
	alias cuamhandi='cd $UAOAM_DEV_HOME/include/uamhand'
	alias cuampcid='cd $UAOAM_DEV_HOME/libsrc/uampcid'
	alias cuaomscid='cd $UAOAM_DEV_HOME/libsrc/uaomscid'
	alias cuaprn='cd $UAOAM_DEV_HOME/libsrc/uaprn'
	alias cuacrypt='cd $UAOAM_DEV_HOME/libsrc/uacrypt'
	alias cuacrypti='cd $UAOAM_DEV_HOME/include/uacrypt'

	alias cuasamd='cd $UAOAM_DEV_HOME/src/uasamd'
	alias comsib='cd $UAOAM_DEV_HOME/src/omsib'
	alias clogib='cd $UAOAM_DEV_HOME/src/logib'
	alias comsd='cd $UAOAM_DEV_HOME/src/omsd'
	alias comsproxy='cd $UAOAM_DEV_HOME/src/omsproxy'
	alias comc='cd $UAOAM_DEV_HOME/src/omc'
	alias cstsd='cd $UAOAM_DEV_HOME/src/stsd'
	alias clogmd='cd $UAOAM_DEV_HOME/src/logmd'
	alias csumd='cd $UAOAM_DEV_HOME/src/sumd'
	alias cmmcd='cd $UAOAM_DEV_HOME/src/mmcd'
	alias cmess='cd $UAOAM_DEV_HOME/src/messhand'
	alias cnmsib='cd $UAOAM_DEV_HOME/src/nmsib'
	alias crmi='cd $UAOAM_DEV_HOME/src/mmcd/rmi'
	alias cschedd='cd $UAOAM_DEV_HOME/src/schedd'
	alias cnotiib='cd $UAOAM_DEV_HOME/src/notiib'

	alias csktscp='cd $HOME/uaoss/project/SKTSCP'
	alias csktsdp='cd $HOME/uaoss/project/SKTSDP'
	alias csktsmp='cd $HOME/uaoss/project/SKTSMP'
	alias cudra='cd $HOME/uaoss/project/TKSDRA'
	alias sonscp1='scp ~/HOME/son.tar app@192.168.1.53:~/HOME/.'
	alias sonscp2='scp ~/HOME/son.tar app@192.168.1.54:~/HOME/.'
	alias sonscp3='scp ~/HOME/son.tar asp@192.168.1.53:~/HOME/.'
	alias sonscp4='scp ~/HOME/son.tar asp@192.168.1.54:~/HOME/.'
	alias sonscp5='scp ~/HOME/son.tar aspapp@192.168.1.181:~/HOME/.'
	alias cudrah='cd $HOME/UANGEL/UANGN/udia3/src/adif'
	alias cuasnmp='cd $HOME/uaoss/product/UASNMP'
	alias coms='cd $HOME/uaoss/product/OMS'
	alias cuaguard='cd $HOME/uaoss/product/UAGUARD/src/uaguard'
	alias chaguard='cd $HOME/uaoss/product/HAGUARD/src/haguard'

	alias csigmgt='cd $HOME/uaoss/product/SIGTRAN/src/sigmgt'
	alias cusrg='cd $HOME/uaoss/product/USRG'
	alias cusrgmgt='cd $HOME/uaoss/product/USRG/src/usrgmgt'
	alias cusnmpd='cd $HOME/uaoss/product/UASNMP/src/usnmpd'

	alias clua='cd $SELSVC_SRC_HOME/lua/script/tkssvc'
	alias cxt='cd $HOME/SELSVC/xcript/addc'
	alias cta='cd $UDRATA_SRC_HOME/xcript/tkssvc'
	alias ccom='cd $HOME/HOME/lua/script/tkssvc/common'
	alias cluat='cd $HOME/HOME/lua/script/tkssvc/tests/devserv'
	alias csvc='cd $HOME/HOME/lua/script/tagent/svc'
	alias cplug='cd $HOME/UANGEL/UANGN/UXCUTOR/lua/plugins'
	alias cexam='cd $HOME/UANGEL/UANGN/UXCSIM/example'
	alias mktag='ctags -R uaoss /usr/include/* UANGEL'
}


function usrgdev_env()
{
	export SVN_EDITOR="vim"
	export USRG_UAMODE="4 5 8 9"
	
#	export DEV_ROOT=${HOME}/UANGEL
	if [ -e "$DEV_ROOT" ] ; then
		export OS_NAME=`uname -s | tr -d '[/ -.]' | tr '[[a-z]]' '[[A-Z]]'`
		export HW_MODEL=`uname -m | tr -d '[/ _.]' | tr '[[a-z]]' '[[A-Z]]'`

		export ULIB_DEV_ROOT=${DEV_ROOT}/ulib
		export USRG_DEV_ROOT=${DEV_ROOT}/usrg
		export USRG_DEV_SCTPTYPE="KERNEL"
		export USCTP_DEV_ROOT=${DEV_ROOT}/usctp
		export USRG_EXTERNAL=${DEV_ROOT}/external/${OS_NAME}_${HW_MODEL}
		export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ULIB_DEV_ROOT/lib:$USCTP_DEV_ROOT/lib:$USRG_DEV_ROOT/lib

		export USRG_ROOT=${DEV_ROOT}/srg
		export USRG_PKG_ROOT=${USRG_ROOT}
		export USRG_KEYBASE=0x10
		source ${USRG_ROOT}/etc/usrg_env.sh
		#source ${USRG_ROOT}/etc/usrg_dev.sh
		export USRG_DATA=${USRG_ROOT}/SRG
	else
		usrg_env
	fi
}	

function usrg_env()
{
	# for USRG
	export USRG_SRC_HOME=$HOME/srg
	export USRG_EXTERNAL=${DEV_ROOT}/external/${OS_NAME}_${HW_MODEL}
	export USRG_DEV_SCTPTYPE="KERNEL"

	export USRG_ROOT=${HOME}/srg
	export USRG_PKG_ROOT=${USRG_ROOT}
	export USRG_KEYBASE=0x10
	source ${USRG_ROOT}/etc/usrg_env.sh
}

function gr() { set -f;if [ ${1:0:1} == "-" ] ; then opt=$1;shift; fi;find . -name "$2" -print | xargs grep $opt "$1";set +f; }
#function gr() { find . -type f -name "$2" | xargs grep -n "$1"; }
function cd { builtin cd $* && PS1="`hostname` [`whoami`{\!} `dirs` ] "; }

sys_env
smsc_env
uangn_env
uaoam_env
alias_env
usrg_env

alias dockerb='sudo docker build -t smsfshseo/map_svc .'
alias dockeru='sudo docker push smsfshseo/map_svc'
alias dockerl='sudo docker login -u smsfshseo'

#export SVC_POD_HOST=192.168.3.5:8011
#export MAP_POD_HOST=192.168.3.5:8001
#export USMSF_HOME=/home/app/go/src/uangel.com/usmsf
#export CONF_POD_HOST=172.10.9.6:9090
#export ULAYER_MY_IP="127.0.0.1"
#sudo service docker start
#source ~/srgpkg/usrg_dev.sh 
