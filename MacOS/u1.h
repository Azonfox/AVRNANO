/*  arduino nano u1 hard file */ 
#ifndef U1_H
#define U1_H

#define F_CPU 16000000UL // ��������� �������� ������� ��
#include <avr/io.h>      // ���������� ����������� �����/������
#include <util/delay.h> 
#include <avr/eeprom.h>  // Funtion and Build file .eep 
#include <avr/interrupt.h> 
#include <stdint.h>

#define LedBoard PB5     // C�������� ����� �����
#define LedPWM   PB0     // C�������� PWM
#define LedRgbB  PB1     // C�������� Rgb B
#define LedRgbG  PB2     // C�������� Rgb G
#define LedRgbR  PB3     // C�������� Rgb R
#define Led0     PC0     // C�������� c0
#define Led1     PC1     // C�������� c1
#define Led2     PC2     // C�������� c2

#endif
