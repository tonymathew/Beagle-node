/* Copyright (c) 2008 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is confidential property of Nordic 
 * Semiconductor. The use, copying, transfer or disclosure of such information 
 * is prohibited except by express written agreement with Nordic Semiconductor.
 *
 * $LastChangedRevision:$
 */

/** @file
 * Radio functions for the nRF24LE1 example application.
 *
 * This file handles all radio communication for the example application, i.e. 
 * radio_init, radio_send_packet and radio_interrupt function.
 *
 * @author Rune Brandsegg
 * @author Ivar C. OEsthus
 *
 */

#include <HAL/hal_nrf.h>
#include <nRF24LE1/radio.h>
#include <HAL/nordic_common.h>

code const uint8_t address[HAL_NRF_AW_5BYTES] = {0x22,0x33,0x44,0x55,0x01};
static uint8_t radio_status;                    // Global radio status byte; 
                                                // READY, BUSY, TX_DS, MAX_RT
                                                // or RX_DR
void radio_init(uint8_t operation_mode)
{
  CE_LOW();                                   // Disable radio

  hal_nrf_enable_ack_payload(true);             // Enable dynamic ack
  hal_nrf_enable_dynamic_payload(true);         // Enable dynamic payload
  hal_nrf_setup_dynamic_payload(0xFF);          // All pipes uses dynamic ack.

  hal_nrf_close_pipe(HAL_NRF_ALL);              // First close all radio pipes
                                                // Pipe 0 and 1 open by default
  hal_nrf_open_pipe(HAL_NRF_PIPE0, true);       // Open pipe0, with autoack

  hal_nrf_set_crc_mode(HAL_NRF_CRC_16BIT);      // Operates in 16bits CRC mode
  hal_nrf_set_auto_retr(15, 250);               // 250 µs delay, 15 retransmits
  
  hal_nrf_set_address_width(HAL_NRF_AW_5BYTES); // 5 bytes address width
  hal_nrf_set_address(HAL_NRF_TX, address);     // Set device's addresses
  hal_nrf_set_address(HAL_NRF_PIPE0, address);  // Pipe0 used for auto ACK

  if(operation_mode == RECEIVER)                // Mode depentant settings
  {        
    hal_nrf_set_operation_mode(HAL_NRF_PRX);    // Enter RX mode
    CE_HIGH();                                   // Enable radio
  }
  else                                          // Mode depentant settings
  {
    hal_nrf_set_operation_mode(HAL_NRF_PTX);    // Enter TX mode
  }
  
  hal_nrf_set_rf_channel(40);                   // Using channel 40 (2440MHz)
  hal_nrf_set_power_mode(HAL_NRF_PWR_UP);       // Power up device
  
  radio_status = RF_IDLE;                       // Radio ready, i.e. RF_IDLE
}


void radio_send_packet(uint8_t *payload, uint8_t length)
{
  hal_nrf_write_tx_payload(payload, length);      // Load message into radio
  
  CE_PULSE();                                   // Send packet

  radio_status = RF_BUSY;                       // Trans. in progress; RF_BUSY
}

bool radio_busy(void)
{
  return(radio_status == RF_BUSY);       
}

bool radio_packet_sent(void)
{
  switch(radio_status)
  {
    case HAL_NRF_TX_DS:                         // Packet sent
      radio_status = RF_IDLE;                   // Return to radio:RF_IDLE
      return true;                                  
      break;

    case HAL_NRF_MAX_RT:                        // Packet lost
      radio_status = RF_IDLE;                   // Return to radio:RF_IDLE
      return false;
      break;
    
    default:
      return false;
      break;
  }
}

bool radio_data_received(void)
{
  return(radio_status == HAL_NRF_RX_DR);
}

uint8_t radio_read_data(uint8_t *rx_data)
{
  uint8_t length = LSB(hal_nrf_read_rx_payload(rx_data)); // Get received data,
                                                        // and bytes received   
  if (hal_nrf_get_rx_fifo_status() == FIFO_EMPTY)       // Fifo is empty?	
  {
    radio_status = RF_IDLE;
  }
  return length;
}


void radio_interrupt(void)
{
  switch(hal_nrf_get_clear_irq_flags())
  {
    case (1<<HAL_NRF_MAX_RT):                   // Max retries reach LED2_flash
      hal_nrf_flush_tx();                       // Flush tx fifo, avoid jamming
      radio_status = HAL_NRF_MAX_RT;
      break;
    
    case (1<<HAL_NRF_TX_DS):                    // Packet sent, LED1_flash      
      radio_status = HAL_NRF_TX_DS;
      break;
    
    case (1<<HAL_NRF_RX_DR):                    // Packet received, LED1_flash
      radio_status = HAL_NRF_RX_DR;
      break;
      
    default:
      break;    
  }
}
