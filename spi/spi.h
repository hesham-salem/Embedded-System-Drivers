/*
 * spi.h
 *
 *  Created on: May 30, 2021
 *      Author: hesham
 */

#ifndef SPI_H_
#define SPI_H_
#include"common_macros.h"
#include"micro_config.h"
#include"std_types.h"
void SPI_initMaster(void);
void SPI_initSlave(void);
void SPI_sendByte(const uint8 data);
uint8 SPI_recieveByte(void);


#endif /* SPI_H_ */
