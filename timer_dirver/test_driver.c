/*
 * test_driver.c
 *
 *  Created on: Jun 11, 2021
 *      Author: hesham
 */

#include"timer.h"

TIMER_configurationType TIMER_config;

int main()
{
	SET_BIT(DDRB,3);
	CLEAR_BIT(PORTB,3);

TIMER_config.timerNumber=0;
TIMER_config.prescaler=1024;
strcpy(TIMER_config.mode,"compare");
strcpy(TIMER_config.compareMatchMode,"toggle");
	TIMER_init(&TIMER_config);
	TIMER_set(250);
	while(1)
	{

	}
}
