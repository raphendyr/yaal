#!/bin/sh

cd "${0%/*}"
tot=0
err=0

selection=$@
selection=${selection:-$(ls -1)}

build_and_run() {
    [ "$1" ] || return -1
    file=$1
    base=${file%.*}
    g++ -o $base.bin -std=c++11 -Wall $file 2>&1 > $base.log
    ret=$?
    if [ $ret -eq 0 ]; then
        ./$base.bin 2>&1 > $base.log
        ret=$?
    fi
    if [ $ret -ne 0 ]; then
        cat $base.log
    fi
    #rm $base.bin $base.log 2>&1 >/dev/null || true
    return $ret
}

for f in $selection; do
    [ -f "$f" ] && (echo "$f" | grep -q -s -E '\.(cc|cpp|c)$') || continue

    build_and_run $f
    ret=$?

    tot=$(($tot + 1))

    if [ $ret -ne 0 ]; then
        echo "$f: FAILED"
        err=$(($err + 1))
    else
        echo "$f: ok"
    fi
done

echo " == $(($tot - $err)) of $tot ok, $err errors == "
exit $err
