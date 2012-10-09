#ifndef __YAAL_ARDUINO__PINOUT__
#define __YAAL_ARDUINO__PINOUT__ 1

#include "pins.hh"

#if defined(ARDUINO_teensy)
# include "pinout/teensy.hh"
#else
# error "You didn't define arduino board or it is not supported yet."
#endif

#endif
