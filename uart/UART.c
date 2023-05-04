
#include "UART.h"



// UART0

void UART0_Init(){

	SET(SYSCTL_RCGCUART_R,0);	//enable clock for UART0
	SET(SYSCTL_RCGCGPIO_R,0);	//enable clock for GPIO_A
	while((SYSCTL_PRGPIO_R & 0x01) == 0){}	//waiting for activation
	GPIO_PORTA_DEN_R |= 0x03; //digital enable of PAO & PA1
	GPIO_PORTA_AFSEL_R |= 0x03;
	GPIO_PORTA_AMSEL_R &= ~0x03;	//Disable analog function PA0 & PA1
	GPIO_PORTA_PCTL_R |= 0x00000011; //select UART0 function for PA0 & PA1
	CLEAR(UART0_CTL_R,0);	// clear control register
	UART0_IBRD_R = uartIBRD;	//configure UART0 with desired baud rate (integer part)
	UART0_FBRD_R = uartFBRD;	//fractional part
	UART0_LCRH_R |= 0x70;	//enable FIFO , 8 bit data
	UART0_CTL_R |= 0x301;	//enable uart as tx and rx
	
}

void UART0_WriteChar(unsigned char ch){						
	while((UART0_FR_R&TXFULL) != 0){} //checks if fifo is full
	UART0_DR_R = ch;
}

unsigned char UART0_ReadChar(void){							
	while((UART0_FR_R&RXEMPTY) != 0){} //checks fifo is empty
	return UART0_DR_R&0xFF; //return character from data register,least significant 8 bits
}

void UART0_WriteString(char *str){								
  while(*str){ //loop continue till null character
    UART0_WriteChar(*str); //write current character in buffer
    str++; //move to next character
  }
}

void UART0_ReadString(char *str, char stopCh){		
	char c = UART0_ReadChar(); // read first character
	while(c && c != stopCh){ //checks for stop character or null charcter
		*str = c; // store current character
		str++; //move to next character
		c = UART0_ReadChar(); //read next character
	}
	*str = 0x00;  //adding null character
}

// UART1

void UART1_Init(){

	SET(SYSCTL_RCGCUART_R,1);
	SET(SYSCTL_RCGCGPIO_R,2);
	while((SYSCTL_PRGPIO_R & (0x01 << 2)) == 0){}
	GPIO_PORTC_DEN_R |= 0x30;	//digital enable of PBO & PB1
	GPIO_PORTC_AFSEL_R |= 0x30; 	//alternate function for PB0 & PB1
	GPIO_PORTC_AMSEL_R &= ~0x30;	//Disable analog function PB0 & PB1
	GPIO_PORTC_PCTL_R |= 0x00220000;	//select UART0 function for PC4 & PC5
	CLEAR(UART1_CTL_R,0);
	UART1_IBRD_R = uartIBRD;
	UART1_FBRD_R = uartFBRD;
	UART1_LCRH_R |= 0x70;
	UART1_CTL_R |= 0x301;
	
}
void UART1_WriteChar(unsigned char ch){						
	while((UART1_FR_R&TXFULL) != 0){}
	UART1_DR_R = ch;
}

unsigned char UART1_ReadChar(void){						
	while((UART1_FR_R&RXEMPTY) != 0){}
	return UART1_DR_R&0xFF;
}

void UART1_WriteString(char *str){								
  while(*str){
    UART1_WriteChar(*str);
    str++;
  }
}

void UART1_ReadString(char *str, char stopCh){		
	char c = UART1_ReadChar();
	while(c && c != stopCh){
		*str = c;
		str++;
		c = UART1_ReadChar();
	}
	*str = 0x00;
}

// UART5

void UART5_Init(){

	SET(SYSCTL_RCGCUART_R,5);
	SET(SYSCTL_RCGCGPIO_R,4);
	while((SYSCTL_PRGPIO_R & (0x01<<4)) == 0){}
	CLEAR(UART5_CTL_R,0);
	UART5_IBRD_R = uartIBRD;
	UART5_FBRD_R = uartFBRD;
	UART5_LCRH_R |= 0x70;
	UART5_CTL_R |= 0x301;
	GPIO_PORTE_DEN_R |= 0x30;		//digital enable of PE4 & PE5
	GPIO_PORTE_AFSEL_R |= 0x30;		//alternate function for PE4 & PE5
	GPIO_PORTE_AMSEL_R &= ~0x30;	//Disable analog function PE4 & PE5
	GPIO_PORTE_PCTL_R |= 0x00110000; //select UART0 function for PE4 & PE5
	
}
void UART5_WriteChar(unsigned char ch){						
	while((UART5_FR_R&TXFULL) != 0){}
	UART5_DR_R = ch;
}

unsigned char UART5_ReadChar(void){								
	while((UART5_FR_R&RXEMPTY) != 0){}
	return UART5_DR_R&0xFF;
}

void UART5_WriteString(char *str){								
  while(*str){
    UART5_WriteChar(*str);
    str++;
  }
}

void UART5_ReadString(char *str, char stopCh){		
	char c = UART5_ReadChar();
	while(c && c != stopCh){
		*str = c;
		str++;
		c = UART5_ReadChar();
	}
	*str = 0x00;
}

// UART7

void UART7_Init(){

	SET(SYSCTL_RCGCUART_R,7);
	SET(SYSCTL_RCGCGPIO_R,4);
	while((SYSCTL_PRGPIO_R & (0x01<<4)) == 0){}
	CLEAR(UART7_CTL_R,0);
	UART7_IBRD_R = uartIBRD;
	UART7_FBRD_R = uartFBRD;
	UART7_LCRH_R |= 0x70;
	UART7_CTL_R |= 0x301;
	GPIO_PORTE_DEN_R |= 0x03;	//digital enable of PEO & PE1
	GPIO_PORTE_AFSEL_R |= 0x03;	//alternate function for PE0 & PE1
	GPIO_PORTE_AMSEL_R &= ~0x03;	//Disable analog function PE0 & PE1
	GPIO_PORTE_PCTL_R |= 0x00000011;	//select UART0 function for PE0 & PE1
	
}
void UART7_WriteChar(unsigned char ch){		
	while((UART7_FR_R&TXFULL) != 0){}
	UART7_DR_R = ch;
}

unsigned char UART7_ReadChar(void){								
	while((UART7_FR_R&RXEMPTY) != 0){}
	return UART7_DR_R&0xFF;
}

void UART7_WriteString(char *str){		
  while(*str){
    UART7_WriteChar(*str);
    str++;
  }
}

void UART7_ReadString(char *str, char stopCh){		
	char c = UART7_ReadChar();
	while(c != stopCh){//while(c && c != stopCh){
		*str = c;
		str++;
		c = UART7_ReadChar();
	}
	*str = 0x00;
}