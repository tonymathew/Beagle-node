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
 * @brief Implementation of hal_w2
 */

#include <stdint.h>
#include <stdbool.h>

#include <Nordic/reg24le1.h>
#include <HAL/nordic_common.h>
#include <HAL/hal_w2.h>

#define BROADCAST_ENABLE      7     // W2CON0 register bit 7
#define CLOCK_STOP            6     // W2CON0 register bit 6
#define X_STOP                5     // W2CON0 register bit 5
#define X_START               4     // W2CON0 register bit 4
#define CLOCK_FREQUENCY_1     3     // W2CON0 register bit 3
#define CLOCK_FREQUENCY_0     2     // W2CON0 register bit 2
#define MASTER_SELECT         1     // W2CON0 register bit 1
#define WIRE_2_ENABLE         0     // W2CON0 register bit 0


/* Slave specific functions */

void hal_w2_respond_to_gen_adr(bool resp_gen)
{ 
  if(resp_gen)
  {                                                                   
    W2CON0 = W2CON0 | (1 << BROADCAST_ENABLE);  // Set "broadcastEnable" bit
  }
  else
  {
    W2CON0 = W2CON0 & ~(1 << BROADCAST_ENABLE); // Clear "broadcastEnable" bit
  }
}

void hal_w2_alter_clock(bool alt_clk)
{
  if(alt_clk)                         
  {
    W2CON0 = W2CON0 | (1 << CLOCK_STOP);      // Set "clockStop" bit
  }
  else
  {
    W2CON0 = W2CON0 & ~(1 << CLOCK_STOP);     // Clear "clockStop" bit
  }
}

void hal_w2_irq_stop_cond_enable(bool stop_cond)
{ 
  if(stop_cond)
  {                                                                  
    W2CON0 = W2CON0 & ~(1 << X_STOP);         // Clear "xStop" bit
  }
  else
  {
    W2CON0 = W2CON0 | (1 << X_STOP);          // Set "xStop" bit
  }
}

void hal_w2_irq_adr_match_enable(bool addr_match)
{
  if(addr_match)
  {
    W2CON0 = W2CON0 & ~(1 << X_START);        // Clear "xStart" bit
  }
  else
  {
    W2CON0 = W2CON0 | (1 << X_START);         // Set "xStart" bit
  }
}

void hal_w2_set_slave_address(uint8_t address)
{
  W2SADR = (address & 0x7F);                  // Set 7 bit adress of the slave
}


/* Master specific functions */

void hal_w2_transmit_start_cond(void)
{
  W2CON0 = W2CON0 | (1 << X_START);           // Set "xStart" bit
}

void hal_w2_transmit_stop_cond(void)
{
  W2CON0 = W2CON0 | (1 << X_STOP);            // Set "xStop" bit
}


/* General functions */

void hal_w2_set_clk_freq(hal_w2_clk_freq_t freq)
{                                             
  W2CON0 = (W2CON0 & 0xF3) | (((uint8_t)freq) << CLOCK_FREQUENCY_0);       
}                                             // Update "clockFrequency" bits

void hal_w2_set_op_mode(hal_w2_op_mode_t mode)
{
  if(mode == HAL_W2_MASTER)                   // Check for master mode
  {                                                                  
    W2CON0 = W2CON0 | (1 << MASTER_SELECT);   // Set "masterSelect" bit
  }
  else
  {
    W2CON0 = W2CON0 & ~(1 << MASTER_SELECT);  // Clear "masterSelect" bit
  }
}

void hal_w2_enable(bool en)
{ 
  if(en)
  {
    W2CON0 = W2CON0 | (1 << WIRE_2_ENABLE);   // Set "wire2Enable" bit
  }
  else
  {
    W2CON0 = W2CON0 & ~(1 << WIRE_2_ENABLE);  // Clear "wire2Enable" bit
  }
}

void hal_w2_all_irq_enable(bool irq)
{ /* In this function the standard "read-modify-write" is not used because
     bit 4:0 (the status bits) in W2CON1 are cleared when read. These bits
     are read only so they can not be modified. */
  if(irq)
  {
    W2CON1 = ~(BIT_5);                        // Clear "maskIrq" bit
  }
  else
  {
    W2CON1 = BIT_5;                           // Set "maskIrq" bit
  }
}

uint8_t hal_w2_get_status(void)
{
  return W2CON1;                              // W2CON1 status variables are
}                                             // cleared when read

void hal_w2_write_data(uint8_t tx_data)
{
  W2DAT = tx_data;                            // Write data to transmitt
}

uint8_t hal_w2_read_data(void)
{
  return W2DAT;                               // Read received data
}