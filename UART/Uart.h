//
// Created by zyn66 on 5/3/2023.
//

#include "needed_files/tm4c123gh6pm.h"
#include "needed_files/hw_uart.h"
#include "needed_files/hw_memmap.h"
#include "needed_files/hw_gpio.h"
#include "needed_files/hw_sysctl.h"
#include "needed_files/hw_types.h"


#define baudRate 9600
#define CLDIV  (int) (((16000000.0) / ((16.0) * (baudRate))))
#define UART_STRING_BUFFER_SIZE 80
#define GPIO_PIN_0              0x00000001  // GPIO pin 0
#define GPIO_PIN_1              0x00000002  // GPIO pin 1
#define GPIO_PIN_2              0x00000004  // GPIO pin 2
#define GPIO_PIN_3              0x00000008  // GPIO pin 3
#define GPIO_PIN_4              0x00000010  // GPIO pin 4
#define GPIO_PIN_5              0x00000020  // GPIO pin 5
#define GPIO_PIN_6              0x00000040  // GPIO pin 6
#define GPIO_PIN_7              0x00000080  // GPIO pin 7


void UartInitialize(uint32_t ui32Base);
char uartGetChar(uint32_t ui32Base);
void UartGetString(uint32_t ui32Base, char *pcStr, uint8_t ui8StopChar);
void uartSendChar(uint32_t ui32Base, char c);
void uartSendString(uint32_t ui32Base, const char* pcStr);
