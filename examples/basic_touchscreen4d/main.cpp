/*
 * A small program to run a 4D Systems touchscreen LCD.
 */
#include <util/delay.h>
#include "yaal/io/serials.hh"
#include "yaal/devices/touchscreen4d.hh"

#define COLOR_RED   0xf800
#define COLOR_GREEN 0x07e0
#define COLOR_BLUE  0x001f

typedef yaal::Touchscreen4D<yaal::Serial1> LCD;

int main() {
    _delay_ms(1000); // Wait for the LCD.

    LCD lcd;

    // Send the required Auto-Baud command.
    (void) lcd.init();

    // Clear the screen.
    (void) lcd.clear_screen();

    // Draw a character.
    (void) lcd.draw_char('A', 1, 1);

    // Change baud rate to 56700.
    (void) lcd.set_baud(56700);

    // Draw another character.
    (void) lcd.draw_char('B', 2, 1);

    // Enable touch screen.
    if (!lcd.toggle_touchscreen(true))
        (void) lcd.draw_char('F', 3, 1);
    else
        (void) lcd.draw_char('C', 3, 1);

    // Reset touch screen active region.
    if (!lcd.reset_active_touch_region())
        (void) lcd.draw_char('F', 4, 1);
    else
        (void) lcd.draw_char('D', 4, 1);


    // Set pen size so that things are drawn solid.
    if (!lcd.set_pen_size(true))
        (void) lcd.draw_char('F', 5, 1);
    else
        (void) lcd.draw_char('E', 5, 1);

    while (true) {
        // Wait for touch activity and get touch coordinates.
        LCD::TouchCoords coords = lcd.wait_until_touch(LCD::WAIT_ANY);

        // Check touch activity type and select color.
        int color;
        enum LCD::TouchActType act = lcd.get_touch_status();
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
            (void) lcd.draw_char('H', 6, 1);
        else
            (void) lcd.draw_char('F', 6, 1);

    }

    // Never reached.
    return 0;
}
