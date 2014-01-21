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
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
/**************************************************************************************************************/


/***
**   File       : testlcd.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is test code for 8051 LCD driver
***/

#include "lcd.h"                         // Include LCD driver

#define LCD_REFRESH_DELAY   5000         // LCD Refresh rate in milliseconds

// Strings to display
// If 20x2 LCD define below string
#if _LCD_TYPE_ == 1
#define String1  "    Hello World    "
#define String2  "    Hai 8051       "
#define String3  "    This is        "
#define String4  "    LCD TEST       "
// Otherwise if 16x2 define below string
#elif _LCD_TYPE_ == 2
#define String1  "    Hello World    "
#define String2  "    Hai 8051       "
#endif


/** Function    : main
*   Parameters  : None
*   Return      : int
*   Description : It is the entry point of program
**/
int main(void)
{
	lcdBegin();                       // Initiate the LCD
	while(1)
	{
    #if _LCD_TYPE_ == 1
	lcdSetCursor(1,0);
    lcdPrint(String1);
    __delay_ms__(LCD_REFRESH_DELAY);
    lcdSetCursor(2,0);
    lcdPrint(String2);
    __delay_ms__(LCD_REFRESH_DELAY);
    lcdSetCursor(3,0);
    lcdPrint(String3);
    __delay_ms__(LCD_REFRESH_DELAY);
    lcdSetCursor(4,0);
    lcdPrint(String4);
    __delay_ms__(LCD_REFRESH_DELAY);
    lcdClear();
    __delay_ms__(LCD_REFRESH_DELAY);
    #elif _LCD_TYPE_ == 2
	lcdSetCursor(1,0);
    lcdPrint(String1);
    __delay_ms__(LCD_REFRESH_DELAY);
    lcdSetCursor(2,0);
    lcdPrint(String2);
    __delay_ms__(LCD_REFRESH_DELAY);
    lcdClear();
    __delay_ms__(LCD_REFRESH_DELAY);
    #endif
	}
}
