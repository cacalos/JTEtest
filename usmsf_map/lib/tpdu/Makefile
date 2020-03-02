
LIB=libTPDU.sl

SRC= BitUtil.c TPDU.c tpdu2_i.c convType.c checkTpdu.c

OBJS=$(SRC:.c=.o)

PROJ_HOME=$(PKG_ROOT)
MOD_INC = $(PROJ_HOME)/src/inc
LIB_DIR=$(PROJ_HOME)/lib

INCLUDES= -I. -I$(MOD_INC)

EXTRA_DEFINES= 	-D_HPUX_SOURCE

CFLAGS= -g -Ae +DA2.0 +z $(INCLUDES) $(EXTRA_DEFINES)
SHAREDFLAGS = -dynamic -b +vnocompatwarnings

RM=rm -f
CC=cc

all: $(LIB) copy 

$(LIB): $(OBJS)
	ld $(SHAREDFLAGS) -o $(LIB) $(OBJS)

.SUFFIXES: .o .c

.c.o:
	$(CC) $(CFLAGS) -c $*.c

clean:
	$(RM) $(LIB) $(OBJS) core 

copy :
	cp $(LIB) $(LIB_DIR)

