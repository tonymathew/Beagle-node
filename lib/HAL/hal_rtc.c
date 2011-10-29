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
 * @brief Implementation of hal_rtc
 */

#include <Nordic\reg24le1.h>
#include <HAL/hal_rtc.h>
#include <HAL/nordic_common.h>

void hal_rtc_capture(void)
{
  RTC2CON |= BIT_4;                         // Set "sfrCapture" bit(Trig. sig.)
}

void hal_rtc_radio_capture_enable(bool en)
{
  if(en)
  {
    RTC2CON |= BIT_3;                       // Set "enableExtCapture" bit
  }
  else
  {
    RTC2CON &= ~BIT_3;                      // Clear "enableExtCapture" bit
  }
}

void hal_rtc_set_compare_mode(hal_rtc_compare_mode_t mode)
{
  RTC2CON = (RTC2CON & 0xF9) | ((mode << 1) & ~0xF9); // Set "compareMode" bits
}

void hal_rtc_start(bool en)
{
  if(en)
  { 
    RTC2CON |= BIT_0;                       // Set "rtc2Enable" bit
  }
  else
  {
    RTC2CON &= ~BIT_0;                      // Clear "rtc2Enable" bit
  }
}

void hal_rtc_set_compare_value(unsigned int value)
{
  unsigned char compare_status;                   
  compare_status = (RTC2CON & (BIT_1 | BIT_2)); // Save "compareMode" bits
  RTC2CON &= ~(BIT_1 | BIT_2);              // Disable compare
  RTC2CMP0 = LSB(value);                    // Write LSB
  RTC2CMP1 = MSB(value);                    // Write MSB
  RTC2CON |= compare_status;                // Update compare status 
}

unsigned int hal_rtc_get_compare_value(void)
{
  unsigned char compare_status;  
  unsigned int value;                           // Create temporary output variable
  compare_status = (RTC2CON & (BIT_1 | BIT_2)); // Save "compareMode" bits
  RTC2CON &= ~(BIT_1 | BIT_2);              // Disable compare
  value = RTC2CMP1;                         // Read MSB
  value <<= 8;                              // Shift to correct position
  value |= RTC2CMP0;                        // Add LSB
  RTC2CON |= compare_status;                // Update compare status 
  return value;                             // Return compare value
}

unsigned int hal_rtc_get_capture_value(void)
{
  unsigned char capture_status;                 
  unsigned int value;                           // Create temporary output variable
  capture_status = (RTC2CON & BIT_3);       // Save "compareMode" bits
  RTC2CON &= ~BIT_3;                        // Disable compare
  value = RTC2CPT01;                        // Read MSB
  value <<= 8;                              // Shift to correct position
  value |= RTC2CPT00;                       // Add LSB
  RTC2CON |= capture_status;                // Update external capture status
  return value;                             // Return timer value
}

unsigned char hal_rtc_get_capture_clock_cycles(void)
{
  return RTC2CPT10;                         // Return register
}