#include <stdio.h>

#include "gpio/gpio.h"
#include "uart/UART.h"
#include "gps/gps.h"
#include "utils.h"

void SystemInit() {}
	
int main() {
	INFO GPSInfo;
	
	char* search = "Searching for satellites\n";
	
	initPort(PortF);
	UartInitialize(UART0_BASE);
	
	delay(50000);
	uartSendString(UART0_BASE, "Waiting for GPS Signal\n");
	
	UartInitialize(UART1_BASE);
	
	delay(50000);
	
	/*
	sendGPSCommand("PUBX,40,GLL,0,0,0,0");
	sendGPSCommand("PUBX,40,GSA,0,0,0,0");
	sendGPSCommand("PUBX,40,GSV,0,0,0,0");
	sendGPSCommand("PUBX,40,GGA,0,0,0,0");
	sendGPSCommand("PUBX,40,VTG,0,0,0,0");
	*/
	delay(10000);
	
	while(1) {
		char output[40];
		char buffer[80];
		memset(buffer, 0, 80*sizeof(char));
		
		
		UartGetString(UART1_BASE, buffer, '\n');
		//readGPS(buffer);
		
		/*if(parseGPSData(buffer, &GPSInfo.latitude, &GPSInfo.longitude, &GPSInfo.time, &GPSInfo.speed) == 0) {
			char formattedTime[15];
			sprintf(formattedTime, "%02i:%02i:%02i\n",  GPSInfo.time / 10000, (GPSInfo.time / 100) % 100, GPSInfo.time%100);
			UART0_WriteString(formattedTime);
			continue;
		} */
		
		delay(25000);
		uartSendString(UART0_BASE, buffer);
		pinHigh(PortF, 3);
		delay(150000);
		pinLow(PortF, 3);
		
	}
		
	return 0;
}