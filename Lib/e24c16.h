#ifndef e24c16_H_
#define e24c16_H_

#include <avr/io.h>  // Подключаем определения

// Prototipes
void e24c16Write(uint8_t adress, uint8_t data);
uint8_t e24c16Read(uint8_t adress);


#endif
