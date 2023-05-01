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
		char buffer[80] = {0} ;
		char output[40];
		readGPS(buffer);
		
		if(parseGPSData(buffer, &GPSInfo.latitude, &GPSInfo.longitude, &GPSInfo.time, &GPSInfo.speed) == 0) {
			char formattedTime[15];
			sprintf(formattedTime, "%i:%i:%i\n",  GPSInfo.time / 10000, (GPSInfo.time / 100) % 100, GPSInfo.time%100);
			UART0_WriteString(formattedTime);
			continue;
		} 
		
		delay(25000);
		UART0_WriteString(search);
		pinHigh(PortF, 3);
		delay(150000);
		pinLow(PortF, 3);
		
	}
		
	return 0;
}