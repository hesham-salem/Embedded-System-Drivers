/*
 * uart.c
 *
 *  Created on: May 29, 2021
 *      Author: hesham
 */
#include"uart.h"

void UART_init(void)
{
/* enables */
	//UCSRA = (1<<U2X);
SET_BIT(UCSRB,RXEN);
SET_BIT(UCSRB,TXEN);
/* TO enable writing on Register UCSRC (used for define the frame )as it has the same address with UBRR register */
SET_BIT(UCSRC,URSEL);
/* the UART frame parameters*/
/* character size */
SET_BIT(UCSRC,UCSZ0);
SET_BIT(UCSRC,UCSZ1);
/* write on UBRR instead of ucsrc register */
CLEAR_BIT(UCSRC,URSEL);
/* writing the baud rate prescaler */
UBRRL=12;
UBRRH=12>>8;


}

uint8 UART_recieveByte(void)
{
	while(BIT_IS_CLEAR(UCSRA,RXC)); /* wait until RXC  flag be 1 it means that there is data not read */

	return UDR;/* read and return RXC flag to zero */
}
void UART_sendByte(uint8 data)
{
	UDR=data;
	UDR = data;
		while(BIT_IS_CLEAR(UCSRA,TXC)){} // Wait until the transimission is complete TXC = 1
		SET_BIT(UCSRA,TXC); // Clear the TXC flag
}
