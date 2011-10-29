/* Copyright (c) 2007 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT. 
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRENTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 * $LastChangedRevision: 4386 $
 */ 

 /** @file
  * @brief Implementation of hal_nrf
 */
/*lint -t2 */
/*lint -esym( 534, hal_nrf_write_reg ) */
/*lint -esym( 534, hal_nrf_rw ) */
/*lint -e708 */
/*lint -e46 */

#include <stdint.h>
#include <stdbool.h>

#include <HAL/nordic_common.h>
#include <HAL/hal_nrf.h>

#define SET_BIT(pos) ((unsigned char) (1<<( (unsigned char) (pos) )))
#define UINT8(t) ((unsigned char) (t))

/** Basis function read_reg.
 * Use this function to read the contents
 * of one radios register.
 *
 * @param reg Register to read
 * @return Register contents
*/
unsigned char hal_nrf_read_reg(unsigned char reg);

/** Basis function write_reg.
 * Use this function to write a new value to
 * a radio register.
 *
 * @param reg Register to write
 * @param value New value to write
 * @return Status register
*/
unsigned char hal_nrf_write_reg(unsigned char reg, unsigned char value);

/** Basis function, read_multibyte register .
 * Use this function to read multiple bytes from
 * a multibyte radio-register
 *
 * @param reg Multibyte register to read from
 * @param *pbuf Pointer to buffer in which to store read bytes to
 *
 * @return pipe# of received data (MSB), if operation used by a hal_nrf_read_rx_pload
 * @return length of read data (LSB), either for hal_nrf_read_rx_pload or
 * for hal_nrf_get_address.
*/
unsigned int hal_nrf_read_multibyte_reg(unsigned char reg, unsigned char *pbuf);

/** Basis function, write_multibyte register.
 * Use this function to write multiple bytes to
 * a multiple radio register.
 *
 * @param reg Register to write
 * @param *pbuf pointer to buffer in which data to write is
 * @param length \# of bytes to write
*/
void hal_nrf_write_multibyte_reg(unsigned char reg, const unsigned char *pbuf, unsigned char length);

/**
 * Typedef for the CONFIG register. Contains all the bitaddressable 
 * settings in the bits struct and the value sent to the radio in the unsigned char
 */
typedef union {
  unsigned char value;
	struct {
		unsigned char prim_rx : 1;
		unsigned char pwr_up : 1;
		unsigned char crc0 : 1;
		unsigned char en_crc : 1;
		unsigned char mask_max_rt : 1;
		unsigned char mask_tx_ds : 1;
		unsigned char mask_rx_dr : 1;
		const unsigned char : 1;
	} bits;
} config_t;

/**
 * Typedef for the EN_AA, EN_RXADDR and DYNPD registers. Contains all the 
 * bitaddressable settings in the bits struct and the value sent to the radio 
 * in the unsigned char 
 */
typedef union {
  unsigned char value;
  struct {
    unsigned char pipe_0 : 1;
    unsigned char pipe_1 : 1;
    unsigned char pipe_2 : 1;
    unsigned char pipe_3 : 1;
    unsigned char pipe_4 : 1;
    unsigned char pipe_5 : 1;
    const unsigned char : 2;
  } bits;
} en_pipes_t;

/**
 * Typedef for the SETUP_AW register. Contains all the bitaddressable 
 * settings in the bits struct and the value sent to the radio in the unsigned char
 */
typedef union {
  unsigned char value;
	struct {
		unsigned char aw : 2;
		const unsigned char : 6;		
	} bits;
} setup_aw_t;

/**
 * Typedef for the SETUP_RETR register. Contains all the bitaddressable 
 * settings in the bits struct and the value sent to the radio in the unsigned char
 */
typedef union {
  unsigned char value;
	struct {
		unsigned char arc : 4;
		unsigned char ard : 4;
	} bits;
} setup_retr_t;

/**
 * Typedef for the RF_CH register. Contains all the bitaddressable 
 * settings in the bits struct and the value sent to the radio in the unsigned char
 */
typedef union {
  unsigned char value;
	struct {
		unsigned char rf_ch : 7;
		const unsigned char : 1;
	} bits;
} rf_ch_t;

/**
 * Typedef for the RF_SETUP register. Contains all the bitaddressable 
 * settings in the bits struct and the value sent to the radio in the unsigned char
 */
