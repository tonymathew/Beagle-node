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
  * @brief Implementation of hal_wdog
 */

#include <stdint.h>
#include <stdbool.h>

#include <Nordic/reg24le1.h>
#include <HAL/nordic_common.h>
#include <HAL/hal_wdog.h>

void hal_wdog_init(uint16_t start_value)
{
  WDSV = LSB(start_value);      // Write the 8 LSB to the WD counter
  WDSV = MSB(start_value);      // Write the 8 MSB to the WD counter
}

void hal_wdog_restart(void)
{
  uint8_t wd_msb, wd_lsb;

  wd_lsb = WDSV;
  wd_msb = WDSV;

  WDSV = wd_lsb;           // Write the 8 LSB to the WD counter
  WDSV = wd_msb;           // Write the 8 MSB to the WD counter
}