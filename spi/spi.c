/*
 * spi.c
 *
 *  Created on: May 30, 2021
 *      Author: hesham
 */

#include"spi.h"

void SPI_initMaster(void)
{
DDRB|=(1<<PB4)|(1<<PB5)|(1<<PB7);
DDRB&=~(1<<PB6);
//SET_BIT(SPCR,SPE);
//sET_BIT(SPCR,MSTR);
//SET_BIT(SPCR,SPR0);
SPCR=(SPE)|(MSTR);
}
void SPI_initSlave(void)
{
	DDRB&=~(1<<PB4)&~(1<<PB5)&~(1<<PB7);
	DDRB|=(1<<PB6);
	//SET_BIT(SPCR,SPE);
	//CLEAR_BIT(SPCR,MSTR);
	//SET_BIT(SPCR,SPR0);
	SPCR=(1<<SPE);

}
void SPI_sendByte(const uint8 data)
{
SPDR=data;
while(BIT_IS_CLEAR(SPSR,SPIF));

}
uint8 SPI_recieveByte(void)
{
	while(BIT_IS_CLEAR(SPSR,SPIF));
return SPDR;
}