typedef union {
  unsigned char value;
	struct {
		const unsigned char : 1;
		unsigned char rf_pwr : 2;
		unsigned char rf_dr_high : 1;
		unsigned char pll_lock : 1;
		unsigned char rf_dr_low : 1;
    const unsigned char : 1;
    unsigned char cont_wave : 1;
	} bits;
} rf_setup_t;

/**
 * Typedef for the RX_PW_Px registers. Contains all the bitaddressable 
 * settings in the bits struct and the value sent to the radio in the unsigned char
 */
typedef union {
  unsigned char value;
	struct {
		unsigned char rx_pw : 6;
		const unsigned char : 2;
	} bits;
} rx_pw_t;

/**
 * Typedef for the FEATURE register. Contains all the bitaddressable 
 * settings in the bits struct and the value sent to the radio in the unsigned char
 */
typedef union {
  unsigned char value;
	struct {
		unsigned char en_dyn_ack : 1;
		unsigned char en_ack_pay : 1;
		unsigned char en_dpl : 1;
		const unsigned char : 5;
	} bits;
} feature_t;

/**
 * Typedef for the AGC_CONFIG register. Contains all the bitaddressable 
 * settings in the bits struct and the value sent to the radio in the unsigned char
 */
typedef union {
  unsigned int value;
  struct {
    unsigned char lnb_out : 3;
    unsigned char lnb_in : 3;
    unsigned char agc_en : 1;
    unsigned char agc_th1mbit : 3;
    unsigned char agc_th2mbit : 3;
    unsigned char cd_th : 3;
  } bits;
} agc_config_t;

/** Content of the CONFIG register */
//static config_t config;
/** Content of the EN_AA register */
//static en_pipes_t en_aa;
/** Content of the EN_RXADDR register */
//static en_pipes_t en_rxaddr;
/** Content of the SETUP_AW register */
//static setup_aw_t setup_aw;
/** Content of the SETUP_RETR register */
//static setup_retr_t setup_retr;
/** Content of the RF_CH register */
//static rf_ch_t rf_ch;
/** Content of the RF_SETUP register */
//static rf_setup_t rf_setup;
/** Content of the RX_PW_P0 register */
//static rx_pw_t rx_pw_px;
/** Content of the DYNPD register */
//static en_pipes_t dynpd;
/** Content of the FEATURE register */
//static feature_t feature;
/** Content of the AGC_CONFIG register */
//static agc_config_t agc_config;

void hal_nrf_set_operation_mode(hal_nrf_operation_mode_t op_mode)
{
  config_t config;
  config.value = hal_nrf_read_reg (CONFIG);

  if(op_mode == HAL_NRF_PRX)
  {
    config.bits.prim_rx = 1;
  }
  else
  {
    config.bits.prim_rx = 0;
  }

  hal_nrf_write_reg (CONFIG, config.value);
}

void hal_nrf_set_power_mode(hal_nrf_pwr_mode_t pwr_mode)
{
  config_t config;
  config.value = hal_nrf_read_reg (CONFIG);

  if(pwr_mode == HAL_NRF_PWR_UP)
  {
    config.bits.pwr_up = 1;
  }
  else
  {
    config.bits.pwr_up = 0;
  }
  
  hal_nrf_write_reg (CONFIG, config.value);
}

void hal_nrf_set_crc_mode(hal_nrf_crc_mode_t crc_mode)
{
  config_t config;
  config.value = hal_nrf_read_reg (CONFIG);

	switch (crc_mode)
	{
		case HAL_NRF_CRC_OFF:
			config.bits.en_crc = 0;
			break;
		case HAL_NRF_CRC_8BIT:
			config.bits.en_crc = 1;
			config.bits.crc0 = 0;
			break;
		case HAL_NRF_CRC_16BIT:
			config.bits.en_crc = 1;
			config.bits.crc0 = 1;
			break;
		default:
			break;
	} 

  hal_nrf_write_reg (CONFIG, config.value);
}

void hal_nrf_set_irq_mode(hal_nrf_irq_source_t int_source, unsigned char irq_state)
{
  config_t config;
  config.value = hal_nrf_read_reg (CONFIG);

	switch (int_source)
	{
		case HAL_NRF_MAX_RT:
			config.bits.mask_max_rt = irq_state ? 0 : 1;
      break;
    case HAL_NRF_TX_DS:
      config.bits.mask_tx_ds = irq_state ? 0 : 1;
      break;
    case HAL_NRF_RX_DR:
      config.bits.mask_rx_dr = irq_state ? 0 : 1;
      break;
  }
  
  hal_nrf_write_reg (CONFIG, config.value);
}

