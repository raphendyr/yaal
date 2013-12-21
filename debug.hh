#ifndef __YAAL_DEBUG__
#define __YAAL_DEBUG__ 1

#include "common_macros.hh"

// Some ideas of yDebug come from QDebug and KDebug

/* FIXME: defining _T here brakes functionality on real AVR hardware
 * Currently this setup works ok on test programs (run on development computer)
 * i.e. yDebug is not ready for debugging on AVR, but works nicely for developing tests
 */
#ifndef _T
#  define _T(s) (s)
#endif


namespace yaal {
    struct YaalNoDebug {
        template<typename T>
        YaalNoDebug& operator << (const T&) {
            return *this;
        }
    };
}
#define yDebugImplPipeNull ::yaal::YaalNoDebug()

#ifndef yDebugImplPipe
#  define yDebugImplPipe yDebugImplPipeNull
#endif

#ifndef yDebugImplEndl
#  define yDebugImplEndl '\n'
#endif

#ifndef yDebugImpl
namespace yaal {
    struct YaalDebug {
        YaalDebug() {}
        ~YaalDebug() {
            yDebugImplPipe << yDebugImplEndl;
        }

        template<typename T>
        YaalDebug& operator << (const T& o) {
            yDebugImplPipe << o;
            return *this;
        }
    };
}
#  define yDebugImpl ::yaal::YaalDebug()
#endif

#define yDebugIf(level, level_name) if (level >= yDebugLevel) \
    yDebugImpl << _T(level_name " " __FILE__ ":" __STRINGIFY(__LINE__) " ")

#define yDebug() yDebugIf(1, "DEBUG")
#define yInfo() yDebugIf(2, "INFO")
#define yWarning() yDebugIf(3, "WARNING")
#define yError() yDebugIf(4, "ERROR")
#define yCritical() yDebugIf(5, "CRITICAL")
#define yFatal() yDebugIf(6, "FATAL")

#ifndef yDebugLevel
#  define yDebugLevel 0
#endif

#endif
