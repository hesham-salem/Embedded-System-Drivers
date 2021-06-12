/*
 * timer.c
 *
 *  Created on: Jun 11, 2021
 *      Author: hesham
 */

#include"timer.h"
static volatile  void(*g_callBackPtr)(void)= NULL_PTR;
ISR(TIMER0_COMP_vect)
{
	if(g_callBackPtr!=NULL_PTR)
		g_callBackPtr();

}
ISR(TIMER0_OVF_vect)
{
	if(g_callBackPtr!=NULL_PTR)
		g_callBackPtr();

}
void TIMER_init(const TIMER_configurationType * config)
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
	{	TCCR0|=(1<<FOC0)|(1<<WGM01);

		if(!strcmp(config->compareMatchMode,"toggle"))
		{
		TCCR0|=(1<<COM00);
		SET_BIT(DDRB,3);
		}
		else if(!strcmp(config->compareMatchMode,"clear"))
			{
			TCCR0|=(1<<COM01);
			SET_BIT(DDRB,3);

			}
		else if(!strcmp(config->compareMatchMode,"set"))
			{
			TCCR0|=(1<<COM01)|(1<<COM00);
			SET_BIT(DDRB,3);

			}
		//enable interrupt
		TIMSK=(1<<OCIE0);

	}
	else if(!strcmp(config->mode,"normal"))
	{
		TCCR0|=(1<<FOC0);
		TIMSK=(1<<TOIE0);
	}
	else if(!strcmp(config->mode,"pwm"))
	{
		TCCR0 |=(1<<WGM00)|(1<<WGM01);
		if(!strcmp(config->pwmMode,"inverting"))
				{
				TCCR0|=(1<<COM00);
				TCCR0|=(1<<COM01);
				SET_BIT(DDRB,3);
				}
				else if(!strcmp(config->pwmMode,"non-inverting"))
					{
					TCCR0|=(1<<COM01);
					SET_BIT(DDRB,3);

					}

	}

	//TCCR0=(1<<FOC0)|(1<<COM00)|(1<<CS00)|(1<<CS02);


	//enable

	sei();
}
}
void TIMER_setCompare(uint8 compareValue)
{
	TCNT0=0;
	OCR0=compareValue;
}
void TIMER_setNormal(uint8 initValue)

{
	TCNT0=initValue;
}

void TIMER_setpwm(uint8 dutyCycle)
{
	TCNT0=0;
	OCR0=dutyCycle;
}

void TIMER_setCallBackPtr(void(*a_ptr)(void))
{
g_callBackPtr=a_ptr;
}
void TIMER_stop()
{
	TCCR0&=~(1<<CS00)&~(1<<CS01)&~(1<<CS02);
}
