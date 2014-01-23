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
**   File       : testuart.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the test code for 8051 uart driver
***/

#include "uart.h"
#include "i2c.h"


#define OSC_FREQ            (unsigned long)11059200
#define BAUD_RATE           9600

#define NEW_LINE_THRESHOLD  3

/*** Function    : main
**   Parameters  : None
**   Return      : int
**   Description : It is the entry point of program
**/
int main(void)
{
SetOsc(OSC_FREQ);             // Set Oscillator Freq
Serialbegin(BAUD_RATE);       // Set Baud Rate
Serialprint("I2C Test\n\r"); // Print a string
if(i2cBegin(0xA0) == 1)
Serialprint("Device Detected\n\r"); // Print a string
else
Serialprint("Device Not Detected\n\r"); // Print a string*/
Serialflush();                // Clear the buffers

setSerialinterrupt();         // Enable Serial Interrupt
while(1)
{
 while(uartNewLineCount<NEW_LINE_THRESHOLD); // Wait until new line count reaches threshold
 Serialprint(uartReadBuffer);                // Print the uart read buffer
 Serialflush();                              // Flush the buffer
}
return 0;
}
