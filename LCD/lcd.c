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
**   File       : lcd.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the lcd driver for 8051 family MCU's
***/

#include "lcd.h"

/*** Function    : __delay_loop_
**   Parameters  : signed long
**   Return      : None
**   Description : It will give a delay for lcd
**/
void __delay_loop_(signed long val)
{
	for(;val;val--);
}

/*** Function    : lcdEnable
**   Parameters  : None
**   Return      : None
**   Description : It will trigger LCD Enable Signal
**/
void lcdEnable(void)
{
	LCD_ENABLE_HIGH;
	__delay_us__(1);
	LCD_ENABLE_LOW;
}

/*** Function    : lcd_port_init
**   Parameters  : None
**   Return      : None
**   Description : It will Initiate the I/O Port for LCD
**/
void lcd_port_init(void)
{
// SET RS Port as OUTPUT and Write LOW to PORT
LCD_RS_DIR  |= LCD_RS_BIT;
//LCD_RS_PORT &= ~LCD_RS_BIT;
LCD_RS_PORT |= LCD_RS_BIT;
// SET EN Port as OUTPUT and Write LOW to PORT
LCD_EN_DIR  |= LCD_EN_BIT;
//LCD_EN_PORT &= ~LCD_EN_BIT;
LCD_EN_PORT |= LCD_EN_BIT;

// If 8- Bit Mode
#if   LCD_MODE == 1
// SET D0 Port as OUTPUT and Write HIGH to PORT
LCD_D0_DIR  |= LCD_D0_BIT;
LCD_D0_PORT |= LCD_D0_BIT;
// SET D1 Port as OUTPUT and Write HIGH to PORT
LCD_D1_DIR  |= LCD_D1_BIT;
LCD_D1_PORT |= LCD_D1_BIT;
// SET D2 Port as OUTPUT and Write HIGH to PORT
LCD_D2_DIR  |= LCD_D2_BIT;
LCD_D2_PORT |= LCD_D2_BIT;
// SET D3 Port as OUTPUT and Write HIGH to PORT
LCD_D3_DIR  |= LCD_D3_BIT;
LCD_D3_PORT |= LCD_D3_BIT;
// SET D4 Port as OUTPUT and Write HIGH to PORT
LCD_D4_DIR  |= LCD_D4_BIT;
LCD_D4_PORT |= LCD_D4_BIT;
// SET D5 Port as OUTPUT and Write HIGH to PORT
LCD_D5_DIR  |= LCD_D5_BIT;
LCD_D5_PORT |= LCD_D5_BIT;
// SET D6 Port as OUTPUT and Write HIGH to PORT
LCD_D6_DIR  |= LCD_D6_BIT;
LCD_D6_PORT |= LCD_D6_BIT;
// SET D7 Port as OUTPUT and Write HIGH to PORT
LCD_D7_DIR  |= LCD_D7_BIT;
LCD_D7_PORT |= LCD_D7_BIT;
// If 4-Bit Mode
#elif LCD_MODE == 2
// SET D4 Port as OUTPUT and Write HIGH to PORT
LCD_D4_DIR  |= LCD_D4_BIT;
LCD_D4_PORT |= LCD_D4_BIT;
// SET D5 Port as OUTPUT and Write HIGH to PORT
LCD_D5_DIR  |= LCD_D5_BIT;
LCD_D5_PORT |= LCD_D5_BIT;
// SET D6 Port as OUTPUT and Write HIGH to PORT
LCD_D6_DIR  |= LCD_D6_BIT;
LCD_D6_PORT |= LCD_D6_BIT;
// SET D7 Port as OUTPUT and Write HIGH to PORT
LCD_D7_DIR  |= LCD_D7_BIT;
LCD_D7_PORT |= LCD_D7_BIT;

// Else display an error
#else
#error "Invalid LCD TYPE (That should be either '1' or '2')"
#endif
}

/*** Function    : lcdwrite8Bits
**   Parameters  : None
**   Return      : unsigned char
**   Description : It will write 8-bit to LCD PORT
**/
void lcdwrite8Bits(unsigned char lByte)
{
	if(lByte & 0x80)
		LCD_D7_PORT |=  LCD_D7_BIT;
	else
		LCD_D7_PORT &= ~LCD_D7_BIT;
	if(lByte & 0x40)
		LCD_D6_PORT |=  LCD_D6_BIT;
	else
		LCD_D6_PORT &= ~LCD_D6_BIT;
	if(lByte & 0x20)
		LCD_D5_PORT |=  LCD_D5_BIT;
	else
		LCD_D5_PORT &= ~LCD_D5_BIT;
	if(lByte & 0x10)
		LCD_D4_PORT |=  LCD_D4_BIT;
	else
		LCD_D4_PORT &= ~LCD_D4_BIT;
#if LCD_MODE == 1
	if(lByte & 0x08)
			LCD_D3_PORT |=  LCD_D3_BIT;
		else
			LCD_D3_PORT &= ~LCD_D3_BIT;
		if(lByte & 0x04)
			LCD_D2_PORT |=  LCD_D2_BIT;
		else
			LCD_D2_PORT &= ~LCD_D2_BIT;
		if(lByte & 0x02)
			LCD_D1_PORT |=  LCD_D1_BIT;
		else
			LCD_D1_PORT &= ~LCD_D1_BIT;
		if(lByte & 0x01)
			LCD_D0_PORT |=  LCD_D0_BIT;
		else
			LCD_D0_PORT &= ~LCD_D0_BIT;
#endif
lcdEnable();
}

