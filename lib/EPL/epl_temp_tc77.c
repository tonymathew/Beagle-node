/* Temperature TC77 sensor driver using external SPI implementation
 *
 * Brian Yang <asdyaya@gmail.com> 
 * 2009/09/12
 */

#include <EPL/epl_temp_tc77.h>
#include <HAL/hal_spi.h>
#include <Nordic/reg24le1.h>
#include <EPL/epl_utils.h>

static char temp_spimcon0;
static char org_spimcon0;
static void epl_temp_tc77_SPI_to_temp(void);
static void epl_temp_tc77_SPI_to_org(void);

void epl_temp_tc77_init(void)
{
	org_spimcon0 = SPIMCON0;
	/* SPI configurations */
	hal_spi_master_init(SPI_CLK_DIV4, HAL_SPI_MODE_3, HAL_SPI_MSB_LSB);
	temp_spimcon0 = SPIMCON0;
	
	/* Configure SCSN as output port. */
	TEMP_CSN_DIR_INIT();
		
	/* Configure MMISO as input port. */
	TEMP_DATA_DIR_INIT();
	
	/* Restore the original SPI settings */
	SPIMCON0 = org_spimcon0;
	
	/* Wait to TC77 initialize */
	epl_mdelay(300);
}


int epl_temp_tc77_read(void)
{
	int read_data;
	
	epl_temp_tc77_SPI_to_temp();
	TEMP_CSN = 0;
	read_data = (hal_spi_master_read_write(0) << 8);
	read_data += hal_spi_master_read_write(0);
	TEMP_CSN = 1;
	epl_temp_tc77_SPI_to_org();
	
	/* Check whether the completion of data convertion */
	if(read_data & 0x0004) {
		/* Convert to centigrade degrees */
		return read_data >> 7;
	}
	else {
		return DATA_ERROR;
	}
}

static void epl_temp_tc77_SPI_to_temp(void)
{
	org_spimcon0 = SPIMCON0;
	SPIMCON0 = temp_spimcon0;
}
static void epl_temp_tc77_SPI_to_org(void)
{
	SPIMCON0 = org_spimcon0;
}
