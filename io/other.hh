#ifndef __YAAL_IO__OTHER__
#define __YAAL_IO__OTHER__ 1
// do not edit. genereted using io_definitions.sh

#include "../requirements.hh"
#include <avr/io.h>

namespace yaal {
    namespace register {

#       ifdef ADC
            typedef Register<YAAL_ADDR(ADC), uint16_t> Adc;
#       endif

#       ifdef ADCW
            typedef Register<YAAL_ADDR(ADCW), uint16_t> Adcw;
#       endif

#       ifdef DAC
            typedef Register<YAAL_ADDR(DAC), uint16_t> Dac;
#       endif

#       ifdef EEAR
            typedef Register<YAAL_ADDR(EEAR), uint16_t> Eear;
#       endif

#       ifdef ICR1
            typedef Register<YAAL_ADDR(ICR1), uint16_t> Icr1;
#       endif

#       ifdef OCR0RA
            typedef Register<YAAL_ADDR(OCR0RA), uint16_t> Ocr0ra;
#       endif

#       ifdef OCR0RB
            typedef Register<YAAL_ADDR(OCR0RB), uint16_t> Ocr0rb;
#       endif

#       ifdef OCR0SB
            typedef Register<YAAL_ADDR(OCR0SB), uint16_t> Ocr0sb;
#       endif

#       ifdef OCR1A
            typedef Register<YAAL_ADDR(OCR1A), uint16_t> Ocr1a;
#       endif

#       ifdef OCR1B
            typedef Register<YAAL_ADDR(OCR1B), uint16_t> Ocr1b;
#       endif

#       ifdef OCR1
            typedef Register<YAAL_ADDR(OCR1), uint16_t> Ocr1;
#       endif

#       ifdef OCR2RA
            typedef Register<YAAL_ADDR(OCR2RA), uint16_t> Ocr2ra;
#       endif

#       ifdef OCR2RB
            typedef Register<YAAL_ADDR(OCR2RB), uint16_t> Ocr2rb;
#       endif

#       ifdef OCR2SB
            typedef Register<YAAL_ADDR(OCR2SB), uint16_t> Ocr2sb;
#       endif

#       ifdef OCRA1
            typedef Register<YAAL_ADDR(OCRA1), uint16_t> Ocra1;
#       endif

#       ifdef OCRB1
            typedef Register<YAAL_ADDR(OCRB1), uint16_t> Ocrb1;
#       endif

#       ifdef SP
            typedef Register<YAAL_ADDR(SP), uint16_t> Sp;
#       endif

#       ifdef TCNT0
            typedef Register<YAAL_ADDR(TCNT0), uint16_t> Tcnt0;
#       endif

#       ifdef TCNT1
            typedef Register<YAAL_ADDR(TCNT1), uint16_t> Tcnt1;
#       endif

#       ifdef ACSRA
            typedef Register<YAAL_ADDR(ACSRA), uint8_t> Acsra;
#       endif

#       ifdef ACSRB
            typedef Register<YAAL_ADDR(ACSRB), uint8_t> Acsrb;
#       endif

#       ifdef ACSR
            typedef Register<YAAL_ADDR(ACSR), uint8_t> Acsr;
#       endif

#       ifdef ADCSRA
            typedef Register<YAAL_ADDR(ADCSRA), uint8_t> Adcsra;
#       endif

#       ifdef ADCSRB
            typedef Register<YAAL_ADDR(ADCSRB), uint8_t> Adcsrb;
#       endif

#       ifdef ADCSR
            typedef Register<YAAL_ADDR(ADCSR), uint8_t> Adcsr;
#       endif

#       ifdef ADMUX
            typedef Register<YAAL_ADDR(ADMUX), uint8_t> Admux;
#       endif

#       ifdef ASSR
            typedef Register<YAAL_ADDR(ASSR), uint8_t> Assr;
#       endif

#       ifdef B_DET
            typedef Register<YAAL_ADDR(B_DET), uint8_t> B_det;
#       endif

#       ifdef BODCR
            typedef Register<YAAL_ADDR(BODCR), uint8_t> Bodcr;
#       endif

#       ifdef BTCNT
            typedef Register<YAAL_ADDR(BTCNT), uint8_t> Btcnt;
#       endif

#       ifdef BTCR
            typedef Register<YAAL_ADDR(BTCR), uint8_t> Btcr;
#       endif

#       ifdef CLK_CNTR
            typedef Register<YAAL_ADDR(CLK_CNTR), uint8_t> Clk_cntr;
#       endif

#       ifdef CLKPR
            typedef Register<YAAL_ADDR(CLKPR), uint8_t> Clkpr;
#       endif

#       ifdef CMCR
            typedef Register<YAAL_ADDR(CMCR), uint8_t> Cmcr;
#       endif

#       ifdef CMIMR
            typedef Register<YAAL_ADDR(CMIMR), uint8_t> Cmimr;
#       endif

#       ifdef CMSR
            typedef Register<YAAL_ADDR(CMSR), uint8_t> Cmsr;
#       endif

#       ifdef DEEARL
            typedef Register<YAAL_ADDR(DEEARL), uint8_t> Deearl;
#       endif

#       ifdef DEEAR
            typedef Register<YAAL_ADDR(DEEAR), uint8_t> Deear;
#       endif

#       ifdef DEECR
            typedef Register<YAAL_ADDR(DEECR), uint8_t> Deecr;
#       endif

#       ifdef DEEDR
            typedef Register<YAAL_ADDR(DEEDR), uint8_t> Deedr;
#       endif

#       ifdef DIDR0
            typedef Register<YAAL_ADDR(DIDR0), uint8_t> Didr0;
#       endif

#       ifdef DIDR1
            typedef Register<YAAL_ADDR(DIDR1), uint8_t> Didr1;
#       endif

#       ifdef DIDR
            typedef Register<YAAL_ADDR(DIDR), uint8_t> Didr;
#       endif

#       ifdef DT1A
            typedef Register<YAAL_ADDR(DT1A), uint8_t> Dt1a;
#       endif

#       ifdef DT1B
            typedef Register<YAAL_ADDR(DT1B), uint8_t> Dt1b;
#       endif

#       ifdef DT1
            typedef Register<YAAL_ADDR(DT1), uint8_t> Dt1;
#       endif

#       ifdef DTPS1
            typedef Register<YAAL_ADDR(DTPS1), uint8_t> Dtps1;
#       endif

#       ifdef DWDR
            typedef Register<YAAL_ADDR(DWDR), uint8_t> Dwdr;
#       endif

#       ifdef EECR
            typedef Register<YAAL_ADDR(EECR), uint8_t> Eecr;
#       endif

#       ifdef EEDR
            typedef Register<YAAL_ADDR(EEDR), uint8_t> Eedr;
#       endif

#       ifdef EICRB
            typedef Register<YAAL_ADDR(EICRB), uint8_t> Eicrb;
#       endif

#       ifdef EICR
            typedef Register<YAAL_ADDR(EICR), uint8_t> Eicr;
#       endif

#       ifdef EIFR
            typedef Register<YAAL_ADDR(EIFR), uint8_t> Eifr;
#       endif

#       ifdef EIMF
            typedef Register<YAAL_ADDR(EIMF), uint8_t> Eimf;
#       endif

#       ifdef EIMSK
            typedef Register<YAAL_ADDR(EIMSK), uint8_t> Eimsk;
#       endif

#       ifdef EIND
            typedef Register<YAAL_ADDR(EIND), uint8_t> Eind;
#       endif

#       ifdef EIRR
            typedef Register<YAAL_ADDR(EIRR), uint8_t> Eirr;
#       endif

#       ifdef EMCUCR
            typedef Register<YAAL_ADDR(EMCUCR), uint8_t> Emcucr;
#       endif

#       ifdef FISCR
            typedef Register<YAAL_ADDR(FISCR), uint8_t> Fiscr;
#       endif

#       ifdef FISUA
            typedef Register<YAAL_ADDR(FISUA), uint8_t> Fisua;
#       endif

#       ifdef FISUB
            typedef Register<YAAL_ADDR(FISUB), uint8_t> Fisub;
#       endif

#       ifdef FISUC
            typedef Register<YAAL_ADDR(FISUC), uint8_t> Fisuc;
#       endif

#       ifdef FISUD
            typedef Register<YAAL_ADDR(FISUD), uint8_t> Fisud;
#       endif

#       ifdef FPGAD
            typedef Register<YAAL_ADDR(FPGAD), uint8_t> Fpgad;
#       endif

#       ifdef FPGAX
            typedef Register<YAAL_ADDR(FPGAX), uint8_t> Fpgax;
#       endif

#       ifdef FPGAY
            typedef Register<YAAL_ADDR(FPGAY), uint8_t> Fpgay;
#       endif

#       ifdef FPGAZ
            typedef Register<YAAL_ADDR(FPGAZ), uint8_t> Fpgaz;
#       endif

#       ifdef GICR
            typedef Register<YAAL_ADDR(GICR), uint8_t> Gicr;
#       endif

#       ifdef GIFR
            typedef Register<YAAL_ADDR(GIFR), uint8_t> Gifr;
#       endif

#       ifdef GIMSK
            typedef Register<YAAL_ADDR(GIMSK), uint8_t> Gimsk;
#       endif

#       ifdef GIPR
            typedef Register<YAAL_ADDR(GIPR), uint8_t> Gipr;
#       endif

#       ifdef GPIOR0
            typedef Register<YAAL_ADDR(GPIOR0), uint8_t> Gpior0;
#       endif

#       ifdef GPIOR1
            typedef Register<YAAL_ADDR(GPIOR1), uint8_t> Gpior1;
#       endif

#       ifdef GPIOR2
            typedef Register<YAAL_ADDR(GPIOR2), uint8_t> Gpior2;
#       endif

#       ifdef GPIOR3
            typedef Register<YAAL_ADDR(GPIOR3), uint8_t> Gpior3;
#       endif

#       ifdef GTCCR
            typedef Register<YAAL_ADDR(GTCCR), uint8_t> Gtccr;
#       endif

#       ifdef ICR
            typedef Register<YAAL_ADDR(ICR), uint8_t> Icr;
#       endif

#       ifdef IFR
            typedef Register<YAAL_ADDR(IFR), uint8_t> Ifr;
#       endif

#       ifdef IO_DATIN
            typedef Register<YAAL_ADDR(IO_DATIN), uint8_t> Io_datin;
#       endif

#       ifdef IO_DATOUT
            typedef Register<YAAL_ADDR(IO_DATOUT), uint8_t> Io_datout;
#       endif

#       ifdef IO_ENAB
            typedef Register<YAAL_ADDR(IO_ENAB), uint8_t> Io_enab;
#       endif

#       ifdef IRDAMOD
            typedef Register<YAAL_ADDR(IRDAMOD), uint8_t> Irdamod;
#       endif

#       ifdef LFCDR
            typedef Register<YAAL_ADDR(LFCDR), uint8_t> Lfcdr;
#       endif

#       ifdef LFFR
            typedef Register<YAAL_ADDR(LFFR), uint8_t> Lffr;
#       endif

#       ifdef LFRB
            typedef Register<YAAL_ADDR(LFRB), uint8_t> Lfrb;
#       endif

#       ifdef LFRR
            typedef Register<YAAL_ADDR(LFRR), uint8_t> Lfrr;
#       endif

#       ifdef LOCKDET1
            typedef Register<YAAL_ADDR(LOCKDET1), uint8_t> Lockdet1;
#       endif

#       ifdef LOCKDET2
            typedef Register<YAAL_ADDR(LOCKDET2), uint8_t> Lockdet2;
#       endif

#       ifdef MCUCR
            typedef Register<YAAL_ADDR(MCUCR), uint8_t> Mcucr;
#       endif

#       ifdef MCUCSR
            typedef Register<YAAL_ADDR(MCUCSR), uint8_t> Mcucsr;
#       endif

#       ifdef MCUCS
            typedef Register<YAAL_ADDR(MCUCS), uint8_t> Mcucs;
#       endif

#       ifdef MCUR
            typedef Register<YAAL_ADDR(MCUR), uint8_t> Mcur;
#       endif

#       ifdef MCUSR
            typedef Register<YAAL_ADDR(MCUSR), uint8_t> Mcusr;
#       endif

#       ifdef MODCR
            typedef Register<YAAL_ADDR(MODCR), uint8_t> Modcr;
#       endif

#       ifdef MONDR
            typedef Register<YAAL_ADDR(MONDR), uint8_t> Mondr;
#       endif

#       ifdef MSMCR
            typedef Register<YAAL_ADDR(MSMCR), uint8_t> Msmcr;
#       endif

#       ifdef OCDR
            typedef Register<YAAL_ADDR(OCDR), uint8_t> Ocdr;
#       endif

#       ifdef OCR0A
            typedef Register<YAAL_ADDR(OCR0A), uint8_t> Ocr0a;
#       endif

#       ifdef OCR0B
            typedef Register<YAAL_ADDR(OCR0B), uint8_t> Ocr0b;
#       endif

#       ifdef OCR0
            typedef Register<YAAL_ADDR(OCR0), uint8_t> Ocr0;
#       endif

#       ifdef OCR1C
            typedef Register<YAAL_ADDR(OCR1C), uint8_t> Ocr1c;
#       endif

#       ifdef OCR1D
            typedef Register<YAAL_ADDR(OCR1D), uint8_t> Ocr1d;
#       endif

#       ifdef OCR2
            typedef Register<YAAL_ADDR(OCR2), uint8_t> Ocr2;
#       endif

#       ifdef OSCCAL
            typedef Register<YAAL_ADDR(OSCCAL), uint8_t> Osccal;
#       endif

#       ifdef OSICSR
            typedef Register<YAAL_ADDR(OSICSR), uint8_t> Osicsr;
#       endif

#       ifdef PACR
            typedef Register<YAAL_ADDR(PACR), uint8_t> Pacr;
#       endif

#       ifdef PCICR
            typedef Register<YAAL_ADDR(PCICR), uint8_t> Pcicr;
#       endif

#       ifdef PCIFR
            typedef Register<YAAL_ADDR(PCIFR), uint8_t> Pcifr;
#       endif

#       ifdef PCMSK0
            typedef Register<YAAL_ADDR(PCMSK0), uint8_t> Pcmsk0;
#       endif

#       ifdef PCMSK1
            typedef Register<YAAL_ADDR(PCMSK1), uint8_t> Pcmsk1;
#       endif

#       ifdef PCMSK2
            typedef Register<YAAL_ADDR(PCMSK2), uint8_t> Pcmsk2;
#       endif

#       ifdef PCMSK
            typedef Register<YAAL_ADDR(PCMSK), uint8_t> Pcmsk;
#       endif

#       ifdef PCNF0
            typedef Register<YAAL_ADDR(PCNF0), uint8_t> Pcnf0;
#       endif

#       ifdef PCNF2
            typedef Register<YAAL_ADDR(PCNF2), uint8_t> Pcnf2;
#       endif

#       ifdef PCTL0
            typedef Register<YAAL_ADDR(PCTL0), uint8_t> Pctl0;
#       endif

#       ifdef PCTL2
            typedef Register<YAAL_ADDR(PCTL2), uint8_t> Pctl2;
#       endif

#       ifdef PERIPHEN
            typedef Register<YAAL_ADDR(PERIPHEN), uint8_t> Periphen;
#       endif

#       ifdef PIFR0
            typedef Register<YAAL_ADDR(PIFR0), uint8_t> Pifr0;
#       endif

#       ifdef PIFR2
            typedef Register<YAAL_ADDR(PIFR2), uint8_t> Pifr2;
#       endif

#       ifdef PIM0
            typedef Register<YAAL_ADDR(PIM0), uint8_t> Pim0;
#       endif

#       ifdef PIM2
            typedef Register<YAAL_ADDR(PIM2), uint8_t> Pim2;
#       endif

#       ifdef PLLCSR
            typedef Register<YAAL_ADDR(PLLCSR), uint8_t> Pllcsr;
#       endif

#       ifdef PLLFRQ
            typedef Register<YAAL_ADDR(PLLFRQ), uint8_t> Pllfrq;
#       endif

#       ifdef PORTCR
            typedef Register<YAAL_ADDR(PORTCR), uint8_t> Portcr;
#       endif

#       ifdef PRELD
            typedef Register<YAAL_ADDR(PRELD), uint8_t> Preld;
#       endif

#       ifdef PRR
            typedef Register<YAAL_ADDR(PRR), uint8_t> Prr;
#       endif

#       ifdef PWR_ATTEN
            typedef Register<YAAL_ADDR(PWR_ATTEN), uint8_t> Pwr_atten;
#       endif

#       ifdef RAMPZ
            typedef Register<YAAL_ADDR(RAMPZ), uint8_t> Rampz;
#       endif

#       ifdef RXB
            typedef Register<YAAL_ADDR(RXB), uint8_t> Rxb;
#       endif

#       ifdef SCCR
            typedef Register<YAAL_ADDR(SCCR), uint8_t> Sccr;
#       endif

#       ifdef SCR
            typedef Register<YAAL_ADDR(SCR), uint8_t> Scr;
#       endif

#       ifdef SFIOR
            typedef Register<YAAL_ADDR(SFIOR), uint8_t> Sfior;
#       endif

#       ifdef SFTCR
            typedef Register<YAAL_ADDR(SFTCR), uint8_t> Sftcr;
#       endif

#       ifdef SMCR
            typedef Register<YAAL_ADDR(SMCR), uint8_t> Smcr;
#       endif

#       ifdef SPCR0
            typedef Register<YAAL_ADDR(SPCR0), uint8_t> Spcr0;
#       endif

#       ifdef SPCR
            typedef Register<YAAL_ADDR(SPCR), uint8_t> Spcr;
#       endif

#       ifdef SPDR0
            typedef Register<YAAL_ADDR(SPDR0), uint8_t> Spdr0;
#       endif

#       ifdef SPDR
            typedef Register<YAAL_ADDR(SPDR), uint8_t> Spdr;
#       endif

#       ifdef SPMCR
            typedef Register<YAAL_ADDR(SPMCR), uint8_t> Spmcr;
#       endif

#       ifdef SPMCSR
            typedef Register<YAAL_ADDR(SPMCSR), uint8_t> Spmcsr;
#       endif

#       ifdef SPSR0
            typedef Register<YAAL_ADDR(SPSR0), uint8_t> Spsr0;
#       endif

#       ifdef SPSR
            typedef Register<YAAL_ADDR(SPSR), uint8_t> Spsr;
#       endif

#       ifdef SREG
            typedef Register<YAAL_ADDR(SREG), uint8_t> Sreg;
#       endif

#       ifdef SSFR
            typedef Register<YAAL_ADDR(SSFR), uint8_t> Ssfr;
#       endif

#       ifdef SVCR
            typedef Register<YAAL_ADDR(SVCR), uint8_t> Svcr;
#       endif

#       ifdef T0CR
            typedef Register<YAAL_ADDR(T0CR), uint8_t> T0cr;
#       endif

#       ifdef T10IFR
            typedef Register<YAAL_ADDR(T10IFR), uint8_t> T10ifr;
#       endif

#       ifdef T1CR
            typedef Register<YAAL_ADDR(T1CR), uint8_t> T1cr;
#       endif

#       ifdef T2CRA
            typedef Register<YAAL_ADDR(T2CRA), uint8_t> T2cra;
#       endif

#       ifdef T2CRB
            typedef Register<YAAL_ADDR(T2CRB), uint8_t> T2crb;
#       endif

#       ifdef T2IFR
            typedef Register<YAAL_ADDR(T2IFR), uint8_t> T2ifr;
#       endif

#       ifdef T2MDR
            typedef Register<YAAL_ADDR(T2MDR), uint8_t> T2mdr;
#       endif

#       ifdef T3CRA
            typedef Register<YAAL_ADDR(T3CRA), uint8_t> T3cra;
#       endif

#       ifdef T3IFR
            typedef Register<YAAL_ADDR(T3IFR), uint8_t> T3ifr;
#       endif

#       ifdef TC1H
            typedef Register<YAAL_ADDR(TC1H), uint8_t> Tc1h;
#       endif

#       ifdef TCCR0A
            typedef Register<YAAL_ADDR(TCCR0A), uint8_t> Tccr0a;
#       endif

#       ifdef TCCR0B
            typedef Register<YAAL_ADDR(TCCR0B), uint8_t> Tccr0b;
#       endif

#       ifdef TCCR0C
            typedef Register<YAAL_ADDR(TCCR0C), uint8_t> Tccr0c;
#       endif

#       ifdef TCCR0
            typedef Register<YAAL_ADDR(TCCR0), uint8_t> Tccr0;
#       endif

#       ifdef TCCR1A
            typedef Register<YAAL_ADDR(TCCR1A), uint8_t> Tccr1a;
#       endif

#       ifdef TCCR1B
            typedef Register<YAAL_ADDR(TCCR1B), uint8_t> Tccr1b;
#       endif

#       ifdef TCCR1C
            typedef Register<YAAL_ADDR(TCCR1C), uint8_t> Tccr1c;
#       endif

#       ifdef TCCR1D
            typedef Register<YAAL_ADDR(TCCR1D), uint8_t> Tccr1d;
#       endif

#       ifdef TCCR1E
            typedef Register<YAAL_ADDR(TCCR1E), uint8_t> Tccr1e;
#       endif

#       ifdef TCCR1
            typedef Register<YAAL_ADDR(TCCR1), uint8_t> Tccr1;
#       endif

#       ifdef TCCR2
            typedef Register<YAAL_ADDR(TCCR2), uint8_t> Tccr2;
#       endif

#       ifdef TCNT2
            typedef Register<YAAL_ADDR(TCNT2), uint8_t> Tcnt2;
#       endif

#       ifdef TIFR0
            typedef Register<YAAL_ADDR(TIFR0), uint8_t> Tifr0;
#       endif

#       ifdef TIFR1
            typedef Register<YAAL_ADDR(TIFR1), uint8_t> Tifr1;
#       endif

#       ifdef TIFR2
            typedef Register<YAAL_ADDR(TIFR2), uint8_t> Tifr2;
#       endif

#       ifdef TIFR3
            typedef Register<YAAL_ADDR(TIFR3), uint8_t> Tifr3;
#       endif

#       ifdef TIFR4
            typedef Register<YAAL_ADDR(TIFR4), uint8_t> Tifr4;
#       endif

#       ifdef TIFR5
            typedef Register<YAAL_ADDR(TIFR5), uint8_t> Tifr5;
#       endif

#       ifdef TIFR
            typedef Register<YAAL_ADDR(TIFR), uint8_t> Tifr;
#       endif

#       ifdef TIMSK0
            typedef Register<YAAL_ADDR(TIMSK0), uint8_t> Timsk0;
#       endif

#       ifdef TIMSK1
            typedef Register<YAAL_ADDR(TIMSK1), uint8_t> Timsk1;
#       endif

#       ifdef TIMSK
            typedef Register<YAAL_ADDR(TIMSK), uint8_t> Timsk;
#       endif

#       ifdef TWAR
            typedef Register<YAAL_ADDR(TWAR), uint8_t> Twar;
#       endif

#       ifdef TWBR
            typedef Register<YAAL_ADDR(TWBR), uint8_t> Twbr;
#       endif

#       ifdef TWCR
            typedef Register<YAAL_ADDR(TWCR), uint8_t> Twcr;
#       endif

#       ifdef TWDR
            typedef Register<YAAL_ADDR(TWDR), uint8_t> Twdr;
#       endif

#       ifdef TWSR
            typedef Register<YAAL_ADDR(TWSR), uint8_t> Twsr;
#       endif

#       ifdef TXB
            typedef Register<YAAL_ADDR(TXB), uint8_t> Txb;
#       endif

#       ifdef TX_CNTL
            typedef Register<YAAL_ADDR(TX_CNTL), uint8_t> Tx_cntl;
#       endif

#       ifdef UBRR0H
            typedef Register<YAAL_ADDR(UBRR0H), uint8_t> Ubrr0h;
#       endif

#       ifdef UBRR0L
            typedef Register<YAAL_ADDR(UBRR0L), uint8_t> Ubrr0l;
#       endif

#       ifdef UBRR0
            typedef Register<YAAL_ADDR(UBRR0), uint8_t> Ubrr0;
#       endif

#       ifdef UBRR1H
            typedef Register<YAAL_ADDR(UBRR1H), uint8_t> Ubrr1h;
#       endif

#       ifdef UBRR1L
            typedef Register<YAAL_ADDR(UBRR1L), uint8_t> Ubrr1l;
#       endif

#       ifdef UBRR1
            typedef Register<YAAL_ADDR(UBRR1), uint8_t> Ubrr1;
#       endif

#       ifdef UBRRHI
            typedef Register<YAAL_ADDR(UBRRHI), uint8_t> Ubrrhi;
#       endif

#       ifdef UBRRH
            typedef Register<YAAL_ADDR(UBRRH), uint8_t> Ubrrh;
#       endif

#       ifdef UBRRL
            typedef Register<YAAL_ADDR(UBRRL), uint8_t> Ubrrl;
#       endif

#       ifdef UBRR
            typedef Register<YAAL_ADDR(UBRR), uint8_t> Ubrr;
#       endif

#       ifdef UCR
            typedef Register<YAAL_ADDR(UCR), uint8_t> Ucr;
#       endif

#       ifdef UCSR0A
            typedef Register<YAAL_ADDR(UCSR0A), uint8_t> Ucsr0a;
#       endif

#       ifdef UCSR0B
            typedef Register<YAAL_ADDR(UCSR0B), uint8_t> Ucsr0b;
#       endif

#       ifdef UCSR0C
            typedef Register<YAAL_ADDR(UCSR0C), uint8_t> Ucsr0c;
#       endif

#       ifdef UCSR1A
            typedef Register<YAAL_ADDR(UCSR1A), uint8_t> Ucsr1a;
#       endif

#       ifdef UCSR1B
            typedef Register<YAAL_ADDR(UCSR1B), uint8_t> Ucsr1b;
#       endif

#       ifdef UCSR1C
            typedef Register<YAAL_ADDR(UCSR1C), uint8_t> Ucsr1c;
#       endif

#       ifdef UCSRA
            typedef Register<YAAL_ADDR(UCSRA), uint8_t> Ucsra;
#       endif

#       ifdef UCSRB
            typedef Register<YAAL_ADDR(UCSRB), uint8_t> Ucsrb;
#       endif

#       ifdef UCSRC
            typedef Register<YAAL_ADDR(UCSRC), uint8_t> Ucsrc;
#       endif

#       ifdef UDR0
            typedef Register<YAAL_ADDR(UDR0), uint8_t> Udr0;
#       endif

#       ifdef UDR1
            typedef Register<YAAL_ADDR(UDR1), uint8_t> Udr1;
#       endif

#       ifdef UDR
            typedef Register<YAAL_ADDR(UDR), uint8_t> Udr;
#       endif

#       ifdef USIBR
            typedef Register<YAAL_ADDR(USIBR), uint8_t> Usibr;
#       endif

#       ifdef USICR
            typedef Register<YAAL_ADDR(USICR), uint8_t> Usicr;
#       endif

#       ifdef USIDR
            typedef Register<YAAL_ADDR(USIDR), uint8_t> Usidr;
#       endif

#       ifdef USIPP
            typedef Register<YAAL_ADDR(USIPP), uint8_t> Usipp;
#       endif

#       ifdef USISR
            typedef Register<YAAL_ADDR(USISR), uint8_t> Usisr;
#       endif

#       ifdef USR
            typedef Register<YAAL_ADDR(USR), uint8_t> Usr;
#       endif

#       ifdef VCOTUNE
            typedef Register<YAAL_ADDR(VCOTUNE), uint8_t> Vcotune;
#       endif

#       ifdef VMCSR
            typedef Register<YAAL_ADDR(VMCSR), uint8_t> Vmcsr;
#       endif

#       ifdef WDTCR
            typedef Register<YAAL_ADDR(WDTCR), uint8_t> Wdtcr;
#       endif

#       ifdef WDTCSR
            typedef Register<YAAL_ADDR(WDTCSR), uint8_t> Wdtcsr;
#       endif

#       ifdef XDIV
            typedef Register<YAAL_ADDR(XDIV), uint8_t> Xdiv;
#       endif

    }
}

#endif
