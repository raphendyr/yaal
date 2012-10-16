#ifndef __YAAL_SETUP_AND_LOOP__
#define __YAAL_SETUP_AND_LOOP__ 1

YAAL_INLINE("Setup")
void setup();

YAAL_INLINE("Loop")
void loop();

void main() __attribute__((noreturn));
void main() {
    setup();

    for (;;) {
        loop();
    }
}

#endif
