/*
 * icu.h
 *
 *  Created on: May 28, 2021
 *      Author: hesham
 */

#ifndef ICU_H_
#define ICU_H_
#include"common_macros.h"
#include"micro_config.h"
#include"std_types.h"

void ICU_init(void);
void Icu_setCallBack(void(*a_ptr)(void));
void Icu_setEdgeDetectionType(uint8 edge);
void Icu_setEdgeDetectionType(uint8 edge);
void Icu_clearTimerValue(void);



#endif /* ICU_H_ */
