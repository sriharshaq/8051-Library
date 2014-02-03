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
**   File       : io.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the io driver for 8051 family MCU's
***/

#include "io.h"

/*** Function    : digitalWrite
**   Parameters  : unsigned char,unsigned char (Pin Number,State->HIGH/LOW)
**   Return      : None
**   Description : It will Write the value to port
**/
void digitalWrite(unsigned char PinNo,unsigned char PinState)
{
if(PinNo < IO_MAX)
{
switch(PinNo % IO_MAX)
{
case 0 : if(PinState) PORT0OUT |= 1 << 0; else PORT0OUT &= (1 << 0); break;
case 1 : if(PinState) PORT0OUT |= 1 << 1; else PORT0OUT &= (1 << 1); break;
case 2 : if(PinState) PORT0OUT |= 1 << 2; else PORT0OUT &= (1 << 2); break;
case 3 : if(PinState) PORT0OUT |= 1 << 3; else PORT0OUT &= (1 << 3); break;
case 4 : if(PinState) PORT0OUT |= 1 << 4; else PORT0OUT &= (1 << 4); break;
case 5 : if(PinState) PORT0OUT |= 1 << 5; else PORT0OUT &= (1 << 5); break;
case 6 : if(PinState) PORT0OUT |= 1 << 6; else PORT0OUT &= (1 << 6); break;
case 7 : if(PinState) PORT0OUT |= 1 << 7; else PORT0OUT &= (1 << 7); break;
}
}
else if (PiNo < (IO_MAX * 2) && (PiNo > (IO_MAX)))
{
switch(PinNo % IO_MAX)
{
case 0 : if(PinState) PORT1OUT |= 1 << 0; else PORT1OUT &= (1 << 0); break;
case 1 : if(PinState) PORT1OUT |= 1 << 1; else PORT1OUT &= (1 << 1); break;
case 2 : if(PinState) PORT1OUT |= 1 << 2; else PORT1OUT &= (1 << 2); break;
case 3 : if(PinState) PORT1OUT |= 1 << 3; else PORT1OUT &= (1 << 3); break;
case 4 : if(PinState) PORT1OUT |= 1 << 4; else PORT1OUT &= (1 << 4); break;
case 5 : if(PinState) PORT1OUT |= 1 << 5; else PORT1OUT &= (1 << 5); break;
case 6 : if(PinState) PORT1OUT |= 1 << 6; else PORT1OUT &= (1 << 6); break;
case 7 : if(PinState) PORT1OUT |= 1 << 7; else PORT1OUT &= (1 << 7); break;
case 7 : if(PinState) PORT1OUT |= 1 << 7; else PORT1OUT &= (1 << 7); break;
}
}
else if (PiNo < (IO_MAX * 3)  && (PiNo > (IO_MAX * 2)))
{
switch(PinNo % IO_MAX)
{
case 0 : if(PinState) PORT2OUT |= 1 << 0; else PORT2OUT &= (1 << 0); break;
case 1 : if(PinState) PORT2OUT |= 1 << 1; else PORT2OUT &= (1 << 1); break;
case 2 : if(PinState) PORT2OUT |= 1 << 2; else PORT2OUT &= (1 << 2); break;
case 3 : if(PinState) PORT2OUT |= 1 << 3; else PORT2OUT &= (1 << 3); break;
case 4 : if(PinState) PORT2OUT |= 1 << 4; else PORT2OUT &= (1 << 4); break;
case 5 : if(PinState) PORT2OUT |= 1 << 5; else PORT2OUT &= (1 << 5); break;
case 6 : if(PinState) PORT2OUT |= 1 << 6; else PORT2OUT &= (1 << 6); break;
case 7 : if(PinState) PORT2OUT |= 1 << 7; else PORT2OUT &= (1 << 7); break;
}
}
else if (PiNo < (IO_MAX * 4)  && (PiNo > (IO_MAX * 3)))
{
switch(PinNo % IO_MAX)
{
case 0 : if(PinState) PORT3OUT |= 1 << 0; else PORT3OUT &= (1 << 0); break;
case 1 : if(PinState) PORT3OUT |= 1 << 1; else PORT3OUT &= (1 << 1); break;
case 2 : if(PinState) PORT3OUT |= 1 << 2; else PORT3OUT &= (1 << 2); break;
case 3 : if(PinState) PORT3OUT |= 1 << 3; else PORT3OUT &= (1 << 3); break;
case 4 : if(PinState) PORT3OUT |= 1 << 4; else PORT3OUT &= (1 << 4); break;
case 5 : if(PinState) PORT3OUT |= 1 << 5; else PORT3OUT &= (1 << 5); break;
case 6 : if(PinState) PORT3OUT |= 1 << 6; else PORT3OUT &= (1 << 6); break;
case 7 : if(PinState) PORT3OUT |= 1 << 7; else PORT3OUT &= (1 << 7); break;
}
}
}

