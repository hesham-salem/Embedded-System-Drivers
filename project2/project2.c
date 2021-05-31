/*
 * src.c
 *
 *  Created on: May 31, 2021
 *      Author: hesham
 */
#include"project2.h"
void PWM_Timer0_Init(unsigned char set_duty_cycle)
{

	TCNT0 = 0; //Set Timer Initial value

	OCR0  = set_duty_cycle; // Set Compare Value

	DDRB  = DDRB | (1<<PB3); //set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
uint8 mapping(uint16 data)
{
	return (255/1024)*data;
}


uint16 analogValue;
uint8 pwm_value;
void main()
{
ADC_init();
LCD_init();

while(1)
{
	analogValue=ADC_readChannel(0);
	LCD_intgerToString(analogValue);
	pwm_value=mapping(analogValue);
	PWM_Timer0_Init(pwm_value);

}
}

