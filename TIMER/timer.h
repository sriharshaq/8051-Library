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
**   File       : timer.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the hardware timer driver include file for 8051 family MCU's
***/

#ifndef __timer_h__
#define __timer_h__

#include <8051.h>

#define ENABLE_TIMER_0
//#define ENABLE_TIMER_1
//#define ENABLE_TIMER_2

#define TIMER0 0
#define TIMER1 1
#define TIMER2 2


#define ENABLE_TIMER_0_INTERRUPT 
//#define ENABLE_TIMER_1_INTERRUPT
//#define ENABLE_TIMER_2_INTERRUPT


extern timerSetosc(unsigned long);                                  // It will sets Oscillator Frequency
extern timerBegin(unsigned char,unsigned char);//,unsigned char); // Timer Number, Timer Value (in milliseconds), Timer Mode
extern timerStart(unsigned char,unsigned char);                   // Timer Number, Interrupts (Enabled,Disabled);
extern timerStop(unsigned char);                                   // Timer Number (It will also disable interrupts)


#ifdef ENABLE_TIMER_0_INTERRUPT
extern void timer0ISR(void) __interrupt(1);
extern unsigned int TimerCount0;
#endif

/*extern unsigned int TimerCount1;
extern unsigned int TimerCount2;*/
#endif

#endif