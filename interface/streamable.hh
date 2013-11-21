#ifndef __YAAL_INTERFACE__STREAMABLE__
#define __YAAL_INTERFACE__STREAMABLE__ 1
#include "../requirements.hh"
#ifdef __YAAL__

namespace yaal {

    class StreamableInterface {
        //! get
        /*! Read byte
         */
        uint8_t get();


        //! put
        /*! Write byte
         */
        void put(uint8_t);
    };

}

#endif
#endif
