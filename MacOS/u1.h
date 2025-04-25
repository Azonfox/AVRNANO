/*  arduino nano u1 hard file */ 
#ifndef U1_H
#define U1_H

#define F_CPU 16000000UL // Указываем тактовую частоту МК
#include <avr/io.h>      // Подключаем определения ввода/вывода
#include <util/delay.h> 
#include <avr/eeprom.h>  // Funtion and Build file .eep 
#include <avr/interrupt.h> 
#include <stdint.h>

#define LedBoard PB5     // Cветодиод самой платы
#define LedPWM   PB0     // Cветодиод PWM
#define LedRgbB  PB1     // Cветодиод Rgb B
#define LedRgbG  PB2     // Cветодиод Rgb G
#define LedRgbR  PB3     // Cветодиод Rgb R
#define Led0     PC0     // Cветодиод c0
#define Led1     PC1     // Cветодиод c1
#define Led2     PC2     // Cветодиод c2

#endif
