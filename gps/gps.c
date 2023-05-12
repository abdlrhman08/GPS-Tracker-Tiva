
#include "gps.h"

/*
*	Avoid using sprintf alot specially with floating variables
* due to limitiations of the microcontroller
*/

void sendGPSCommand(uint32_t base, char* command) {
	unsigned char checkSum = calculateChecksum(command);
	
	char newCommand[27];
	sprintf(newCommand, "$%s*%X\r\n", command, checkSum);
	uartSendString(base, newCommand);
}

void get_Latitude( char* GPRMC_String, char* Latitude_Buffer)
{


    uint8_t lat_index = 0;
    uint8_t index = 0;
		uint8_t comma_count;
	
		float lat_decimal_value, lat_degrees_value;
    int32_t lat_degrees;
		int latFrac;
	
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

    lat_decimal_value = stof(Latitude_Buffer); /* Latitude in ddmm.mmmm */

    /* convert raw latitude into degree format */
    lat_decimal_value = (lat_decimal_value / 100); /* Latitude in dd.mmmmmm */
    lat_degrees = (int)(lat_decimal_value); /* dd of latitude */
    lat_decimal_value = (lat_decimal_value - lat_degrees) / 0.6; /* .mmmm/0.6 (Converting minutes to eequivalent degrees) */
    latFrac = lat_decimal_value * 1000000;
		
		//lat_degrees_value = (float)(lat_degrees + lat_decimal_value); /* Latitude in dd.dddd format */

		/*
		*	Using sprintf(buffer, "%f", lat_degrees_value);
		* will not work due to the functions high emory consumptions
		* specially with floating values
		*/
		
    sprintf(Latitude_Buffer, "%i.%i", lat_degrees, latFrac);

}

void get_Longitude( char* GPRMC_String, char* Longitude_Buffer)
{

    uint8_t long_index = 0;
    uint8_t index = 0;
		float long_decimal_value, long_degrees_value;
    int32_t long_degrees;
		int longFrac;
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
    long_decimal_value = stof(Longitude_Buffer);	/* Longitude in dddmm.mmmm */

    /* convert raw longitude into degree format */
    long_decimal_value = (long_decimal_value/100);	/* Longitude in ddd.mmmmmm */
    long_degrees = (int)(long_decimal_value);	/* ddd of Longitude */
		
    long_decimal_value = (long_decimal_value - long_degrees)/0.6;	/* .mmmmmm/0.6 (Converting minutes to equivalent degrees) */
		longFrac = long_decimal_value * 1000000;
		//long_degrees_value = (float)(long_degrees + long_decimal_value);	/* Longitude in dd.dddd format */

		sprintf(Longitude_Buffer, "%i.%i", long_degrees, longFrac);

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
    hour = (Time_value / 10000);                  /* extract hour from integer */
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
