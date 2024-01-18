//
// Created by 14621 on 2024/1/15.
//

#include "I2CDriver.h"

I2CDriver::I2CDriver() :
m_fd(-1)
{

}

I2CDriver::~I2CDriver() {

}

int I2CDriver::OpenI2CDevice(const char *devName, unsigned char address) {
    if ((m_fd = open(devName, O_RDWR)) < 0) {
        perror("Failed to open the i2c bus\n");
        return -1;
    }
    if (ioctl(m_fd, I2C_SLAVE, address) < 0) // 设置 I2C 设备地址
    {
        perror("Failed to acquire bus access and/or talk to slave.\n");
        return -1;
    }
    return 0;
}

int I2CDriver::I2CWriteByte(unsigned char reg, unsigned char val) {
    unsigned char buffer[2];
    buffer[0] = reg;
    buffer[1] = val;
    if (write(m_fd, buffer, 2) != 2)
    {
        perror("Failed to write to the i2c bus.");
        return -1;
    }
    return 0;
}

int I2CDriver::I2CReadByte(unsigned char reg, unsigned char *val) {
    if (write(m_fd, &reg, 1) != 1)
    {
        perror("Failed to write to the i2c bus");
        return -1;
    }
    if (read(m_fd, val, 1) != 1)
    {
        perror("Failed to read from the i2c bus");
        return -1;
    }
    return 0;
}