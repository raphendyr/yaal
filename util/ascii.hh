#ifndef __YAAL_UTIL__ASCII__
#define __YAAL_UTIL__ASCII__ 1
#include "../requirements.hh"
#ifdef __YAAL__

namespace yaal {

    namespace ASCII {

        enum control_char : char {
            NUL = 0,   // null
            SOH = 1,   // start of heading
            STX = 2,   // start of text
            ETX = 3,   // end of text
            EOT = 4,   // end of transmission
            ENQ = 5,   // enquiry
            ACK = 6,   // acknowledge
            BEL = 7,   // bell
             BS = 8,   // backspace
             HT = 9,   // horizontal tabulation
             LF = 10,  // line feed
             VT = 11,  // vertical tabulation
             FF = 12,  // form feed
             CR = 13,  // carriage return
             SO = 14,  // shift out
             SI = 15,  // shift in
            DLE = 16,  // data link escape
            DC1 = 17,  // device control one
            DC2 = 18,  // device control two
            DC3 = 19,  // device control three
            DC4 = 20,  // device control four
            NAK = 21,  // negative acknowledge
            SYN = 22,  // synchronous idle
            ETB = 23,  // end of transmission block
            CAN = 24,  // cancel
             EM = 25,  // end of medium
            SUB = 26,  // substitute
            ESC = 27,  // escape
             FS = 28,  // file separator
             GS = 29,  // group separator
             RS = 30,  // record separator
             US = 31,  // unit separator
            DEL = 127, // delete
        };

    }

}

#endif
#endif
