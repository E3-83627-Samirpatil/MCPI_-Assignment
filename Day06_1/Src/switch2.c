/*
 * switch2.c
 *
 *  Created on: Mar 30, 2024
 *      Author: sameer
 */

#include "switch2.h"
#include "LCD1.h"

void Switchinit(uint32_t PIN)
{
	// enable gpio clock (in AHB1ENR)
	RCC->AHB1ENR |= BV(SWITCH_GPIO_E);
	// set gpio PIN as input (in MODER)
	SWITCH_GPIO->MODER &= ~(BV(PIN * 2 + 1) | BV(PIN * 2));
	// set gpio PIN speed to low (in OSPEEDR)
	SWITCH_GPIO->OSPEEDR &= ~(BV(PIN * 2 + 1) | BV(PIN * 2));
	// set gpio PIN no pull up, no pull down (in PUPDR)
	SWITCH_GPIO->PUPDR &= ~(BV(PIN * 2 + 1) | BV(PIN* 2));
	// enable falling edge detection (in FTSR)
	EXTI->FTSR |= BV(SWITCH);
	// enable (unmask) exti interrupt (in IMR)
	EXTI->IMR |= BV(SWITCH);
	// select exti interrupt (in SYSCFG->EXTICRx)
	SYSCFG->EXTICR[0] &= ~(BV(3) | BV(2) | BV(1) | BV(0));
	// enable exti in NVIC (ISER or NVIC_EnableIRQ())
	//NVIC->ISER[0] |= BV(EXTI0_IRQn);
	NVIC_EnableIRQ(EXTI0_IRQn);
}

int Switchgetstate(uint32_t PIN)
{
	// read gpio PIN
	uint32_t state = SWITCH_GPIO->IDR;
	// return 1 if PIN in high, otherwise return 0
	if(state & BV(PIN))
		return 1;
	return 0;
}

volatile int exit0_flag = 0;
// Switch EXTT0 IRQ Handler
void EXTI0_IRQHandler(void)
{
    // Acknowledge interrupt (in PR)
	EXTI->PR |= BV(SWITCH);
	// Handle interrupt
	exit0_flag =1;
}

