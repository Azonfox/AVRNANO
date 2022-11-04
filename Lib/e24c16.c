#include "i2c.h"
#include "e24c16.h"

#define ChipAdr 0b10100000

// Запись байта
void e24c16Write(uint16_t adr16, uint8_t data){
	I2cStart();
	I2cWrite(ChipAdr|((uint8_t)((adr16&0x700)>>7)+0)); //write
	I2cWrite((uint8_t)(adr16&0x00FF)); //adress
	I2cWrite(data);
	I2cStop();
}

// Чтение байта
uint8_t e24c16Read(uint16_t adr16){
	uint8_t data;
	I2cStart();
	I2cWrite(ChipAdr|((uint8_t)((adr16&0x700)>>7)+0)); //write
	I2cWrite((uint8_t)(adr16&0x00FF)); //adress
	I2cStart();
	I2cWrite(ChipAdr|((uint8_t)((adr16&0x700)>>7)+1)); //read
	data=I2cReadNACK();
	I2cStop();
	return data;	
}
