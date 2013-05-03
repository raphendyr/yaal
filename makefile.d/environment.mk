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

# List C source files here.
#SRC = 

# List C++ source files here. (C dependencies are automatically generated.)
# CPPSRC defaults to main.* or $(TARGET).*, where * is extension we know howto build
CPPSRC ?= $(word 1,$(foreach base,main $(TARGET),$(wildcard $(base).cpp)))

# List Assembler source files here.
#     Make them always end in a capital .S.  Files ending in a lowercase .s
#     will not be considered source files but generated files (assembler
#     output from the compiler), and will be deleted upon "make clean"!
#     Even though the DOS/Win* filesystem matches both .s and .S the same,
#     it will preserve the spelling of the filenames, and gcc itself does
#     care about how the name is spelled on its command-line.
#ASRC =

# Test that at least something is included
ifeq ($(SRC)$(CPPSRC)$(ASRC),)
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
