#ifndef GPS_H
#define GPS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#include "../utils.h"

#define RADIUS 6371000

//To avoid multiple definitions

extern float lat_decimal_value, lat_degrees_value;
extern float long_decimal_value, long_degrees_value;
extern float speedInKnots;

void sendGPSCommand(uint32_t base, char* command);

void get_Time(char*GPRMC_String,char*Time_Buffer);
void get_Longitude(char* GPRMC_String, char* Longitude_Buffer);
void get_Latitude( char* GPRMC_String, char* Latitude_Buffer);
void get_Speed(const char* GPRMC_String, char* speed); 

float calcDistance(char* lat1_str, char* lon1_str, char* lat2_str, char* lon2_str);
float calcDistance_float(float lat1, float lon1, float lat2, float lon2);

bool checkValidity(char* buffer); 

#endif