unsigned char hal_nrf_get_clear_irq_flags(void)
{
  unsigned char retval;
  
  retval = hal_nrf_write_reg (STATUS, (BIT_6|BIT_5|BIT_4));

  return (retval & (BIT_6|BIT_5|BIT_4));
}

void hal_nrf_clear_irq_flag(hal_nrf_irq_source_t int_source)
{
  hal_nrf_write_reg (STATUS, SET_BIT(int_source));
}

unsigned char hal_nrf_get_irq_flags(void)
{
  return hal_nrf_nop() & (BIT_6|BIT_5|BIT_4);
}

void hal_nrf_open_pipe(hal_nrf_address_t pipe_num, unsigned char auto_ack)
{
  en_pipes_t en_rxaddr;
  en_pipes_t en_aa;
  en_rxaddr.value = hal_nrf_read_reg (EN_RXADDR);
  en_aa.value = hal_nrf_read_reg (EN_AA);

  switch(pipe_num)
  {
    case HAL_NRF_PIPE0:
    case HAL_NRF_PIPE1:
    case HAL_NRF_PIPE2:
    case HAL_NRF_PIPE3:
    case HAL_NRF_PIPE4:
    case HAL_NRF_PIPE5:
      en_rxaddr.value = en_rxaddr.value | SET_BIT(pipe_num);

      if(auto_ack)
      {
        en_aa.value = en_aa.value | SET_BIT(pipe_num);
      }
      else
      {
        en_aa.value = en_aa.value & ~SET_BIT(pipe_num);
      }
      break;

    case HAL_NRF_ALL:
      en_rxaddr.value = ~(BIT_6|BIT_7);
      
      if(auto_ack)
      {
        en_aa.value = ~(BIT_6|BIT_7);
      }
      else
      {
        en_aa.value = 0;
      }
      break;
      
    default:
      break;
  }

  hal_nrf_write_reg (EN_RXADDR, en_rxaddr.value);
  hal_nrf_write_reg (EN_AA, en_aa.value);
}

void hal_nrf_close_pipe(hal_nrf_address_t pipe_num)
{
  en_pipes_t en_rxaddr;
  en_pipes_t en_aa;
  en_rxaddr.value = hal_nrf_read_reg (EN_RXADDR);
  en_aa.value = hal_nrf_read_reg (EN_AA);

  switch(pipe_num)
  {
    case HAL_NRF_PIPE0:
    case HAL_NRF_PIPE1:
    case HAL_NRF_PIPE2:
    case HAL_NRF_PIPE3:
    case HAL_NRF_PIPE4:
    case HAL_NRF_PIPE5:
      en_rxaddr.value = en_rxaddr.value & ~SET_BIT(pipe_num);
      en_aa.value = en_aa.value & ~SET_BIT(pipe_num);
      break;
    
    case HAL_NRF_ALL:
      en_rxaddr.value = 0;
      en_aa.value = 0;
      break;
      
    default:
      break;
  }

  hal_nrf_write_reg (EN_RXADDR, en_rxaddr.value);
  hal_nrf_write_reg (EN_AA, en_aa.value);
}

void hal_nrf_set_address(const hal_nrf_address_t address, const unsigned char *addr)
{
  switch(address)
  {
    case HAL_NRF_TX:
    case HAL_NRF_PIPE0:
    case HAL_NRF_PIPE1:
      hal_nrf_write_multibyte_reg(W_REGISTER + RX_ADDR_P0 + (unsigned char) address, addr, hal_nrf_get_address_width());
      break;
    case HAL_NRF_PIPE2:
    case HAL_NRF_PIPE3:
    case HAL_NRF_PIPE4:
    case HAL_NRF_PIPE5:
      hal_nrf_write_reg (RX_ADDR_P0 + (unsigned char) address, *addr);
      break;

    default:
      break;
  }
}

unsigned char hal_nrf_get_address(unsigned char address, unsigned char *addr)
{
  switch (address)
  {
    case HAL_NRF_PIPE0:
    case HAL_NRF_PIPE1:
    case HAL_NRF_TX:
      return hal_nrf_read_multibyte_reg (address, addr);
    default:
      *addr = hal_nrf_read_reg(RX_ADDR_P0 + address);
      return 1;
  }
}

