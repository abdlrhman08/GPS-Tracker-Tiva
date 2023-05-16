//
// Created by zyn66 on 5/6/2023.
//

#include "esp.h"

unsigned int WIFI_UART_BASE;

int8_t Response_Status;
volatile int16_t Counter = 0, pointer = 0;
uint32_t TimeOut = 0;
char RESPONSE_BUFFER[100];

	char temp[256];
	char y;

bool SendATCommand(uint32_t ui32Base, char *pcCmd)
{
    uartSendChar(ui32Base, 'A');  // Send 'A' character to wake up ESP
    uartSendChar(ui32Base, 'T');  // Send 'T' character to start AT command
    while (*pcCmd != '\0')
    {
        uartSendChar(ui32Base, *pcCmd++);
    }
    uartSendChar(ui32Base, '\r'); // Send carriage return character
    uartSendChar(ui32Base, '\n'); // Send line feed character
    return true; // Return success
}

void ESP_Clear()
{
    memset(RESPONSE_BUFFER,0,100);
    Counter = 0;	pointer = 0;
}

void Start_Read_Response(char* _ExpectedResponse)
{
    Response_Status = ESP_RESPONSE_STARTING;
   // do {
   //     Read_Response(_ExpectedResponse);
   // } while(Response_Status == ESP_RESPONSE_WAITING);

}

void GetResponseBody(char* Response, uint32_t ResponseLength)
{
    uint32_t i = 12;
		uint32_t tmp;
    char buffer[5];
    while(Response[i] != '\r')
        ++i;

    strncpy(buffer, Response + 12, (i - 12));
    ResponseLength = atoi(buffer);

    i += 2;
    tmp = strlen(Response) - i;
    memcpy(Response, Response + i, tmp);

    if(!strncmp(Response + tmp - 6, "\r\nOK\r\n", 6))
        memset(Response + tmp - 6, 0, i + 6);
}

bool WaitForExpectedResponse(char* ExpectedResponse)
{
    Start_Read_Response(ExpectedResponse);	/* First read response */
    if((Response_Status != ESP_RESPONSE_TIMEOUT))
        return true;				/* Return true for success */
    return false;				/* Else return false */
}

bool SendATandExpectResponse(uint32_t ui32Base,char* ATCommand, char* ExpectedResponse)
{
    ESP_Clear();
    uartSendString(ui32Base,ATCommand);		/* Send AT command to ESP */
    uartSendString(ui32Base,"\r\n");
    return WaitForExpectedResponse(ExpectedResponse);
}

bool ESP_ApplicationMode(uint32_t ui32Base,uint8_t Mode)
{
    char _atCommand[20];
    memset(_atCommand, 0, 20);
    sprintf(_atCommand, "AT+CIPMODE=%d", Mode);
    _atCommand[19] = 0;
    return SendATandExpectResponse(ui32Base,_atCommand, "\r\nOK\r\n");
}

bool ESP_ConnectionMode(uint32_t ui32Base,uint8_t Mode)
{
    char _atCommand[20];
    memset(_atCommand, 0, 20);
    sprintf(_atCommand, "AT+CIPMUX=%d", Mode);
    _atCommand[19] = 0;
    return SendATandExpectResponse(ui32Base,_atCommand, "\r\nOK\r\n");
}

bool ESP_Begin(uint32_t ui32Base)
{
	char c;
	
	WIFI_UART_BASE = ui32Base;
	delay_ms(100);
	
		uartSendString(WIFI_UART_BASE, "ATE0\r\n");
		delay_ms(200);
		while ((c = uartGetChar(WIFI_UART_BASE)) != 'K') {
			LOG_CHAR(c);
		}
		LOG_CHAR(c);
		LOG_CHAR(uartGetChar(WIFI_UART_BASE));
		LOG_CHAR(uartGetChar(WIFI_UART_BASE));
		LOG("ENDED HERE1\r\n");
		if (c == 'K') {
			uartFlushAndDebug(WIFI_UART_BASE);
			LOG("ENDED HERE2\r\n");
			return true;
		}
	return false;
}

bool ESP_Close(uint32_t ui32Base)
{
    return SendATandExpectResponse(ui32Base,"AT+CIPCLOSE=1", "\r\nOK\r\n");
}

bool ESP_WIFIMode(uint32_t ui32Base, uint32_t mode)
{
		char response[256];
    char atCommand[20];
	
		uint16_t responseLength;
	
    memset(atCommand, 0, 20);
    sprintf(atCommand, "AT+CWMODE=%iu", mode);
    atCommand[19] = 0;

    // Send the command and get the response
    
    if(!SendATCommand(ui32Base, atCommand))
        return false;

    // Check if the response contains "OK"
    response[responseLength] = '\0';
    if(strstr(response, "\r\nOK\r\n") == NULL)
        return false;

    return true;
}

