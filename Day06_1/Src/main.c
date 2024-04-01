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

#include "led_I.h"
#include "switch2.h"
#include "LCD1.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	SystemInit();
	LcdInit();
//	LcdPuts(LCD_LINE1, "DESD@SUNBEAM");
//LcdPuts(LCD_LINE2, "#E3#");
	switchinit(SWITCH);
	int count = 0;
	char str[16];
	while(1)
		{
			//int count = 0;
			//char str[16];
			while(exit0_flag!=0)
				;
					LcdPuts(LCD_LINE1, "count");
					//LcdInit();
					LedBlink(LED_RED,500)
					count++;
					//LcdWrite(LCD_CMD, line);
					//LcdWrite(LCD_CMD, LCD_DISP_SHIFT);
					sprintf(str,"Count=%d",count);
					count++;
					//LcdPuts(LCD_LINE1, "SUNBEAM PUNE");
					//LcdPuts(LCD_LINE1, "count");
					//DelayMs(200);
					exit0_flag=0;
				}
			LcdPuts(LCD_LINE1, str);
		}
	return 0;
}
