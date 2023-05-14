#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

#include "uart/uart.h"

#define M_PI 3.1415926

#define LOG(message) uartSendString(UART0_BASE, message)
#define LOG_CHAR(message) uartSendChar(UART0_BASE, message)

unsigned char calculateChecksum(char* str);

float deg2rad(float deg);

void delay_us(int t);
void delay_ms(int t);

void substr(char* src, int pos, int len, char* dest);

void initSystick();

#endif