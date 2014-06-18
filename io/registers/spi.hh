#ifndef __YAAL_IO__REGISTERS__SPI__
#define __YAAL_IO__REGISTERS__SPI__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

namespace yaal {

    namespace internal {

        struct SpiRegisters {
            typedef Register<YAAL_ADDR(SPCR)> Control;
            SingleBit<Control, 7> interrupt_enable;
            SingleBit<Control, 6> enable;
            SingleBit<Control, 5> data_order; // 1 = LSB, 0 = MSB
            SingleBit<Control, 4> master_mode;
            SingleBit<Control, 3> clock_polarity;
            SingleBit<Control, 2> clock_phase;
            SingleBit<Control, 1> clock_rate1;
            SingleBit<Control, 0> clock_rate0;
    
            typedef Register<YAAL_ADDR(SPSR)> Status;
            SingleBit<Status, 7> interrupt_flag;
            SingleBit<Status, 6> write_collision_flag;
            SingleBit<Status, 0> clock_rate2x;
    
            typedef Register<YAAL_ADDR(SPDR)> Data;
            Data data;
        }

    }
}

#endif
#endif
