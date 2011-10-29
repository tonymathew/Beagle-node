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
 * @brief Implementation of hal_clk 
 */

#include <stdint.h>
#include <stdbool.h>

#include <Nordic/reg24le1.h>
#include <HAL/hal_clk.h>

void hal_clk_regret_xosc16m_on(bool on)
{
  if(on)
  {
    CLKCTRL = (CLKCTRL | 0x80) & ~0x08;   // & ~0x08 to prevent writing 1 to this bit 
  }
  else
  {
    CLKCTRL = CLKCTRL & ~0x88;            // & ~0x08 to prevent writing 1 to this bit
  }
}

void hal_clk_set_input(hal_clk_input_t input)
{
  CLKCTRL = (CLKCTRL & ~0x48) | ((input & 0x01) << 6); 
}

void hal_clk_set_16m_source(hal_clk_source_t source)
{
  CLKCTRL = ((CLKCTRL & ~0x38) | ((source & 0x03) << 4));
}

hal_clk_source_t hal_clk_get_16m_source()
{
  if(CLKCTRL & 0x08)
  {
    return HAL_CLK_XOSC16M;
  }
  else
  {
    return HAL_CLK_RCOSC16M;
  }
}

void hal_clk_set_freq(hal_clk_freq_t freq)
{
  CLKCTRL = ((CLKCTRL & ~0x0F) | (freq & 0x07)); // & ~0x08 to prevent writing 1 to this bit
}

bool hal_clklf_phase()
{
  return((CLKLFCTRL & 0x80) > 0);
}

bool hal_clklf_ready()
{
  return((CLKLFCTRL & 0x40) > 0);
}

void hal_clklf_set_source(hal_clklf_source_t source)
{
  CLKLFCTRL = (CLKLFCTRL & ~0x07) | (source & 0x07);
}