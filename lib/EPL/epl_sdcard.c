/* SD Card driver for LE1
 *
 * Brian Yang <asdyaya@gmail.com> 
 * 2009/2/17 V1.0
 *
 * 
 */

#include <EPL/epl_sdcard.h>
#include <Nordic/reg24le1.h>
#include <HAL/hal_spi.h>

int wsector = 0;
int rsector = 0;
int wcount = 0;
int rcount = 0;

void epl_sdcard_command(char befF, unsigned int AdrH, unsigned int AdrL, char befH )
{	
	// sends a command to the MMC	
	hal_spi_master_read_write(befF|0x40);
	hal_spi_master_read_write((char)(AdrH >> 8));
	hal_spi_master_read_write((char)(AdrH));
	hal_spi_master_read_write((char)(AdrL >> 8));
	hal_spi_master_read_write((char)(AdrL));
	hal_spi_master_read_write(befH);
}

char epl_sdcard_init()
{
	char i;
	
	//enable spi
	hal_spi_master_init(SPI_CLK_DIV2,HAL_SPI_MODE_0,HAL_SPI_MSB_LSB);
	
	// set P0.6 as output
	P0DIR &= ~0x40;
	
	//disable MMC
	SD_CS = 1;
	
	// start MMC in SPI mode
	for(i = 0; i < 10; i++) 
		hal_spi_master_read_write(0xFF); // send 10*8=80 clock pulses
	
	//go to idle mode
	return (epl_sdcard_goIdle());	
}

char epl_sdcard_goIdle()
{
	char response = 0x01;
	
	//enable MMC
	SD_CS = 0;
	
	//Send Command 0 to put MMC in SPI mode
	epl_sdcard_command(MMC_GO_IDLE_STATE,0x0000,0x0000,0x95);
	
	//Now wait for READY RESPONSE
	if(epl_sdcard_getResponse() != 0x01)
		return MMC_INIT_ERROR;
	
	while(response == 0x01)
	{
	    SD_CS = 1;
	    hal_spi_master_read_write(0xff);
	    SD_CS = 0;
	    
	    epl_sdcard_command(MMC_SEND_OP_COND,0x0000,0x0000,0xff);
	    response = epl_sdcard_getResponse();
	}
	
	SD_CS = 1;
	hal_spi_master_read_write(0xff);
  	
  	return (MMC_SUCCESS);
}

// sd Get Responce
char epl_sdcard_getResponse()
{
  	//Response comes 1-8bytes after command
  	//the first bit will be a 0
  	//followed by an error code
  	//data will be 0xff until response
  
  	char i = 0;

  	char response = 0x00;

  	while(i <= 64)
  	{
    	response = hal_spi_master_read_write(0xff);
    	if(response == 0x00)
    		break;    
    	if(response == 0x01)
    		break;  
    	i++;
  	}

  	return response;
}

char epl_sdcard_getXXResponse(char resp)
{
	//Response comes 1-8bytes after command
  	//the first bit will be a 0
  	//followed by an error code
  	//data will be 0xff until response
  	int i = 0;

  	char response = 0x00;

  	for(i = 0;i <= 1000;i++)
  	{
    	response = hal_spi_master_read_write(0xff);
    	if(response == resp)
    		break;
  	}	
  	return response;
}

char epl_sdcard_checkBusy(void)
{
  	//Response comes 1-8bytes after command
  	//the first bit will be a 0
  	//followed by an error code
  	//data will be 0xff until response
  
  	char i = 0;
  	char response;
  	char rvalue;
  
  	while(i <= 64)
  	{
    	response = hal_spi_master_read_write(0xff);
    	response &= 0x1f;
   		
   		switch(response)
    	{
      		case 0x05: 
      			rvalue = MMC_SUCCESS;
      			break;
      		case 0x0b: 
      			return(MMC_CRC_ERROR);
      		case 0x0d: 
      			return(MMC_WRITE_ERROR);
      		default:
        		rvalue = MMC_OTHER_ERROR;
        		break;
    	}
    	if(rvalue == MMC_SUCCESS)
    		break;    		
    	i++;
  	}
   	do
  	{
    	response = hal_spi_master_read_write(0xff);
  	}while(response == 0);
  
  	return response;
}

char epl_sdcard_setBlockLength(unsigned int hCnt,unsigned int lCnt)
{ 	
  	SD_CS = 0;
  
  	epl_sdcard_command(MMC_SET_BLOCKLEN,hCnt,lCnt,0xFF);
  
  	if(epl_sdcard_getResponse() != 0x00)
  	{ 
  		epl_sdcard_init();
  		epl_sdcard_command(MMC_SET_BLOCKLEN,hCnt,lCnt,0xFF);
  		epl_sdcard_getResponse();
  	}

  	SD_CS = 1;

  	// Send 8 Clock pulses of delay.
  	hal_spi_master_read_write(0xff);
 
  	return MMC_SUCCESS;
}

