/*
 * adc.h
 *
 *  Created on: May 28, 2021
 *      Author: hesham
 */

#ifndef ADC_H_
#define ADC_H_
#include"common_macros.h"
#include"micro_config.h"
#include"std_types.h"

void ADC_init(void);
uint16 ADC_readChannel(uint8 ch_num);




#endif /* ADC_H_ */
