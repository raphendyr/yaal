#!/bin/sh

# serial registers
for f in /usr/lib/avr/include/avr/io*.h; do grep _SFR_MEM $f | sed "s/#[[:space:]]*define/#define/" | awk '{print $2 " " $3}' | cut -d '(' -f 1; done | \
	grep -E "^(UDR[[:digit:]]?|UCSR[[:digit:]]?[A-C]|UBRR[[:digit:]]?) " | \
	grep -v _struct | \
	sort -u > serial_registers.tmp

# 16 bits
grep "MEM16$" serial_registers.tmp | awk '{print $1}' | sort -u > serial_registers_16.tmp

# 8 bits
grep "MEM8$" serial_registers.tmp | awk '{print $1}' | sort -u > serial_registers_8.tmp

echo "#ifndef __YAAL_IO__REGISTERS__SERIAL__"
echo "#define __YAAL_IO__REGISTERS__SERIAL__ 1"
echo '#include "../../requirements.hh"'
echo '#ifdef __YAAL__'
echo "// do not edit. generated using serial.sh"
echo ""
echo '#include "../types/register.hh"'
echo "#include <avr/io.h>"
echo ""
echo "namespace yaal {"
echo "    namespace internal {"
echo ""
while read r16; do
	echo "#       ifdef $r16"
	r16o=$(python -c "print '$r16'.lower().capitalize()")
	echo "            typedef Register<YAAL_ADDR($r16), reg16_t> $r16o;"
	echo "#       endif"
	echo ""
done < serial_registers_16.tmp
while read r8; do
	echo "#       ifdef $r8"
	r8o=$(python -c "print '$r8'.lower().capitalize()")
	echo "            typedef Register<YAAL_ADDR($r8), reg8_t> $r8o;"
	echo "#       endif"
	echo ""
done < serial_registers_8.tmp

echo "    }"
echo "}"
echo ""
echo "#endif"
echo "#endif"
