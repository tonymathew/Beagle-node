/** @file
 * Interface functions for the UART serial interface (without interrupt version)
 *
 * @author Jackal Chen <wtg.design@gmail.com>
 * this lib is the non-interrupt version of uart driver for LU1
`* if you need the interrupt version for better perfromance, please use HAL/hal_uart.h
 *
 * version 1.0 at 2008/04/04 by Jackal
 */

#ifndef EPL_UART_H__
#define EPL_UART_H__

#include <stdint.h>

typedef enum
{
    UART_BAUD_9K6,      ///< 9600 baud
    UART_BAUD_19K2,     ///< 19.2 kbaud
    UART_BAUD_38K4,     ///< 38.4 kbaud
    UART_BAUD_57K6,     ///< 57.6 kbaud
} epl_uart_baudrate_t;

/** Function to initialize the UART.
 * This function initializes the UART for interrupt operation. An 8 byte receive
 * buffer and an 8 byte transmit buffer is used.
 * @param baud a constant for the baud rate (0 = 600 Baud, ..., 7=57600 baud)
 */
void epl_uart_init(epl_uart_baudrate_t baud);

/** Function to write a character to the UART transmit buffer.
 * @param ch Character to write
 */
void epl_uart_putchar(unsigned char ch);


/** Function to write a string to the UART transmit buffer.
 * @param str string to write
 */
void epl_uart_putstr(unsigned char* str);


/** Function to read a character from the UART receive buffer.
 * @return Character read
 */
unsigned char epl_uart_getchar(void);

/** Function to write a decimal number to UART transmit buffer (written by Jackal@EPL).
 *  * @param num the number to be written
 *   */
void epl_uart_putint(unsigned int num) reentrant;


/** Function to write a hex humber to UART transmit buffer (written by Jackal@EPL).
 *  * @param num the number to be written
 *   */
void epl_uart_puthex(unsigned int num) reentrant;

int epl_uart_rcv_buf_is_empty(void);

#endif
