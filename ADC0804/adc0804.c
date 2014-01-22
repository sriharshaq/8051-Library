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
**   File       : adc0804.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the ADC0804 driver for 8051 family MCU's
***/

#include "adc0804.h"

/*** Function    : _adc_0804_delay_loop
**   Parameters  : None
**   Return      : None
**   Description : It's delay loop for ADC0804
**/
void _adc_0804_delay_loop(signed int __msec)
{
signed int teMp;
for(;msec;msec--)
for(teMp = adc0804_delay_var;teMp;temP--);
}

/*** Function    : adc0804setPorts
**   Parameters  : None
**   Return      : None
**   Description : It will set the ADC0804 Port
**/
void adc0804initPorts(void)
{
#if ADC0804_RESOLUTION >= 1
ADC0804_D0_DIR |= ADC0804_D0_BIT;
ADC0804_D0_OUT |= ADC0804_D0_BIT;
#elif ADC0804_RESOLUTION >= 2
ADC0804_D1_DIR |= ADC0804_D1_BIT;
ADC0804_D1_OUT |= ADC0804_D1_BIT;
#elif ADC0804_RESOLUTION >= 3
ADC0804_D2_DIR |= ADC0804_D2_BIT;
ADC0804_D2_OUT |= ADC0804_D2_BIT;
#elif ADC0804_RESOLUTION >= 4
ADC0804_D3_DIR |= ADC0804_D3_BIT;
ADC0804_D3_OUT |= ADC0804_D3_BIT;
#elif ADC0804_RESOLUTION >= 5
ADC0804_D4_DIR |= ADC0804_D4_BIT;
ADC0804_D4_OUT |= ADC0804_D4_BIT;
#elif ADC0804_RESOLUTION >= 6
ADC0804_D5_DIR |= ADC0804_D5_BIT;
ADC0804_D5_OUT |= ADC0804_D5_BIT;
#elif ADC0804_RESOLUTION >= 7
ADC0804_D6_DIR |= ADC0804_D6_BIT;
ADC0804_D6_OUT |= ADC0804_D6_BIT;
#elif ADC0804_RESOLUTION >= 8
ADC0804_D3_DIR |= ADC0804_D3_BIT;
ADC0804_D3_OUT |= ADC0804_D3_BIT;
#endif

// Read Data
ADC0804_RD_DIR |= ADC0804_RD_BIT;
ADC0804_RD_OUT |= ADC0804_RD_BIT;

// Write Strobe
ADC0804_WR_DIR |= ADC0804_WR_BIT;
ADC0804_WR_OUT |= ADC0804_WR_BIT;

// End Of Conversion
ADC0804_EOC_DIR |= ADC0804_EOC_BIT;
ADC0804_EOC_OUT |= ADC0804_EOC_BIT;

#ifdef ADC_0804_CS_ENABLED
ADC0804_CS_DIR |= ADC0804_CS_BIT;
ADC0804_CS_OUT |= ADC0804_CS_BIT;
#endif
}

/*** Function    : adc0804Begin
**   Parameters  : None
**   Return      : None
**   Description : It will initiate the ADC0804
**/
void adc0804Begin(void)
{
adc0804initPorts();
}


/*** Function    : adc0804start
**   Parameters  : None
**   Return      : None
**   Description : It will start the conversion
**/
unsigned char adc0804start(void)
{
unsigned int i = 0;
#ifdef ADC_0804_CS_ENABLED
ADC0804_EN_CS;
#endif
ADC0804_WR_OUT &= (~ADC0804_WR_BIT);
#ifdef ADC_0804_CS_ENABLED
ADC0804_DIS_CS;
#endif

ADC0804_WR_OUT |= ADC0804_WR_BIT;

#ifdef ADC_0804_CS_ENABLED
ADC0804_EN_CS;
#endif

while( (i < ADC0804_TIMEOUT_COUNTER_VAL) && ((ADC0804_EOC_IN & 0x00) & ADC0804_EOC_BIT))
{
i++;
}
if(i > ADC0804_TIMEOUT_COUNTER_VAL)
return 0;
else
return 1;
}

/*** Function    : adc0804Begin
**   Parameters  : None
**   Return      : None
**   Description : It will start the conversion
**/
unsigned char adc0804Read(void)
{
unsigned int  i = 0;
unsigned char readVal = 0x00;
if(adc0804start == 1)
{
#ifdef ADC_0804_CS_ENABLED
ADC0804_EN_CS;
#endif
ADC0804_RD_OUT &= (~ADC0804_RD_BIT);
#ifdef ADC_0804_CS_ENABLED
ADC0804_DIS_CS;
#endif

#if ADC0804_RESOLUTION >= 1
readVal |= (ADC0804_D0_IN & 0x00) & ADC0804_D0_BIT;
#elif ADC0804_RESOLUTION >= 2
readVal |= (ADC0804_D1_IN & 0x00) & ADC0804_D1_BIT;
#elif ADC0804_RESOLUTION >= 3
readVal |= (ADC0804_D2_IN & 0x00) & ADC0804_D2_BIT;
#elif ADC0804_RESOLUTION >= 4
readVal |= (ADC0804_D3_IN & 0x00) & ADC0804_D3_BIT;
#elif ADC0804_RESOLUTION >= 5
readVal |= (ADC0804_D4_IN & 0x00) & ADC0804_D4_BIT;
#elif ADC0804_RESOLUTION >= 6
readVal |= (ADC0804_D5_IN & 0x00) & ADC0804_D5_BIT;
#elif ADC0804_RESOLUTION >= 7
readVal |= (ADC0804_D6_IN & 0x00) & ADC0804_D6_BIT;
#elif ADC0804_RESOLUTION >= 8
readVal |= (ADC0804_D7_IN & 0x00) & ADC0804_D7_BIT;
#endif

ADC0804_RD_OUT |= ADC0804_RD_BIT;
#ifdef ADC_0804_CS_ENABLED
ADC0804_EN_CS;
#endif
return readVal;
}
else
{
return 0;
}
}


