/* @file 
 * LE1 utils driver
 *
 * @author Brian Yang <asdyaya@gmail.com>
 * 2009/02/19
 */

#ifndef EPL_UTILS_H_
#define EPL_UTILS_H_

#include <stdint.h>

#define BUTTON P03

#define LED0 P07
#define LED1 P10

#define LED0_SIMPLE P13
#define LED1_SIMPLE P14

#define ON 0
#define OFF 1

void epl_mdelay(unsigned int ms);
void epl_led_init();
void epl_led_simple_init();
void epl_btn_init();


#define LED0_BLINK() do{  LED0 = ON;        \
						  epl_mdelay(50);   \
                          LED0 = OFF;       \
                          }while(0)

#define LED1_BLINK() do{  LED1 = ON;        \
					      epl_mdelay(50);   \
                          LED1 = OFF;       \
                          }while(0)

#define LED0_SIMPLE_BLINK() do{	LED0_SIMPLE = ON;       \
								epl_mdelay(50);   	    \
						  		LED0_SIMPLE = OFF;      \
                          	}while(0)

#define LED1_SIMPLE_BLINK() do{ LED1_SIMPLE = ON;       \
								epl_mdelay(50);   		\
						  		LED1_SIMPLE = OFF;      \
							}while(0)

#endif /*EPL_UTILS_H_*/
