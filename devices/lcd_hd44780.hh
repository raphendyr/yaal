#ifndef __YAAL_DEVICES__LCD_HD44780__
#define __YAAL_DEVICES__LCD_HD44780__ 1
#include "../requirements.hh"
#include <util/delay.h>
#ifdef __YAAL__

// The #defines below are borrowed from the Arduino LiquidCrystal library.

// commands
#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0x20
#define LCD_SETCGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

// flags for display entry mode
#if 0
        // megari sez: These are very misleadingly named.
        #define LCD_ENTRYRIGHT 0x00
        #define LCD_ENTRYLEFT 0x02
        #define LCD_ENTRYSHIFTINCREMENT 0x01
        #define LCD_ENTRYSHIFTDECREMENT 0x00
#else
// megari sez: These are far better names.
#define LCD_ENTRYINCREMENT 0x02
#define LCD_ENTRYDECREMENT 0x00
#define LCD_ENTRYSHIFT 0x01
#define LCD_ENTRYNOSHIFT 0x00
#endif

// flags for display on/off control
#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x02
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

// flags for display/cursor shift
#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMOVE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

// flags for function set
#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

namespace yaal {

    template<typename Interface, uint8_t lines = 2, bool bigfont = false>
    class LiquidCrystalHD44780 {
        Interface interface;

        uint8_t read_bf_addr() {
           interface.setRS(false); // Select instruction register.
           return interface.read_fast();
        }
    public:

        enum IncDec : uint8_t {
            INCREMENT,
            DECREMENT
        };

        enum CurDispShift : uint8_t {
            MOVE_CURSOR,
            SHIFT_DISPLAY
        };

        enum ShiftDirection : uint8_t {
            RIGHT,
            LEFT
        };

        void init() {
            // Function set: set bitmode, # of lines and font.
            const uint8_t bits = interface.init();
            const uint8_t l = lines > 1 ? LCD_2LINE : LCD_1LINE;
            const uint8_t f = bigfont ? LCD_5x10DOTS : LCD_5x8DOTS;
            interface.write(LCD_FUNCTIONSET | bits | l | f);
        }

        void clear() {
            interface.setRS(false); // Select instruction register.
            interface.write(LCD_CLEARDISPLAY);
            _delay_us(2000); // Clearing takes at most 1.52 ms.
        }

        void home() {
            interface.setRS(false); // Select instruction register.
            interface.write(LCD_RETURNHOME);
            _delay_us(2000); // Returning home takes at most 1.52 ms.
        }

        void display_control(bool display_on, bool cursor_on, bool blink_on) {
            interface.setRS(false); // Select instruction register.
            interface.write(LCD_DISPLAYCONTROL |
                            (display_on ? LCD_DISPLAYON : LCD_DISPLAYOFF) |
                            (cursor_on  ? LCD_CURSORON  : LCD_CURSOROFF)  |
                            (blink_on   ? LCD_BLINKON   : LCD_BLINKOFF));
        }

        void entry_mode(IncDec id, bool shift) {
            interface.setRS(false); // Select instruction register.
            interface.write(LCD_ENTRYMODESET |
                           (id == INCREMENT ? LCD_ENTRYINCREMENT : LCD_ENTRYDECREMENT) |
                           (shift ? LCD_ENTRYSHIFT : LCD_ENTRYNOSHIFT));
        }

        void cursor_display_shift(CurDispShift op, ShiftDirection dir) {
            interface.setRS(false); // Select instruction register.
            interface.write(LCD_CURSORSHIFT |
                            (op == MOVE_CURSOR ? LCD_CURSORMOVE : LCD_DISPLAYMOVE) |
                            (dir == LEFT ? LCD_MOVELEFT : LCD_MOVERIGHT));
        }

        void set_cgram_addr(uint8_t addr) {
            interface.setRS(false); // Select instruction register.
            interface.write(LCD_SETCGRAMADDR | (addr & ~0xc0));
        }

        void set_ddram_addr(uint8_t addr) {
            interface.setRS(false); // Select instruction register.
            interface.write(LCD_SETDDRAMADDR | (addr & ~0x80));
        }

        uint8_t read_char() {
            interface.setRS(true); // Select data register.
            return interface.read();
        }

        bool read_busy() {
            return read_bf_addr() & 0x80;
        }

        uint8_t read_addr() {
            return read_bf_addr() & 0x7f;
        }

        // Puts a character into DDRAM or CGRAM. In the latter case, remember
        // that multiple calls are needed to define a glyph!
        void put_char(uint8_t c) {
            interface.setRS(true); // Select data register.
            interface.write(c);
        }

