//
// Created by zyn66 on 5/3/2023.
//

#include <stdint.h>
#include "UART.h"


#ifndef UART_H
#define UART_H

typedef enum {
    UART_OK = 1,
    UART_ERROR = 0
} UART_Status;

#endif /* UART_H */
// if you want to use type(UART0_BASE,UART1_BASE,.....)

void UARTInitialize(uint32_t ui32Base, uint32_t ui32GPIOPort, uint8_t ui8GPIOPinRX, uint8_t ui8GPIOPinTX, int baudRate)
{
double CLDIV = 16000000.0 / (16.0 * baudRate);
// Enable the UART peripheral
HWREG(SYSCTL_RCGCUART) |= (1 << ((ui32Base - UART0_BASE) / 0x1000));

// Enable the GPIO port that is used for the UART pins
HWREG(SYSCTL_RCGCGPIO) |= (1 << ((ui32GPIOPort - GPIO_PORTA_BASE) / 0x1000));

// Configure the UART pins
HWREG(ui32GPIOPort + GPIO_O_DEN) |= (1 << ui8GPIOPinRX) | (1 << ui8GPIOPinTX);
HWREG(ui32GPIOPort + GPIO_O_PUR) |= (1 << ui8GPIOPinRX);
HWREG(ui32GPIOPort + GPIO_O_PCTL) |= (1 << 4*ui8GPIOPinRX) | (1 << 4*ui8GPIOPinTX);

// UART configuration
HWREG(ui32Base + UART_O_CTL) &= ~(UART_CTL_UARTEN);
HWREG(ui32Base + UART_O_CTL) |= UART_CTL_EOT;
HWREG(ui32Base + UART_O_CTL) &= ~(UART_CTL_LBE);
HWREG(ui32Base + UART_O_IBRD) = (int)CLDIV;
HWREG(ui32Base + UART_O_FBRD) = ((int)((((CLDIV) - ((int)(CLDIV))) * (64)) + (0.5)));
HWREG(ui32Base + UART_O_LCRH) = 0x70;
HWREG(ui32Base + UART_O_CTL) |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
HWREG(ui32GPIOPort + GPIO_O_AFSEL) |= (1 << ui8GPIOPinRX) | (1 << ui8GPIOPinTX);
}

char uartGetChar(uint32_t ui32Base)
{
    char c;

    // Wait for a character to be received
    while(((HWREG(ui32Base + UART_O_FR) & UART_FR_RXFE)) != 0);

    // Read the received character
    c = HWREG(ui32Base + UART_O_DR);

    return c;
}
void uartFlushAndDebug(uint32_t ui32Base) {
    volatile uint32_t trash; // Add volatile keyword for correct memory access
 // Explicit typecasting

    while (!(HWREG(ui32Base + UART_O_FR) & UART_FR_RXFE)) { // Explicit typecasting
        trash = (uint32_t)HWREG(ui32Base + UART_O_DR); // Explicit typecasting
    }
	}

void uartGetString(uint32_t ui32Base, char *pcStr, uint8_t ui8StopChar)
{
    uint32_t ui32Count = 0;
    char cChar;

    while (1)
    {
        cChar = uartGetChar(ui32Base);

        if (cChar == ui8StopChar)
        {
            break;
        }

        pcStr[ui32Count] = cChar;
        ui32Count++;

        // Check if the string buffer is full
        if (ui32Count == UART_STRING_BUFFER_SIZE - 1)
        {
            break;
        }
    }

    // Null-terminate the string
    pcStr[ui32Count] = '\0';
}

void uartGetString_useLen(uint32_t ui32Base, char *pcStr, uint8_t bufferLEN) {
	int counter = 0;
	
	while (counter < bufferLEN) {
		pcStr[counter++] = uartGetChar(ui32Base);
	}
	
	pcStr[bufferLEN] = 0;

}


void uartSendChar(uint32_t ui32Base, char c) {
    // Wait until there is space available in the transmit FIFO
    while (HWREG(ui32Base + UART_O_FR) & UART_FR_TXFF);

    // Write the character to the transmit FIFO
    HWREG(ui32Base + UART_O_DR) = c;
}

void uartSendString(uint32_t ui32Base, const char* pcStr) {
    // Loop through the string until we reach the end ('\0')
    while (*pcStr != '\0') {
        // Send the current character
        uartSendChar(ui32Base, *pcStr);

        // Move to the next character in the string
        pcStr++;
    }
}

bool UARTCharsAvail(uint32_t ui32Base)
{
    // Check if there is at least one byte available in the receive FIFO
    return (HWREG(ui32Base + UART_O_FR) & UART_FR_RXFE) == 0;
}

uint32_t UARTCharGetNonBlocking(uint32_t ui32Base, char *pcData)
{
    // Check if there is data in the receive FIFO
    if(UARTCharsAvail(ui32Base))
    {
        // Read the character from the receive FIFO
        *pcData = uartGetChar(ui32Base);
        return UART_OK;
    }
    else
    {
        // There is no data available in the receive FIFO
        return UART_ERROR;
    }
}
