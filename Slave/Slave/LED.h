/*
 * LED.h
 *
 * Created: 10/3/2020 11:21:23 AM
 *  Author: Mohamed Salem
 */ 


#ifndef LED_H_
#define LED_H_

#include "DIO.h"


void LED0_Init(void);
void LED1_Init(void);
void LED2_Init(void);

void LED0_ON(void);
void LED1_ON(void);
void LED2_ON(void);

void LED0_OFF(void);
void LED1_OFF(void);
void LED2_OFF(void);

void LED0_Toggle(void);
void LED1_Toggle(void);
void LED2_Toggle(void);



#endif /* LED_H_ */