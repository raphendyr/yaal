#ifndef __YAAL_DEVICES__TOUCHSCREEN4D__
#define __YAAL_DEVICES__TOUCHSCREEN4D__ 1
#include "../requirements.hh"
#ifdef __YAAL__

namespace yaal {

    // The 4D Systems touchscreens use an initial baudrate of 9600 by default,
    // but this can be changed with a tool. Hence, allow for a different
    // default baudrate.
    template <typename SerialConnection, uint32_t initbaud = 9600>
    class Touchscreen4D {
    private:

        static constexpr uint8_t ACK = 0x06;
        static constexpr uint8_t NAK = 0x15;

        static constexpr uint8_t AUTOBAUD = 0x55;
        static constexpr uint8_t SETBAUD = 0x51;

        static constexpr uint8_t DISPCONTROL = 0x59;
        static constexpr uint8_t DISPCONTROL_TOUCH = 0x05;
        static constexpr uint8_t DISPCONTROL_TOUCH_ENABLE = 0x00;
        static constexpr uint8_t DISPCONTROL_TOUCH_DISABLE = 0x01;
        static constexpr uint8_t DISPCONTROL_TOUCH_RESET_ACTIVE = 0x02;

        static constexpr uint8_t CLEARSCREEN = 0x45;
        static constexpr uint8_t DRAWCHAR_TEXT = 0x54;
        static constexpr uint8_t DRAWELLIPSE = 0x65;
        static constexpr uint8_t SETPENSIZE = 0x70;
        static constexpr uint8_t PEN_SOLID = 0x00;
        static constexpr uint8_t PEN_WIREFRAME = 0x01;

        static constexpr uint8_t TOUCHCOORDS = 0x6f;
        static constexpr uint8_t TOUCHCOORDS_WAIT_ANY = 0x00;
        static constexpr uint8_t TOUCHCOORDS_WAIT_PRESS = 0x01;
        static constexpr uint8_t TOUCHCOORDS_WAIT_RELEASE = 0x02;
        static constexpr uint8_t TOUCHCOORDS_WAIT_MOVING = 0x03;
        static constexpr uint8_t TOUCHCOORDS_STATUS = 0x04;
        static constexpr uint8_t TOUCHCOORDS_GETCOORDINATES = 0x05;

        SerialConnection serial;

    public:

        enum TouchActType : uint8_t {
            ACT_NONE = 0,
            ACT_PRESS = 1,
            ACT_RELEASE = 2,
            ACT_MOVING = 3
        };

        struct TouchCoords {
            uint16_t x;
            uint16_t y;
        };

        enum TouchKind : uint8_t {
            WAIT_ANY = TOUCHCOORDS_WAIT_ANY,
            WAIT_PRESS = TOUCHCOORDS_WAIT_PRESS,
            WAIT_RELEASE = TOUCHCOORDS_WAIT_RELEASE,
            WAIT_MOVING = TOUCHCOORDS_WAIT_MOVING
        };

        enum RetStatus_ : uint8_t {
            OK = 0,
            FAIL = 1,
            CONNECTION_ERROR = 2
        };

        class RetStatus {
            RetStatus_ ret;
        public:
            RetStatus(bool code) = delete; // This is here to avoid bugs.

            constexpr RetStatus(uint8_t code)
                : ret(code == ACK ? OK : code == NAK ? FAIL : CONNECTION_ERROR) {}

            constexpr RetStatus(RetStatus_ const status) : ret(status) {}

            operator RetStatus_ () const {
                return ret;
            }

            explicit operator bool () const {
                return ret == OK;
            }

        };

        YAAL_INLINE("4D touchscreen init")
        RetStatus setup(uint32_t baud = initbaud) {
            serial.setBaud(initbaud);
            serial.setFrameFormat();
            serial.put(AUTOBAUD);

            RetStatus ret(serial.get());
            if (ret != OK)
                return ret;

            if (baud != initbaud)
                return set_baud(baud);

            return OK;
        }

