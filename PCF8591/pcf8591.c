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
**   File       : pcf8591.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the PCF8591 driver file with 8051
***/


void begin(void)
{
i2cbegin(PCF8591_SLAVE_ADDRESS);
}

int analogRead(unsigned char ch)
{
if(ch == ADC_CH_0)
return i2cread(ADC_CH_0);
else if(ch == ADC_CH_1)
return i2cread(ADC_CH_1);
else if(ch == ADC_CH_2)
return i2cread(ADC_CH_2);
else if(ch == ADC_CH_3)
return i2cread(ADC_CH_3);
}

void analogWrite(int __val)
{

}

