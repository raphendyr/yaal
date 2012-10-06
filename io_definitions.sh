#!/bin/sh

# io registers
for f in /usr/lib/avr/include/avr/io*.h; do grep _SFR_IO $f | awk '{print $2 " " $3}' | cut -d '(' -f 1; done | grep -v _struct | grep -v "^define" | grep -v "_CONFIG" | sort -u > registers.txt

# 16 bits
grep "IO16$" registers.txt | awk '{print $1}' > registers_16.txt

# 8 bits
awk '{print $1}' registers.txt > registers_8.txt
while read l; do
	grep -Ev "^${l}"'(L|H|LO|HI)?$' registers_8.txt > registers_8.txt.tmp
	mv registers_8.txt.tmp registers_8.txt
done < registers_16.txt

(
	echo "#ifndef __YAAL_IO_DEFINITIONS_H__"
	echo "#define __YAAL_IO_DEFINITIONS_H__ 1"
	echo "// do not edit. genereted using io_definitions.sh"
	echo ""
	echo "#include <avr/io.h>"
	echo ""
	echo "namespace yaal {"
	echo ""
	while read r16; do
		echo "#ifdef $r16"
		r16o=$(python -c "print '$r16'.lower().capitalize()")
		echo "    typedef Register<YAAL_ADDR($r16), uint16_t> $r16o;"
		echo "#endif"
		echo ""
	done < registers_16.txt
	while read r8; do
		echo "#ifdef $r8"
		r8o=$(python -c "print '$r8'.lower().capitalize()")
		echo "    typedef Register<YAAL_ADDR($r8), uint8_t> $r8o;"
		echo "#endif"
		echo ""
	done < registers_8.txt

	echo "// ports"

	for c in A B C D E F G H I J K L M N O P Q R S T U V W X Y Z; do
		echo "#if defined(PORT$c) && defined(DDR$c) && defined(PIN$c)"
		l=$(python -c "print '$c'.lower()")
		echo "    typedef Port<Port$l, Ddr$l, Pin$l> Port$c;"
		for i in 0 1 2 3 4 5 6 7; do
			echo "# if defined(PORT$c$i) || defined(P$c$i)"
			echo "    typedef Pin<Port$c, $i> Port$c$i;"
			echo "# endif"
		done
		echo "#endif"
		echo ""
	done
	echo "}"
	echo ""
	echo "#endif"
) > io_definitions.hpp
