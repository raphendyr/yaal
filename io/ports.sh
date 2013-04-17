#!/bin/sh -e

cd ${0%/*}

# PORTS="A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"
PORTS="A B C D E F G H I J K"

(
echo '#ifndef __YAAL_IO__PORTS__'
echo '#define __YAAL_IO__PORTS__ 1'
echo '#include "../requirements.hh"'
echo '#ifdef __YAAL__'
echo '/* Generated using ports.sh */'
echo
echo '#include "types/port.hh"'
echo '#include "types/pin.hh"'
echo '#include "registers/port.hh"'
echo
echo 'namespace yaal {'
for c in $PORTS; do
	echo
	echo "    /*  port $c  */"
	echo "#   if defined(PORT$c) && defined(DDR$c) && defined(PIN$c)"
	echo "        typedef Port<internal::Port${c}Reg, internal::Ddr${c}Reg, internal::Pin${c}Reg> Port$c;"
	echo
	for i in 0 1 2 3 4 5 6 7; do
		echo "#       ifdef PORT$c$i"
		echo "            typedef Pin<Port$c, PORT$c$i> Port$c$i;"
		echo '#       endif'
	done
	echo '#   endif'
done
echo '}'
echo
echo '#endif'
echo '#endif'

) > ports.hh
