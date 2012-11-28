#!/bin/bash

tot=0
err=0

cwd=$(pwd)

for d in *; do
    ( [ -d "$d" ] && [ -f "$d/Makefile" ] ) || continue
    cd "$d"

    make clean >/dev/null 2>&1
    make >/dev/null 2>&1
    ret=$?
    make clean >/dev/null 2>&1

    tot=$(($tot + 1))

    if [ $ret -ne 0 ]; then
        echo "$d: FAILED"
        err=$(($err + 1))
    else
        echo "$d: ok"
    fi

    cd "$cwd"
done

echo " == $(($tot - $err)) of $tot ok, $err errors == "
