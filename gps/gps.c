
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
  int count = 0;  
  char *token, *NS, *EW;
  token = strtok(gpsString, ",");
    
  while (token != NULL) {
    count++;
    switch (count) {
      case 2:
        *time = atoi(token);
        break;
      case 3:
        if(strcmp(token, "V") == 0) {
          return -1;
        }
        break;
      case 4:
        *latitude = atof(token) / 100;
        break;
      case 5:
        NS = token;
        break;
      case 6:
        *longitude = atof(token) / 100;
        break;     
      case 7:
        EW = token;
        break;   
      case 8:
        *speed = atof(token) * 0.514444;
        break;
    }
    token = strtok(NULL, ",");    
  }

  // Check the sign of latitude and longitude
  if (*NS == 'S') {
    *latitude = -*latitude;
  }
  if (*EW == 'W') {
    *longitude = -*longitude;
  }
	
  return 0;
}
