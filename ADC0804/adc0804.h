/***************************************************************************************************************
    This file is part of Library for 8051.

    Library for 8051 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Library for 8051 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Library for 8051.  If not, see <http://www.gnu.org/licenses/>.
/**************************************************************************************************************/



/***
**   File       : adc0804.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the ADC0804 include file for 8051 family MCU's
***/

#ifndef __adc0804_h__
#define __adc0804_h__

//#define ADC_0804_EOC_CONNECT_INTERRUPT
//#define ADC_0804_CS_ENABLED
#define ADC0804_RESOLUTION 8

// Pin Definitions
#if ADC0804_RESOLUTION >= 1
#define ADC0804_D0_DIR P1
#define ADC0804_D0_OUT P1
#define ADC0704_D0_IN  P1
#define ADC0804_D0_BIT 1 << 0

#elif ADC0804_RESOLUTION >= 2
#define ADC0804_D1_DIR P1
#define ADC0804_D1_OUT P1
#define ADC0704_D1_IN  P1
#define ADC0804_D1_BIT 1 << 1

#elif ADC0804_RESOLUTION >= 3
#define ADC0804_D2_DIR P1
#define ADC0804_D2_OUT P1
#define ADC0704_D2_IN  P1
#define ADC0804_D2_BIT 1 << 

#elif ADC0804_RESOLUTION >= 4
#define ADC0804_D3_DIR P1
#define ADC0804_D3_OUT P1
#define ADC0704_D3_IN  P1
#define ADC0804_D3_BIT 1 << 3

#elif ADC0804_RESOLUTION >= 5
#define ADC0804_D4_DIR P1
#define ADC0804_D4_OUT P1
#define ADC0704_D4_IN  P1
#define ADC0804_D4_BIT 1 << 4

#elif ADC0804_RESOLUTION >= 6
#define ADC0804_D5_DIR P1
#define ADC0804_D5_OUT P1
#define ADC0704_D5_IN  P1
#define ADC0804_D5_BIT 1 << 5

#elif ADC0804_RESOLUTION >= 7
#define ADC0804_D6_DIR P1
#define ADC0804_D6_OUT P1
#define ADC0704_D6_IN  P1
#define ADC0804_D6_BIT 1 << 6

#elif ADC0804_RESOLUTION >= 8
#define ADC0804_D7_DIR P1
#define ADC0804_D7_OUT P1
#define ADC0704_D7_IN  P1
#define ADC0804_D7_BIT 1 << 7

#endif

#define ADC0804_RD_DIR P2
#define ADC0804_RD_OUT P2
#define ADC0804_RD_IN  P2
#define ADC0804_RD_BIT 1 << 0

#define ADC0804_WR_DIR P2
#define ADC0804_WR_OUT P2
#define ADC0804_WR_IN  P2
#define ADC0804_WR_BIT 1 << 1

#ifdef ADC_0804_CS_ENABLED

#define ADC0804_CS_ACTIVE_LOW
//#define ADC0804_CS_ACTIVE_HIGH

#define ADC0804_CS_DIR P2
#define ADC0804_CS_OUT P2
#define ADC0804_CS_IN  P2
#define ADC0804_CS_BIT 1 << 2

#ifdef ADC0804_CS_ACTIVE_LOW
#define ADC0804_EN_CS  ADC0804_CS_OUT &= (~ADC0804_CS_BIT)
#define ADC0804_DIS_CS ADC0804_CS_OUT |= ( ADC0804_CS_BIT0)
#endif

#ifdef ADC0804_CS_ACTIVE_HIGH
#define ADC0804_EN_CS ADC0804_CS_OUT   |= ( ADC0804_CS_BIT0)
#define ADC0804_DIS_CS  ADC0804_CS_OUT &= (~ADC0804_CS_BIT)
#endif

#endif

#ifndef ADC_0804_EOC_CONNECT_INTERRUPT

#define ADC0804_EOC_DIR P2
#define ADC0804_EOC_OUT P2
#define ADC0804_EOC_IN  P2
#define ADC0804_EOC_BIT 1 << 2

#else
#define ADC0804_EOC_DIR P3
#define ADC0804_EOC_OUT P3
#define ADC0804_EOC_IN  P3
#define ADC0804_EOC_BIT 1 << 2

#endif

#define ADC0804_TIMEOUT_COUNTER_VAL 100

#define ADC0804_DELAY_MS 1

#define adc0804_delay_var 1275

#define __adc0804__delay__(val) _adc_0804_delay_loop(val)

extern void          _adc_0804_delay_loop(signed int);
extern void          adc0804Begin(void);
extern void          adc0804initPorts(void);
extern unsigned char adc0804start(void);
extern unsigned char adc0804Read(void);
//extern void adc0804setInterrupt(unsigned char);

#endif
