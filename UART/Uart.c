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
    // Get the number of bytes available in the receive FIFO
    uint32_t ui32BytesAvailable = UARTCharsAvail(ui32Base);

    // Return true if at least one byte is available, false otherwise
    return (ui32BytesAvailable > 0);
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
void hundredMicroSecounds(void)
{
    NVIC_ST_CTRL_R = NVIC_ST_CTRL_R & ~(0x00000001); //disable Timer
    NVIC_ST_RELOAD_R = (1600000 - 1); 		//to make 1 secound as our Tiva has clk = 16 MHZ
    NVIC_ST_CURRENT_R = 0; 				//to clear counter value and underflow flag of counter
    NVIC_ST_CTRL_R |= 0x5; 				//to put at source clk 1 to get PROCESOR CLK NOT its 8th only and enable Timer
};
void oneMilliSecond(uint32_t ms)
{
    uint32_t delay_cycles = 16000 * ms; //16000 cycles = 1 millisecond
    NVIC_ST_CTRL_R = NVIC_ST_CTRL_R & ~(0x00000001); //disable Timer
    NVIC_ST_RELOAD_R = (delay_cycles - 1); //set the delay value
    NVIC_ST_CURRENT_R = 0; //reset the counter
    NVIC_ST_CTRL_R |= 0x5; //enable and start the Timer
    while((NVIC_ST_CTRL_R & 0x00010000) == 0); //wait for Timer to finish
};