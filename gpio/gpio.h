#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

#include "tm4c123gh6ph.h"

#define GPIO_PORT_DEN 0x4000051C
#define GPIO_PORT_DIR 0x40000400
#define GPIO_PORT_PDR 0x40000514
#define GPIO_PORT_LOCK 0x40000520
#define GPIO_PORT_COMMIT 0x40000524
#define GPIO_PORT_DATA 0x400003FC

#define	PortA 0x04000
#define	PortB 0x05000
#define	PortC 0x06000
#define	PortD 0x07000
#define	PortE 0x24000
#define	PortF 0x25000

#define RED_LED 1
#define GREEN_LED 3
#define BLUE_LED 2

void initPort(uint32_t port);

void pinOutput(uint32_t port, uint8_t pin);
void pinHigh(uint32_t port, uint8_t pin);
void pinLow(uint32_t port, uint8_t pin);

#endif