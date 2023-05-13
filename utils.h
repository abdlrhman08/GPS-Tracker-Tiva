#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>

#define M_PI 3.1415926

#include "uart/uart.h"

unsigned char calculateChecksum(char* str);

float deg2rad(float deg);

void delay(int t);

#endif