#!/usr/bin/env python

def calc(f_cpu, baud):
    ubrr_val = f_cpu / baud
    if ubrr_val > 0xffff:
        print "{:9}: invalid".format(baud)
        return False
    scaled_f_cpu = f_cpu << 7 # 128 * f_cpu
    scaled_baud = baud << 7 # 128 * baud
    baud_tol = 128 * baud * 2 / 100 # << 1 # 128 * baud * (tolerance% / 100)
    ubrr_filtered = ubrr_val & 0xfff0 # (UBRR/16)*16 aka (UBRR >> 4) << 4
    use_u2x = (scaled_f_cpu > ubrr_filtered * (scaled_baud + baud_tol)) or (scaled_f_cpu < ubrr_filtered * (scaled_baud - baud_tol))
    use = (ubrr_val & 0xf) > (ubrr_val >> 6)
    print "{:9}: {:5} {:5} {:5} {:12} {:10} {:6} {!s:5} {!s:5} {}".format(baud, (ubrr_val/(8 if use_u2x else 16)), ubrr_val, ubrr_filtered, scaled_f_cpu, scaled_baud, baud_tol, use_u2x, use, ubrr_val >> 6)
    return use_u2x


for fi in [20, 16]:
    f = fi * 10**6
    baud = 9600 >> 3
    bauds = [282353, 256000, 129032, 128000, 115200, 57600, 56000, 38400, 31250, 19200, 14400, 9600, 4800, 2400, 1200, 600, 300, 110]
    bauds.reverse()

    while f >= 10 ** 6:
        print f
        print "     baud:  ubrr   val  filt    f_cpu        baud     tol   u2x"
        #for j in xrange(9):
        #    calc(f, baud << j)
        #for j in xrange(1,600):
        #    calc(f, baud*j)
        for b in bauds:
            calc(f, b)
        f /= 2;
