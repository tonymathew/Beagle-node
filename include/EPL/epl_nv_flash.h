#ifndef EPL_NV_FLASH_H_
#define EPL_NV_FLASH_H_

#include <stdint.h>

#define HAL_DATA_NV_BASE_ADDRESS 0xFA00

/** Function to erase a page in the NV Flash memory
 *  @param pn Page number
 */
void epl_nv_flash_page_erase(uint8_t pn);

/** Function to write a byte to the NV Flash memory
 *  @param a 16 bit address in Flash
 *  @param b byte to write
 */
void epl_nv_flash_byte_write(uint16_t a, uint8_t b);

/** Function to write n bytes to the NV Flash memory
 *  @param a 16 bit address in Flash
 *  @param *p pointer to bytes to write
 *  @param n number of bytes to write
 */
void epl_nv_flash_bytes_write(uint16_t a, uint8_t *p, uint16_t n);

/** Function to read a byte from the NV Flash memory
 *  @param a 16 bit address in Flash
 *  @return the byte read
 */
uint8_t epl_nv_flash_byte_read(uint16_t a);

/** Function to read n bytes from the NV Flash memory
 *  @param a 16 bit address in Flash
 *  @param *p pointer to bytes to write
 *  @param n number of bytes to read
 */
void epl_nv_flash_bytes_read(uint16_t a, uint8_t *p, uint16_t n);

#endif /*EPL_NV_FLASH_H_*/
