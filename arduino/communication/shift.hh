#ifndef __YAAL_ARDUINO__COMMUNICATION__SHIFT__
#define __YAAL_ARDUINO__COMMUNICATION__SHIFT__ 1

#include "../../communication/shift.hh"
#include "../../io/null.hh"

namespace yaal {
	namespace arduino {

		template<typename ClockPin, typename WritePin>
		void shiftOut(ClockPin, WritePin, uint8_t byte, bool LSBfirst = true) {
			if (LSBfirst)
				internal::shiftByte<ClockPin, WritePin, NullPin, true>(byte);
			else
				internal::shiftByte<ClockPin, WritePin, NullPin, false>(byte);
		}

		template<typename ClockPin, typename ReadPin>
		uint8_t shiftIn(ClockPin, ReadPin, bool LSBfirst = true) {
			if (LSBfirst)
				return internal::shiftByte<ClockPin, NullPin, ReadPin, true>();
			else
				return internal::shiftByte<ClockPin, NullPin, ReadPin, false>();
		}

	}
}

#endif
