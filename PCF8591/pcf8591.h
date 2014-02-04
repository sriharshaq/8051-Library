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
**   File       : pcf8591.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the include file for PCF8591 with 8051
***/

#ifndef __pcf8591_h__
#define __pcf8591_h__

#define PCF8591_SLAVE_ADDRESS 0x90

int  analogRead(unsigned char);
<<<<<<< HEAD
void analogWrite(int);
=======
void analogWrite(unsigned int);
>>>>>>> 7b87dc8e7aacf5e30416c903205ba0a92e66d671
void begin(void);

#define ADC_CH_0 0
#define ADC_CH_1 1
#define ADC_CH_2 2
#define ADC_CH_3 3

#define ADC_CH0_REG_ADDRESS 0
#define ADC_CH1_REG_ADDRESS 1
#define ADC_CH2_REG_ADDRESS 2
#define ADC_CH3_REG_ADDRESS 3

#define DAC_REG_ADDRESS     0x40

#endif