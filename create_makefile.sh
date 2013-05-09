#!/bin/sh -e

yaal_test() {
    test -f "$1/makefile.ext" && \
    grep -E -q -s "^# Hi, I'm yaal -\*- makefile -\*-$" "$1/makefile.ext"
    return $?
}

YAAL=${0%/*}
if [ "$YAAL" = "$0" ]; then
    YAAL=${1}
fi

if [ -z "$YAAL" ]; then
    echo "ERROR: no idea where yaal library could be..."
    echo "usage: $0 path/to/yaal"
    exit 1
fi

if ! yaal_test "$YAAL"; then
    echo "path '${YAAL}' do not contain yaal"
    exit 1
fi


for f in makefile Makefile; do
    if [ -e $f ]; then
       echo "ERROR: $f already exists."
       exit 2
    fi
done

cat > Makefile <<MAKEFILE
# Target filename
#TARGET = current_dir_name

# Sourcefiles c, c++, assembly (.c .cpp .cc .S)
#SRC = first_of(main.* TARGET.*)

# Define known board. To list all known boards run: make boards_list
#BOARD = teensy2

# If you do not know the board or want to overwrite:
#MCU = atmegaXXX
#F_CPU = 16000000

# List macro defines here (-D for gcc)
# DEFS = -DFOOBAR="foo bar" -DBAZ=baz

# Uncomment if you do not want to have yaal to setup cpu prescaler and
# do not want to use void loop nor void setup
#YAAL_NO_INIT = 1
# else, remembe to add '#include <yaal/core.hh>' in your main.*

# Include YAAL makefile
include $YAAL/makefile.ext

# ps. run 'make help' for more info
MAKEFILE

echo "OK. I created Makefile for you. You should edit it."
exit 0
