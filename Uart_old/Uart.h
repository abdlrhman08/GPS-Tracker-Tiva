#include <stdint.h>
#include "tm4c123gh6pm.h"

#define SYSCTL_RCGCUART 0x400FE618
#define SYSCTL_RCGCGPIO 0x400FE608
#define SYSCTL_PRGPIO 0x400FEA08

#define GPIO_PORTA_DEN 0x4000451C
#define GPIO_PORTA_AFSEL 0x40004420
#define GPIO_PORTA_PCTL 0x4000452C

#define UART0_IBRD 0x4000C024
#define UART0_FBRD 0x4000C028
#define UART0_LCRH 0x4000C02C
#define UART0_CTL 0x4000C030
#define UART0_FR 0x4000C018
#define UART0_DR 0x4000C000

#define TXFULL 0x00000020
#define RXEMPTY 0x00000010

void UART_Initialize(uint8_t UartNum, char PortLetter);
void UART_WriteChar(uint8_t UartNum ,unsigned char ch);
unsigned char UART_ReadChar(uint8_t UartNum);
void UART_WriteString(uint8_t UartNum ,char* str);
void UART_ReadString(uint8_t UartNum ,char* str, char stopCh);


