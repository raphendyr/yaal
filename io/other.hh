#ifndef __YAAL_IO__OTHER__
#define __YAAL_IO__OTHER__ 1
// do not edit. genereted using io_definitions.sh

#include "../requirements.hh"
#include <avr/io.h>

namespace yaal {
    namespace registers {

#       ifdef ADC
            typedef Register<YAAL_ADDR(ADC), reg16_t> Adc;
#       endif

#       ifdef ADCW
            typedef Register<YAAL_ADDR(ADCW), reg16_t> Adcw;
#       endif

#       ifdef ADRSLT
            typedef Register<YAAL_ADDR(ADRSLT), reg16_t> Adrslt;
#       endif

#       ifdef DAC
            typedef Register<YAAL_ADDR(DAC), reg16_t> Dac;
#       endif

#       ifdef DACVAL
            typedef Register<YAAL_ADDR(DACVAL), reg16_t> Dacval;
#       endif

#       ifdef EEAR
            typedef Register<YAAL_ADDR(EEAR), reg16_t> Eear;
#       endif

#       ifdef EXOCR1A
            typedef Register<YAAL_ADDR(EXOCR1A), reg16_t> Exocr1a;
#       endif

#       ifdef EXOCR1B
            typedef Register<YAAL_ADDR(EXOCR1B), reg16_t> Exocr1b;
#       endif

#       ifdef EXTCNT1
            typedef Register<YAAL_ADDR(EXTCNT1), reg16_t> Extcnt1;
#       endif

#       ifdef ICR0
            typedef Register<YAAL_ADDR(ICR0), reg16_t> Icr0;
#       endif

#       ifdef ICR1
            typedef Register<YAAL_ADDR(ICR1), reg16_t> Icr1;
#       endif

#       ifdef IPA
            typedef Register<YAAL_ADDR(IPA), reg16_t> Ipa;
#       endif

#       ifdef IPD
            typedef Register<YAAL_ADDR(IPD), reg16_t> Ipd;
#       endif

#       ifdef OCR0A
            typedef Register<YAAL_ADDR(OCR0A), reg16_t> Ocr0a;
#       endif

#       ifdef OCR0B
            typedef Register<YAAL_ADDR(OCR0B), reg16_t> Ocr0b;
#       endif

#       ifdef OCR0RA
            typedef Register<YAAL_ADDR(OCR0RA), reg16_t> Ocr0ra;
#       endif

#       ifdef OCR0RB
            typedef Register<YAAL_ADDR(OCR0RB), reg16_t> Ocr0rb;
#       endif

#       ifdef OCR0SB
            typedef Register<YAAL_ADDR(OCR0SB), reg16_t> Ocr0sb;
#       endif

#       ifdef OCR1A
            typedef Register<YAAL_ADDR(OCR1A), reg16_t> Ocr1a;
#       endif

#       ifdef OCR1B
            typedef Register<YAAL_ADDR(OCR1B), reg16_t> Ocr1b;
#       endif

#       ifdef OCR1
            typedef Register<YAAL_ADDR(OCR1), reg16_t> Ocr1;
#       endif

#       ifdef OCR2RA
            typedef Register<YAAL_ADDR(OCR2RA), reg16_t> Ocr2ra;
#       endif

#       ifdef OCR2RB
            typedef Register<YAAL_ADDR(OCR2RB), reg16_t> Ocr2rb;
#       endif

#       ifdef OCR2SB
            typedef Register<YAAL_ADDR(OCR2SB), reg16_t> Ocr2sb;
#       endif

#       ifdef OCRA1
            typedef Register<YAAL_ADDR(OCRA1), reg16_t> Ocra1;
#       endif

#       ifdef OCRB1
            typedef Register<YAAL_ADDR(OCRB1), reg16_t> Ocrb1;
#       endif

#       ifdef SP
            typedef Register<YAAL_ADDR(SP), reg16_t> Sp;
#       endif

#       ifdef TCNT0
            typedef Register<YAAL_ADDR(TCNT0), reg16_t> Tcnt0;
#       endif

#       ifdef TCNT1
            typedef Register<YAAL_ADDR(TCNT1), reg16_t> Tcnt1;
#       endif

#       ifdef ACSRA
            typedef Register<YAAL_ADDR(ACSRA), reg8_t> Acsra;
#       endif

#       ifdef ACSRB
            typedef Register<YAAL_ADDR(ACSRB), reg8_t> Acsrb;
#       endif

#       ifdef ACSR
            typedef Register<YAAL_ADDR(ACSR), reg8_t> Acsr;
#       endif

#       ifdef ADCSRA
            typedef Register<YAAL_ADDR(ADCSRA), reg8_t> Adcsra;
#       endif

#       ifdef ADCSRB
            typedef Register<YAAL_ADDR(ADCSRB), reg8_t> Adcsrb;
#       endif

#       ifdef ADCSR
            typedef Register<YAAL_ADDR(ADCSR), reg8_t> Adcsr;
#       endif

#       ifdef ADMUX
            typedef Register<YAAL_ADDR(ADMUX), reg8_t> Admux;
#       endif

#       ifdef AGPDDR
            typedef Register<YAAL_ADDR(AGPDDR), reg8_t> Agpddr;
#       endif

#       ifdef AGPPIN
            typedef Register<YAAL_ADDR(AGPPIN), reg8_t> Agppin;
#       endif

#       ifdef AGPPORT
            typedef Register<YAAL_ADDR(AGPPORT), reg8_t> Agpport;
#       endif

#       ifdef AMUXCTL
            typedef Register<YAAL_ADDR(AMUXCTL), reg8_t> Amuxctl;
#       endif

#       ifdef ASSR
            typedef Register<YAAL_ADDR(ASSR), reg8_t> Assr;
#       endif

#       ifdef B_DET
            typedef Register<YAAL_ADDR(B_DET), reg8_t> B_det;
#       endif

#       ifdef BGPDDR
            typedef Register<YAAL_ADDR(BGPDDR), reg8_t> Bgpddr;
#       endif

#       ifdef BGPPIN
            typedef Register<YAAL_ADDR(BGPPIN), reg8_t> Bgppin;
#       endif

#       ifdef BGPPORT
            typedef Register<YAAL_ADDR(BGPPORT), reg8_t> Bgpport;
#       endif

#       ifdef BODCR
            typedef Register<YAAL_ADDR(BODCR), reg8_t> Bodcr;
#       endif

#       ifdef BTCNT
            typedef Register<YAAL_ADDR(BTCNT), reg8_t> Btcnt;
#       endif

#       ifdef BTCR
            typedef Register<YAAL_ADDR(BTCR), reg8_t> Btcr;
#       endif

#       ifdef CCP
            typedef Register<YAAL_ADDR(CCP), reg8_t> Ccp;
#       endif

#       ifdef CGPDDR
            typedef Register<YAAL_ADDR(CGPDDR), reg8_t> Cgpddr;
#       endif

#       ifdef CGPPIN
            typedef Register<YAAL_ADDR(CGPPIN), reg8_t> Cgppin;
#       endif

#       ifdef CGPPORT
            typedef Register<YAAL_ADDR(CGPPORT), reg8_t> Cgpport;
#       endif

#       ifdef CLK_CNTR
            typedef Register<YAAL_ADDR(CLK_CNTR), reg8_t> Clk_cntr;
#       endif

#       ifdef CLKMSR
            typedef Register<YAAL_ADDR(CLKMSR), reg8_t> Clkmsr;
#       endif

#       ifdef CLKPR
            typedef Register<YAAL_ADDR(CLKPR), reg8_t> Clkpr;
#       endif

#       ifdef CLKPSR
            typedef Register<YAAL_ADDR(CLKPSR), reg8_t> Clkpsr;
#       endif

#       ifdef CMCR
            typedef Register<YAAL_ADDR(CMCR), reg8_t> Cmcr;
#       endif

#       ifdef CMIMR
            typedef Register<YAAL_ADDR(CMIMR), reg8_t> Cmimr;
#       endif

#       ifdef CMSR
            typedef Register<YAAL_ADDR(CMSR), reg8_t> Cmsr;
#       endif

#       ifdef DEEARL
            typedef Register<YAAL_ADDR(DEEARL), reg8_t> Deearl;
#       endif

#       ifdef DEEAR
            typedef Register<YAAL_ADDR(DEEAR), reg8_t> Deear;
#       endif

#       ifdef DEECR
            typedef Register<YAAL_ADDR(DEECR), reg8_t> Deecr;
#       endif

#       ifdef DEEDR
            typedef Register<YAAL_ADDR(DEEDR), reg8_t> Deedr;
#       endif

#       ifdef DIDR0
            typedef Register<YAAL_ADDR(DIDR0), reg8_t> Didr0;
#       endif

#       ifdef DIDR1
            typedef Register<YAAL_ADDR(DIDR1), reg8_t> Didr1;
#       endif

#       ifdef DIDR
            typedef Register<YAAL_ADDR(DIDR), reg8_t> Didr;
#       endif

#       ifdef DT1A
            typedef Register<YAAL_ADDR(DT1A), reg8_t> Dt1a;
#       endif

#       ifdef DT1B
            typedef Register<YAAL_ADDR(DT1B), reg8_t> Dt1b;
#       endif

#       ifdef DT1
            typedef Register<YAAL_ADDR(DT1), reg8_t> Dt1;
#       endif

#       ifdef DTPS1
            typedef Register<YAAL_ADDR(DTPS1), reg8_t> Dtps1;
#       endif

#       ifdef DWDR
            typedef Register<YAAL_ADDR(DWDR), reg8_t> Dwdr;
#       endif

#       ifdef EECR
            typedef Register<YAAL_ADDR(EECR), reg8_t> Eecr;
#       endif

#       ifdef EEDR
            typedef Register<YAAL_ADDR(EEDR), reg8_t> Eedr;
#       endif

#       ifdef EICRA
            typedef Register<YAAL_ADDR(EICRA), reg8_t> Eicra;
#       endif

#       ifdef EICRB
            typedef Register<YAAL_ADDR(EICRB), reg8_t> Eicrb;
#       endif

#       ifdef EICR
            typedef Register<YAAL_ADDR(EICR), reg8_t> Eicr;
#       endif

#       ifdef EIFR
            typedef Register<YAAL_ADDR(EIFR), reg8_t> Eifr;
#       endif

#       ifdef EIMF
            typedef Register<YAAL_ADDR(EIMF), reg8_t> Eimf;
#       endif

#       ifdef EIMSK
            typedef Register<YAAL_ADDR(EIMSK), reg8_t> Eimsk;
#       endif

#       ifdef EIND
            typedef Register<YAAL_ADDR(EIND), reg8_t> Eind;
#       endif

#       ifdef EIRR
            typedef Register<YAAL_ADDR(EIRR), reg8_t> Eirr;
#       endif

#       ifdef EMCUCR
            typedef Register<YAAL_ADDR(EMCUCR), reg8_t> Emcucr;
#       endif

#       ifdef EXTCCR0
            typedef Register<YAAL_ADDR(EXTCCR0), reg8_t> Extccr0;
#       endif

#       ifdef EXTCCR1A
            typedef Register<YAAL_ADDR(EXTCCR1A), reg8_t> Extccr1a;
#       endif

#       ifdef EXTCCR1B
            typedef Register<YAAL_ADDR(EXTCCR1B), reg8_t> Extccr1b;
#       endif

#       ifdef EXTCNT
            typedef Register<YAAL_ADDR(EXTCNT), reg8_t> Extcnt;
#       endif

#       ifdef EXTIFR
            typedef Register<YAAL_ADDR(EXTIFR), reg8_t> Extifr;
#       endif

#       ifdef EXTIMSK
            typedef Register<YAAL_ADDR(EXTIMSK), reg8_t> Extimsk;
#       endif

#       ifdef FISCR
            typedef Register<YAAL_ADDR(FISCR), reg8_t> Fiscr;
#       endif

#       ifdef FISUA
            typedef Register<YAAL_ADDR(FISUA), reg8_t> Fisua;
#       endif

#       ifdef FISUB
            typedef Register<YAAL_ADDR(FISUB), reg8_t> Fisub;
#       endif

#       ifdef FISUC
            typedef Register<YAAL_ADDR(FISUC), reg8_t> Fisuc;
#       endif

#       ifdef FISUD
            typedef Register<YAAL_ADDR(FISUD), reg8_t> Fisud;
#       endif

#       ifdef FPGAD
            typedef Register<YAAL_ADDR(FPGAD), reg8_t> Fpgad;
#       endif

#       ifdef FPGAX
            typedef Register<YAAL_ADDR(FPGAX), reg8_t> Fpgax;
#       endif

#       ifdef FPGAY
            typedef Register<YAAL_ADDR(FPGAY), reg8_t> Fpgay;
#       endif

#       ifdef FPGAZ
            typedef Register<YAAL_ADDR(FPGAZ), reg8_t> Fpgaz;
#       endif

#       ifdef GICR
            typedef Register<YAAL_ADDR(GICR), reg8_t> Gicr;
#       endif

#       ifdef GIFR
            typedef Register<YAAL_ADDR(GIFR), reg8_t> Gifr;
#       endif

#       ifdef GIMSK
            typedef Register<YAAL_ADDR(GIMSK), reg8_t> Gimsk;
#       endif

#       ifdef GIPR
            typedef Register<YAAL_ADDR(GIPR), reg8_t> Gipr;
#       endif

#       ifdef GPIOR0
            typedef Register<YAAL_ADDR(GPIOR0), reg8_t> Gpior0;
#       endif

#       ifdef GPIOR1
            typedef Register<YAAL_ADDR(GPIOR1), reg8_t> Gpior1;
#       endif

#       ifdef GPIOR2
            typedef Register<YAAL_ADDR(GPIOR2), reg8_t> Gpior2;
#       endif

#       ifdef GPIOR3
            typedef Register<YAAL_ADDR(GPIOR3), reg8_t> Gpior3;
#       endif

#       ifdef GTCCR
            typedef Register<YAAL_ADDR(GTCCR), reg8_t> Gtccr;
#       endif

#       ifdef ICR
            typedef Register<YAAL_ADDR(ICR), reg8_t> Icr;
#       endif

#       ifdef IFR
            typedef Register<YAAL_ADDR(IFR), reg8_t> Ifr;
#       endif

#       ifdef IO_DATIN
            typedef Register<YAAL_ADDR(IO_DATIN), reg8_t> Io_datin;
#       endif

#       ifdef IO_DATOUT
            typedef Register<YAAL_ADDR(IO_DATOUT), reg8_t> Io_datout;
#       endif

#       ifdef IO_ENAB
            typedef Register<YAAL_ADDR(IO_ENAB), reg8_t> Io_enab;
#       endif

#       ifdef IPCR
            typedef Register<YAAL_ADDR(IPCR), reg8_t> Ipcr;
#       endif

#       ifdef IRDAMOD
            typedef Register<YAAL_ADDR(IRDAMOD), reg8_t> Irdamod;
#       endif

#       ifdef LFCDR
            typedef Register<YAAL_ADDR(LFCDR), reg8_t> Lfcdr;
#       endif

#       ifdef LFFR
            typedef Register<YAAL_ADDR(LFFR), reg8_t> Lffr;
#       endif

#       ifdef LFRB
            typedef Register<YAAL_ADDR(LFRB), reg8_t> Lfrb;
#       endif

#       ifdef LFRR
            typedef Register<YAAL_ADDR(LFRR), reg8_t> Lfrr;
#       endif

#       ifdef LOCKDET1
            typedef Register<YAAL_ADDR(LOCKDET1), reg8_t> Lockdet1;
#       endif

#       ifdef LOCKDET2
            typedef Register<YAAL_ADDR(LOCKDET2), reg8_t> Lockdet2;
#       endif

#       ifdef MCSR
            typedef Register<YAAL_ADDR(MCSR), reg8_t> Mcsr;
#       endif

#       ifdef MCUCR
            typedef Register<YAAL_ADDR(MCUCR), reg8_t> Mcucr;
#       endif

#       ifdef MCUCSR
            typedef Register<YAAL_ADDR(MCUCSR), reg8_t> Mcucsr;
#       endif

#       ifdef MCUCS
            typedef Register<YAAL_ADDR(MCUCS), reg8_t> Mcucs;
#       endif

#       ifdef MCUR
            typedef Register<YAAL_ADDR(MCUR), reg8_t> Mcur;
#       endif

#       ifdef MCUSR
            typedef Register<YAAL_ADDR(MCUSR), reg8_t> Mcusr;
#       endif

#       ifdef MODCR
            typedef Register<YAAL_ADDR(MODCR), reg8_t> Modcr;
#       endif

#       ifdef MONDR
            typedef Register<YAAL_ADDR(MONDR), reg8_t> Mondr;
#       endif

#       ifdef MSMCR
            typedef Register<YAAL_ADDR(MSMCR), reg8_t> Msmcr;
#       endif

#       ifdef MSPCR
            typedef Register<YAAL_ADDR(MSPCR), reg8_t> Mspcr;
#       endif

#       ifdef MSPDR
            typedef Register<YAAL_ADDR(MSPDR), reg8_t> Mspdr;
#       endif

#       ifdef MSPSR
            typedef Register<YAAL_ADDR(MSPSR), reg8_t> Mspsr;
#       endif

#       ifdef NVMCMD
            typedef Register<YAAL_ADDR(NVMCMD), reg8_t> Nvmcmd;
#       endif

#       ifdef NVMCSR
            typedef Register<YAAL_ADDR(NVMCSR), reg8_t> Nvmcsr;
#       endif

#       ifdef OCDR
            typedef Register<YAAL_ADDR(OCDR), reg8_t> Ocdr;
#       endif

#       ifdef OCR0
            typedef Register<YAAL_ADDR(OCR0), reg8_t> Ocr0;
#       endif

#       ifdef OCR1C
            typedef Register<YAAL_ADDR(OCR1C), reg8_t> Ocr1c;
#       endif

#       ifdef OCR1D
            typedef Register<YAAL_ADDR(OCR1D), reg8_t> Ocr1d;
#       endif

#       ifdef OCR2
            typedef Register<YAAL_ADDR(OCR2), reg8_t> Ocr2;
#       endif

#       ifdef OSCCAL
            typedef Register<YAAL_ADDR(OSCCAL), reg8_t> Osccal;
#       endif

#       ifdef OSICSR
            typedef Register<YAAL_ADDR(OSICSR), reg8_t> Osicsr;
#       endif

#       ifdef PACR
            typedef Register<YAAL_ADDR(PACR), reg8_t> Pacr;
#       endif

#       ifdef PCICR
            typedef Register<YAAL_ADDR(PCICR), reg8_t> Pcicr;
#       endif

#       ifdef PCIFR
            typedef Register<YAAL_ADDR(PCIFR), reg8_t> Pcifr;
#       endif

#       ifdef PCMSK0
            typedef Register<YAAL_ADDR(PCMSK0), reg8_t> Pcmsk0;
#       endif

#       ifdef PCMSK1
            typedef Register<YAAL_ADDR(PCMSK1), reg8_t> Pcmsk1;
#       endif

#       ifdef PCMSK2
            typedef Register<YAAL_ADDR(PCMSK2), reg8_t> Pcmsk2;
#       endif

#       ifdef PCMSK
            typedef Register<YAAL_ADDR(PCMSK), reg8_t> Pcmsk;
#       endif

#       ifdef PCNF0
            typedef Register<YAAL_ADDR(PCNF0), reg8_t> Pcnf0;
#       endif

#       ifdef PCNF2
            typedef Register<YAAL_ADDR(PCNF2), reg8_t> Pcnf2;
#       endif

#       ifdef PCTL0
            typedef Register<YAAL_ADDR(PCTL0), reg8_t> Pctl0;
#       endif

#       ifdef PCTL2
            typedef Register<YAAL_ADDR(PCTL2), reg8_t> Pctl2;
#       endif

#       ifdef PERIPHEN
            typedef Register<YAAL_ADDR(PERIPHEN), reg8_t> Periphen;
#       endif

#       ifdef PIFR0
            typedef Register<YAAL_ADDR(PIFR0), reg8_t> Pifr0;
#       endif

#       ifdef PIFR2
            typedef Register<YAAL_ADDR(PIFR2), reg8_t> Pifr2;
#       endif

#       ifdef PIM0
            typedef Register<YAAL_ADDR(PIM0), reg8_t> Pim0;
#       endif

#       ifdef PIM2
            typedef Register<YAAL_ADDR(PIM2), reg8_t> Pim2;
#       endif

#       ifdef PLLCSR
            typedef Register<YAAL_ADDR(PLLCSR), reg8_t> Pllcsr;
#       endif

#       ifdef PLLFRQ
            typedef Register<YAAL_ADDR(PLLFRQ), reg8_t> Pllfrq;
#       endif

#       ifdef PORTCR
            typedef Register<YAAL_ADDR(PORTCR), reg8_t> Portcr;
#       endif

#       ifdef PRELD
            typedef Register<YAAL_ADDR(PRELD), reg8_t> Preld;
#       endif

#       ifdef PRR
            typedef Register<YAAL_ADDR(PRR), reg8_t> Prr;
#       endif

#       ifdef PUEA
            typedef Register<YAAL_ADDR(PUEA), reg8_t> Puea;
#       endif

#       ifdef PUEB
            typedef Register<YAAL_ADDR(PUEB), reg8_t> Pueb;
#       endif

#       ifdef PUEC
            typedef Register<YAAL_ADDR(PUEC), reg8_t> Puec;
#       endif

#       ifdef PWR_ATTEN
            typedef Register<YAAL_ADDR(PWR_ATTEN), reg8_t> Pwr_atten;
#       endif

#       ifdef QTCSR
            typedef Register<YAAL_ADDR(QTCSR), reg8_t> Qtcsr;
#       endif

#       ifdef RAMAR
            typedef Register<YAAL_ADDR(RAMAR), reg8_t> Ramar;
#       endif

#       ifdef RAMDR
            typedef Register<YAAL_ADDR(RAMDR), reg8_t> Ramdr;
#       endif

#       ifdef RAMPZ
            typedef Register<YAAL_ADDR(RAMPZ), reg8_t> Rampz;
#       endif

#       ifdef RSTFLR
            typedef Register<YAAL_ADDR(RSTFLR), reg8_t> Rstflr;
#       endif

#       ifdef RXB
            typedef Register<YAAL_ADDR(RXB), reg8_t> Rxb;
#       endif

#       ifdef SCCR
            typedef Register<YAAL_ADDR(SCCR), reg8_t> Sccr;
#       endif

#       ifdef SCR
            typedef Register<YAAL_ADDR(SCR), reg8_t> Scr;
#       endif

#       ifdef SFIOR
            typedef Register<YAAL_ADDR(SFIOR), reg8_t> Sfior;
#       endif

#       ifdef SFTCR
            typedef Register<YAAL_ADDR(SFTCR), reg8_t> Sftcr;
#       endif

#       ifdef SMCR
            typedef Register<YAAL_ADDR(SMCR), reg8_t> Smcr;
#       endif

#       ifdef SPCR0
            typedef Register<YAAL_ADDR(SPCR0), reg8_t> Spcr0;
#       endif

#       ifdef SPCR
            typedef Register<YAAL_ADDR(SPCR), reg8_t> Spcr;
#       endif

#       ifdef SPDR
            typedef Register<YAAL_ADDR(SPDR), reg8_t> Spdr;
#       endif

#       ifdef SPMCR
            typedef Register<YAAL_ADDR(SPMCR), reg8_t> Spmcr;
#       endif

#       ifdef SPMCSR
            typedef Register<YAAL_ADDR(SPMCSR), reg8_t> Spmcsr;
#       endif

#       ifdef SPSR0
            typedef Register<YAAL_ADDR(SPSR0), reg8_t> Spsr0;
#       endif

#       ifdef SPSR
            typedef Register<YAAL_ADDR(SPSR), reg8_t> Spsr;
#       endif

#       ifdef SREG
            typedef Register<YAAL_ADDR(SREG), reg8_t> Sreg;
#       endif

#       ifdef SSFR
            typedef Register<YAAL_ADDR(SSFR), reg8_t> Ssfr;
#       endif

#       ifdef SVCR
            typedef Register<YAAL_ADDR(SVCR), reg8_t> Svcr;
#       endif

#       ifdef T0CR
            typedef Register<YAAL_ADDR(T0CR), reg8_t> T0cr;
#       endif

#       ifdef T10IFR
            typedef Register<YAAL_ADDR(T10IFR), reg8_t> T10ifr;
#       endif

#       ifdef T1CR
            typedef Register<YAAL_ADDR(T1CR), reg8_t> T1cr;
#       endif

#       ifdef T2CRA
            typedef Register<YAAL_ADDR(T2CRA), reg8_t> T2cra;
#       endif

#       ifdef T2CRB
            typedef Register<YAAL_ADDR(T2CRB), reg8_t> T2crb;
#       endif

#       ifdef T2IFR
            typedef Register<YAAL_ADDR(T2IFR), reg8_t> T2ifr;
#       endif

#       ifdef T2MDR
            typedef Register<YAAL_ADDR(T2MDR), reg8_t> T2mdr;
#       endif

#       ifdef T3CRA
            typedef Register<YAAL_ADDR(T3CRA), reg8_t> T3cra;
#       endif

#       ifdef T3IFR
            typedef Register<YAAL_ADDR(T3IFR), reg8_t> T3ifr;
#       endif

#       ifdef TC1H
            typedef Register<YAAL_ADDR(TC1H), reg8_t> Tc1h;
#       endif

#       ifdef TCCR0A
            typedef Register<YAAL_ADDR(TCCR0A), reg8_t> Tccr0a;
#       endif

#       ifdef TCCR0B
            typedef Register<YAAL_ADDR(TCCR0B), reg8_t> Tccr0b;
#       endif

#       ifdef TCCR0C
            typedef Register<YAAL_ADDR(TCCR0C), reg8_t> Tccr0c;
#       endif

#       ifdef TCCR0
            typedef Register<YAAL_ADDR(TCCR0), reg8_t> Tccr0;
#       endif

#       ifdef TCCR1A
            typedef Register<YAAL_ADDR(TCCR1A), reg8_t> Tccr1a;
#       endif

#       ifdef TCCR1B
            typedef Register<YAAL_ADDR(TCCR1B), reg8_t> Tccr1b;
#       endif

#       ifdef TCCR1C
            typedef Register<YAAL_ADDR(TCCR1C), reg8_t> Tccr1c;
#       endif

#       ifdef TCCR1D
            typedef Register<YAAL_ADDR(TCCR1D), reg8_t> Tccr1d;
#       endif

#       ifdef TCCR1E
            typedef Register<YAAL_ADDR(TCCR1E), reg8_t> Tccr1e;
#       endif

#       ifdef TCCR1
            typedef Register<YAAL_ADDR(TCCR1), reg8_t> Tccr1;
#       endif

#       ifdef TCCR2
            typedef Register<YAAL_ADDR(TCCR2), reg8_t> Tccr2;
#       endif

#       ifdef TCNT2
            typedef Register<YAAL_ADDR(TCNT2), reg8_t> Tcnt2;
#       endif

#       ifdef TIFR0
            typedef Register<YAAL_ADDR(TIFR0), reg8_t> Tifr0;
#       endif

#       ifdef TIFR1
            typedef Register<YAAL_ADDR(TIFR1), reg8_t> Tifr1;
#       endif

#       ifdef TIFR2
            typedef Register<YAAL_ADDR(TIFR2), reg8_t> Tifr2;
#       endif

#       ifdef TIFR3
            typedef Register<YAAL_ADDR(TIFR3), reg8_t> Tifr3;
#       endif

#       ifdef TIFR4
            typedef Register<YAAL_ADDR(TIFR4), reg8_t> Tifr4;
#       endif

#       ifdef TIFR5
            typedef Register<YAAL_ADDR(TIFR5), reg8_t> Tifr5;
#       endif

#       ifdef TIFR
            typedef Register<YAAL_ADDR(TIFR), reg8_t> Tifr;
#       endif

#       ifdef TIMSK0
            typedef Register<YAAL_ADDR(TIMSK0), reg8_t> Timsk0;
#       endif

#       ifdef TIMSK1
            typedef Register<YAAL_ADDR(TIMSK1), reg8_t> Timsk1;
#       endif

#       ifdef TIMSK
            typedef Register<YAAL_ADDR(TIMSK), reg8_t> Timsk;
#       endif

#       ifdef TWAR
            typedef Register<YAAL_ADDR(TWAR), reg8_t> Twar;
#       endif

#       ifdef TWBR
            typedef Register<YAAL_ADDR(TWBR), reg8_t> Twbr;
#       endif

#       ifdef TWCR
            typedef Register<YAAL_ADDR(TWCR), reg8_t> Twcr;
#       endif

#       ifdef TWDR
            typedef Register<YAAL_ADDR(TWDR), reg8_t> Twdr;
#       endif

#       ifdef TWSAM
            typedef Register<YAAL_ADDR(TWSAM), reg8_t> Twsam;
#       endif

#       ifdef TWSA
            typedef Register<YAAL_ADDR(TWSA), reg8_t> Twsa;
#       endif

#       ifdef TWSCRA
            typedef Register<YAAL_ADDR(TWSCRA), reg8_t> Twscra;
#       endif

#       ifdef TWSCRB
            typedef Register<YAAL_ADDR(TWSCRB), reg8_t> Twscrb;
#       endif

#       ifdef TWSD
            typedef Register<YAAL_ADDR(TWSD), reg8_t> Twsd;
#       endif

#       ifdef TWSR
            typedef Register<YAAL_ADDR(TWSR), reg8_t> Twsr;
#       endif

#       ifdef TWSSRA
            typedef Register<YAAL_ADDR(TWSSRA), reg8_t> Twssra;
#       endif

#       ifdef TXB
            typedef Register<YAAL_ADDR(TXB), reg8_t> Txb;
#       endif

#       ifdef TX_CNTL
            typedef Register<YAAL_ADDR(TX_CNTL), reg8_t> Tx_cntl;
#       endif

#       ifdef UBRR0H
            typedef Register<YAAL_ADDR(UBRR0H), reg8_t> Ubrr0h;
#       endif

#       ifdef UBRR0L
            typedef Register<YAAL_ADDR(UBRR0L), reg8_t> Ubrr0l;
#       endif

#       ifdef UBRR0
            typedef Register<YAAL_ADDR(UBRR0), reg8_t> Ubrr0;
#       endif

#       ifdef UBRR1H
            typedef Register<YAAL_ADDR(UBRR1H), reg8_t> Ubrr1h;
#       endif

#       ifdef UBRR1L
            typedef Register<YAAL_ADDR(UBRR1L), reg8_t> Ubrr1l;
#       endif

#       ifdef UBRR1
            typedef Register<YAAL_ADDR(UBRR1), reg8_t> Ubrr1;
#       endif

#       ifdef UBRRHI
            typedef Register<YAAL_ADDR(UBRRHI), reg8_t> Ubrrhi;
#       endif

#       ifdef UBRRH
            typedef Register<YAAL_ADDR(UBRRH), reg8_t> Ubrrh;
#       endif

#       ifdef UBRRLO
            typedef Register<YAAL_ADDR(UBRRLO), reg8_t> Ubrrlo;
#       endif

#       ifdef UBRRL
            typedef Register<YAAL_ADDR(UBRRL), reg8_t> Ubrrl;
#       endif

#       ifdef UBRR
            typedef Register<YAAL_ADDR(UBRR), reg8_t> Ubrr;
#       endif

#       ifdef UCRA
            typedef Register<YAAL_ADDR(UCRA), reg8_t> Ucra;
#       endif

#       ifdef UCRB
            typedef Register<YAAL_ADDR(UCRB), reg8_t> Ucrb;
#       endif

#       ifdef UCR
            typedef Register<YAAL_ADDR(UCR), reg8_t> Ucr;
#       endif

#       ifdef UCSR0A
            typedef Register<YAAL_ADDR(UCSR0A), reg8_t> Ucsr0a;
#       endif

#       ifdef UCSR0B
            typedef Register<YAAL_ADDR(UCSR0B), reg8_t> Ucsr0b;
#       endif

#       ifdef UCSR0C
            typedef Register<YAAL_ADDR(UCSR0C), reg8_t> Ucsr0c;
#       endif

#       ifdef UCSR1A
            typedef Register<YAAL_ADDR(UCSR1A), reg8_t> Ucsr1a;
#       endif

#       ifdef UCSR1B
            typedef Register<YAAL_ADDR(UCSR1B), reg8_t> Ucsr1b;
#       endif

#       ifdef UCSR1C
            typedef Register<YAAL_ADDR(UCSR1C), reg8_t> Ucsr1c;
#       endif

#       ifdef UCSRA
            typedef Register<YAAL_ADDR(UCSRA), reg8_t> Ucsra;
#       endif

#       ifdef UCSRB
            typedef Register<YAAL_ADDR(UCSRB), reg8_t> Ucsrb;
#       endif

#       ifdef UCSRC
            typedef Register<YAAL_ADDR(UCSRC), reg8_t> Ucsrc;
#       endif

#       ifdef UDR0
            typedef Register<YAAL_ADDR(UDR0), reg8_t> Udr0;
#       endif

#       ifdef UDR1
            typedef Register<YAAL_ADDR(UDR1), reg8_t> Udr1;
#       endif

#       ifdef UDR
            typedef Register<YAAL_ADDR(UDR), reg8_t> Udr;
#       endif

#       ifdef USIBR
            typedef Register<YAAL_ADDR(USIBR), reg8_t> Usibr;
#       endif

#       ifdef USICR
            typedef Register<YAAL_ADDR(USICR), reg8_t> Usicr;
#       endif

#       ifdef USIDR
            typedef Register<YAAL_ADDR(USIDR), reg8_t> Usidr;
#       endif

#       ifdef USIPP
            typedef Register<YAAL_ADDR(USIPP), reg8_t> Usipp;
#       endif

#       ifdef USISR
            typedef Register<YAAL_ADDR(USISR), reg8_t> Usisr;
#       endif

#       ifdef USPCR
            typedef Register<YAAL_ADDR(USPCR), reg8_t> Uspcr;
#       endif

#       ifdef USPDR
            typedef Register<YAAL_ADDR(USPDR), reg8_t> Uspdr;
#       endif

#       ifdef USPSR
            typedef Register<YAAL_ADDR(USPSR), reg8_t> Uspsr;
#       endif

#       ifdef USR
            typedef Register<YAAL_ADDR(USR), reg8_t> Usr;
#       endif

#       ifdef VCOTUNE
            typedef Register<YAAL_ADDR(VCOTUNE), reg8_t> Vcotune;
#       endif

#       ifdef VLMCSR
            typedef Register<YAAL_ADDR(VLMCSR), reg8_t> Vlmcsr;
#       endif

#       ifdef VMCSR
            typedef Register<YAAL_ADDR(VMCSR), reg8_t> Vmcsr;
#       endif

#       ifdef WDTCR
            typedef Register<YAAL_ADDR(WDTCR), reg8_t> Wdtcr;
#       endif

#       ifdef WDTCSR
            typedef Register<YAAL_ADDR(WDTCSR), reg8_t> Wdtcsr;
#       endif

#       ifdef XDIV
            typedef Register<YAAL_ADDR(XDIV), reg8_t> Xdiv;
#       endif

    }
}

#endif
