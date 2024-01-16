//
// Created by 14621 on 2024/1/15.
//

#ifndef PADDEMO_REGISTERDEFINE_H
#define PADDEMO_REGISTERDEFINE_H
/*
 * ABS(min~max)
 */
#define ABSMIN_GYRO	-1023
#define ABSMAX_GYRO	1023

/*
 * Device ID
 */
#define GYRO_DEVICE_ID 0x61
#define IC_CHECK 0

/*
 * I2C Address
 */
#define GYRO_I2C_ADDRESS 0x36

/*
 * I2C Name
 */
#define GYRO_I2C_NAME "sh3001g"

/*
 * Register Map
 */


/******************************************************************
*	GYRO Config Macro Definitions
******************************************************************/
#define SH3001G_GYRO_RANGE_125	(0x02)
#define SH3001G_GYRO_RANGE_250	(0x03)
#define SH3001G_GYRO_RANGE_500	(0x04)
#define SH3001G_GYRO_RANGE_1000	(0x05)
#define SH3001G_GYRO_RANGE_2000	(0x06)

#define SH3001G_GYRO_ODRX00	    (0x00)
#define SH3001G_GYRO_ODRX01	    (0x04)
#define SH3001G_GYRO_ODRX02	    (0x08)
#define SH3001G_GYRO_ODRX03	    (0x0C)

#define SH3001G_GYRO_FILTER_EN	(0x00)
#define SH3001G_GYRO_FILTER_DIS	(0x10)


#define SH3001G_ODR_1000HZ	    (0x00)
#define SH3001G_ODR_500HZ	    (0x01)
#define SH3001G_ODR_250HZ	    (0x02)
#define SH3001G_ODR_125HZ		(0x03)
#define SH3001G_ODR_63HZ		(0x04)
#define SH3001G_ODR_31HZ		(0x05)
#define SH3001G_ODR_16HZ		(0x06)
#define SH3001G_ODR_2000HZ		(0x08)
#define SH3001G_ODR_4000HZ		(0x09)
#define SH3001G_ODR_8000HZ		(0x0A)
#define SH3001G_ODR_16000HZ		(0x0B)
#define SH3001G_ODR_32000HZ		(0x0C)

#define SH3001G_GYRO_XL			(0x06)
#define SH3001G_GYRO_XH			(0x07)
#define SH3001G_GYRO_YL			(0x08)
#define SH3001G_GYRO_YH			(0x09)
#define SH3001G_GYRO_ZL			(0x0A)
#define SH3001G_GYRO_ZH			(0x0B)

#define SH3001G_GYRO_CONF0		(0x28)		// gyroscope config 0x28-0x2B
#define SH3001G_GYRO_CONF1		(0x29)
#define SH3001G_GYRO_CONF2		(0x2B)
#define SH3001G_GYRO_CONF3		(0x8F)
#define SH3001G_GYRO_CONF4		(0x9F)
#define SH3001G_GYRO_CONF5		(0xAF)

#define SH3001G_CHIP_VERSION        (0xDD)
#define SH3001G_CHIP_VERSION_MCC    (0x08)
#define SH3001G_CHIP_VERSION_MC	    (0x10)
#define SH3001G_CHIP_VERSION_MCF	(0x20)
#define SENODIAG_MODULERESET_COMPAT (1)
#define SH3001G_WHOAMI              (0x0F)

#define ODR_MASK	                (0xf9)
/* FILT CONF and ODR Bits */
#define TEMPERATURE_FILT_EN     (1 << 4)
#define HPF_BYPASS		        (1 << 3)
#define ODR(x)			        (((x) & 0x03) << 1)
#define FILT_EN			        (1 << 0)

/* AUX CTL Bits */
#define AUX_EN			        (1 << 3)
#define PLL_EN			        (1 << 4)
/*
 * Miscellaneous set.
 */
#define MAX_FAILURE_COUNT 	    3
#define GYRO_DEFAULT_DELAY   	30
#define GYRO_AUTO_TEST	   	    0
#define OLD_KERNEL_VERSION	    0
#define AUX_I2C_EN 		        0

#define GYROIO                  0xA2

/* IOCTLs for hal*/
#define ECS_IOCTL_GYRO_SET_GRFLAG       _IOW(GYROIO, 0x32, short)
#define ECS_IOCTL_GYRO_GET_GRFLAG       _IOR(GYROIO, 0x33, short)
#define ECS_IOCTL_GYRO_SET_LAFLAG       _IOW(GYROIO, 0x34, short)
#define ECS_IOCTL_GYRO_GET_LAFLAG       _IOR(GYROIO, 0x35, short)
#define ECS_IOCTL_GYRO_SET_RVFLAG       _IOW(GYROIO, 0x36, short)
#define ECS_IOCTL_GYRO_GET_RVFLAG       _IOR(GYROIO, 0x37, short)
#define ECS_IOCTL_GYRO_SET_ORFLAG       _IOW(GYROIO, 0x38, short)
#define ECS_IOCTL_GYRO_GET_ORFLAG       _IOR(GYROIO, 0x39, short)
#define ECS_IOCTL_GYRO_SET_GYFLAG       _IOW(GYROIO, 0x30, short)
#define ECS_IOCTL_GYRO_GET_GYFLAG       _IOR(GYROIO, 0x31, short)
#define ECS_IOCTL_GYRO_SET_DELAY        _IOW(GYROIO, 0x40, short)
#define ECS_IOCTL_GYRO_GET_DELAY        _IOR(GYROIO, 0x41, short)
#endif //PADDEMO_REGISTERDEFINE_H
