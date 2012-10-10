
#include "io.hh"

namespace yaal {

	template<typename clock, typename output, bool LSBfirst>
	static void shiftByte(uint8_t byte) {
		for (uint8_t i = 0; i < 8; i++) {
			clock::high();
			if (byte & (LSBfirst ? 0x01 : 0x80))
				output::high();
			else
				output::low();
			byte = LSBfirst ? (byte >> 1) : (byte << 1);
			clock::low();
		}
	}

	template<typename clock, typename input, bool LSBfirst>
	static uint8_t shiftByte(void) {
		uint8_t byte = 0;
		for (uint8_t i = 0; i < 8; i++) {
			clock::high();
			byte = LSBfirst ? (byte >> 1) : (byte << 1);
			if (input::get())
				byte |= LSBfirst ? 0x80 : 0x01;
			clock::low();
		}
		return byte;
	}

	template<typename clock, typename output, typename input, bool LSBfirst>
	static uint8_t shiftByte(uint8_t byte) {
		for (uint8_t i = 0; i < 8; i++) {
			clock::high();
			if (byte & (LSBfirst ? 0x01 : 0x80))
				output::high();
			else
				output::low();
			byte = LSBfirst ? (byte >> 1) : (byte << 1);
			if (input::get())
				byte |= LSBfirst ? 0x80 : 0x01;
			clock::low();
		}
		return byte;
	}

	namespace arduino {
	
		template<typename ClockPin, typename WritePin, bool LSBfirst = true>
		void shiftOut(ClockPin, WritePin, uint8_t byte) {
			shiftByte<ClockPin, WritePin, LSBfirst>(byte);
		}

		template<typename ClockPin, typename ReadPin, bool LSBfirst = true>
		uint8_t shiftIn(ClockPin, ReadPin) {
			return shiftByte<ClockPin, ReadPin, LSBfirst>();
		}

	}
}

