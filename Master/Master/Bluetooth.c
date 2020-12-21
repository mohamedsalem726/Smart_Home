/*
 * Bluetooth.c
 *
 * Created: 12/12/2020 2:41:11 PM
 *  Author: Mohamed Salem
 */ 

#include "Bluetooth.h"


void Bluetooth_SendData(uint8 * data)
{
	
	UART_TX(2);
	UART_TxString(data);
	UART_TX(3);
	
}