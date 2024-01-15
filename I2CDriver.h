//
// Created by 14621 on 2024/1/15.
//

#ifndef PADDEMO_I2CDRIVER_H
#define PADDEMO_I2CDRIVER_H
#include "headfile.h"

class I2CDriver {
public:
    /**
     * @brief:      Construction func.
     * @param[in]:  None.
     * @return:     None.
     * */
    explicit I2CDriver();
    /**
     * @brief:      Destroy func.
     * @param[in]:  None.
     * @return:     None.
     * */
    ~I2CDriver();
    /**
     * @brief:      Open I2C device.
     * @param[in]:  devName -- device name.
     * @param[in]:  address -- device slave address.
     * @return:     0:success, -1:failed.
     * */
    int OpenI2CDevice(const char *devName, uint8_t address);
    /**
     * @brief:      write byte value to device register.
     * @param[in]:  reg -- device register address.
     * @param[in]:  val -- the value will write to register.
     * @return:     0:success, -1:failed.
     * */
    int I2CWriteByte(uint8_t reg, uint8_t val);
    /**
     * @brief:      read byte value for device register.
     * @param[in]:  reg -- device register address.
     * @param[in]:  val -- the value will read for register.
     * @return:     0:success, -1:failed.
     * */
    int I2CReadByte(uint8_t reg, uint8_t *val);

private:
    int m_fd;
};


#endif //PADDEMO_I2CDRIVER_H
