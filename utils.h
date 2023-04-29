#include <stdlib.h>

#include "uart/uart.h"

unsigned char calculateChecksum(char* str);

void sendGPSCommand(char* command);

void delay(int t) {
	int x = 0;
	int i;
	for (i = 0; i < t; i++) {
			x++;
		}
}

void sendGPSCommand(char* command) {
	unsigned char checkSum = calculateChecksum(command);
	
	char newCommand[27];
	sprintf(newCommand, "$%s*%X\r\n", command, checkSum);
	UART1_WriteString(newCommand);
}

unsigned char calculateChecksum(char* str) {
	uint8_t checkSumChar = 0;
	
	int i;
	for (i = 0; str[i]; i++) {
		checkSumChar ^= str[i];
	}
	
	return (unsigned char)checkSumChar;
}