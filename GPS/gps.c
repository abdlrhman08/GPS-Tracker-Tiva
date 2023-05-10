//
// Created by zyn66 on 5/8/2023.
//
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "esp.h"
#include <math.h>

#define RADIUS 6371 // radius of the earth in kilometers
bool validate_GPRMC_string(const char* GPRMC_String)
{
    int comma_count = 0;
    char field_buffer[20];
    int field_index = 0;

    // Check that string starts with "$GPRMC"
    if (strncmp(GPRMC_String, "$GPRMC,", 7) != 0)
    {
        return false;
    }

    // Count commas and validate fields
    for (int i = 7; i < strlen(GPRMC_String); i++)
    {
        if (GPRMC_String[i] == ',')
        {
            comma_count++;
            field_index = 0;
            if (comma_count == 2) // validate time field
            {
                if (strlen(field_buffer) != 10 || field_buffer[6] != '.')
                {
                    return false;
                }
                for (int j = 0; j < 10; j++)
                {
                    if (j == 6) continue;
                    if (field_buffer[j] < '0' || field_buffer[j] > '9')
                    {
                        return false;
                    }
                }
            }
            else if (comma_count == 3) // validate data valid field
            {
                if (strlen(field_buffer) != 1 || (field_buffer[0] != 'A' && field_buffer[0] != 'V'))
                {
                    return false;
                }
            }
            else if (comma_count == 4) // validate latitude field
            {
                if (strlen(field_buffer) < 8 || field_buffer[strlen(field_buffer)-1] != 'N' || field_buffer[strlen(field_buffer)-1] != 'S')
                {
                    return false;
                }
                for (int j = 0; j < strlen(field_buffer)-1; j++)
                {
                    if (j == 2 && field_buffer[j] != '.')
                    {
                        return false;
                    }
                    if ((j < 2 || j > 2) && (field_buffer[j] < '0' || field_buffer[j] > '9'))
                    {
                        return false;
                    }
                }
            }
            else if (comma_count == 6) // validate longitude field
            {
                if (strlen(field_buffer) < 9 || field_buffer[strlen(field_buffer)-1] != 'E' || field_buffer[strlen(field_buffer)-1] != 'W')
                {
                    return false;
                }
                for (int j = 0; j < strlen(field_buffer)-1; j++)
                {
                    if (j == 3 && field_buffer[j] != '.')
                    {
                        return false;
                    }
                    if ((j < 3 || j > 3) && (field_buffer[j] < '0' || field_buffer[j] > '9'))
                    {
                        return false;
                    }
                }
            }
        }
        else
        {
            field_buffer[field_index++] = GPRMC_String[i];
        }
    }

    return true;
}


bool validate_GPRMC_checksum(const char* GPRMC_String)
{
    // Find the start of the checksum in the string
    const char* checksum_start = strchr(GPRMC_String, '*');
    if (checksum_start == NULL || *(checksum_start+1) == '\0' || *(checksum_start+2) == '\0')
    {
        return false; // Invalid checksum format
    }

    // Convert the checksum from hexadecimal to decimal
    char checksum_str[3] = { *(checksum_start+1), *(checksum_start+2), '\0' };
    int expected_checksum = strtol(checksum_str, NULL, 16);

    // Calculate the actual checksum
    int calculated_checksum = 0;
    for (int i = 1; i < (checksum_start - GPRMC_String); i++)
    {
        calculated_checksum ^= GPRMC_String[i];
    }

    // Compare the actual and expected checksums
    return (expected_checksum == calculated_checksum);
}

void get_Time(uint32_t ui32Base,char*GPRMC_String,char*Time_Buffer)
{


    uint8_t time_index = 0;
    uint8_t index;
    uint16_t hour, min, sec;
    uint32_t Time_value;

    /* parse Time in GPRMC string stored in buffer */
    for(index = 0; GPRMC_String[index]!=','; index++)
    {
        /* Skip the first 7 fields before the time field in GPRMC string */
        if(index >= 7) {
            Time_Buffer[time_index] = GPRMC_String[index];
            time_index++;
        }
    }
    Time_value = atol(Time_Buffer);               /* convert string to integer */
    hour = (Time_value / 10000);                  /* extract hour from integer */
    min = (Time_value % 10000) / 100;             /* extract minute from integer */
    sec = (Time_value % 10000) % 100;             /* extract second from integer*/

    sprintf(Time_Buffer, "%d:%d:%d", hour, min, sec);


}

