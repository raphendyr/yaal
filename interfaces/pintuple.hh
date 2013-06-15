#ifndef __YAAL_INTERFACES__PINTUPLE__
#define __YAAL_INTERFACES__PINTUPLE__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "../util/constexpr.hh"

namespace yaal {

    /*!
     * PinTupleInterface defines interface for classes describing
     * tuple of pins. These are mainly Ports nad Pinsets.
     */
    class PinTupleInterface {
        typedef PinTupleInterface self_type;
    public:
        /** type definitions ***/
        /*! Should define atomiced and non atomiced versions of self type */
        typedef PinTupleInterface Atomiced;
        typedef PinTupleInterface NonAtomiced;

        /** constant variables **/

        /*! mask - bitmask defining which bits in byte are used by this tuple */
        static constexpr uint8_t mask = 0xff;

        /*! size - pin count of this tuple */
        static constexpr uint8_t size = bits_up_ce(mask);


        /** methods **/

        /*! set - set tuple to value */
        static void set(uint8_t new_value);

        /*! get - get value in tuple */
        static uint8_t get();

        /*! set_output - set pins in tuple in output state */
        static void set_output();

        /*! set_input - set pins in tuple in input state */
        static void set_input(bool pullup = false);

        // FIXME: define and implement .mode (like in Pin)


        /* operators. Should use following PinTuple as implementation */

        /*! get operator */
        operator uint8_t () const;

        /*! set operator */
        self_type& operator = (uint8_t new_value);

    };

    /*! PinTuple
     *  Basic implementation of operator overloads
     */
    template<typename BasePinTuple>
    class PinTuple : public BasePinTuple {
        typedef PinTuple<BasePinTuple> self_type;

    public:
        typedef PinTuple<typename BasePinTuple::Atomiced> Atomiced;
        typedef PinTuple<typename BasePinTuple::NonAtomiced> NonAtomiced;

        static constexpr uint8_t size = bits_up_ce(BasePinTuple::mask);

        operator uint8_t () const {
            return this->get();
        }

        self_type& operator = (uint8_t new_value) {
            this->set(new_value);
            return *this;
        }
    };

}

#endif
#endif
