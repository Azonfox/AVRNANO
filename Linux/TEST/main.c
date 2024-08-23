//   UCSR0B test
// Новая дешевая плата arduino nano328 из ОЗОН
// не отключает UART после работы загрузчика
// и поэтому пины PD0-PD1 равны 1 при чтении!
// То есть в регистре UCSR0B УСТАНОВЛЕНЫ биты RXEN0 TXEN0
// для продолжения работы с UART RX-TX вместо пинов портов!
// Необходимо отключать UART самому:
// UCSR0B &= ~((1<<RXEN0)|(1<<TXEN0));
// Вот код для проверки новых плат:

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h> 
#define LEDON  PORTB |= (1<<PB5);
#define LEDOFF PORTB &=~(1<<PB5);
int main(){
	//UCSR0B &= ~((1<<RXEN0)|(1<<TXEN0)); // Чтобы убедиться
	DDRB = 0b00111111; 	//OUTPUT
	// Если UCSR0B не чист, то часто моргаем, иначе медленно
	if(UCSR0B==0x18) {
		for(char i=0; i<45; i++){
		   LEDON;  _delay_ms(30);
		   LEDOFF; _delay_ms(30);
		}
	} else {
		for(char i=0; i<5; i++){
		   LEDON;  _delay_ms(500);
		   LEDOFF; _delay_ms(500);
		}
	}
}
