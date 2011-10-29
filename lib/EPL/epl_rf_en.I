
#line 1 "../LE1/lib/EPL/epl_rf_en.c" /0








 
 






















 
 
  
#line 1 "../LE1/INCLUDE\EPL/EPL_RF_EN.H" /0








 
 






















 
 




 
 
 
 
  
#line 1 "../LE1/INCLUDE\NORDIC/REG24LE1.H" /0







 
 
 
 
 
 
 
 
 sfr   P0           = 0x80;
 sfr   SP           = 0x81;
 sfr   DPL          = 0x82;
 sfr   DPH          = 0x83;
 sfr   DPL1         = 0x84;
 sfr   DPH1         = 0x85;
 sfr   PCON         = 0x87;
 sfr   TCON         = 0x88;
 sfr   TMOD         = 0x89;
 sfr   TL0          = 0x8A;
 sfr   TL1          = 0x8B;
 sfr   TH0          = 0x8C;
 sfr   TH1          = 0x8D;
 sfr   P3CON        = 0x8F;
 sfr   P1           = 0x90;
 sfr   DPS          = 0x92;
 sfr   P0DIR        = 0x93;
 sfr   P1DIR        = 0x94;
 sfr   P2DIR        = 0x95;
 sfr   P3DIR        = 0x96;
 sfr   P2CON        = 0x97;
 sfr   S0CON        = 0x98;
 sfr   S0BUF        = 0x99;
 sfr   P0CON        = 0x9E;
 sfr   P1CON        = 0x9F;
 sfr   P2           = 0xA0;
 sfr   PWMDC0       = 0xA1;
 sfr   PWMDC1       = 0xA2;
 sfr   CLKCTRL      = 0xA3;
 sfr   PWRDWN       = 0xA4;
 sfr   WUCON        = 0xA5;
 sfr   INTEXP       = 0xA6;
 sfr   MEMCON       = 0xA7;
 sfr   IEN0         = 0xA8;
 sfr   IP0          = 0xA9;
 sfr   S0RELL       = 0xAA;
 sfr   RTC2CPT01    = 0xAB;
 sfr   RTC2CPT10    = 0xAC;
 sfr   CLKLFCTRL    = 0xAD;
 sfr   OPMCON       = 0xAE;
 sfr   WDSV         = 0xAF;
 sfr   P3           = 0xB0;
 sfr   RSTREAS      = 0xB1;
 sfr   PWMCON       = 0xB2;
 sfr   RTC2CON      = 0xB3;
 sfr   RTC2CMP0     = 0xB4;
 sfr   RTC2CMP1     = 0xB5;
 sfr   RTC2CPT00    = 0xB6;
 sfr   SPISRDSZ     = 0xB7;
 sfr   IEN1         = 0xB8;
 sfr   IP1          = 0xB9;
 sfr   S0RELH       = 0xBA;
 sfr   SPISCON0     = 0xBC;
 sfr   SPISCON1     = 0xBD;
 sfr   SPISSTAT     = 0xBE;
 sfr   SPISDAT      = 0xBF;
 sfr   IRCON        = 0xC0;
 sfr   CCEN         = 0xC1;
 sfr   CCL1         = 0xC2;
 sfr   CCH1         = 0xC3;
 sfr   CCL2         = 0xC4;
 sfr   CCH2         = 0xC5;
 sfr   CCL3         = 0xC6;
 sfr   CCH3         = 0xC7;
 sfr   T2CON        = 0xC8;
 sfr   MPAGE        = 0xC9;
 sfr   CRCL         = 0xCA;
 sfr   CRCH         = 0xCB;
 sfr   TL2          = 0xCC;
 sfr   TH2          = 0xCD;
 sfr   WUOPC1       = 0xCE;
 sfr   WUOPC0       = 0xCF;
 sfr   PSW          = 0xD0;
 sfr   ADCCON3      = 0xD1;
 sfr   ADCCON2      = 0xD2;
 sfr   ADCCON1      = 0xD3;
 sfr   ADCDATH      = 0xD4;
 sfr   ADCDATL      = 0xD5;
 sfr   RNGCTL       = 0xD6;
 sfr   RNGDAT       = 0xD7;
 sfr   ADCON        = 0xD8;
 sfr   W2SADR       = 0xD9;
 sfr   W2DAT        = 0xDA;
 sfr   COMPCON      = 0xDB;
 sfr   POFCON       = 0xDC;
 sfr   CCPDATIA     = 0xDD;
 sfr   CCPDATIB     = 0xDE;
 sfr   CCPDATO      = 0xDF;
 sfr   ACC          = 0xE0;
 sfr   W2CON1       = 0xE1;
 sfr   W2CON0       = 0xE2;
 sfr   SPIRCON0     = 0xE4;
 sfr   SPIRCON1     = 0xE5;
 sfr   SPIRSTAT     = 0xE6;
 sfr   SPIRDAT      = 0xE7;
 sfr   RFCON        = 0xE8;
 sfr   MD0          = 0xE9;
 sfr   MD1          = 0xEA;
 sfr   MD2          = 0xEB;
 sfr   MD3          = 0xEC;
 sfr   MD4          = 0xED;
 sfr   MD5          = 0xEE;
 sfr   ARCON        = 0xEF;
 sfr   B            = 0xF0;
 sfr   FSR          = 0xF8;
 sfr   FPCR         = 0xF9;
 sfr   FCR          = 0xFA;
 sfr   FDCR         = 0xFB;
 sfr   SPIMCON0     = 0xFC;
 sfr   SPIMCON1     = 0xFD;
 sfr   SPIMSTAT     = 0xFE;
 sfr   SPIMDAT      = 0xFF;
 
 sfr16 CC1          = 0xC2;
 sfr16 CC2          = 0xC4;
 sfr16 CC3          = 0xC6;
 sfr16 CRC          = 0xCA;
 sfr16 T2           = 0xCC;
 
 
 sbit  MCDIS        = FSR^7;
 sbit  STP          = FSR^6;
 sbit  WEN          = FSR^5;
 sbit  RDYN         = FSR^4;
 sbit  INFEN        = FSR^3;
 sbit  RDIS         = FSR^2;
 sbit  RDEND        = FSR^1;
 sbit  WPEN         = FSR^0;
 
 
 sbit  CY           = PSW^7;
 sbit  AC           = PSW^6;
 sbit  F0           = PSW^5;
 sbit  RS1          = PSW^4;
 sbit  RS0          = PSW^3;
 sbit  OV           = PSW^2;
 sbit  P            = PSW^0;
 
 
 sbit  TF1          = TCON^7;
 sbit  TR1          = TCON^6;
 sbit  TF0          = TCON^5;
 sbit  TR0          = TCON^4;
 sbit  IE1          = TCON^3;
 sbit  IT1          = TCON^2;
 sbit  IE0          = TCON^1;
 sbit  IT0          = TCON^0;
 
 
 sbit  SM0          = S0CON^7;
 sbit  SM1          = S0CON^6;
 sbit  SM20         = S0CON^5;
 sbit  REN0         = S0CON^4;
 sbit  TB80         = S0CON^3;
 sbit  RB80         = S0CON^2;
 sbit  TI0          = S0CON^1;
 sbit  RI0          = S0CON^0;
 
 
 sbit  T2PS         = T2CON^7;
 sbit  I3FR         = T2CON^6;
 sbit  I2FR         = T2CON^5;
 sbit  T2R1         = T2CON^4;
 sbit  T2R0         = T2CON^3;
 sbit  T2CM         = T2CON^2;
 sbit  T2I1         = T2CON^1;
 sbit  T2I0         = T2CON^0;
 
 
 sbit  EA           = IEN0^7;
 sbit  ET2          = IEN0^5;
 sbit  ES0          = IEN0^4;
 sbit  ET1          = IEN0^3;
 sbit  EX1          = IEN0^2;
 sbit  ET0          = IEN0^1;
 sbit  EX0          = IEN0^0;
 
 
 sbit  EXEN2        = IEN1^7;
 sbit  WUIRQ        = IEN1^5;
 sbit  MISC         = IEN1^4;
 sbit  WUPIN        = IEN1^3;
 sbit  SPI          = IEN1^2;
 sbit  RF           = IEN1^1;
 sbit  RFSPI        = IEN1^0;
 
 
 sbit  EXF2         = IRCON^7;
 sbit  TF2          = IRCON^6;
 sbit  WUF          = IRCON^5;
 sbit  MISCF        = IRCON^4;
 sbit  WUPINF       = IRCON^3;
 sbit  SPIF         = IRCON^2;
 sbit  RFF          = IRCON^1;
 sbit  RFSPIF       = IRCON^0;
 
 
 sbit  P00          = P0^0;
 sbit  P01          = P0^1;
 sbit  P02          = P0^2;
 sbit  P03          = P0^3;
 sbit  P04          = P0^4;
 sbit  P05          = P0^5;
 sbit  P06          = P0^6;
 sbit  P07          = P0^7;
 
 
 sbit  P10          = P1^0;
 sbit  P11          = P1^1;
 sbit  P12          = P1^2;
 sbit  P13          = P1^3;
 sbit  P14          = P1^4;
 sbit  P15          = P1^5;
 sbit  P16          = P1^6;
 sbit  P17          = P1^7;
 
 
 sbit P20           = P2^0;
 sbit P21           = P2^1;
 sbit P22           = P2^2;
 sbit P23           = P2^3;
 sbit P24           = P2^4;
 sbit P25           = P2^5;
 sbit P26           = P2^6;
 sbit P27           = P2^7;
 
 
 sbit P30           = P3^0;
 sbit P31           = P3^1;
 sbit P32           = P3^2;
 sbit P33           = P3^3;
 sbit P34           = P3^4;
 sbit P35           = P3^5;
 sbit P36           = P3^6;
 sbit P37           = P3^7;
 
 
 sbit  RFCE         = RFCON^0;
 sbit  RFCSN        = RFCON^1;
 sbit  RFCKEN       = RFCON^2;
 
 
 sbit  BD           = ADCON^7;
 
 
 
