//
// Created by zyn66 on 5/6/2023.
//

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Uart.h"


#define DEFAULT_BUFFER_SIZE		160
#define DEFAULT_TIMEOUT			10000
#define MAX_RESPONSE_LEN 256
/* Connection Mode */
#define SINGLE				0
#define MULTIPLE			1

/* Application Mode */
#define NORMAL				0
#define TRANSPERANT			1

/* Application Mode */
#define STATION				1
#define ACCESSPOINT			2
#define BOTH_STATION_AND_ACCESPOINT	3

/* Select Demo */
#define RECEIVE_DEMO			/* Define RECEIVE demo */
//#define SEND_DEMO			/* Define SEND demo */

/* Define Required fields shown below */
#define DOMAIN				"api.thingspeak.com"
#define PORT				"80"
#define API_WRITE_KEY			"C7JFHZY54GLCJY38"
#define CHANNEL_ID			"119922"

#define SSID				"ssid"
#define PASSWORD			"password"

enum ESP8266_RESPONSE_STATUS{
    ESP8266_RESPONSE_WAITING,
    ESP8266_RESPONSE_FINISHED,
    ESP8266_RESPONSE_TIMEOUT,
    ESP8266_RESPONSE_BUFFER_FULL,
    ESP8266_RESPONSE_STARTING,
    ESP8266_RESPONSE_ERROR
};

enum ESP8266_CONNECT_STATUS {
    ESP8266_CONNECTED_TO_AP,
    ESP8266_CREATED_TRANSMISSION,
    ESP8266_TRANSMISSION_DISCONNECTED,
    ESP8266_NOT_CONNECTED_TO_AP,
    ESP8266_CONNECT_UNKNOWN_ERROR
};

enum ESP8266_JOINAP_STATUS {
    ESP8266_WIFI_CONNECTED,
    ESP8266_CONNECTION_TIMEOUT,
    ESP8266_WRONG_PASSWORD,
    ESP8266_NOT_FOUND_TARGET_AP,
    ESP8266_CONNECTION_FAILED,
    ESP8266_JOIN_UNKNOWN_ERROR
};

int8_t Response_Status;
volatile int16_t Counter = 0, pointer = 0;
uint32_t TimeOut = 0;
char RESPONSE_BUFFER[DEFAULT_BUFFER_SIZE];

bool GetResponse(uint32_t ui32Base, char* Response, uint16_t ResponseLength);
bool SendATCommand(uint32_t ui32Base, char *pcCmd);
void Read_Response(char* _Expected_Response);
void ESP8266_Clear();
void Start_Read_Response(const char* _ExpectedResponse);
void GetResponseBody(char* Response, uint32_t ResponseLength);
bool WaitForExpectedResponse(const char* ExpectedResponse);
bool SendATandExpectResponse(uint32_t ui32Base,char* ATCommand, const char* ExpectedResponse);
bool ESP8266_ApplicationMode(uint32_t ui32Base,uint8_t Mode);
bool ESP8266_ConnectionMode(uint32_t ui32Base,uint8_t Mode);
bool ESP8266_Begin(uint32_t ui32Base);
bool ESP8266_Close(uint32_t ui32Base);
uint8_t ESP8266_JoinAccessPoint(uint32_t ui32Base, const char* _SSID, const char* _PASSWORD);
uint8_t ESP8266_connected(uint32_t ui32Base);
uint8_t ESP8266_Start(uint32_t ui32Base,uint8_t _ConnectionNumber, const char* Domain, const char* Port);
uint8_t ESP8266_Send(uint32_t ui32Base,char* Data);
int16_t ESP8266_DataAvailable();
uint8_t ESP8266_DataRead();
uint16_t Read_Data(char* _buffer);
