#ifndef __YAAL_DEVICES__LCD_BACKPACK__
#define __YAAL_DEVICES__LCD_BACKPACK__ 1
#include "../requirements.hh"
#ifdef __YAAL__

namespace yaal {

    namespace internal {
        template<uint8_t RS, uint8_t RW, uint8_t Enable, uint8_t Data4, uint8_t Data5, uint8_t Data6, uint8_t Data7, uint8_t Backlight>
        struct LcdBackPack {
        };

#       define __INTERNAL_INCLUDE_STRUCTS__ 1
#       include "lcd_backpack_layouts.hh"
#       undef __INTERNAL_INCLUDE_STRUCTS__

    }


    template<uint8_t RS, uint8_t RW, uint8_t Enable, uint8_t Data4, uint8_t Data5, uint8_t Data6, uint8_t Data7, uint8_t Backlight, bool Backlight_polarity>
    struct LcdBackPack {
        typedef internal::LcdBackPack<RS, RW, Enable, Data4, Data5, Data6, Data7, Backlight> Type;
        union {
            Type bits;
            uint8_t value;
        };
        static constexpr bool backlight_polarity = Backlight_polarity;
    };



    /* Known backpack types */

    // FIXME: better naming required
    typedef LcdBackPack<0, 1, 2, 4, 5, 6, 7, 3, true> LcdBackPack_Type1;
    typedef LcdBackPack<6, 5, 4, 0, 1, 2, 3, 7, false> LcdBackPack_Type2;

}

#endif
#endif
