#!/usr/bin/env python

parts = [
        ('rs', 1, [0]),
        ('rw', 1, [1]),
        ('enable', 1, [2]),
        ('data', 4, [3, 4, 5, 6]),
        ('backlight', 1, [7]),
]

from itertools import permutations

print "#ifdef __INTERNAL_INCLUDE_STRUCTS__"
print

for order in permutations(parts):
    content = ""
    i = 0
    numbers = [0] * 8
    for name, width, pos in order:
        content += "    uint8_t {} : {};\n".format(name, width)
        for p in pos:
            numbers[p] = i
            i += 1
    print "template<>"
    print "struct LcdBackPack<{}> {{".format(", ".join(str(n) for n in numbers))
    print content
    print "};"

print
print "#endif"