char epl_sdcard_open()
{
	char tm = 0;
	char status = MMC_INIT_ERROR;
	
	//init sd card
	while (status != MMC_SUCCESS)
	{              
		// if return in not NULL an error did occur and the
        // MMC/SD-card will be initialized again 
    	status = epl_sdcard_init();
    	tm++;
    		
    	// Try 50 times till error
    	if (tm == 50){            	
      		return MMC_INIT_ERROR;
    	}
  	}	
	
  	//set block length 512
  	return epl_sdcard_setBlockLength(0,0x200);
}

char epl_sdcard_begin_write()
{
	unsigned long Addr = 512ul * wsector;
	unsigned int hAddr = (unsigned int)((Addr >> 16) & 0xFFFF);
  	unsigned int lAddr = (unsigned int)(Addr & 0xFFFF);
  	
  	wcount = 0;
	
	//begin write to sd card
    SD_CS = 0;
    
    // send write command
    epl_sdcard_command(MMC_WRITE_BLOCK,hAddr,lAddr, 0xFF);

    // check if the MMC acknowledged the write block command
    // it will do this by sending an affirmative response
    // in the R1 format (0x00 is no errors)
    if(epl_sdcard_getXXResponse(MMC_R1_RESPONSE) == MMC_R1_RESPONSE)
    {
      	hal_spi_master_read_write(0xff);
      		
      	// send the data token to signify the start of the data	
      	hal_spi_master_read_write(0xfe);
      		
      	return MMC_SUCCESS;
    }
      	
    return MMC_ERROR;
}
      		
void epl_sdcard_write_char(char c)
{	
	//write a byte to sd
	hal_spi_master_read_write(c);

	wcount += 1;
	
	if(wcount == 512){
		epl_sdcard_end_write();
		epl_sdcard_begin_write();
	}
}

void epl_sdcard_write_str(char *s)
{
	while (*s)
		epl_sdcard_write_char(*s++);	
}

char epl_sdcard_end_write(){
	//end write to sd card
	int i;

	//padding to 512 bytes
	i = wcount;
	
	if(wcount != 0)
	{
		for(;i < 512;i++)
			hal_spi_master_read_write(0xFF);
	}
	wsector++;
	
	// put CRC bytes (not really needed by us, but required by MMC)
    hal_spi_master_read_write(0xff);
    hal_spi_master_read_write(0xff);
      				
    // read the data response xxx0<status>1 : status 010: Data accected, status 101: Data
    // rejected due to a crc error, status 110: Data rejected due to a Write error.
    epl_sdcard_checkBusy();
      	
    SD_CS = 1;
  	// Send 8 Clock pulses of delay.
  	hal_spi_master_read_write(0xff);
  	
  	return MMC_SUCCESS;
}

char epl_sdcard_begin_read()
{
	//begin read to sd card
	
	unsigned long Addr = 512ul * rsector;
	unsigned int hAddr = (unsigned int)((Addr >> 16) & 0xFFFF);
  	unsigned int lAddr = (unsigned int)(Addr & 0xFFFF);
	
  	rcount = 0;
  	
    SD_CS = 0;
    
    // send read command MMC_READ_SINGLE_BLOCK=CMD17
    epl_sdcard_command(MMC_READ_SINGLE_BLOCK,hAddr,lAddr,0xFF);
    
    // Send 8 Clock pulses of delay, check if the MMC acknowledged the read block command
    // it will do this by sending an affirmative response
    // in the R1 format (0x00 is no errors)
    if(epl_sdcard_getResponse() == 0x00)
    {
      	// now look for the data token to signify the start of the data
      	if (((unsigned char)epl_sdcard_getXXResponse(MMC_START_DATA_BLOCK_TOKEN)) == MMC_START_DATA_BLOCK_TOKEN)
      		return MMC_SUCCESS;  
      	else
        	return MMC_ERROR;      // 3  , the data token was never received
    }
      	
    return MMC_ERROR;
}

char epl_sdcard_read()
{
	//read a byte from sd
	char c = hal_spi_master_read_write(0xFF);
	
	rcount++;
	
	if(rcount == 512){
		epl_sdcard_end_read();
		epl_sdcard_begin_read();
	}
	
	return c;
}

char epl_sdcard_end_read()
{
	//end read to sd card
	
	//read other bytes
	int i;
	
	//padding to 512 bytes
	
	i = rcount;
	if(rcount != 0)
	{
		for(;i < 512;i++)
			hal_spi_master_read_write(0xff);
	}
	rsector++;
	
	// get CRC bytes (not really needed by us, but required by MMC)
    hal_spi_master_read_write(0xff);
    hal_spi_master_read_write(0xff);
	
    SD_CS = 1;
    // Send 8 Clock pulses of delay.
    hal_spi_master_read_write(0xff);
    
	return MMC_SUCCESS;
}

void epl_sdcard_setRsector(int sector)
{
	rsector = sector;	
}

void epl_sdcard_setWsector(int sector)
{
	wsector = sector;	
}
