/* flash driver using external SPI implementation
 *
 * Brian Yang <asdyaya@gmail.com> 
 * 2009/02/12
 */

#include <Nordic/reg24le1.h>
#include <HAL/hal_spi.h>
#include <EPL/epl_flash_SST25VF032B.h>
#include <stdint.h>

//uint32_t start_addr = 0;
//uint16_t write_count = 0;
bool first_byte = false;

void flash_SST25VF032B_init()
{
	/* connect spi to flash and setup clock rate */
	hal_spi_master_init(SPI_CLK_DIV2, HAL_SPI_MODE_0, HAL_SPI_MSB_LSB);
	
	/* set CS to output direction */
	P1DIR &= ~0x08;
	
	/* make all blocks unprotected */
	flash_SST25VF032B_write_status(0x00);
}

void flash_SST25VF032B_begin_write(uint32_t addr)
{
	first_byte = true;
	
	FLASH_CS = 0;										/* active flash */
	hal_spi_master_read_write(FLASH_SST25VF032B_WREN);	/* write-enable instruction */
	FLASH_CS = 1;										/* inactive flash */
	FLASH_CS = 0;										/* active flash */
	hal_spi_master_read_write(FLASH_SST25VF032B_AII_WORD_PROG);		/* write instruction */
	hal_spi_master_read_write((addr >> 16) & 0xff); 	/* highest byte of addr */
	hal_spi_master_read_write((addr >> 8) & 0xff); 		/* medium byte of addr */
	hal_spi_master_read_write(addr & 0xff);     /* lowest byte */
}

void flash_SST25VF032B_write(uint8_t b1, uint8_t b2)
{
	if(first_byte)
	{
		first_byte = false;
	}
	else
	{
		FLASH_CS = 0;							/* active flash */
		hal_spi_master_read_write(FLASH_SST25VF032B_AII_WORD_PROG);		/* write instruction */
	}
	hal_spi_master_read_write(b1);
	hal_spi_master_read_write(b2);
	FLASH_CS = 1;      								/* inactive flash */
	while (flash_SST25VF032B_read_status() & 0x01)  /* wait until write cycle done */
		;
}

void flash_SST25VF032B_end_write()
{
	FLASH_CS = 1;                         				/* inactive flash */
	FLASH_CS = 0;										/* active flash */
	hal_spi_master_read_write(FLASH_SST25VF032B_WRDI);	/* write-disable instruction */
	FLASH_CS = 1;										/* inactive flash */
	
	while (flash_SST25VF032B_read_status() & 0x01)       /* wait until write cycle done */
		;
}

void flash_SST25VF032B_begin_read(uint32_t addr)
{
	uint8_t byte = 0;
	while (flash_SST25VF032B_read_status() & 0x01)		/* wait until write cycle done */
		;
	FLASH_CS = 0;										/* active flash */
	hal_spi_master_read_write(FLASH_SST25VF032B_READ);	/* read instruction */
	hal_spi_master_read_write((addr >> 16) & 0xff); 	/* highest byte of addr */
	hal_spi_master_read_write((addr >> 8) & 0xff); 		/* medium byte of addr */
	hal_spi_master_read_write(addr & 0xff);     /* lowest byte */
}

uint8_t flash_SST25VF032B_read()
{
  	uint8_t byte = 0;
  	byte = hal_spi_master_read_write(0);
	return byte;
}

void flash_SST25VF032B_end_read()
{
	FLASH_CS = 1;                        		/* inactive flash */
}

uint8_t flash_SST25VF032B_read_status()
{
	uint8_t byte;
	FLASH_CS = 0;								/* active flash */
	hal_spi_master_read_write(FLASH_SST25VF032B_RDSR);		/* send read-status-register
															instruction to the flash */
	byte = hal_spi_master_read_write(0x00);
	FLASH_CS = 1;								/* inactive flash */

	return byte;
}

void flash_SST25VF032B_write_status(uint8_t b)
{
	FLASH_CS = 0;   									/* active flash */
	hal_spi_master_read_write(FLASH_SST25VF032B_EWSR);  /* enable write-status-register operation */
	FLASH_CS = 1;   									/* inactive flash */
	FLASH_CS = 0;   									/* active flash */
	hal_spi_master_read_write(FLASH_SST25VF032B_WRSR);  /* send write-status-register
							   							instruction to the flash */
	hal_spi_master_read_write(b);
	FLASH_CS = 1;   									/* inactive flash */
	while (flash_SST25VF032B_read_status() & 0x01)      /* wait until write cycle done */
	  	;
}

