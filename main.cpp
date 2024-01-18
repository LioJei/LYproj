#include "SH3001Driver.h"

int main()
{
    setenv("DISPLAY",":0",1);
    sh3001RegVal stRegval= {0};
    SH3001Driver i2CDriver;
    int64_t x,y,z,old=0,index=0,current=0;
    system("xrandr -o normal");
    i2CDriver.OpenI2CDevice("/dev/i2c-5", 0x37);
    i2CDriver.GyroSetup();
    i2CDriver.printfGyroData();
    /*while(true){
        for (int i=0; i<100; i++){
            i2CDriver.I2CReadByte(SH3001G_GYRO_XL, &stRegval.gyro_xdata_l);
            i2CDriver.I2CReadByte(SH3001G_GYRO_XH, &stRegval.gyro_xdata_h);
            i2CDriver.I2CReadByte(SH3001G_GYRO_YL, &stRegval.gyro_ydata_l);
            i2CDriver.I2CReadByte(SH3001G_GYRO_YH, &stRegval.gyro_ydata_h);
            i2CDriver.I2CReadByte(SH3001G_GYRO_ZL, &stRegval.gyro_zdata_l);
            i2CDriver.I2CReadByte(SH3001G_GYRO_ZH, &stRegval.gyro_zdata_h);
            x += ((stRegval.gyro_xdata_h << 8)|stRegval.gyro_xdata_l);
            y += ((stRegval.gyro_ydata_h << 8)|stRegval.gyro_ydata_l);
            z += ((stRegval.gyro_zdata_h << 8)|stRegval.gyro_zdata_l);
        }
        printf("\nx: %d\ny: %d\nz: %d\n",x/100, y/100, z/100);
        x /= 100;
        if (current == 0){
            old = x;
            current++;
            continue;
        }
        if (abs(x-old) > 3000){
            if (index == 0){
                system("xrandr -o inverted");
                index = 1;
            } else {
                system("xrandr -o normal");
                index = 0;
            }
        }

        x=y=z=0;
        usleep(500000);
    }*/
}

