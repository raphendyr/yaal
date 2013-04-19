#ifndef __YAAL_DEVICE__TOUCHSCREEN4D__
#define __YAAL_DEVICE__TOUCHSCREEN4D__ 1
#include "../requirements.hh"
#ifdef __YAAL__

namespace yaal {

    namespace internal {
        static constexpr uint8_t ACK = 0x06;
        static constexpr uint8_t NAK = 0x15;

        static constexpr uint8_t AUTOBAUD = 0x55;

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

        bool init() {
            serial.transmit(internal::AUTOBAUD);
            return serial.receive() == internal::ACK;
        }

        // Draw ASCII character in white.
        // TODO: an arbitrary color.
        bool draw_char(uint8_t c, uint8_t x, uint8_t y, uint16_t color) {
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
