#!/bin/sh

base=${0%/*}
base=${base#./}
cd "$base"

tot=0
err=0

selection=$@
selection=${selection:-$(ls -1)}

GXX=g++
GXXFLAGS="-I../include -std=c++11 -Wall"


build_and_run() {
    [ "$1" ] || return -1
    file=$1
    base=${file%.*}

    (
        echo "# $GXX $GXXFLAGS -o $base.bin $file" && \
        $GXX $GXXFLAGS -o $base.bin $file 2>&1 && \
        start=$(nm -n $base.bin | grep "B __registers" | cut -d ' ' -f 1) && \
        echo "# $GXX $GXXFLAGS -DREG_START__=0x$start -o $base.bin $file" && \
        $GXX $GXXFLAGS -DREG_START__=0x$start -o $base.bin $file 2>&1 && \
        echo "# ./$base.bin" && \
        ./$base.bin 2>&1
    ) > $base.log
    ret=$?
    if [ $ret -ne 0 ]; then
        cat $base.log | awk '{print "(LOG) " $0}'
    fi
    return $ret
}

for f in $selection; do
    f=${f#./}
    f=${f#$base}
    f=${f#/}
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

if [ $tot -eq 0 ]; then
    echo "Nothing to do..."
else
    echo " == $(($tot - $err)) of $tot ok, $err errors == "
fi

exit $err
