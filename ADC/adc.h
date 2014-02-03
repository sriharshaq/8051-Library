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
    along with Library for 8051. If not, see <http://www.gnu.org/licenses/>.
/**************************************************************************************************************/


/***
**   File       : adc.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is include file for ADC library for 8051 family MCU's
***/

#ifndef __adc_h__
#define __adc_h__

#define ADC_RES_BITS          10

#if ADC_RES_BITS == 12
#define ADC_RES_VAL           4095
#elif ADC_RES_BITS == 10
#define ADC_RES_VAL           1023
#elif ADC_RES_BITS == 8
#define ADC_RES_VAL           255
#endif

#define Vref                  3.3
#define AdcRefVoltage         (Vref * 1000)                          // In milli volts  
#define ADC_TO_VOLTAGE(val)   val * (AdcRefVoltage /  ADC_RES_VAL)    

extern double Raw2Voltage(void);                                     // Return in milli volts

#endif

