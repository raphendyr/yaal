#ifndef __YAAL_MATH__LOG__
#define __YAAL_MATH__LOG__ 1
#include "../requirements.hh"
#ifdef __YAAL__

#include "fixed.hh"
#include "log2.hh"
#include "constants.hh"

namespace yaal {

    //! log
    /* log(y) = log(2) * log2(y)
     * FIXME: more optimal implementation if available
     */
    template<uint8_t bits, typename c_type>
    FixedDecimal<bits, c_type> log(FixedDecimal<bits, c_type>& val) {
        typedef ::yaal::FixedDecimal<bits, c_type> fixed_t;
        constexpr fixed_t log_2 = constants::log_2;

        yDebug() << _T("calculating log for ") << val.to_float();

        fixed_t result = log2(val) * log_2;

        yDebug() << _T(" log result is ") << result.to_float();

        return result;
    }

}

#endif
#endif
