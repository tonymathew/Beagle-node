/* @file 
 * LE1 Temperature sensor(TC77) driver using external SPI
 *
 * @author Brian Yang <asdyaya@gmail.com>
 * 2009/09/12
 */

#ifndef EPL_TEMP_TC77_H_
#define EPL_TEMP_TC77_H_

#include <Nordic/reg24le1.h>

#define TEMP_CSN 				P11
#define TEMP_CSN_DIR_INIT();	P1DIR &= ~0x02;			
#define TEMP_DATA				P16
#define TEMP_DATA_DIR_INIT();	P1DIR |= 0x40;

#define DATA_ERROR				0xFFFF

void epl_temp_tc77_init(void);
int epl_temp_tc77_read(void);

#endif /*EPL_TEMP_TC77_H_*/
