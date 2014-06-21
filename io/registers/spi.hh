#ifndef __YAAL_IO__REGISTERS__SPI__
#define __YAAL_IO__REGISTERS__SPI__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

#include <avr/io.h>
#include "../../types/register.hh"

namespace yaal {

    namespace internal {

        struct SpiRegisters {
            typedef Register<YAAL_ADDR(SPCR)> ControlRegister;
            typedef SingleBit<ControlRegister, 7> InterruptEnable;
            typedef SingleBit<ControlRegister, 6> Enable;
            typedef SingleBit<ControlRegister, 5> DataOrder; // 1 = LSB, 0 = MSB
            typedef SingleBit<ControlRegister, 4> MasterMode;
            typedef SingleBit<ControlRegister, 3> ClockPolarity;
            typedef SingleBit<ControlRegister, 2> ClockPhase;
            typedef SingleBit<ControlRegister, 1> ClockRate1;
            typedef SingleBit<ControlRegister, 0> ClockRate0;

            typedef Register<YAAL_ADDR(SPSR)> StatusRegister;
            typedef SingleBit<StatusRegister, 7> InterruptFlag;
            typedef SingleBit<StatusRegister, 6> WriteCollisionFlag;
            typedef SingleBit<StatusRegister, 0> ClockRate2x;

            typedef Register<YAAL_ADDR(SPDR)> Data;

            typedef SingleBit<Register<YAAL_ADDR(PRR0)>, PRSPI> Power;


            typedef SpiClockPrescaler2x<ClockRate2x, ClockRate1, ClockRate0> ClockPrescaler;
            typedef SpiClock<ClockPrescaler> Clock;
        };

    }
}

#endif
#endif
