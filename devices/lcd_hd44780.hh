#ifndef __YAAL_DEVICES__LCD_HD44780__
#define __YAAL_DEVICES__LCD_HD44780__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include <util/delay.h>
#include "../../communication/i2c_hw.hh"
#include "lcd_backpack.hh"

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

        void setup() {
            // Function set: set bitmode, # of lines and font.
            const uint8_t bits = interface.setup() == Interface::_4BIT
                                 ? LCD_4BITMODE
                                 : LCD_8BITMODE;
            const uint8_t l = lines > 1 ? LCD_2LINE : LCD_1LINE;
            const uint8_t f = bigfont ? LCD_5x10DOTS : LCD_5x8DOTS;
            interface.write(LCD_FUNCTIONSET | bits | l | f);
        }

        void clear() {
            interface.set_RS(false); // Select instruction register.
            interface.write(LCD_CLEARDISPLAY);
        }

        void home() {
            interface.set_RS(false); // Select instruction register.
            interface.write(LCD_RETURNHOME);
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

    template<typename RS, typename RW, typename Enable, typename DataSet>
    class LCDInterface {
        static_assert(DataSet::size == 4 || DataSet::size == 8,
                      "Only DataSet with size of 4 or 8 is supported.");

        RS rs_pin;
        RW rw_pin;
        Enable enable_pin;
        DataSet data;

        void pulse_enable() {
            enable_pin = true;
            _delay_us(1); // >450 ns is a sufficient pulse width.
            enable_pin = false;
        }

        void write_real(uint8_t value) {
            data = value;
            pulse_enable();
        }

        uint8_t read_real() {
            enable_pin = true;
            _delay_us(1); // >450 ns is a sufficient pulse width.
                          // This also includes a max 360 ns delay for data.

            uint8_t ret = data;

            enable_pin = false;

            return ret;
        }

        // Wait until the LCD clears the busy flag.
        void wait_busy() {
            bool old_rs = rs_pin.output;
            rs_pin = false;
            while (read_fast() & 0x80);
            rs_pin = old_rs;
        }

    public:

        enum BitMode : uint8_t {
            _4BIT = 4,
            _8BIT = 8
        };

        // Returns the correct bit mode.
        uint8_t setup() {
            rs_pin.mode = OUTPUT;
            rw_pin.mode = OUTPUT;
            enable_pin.mode = OUTPUT;
            data.set_output();

            _delay_ms(50);

            rs_pin = false;
            rw_pin = false;
            enable_pin = false;

            if (DataSet::size == 4) {
                // Set 4-bit interface in four steps.
                // Effectively, LCD_FUNCTIONSET | LCD_8BITMODE
                // is sent 3 times when the interface length is still 8 bits
                // and finally the interface is set to 4 bits long.
                data = 0x03;

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
                data = 0x02;
                pulse_enable();
                _delay_us(50); // >37 us is enough for commands.
            }
            else {
                // Set 8-bit interface in 3 steps.
                // Effectively, LCD_FUNCTIONSET | LCD_8BITMODE
                // is sent 3 times.
                data = 0x30;

                // One.
                pulse_enable();
                _delay_us(4500); // >4.1 ms + >37 us is enough.

                // Two.
                pulse_enable();
                _delay_us(150); // >100 us + >37 us is enough.

                // Three.
                pulse_enable();
                _delay_us(50); // >37 us is enough for commands.
            }

            return DataSet::size;
        }

        // An 8-bit write, with a wait for the busy flag.
        void write(uint8_t value) {
            wait_busy();

            if (DataSet::size == 4) {
                write_real(value >> static_cast<uint8_t>(4));
                write_real(value);
            }
            else
                write_real(value);
        }

        // An 8-bit read, with a wait for the busy flag.
        // Used for other read commands than reading the busy flag.
        uint8_t read() {
            wait_busy();
            uint8_t ret = read_fast();
            return ret;
        }

        // An 8-bit read without a wait. Used for reading the busy flag.
        uint8_t read_fast() {
            data.set_input();
            rw_pin = true;

            uint8_t ret;

            if (DataSet::size == 4) {
                ret = read_real() << static_cast<uint8_t>(4);
                ret |= read_real() & 0x0f;
            }
            else
                ret = read_real();

            rw_pin = false;
            data.set_output();

            return ret;
        }

        void set_RS(bool value) {
            rs_pin = value;
        }

    };


    // Supports PCF8574/PCF8574A based I2C expanders.
    template<typename Backpack_type, uint8_t address, typename SDA = PortC4, typename SCL = PortC5>
    class LCDInterface_I2C {

        SDA sda;
        SCL scl;

        Backpack_type status;

        void commit_status() {
            I2c_HW.write(address, status.value);
        }

        void read_data() {
            Backpack_type new_status;
            new_status.value = I2c_HW.read(address);
            // Update only data bits.
            status.bits.data = new_status.bits.data;
        }

        void pulse_enable() {
            commit_status(); // This needs to be here because there must be
                             // at least 60 ns between setting RS+RW and Enable.
                             // At 16 MHz, 1 instruction takes 62.5 ns.
            status.bits.enable = 1;
            commit_status();
            _delay_us(1); // >450 ns is a sufficient pulse width.
            status.bits.enable = 0;
            commit_status();
        }

        void write_real(uint8_t value) {
            status.bits.data = value;
            pulse_enable();
        }

        uint8_t read_real() {
            commit_status(); // This needs to be here because there must be
                             // at least 60 ns between setting RS+RW and Enable.
                             // At 16 MHz, 1 instruction takes 62.5 ns.
            status.bits.enable = 1;
            status.bits.data = 0x0f; // This seems to be needed for the read to work.
            commit_status();
            _delay_us(1); // >450 ns is a sufficient pulse width.
                          // This also includes a max 360 ns delay for data.

            read_data();
            uint8_t ret = status.bits.data;
            
            status.bits.enable = 0;
            commit_status();

            return ret;
        }

        // Wait until the LCD clears the busy flag.
        void wait_busy() {
            uint8_t old_rs = status.bits.rs;
            status.bits.rs = 0;
            while (read_fast() & 0x80);
            status.bits.rs = old_rs;
        }

    public:

        enum BitMode : uint8_t {
            _4BIT = 4,
            _8BIT = 8
        };

        // Returns the correct bit mode.
        uint8_t setup() {
            sda.mode = INPUT_PULLUP;
            scl.mode = INPUT_PULLUP;
            sei();

            I2c_HW.setup();

            _delay_ms(50);

            status.bits.rs = 0;
            status.bits.rw = 0;
            status.bits.enable = 0;
            status.bits.backlight = Backpack_type::backlight_polarity; // Always enable backlight.

            // Set 4-bit interface in four steps.
            // Effectively, LCD_FUNCTIONSET | LCD_8BITMODE
            // is sent 3 times when the interface length is still 8 bits
            // and finally the interface is set to 4 bits long.
            status.bits.data = 0x03;

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
            status.bits.data = 0x02;
            pulse_enable();
            _delay_us(50); // >37 us is enough for commands.

            return _4BIT;
        }

        // An 8-bit write, with a wait for the busy flag.
        void write(uint8_t value) {
            wait_busy();
            write_real(value >> static_cast<uint8_t>(4));
            write_real(value);
        }

        // An 8-bit read, with a wait for the busy flag.
        // Used for other read commands than reading the busy flag.
        uint8_t read() {
            wait_busy();
            uint8_t ret = read_fast();
            return ret;
        }

        // An 8-bit read without a wait. Used for reading the busy flag.
        uint8_t read_fast() {
            status.bits.rw = 1;

            uint8_t ret;

            ret = read_real() << static_cast<uint8_t>(4);
            ret |= read_real() & 0x0f;

            status.bits.rw = 0;

            return ret;
        }

        void set_RS(bool value) {
            status.bits.rs = value ? 1 : 0;
        }

    };
}

#endif
#endif