void get_Longitude( char* GPRMC_String, char* Longitude_Buffer)
{

    uint8_t long_index = 0;
    uint8_t index = 0;

    /* find the index of the fourth comma */
    for(uint8_t comma_count=0; GPRMC_String[index] != '\0'; index++)
    {
        if(GPRMC_String[index] == ',')
        {
            comma_count++;
            if(comma_count == 3)
            {
                index++;
                break;
            }
        }
    }

    /* parse longitude in GPRMC string */
    for(; GPRMC_String[index] != ',' && GPRMC_String[index] != '\0'; index++)
    {
        Longitude_Buffer[long_index] = GPRMC_String[index];
        long_index++;
    }

    float long_decimal_value, long_degrees_value;
    int32_t long_degrees;
    long_decimal_value = atof(Longitude_Buffer);	/* Longitude in dddmm.mmmm */

    /* convert raw longitude into degree format */
    long_decimal_value = (long_decimal_value/100);	/* Longitude in ddd.mmmmmm */
    long_degrees = (int)(long_decimal_value);	/* ddd of Longitude */
    long_decimal_value = (long_decimal_value - long_degrees)/0.6;	/* .mmmmmm/0.6 (Converting minutes to equivalent degrees) */
    long_degrees_value = (float)(long_degrees + long_decimal_value);	/* Longitude in dd.dddd format */

    sprintf(Longitude_Buffer, "%f", long_degrees_value);

}

void get_Latitude( char* GPRMC_String, char* Latitude_Buffer)
{


    uint8_t lat_index = 0;
    uint8_t index = 0;

   for(uint8_t comma_count=0; GPRMC_String[index] != '\0'; index++)
    {
        if(GPRMC_String[index] == ',')
        {
            comma_count++;
            if(comma_count == 5)
            {
                index++;
                break;
            }
        }
    }

    /* parse Latitude in GPRMC string stored in buffer */
    for (; GPRMC_String[index] != ','; index++)
    {
        Latitude_Buffer[lat_index] = GPRMC_String[index];
        lat_index++;
    }

    float lat_decimal_value, lat_degrees_value;
    int32_t lat_degrees;
    lat_decimal_value = atof(Latitude_Buffer); /* Latitude in ddmm.mmmm */

    /* convert raw latitude into degree format */
    lat_decimal_value = (lat_decimal_value / 100); /* Latitude in dd.mmmmmm */
    lat_degrees = (int)(lat_decimal_value); /* dd of latitude */
    lat_decimal_value = (lat_decimal_value - lat_degrees) / 0.6; /* .mmmm/0.6 (Converting minutes to eequivalent degrees) */
    lat_degrees_value = (float)(lat_degrees + lat_decimal_value); /* Latitude in dd.dddd format */

    sprintf(Latitude_Buffer, "%f", lat_degrees_value);

}

float deg2rad(float deg) {
    return deg * (M_PI/180);
}

float Distance (char* lat1_str, char* lon1_str, char* lat2_str, char* lon2_str) {
    float lat1 = atof(lat1_str);
    float lon1 = atof(lon1_str);
    float lat2 = atof(lat2_str);
    float lon2 = atof(lon2_str);

    float dLat = deg2rad(lat2 - lat1);
    float dLon = deg2rad(lon2 - lon1);

    float a = sin(dLat/2) * sin(dLat/2) +
              cos(deg2rad(lat1)) * cos(deg2rad(lat2)) *
              sin(dLon/2) * sin(dLon/2);
    float c = 2 * atan2(sqrt(a), sqrt(1-a));
    float distance = RADIUS * c;

    return distance;
}

