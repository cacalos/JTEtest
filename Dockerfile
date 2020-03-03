From camel.uangel.com:5000/centos7.5:latest
MAINTAINER Cho samhyun <cacalos@uangel.com>

USER root
RUN echo "/home/app/srg/lib" > /etc/ld.so.conf.d/srg.conf
RUN chown -R app:app /home/app

USER app
WORKDIR /home/app
RUN mkdir HOME;mkdir HOME/lib;mkdir HOME/bin
COPY --from=camel.uangel.com:5000/sigtran-centos7.5 /home/app/srg ./srg
RUN echo "source /home/app/srg/usrg_dev.sh" >> /home/app/.bashrc

ENV ULIB_DEV_ROOT /home/app/srgpkg/ulib
ENV LD_LIBRARY_PATH /home/app/HOME/lib:/home/app/srg/lib
ENV PATH /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/home/app/HOME/bin:/home/app/srg/bin:
ENV USRG_KEYBASE 0x10
ENV USRG_PKG_ROOT /home/app/srg
ENV USRG_ROOT /home/app/srg
ENV USRG_SRC_HOME /home/app/srg
ENV USRG_DEV_SCTPTYPE KERNEL
ENV USRG_DATA /home/app/srg/SRG
RUN env

COPY --from=camel.uangel.com:5000/uaoss-centos7.5 /home/app/uaoss/ualib/lib/linux64/* ./HOME/lib/
COPY --from=camel.uangel.com:5000/uaoss-centos7.5 /home/app/uaoss/uaoam/lib/linux64/* ./HOME/lib/
COPY --from=camel.uangel.com:5000/uaoss-centos7.5 /home/app/uaoss/ualib/bin/linux64/* ./HOME/bin/
COPY --from=camel.uangel.com:5000/uaoss-centos7.5 /home/app/uaoss/uaoam/bin/linux64/* ./HOME/bin/

COPY --from=camel.uangel.com:5000/diameter-centos7.5 /home/app/UANGEL/UALIB/lib/linux64/* ./HOME/lib/
COPY --from=camel.uangel.com:5000/diameter-centos7.5 /home/app/UANGEL/UXCORE/UXLIB/lib/* ./HOME/lib/
COPY --from=camel.uangel.com:5000/diameter-centos7.5 /home/app/UANGEL/UXCORE/UXCUTOR/lib/* ./HOME/lib/
COPY --from=camel.uangel.com:5000/diameter-centos7.5 /home/app/UANGEL/UXCORE/udia/lib/* ./HOME/lib/
COPY --from=camel.uangel.com:5000/diameter-centos7.5 /home/app/UANGEL/UXCORE/udia/bin/* ./HOME/bin/
COPY --from=camel.uangel.com:5000/diameter-centos7.5 /home/app/UANGEL ./UANGEL

#COPY usmsf_map /home/app/SMSF
COPY lib/* /home/app/HOME/lib/
COPY env/.* /home/app/
#RUN ln -s /home/app/HOME home;ln -s /home/app/SMSF src
RUN ls /home/app
									
