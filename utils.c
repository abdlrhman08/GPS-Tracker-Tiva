
#include "utils.h"

void delay_us(int t) {
 int i;
 for( i = 0; i<t; i++){
 while((NVIC_ST_CTRL_R&0x10000)==0){}
 }
}

void delay_ms(int t) {
 int i;
 for( i = 0; i<t*1000; i++){
 while((NVIC_ST_CTRL_R&0x10000)==0){}
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

void initSystick() {
	NVIC_ST_CTRL_R = 0;
	
	//for one micro sec
	NVIC_ST_RELOAD_R = 15;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 5;
}