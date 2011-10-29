/** @file
 *
 * Header file defining hardware dependent functions for nRF24LE1.
 *
 * @addtogroup nordic_hal_nrf
 *
 * @{
 * @name Hardware dependencies
 * @{
 *
 */

#ifndef _HAL_NRF_LE1_H_
#define _HAL_NRF_LE1_H_

#include <Nordic/reg24le1.h>

/** Macro that set radio's CSN line LOW.
 *
 */
#define CSN_LOW() do { RFCSN = 0; } while(0)

/** Macro that set radio's CSN line HIGH.
 *
 */
#define CSN_HIGH() do { RFCSN = 1; } while(0)

/** Macro that set radio's CE line LOW.
 *
 */
#define CE_LOW() do { RFCE = 0;} while(0)

/** Macro that set radio's CE line HIGH.
 *
 */
#define CE_HIGH() do { RFCE = 1;} while(0)

/**
 * Pulses the CE to nRF24L01p for at least 10 us
 */
#define CE_PULSE() do { \
  unsigned char count; \
  count = 20; \
  CE_HIGH();  \
  while(count--) \
    ; \
  CE_LOW();  \
  } while(0)

#endif

/** @} */
/** @} */
