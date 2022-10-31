#include "i2c.h"
#include "e24c16.h"

// Запись байта
void e24c16Write(uint8_t data){
	I2cStart();
	I2cWrite(0XA0+0); //wrte
	I2cWrite(0); //adress
	I2cWrite(data);
	I2cStop();
}

// Чтение байта
uint8_t e24c16Read(){
	uint8_t data;
	I2cStart();
	I2cWrite(0XA0+0); //write
	I2cWrite(0); //adress
	I2cStart();
	I2cWrite(0XA0+1); //read
	data=I2cReadNACK();
	I2cStop();
	return data;	
}
