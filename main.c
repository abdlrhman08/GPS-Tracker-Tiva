#include <stdio.h>

#include "gpio/gpio.h"
#include "uart/UART.h"
#include "gps/gps.h"
#include "utils.h"

void SystemInit() {}
	
int main() {
	INFO GPSInfo;
	
	initPort(PortF);
	UartInitialize(UART0_BASE);
	
	delay(50000);
	uartSendString(UART0_BASE, "Initialization started\r\n");
	
	UartInitialize(UART1_BASE);
	
	delay(50000);
	
	sendGPSCommand(UART1_BASE, "PUBX,40,GLL,0,0,0,0");
	sendGPSCommand(UART1_BASE, "PUBX,40,GSA,0,0,0,0");
	sendGPSCommand(UART1_BASE, "PUBX,40,GSV,0,0,0,0");
	sendGPSCommand(UART1_BASE, "PUBX,40,GGA,0,0,0,0");
	sendGPSCommand(UART1_BASE, "PUBX,40,VTG,0,0,0,0");
	
	delay(10000);
	
	while(1) {
		char longitude[30];
		char latitude[30];
		char time[20];
		char buffer[120];
		memset(buffer, 0, 120*sizeof(char));
		memset(longitude, 0, 30*sizeof(char));
		memset(latitude, 0, 30*sizeof(char));
		
		UartGetString(UART1_BASE, buffer, '\n');
		
		if (checkValidity(buffer)) {
			get_Time(buffer, time);
			get_Longitude(buffer, longitude);
			get_Latitude(buffer, latitude);
		}
		
		/* TODO: 1.ESP functionality (URGENT)
		*				 2. Distance calculation (URGENT)
		*				 3.	LCD
		*				 4. Timers instead of delay (not urgent)
		*/
		
		memset(buffer, 0, 120*sizeof(char));
		sprintf(buffer, "Current time %s \r\nCurrent longitude %s \r\n Current latitude %s \r\n", time, longitude, latitude);
		
		delay(25000);
		uartSendString(UART0_BASE, buffer);
		pinHigh(PortF, 3);
		delay(150000);
		pinLow(PortF, 3);
		
	}
		
	return 0;
}