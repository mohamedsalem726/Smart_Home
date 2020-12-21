/*
 * Button.c
 *
 * Created: 10/3/2020 12:01:01 PM
 *  Author: Mohamed Salem
 */ 


#include "Button.h"







void Button1_Init(void)
{
	CLR_BIT(DDRB,4);
}

uint8 Button1_GetVal(void)
{
	uint8 value = 0;
	
	value = GET_BIT(PINB,4);
	
	while(GET_BIT(PINB,4));
	
	_delay_ms(10);
	
	return value;
	
}