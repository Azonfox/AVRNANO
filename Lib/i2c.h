#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>  // Подключаем определения

// Prototipes
void I2C_Init();
byte I2C_Detect(byte addr);
byte I2C_FindDevice(byte start);
void I2C_Start (byte slaveAddr);
byte I2C_Write (byte data);
byte I2C_ReadACK ();
byte I2C_ReadNACK ();
void I2C_WriteByte(byte busAddr, byte data);
void I2C_WriteRegister(byte busAddr, byte deviceRegister, byte data);
byte I2C_ReadRegister(byte busAddr, byte deviceRegister);


#endif
