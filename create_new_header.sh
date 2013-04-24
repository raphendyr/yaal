#!/bin/sh -e

if [ -z "$1" ]; then
    echo "usage: $0 filename.hh"
    exit 1
fi

if [ "$(git rev-parse --show-toplevel)" != "$(pwd)" ]; then
    echo "ERROR: you need to execute this in project root"
    exit 1
fi

file=$1
name=$file
name=${name#./}
name=${name%.hh}
if [ "${name#/}" != "$name" ]; then
    echo "ERROR: absolute paths are not ok."
    exit 1
fi

if [ "$name" != "${name#*/*}" ]; then
    dir=$(echo "$name" | sed 's,/[^/]*$,/,g')
else
    dir=""
fi
upper=$(echo "$name" | sed 's,/,__,g' | tr '[a-z]' '[A-Z]')
prefix=$(echo "$dir" | sed 's,[^/]*/,../,g')

if ! [ -d "$dir" ]; then
    mkdir -p "$dir"
    echo "Created directory: ${dir%/}"
fi

cat > "$file" <<EOF
#ifndef __YAAL_${upper}__
#define __YAAL_${upper}__ 1
#include "${prefix}requirements.hh"
#ifdef __YAAL__

/* ... */

#endif
#endif
EOF
echo "Created file $file"
echo "---"
cat "$file"
echo "---"

git add "$file" && echo "Added it to git"
