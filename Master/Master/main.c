/*
 * main.c
 *
 * Created: 12/16/2020
 *  Author: Mohamed Salem
 */ 
 
 #define F_CPU	8000000
 #include "Bluetooth.h" 
 #include "SPI.h"
 #include "LCD.h"
 #include "UART.h"
 #include <util/delay.h>

 #define _LED0_ON	'1'
 #define _LED1_ON	'2'
 #define _LED2_ON	'3'
 #define _LED0_OFF	'4'
 #define _LED1_OFF	'5'
 #define _LED2_OFF	'6'
 #define _ALL_ON	'7'
 #define _ALL_OFF	'8'
 
 #define WrongPass	1
 #define RightPass	0
 #define PassLength	4
 #define Password	"1234"
 #define MaxTryNum	3
 
 uint8 PasswordState = WrongPass;
 
 void PasswordCheck(void);
 
 int main(void)
 {
	 uint8 rec_data = 0;
	 uint8 Command = 0;
	 uint8 data = 0;
	 SPI_Master_Init();
	 LCD_Init();
	 UART_Init();
	 _delay_ms(1000); 
	 
	 
	 while (PasswordState == WrongPass){
		 PasswordCheck();
	 }
	 
	 while(1)
	 {
	
	data = UART_RX();
	if(data == _LED0_ON)
	{
		Command = data;
	}
	else if(data == _LED1_ON)
	{
		Command = data;
	}
	else if(data == _LED2_ON)
	{
		Command = data;
	}
	else if(data == _LED0_OFF)
	{
		Command = data;
	}
	else if(data == _LED1_OFF)
	{
		Command = data;
	}
	else if(data == _LED2_OFF)
	{
		Command = data;
	}
	else if(data == _ALL_ON)
	{
		Command = data;
	}
	else if(data == _ALL_OFF)
	{
		Command = data;
	}
	else{
		/* error */
	}
	LCD_Clear();
	switch(Command)
	{
		case _LED0_ON:	LCD_WriteString("LED0 ON");			break;
		case _LED1_ON:	LCD_WriteString("LED1 ON");			break;
		case _LED2_ON:	LCD_WriteString("LED2 ON");			break;
		case _LED0_OFF: LCD_WriteString("LED0 OFF");		break;
		case _LED1_OFF: LCD_WriteString("LED1 OFF");		break;
		case _LED2_OFF: LCD_WriteString("LED2 OFF");		break;
		case _ALL_ON:	LCD_WriteString("All LEDs ON");		break;
		case _ALL_OFF:	LCD_WriteString("All LEDs OFF");	break;
		default: break;
	}
	
	rec_data = SPI_Transiver(Command);
	 }
	 
	 
	 
	 return 0;
 }
 
 void PasswordCheck(void)
 {
	 static uint8 wrongTimes = 0;
	 uint8 rightOrWrong = 1;
	 uint8 passVal[4];
      LCD_Clear();  
	 if(wrongTimes < MaxTryNum)
	 {
		 LCD_WriteString("Password: ");
	 for(uint8 i = 0; i<PassLength; i++)
	 {
		 passVal[i]=UART_RX();
		 LCD_WriteChar(passVal[i]);
	 }
	 
	 for(uint8 i = 0; i<PassLength; i++)
	 {
		 if(passVal[i] != Password[i])
		 {
			 LCD_Goto(1,0);
			 LCD_WriteString("WrongPass ");
			 wrongTimes++;
			 LCD_WriteChar(48+wrongTimes);
			 LCD_WriteString("Times");
			 rightOrWrong = 0;
			 _delay_ms(1000);
			 break;
		 }
	 }
	 
	 if(rightOrWrong)
	 {
		 _delay_ms(1000);
		 LCD_Clear();
		 PasswordState = RightPass;
		 LCD_WriteString("Right Pass");
		 LCD_Goto(1,0);
		 LCD_WriteString("Welcome");
		 _delay_ms(2000);
		 LCD_Clear();		 
	 }
	 }
	 else
	 {
		 LCD_Clear();
		 LCD_WriteString("Access Denied"); 
		 while(1);
	 }
	 
	 
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 