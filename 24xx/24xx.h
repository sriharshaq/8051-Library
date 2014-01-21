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
**   File       : 24xx.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the EEPROM(24xx Series) driver include file for 8051 family MCU's
***/

#ifndef __24xx_h__
#define __24xx_h__

#define 24XX_ADDRESS 0x00

#define 24xxBegin(val)       i2cBegin(val)
#define 24xxBusy()           i2cavailable()
#define 24xxWrite(val1,val2) i2cWrite(val1,val2)
#define 24xxRead(val)        i2cRead(val)
#define 24xxAddress(val)     i2csetAdd(val)

#endif

