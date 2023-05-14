#include "gps.h"


float lat_decimal_value, lat_degrees_value;
float long_decimal_value, long_degrees_value;
float speedInKnots;


void sendGPSCommand(uint32_t base, char* command) {
	unsigned char checkSum = calculateChecksum(command);
	
	char newCommand[27];
	sprintf(newCommand, "$%s*%02X\r\n", command, checkSum);
	uartSendString(base, newCommand);
}

void get_Latitude( char* GPRMC_String, char* Latitude_Buffer)
{


    uint8_t lat_index = 0;
    uint8_t index = 0;
		uint8_t comma_count;
    int32_t lat_degrees;
	
   for(comma_count=0; GPRMC_String[index] != '\0'; index++)
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

    /* parse Latitude in GPRMC string stored in buffer */
    for (; GPRMC_String[index] != ','; index++)
    {
        Latitude_Buffer[lat_index] = GPRMC_String[index];
        lat_index++;
    }

    lat_decimal_value = atof(Latitude_Buffer); /* Latitude in ddmm.mmmm */
		
    /* convert raw latitude into degree format */
    lat_decimal_value = (lat_decimal_value / 100); /* Latitude in dd.mmmmmm */
    lat_degrees = (int)(lat_decimal_value); /* dd of latitude */
    lat_decimal_value = (lat_decimal_value - lat_degrees) / 0.6; /* .mmmm/0.6 (Converting minutes to eequivalent degrees) */
		
		lat_degrees_value = (float)(lat_degrees + lat_decimal_value);		/* Latitude in dd.dddd format */
		
		if (GPRMC_String[++index] == 'S')
			lat_degrees_value *= -1;
		
    sprintf(Latitude_Buffer, "%f", lat_degrees_value);

}

void get_Longitude( char* GPRMC_String, char* Longitude_Buffer)
{

    uint8_t long_index = 0;
    uint8_t index = 0;
    int32_t long_degrees;
		uint8_t comma_count;
	
    /* find the index of the fourth comma */
    for(comma_count=0; GPRMC_String[index]; index++)
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

    /* parse longitude in GPRMC string */
    for(; GPRMC_String[index] != ',' && GPRMC_String[index] != '\0'; index++)
    {
        Longitude_Buffer[long_index] = GPRMC_String[index];
        long_index++;
    }
    long_decimal_value = atof(Longitude_Buffer);	/* Longitude in dddmm.mmmm */

    /* convert raw longitude into degree format */
    long_decimal_value = (long_decimal_value/100);	/* Longitude in ddd.mmmmmm */
    long_degrees = (int)(long_decimal_value);	/* ddd of Longitude */
		
    long_decimal_value = (long_decimal_value - long_degrees)/0.6;	/* .mmmmmm/0.6 (Converting minutes to equivalent degrees) */
		long_degrees_value = (float)(long_degrees + long_decimal_value);	/* Longitude in dd.dddd format */
		
		if (GPRMC_String[++index] == 'W')
			long_degrees_value *= -1;

		sprintf(Longitude_Buffer, "%f", long_degrees_value);

}

void get_Speed(const char* GPRMC_String, char* speed) {
    float conversionFactor = 0.514444; // Conversion factor from knots to m/s
		float speedInMetersPerSecond;
	
		uint8_t long_index = 0;
    uint8_t index = 0;
		uint8_t comma_count;
	
    for (comma_count = 0; GPRMC_String[index] != '\0'; index++) {
        if (GPRMC_String[index] == ',') {
            comma_count++;
            if (comma_count == 7) {
                index++;
                break;
            }
        }
    }
    for (; GPRMC_String[index] != ',' && GPRMC_String[index] != '\0'; index++) {
        speed[long_index] = GPRMC_String[index];
        long_index++;
    }
    speedInKnots = atof(speed);
    speedInMetersPerSecond = speedInKnots * conversionFactor;
    
		sprintf(speed, "%i", (int)speedInMetersPerSecond);
}

void get_Time(char*GPRMC_String,char*Time_Buffer)
{


    uint8_t time_index = 0;
    uint8_t index;
    uint16_t hour, min, sec;
    uint32_t Time_value;

    /* parse Time in GPRMC string stored in buffer */
    for(index = 7; GPRMC_String[index]!=','; index++)
    {
        /* Skip the first 7 fields before the time field in GPRMC string */
      
            Time_Buffer[time_index] = GPRMC_String[index];
            time_index++;
       
    }
    Time_value = atol(Time_Buffer);               /* convert string to integer */
    hour = (Time_value / 10000) + 3;              /* extract hour from integer, aded 3Hrs for timezone*/
		
		if (hour >= 24)
			hour -= 24;
		
    min = (Time_value % 10000) / 100;             /* extract minute from integer */
    sec = (Time_value % 10000) % 100;             /* extract second from integer*/

    sprintf(Time_Buffer, "%02i:%02i:%02i", hour, min, sec);


}

bool checkValidity(char* buffer) {
  uint8_t index = 0;
	uint8_t comma_count;
	
    /* find the index of the fourth comma */
  for(comma_count=0; buffer[index]; index++)
  {
		if(buffer[index] == ',')
    {
			comma_count++;
			if(comma_count == 2)
      {
				index++;
				if (buffer[index] == 'A')
					return true;
				
				return false;
      }
    }
  }
	
	return false;
}

float calcDistance(char* lat1_str, char* lon1_str, char* lat2_str, char* lon2_str) {
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

float calcDistance_float(float lat1, float lon1, float lat2, float lon2) {
		float dLat = deg2rad(lat2 - lat1);
    float dLon = deg2rad(lon2 - lon1);

    float a = sin(dLat/2) * sin(dLat/2) +
              cos(deg2rad(lat1)) * cos(deg2rad(lat2)) *
              sin(dLon/2) * sin(dLon/2);
    float c = 2 * atan2(sqrt(a), sqrt(1-a));
    float distance = RADIUS * c;

    return distance;
}

