//
// Created by zyn66 on 5/6/2023.
//
#ifndef ESP_H
#define ESP_H

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../uart/UART.h"
#include "../utils.h"

/* Select Demo */
#define RECEIVE_DEMO			/* Define RECEIVE demo */
//#define SEND_DEMO			/* Define SEND demo */
#define SERVER_RESPONSE_END 1278

extern unsigned int WIFI_UART_BASE;

extern char temp[256];
extern char y;

enum ESP_RESPONSE_STATUS{
    ESP_RESPONSE_WAITING,
    ESP_RESPONSE_FINISHED,
    ESP_RESPONSE_TIMEOUT,
    ESP_RESPONSE_BUFFER_FULL,
    ESP_RESPONSE_STARTING,
    ESP_RESPONSE_ERROR
};

enum ESP_CONNECT_STATUS {
    ESP_CONNECTED_TO_AP,
    ESP_CREATED_TRANSMISSION,
    ESP_TRANSMISSION_DISCONNECTED,
    ESP_NOT_CONNECTED_TO_AP,
    ESP_CONNECT_UNKNOWN_ERROR
};

enum ESP_JOINAP_STATUS {
    ESP_WIFI_CONNECTED,
    ESP_CONNECTION_TIMEOUT,
    ESP_WRONG_PASSWORD,
    ESP_NOT_FOUND_TARGET_AP,
    ESP_CONNECTION_FAILED,
    ESP_JOIN_UNKNOWN_ERROR
};

extern int8_t Response_Status;
extern volatile int16_t Counter, pointer;
extern uint32_t TimeOut;
extern char RESPONSE_BUFFER[100];

bool GetResponse(uint32_t ui32Base, char* Response, uint16_t ResponseLength);
bool SendATCommand(uint32_t ui32Base, char *pcCmd);
void Read_Response(char* _Expected_Response);
void ESP_Clear();
void Start_Read_Response(char* _ExpectedResponse);
void GetResponseBody(char* Response, uint32_t ResponseLength);
bool WaitForExpectedResponse(char* ExpectedResponse);
bool SendATandExpectResponse(uint32_t ui32Base,char* ATCommand, char* ExpectedResponse);
bool ESP_ApplicationMode(uint32_t ui32Base,uint8_t Mode);
bool ESP_ConnectionMode(uint32_t ui32Base,uint8_t Mode);
bool ESP_Close(uint32_t ui32Base);

bool ESP_Begin(uint32_t ui32Base);
bool ESP_connectServer(const char* Domain,int Port);
bool ESP_JoinAccessPoint(const char* _SSID, const char* _PASSWORD);
bool ESP_Send(char* Data);
bool ESP_SendAndGetResponse(char* Data, char* response, int responseLength);
bool ESP_GetResponse(char* response,int start, int responseLength);

uint8_t ESP_connected(uint32_t ui32Base);

int16_t ESP_DataAvailable();
uint8_t ESP_DataRead();
uint16_t Read_Data(char* _buffer);

#endif