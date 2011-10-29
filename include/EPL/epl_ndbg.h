#ifndef EPL_NDBG_H_
#define EPL_NDBG_H_

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

#define epl_dbg_init() ((void)0)
#define epl_dbg_print(a,b) ((void)0)

#endif /*EPL_NDBG_H_*/