#line 43 "../LE1/INCLUDE\EPL/EPL_RF_EN.H" /0
 
  
#line 1 "../LE1/INCLUDE\HAL/HAL_NRF_HW.H" /0










 
 
 
 
 
  
#line 1 "../LE1/INCLUDE\NORDIC/REG24LE1.H" /0







 
 
#line 10 "../LE1/INCLUDE\NORDIC/REG24LE1.H" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 16 "../LE1/INCLUDE\HAL/HAL_NRF_HW.H" /0
#line 16 "../LE1/INCLUDE\HAL/HAL_NRF_HW.H" /0
 
 


 
 
 


 
 
 


 
 
 


 
 
 


 
 







 
 
 
 
 
#line 44 "../LE1/INCLUDE\EPL/EPL_RF_EN.H" /0
 
  
#line 1 "../LE1/INCLUDE\HAL/HAL_NRF.H" /0











 
 

























 
 
 
 
 
  
#line 1 "../LE1/INCLUDE\STDINT.H" /0








 
 



 
 
 
 
 
 
 
 typedef unsigned char uint8_t;         
 
 typedef signed char int8_t;           
 
 typedef unsigned int uint16_t;         
 
 typedef signed int int16_t;           
 
 typedef unsigned long uint32_t;        
 
 typedef signed long int32_t;          
 
 
 
 
 
 
 
 
