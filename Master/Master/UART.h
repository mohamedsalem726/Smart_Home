/*
 * UART.h
 *
 * Created: 10/28/2020 5:37:41 PM
 *  Author: Mohamed Salem
 */ 


#ifndef UART_H_
#define UART_H_


#include "Atmega32_Registers.h"
#include "BIT_Math.h"


void UART_Init(void);

void UART_TX(uint8 data);

void UART_TxString(uint8* str);

uint8 UART_RX(void);





#endif /* UART_H_ */