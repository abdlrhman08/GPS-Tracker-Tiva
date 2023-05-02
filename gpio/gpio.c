#include "gpio.h"

void initPort(GPIO port) {
	uint8_t clock = 0x00;
	
	if (port == PortA) {
		clock = 0x01;
	} else if (port == PortB) {
		clock = 0x02;
	} else if (port == PortC) {
		clock = 0x04;
	} else if (port == PortD) {
		clock = 0x08;
	} else if (port == PortE) {
		clock = 0x10;
	} else if (port == PortF) {
		clock = 0x20;
	}
	
	SYSCTL_RCGCGPIO_R |= clock;
	while((SYSCTL_PRGPIO_R& (0x01 << 5)) == 0){}
	
	*((volatile unsigned long *)(GPIO_PORT_LOCK | port )) 		   = 0x4C4F434B;
	*((volatile unsigned long *)(GPIO_PORT_COMMIT | port ))		 = 0xFF;
	*((volatile unsigned long *)(GPIO_PORT_DEN | port )) 			 = 0x1E;
		
	//Defaulted on the pins on portF, a function later will be made for every pin
	*((volatile unsigned long *)(GPIO_PORT_DIR | port)) 			 = 0x0E;
}

void pinHigh(GPIO port, uint8_t pin) {
	*((volatile unsigned long *)(GPIO_PORT_DATA | port)) |= 0x1 << pin;
}

void pinLow(GPIO port, uint8_t pin) {
	*((volatile unsigned long *)(GPIO_PORT_DATA | port)) &= ~(0x1 << pin);
}

