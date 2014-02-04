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
**   File       : hc05.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is include file of HC-05 Driver for 8051 family MCU's
***/

#ifndef __hc05_h__
#define __hc05_h__

#include "uart.h"

#define COMMAND_TEST_COMMUNICATION   "AT"
#define COMMAND_GET_VERSION          "AT+VERSION?"
#define COMMAND_SET_DEFAULT          "AT+ORGL"
#define COMMAND_GET_ADDRESS          "AT+ADDR?"
#define COMMAND_GET_MOD_NAME         "AT+NAME?"
#define COMMAND_SET_MOD_NAME         "AT+NAME="   // AT+NAME=<param> ; here param is module name    
#define COMMAND_GET_DEV_NAME         "AT+RNAME?"  // AT+RNAME?<param> ; param is address of bluetooth device
#define COMMAND_GET_MOD_MODE         "AT+ROLE?"
#define COMMAND_SET_MOD_MODE         "AT+ROLE="

#define HC05_BAUDRATE                38400


#endif

