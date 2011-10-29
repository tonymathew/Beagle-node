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
 * Radio header file for the nRF24LE1 example application
 * 
*/

#define RF_IDLE 0x00
#define RF_BUSY 0xff
#define FIFO_EMPTY 0x01

#define TRANSMITTER 0
#define RECEIVER 1

/**@brief This function initializes the radio interface, and makes a complete radio setup.
@param operation_mode : if 0, set the radio in receiver mode, otherwise set transmitter mode.
*/
void radio_init(uint8_t operation_mode);

/** Function to enable SPI interface to the radio 
 */
void nrf_spi_init(void);

/**@brief This function load the bytes to be sent into the radio, starts transmission, and returns
@param payload data to send.
@param length number of bytes to send.
*/
void radio_send_packet(uint8_t *payload, uint8_t length);

/**@brief This function check if the radio is busy.
@return true if radio is busy; false otherwise.
*/
bool radio_busy(void);

/**@brief This function check if the last packet has been sent successfully.
@return true if the packet has been successfully sent, false otherwise.
*/
bool radio_packet_sent(void);

/**@brief This function check if data has been received.
@return true if data has been received, false otherwise.
*/
bool radio_data_received(void);

/**@brief This function saves the data from the radio to the specified array.
@param rx_data pointer to where the received data shall be written.
@return the width of the received data.
*/
uint8_t radio_read_data(uint8_t *rx_data);

/**@brief This function is called on the radio interrupt. It reads the RF flags and
set the radio_status accordingly. 
*/
void radio_interrupt(void);
