/*
 * switch2.h
 *
 *  Created on: Mar 30, 2024
 *      Author: sameer
 */

#ifndef SWITCH2_H_
#define SWITCH2_H_

#include "stm32f4xx.h"
#include "stm32f407xx.h"

#define SWITCH_GPIO            GPIOA
#define SWITCH_GPIO_E           0

#define SWITCH                  0

void Switchinit(uint32_t PIN);
int Switchgetstate(uint32_t PIN);
#endif /* SWITCH2_H_ */
