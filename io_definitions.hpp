#ifndef __YAAL_IO_DEFINITIONS_H__
#define __YAAL_IO_DEFINITIONS_H__ 1
// do not edit. genereted using io_definitions.sh

#include <avr/io.h>

namespace yaal {

#ifdef ADC
    typedef Register<YAAL_ADDR(ADC), uint16_t> Adc;
#endif

#ifdef ADCW
    typedef Register<YAAL_ADDR(ADCW), uint16_t> Adcw;
#endif

#ifdef ADRSLT
    typedef Register<YAAL_ADDR(ADRSLT), uint16_t> Adrslt;
#endif

#ifdef DAC
    typedef Register<YAAL_ADDR(DAC), uint16_t> Dac;
#endif

#ifdef DACVAL
    typedef Register<YAAL_ADDR(DACVAL), uint16_t> Dacval;
#endif

#ifdef EEAR
    typedef Register<YAAL_ADDR(EEAR), uint16_t> Eear;
#endif

#ifdef EXOCR1A
    typedef Register<YAAL_ADDR(EXOCR1A), uint16_t> Exocr1a;
#endif

#ifdef EXOCR1B
    typedef Register<YAAL_ADDR(EXOCR1B), uint16_t> Exocr1b;
#endif

#ifdef EXTCNT1
    typedef Register<YAAL_ADDR(EXTCNT1), uint16_t> Extcnt1;
#endif

#ifdef ICR0
    typedef Register<YAAL_ADDR(ICR0), uint16_t> Icr0;
#endif

#ifdef ICR1
    typedef Register<YAAL_ADDR(ICR1), uint16_t> Icr1;
#endif

#ifdef IPA
    typedef Register<YAAL_ADDR(IPA), uint16_t> Ipa;
#endif

#ifdef IPD
    typedef Register<YAAL_ADDR(IPD), uint16_t> Ipd;
#endif

#ifdef OCR0A
    typedef Register<YAAL_ADDR(OCR0A), uint16_t> Ocr0a;
#endif

#ifdef OCR0B
    typedef Register<YAAL_ADDR(OCR0B), uint16_t> Ocr0b;
#endif

#ifdef OCR0RA
    typedef Register<YAAL_ADDR(OCR0RA), uint16_t> Ocr0ra;
#endif

#ifdef OCR0RB
    typedef Register<YAAL_ADDR(OCR0RB), uint16_t> Ocr0rb;
#endif

#ifdef OCR0SB
    typedef Register<YAAL_ADDR(OCR0SB), uint16_t> Ocr0sb;
#endif

#ifdef OCR1A
    typedef Register<YAAL_ADDR(OCR1A), uint16_t> Ocr1a;
#endif

#ifdef OCR1B
    typedef Register<YAAL_ADDR(OCR1B), uint16_t> Ocr1b;
#endif

#ifdef OCR1
    typedef Register<YAAL_ADDR(OCR1), uint16_t> Ocr1;
#endif

#ifdef OCR2RA
    typedef Register<YAAL_ADDR(OCR2RA), uint16_t> Ocr2ra;
#endif

#ifdef OCR2RB
    typedef Register<YAAL_ADDR(OCR2RB), uint16_t> Ocr2rb;
#endif

#ifdef OCR2SB
    typedef Register<YAAL_ADDR(OCR2SB), uint16_t> Ocr2sb;
#endif

#ifdef OCRA1
    typedef Register<YAAL_ADDR(OCRA1), uint16_t> Ocra1;
#endif

#ifdef OCRB1
    typedef Register<YAAL_ADDR(OCRB1), uint16_t> Ocrb1;
#endif

#ifdef SP
    typedef Register<YAAL_ADDR(SP), uint16_t> Sp;
#endif

#ifdef TCNT0
    typedef Register<YAAL_ADDR(TCNT0), uint16_t> Tcnt0;
#endif

#ifdef TCNT1
    typedef Register<YAAL_ADDR(TCNT1), uint16_t> Tcnt1;
#endif

#ifdef ACSRA
    typedef Register<YAAL_ADDR(ACSRA), uint8_t> Acsra;
#endif

#ifdef ACSRB
    typedef Register<YAAL_ADDR(ACSRB), uint8_t> Acsrb;
#endif

#ifdef ACSR
    typedef Register<YAAL_ADDR(ACSR), uint8_t> Acsr;
#endif

#ifdef ADCSRA
    typedef Register<YAAL_ADDR(ADCSRA), uint8_t> Adcsra;
#endif

#ifdef ADCSRB
    typedef Register<YAAL_ADDR(ADCSRB), uint8_t> Adcsrb;
#endif

#ifdef ADCSR
    typedef Register<YAAL_ADDR(ADCSR), uint8_t> Adcsr;
#endif

#ifdef ADMUX
    typedef Register<YAAL_ADDR(ADMUX), uint8_t> Admux;
#endif

#ifdef AGPDDR
    typedef Register<YAAL_ADDR(AGPDDR), uint8_t> Agpddr;
#endif

#ifdef AGPPIN
    typedef Register<YAAL_ADDR(AGPPIN), uint8_t> Agppin;
#endif

#ifdef AGPPORT
    typedef Register<YAAL_ADDR(AGPPORT), uint8_t> Agpport;
#endif

#ifdef AMUXCTL
    typedef Register<YAAL_ADDR(AMUXCTL), uint8_t> Amuxctl;
#endif

#ifdef ASSR
    typedef Register<YAAL_ADDR(ASSR), uint8_t> Assr;
#endif

#ifdef B_DET
    typedef Register<YAAL_ADDR(B_DET), uint8_t> B_det;
#endif

#ifdef BGPDDR
    typedef Register<YAAL_ADDR(BGPDDR), uint8_t> Bgpddr;
#endif

#ifdef BGPPIN
    typedef Register<YAAL_ADDR(BGPPIN), uint8_t> Bgppin;
#endif

#ifdef BGPPORT
    typedef Register<YAAL_ADDR(BGPPORT), uint8_t> Bgpport;
#endif

#ifdef BODCR
    typedef Register<YAAL_ADDR(BODCR), uint8_t> Bodcr;
#endif

#ifdef BTCNT
    typedef Register<YAAL_ADDR(BTCNT), uint8_t> Btcnt;
#endif

#ifdef BTCR
    typedef Register<YAAL_ADDR(BTCR), uint8_t> Btcr;
#endif

#ifdef CCP
    typedef Register<YAAL_ADDR(CCP), uint8_t> Ccp;
#endif

#ifdef CGPDDR
    typedef Register<YAAL_ADDR(CGPDDR), uint8_t> Cgpddr;
#endif

#ifdef CGPPIN
    typedef Register<YAAL_ADDR(CGPPIN), uint8_t> Cgppin;
#endif

#ifdef CGPPORT
    typedef Register<YAAL_ADDR(CGPPORT), uint8_t> Cgpport;
#endif

#ifdef CLK_CNTR
    typedef Register<YAAL_ADDR(CLK_CNTR), uint8_t> Clk_cntr;
#endif

#ifdef CLKMSR
    typedef Register<YAAL_ADDR(CLKMSR), uint8_t> Clkmsr;
#endif

#ifdef CLKPR
    typedef Register<YAAL_ADDR(CLKPR), uint8_t> Clkpr;
#endif

#ifdef CLKPSR
    typedef Register<YAAL_ADDR(CLKPSR), uint8_t> Clkpsr;
#endif

#ifdef CMCR
    typedef Register<YAAL_ADDR(CMCR), uint8_t> Cmcr;
#endif

#ifdef CMIMR
    typedef Register<YAAL_ADDR(CMIMR), uint8_t> Cmimr;
#endif

#ifdef CMSR
    typedef Register<YAAL_ADDR(CMSR), uint8_t> Cmsr;
#endif

#ifdef DDRA
    typedef Register<YAAL_ADDR(DDRA), uint8_t> Ddra;
#endif

#ifdef DDRB
    typedef Register<YAAL_ADDR(DDRB), uint8_t> Ddrb;
#endif

#ifdef DDRC
    typedef Register<YAAL_ADDR(DDRC), uint8_t> Ddrc;
#endif

#ifdef DDRD
    typedef Register<YAAL_ADDR(DDRD), uint8_t> Ddrd;
#endif

#ifdef DDRE
    typedef Register<YAAL_ADDR(DDRE), uint8_t> Ddre;
#endif

#ifdef DDRF
    typedef Register<YAAL_ADDR(DDRF), uint8_t> Ddrf;
#endif

#ifdef DDRG
    typedef Register<YAAL_ADDR(DDRG), uint8_t> Ddrg;
#endif

#ifdef DEEARL
    typedef Register<YAAL_ADDR(DEEARL), uint8_t> Deearl;
#endif

#ifdef DEEAR
    typedef Register<YAAL_ADDR(DEEAR), uint8_t> Deear;
#endif

#ifdef DEECR
    typedef Register<YAAL_ADDR(DEECR), uint8_t> Deecr;
#endif

#ifdef DEEDR
    typedef Register<YAAL_ADDR(DEEDR), uint8_t> Deedr;
#endif

#ifdef DIDR0
    typedef Register<YAAL_ADDR(DIDR0), uint8_t> Didr0;
#endif

#ifdef DIDR1
    typedef Register<YAAL_ADDR(DIDR1), uint8_t> Didr1;
#endif

#ifdef DIDR
    typedef Register<YAAL_ADDR(DIDR), uint8_t> Didr;
#endif

#ifdef DT1A
    typedef Register<YAAL_ADDR(DT1A), uint8_t> Dt1a;
#endif

#ifdef DT1B
    typedef Register<YAAL_ADDR(DT1B), uint8_t> Dt1b;
#endif

#ifdef DT1
    typedef Register<YAAL_ADDR(DT1), uint8_t> Dt1;
#endif

#ifdef DTPS1
    typedef Register<YAAL_ADDR(DTPS1), uint8_t> Dtps1;
#endif

#ifdef DWDR
    typedef Register<YAAL_ADDR(DWDR), uint8_t> Dwdr;
#endif

#ifdef EECR
    typedef Register<YAAL_ADDR(EECR), uint8_t> Eecr;
#endif

#ifdef EEDR
    typedef Register<YAAL_ADDR(EEDR), uint8_t> Eedr;
#endif

#ifdef EICRA
    typedef Register<YAAL_ADDR(EICRA), uint8_t> Eicra;
#endif

#ifdef EICRB
    typedef Register<YAAL_ADDR(EICRB), uint8_t> Eicrb;
#endif

#ifdef EICR
    typedef Register<YAAL_ADDR(EICR), uint8_t> Eicr;
#endif

#ifdef EIFR
    typedef Register<YAAL_ADDR(EIFR), uint8_t> Eifr;
#endif

#ifdef EIMF
    typedef Register<YAAL_ADDR(EIMF), uint8_t> Eimf;
#endif

#ifdef EIMSK
    typedef Register<YAAL_ADDR(EIMSK), uint8_t> Eimsk;
#endif

#ifdef EIND
    typedef Register<YAAL_ADDR(EIND), uint8_t> Eind;
#endif

#ifdef EIRR
    typedef Register<YAAL_ADDR(EIRR), uint8_t> Eirr;
#endif

#ifdef EMCUCR
    typedef Register<YAAL_ADDR(EMCUCR), uint8_t> Emcucr;
#endif

#ifdef EXTCCR0
    typedef Register<YAAL_ADDR(EXTCCR0), uint8_t> Extccr0;
#endif

#ifdef EXTCCR1A
    typedef Register<YAAL_ADDR(EXTCCR1A), uint8_t> Extccr1a;
#endif

#ifdef EXTCCR1B
    typedef Register<YAAL_ADDR(EXTCCR1B), uint8_t> Extccr1b;
#endif

#ifdef EXTCNT
    typedef Register<YAAL_ADDR(EXTCNT), uint8_t> Extcnt;
#endif

#ifdef EXTIFR
    typedef Register<YAAL_ADDR(EXTIFR), uint8_t> Extifr;
#endif

#ifdef EXTIMSK
    typedef Register<YAAL_ADDR(EXTIMSK), uint8_t> Extimsk;
#endif

#ifdef FISCR
    typedef Register<YAAL_ADDR(FISCR), uint8_t> Fiscr;
#endif

#ifdef FISUA
    typedef Register<YAAL_ADDR(FISUA), uint8_t> Fisua;
#endif

#ifdef FISUB
    typedef Register<YAAL_ADDR(FISUB), uint8_t> Fisub;
#endif

#ifdef FISUC
    typedef Register<YAAL_ADDR(FISUC), uint8_t> Fisuc;
#endif

#ifdef FISUD
    typedef Register<YAAL_ADDR(FISUD), uint8_t> Fisud;
#endif

#ifdef FPGAD
    typedef Register<YAAL_ADDR(FPGAD), uint8_t> Fpgad;
#endif

#ifdef FPGAX
    typedef Register<YAAL_ADDR(FPGAX), uint8_t> Fpgax;
#endif

#ifdef FPGAY
    typedef Register<YAAL_ADDR(FPGAY), uint8_t> Fpgay;
#endif

#ifdef FPGAZ
    typedef Register<YAAL_ADDR(FPGAZ), uint8_t> Fpgaz;
#endif

#ifdef GICR
    typedef Register<YAAL_ADDR(GICR), uint8_t> Gicr;
#endif

#ifdef GIFR
    typedef Register<YAAL_ADDR(GIFR), uint8_t> Gifr;
#endif

#ifdef GIMSK
    typedef Register<YAAL_ADDR(GIMSK), uint8_t> Gimsk;
#endif

#ifdef GIPR
    typedef Register<YAAL_ADDR(GIPR), uint8_t> Gipr;
#endif

#ifdef GPIOR0
    typedef Register<YAAL_ADDR(GPIOR0), uint8_t> Gpior0;
#endif

#ifdef GPIOR1
    typedef Register<YAAL_ADDR(GPIOR1), uint8_t> Gpior1;
#endif

#ifdef GPIOR2
    typedef Register<YAAL_ADDR(GPIOR2), uint8_t> Gpior2;
#endif

#ifdef GPIOR3
    typedef Register<YAAL_ADDR(GPIOR3), uint8_t> Gpior3;
#endif

#ifdef GTCCR
    typedef Register<YAAL_ADDR(GTCCR), uint8_t> Gtccr;
#endif

#ifdef ICR
    typedef Register<YAAL_ADDR(ICR), uint8_t> Icr;
#endif

#ifdef IFR
    typedef Register<YAAL_ADDR(IFR), uint8_t> Ifr;
#endif

#ifdef IO_DATIN
    typedef Register<YAAL_ADDR(IO_DATIN), uint8_t> Io_datin;
#endif

#ifdef IO_DATOUT
    typedef Register<YAAL_ADDR(IO_DATOUT), uint8_t> Io_datout;
#endif

#ifdef IO_ENAB
    typedef Register<YAAL_ADDR(IO_ENAB), uint8_t> Io_enab;
#endif

#ifdef IPCR
    typedef Register<YAAL_ADDR(IPCR), uint8_t> Ipcr;
#endif

#ifdef IRDAMOD
    typedef Register<YAAL_ADDR(IRDAMOD), uint8_t> Irdamod;
#endif

#ifdef LFCDR
    typedef Register<YAAL_ADDR(LFCDR), uint8_t> Lfcdr;
#endif

#ifdef LFFR
    typedef Register<YAAL_ADDR(LFFR), uint8_t> Lffr;
#endif

#ifdef LFRB
    typedef Register<YAAL_ADDR(LFRB), uint8_t> Lfrb;
#endif

#ifdef LFRR
    typedef Register<YAAL_ADDR(LFRR), uint8_t> Lfrr;
#endif

#ifdef LOCKDET1
    typedef Register<YAAL_ADDR(LOCKDET1), uint8_t> Lockdet1;
#endif

#ifdef LOCKDET2
    typedef Register<YAAL_ADDR(LOCKDET2), uint8_t> Lockdet2;
#endif

#ifdef MCSR
    typedef Register<YAAL_ADDR(MCSR), uint8_t> Mcsr;
#endif

#ifdef MCUCR
    typedef Register<YAAL_ADDR(MCUCR), uint8_t> Mcucr;
#endif

#ifdef MCUCSR
    typedef Register<YAAL_ADDR(MCUCSR), uint8_t> Mcucsr;
#endif

#ifdef MCUCS
    typedef Register<YAAL_ADDR(MCUCS), uint8_t> Mcucs;
#endif

#ifdef MCUR
    typedef Register<YAAL_ADDR(MCUR), uint8_t> Mcur;
#endif

#ifdef MCUSR
    typedef Register<YAAL_ADDR(MCUSR), uint8_t> Mcusr;
#endif

#ifdef MODCR
    typedef Register<YAAL_ADDR(MODCR), uint8_t> Modcr;
#endif

#ifdef MONDR
    typedef Register<YAAL_ADDR(MONDR), uint8_t> Mondr;
#endif

#ifdef MSMCR
    typedef Register<YAAL_ADDR(MSMCR), uint8_t> Msmcr;
#endif

#ifdef MSPCR
    typedef Register<YAAL_ADDR(MSPCR), uint8_t> Mspcr;
#endif

#ifdef MSPDR
    typedef Register<YAAL_ADDR(MSPDR), uint8_t> Mspdr;
#endif

#ifdef MSPSR
    typedef Register<YAAL_ADDR(MSPSR), uint8_t> Mspsr;
#endif

#ifdef NVMCMD
    typedef Register<YAAL_ADDR(NVMCMD), uint8_t> Nvmcmd;
#endif

#ifdef NVMCSR
    typedef Register<YAAL_ADDR(NVMCSR), uint8_t> Nvmcsr;
#endif

#ifdef OCDR
    typedef Register<YAAL_ADDR(OCDR), uint8_t> Ocdr;
#endif

#ifdef OCR0
    typedef Register<YAAL_ADDR(OCR0), uint8_t> Ocr0;
#endif

#ifdef OCR1C
    typedef Register<YAAL_ADDR(OCR1C), uint8_t> Ocr1c;
#endif

#ifdef OCR1D
    typedef Register<YAAL_ADDR(OCR1D), uint8_t> Ocr1d;
#endif

#ifdef OCR2
    typedef Register<YAAL_ADDR(OCR2), uint8_t> Ocr2;
#endif

#ifdef OSCCAL
    typedef Register<YAAL_ADDR(OSCCAL), uint8_t> Osccal;
#endif

#ifdef OSICSR
    typedef Register<YAAL_ADDR(OSICSR), uint8_t> Osicsr;
#endif

#ifdef PACR
    typedef Register<YAAL_ADDR(PACR), uint8_t> Pacr;
#endif

#ifdef PCICR
    typedef Register<YAAL_ADDR(PCICR), uint8_t> Pcicr;
#endif

#ifdef PCIFR
    typedef Register<YAAL_ADDR(PCIFR), uint8_t> Pcifr;
#endif

#ifdef PCMSK0
    typedef Register<YAAL_ADDR(PCMSK0), uint8_t> Pcmsk0;
#endif

#ifdef PCMSK1
    typedef Register<YAAL_ADDR(PCMSK1), uint8_t> Pcmsk1;
#endif

#ifdef PCMSK2
    typedef Register<YAAL_ADDR(PCMSK2), uint8_t> Pcmsk2;
#endif

#ifdef PCMSK
    typedef Register<YAAL_ADDR(PCMSK), uint8_t> Pcmsk;
#endif

#ifdef PCNF0
    typedef Register<YAAL_ADDR(PCNF0), uint8_t> Pcnf0;
#endif

#ifdef PCNF2
    typedef Register<YAAL_ADDR(PCNF2), uint8_t> Pcnf2;
#endif

#ifdef PCTL0
    typedef Register<YAAL_ADDR(PCTL0), uint8_t> Pctl0;
#endif

#ifdef PCTL2
    typedef Register<YAAL_ADDR(PCTL2), uint8_t> Pctl2;
#endif

#ifdef PERIPHEN
    typedef Register<YAAL_ADDR(PERIPHEN), uint8_t> Periphen;
#endif

#ifdef PIFR0
    typedef Register<YAAL_ADDR(PIFR0), uint8_t> Pifr0;
#endif

#ifdef PIFR2
    typedef Register<YAAL_ADDR(PIFR2), uint8_t> Pifr2;
#endif

#ifdef PIM0
    typedef Register<YAAL_ADDR(PIM0), uint8_t> Pim0;
#endif

#ifdef PIM2
    typedef Register<YAAL_ADDR(PIM2), uint8_t> Pim2;
#endif

#ifdef PINA
    typedef Register<YAAL_ADDR(PINA), uint8_t> Pina;
#endif

#ifdef PINB
    typedef Register<YAAL_ADDR(PINB), uint8_t> Pinb;
#endif

#ifdef PINC
    typedef Register<YAAL_ADDR(PINC), uint8_t> Pinc;
#endif

#ifdef PIND
    typedef Register<YAAL_ADDR(PIND), uint8_t> Pind;
#endif

#ifdef PINE
    typedef Register<YAAL_ADDR(PINE), uint8_t> Pine;
#endif

#ifdef PINF
    typedef Register<YAAL_ADDR(PINF), uint8_t> Pinf;
#endif

#ifdef PING
    typedef Register<YAAL_ADDR(PING), uint8_t> Ping;
#endif

#ifdef PLLCSR
    typedef Register<YAAL_ADDR(PLLCSR), uint8_t> Pllcsr;
#endif

#ifdef PLLFRQ
    typedef Register<YAAL_ADDR(PLLFRQ), uint8_t> Pllfrq;
#endif

#ifdef PORTA
    typedef Register<YAAL_ADDR(PORTA), uint8_t> Porta;
#endif

#ifdef PORTB
    typedef Register<YAAL_ADDR(PORTB), uint8_t> Portb;
#endif

#ifdef PORTCR
    typedef Register<YAAL_ADDR(PORTCR), uint8_t> Portcr;
#endif

#ifdef PORTC
    typedef Register<YAAL_ADDR(PORTC), uint8_t> Portc;
#endif

#ifdef PORTD
    typedef Register<YAAL_ADDR(PORTD), uint8_t> Portd;
#endif

#ifdef PORTE
    typedef Register<YAAL_ADDR(PORTE), uint8_t> Porte;
#endif

#ifdef PORTF
    typedef Register<YAAL_ADDR(PORTF), uint8_t> Portf;
#endif

#ifdef PORTG
    typedef Register<YAAL_ADDR(PORTG), uint8_t> Portg;
#endif

#ifdef PRELD
    typedef Register<YAAL_ADDR(PRELD), uint8_t> Preld;
#endif

#ifdef PRR
    typedef Register<YAAL_ADDR(PRR), uint8_t> Prr;
#endif

#ifdef PUEA
    typedef Register<YAAL_ADDR(PUEA), uint8_t> Puea;
#endif

#ifdef PUEB
    typedef Register<YAAL_ADDR(PUEB), uint8_t> Pueb;
#endif

#ifdef PUEC
    typedef Register<YAAL_ADDR(PUEC), uint8_t> Puec;
#endif

#ifdef PWR_ATTEN
    typedef Register<YAAL_ADDR(PWR_ATTEN), uint8_t> Pwr_atten;
#endif

#ifdef QTCSR
    typedef Register<YAAL_ADDR(QTCSR), uint8_t> Qtcsr;
#endif

#ifdef RAMAR
    typedef Register<YAAL_ADDR(RAMAR), uint8_t> Ramar;
#endif

#ifdef RAMDR
    typedef Register<YAAL_ADDR(RAMDR), uint8_t> Ramdr;
#endif

#ifdef RAMPZ
    typedef Register<YAAL_ADDR(RAMPZ), uint8_t> Rampz;
#endif

#ifdef RSTFLR
    typedef Register<YAAL_ADDR(RSTFLR), uint8_t> Rstflr;
#endif

#ifdef RXB
    typedef Register<YAAL_ADDR(RXB), uint8_t> Rxb;
#endif

#ifdef SCCR
    typedef Register<YAAL_ADDR(SCCR), uint8_t> Sccr;
#endif

#ifdef SCR
    typedef Register<YAAL_ADDR(SCR), uint8_t> Scr;
#endif

#ifdef SFIOR
    typedef Register<YAAL_ADDR(SFIOR), uint8_t> Sfior;
#endif

#ifdef SFTCR
    typedef Register<YAAL_ADDR(SFTCR), uint8_t> Sftcr;
#endif

#ifdef SMCR
    typedef Register<YAAL_ADDR(SMCR), uint8_t> Smcr;
#endif

#ifdef SPCR0
    typedef Register<YAAL_ADDR(SPCR0), uint8_t> Spcr0;
#endif

#ifdef SPCR
    typedef Register<YAAL_ADDR(SPCR), uint8_t> Spcr;
#endif

#ifdef SPDR0
    typedef Register<YAAL_ADDR(SPDR0), uint8_t> Spdr0;
#endif

#ifdef SPDR
    typedef Register<YAAL_ADDR(SPDR), uint8_t> Spdr;
#endif

#ifdef SPMCR
    typedef Register<YAAL_ADDR(SPMCR), uint8_t> Spmcr;
#endif

#ifdef SPMCSR
    typedef Register<YAAL_ADDR(SPMCSR), uint8_t> Spmcsr;
#endif

#ifdef SPSR0
    typedef Register<YAAL_ADDR(SPSR0), uint8_t> Spsr0;
#endif

#ifdef SPSR
    typedef Register<YAAL_ADDR(SPSR), uint8_t> Spsr;
#endif

#ifdef SREG
    typedef Register<YAAL_ADDR(SREG), uint8_t> Sreg;
#endif

#ifdef SSFR
    typedef Register<YAAL_ADDR(SSFR), uint8_t> Ssfr;
#endif

#ifdef SVCR
    typedef Register<YAAL_ADDR(SVCR), uint8_t> Svcr;
#endif

#ifdef T0CR
    typedef Register<YAAL_ADDR(T0CR), uint8_t> T0cr;
#endif

#ifdef T10IFR
    typedef Register<YAAL_ADDR(T10IFR), uint8_t> T10ifr;
#endif

#ifdef T1CR
    typedef Register<YAAL_ADDR(T1CR), uint8_t> T1cr;
#endif

#ifdef T2CRA
    typedef Register<YAAL_ADDR(T2CRA), uint8_t> T2cra;
#endif

#ifdef T2CRB
    typedef Register<YAAL_ADDR(T2CRB), uint8_t> T2crb;
#endif

#ifdef T2IFR
    typedef Register<YAAL_ADDR(T2IFR), uint8_t> T2ifr;
#endif

#ifdef T2MDR
    typedef Register<YAAL_ADDR(T2MDR), uint8_t> T2mdr;
#endif

#ifdef T3CRA
    typedef Register<YAAL_ADDR(T3CRA), uint8_t> T3cra;
#endif

#ifdef T3IFR
    typedef Register<YAAL_ADDR(T3IFR), uint8_t> T3ifr;
#endif

#ifdef TC1H
    typedef Register<YAAL_ADDR(TC1H), uint8_t> Tc1h;
#endif

#ifdef TCCR0A
    typedef Register<YAAL_ADDR(TCCR0A), uint8_t> Tccr0a;
#endif

#ifdef TCCR0B
    typedef Register<YAAL_ADDR(TCCR0B), uint8_t> Tccr0b;
#endif

#ifdef TCCR0C
    typedef Register<YAAL_ADDR(TCCR0C), uint8_t> Tccr0c;
#endif

#ifdef TCCR0
    typedef Register<YAAL_ADDR(TCCR0), uint8_t> Tccr0;
#endif

#ifdef TCCR1A
    typedef Register<YAAL_ADDR(TCCR1A), uint8_t> Tccr1a;
#endif

#ifdef TCCR1B
    typedef Register<YAAL_ADDR(TCCR1B), uint8_t> Tccr1b;
#endif

#ifdef TCCR1C
    typedef Register<YAAL_ADDR(TCCR1C), uint8_t> Tccr1c;
#endif

#ifdef TCCR1D
    typedef Register<YAAL_ADDR(TCCR1D), uint8_t> Tccr1d;
#endif

#ifdef TCCR1E
    typedef Register<YAAL_ADDR(TCCR1E), uint8_t> Tccr1e;
#endif

#ifdef TCCR1
    typedef Register<YAAL_ADDR(TCCR1), uint8_t> Tccr1;
#endif

#ifdef TCCR2
    typedef Register<YAAL_ADDR(TCCR2), uint8_t> Tccr2;
#endif

#ifdef TCNT2
    typedef Register<YAAL_ADDR(TCNT2), uint8_t> Tcnt2;
#endif

#ifdef TIFR0
    typedef Register<YAAL_ADDR(TIFR0), uint8_t> Tifr0;
#endif

#ifdef TIFR1
    typedef Register<YAAL_ADDR(TIFR1), uint8_t> Tifr1;
#endif

#ifdef TIFR2
    typedef Register<YAAL_ADDR(TIFR2), uint8_t> Tifr2;
#endif

#ifdef TIFR3
    typedef Register<YAAL_ADDR(TIFR3), uint8_t> Tifr3;
#endif

#ifdef TIFR4
    typedef Register<YAAL_ADDR(TIFR4), uint8_t> Tifr4;
#endif

#ifdef TIFR5
    typedef Register<YAAL_ADDR(TIFR5), uint8_t> Tifr5;
#endif

#ifdef TIFR
    typedef Register<YAAL_ADDR(TIFR), uint8_t> Tifr;
#endif

#ifdef TIMSK0
    typedef Register<YAAL_ADDR(TIMSK0), uint8_t> Timsk0;
#endif

#ifdef TIMSK1
    typedef Register<YAAL_ADDR(TIMSK1), uint8_t> Timsk1;
#endif

#ifdef TIMSK
    typedef Register<YAAL_ADDR(TIMSK), uint8_t> Timsk;
#endif

#ifdef TWAR
    typedef Register<YAAL_ADDR(TWAR), uint8_t> Twar;
#endif

#ifdef TWBR
    typedef Register<YAAL_ADDR(TWBR), uint8_t> Twbr;
#endif

#ifdef TWCR
    typedef Register<YAAL_ADDR(TWCR), uint8_t> Twcr;
#endif

#ifdef TWDR
    typedef Register<YAAL_ADDR(TWDR), uint8_t> Twdr;
#endif

#ifdef TWSAM
    typedef Register<YAAL_ADDR(TWSAM), uint8_t> Twsam;
#endif

#ifdef TWSA
    typedef Register<YAAL_ADDR(TWSA), uint8_t> Twsa;
#endif

#ifdef TWSCRA
    typedef Register<YAAL_ADDR(TWSCRA), uint8_t> Twscra;
#endif

#ifdef TWSCRB
    typedef Register<YAAL_ADDR(TWSCRB), uint8_t> Twscrb;
#endif

#ifdef TWSD
    typedef Register<YAAL_ADDR(TWSD), uint8_t> Twsd;
#endif

#ifdef TWSR
    typedef Register<YAAL_ADDR(TWSR), uint8_t> Twsr;
#endif

#ifdef TWSSRA
    typedef Register<YAAL_ADDR(TWSSRA), uint8_t> Twssra;
#endif

#ifdef TXB
    typedef Register<YAAL_ADDR(TXB), uint8_t> Txb;
#endif

#ifdef TX_CNTL
    typedef Register<YAAL_ADDR(TX_CNTL), uint8_t> Tx_cntl;
#endif

#ifdef UBRR0H
    typedef Register<YAAL_ADDR(UBRR0H), uint8_t> Ubrr0h;
#endif

#ifdef UBRR0L
    typedef Register<YAAL_ADDR(UBRR0L), uint8_t> Ubrr0l;
#endif

#ifdef UBRR0
    typedef Register<YAAL_ADDR(UBRR0), uint8_t> Ubrr0;
#endif

#ifdef UBRR1H
    typedef Register<YAAL_ADDR(UBRR1H), uint8_t> Ubrr1h;
#endif

#ifdef UBRR1L
    typedef Register<YAAL_ADDR(UBRR1L), uint8_t> Ubrr1l;
#endif

#ifdef UBRR1
    typedef Register<YAAL_ADDR(UBRR1), uint8_t> Ubrr1;
#endif

#ifdef UBRRHI
    typedef Register<YAAL_ADDR(UBRRHI), uint8_t> Ubrrhi;
#endif

#ifdef UBRRH
    typedef Register<YAAL_ADDR(UBRRH), uint8_t> Ubrrh;
#endif

#ifdef UBRRLO
    typedef Register<YAAL_ADDR(UBRRLO), uint8_t> Ubrrlo;
#endif

#ifdef UBRRL
    typedef Register<YAAL_ADDR(UBRRL), uint8_t> Ubrrl;
#endif

#ifdef UBRR
    typedef Register<YAAL_ADDR(UBRR), uint8_t> Ubrr;
#endif

#ifdef UCRA
    typedef Register<YAAL_ADDR(UCRA), uint8_t> Ucra;
#endif

#ifdef UCRB
    typedef Register<YAAL_ADDR(UCRB), uint8_t> Ucrb;
#endif

#ifdef UCR
    typedef Register<YAAL_ADDR(UCR), uint8_t> Ucr;
#endif

#ifdef UCSR0A
    typedef Register<YAAL_ADDR(UCSR0A), uint8_t> Ucsr0a;
#endif

#ifdef UCSR0B
    typedef Register<YAAL_ADDR(UCSR0B), uint8_t> Ucsr0b;
#endif

#ifdef UCSR0C
    typedef Register<YAAL_ADDR(UCSR0C), uint8_t> Ucsr0c;
#endif

#ifdef UCSR1A
    typedef Register<YAAL_ADDR(UCSR1A), uint8_t> Ucsr1a;
#endif

#ifdef UCSR1B
    typedef Register<YAAL_ADDR(UCSR1B), uint8_t> Ucsr1b;
#endif

#ifdef UCSR1C
    typedef Register<YAAL_ADDR(UCSR1C), uint8_t> Ucsr1c;
#endif

#ifdef UCSRA
    typedef Register<YAAL_ADDR(UCSRA), uint8_t> Ucsra;
#endif

#ifdef UCSRB
    typedef Register<YAAL_ADDR(UCSRB), uint8_t> Ucsrb;
#endif

#ifdef UCSRC
    typedef Register<YAAL_ADDR(UCSRC), uint8_t> Ucsrc;
#endif

#ifdef UDR0
    typedef Register<YAAL_ADDR(UDR0), uint8_t> Udr0;
#endif

#ifdef UDR1
    typedef Register<YAAL_ADDR(UDR1), uint8_t> Udr1;
#endif

#ifdef UDR
    typedef Register<YAAL_ADDR(UDR), uint8_t> Udr;
#endif

#ifdef USIBR
    typedef Register<YAAL_ADDR(USIBR), uint8_t> Usibr;
#endif

#ifdef USICR
    typedef Register<YAAL_ADDR(USICR), uint8_t> Usicr;
#endif

#ifdef USIDR
    typedef Register<YAAL_ADDR(USIDR), uint8_t> Usidr;
#endif

#ifdef USIPP
    typedef Register<YAAL_ADDR(USIPP), uint8_t> Usipp;
#endif

#ifdef USISR
    typedef Register<YAAL_ADDR(USISR), uint8_t> Usisr;
#endif

#ifdef USPCR
    typedef Register<YAAL_ADDR(USPCR), uint8_t> Uspcr;
#endif

#ifdef USPDR
    typedef Register<YAAL_ADDR(USPDR), uint8_t> Uspdr;
#endif

#ifdef USPSR
    typedef Register<YAAL_ADDR(USPSR), uint8_t> Uspsr;
#endif

#ifdef USR
    typedef Register<YAAL_ADDR(USR), uint8_t> Usr;
#endif

#ifdef VCOTUNE
    typedef Register<YAAL_ADDR(VCOTUNE), uint8_t> Vcotune;
#endif

#ifdef VLMCSR
    typedef Register<YAAL_ADDR(VLMCSR), uint8_t> Vlmcsr;
#endif

#ifdef VMCSR
    typedef Register<YAAL_ADDR(VMCSR), uint8_t> Vmcsr;
#endif

#ifdef WDTCR
    typedef Register<YAAL_ADDR(WDTCR), uint8_t> Wdtcr;
#endif

#ifdef WDTCSR
    typedef Register<YAAL_ADDR(WDTCSR), uint8_t> Wdtcsr;
#endif

#ifdef XDIV
    typedef Register<YAAL_ADDR(XDIV), uint8_t> Xdiv;
#endif

// ports
#if defined(PORTA) && defined(DDRA) && defined(PINA)
    typedef Port<Porta, Ddra, Pina> PortA;
# if defined(PORTA0) || defined(PA0)
    typedef Pin<PortA, 0> PortA0;
# endif
# if defined(PORTA1) || defined(PA1)
    typedef Pin<PortA, 1> PortA1;
# endif
# if defined(PORTA2) || defined(PA2)
    typedef Pin<PortA, 2> PortA2;
# endif
# if defined(PORTA3) || defined(PA3)
    typedef Pin<PortA, 3> PortA3;
# endif
# if defined(PORTA4) || defined(PA4)
    typedef Pin<PortA, 4> PortA4;
# endif
# if defined(PORTA5) || defined(PA5)
    typedef Pin<PortA, 5> PortA5;
# endif
# if defined(PORTA6) || defined(PA6)
    typedef Pin<PortA, 6> PortA6;
# endif
# if defined(PORTA7) || defined(PA7)
    typedef Pin<PortA, 7> PortA7;
# endif
#endif

#if defined(PORTB) && defined(DDRB) && defined(PINB)
    typedef Port<Portb, Ddrb, Pinb> PortB;
# if defined(PORTB0) || defined(PB0)
    typedef Pin<PortB, 0> PortB0;
# endif
# if defined(PORTB1) || defined(PB1)
    typedef Pin<PortB, 1> PortB1;
# endif
# if defined(PORTB2) || defined(PB2)
    typedef Pin<PortB, 2> PortB2;
# endif
# if defined(PORTB3) || defined(PB3)
    typedef Pin<PortB, 3> PortB3;
# endif
# if defined(PORTB4) || defined(PB4)
    typedef Pin<PortB, 4> PortB4;
# endif
# if defined(PORTB5) || defined(PB5)
    typedef Pin<PortB, 5> PortB5;
# endif
# if defined(PORTB6) || defined(PB6)
    typedef Pin<PortB, 6> PortB6;
# endif
# if defined(PORTB7) || defined(PB7)
    typedef Pin<PortB, 7> PortB7;
# endif
#endif

#if defined(PORTC) && defined(DDRC) && defined(PINC)
    typedef Port<Portc, Ddrc, Pinc> PortC;
# if defined(PORTC0) || defined(PC0)
    typedef Pin<PortC, 0> PortC0;
# endif
# if defined(PORTC1) || defined(PC1)
    typedef Pin<PortC, 1> PortC1;
# endif
# if defined(PORTC2) || defined(PC2)
    typedef Pin<PortC, 2> PortC2;
# endif
# if defined(PORTC3) || defined(PC3)
    typedef Pin<PortC, 3> PortC3;
# endif
# if defined(PORTC4) || defined(PC4)
    typedef Pin<PortC, 4> PortC4;
# endif
# if defined(PORTC5) || defined(PC5)
    typedef Pin<PortC, 5> PortC5;
# endif
# if defined(PORTC6) || defined(PC6)
    typedef Pin<PortC, 6> PortC6;
# endif
# if defined(PORTC7) || defined(PC7)
    typedef Pin<PortC, 7> PortC7;
# endif
#endif

#if defined(PORTD) && defined(DDRD) && defined(PIND)
    typedef Port<Portd, Ddrd, Pind> PortD;
# if defined(PORTD0) || defined(PD0)
    typedef Pin<PortD, 0> PortD0;
# endif
# if defined(PORTD1) || defined(PD1)
    typedef Pin<PortD, 1> PortD1;
# endif
# if defined(PORTD2) || defined(PD2)
    typedef Pin<PortD, 2> PortD2;
# endif
# if defined(PORTD3) || defined(PD3)
    typedef Pin<PortD, 3> PortD3;
# endif
# if defined(PORTD4) || defined(PD4)
    typedef Pin<PortD, 4> PortD4;
# endif
# if defined(PORTD5) || defined(PD5)
    typedef Pin<PortD, 5> PortD5;
# endif
# if defined(PORTD6) || defined(PD6)
    typedef Pin<PortD, 6> PortD6;
# endif
# if defined(PORTD7) || defined(PD7)
    typedef Pin<PortD, 7> PortD7;
# endif
#endif

#if defined(PORTE) && defined(DDRE) && defined(PINE)
    typedef Port<Porte, Ddre, Pine> PortE;
# if defined(PORTE0) || defined(PE0)
    typedef Pin<PortE, 0> PortE0;
# endif
# if defined(PORTE1) || defined(PE1)
    typedef Pin<PortE, 1> PortE1;
# endif
# if defined(PORTE2) || defined(PE2)
    typedef Pin<PortE, 2> PortE2;
# endif
# if defined(PORTE3) || defined(PE3)
    typedef Pin<PortE, 3> PortE3;
# endif
# if defined(PORTE4) || defined(PE4)
    typedef Pin<PortE, 4> PortE4;
# endif
# if defined(PORTE5) || defined(PE5)
    typedef Pin<PortE, 5> PortE5;
# endif
# if defined(PORTE6) || defined(PE6)
    typedef Pin<PortE, 6> PortE6;
# endif
# if defined(PORTE7) || defined(PE7)
    typedef Pin<PortE, 7> PortE7;
# endif
#endif

#if defined(PORTF) && defined(DDRF) && defined(PINF)
    typedef Port<Portf, Ddrf, Pinf> PortF;
# if defined(PORTF0) || defined(PF0)
    typedef Pin<PortF, 0> PortF0;
# endif
# if defined(PORTF1) || defined(PF1)
    typedef Pin<PortF, 1> PortF1;
# endif
# if defined(PORTF2) || defined(PF2)
    typedef Pin<PortF, 2> PortF2;
# endif
# if defined(PORTF3) || defined(PF3)
    typedef Pin<PortF, 3> PortF3;
# endif
# if defined(PORTF4) || defined(PF4)
    typedef Pin<PortF, 4> PortF4;
# endif
# if defined(PORTF5) || defined(PF5)
    typedef Pin<PortF, 5> PortF5;
# endif
# if defined(PORTF6) || defined(PF6)
    typedef Pin<PortF, 6> PortF6;
# endif
# if defined(PORTF7) || defined(PF7)
    typedef Pin<PortF, 7> PortF7;
# endif
#endif

#if defined(PORTG) && defined(DDRG) && defined(PING)
    typedef Port<Portg, Ddrg, Ping> PortG;
# if defined(PORTG0) || defined(PG0)
    typedef Pin<PortG, 0> PortG0;
# endif
# if defined(PORTG1) || defined(PG1)
    typedef Pin<PortG, 1> PortG1;
# endif
# if defined(PORTG2) || defined(PG2)
    typedef Pin<PortG, 2> PortG2;
# endif
# if defined(PORTG3) || defined(PG3)
    typedef Pin<PortG, 3> PortG3;
# endif
# if defined(PORTG4) || defined(PG4)
    typedef Pin<PortG, 4> PortG4;
# endif
# if defined(PORTG5) || defined(PG5)
    typedef Pin<PortG, 5> PortG5;
# endif
# if defined(PORTG6) || defined(PG6)
    typedef Pin<PortG, 6> PortG6;
# endif
# if defined(PORTG7) || defined(PG7)
    typedef Pin<PortG, 7> PortG7;
# endif
#endif

#if defined(PORTH) && defined(DDRH) && defined(PINH)
    typedef Port<Porth, Ddrh, Pinh> PortH;
# if defined(PORTH0) || defined(PH0)
    typedef Pin<PortH, 0> PortH0;
# endif
# if defined(PORTH1) || defined(PH1)
    typedef Pin<PortH, 1> PortH1;
# endif
# if defined(PORTH2) || defined(PH2)
    typedef Pin<PortH, 2> PortH2;
# endif
# if defined(PORTH3) || defined(PH3)
    typedef Pin<PortH, 3> PortH3;
# endif
# if defined(PORTH4) || defined(PH4)
    typedef Pin<PortH, 4> PortH4;
# endif
# if defined(PORTH5) || defined(PH5)
    typedef Pin<PortH, 5> PortH5;
# endif
# if defined(PORTH6) || defined(PH6)
    typedef Pin<PortH, 6> PortH6;
# endif
# if defined(PORTH7) || defined(PH7)
    typedef Pin<PortH, 7> PortH7;
# endif
#endif

#if defined(PORTI) && defined(DDRI) && defined(PINI)
    typedef Port<Porti, Ddri, Pini> PortI;
# if defined(PORTI0) || defined(PI0)
    typedef Pin<PortI, 0> PortI0;
# endif
# if defined(PORTI1) || defined(PI1)
    typedef Pin<PortI, 1> PortI1;
# endif
# if defined(PORTI2) || defined(PI2)
    typedef Pin<PortI, 2> PortI2;
# endif
# if defined(PORTI3) || defined(PI3)
    typedef Pin<PortI, 3> PortI3;
# endif
# if defined(PORTI4) || defined(PI4)
    typedef Pin<PortI, 4> PortI4;
# endif
# if defined(PORTI5) || defined(PI5)
    typedef Pin<PortI, 5> PortI5;
# endif
# if defined(PORTI6) || defined(PI6)
    typedef Pin<PortI, 6> PortI6;
# endif
# if defined(PORTI7) || defined(PI7)
    typedef Pin<PortI, 7> PortI7;
# endif
#endif

#if defined(PORTJ) && defined(DDRJ) && defined(PINJ)
    typedef Port<Portj, Ddrj, Pinj> PortJ;
# if defined(PORTJ0) || defined(PJ0)
    typedef Pin<PortJ, 0> PortJ0;
# endif
# if defined(PORTJ1) || defined(PJ1)
    typedef Pin<PortJ, 1> PortJ1;
# endif
# if defined(PORTJ2) || defined(PJ2)
    typedef Pin<PortJ, 2> PortJ2;
# endif
# if defined(PORTJ3) || defined(PJ3)
    typedef Pin<PortJ, 3> PortJ3;
# endif
# if defined(PORTJ4) || defined(PJ4)
    typedef Pin<PortJ, 4> PortJ4;
# endif
# if defined(PORTJ5) || defined(PJ5)
    typedef Pin<PortJ, 5> PortJ5;
# endif
# if defined(PORTJ6) || defined(PJ6)
    typedef Pin<PortJ, 6> PortJ6;
# endif
# if defined(PORTJ7) || defined(PJ7)
    typedef Pin<PortJ, 7> PortJ7;
# endif
#endif

#if defined(PORTK) && defined(DDRK) && defined(PINK)
    typedef Port<Portk, Ddrk, Pink> PortK;
# if defined(PORTK0) || defined(PK0)
    typedef Pin<PortK, 0> PortK0;
# endif
# if defined(PORTK1) || defined(PK1)
    typedef Pin<PortK, 1> PortK1;
# endif
# if defined(PORTK2) || defined(PK2)
    typedef Pin<PortK, 2> PortK2;
# endif
# if defined(PORTK3) || defined(PK3)
    typedef Pin<PortK, 3> PortK3;
# endif
# if defined(PORTK4) || defined(PK4)
    typedef Pin<PortK, 4> PortK4;
# endif
# if defined(PORTK5) || defined(PK5)
    typedef Pin<PortK, 5> PortK5;
# endif
# if defined(PORTK6) || defined(PK6)
    typedef Pin<PortK, 6> PortK6;
# endif
# if defined(PORTK7) || defined(PK7)
    typedef Pin<PortK, 7> PortK7;
# endif
#endif

#if defined(PORTL) && defined(DDRL) && defined(PINL)
    typedef Port<Portl, Ddrl, Pinl> PortL;
# if defined(PORTL0) || defined(PL0)
    typedef Pin<PortL, 0> PortL0;
# endif
# if defined(PORTL1) || defined(PL1)
    typedef Pin<PortL, 1> PortL1;
# endif
# if defined(PORTL2) || defined(PL2)
    typedef Pin<PortL, 2> PortL2;
# endif
# if defined(PORTL3) || defined(PL3)
    typedef Pin<PortL, 3> PortL3;
# endif
# if defined(PORTL4) || defined(PL4)
    typedef Pin<PortL, 4> PortL4;
# endif
# if defined(PORTL5) || defined(PL5)
    typedef Pin<PortL, 5> PortL5;
# endif
# if defined(PORTL6) || defined(PL6)
    typedef Pin<PortL, 6> PortL6;
# endif
# if defined(PORTL7) || defined(PL7)
    typedef Pin<PortL, 7> PortL7;
# endif
#endif

#if defined(PORTM) && defined(DDRM) && defined(PINM)
    typedef Port<Portm, Ddrm, Pinm> PortM;
# if defined(PORTM0) || defined(PM0)
    typedef Pin<PortM, 0> PortM0;
# endif
# if defined(PORTM1) || defined(PM1)
    typedef Pin<PortM, 1> PortM1;
# endif
# if defined(PORTM2) || defined(PM2)
    typedef Pin<PortM, 2> PortM2;
# endif
# if defined(PORTM3) || defined(PM3)
    typedef Pin<PortM, 3> PortM3;
# endif
# if defined(PORTM4) || defined(PM4)
    typedef Pin<PortM, 4> PortM4;
# endif
# if defined(PORTM5) || defined(PM5)
    typedef Pin<PortM, 5> PortM5;
# endif
# if defined(PORTM6) || defined(PM6)
    typedef Pin<PortM, 6> PortM6;
# endif
# if defined(PORTM7) || defined(PM7)
    typedef Pin<PortM, 7> PortM7;
# endif
#endif

#if defined(PORTN) && defined(DDRN) && defined(PINN)
    typedef Port<Portn, Ddrn, Pinn> PortN;
# if defined(PORTN0) || defined(PN0)
    typedef Pin<PortN, 0> PortN0;
# endif
# if defined(PORTN1) || defined(PN1)
    typedef Pin<PortN, 1> PortN1;
# endif
# if defined(PORTN2) || defined(PN2)
    typedef Pin<PortN, 2> PortN2;
# endif
# if defined(PORTN3) || defined(PN3)
    typedef Pin<PortN, 3> PortN3;
# endif
# if defined(PORTN4) || defined(PN4)
    typedef Pin<PortN, 4> PortN4;
# endif
# if defined(PORTN5) || defined(PN5)
    typedef Pin<PortN, 5> PortN5;
# endif
# if defined(PORTN6) || defined(PN6)
    typedef Pin<PortN, 6> PortN6;
# endif
# if defined(PORTN7) || defined(PN7)
    typedef Pin<PortN, 7> PortN7;
# endif
#endif

#if defined(PORTO) && defined(DDRO) && defined(PINO)
    typedef Port<Porto, Ddro, Pino> PortO;
# if defined(PORTO0) || defined(PO0)
    typedef Pin<PortO, 0> PortO0;
# endif
# if defined(PORTO1) || defined(PO1)
    typedef Pin<PortO, 1> PortO1;
# endif
# if defined(PORTO2) || defined(PO2)
    typedef Pin<PortO, 2> PortO2;
# endif
# if defined(PORTO3) || defined(PO3)
    typedef Pin<PortO, 3> PortO3;
# endif
# if defined(PORTO4) || defined(PO4)
    typedef Pin<PortO, 4> PortO4;
# endif
# if defined(PORTO5) || defined(PO5)
    typedef Pin<PortO, 5> PortO5;
# endif
# if defined(PORTO6) || defined(PO6)
    typedef Pin<PortO, 6> PortO6;
# endif
# if defined(PORTO7) || defined(PO7)
    typedef Pin<PortO, 7> PortO7;
# endif
#endif

#if defined(PORTP) && defined(DDRP) && defined(PINP)
    typedef Port<Portp, Ddrp, Pinp> PortP;
# if defined(PORTP0) || defined(PP0)
    typedef Pin<PortP, 0> PortP0;
# endif
# if defined(PORTP1) || defined(PP1)
    typedef Pin<PortP, 1> PortP1;
# endif
# if defined(PORTP2) || defined(PP2)
    typedef Pin<PortP, 2> PortP2;
# endif
# if defined(PORTP3) || defined(PP3)
    typedef Pin<PortP, 3> PortP3;
# endif
# if defined(PORTP4) || defined(PP4)
    typedef Pin<PortP, 4> PortP4;
# endif
# if defined(PORTP5) || defined(PP5)
    typedef Pin<PortP, 5> PortP5;
# endif
# if defined(PORTP6) || defined(PP6)
    typedef Pin<PortP, 6> PortP6;
# endif
# if defined(PORTP7) || defined(PP7)
    typedef Pin<PortP, 7> PortP7;
# endif
#endif

#if defined(PORTQ) && defined(DDRQ) && defined(PINQ)
    typedef Port<Portq, Ddrq, Pinq> PortQ;
# if defined(PORTQ0) || defined(PQ0)
    typedef Pin<PortQ, 0> PortQ0;
# endif
# if defined(PORTQ1) || defined(PQ1)
    typedef Pin<PortQ, 1> PortQ1;
# endif
# if defined(PORTQ2) || defined(PQ2)
    typedef Pin<PortQ, 2> PortQ2;
# endif
# if defined(PORTQ3) || defined(PQ3)
    typedef Pin<PortQ, 3> PortQ3;
# endif
# if defined(PORTQ4) || defined(PQ4)
    typedef Pin<PortQ, 4> PortQ4;
# endif
# if defined(PORTQ5) || defined(PQ5)
    typedef Pin<PortQ, 5> PortQ5;
# endif
# if defined(PORTQ6) || defined(PQ6)
    typedef Pin<PortQ, 6> PortQ6;
# endif
# if defined(PORTQ7) || defined(PQ7)
    typedef Pin<PortQ, 7> PortQ7;
# endif
#endif

#if defined(PORTR) && defined(DDRR) && defined(PINR)
    typedef Port<Portr, Ddrr, Pinr> PortR;
# if defined(PORTR0) || defined(PR0)
    typedef Pin<PortR, 0> PortR0;
# endif
# if defined(PORTR1) || defined(PR1)
    typedef Pin<PortR, 1> PortR1;
# endif
# if defined(PORTR2) || defined(PR2)
    typedef Pin<PortR, 2> PortR2;
# endif
# if defined(PORTR3) || defined(PR3)
    typedef Pin<PortR, 3> PortR3;
# endif
# if defined(PORTR4) || defined(PR4)
    typedef Pin<PortR, 4> PortR4;
# endif
# if defined(PORTR5) || defined(PR5)
    typedef Pin<PortR, 5> PortR5;
# endif
# if defined(PORTR6) || defined(PR6)
    typedef Pin<PortR, 6> PortR6;
# endif
# if defined(PORTR7) || defined(PR7)
    typedef Pin<PortR, 7> PortR7;
# endif
#endif

#if defined(PORTS) && defined(DDRS) && defined(PINS)
    typedef Port<Ports, Ddrs, Pins> PortS;
# if defined(PORTS0) || defined(PS0)
    typedef Pin<PortS, 0> PortS0;
# endif
# if defined(PORTS1) || defined(PS1)
    typedef Pin<PortS, 1> PortS1;
# endif
# if defined(PORTS2) || defined(PS2)
    typedef Pin<PortS, 2> PortS2;
# endif
# if defined(PORTS3) || defined(PS3)
    typedef Pin<PortS, 3> PortS3;
# endif
# if defined(PORTS4) || defined(PS4)
    typedef Pin<PortS, 4> PortS4;
# endif
# if defined(PORTS5) || defined(PS5)
    typedef Pin<PortS, 5> PortS5;
# endif
# if defined(PORTS6) || defined(PS6)
    typedef Pin<PortS, 6> PortS6;
# endif
# if defined(PORTS7) || defined(PS7)
    typedef Pin<PortS, 7> PortS7;
# endif
#endif

#if defined(PORTT) && defined(DDRT) && defined(PINT)
    typedef Port<Portt, Ddrt, Pint> PortT;
# if defined(PORTT0) || defined(PT0)
    typedef Pin<PortT, 0> PortT0;
# endif
# if defined(PORTT1) || defined(PT1)
    typedef Pin<PortT, 1> PortT1;
# endif
# if defined(PORTT2) || defined(PT2)
    typedef Pin<PortT, 2> PortT2;
# endif
# if defined(PORTT3) || defined(PT3)
    typedef Pin<PortT, 3> PortT3;
# endif
# if defined(PORTT4) || defined(PT4)
    typedef Pin<PortT, 4> PortT4;
# endif
# if defined(PORTT5) || defined(PT5)
    typedef Pin<PortT, 5> PortT5;
# endif
# if defined(PORTT6) || defined(PT6)
    typedef Pin<PortT, 6> PortT6;
# endif
# if defined(PORTT7) || defined(PT7)
    typedef Pin<PortT, 7> PortT7;
# endif
#endif

#if defined(PORTU) && defined(DDRU) && defined(PINU)
    typedef Port<Portu, Ddru, Pinu> PortU;
# if defined(PORTU0) || defined(PU0)
    typedef Pin<PortU, 0> PortU0;
# endif
# if defined(PORTU1) || defined(PU1)
    typedef Pin<PortU, 1> PortU1;
# endif
# if defined(PORTU2) || defined(PU2)
    typedef Pin<PortU, 2> PortU2;
# endif
# if defined(PORTU3) || defined(PU3)
    typedef Pin<PortU, 3> PortU3;
# endif
# if defined(PORTU4) || defined(PU4)
    typedef Pin<PortU, 4> PortU4;
# endif
# if defined(PORTU5) || defined(PU5)
    typedef Pin<PortU, 5> PortU5;
# endif
# if defined(PORTU6) || defined(PU6)
    typedef Pin<PortU, 6> PortU6;
# endif
# if defined(PORTU7) || defined(PU7)
    typedef Pin<PortU, 7> PortU7;
# endif
#endif

#if defined(PORTV) && defined(DDRV) && defined(PINV)
    typedef Port<Portv, Ddrv, Pinv> PortV;
# if defined(PORTV0) || defined(PV0)
    typedef Pin<PortV, 0> PortV0;
# endif
# if defined(PORTV1) || defined(PV1)
    typedef Pin<PortV, 1> PortV1;
# endif
# if defined(PORTV2) || defined(PV2)
    typedef Pin<PortV, 2> PortV2;
# endif
# if defined(PORTV3) || defined(PV3)
    typedef Pin<PortV, 3> PortV3;
# endif
# if defined(PORTV4) || defined(PV4)
    typedef Pin<PortV, 4> PortV4;
# endif
# if defined(PORTV5) || defined(PV5)
    typedef Pin<PortV, 5> PortV5;
# endif
# if defined(PORTV6) || defined(PV6)
    typedef Pin<PortV, 6> PortV6;
# endif
# if defined(PORTV7) || defined(PV7)
    typedef Pin<PortV, 7> PortV7;
# endif
#endif

#if defined(PORTW) && defined(DDRW) && defined(PINW)
    typedef Port<Portw, Ddrw, Pinw> PortW;
# if defined(PORTW0) || defined(PW0)
    typedef Pin<PortW, 0> PortW0;
# endif
# if defined(PORTW1) || defined(PW1)
    typedef Pin<PortW, 1> PortW1;
# endif
# if defined(PORTW2) || defined(PW2)
    typedef Pin<PortW, 2> PortW2;
# endif
# if defined(PORTW3) || defined(PW3)
    typedef Pin<PortW, 3> PortW3;
# endif
# if defined(PORTW4) || defined(PW4)
    typedef Pin<PortW, 4> PortW4;
# endif
# if defined(PORTW5) || defined(PW5)
    typedef Pin<PortW, 5> PortW5;
# endif
# if defined(PORTW6) || defined(PW6)
    typedef Pin<PortW, 6> PortW6;
# endif
# if defined(PORTW7) || defined(PW7)
    typedef Pin<PortW, 7> PortW7;
# endif
#endif

#if defined(PORTX) && defined(DDRX) && defined(PINX)
    typedef Port<Portx, Ddrx, Pinx> PortX;
# if defined(PORTX0) || defined(PX0)
    typedef Pin<PortX, 0> PortX0;
# endif
# if defined(PORTX1) || defined(PX1)
    typedef Pin<PortX, 1> PortX1;
# endif
# if defined(PORTX2) || defined(PX2)
    typedef Pin<PortX, 2> PortX2;
# endif
# if defined(PORTX3) || defined(PX3)
    typedef Pin<PortX, 3> PortX3;
# endif
# if defined(PORTX4) || defined(PX4)
    typedef Pin<PortX, 4> PortX4;
# endif
# if defined(PORTX5) || defined(PX5)
    typedef Pin<PortX, 5> PortX5;
# endif
# if defined(PORTX6) || defined(PX6)
    typedef Pin<PortX, 6> PortX6;
# endif
# if defined(PORTX7) || defined(PX7)
    typedef Pin<PortX, 7> PortX7;
# endif
#endif

#if defined(PORTY) && defined(DDRY) && defined(PINY)
    typedef Port<Porty, Ddry, Piny> PortY;
# if defined(PORTY0) || defined(PY0)
    typedef Pin<PortY, 0> PortY0;
# endif
# if defined(PORTY1) || defined(PY1)
    typedef Pin<PortY, 1> PortY1;
# endif
# if defined(PORTY2) || defined(PY2)
    typedef Pin<PortY, 2> PortY2;
# endif
# if defined(PORTY3) || defined(PY3)
    typedef Pin<PortY, 3> PortY3;
# endif
# if defined(PORTY4) || defined(PY4)
    typedef Pin<PortY, 4> PortY4;
# endif
# if defined(PORTY5) || defined(PY5)
    typedef Pin<PortY, 5> PortY5;
# endif
# if defined(PORTY6) || defined(PY6)
    typedef Pin<PortY, 6> PortY6;
# endif
# if defined(PORTY7) || defined(PY7)
    typedef Pin<PortY, 7> PortY7;
# endif
#endif

#if defined(PORTZ) && defined(DDRZ) && defined(PINZ)
    typedef Port<Portz, Ddrz, Pinz> PortZ;
# if defined(PORTZ0) || defined(PZ0)
    typedef Pin<PortZ, 0> PortZ0;
# endif
# if defined(PORTZ1) || defined(PZ1)
    typedef Pin<PortZ, 1> PortZ1;
# endif
# if defined(PORTZ2) || defined(PZ2)
    typedef Pin<PortZ, 2> PortZ2;
# endif
# if defined(PORTZ3) || defined(PZ3)
    typedef Pin<PortZ, 3> PortZ3;
# endif
# if defined(PORTZ4) || defined(PZ4)
    typedef Pin<PortZ, 4> PortZ4;
# endif
# if defined(PORTZ5) || defined(PZ5)
    typedef Pin<PortZ, 5> PortZ5;
# endif
# if defined(PORTZ6) || defined(PZ6)
    typedef Pin<PortZ, 6> PortZ6;
# endif
# if defined(PORTZ7) || defined(PZ7)
    typedef Pin<PortZ, 7> PortZ7;
# endif
#endif

}

#endif