void hal_nrf_set_auto_retr(unsigned char retr, unsigned int delay)
{
  setup_retr_t setup_retr;
  setup_retr.bits.ard = (delay / 250) - 1;
  setup_retr.bits.arc = retr;

  hal_nrf_write_reg (SETUP_RETR, setup_retr.value);
}

void hal_nrf_set_address_width(hal_nrf_address_width_t aw)
{
  setup_aw_t setup_aw;
  setup_aw.bits.aw = (unsigned char)aw - 2;

  hal_nrf_write_reg (SETUP_AW, setup_aw.value);
}

unsigned char hal_nrf_get_address_width (void)
{
  return hal_nrf_read_reg (SETUP_AW) + 2;
}

void hal_nrf_set_rx_payload_width(unsigned char pipe_num, unsigned char pload_width)
{
  hal_nrf_write_reg (RX_PW_P0 + pipe_num, pload_width);
}

unsigned char hal_nrf_get_pipe_status(unsigned char pipe_num)
{
  en_pipes_t en_rxaddr;
  en_pipes_t en_aa;
  unsigned char en_rx_r, en_aa_r;
  
  en_rxaddr.value = hal_nrf_read_reg (EN_RXADDR);
  en_aa.value = hal_nrf_read_reg (EN_AA);

  switch (pipe_num)
  {
    case 0:
      en_rx_r = en_rxaddr.bits.pipe_0;
      en_aa_r = en_aa.bits.pipe_0;
      break;
    case 1:
      en_rx_r = en_rxaddr.bits.pipe_1;
      en_aa_r = en_aa.bits.pipe_1;
      break;
    case 2:
      en_rx_r = en_rxaddr.bits.pipe_2;
      en_aa_r = en_aa.bits.pipe_2;
      break;
    case 3:
      en_rx_r = en_rxaddr.bits.pipe_3;
      en_aa_r = en_aa.bits.pipe_3;
      break;
    case 4:
      en_rx_r = en_rxaddr.bits.pipe_4;
      en_aa_r = en_aa.bits.pipe_4;
      break;
    case 5:
      en_rx_r = en_rxaddr.bits.pipe_5;
      en_aa_r = en_aa.bits.pipe_5;
      break;
    default:
      en_rx_r = 0;
      en_aa_r = 0;
      break;
  }
  
  return (unsigned char)(en_aa_r << 1) + en_rx_r;
}


unsigned char hal_nrf_get_auto_retr_status(void)
{
  return hal_nrf_read_reg(OBSERVE_TX);
}

unsigned char hal_nrf_get_packet_lost_ctr(void)
{
  return ((hal_nrf_read_reg(OBSERVE_TX) & (BIT_7|BIT_6|BIT_5|BIT_4)) >> 4);
}

unsigned char hal_nrf_get_rx_payload_width(unsigned char pipe_num)
{
  unsigned char pw;

  switch (pipe_num)
  {
    case 0:
      pw = hal_nrf_read_reg (RX_PW_P0);
      break;      
    case 1:
      pw = hal_nrf_read_reg (RX_PW_P1);
      break;
    case 2:
      pw = hal_nrf_read_reg (RX_PW_P2);
      break;
    case 3:
      pw = hal_nrf_read_reg (RX_PW_P3);
      break;
    case 4:
      pw = hal_nrf_read_reg (RX_PW_P4);
      break;
    case 5:
      pw = hal_nrf_read_reg (RX_PW_P5);
      break;
    default:
      pw = 0;
      break;
  }

  return pw;
}

void hal_nrf_set_rf_channel(unsigned char channel)
{
  rf_ch_t rf_ch;
  rf_ch.bits.rf_ch = channel;
  
  hal_nrf_write_reg (RF_CH, rf_ch.value);
}

void hal_nrf_set_output_power(hal_nrf_output_power_t power)
{
  rf_setup_t rf_setup;
  rf_setup.value = hal_nrf_read_reg (RF_SETUP);

  rf_setup.bits.rf_pwr = (unsigned char)power;
  
  hal_nrf_write_reg (RF_SETUP, rf_setup.value);
}

