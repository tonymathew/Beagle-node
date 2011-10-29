/* @file 
 * LE1 SST25VF032B Flash (32Mbit) driver using external SPI
 * if you wnat to control flash use MCU please include HAL/hal_flash.h and use it
 *
 * @author Brian Yang <asdyaya@gmail.com>
 * 2009/02/12
 */

#ifndef _EPL_FLASH_SST25VF032B_H_
#define _EPL_FLASH_SST25VF032B_H_

/* instruction set defined in SST25VF032B */
#define	FLASH_SST25VF032B_READ		 		0x03	/* read data from flash											*/
#define FLASH_SST25VF032B_FAST_READ  		0x0B   	/* read data from flash at fast read mode						*/
#define FLASH_SST25VF032B_SECTOR_ERASE  	0x20   	/* 4KByte sector erase											*/
#define FLASH_SST25VF032B_BLOCK_ERASE_32  	0x52   	/* 32KByte block erase											*/
#define FLASH_SST25VF032B_BLOCK_ERASE_64  	0xD8   	/* 64KByte block erase											*/
#define FLASH_SST25VF032B_CHIP_ERASE 		0x60	/* chip erase													*/
#define	FLASH_SST25VF032B_BYTE_PROG		 	0x02	/* write one byte to flash										*/
#define	FLASH_SST25VF032B_AII_WORD_PROG	 	0xAD	/* auto address increment programming							*/
#define FLASH_SST25VF032B_RDSR		 		0x05	/* read flash status register 									*/
#define FLASH_SST25VF032B_EWSR		 		0x50	/* enable write status register									*/
#define FLASH_SST25VF032B_WRSR		 		0x01 	/* write flash status register									*/
#define	FLASH_SST25VF032B_WREN		 		0x06	/* set write enable 											*/
#define FLASH_SST25VF032B_WRDI		 		0x04	/* reset write enable 											*/
#define FLASH_SST25VF032B_RDID		 		0xAB   	/* read manufacturer and product ID								*/
#define FLASH_SST25VF032B_JEDEC_ID_READ  	0x9F   	/* read manufacturer and product ID by JEDEC ID command			*/
#define FLASH_SST25VF032B_EBSY			  	0x70   	/* enable SO as an output RY/BY# status during AAI progeamming	*/
#define FLASH_SST25VF032B_DBSY			  	0x80   	/* disable SO as an output RY/BY# status during AAI progeamming	*/


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
void flash_SST25VF032B_init();

/** begin to write flash from address.
 * @param addr target address
 */
void flash_SST25VF032B_begin_write(uint32_t addr);

/** write a byte to flash
 * @param b1 the first writting byte of data (invalid if (addr & 0x01) == 1)
 * @param b2 the second writting byte of data
 */
void flash_SST25VF032B_write(uint8_t b1, uint8_t b2);

/** end of flash write sequence.
 */
void flash_SST25VF032B_end_write();

/** read flash from specific address.
 * @param addr target address
 */
void flash_SST25VF032B_begin_read(uint32_t addr);

/** read a single byte from flash.
 * @return the read byte
 */
uint8_t flash_SST25VF032B_read();

/** end to read from flash.
 */
void flash_SST25VF032B_end_read();

/** read the status register.
 *  @return the read byte of status register
 */
uint8_t flash_SST25VF032B_read_status();

/** write the status register.
 * @param b the status data
 */
void flash_SST25VF032B_write_status(uint8_t b);

/** read a single byte from specified address.
 * @param addr target address
 * @return the read byte of address addr
 */
uint8_t flash_SST25VF032B_read_single_byte(uint32_t addr);

/** write a single byte to specified address.
 * @param addr target address
 * @param b the writting byte of data
 */
void flash_SST25VF032B_write_single_byte(uint32_t addr, uint8_t b);

/** erase specific sector.
 * @param addr sector address
 */
void flash_SST25VF032B_erase_sector(uint32_t addr);

/** erase specific block (32KB).
 * @param addr block address
 */
void flash_SST25VF032B_erase_block_32(uint32_t addr);

/** erase specific block (64KB).
 * @param addr block address
 */
void flash_SST25VF032B_erase_block_64(uint32_t addr);

/** erase all blocks on flash.
 */
void flash_SST25VF032B_erase_chip();

#endif 
