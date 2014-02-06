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
**   File       : rfid.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the RFID (UART Interface) driver include file for 8051 uart driver
***/

#ifndef __rfid_h__
#define __rfid_h__

//#define LINEF_TERMINATION 
#define COUNT_TERMINATION


#ifdef LINEF_TERMINATION
#ifdef COUNT_TERMINATION
#error "Both LINEF_TERMINATION and COUNT_TERMINATION are defined"
#endif
#endif

#ifdef COUNT_TERMINATION
#ifdef LINEF_TERMINATION
#error "Both LINEF_TERMINATION and COUNT_TERMINATION are defined"
#endif
#endif


#define RFID_FRAME_LENGTH 9

#define RFID_DB_SIZE     10

#ifdef  COUNT_TERMINATION
#define RFID_CHAR_COUNT 9
#endif


extern unsigned char  checkSwipe(void);
extern unsigned char  checkDatabase(void);
extern          char* getName(void);
extern          char* getTagNo(void);


#endif