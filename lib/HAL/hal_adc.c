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
 * @brief Implementation of hal_adc
 */

#include <stdint.h>
#include <stdbool.h>

#include <Nordic/reg24le1.h>
#include <HAL/nordic_common.h>
#include <HAL/hal_adc.h>


void hal_adc_set_input_channel(hal_adc_input_channel_t chsel)
{ // Update "chsel" bits
  ADCCON1 = ((ADCCON1 & 0xC3) | (((unsigned char)(chsel) << 2) & ~0xC3));       
}


void hal_adc_set_reference(hal_adc_reference_t refsel)
{ // Update "refsel" bits
  ADCCON1 = ((ADCCON1 & 0xFC) | (((unsigned char)(refsel)) & ~0xFC));             
}


void hal_adc_set_input_mode(hal_adc_input_mode_t input_mode)
{ // Update "diffm" bits
  ADCCON2 = ((ADCCON2 & 0x3F) | ((unsigned char)(input_mode) << 6));  
}


void hal_adc_set_conversion_mode(hal_adc_conversion_mode_t conv_mode)
{ // Update "cont" bit
  ADCCON2 = ((ADCCON2 & 0xDF) | (((unsigned char)(conv_mode) << 5) & ~0xDF));   
}


void hal_adc_set_sampling_rate(hal_adc_sampling_rate_t rate)
{ // Update "rate" bits
  ADCCON2 = ((ADCCON2 & 0xE3) | (((unsigned char)(rate) << 2) & ~0xE3));        
}


void hal_adc_set_power_down_delay(hal_adc_power_down_delay_t pdd)
{ // Update "rate" bits
  ADCCON2 = ((ADCCON2 & 0xE3) | (((unsigned char)(pdd) << 2) & ~0xE3));        
}


void hal_adc_set_acq_window(hal_adc_acq_window_t tacq)
{ // Update "tacq" bits
  ADCCON2 = ((ADCCON2 & 0xFC) | (((unsigned char)(tacq)) & ~0xFC));               
}


void hal_adc_set_resolution(hal_adc_resolution_t res)
{ // Update "resol" bits
  ADCCON3 = ((ADCCON3 & 0x3F) | ((unsigned char)(res) << 6));         
}


void hal_adc_set_data_just(hal_adc_data_just_t just)
{ // Update "rljust" bit
  ADCCON3 = ((ADCCON3 & 0xDF) | (((unsigned char)(just) << 5) & ~0xDF));      
}


void hal_adc_start(void)
{
  unsigned char cnt = ADC_STARTUP_CNT;             // Get the counter value
  ADCCON1 = ADCCON1 | BIT_7;                 // Set "pwrup" bit
   
  while(cnt--);                              // Wait for busy bit to stabilize
}


unsigned char hal_adc_read_LSB(void)
{
  return ADCDATL;                            // Return value stored in ADCDATL
}

unsigned char hal_adc_read_MSB(void)
{
  return ADCDATH;                            // Return value stored in ADCDATH
}

unsigned char hal_adc_busy(void)
{
  return ((ADCCON1 & BIT_6) > 0);            // Return status of "busy" bit  
}
                                                                               
hal_adc_overflow_t hal_adc_get_overflow_status(void)
{
  return (hal_adc_overflow_t)((ADCCON3 & (BIT_3 | BIT_4)) >> 3); 
}                                            // Return status bits from ADCCON3