/* @file 
 * LE1 SST25VF512A Flash (512Kbit) driver using external SPI
 * if you wnat to control flash use MCU please include HAL/hal_flash.h and use it
 *
 * @author Brian Yang <asdyaya@gmail.com>
 * 2009/02/12
 */

#ifndef _EPL_FLASH_SST25VF512A_H_
#define _EPL_FLASH_SST25VF512A_H_

/* instruction set defined in SST25VF512A */
#define	FLASH_SST25VF512A_READ		 		0x03	/* read data from flash											*/
#define FLASH_SST25VF512A_SECTOR_ERASE  	0x20   	/* sector erase													*/
#define FLASH_SST25VF512A_BLOCK_ERASE	  	0x52   	/* block erase													*/
#define FLASH_SST25VF512A_CHIP_ERASE 		0x60	/* chip erase													*/
#define	FLASH_SST25VF512A_BYTE_PROG		 	0x02	/* write one byte to flash										*/
#define	FLASH_SST25VF512A_AII_WORD_PROG	 	0xAF	/* auto address increment programming							*/
#define FLASH_SST25VF512A_RDSR		 		0x05	/* read flash status register 									*/
#define FLASH_SST25VF512A_EWSR		 		0x50	/* enable write status register									*/
#define FLASH_SST25VF512A_WRSR		 		0x01 	/* write flash status register									*/
#define	FLASH_SST25VF512A_WREN		 		0x06	/* set write enable 											*/
#define FLASH_SST25VF512A_WRDI		 		0x04	/* reset write enable 											*/
#define FLASH_SST25VF512A_RDID		 		0xAB   	/* read manufacturer and product ID								*/

/* additional instruction for flash memory in nRF24LE1 */
#define FLASH_ERASE_PAGE 		0x52	/* erase address page											*/
#define	FLASH_ERASE_ALL	 		0x62	/* erase all page												*/
#define FLASH_RDFPCR	 		0x89	/* read flash protect configuration register					*/
#define FLASH_RDISMB     		0x85    /* set flash main block read-back disable      					*/
#define FLASH_ENDEBUG	 		0x86	/* enable debugger through JTAG-pins							*/
	
/* SPI master cs is P13 */
#define	FLASH_CS		P13

#include <stdint.h>

/** init the flash, connect flash to the SPI interface.
 */
void flash_SST25VF512A_init();

/** begin to write flash from address.
 * @param addr target address
 */
void flash_SST25VF512A_begin_write(uint32_t addr);

/** write a byte to flash
 * @param b the writting byte of data
 */
void flash_SST25VF512A_write(uint8_t b);

/** end of flash write sequence.
 */
void flash_SST25VF512A_end_write();

/** read flash from specific address.
 * @param addr target address
 */
void flash_SST25VF512A_begin_read(uint16_t addr);

/** read a single byte from flash.
 * @return the read byte
 */
uint8_t flash_SST25VF512A_read();

/** end to read from flash.
 */
void flash_SST25VF512A_end_read();

/** read the status register.
 * @return the read byte of status register
 */
uint8_t flash_SST25VF512A_read_status();

/** write the status register.
 * @param b the status data
 */
void flash_SST25VF512A_write_status(uint8_t b);

/** read a single byte from specified address.
 * @param addr target address
 * @return the read byte of address addr
 */
uint8_t flash_SST25VF512A_read_single_byte(uint16_t addr);

/** write a single byte to specified address.
 * @param addr target address
 * @param b the writting byte of data
 */
void flash_SST25VF512A_write_single_byte(uint16_t addr, uint8_t b);

/** erase specific sector.
 * @param addr sector address
 */
void flash_SST25VF512A_erase_sector(uint16_t addr);

/** erase specific block.
 * @param addr block address
 */
void flash_SST25VF512A_erase_block(uint16_t addr);

/** erase all blocks on flash.
 */
void flash_SST25VF512A_erase_chip();

#endif 
