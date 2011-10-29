/* ===================================================================================== *
 * Author(s): Tu Yi-Hsuan (cindyduh@nthu.us)                                             *
 *            Embedded Platform Lab, NTHU                                                *
 *                                                                                       *
 * Copyright (c) 2009 National Tsing Hua University (NTHU)                               *
 * Permission to copy, modify, and distribute this program is granted for noncommercial  *
 * purposes, provided the author(s) and copyright notice are retained.                   *
 * All other uses require explicit written permission from NTHU.                         *
 * ===================================================================================== */

/* epl_rf_en.h
 * ------------------------------------------------------------------------------------- *
 * Revision:
 * 		version 1.0	2009/03/04 = Tu Yi-Hsuan (cindyduh@nthu.us)
 * 			- The original version.
 * ------------------------------------------------------------------------------------- *
 * Description:
 * 		The target platform of the radio driver in this file is Nordic nRF24LU1.
 * 	 	The original Nordic HAL_NRF driver is required for this driver.
 * ------------------------------------------------------------------------------------- *
 * How to Use:
 * 		1. You can use only "epl_rf_en_easy_start_tx" or "epl_rf_en_easy_start_rx" to
 *         start to send or receive default RF packet.
 *      or
 * 		2. You can use only "rf_quick_init" function as a simplest way to configure RF.
 * 		or
 * 		3. For more detailed configurations, use "rf_init" and "rf_rcv_pipe_config"
 * 		   instead of "rf_quick_init".
 *
 * 		After RF initialization (2 or 3), use  "rf_enter_tx_mode" or "rf_enter_rx_mode"
 * 		to switch the mode you need.
 * ------------------------------------------------------------------------------------- *
 */

/** @file
 * Drivers for nRF24LU1 RF function
 * @author Tu Yi-Hsuan <cindyduh@nthu.us>
 *
 */
#ifndef EPL_RF_EN_H__
#define EPL_RF_EN_H__

#include <Nordic/reg24le1.h>
#include <HAL/hal_nrf_hw.h>
#include <HAL/hal_nrf.h>

/** An enum describing the radio's CRC mode.
 *
 */
typedef enum {
	RF_EN_CRC_OFF,        /* CRC check disabled */
	RF_EN_CRC_8BIT,   /* CRC check set to 8-bit */
	RF_EN_CRC_16BIT       /* CRC check set to 16-bit */
} epl_rf_en_crc_mode_t;

/** An enum describing the radio's on-air datarate.
 *
 */
typedef enum {
    RF_EN_1MBPS,          /* Datarate set to 1 Mbps  */
    RF_EN_2MBPS           /* Datarate set to 2 Mbps  */
} epl_rf_en_datarate_t;

/** An enum describing the radio's auto ack enable.
 *
 */
typedef enum {
    RF_EN_AUTO_ACK_OFF,	/* auto ack off */
    RF_EN_AUTO_ACK_ON		/* auto ack on */
} epl_rf_en_auto_ack_t;

typedef enum {
    RF_EN_SPI_CLK_RATE_1_OVER_2,
    RF_EN_SPI_CLK_RATE_1_OVER_4 = 2,
    RF_EN_SPI_CLK_RATE_1_OVER_8,
    RF_EN_SPI_CLK_RATE_1_OVER_16,
    RF_EN_SPI_CLK_RATE_1_OVER_32,
    RF_EN_SPI_CLK_RATE_1_OVER_64,
} epl_rf_en_spi_clk_rate_t;

#define RF_EN_INT_ENABLE	1
#define RF_EN_INT_DISABLE	0

/* LU1 RF configuration descriptor */
struct epl_lu1_rf_en_config {
	/* RF channel, RF frequency = 2400 + channel (Hz)*/
	unsigned char channel;
	/* Address width */
	/* (Both RX and TX's address are configured to have the same width) */
	unsigned char addr_width;
	/* The destination address. */
	char my_tx_dst_addr[5];
	/* The address of pipe PRX, the default is pipe0. */
	char my_prx_addr[5];
	/* Received data length (in bytes) */
	unsigned char data_length;
	/* RF Datarate */
	epl_rf_en_datarate_t datarate;
	/* CRC mode bit */
	epl_rf_en_crc_mode_t crc_mode;
	/* Auto ack bit */
	unsigned char auto_ack;
	/* Auto Retransmission times, 0 disable auto retransmit*/
	unsigned char auto_retr;
	/* Auto Retransmission delay (in us)*/
	unsigned int auto_retr_delay;
};

/** Initialized the RF configurations and powre up the RF.
 * Use this function to initialize RF configurations.
 * Note that the pipe isn't opened in this function,
 * please use "rf_rcv_pipe_config" after using this
 * function to configure RX pipe.
 *
 * @param in_channel RF Frequency (in_channel + 2400MHz)
 * @param in_datarate Data rate of the RF transmission. (1Mbps or 2Mbps)
 * @param in_output_power RF output power configuration.
 * @param in_auto_retr Enable auto retransmission or not.
 * @param in_auto_retr_delay Auto retransmission delay.
 * @param in_addr_width Address width configuration for both PTX and PRX pipe.
 * @param in_crc_mode CRC enable or disable configuration.
 * @param in_spi_clk_rate SPI clock rate. (SPI speed)
 * @param in_rf_int RF interrupt enable bit.
 */
