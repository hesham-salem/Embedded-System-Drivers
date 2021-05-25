/*  module name :keypad driver
 *
 *  file name :keybad.c
 *
 *  description :the source file of keypad driver
 *
 *  Created on: May 24, 2021
 *
*   Author: Hesham Salem
 */

#include"keybad.h"

static uint8 KeyPad_4x3_adjustSwitchNumber(uint8 number);

/***************************************************************
 * 					function definition 						*
 * *************************************************************
 */

uint8 KeyPad_getPressedKey(void)
{
	uint8 row,col;
		for(col=0;col<N_COL;col++)
		{
			KEYPAD_PORT_DIR=(0b0001000<<col);
			KEYPAD_PORT_OUT=(~(0b0001000<<col));
			for(row=0;row<N_ROW;row++)
			{
				if(BIT_IS_CLEAR(KEYPAD_PORT_IN,row))
				{
					return KeyPad_4x3_adjustSwitchNumber((row*N_COL)+col+1);
				}
			}
		}


}
static uint8 KeyPad_4x3_adjustSwitchNumber(uint8 a_number)
{
	switch(a_number)
	{
	case 10 :
		return '*';
	case 11 :
		return 0;
	case 12 :
		return '#';
	default : return a_number;
	}

}
