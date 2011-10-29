/** @file
 * Type definitions for firmware projects developed at Nordic semiconductor.
 *
 * Standard storage classes in C, such as @c char, @c int, and @c long, ar not always
 * interpreted in the same way by the compiler. The types here are defined by their
 * bit length and signed/unsigned property, as their name indicate. The correlation
 * between the name and properties of the storage class should be true, regardless of
 * the compiler being used.
 */
 
/* $copyright$
 *
 * $license$
 */

#ifndef __STDBOOL_H__
#define __STDBOOL_H__

//lint -strong(B,_Bool)
typedef unsigned char _Bool; ///< Boolean type

#define bool _Bool
#define true 1
#define false 0
#define __bool_true_false_are_defined 1

#endif // __STDBOOL_H__
