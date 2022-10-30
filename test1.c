/* arduino nano u1
 * Изучение отладочной платы на atmega328P
 */ 
#include <u1.h>      // Подключаем определения ввода/вывода
#include "./Lib/usart.h"
#include "./Lib/i2c.h"

#define delms 500

int main(void){

uint8_t temp;

	UsartInit(9600); 
 	I2cInit(100000);
	
	I2cStart();
	I2cWrite(0XA0+0); //w
	I2cWrite(0); //adr1
//	I2cWrite(0); //adr2
	for(uint8_t i=0; i<8; i++){
		I2cWrite(0X33);
	}
	I2cStop();

						_delay_ms(600);

	I2cStart();
	I2cWrite(0XA0+0); //w
	I2cWrite(0); //adr1
	I2cWrite(0); //adr2
	I2cStart();
	I2cWrite(0XA0+1); //r
	for(uint8_t i=0; i<20; i++){
		temp=I2cReadACK();
	//	UsartWrite(i);
		UsartWrite(temp);
	}
	temp=I2cReadNACK();
	I2cStop();


  DDRB |= (1<<LedBoard)|(1<<LedPWM)|(1<<LedRgbB)|(1<<LedRgbG)|(1<<LedRgbR);     // конфигурируем пин как выход
  DDRC |= (1<<Led0)|(1<<Led1)|(1<<Led2);
  while (1) 
  {
// LedPWM for test Zotek ZT301
	PORTB |= (1<<LedPWM); // 100ms 10Hz
	_delay_ms(delms);
	PORTB &=~(1<<LedPWM); 
	_delay_ms(delms);

// Test Led0-2 green
	PORTC |= (1<<Led0);
		_delay_ms(delms);
	PORTC &=~(1<<Led0); 
	_delay_ms(delms);		
		
	PORTC |= (1<<Led1);
		_delay_ms(delms);
	PORTC &=~(1<<Led1); 
	_delay_ms(delms);	
	
	PORTC |= (1<<Led2);
		_delay_ms(delms);
	PORTC &=~(1<<Led2); 
	_delay_ms(delms);	

// Mini Test Rgb	
	PORTB |= (1<<LedRgbR); // RED
	_delay_ms(delms);
	PORTB &=~(1<<LedRgbR); 
	_delay_ms(delms);
	PORTB |= (1<<LedRgbG); // GREEN
	_delay_ms(delms);
	PORTB &=~(1<<LedRgbG); 
	_delay_ms(delms);
	PORTB |= (1<<LedRgbB); // BLUE
	_delay_ms(delms);
	PORTB &=~(1<<LedRgbB); 
	_delay_ms(delms);

// LedBoard
	PORTB |= (1<<LedBoard); // LedBoard
	_delay_ms(delms);
	PORTB &=~(1<<LedBoard); 
	_delay_ms(delms);
		 
  }
}
