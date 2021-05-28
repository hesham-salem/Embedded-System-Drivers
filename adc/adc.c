/*
 * adc.c
 *
 *  Created on: May 28, 2021
 *      Author: hesham
 */
#include"adc.h"

void ADC_init(void)
{
//ADMUX=0 ---> REF (AREF)  and assume the work on channel 0
	ADMUX=0;
	//ADCSRA --> ENABLE ADC
	SET_BIT(ADCSRA,7);
	// disable interrupt
	CLEAR_BIT(ADCSRA,3);
	// select scaller /8
	ADCSRA |=(1<<0)|(1<<1);
	CLEAR_BIT(ADCSRA,2);

}

uint16 ADC_readChannel(uint8 ch_num)
{
// insert ch_num
	ADMUX=ch_num;
	//start conversion
	SET_BIT(ADCSRA,6);
	//PULLING unitl ADIF =1
	while(BIT_IS_SET(ADCSRA,4)){}
	// clear ADIF
	CLEAR_BIT(ADCSRA,4);
	// return ADC
	return ADC;

}
