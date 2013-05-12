#!/bin/sh

# io registers
for f in /usr/lib/avr/include/avr/io*.h; do grep _SFR_IO $f | awk '{print $2 " " $3}' | cut -d '(' -f 1; done | \
	grep -v _struct | \
	grep -v "^define" | \
	grep -v "_CONFIG" | \
	grep -v "SPDR0" | \
	grep -v "^CLKPR " | \
	grep -vE "^(PORT|DDR|PIN)[A-Z] " | \
	grep -vE "^(UDR[[:digit:]]?|UCSR[[:digit:]]?[A-Z]|UBRR[[:digit:]]?(|HI?|LO?)) " | \
	sort -u > registers.tmp

# 16 bits
grep "IO16$" registers.tmp | awk '{print $1}' > registers_16.tmp

# 8 bits
awk '{print $1}' registers.tmp > registers_8.tmp
while read l; do
	grep -Ev "^${l}"'(L|H|LO|HI)?$' registers_8.tmp > registers_8.tmp.tmp
	mv registers_8.tmp.tmp registers_8.tmp
done < registers_16.tmp

echo "#ifndef __YAAL_IO__OTHER__"
echo "#define __YAAL_IO__OTHER__ 1"
echo '#include "../requirements.hh"'
echo '#ifdef __YAAL__'
echo "// do not edit. genereted using io_definitions.sh"
echo ""
echo '#include "types/register.hh"'
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
done < registers_16.tmp
while read r8; do
	echo "#       ifdef $r8"
	r8o=$(python -c "print '$r8'.lower().capitalize()")
	echo "            typedef Register<YAAL_ADDR($r8), reg8_t> $r8o;"
	echo "#       endif"
	echo ""
done < registers_8.tmp

echo "    }"
echo "}"
echo ""
echo "#endif"
echo "#endif"
