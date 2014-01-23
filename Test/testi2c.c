#include <8051.h>
#include "uart.h"

#define SDA P0_0
#define SCL P0_1

void I2CInit(){
SDA = 1;
SCL = 1;
}

void I2CStart(){
SCL = 1;
SDA = 0;
SCL = 0;
}

void I2CRestart(){
SDA = 1;
SCL = 1;
SDA = 0;
}

void I2CStop(){
SDA = 0;
SCL = 1;
SDA = 1;
}

void I2CAck(){
SDA = 0;
SCL = 1;
SCL = 0;
}

void I2CNak(){
SDA = 1;
SCL = 1;
SCL = 0;
}

unsigned char I2CSend(unsigned char Data){
unsigned char i, ack_bit;
for(i=0;i<8;i++){
SCL = 0;
if ((Data & 0x80) == 0)
SDA = 0;
else
SDA = 1;
SCL = 1;
Data<<=1;
}
SCL = 0;
ack_bit = SDA;
SCL = 1;
SCL = 0;
return !ack_bit;
}

unsigned char I2CRead(){
unsigned char i, Data=0;
for(i=0;i<8;i++){
SCL = 0;
SCL = 1;
if(SDA)
Data |=1;
if(i<7)
Data<<=1;
}
SCL = 0;
SDA = 1;
return Data;
}

int main()
{
unsigned char i, a[7], ack;
unsigned int j;
I2CInit();
Serialbegin(9600);
Serialprint("Test Hello I2C");
/* Writing on i2c */
I2CStart();
I2CSend(0xD0);
I2CSend(0x00);
I2CSend(0x00);
I2CSend(0x00);
I2CSend(0x00);
I2CSend(0x03);
I2CSend(0x01);
I2CSend(0x01);
I2CSend(0x13);
I2CStop();

while(1){
/* reading on I2c */
/* Dummy Write */
I2CStart();
I2CSend(0xD0);
I2CSend(0x00);
/* Actual read */
I2CRestart();
I2CSend(0xD1);
for(i=0;i<7;i++){
a[i]=I2CRead();
if(i==6)
I2CNak();
else
I2CAck();
}
I2CStop();
SerialIntWrite(a[2]);
Serialwrite(':');
SerialIntWrite(a[1]);
Serialwrite(':');
SerialIntWrite(a[0]);
SerialIntWrite(a[4]);
Serialwrite('-');
SerialIntWrite(a[5]);
Serialwrite('-');
SerialIntWrite(a[6]);
for(j=65535;j>0;j--);
}
}
