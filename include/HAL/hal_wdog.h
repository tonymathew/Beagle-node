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
 * @brief Interface for hal_wdog
 *
 * @defgroup arch_nrf24le1_hal_wdog hal_wdog
 * @{
 * @ingroup arch_nrf24le1
 *
 * @brief Interface functions for the watchdog
 *
 * The on-chip watchdog counter is intended to force a system reset if the software hangs.
 * This module contains functions for initializing and enabling the watchdog, reloading 
 * the watchdog ("kicking the dog") and for reading the current watchdog counter value.
 */


#ifndef HAL_WDOG_H__
#define HAL_WDOG_H__

#include <stdint.h>
#include <stdbool.h>


/** Function to initialize and enable the watch dog.
 *
 * @remark Remember to enable the low frequency clock before use
 * @param start_value The value to load into the watch dog counter.
 */
void hal_wdog_init(uint16_t start_value);

/** Function to reload the watch dog.
 * This function reloads the watch dog counter with the parameter given in the
 * hal_wdog_init function.
 */
void hal_wdog_restart(void);

#endif // HAL_WDOG_H__
/** @} */

