# FIXME: this file requires updates

# If no other programmer is set
PROGRAMMER ?= avrdude


ifeq ($(PROGRAMMER),avrdude)
#-------------- avrdude ---------------

# avrdude executable
AVRDUDE ?= avrdude

# Programming hardware
# Type: avrdude -c ?
# to get a full listing.
#
AVRDUDE_PROGRAMMER ?= stk500v2

# com1 = serial port. Use lpt1 to connect to parallel port.
AVRDUDE_PORT ?= com1    # programmer connected to serial device

AVRDUDE_WRITE_FLASH = -U flash:w:$(TARGET).hex
#AVRDUDE_WRITE_EEPROM = -U eeprom:w:$(TARGET).eep


# Uncomment the following if you want avrdude's erase cycle counter.
# Note that this counter needs to be initialized first using -Yn,
# see avrdude manual.
#AVRDUDE_ERASE_COUNTER = -y

# Uncomment the following if you do /not/ wish a verification to be
# performed after programming the device.
#AVRDUDE_NO_VERIFY = -V

# Increase verbosity level.  Please use this when submitting bug
# reports about avrdude. See <http://savannah.nongnu.org/projects/avrdude> 
# to submit bug reports.
#AVRDUDE_VERBOSE = -v -v

AVRDUDE_FLAGS = -p $(MCU) -P $(AVRDUDE_PORT) -c $(AVRDUDE_PROGRAMMER)
AVRDUDE_FLAGS += $(AVRDUDE_NO_VERIFY)
AVRDUDE_FLAGS += $(AVRDUDE_VERBOSE)
AVRDUDE_FLAGS += $(AVRDUDE_ERASE_COUNTER)


# Program the device.  
.PHONY: program
program: $(TARGET).hex $(TARGET).eep
	$(AVRDUDE) $(AVRDUDE_FLAGS) $(AVRDUDE_WRITE_FLASH) $(AVRDUDE_WRITE_EEPROM)


# end, avrdude
endif



ifeq ($(PROGRAMMER),teensy)
#--------------- teensy ---------------

TEENSY := $(YAAL)/vendor/teensy/teensy_loader_cli/teensy_loader_cli
TEENSY_FLAGS = -v -w -mmcu=$(MCU)

# We have teensy_loader_cli source shipped with yaal,
# so try to build it if it's missing
ifneq ($(wildcard $(TEENSY).c),)
$(TEENSY): $(TEENSY).c
	@if test ! -e /usr/include/usb.h; then echo "WARNING: no /usr/include/usb.h, you propably need libusb-dev for next thing to work"; fi
	@echo "Executing makefile for $(notdir $(TEENSY))"
	cd $(dir $(TEENSY)); make OS=LINUX
endif


program: $(TARGET).hex $(TEENSY)
	$(TEENSY) $(TEENSY_FLAGS) $<


# end, teensy
endif

#============================================================================

