#!/usr/bin/env python

bits = lambda n: "".join("1" if n & (0x80 >> i) else "0" for i in xrange(8))

pad = lambda s, w: " "*(w-min(len(s), w)) + s[:w]

line = lambda a, l, w=5: " ".join([pad(str(a), w), ":"] + [pad(str(f), w) for f in l])

khz = lambda m, b: m*10**3/2**b/1000

def mode(n):
    if 200 <= n < 300:
        return "ULT"
    elif 100 <= n < 200:
        return "hgh"
    elif 50 <= n < 100:
        return "low"
    else:
        return ""

def get_adc_table(r):
    s = [ line("kHz", (bits(i)[-3:] for i in xrange(8))) ]
    prev = ""
    for m in r:
        l = line(m, (mode(khz(m, b)) for b in xrange(8)))
        end = l.split(':')[1].strip()
        if end != prev:
            s.append(l)
            prev = end
            if len(end) == 0:
                break
    return s

def to_enum_vars(m, l):
    t = [
            ('ULT', 'SUPER'),
            ('hgh', 'FAST'),
            ('low', 'SLOW'),
            ]
    ret = {}
    for k,v in t:
        if k in l:
            ret[v] = m[l.index(k)]
    return ret

def get_enum_variables(r):
    bitmap = dict((i, bits(i)[-3:]) for i in xrange(8))
    prev = [""]*8
    s = []
    for m in r:
        l = [mode(khz(m, b)) for b in xrange(8)]
        if l != prev:
            prev = l
            vals = to_enum_vars(bitmap, l)
            s.append((m*1000, vals))
            if not any(l):
                break
    return s

#print """#ifndef __YAAL_ADC__PRESCALER_CONSTANTS__
##define __YAAL_ADC__PRESCALER_CONSTANTS__ 1
#
#namespace yaal {
#    enum PrescalerMode {
#"""
print """#ifdef __INTERNAL_INCLUDE_ENUM__
"""

#print "/*"
#print "\n".join(get_adc_table(xrange(0, 40000)))
#print " */"
#print

s = get_enum_variables(xrange(0, 40000))
s.reverse()
first = True
for h, vals in s:
    if not vals:
        print "#  if F_CPU < %dUL" % (h,)
        print
    else:
        print "#    %s F_CPU >= %dUL" % (("if" if first else "elif"), h)
        first = False
        for k,v in vals.iteritems():
            print "        %s = 0x%x," % (k, int(v, 2))

print """
#    else
#      error "Too slow F_CPU for ADC module"
#    endif
#  else
#    error "Too fast F_CPU for ADC module"
#  endif
"""
#print """
#    }
#}
#"""
print """#endif
"""