bool ESP_JoinAccessPoint(const char* _SSID, const char* _PASSWORD)
{
    char _atCommand[60];
		char c;
    memset(_atCommand, 0, 60);
    sprintf(_atCommand, "AT+CWJAP=\"%s\",\"%s\"\r\n", _SSID, _PASSWORD);
	
		uartSendString(WIFI_UART_BASE, _atCommand);
		delay_ms(300);
		while ((c = uartGetChar(WIFI_UART_BASE)) != 'K') {
			LOG_CHAR(c);
		}
		LOG_CHAR(c);
			uartFlushAndDebug(WIFI_UART_BASE);
			LOG("\r\n");
			return true;
		
	return false;
}

uint8_t ESP_connected(uint32_t ui32Base)
{
    SendATandExpectResponse(ui32Base,"AT+CIPSTATUS", "\r\nOK\r\n");
    if(strstr(RESPONSE_BUFFER, "STATUS:2"))
        return ESP_CONNECTED_TO_AP;
    else if(strstr(RESPONSE_BUFFER, "STATUS:3"))
        return ESP_CREATED_TRANSMISSION;
    else if(strstr(RESPONSE_BUFFER, "STATUS:4"))
        return ESP_TRANSMISSION_DISCONNECTED;
    else if(strstr(RESPONSE_BUFFER, "STATUS:5"))
        return ESP_NOT_CONNECTED_TO_AP;
    else
        return ESP_CONNECT_UNKNOWN_ERROR;
}

bool ESP_connectServer(const char* Domain, int Port)
{
    char _atCommand[100];
		char c;
	
    memset(_atCommand, 0, 100*sizeof(char));

   
    sprintf(_atCommand, "AT+CIPSTART=\"TCP\",\"%s\",%i\r\n", Domain, Port);
		uartSendString(WIFI_UART_BASE, _atCommand);
		delay_ms(200);
	
		while ((c = uartGetChar(WIFI_UART_BASE)) != 'K') {
			LOG_CHAR(c);
		}
		if (c == 'K') {
			LOG_CHAR(c);
			uartFlushAndDebug(WIFI_UART_BASE);
			LOG("\r\n");
			return true;
		}
		
		return false;
}

bool ESP_SendAndGetResponse(char* Data, char* response, int responseLength)
{
	char c;
	int i;
	
	
	if (ESP_Send(Data)) {
		uartFlushAndDebug(WIFI_UART_BASE);
		while ((c = uartGetChar(WIFI_UART_BASE)) != ':')
			LOG_CHAR(c);
		
		if (c == ':') {
			LOG_CHAR(c);
			for (i = 0; i < responseLength; i++) {
				*(response + i) = uartGetChar(WIFI_UART_BASE);
				LOG_CHAR(*(response + i));
			}
		
			uartFlushAndDebug(WIFI_UART_BASE);
			LOG("\r\n");
			return true;
		}
	}

	return false;
}

bool ESP_GetResponse(char* response,int start, int responseLength) {
	uartFlushAndDebug(WIFI_UART_BASE);
	uartGetString(WIFI_UART_BASE, response, 10);
	return true;
}

bool ESP_Send(char* Data)
{
    char _atCommand[256];
		char c;
	
    memset(_atCommand, 0, 256*sizeof(char));
    sprintf(_atCommand, "AT+CIPSEND=%d\r\n", strlen(Data));
		uartSendString(WIFI_UART_BASE, _atCommand);
		delay_ms(200);
		while ((c = uartGetChar(WIFI_UART_BASE)) != '>') {
			LOG_CHAR(c);
		}
		if (c == '>') {
			LOG_CHAR(c);
			uartSendString(WIFI_UART_BASE, Data);
			while ((c = uartGetChar(WIFI_UART_BASE)) != 'K') {
				LOG_CHAR(c);
			}
			
			if (c == 'K') {
				LOG_CHAR(c);
				uartFlushAndDebug(WIFI_UART_BASE);
				LOG("\r\n");
				return true;
			}
		}
		return false;
	
}

int16_t ESP_DataAvailable()
{
    return (Counter - pointer);
}

uint8_t ESP_DataRead()
{
    if(pointer < Counter)
        return RESPONSE_BUFFER[pointer++];
    else{
        ESP_Clear();
        return 0;
    }
}

uint16_t Read_Data(char* _buffer)
{
    uint16_t len = 0;
    delay_ms(100);
    while(ESP_DataAvailable() > 0)
        _buffer[len++] = ESP_DataRead();
    return len;
}

