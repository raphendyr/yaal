#ifndef __YAAL_COMMUNICATION__HWSPI__
#define __YAAL_COMMUNICATION__HWSPI__ 1
#include "../requirements.hh"
#ifdef __YAAL__

namespace yaal {

    template< typename Derived >
    struct HWSPI : public interface::SycronousPointToPoint<Derived> {

        void setup(void) {
            // implement
        }

        uint8_t get(void) {
        }

        void put(uint8_t data) {
        }


        template<typename T>
        static inline
        T transfer(T data) {
        }

        template<typename T>
        static inline
        T transfer(T data, uint8_t bits) {
        }
    };

}

#endif
#endif
