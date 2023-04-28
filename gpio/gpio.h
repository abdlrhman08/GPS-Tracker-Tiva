#include <stdint.h>

#include "tm4c123gh6ph.h"

#define GPIO_Port 0x40000000
#define DEN 0x51C
#define DIR 0x400
#define LOCK 0x520
#define COMMIT 524
#define DATA 0x3FC

typedef enum {
	PortA = 0x04000,
	PortB = 0x05000,
	PortC = 0x06000,
	PortD = 0x07000,
	PortE = 0x24000,
	PortF = 0x25000
} GPIO;

void initPort(GPIO port);

void pinHigh(GPIO port, uint8_t pin);
void pinLow(GPIO port, uint8_t pin);