/*
 * i2c.h
 *
 *  Created on: Jun 6, 2021
 *      Author: hesham
 */

#ifndef I2C_H_
#define I2C_H_
#include "common_macros.h"
#include "micro_config.h"
#include "std_types.h"


void TWI_init(void);
void TWI_start(void);
void TWI_STOP(void);
void TWI_write(uint8 data);
uint8 TWI_read_with_ACK(void);
uint8 TWI_read_with_NACK(void);
uint8 TWI_get_status();



#endif /* I2C_H_ */
