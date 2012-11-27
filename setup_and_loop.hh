#ifndef __YAAL_SETUP_AND_LOOP__
#define __YAAL_SETUP_AND_LOOP__ 1

#include "qualifiers.hh"
#include "core/main.hh"

#define setup() \
    setup() __attribute__ ((naked, section(".init8"))); \
    void setup()

#define loop() \
    YAAL_INLINE("main loop") loop(); \
    void main() { for(;;) loop(); } \
    void loop()

#endif
