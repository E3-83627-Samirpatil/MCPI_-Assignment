/*
 * led_I.h
 *
 *  Created on: Mar 30, 2024
 *      Author: sameer
 */

#ifndef LED_I_H_
#define LED_I_H_

#include "stm32f407xx.h"

#define LED_GPIO	GPIOD
#define LED_GPIO_EN	3

#define LED_GREEN	12
#define LED_ORANGE	13
#define LED_RED		14
#define LED_BLUE	15

void Ledinit(uint32_t pin);
void LedOn(uint32_t pin);
void LedOff(uint32_t pin);
void LedBlink(uint32_t pin, uint32_t delay);

#endif /* LED_I_H_ */
