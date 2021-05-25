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
static uint8 KeyPad_4x4_adjustSwitchNumber(uint8 number);

/***************************************************************
 * 					function definition 						*
 * *************************************************************
 */

uint8 KeyPad_getPressedKey(void) {
	uint8 row, col;
	for (col = 0; col < N_COL; col++) {
		KEYPAD_PORT_DIR = (0b0001000 << col);
		KEYPAD_PORT_OUT = (~(0b0001000 << col));
		for (row = 0; row < N_ROW; row++) {
			if (BIT_IS_CLEAR(KEYPAD_PORT_IN, row)) {
				return KeyPad_4x3_adjustSwitchNumber((row * N_COL) + col + 1);
			}
		}
	}

}
static uint8 KeyPad_4x3_adjustSwitchNumber(uint8 a_number) {
	switch (a_number) {
	case 10:
		return '*';
	case 11:
		return 0;
	case 12:
		return '#';
	default:
		return a_number;
	}
	static uint8 KeyPad_4x4_adjustSwitchNumber(uint8 a_number) {
		switch (a_number) {
		case 1:
			return 7;
		case 2:
			return 8;
		case 3:
			return 9;
		case 4:
			return '/';
		case 5:
			return  4;
		case 6:
			return 5 ;
		case 7:
			return 6;
		case 8:
			return '*';
		case 9:
			return 1;
		case 10:
			return 2;
		case 11:
			return 3;
		case 12:
			return '-';
		case 13:
			return 13;
		case 14:
			return "0";
		case 15:
			return '=';
		case 16:
			return '+';

		}
	}