void hal_nrf_set_datarate(hal_nrf_datarate_t datarate)
{
  rf_setup_t rf_setup;
  rf_setup.value = hal_nrf_read_reg (RF_SETUP);
  
  switch (datarate)
  {
    case HAL_NRF_250KBPS:
      rf_setup.bits.rf_dr_low = 1;
      rf_setup.bits.rf_dr_high = 0;
      break;
    case HAL_NRF_1MBPS:
      rf_setup.bits.rf_dr_low = 0;
      rf_setup.bits.rf_dr_high = 0;
      break;
    case HAL_NRF_2MBPS:
    default:
      rf_setup.bits.rf_dr_low = 0;
      rf_setup.bits.rf_dr_high = 1;
      break;
  }
  
  hal_nrf_write_reg (RF_SETUP, rf_setup.value);
}

unsigned char hal_nrf_rx_fifo_empty(void)
{
  if(hal_nrf_get_rx_data_source()==7)
  {
    return true;
  }
  else
  {
    return false;
  }
}

unsigned char hal_nrf_rx_fifo_full(void)
{
  return (unsigned char)((hal_nrf_read_reg(FIFO_STATUS)>> RX_EMPTY) & 1);
}

unsigned char hal_nrf_tx_fifo_empty(void)
{
  return (unsigned char)((hal_nrf_read_reg(FIFO_STATUS) >> TX_EMPTY) & 1);
}

unsigned char hal_nrf_tx_fifo_full(void)
{
  return (unsigned char)((hal_nrf_read_reg(FIFO_STATUS) >> TX_FIFO_FULL) & 1);
}

unsigned char hal_nrf_get_tx_fifo_status(void)
{
  return ((hal_nrf_read_reg(FIFO_STATUS) & ((1<<TX_FIFO_FULL)|(1<<TX_EMPTY))) >> 4);
}

unsigned char hal_nrf_get_rx_fifo_status(void)
{
  return (hal_nrf_read_reg(FIFO_STATUS) & ((1<<RX_FULL)|(1<<RX_EMPTY)));
}

unsigned char hal_nrf_get_fifo_status(void)
{
  return hal_nrf_read_reg(FIFO_STATUS);
}

unsigned char hal_nrf_get_transmit_attempts(void)
{
  return (hal_nrf_read_reg(OBSERVE_TX) & (BIT_3|BIT_2|BIT_1|BIT_0));
}

unsigned char hal_nrf_get_carrier_detect(void)
{
  return hal_nrf_read_reg(CD) & 1;
}

void hal_nrf_activate_features(void)
{return;}

void hal_nrf_setup_dynamic_payload (unsigned char setup)
{
  en_pipes_t dynpd;
  dynpd.value = setup & ~0xC0;

  hal_nrf_write_reg (DYNPD, dynpd.value);
}

void hal_nrf_enable_dynamic_payload(unsigned char enable)
{
  feature_t feature;
  feature.value = hal_nrf_read_reg (FEATURE);
  feature.bits.en_dpl = (enable) ? 1 : 0;

  hal_nrf_write_reg (FEATURE, feature.value);
}

void hal_nrf_enable_ack_payload(unsigned char enable)
{
  feature_t feature;
  feature.value = hal_nrf_read_reg (FEATURE);
  feature.bits.en_ack_pay = (enable) ? 1 : 0;

  hal_nrf_write_reg (FEATURE, feature.value);
}

void hal_nrf_enable_dynamic_ack(unsigned char enable)
{
  feature_t feature;
  feature.value = hal_nrf_read_reg (FEATURE);
  feature.bits.en_dyn_ack = (enable) ? 1 : 0;

  hal_nrf_write_reg (FEATURE, feature.value);
}

void hal_nrf_write_tx_payload(const unsigned char *tx_pload, unsigned char length)
{
  hal_nrf_write_multibyte_reg(W_TX_PAYLOAD, tx_pload, length);
}

void hal_nrf_write_tx_payload_noack(const unsigned char *tx_pload, unsigned char length)
{
  hal_nrf_write_multibyte_reg(W_TX_PAYLOAD_NOACK, tx_pload, length);
}

void hal_nrf_write_ack_payload(unsigned char pipe, const unsigned char *tx_pload, unsigned char length)
{
  hal_nrf_write_multibyte_reg(W_ACK_PAYLOAD | pipe, tx_pload, length);
}

unsigned char hal_nrf_read_rx_payload_width()
{
  return hal_nrf_read_reg(R_RX_PL_WID);
}