/*** Function    : digitalRead
**   Parameters  : unsigned char(Pin Number)
**   Return      : Pin State (HIGH,LOW)
**   Description : It will Read the data from PORT
**/
unsigned char digitalRead(unsigned char PinNo)
{
if(PinNo < IO_MAX)
{
switch(PinNo % IO_MAX)
{
case 0 : if(PORT0IN & 0x01) return HIGH; else return LOW;
case 1 : if(PORT0IN & 0x02) return HIGH; else return LOW;
case 2 : if(PORT0IN & 0x04) return HIGH; else return LOW;
case 3 : if(PORT0IN & 0x08) return HIGH; else return LOW;
case 4 : if(PORT0IN & 0x10) return HIGH; else return LOW;
case 5 : if(PORT0IN & 0x20) return HIGH; else return LOW;
case 6 : if(PORT0IN & 0x40) return HIGH; else return LOW;
case 7 : if(PORT0IN & 0x80) return HIGH; else return LOW;
}
}
else if (PiNo < (IO_MAX * 2)  && (PiNo > (IO_MAX)))
{
switch(PinNo % IO_MAX)
{
case 0 : if(PORT1IN & 0x01) return HIGH; else return LOW;
case 1 : if(PORT1IN & 0x02) return HIGH; else return LOW;
case 2 : if(PORT1IN & 0x04) return HIGH; else return LOW;
case 3 : if(PORT1IN & 0x08) return HIGH; else return LOW;
case 4 : if(PORT1IN & 0x10) return HIGH; else return LOW;
case 5 : if(PORT1IN & 0x20) return HIGH; else return LOW;
case 6 : if(PORT1IN & 0x40) return HIGH; else return LOW;
case 7 : if(PORT1IN & 0x80) return HIGH; else return LOW;
}
}
else if (PiNo < (IO_MAX * 3)  && (PiNo > (IO_MAX * 2)))
{
switch(PinNo % IO_MAX)
{
case 0 : if(PORT2IN & 0x01) return HIGH; else return LOW;
case 1 : if(PORT2IN & 0x02) return HIGH; else return LOW;
case 2 : if(PORT2IN & 0x04) return HIGH; else return LOW;
case 3 : if(PORT2IN & 0x08) return HIGH; else return LOW;
case 4 : if(PORT2IN & 0x10) return HIGH; else return LOW;
case 5 : if(PORT2IN & 0x20) return HIGH; else return LOW;
case 6 : if(PORT2IN & 0x40) return HIGH; else return LOW;
case 7 : if(PORT2IN & 0x80) return HIGH; else return LOW;
}
}
else if (PiNo < (IO_MAX * 4)  && (PiNo > (IO_MAX * 3)))
{
switch(PinNo % IO_MAX)
{
case 0 : if(PORT3IN & 0x01) return HIGH; else return LOW;
case 1 : if(PORT3IN & 0x02) return HIGH; else return LOW;
case 2 : if(PORT3IN & 0x04) return HIGH; else return LOW;
case 3 : if(PORT3IN & 0x08) return HIGH; else return LOW;
case 4 : if(PORT3IN & 0x10) return HIGH; else return LOW;
case 5 : if(PORT3IN & 0x20) return HIGH; else return LOW;
case 6 : if(PORT3IN & 0x40) return HIGH; else return LOW;
case 7 : if(PORT3IN & 0x80) return HIGH; else return LOW;
}
}
}

