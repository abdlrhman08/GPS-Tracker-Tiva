# GPS Tracker Tiva TM4c123 GXL(accumulative work of 500 hours)

This embedded module tracks your location using the gps module and parses all information it can from the NMEA Message, like time, date and location. Sends the information to a JAVA server and the server then sends it to an application which show the position of the TIVA,

> All drivers are written with code reusability in mind.
# Extra features 
* ## LCD :arrow_right: displays the time ,speed and location 
* ## Java Server 
* ## Wifi module :arrow_right: makes connection wireless with pc
* ## Application :arrow_right: diplays same LCD info on pc ![image](https://github.com/abdlrhman08/GPS-Tracker-Tiva/assets/131257593/f4245fdb-e9ab-42b1-b034-9010bcd61ede)


* ### arduino mega + speaker >> treats pin 6 and 7 as the leds of TIVA so the speaker produces different songs in different situations

* 
|case         | pin 6    |pin 7  | song number |
| --- | --- | --- | --- |
|normal       |  1       |  1    |[ song 1  ](https://github.com/abdlrhman08/GPS-Tracker-Tiva/assets/89034348/8d0e7e9b-3f33-4e29-b987-f7ab8c413f91)    |
|out of track |  1       |  0    | [song 2](https://github.com/abdlrhman08/GPS-Tracker-Tiva/assets/89034348/8d0e7e9b-3f33-4e29-b987-f7ab8c413f91)     |
|finish       |  0       |  1    | [song 3](https://github.com/abdlrhman08/GPS-Tracker-Tiva/assets/89034348/43420f24-f454-4257-99c2-2e1e415663c0)      |
|impossible   |  0       |  0    | Off     |
## Contributors

|Name        | code    |Department  | 
| :--- | :---: | :---: |
|Nassar khaled mesoud | 2001464 | CSE|
|abdelrahman atef saad hamada |2101645| CSE|
|abdelrahman zain mohmed |2101646| CSE|
|mahmoud osama mohmed abdelaal| 2101713| ECE|
|shawky ahmed shawky |2002020 |CSE|
|ahmed adel ali mashal| 2002296 |ECE |
### Data flow
```mermaid
graph TD;
    gps-->|GPS Data|Tiva;
    Tiva-->|string|lcd;
    Tiva-->|finish pin6 1 >> 0 <br> and out of track pin 7 1 >> 0 |Arduino;
    Arduino-->buzzer;
    Tiva-->|AT Wifi commands|Wifi_module;
    Wifi_module-->|custom made <br> Server commands|TCP_Server;
    TCP_Server-->|response|Wifi_module;
    Application-->|custom made <br> application commands|TCP_Server;
    TCP_Server-->|response|Application;
    
```
[Server repo](https://github.com/abdlrhman08/GPS-Tracker-Server)

## identification commands

|Command      | Description  | 
| :--- | :--- |
| |When the client is first connected to the server, the server waits for.a 4 byte message to identify themself|
||tiva: This message is sent by the Wi-Fi module of the Tiva, so the server understands that it will later send the destination point to it|
||appl: This message is sent by the application, the server will know that it will be the one who assigns the destination point|
||After the server receives the identification message it will assign a thread to the client and start the lifecycle loop and wait for commands|
||This commands the server first checks if it is sent by the app or the tiva, if it is the send by the app it sends a one byte message '1'. <br> This message tells the client that it is waiting for a response. Here the application should send to the application the destination point where you want the Tiva to go|
||If the command was send by Tiva it will respond with the same one byte message and it will wait for the Tiva to respond with its starting point. <br> After that, the Server will reply to the tiva with the destination point which the app sent first|


## GPS commands

|Command      | Description  | 
| :--- | :--- |





