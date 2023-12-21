/* arduino nano u1
 * Изучение отладочной платы на atmega328P
*/
#define F_CPU 16000000UL // Указываем тактовую частоту МК
#include <avr/io.h>      // Подключаем определения ввода/вывода
#include <util/delay.h> 

#define LedBoard PB5     // Cветодиод самой платы
#define LedPWM   PB0     // Cветодиод PWM
#define LedRgbB  PB1     // Cветодиод Rgb B
#define LedRgbG  PB2     // Cветодиод Rgb G
#define LedRgbR  PB3     // Cветодиод Rgb R
#define Led0     PC0     // Cветодиод c0
#define Led1     PC1     // Cветодиод c1
#define Led2     PC2     // Cветодиод c2

// Функция работы со светодиодом по указателям
// через макрос удаления & из имени порта при вызове
// иначе  вызов будет prnt(&PORTB,..)
#define prnt(xport,xname,delms) _prnt(&xport,xname,delms)
void _prnt(volatile uint8_t *xport, uint8_t xname, uint16_t delms) {
	*xport |= (1<<xname);
	_delay_ms(delms);
	*xport &=~(1<<xname);
	_delay_ms(delms);
}

int main(void){
  DDRB |= (1<<LedBoard)|(1<<LedPWM)|(1<<LedRgbB)|(1<<LedRgbG)|(1<<LedRgbR);     // конфигурируем пин как выход
  DDRC |= (1<<Led0)|(1<<Led1)|(1<<Led2);

  while (1) {
   // Test PWM несколько раз
   for (uint8_t i=0;i<10;i++){
     prnt(PORTB,LedPWM,30);
   }
   // Test Led0-2
   prnt(PORTC,Led0,200);
   prnt(PORTC,Led1,200);
   prnt(PORTC,Led2,200);
   // Mini Test Rgb
   prnt(PORTB,LedRgbR,300);
   prnt(PORTB,LedRgbG,300);
   prnt(PORTB,LedRgbB,300);
   // LedBoard NANO
   prnt(PORTB,LedBoard,500);
  }
}
