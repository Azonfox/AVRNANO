#include "i2c.h"

// �������������  �������� I2C
void I2cInit(uint32_t I2cSpeed) {
   	TWSR = 0;           
   	TWBR = ((F_CPU/I2cSpeed)-16)/2; 
}

// ������ �����
void I2cStart(void) {
  	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
  	while(!(TWCR & (1<<TWINT)));    
}

// ������ ����
void I2cStop(void) {
  	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);    
}

// �������� �����
void I2cWrite(uint8_t data){
   	TWDR = data;            
   	TWCR = (1<<TWINT)|(1<<TWEN); 
   	while(!(TWCR & (1<<TWINT)));
}

// ������ ASK
uint8_t I2cReadACK(){
	uint8_t data;
  	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
  	while(!(TWCR & (1<<TWINT)));
  	data = TWDR;
  	return TWDR;
}

// ������ NASK
uint8_t I2cReadNACK(){
   	uint8_t data;
  	TWCR = (1<<TWINT)|(1<<TWEN);
  	while(!(TWCR & (1<<TWINT)));
  	data = TWDR;
  	return TWDR;
}


