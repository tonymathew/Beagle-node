/** @file
 * Implementation of the non-interrupt EPL UART module
 * @author: Jackal Chen <wtg.design@gmail.com>
 */

#include <Nordic/reg24le1.h>
#include <stdint.h>
#include <EPL/epl_uart.h>


#define BAUD_57K6   1015  // = Round(1024 - (2*16e6)/(64*57600))
#define BAUD_38K4   1011  // = Round(1024 - (2*16e6)/(64*38400))
#define BAUD_19K2    998  // = Round(1024 - (2*16e6)/(64*19200))
#define BAUD_9K6     972  // = Round(1024 - (2*16e6)/(64*9600))

void epl_uart_init(epl_uart_baudrate_t baud){
	unsigned int temp;

	ES0 = 0;                                      // Disable UART0 interrupt while initializing
	REN0 = 1;                                     // Enable receiver
	SM0 = 0;                                      // Mode 1..
	SM1 = 1;                                      // ..8 bit variable baud rate
	PCON |= 0x80;                                 // SMOD = 1
	ADCON |= 0x80;                                // Select internal baud rate generator
  	
	switch(baud){
    		case UART_BAUD_57K6:
      			temp = BAUD_57K6;
      			break;
    		case UART_BAUD_38K4:
      			temp = BAUD_38K4;
      			break;
    		case UART_BAUD_9K6:
      			temp = BAUD_9K6;
      			break;
    		case UART_BAUD_19K2:
    		default:
      			temp = BAUD_19K2;
      			break;
  	}
	
  	S0RELL = (unsigned char)temp;
  	S0RELH = (unsigned char)(temp >> 8);
  
  	P0DIR |= 0x10;      // P04 (RxD) is input
  	P0DIR &= ~0x08;		// P03 (TxD) is output
  	
  	TI0 = 0;
  	RI0 = 0;
}

void epl_uart_putchar(unsigned char ch){
	S0BUF = ch;	/* write to serial buffer */
	while (!TI0)	/* wait until done */
		;
	TI0 = 0;	/* clean transmit done bit */
}

void epl_uart_putstr(unsigned char *str){
	while(*str)
		epl_uart_putchar(*str++);
}

unsigned char epl_uart_getchar(void){
	unsigned char ret;

	while (!RI0)	/* wait until done */
		;
	RI0 = 0;		/* clean receive bit */
	ret = S0BUF;
	return ret;
}

void epl_uart_putint(unsigned int num) reentrant{
        unsigned int t1,t2;
        t1 = num / 10;
        t2 = num % 10;
        
        if(t1)
        	epl_uart_putint(t1);
        
        epl_uart_putchar( t2 + '0');
}

void epl_uart_puthex(unsigned int num) reentrant{ 
        unsigned int t1,t2;
        t1 = num / 16;
        t2 = num % 16;

        if(t1)
                epl_uart_puthex(t1);
        else
                epl_uart_putstr("0x");

        if(t2 >= 10)
                epl_uart_putchar((t2 - 10) + 'a');
        else
                epl_uart_putchar(t2 + '0');
}

int epl_uart_rcv_buf_is_empty(void)
{
	if (RI0)
		return 0;
	else
		return 1;
}
