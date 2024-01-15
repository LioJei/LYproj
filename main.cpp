//std::cout << "Hello, World!" << std::endl;
//std::vector<std::string> strVec = {"xrandr -o normal","xrandr -o inverted","xrandr -o left","xrandr -o right"};
//setenv("DISPLAY",":0",1);
//int res = execl("/bin/sh", "sh", "-c", strVec[1].c_str(), (char *) 0);

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
int file;
char filename[20];
int address = 0x37; // I2C 设备地址
int i2c_line = 5;

// 打开 I2C 总线，并返回文件描述符
int open_i2c_dev(char *devname, int address)
{
    int file;
    sprintf(filename, "/dev/i2c-%d", i2c_line); // I2C 总线的编号
    if ((file = open(filename, O_RDWR)) < 0)
    {
        perror("Failed to open the i2c bus");
        return -1;
    }
    if (ioctl(file, I2C_SLAVE, address) < 0) // 设置 I2C 设备地址
    {
        perror("Failed to acquire bus access and/or talk to slave.\n");
        return -1;
    }
    return file;
}

int ioctl_i2c_write(int file, uint8_t reg, uint8_t val)
{
    uint8_t buffer[2];
    buffer[0] = reg;
    buffer[1] = val;
    if (write(file, buffer, 2) != 2)
    {
        perror("Failed to write to the i2c bus");
        return -1;
    }
    return 0;
}

int ioctl_i2c_read(int file, uint8_t reg, uint8_t *val)
{
    if (write(file, &reg, 1) != 1)
    {
        perror("Failed to write to the i2c bus");
        return -1;
    }
    if (read(file, val, 1) != 1)
    {
        perror("Failed to read from the i2c bus");
        return -1;
    }
    return 0;
}


int main()
{
    if ((file = open_i2c_dev(filename, address)) < 0)
    {
        return -1;
    }

    uint8_t reg = 0x08;
    // 读取 I2C 数据
    uint8_t data;
    if (ioctl_i2c_read(file, reg, &data) < 0)
    {
        return -1;
    }

    printf("data: 0x%x\n", data);
}

