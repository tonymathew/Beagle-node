/* ===================================================================================== *
 * Author(s): Tu Yi-Hsuan (cindyduh@nthu.us)                                             *
 *            Embedded Platform Lab, NTHU                                                *
 *                                                                                       *
 * Copyright (c) 2009 National Tsing Hua University (NTHU)                               *
 * Permission to copy, modify, and distribute this program is granted for noncommercial  *
 * purposes, provided the author(s) and copyright notice are retained.                   *
 * All other uses require explicit written permission from NTHU.                         *
 * ===================================================================================== */

/* epl_rf_en.c
 * ------------------------------------------------------------------------------------- *
 * Revision:
 * 		version 1.0	2009/02/03 = Tu Yi-Hsuan (cindyduh@nthu.us)
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

#include <EPL/epl_rf_en.h>
#include <HAL/hal_nrf_hw.h>
#include <HAL/hal_nrf.h>

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
void epl_rf_en_init(unsigned char in_channel, epl_rf_en_datarate_t in_datarate, char in_output_power, unsigned char in_auto_retr, unsigned int in_auto_retr_delay, char in_addr_width, epl_rf_en_crc_mode_t in_crc_mode, unsigned char in_rf_int)
{

	RFCKEN = 1;	// RF clock enable.

	CE_LOW();

	//--- Default static setup. These setting is optimized to match the RF protocol with nRF24E1. ---//
	hal_nrf_close_pipe(HAL_NRF_ALL); // Close all pipes first. By default, pipe0 and pipe1 are opened.

	hal_nrf_set_datarate(in_datarate);
	hal_nrf_set_auto_retr(in_auto_retr, in_auto_retr_delay); // First parameter is set to zero indicating the auto retransmission is off.
	hal_nrf_set_output_power(in_output_power); // Maximum radio output power (0dbm).
	hal_nrf_set_crc_mode(in_crc_mode);

	hal_nrf_set_address_width(in_addr_width); // Both RX and TX's address width are Configured.

	hal_nrf_set_operation_mode(HAL_NRF_PTX); // Enter RF TX mode

	hal_nrf_set_rf_channel(in_channel);
	hal_nrf_set_power_mode(HAL_NRF_PWR_UP); // Power up radio

	hal_nrf_get_clear_irq_flags();

	// IEN1 RF interrupt enable bit
	RF = in_rf_int;
}


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
void epl_rf_en_rcv_pipe_config(hal_nrf_address_t in_pipe_num, char *in_pipe_rcv_addr, unsigned char in_pipe_pload_length, epl_rf_en_auto_ack_t in_auto_ack) 
{
	hal_nrf_open_pipe(in_pipe_num, in_auto_ack); // Open pipe and configure the auto ack function.
	hal_nrf_set_address(in_pipe_num, in_pipe_rcv_addr); // Address for PRX pipe
	hal_nrf_set_rx_payload_width(in_pipe_num, in_pipe_pload_length);
}

/** Easy initialization for RF functions.
 * Use this function as a convenient way to initialize the RF as tx mode.
 * The default pipe is pipe0.
 *
 * @param channel RF channel, RF frequency = 2400 + channel (Hz)
 * @param auto_retr Number of retransmit, 0 equal retransmit OFF
 * @param delay Retransmit delay in us
 */
void epl_rf_en_easy_start_tx(unsigned char channel, unsigned char auto_retr, unsigned int delay){

	char my_tx_dst_addr[5] = {0x65,0x65,0x65,0x65,0x65};

	/* RF SFR configurations */
	epl_rf_en_init(channel,
			RF_EN_1MBPS,
			HAL_NRF_0DBM,
			auto_retr,
			delay,
			5,
			RF_EN_CRC_16BIT,
			RF_EN_INT_ENABLE);

	epl_rf_en_set_dst_addr(my_tx_dst_addr);

	if( auto_retr != 0){

		/* RF pipe configurations for auto ack*/
		epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE0,
							my_tx_dst_addr,
							8,
							RF_EN_AUTO_ACK_ON
							);
	}

	epl_rf_en_enter_tx_mode();
}

/** Easy initialization for RF functions.
 * Use this function as a convenient way to initialize the RF as rx mode.
 * The default pipe is pipe0.
 *
 * @param channel RF channel, RF frequency = 2400 + channel (Hz)
 * @param pload_len RX payload length for designated pipe.
 * @param auto_ack Auto ack bit
 */
void epl_rf_en_easy_start_rx(unsigned char channel, unsigned char pload_len, unsigned char auto_ack){

	char my_rx_dst_addr[5] = {0x65,0x65,0x65,0x65,0x65};

	/* RF SFR configurations */
	epl_rf_en_init(channel,
			RF_EN_1MBPS,
			HAL_NRF_0DBM,
			0,					//Ignore auto retransmission
			0,
			5,
			RF_EN_CRC_16BIT,
			RF_EN_INT_ENABLE);

	/* RF pipe configurations for auto ack*/
	epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE0,
							my_rx_dst_addr,
							pload_len,
							auto_ack
							);

	epl_rf_en_enter_rx_mode();
}