unsigned int hal_nrf_read_rx_payload(unsigned char *rx_pload)
{
  return hal_nrf_read_multibyte_reg(UINT8(HAL_NRF_RX_PLOAD), rx_pload);
}

unsigned char hal_nrf_get_rx_data_source(void)
{
  return ((hal_nrf_nop() & (BIT_3|BIT_2|BIT_1)) >> 1);
}

void hal_nrf_reuse_tx(void)
{
  CSN_LOW();
  hal_nrf_rw(REUSE_TX_PL);
  CSN_HIGH();
}

unsigned char hal_nrf_get_reuse_tx_status(void)
{
  return (unsigned char)((hal_nrf_get_fifo_status() & (1<<TX_REUSE)) >> TX_REUSE);
}

void hal_nrf_flush_rx(void)
{
  CSN_LOW();
  hal_nrf_rw(FLUSH_RX);
  CSN_HIGH();
}

void hal_nrf_flush_tx(void)
{
  CSN_LOW();
  hal_nrf_rw(FLUSH_TX);
  CSN_HIGH();
}

unsigned char hal_nrf_nop(void)
{
  unsigned char retval;

  CSN_LOW();
  retval = hal_nrf_rw(NOP);
  CSN_HIGH();

  return retval;
}

void hal_nrf_set_pll_mode(unsigned char pll_lock)
{
  rf_setup_t rf_setup;
  rf_setup.value = hal_nrf_read_reg (RF_SETUP);
  rf_setup.bits.pll_lock = (pll_lock) ? 1 : 0;

  hal_nrf_write_reg(RF_SETUP, rf_setup.value);
}

unsigned char hal_nrf_get_rssi(void)
{
  agc_config_t agc_config;
  unsigned char value[2];
  hal_nrf_read_multibyte_reg(AGC_CONFIG, value);
  agc_config.value = ((value[1]) | (value[0] << 8));
  return UINT8(agc_config.bits.lnb_out);
}

void hal_nrf_enable_continious_wave (unsigned char enable)
{
  rf_setup_t rf_setup;
  rf_setup.value = hal_nrf_read_reg (RF_SETUP);
  rf_setup.bits.cont_wave = (enable ? 1 : 0);

  hal_nrf_write_reg(RF_SETUP, rf_setup.value);
}

unsigned char hal_nrf_read_reg(unsigned char reg)
{
  unsigned char temp;

  CSN_LOW();
  hal_nrf_rw(reg);
  temp = hal_nrf_rw(0);
  CSN_HIGH();

  return temp;
}

unsigned char hal_nrf_write_reg(unsigned char reg, unsigned char value)
{
  unsigned char retval;
  
  CSN_LOW();
  retval = hal_nrf_rw(W_REGISTER + reg);
  hal_nrf_rw(value);
  CSN_HIGH();

  return retval;
}

unsigned int hal_nrf_read_multibyte_reg(unsigned char reg, unsigned char *pbuf)
{
  unsigned char ctr, length;
  switch(reg)
  {
    case HAL_NRF_PIPE0:
    case HAL_NRF_PIPE1:
    case HAL_NRF_TX:
      length = ctr = hal_nrf_get_address_width();
      CSN_LOW();
      hal_nrf_rw(RX_ADDR_P0 + reg);
      break;
      
    case HAL_NRF_RX_PLOAD:
      if( (reg = hal_nrf_get_rx_data_source()) < 7)
      {
        length = ctr = hal_nrf_read_rx_payload_width();

        CSN_LOW();
        hal_nrf_rw(R_RX_PAYLOAD);
      }
      else
      {
       ctr = length = 0;
      }
      break;

    case AGC_CONFIG:
      ctr = length = 2;
      CSN_LOW();
      hal_nrf_rw (AGC_CONFIG);
      break;

    default:
      ctr = length = 0;
      break;
  }

  while(ctr--)
  {
    *pbuf++ = hal_nrf_rw(0);
  }

  CSN_HIGH();

  return (((unsigned int) reg << 8) | length);
}

void hal_nrf_write_multibyte_reg(unsigned char cmd, const unsigned char *pbuf, unsigned char length)
{
  CSN_LOW();

  hal_nrf_rw(cmd);

  while(length--)
  {
    hal_nrf_rw(*pbuf++);
  }

  CSN_HIGH();
}
