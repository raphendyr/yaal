#ifndef __YAAL_IO__
#define __YAAL_IO__ 1

#include "requirements.hh"

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
#define YAAL_REG(reg_t, addr) (*reinterpret_cast<reg_t*>(addr))
#define YAAL_ADDR(reg) (reinterpret_cast<reg_a_t>(&(reg)))


namespace yaal {

    typedef uint16_t reg_a_t;
    typedef uint8_t bit_t;
    typedef volatile uint8_t reg8_t;
    typedef volatile uint16_t reg16_t;

    template <reg_a_t reg, typename reg_size = reg8_t>
    struct ReadableRegister {
        static reg_size get(void) {
            return YAAL_REG(reg_size, reg);
        }

        operator reg_size (void) const {
            // read: Register x; y = x;
            return YAAL_REG(reg_size, reg);
        }
    };

    template<reg_a_t reg, typename reg_size = reg8_t>
    struct WriteableRegister {
        static void set(reg_size value) {
            YAAL_REG(reg_size, reg) = value;
        }

        operator reg_size& (void) {
            // write: Register x; x = 3; x |= 1 << 4;
            return YAAL_REG(reg_size, reg);
        }
    };

    template <reg_a_t reg, typename reg_size = reg8_t>
    struct ReadonlyRegister : public ReadableRegister<reg, reg_size>, private WriteableRegister<reg, reg_size> {
        typedef reg_size size_type;
    };

    template<reg_a_t reg, typename reg_size = reg8_t>
    struct WriteonlyRegister : public WriteableRegister<reg, reg_size>, private ReadableRegister<reg, reg_size> {
        typedef reg_size size_type;
    };

    template<reg_a_t reg, typename reg_size = reg8_t>
    struct Register : public ReadableRegister<reg, reg_size>, public WriteableRegister<reg, reg_size> {
        typedef reg_size size_type;
    };


    // Register port, Register ddr, ReadonlyRegister pin
    template<typename OutputClass, typename DirectionClass, typename InputClass>
    struct Port {
        static OutputClass output;
        static DirectionClass direction;
        static InputClass input;
        typedef Port<OutputClass, DirectionClass, InputClass> self_type;

        // there is no protection if port is in input state
        static void set(typename OutputClass::size_type value) {
            output = value;
        }

        static typename InputClass::size_type get(void) {
            return input;
        }

        // FIXME: name collision with this function and output type
        static void set_output(void) {
            // TODO: is this enough?
            direction = ~(typename DirectionClass::size_type)0;
        }

        // FIXME: name collision with this function and input type
        static void set_input(void) {
            // TODO: is this enough?
            direction = 0;
        }

        operator typename InputClass::size_type (void) const {
            /* read: Port<> x; uint8_t value = x; */
            return get();
        }

        operator typename OutputClass::size_type& (void) {
            /* write: Register x; x = 3; x |= 1 << 4; */
            return output;
        }

        self_type& operator= (typename OutputClass::size_type value) {
            set(value);
            return *this;
        }
    };


    template<typename PortClass, bit_t bit>
    struct Pin {
        static PortClass port;
        typedef Pin<PortClass, bit> self_type;

        static void set(bool state = true) {
            if (state)
                port |= 1 << bit;
            else
                port &= ~(1 << bit);
        }

        static void clear(void) {
            set(false);
        }

        static bool get(void) {
            return port & (1 << bit);
        }

        static void output(void) {
            // TODO: should we clear output state?
            clear();
            port.direction |= (1 << bit);
        }

        static void input(bool pullup = false) {
            // TODO: order of operations? order by variable? should we even touch on output bit?
            if (!pullup)
                clear();
            port.direction &= ~(1 << bit);
            if (pullup)
                set();
        }
        operator bool (void) const {
            return get();
        }

        self_type& operator= (bool state) {
            set(state);
            return *this;
        }
    };

}

#include "io/ports.hh"
#include "io/other.hh"

#endif
