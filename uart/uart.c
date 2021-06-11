/*
 * uart.c
 *
 *  Created on: May 29, 2021
 *      Author: hesham
 */
#include"uart.h"

void UART_init(UART_configurationType * config)
{
/* enables */
	if(config->mode=="normal")
	{
CLEAR_BIT(UCSRA,U2X);
UBRRL=((F_CPU /(16*config->buadRate))-1);
UBRRH=((F_CPU /(16*config->buadRate))-1)>>8;


	}
	else if(config->mode=="double speed")
	{
		SET_BIT(UCSRA,U2X);
		UBRRL=((F_CPU /(8*config->buadRate))-1);
		UBRRH=((F_CPU /(8*config->buadRate))-1)>>8;
	}


/* TO enable writing on Register UCSRC (used for define the frame )as it has the same address with UBRR register */
SET_BIT(UCSRC,URSEL);
/* the UART frame parameters*/
/* character size */
//SET_BIT(UCSRC,UCSZ0);
//SET_BIT(UCSRC,UCSZ1);
switch(config->character_size)
{
case 5:
	CLEAR_BIT(UCSRC,UCSZ0);
	CLEAR_BIT(UCSRC,UCSZ1);
	break;

case 6:
	CLEAR_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
	break;
case 7:
	CLEAR_BIT(UCSRC,UCSZ1);
	SET_BIT(UCSRC,UCSZ0);
		break;
case 9:
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
	SET_BIT(UCSRC,UCSZ2);
	typedef uint16 character ;

	break;

default :
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
}

/* write on UBRR instead of ucsrc register */
//CLEAR_BIT(UCSRC,URSEL);//---------------------------------------<<<<
/* writing the baud rate prescaler */
//UBRRL=12;
//UBRRH=12>>8;
SET_BIT(UCSRB,RXEN);
SET_BIT(UCSRB,TXEN);
}

uint8 UART_recieveByte(void)
{
	while(BIT_IS_CLEAR(UCSRA,RXC)); /* wait until RXC  flag be 1 it means that there is data not read */

	return UDR;/* read and return RXC flag to zero */
}
void UART_sendByte(const uint8 data)
{
	UDR=data;
	while(BIT_IS_SET(UCSRA,TXC));//wait until send data txc =1;
	CLEAR_BIT(UCSRA,TXC); //clear the flag as it doesnt clear automatically as ISR
}
void UART_sendString(uint8 *str)
{
	for(uint8 i=0;str[i]!='\n';i++)
	{
		UART_sendByte(str[i]);
	}
	//UART_sendByte('#');

}
void UART_recieveString(uint8 *str)
{
	uint8 i=0;
	for( i=0;str[i]!='\0';i++)
	{
		str[i]=UART_recieveByte();
	}
	str[i]='\0';
}
