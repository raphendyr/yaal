#ifndef __YAAL_IO__REGISTERS__ADC__
#define __YAAL_IO__REGISTERS__ADC__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

#include "../types/adc.hh"

#ifndef YAAL_ADC_DISABLED

namespace yaal {

    // atmega16u4 and atmega32u4
#   if defined(__AVR_ATmega16U4__) || defined(__AVR_ATmega32U4__)
        typedef AnalogDigitalConverter AdcUnit0;

        typedef AdcSingleChannel<0x1e, AdcUnit0, AnalogDigitalConverter::Reference::INTERNAL> AdcVBandGap;
        typedef AdcSingleChannel<0x1f, AdcUnit0, AnalogDigitalConverter::Reference::INTERNAL> AdcGnd;
        typedef AdcSingleChannel<0x27, AdcUnit0, AnalogDigitalConverter::Reference::INTERNAL> AdcTemp;
        typedef AdcSingleChannel<0x00, AdcUnit0> AdcChannel0;
#       define PORTF0_ADC 0
        typedef AdcSingleChannel<0x01, AdcUnit0> AdcChannel1;
#       define PORTF1_ADC 1
        typedef AdcSingleChannel<0x04, AdcUnit0> AdcChannel4;
#       define PORTF4_ADC 4
        typedef AdcSingleChannel<0x05, AdcUnit0> AdcChannel5;
#       define PORTF5_ADC 5
        typedef AdcSingleChannel<0x06, AdcUnit0> AdcChannel6;
#       define PORTF6_ADC 6
        typedef AdcSingleChannel<0x07, AdcUnit0> AdcChannel7;
#       define PORTF7_ADC 7
        typedef AdcSingleChannel<0x20, AdcUnit0> AdcChannel8;
#       define PORTD4_ADC 8
        typedef AdcSingleChannel<0x21, AdcUnit0> AdcChannel9;
#       define PORTD6_ADC 9
        typedef AdcSingleChannel<0x22, AdcUnit0> AdcChannel10;
#       define PORTD7_ADC 10
        typedef AdcSingleChannel<0x23, AdcUnit0> AdcChannel11;
#       define PORTB4_ADC 11
        typedef AdcSingleChannel<0x24, AdcUnit0> AdcChannel12;
#       define PORTB5_ADC 12
        typedef AdcSingleChannel<0x25, AdcUnit0> AdcChannel13;
#       define PORTB6_ADC 13

#   else
#      warning "There is no adc defines for your MCU. Update yaal/io/registers/adc.hh."
#   endif

}

#endif // !defined(YAAL_ADC_DISABLED)

#endif
#endif
