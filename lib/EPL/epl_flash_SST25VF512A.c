/* flash driver using external SPI implementation
 *
 * Brian Yang <asdyaya@gmail.com> 
 * 2009/02/12
 */

#include <Nordic/reg24le1.h>
#include <HAL/hal_spi.h>
#include <EPL/epl_flash_SST25VF512A.h>
#include <stdint.h>

bool first_byte = false;

void flash_SST25VF512A_init()
{
	/* connect spi to flash and setup clock rate */
	hal_spi_master_init(SPI_CLK_DIV2, HAL_SPI_MODE_0, HAL_SPI_MSB_LSB);
	
	/* set CS to output direction */
	P1DIR &= ~0x08;
	
	/* make all blocks unprotected */
	flash_SST25VF512A_write_status(0x00);
}

void flash_SST25VF512A_begin_write(uint32_t addr)
{
	first_byte = true;
	
	FLASH_CS = 0;										/* active flash */
	hal_spi_master_read_write(FLASH_SST25VF512A_WREN);	/* write-enable instruction */
	FLASH_CS = 1;										/* inactive flash */
	FLASH_CS = 0;										/* active flash */
	hal_spi_master_read_write(FLASH_SST25VF512A_AII_WORD_PROG);		/* write instruction */
	hal_spi_master_read_write(0x00); 			/* highest byte of addr */
	hal_spi_master_read_write(addr >> 8); 		/* medium byte of addr */
	hal_spi_master_read_write(addr & 0xff);     /* lowest byte */
}

void flash_SST25VF512A_write(uint8_t b)
{
	if(first_byte)
	{
		first_byte = false;
	}
	else
	{
		FLASH_CS = 0;							/* active flash */
		hal_spi_master_read_write(FLASH_SST25VF512A_AII_WORD_PROG);		/* write instruction */
	}
	hal_spi_master_read_write(b);
	FLASH_CS = 1;      							/* inactive flash */
	while (flash_SST25VF512A_read_status() & 0x01)         	/* wait until write cycle done */
		;
}

void flash_SST25VF512A_end_write()
{
	FLASH_CS = 1;                         		/* inactive flash */
	FLASH_CS = 0;								/* active flash */
	hal_spi_master_read_write(FLASH_SST25VF512A_WRDI);		/* write-disable instruction */
	FLASH_CS = 1;								/* inactive flash */
	
	while (flash_SST25VF512A_read_status() & 0x01)       	/* wait until write cycle done */
		;
}

void flash_SST25VF512A_begin_read(uint16_t addr)
{
	uint8_t byte = 0;
	while (flash_SST25VF512A_read_status() & 0x01)		/* wait until write cycle done */
		;
	FLASH_CS = 0;										/* active flash */
	hal_spi_master_read_write(FLASH_SST25VF512A_READ);	/* read instruction */
	hal_spi_master_read_write(0x00); 			/* highest byte of addr */
	hal_spi_master_read_write(addr >> 8); 		/* medium byte of addr */
	hal_spi_master_read_write(addr & 0xff);     /* lowest byte */
}

uint8_t flash_SST25VF512A_read()
{
  	uint8_t byte = 0;
  	byte = hal_spi_master_read_write(0);
	return byte;
}

void flash_SST25VF512A_end_read()
{
	FLASH_CS = 1;                        		/* inactive flash */
}

uint8_t flash_SST25VF512A_read_status()
{
	uint8_t byte;
	FLASH_CS = 0;								/* active flash */
	hal_spi_master_read_write(FLASH_SST25VF512A_RDSR);	/* send read-status-register
														instruction to the flash */
	byte = hal_spi_master_read_write(0x00);
	FLASH_CS = 1;								/* inactive flash */

	return byte;
}

void flash_SST25VF512A_write_status(uint8_t b)
{
	FLASH_CS = 0;   									/* active flash */
	hal_spi_master_read_write(FLASH_SST25VF512A_EWSR);   /* enable write-status-register operation */
	FLASH_CS = 1;   									/* inactive flash */
	FLASH_CS = 0;   									/* active flash */
	hal_spi_master_read_write(FLASH_SST25VF512A_WRSR);  /* send write-status-register
						   								instruction to the flash */
	hal_spi_master_read_write(b);
	FLASH_CS = 1;   									/* inactive flash */
	while (flash_SST25VF512A_read_status() & 0x01)      /* wait until write cycle done */
	  	;
}

