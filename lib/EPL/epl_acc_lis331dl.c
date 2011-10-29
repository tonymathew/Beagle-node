#include <EPL/epl_acc_lis331dl.h>
#include <HAL/hal_spi.h>
#include <Nordic/reg24le1.h>

static char tmep_acc_spimcon0;
static char temp_org_spimcon0;

void epl_acc_lis331dl_init(epl_acc_lis331dl_scale in_scale, epl_acc_lis331dl_data_rate in_data_rate)
{
	temp_org_spimcon0 = SPIMCON0;
	/* SPI configurations */
	hal_spi_master_init(SPI_CLK_DIV4, HAL_SPI_MODE_3, HAL_SPI_MSB_LSB);
	tmep_acc_spimcon0 = SPIMCON0;
	
	/* Configure CSN as output port. */
	ACC_CSN_DIR_INIT();
	
	/* Configure INT_DRDY as input port. (INT1, as data ready)*/
	ACC_INT_DRDY_DIR_INIT();

	// Turn LIS331DL into active mode (power up) and setup measurement scale and output data rate.
	epl_acc_lis331dl_write_reg(ACC_LIS331DL_CTRL_REG1, 0x47 | (in_scale<<5) | (in_data_rate<<7));
	
	// Assigned INT1 as data ready pin.
	epl_acc_lis331dl_write_reg(ACC_LIS331DL_CTRL_REG3, 0x24);
	
	SPIMCON0 = temp_org_spimcon0;
}

bool epl_acc_lis331dl_data_is_ready(void)
{
	// ACC_INIT_DRDY turns high when measurement is done.
	return ACC_INT_DRDY;
}

char epl_acc_lis331dl_read_X(void)
{
	return (signed char)epl_acc_lis331dl_read_reg(ACC_LIS331DL_OUT_X);
}

char epl_acc_lis331dl_read_Y(void)
{
	return (signed char)epl_acc_lis331dl_read_reg(ACC_LIS331DL_OUT_Y);
}

char epl_acc_lis331dl_read_Z(void)
{
	return (signed char)epl_acc_lis331dl_read_reg(ACC_LIS331DL_OUT_Z);
}


void epl_acc_lis331dl_write_reg(epl_acc_lis331dl_reg in_reg, char in_data)
{
	epl_acc_lis331dl_SPI_init_switch_to_acc();
	ACC_CSN = 0;
	hal_spi_master_read_write(in_reg);
	hal_spi_master_read_write(in_data);
	ACC_CSN = 1;
	epl_acc_lis331dl_SPI_init_switch_back_to_org();
}

unsigned char epl_acc_lis331dl_read_reg(epl_acc_lis331dl_reg in_reg)
{
	unsigned char result_data;
	epl_acc_lis331dl_SPI_init_switch_to_acc();
	ACC_CSN = 0;
	hal_spi_master_read_write(0x80 | in_reg);
	result_data = hal_spi_master_read_write(0);
	ACC_CSN = 1;
	epl_acc_lis331dl_SPI_init_switch_back_to_org();
	return result_data;
}

void epl_acc_lis331dl_SPI_init_switch_to_acc(void)
{
	temp_org_spimcon0 = SPIMCON0;
	SPIMCON0 = tmep_acc_spimcon0;
}

void epl_acc_lis331dl_SPI_init_switch_back_to_org(void)
{
	SPIMCON0 = temp_org_spimcon0;
}
