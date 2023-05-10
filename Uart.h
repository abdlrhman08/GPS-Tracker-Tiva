#include <stdint.h>
#include "tm4c123gh6pm.h"
#define TXFULL 0x00000020
#define RXEMPTY 0x00000010

void UartInitialize(uint8_t UartNum, char PortLetter);
void UART_WriteChar(unsigned char ch);
unsigned char UART_ReadChar(void);
void UART_WriteString(char* str);
void UART_ReadString(char* str, char stopCh);