uint8_t flash_SST25VF032B_read_single_byte(uint32_t addr)
{
	uint8_t b;
  	FLASH_CS = 0;                           	/* active flash */
	hal_spi_master_read_write(FLASH_SST25VF032B_READ);  	/* read instruction */
	hal_spi_master_read_write((addr >> 16) & 0xff); 	/* highest byte of addr */
	hal_spi_master_read_write((addr >> 8) & 0xff); 		/* medium byte of addr */
	hal_spi_master_read_write(addr & 0xff);     /* lowest byte */
	b = hal_spi_master_read_write(0x00); 		/* read a byte */
	FLASH_CS = 1;                           	/* inactive flash */
	return b;
}

void flash_SST25VF032B_write_single_byte(uint32_t addr, uint8_t b)
{
    FLASH_CS = 0;      										/* active flash */
    hal_spi_master_read_write(FLASH_SST25VF032B_WREN);  	/* write-enable instruction */
    FLASH_CS = 1;      										/* inactive flash */
    FLASH_CS = 0;      										/* active flash */
    hal_spi_master_read_write(FLASH_SST25VF032B_BYTE_PROG); /* write instruction */
    hal_spi_master_read_write((addr >> 16) & 0xff); 		/* highest byte of addr */
    hal_spi_master_read_write((addr >> 8) & 0xff); 			/* medium byte of addr */
    hal_spi_master_read_write(addr & 0xff);     			/* lowest byte */
    hal_spi_master_read_write(b); 	     					/* write data */
    FLASH_CS = 1;      										/* inactive flash */
	while (flash_SST25VF032B_read_status() & 0x01)         	/* wait until write cycle done */
	  	;
}

void flash_SST25VF032B_erase_sector(uint32_t addr)
{
	FLASH_CS = 0;	
	hal_spi_master_read_write(FLASH_SST25VF032B_WREN);		/* write-enable instruction */
	FLASH_CS = 1;				
	FLASH_CS = 0;				
	hal_spi_master_read_write(FLASH_SST25VF032B_SECTOR_ERASE);	/* erase-sector instruction */
	hal_spi_master_read_write((addr >> 16) & 0xff); 	/* highest byte of addr */
	hal_spi_master_read_write((addr >> 8) & 0xff); 		/* medium byte of addr */
	hal_spi_master_read_write(addr & 0xff);   			/* lowest byte */
	FLASH_CS = 1;										/* inactive flash */
	while (flash_SST25VF032B_read_status() & 0x01)		/* wait until erase done */
		;
}

void flash_SST25VF032B_erase_block_32(uint32_t addr)
{
	FLASH_CS = 0;	
	hal_spi_master_read_write(FLASH_SST25VF032B_WREN);	/* write-enable instruction */
	FLASH_CS = 1;				
	FLASH_CS = 0;				
	hal_spi_master_read_write(FLASH_SST25VF032B_BLOCK_ERASE_32);	/* erase-block32 instruction */
	hal_spi_master_read_write((addr >> 16) & 0xff); 	/* highest byte of addr */
	hal_spi_master_read_write((addr >> 8) & 0xff); 		/* medium byte of addr */
	hal_spi_master_read_write(addr & 0xff);   			/* lowest byte */
	FLASH_CS = 1;										/* inactive flash */
	while (flash_SST25VF032B_read_status() & 0x01)		/* wait until erase done */
		;
}

void flash_SST25VF032B_erase_block_64(uint32_t addr)
{
	FLASH_CS = 0;	
	hal_spi_master_read_write(FLASH_SST25VF032B_WREN);	/* write-enable instruction */
	FLASH_CS = 1;				
	FLASH_CS = 0;				
	hal_spi_master_read_write(FLASH_SST25VF032B_BLOCK_ERASE_64);	/* erase-block64 instruction */
	hal_spi_master_read_write((addr >> 16) & 0xff); 	/* highest byte of addr */
	hal_spi_master_read_write((addr >> 8) & 0xff); 		/* medium byte of addr */
	hal_spi_master_read_write(addr & 0xff);   			/* lowest byte */
	FLASH_CS = 1;										/* inactive flash */
	while (flash_SST25VF032B_read_status() & 0x01)		/* wait until erase done */
		;
}

void flash_SST25VF032B_erase_chip()
{
	FLASH_CS = 0;	
	hal_spi_master_read_write(FLASH_SST25VF032B_WREN);		/* write-enable instruction */
	FLASH_CS = 1;				
	FLASH_CS = 0;				
	hal_spi_master_read_write(FLASH_SST25VF032B_CHIP_ERASE);/* erase-all instruction */
	FLASH_CS = 1;											/* inactive flash */
	while (flash_SST25VF032B_read_status() & 0x01)			/* wait until erase done */
		;
}

