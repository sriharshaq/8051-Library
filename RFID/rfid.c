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
**   File       : rfid.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the RFID (UART Interface) driver for 8051 family MCU's
***/

#include "uart.h"
#include "rfid.h"

#if TOOLCHAIN == SDCC
__code unsigned char *ID_DB[] = {"12345","45678"};
__code unsigned char *NM_DB[] = {"Name1","Name2"};

#elif TOOLCHAIN == KEIL
code unsigned char *ID_DB[] = {"12345","45678"};
code unsigned char *NM_DB[] = {"Name1","Name2"};
#endif


volatile unsigned char FrameIndexDB = 0;
volatile unsigned char FrameIndexPt = 0;

unsigned char checkSwipe(void)
{
#ifdef COUNT_TERMINATION
if(uartReadCount == RFID_CHAR_COUNT)
return 1;
else
return 0;
#endif

#ifdef LINEF_TERMINATION
if(uartNewLineFlag)
return 1;
else 
return 0;
#endif
}

unsigned char checkDatabase(void)
{
unsigned char i;
unsigned char j;
unsigned char tempCount;
for(i=0;i<=RFID_DB_SIZE;i++)
{
for(j=0;j<=RFID_DB_SIZE;j++)
{
if(ID_DB[i][j] == uartReadBuffer[j])
tempCount++;
}
if(tempCount == RFID_FRAME_LENGTH)
{
FrameIndexDB = i;
FrameIndexPt = j;
return 1;
}
else
tempCount = 0;
}
}

char* getName(void)
{
return NM_DB[FrameIndexDB][FrameIndexPt];
}

char* getTagNo(void)
{
return ID_DB[FrameIndexDB][FrameIndexPt];
}



