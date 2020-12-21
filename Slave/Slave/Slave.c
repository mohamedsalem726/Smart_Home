/*
 * main.c
 *
 * Created: 12/16/2020
 *  Author: Mohamed Salem
 */ 
 #define  F_CPU 16000000
 #include "SPI.h"
 #include "LED.h"
#include  <util/delay.h>
 
 #define _LED0_ON	'1'
 #define _LED1_ON	'2'
 #define _LED2_ON	'3'
 #define _LED0_OFF	'4'
 #define _LED1_OFF	'5'
 #define _LED2_OFF	'6'
 #define _ALL_ON	'7'
 #define _ALL_OFF	'8'
 
 volatile uint8 SPI_Rec[2];
 volatile uint8 Index = 0;
 volatile uint8 ReadFlag = 1;
 

 
 int main(void)
 {
	 
	 uint8 Recived_Data = 0;
	 uint8 Trans_Data = 1;
	SPI_Slave_Init();
	LED0_Init();
	LED1_Init();
	LED2_Init();
	
	
	
	_delay_ms(1000);
	while(1)
	{	  
	
		 Recived_Data = SPI_Transiver('\n');
	  
	  
		if (Recived_Data==_LED0_ON){
			LED0_ON();
		}else if (Recived_Data==_LED1_ON){
			LED1_ON();
		}else if (Recived_Data==_LED2_ON){
			LED2_ON();
		}else if (Recived_Data==_LED0_OFF){
			LED0_OFF();
		}else if (Recived_Data==_LED1_OFF){
			LED1_OFF();
		}else if (Recived_Data==_LED2_OFF){
			LED2_OFF();
		}
		else if (Recived_Data==_ALL_ON){
			LED0_ON();
			LED1_ON();
			LED2_ON();
		}
		else if (Recived_Data==_ALL_OFF){
			LED0_OFF();
			LED1_OFF();
			LED2_OFF();
		}
// 		switch(Recived_Data)
// 		{
// 			case _LED0_ON:
// 			   LED0_ON();
// 			break;	 
// 			case _LED1_ON:
// 			    LED1_ON();
// 			break;
//  	 		case _LED2_ON:
// 			    LED2_ON();
// 			break;
// 			case _LED0_OFF:
// 			    LED0_OFF();
// 			break;
// 			case _LED1_OFF:
// 			    LED1_OFF();
// 			break;
// 			case _LED2_OFF:
// 			    LED2_OFF();
// 			break;
// 			default:
// 			
// 			break;
//   		}		
		}
  			
	
	 return 0;
	 		
 }				
 
  