#line 44 "../LE1/INCLUDE\HAL/HAL_NRF.H" /0
 
  
#line 1 "../LE1/INCLUDE\STDBOOL.H" /0








 
 



 
 
 
 
 
 
 typedef unsigned char _Bool;  
 
 
 
 
 
 
 
#line 45 "../LE1/INCLUDE\HAL/HAL_NRF.H" /0
 
 
  
#line 1 "../LE1/INCLUDE\HAL/HAL_NRF_REG.H" /0











 
 




 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


 
 typedef enum {
 HAL_NRF_MAX_RT = 4,      
 HAL_NRF_TX_DS,           
 HAL_NRF_RX_DR            
 } hal_nrf_irq_source_t;
 
 


 
 typedef enum {
 HAL_NRF_PTX,             
 HAL_NRF_PRX              
 } hal_nrf_operation_mode_t;
 


 
 typedef enum {
 HAL_NRF_PWR_DOWN,        
 HAL_NRF_PWR_UP           
 } hal_nrf_pwr_mode_t;
 


 
 typedef enum {
 HAL_NRF_18DBM,           
 HAL_NRF_12DBM,           
 HAL_NRF_6DBM,            
 HAL_NRF_0DBM             
 } hal_nrf_output_power_t;
 


 
 typedef enum {
 HAL_NRF_1MBPS,           
 HAL_NRF_2MBPS,           
 HAL_NRF_250KBPS          
 } hal_nrf_datarate_t;
 


 
 typedef enum {
 HAL_NRF_CRC_OFF,     
 HAL_NRF_CRC_8BIT,    
 HAL_NRF_CRC_16BIT    
 } hal_nrf_crc_mode_t;
 


 
 typedef enum {
 HAL_NRF_TX_PLOAD = 7,    
 HAL_NRF_RX_PLOAD,         
 HAL_NRF_ACK_PLOAD
 } hal_nrf_pload_command_t;
 




 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


 
 typedef enum {
 HAL_NRF_PIPE0,               
 HAL_NRF_PIPE1,               
 HAL_NRF_PIPE2,               
 HAL_NRF_PIPE3,               
 HAL_NRF_PIPE4,               
 HAL_NRF_PIPE5,               
 HAL_NRF_TX,                  
 HAL_NRF_ALL = 0xFF           

 
 } hal_nrf_address_t;
 


 
 typedef enum {
 HAL_NRF_AW_3BYTES = 3,       
 HAL_NRF_AW_4BYTES,           
 HAL_NRF_AW_5BYTES            
 } hal_nrf_address_width_t;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 47 "../LE1/INCLUDE\HAL/HAL_NRF.H" /0
 
  
