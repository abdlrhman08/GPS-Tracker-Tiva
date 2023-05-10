#include <stdint.h>
#include "tm4c123gh6pm.h"
#define TXFULL 0x00000020
#define RXEMPTY 0x00000010

void UART_Initialize(uint8_t UartNum, char PortLetter);
void UART_WriteChar(uint8_t UartNum ,unsigned char ch);
unsigned char UART_ReadChar(uint8_t UartNum);
void UART_WriteString(uint8_t UartNum ,char* str);
void UART_ReadString(uint8_t UartNum ,char* str, char stopCh);
