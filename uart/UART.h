#include "tm4c123gh6pm.h"

#define SET(P_DATA,PIN) (P_DATA |= (0x01 << PIN))
#define CLEAR(P_DATA,PIN) (P_DATA &= ~(0x01 << PIN))
#define TOGGLE(P_DATA,PIN) (P_DATA ^= (0x01 << PIN))
#define DEG_TO_RAD(DEG)((DEG*PI/180))

//baud_rate calculation
#define baudRate 9600
#define CLDIV  ((16000000.0) / ((16.0) * (baudRate)))
#define uartIBRD ((int)(CLDIV))
#define uartFBRD ((int)(((((CLDIV)) - (uartIBRD))) * (64)) + (0.5))
	
#define TXFULL 0x00000020
#define RXEMPTY 0x00000010


//UART0
void UART0_Init();

void UART0_WriteChar(unsigned char ch);

unsigned char UART0_ReadChar(void);

void UART0_WriteString(char *str);

void UART0_ReadString(char *str, char stopCh);

//UART1
void UART1_Init();

void UART1_WriteChar(unsigned char ch);

unsigned char UART1_ReadChar(void);

void UART1_WriteString(char *str);

void UART1_ReadString(char *str, char stopCh);

//UART5
void UART5_Init();

void UART5_WriteChar(unsigned char ch);

unsigned char UART5_ReadChar(void);

void UART5_WriteString(char *str);

void UART5_ReadString(char *str, char stopCh);

//UART7
void UART7_Init();

void UART7_WriteChar(unsigned char ch);

unsigned char UART7_ReadChar(void);

void UART7_WriteString(char *str);

void UART7_ReadString(char *str, char stopCh);