        void put_string(char const *str) {
            while (*str != '\0')
                    put_char(*str++);
        }

        void set_cursor_pos(uint8_t row, uint8_t column) {
            // The HD44780 datasheet doesn't define what the row offsets should
            // be for >2-line displays, but the following arrangement seems
            // to be used by 4-line LCDs touted as HD44780 compatible. It covers
            // the entire 80-byte DDRAM of a 4x20 display exactly.
            static const uint8_t offsets[] = { 0x00, 0x40, 0x14, 0x54 };
            set_ddram_addr(offsets[row] + column);
        }
    };

    template<typename RS, typename RW, typename Enable, typename D0, typename D1, typename D2, typename D3>
    class FourBitLCDInterface {
        RS rs_pin;
        RW rw_pin;
        Enable enable_pin;
        D0 D0_pin;
        D1 D1_pin;
        D2 D2_pin;
        D3 D3_pin;


        void pulseEnable() {
            enable_pin = true;
            _delay_us(1); // >450 ns is a sufficient pulse width.
            enable_pin = false;
            _delay_us(50); // >37 us is enough for commands.
        }

        void write4(uint8_t value) {
            D0_pin = value & 0x01;
            D1_pin = value & 0x02;
            D2_pin = value & 0x04;
            D3_pin = value & 0x08;
            pulseEnable();
        }

        // A 4-bit read without an additional delay.
        uint8_t read4_fast() {
            enable_pin = true;
            _delay_us(1); // >450 ns is a sufficient pulse width.
                          // This also includes a max 160 ns delay for data.

            uint8_t ret = (D0_pin ? 0x01 : 0x00) |
                          (D1_pin ? 0x02 : 0x00) |
                          (D2_pin ? 0x04 : 0x00) |
                          (D3_pin ? 0x08 : 0x00);

            enable_pin = false;

            return ret;
        }

        // A 4-bit read with a 50 us delay. Used for most read commands.
        uint8_t read4() {
            uint8_t ret = read4_fast();
            _delay_us(50); // >37 us is enough for commands.
            return ret;
        }

    public:

        // Returns the correct bit mode.
        uint8_t init() {
            rs_pin.mode = OUTPUT;
            rw_pin.mode = OUTPUT;
            enable_pin.mode = OUTPUT;
            D0_pin.mode = OUTPUT;
            D1_pin.mode = OUTPUT;
            D2_pin.mode = OUTPUT;
            D3_pin.mode = OUTPUT;

            _delay_ms(50);

            rs_pin = false;
            rw_pin = false;
            enable_pin = false;

            // Set 4-bit interface in four steps.
            // Effectively, LCD_FUNCTIONSET | LCD_8BITMODE
            // is sent 3 times when the interface length is still 8 bits
            // and finally the interface is set to 4 bits long.
            D0_pin = true;
            D1_pin = true;
            D2_pin = false;
            D3_pin = false;

            // One.
            pulseEnable();
            _delay_us(4500); // >4.1 ms is enough.

            // Two.
            pulseEnable();
            _delay_us(150); // >100 us is enough.

            // Three.
            pulseEnable();
            // No delay necessary.

            // Four: finally set 4-bit mode.
            D0_pin = false;
            pulseEnable();

            return LCD_4BITMODE;
        }

        // An 8-bit write.
        void write(uint8_t value) {
            write4(value >> 4);
            write4(value);
        }

        // An 8-bit read, with a delay after each 4-bit read.
        // Used for most read commands.
        uint8_t read() {
            D0_pin.mode = INPUT;
            D1_pin.mode = INPUT;
            D2_pin.mode = INPUT;
            D3_pin.mode = INPUT;
            rw_pin = true;

            uint8_t ret = read4() << 4;
            ret |= read4() & 0x0f;

            rw_pin = false;
            D0_pin.mode = OUTPUT;
            D1_pin.mode = OUTPUT;
            D2_pin.mode = OUTPUT;
            D3_pin.mode = OUTPUT;

            return ret;
        }

        // An 8-bit read without a delay.
        uint8_t read_fast() {
            D0_pin.mode = INPUT;
            D1_pin.mode = INPUT;
            D2_pin.mode = INPUT;
            D3_pin.mode = INPUT;
            rw_pin = true;

            uint8_t ret = read4_fast() << 4;
            ret |= read4_fast() & 0x0f;

            rw_pin = false;
            D0_pin.mode = OUTPUT;
            D1_pin.mode = OUTPUT;
            D2_pin.mode = OUTPUT;
            D3_pin.mode = OUTPUT;

            return ret;
        }

        void setRS(bool value) {
            rs_pin = value;
        }
    };
}

#endif
#endif
