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
#include "i2c_lcd.h"
#include "Acce.h"
#include "spi.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	int ret;
	char str1[32];
	char str2[32];
	LIS_Init();
	SystemInit();
	LcdInit();
	LIS_Data val;

//	UartPuts("LIS3DSH Accel Demo!\r\n");
	//LIS_Init();
	DelayMs(1000);
	while(1)
	{
		ret = LIS_DRdy();

		if(ret) {
				val = LIS_GetData();
				sprintf(str1, "X=%d, Y=%d, Z=%d\r\n", val.x, val.y, val.z);
				sprintf(str2, "X=%d, Y=%d, Z=%d\r\n", val.x, val.y, val.z);
				LcdPuts(LCD_LINE1,str1);
				LcdPuts(LCD_LINE2, str2);
				DelayMs(1000);
		}
	}
	return 0;
}
