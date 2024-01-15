#include "I2CDriver.h"

int main()
{
    setenv("DISPLAY",":0",1);
    sh3001RegVal stRegval= {0};
    I2CDriver i2CDriver;
//    int res = execl("/bin/sh", "sh", "-c", "xrandr -o normal", (char *) 0);
//    if (res){
//        perror("xrandr exec error.");
//    }
    system("xrandr -o normal");
    i2CDriver.OpenI2CDevice("/dev/i2c-5", 0x37);
    while(true){
        i2CDriver.I2CReadByte(SH3001_GYRO_XDATA_L, &stRegval.gyro_xdata_l);
        i2CDriver.I2CReadByte(SH3001_GYRO_XDATA_H, &stRegval.gyro_xdata_h);
        i2CDriver.I2CReadByte(SH3001_GYRO_YDATA_L, &stRegval.gyro_ydata_l);
        i2CDriver.I2CReadByte(SH3001_GYRO_YDATA_H, &stRegval.gyro_ydata_h);
        i2CDriver.I2CReadByte(SH3001_GYRO_ZDATA_L, &stRegval.gyro_zdata_l);
        i2CDriver.I2CReadByte(SH3001_GYRO_ZDATA_H, &stRegval.gyro_zdata_h);
//        printf("data:0x%x\n", stRegval.gyro_xdata_l);
//        printf("data:0x%x\n", stRegval.gyro_xdata_h);
//        printf("data:0x%x\n", stRegval.gyro_ydata_l);
//        printf("data:0x%x\n", stRegval.gyro_ydata_h);
//        printf("data:0x%x\n", stRegval.gyro_zdata_l);
//        printf("data:0x%x\n", stRegval.gyro_zdata_h);

        printf("\nx: 0x%x\ny: 0x%x\nz: 0x%x\n",((stRegval.gyro_xdata_h << 8)|stRegval.gyro_xdata_l),
               ((stRegval.gyro_ydata_h << 8)|stRegval.gyro_ydata_l),
               ((stRegval.gyro_zdata_h << 8)|stRegval.gyro_zdata_l));
        sleep(1);
    }
}

