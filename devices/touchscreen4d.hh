#ifndef __YAAL_DEVICE__TOUCHSCREEN4D__
#define __YAAL_DEVICE__TOUCHSCREEN4D__ 1
#include "../requirements.hh"
#ifdef __YAAL__

namespace yaal {

    namespace internal {
        static constexpr uint8_t ACK = 0x06;
        static constexpr uint8_t NAK = 0x15;

        static constexpr uint8_t AUTOBAUD = 0x55;
        static constexpr uint8_t SETBAUD = 0x51;

        static constexpr uint8_t CLEARSCREEN = 0x45;
        static constexpr uint8_t DRAWCHAR_TEXT = 0x54;
        static constexpr uint8_t DRAWELLIPSE = 0x65;
        static constexpr uint8_t TOUCHCOORDS = 0x6f;
        static constexpr uint8_t TOUCHCOORDS_STATUS = 0x04; // FIXME -> enum
    }


    template <typename T>
    class Touchscreen4D {
    private:
        T serial;

        struct Coords {
            unsigned int x;
            unsigned int y;
        };

        enum TouchActType {
            ACT_NONE = 0,
            ACT_PRESS = 1,
            ACT_RELEASE = 2,
            ACT_MOVING = 3
        };


    public:

        YAAL_INLINE("4D touchscreen init")
        bool init(uint32_t baud = 9600) {
            serial.setBaud(baud);
            serial.setFrameFormat();
            serial.transmit(internal::AUTOBAUD);
            return serial.receive() == internal::ACK;
        }

        YAAL_INLINE("4D touchscreen set baud")
        bool set_baud(uint32_t baud) {
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
                    return false;
            }

            serial.transmit(internal::SETBAUD);
            serial.transmit(rate);
            if (serial.receive() != internal::ACK)
                return false;

            serial.setBaud(baud);
            return true;
        }

        // Draw ASCII character in white.
        bool draw_char(uint8_t c, uint8_t x, uint8_t y, uint16_t color = 0xffff) {
            serial.transmit(internal::DRAWCHAR_TEXT);
            serial.transmit(c);
            serial.transmit(x);
            serial.transmit(y);
            serial.transmit(color);
            return serial.receive() == internal::ACK;
        }

        bool draw_ellipse(uint16_t x, uint16_t y, uint16_t rx, uint16_t ry, uint16_t color) {

            serial.transmit(internal::DRAWELLIPSE);

            serial.transmit(x); // X coordinate of center
            serial.transmit(y); // Y coordinate of center
            serial.transmit(rx); // Radius in the X axis
            serial.transmit(ry); // Radius in the Y axis
            serial.transmit(color); // Color

            return serial.receive() == internal::ACK;
        }

        bool clear_screen() {
            serial.transmit(internal::CLEARSCREEN);
            return serial.receive() == internal::ACK;
        }

        enum TouchActType LCD_gettouchactivity() {
            serial.transmit(internal::TOUCHCOORDS);
            serial.transmit(internal::TOUCHCOORDS_STATUS);

            uint8_t response[4];
            for (int i = 0; i < 4; ++i)
                response[i] = serial.receive();

            return static_cast<TouchActType>(response[1]);
        }

    };

}

#endif
#endif
