#!/bin/sh

# PORTS="A B C D E F G H I J K L M N O P Q R S T U V W X Y Z"
PORTS="A B C D E F G"

echo "#ifndef __YAAL_IO__PORTS__"
echo "#define __YAAL_IO__PORTS__ 1"
echo '#include "../requirements.hh"'
echo '#ifdef __YAAL__'
echo "/* Generated using ports.sh */"
echo ""
echo '#include "types/register.hh"'
echo '#include "port.hh"'
echo '#include <avr/io.h>'
echo ""
echo "namespace yaal {"
echo ""

echo "    namespace internal {"
for c in $PORTS; do
	echo "#       ifdef PIN$c"
	echo "            typedef ReadonlyRegister<YAAL_ADDR(PIN$c)> Pin$c;"
	echo "#       endif"
	echo "#       ifdef DDR$c"
	echo "            typedef Register<YAAL_ADDR(DDR$c)> Ddr$c;"
	echo "#       endif"
	echo "#       ifdef PORT$c"
	echo "            typedef Register<YAAL_ADDR(PORT$c)> Port$c;"
	echo "#       endif"
done
echo "    }"
echo ""
echo ""
for c in $PORTS; do
	echo "#   if defined(PORT$c) && defined(DDR$c) && defined(PIN$c)"
	echo "        typedef Port<internal::Port$c, internal::Ddr$c, internal::Pin$c> Port$c;"
	for i in 0 1 2 3 4 5 6 7; do
		echo "#       ifdef PORT$c$i"
		echo "            typedef Pin<Port$c, $i> Port$c$i;"
		echo "#       endif"
	done
	echo "#   endif"
	echo ""
done
echo "}"
echo ""
echo "#endif"
echo "#endif"
