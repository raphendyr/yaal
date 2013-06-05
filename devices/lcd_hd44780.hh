#ifndef __YAAL_DEVICES__LCD_HD44780__
#define __YAAL_DEVICES__LCD_HD44780__ 1
#include "../requirements.hh"
#include <util/delay.h>
#ifdef __YAAL__

namespace yaal {

    template<typename Interface, uint8_t lines = 2, bool bigfont = false>
    class LiquidCrystalHD44780 {
        // The constants below are mostly borrowed from the Arduino
        // LiquidCrystal library.

        // commands
        static constexpr uint8_t LCD_CLEARDISPLAY = 0x01;
        static constexpr uint8_t LCD_RETURNHOME = 0x02;
        static constexpr uint8_t LCD_ENTRYMODESET = 0x04;
        static constexpr uint8_t LCD_DISPLAYCONTROL = 0x08;
        static constexpr uint8_t LCD_CURSORSHIFT = 0x10;
        static constexpr uint8_t LCD_FUNCTIONSET = 0x20;
        static constexpr uint8_t LCD_SETCGRAMADDR = 0x40;
        static constexpr uint8_t LCD_SETDDRAMADDR = 0x80;

        // flags for display entry mode
        // (These are named differently from Arduino LiquidCrystal.)
        static constexpr uint8_t LCD_ENTRYINCREMENT = 0x02;
        static constexpr uint8_t LCD_ENTRYDECREMENT = 0x00;
        static constexpr uint8_t LCD_ENTRYSHIFT = 0x01;
        static constexpr uint8_t LCD_ENTRYNOSHIFT = 0x00;

        // flags for display on/off control
        static constexpr uint8_t LCD_DISPLAYON = 0x04;
        static constexpr uint8_t LCD_DISPLAYOFF = 0x00;
        static constexpr uint8_t LCD_CURSORON = 0x02;
        static constexpr uint8_t LCD_CURSOROFF = 0x00;
        static constexpr uint8_t LCD_BLINKON = 0x01;
        static constexpr uint8_t LCD_BLINKOFF = 0x00;

        // flags for display/cursor shift
        static constexpr uint8_t LCD_DISPLAYMOVE = 0x08;
        static constexpr uint8_t LCD_CURSORMOVE = 0x00;
        static constexpr uint8_t LCD_MOVERIGHT = 0x04;
        static constexpr uint8_t LCD_MOVELEFT = 0x00;

        // flags for function set
        static constexpr uint8_t LCD_8BITMODE = 0x10;
        static constexpr uint8_t LCD_4BITMODE = 0x00;
        static constexpr uint8_t LCD_2LINE = 0x08;
        static constexpr uint8_t LCD_1LINE = 0x00;
        static constexpr uint8_t LCD_5x10DOTS = 0x04;
        static constexpr uint8_t LCD_5x8DOTS = 0x00;

        Interface interface;

        uint8_t read_bf_addr() {
           interface.set_RS(false); // Select instruction register.
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
            const uint8_t bits = interface.init() == Interface::_4BIT
                                 ? LCD_4BITMODE
                                 : LCD_8BITMODE;
            const uint8_t l = lines > 1 ? LCD_2LINE : LCD_1LINE;
            const uint8_t f = bigfont ? LCD_5x10DOTS : LCD_5x8DOTS;
            interface.write(LCD_FUNCTIONSET | bits | l | f);
        }

        void clear() {
            interface.set_RS(false); // Select instruction register.
            interface.write(LCD_CLEARDISPLAY);
            _delay_us(2000); // Clearing takes at most 1.52 ms.
        }

        void home() {
            interface.set_RS(false); // Select instruction register.
            interface.write(LCD_RETURNHOME);
            _delay_us(2000); // Returning home takes at most 1.52 ms.
        }

        void display_control(bool display_on, bool cursor_on, bool blink_on) {
            interface.set_RS(false); // Select instruction register.
            interface.write(LCD_DISPLAYCONTROL |
                            (display_on ? LCD_DISPLAYON : LCD_DISPLAYOFF) |
                            (cursor_on  ? LCD_CURSORON  : LCD_CURSOROFF)  |
                            (blink_on   ? LCD_BLINKON   : LCD_BLINKOFF));
        }

        void entry_mode(IncDec id, bool shift) {
            interface.set_RS(false); // Select instruction register.
            interface.write(LCD_ENTRYMODESET |
                           (id == INCREMENT ? LCD_ENTRYINCREMENT : LCD_ENTRYDECREMENT) |
                           (shift ? LCD_ENTRYSHIFT : LCD_ENTRYNOSHIFT));
        }

        void cursor_display_shift(CurDispShift op, ShiftDirection dir) {
            interface.set_RS(false); // Select instruction register.
            interface.write(LCD_CURSORSHIFT |
                            (op == MOVE_CURSOR ? LCD_CURSORMOVE : LCD_DISPLAYMOVE) |
                            (dir == LEFT ? LCD_MOVELEFT : LCD_MOVERIGHT));
        }

        void set_cgram_addr(uint8_t addr) {
            interface.set_RS(false); // Select instruction register.
            interface.write(LCD_SETCGRAMADDR | (addr & ~0xc0));
        }

        void set_ddram_addr(uint8_t addr) {
            interface.set_RS(false); // Select instruction register.
            interface.write(LCD_SETDDRAMADDR | (addr & ~0x80));
        }

        uint8_t read_char() {
            interface.set_RS(true); // Select data register.
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
            interface.set_RS(true); // Select data register.
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

        void pulse_enable() {
            enable_pin = true;
            _delay_us(1); // >450 ns is a sufficient pulse width.
            enable_pin = false;
        }

        void write4(uint8_t value) {
            D0_pin = value & 0x01;
            D1_pin = value & 0x02;
            D2_pin = value & 0x04;
            D3_pin = value & 0x08;
            pulse_enable();
        }

        // A 4-bit read.
        uint8_t read4() {
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

    public:

        enum BitMode : uint8_t {
            _4BIT,
            _8BIT
        };

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
            pulse_enable();
            _delay_us(4500); // >4.1 ms + >37 us is enough.

            // Two.
            pulse_enable();
            _delay_us(150); // >100 us + >37 us is enough.

            // Three.
            pulse_enable();
            _delay_us(50); // >37 us is enough for commands.

            // Four: finally set 4-bit mode.
            D0_pin = false;
            pulse_enable();
            _delay_us(50); // >37 us is enough for commands.

            return _4BIT;
        }

        // An 8-bit write, with a delay to wait for command completion.
        void write(uint8_t value) {
            write4(value >> 4);
            write4(value);
            _delay_us(50); // >37 us is enough for commands.
        }

        // An 8-bit read, with a delay to wait for command completion.
        // Used for other read commands than reading the busy flag.
        uint8_t read() {
            uint8_t ret = read_fast();
            _delay_us(50); // >37 us is enough for commands.

            return ret;
        }

        // An 8-bit read without a delay. Used for reading the busy flag.
        uint8_t read_fast() {
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

        void set_RS(bool value) {
            rs_pin = value;
        }

    };
}

#endif
#endif
