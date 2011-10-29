#include <Nordic/reg24le1.h>
#include <EPL/epl_nv_flash.h>

void epl_nv_flash_page_erase(uint8_t pn)
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

void epl_nv_flash_byte_write(uint16_t a, uint8_t b)
{
  uint8_t xdata *data pb;
  
  if(a < HAL_DATA_NV_BASE_ADDRESS)
	  return;
  
  // Save interrupt enable state and disable interrupts:
  F0 = EA;
  EA = 0;
  
  // Enable flash write operation:
  WEN = 1;
  
  // Write the byte directly to the flash. This operation is "self timed" when
  // executing from the flash; the CPU will halt until the operation is
  // finished:
  pb = (uint8_t xdata *)a;
  *pb = b;

  // When running from XDATA RAM we need to wait for the operation to finish:
  while(RDYN == 1)
    ;
  
  WEN = 0;
    
  EA = F0; // Restore interrupt enable state
}

void epl_nv_flash_bytes_write(uint16_t a, uint8_t *p, uint16_t n)
{
  uint8_t xdata *data pb;

  if(a < HAL_DATA_NV_BASE_ADDRESS)
	  return;
  
  // Save interrupt enable state and disable interrupts:
  F0 = EA;
  EA = 0;

  // Enable flash write operation:
  WEN = 1;

  // Write the bytes directly to the flash. This operation is
  // "self timed"; the CPU will halt until the operation is
  // finished:
  pb = (uint8_t xdata *)a;
  while(n--)
  {
    *pb = *p;
    pb++;
    p++;

    //
    // When running from XDATA RAM we need to wait for the operation to
    // finish:
    while(RDYN == 1)
      ;
  }
  
  WEN = 0;

  EA = F0; // Restore interrupt enable state
}

uint8_t epl_nv_flash_byte_read(uint16_t a)
{
  uint8_t xdata *pb = (uint8_t xdata *)a;
  return *pb;
}

void epl_nv_flash_bytes_read(uint16_t a, uint8_t *p, uint16_t n)
{  
  uint8_t xdata *pb = (uint8_t xdata *)a;
  while(n--)
  {
    *p = *pb;
    pb++;
    p++;
  }
}