//
// Created by zyn66 on 5/6/2023.
//

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "esp.h"
#include "Uart.h"



bool GetResponse(uint32_t ui32Base, char* Response, uint16_t ResponseLength) {
    uint16_t len = 0;
    uint32_t ui32Status = 0;

    while (len < ResponseLength - 1) {
        ui32Status = UARTCharGetNonBlocking(ui32Base,Response);
        if (ui32Status == UART_ERROR) {
            return false;
        }
        else if (ui32Status == 0) {
            continue;
        }
        else {
            Response[len++] = ui32Status;
            if (Response[len - 1] == '\n') {
                Response[len] = 0;
                break;
            }
        }
    }

    if (len >= MAX_RESPONSE_LEN) {
        Response[MAX_RESPONSE_LEN - 1] = 0;
    }

    return true;
}

bool SendATCommand(uint32_t ui32Base, char *pcCmd)
{
    uartSendChar(ui32Base, 'A');  // Send 'A' character to wake up ESP8266
    uartSendChar(ui32Base, 'T');  // Send 'T' character to start AT command
    while (*pcCmd != '\0')
    {
        uartSendChar(ui32Base, *pcCmd++);
    }
    uartSendChar(ui32Base, '\r'); // Send carriage return character
    uartSendChar(ui32Base, '\n'); // Send line feed character
    return true; // Return success
}

void Read_Response(char* _Expected_Response)
{
    uint32_t EXPECTED_RESPONSE_LENGTH = strlen(_Expected_Response);
    uint32_t TimeCount = 0, ResponseBufferLength;
    char RECEIVED_CRLF_BUF[30];

    while(1)
    {
        if(TimeCount >= (DEFAULT_TIMEOUT+TimeOut))
        {
            TimeOut = 0;
            Response_Status = ESP8266_RESPONSE_TIMEOUT;
            return;
        }

        if(Response_Status == ESP8266_RESPONSE_STARTING)
        {
            Response_Status = ESP8266_RESPONSE_WAITING;
        }

        ResponseBufferLength = strlen(RESPONSE_BUFFER);
        if (ResponseBufferLength)
        {
            oneMilliSecond(1);
            TimeCount++;
            if (ResponseBufferLength==strlen(RESPONSE_BUFFER))
            {
                for (uint32_t i=0;i<ResponseBufferLength;i++)
                {
                    memmove(RECEIVED_CRLF_BUF, RECEIVED_CRLF_BUF + 1, EXPECTED_RESPONSE_LENGTH-1);
                    RECEIVED_CRLF_BUF[EXPECTED_RESPONSE_LENGTH-1] = RESPONSE_BUFFER[i];
                    if(!strncmp(RECEIVED_CRLF_BUF, _Expected_Response, EXPECTED_RESPONSE_LENGTH))
                    {
                        TimeOut = 0;
                        Response_Status = ESP8266_RESPONSE_FINISHED;
                        return;
                    }
                }
            }
        }
        oneMilliSecond(1);
        TimeCount++;
    }
}

void ESP8266_Clear()
{
    memset(RESPONSE_BUFFER,0,DEFAULT_BUFFER_SIZE);
    Counter = 0;	pointer = 0;
}

void Start_Read_Response(const char* _ExpectedResponse)
{
    Response_Status = ESP8266_RESPONSE_STARTING;
    do {
        Read_Response(_ExpectedResponse);
    } while(Response_Status == ESP8266_RESPONSE_WAITING);

}

void GetResponseBody(char* Response, uint32_t ResponseLength)
{
    uint32_t i = 12;
    char buffer[5];
    while(Response[i] != '\r')
        ++i;

    strncpy(buffer, Response + 12, (i - 12));
    ResponseLength = atoi(buffer);

    i += 2;
    uint32_t tmp = strlen(Response) - i;
    memcpy(Response, Response + i, tmp);

    if(!strncmp(Response + tmp - 6, "\r\nOK\r\n", 6))
        memset(Response + tmp - 6, 0, i + 6);
}

bool WaitForExpectedResponse(const char* ExpectedResponse)
{
    Start_Read_Response(ExpectedResponse);	/* First read response */
    if((Response_Status != ESP8266_RESPONSE_TIMEOUT))
        return true;				/* Return true for success */
    return false;				/* Else return false */
}

bool SendATandExpectResponse(uint32_t ui32Base,char* ATCommand, const char* ExpectedResponse)
{
    ESP8266_Clear();
    uartSendString(ui32Base,ATCommand);		/* Send AT command to ESP8266 */
    uartSendString(ui32Base,"\r\n");
    return WaitForExpectedResponse(ExpectedResponse);
}

bool ESP8266_ApplicationMode(uint32_t ui32Base,uint8_t Mode)
{
    char _atCommand[20];
    memset(_atCommand, 0, 20);
    sprintf(_atCommand, "AT+CIPMODE=%d", Mode);
    _atCommand[19] = 0;
    return SendATandExpectResponse(ui32Base,_atCommand, "\r\nOK\r\n");
}

bool ESP8266_ConnectionMode(uint32_t ui32Base,uint8_t Mode)
{
    char _atCommand[20];
    memset(_atCommand, 0, 20);
    sprintf(_atCommand, "AT+CIPMUX=%d", Mode);
    _atCommand[19] = 0;
    return SendATandExpectResponse(ui32Base,_atCommand, "\r\nOK\r\n");
}

