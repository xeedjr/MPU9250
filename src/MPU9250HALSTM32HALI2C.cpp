/*
 * MPU9250HALSTM32HALI2C.cpp
 *
 *  Created on: 13 жовт. 2020 р.
 *      Author: Bogdan
 */

#include "MPU9250HALSTM32HALI2C.h"

MPU9250HALSTM32HALI2C::MPU9250HALSTM32HALI2C(I2C_HandleTypeDef *i2c, uint8_t address) {
	// TODO Auto-generated constructor stub
	this->i2c = i2c;
	this->address = address;
}

MPU9250HALSTM32HALI2C::~MPU9250HALSTM32HALI2C() {
	// TODO Auto-generated destructor stub
}

void MPU9250HALSTM32HALI2C::begin() {

}

void MPU9250HALSTM32HALI2C::set_spi_speed(bool is_hi_speed) {

}

int MPU9250HALSTM32HALI2C::writeRegister(uint8_t subAddress, uint8_t data) {

	HAL_I2C_Mem_Write(i2c, address << 1,
						subAddress, sizeof(subAddress),
						&data, sizeof(data),
						1000);

	delay(10);

	uint8_t _buffer = 0;
	/* read back the register */
	readRegisters(subAddress, sizeof(_buffer), &_buffer);
	/* check the read back register against the written register */
	if(_buffer == data) {
		return 1;
	}
	else{
		return -1;
	}
}

int MPU9250HALSTM32HALI2C::readRegisters(uint8_t subAddress, uint8_t count, uint8_t* dest) {
	HAL_I2C_Mem_Read(i2c, address << 1,
						subAddress, sizeof(subAddress),
						dest, count,
						1000);
	return 1;
}

int MPU9250HALSTM32HALI2C::delay(uint32_t ms) {
	HAL_Delay(ms);
}
