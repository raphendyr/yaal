#!/bin/sh -e

[ "${0%/*}" != "${0}" ] && cd ${0%/*}

PORTS='A B C D E F G H I J K L M N O P Q R S T U V W X Y Z'
PORTS='A B C D E F G H I J K L M N'

(
echo '#ifndef __YAAL_IO__REGISTERS__PORT__'
echo '#define __YAAL_IO__REGISTERS__PORT__ 1'
echo '#include "../../requirements.hh"'
echo '#ifdef __YAAL__'
echo '/* Generated using port.sh */'
echo
echo '#include "../types/register.hh"'
echo '#include <avr/io.h>'
echo
echo 'namespace yaal {'
echo
echo '    namespace internal {'
for c in $PORTS; do
	echo
	echo "        /*  port $c  */"
	echo "#       ifdef PIN$c"
	echo "            typedef ReadonlyRegister<YAAL_ADDR(PIN$c)> Pin${c}Reg;"
	echo '#       endif'
	echo "#       ifdef DDR$c"
	echo "            typedef Register<YAAL_ADDR(DDR$c)> Ddr${c}Reg;"
	echo '#       endif'
	echo "#       ifdef PORT$c"
	echo "            typedef Register<YAAL_ADDR(PORT$c)> Port${c}Reg;"
	echo '#       endif'
done
echo '    }'
echo
echo '}'
echo ''
echo '#endif'
echo '#endif'

) > port.hh
