
#include "utils.h"

void delay(int t) {
	int x = 0;
	int i;
	for (i = 0; i < t; i++) {
			x++;
		}
}

unsigned char calculateChecksum(char* str) {
	uint8_t checkSumChar = 0;
	
	int i;
	for (i = 0; str[i]; i++) {
		checkSumChar ^= str[i];
	}
	
	return (unsigned char)checkSumChar;
}

float deg2rad(float deg) {
    return deg * (M_PI/180);
}