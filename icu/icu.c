/*
 * icu.c
 *
 *  Created on: May 28, 2021
 *      Author: hesham
 */
#include"icu.h"

volatile void (*g_callback_function)(void);

void ICU_init(void)
{
	DDRD&=~(1<<PD6);
	// nomal mode
	TCCR1A=(1<<FOC1A)|(1<<FOC1B);
	//prescaler
	TCCR1B=(1<<ICES1)|(1<<CS10);
	//intial values
	TCNT1=0;
	ICR1=0;
	TIMSK|=(1<<TICIE1);

}
ISR(TIMER1_CAPT_vect)
{
	(*g_callback_function)();
}
void Icu_setCallBack(void(*a_ptr)(void))
{
	g_callback_function=a_ptr;
}
void Icu_setEdgeDetectionType(uint8 edge)
{
	if(edge==1)
	TCCR1B|=(1<<ICES1);
	else
		TCCR1B&=~(1<<ICES1);

}

uint16 Icu_getInputCaptureValue(void)
{
	return ICR1;
}

void Icu_clearTimerValue(void)
{
	TCNT1=0;
}



