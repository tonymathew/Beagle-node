#ifndef EPL_ACC_LIS331DL_H_
#define EPL_ACC_LIS331DL_H_

#include <Nordic/reg24le1.h>
#include <stdbool.h>

#define	ACC_INT_DRDY				P02
#define	ACC_INT_DRDY_DIR_INIT();	P0DIR|=0x04;
#define	ACC_CSN						P12
#define	ACC_CSN_DIR_INIT();			P1DIR&=~0x04;

/** An enum describing register map in LIS331DL.
 */
typedef enum {
	ACC_LIS331DL_WHO_AM_I				= 0x0F,	/* Device identification register         */
	ACC_LIS331DL_CTRL_REG1				= 0x20,	/* LIS331DL control register 1            */
	ACC_LIS331DL_CTRL_REG2				= 0x21,	/* LIS331DL control register 2            */
	ACC_LIS331DL_CTRL_REG3				= 0x22,	/* LIS331DL control register 3            */
	ACC_LIS331DL_HP_FILTER_RESET		= 0x23,	/* Dummy register. High pass-filter       */
	ACC_LIS331DL_STATUS_REG				= 0x27,	/* Status register                        */
	ACC_LIS331DL_OUT_X					= 0x29,	/* X axis data (2's complement number)    */
	ACC_LIS331DL_OUT_Y					= 0x2B,	/* Y axis data (2's complement number)    */
	ACC_LIS331DL_OUT_Z					= 0x2D,	/* Z axis data (2's complement number)    */
	ACC_LIS331DL_FF_WU_CFG_1			= 0x30,	/*                                        */
	ACC_LIS331DL_FF_WU_CFG_1_ACK1		= 0x31,	/*                                        */
	ACC_LIS331DL_FF_WU_THS_1			= 0x32,	/*                                        */
	ACC_LIS331DL_FF_WU_DURATION_1		= 0x33,	/*                                        */
	ACC_LIS331DL_FF_WU_CFG_2			= 0x34,	/*                                        */
	ACC_LIS331DL_FF_WU_CFG_2_ACK2		= 0x35,	/*                                        */
	ACC_LIS331DL_FF_WU_THS_2			= 0x36, /*                                        */
	ACC_LIS331DL_FF_WU_DURATION_2		= 0x37,	/*                                        */	
	ACC_LIS331DL_CLICK_CFG				= 0x38,	/*                                        */
	ACC_LIS331DL_CLICK_SRC_ACK			= 0x39,	/*                                        */
	ACC_LIS331DL_CLICK_THSY_X			= 0x3B,	/*                                        */
	ACC_LIS331DL_CLICK_THSZ				= 0x3C,	/*                                        */
	ACC_LIS331DL_CLICK_TIME_LIMIT		= 0x3D, /*                                        */
	ACC_LIS331DL_CLICK_LATENCY			= 0x3E, /*                                        */
	ACC_LIS331DL_CLICK_WINDOW			= 0x3F /*                                        */
} epl_acc_lis331dl_reg;


/** An enum describing full measurement scale.
 */
typedef enum {
	ACC_LIS331DL_2G_SCALE = 0x00,		/* +-2G mode */
	ACC_LIS331DL_8G_SCALE = 0x01		/* +-8G mode */
} epl_acc_lis331dl_scale;

/** An enum describing full measurement scale.
 */
typedef enum {
	ACC_LIS331DL_DATA_RATE_100HZ = 0x00,	/* 100Hz output data rate */
	ACC_LIS331DL_DATA_RATE_400HZ = 0x01		/* 400Hz output data rate */
} epl_acc_lis331dl_data_rate;

void epl_acc_lis331dl_init(epl_acc_lis331dl_scale in_scale, epl_acc_lis331dl_data_rate in_data_rate);
bool epl_acc_lis331dl_data_is_ready(void);
char epl_acc_lis331dl_read_X(void);
char epl_acc_lis331dl_read_Y(void);
char epl_acc_lis331dl_read_Z(void);
void epl_acc_lis331dl_write_reg(epl_acc_lis331dl_reg in_reg, char in_data);
unsigned char epl_acc_lis331dl_read_reg(epl_acc_lis331dl_reg in_reg);
void epl_acc_lis331dl_SPI_init_switch_to_acc(void);
void epl_acc_lis331dl_SPI_init_switch_back_to_org(void);

#endif /*EPL_ACC_LIS331DL_H_*/
