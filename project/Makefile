export

# default platform
PLAT ?= __oc2000__

# default target
TARGET ?= BT01_CP1

# default BSP
BSP ?= bt206

# default CPU and corresponding version of __oc2000__
ifeq ($(PLAT), __oc2000__)
ifeq ($(BSP), bt202)
CPU := R3000
OCVERSION := 2.42.10
endif
ifeq ($(BSP), bt205)
CPU := R3000
OCVERSION := 2.50.20
endif
ifeq ($(BSP), bt206)
CPU := R4000
OCVERSION := 2.50.20
endif
endif

CPU ?= R4000
OCVERSION ?= 2.50.20

ifndef INSTALL_PATH
ifeq ($(PLAT), __oc2000__)
# /home/vxuser must have 777
INSTALL_PATH = /home/vxuser
INSTALL_USER = vxuser
# For network installation
#INSTALL_PATH = hostname:$(INSTALL_PATH)
else
INSTALL_PATH = .
INSTALL_USER = $(USER)
endif
endif

ifndef INSTALL
INSTALL = scp 
endif 

BASE=$(shell pwd)/../$(PATH_TT)

OCMAKEFILE := $(addprefix oc2000_v, $(OCVERSION))

include Projects.mk



PROJECTS := $(addprefix $(BASE)/, $(projects))
ALLSRC := $(wildcard $(addsuffix /src/*.c, $(PROJECTS)))
ALLHEADERS := $(wildcard $(addsuffix /include/*.h, $(PROJECTS)) $(BASE)/include/*.h)

MAKEFLAGS += --no-print-directory
SHELL := /bin/sh

CFLAGS = $(CCOPTIM) $(CCWARNINGS) $(ADDEDFLAGS)
CPPFLAGS = $(CCINCLUDE) $(CCDEFINES) -D$(TARGET)
# this is workaround to fool that old and stupid compiler for bt202
ifneq ($(BSP), bt202)
CPPFLAGS += -D$(PLAT)
endif

CCOPTIM += 
CCWARNINGS += -Wall
CCINCLUDE += $(addprefix -I, $(addsuffix /include, $(PROJECTS)) $(BASE)/include $(PROJECTS))
CCDEFINES += -D$(BSP) -DOC2K1x
CCLIBS +=
LDFLAGS +=


#ifeq ($(CPU), R4000)
#LDFLAGS += -G0 -L$(OSBASE)/gbrv/lib/R4000/ -lX11 $(OSBASE)/lib/oc2000R4000.a
#LDFLAGS += -G0 -L/usr/oc2000_v2.50.20/gbrv/lib/R4000 -lX11 /usr/oc2000_v2.50.20/lib/oc2000R4000.a
#endif
#$(OSBASE)/gbrv/lib/R4000/libX11.a
##
ADDEDFLAGS +=

vpath %.c $(addsuffix /src, $(PROJECTS))
vpath %.h $(addsuffix /include, $(PROJECTS)) $(BASE)/include

ifeq ($(PLAT), __oc2000__)
include $(OCMAKEFILE).mk
endif

ifeq ($(PLAT), linux)
CC := gcc
endif

ifeq ($(PLAT), qnx)
CC := gcc
endif


.PHONY: all install mrproper clean clobber fallout

install: $(wildcard $(BASE)/$(PROJECT)/src/debug/*)
	@if $(INSTALL) $^ $(INSTALL_PATH); then \
	printf "[ CP ] %-30s[ OK ]\n" $(PROJECT); \
	else printf "[ CP ] %-30s[FAIL]\n" $(PROJECT); fi

fallout: clean mrproper clobber
clean:
	@-$(RM) $(wildcard *.o)

mrproper:
	@-$(RM) $(wildcard *.d)

clobber:
	@-$(RM) $(BASE)/$(PROJECT)/src/debug/*
	
# IMPLICIT RULES
%.o: %.c
	@if $(CC) $(CFLAGS) $(CPPFLAGS) -g -MD -c -o $@ $<; then \
	printf "[ CC ] %-30s[ OK ]\n" $(notdir $<); else printf "[ CC ] %-30s[FAIL]\n" $(notdir $<); fi

ifeq ($(PLAT), __oc2000__)
%: 
	@if $(CC) $(CFLAGS) $(LDFLAGS) -MD -Xlinker -r $^ $(LDFLAGS) -o $(BASE)/$(PROJECT)/src/debug/$@; then \
	printf "[ LD ] %-30s[ OK ]\n" $(PROJECT); chmod a+rwx $(BASE)/$(PROJECT); \
	else printf "[ LD ] %-30s[FAIL]\n" $(PROJECT); fi
endif

ifeq ($(PLAT), linux)
%: 
	@if $(CC) $(CFLAGS) $(LDFLAGS) -gp -MD $^ -o $(BASE)/$(PROJECT)/src/debug/$@ $(CCLIBS); then \
	printf "[ LD ] %-30s[ OK ]\n" $(PROJECT); else printf "[ LD ] %-30s[FAIL]\n" $(PROJECT); fi
endif


ifeq ($(PLAT), qnx)
%:
	@if $(CC) $(CFLAGS) $(LDFLAGS) -gp -MD $^ -o $(BASE)/$(PROJECT)/src/debug/$@ $(CCLIBS); then \
	printf "[ LD ] %-30s[ OK ]\n" $(PROJECT); else printf "[ LD ] %-30s[FAIL]\n" $(PROJECT); fi
endif

include $(wildcard *.d)
include $(wildcard $(addsuffix /src/*.d, $(PROJECTS)))
 
