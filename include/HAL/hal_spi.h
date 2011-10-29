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
 * $LastChangedRevision: 4234 $
 */ 

/** @file
 * @brief Interface functions for the SPI bus
 *
 * @defgroup arch_nrf24le1_hal_spi hal_spi
 * @{
 * @ingroup arch_nrf24le1
 * 
 * @brief Interface functions for the SPI bus.
 *
 * The Serial Peripheral Interface (SPI) is double buffered and can be configured to 
 * work in all four SPI modes. The default is mode 0.
 *
 * The SPI connects to the following pins of the device: MMISO, MMOSI, MSCK.
 * The SPI Master function does not generate any chip 
 * select signal (CSN). The programmer typically uses another programmable 
 * digital I/O to act as chip selects for one or more external SPI Slave devices.
 * 
 * This module contains functions for initializing the SPI master; reading and 
 * writing single and multiple bytes from/to the SPI master; and flushing the SPI RX FIFO.
 */
#ifndef HAL_SPI_H__
#define HAL_SPI_H__

#include <stdint.h>
#include <stdbool.h>

/** Available SPI clock divide factors
 * The input argument of hal_spi_master_init must be defined in this @c enum
 */
typedef enum
{
    SPI_CLK_DIV2,        /**< CPU clock/2 */
    SPI_CLK_DIV4,        /**< CPU clock/4 */
    SPI_CLK_DIV8,        /**< CPU clock/8 */
    SPI_CLK_DIV16,       /**< CPU clock/16 */
    SPI_CLK_DIV32,       /**< CPU clock/32 */
    SPI_CLK_DIV64,       /**< CPU clock/64 */
    SPI_CLK_DIV128       /**< CPU clock/128 */
} hal_spi_clkdivider_t;  

/** SPI data order (bit wise per byte) on serial output and input
 * The input argument of hal_spi_master_init must be defined in this @c enum
 */
typedef enum {
   HAL_SPI_LSB_MSB,      /**< LSBit first, MSBit last */
   HAL_SPI_MSB_LSB       /**< MSBit first, LSBit last */
} hal_spi_byte_order_t;
    
/** SPI operating modes
 * The input argument of hal_spi_master_init must be defined in this @c enum
 */
typedef enum {           
   HAL_SPI_MODE_0,       /**< MSCK is active high, sample on leading edge of MSCK */
   HAL_SPI_MODE_1,       /**< MSCK is active high, sample on trailing edge of MSCK */
   HAL_SPI_MODE_2,       /**< MSCK is active low, sample on leading edge of MSCK */
   HAL_SPI_MODE_3        /**< MSCK is active low, sample on trailing edge of MSCK/ */
} hal_spi_mode_t;


/** Function to initialize and enable the SPI master.
 */
void hal_spi_master_init(hal_spi_clkdivider_t ck, hal_spi_mode_t mode, hal_spi_byte_order_t bo);

/** Function to read/write a byte on the SPI master
 * This function writes a byte to the SPI master, then enters an infinite loop
 * waiting for the operation to finish. When the operation is finished the SPI
 * master interrupt bit is cleared and the received byte is returned
 * @param pLoad byte to write
 * @return The read byte
 */
unsigned char hal_spi_master_read_write(unsigned char pLoad);


#endif // HAL_SPI_H__
/** @} */

