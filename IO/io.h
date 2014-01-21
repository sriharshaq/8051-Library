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
**   File       : io.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is include file for io library for 8051 family MCU's
***/
#ifndef __io_h__
#define __io_h__

#ifndef SDCC
#define SDCC 0
#endif
#ifndef KEIL
#define KEIL 1
#endif

#ifndef TOOLCHAIN
#define TOOLCHAIN SDCC
#endif

#if TOOLCHAIN   == SDCC
#include <8051.h>             // 8051 Peripheral Address preprocessor file
#elif TOOLCHAIN == KEIL
#include <reg51.h>
#else
#error "Invalid Toolchain, Please check 'TOOLCHAIN' macro (SDCC/KEIL)"
#endif

#include <stdio.h>

#define PORT0DIR P0
#define PORT1DIR P1
#define PORT2DIR P2
#define PORT3DIR P3

#define PORT0OUT P0
#define PORT1OUT P1
#define PORT2OUT P2
#define PORT3OUT P3

#define PORT0IN  P0
#define PORT1IN  P1
#define PORT2IN  P2
#define PORT3IN  P3

#define HIGH     1
#define LOW      0
#define OUTPUT   1
#define INPUT    0

#define IO_MAX 7

// Prototypes

extern void          digitalWrite(unsigned char,unsigned char);         // Pin Number, Pin State (HIGH,LOW)
extern unsigned char digitalRead(unsigned char);                        // Pin Number
extern void          pinMode(unsigned char,unsigned char);              // Pin Number, Mode-> OUTPUT,INPUT

#endif
