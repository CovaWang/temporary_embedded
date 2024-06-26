#
# Makefile for module.
#
# Copyright (C) 2015-2018 BeiJing OURS Education Technology Co., Ltd.
# Copyright (C) 2017 Tangle.Xu. All rights reserved.
#
# Official site: http://www.ourselec.com
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, you can access it online at
# http://www.gnu.org/licenses/gpl-2.0.html.
#
# Author: Tangle.Xu <420724072@qq.com>
# Date: 2017.05
# Version: v0.1

CROSS		?= arm-none-eabi-
NAME		:= XX-ours-key-with-led

#
# System environment variable.
#
ifneq (,$(findstring Linux, $(shell uname -s)))
HOSTOS		:= linux
else
HOSTOS		:= windows
endif

#
# Load variables of flag.
#
ASFLAGS		:= -g -ggdb -Wall -O3
CFLAGS		:= -g -ggdb -Wall -O3
CXXFLAGS	:= -g -ggdb -Wall -O3
LDFLAGS		:= -T link.ld -nostdlib
ARFLAGS		:= -rcs
OCFLAGS		:= -v -O binary
ODFLAGS		:=
MCFLAGS		:= -mcpu=cortex-a9 -mtune=cortex-a9 -march=armv7-a -mfpu=neon -ftree-vectorize -ffast-math -mfloat-abi=softfp

LIBDIRS		:=
LIBS 		:=
INCDIRS		:=
SRCDIRS		:=

#
# Add necessary directory for INCDIRS and SRCDIRS.
#
INCDIRS		+= include \
			   include/hardware \
			   include/library
SRCDIRS		+= source \
			   source/startup \
			   source/hardware \
			   source/hardware/clk \
			   source/hardware/gpio \
			   source/hardware/interrupt \
			   source/hardware/pwm \
			   source/arm \
			   source/library \
			   source/library/ctype \
			   source/library/errno \
			   source/library/exit \
			   source/library/malloc \
			   source/library/stdlib \
			   source/library/string \
			   source/library/stdio \
			   source/library/math \
			   source/graphic \
			   source/graphic/maps/software

#
# You shouldn't need to change anything below this point.
#
AS			:= $(CROSS)gcc -x assembler-with-cpp
CC			:= $(CROSS)gcc
CXX			:= $(CROSS)g++
LD			:= $(CROSS)ld
AR			:= $(CROSS)ar
OC			:= $(CROSS)objcopy
OD			:= $(CROSS)objdump
MKDIR		:= mkdir -p
CP			:= cp -af
RM			:= rm -fr
CD			:= cd
FIND		:= find

ifeq ($(strip $(HOSTOS)), linux)
MK6818		:= tools/linux/mk6818
endif
ifeq ($(strip $(HOSTOS)), windows)
MK6818		:= tools/windows/mk6818
endif
NSIH		:= tools/image/nsih.txt
SECBOOT		:= tools/image/2ndboot

#
# X variables
#
X_ASFLAGS	:= $(MCFLAGS) $(ASFLAGS)
X_CFLAGS	:= $(MCFLAGS) $(CFLAGS)
X_CXXFLAGS	:= $(MCFLAGS) $(CXXFLAGS)
X_LDFLAGS	:= $(LDFLAGS)
X_OCFLAGS	:= $(OCFLAGS)
X_LIBDIRS	:= $(LIBDIRS)
X_LIBS		:= $(LIBS) -lgcc

X_OUT		:= output
X_NAME		:= $(patsubst %, $(X_OUT)/%, $(NAME))
X_INCDIRS	:= $(patsubst %, -I %, $(INCDIRS))
X_SRCDIRS	:= $(patsubst %, %, $(SRCDIRS))
X_OBJDIRS	:= $(patsubst %, .obj/%, $(X_SRCDIRS))

X_SFILES	:= $(foreach dir, $(X_SRCDIRS), $(wildcard $(dir)/*.S))
X_CFILES	:= $(foreach dir, $(X_SRCDIRS), $(wildcard $(dir)/*.c))
X_CPPFILES	:= $(foreach dir, $(X_SRCDIRS), $(wildcard $(dir)/*.cpp))

X_SDEPS		:= $(patsubst %, .obj/%, $(X_SFILES:.S=.o.d))
X_CDEPS		:= $(patsubst %, .obj/%, $(X_CFILES:.c=.o.d))
X_CPPDEPS	:= $(patsubst %, .obj/%, $(X_CPPFILES:.cpp=.o.d))
X_DEPS		:= $(X_SDEPS) $(X_CDEPS) $(X_CPPDEPS)

X_SOBJS		:= $(patsubst %, .obj/%, $(X_SFILES:.S=.o))
X_COBJS		:= $(patsubst %, .obj/%, $(X_CFILES:.c=.o))
X_CPPOBJS	:= $(patsubst %, .obj/%, $(X_CPPFILES:.cpp=.o)) 
X_OBJS		:= $(X_SOBJS) $(X_COBJS) $(X_CPPOBJS)

VPATH		:= $(X_OBJDIRS)

.PHONY:	all clean
all : $(X_NAME)

$(X_NAME) : $(X_OBJS)
	@echo [LD] Linking $@.elf
	@$(CC) $(X_LDFLAGS) $(X_LIBDIRS) -Wl,--cref,-Map=$@.map $^ -o $@.elf $(X_LIBS)
	@echo [OC] Objcopying $@.bin
	@$(OC) $(X_OCFLAGS) $@.elf $@.bin
	@echo Make header information for irom booting
	@$(MK6818) $@pak.bin $(NSIH) $(SECBOOT) $@.bin
	@$(RM) $(X_DEPS) $(X_OBJS) $(X_OBJDIRS) .obj

$(X_SOBJS) : .obj/%.o : %.S
	@echo [AS] $<
	@$(AS) $(X_ASFLAGS) $(X_INCDIRS) -c $< -o $@
	@$(AS) $(X_ASFLAGS) -MD -MP -MF $@.d $(X_INCDIRS) -c $< -o $@

$(X_COBJS) : .obj/%.o : %.c
	@echo [CC] $<
	@$(CC) $(X_CFLAGS) $(X_INCDIRS) -c $< -o $@
	@$(CC) $(X_CFLAGS) -MD -MP -MF $@.d $(X_INCDIRS) -c $< -o $@

$(X_CPPOBJS) : .obj/%.o : %.cpp
	@echo [CXX] $<
	@$(CXX) $(X_CXXFLAGS) $(X_INCDIRS) -c $< -o $@	
	@$(CXX) $(X_CXXFLAGS) -MD -MP -MF $@.d $(X_INCDIRS) -c $< -o $@

clean:
	@$(RM) $(X_DEPS) $(X_OBJS) $(X_OBJDIRS) $(X_OUT) .obj
	@echo Clean complete.

#
# Include the dependency files, should be place the last of makefile
#
sinclude $(shell $(MKDIR) $(X_OBJDIRS) $(X_OUT)) $(X_DEPS)
