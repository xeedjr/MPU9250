/*
 * MPU9250HALSTM32HALI2C.h
 *
 *  Created on: 13 жовт. 2020 р.
 *      Author: Bogdan
 */

#ifndef MPU9250_SRC_MPU9250HALSTM32HALI2C_H_
#define MPU9250_SRC_MPU9250HALSTM32HALI2C_H_

#include <stdint.h>
#include "stm32f1xx_hal.h"

#include "MPU9250HAL.h"

class MPU9250HALSTM32HALI2C : public MPU9250HAL {
	I2C_HandleTypeDef *i2c;
	uint8_t address;
public:
	MPU9250HALSTM32HALI2C(I2C_HandleTypeDef *i2c, uint8_t address);
	virtual ~MPU9250HALSTM32HALI2C();

	void begin();
	void set_spi_speed(bool is_hi_speed);
	int writeRegister(uint8_t subAddress, uint8_t data);
	int readRegisters(uint8_t subAddress, uint8_t count, uint8_t* dest);
	int delay(uint32_t ms);
};

#endif /* MPU9250_SRC_MPU9250HALSTM32HALI2C_H_ */
