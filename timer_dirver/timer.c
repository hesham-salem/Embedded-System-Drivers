/*
 * timer.c
 *
 *  Created on: Jun 11, 2021
 *      Author: hesham
 */

#include"timer.h"


void TIMER_init(TIMER_configurationType * config)
{
	if(config->timerNumber==0)
	{
		TCCR0=0;
	switch(config->prescaler)
	{
	case 8:
		TCCR0|=(1<<CS01);
		break;
	case 64:
			TCCR0|=(1<<CS00)|(1<<CS01);
			break;
	case 256:
			TCCR0|=(1<<CS02);
			break;
	case 1024:
			TCCR0|=(1<<CS00)|(1<<CS02);
			break;
	default:
			TCCR0|=(1<<CS00);

		}

	if(!strcmp(config->mode,"compare"))
	{	TCCR0|=(1<<FOC0);
		if(!strcmp(config->compareMatchMode,"toggle")) 	TCCR0|=(1<<COM00);
		else if(config->compareMatchMode=="clear") 	TCCR0|=(1<<COM01);
		else if(config->compareMatchMode=="set") 	TCCR0|=(1<<COM01)|(1<<COM00);
	}

	//TCCR0=(1<<FOC0)|(1<<COM00)|(1<<CS00)|(1<<CS02);


	//enable
	TIMSK=(1<<OCIE0);
	sei();
}
}
void TIMER_set(uint8 compareValue)
{
	TCNT0=0;
	OCR0=compareValue;
}
