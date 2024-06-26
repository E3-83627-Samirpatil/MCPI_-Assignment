/*
 * LCD1.h
 *
 *  Created on: Mar 29, 2024
 *      Author: sameer
 */

#ifndef LCD1_H_
#define LCD1_H_

#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#define LCD_DATA_GPIO	GPIOB
#define LCD_DATA_GPIO_EN	3
#define LCD_D7			3
#define LCD_D6			2
#define LCD_D5			1
#define LCD_D4			0
//#define LCD_D3			3
//#define LCD_D2			2
//#define LCD_D1			1
//#define LCD_D0			0

#define LCD_BF			LCD_D7
#define LCD_D7_CLR		(LCD_D7+16)
#define LCD_D6_CLR		(LCD_D6+16)
#define LCD_D5_CLR		(LCD_D5+16)
#define LCD_D4_CLR		(LCD_D4+16)
//#define LCD_D3_CLR		(LCD_D3+16)
//#define LCD_D2_CLR		(LCD_D2+16)
//#define LCD_D1_CLR		(LCD_D1+16)
//#define LCD_D0_CLR		(LCD_D0+16)

#define LCD_CTRL_GPIO	GPIOD
#define LCD_CTRL_GPIO_EN	3
#define LCD_RS			5
#define LCD_RW			6
#define LCD_EN			7
#define LCD_RS_CLR		(LCD_RS+16)
#define LCD_RW_CLR		(LCD_RW+16)
#define LCD_EN_CLR		(LCD_EN+16)

#define LCD_CLEAR		0x01
#define LCD_FN_SET		0x28
#define LCD_DISP_ON		0x0F
#define LCD_ENTRY_MODE	0x06
#define LCD_DISP_SHIFT  0x18
#define LCD_LINE1		0x80
#define LCD_LINE2		0xC0

#define LCD_CMD			0
#define LCD_DATA		1

void LcdBusyWait(void);
void LcdWriteNibble(uint8_t rs, uint8_t val);
void LcdWrite(uint8_t rs, uint8_t val);
void LcdShift(void);
void LcdInit(void);
void LcdPuts(uint8_t line, char str[]);

#endif /* LCD1_H_ */