#line 1 "../LE1/INCLUDE\HAL/HAL_NRF_HW.H" /0










 
 
 
#line 14 "../LE1/INCLUDE\HAL/HAL_NRF_HW.H" /1
  
 
  
 


 
  
 


 
  
 


 
  
 


 
  
 


 
  







 
 
#line 51 "../LE1/INCLUDE\HAL/HAL_NRF_HW.H" /0
 
 
 
#line 48 "../LE1/INCLUDE\HAL/HAL_NRF.H" /0
 
 
 
 
 
 
 









 
 void hal_nrf_set_irq_mode(hal_nrf_irq_source_t int_source, unsigned char irq_state);
 



 
 void hal_nrf_activate_features(void);
 


 
 void hal_nrf_enable_dynamic_payload(unsigned char enable);
 


 
 void hal_nrf_enable_ack_payload(unsigned char enable);
 


 
 void hal_nrf_enable_dynamic_ack(unsigned char enable);
 





 
 void hal_nrf_setup_dynamic_payload(unsigned char setup);
 


 
 unsigned char hal_nrf_read_rx_payload_width(void);
 





 
 void hal_nrf_write_ack_payload(unsigned char pipe, const unsigned char *tx_pload, unsigned char length);
 








 
 unsigned char hal_nrf_get_clear_irq_flags(void);
 





 
 void hal_nrf_clear_irq_flag(hal_nrf_irq_source_t int_source);
 




 
 void hal_nrf_set_crc_mode(hal_nrf_crc_mode_t crc_mode);
 







 
 void hal_nrf_open_pipe(hal_nrf_address_t pipe_num, unsigned char auto_ack);
 




 
 void hal_nrf_close_pipe(hal_nrf_address_t pipe_num);
 






 
 void hal_nrf_set_address(const hal_nrf_address_t address, const unsigned char *addr);
 










 
 unsigned char hal_nrf_get_address (unsigned char address, unsigned char *addr);
 






 
 void hal_nrf_set_auto_retr(unsigned char retr, unsigned int delay);
 





 
 void hal_nrf_set_address_width(hal_nrf_address_width_t address_width);
 



 
 unsigned char hal_nrf_get_address_width (void);
 






 
 void hal_nrf_set_rx_payload_width(unsigned char pipe_num, unsigned char pload_width);
 









 
 unsigned char hal_nrf_get_irq_mode(unsigned char int_source);
 









 
 unsigned char hal_nrf_get_irq_flags(void);
 









 
 unsigned char hal_nrf_get_pipe_status(unsigned char pipe_num);
 








 
 unsigned char hal_nrf_get_auto_retr_status(void);
 




 
 unsigned char hal_nrf_get_packet_lost_ctr(void);
 







 
 unsigned char hal_nrf_get_rx_payload_width(unsigned char pipe_num);
 
 
 
 
 
 





 
 void hal_nrf_set_operation_mode(hal_nrf_operation_mode_t op_mode);
 




 
 void hal_nrf_set_power_mode(hal_nrf_pwr_mode_t pwr_mode);
 




 
 void hal_nrf_set_rf_channel(unsigned char channel);
 




 
 void hal_nrf_set_output_power(hal_nrf_output_power_t power);
 





 
 void hal_nrf_set_datarate(hal_nrf_datarate_t datarate);
 
 
 
 









 
 unsigned char hal_nrf_get_tx_fifo_status(void);
 








 
 unsigned char hal_nrf_tx_fifo_empty(void);
 








 
 unsigned char hal_nrf_tx_fifo_full(void);
 









 
 unsigned char hal_nrf_get_rx_fifo_status(void);
 










 
 unsigned char hal_nrf_rx_fifo_empty(void);
 








 
 unsigned char hal_nrf_rx_fifo_full(void);
 





 
 unsigned char hal_nrf_get_transmit_attempts(void);
 








 
 unsigned char hal_nrf_get_carrier_detect(void);
 
 
 





 
 unsigned char hal_nrf_get_rx_data_source(void);
 






 
 unsigned int hal_nrf_read_rx_payload(unsigned char *rx_pload);
 







 
 void hal_nrf_write_tx_payload(const unsigned char *tx_pload, unsigned char length);
 










 
 void hal_nrf_write_tx_payload_noack(const unsigned char *tx_pload, unsigned char length);
 




 
 void hal_nrf_reuse_tx(void);
 







 
 unsigned char hal_nrf_get_reuse_tx_status(void);
 




 
 void hal_nrf_flush_rx(void);
 




 
 void hal_nrf_flush_tx(void);
 





 
 unsigned char hal_nrf_nop(void);
 
 
 
 
 
 





 
 void hal_nrf_set_pll_mode(unsigned char pll_lock);
 





 
 void hal_nrf_set_lna_gain(unsigned char lna_gain);
 




 
 void hal_nrf_enable_continious_wave (unsigned char enable);
 


 
 unsigned char hal_nrf_get_rssi(void);
 
 
 
 
 
 
 
 







 
 unsigned char hal_nrf_rw(unsigned char value);
 
 


 
 