bool ESP8266_Begin(uint32_t ui32Base)
{
    for (uint8_t i=0;i<5;i++)
    {
        if(SendATandExpectResponse(ui32Base,"ATE0","\r\nOK\r\n")||SendATandExpectResponse(ui32Base,"AT","\r\nOK\r\n"))
            return true;
    }
    return false;
}

bool ESP8266_Close(uint32_t ui32Base)
{
    return SendATandExpectResponse(ui32Base,"AT+CIPCLOSE=1", "\r\nOK\r\n");
}

bool ESP8266_WIFIMode(uint32_t ui32Base, uint32_t mode)
{
    char atCommand[20];
    memset(atCommand, 0, 20);
    sprintf(atCommand, "AT+CWMODE=%lu", mode);
    atCommand[19] = 0;

    // Send the command and get the response
    char response[256];
    uint16_t responseLength;
    if(!SendATCommand(ui32Base, atCommand))
        return false;

    // Check if the response contains "OK"
    response[responseLength] = '\0';
    if(strstr(response, "\r\nOK\r\n") == NULL)
        return false;

    return true;
}

uint8_t ESP8266_JoinAccessPoint(uint32_t ui32Base, const char* _SSID, const char* _PASSWORD)
{
    char _atCommand[60];
    memset(_atCommand, 0, 60);
    sprintf(_atCommand, "AT+CWJAP=\"%s\",\"%s\"", _SSID, _PASSWORD);
    _atCommand[59] = 0;
    if(SendATandExpectResponse(ui32Base,_atCommand, "\r\nWIFI CONNECTED\r\n"))
        return ESP8266_WIFI_CONNECTED;
    else{
        if(strstr(RESPONSE_BUFFER, "+CWJAP:1"))
            return ESP8266_CONNECTION_TIMEOUT;
        else if(strstr(RESPONSE_BUFFER, "+CWJAP:2"))
            return ESP8266_WRONG_PASSWORD;
        else if(strstr(RESPONSE_BUFFER, "+CWJAP:3"))
            return ESP8266_NOT_FOUND_TARGET_AP;
        else if(strstr(RESPONSE_BUFFER, "+CWJAP:4"))
            return ESP8266_CONNECTION_FAILED;
        else
            return ESP8266_JOIN_UNKNOWN_ERROR;
    }
}

uint8_t ESP8266_connected(uint32_t ui32Base)
{
    SendATandExpectResponse(ui32Base,"AT+CIPSTATUS", "\r\nOK\r\n");
    if(strstr(RESPONSE_BUFFER, "STATUS:2"))
        return ESP8266_CONNECTED_TO_AP;
    else if(strstr(RESPONSE_BUFFER, "STATUS:3"))
        return ESP8266_CREATED_TRANSMISSION;
    else if(strstr(RESPONSE_BUFFER, "STATUS:4"))
        return ESP8266_TRANSMISSION_DISCONNECTED;
    else if(strstr(RESPONSE_BUFFER, "STATUS:5"))
        return ESP8266_NOT_CONNECTED_TO_AP;
    else
        return ESP8266_CONNECT_UNKNOWN_ERROR;
}

uint8_t ESP8266_Start(uint32_t ui32Base,uint8_t _ConnectionNumber, const char* Domain, const char* Port)
{
    bool _startResponse;
    char _atCommand[60];
    memset(_atCommand, 0, 60);
    _atCommand[59] = 0;

    if(SendATandExpectResponse(ui32Base,"AT+CIPMUX?", "CIPMUX:0"))
        sprintf(_atCommand, "AT+CIPSTART=\"TCP\",\"%s\",%s", Domain, Port);
    else
        sprintf(_atCommand, "AT+CIPSTART=\"%d\",\"TCP\",\"%s\",%s", _ConnectionNumber, Domain, Port);

    _startResponse = SendATandExpectResponse(ui32Base,_atCommand, "CONNECT\r\n");
    if(!_startResponse)
    {
        if(Response_Status == ESP8266_RESPONSE_TIMEOUT)
            return ESP8266_RESPONSE_TIMEOUT;
        return ESP8266_RESPONSE_ERROR;
    }
    return ESP8266_RESPONSE_FINISHED;
}

uint8_t ESP8266_Send(uint32_t ui32Base,char* Data)
{
    char _atCommand[20];
    memset(_atCommand, 0, 20);
    sprintf(_atCommand, "AT+CIPSEND=%d", (strlen(Data)+2));
    _atCommand[19] = 0;
    SendATandExpectResponse(ui32Base,_atCommand, "\r\nOK\r\n>");
    if(!SendATandExpectResponse(ui32Base,Data, "\r\nSEND OK\r\n"))
    {
        if(Response_Status == ESP8266_RESPONSE_TIMEOUT)
            return ESP8266_RESPONSE_TIMEOUT;
        return ESP8266_RESPONSE_ERROR;
    }
    return ESP8266_RESPONSE_FINISHED;
}

int16_t ESP8266_DataAvailable()
{
    return (Counter - pointer);
}

uint8_t ESP8266_DataRead()
{
    if(pointer < Counter)
        return RESPONSE_BUFFER[pointer++];
    else{
        ESP8266_Clear();
        return 0;
    }
}

uint16_t Read_Data(char* _buffer)
{
    uint16_t len = 0;
    oneMilliSecond(100);
    while(ESP8266_DataAvailable() > 0)
        _buffer[len++] = ESP8266_DataRead();
    return len;
}