#define	LOWNIB(x)	P1OUT = (P1OUT & 0xF0) + (x & 0x0F)

/*** Function    : lcdwrite4Bits
**   Parameters  : None
**   Return      : unsigned char
**   Description : It will write 4-bit to LCD PORT
**/
void lcdwrite4Bits(unsigned char val)
{
	if(val & 0x08)
		LCD_D7_PORT |=  LCD_D7_BIT;
	else
		LCD_D7_PORT &= ~LCD_D7_BIT;
	if(val & 0x04)
		LCD_D6_PORT |=  LCD_D6_BIT;
	else
		LCD_D6_PORT &= ~LCD_D6_BIT;
	if(val & 0x02)
		LCD_D5_PORT |=  LCD_D5_BIT;
	else
		LCD_D5_PORT &= ~LCD_D5_BIT;
	if(val & 0x01)
		LCD_D4_PORT |=  LCD_D4_BIT;
	else
		LCD_D4_PORT &= ~LCD_D4_BIT;
	lcdEnable();
}

/*** Function    : lcdSendbyte
**   Parameters  : None
**   Return      : unsigned char
**   Description : It will Send byte to LCD based on 8-bit/4-bit
**/
void lcdSendbyte(unsigned char lByte)
{
    #if LCD_MODE == 1
	lcdwrite8Bits(lByte);
    #elif LCD_MODE == 2
	lcdwrite4Bits(lByte >> 4);
	lcdwrite4Bits(lByte);
	__delay_ms__(5);
    #endif
}

/*** Function    : lcd_command
**   Parameters  : None
**   Return      : unsigned char
**   Description : It will Send byte to lcd as command
**/
void lcd_command(unsigned char lByte)
{
	LCD_ENABLE_LOW;
	LCD_COMMAND_MODE_RS;
	lcdSendbyte(lByte);
}

/*** Function    : lcd_data
**   Parameters  : None
**   Return      : unsigned char
**   Description : It will Send byte to LCD as data
**/
void lcd_data(unsigned char lByte)
{
	LCD_ENABLE_LOW;
	LCD_DATA_MODE_RS;
	lcdSendbyte(lByte);
}

/*** Function    : lcd_data
**   Parameters  : None
**   Return      : unsigned char
**   Description : It will send one char to LCD as data
**/
void lcdWrite(unsigned char lByte)
{
	lcd_data(lByte);
}

/*** Function    : lcdPrint
**   Parameters  : None
**   Return      : unsigned char*
**   Description : It will send String to LCD
**/
void lcdPrint(unsigned char *lByte)
{
	for(;*lByte!='\0';lByte++)
	lcdWrite(*lByte);
}

/*** Function    : lcdSetCursor
**   Parameters  : None
**   Return      : int,int
**   Description : It will set row and column of the lcd
**/
void lcdSetCursor(int line,int col)
{
#if _LCD_TYPE_ == 1
if(line==1)
lcd_command(LCD_ADDRESS_ROW1 + col);
else if(line == 2)
lcd_command(LCD_ADDRESS_ROW2 + col);
else if(line == 3)
lcd_command(LCD_ADDRESS_ROW3 + col);
else
lcd_command(LCD_ADDRESS_ROW4 + col);
#elif _LCD_TYPE_ == 2
if(line==1)
lcd_command(LCD_ADDRESS_ROW1 + col);
else
lcd_command(LCD_ADDRESS_ROW2 + col);
#endif
}

/*** Function    : lcdClear
**   Parameters  : None
**   Return      : None
**   Description : It will Clear the LCD screen and DDRAM of the LCD
**/
void lcdClear(void)
{
	lcd_command(LCD_CLEAR_ALSO_DDRAM);
}

/*** Function    : lcdReset
**   Parameters  : None
**   Return      : None
**   Description : It will Reset the LCD for 4-bit Mode
**/
void lcdReset(void)
{
	LCD_D7_PORT &= ~LCD_D7_BIT;
	LCD_D6_PORT &= ~LCD_D6_BIT;
	LCD_D5_PORT |= LCD_D5_BIT;
	LCD_D4_PORT |= LCD_D4_BIT;

	lcdEnable();
	__delay_ms__(10);
	lcdEnable();
	__delay_ms__(10);
	lcdEnable();
	__delay_ms__(10);

	LCD_D7_PORT &= ~LCD_D7_BIT;
	LCD_D6_PORT &= ~LCD_D6_BIT;
	LCD_D5_PORT |= LCD_D5_BIT;
	LCD_D4_PORT &= ~LCD_D4_BIT;

	lcdEnable();
	__delay_ms__(10);
}

/*** Function    : lcdBegin
**   Parameters  : None
**   Return      : None
**   Description : It will initiate the lcd
**/
void lcdBegin(void)
{
	lcd_port_init();
    #if LCD_MODE == 1
	lcd_command(LCD_8BIT_2_LINE_5_x_7);
	_lcd_delay;
    #elif LCD_MODE == 2
	lcdReset();
	lcd_command(LCD_4BIT_2_LINE_5_x_7);
    #endif
	lcd_command(LCD_DISPLAY_ON_CURSOR_OFF);
	lcd_command(LCD_CLEAR_ALSO_DDRAM);
	lcd_command(LCD_ADDRESS_ROW1);
}

/*** Function    : lcdWriteint
**   Parameters  : None
**   Return      : None
**   Description : It will initiate the lcd
**/
void lcdWriteint(signed int num)
{
char *tempBuffer;
sprintf(tempBuffer,"%d",num);
lcdPrint((unsigned char*)tempBuffer);
}


