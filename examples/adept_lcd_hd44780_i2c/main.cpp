#include <yaal/io/ports.hh>
#include <yaal/devices/lcd_hd44780.hh>
#include <yaal/types/pinset.hh>

using namespace yaal;

uint8_t hbyte_to_hex(uint8_t hbyte) {
    return hbyte < 10 ? '0' + hbyte : 'a' + hbyte - 10;
}

uint16_t byte_to_hex(uint8_t byte) {
    return hbyte_to_hex(byte >> 4) << 8 | hbyte_to_hex(byte & 0x0f);
}

// There are two different pin configurations I know of. Pick whichever works.
// Don't forget to select the correct polarity for the backlight pin. If there
// is no backlight, toggle the polarity and you'll be fine.
// Typical I2C addresses are 0x20-0x27 and 0x38-0x3F.
//typedef LCDInterface_I2C<6, 5, 4, 0, 1, 2, 3, 7, false, 0x20> I2CInterface;
typedef LCDInterface_I2C<0, 1, 2, 4, 5, 6, 7, 3, true, 0x27> I2CInterface;
typedef LiquidCrystalHD44780<I2CInterface, 2, false> LCD;

void main() {

    // Use 2 lines, 5x8 font for the LCD
    LCD lcd;

    // Initialize the interface.
    lcd.setup();

    // Display on, cursor on, blink on.
    lcd.display_control(true, true, true);

    // Clear display.
    lcd.clear();

    // Set entry mode: increment, no shift.
    lcd.entry_mode(LCD::INCREMENT, false);

    // Write the character 'H'.
    lcd.put_char('H');

    // Write the character 'i'.
    lcd.put_char('i');

    // Write a string.
    lcd.put_string(", Mom!");

    // Read the first character on the first line
    // and copy it to the second line.
    // This is a bit complicated.

    // 1. Set the DDRAM address to the beginning of the first line.
    lcd.set_ddram_addr(0x00);

    // 2. Read the character.
    uint8_t c = lcd.read_char();

    // 3. Set the DDRAM address to the beginning of the second line.
    lcd.set_ddram_addr(0x40);

    // 4. Write the character.
    lcd.put_char(c);

    // Some debugging: print the hex value of the character read.
    {
        uint16_t chars = byte_to_hex(c);
        char a = chars >> 8;
        char b = chars & 0xff;
        lcd.put_char(a);
        lcd.put_char(b);
        lcd.put_char(' ');
    }

    // Some more debugging: print the expected hex value.
    {
        uint16_t chars = byte_to_hex('H');
        char a = chars >> 8;
        char b = chars & 0xff;
        lcd.put_char(a);
        lcd.put_char(b);
        lcd.put_char(' ');
    }

    // Create a custom character glyph and use it.
    // Borrowed the glyph from the CustomCharacter
    // Arduino sketch.
    uint8_t heart[8] = {
            0b00000,
            0b01010,
            0b11111,
            0b11111,
            0b11111,
            0b01110,
            0b00100,
            0b00000
    };

    // Set the first glyph in CGRAM.
    lcd.set_cgram_addr(0x00);
    for (uint8_t i = 0; i < 8; ++i)
        lcd.put_char(heart[i]);

    // Position the cursor right after "Hi, mom!".
    lcd.set_cursor_pos(0, 9);

    lcd.put_char(0x00);

    // Position the cursor on the end of the third line.
    lcd.set_cursor_pos(2, 19);

    lcd.put_char(0x00);

    // Position the cursor on the end of the fourth line.
    lcd.set_cursor_pos(3, 19);

    lcd.put_char(0x00);
}

