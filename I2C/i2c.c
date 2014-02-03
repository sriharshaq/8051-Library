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
**   File       : i2c.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the i2c driver for 8051 family MCU's
***/

#include "i2c.h"

unsigned char SlaveACK   = 0x00;
unsigned char DevAddress = 0x00;
unsigned char ClockVar   = 0x00;

/*** Function    : _time_out_timer_0__
**   Parameters  : None
**   Return      : None
**   Description : It will give 25ms delay for I2C Detect Timeout
**/
void _time_out_timer_0__(void)
{
TMOD |= 0x01;
TL0   = 0x00;	
TH0   = 0x4C;	
TR0   = 1;	
}

/*** Function    : i2cSetPort
**   Parameters  : None
**   Return      : None
**   Description : It will set the i2c Port
**/
void  i2cSetPort(void)
{
SDADIR |= SDABIT;
SCLDIR |= SCLBIT;
SDA_HIGH;
SCL_HIGH;
}

/*** Function    : i2cDelay
**   Parameters  : unsigned int
**   Return      : None
**   Description : It's delay loop for i2c Clock Generation
**/
void i2cDelay(unsigned int ClockVar)
{
signed char i;
for(i=0;i<=ClockVar;i++)
{
__asm
NOP
__endasm;
}
}

/*** Function    : i2cavailable
**   Parameters  : None
**   Return      : unsigned char
**   Description : It will return's the state of i2c bus (Busy -> 0, Free -> 1)
**/
unsigned char i2cavailable(void)
{
return (!(SDA | SCL));
}

/*** Function    : i2cStart
**   Parameters  : None
**   Return      : None
**   Description : It will Starts the i2c communication
**/
void i2cStart(void)
{
    // This Block will execute contiuous until i2c bus become free
	back:
	if(SDA == 0)
	goto back;
	if(SCL == 0)
	goto back;
	// Start communication
	SDA_HIGH;
	SCL_HIGH;
	i2cClock(ClockVar);
	SDA_LOW;
	SCL_LOW;
}

/*** Function    : i2cStartonce
**   Parameters  : None
**   Return      : None
**   Description : It will start communication without checking bus state
**/
void i2cStartonce(void)
{
	SDA_HIGH;
	SCL_HIGH;
	i2cClock(ClockVar);
	SDA_LOW;
	SCL_LOW;
}

/*** Function    : i2cStop
**   Parameters  : None
**   Return      : None
**   Description : It will stop the i2c communication
**/
void i2cStop(void)
{
	SDA_LOW;
	SCL_HIGH;
    i2cClock(ClockVar);
    SDA_HIGH;
    SCL_LOW;
}

/*** Function    : i2cWritebyte
**   Parameters  : unsigned char (1-Byte value)
**   Return      : None
**   Description : It will write single byte to i2c bus
**/
void i2cWritebyte(unsigned char uByte)
{
	unsigned char MaskByte;
	MaskByte = 0x80;
	do
	{
		if(uByte & MaskByte)
			SDA_HIGH;
		else
			SDA_LOW;
		SCL_HIGH;
		i2cClock(ClockVar);
		SCL_LOW;
		i2cClock(ClockVar);
		MaskByte /= 2;
	}
	while(MaskByte>0);
	SDA_HIGH;
	SCL_HIGH;
	i2cClock(ClockVar);
	SlaveACK = SDA;
	SCL_LOW;
}

/*** Function    : i2cReadbyte
**   Parameters  : unsigned char (Master ACK)
**   Return      : unsigned char (1-Byte value)
**   Description : It will read single byte from i2c bus
**/
unsigned char i2cReadbyte(unsigned char MasterACK)
{
	unsigned char uByte;
	unsigned char MaskByte;
	uByte    = 0;
	MaskByte = 0x80;
	do
	{
		SCL_HIGH;
		if(SDA == 1)
		{
		uByte |= MaskByte;
		}
		SCL_LOW;
		MaskByte /= 2;
	}
	while(MaskByte > 0);
	if(MasterACK==1)
		SDA_HIGH;
	else
		SDA_LOW;
	SCL_LOW;
	SDA_HIGH;
	return uByte;
}

