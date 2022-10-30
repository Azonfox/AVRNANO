#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>  // Подключаем определения

// Prototipes
void I2cInit(uint32_t I2cSpeed);
void I2cStart(void);
void I2cStop(void);
void I2cWrite(uint8_t data);
uint8_t I2cReadACK();
uint8_t I2cReadNACK();

#endif
