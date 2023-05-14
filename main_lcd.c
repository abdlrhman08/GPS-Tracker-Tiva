#include "SYSTICK.h"
#include "tm4c123gh6pm.h"
#include "LCD.h"
#include <stdio.h>
char distance[40] = "30000" ;;
char time[40] = " 12:00 ";
char speed[40] = " 20 ";
char lineardist[40] = "2000";
char latitude[40] = "1234567" ;
char longitude[40] = "245671" ;

void SystemInit(){}

void LCD_message_R1(char *data){
			LCD_CMD(clear_display);
			delay_milli(100);
			LCD_CMD(cursorOn);
			delay_milli(100);
			LCD_CMD(FirstRow);
			delay_milli(100);
			LCD_String(data);
			delay_milli(100);
}
/*void LCD_message_Dis(char *distance , char *Time){
			LCD_CMD(clear_display);
			delay_milli(15);
			LCD_CMD(FirstRow);
			delay_milli(15);
			LCD_CMD(cursorOn);
			delay_milli(15);
			LCD_String("Distance :" );
	    LCD_String(distance );
	    LCD_String(" m");
			delay_milli(15);
			LCD_CMD(SecondRow);
			delay_milli(15);
			LCD_CMD(cursorOn);
			delay_milli(15);
			LCD_String("Time :" );
	    LCD_String(time );
}
void LCD_speed_lineardistance(char *speed , char *lindistance){
			LCD_CMD(clear_display);
			delay_milli(15);
			LCD_CMD(FirstRow);
			delay_milli(15);
			LCD_CMD(cursorOn);
			delay_milli(15);
			LCD_String("Speed is :" );
	    LCD_String(speed );
	    LCD_String(" m/sec");
			delay_milli(15);
			LCD_CMD(SecondRow);
			delay_milli(15);
			LCD_CMD(cursorOn);
			delay_milli(15);
			LCD_String("linear distance :" );
	    LCD_String(lindistance );
	    LCD_String(" m");
}

void LCD_LatLogDis(char *lat,char *log){
			LCD_CMD(clear_display);
			delay_milli(15);
			LCD_CMD(FirstRow);
			delay_milli(15);
			LCD_CMD(cursorOn);
			delay_milli(15);
			LCD_String("Lat = ");
			LCD_String(lat);
			delay_milli(15);
			LCD_CMD(SecondRow);
			delay_milli(15);
			LCD_CMD(cursorOn);
			delay_milli(15);
			LCD_String("Log = ");
			LCD_String(log);
}*/
int main (){
	// display distance and time
LCD_CMD(clear_display);
			delay_milli(15);
			LCD_CMD(FirstRow);
			delay_milli(15);
			LCD_CMD(cursorOn);
			delay_milli(15);
			LCD_String("distance = ");
			LCD_String(distance);
	    LCD_String(" m"); 
			LCD_CMD(SecondRow);
			delay_milli(15);
			LCD_CMD(cursorOn);
			delay_milli(15);
			LCD_String("Time = ");
			LCD_String(time);	
		  LCD_String(" s"); 
			delay_milli(1000);

   // display speed and distance
	    LCD_CMD(clear_display);
			delay_milli(15);
			LCD_CMD(FirstRow);
			delay_milli(15);
			LCD_CMD(cursorOn);
			delay_milli(15);
			LCD_String("Speed is :" );
	    LCD_String(speed );
	    LCD_String(" m/sec");
			delay_milli(15);
			LCD_CMD(SecondRow);
			delay_milli(15);
			LCD_CMD(cursorOn);
			delay_milli(15);
			LCD_String("linear distance :" );
	    LCD_String(lineardist );
	    LCD_String(" m"); 
			delay_milli(1000);

   // latitude speed and longitude
      LCD_CMD(clear_display);
			delay_milli(15);
			LCD_CMD(FirstRow);
			delay_milli(15);
			LCD_CMD(cursorOn);
			delay_milli(15);
			LCD_String("Lat = ");
			LCD_String(latitude);
			delay_milli(15);
			LCD_CMD(SecondRow);
			delay_milli(15);
			LCD_CMD(cursorOn);
			delay_milli(15);
			LCD_String("Log = ");
			LCD_String(longitude);
			delay_milli(1000);
}

