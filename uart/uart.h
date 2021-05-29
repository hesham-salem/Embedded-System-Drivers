/*
 * uart.h
 *
 *  Created on: May 29, 2021
 *      Author: hesham
 */

#ifndef UART_H_
#define UART_H_
#include "common_macros.h"
#include "micro_config.h"
#include "std_types.h"

void UART_init(void);
uint8 UART_recieveByte(void);
void UART_sendByte(uint8 data);


#endif /* UART_H_ */
