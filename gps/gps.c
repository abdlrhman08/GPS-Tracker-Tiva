
#include "gps.h"

void sendGPSCommand(char* command) {
	unsigned char checkSum = calculateChecksum(command);
	
	char newCommand[27];
	sprintf(newCommand, "$%s*%X\r\n", command, checkSum);
	UART1_WriteString(newCommand);
}

void readGPS(char* str) {
	char buffer[100];
	UART1_ReadString(buffer, '\n');
	sprintf(str, "%s\n", buffer);
}

int parseGPSData(char* gpsString, float* latitude, float* longitude, int* time, float* speed) {
    
  // Split GPS string into parts
	int count = 0;  
	char *token;
	char *NS , *EW;
  token = strtok(gpsString, ",");
    
  while (token != NULL) {
		count++;
    switch (count) {
			case 2:
			{
				*time = atoi(token);
				break;
			}
			case 3:
			{
				if(strcmp(token, "V") == 0) {
					return -1;
				}
				break;
			}
      case 4:
			{
        // Convert latitude from degrees and minutes to decimal degrees
				
				
				char degree1[3], minute1[9];
				
			/*
        strncpy(degree1, token, 2);
        strncpy(minute1, token + 2, 8);
        degree1[2] = '\0';
        minute1[8] = '\0';
        *longitude = atof(degree1) + atof(minute1) / 60;
*/				
        break;
			}
			case 5:
			{
				NS = token;
        break;
			}
			case 6:
  		{
				//Convert longitude from degrees and minutes to decimal degrees
        /*
				char degree2[4], minute2[9];
        strncpy(degree2, token, 3);
        strncpy(minute2, token + 3, 8);
        degree2[3] = '\0';
        minute2[8] = '\0';
        *longitude = atof(degree2) + atof(minute2) / 60;
				*/
        break;
      }     
			case 7:
			{
				EW = token;
        break;
				
      }
			case 8:
			{
        *speed = atof(token) * 0.514444;
         break;
			}
		}
    token = strtok(NULL, ",");    
  }
    //check the sign of latitude and longitude
  //if (*NS == 'S'){*latitude= -*latitude;}
  //if (*EW == 'W' ){*longitude= -*longitude;}
	
	return 0;
}