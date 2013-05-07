#ifndef __YAAL_ARDUINO__PINOUT__
#define __YAAL_ARDUINO__PINOUT__ 1

#include "pins.hh"

#define __YAAL_ARDUINO__PINOUT__LOCK 1

#if defined(ARDUINO_teensy)
# include "pinout/teensy.hh"
#elif defined(ARDUINO_standard) || defined(ARDUINO_eightanaloginputs)
// eightanaloginputs has 2 extra analog pins (no digital funktions)
# include "pinout/standard.hh"
#elif defined(ARDUINO_leonardo) || defined(ARDUINO_micro)
// micro has same pinout, only tx and rx leds are connected in reverse
# include "pinout/leonardo.hh"
#elif defined(ARDUINO_mega)
# include "pinout/mega.hh"
#else
# error "You didn't define arduino board or it is not supported yet."
#endif

#undef __YAAL_ARDUINO__PINOUT__LOCK

#endif
