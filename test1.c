/* arduino nano u1
 * Изучение отладочной платы на atmega328P
 */ 
#define F_CPU 16000000UL // Указываем тактовую частоту МК
#include <avr/io.h>      // Подключаем определения ввода/вывода
#include <util/delay.h> 

#define LedBoard PB5     // Cветодиод сатой платы
#define LedPWM   PB0     // Cветодиод PWM
#define LedRgbB  PB1     // Cветодиод Rgb B
#define LedRgbG  PB2     // Cветодиод Rgb G
#define LedRgbR  PB3     // Cветодиод Rgb R
#define Led0     PC0     // Cветодиод c0
#define Led1     PC1     // Cветодиод c1
#define Led2     PC2     // Cветодиод c2

#define delms 250

int main(void){
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
