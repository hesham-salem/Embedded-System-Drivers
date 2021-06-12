/*
 * timer.h
 *
 *  Created on: Jun 11, 2021
 *      Author: hesham
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "common_macros.h"
#include "micro_config.h"
#include "std_types.h"
#include <string.h>
typedef struct
{
	uint8 timerNumber;
	char mode[20];
	uint16 prescaler;
	char compareMatchMode[20];

}TIMER_configurationType;

void TIMER_init(const TIMER_configurationType * config);
void TIMER_set(uint8 compareValue);
void TIMER_setCallBack(void(*a_ptr)(void));


#endif /* TIMER_H_ */
