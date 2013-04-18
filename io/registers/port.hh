#ifndef __YAAL_IO__REGISTERS__PORT__
#define __YAAL_IO__REGISTERS__PORT__ 1
#include "../../requirements.hh"
#ifdef __YAAL__
/* Generated using port.sh */

#include "../types/register.hh"
#include <avr/io.h>

namespace yaal {

    namespace internal {

        /*  port A  */
#       ifdef PINA
            typedef ReadonlyRegister<YAAL_ADDR(PINA)> PinAReg;
#       endif
#       ifdef DDRA
            typedef Register<YAAL_ADDR(DDRA)> DdrAReg;
#       endif
#       ifdef PORTA
            typedef Register<YAAL_ADDR(PORTA)> PortAReg;
#       endif

        /*  port B  */
#       ifdef PINB
            typedef ReadonlyRegister<YAAL_ADDR(PINB)> PinBReg;
#       endif
#       ifdef DDRB
            typedef Register<YAAL_ADDR(DDRB)> DdrBReg;
#       endif
#       ifdef PORTB
            typedef Register<YAAL_ADDR(PORTB)> PortBReg;
#       endif

        /*  port C  */
#       ifdef PINC
            typedef ReadonlyRegister<YAAL_ADDR(PINC)> PinCReg;
#       endif
#       ifdef DDRC
            typedef Register<YAAL_ADDR(DDRC)> DdrCReg;
#       endif
#       ifdef PORTC
            typedef Register<YAAL_ADDR(PORTC)> PortCReg;
#       endif

        /*  port D  */
#       ifdef PIND
            typedef ReadonlyRegister<YAAL_ADDR(PIND)> PinDReg;
#       endif
#       ifdef DDRD
            typedef Register<YAAL_ADDR(DDRD)> DdrDReg;
#       endif
#       ifdef PORTD
            typedef Register<YAAL_ADDR(PORTD)> PortDReg;
#       endif

        /*  port E  */
#       ifdef PINE
            typedef ReadonlyRegister<YAAL_ADDR(PINE)> PinEReg;
#       endif
#       ifdef DDRE
            typedef Register<YAAL_ADDR(DDRE)> DdrEReg;
#       endif
#       ifdef PORTE
            typedef Register<YAAL_ADDR(PORTE)> PortEReg;
#       endif

        /*  port F  */
#       ifdef PINF
            typedef ReadonlyRegister<YAAL_ADDR(PINF)> PinFReg;
#       endif
#       ifdef DDRF
            typedef Register<YAAL_ADDR(DDRF)> DdrFReg;
#       endif
#       ifdef PORTF
            typedef Register<YAAL_ADDR(PORTF)> PortFReg;
#       endif

        /*  port G  */
#       ifdef PING
            typedef ReadonlyRegister<YAAL_ADDR(PING)> PinGReg;
#       endif
#       ifdef DDRG
            typedef Register<YAAL_ADDR(DDRG)> DdrGReg;
#       endif
#       ifdef PORTG
            typedef Register<YAAL_ADDR(PORTG)> PortGReg;
#       endif

        /*  port H  */
#       ifdef PINH
            typedef ReadonlyRegister<YAAL_ADDR(PINH)> PinHReg;
#       endif
#       ifdef DDRH
            typedef Register<YAAL_ADDR(DDRH)> DdrHReg;
#       endif
#       ifdef PORTH
            typedef Register<YAAL_ADDR(PORTH)> PortHReg;
#       endif

        /*  port I  */
#       ifdef PINI
            typedef ReadonlyRegister<YAAL_ADDR(PINI)> PinIReg;
#       endif
#       ifdef DDRI
            typedef Register<YAAL_ADDR(DDRI)> DdrIReg;
#       endif
#       ifdef PORTI
            typedef Register<YAAL_ADDR(PORTI)> PortIReg;
#       endif

        /*  port J  */
#       ifdef PINJ
            typedef ReadonlyRegister<YAAL_ADDR(PINJ)> PinJReg;
#       endif
#       ifdef DDRJ
            typedef Register<YAAL_ADDR(DDRJ)> DdrJReg;
#       endif
#       ifdef PORTJ
            typedef Register<YAAL_ADDR(PORTJ)> PortJReg;
#       endif

        /*  port K  */
#       ifdef PINK
            typedef ReadonlyRegister<YAAL_ADDR(PINK)> PinKReg;
#       endif
#       ifdef DDRK
            typedef Register<YAAL_ADDR(DDRK)> DdrKReg;
#       endif
#       ifdef PORTK
            typedef Register<YAAL_ADDR(PORTK)> PortKReg;
#       endif

        /*  port L  */
#       ifdef PINL
            typedef ReadonlyRegister<YAAL_ADDR(PINL)> PinLReg;
#       endif
#       ifdef DDRL
            typedef Register<YAAL_ADDR(DDRL)> DdrLReg;
#       endif
#       ifdef PORTL
            typedef Register<YAAL_ADDR(PORTL)> PortLReg;
#       endif

        /*  port M  */
#       ifdef PINM
            typedef ReadonlyRegister<YAAL_ADDR(PINM)> PinMReg;
#       endif
#       ifdef DDRM
            typedef Register<YAAL_ADDR(DDRM)> DdrMReg;
#       endif
#       ifdef PORTM
            typedef Register<YAAL_ADDR(PORTM)> PortMReg;
#       endif

        /*  port N  */
#       ifdef PINN
            typedef ReadonlyRegister<YAAL_ADDR(PINN)> PinNReg;
#       endif
#       ifdef DDRN
            typedef Register<YAAL_ADDR(DDRN)> DdrNReg;
#       endif
#       ifdef PORTN
            typedef Register<YAAL_ADDR(PORTN)> PortNReg;
#       endif
    }

}

#endif
#endif
