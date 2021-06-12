/*
 * test_driver.c
 *
 *  Created on: Jun 11, 2021
 *      Author: hesham
 */

#include"timer.h"

TIMER_configurationType TIMER_config;

void toggle_function(void)
{
	TOGGLE_BIT(PORTB,0);
}
int main()
{
	SET_BIT(DDRB,0);
	CLEAR_BIT(PORTB,0);
//timer configuration
TIMER_config.timerNumber=0;
TIMER_config.prescaler=1024;
strcpy(TIMER_config.mode,"normal");
//strcpy(TIMER_config.compareMatchMode,"ff");
	TIMER_init(&TIMER_config);
	TIMER_setNormal(0);
	TIMER_setCallBackPtr(toggle_function);
	while(1)
	{

	}
}

