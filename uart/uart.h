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
void UART_sendByte(const uint8 data);
void UART_sendString(uint8 *str);
void UART_recieveString(uint8 *str);


#endif /* UART_H_ */