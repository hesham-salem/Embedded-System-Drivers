/*
 * Exercise2.c
 *
 * Created: 4/3/2014 6:00:08 PM
 *  Author: Mohamed Tarek
 */

#include "lcd.h"

int main(void)
{
	LCD_init();
	// LCD_displayCharacter('A');
	//  LCD_displayString("embedded");



	 LCD_displayStringRowColumn(0,2,"My LCD Driver");
	 LCD_displayStringRowColumn(1,3,"Embedded WS");
	_delay_ms(4000); // wait four seconds
	LCD_clearScreen(); // clear the LCD display
	//LCD_displayString("Interf. Course");
//	LCD_displayStringRowColumn(1,5,"Group ");
	LCD_intgerToString(55);

    while(1)
    {
		/* Note: we write the code before while(1) because we want to execute it only once */
    }

}