/*** Function    : pinMode
**   Parameters  : unsigned char,unsigned char (Pin Number,PinDirection->INPUT/OUTPUT)
**   Return      : None
**   Description : It will Set the direction of port
**/
void pinMode(unsigned char PinNo,unsigned char PinDirection)
{
if(PinNo < IO_MAX)
{
switch(PinNo % IO_MAX)
{
case 0 : if(PinState) PORT0DIR |= 1 << 0; else PORT0DIR &= (1 << 0); break;
case 1 : if(PinState) PORT0DIR |= 1 << 1; else PORT0DIR &= (1 << 1); break;
case 2 : if(PinState) PORT0DIR |= 1 << 2; else PORT0DIR &= (1 << 2); break;
case 3 : if(PinState) PORT0DIR |= 1 << 3; else PORT0DIR &= (1 << 3); break;
case 4 : if(PinState) PORT0DIR |= 1 << 4; else PORT0DIR &= (1 << 4); break;
case 5 : if(PinState) PORT0DIR |= 1 << 5; else PORT0DIR &= (1 << 5); break;
case 6 : if(PinState) PORT0DIR |= 1 << 6; else PORT0DIR &= (1 << 6); break;
case 7 : if(PinState) PORT0DIR |= 1 << 7; else PORT0DIR &= (1 << 7); break;
}
}
else if (PiNo < (IO_MAX * 2)  && (PiNo > (IO_MAX)))
{
switch(PinNo % IO_MAX)
{
case 0 : if(PinState) PORT1DIR |= 1 << 0; else PORT1DIR &= (1 << 0); break;
case 1 : if(PinState) PORT1DIR |= 1 << 1; else PORT1DIR &= (1 << 1); break;
case 2 : if(PinState) PORT1DIR |= 1 << 2; else PORT1DIR &= (1 << 2); break;
case 3 : if(PinState) PORT1DIR |= 1 << 3; else PORT1DIR &= (1 << 3); break;
case 4 : if(PinState) PORT1DIR |= 1 << 4; else PORT1DIR &= (1 << 4); break;
case 5 : if(PinState) PORT1DIR |= 1 << 5; else PORT1DIR &= (1 << 5); break;
case 6 : if(PinState) PORT1DIR |= 1 << 6; else PORT1DIR &= (1 << 6); break;
case 7 : if(PinState) PORT1DIR |= 1 << 7; else PORT1DIR &= (1 << 7); break;
case 7 : if(PinState) PORT1DIR |= 1 << 7; else PORT1DIR &= (1 << 7); break;
}
}
else if (PiNo < (IO_MAX * 3)  && (PiNo > (IO_MAX * 2)))
{
switch(PinNo % IO_MAX)
{
case 0 : if(PinState) PORT2DIR |= 1 << 0; else PORT2DIR &= (1 << 0); break;
case 1 : if(PinState) PORT2DIR |= 1 << 1; else PORT2DIR &= (1 << 1); break;
case 2 : if(PinState) PORT2DIR |= 1 << 2; else PORT2DIR &= (1 << 2); break;
case 3 : if(PinState) PORT2DIR |= 1 << 3; else PORT2DIR &= (1 << 3); break;
case 4 : if(PinState) PORT2DIR |= 1 << 4; else PORT2DIR &= (1 << 4); break;
case 5 : if(PinState) PORT2DIR |= 1 << 5; else PORT2DIR &= (1 << 5); break;
case 6 : if(PinState) PORT2DIR |= 1 << 6; else PORT2DIR &= (1 << 6); break;
case 7 : if(PinState) PORT2DIR |= 1 << 7; else PORT2DIR &= (1 << 7); break;
}
}
else if (PiNo < (IO_MAX * 4)  && (PiNo > (IO_MAX * 3)))
{
switch(PinNo % IO_MAX)
{
case 0 : if(PinState) PORT3DIR |= 1 << 0; else PORT3DIR &= (1 << 0); break;
case 1 : if(PinState) PORT3DIR |= 1 << 1; else PORT3DIR &= (1 << 1); break;
case 2 : if(PinState) PORT3DIR |= 1 << 2; else PORT3DIR &= (1 << 2); break;
case 3 : if(PinState) PORT3DIR |= 1 << 3; else PORT3DIR &= (1 << 3); break;
case 4 : if(PinState) PORT3DIR |= 1 << 4; else PORT3DIR &= (1 << 4); break;
case 5 : if(PinState) PORT3DIR |= 1 << 5; else PORT3DIR &= (1 << 5); break;
case 6 : if(PinState) PORT3DIR |= 1 << 6; else PORT3DIR &= (1 << 6); break;
case 7 : if(PinState) PORT3DIR |= 1 << 7; else PORT3DIR &= (1 << 7); break;
}
}
}