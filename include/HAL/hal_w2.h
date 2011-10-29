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
 * @brief Interface for hal_w2
 * @defgroup arch_nrf24le1_hal_w2 hal_w2
 * @{
 * @ingroup arch_nrf24le1
 *
 * @brief  Interface for the 2-Wire module.
 */


#ifndef HAL_W2_H__
#define HAL_W2_H__

#include <stdint.h>
#include <stdbool.h>


/** An enum describing the clock frequency.
 *
 */
typedef enum {
  HAL_W2_IDLE   = 0x00,       /**< Idle */
  HAL_W2_100KHZ = 0x01,       /**< 100 KHz (Standard mode) */
  HAL_W2_400KHZ = 0x02        /**< 400 KHz (Fast mode) */
} hal_w2_clk_freq_t;                

/** An enum describing master or slave mode.
 *
 */
typedef enum {
  HAL_W2_MASTER,              /**< Master mode */
  HAL_W2_SLAVE                /**< Slave mode */
} hal_w2_op_mode_t;                 

/** An enum describing the 2-wire's irq sources.
 *
 */ 
typedef enum {
  HAL_W2_STOP_COND = 0x08,    /**< Interrupt caused by stop condition */
  HAL_W2_ADRESS_MATCH = 0x04, /**< Interrupt caused by address match */
  HAL_W2_DATA_READY = 0x01    /**< Interrupt caused by byte transmitted/received */
} hal_w2_irq_source_t;

/** @name   SLAVE SPECIFIC FUNCTIONS  */
//@{
/* Slave specific function prototypes */

/** Function to set the slave to respond to a general call address.
 * Use this function set the slave to respond to a general call address (0x00) 
 * as well as the defined address
 * -- Slave only --
 *
 * @param resp_gen True if the slave shall respond to general call adress
 */
void hal_w2_respond_to_gen_adr(bool resp_gen);

/** Function to control clockStop mode.
 * Use this function to control clockStop mode
 * -- Slave only --
 */
void hal_w2_alter_clock(bool alt_clk);

/** Function to enable irq when stop condition is detected.
 * Use this function enable irq when stop condition is detected
 * -- Slave only --
 *
 * @param stop_cond True to enable, false to disable irq when stop condition is detected
 */
void hal_w2_irq_stop_cond_enable(bool stop_cond);

/** Function to enable the irq on address match.
 * Use this function enable the irq on address match
 * -- Slave only --
 *
 * @param addr_match True to enable, false to disable the irq on address match
 */
void hal_w2_irq_adr_match_enable(bool addr_match);

/** Function to set the slave address.
 * Use this function to set the 7-bit address for slave mode.
 *
 * @param address 7-bit slave address 
 */
void hal_w2_set_slave_address(uint8_t address);
//@}


/** @name   MASTER SPECIFIC FUNCTIONS  */
//@{
/* Master specific function prototypes */

/** Function to start transmitting.
 * Use this function start transmitting
 * -- Master only --
 */
void hal_w2_transmit_start_cond(void);

/** Function to stop transmitting.
 * Use this function stop transmitting
 * -- Master only -- 
 */
void hal_w2_transmit_stop_cond(void);
//@}


/** Function to set the clock frequency.
 * Use this function select clock frequency of the 2-wire.
 *
 * @param freq The clock frequency of the 2-wire
 */
void hal_w2_set_clk_freq(hal_w2_clk_freq_t freq);

/** Function to set the operation mode of the 2-wire.
 * Use this function select master or slave mode.
 *
 * @param mode The operation mode of the 2-wire
 */
void hal_w2_set_op_mode(hal_w2_op_mode_t mode);

/** Function to enable the 2-wire.
 * Use this function enable the 2-wire, must be done before any other
 * programming of the 2-wire.
 *
 * @param en True to enable, false to disable
 */
void hal_w2_enable(bool en);

/** Function to enable all interrupts.
 * Use this function enable all interrupts.
 *
 * @param irq True to enable, false to disable all interrupts in the 2-wire
 */
void hal_w2_all_irq_enable(bool irq);

/** Function that returns the status of the 2-wire.
 * Use this function to get the status of the 2-wire
 * 
 * @remark Bit 4:0 are cleared when read.
 * @return Status register
 */
uint8_t hal_w2_get_status(void);

/** Function to write to the 2-wire data register.
 * Use this function to write to the 2-wire data register.
 *
 * @param tx_data Data to transmit
 */
void hal_w2_write_data(uint8_t tx_data);

/** Function to read from the 2-wire data register.
 * Use this function to read from the 2-wire data register.
 *
 * @return Data in 2-wire data register
 */
uint8_t hal_w2_read_data(void);


#endif // HAL_W2_H__
/** @}  */
