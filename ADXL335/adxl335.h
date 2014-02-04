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
    along with Library for 8051. If not, see <http://www.gnu.org/licenses/>.
/**************************************************************************************************************/


/***
**   File       : adxl335.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is include file for ADXL335 Accelerometer library for 8051 family MCU's
***/

// To read Raw Values
extern int   Adxl335getPureRawX(void);
extern int   Adxl335getPureRawY(void);
extern int   Adxl335getPureRawZ(void);

// To read Calculated raw values (Bias voltage is considered)
extern double Adxl335getCalRawX(void);
extern double Adxl335getCalRawY(void);
extern double Adxl335getCalRawZ(void);

// To read Voltage from X,Y,Z
extern double Adxl335getCalVoltageX(void);
extern double Adxl335getCalVoltageY(void);
extern double Adxl335getCalVoltageZ(void);

// To read g Values
extern double Adxl335get_g_X(void);
extern double Adxl335get_g_Y(void);
extern double Adxl335get_g_Z(void);

#endif
