/* Copyright (c) 2008 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT. 
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRENTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 * $LastChangedRevision$
 */ 

 /** @file
 * @brief Implementation of  hal_spi
 */

#include <Nordic/reg24le1.h>
#include <HAL/hal_spi.h>
#include <HAL/nordic_common.h>

void hal_spi_master_init(hal_spi_clkdivider_t ck, hal_spi_mode_t mode, hal_spi_byte_order_t bo)
{
  SPIMCON0 = 0;                           // Default register settings
  switch (ck)                             // Set desired clock divider
  {
    case SPI_CLK_DIV2:
      SPIMCON0 |= (0x00 << 4);
      break;
    case SPI_CLK_DIV4:
      SPIMCON0 |= (0x01 << 4);
      break;
    case SPI_CLK_DIV8:
      SPIMCON0 |= (0x02 << 4);
      break;
    case SPI_CLK_DIV16:
      SPIMCON0 |= (0x03 << 4);
      break;
    case SPI_CLK_DIV32:
      SPIMCON0 |= (0x04 << 4);
      break;
    case SPI_CLK_DIV64:                   // We use clock divder 64 as default
    default:
      SPIMCON0 |= (0x05 << 4);
      break;  
  }
  switch(mode)                            // Set desired mode
  {
    case HAL_SPI_MODE_0:
      SPIMCON0 |= (0x00 << 1);
      break;
    case HAL_SPI_MODE_1:
      SPIMCON0 |= (0x01 << 1);
      break;
    case HAL_SPI_MODE_2:
      SPIMCON0 |= (0x02 << 1);
      break;
    case HAL_SPI_MODE_3:      
      SPIMCON0 |= (0x03 << 1);
      break;
  }
  
  if(bo == HAL_SPI_LSB_MSB)               // Set desired data order
  {
    SPIMCON0 |= BIT_3;
  }

  SPIMCON0 |= BIT_0;                      // Enable SPI master
}

unsigned char hal_spi_master_read_write(unsigned char pLoad)
{
  SPIMDAT = pLoad ;                       // Write data to SPI master
  while(!(SPIMSTAT & 0x04))               // Wait for data available in rx_fifo
  ;
  return SPIMDAT;                         // Return data register
}