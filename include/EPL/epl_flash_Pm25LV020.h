/* @file 
 * LE1 Pm25LV020 Flash (2MB) driver using external SPI
 * if you wnat to control flash use MCU please include HAL/hal_flash.h and use it
 *
 * @author Brian Yang <asdyaya@gmail.com>
 * 2009/02/12
 */

#ifndef _EPL_FLASH_PM25LV020_H_
#define _EPL_FLASH_PM25LV020_H_

/* instruction set defined in Pm25LV020 */
#define	FLASH_PM25LV020_WREN		 	0x06	/* set write enable 									*/
#define FLASH_PM25LV020_WRDI		 	0x04	/* reset write enable 									*/
#define FLASH_PM25LV020_RDSR		 	0x05	/* read flash status register 							*/
#define FLASH_PM25LV020_WRSR		 	0x01 	/* write flash status register							*/
#define	FLASH_PM25LV020_READ		 	0x03	/* read data from flash									*/
#define FLASH_PM25LV020_FAST_READ  		0x0B   	/* read data from flash at fast read mode				*/
#define FLASH_PM25LV020_RDID		 	0xAB   	/* read manufacturer and product ID						*/
#define FLASH_PM25LV020_JEDEC_ID_READ  	0x0B   	/* read manufacturer and product ID by JEDEC ID command	*/
#define	FLASH_PM25LV020_PAGE_PROG	 	0x02	/* write data to flash									*/
#define FLASH_PM25LV020_RDCR		  	0xA1   	/* read configure register								*/
#define FLASH_PM25LV020_WRCR  			0xF1   	/* write configure register								*/
#define FLASH_PM25LV020_SECTOR_ERASE  	0xD7   	/* sector erase											*/
#define FLASH_PM25LV020_BLOCK_ERASE  	0xD8   	/* block erase											*/
#define FLASH_PM25LV020_CHIP_ERASE 		0xC7	/* chip erase											*/

/* additional instruction for flash memory in nRF24LE1 */
#define FLASH_ERASE_PAGE 		0x52	/* erase address page									*/
#define	FLASH_ERASE_ALL	 		0x62	/* erase all page										*/
#define FLASH_RDFPCR	 		0x89	/* read flash protect configuration register			*/
#define FLASH_RDISMB     		0x85    /* set flash main block read-back disable      			*/
#define FLASH_ENDEBUG	 		0x86	/* enable debugger through JTAG-pins					*/
	
/* SPI master cs is P13 */
#define	FLASH_CS		P13

#include <stdint.h>

/** init the flash, connect flash to the SPI interface.
 */
void flash_Pm25LV020_init();

/** begin to write flash from address.
 * @param addr target address
 */
void flash_Pm25LV020_begin_write(uint32_t addr);

/** write a byte to flash
 * @param byte the writting byte of data
 */
void flash_Pm25LV020_write(uint8_t b);

/** end of flash write sequence.
 */
void flash_Pm25LV020_end_write();

/** read flash from specific address.
 * @param addr target address
 */
void flash_Pm25LV020_begin_read(uint32_t addr);

/** read a single byte from flash.
 * @return the read byte
 */
uint8_t flash_Pm25LV020_read();

/** end to read from flash.
 */
void flash_Pm25LV020_end_read();

/** read the status register.
 */
uint8_t flash_Pm25LV020_read_status();

/** write the status register.
 * @param b the status data
 */
void flash_Pm25LV020_write_status(uint8_t b);

/** read a single byte from specified address.
 * @param addr target address
 * @return the read byte of address addr
 */
uint8_t flash_Pm25LV020_read_single_byte(uint32_t addr);

/** write a single byte to specified address.
 * @param addr target address
 * @param b the writting byte of data
 */
void flash_Pm25LV020_write_single_byte(uint32_t addr, uint8_t b);

/** erase specific sector.
 * @param addr sector address
 */
void flash_Pm25LV020_erase_sector(uint32_t addr);

/** erase specific block.
 * @param addr block address
 */
void flash_Pm25LV020_erase_block(uint32_t addr);

/** erase all blocks on flash.
 */
void flash_Pm25LV020_erase_chip();

#endif 
