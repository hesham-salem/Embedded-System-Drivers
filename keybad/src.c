/*
 * src.c
 *
 *  Created on: May 25, 2021
 *      Author: hesham
 */
#include"keybad.h"

int main()
{
	uint8 value;
	DDRC |=0X0F;
	PORTC &=~(0x0f);

	while(1)
	{
	value=KeyPad_getPressedKey();
		if(value<10)

			PORTC=(PORTC&(0xf0))|((value&(0x0f)));


	}

}

