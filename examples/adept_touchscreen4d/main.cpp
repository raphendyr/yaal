#include <util/delay.h>
#include <yaal/core.hh>
#include <yaal/io/serial.hh>
#include <yaal/devices/touchscreen4d.hh>

using namespace yaal;

#define COLOR_RED   0xf800
#define COLOR_GREEN 0x07e0
#define COLOR_BLUE  0x001f

typedef Touchscreen4D<Serial1> LCD;
LCD lcd;

void setup() {
    // Wait for the LCD to bootup
    _delay_ms(1000);

    // Send the required Auto-Baud command.
    lcd.setup();

    // Clear the screen.
    lcd.clear_screen();
}

void main() {
    // Draw a character.
    lcd.draw_char('A', 1, 1);

    // Change baud rate to 56700.
    lcd.set_baud(56700);

    // Draw another character.
    lcd.draw_char('B', 2, 1);

    // Enable touch screen.
    if (!lcd.toggle_touchscreen(true))
        lcd.draw_char('F', 3, 1);
    else
        lcd.draw_char('C', 3, 1);

    // Reset touch screen active region.
    if (!lcd.reset_active_touch_region())
        lcd.draw_char('F', 4, 1);
    else
        lcd.draw_char('D', 4, 1);

    // Set pen size so that things are drawn solid.
    if (!lcd.set_pen_size(true))
        lcd.draw_char('F', 5, 1);
    else
        lcd.draw_char('E', 5, 1);


    for (;;) {
        // Wait for touch activity and get touch coordinates.
        LCD::TouchCoords coords = lcd.wait_until_touch(LCD::WAIT_ANY);

        // Check touch activity type and select color.
        uint16_t color;
        LCD::TouchActType act = lcd.get_touch_status();
        switch (act) {
            case LCD::ACT_PRESS:
                color = COLOR_RED;
                break;
            case LCD::ACT_RELEASE:
                color = COLOR_BLUE;
                break;
            case LCD::ACT_MOVING:
                color = COLOR_GREEN;
                break;
            default:
                color = COLOR_RED | COLOR_BLUE | COLOR_GREEN;
        }

        // Draw a circle around the touch area.
        if (!lcd.draw_ellipse(coords.x, coords.y, 10, 10, color))
            lcd.draw_char('H', 6, 1);
        else
            lcd.draw_char('F', 6, 1);
    }
}
