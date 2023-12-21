/* arduino nano u1
 * �������� ���������� ����� �� atmega328P
*/
#define F_CPU 16000000UL // ��������� �������� ������� ��
#include <avr/io.h>      // ���������� ����������� �����/������
#include <util/delay.h> 

#define LedBoard PB5     // C�������� ����� �����
#define LedPWM   PB0     // C�������� PWM
#define LedRgbB  PB1     // C�������� Rgb B
#define LedRgbG  PB2     // C�������� Rgb G
#define LedRgbR  PB3     // C�������� Rgb R
#define Led0     PC0     // C�������� c0
#define Led1     PC1     // C�������� c1
#define Led2     PC2     // C�������� c2

// ������� ������ �� ����������� �� ����������
// ����� ������ �������� & �� ����� ����� ��� ������
// �����  ����� ����� prnt(&PORTB,..)
#define prnt(xport,xname,delms) _prnt(&xport,xname,delms)
void _prnt(volatile uint8_t *xport, uint8_t xname, uint16_t delms) {
	*xport |= (1<<xname);
	_delay_ms(delms);
	*xport &=~(1<<xname);
	_delay_ms(delms);
}

int main(void){
  DDRB |= (1<<LedBoard)|(1<<LedPWM)|(1<<LedRgbB)|(1<<LedRgbG)|(1<<LedRgbR);     // ������������� ��� ��� �����
  DDRC |= (1<<Led0)|(1<<Led1)|(1<<Led2);

  while (1) {
   // Test PWM ��������� ���
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
