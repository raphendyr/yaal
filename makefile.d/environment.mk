# Board
# -----

# Processor frequency.
#   Normally the first thing your program should do is set the clock prescaler,
#   so your program will run at the correct speed.  You should also set this
#   variable to same clock speed.  The _delay_ms() macro uses this, and many
#   examples use this variable to calculate timings.  Do not add a "UL" here.
#F_CPU = 16000000
ifndef F_CPU
$(error You need to define F_CPU before including yaal makefile.)
endif


# MCU name
#   you MUST set this to match the chip you are using
#MCU = atmega8
ifndef MCU
$(error You need to define MCU before including yaal makefile.)
endif



# Project files
# -------------

# Target file name (without extension).
TARGET ?= $(shell basename $(shell pwd))

# List C, C++ and assembly source files here.
#SRC = 
# SRC defaults to main.* or $(TARGET).*, where * is extension we know howto build
# FIXME: get prefixes from build.mk
SRC ?= $(word 1,$(foreach base,main $(TARGET),$(foreach ext,.c .cpp .cc .S,$(wildcard $(base)$(ext)))))

# Test that at least something is included
ifeq ($(SRC),)
$(error No file matching main.* nor TARGET.* were found, also no SRC was specified in Makefile (before include))
endif



# Commands
# --------
# FIXME: how user could overwrite these as make has it's own defaults?
SHELL = sh
WINSHELL = cmd
CC = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
SIZE = avr-size
AR = avr-ar rcs
NM = avr-nm
AVRDUDE = avrdude
REMOVE = rm -f
REMOVEDIR = rm -rf
COPY = cp

# Env info
# --------
ARCH := $(shell uname -p)
# FIXME: I'm sure that there is better way to do this
LANG := $(shell locale | grep -E '^(LANG|LANGUAGE|LC_MESSAGES|LC_ALL)' | cut -d '=' -f 2 | tr -d '"' | tr '[\n-_:]' ' ' | cut -d ' ' -f 1)
