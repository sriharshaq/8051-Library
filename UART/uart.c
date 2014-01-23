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
**   File       : uart.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the uart driver for 8051 family MCU's
***/

#include "uart.h"

// Globals

// Oscillator Frequency (Default 11.0592 MHz)
unsigned long OscillatorFrequency = 11059200;


#ifdef SERIAL_RX_INTERRUPT_ENABLE

// Uart New Line Flag (Set when new line received)
 volatile unsigned char uartNewLineFlag = 0;
// UART Read Buffer to store Received Data
 volatile unsigned char uartReadBuffer[UART_RX_BUFFER_SIZE];
// Uart Byte Count
 volatile unsigned int  uartReadCount    = 0;
// Uart New Line Count
 volatile unsigned char uartNewLineCount = 0;
// It holds every new line index
 volatile unsigned char uartNewLineIndexes[NEW_LINE_INDEX_BUFFER_SIZE];
// It hold single byte (Last Received)
 volatile unsigned char uartReadByte = CHAR_NULL;

#endif



/*** Function    : SetOsc
**   Parameters  : unsigned long (Oscillator Frequency in Hz)
**   Return      : None
**   Description : It will Set the Oscillator Frequency for Baud Rate Calculations
**/
void SetOsc(unsigned long OscFreq)
{
OscillatorFrequency = OscFreq;
}

/*** Function    : Serialbegin
**   Parameters  : unsigned long (Standard BaudRate)
**   Return      : None
**   Description : It will Set the baud rate for serial communication
**/
void Serialbegin(unsigned long baudRate)
{
volatile unsigned int autoReloadvalue;
#if UART_CLOCK_SOURCE == __TIMER_1__
autoReloadvalue =  __baudRate_calc_timer_1(OscillatorFrequency,baudRate);
TMOD  |= 0x20;
SCON  |= 0x50;
TL1    = autoReloadvalue >> 8;
TH1    = autoReloadvalue;
TR1    = 1
#elif UART_CLOCK_SOURCE == __TIMER_2__
autoReloadvalue=  __baudRate_calc_timer_2(OscillatorFrequency,baudRate);
T2CON = 0x00;
T2CON = 0x30;
SCON  = 0x50;
RCAP2H = autoReloadvalue >> 8;
RCAP2L = autoReloadvalue;
TH2 = autoReloadvalue >> 8;
TL2 = autoReloadvalue;
TR2    = 1;
#endif
}

/*** Function    : Serialavailable
**   Parameters  : None
**   Return      : __bit (If byte is available in receive buffer returns 1, else returns 0)
**   Description : It will give the whether Receiver is available or not
**/
unsigned char Serialavailable(void)
{
return RI;
}


/*** Function    : Serialwrite
**   Parameters  : unsigned char (Single character that will send to UART)
**   Return      : None
**   Description : It will write single character to UART
**/
void Serialwrite(unsigned char Byte)
{
#ifdef SERIAL_RX_INTERRUPT_ENABLE
EA = 0;
#endif
SBUF = Byte;
while(!TI);
TI   = 0;
#ifdef SERIAL_RX_INTERRUPT_ENABLE
EA = 1;
#endif
}

/*** Function    : Serialread
**   Parameters  : None
**   Return      : unsigned char
**   Description : It will read single byte from uart
**/
unsigned char Serialread(void)
{
while(!RI);
return SBUF;
}

/*** Function    : Serialprint
**   Parameters  : unsigned char *
**   Return      : None
**   Description : It will send the string to UART
**/
void Serialprint(unsigned char *sPtr)
{
for(;*sPtr!='\0';Serialwrite(*(sPtr++)));
}


/*** Function    : Serialprint
**   Parameters  : unsigned char *
**   Return      : None
**   Description : It will send the string to UART
**/
void SerialIntWrite(signed int num)
{
char *tempBuffer;
sprintf(tempBuffer,"%d",num);
Serialprint((unsigned char*)tempBuffer);
}


#ifdef SERIAL_RX_INTERRUPT_ENABLE

/*** Function    : setSerialinterrupt
**   Parameters  : None
**   Return      : None
**   Description : It sets the Serial Interrupt
**/
void setSerialinterrupt(void)
{
ES = 1;
EA = 1;
}

/*** Function    : Serialflush
**   Parameters  : None
**   Return      : None
**   Description : It clears the UART buffer,Index Buffer and Flags
**/
void Serialflush(void)
{
unsigned char i;
uartReadCount    = 0;           // Clear Uart Byte Count
uartNewLineFlag  = 0;           // Clear New Line Flag
uartNewLineCount = 0;           // Clear New Line Count
uartReadByte     = CHAR_NULL;   // Clear Last Read Byte

// Flush New Line Index Buffer
for(i=0;i<=NEW_LINE_INDEX_BUFFER_SIZE;i++)
uartNewLineIndexes[i] = CHAR_NULL;

// Flush Uart Read Buffer
for(i=0;i<=UART_RX_BUFFER_SIZE;i++)
uartReadBuffer[i] = CHAR_NULL;
}

/*** Function    : SerialReadByteFlush
**   Parameters  : None
**   Return      : None
**   Description : It clears the UART Read Byte (uartReadByte)
**/
void SerialReadByteFlush(void)
{
uartReadByte     = CHAR_NULL;   // Clear Last Read Byte
}

/*** Function    : uartISR
**   Parameters  : None
**   Return      : None
**   Description : It is ISR for UART Receive (It will trigger if any byte is received)
**/
#if TOOLCHAIN   == SDCC
void uartISR(void) __interrupt (4)
{
EA = 0;                                      // Disable Global Interrupt Flag
RI = 0;                                      // Clear RI flag
uartReadByte = SBUF;                         // Read Byte from SBUF
uartReadBuffer[uartReadCount++] = uartReadByte;
if(uartReadByte == LF)
{
uartNewLineIndexes[uartNewLineCount] = uartReadCount;
uartNewLineCount++;
uartNewLineFlag = 1;
}
EA = 1;                                     // Everything is done , Now Enable the Global Interrupt
}

#elif TOOLCHAIN == KEIL
void uartISR(void) interrupt (4)
{
EA = 0;                                      // Disable Global Interrupt Flag
RI = 0;                                      // Clear RI flag
uartReadByte = SBUF;                         // Read Byte from SBUF
uartReadBuffer[uartReadCount++] = uartReadByte;
if(uartReadByte == LF)
{
uartNewLineIndexes[uartNewLineCount] = uartReadCount;
uartNewLineCount++;
uartNewLineFlag = 1;
}
EA = 1;                                     // Everything is done , Now Enable the Global Interrupt
}

#else
#error "Invalid Toolchain, Please check 'TOOLCHAIN' macro (SDCC/KEIL)"
#endif

#endif



