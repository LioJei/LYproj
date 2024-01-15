//
// Created by 14621 on 2024/1/15.
//

#ifndef PADDEMO_HEADFILE_H
#define PADDEMO_HEADFILE_H

#include <cstdio>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <vector>
#include <string>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include "registerDefine.h"

struct sh3001RegVal{
    uint8_t gyro_xdata_l;
    uint8_t gyro_xdata_h;
    uint8_t gyro_ydata_l;
    uint8_t gyro_ydata_h;
    uint8_t gyro_zdata_l;
    uint8_t gyro_zdata_h;
};

#endif //PADDEMO_HEADFILE_H
