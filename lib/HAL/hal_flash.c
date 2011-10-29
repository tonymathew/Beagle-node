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
 * $LastChangedRevision:$
 */ 

/** @file
 *@brief Implementation of hal_flash
 */

#include <Nordic/reg24le1.h>
#include <HAL/hal_flash.h>

void hal_flash_page_erase(unsigned char pn)
{ 
  // Save interrupt enable state and disable interrupts:
  F0 = EA;
  EA = 0;
  
  // Enable flash write operation:
  WEN = 1; 
  
  // Write the page address to FCR to start the page erase operation. This
  // operation is "self timed" when executing from the flash; the CPU will
  // halt until the operation is finished:
  FCR = pn;

  // When running from XDATA RAM we need to wait for the operation to finish:
  while(RDYN == 1)
    ;
 
  WEN = 0;
  
  EA = F0; // Restore interrupt enable state  
}

void hal_flash_byte_write(unsigned int a, unsigned char b)
{
  unsigned char xdata *data pb;
    
  // Save interrupt enable state and disable interrupts:
  F0 = EA;
  EA = 0;
  
  // Enable flash write operation:
  WEN = 1;
  
  // Enable program memory write mode:
  PCON |= 0x10;
  
  // Write the byte directly to the flash. This operation is "self timed" when
  // executing from the flash; the CPU will halt until the operation is
  // finished:
  pb = (unsigned char xdata *)a;
  *pb = b;

  // When running from XDATA RAM we need to wait for the operation to finish:
  while(RDYN == 1)
    ;
  // Disable program memory write mode:
  PCON &= ~0x10;
  
  WEN = 0;
    
  EA = F0; // Restore interrupt enable state
}

void hal_flash_bytes_write(unsigned int a, unsigned char *p , unsigned int n)
{
  unsigned char xdata *data pb;
  unsigned char x;

  // Save interrupt enable state and disable interrupts:
  F0 = EA;
  EA = 0;

  // Enable flash write operation:
  WEN = 1;

  // Write the bytes directly to the flash. This operation is
  // "self timed"; the CPU will halt until the operation is
  // finished:
  pb = (unsigned char xdata *)a;
  while(n--)
  {
	x = *p;
	  	
	PCON |= 0x10;
	*pb = x;	
	PCON &= ~0x10;
   
    pb++;
    p++;

    //																				 
    // When running from XDATA RAM we need to wait for the operation to
    // finish:
    while(RDYN == 1)
      ;
  }
  // Disable program memory write mode:
  PCON &= ~0x10;
  
  WEN = 0;

  EA = F0; // Restore interrupt enable state
}

unsigned char hal_flash_byte_read(unsigned int a)
{
  unsigned char code *pb = (unsigned char code *)a;
  return *pb;
}

void hal_flash_bytes_read(unsigned int a, unsigned char *p, unsigned int n)
{  
  unsigned char code *pb = (unsigned char code *)a;
  while(n--)
  {
    *p = *pb;
    pb++;
    p++;
  }
}
