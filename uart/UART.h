//
// Created by zyn66 on 5/3/2023.
//
#ifndef UART_H
#define UART_H

#include <stdbool.h>
#include "needed_files/tm4c123gh6pm.h"
#include "needed_files/hw_uart.h"
#include "needed_files/hw_memmap.h"
#include "needed_files/hw_gpio.h"
#include "needed_files/hw_sysctl.h"
#include "needed_files/hw_types.h"

typedef enum {
    UART_OK = 1,
    UART_ERROR = 0
} UART_Status;


#define UART_STRING_BUFFER_SIZE 80
#define UART0_RX_PIN 0
#define UART0_TX_PIN 1

// UART1
#define UART1_RX_PIN 0
#define UART1_TX_PIN 1

// UART2
#define UART2_RX_PIN 6
#define UART2_TX_PIN 7

// UART3
#define UART3_RX_PIN 6
#define UART3_TX_PIN 7

// UART4
#define UART4_RX_PIN 4
#define UART4_TX_PIN 5

// UART5
#define UART5_RX_PIN 4
#define UART5_TX_PIN 5

// UART6
#define UART6_RX_PIN 4
#define UART6_TX_PIN 5

// UART7
#define UART7_RX_PIN 0
#define UART7_TX_PIN 1n 7

void UartGetString(uint32_t ui32Base, char *pcStr, uint8_t ui8StopChar);
void uartSendChar(uint32_t ui32Base, char c);
void uartSendString(uint32_t ui32Base, const char* pcStr);
char uartGetChar(uint32_t ui32Base);
void UARTInitialize(uint32_t ui32Base, uint32_t ui32GPIOPort, uint8_t ui8GPIOPinRX, uint8_t ui8GPIOPinTX, int baudRate);
void oneMilliSecond(uint32_t ms);
void hundredMicroSecounds(void);
bool UARTCharsAvail(uint32_t ui32Base);
uint32_t UARTCharGetNonBlocking(uint32_t ui32Base, char *pcData);

#endif /* UART_H */