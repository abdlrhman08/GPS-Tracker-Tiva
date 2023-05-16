/* TODO: 1.ESP functionality (URGENT)
*				 2. Distance accumulation (URGENT) (Done)
*				 3.	LCD
*				 4. Timers instead of delay (not urgent) (DONE)
*				 5. Linear distance
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "gpio/gpio.h"
#include "esp/esp.h"
#include "uart/UART.h"
#include "gps/gps.h"
#include "utils.h"
#include "lcd/lcd.h"


#define SSID "iPhone"
#define PASSWORD "aae4mejb"

#define DOMAIN "172.20.10.9"
#define PORT 1350

char longitude[50];
char latitude[50];
char time[50];
char speed[50];
char buffer[256];
char destination[256];
char destinationLat[30];
char destinationLong[30];
char data[40];
char LCD_Text[50];
char serverResponse;

float prevLat, prevLong;
float destLat = 29.996730, destLong = 32.49281;
float Lat, Long;
float currentDistanceFromDest;

float accDistance, distance, linearDistance;

bool firstRead = true;

void LCD_message_R1(char *data);

void SystemInit() {}
	
int main() {
	initPort(PortF);
	initPort(PortC);
	
	//For the songs played by the arduino
	initPort(PortD);

	initSystick();
	
	pinOutput(PortC, 5);
	pinHigh(PortC, 5);
	
	pinOutput(PortD, 6);
	pinOutput(PortD, 7);
	
	UARTInitialize(UART0_BASE, GPIO_PORTA_BASE, UART0_RX_PIN, UART0_TX_PIN, 9600);
	UARTInitialize(UART1_BASE, GPIO_PORTB_BASE, UART1_RX_PIN, UART1_TX_PIN, 9600);
	UARTInitialize(UART3_BASE, GPIO_PORTC_BASE, UART3_RX_PIN, UART3_TX_PIN, 115200);
	
	delay_ms(500);
	
	uartSendString(UART0_BASE, "Initialization started\r\n");
	
	delay_ms(500);
	
	//Wake the ESP and connect it to the server
	if (ESP_Begin(UART3_BASE) && ESP_JoinAccessPoint(SSID, PASSWORD)) {
		LOG("ESP started and Connected to Access Point\r\n");
	
		if(ESP_connectServer(DOMAIN, PORT) && ESP_Send("tiva")) {
			LOG("Connected to server\r\n");
		}
	}
	
	
	sendGPSCommand(UART1_BASE, "PUBX,40,GLL,0,0,0,0");
	sendGPSCommand(UART1_BASE, "PUBX,40,GSA,0,0,0,0");
	sendGPSCommand(UART1_BASE, "PUBX,40,GSV,0,0,0,0");
	sendGPSCommand(UART1_BASE, "PUBX,40,GGA,0,0,0,0");
	sendGPSCommand(UART1_BASE, "PUBX,40,VTG,0,0,0,0");
	
	LCD_INIT();
	LCD_CMD(Function_set_8bit);
	
	while(1) {
		
		memset(buffer, 0, 256*sizeof(char));
		memset(longitude, 0, 30*sizeof(char));
		memset(latitude, 0, 30*sizeof(char));
		memset(speed, 0, 10*sizeof(char));
		
		uartGetString(UART1_BASE, buffer, '\n');
		LOG(buffer);
		
		if (checkValidity(buffer)) {
			
			get_Time(buffer, time);
			get_Longitude(buffer, longitude);
			get_Latitude(buffer, latitude);
			get_Speed(buffer, speed);
			
			Lat = atof(latitude);
			Long = atof(longitude);
			
			//Lat = roundf(Lat*10000)/10000;
			//Long = roundf(Long*10000)/10000;
				
			linearDistance = calcDistance_float(Lat, Long, destLat, destLong);
			
			if (firstRead) {
				prevLat = lat_degrees_value;
				prevLong = long_degrees_value;
				
				if (firstRead && ESP_Send("dest")) {
						memset(data, 0, 40*sizeof(char));
						sprintf(data, "%s,%s", latitude, longitude);
						ESP_Send(data);
	
					firstRead = false;
			}
				
		}
			
		
			distance = calcDistance_float(Lat, Long, prevLat, prevLong);
			currentDistanceFromDest = calcDistance_float(Lat, Long, destLat, destLong);
			
			sprintf(LCD_Text, "Distance Left: %f", currentDistanceFromDest);
			LCD_String(LCD_Text);
			
			if (distance > 2)
				accDistance += distance;
			
			prevLat = lat_degrees_value;
			prevLong = long_degrees_value;
			
			
		if(ESP_Send("gpsd")) {
			memset(data, 0, 40*sizeof(char));
			sprintf(data, "%f,%f,%f,%s", Lat, Long,accDistance, speed);
			LOG(data);
			ESP_Send(data);
		}
		
				//memset(buffer, 0, 120*sizeof(char));
		sprintf(buffer, "Current time %s \r\nCurrent longitude %s \r\nCurrent latitude %s \r\nCurrent Speed %s \r\nDistance %f\r\n", time, longitude, latitude, speed, currentDistanceFromDest);
		
		uartSendString(UART0_BASE, buffer);
		
	} 
		
	if (currentDistanceFromDest > 7) {
			pinHigh(PortF, RED_LED);
			pinLow(PortF, GREEN_LED);
			pinLow(PortF, BLUE_LED);
	
			pinHigh(PortD, 6);
			pinHigh(PortD, 7);
	}
	else if (currentDistanceFromDest > 2) {
			pinHigh(PortF, RED_LED);
			pinHigh(PortF, GREEN_LED);
			pinLow(PortF, BLUE_LED);
	
			pinHigh(PortD, 6);
			pinLow(PortD, 7);
	
	} else
		pinHigh(PortF, GREEN_LED);
		pinLow(PortF, RED_LED);
		pinLow(PortF, BLUE_LED);
		
		pinLow(PortD, 6);
		pinHigh(PortD, 7);

	
	}	
		
	return 0;
}