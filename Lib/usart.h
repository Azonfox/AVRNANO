#ifndef USART_H_
#define USART_H_

#include <avr/io.h>  // Подключаем определения

// Prototipes
void UsartInit(long int UartSpeed);
void UsartWrite(uint8_t data);
uint8_t UsartRead(void);


#endif
