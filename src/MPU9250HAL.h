/*
 * MPU9250HAL.h
 *
 *  Created on: 13 жовт. 2020 р.
 *      Author: Bogdan
 */

#ifndef MPU9250_SRC_MPU9250HAL_H_
#define MPU9250_SRC_MPU9250HAL_H_

class MPU9250HAL {
public:
	MPU9250HAL() {};
	virtual ~MPU9250HAL() {};

	virtual void begin() = 0;
	virtual void set_spi_speed(bool is_hi_speed) = 0;
	virtual int writeRegister(uint8_t subAddress, uint8_t data) = 0;
	virtual int readRegisters(uint8_t subAddress, uint8_t count, uint8_t* dest) = 0;
	virtual int delay(uint32_t ms) = 0;
};



#endif /* MPU9250_SRC_MPU9250HAL_H_ */