/*** Function    : i2cWrite
**   Parameters  : unsigned char,unsigned char (Data,Address)
**   Return      : unsigned char (1-Byte value)
**   Description : It will write single byte to argued address
**/
void i2cWrite(unsigned char Byte,unsigned char Address)
{
	do
	{
		i2cStart();
		i2cWritebyte(DevAddress);
		if(SlaveACK == 1)
		i2cStop();
	}
	while(SlaveACK==1);
	i2cWritebyte(Address);
	i2cWritebyte(Byte);
	i2cStop();
}

/*** Function    : i2cRead
**   Parameters  : unsigned char (Address)
**   Return      : unsigned char (1-Byte value)
**   Description : It will read single byte from argued address
**/
unsigned char i2cRead(unsigned char Address)
{
	unsigned char ReadByte;
	do
	{
		i2cStart();
		i2cWritebyte(DevAddress);
		if(SlaveACK==1)
		i2cStop();
	}
	while(SlaveACK==1);
	i2cWritebyte(Address);
	i2cStop();
	i2cStart();
	i2cWritebyte(DevAddress+1);
	ReadByte = i2cReadbyte(1);
	i2cStop();
	return ReadByte;
}

/*** Function    : i2cBegin
**   Parameters  : unsigned long (Osc Freq in Hz),unsigned long (Speed in Hz)
**   Return      : unsigned char (1-> Device Detected,0->Device Not Detected)
**   Description : It will read initiate the i2c communication
**/
unsigned char i2cBegin(unsigned long OscFreq,unsigned long Speed)
{
unsigned char teMp = 12 / ((OscFreq / 1000)/1000);
teMp = teMp + CLOCK_ERROR_CORRECTION;
ClockVar = teMp / Speed;
}

/*** Function    : i2csetAdd
**   Parameters  : unsigned char (Device Address)
**   Return      : None
**   Description : It will set the device address for I2C (See global)
**/
void i2csetAdd(unsigned char SlaveAddress)
{
DevAddress = SlaveAddress;
}

/*** Function    : i2cScan
**   Parameters  : unsigned char,unsigned char (start Address,End Address)
**   Return      : unsigned char* (That contain Address Array and Device Count)
**   Description : It will Scan the i2c devices connected to bus
**/
unsigned char* i2cScan(unsigned char startAddress,unsigned char EndAddress)
{
unsigned char i2cAddressArray[10];
unsigned char DeviceCounter = 0;
unsigned char temp;

// Clear the buffer
for(temp = 0;temp <= (EndAddress - startAddress);temp++)
i2cAddressArray[temp] = 0;

// Scan the devices
for(temp = startAddress;temp <= EndAddress;temp++)
{
if(i2cBegin(temp) == 1)
{
DeviceCounter++;
i2cAddressArray[DeviceCounter] = DeviceCounter;
}
}
return i2cAddressArray;
}

/*** Function    : i2cDetect
**   Parameters  : unsigned char (Device Address)
**   Return      : 1 -> If detected, 0 -> If not detected
**   Description : It will Detect the Slave 
**/
unsigned char i2cDetect(unsigned char _Address)
{

}

/*** Function    : i2cWriteBlock
**   Parameters  : unsigned char (Start Address),unsigned char (End Address),unsigned char* (Data)
**   Return      : None
**   Description : It will Write block of data into i2c bus
**/
void i2cWriteBlock(unsigned char sAddress,unsigned char eAddress,unsigned char *dPtr)
{
unsigned char duMmy;
unsigned char i = 0;
for(duMmy=sAddress;i<= eAddress;duMmy++)
{
i2cWrite(dPtr[i],duMmy);
i++;
}
}

/*** Function    : i2cReadBlock
**   Parameters  : unsigned char (Start Address),unsigned char (End Address),unsigned char* (Data)
**   Return      : None
**   Description : It will Read block of data into i2c bus
**/
void i2cReadBlock(unsigned char sAddress,unsigned char eAddress,unsigned char *dPtr)
{
unsigned char duMmy;
unsigned char i = 0;
for(duMmy=sAddress;i<= eAddress;duMmy++)
{
dPtr[i] = i2cRead(duMmy);
i++;
}
}






