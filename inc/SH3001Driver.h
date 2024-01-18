//
// Created by 14621 on 2024/1/16.
//

#ifndef PADDEMO_SH3001DRIVER_H
#define PADDEMO_SH3001DRIVER_H
#include "I2CDriver.h"

//gyro寄存存数结构体
struct sh3001RegVal{
    uint8_t gyro_xdata_l;
    uint8_t gyro_xdata_h;
    uint8_t gyro_ydata_l;
    uint8_t gyro_ydata_h;
    uint8_t gyro_zdata_l;
    uint8_t gyro_zdata_h;
};

class SH3001Driver : public I2CDriver {
public:
    /**
     * @brief:      Construction func.
     * @param[in]:  None.
     * @return:     None.
     * */
    explicit SH3001Driver();
    /**
     * @brief:      Destroy func.
     * @param[in]:  None.
     * @return:     None.
     * */
    ~SH3001Driver();
    /**
     * @brief:      init sh3001.
     * @param[in]:  None.
     * @return:     0:success, -1:failed..
     * */
    int GyroSetup();
    /**
     * @brief:      Software Reset.
     * @param[in]:  None.
     * @return:     None.
     * */
    void SoftReset();
    /**
     * @brief:      Start Module.
     * @param[in]:  None.
     * @return:     None.
     * */
    void DriveStart();
    /**
     * @brief:      Reset ADC Module.
     * @param[in]:  None.
     * @return:     None.
     * */
    void ADCReset();
    /**
     * @brief:      Reset CVA Module.
     * @param[in]:  None.
     * @return:     None.
     * */
    void CVAReset();
    /**
     * @brief:      Configure Module.
     * @param[in]:  gyroODR         --ODR_Freq.
     * @param[in]:  gyroRangeX      --X_Range.
     * @param[in]:  gyryRangeY      --Y_Range.
     * @param[in]:  gyroRangeZ      --Z_Range.
     * @param[in]:  gyroCutOffFreq  --ODR_Choice.
     * @param[in]:  gryoFilterEnable--Filter_Enable.
     * @return:     None.
     * */
    void GyroConfig(unsigned char gyroODR,
                    unsigned char gyroRangeX,
                    unsigned char gyroRangeY,
                    unsigned char gyroRangeZ,
                    unsigned char gyroCutOffFreq,
                    unsigned char gyroFilterEnable);
    /**
     * @brief:      Printf Gyro Data.
     * @param[in]:  None.
     * @return:     None.
     * */
    void printfGyroData(void);
private:
};


#endif //PADDEMO_SH3001DRIVER_H
