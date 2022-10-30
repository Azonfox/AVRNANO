#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>  // Подключаем определения

// Prototipes
void I2C_Init();
uint8_t I2C_Detect(uint8_t addr);
uint8_t I2C_FindDevice(uint8_t start);
void I2C_Start (uint8_t slaveAddr);
uint8_t I2C_Write (uint8_t data);
uint8_t I2C_ReadACK ();
uint8_t I2C_ReadNACK ();
void I2C_WriteByte(uint8_t busAddr, uint8_t data);
void I2C_WriteRegister(uint8_t busAddr, uint8_t deviceRegister, uint8_t data);
uint8_t I2C_ReadRegister(uint8_t busAddr, uint8_t deviceRegister);


#endif
