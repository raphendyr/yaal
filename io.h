#ifndef __YAAL_IO_H__
#define __YAAL_IO_H__ 1

#include "requirements.h"

#include <avr/io.h>
#include <inttypes.h>

// from lib/util.h
#define SHIFT8BIT_RIGHT(val, num)       ((unsigned char)(val) >> (num))
#define SHIFT8BIT_LEFT(val, num)        ((unsigned char)(val) << (num))
#define DIV2(val)                                       SHIFT8BIT_RIGHT(val, 1)
#define MUL2(val)                                       SHIFT8BIT_LEFT(val, 1)
#define NEG(byte)                                       ((unsigned char)~(byte))
#define BITSET(port, num)       ((port) |= _BV(num))
#define BITCLR(port, num)       ((port) &= NEG(_BV(num)))
#define BITGET(port, num)       ((port) & _BV(num))

// wrapper and unwrapper
#define YAAL_REG(addr) (*reinterpret_cast<reg_t>(addr))
#define YAAL_ADDR(reg) (reinterpret_cast<reg_a_t(reg))


namespace yaal {

    typedef uint8_t reg_a_t;
    typedef volatile uint8_t* reg_t;


    template<reg_a_t reg>
    struct ReadonlyRegister {
        static uint8_t get(void) {
            return YAAL_REG(reg);
        }

        // TODO: kokeile kääntyykö
        uint8_t operator uint8_t(void) const {
            // read: Register x; y = x;
            return YAAL_REG(reg);
        }
    };

    template<reg_a_t reg>
    struct WriteonlyRegister {
        static void set(uint8_t value) {
            YAAL_REG(reg) = value;
        }
        
    };

    template<reg_a_t reg>
    struct Register : public ReadonlyRegister {
        static void set(uint8_t value) {
            YAAL_REG(reg) = value;
        }

        // TODO: does this optimize correctly?
        static void setBit(uint8_t bit, bool state = true) {
            if (state)
                BITSET(YAAL_REG(reg), bit);
            else
                BITCLR(YAAL_REG(reg), bit);
        }

        static void clrBit(uint8_t bit) {
            setBit(bit, false);
        }

        /*
        Register<reg>& operator=(uint8_t value) {
            set(value);
            return *this;
        }
        */

        // TODO: kokeile kääntyykö
        uint8_t& operator uint8_t(void) {
            // write: Register x; x = 3; x |= 1 << 4;
            return YAAL_REG(reg);
        }
    };


    // Register port, Register ddr, ReadonlyRegister pin
    template<typename OutputClass, typename Directionclass, typename InputClass>
    struct Port {
        typedef OuputClass output;
        typedef DirectionClass direction;
        typedef InputClass input;

        Port() {}

        // there is no protection if port is in input state
        static void set(uint8_t value) {
            output::set(value);
        }

        static uint8_t get(void) {
            return input::get();
        }

        static void output(void) {
            // TODO: is this enough?
            direction::set(0xff);
        }

        static void input(void) {
            // TODO: is this enough?
            direction::set(0x00);
        }
    };


    template<typename PortClass, uint8_t bit>
    struct Pin {
        typedef PortClass port;

        static void set(bool state = true) {
            // TODO: do this optimize correctly?
            port::output::setBit(bit, state);
        }

        static void clear(void) {
            set(false);
        }

        static bool get(void) {
            return port::input::getBit(bit);
        }

        static void output(void) {
            // TODO: should we clear output state?
            port::output::clrBit(bit);
            port::direction::setBit(bit);
        }

        static void input(bool pullup = false) {
            // TODO: order of operations? order by variable? should we even touch on output bit?
            if (!pullup)
                port::output::clrBit(bit);
            port::direction::setBit(bit);
            if (pullup)
                port::output::setBit(bit);
        }
    };

}

#include "io_definitions.hpp"

#endif
