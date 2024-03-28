/*
 * D3_2.h
 *
 *  Created on: Mar 27, 2024
 *      Author: sameer
 */

#ifndef D3_2_H_
#define D3_2_H_
#include "stm32f407xx.h"

#define LED_GPIO	GPIOD
#define LED_GPIO_EN	3

#define LED_GREEN	12
#define LED_ORANGE	13
#define LED_RED		14
#define LED_BLUE	15

void LedInit(uint32_t pin);
void LedOn(uint32_t pin);
void LedOff(uint32_t pin);

#endif /* D3_2_H_ */
