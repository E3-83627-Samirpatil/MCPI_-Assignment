/*
 * Led3.c
 *
 *  Created on: Mar 30, 2024
 *      Author: sameer
 */


#include"stm32f4xx.h"
#include "led_I.h"

void Led_init(uint32_t PIN)
{
	// enable gpio clock (in AHB1ENR)
	RCC->AHB1ENR |= BV(LED_GPIO_EN);
	// set gpio PIN as output (in MODER)
	LED_GPIO->MODER &= ~BV(PIN * 2 + 1);
	LED_GPIO->MODER |= BV(PIN * 2);
	// set gpio PIN speed to low (in OSPEEDR)
	LED_GPIO->OSPEEDR &= ~(BV(PIN * 2 + 1) | BV(PIN * 2));
	// set gpio PIN no pull up, no pull down (in PUPDR)
	LED_GPIO->PUPDR &= ~(BV(PIN * 2 + 1) | BV(PIN * 2));
	// set gpio PIN type as push-pull (in OTYPER)
	LED_GPIO->OTYPER &= ~BV(PIN);

}

void LedOn(uint32_t PIN)
{
	// set led PIN (in ODR)
	LED_GPIO->ODR |= BV(PIN);
}

void LedOff(uint32_t PIN)
{
	// clear led PIN (in ODR)
	LED_GPIO->ODR &= ~BV(PIN);
}

void LedBlink(uint32_t PIN, uint32_t delay)
{
	LedOn(PIN);
	DelayMs(delay);
	LedOff(PIN);
}


