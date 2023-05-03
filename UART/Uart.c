//
// Created by zyn66 on 5/3/2023.
//

#include <stdint.h>
#include "Uart.h"

// if you want to use type(UART0_BASE,UART1_BASE,.....)

void UartInitialize(uint32_t ui32Base)
{
    // Enable the UART peripheral
    HWREG(SYSCTL_RCGCUART) |= (1 << ((ui32Base - UART0_BASE) / 0x1000));

    // Enable the GPIO port that is used for the UART pins
    uint32_t ui32Port = (ui32Base == UART0_BASE) ? GPIO_PORTA_BASE : GPIO_PORTB_BASE;
    HWREG(SYSCTL_RCGCGPIO) |= (1 << ((ui32Base - UART0_BASE) / 0x1000));

    // Configure the UART pins
    HWREG(ui32Port + GPIO_O_DEN) |= (GPIO_PIN_0 | GPIO_PIN_1);
    HWREG(ui32Port + GPIO_O_PUR) |= GPIO_PIN_0;
    HWREG(ui32Base + UART_O_CTL) &= ~(UART_CTL_UARTEN);
    HWREG(ui32Base + UART_O_CTL) |= UART_CTL_EOT;
    HWREG(ui32Base + UART_O_CTL) &= ~(UART_CTL_LBE);
    HWREG(ui32Base + UART_O_IBRD) = CLDIV / (16 * baudRate);
    HWREG(ui32Base + UART_O_FBRD) = ((64 * CLDIV) % (16 * baudRate)) / (16 * baudRate);
    HWREG(ui32Base + UART_O_LCRH) = UART_LCRH_WLEN_8 ;
    HWREG(ui32Base + UART_O_CTL) |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
}

char uartGetChar(uint32_t ui32Base)
{
    char c;

    // Wait for a character to be received
    while(!(HWREG(ui32Base + UART_O_FR) & UART_FR_RXFE));

    // Read the received character
    c = HWREG(ui32Base + UART_O_DR) & 0xFF;

    return c;
}

void UartGetString(uint32_t ui32Base, char *pcStr, uint8_t ui8StopChar)
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

