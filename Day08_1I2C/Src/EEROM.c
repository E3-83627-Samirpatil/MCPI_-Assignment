/*
 * EEROM.c
 *
 *  Created on: Apr 2, 2024
 *      Author: sameer
 */

#include "EEROM.h"

void EEPROM_init(void)
{
	uint8_t RET;
	I2CInit();
	I2CStart();
	RET = I2CIsDeviceReady(EEPROM_W);
	I2CStop();
}
void EEPROM_write(uint16_t addr , uint8_t byte[], uint8_t n)
{
	uint8_t HIGH = addr >> 8, LOW = addr & 0XFF;
	I2CStart();
	I2CSendSlaveAddress(EEPROM_W);
	I2CSendData(HIGH);
	I2CSendData(LOW);
	for(int i=0;i<n;i++)
	I2CSendData(byte[i]);
	I2CStop();
}
void EEPROM_read(uint16_t addr , uint8_t byte[], uint8_t n)
{
	uint8_t HIGH = addr >> 8, LOW = addr & 0XFF;
	I2CStart();
	I2CSendSlaveAddress(EEPROM_W);
	I2CSendData(HIGH);
	I2CSendData(LOW);
	I2CRepeatStart();
	I2CSendSlaveAddress(EEPROM_R);
	for(int i=0;i<n;i++)
		byte[i] = I2CRecvDataAck();
	I2CStop();
}
