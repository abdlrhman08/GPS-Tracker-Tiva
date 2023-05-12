#ifndef GPS_H
#define GPS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include "../utils.h"

typedef struct INFO {
	float longitude;
	float latitude;
	float speed;
	
	int time;
	int date;
	
} INFO;


void sendGPSCommand(uint32_t base, char* command);

void get_Time(char*GPRMC_String,char*Time_Buffer);
void get_Longitude(char* GPRMC_String, char* Longitude_Buffer);
void get_Latitude( char* GPRMC_String, char* Latitude_Buffer);

bool checkValidity(char* buffer); 

#endif