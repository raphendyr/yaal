#include <avr/io.h>
#include <inttypes.h>

#define SHIFT8BIT_RIGHT(val, num)       ((unsigned char)(val) >> (num))
#define SHIFT8BIT_LEFT(val, num)        ((unsigned char)(val) << (num))
#define DIV2(val)                                       SHIFT8BIT_RIGHT(val, 1)
#define MUL2(val)                                       SHIFT8BIT_LEFT(val, 1)
#define NEG(byte)                                       ((unsigned char)~(byte))
#define BITSET(port, num)       ((port) |= _BV(num))
#define BITCLR(port, num)       ((port) &= NEG(_BV(num)))
#define BITGET(port, num)       ((port) & _BV(num))


#define PORTA_A (0x1B + __SFR_OFFSET)
#define PORTB_A (0x18 + __SFR_OFFSET)
#define PORTC_A (0x15 + __SFR_OFFSET)
#define REG(addr) (*(volatile uint8_t*)(addr))


class IO {
    volatile uint8_t* const port;

public:
    IO(volatile uint8_t* p) : port(p) {}

    void set(uint8_t bit) const {
        // voi
        *port |= 1;
        // ei ovi
        *port |= 1 << bit;
    }
};

template<uint8_t port, uint8_t bit>
class Pin {
public:
    Pin() {}

    void operator=(bool state) const {
        if (state)
            BITSET(REG(port), bit);
        else
            BITCLR(REG(port), bit);
    }

    bool is(void) const {
        return !!BITGET(REG(port), bit);
    }

    bool operator*(void) const {
        return is();
    }
};

template<uint8_t port>
class Port {
public:
    Port() {}

    void operator=(uint8_t byte) const {
        REG(port) = byte;
    }

    void operator|=(uint8_t byte) const {
        REG(port) |= byte;
    }

    void operator&=(uint8_t byte) const {
        REG(port) &= byte;
    }

    uint8_t operator*(void) const {
        return REG(port);
    }
};

const Pin<PORTB_A, 0> PortB0;
const Pin<PORTB_A, 1> PortB1;
const Pin<PORTB_A, 2> PortB2;
const Pin<PORTB_A, 3> PortB3;
const Pin<PORTB_A, 4> PortB4;
const Pin<PORTB_A, 5> PortB5;
const Pin<PORTB_A, 6> PortB6;
const Pin<PORTB_A, 7> PortB7;
const Port<PORTB_A> PortB;


template<const Pin<uint8_t, uint8_t> pin>
class Test {
public:
    void test() {
        pin = 1;
    }
};


template<uint8_t sda_addr, uint8_t sda_bit, uint8_t scl_addr, uint8_t scl_bit>
class Bus {
public:
    Bus() {}

    void write(uint8_t byte) {
        for (uint8_t i = 0x80; i > 0; i >>= 1) {
            BITSET(REG(scl_addr), scl_bit);
            if (i & byte)
                BITSET(REG(sda_addr), sda_bit);
            else
                BITCLR(REG(sda_addr), sda_bit);
            BITCLR(REG(scl_addr), scl_bit);
        }
    }

    void read(uint8_t & byte) {
         for (uint8_t i = 0x80; i > 0; i >>= 1) {
            BITSET(REG(scl_addr), scl_bit);
            byte <<= 1;
            if (BITGET(REG(sda_addr), sda_bit))
                byte |= 1;
            BITCLR(REG(scl_addr), scl_bit);
        }
    }
};

Bus<PORTB_A, PORTB1, PORTC_A, PORTC6> bus;

int main(void) {
    uint8_t byte = 0x00;
    while (1) {
        bus.write(byte);
        bus.read(byte);

        // SET
        PortB4 = 1;
        PortB6 = 0;

        PortB = 0x01;
        BITSET(PortB, 7);

        // foo
        // bar
        Test<PortB1> test;
        test.test();
    }
}
