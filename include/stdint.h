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

#ifndef __STDINT_H__
#define __STDINT_H__

//#ifdef __C51__

typedef unsigned char uint8_t;        ///< 8 bit unsigned int

typedef signed char int8_t;          ///< 8 bit signed int

typedef unsigned int uint16_t;        ///< 16 bit unsigned int

typedef signed int int16_t;          ///< 16 bit signed int

typedef unsigned long uint32_t;       ///< 32 bit unsigned int

typedef signed long int32_t;         ///< 32 bit signed int

//#endif // __C51__

#ifndef NULL
#define NULL (void*)0
#endif

#endif // __STDINT_H__