        YAAL_INLINE("4D touchscreen set baud")
        RetStatus set_baud(uint32_t baud) {
            uint8_t rate;
            switch (baud) {
                case 110:
                    rate = 0x00;
                    break;
                case 300:
                    rate = 0x01;
                    break;
                case 600:
                    rate = 0x02;
                    break;
                case 1200:
                    rate = 0x03;
                    break;
                case 2400:
                    rate = 0x04;
                    break;
                case 4800:
                    rate = 0x05;
                    break;
                case 9600:
                    rate = 0x06;
                    break;
                case 14400:
                    rate = 0x07;
                    break;
                case 19200:
                    rate = 0x08;
                    break;
                case 31250:
                    rate = 0x09;
                    break;
                case 38400:
                    rate = 0x0a;
                    break;
                case 56000:
                    rate = 0x0b;
                    break;
                case 57600:
                    rate = 0x0c;
                    break;
                case 115200:
                    rate = 0x0d;
                    break;
                case 129032:
                    rate = 0x0e;
                    break;
                case 282353:
                    rate = 0x0f;
                    break;
                case 128000:
                    rate = 0x10;
                    break;
                case 256000:
                    rate = 0x11;
                    break;
                default:
                    rate = 0xff;
                    return FAIL;
            }

            serial.put(SETBAUD);
            serial.put(rate);

            RetStatus ret = serial.get();
            if (ret != OK)
                return ret;

            serial.setBaud(baud);
            return OK;
        }

        // Draw ASCII character in the given color.
        // The color format is R5G6B5.
        RetStatus draw_char(uint8_t c, uint8_t x, uint8_t y, uint16_t color = 0xffff) {
            serial.put(DRAWCHAR_TEXT);
            serial.put(c);
            serial.put(x);
            serial.put(y);
            serial.write(color);
            return serial.get();
        }

        // Draw an ellipse in the given color.
        // The color format is R5G6B5.
        RetStatus draw_ellipse(uint16_t x, uint16_t y, uint16_t rx, uint16_t ry, uint16_t color) {
            serial.put(DRAWELLIPSE);
            serial.write(x); // X coordinate of center
            serial.write(y); // Y coordinate of center
            serial.write(rx); // Radius in the X axis
            serial.write(ry); // Radius in the Y axis
            serial.write(color); // Color
            return serial.get();
        }

        RetStatus set_pen_size(bool solid) {
            serial.put(SETPENSIZE);
            serial.put(solid ? PEN_SOLID : PEN_WIREFRAME);
            return serial.get();
        }

        RetStatus clear_screen() {
            serial.put(CLEARSCREEN);
            return serial.get();
        }

        RetStatus toggle_touchscreen(bool enabled) {
            serial.put(DISPCONTROL);
            serial.put(DISPCONTROL_TOUCH);
            serial.put(enabled ? DISPCONTROL_TOUCH_ENABLE : DISPCONTROL_TOUCH_DISABLE);
            return serial.get();
        }

        RetStatus reset_active_touch_region() {
            serial.put(DISPCONTROL);
            serial.put(DISPCONTROL_TOUCH);
            serial.put(DISPCONTROL_TOUCH_RESET_ACTIVE);
            return serial.get();
        }

        TouchActType get_touch_status() {
            serial.put(TOUCHCOORDS);
            serial.put(TOUCHCOORDS_STATUS);

            uint8_t response[4];
            for (int i = 0; i < 4; ++i)
                response[i] = serial.get();

            return static_cast<TouchActType>(response[1]);
        }

        TouchCoords get_touch_coordinates() {
            serial.put(TOUCHCOORDS);
            serial.put(TOUCHCOORDS_GETCOORDINATES);

            autounion<uint16_t> response[2];
            for (uint8_t i = 0; i < 2; ++i)
                serial.read(response[i].value());

            TouchCoords ret = { response[0], response[1] };
            return ret;
        }

        TouchCoords wait_until_touch(TouchKind kind = WAIT_ANY) {
            serial.put(TOUCHCOORDS);
            serial.put(kind);

            autounion<uint16_t> response[2];
            for (uint8_t i = 0; i < 2; ++i)
                serial.read(response[i].value());

            TouchCoords ret = { response[0], response[1] };
            return ret;
        }

    };

}

#endif
#endif
