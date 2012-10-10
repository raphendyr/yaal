
#include "io.hh"

namespace yaal {

	template<typename ClockPin, typename WritePin, typename ReadPin, bool LSBfirst>
	struct SoftTwoWireInterface {
		typedef ClockPin clock;
		typedef WritePin output;
		typedef ReadPin  input;

		static writeByte() {
		}

		static readByte() {
		}

		static uint8_t transferByte(uint8_t byte) {
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
	};

	namespace arduino {
	
		template<typename ClockPin, typename WritePin, bool LSBfirst>
		void shiftOut(uint8_t byte) {
			return SoftTwoWireInterface<ClockPin, WritePin, NullPin, LSBfirst>::writeByte(byte);
		}

		template<typename ClockPin, typename ReadPin, bool LSBfirst>
		uint8_t shiftIn(void) {
			return SoftTwoWireInterface<ClockPin, NullPin, ReadPin, LSBfirst>::readByte();
		}

	}
}

void shift_register_bus_##busname##_write_byte(unsigned char byte) { 
    for (unsigned char mask = 0x01; mask > 0; mask <<= 1) { 
        if (byte & mask) { 
            shift_register_bus_##busname##_data_high(); 
        } else { 
            shift_register_bus_##busname##_data_low(); 
        } 
        shift_register_bus_##busname##_clock_pulse(); 
    } 
} 
unsigned char shift_register_bus_##busname##_read_byte() { 
    unsigned char byte = 0; 
    for (unsigned char i = 0; i < 8; i++) { 
        shift_register_bus_##busname##_clock_high(); 
        byte <<= 1; 
        if (shift_register_bus_##busname##_read_data())
            byte |= 1; 
        shift_register_bus_##busname##_clock_low(); 
    } 
    return byte; 
} 


uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder) {
	uint8_t value = 0;
	uint8_t i;

	for (i = 0; i < 8; ++i) {
		digitalWrite(clockPin, HIGH);
		if (bitOrder == LSBFIRST)
			value |= digitalRead(dataPin) << i;
		else
			value |= digitalRead(dataPin) << (7 - i);
		digitalWrite(clockPin, LOW);
	}
	return value;
}

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val)
{
	uint8_t i;

	for (i = 0; i < 8; i++)  {
		if (bitOrder == LSBFIRST)
			digitalWrite(dataPin, !!(val & (1 << i)));
		else	
			digitalWrite(dataPin, !!(val & (1 << (7 - i))));
			
		digitalWrite(clockPin, HIGH);
		digitalWrite(clockPin, LOW);		
	}
}




