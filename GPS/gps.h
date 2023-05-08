//
// Created by zyn66 on 5/8/2023.
//

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "esp.h"
#include <math.h>

#define RADIUS 6371 // radius of the earth in kilometers

bool validate_GPRMC_string(const char* GPRMC_String);
bool validate_GPRMC_checksum(const char* GPRMC_String);
void get_Time(uint32_t ui32Base,char*GPRMC_String,char*Time_Buffer);
void get_Longitude( char* GPRMC_String, char* Longitude_Buffer);
void get_Latitude( char* GPRMC_String, char* Latitude_Buffer);
float Distance (char* lat1_str, char* lon1_str, char* lat2_str, char* lon2_str);


