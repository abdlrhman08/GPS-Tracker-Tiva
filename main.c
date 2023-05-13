/* TODO: 1.ESP functionality (URGENT)
*				 2. Distance accumulation (URGENT) (Done)
*				 3.	LCD
*				 4. Timers instead of delay (not urgent)
*				 5. Linear distance
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "gpio/gpio.h"
#include "esp/esp.h"
#include "uart/UART.h"
#include "gps/gps.h"
#include "utils.h"

char longitude[30];
char latitude[30];
char time[20];
char speed[10];
char buffer[120];

char wifiTest[20];

float prevLat, prevLong;

float accDistance, distance;

bool firstRead = true;

void SystemInit() {}
	
int main() {
	
	initPort(PortF);
	initPort(PortC);
	
	pinOutput(PortC, 5);
	pinHigh(PortC, 5);
	
	UARTInitialize(UART0_BASE, GPIO_PORTA_BASE, UART0_RX_PIN, UART0_TX_PIN, 9600);
	UARTInitialize(UART1_BASE, GPIO_PORTB_BASE, UART1_RX_PIN, UART1_TX_PIN, 9600);
	UARTInitialize(UART3_BASE, GPIO_PORTC_BASE, UART3_RX_PIN, UART3_TX_PIN, 115200);
	
	delay(50000);
	uartSendString(UART0_BASE, "Initialization started\r\n");
	
	delay(50000);
	
	sendGPSCommand(UART1_BASE, "PUBX,40,GLL,0,0,0,0");
	sendGPSCommand(UART1_BASE, "PUBX,40,GSA,0,0,0,0");
	sendGPSCommand(UART1_BASE, "PUBX,40,GSV,0,0,0,0");
	sendGPSCommand(UART1_BASE, "PUBX,40,GGA,0,0,0,0");
	sendGPSCommand(UART1_BASE, "PUBX,40,VTG,0,0,0,0");
	
	delay(10000);
	
	while(1) {
		memset(buffer, 0, 120*sizeof(char));
		memset(longitude, 0, 30*sizeof(char));
		memset(latitude, 0, 30*sizeof(char));
		memset(speed, 0, 10*sizeof(char));
		
		UartGetString(UART1_BASE, buffer, '\n');

		if (checkValidity(buffer)) {
			
			get_Time(buffer, time);
			get_Longitude(buffer, longitude);
			get_Latitude(buffer, latitude);
			get_Speed(buffer, speed);
			
			if (firstRead) {
				prevLat = lat_degrees_value;
				prevLong = long_degrees_value;
				firstRead = false;
			}
			distance = calcDistance_float(lat_degrees_value, long_degrees_value, prevLat, prevLong);
			
			if (distance > 1.5)
				accDistance += distance;
			
			prevLat = lat_degrees_value;
			prevLong = long_degrees_value;
			
		} else {
			uartSendString(UART0_BASE, "Searching for satellites\r");
			continue;
		}
		
		memset(buffer, 0, 120*sizeof(char));
		sprintf(buffer, "Current time %s \r\nCurrent longitude %s \r\nCurrent latitude %s \r\nCurrent Speed %s \r\nDistance %f\r\n", time, longitude, latitude, speed, accDistance);
		
		uartSendString(UART0_BASE, buffer);
		
		delay(25000);
		pinHigh(PortF, RED_LED);
		delay(150000);
		pinLow(PortF, RED_LED);
		
	}
		
	return 0;
}