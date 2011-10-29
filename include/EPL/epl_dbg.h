//Author : Brian Yang <asdyaya@gmail.com> 

#ifndef EPL_DBG_H_
#define EPL_DBG_H_
	
#include <Nordic/reg24le1.h>
#include <EPL/epl_rf_en.h>
#include <stdint.h>

/*
 * 要開啟 wireless debug mode，請使用以下code:
 * 
 * #define WIRELESS_DEBUGER
 * 
 * #ifndef WIRELESS_DEBUGER
 * 	#include <EPL/epl_ndbg.h> 
 * #else
 * 	#include <EPL/epl_dbg.h>
 * #endif
 * 
 * 如果不需要回傳 debug message 只需把 "#define WIRELESS_DEBUGER" 註解掉即可
 * 不需將print拿掉
 *
 * P.S 不支援 RF debug
 */

void epl_dbg_init();
void epl_dbg_print(uint8_t *pload, uint8_t size);


#endif /*EPL_DBG_H_*/

	





