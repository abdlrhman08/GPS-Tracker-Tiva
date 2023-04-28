#include <stdio.h>

#include "gpio/gpio.h"

void SystemInit() {}

int i, x;
	
int main() {
	initPort(PortF);
	
	while(1) {
		pinHigh(PortF, 3);
		for (i = 0; i < 50000; i++) {
			x++;
		}
		x = 0;
		pinLow(PortF, 3);
		
		for (i = 0; i < 50000; i++) {
			x++;
		}
		x = 0;
	}
		
	return 0;
}