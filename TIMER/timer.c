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
**   File       : timer.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the hardware timer driver for 8051 family MCU's
***/

#include "timer.h"


#ifdef ENABLE_TIMER_0_INTERRUPT
volatile unsigned int TimerCount0 = 0;
#endif


/*** Function    : timerBegin
**   Parameters  : unsigned char,unsigned char -> Timer Number, Timer Value (In milliseconds),unsigned long -> Oscillator Frequency in Hz
**   Return      : None
**   Description : It will initiates the timer
**/
void timerBegin(unsigned char TimerNo,unsigned char TimerVal,unsigned long oscFreq)
{
int reloadVal = 0;
// Set Timer Mode
TMOD |= 0x01;

reloadVal = _timer_0_1_mode_2_calc(TimerVal,oscFreq);
TL0 = reloadVal >> 8;
TH0 = reloadVal;
}

/*** Function    : timerStart
**   Parameters  : unsigned char,unsigned char -> Timer Number, Interrupts (0-> Disabled,1->Enabled)
**   Return      : None
**   Description : It will Start The Timer
**/
void timerStart(unsigned char TimerNo,unsigned char _inter)
{
if(TimerNo == TIMER0)
{
if(_inter == 1)
{
IE_1 = 1;
EA   = 1
}
TR0 = 1;
}
else if(TimerNo == TIMER1)
{
if(_inter == 1)
{
IE_3 = 1;
EA   = 1
}
TR1 = 1;
}
}

/*** Function    : timerStop
**   Parameters  : unsigned char (Timer Number)
**   Return      : None
**   Description : It will Stop The Timer
**/
void timerStop(unsigned char TimerNo)
{
if(TimerNo == TIMER0)
{
TR0  = 0;
IE_1 = 0; 
}
else if(TimerNo == TIMER1)
{
TR1  = 0;
IE_3 = 0; 
}
}


/*** Function    : N/A (It's an ISR)
**   Parameters  : None
**   Return      : None
**   Description : This is ISR for TIMER - 0 of 8051
**/
#ifdef ENABLE_TIMER_0_INTERRUPT
#if TOOLCHAIN   == SDCC
void timer0ISR(void) __interrupt(1)
{
TimerCount0++;
TF0 = 0;
}
#elif TOOLCHAIN == KEIL
void timer0ISR(void) interrupt(1)
{
TimerCount0++;
TF0 = 0;
}
#error "Invalid Toolchain, Please check 'TOOLCHAIN' macro (SDCC/KEIL)"
#endif

/*** Function    : timerClear0
**   Parameters  : None
**   Return      : None
**   Description : This function clears the count of TIMER - 0
**/
void timerClear0(void)
{
TimerCount0 = 0;
}

#endif