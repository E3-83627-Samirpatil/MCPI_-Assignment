/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "timer.h"
#include "switch.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
   int duty;
   SystemInit();
   SwitchInit(SWITCH);
   TimerInit();
   while(1)
   {
	   for(duty=1; duty<=100;)
	   {
		   TIM8->CCR1 = duty;// LED on
		   while(exti0_flag == 0);
		   duty = duty+5;
		   exti0_flag = 0;
		   DelayMs(50);
	   }

	   for(; duty>=1;)
	   {
		   TIM8->CCR1 = duty;// LED on
		   while(exti0_flag == 0);
		   duty = duty-5;
		   exti0_flag = 0;
		   DelayMs(50);

   }
   }
	   return 0;

}
