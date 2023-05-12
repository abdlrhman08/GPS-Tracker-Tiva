#include <stdint.h>

#define isdigit(c) (c >= '0' && c <= '9')

#include "uart/uart.h"

unsigned char calculateChecksum(char* str);

double stof(const char* s);

void delay(int t);
