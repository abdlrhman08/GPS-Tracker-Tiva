#include "Uart.h"

// calculate baud rate
#define baudRate 9600
#define CLDIV  ((16000000.0) / ((16.0) * (baudRate)))
#define uartIBRD ((int)(CLDIV))
#define uartFBRD ((int)((((CLDIV) - (uartIBRD)) * (64)) + (0.5)))

/*
PORT A --> UART 0
PORT B --> UART 1
PORT C --> UART 3 & 4
PORT D --> UART 2 & 6
PORT E --> UART 5 & 7
*/

void UartInitialize(uint8_t UartNum, char PortLetter)
{
    // Enable the UART peripheral
    *((volatile uint32_t*)(SYSCTL_RCGCUART)) |= (1 << UartNum);

    // Enable the GPIO port that is used for the UART pins
    uint32_t PORT_NUM = 0;
    switch (PortLetter) {
    case 'A': PORT_NUM = 0; BREAK;
    case 'B': PORT_NUM = 1; BREAK;
    case 'C': PORT_NUM = 2; BREAK;
    case 'D': PORT_NUM = 3; BREAK;
    case 'E': PORT_NUM = 20; BREAK;
    }

    *((volatile uint32_t*)(SYSCTL_RCGCGPIO)) |= (1 << (PortLetter - 'A'));

    // Wait for the GPIO port to be ready
    while ((*((volatile uint32_t*)(SYSCTL_PRGPIO)) & (1 << (PortLetter - 'A'))) == 0) {}

    //Values for GPIO registers
    if (UartNum == 0 || UartNum == 1 || UartNum == 7) {
        VAL = 0x03;
    }
    else if (UartNum == 2 || UartNum == 4 || UartNum == 5) {
        VAL = 0x30;
    }
    else if (UartNum == 3) {
        VAL = 0xC0;
    }
    // Configure the GPIO pins for UART function
    *((volatile uint32_t*)((GPIO_PORTA_DEN_R)+(PORT_NUM * 0x1000))) |= VAL;
    *((volatile uint32_t*)((GPIO_PORTA_AFSEL_R)+(PORT_NUM * 0x1000))) |= VAL;
    *((volatile uint32_t*)((GPIO_PORTA_PCTL_R)+(PORT_NUM * 0x1000))) |= VAL;

    // Disable UART and all interrupts
    *((volatile uint32_t*)((UART0_CTL_R)+(UartNum * 0x1000))) = 0;

    // set the baud rate integer and fractional values
    *((volatile uint32_t*)((UART0_IBRD_R)+(UartNum * 0x1000))) = uartIBRD;
    *((volatile uint32_t*)((UART0_FBRD_R)+(UartNum * 0x1000))) = uartFBRD;

    // Configure the UART line control settings (enable FIFO, 8 bit data)
    *((volatile uint32_t*)((UART0_LCRH_R)+(UartNum * 0x1000))) |= 0x70;

    // Enable the UART
    *((volatile uint32_t*)((UART0_CTL_R)+(UartNum * 0x1000))) |= 0x301;
}

void UART_WriteChar(unsigned char ch) {
    while ((((UART0_FR_R)+(UartNum * 0x1000)) & TXFULL) != 0) {} //checks if fifo is full
    ((UART0_DR_R)+(UartNum * 0x1000)) = ch;
}

unsigned char UART_ReadChar(void) {
    while ((((UART0_FR_R)+(UartNum * 0x1000)) & RXEMPTY) != 0) {} //checks fifo is empty
    return ((UART0_DR_R)+(UartNum * 0x1000)) & 0xFF; //return character from data register,least significant 8 bits
}

void UART_WriteString(char* str) {
    while (*str) { //loop continue till null character
        UART_WriteChar(*str); //write current character in buffer
        str++; //move to next character
    }
}

void UART_ReadString(char* str, char stopCh) {
    char c = UART_ReadChar(); // read first character
    while (c && c != stopCh) { //checks for stop character or null charcter
        *str = c; // store current character
        str++; //move to next character
        c = UART_ReadChar(); //read next character
    }
    *str = 0x00;  //adding null character
}