void epl_rf_en_init(unsigned char in_channel, 		// Freq = in_channel + 2400 MHz
			 epl_rf_en_datarate_t in_datarate,// HAL_NRF_1MBPS or HAL_NRF_2MBPS
			 char in_output_power, 			// HAL_NRF_0DBM, HAL_NRF_6DBM, HAL_NRF_12DBM or HAL_NRF_18DBM
			 unsigned char in_auto_retr,				//
			 unsigned int in_auto_retr_delay,		//
			 char in_addr_width, 			// Address width for both PTX and PRX
			 epl_rf_en_crc_mode_t in_crc_mode,	//
			 unsigned char in_rf_int);					//

/** Setting receiver's pipe configuration.
 * Use this function to open a designated pipe, and
 * configure the payload length and auto-ack function.
 * To be compatible with nRF24L01, please disable the
 * auto ack function.
 *
 * @param in_pipe_num The pipe number you want to open.
 * @param *in_pipe_rcv_addr The address for designated pipe.
 * @param in_pipe_pload_length RX payload length for designated pipe.
 * @param in_auto_ack Auto ack enable bit.
 */
/* To be compatible with nRF24L01, please disable the auto ack function. */
void epl_rf_en_rcv_pipe_config(hal_nrf_address_t in_pipe_num, 		// The pipe number
						char *in_pipe_rcv_addr,				// The address which the data to be received.
						unsigned char in_pipe_pload_length,	// RX payload length.
						epl_rf_en_auto_ack_t in_auto_ack);					// Auto ack enable bit.

/** Easy initialization for RF functions.
 * Use this function as a convenient way to initialize the RF as tx mode.
 * The default pipe is pipe0.
 *
 * @param channel RF channel, RF frequency = 2400 + channel (Hz)
 * @param auto_retr Number of retransmit, 0 equal retransmit OFF
 * @param delay Retransmit delay in us
 */
void epl_rf_en_easy_start_tx(unsigned char channel, unsigned char auto_retr, unsigned int delay);

/** Easy initialization for RF functions.
 * Use this function as a convenient way to initialize the RF as rx mode.
 * The default pipe is pipe0.
 *
 * @param channel RF channel, RF frequency = 2400 + channel (Hz)
 * @param pload_len RX payload length for designated pipe.
 * @param auto_ack Auto ack bit
 */
void epl_rf_en_easy_start_rx(unsigned char channel, unsigned char pload_len, unsigned char auto_ack);

/** Quick initialization for RF functions.
 * Use this function as a convenient way to initialize the RF.
 * The default pipe is pipe0.
 *
 * @param *in_cfg A configuration structure to configure RF.
 */
/* The default pipe is pipe0. */
void epl_rf_en_quick_init(struct epl_lu1_rf_en_config *in_cfg);

/** Switch RF mode to TX mode.
 * Use this function to switch the mode to TX mode.
 */
void epl_rf_en_enter_tx_mode(void);

/** Switch RF mode to RX mode.
 * Use this function to switch the mode to RX mode.
 */
void epl_rf_en_enter_rx_mode(void);

/** Configuring the PTX address (destination address).
 * Use this function to configure destination address.
 *
 * @param *in_dst_addr The destination address.
 */
void epl_rf_en_set_dst_addr(unsigned char *in_dst_addr);

/** Send the RF packet to designated destination.
 * Use this function to send RF packet.
 *
 * @param *in_dst_addr The destination address.
 * @param *in_tx_pload The pointer point to the packet to be sent.
 * @param in_length The packet length.
 */
void epl_rf_en_send_dst(unsigned char *in_dst_addr, unsigned char *in_tx_pload, unsigned char in_pload_length);

/** Send the RF packet with the unchanged destination address.
 * Use this function to send RF packet with the last destination
 * address.
 *
 * @param *in_tx_pload The pointer point to the packet to be sent.
 * @param in_length The packet length.
 */
void epl_rf_en_send(unsigned char *in_tx_pload, unsigned char in_pload_length);

/** Check the RX payload is empty or not.
 * Use this function to check the RX payload is empty or not.
 *
 * @param *in_tx_pload The pointer point to the packet to be sent.
 * @return True (1) for RX fifo empty or false for RX fifo not empty.
 */
unsigned char epl_rf_en_rx_pload_is_empty(void);

/** Read the RX payload.
 * Use this function to read the RX payload.
 *
 * @param *out_rx_pload The space to copy the RX payload.
  */
void epl_rf_en_read_rx_pload(unsigned char *out_rx_pload);

/** Wait until the RX payload is valid, and read the RX payload.
 * Use this function to read the RX payload, the function will
 * stay in a while loop unless a RX payload is valid.
 *
 * @param *out_rx_pload The space to copy the RX payload.
  */
void epl_rf_en_wait_rcv_msg(unsigned char *out_rx_pload);

#endif

