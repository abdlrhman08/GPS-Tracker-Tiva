#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils.h"

typedef struct INFO {
	float longitude;
	float latitude;
	double speed;
	
	int time;
	int date;
	
} INFO;


void sendGPSCommand(char* command);

void readGPS(char* str);

int parseGPSData(char* gpsString, float* latitude, float* longitude, int* time, double* speed);
