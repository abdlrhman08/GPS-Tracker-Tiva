#include <stdio.h>

#include "gpio/gpio.h"
#include "uart/UART.h"
#include "utils.h"

void SystemInit() {}
	
int main() {
	initPort(PortF);
	UART0_Init();
	
	delay(50000);
	UART0_WriteString("Waiting for GPS Signal\n");
	
	UART1_Init();
	
	delay(50000);
	
	sendGPSCommand("PUBX,40,GLL,0,0,0,0");
	sendGPSCommand("PUBX,40,GSA,0,0,0,0");
	sendGPSCommand("PUBX,40,GSV,0,0,0,0");
	sendGPSCommand("PUBX,40,GGA,0,0,0,0");
	sendGPSCommand("PUBX,40,VTG,0,0,0,0");
	
	delay(10000);
	
	while(1) {
		char str[50];
		UART1_ReadString(str, '\n');
		
		str[18] = '\n';
		str[19] = '\0';
		delay(25000);
		UART0_WriteString(str);
		pinHigh(PortF, 3);
		delay(150000);
		pinLow(PortF, 3);
		
	}
		
	return 0;
}