#include <EPL/epl_utils.h>
#include <HAL/hal_nrf.h>
#include <EPL/epl_uart.h>
#include <EPL/epl_dbg.h>

#define MAX_RF_PLOAD 32

struct epl_lu1_rf_en_config rf_conf = { 
		{118}, 						/* channel */
        {5}, 							/* Address width */
        {0x65, 0x65, 0x65, 0x65, 0x65}, /* Destination Address */
        {0x65, 0x65, 0x65, 0x65, 0x65}, /* PIPE 0 Address */
        {32},							/* Payload length */
        {RF_EN_1MBPS},					/* Data rate */
        (RF_EN_CRC_16BIT),				/* CRC Mode */
        {RF_EN_AUTO_ACK_ON},			/* Enable Autoack or not */
		{15},							/* ART times */
        {250} 							/* ART delay time */
};

struct epl_lu1_rf_en_config * cfg = &rf_conf;

void epl_dbg_init()
{
	//Start RF tx mode
	epl_rf_en_quick_init(cfg);
	//epl_rf_en_enter_tx_mode();
	
	//test
	epl_uart_init(UART_BAUD_57K6);
	
	//Clear TX FIFO
	hal_nrf_flush_tx();
}

void epl_dbg_print(uint8_t *pload, uint8_t size)
{
	uint8_t xdata outbuf[MAX_RF_PLOAD];
	uint8_t i = 0;
	
	if (size > MAX_RF_PLOAD -1)
	{
		size = MAX_RF_PLOAD -1;		
	}
	
	// first byte indicate pload length
	outbuf[0] = size;
	
	/*
	// at most 32 bytes pload
	if (size > MAX_RF_PLOAD)
	{
		size = MAX_RF_PLOAD;		
	}
	else	// padding
	{
		for(i=size;i<MAX_RF_PLOAD;i++)
		{
			outbuf[i] = '\0';
		}
	}
	*/
	for(i=1;i<=size;i++)
	{
		outbuf[i] = (*pload++);		
	}
	
	for(i=0;i<MAX_RF_PLOAD;i++)
	{
		epl_uart_puthex(outbuf[i]);
		epl_uart_putstr(" ");
	}
	epl_uart_putstr("\n");
	
	epl_rf_en_send(outbuf, MAX_RF_PLOAD);
	
	hal_nrf_get_clear_irq_flags();
}