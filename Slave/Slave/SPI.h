/*
 * SPI.h
 *
 * Created: 10/30/2020 12:45:06 PM
 *  Author: Mohamed Salem
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "DIO.h"



void SPI_Master_Init(void);

void SPI_Slave_Init(void);

void SPI_Master_Init_Trans(void);

void SPI_Master_Ter_Trans(void);

uint8 SPI_Transiver(uint8 data);

uint8 SPI_Receive(void);


#endif /* SPI_H_ */