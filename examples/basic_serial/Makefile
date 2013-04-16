################################################################################
# Simple makefile for an atmega2560 project.
################################################################################

RM := rm -rf

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS = serial.cpp

OBJS = serial.o

SIZEDUMMY = sizedummy

# All Target
all: serial.hex

# Tool invocations
serial.o: serial.cpp yaal/io/serials.hh yaal/io/types/serial.hh yaal/io/registers/serialregs.hh
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-g++ -Wall -Os -fpack-struct -fshort-enums -std=c++0x -funsigned-char -funsigned-bitfields -mmcu=atmega2560 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

serial.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-g++ -mmcu=atmega2560 -o"serial.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

serial.hex: serial.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex serial.elf  "serial.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: serial.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t serial.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS) serial.elf serial.hex serial.d
	-@echo ' '

upload: serial.hex
	@echo 'Invoking: Avrdude'
	avrdude -c stk500v2 -p m2560 -P /dev/ttyACM0 -U flash:w:serial.hex
	@echo 'Finished uploading: $@'
	@echo ' '

.PHONY: all clean dependents
.SECONDARY:


