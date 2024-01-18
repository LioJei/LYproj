//
// Created by 14621 on 2024/1/16.
//

#include "SH3001Driver.h"

SH3001Driver::SH3001Driver() {

}

SH3001Driver::~SH3001Driver() {

}

int SH3001Driver::GyroSetup() {
    this->SoftReset();
    this->DriveStart();
    this->ADCReset();
    this->CVAReset();
    this->GyroConfig(SH3001G_ODR_500HZ,
                     SH3001G_GYRO_RANGE_2000,
                     SH3001G_GYRO_RANGE_2000,
                     SH3001G_GYRO_RANGE_2000,
                     SH3001G_GYRO_ODRX00,
                     SH3001G_GYRO_FILTER_EN);
    return 0;
}

void SH3001Driver::SoftReset() {
    unsigned char regData = 0;
    regData = 0x84;
    this->I2CWriteByte(0xD4, regData);
    usleep(1000);

    regData = 0x04;
    this->I2CWriteByte(0xD4, regData);
    usleep(1000);

    regData = 0x08;
    this->I2CWriteByte(0x2F,regData);
    usleep(1000);

    regData = 0x73;
    this->I2CWriteByte(0x00,regData);
    usleep(50000);
}

void SH3001Driver::DriveStart() {
    unsigned char regAddr[3] = {0x2E, 0xC0, 0xC1};
    unsigned char regData[3] = {0x2E, 0xC0, 0xC1};
    unsigned char regDataBack[3] = {0};
    unsigned char i = 0;
    for(i=0; i<3; i++)
    {
        this->I2CReadByte(regAddr[i], &regData[i]);
    }

    regDataBack[0] = 0x9F;
    regDataBack[1] = 0x38;
    regDataBack[2] = 0xFF;
    for(i=0; i<3; i++)
    {
       this->I2CWriteByte(regAddr[i], regDataBack[i]);
    }
    usleep(50000);

    for(i=0; i<3; i++)
    {
        this->I2CWriteByte(regAddr[i], regData[i]);
    }
    usleep(50000);
}

void SH3001Driver::ADCReset() {
    unsigned char regAddr[2] = {0xD3, 0xD5};
    unsigned char regData[2] = {0xD3, 0xD5};
    unsigned char i = 0;


    for(i=0; i<2; i++)
    {
        this->I2CReadByte(regAddr[i], &regData[i]);
    }

    regData[0] = (regData[0] & 0xFC) | 0x01;
    regData[1] = (regData[1] & 0xF9) | 0x02;

    this->I2CWriteByte(0xD5, regData[1]);
    this->I2CWriteByte(0xD3, regData[0]);
    usleep(1000);

    regData[0] = (regData[0] & 0xFC) | 0x02;
    this->I2CWriteByte(0xD3, regData[0]);
    usleep(1000);

    regData[1] = (regData[1] & 0xF9);
    this->I2CWriteByte(0xD5, regData[1]);
    usleep(50000);
}

void SH3001Driver::CVAReset() {
    unsigned char regData = 0;

    this->I2CReadByte(0xD4, &regData);
    regData |= 0x08;
    this->I2CWriteByte(0xD4, regData);
    usleep(10000);

    regData &= 0xF7;
    this->I2CWriteByte(0xD4, regData);
}

void SH3001Driver::GyroConfig(unsigned char gyroODR, unsigned char gyroRangeX, unsigned char gyroRangeY,
                              unsigned char gyroRangeZ, unsigned char gyroCutOffFreq, unsigned char gyroFilterEnable) {
    unsigned char regData = 0;

    // enable gyro digital filter
    regData = 0;
    this->I2CReadByte(SH3001G_GYRO_CONF0, &regData);
    regData |= 0x01;
    this->I2CWriteByte(SH3001G_GYRO_CONF0, regData);

    // set gyro ODR
    this->I2CWriteByte(SH3001G_GYRO_CONF1, gyroODR);

    // set gyro X\Y\Z range
    this->I2CWriteByte(SH3001G_GYRO_CONF3, gyroRangeX);
    this->I2CWriteByte(SH3001G_GYRO_CONF4, gyroRangeY);
    this->I2CWriteByte(SH3001G_GYRO_CONF5, gyroRangeZ);

    // bypass gyro low pass filter or not
    regData = 0;
    this->I2CReadByte(SH3001G_GYRO_CONF2, &regData);
    regData &= 0xE3;
    regData |= (gyroCutOffFreq | gyroFilterEnable);
    this->I2CWriteByte(SH3001G_GYRO_CONF2, regData);
}

void SH3001Driver::printfGyroData() {
    sh3001RegVal stRegval= {0};
    int x,y,z;
    while(true) {
        this->I2CReadByte(SH3001G_GYRO_XL, &stRegval.gyro_xdata_l);
        this->I2CReadByte(SH3001G_GYRO_XH, &stRegval.gyro_xdata_h);
        this->I2CReadByte(SH3001G_GYRO_YL, &stRegval.gyro_ydata_l);
        this->I2CReadByte(SH3001G_GYRO_YH, &stRegval.gyro_ydata_h);
        this->I2CReadByte(SH3001G_GYRO_ZL, &stRegval.gyro_zdata_l);
        this->I2CReadByte(SH3001G_GYRO_ZH, &stRegval.gyro_zdata_h);
        printf("%d,%d,%d,%d,%d,%d\n", stRegval.gyro_xdata_l, stRegval.gyro_xdata_h,
                                        stRegval.gyro_ydata_l, stRegval.gyro_ydata_h,
                                        stRegval.gyro_zdata_l,stRegval.gyro_zdata_h);
        x = ((stRegval.gyro_xdata_h << 8) | stRegval.gyro_xdata_l);
        y = ((stRegval.gyro_ydata_h << 8) | stRegval.gyro_ydata_l);
        z = ((stRegval.gyro_zdata_h << 8) | stRegval.gyro_zdata_l);
        printf("\nx: %d\ny: %d\nz: %d\n", x, y, z);
        sleep(3);
    }
}