#line 45 "../LE1/INCLUDE\EPL/EPL_RF_EN.H" /0
 
 


 
 typedef enum {
 RF_EN_CRC_OFF,         
 RF_EN_CRC_8BIT,    
 RF_EN_CRC_16BIT        
 } epl_rf_en_crc_mode_t;
 


 
 typedef enum {
 RF_EN_1MBPS,           
 RF_EN_2MBPS            
 } epl_rf_en_datarate_t;
 


 
 typedef enum {
 RF_EN_AUTO_ACK_OFF,	 
 RF_EN_AUTO_ACK_ON		 
 } epl_rf_en_auto_ack_t;
 
 typedef enum {
 RF_EN_SPI_CLK_RATE_1_OVER_2,
 RF_EN_SPI_CLK_RATE_1_OVER_4 = 2,
 RF_EN_SPI_CLK_RATE_1_OVER_8,
 RF_EN_SPI_CLK_RATE_1_OVER_16,
 RF_EN_SPI_CLK_RATE_1_OVER_32,
 RF_EN_SPI_CLK_RATE_1_OVER_64,
 } epl_rf_en_spi_clk_rate_t;
 
 
 
 
 
 struct epl_lu1_rf_en_config {
 
 unsigned char channel;
 
 
 unsigned char addr_width;
 
 char my_tx_dst_addr[5];
 
 char my_prx_addr[5];
 
 unsigned char data_length;
 
 epl_rf_en_datarate_t datarate;
 
 epl_rf_en_crc_mode_t crc_mode;
 
 unsigned char auto_ack;
 
 unsigned char auto_retr;
 
 unsigned int auto_retr_delay;
 };
 















 
 void epl_rf_en_init(unsigned char in_channel, 		 
 epl_rf_en_datarate_t in_datarate, 
 char in_output_power, 			 
 unsigned char in_auto_retr,				 
 unsigned int in_auto_retr_delay,		 
 char in_addr_width, 			 
 epl_rf_en_crc_mode_t in_crc_mode,	 
 unsigned char in_rf_int);					 
 










 
 
 void epl_rf_en_rcv_pipe_config(hal_nrf_address_t in_pipe_num, 		 
 char *in_pipe_rcv_addr,				 
 unsigned char in_pipe_pload_length,	 
 epl_rf_en_auto_ack_t in_auto_ack);					 
 







 
 void epl_rf_en_easy_start_tx(unsigned char channel, unsigned char auto_retr, unsigned int delay);
 







 
 void epl_rf_en_easy_start_rx(unsigned char channel, unsigned char pload_len, unsigned char auto_ack);
 





 
 
 void epl_rf_en_quick_init(struct epl_lu1_rf_en_config *in_cfg);
 


 
 void epl_rf_en_enter_tx_mode(void);
 


 
 void epl_rf_en_enter_rx_mode(void);
 




 
 void epl_rf_en_set_dst_addr(unsigned char *in_dst_addr);
 






 
 void epl_rf_en_send_dst(unsigned char *in_dst_addr, unsigned char *in_tx_pload, unsigned char in_pload_length);
 






 
 void epl_rf_en_send(unsigned char *in_tx_pload, unsigned char in_pload_length);
 





 
 unsigned char epl_rf_en_rx_pload_is_empty(void);
 




 
 void epl_rf_en_read_rx_pload(unsigned char *out_rx_pload);
 





 
 void epl_rf_en_wait_rcv_msg(unsigned char *out_rx_pload);
 
 
 
