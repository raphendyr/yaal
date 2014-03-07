#ifndef __YAAL_MATH__LOG2__
#define __YAAL_MATH__LOG2__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "fixed.hh"

namespace yaal {

    //! log2
    /* Use algorithm from Wikipedia
     *   http://en.wikipedia.org/wiki/Binary_logarithm?oldid=584017666#Real_number
     * constexpr version log2_ce uses the same
     * This is basically same as log2 function in libfixmath's fix16_exp.c
     *   https://code.google.com/p/libfixmath/
     */
    // do not get val with reference, as it's changed in this function
    template<uint8_t bits, typename c_type>
    FixedDecimal<bits, c_type> log2(FixedDecimal<bits, c_type> val) {
        typedef ::yaal::FixedDecimal<bits, c_type> fixed_t;
        constexpr fixed_t one = fixed_t::one;
        constexpr fixed_t two = 2;
        constexpr fixed_t minimum = fixed_t::minimum;

        yDebug() << _T("calculating log2 for ") << val.to_float();
        // if val is 0, result is undefined
        // and for negative numbers, complex result would be needed
        bool negate = false;
        if (type_traits<c_type>::is_signed) {
            if (val <= 0)
                return 0;

            // If val is less than one, result is -log2(1 / val)
            if (val < one) {
                yDebug() << _T("If val is less than one, result is -log2(1 / val)");
                if (val <= minimum)
                    return -bits;
                // inverse
                val = one / val;
                negate = true;
            }
        } else {
            // with unsigned types, we can't represent negative results
            if (val < one)
                return 0;
        }

        // calculate raw fixed_t value
        c_type result = 0;

        // Calculate integer part
        while (val >= two) {
            result++;
            val >>= 1; // val / 2, compiler can't make optimization here
        }

        yDebug() << _T("Integer part of log2 is ") << result << _T(" and value is ") << val.to_float();

        // If only integer part is needed
        if (val == one)
            return fixed_t(result);

        // at this point val is >1, because any x / 2 > 1, when x > 2
        /* From wikipedia:
         * 1. square the number
         * 2. if the square is >= 2, divide it by two and write a 1. Else write a 0.
         */
        for (uint8_t i = bits; i > 0; i--) {
            val *= val;
            result <<= 1;
            yDebug() << _T("  log2 iteration, val=val*val -> ") << val.to_float();
            if (val >= two) {
                result |= 1;
                val >>= 1; // val /= 2
                yDebug() << _T("    dividing it by 2 -> ") << val.to_float();
            }
        }

        // round up if next bit would have been 1
        val *= val;
        if (val >= two)
            result++;

        // Convert raw representation of fixed_t to actual type
        if (type_traits<c_type>::is_signed) {
            if (negate)
                result = -result;
        }


        fixed_t ret = typename fixed_t::RawValue(result);
        yDebug() << _T(" log2 result is ") << ret.to_float();
        return ret;
    }

}

#endif
#endif