uint8_t flash_SST25VF512A_read_single_byte(uint16_t addr)
{
	uint8_t b;
  	FLASH_CS = 0;                           			/* active flash */
	hal_spi_master_read_write(FLASH_SST25VF512A_READ);  /* read instruction */
	hal_spi_master_read_write(0x00); 				/* highest byte of addr */
	hal_spi_master_read_write(addr >> 8); 			/* medium byte of addr */
	hal_spi_master_read_write(addr & 0xff);     /* lowest byte */
	b = hal_spi_master_read_write(0x00); 		/* read a byte */
	FLASH_CS = 1;                           	/* inactive flash */
	return b;
}

void flash_SST25VF512A_write_single_byte(uint16_t addr, uint8_t b)
{
    FLASH_CS = 0;      									/* active flash */
    hal_spi_master_read_write(FLASH_SST25VF512A_WREN);  /* write-enable instruction */
    FLASH_CS = 1;      									/* inactive flash */
    FLASH_CS = 0;      									/* active flash */
    hal_spi_master_read_write(FLASH_SST25VF512A_BYTE_PROG);  	/* write instruction */
    hal_spi_master_read_write(0x00); 				/* highest byte of addr */
    hal_spi_master_read_write(addr >> 8); 			/* medium byte of addr */
    hal_spi_master_read_write(addr & 0xff);     	/* lowest byte */
    hal_spi_master_read_write(b); 	     			/* write data */
    FLASH_CS = 1;      								/* inactive flash */
	while (flash_SST25VF512A_read_status() & 0x01)  /* wait until write cycle done */
	  	;
}

void flash_SST25VF512A_erase_sector(uint16_t addr)
{
	FLASH_CS = 0;	
	hal_spi_master_read_write(FLASH_SST25VF512A_WREN);			/* write-enable instruction */
	FLASH_CS = 1;				
	FLASH_CS = 0;				
	hal_spi_master_read_write(FLASH_SST25VF512A_SECTOR_ERASE);	/* erase-sector instruction */
	hal_spi_master_read_write(0x00); 				/* highest byte of addr */
	hal_spi_master_read_write(addr >> 8); 			/* medium byte of addr */
	hal_spi_master_read_write(addr & 0xff);   		/* lowest byte */
	FLASH_CS = 1;									/* inactive flash */
	while (flash_SST25VF512A_read_status() & 0x01)				/* wait until erase done */
		;
}

void flash_SST25VF512A_erase_block(uint16_t addr)
{
	FLASH_CS = 0;	
	hal_spi_master_read_write(FLASH_SST25VF512A_WREN);			/* write-enable instruction */
	FLASH_CS = 1;				
	FLASH_CS = 0;				
	hal_spi_master_read_write(FLASH_SST25VF512A_BLOCK_ERASE);	/* erase-block instruction */
	hal_spi_master_read_write(0x00); 				/* highest byte of addr */
	hal_spi_master_read_write(addr >> 8); 			/* medium byte of addr */
	hal_spi_master_read_write(addr & 0xff);   		/* lowest byte */
	FLASH_CS = 1;									/* inactive flash */
	while (flash_SST25VF512A_read_status() & 0x01)				/* wait until erase done */
		;
}

void flash_SST25VF512A_erase_chip()
{
	FLASH_CS = 0;	
	hal_spi_master_read_write(FLASH_SST25VF512A_WREN);		/* write-enable instruction */
	FLASH_CS = 1;				
	FLASH_CS = 0;				
	hal_spi_master_read_write(FLASH_SST25VF512A_CHIP_ERASE);/* erase-all instruction */
	FLASH_CS = 1;											/* inactive flash */
	while (flash_SST25VF512A_read_status() & 0x01)			/* wait until erase done */
		;
}