#line 35 "../LE1/lib/EPL/epl_rf_en.c" /0
 
  
#line 1 "../LE1/INCLUDE\HAL/HAL_NRF_HW.H" /0










 
 
 
#line 14 "../LE1/INCLUDE\HAL/HAL_NRF_HW.H" /1
  
 
  
 


 
  
 


 
  
 


 
  
 


 
  
 


 
  







 
 
#line 51 "../LE1/INCLUDE\HAL/HAL_NRF_HW.H" /0
 
 
 
#line 36 "../LE1/lib/EPL/epl_rf_en.c" /0
 
  
#line 1 "../LE1/INCLUDE\HAL/HAL_NRF.H" /0











 
 

























 
 
 
#line 42 "../LE1/INCLUDE\HAL/HAL_NRF.H" /1
  
 
  
  
 
  
  
 
 
 
 
 
 









 
 
 



 
 
 


 
 
 


 
 
 


 
 
 





 
 
 


 
 
 





 
 
 








 
 
 





 
 
 




 
 
 







 
 
 




 
 
 






 
 
 










 
 
 






 
 
 





 
 
 



 
 
 






 
 
 









 
 
 









 
 
 









 
 
 








 
 
 




 
 
 







 
 
 
 
 
 
 
 





 
 
 




 
 
 




 
 
 




 
 
 





 
 
 
 
 
 









 
 
 








 
 
 








 
 
 









 
 
 










 
 
 








 
 
 





 
 
 








 
 
 
 
 





 
 
 






 
 
 







 
 
 










 
 
 




 
 
 







 
 
 




 
 
 




 
 
 





 
 
 
 
 
 
 
 





 
 
 





 
 
 




 
 
 


 
 
 
 
 
 
 
 
 
 







 
 
 
 
#line 536 "../LE1/INCLUDE\HAL/HAL_NRF.H" /0


 
 
