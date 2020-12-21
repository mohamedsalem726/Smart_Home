/*
 * LED.c
 *
 * Created: 10/3/2020 11:23:56 AM
 *  Author: Mohamed Salem
 */ 





#include "LED.h"
#include "DIO.h"


void LED0_Init(void)
{
	DIO_SetPinDir(DIO_PORTC , DIO_PIN2 , DIO_PIN_OUTPUT);
}
void LED1_Init(void)
{
	DIO_SetPinDir(DIO_PORTC , DIO_PIN7 , DIO_PIN_OUTPUT);
}
void LED2_Init(void)
{
	DIO_SetPinDir(DIO_PORTD , DIO_PIN3 , DIO_PIN_OUTPUT);
}

void LED0_ON(void)
{
	DIO_SetPinValue(DIO_PORTC , DIO_PIN2 , DIO_PIN_HIGH);
}
void LED1_ON(void)
{
	DIO_SetPinValue(DIO_PORTC , DIO_PIN7 , DIO_PIN_HIGH);
}
void LED2_ON(void)
{
	DIO_SetPinValue(DIO_PORTD , DIO_PIN3 , DIO_PIN_HIGH);
}

void LED0_OFF(void)
{
	DIO_SetPinValue(DIO_PORTC ,DIO_PIN2 ,DIO_PIN_LOW);
}
void LED1_OFF(void)
{
	DIO_SetPinValue(DIO_PORTC ,DIO_PIN7 ,DIO_PIN_LOW);
}
void LED2_OFF(void)
{
	DIO_SetPinValue(DIO_PORTD ,DIO_PIN3 ,DIO_PIN_LOW);
}

void LED0_Toggle(void)
{
	Toggle_BIT(PORTC,2);
}
void LED1_Toggle(void)
{
	Toggle_BIT(PORTC,7);
}
void LED2_Toggle(void)
{
	Toggle_BIT(PORTD,3);
}