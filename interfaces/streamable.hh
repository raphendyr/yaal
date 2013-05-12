#ifndef __YAAL_INTERFACES__STREAMABLE__
#define __YAAL_INTERFACES__STREAMABLE__ 1
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