/** Quick initialization for RF functions.
 * Use this function as a convenient way to initialize the RF.
 * The default pipe is pipe0.
 *
 * @param *in_cfg A configuration structure to configure RF.
 */
/* The default pipe is pipe0. */
void epl_rf_en_quick_init(struct epl_lu1_rf_en_config *in_cfg)
{

	/* RF SFR configurations */
	epl_rf_en_init(in_cfg->channel,
			in_cfg->datarate,
			HAL_NRF_0DBM,
			in_cfg->auto_retr,
			in_cfg->auto_retr_delay,
			in_cfg->addr_width,
			in_cfg->crc_mode,
			RF_EN_INT_DISABLE);

	epl_rf_en_set_dst_addr(in_cfg->my_tx_dst_addr);


	/* RF pipe configurations */
	epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE0,
					   in_cfg->my_prx_addr,
					   in_cfg->data_length,
					   in_cfg->auto_ack
					   );
}

/** Switch RF mode to TX mode.
 * Use this function to switch the mode to TX mode.
 */
void epl_rf_en_enter_tx_mode(void)
{
	RFCE = 0;
	hal_nrf_set_operation_mode(HAL_NRF_PTX); // Enter RF TX mode
}

/** Switch RF mode to RX mode.
 * Use this function to switch the mode to RX mode.
 */
void epl_rf_en_enter_rx_mode(void)
{
	RFCE = 1;
	hal_nrf_set_operation_mode(HAL_NRF_PRX); // Enter RF RX mode
}

/** Configuring the PTX address (destination address).
 * Use this function to configure destination address.
 *
 * @param *in_dst_addr The destination address.
 */
void epl_rf_en_set_dst_addr(unsigned char *in_dst_addr)
{
	hal_nrf_set_address(HAL_NRF_TX, in_dst_addr); // Address for PTX (The address of destination.)
}

/** Send the RF packet to designated destination.
 * Use this function to send RF packet.
 *
 * @param *in_dst_addr The destination address.
 * @param *in_tx_pload The pointer point to the packet to be sent.
 * @param in_length The packet length.
 */
void epl_rf_en_send_dst(unsigned char *in_dst_addr, unsigned char *in_tx_pload, unsigned char in_pload_length)
{
	hal_nrf_set_address(HAL_NRF_TX, in_dst_addr); // Address for PTX (The address of destination.)
	epl_rf_en_enter_tx_mode();
	hal_nrf_write_tx_payload(in_tx_pload, in_pload_length);
	CE_PULSE();
}

/** Send the RF packet with the unchanged destination address.
 * Use this function to send RF packet with the last destination
 * address.
 *
 * @param *in_tx_pload The pointer point to the packet to be sent.
 * @param in_length The packet length.
 */
void epl_rf_en_send(unsigned char *in_tx_pload, unsigned char in_pload_length)
{
	epl_rf_en_enter_tx_mode();
	hal_nrf_write_tx_payload(in_tx_pload, in_pload_length);
	CE_PULSE();
}

/** Check the RX payload is empty or not.
 * Use this function to check the RX payload is empty or not.
 *
 * @param *in_tx_pload The pointer point to the packet to be sent.
 * @return True (1) for RX fifo empty or false for RX fifo not empty.
 */
unsigned char epl_rf_en_rx_pload_is_empty(void)
{
	unsigned char rx_fifo_status;
	rx_fifo_status = hal_nrf_get_rx_fifo_status();
	if (rx_fifo_status == 0x01)
	{
		return 1;	// RX fifo is empty.
	}
	else
	{// rx_fifo_status == 0x00 or 0x02
		return 0;	// RX fifo is not empty or is full.
	}
}

/** Read the RX payload.
 * Use this function to read the RX payload.
 *
 * @param *out_rx_pload The space to copy the RX payload.
  */
void epl_rf_en_read_rx_pload(unsigned char *out_rx_pload)
{
	hal_nrf_read_rx_payload(out_rx_pload);
	//or hal_nrf_read_multibyte_reg(UINT8(HAL_NRF_RX_PLOAD), out_rx_pload);
}

/** Wait until the RX payload is valid, and read the RX payload.
 * Use this function to read the RX payload, the function will
 * stay in a while loop unless a RX payload is valid.
 *
 * @param *out_rx_pload The space to copy the RX payload.
  */
void epl_rf_en_wait_rcv_msg(unsigned char *out_rx_pload)
{
	epl_rf_en_enter_rx_mode();
	while (epl_rf_en_rx_pload_is_empty());
	hal_nrf_read_rx_payload(out_rx_pload);
}

