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
**   File       : r303a.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the R1303A Fingerprint Driver include file for 8051 family MCU's
***/

#ifndef __r303a_h__
#define __r303a_h__

#ifndef SDCC
#define SDCC 0
#endif
#ifndef KEIL
#define KEIL 1
#endif

#ifndef TOOLCHAIN
#define TOOLCHAIN SDCC
#endif

#if TOOLCHAIN   == SDCC
#include <8051.h>             // 8051 Peripheral Address preprocessor file
#elif TOOLCHAIN == KEIL
#include <reg51.h>
#else
#error "Invalid Toolchain, Please check 'TOOLCHAIN' macro (SDCC/KEIL)"
#endif

// Acknowledgements
#define EXEC_COMPLETE                                       0x00
#define ERROR_RECV_DATA_PACK                                0x01
#define NO_FINGER_ON_SENSOR                                 0x02
#define FAIL_TO_ENROLL_FINGER                               0x03
#define FAIL_OVER_DISORDER_FINGER_IMAGE                     0x06
#define FAIL_LACKNESS_CHAR_POINT_FINGER_IMAGE               0x07
#define FINGER_MIS_MATCH                                    0x08
#define FAIL_TO_FIND_MATCH_FINGER                           0x09
#define FAIL_TO_COMBINE_CHAR_FILE                           0x0A
#define ADDRESS_PAGE_ID_EXCEEDS_LIMIT                       0x0B
#define ERROR_READING_TEMPLATE                              0x0C
#define ERROR_UPLOAD_TEMPLATE                               0x0D
#define CANT_RECV_DATA_FOLLW_DATA_PACK                      0x0E
#define ERROR_TO_UPLOAD_IMAGE                               0x0F
#define FAIL_TO_DELETE_FROM_LIB                             0x10
#define FAIL_TO_CLEAR_FING_LIB                              0x11
#define WRONG_PASSWORD                                      0x13
#define FAIL_TO_GEN_IMAGE_FOR_LACKNESS_PRIMARY_IMAGE        0x15
#define ERRROR_WHILE_WRITING_TO_FLASH                       0x18
#define NO_DEFINITION_ERROR                                 0x19
#define INVALID_REG_NUMBER                                  0x1A
#define INCORRET_CONF_REG                                   0x1B
#define WRONG_NOTEPAD_PAGE_NUMBER                           0x1C
#define FAIL_TO_OPERATE_COM_PORT                            0x1D

/** PACKET FORMAT

/*** [Header (2 Bytes)] [ Adder (4 Bytes)] [PACKAGE_ID (1 Byte)] [PACKAGE_LEN (2 Bytes)] [PACKAGE_CONTENT ()] [CHECKSUM (2 Byte)] ***/

// Prototypes



#endif