#line 37 "../LE1/lib/EPL/epl_rf_en.c" /0
 
 















 
 void epl_rf_en_init(unsigned char in_channel, epl_rf_en_datarate_t in_datarate, char in_output_power, unsigned char in_auto_retr, unsigned int in_auto_retr_delay, char in_addr_width, epl_rf_en_crc_mode_t in_crc_mode, unsigned char in_rf_int)
 {
 
 RFCKEN = 1;	 
 
  do { RFCE = 0;} while(0);
 
 
 hal_nrf_close_pipe(HAL_NRF_ALL);  
 
 hal_nrf_set_datarate(in_datarate);
 hal_nrf_set_auto_retr(in_auto_retr, in_auto_retr_delay);  
 hal_nrf_set_output_power(in_output_power);  
 hal_nrf_set_crc_mode(in_crc_mode);
 
 hal_nrf_set_address_width(in_addr_width);  
 
 hal_nrf_set_operation_mode(HAL_NRF_PTX);  
 
 hal_nrf_set_rf_channel(in_channel);
 hal_nrf_set_power_mode(HAL_NRF_PWR_UP);  
 
 hal_nrf_get_clear_irq_flags();
 
 
 RF = in_rf_int;
 }
 
 










 
 
 void epl_rf_en_rcv_pipe_config(hal_nrf_address_t in_pipe_num, char *in_pipe_rcv_addr, unsigned char in_pipe_pload_length, epl_rf_en_auto_ack_t in_auto_ack) 
 {
 hal_nrf_open_pipe(in_pipe_num, in_auto_ack);  
 hal_nrf_set_address(in_pipe_num, in_pipe_rcv_addr);  
 hal_nrf_set_rx_payload_width(in_pipe_num, in_pipe_pload_length);
 }
 







 
 void epl_rf_en_easy_start_tx(unsigned char channel, unsigned char auto_retr, unsigned int delay){
 
 char my_tx_dst_addr[5] = {0x65,0x65,0x65,0x65,0x65};
 
 
 epl_rf_en_init(channel,
 RF_EN_1MBPS,
 HAL_NRF_0DBM,
 auto_retr,
 delay,
 5,
 RF_EN_CRC_16BIT,
  1);
 
 epl_rf_en_set_dst_addr(my_tx_dst_addr);
 
 if( auto_retr != 0){
 
 
 epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE0,
 my_tx_dst_addr,
 8,
 RF_EN_AUTO_ACK_ON
 );
 }
 
 epl_rf_en_enter_tx_mode();
 }
 







 
 void epl_rf_en_easy_start_rx(unsigned char channel, unsigned char pload_len, unsigned char auto_ack){
 
 char my_rx_dst_addr[5] = {0x65,0x65,0x65,0x65,0x65};
 
 
 epl_rf_en_init(channel,
 RF_EN_1MBPS,
 HAL_NRF_0DBM,
 0,					 
 0,
 5,
 RF_EN_CRC_16BIT,
  1);
 
 
 epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE0,
 my_rx_dst_addr,
 pload_len,
 auto_ack
 );
 
 epl_rf_en_enter_rx_mode();
 }
 





 
 
 void epl_rf_en_quick_init(struct epl_lu1_rf_en_config *in_cfg)
 {
 
 
 epl_rf_en_init(in_cfg->channel,
 in_cfg->datarate,
 HAL_NRF_0DBM,
 in_cfg->auto_retr,
 in_cfg->auto_retr_delay,
 in_cfg->addr_width,
 in_cfg->crc_mode,
  0);
 
 epl_rf_en_set_dst_addr(in_cfg->my_tx_dst_addr);
 
 
 
 epl_rf_en_rcv_pipe_config(HAL_NRF_PIPE0,
 in_cfg->my_prx_addr,
 in_cfg->data_length,
 in_cfg->auto_ack
 );
 }
 


 
 void epl_rf_en_enter_tx_mode(void)
 {
 RFCE = 0;
 hal_nrf_set_operation_mode(HAL_NRF_PTX);  
 }
 


 
 void epl_rf_en_enter_rx_mode(void)
 {
 RFCE = 1;
 hal_nrf_set_operation_mode(HAL_NRF_PRX);  
 }
 




 
 void epl_rf_en_set_dst_addr(unsigned char *in_dst_addr)
 {
 hal_nrf_set_address(HAL_NRF_TX, in_dst_addr);  
 }
 






 
 void epl_rf_en_send_dst(unsigned char *in_dst_addr, unsigned char *in_tx_pload, unsigned char in_pload_length)
 {
 hal_nrf_set_address(HAL_NRF_TX, in_dst_addr);  
 epl_rf_en_enter_tx_mode();
 hal_nrf_write_tx_payload(in_tx_pload, in_pload_length);
  do { unsigned char count; count = 20; do { RFCE = 1;} while(0); while(count--) ; do { RFCE = 0;} while(0); } while(0);
 }
 






 
 void epl_rf_en_send(unsigned char *in_tx_pload, unsigned char in_pload_length)
 {
 epl_rf_en_enter_tx_mode();
 hal_nrf_write_tx_payload(in_tx_pload, in_pload_length);
  do { unsigned char count; count = 20; do { RFCE = 1;} while(0); while(count--) ; do { RFCE = 0;} while(0); } while(0);
 }
 





 
 unsigned char epl_rf_en_rx_pload_is_empty(void)
 {
 unsigned char rx_fifo_status;
 rx_fifo_status = hal_nrf_get_rx_fifo_status();
 if (rx_fifo_status == 0x01)
 {
 return 1;	 
 }
 else
 { 
 return 0;	 
 }
 }
 




 
 void epl_rf_en_read_rx_pload(unsigned char *out_rx_pload)
 {
 hal_nrf_read_rx_payload(out_rx_pload);
 
 }
 





 
 void epl_rf_en_wait_rcv_msg(unsigned char *out_rx_pload)
 {
 epl_rf_en_enter_rx_mode();
 while (epl_rf_en_rx_pload_is_empty());
 hal_nrf_read_rx_payload(out_rx_pload);
 }
 
