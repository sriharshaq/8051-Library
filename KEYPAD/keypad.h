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
**   File       : keypad.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the Keypad include file for 8051 family MCU's
***/
#ifndef __keypad_h__
#define __keypad_h__

#ifndef KEYPAD_HEX
#define KEYPAD_HEX
#endif

/*
#ifndef KEYPAD_DEC
#define KEYPAD_DEC
#endif
*/

// Pin Definitions
#define KEYPAD_ROW_0_DIR P1
#define KEYPAD_ROW_0_OUT P1
#define KEYPAD_ROW_0_IN  P1
#define KEYPAD_ROW_0_BIT 1 << 0

#define KEYPAD_ROW_1_DIR P1
#define KEYPAD_ROW_1_OUT P1
#define KEYPAD_ROW_1_IN  P1
#define KEYPAD_ROW_1_BIT 1 << 1

#define KEYPAD_ROW_2_DIR P1
#define KEYPAD_ROW_2_OUT P1
#define KEYPAD_ROW_2_IN  P1
#define KEYPAD_ROW_2_BIT 1 << 2

#define KEYPAD_ROW_3_DIR P1
#define KEYPAD_ROW_3_OUT P1
#define KEYPAD_ROW_3_IN  P1
#define KEYPAD_ROW_3_BIT 1 << 3


#define KEYPAD_COL_0_DIR P1
#define KEYPAD_COL_0_OUT P1
#define KEYPAD_COL_0_IN  P1
#define KEYPAD_COL_0_BIT 1 << 4

#define KEYPAD_COL_1_DIR P1
#define KEYPAD_COL_1_OUT P1
#define KEYPAD_COL_1_IN  P1
#define KEYPAD_COL_1_BIT 1 << 5

#define KEYPAD_COL_2_DIR P1
#define KEYPAD_COL_2_OUT P1
#define KEYPAD_COL_2_IN  P1
#define KEYPAD_COL_2_BIT 1 << 6

#ifdef KEYPAD_HEX
#define KEYPAD_COL_3_DIR P1
#define KEYPAD_COL_3_OUT P1
#define KEYPAD_COL_3_IN  P1
#define KEYPAD_COL_3_BIT 1 << 7
#endif



#endif