#ifndef __YAAL_IO__REGISTERS__ADC__
#define __YAAL_IO__REGISTERS__ADC__ 1
#include "../../requirements.hh"
#ifdef __YAAL__

#include "../types/adc.hh"

#ifndef YAAL_ADC_DISABLED

namespace yaal {

    // atmega16u4 and atmega32u4
#   if defined(__AVR_ATmega16U4__) || defined(__AVR_ATmega32U4__)
        typedef AnalogDigitalConverter<6> AdcUnit0;

        typedef AdcSingleChannel<0x1e, AdcUnit0, AdcUnit0::Reference::INTERNAL> AdcVBandGap; // 2.56V
        typedef AdcSingleChannel<0x1f, AdcUnit0, AdcUnit0::Reference::INTERNAL> AdcGnd;
        typedef AdcSingleChannel<0x27, AdcUnit0, AdcUnit0::Reference::INTERNAL> AdcTemp;

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

    // atmega328p
#   elif defined(__AVR_ATmega328P__)
        typedef AnalogDigitalConverter<4> AdcUnit0;

        typedef AdcSingleChannel<0x0e, AdcUnit0, AdcUnit0::Reference::INTERNAL> AdcVBandGap; // 1.1V
        typedef AdcSingleChannel<0x0f, AdcUnit0, AdcUnit0::Reference::INTERNAL> AdcGnd;
        typedef AdcSingleChannel<0x08, AdcUnit0, AdcUnit0::Reference::INTERNAL> AdcTemp;

#       define PORTC0_ADC 0
        typedef AdcSingleChannel<0x00, AdcUnit0> AdcChannel0;
#       define PORTC1_ADC 1
        typedef AdcSingleChannel<0x01, AdcUnit0> AdcChannel1;
#       define PORTC2_ADC 2
        typedef AdcSingleChannel<0x02, AdcUnit0> AdcChannel2;
#       define PORTC3_ADC 3
        typedef AdcSingleChannel<0x03, AdcUnit0> AdcChannel3;
#       define PORTC4_ADC 4
        typedef AdcSingleChannel<0x04, AdcUnit0> AdcChannel4;
#       define PORTC5_ADC 5
        typedef AdcSingleChannel<0x05, AdcUnit0> AdcChannel5;
        // Last 2 channels are not in PDIP package and do not have digital functionalities
        typedef AdcSingleChannel<0x06, AdcUnit0> AdcChannel6;
        typedef AdcSingleChannel<0x07, AdcUnit0> AdcChannel7;

#   else
#      warning "There is no adc defines for your MCU. Update yaal/io/registers/adc.hh."
#   endif

}

#endif // !defined(YAAL_ADC_DISABLED)

#endif
#endif
