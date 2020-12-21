/*
 * Button.h
 *
 * Created: 10/3/2020 12:00:44 PM
 *  Author: Mohamed Salem
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "Atmega32_Registers.h"
#include "Bit_Math.h"
#define F_CPU 16000000
#include <util/delay.h>


void Button1_Init(void);

uint8 Button1_GetVal(void);





#endif /* BUTTON_H_ */