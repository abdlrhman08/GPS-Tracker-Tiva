#include <stdint.h>

#include "tm4c123gh6ph.h"

#define GPIO_PORT_DEN 0x4000051C
#define GPIO_PORT_DIR 0x40000400
#define GPIO_PORT_LOCK 0x40000520
#define GPIO_PORT_COMMIT 0x40000524
#define GPIO_PORT_DATA 0x400003FC

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