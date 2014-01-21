#ifndef __i2c_h__
#define __i2c_h__

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

// Port Definitions
#define SDADIR P1
#define SCLDIR P1

#define SDAOUT P1
#define SCLOUT P1

#define SDAIN  P1
#define SCLIN  P1

#define SDABIT 1 << 0
#define SCLBIT 1 << 1

#define SDA ( (SDAIN & 0x00) & (SDABIT) )
#define SCL ( (SCLIN & 0x00) & (SCLBIT) )

#define I2C_CLOCK_VAR                    10
#define I2C_SCAN_TIMEOUT_COUNTER_VAL     100

/***************** Prototypes ******************************/
extern unsigned char i2cbegin(unsigned char);
extern unsigned char i2cavailable(void);
extern void          i2cStart(void);
extern void          i2cStop(void);
extern void          i2cSend(unsigned char);
extern unsigned char i2cReceive(unsigned char);
extern void          i2cWrite(unsigned char,unsigned char);
extern unsigned char i2cRead(unsigned char);
extern void          i2csetAdd(unsigned char);
/***********************************************************/

#endif