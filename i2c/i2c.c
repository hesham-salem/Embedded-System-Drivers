/*
 * i2c.c
 *
 *  Created on: Jun 6, 2021
 *      Author: hesham
 */
#include"i2c.h"

void TWI_init(void)
{
	TWBR=0X02;//buad rate
	TWSR=0X00; //prescaler
	 TWAR=0B00000100;// adress+ other bit
	TWCR|=(1<<TWEN);// دائما فى الاخر

}
void TWI_start(void)
{
	//make enable again to force other bits in the register to be zero
	//start bit and clear done flag
TWCR=(1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
while(BIT_IS_CLEAR(TWCR,TWINT));// WAIT acation done
}
void TWI_stop(void)
{
TWCR=(1<<TWINT)|(1<<TWSTO)|(1<<TWEN);

//NO NEED TO WAIT twint flag
}
void TWI_write(uint8 data)
{
	TWDR=data;
	TWCR=(1<<TWINT)|(TWEN);
	while(BIT_IS_CLEAR(TWCR,TWINT));
}
uint8 TWI_read_with_ACK(void)
{
	TWCR=(1<<TWINT)|(1<<TWEA)|(TWEN);
	while(BIT_IS_CLEAR(TWCR,TWINT));
	//CLEAR flag before or after
	return TWDR;
}

uint8 TWI_read_with_NACK(void)
{
	TWCR=(1<<TWINT)|(TWEN);
	while(BIT_IS_CLEAR(TWCR,TWINT));
	//CLEAR flag before or after
	return TWDR;
}
uint8 TWI_getStatus()
{
	return TWSR&0XF8;
}
