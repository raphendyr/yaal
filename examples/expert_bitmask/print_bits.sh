#!/bin/sh

if [ -z "$1" ]; then
    echo "usage: $0 number" >&2
    exit 1
fi

exec python -c "n=$1; print ''.join(['1' if n & (0x80 >> i) else '0' for i in xrange(8)])"
