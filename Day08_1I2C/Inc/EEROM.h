/*
 * EEROM.h
 *
 *  Created on: Apr 2, 2024
 *      Author: sameer
 */

#ifndef EEROM_H_
#define EEROM_H_

#include"I2C.h"
#include "uart.h"

//#include "stm32f4xx.h"
//#include "stm32f407xx.h"

#define EEPROM_W     0xA0
#define EEPROM_R     0xA1


void EEPROM_init(void);
void EEPROM_write(uint16_t addr , uint8_t byte[], uint8_t n);
void EEPROM_read(uint16_t addr , uint8_t byte[], uint8_t n);

#endif /* EEROM_H_ */
