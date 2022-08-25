#ifndef USART_H_
#define USART_H_

#include <avr/io.h>  // Подключаем определения

// Prototipes
void UsartInit(long int UartSpeed);
void UsartWrite(unsigned char data);
unsigned char UsartRead(void);


#endif
