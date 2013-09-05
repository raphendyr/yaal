#!/bin/sh -e

did_something=false

yaal_test() {
    test -f "$1/makefile.ext" && \
    grep -E -q -s "^# Hi, I'm yaal -\*- makefile -\*-$" "$1/makefile.ext"
    return $?
}

git_root=$(git rev-parse --show-toplevel 2>/dev/null || true)

YAAL=${0%/*}
if [ "$YAAL" = "$0" ]; then
    YAAL=${1}
fi


# Test for YAAL path
if [ -z "$YAAL" ]; then
    echo "ERROR: no idea where yaal library could be..."
    echo "usage: $0 path/to/yaal"
    exit 1
fi

if ! yaal_test "$YAAL"; then
    echo "path '${YAAL}' do not contain yaal"
    exit 1
fi



# Makefile
has_makefile=false
for f in makefile Makefile; do
    if [ -e $f ]; then
        has_makefile=true
        break
    fi
done

if ! $has_makefile; then
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
# do not want to use void loop(); nor void setup();
#YAAL_NO_INIT = 1

# If you are planning to change cpu.clock (F_CPU) at runtime,
# you should set following option, so yaal methods will get F_CPU at runtime
#DEFS += -DYAAL_UNSTABLE_F_CPU
# NOTE: this could make your code slow and big

# Include YAAL makefile
include $YAAL/makefile.ext

# ps. run 'make help' for more info
MAKEFILE
    git add Makefile 2>/dev/null || true

    echo "I created Makefile for you. You should edit it."
    did_something=true
else
    echo "Makefile exists, didn't touch that." >&2
fi



# .gitignore
if [ "$git_root" ] && ! [ -f "$git_root" ]; then
    cat > "$git_root/.gitignore" <<GITIGNORE
*~
*.tmp
*.o
*.i
*.hex
*.elf
*.eep
*.lss
*.map
*.sym
*.lst
.dep/
GITIGNORE
    ( cd "$git_root" && git add .gitignore )

    echo "I created .gitignore for you into git root, you didn't have that."
    did_something=true
else
    echo "File .gitignore exists in git root. Didn't touch." >&2
fi



# main.cpp
has_main=false
for base in main $(basename $(pwd)); do
    for ext in .c .cpp .cc .S; do
        if [ -e "$base$ext" ]; then
            has_main=true
            break
        fi
    done
done

if ! $has_main; then
    cat > main.cpp <<MAIN
#include <yaal/core.hh>
#include <yaal/io.hh>

setup() {
    // initialization
}

loop() {
    // repeatable
}
MAIN
    git add main.cpp 2>/dev/null || true

    echo "I created main.cpp you to start with."
    did_something=true
else
    echo "Good. You allready have main source file. Remembe to include <yaal/core.hh>"
fi

if $did_something && [ "$git_root" ]; then
    echo
    echo "You should create git commit as there is new files."
fi
exit 0
