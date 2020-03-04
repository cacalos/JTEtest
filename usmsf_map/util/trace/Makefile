
DEPEND = makedepend

PROG= trace
PROG2= calltrace

SRC= trace.c
SRC2= calltrace.c

OBJS= $(SRC:.c=.o)
OBJS2= $(SRC2:.c=.o)

PROJ_HOME=/data1/iXsmsc3

MOD_INC=$(PROJ_HOME)/src/inc

MOD_LIB_DIR=$(PROJ_HOME)/lib 

MOD_LIBS= -lGCA -lUTIL

BIN_DIR=$(PKG_ROOT)/bin
IXSMS_LIBS = /data2/IXSMSC3/lib

TOTAL_LIBS=	-Wl,+s -L$(MOD_LIB_DIR) $(MOD_LIBS)

INCLUDES= -I$(MOD_INC)

EXTRA_DEFINES= -D_HPUX_SOURCE

CFLAGS= -g -Ae $(INCLUDES) $(EXTRA_DEFINES) 

CC=cc
RM=rm -f

all: $(PROG) $(PROG2) copy 

rebuild: clean all

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS) $(TOTAL_LIBS) 

$(PROG2): $(OBJS2)
	$(CC) -o $(PROG2) $(OBJS2) $(TOTAL_LIBS) 

.SUFFIXES: .o .c

.c.o:
	$(CC) $(CFLAGS) -c $*.c

clean:
	$(RM) $(PROG) $(PROG2) $(OBJS) $(OBJS2) core 

copy :
	cp $(PROG) $(PROG2) $(PROJ_HOME)/bin

