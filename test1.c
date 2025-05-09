/* arduino nano u1
 * �������� ���������� ����� �� atmega328P
 */ 
#include <u1.h>      // ���������� ����������� �����/������
#include "./Lib/usart.h"
#include "./Lib/i2c.h"
#include "./Lib/e24c16.h"

#define delms 50

int main(void){

	uint8_t temp;
	UsartInit(9600); 
 	I2cInit(100000);
	
	for (uint16_t i=0; i<2048;i++){
		e24c16Write(i,(uint8_t)(i&0xFF)); 
		_delay_ms(10);
	}
	
	_delay_ms(100);
	for (uint16_t i=0; i<2048;i++){
		temp=e24c16Read(i);
		UsartWrite(temp);
		_delay_ms(10);
		}


  DDRB |= (1<<LedBoard)|(1<<LedPWM)|(1<<LedRgbB)|(1<<LedRgbG)|(1<<LedRgbR);     // ������������� ��� ��� �����
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
