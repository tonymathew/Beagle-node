
#line 1 "../LE1/lib/HAL/hal_nrf.c" /0











 
 


 
 
 
 
 
 
 
  
#line 1 "../LE1/INCLUDE\STDINT.H" /0








 
 



 
 
 
 
 
 
 
 typedef unsigned char uint8_t;         
 
 typedef signed char int8_t;           
 
 typedef unsigned int uint16_t;         
 
 typedef signed int int16_t;           
 
 typedef unsigned long uint32_t;        
 
 typedef signed long int32_t;          
 
 
 
 
 
 
 
 
#line 23 "../LE1/lib/HAL/hal_nrf.c" /0
 
  
#line 1 "../LE1/INCLUDE\STDBOOL.H" /0








 
 



 
 
 
 
 
 
 typedef unsigned char _Bool;  
 
 
 
 
 
 
 
#line 24 "../LE1/lib/HAL/hal_nrf.c" /0
 
 
  
#line 1 "../LE1/INCLUDE\HAL/NORDIC_COMMON.H" /0





 
 




 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
#line 26 "../LE1/lib/HAL/hal_nrf.c" /0
 
  
#line 1 "../LE1/INCLUDE\HAL/HAL_NRF.H" /0











 
 

























 
 
 
 
 
  
#line 1 "../LE1/INCLUDE\STDINT.H" /0








 
 



 
 
 
#line 17 "../LE1/INCLUDE\STDINT.H" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
#line 44 "../LE1/INCLUDE\HAL/HAL_NRF.H" /0
#line 44 "../LE1/INCLUDE\HAL/HAL_NRF.H" /0
 
  
#line 1 "../LE1/INCLUDE\STDBOOL.H" /0








 
 



 
 
 
#line 17 "../LE1/INCLUDE\STDBOOL.H" /1
  
 
 
 
 
  
  
  
  
 
 
#line 45 "../LE1/INCLUDE\HAL/HAL_NRF.H" /0
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
 
 
 
#line 16 "../LE1/INCLUDE\HAL/HAL_NRF_HW.H" /0
 
 


 
 
 


 
 
 


 
 
 


 
 
 


 
 







 
 
 
 
 
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
 
 


 
 
#line 27 "../LE1/lib/HAL/hal_nrf.c" /0
 
 
 
 
 






 
 unsigned char hal_nrf_read_reg(unsigned char reg);
 







 
 unsigned char hal_nrf_write_reg(unsigned char reg, unsigned char value);
 










 
 unsigned int hal_nrf_read_multibyte_reg(unsigned char reg, unsigned char *pbuf);
 







 
 void hal_nrf_write_multibyte_reg(unsigned char reg, const unsigned char *pbuf, unsigned char length);
 



 
 typedef union {
 unsigned char value;
 struct {
 unsigned char prim_rx : 1;
 unsigned char pwr_up : 1;
 unsigned char crc0 : 1;
 unsigned char en_crc : 1;
 unsigned char mask_max_rt : 1;
 unsigned char mask_tx_ds : 1;
 unsigned char mask_rx_dr : 1;
 const unsigned char : 1;
 } bits;
 } config_t;
 




 
 typedef union {
 unsigned char value;
 struct {
 unsigned char pipe_0 : 1;
 unsigned char pipe_1 : 1;
 unsigned char pipe_2 : 1;
 unsigned char pipe_3 : 1;
 unsigned char pipe_4 : 1;
 unsigned char pipe_5 : 1;
 const unsigned char : 2;
 } bits;
 } en_pipes_t;
 



 
 typedef union {
 unsigned char value;
 struct {
 unsigned char aw : 2;
 const unsigned char : 6;		
 } bits;
 } setup_aw_t;
 



 
 typedef union {
 unsigned char value;
 struct {
 unsigned char arc : 4;
 unsigned char ard : 4;
 } bits;
 } setup_retr_t;
 



 
 typedef union {
 unsigned char value;
 struct {
 unsigned char rf_ch : 7;
 const unsigned char : 1;
 } bits;
 } rf_ch_t;
 



 
 typedef union {
 unsigned char value;
 struct {
 const unsigned char : 1;
 unsigned char rf_pwr : 2;
 unsigned char rf_dr_high : 1;
 unsigned char pll_lock : 1;
 unsigned char rf_dr_low : 1;
 const unsigned char : 1;
 unsigned char cont_wave : 1;
 } bits;
 } rf_setup_t;
 



 
 typedef union {
 unsigned char value;
 struct {
 unsigned char rx_pw : 6;
 const unsigned char : 2;
 } bits;
 } rx_pw_t;
 



 
 typedef union {
 unsigned char value;
 struct {
 unsigned char en_dyn_ack : 1;
 unsigned char en_ack_pay : 1;
 unsigned char en_dpl : 1;
 const unsigned char : 5;
 } bits;
 } feature_t;
 



 
 typedef union {
 unsigned int value;
 struct {
 unsigned char lnb_out : 3;
 unsigned char lnb_in : 3;
 unsigned char agc_en : 1;
 unsigned char agc_th1mbit : 3;
 unsigned char agc_th2mbit : 3;
 unsigned char cd_th : 3;
 } bits;
 } agc_config_t;
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void hal_nrf_set_operation_mode(hal_nrf_operation_mode_t op_mode)
 {
 config_t config;
 config.value = hal_nrf_read_reg (0x00);
 
 if(op_mode == HAL_NRF_PRX)
 {
 config.bits.prim_rx = 1;
 }
 else
 {
 config.bits.prim_rx = 0;
 }
 
 hal_nrf_write_reg (0x00, config.value);
 }
 
 void hal_nrf_set_power_mode(hal_nrf_pwr_mode_t pwr_mode)
 {
 config_t config;
 config.value = hal_nrf_read_reg (0x00);
 
 if(pwr_mode == HAL_NRF_PWR_UP)
 {
 config.bits.pwr_up = 1;
 }
 else
 {
 config.bits.pwr_up = 0;
 }
 
 hal_nrf_write_reg (0x00, config.value);
 }
 
 void hal_nrf_set_crc_mode(hal_nrf_crc_mode_t crc_mode)
 {
 config_t config;
 config.value = hal_nrf_read_reg (0x00);
 
 switch (crc_mode)
 {
 case HAL_NRF_CRC_OFF:
 config.bits.en_crc = 0;
 break;
 case HAL_NRF_CRC_8BIT:
 config.bits.en_crc = 1;
 config.bits.crc0 = 0;
 break;
 case HAL_NRF_CRC_16BIT:
 config.bits.en_crc = 1;
 config.bits.crc0 = 1;
 break;
 default:
 break;
 } 
 
 hal_nrf_write_reg (0x00, config.value);
 }
 
 void hal_nrf_set_irq_mode(hal_nrf_irq_source_t int_source, unsigned char irq_state)
 {
 config_t config;
 config.value = hal_nrf_read_reg (0x00);
 
 switch (int_source)
 {
 case HAL_NRF_MAX_RT:
 config.bits.mask_max_rt = irq_state ? 0 : 1;
 break;
 case HAL_NRF_TX_DS:
 config.bits.mask_tx_ds = irq_state ? 0 : 1;
 break;
 case HAL_NRF_RX_DR:
 config.bits.mask_rx_dr = irq_state ? 0 : 1;
 break;
 }
 
 hal_nrf_write_reg (0x00, config.value);
 }
 
 unsigned char hal_nrf_get_clear_irq_flags(void)
 {
 unsigned char retval;
 
 retval = hal_nrf_write_reg (0x07, (0x40|0x20|0x10));
 
 return (retval & (0x40|0x20|0x10));
 }
 
 void hal_nrf_clear_irq_flag(hal_nrf_irq_source_t int_source)
 {
 hal_nrf_write_reg (0x07, ((unsigned char) (1<<( (unsigned char) (int_source) ))));
 }
 
 unsigned char hal_nrf_get_irq_flags(void)
 {
 return hal_nrf_nop() & (0x40|0x20|0x10);
 }
 
 void hal_nrf_open_pipe(hal_nrf_address_t pipe_num, unsigned char auto_ack)
 {
 en_pipes_t en_rxaddr;
 en_pipes_t en_aa;
 en_rxaddr.value = hal_nrf_read_reg (0x02);
 en_aa.value = hal_nrf_read_reg (0x01);
 
 switch(pipe_num)
 {
 case HAL_NRF_PIPE0:
 case HAL_NRF_PIPE1:
 case HAL_NRF_PIPE2:
 case HAL_NRF_PIPE3:
 case HAL_NRF_PIPE4:
 case HAL_NRF_PIPE5:
 en_rxaddr.value = en_rxaddr.value | ((unsigned char) (1<<( (unsigned char) (pipe_num) )));
 
 if(auto_ack)
 {
 en_aa.value = en_aa.value | ((unsigned char) (1<<( (unsigned char) (pipe_num) )));
 }
 else
 {
 en_aa.value = en_aa.value & ~((unsigned char) (1<<( (unsigned char) (pipe_num) )));
 }
 break;
 
 case HAL_NRF_ALL:
 en_rxaddr.value = ~(0x40|0x80);
 
 if(auto_ack)
 {
 en_aa.value = ~(0x40|0x80);
 }
 else
 {
 en_aa.value = 0;
 }
 break;
 
 default:
 break;
 }
 
 hal_nrf_write_reg (0x02, en_rxaddr.value);
 hal_nrf_write_reg (0x01, en_aa.value);
 }
 
 void hal_nrf_close_pipe(hal_nrf_address_t pipe_num)
 {
 en_pipes_t en_rxaddr;
 en_pipes_t en_aa;
 en_rxaddr.value = hal_nrf_read_reg (0x02);
 en_aa.value = hal_nrf_read_reg (0x01);
 
 switch(pipe_num)
 {
 case HAL_NRF_PIPE0:
 case HAL_NRF_PIPE1:
 case HAL_NRF_PIPE2:
 case HAL_NRF_PIPE3:
 case HAL_NRF_PIPE4:
 case HAL_NRF_PIPE5:
 en_rxaddr.value = en_rxaddr.value & ~((unsigned char) (1<<( (unsigned char) (pipe_num) )));
 en_aa.value = en_aa.value & ~((unsigned char) (1<<( (unsigned char) (pipe_num) )));
 break;
 
 case HAL_NRF_ALL:
 en_rxaddr.value = 0;
 en_aa.value = 0;
 break;
 
 default:
 break;
 }
 
 hal_nrf_write_reg (0x02, en_rxaddr.value);
 hal_nrf_write_reg (0x01, en_aa.value);
 }
 
 void hal_nrf_set_address(const hal_nrf_address_t address, const unsigned char *addr)
 {
 switch(address)
 {
 case HAL_NRF_TX:
 case HAL_NRF_PIPE0:
 case HAL_NRF_PIPE1:
 hal_nrf_write_multibyte_reg(0x20 + 0x0A + (unsigned char) address, addr, hal_nrf_get_address_width());
 break;
 case HAL_NRF_PIPE2:
 case HAL_NRF_PIPE3:
 case HAL_NRF_PIPE4:
 case HAL_NRF_PIPE5:
 hal_nrf_write_reg (0x0A + (unsigned char) address, *addr);
 break;
 
 default:
 break;
 }
 }
 
 unsigned char hal_nrf_get_address(unsigned char address, unsigned char *addr)
 {
 switch (address)
 {
 case HAL_NRF_PIPE0:
 case HAL_NRF_PIPE1:
 case HAL_NRF_TX:
 return hal_nrf_read_multibyte_reg (address, addr);
 default:
 *addr = hal_nrf_read_reg(0x0A + address);
 return 1;
 }
 }
 
 void hal_nrf_set_auto_retr(unsigned char retr, unsigned int delay)
 {
 setup_retr_t setup_retr;
 setup_retr.bits.ard = (delay / 250) - 1;
 setup_retr.bits.arc = retr;
 
 hal_nrf_write_reg (0x04, setup_retr.value);
 }
 
 void hal_nrf_set_address_width(hal_nrf_address_width_t aw)
 {
 setup_aw_t setup_aw;
 setup_aw.bits.aw = (unsigned char)aw - 2;
 
 hal_nrf_write_reg (0x03, setup_aw.value);
 }
 
 unsigned char hal_nrf_get_address_width (void)
 {
 return hal_nrf_read_reg (0x03) + 2;
 }
 
 void hal_nrf_set_rx_payload_width(unsigned char pipe_num, unsigned char pload_width)
 {
 hal_nrf_write_reg (0x11 + pipe_num, pload_width);
 }
 
 unsigned char hal_nrf_get_pipe_status(unsigned char pipe_num)
 {
 en_pipes_t en_rxaddr;
 en_pipes_t en_aa;
 unsigned char en_rx_r, en_aa_r;
 
 en_rxaddr.value = hal_nrf_read_reg (0x02);
 en_aa.value = hal_nrf_read_reg (0x01);
 
 switch (pipe_num)
 {
 case 0:
 en_rx_r = en_rxaddr.bits.pipe_0;
 en_aa_r = en_aa.bits.pipe_0;
 break;
 case 1:
 en_rx_r = en_rxaddr.bits.pipe_1;
 en_aa_r = en_aa.bits.pipe_1;
 break;
 case 2:
 en_rx_r = en_rxaddr.bits.pipe_2;
 en_aa_r = en_aa.bits.pipe_2;
 break;
 case 3:
 en_rx_r = en_rxaddr.bits.pipe_3;
 en_aa_r = en_aa.bits.pipe_3;
 break;
 case 4:
 en_rx_r = en_rxaddr.bits.pipe_4;
 en_aa_r = en_aa.bits.pipe_4;
 break;
 case 5:
 en_rx_r = en_rxaddr.bits.pipe_5;
 en_aa_r = en_aa.bits.pipe_5;
 break;
 default:
 en_rx_r = 0;
 en_aa_r = 0;
 break;
 }
 
 return (unsigned char)(en_aa_r << 1) + en_rx_r;
 }
 
 
 unsigned char hal_nrf_get_auto_retr_status(void)
 {
 return hal_nrf_read_reg(0x08);
 }
 
 unsigned char hal_nrf_get_packet_lost_ctr(void)
 {
 return ((hal_nrf_read_reg(0x08) & (0x80|0x40|0x20|0x10)) >> 4);
 }
 
 unsigned char hal_nrf_get_rx_payload_width(unsigned char pipe_num)
 {
 unsigned char pw;
 
 switch (pipe_num)
 {
 case 0:
 pw = hal_nrf_read_reg (0x11);
 break;      
 case 1:
 pw = hal_nrf_read_reg (0x12);
 break;
 case 2:
 pw = hal_nrf_read_reg (0x13);
 break;
 case 3:
 pw = hal_nrf_read_reg (0x14);
 break;
 case 4:
 pw = hal_nrf_read_reg (0x15);
 break;
 case 5:
 pw = hal_nrf_read_reg (0x16);
 break;
 default:
 pw = 0;
 break;
 }
 
 return pw;
 }
 
 void hal_nrf_set_rf_channel(unsigned char channel)
 {
 rf_ch_t rf_ch;
 rf_ch.bits.rf_ch = channel;
 
 hal_nrf_write_reg (0x05, rf_ch.value);
 }
 
 void hal_nrf_set_output_power(hal_nrf_output_power_t power)
 {
 rf_setup_t rf_setup;
 rf_setup.value = hal_nrf_read_reg (0x06);
 
 rf_setup.bits.rf_pwr = (unsigned char)power;
 
 hal_nrf_write_reg (0x06, rf_setup.value);
 }
 
 void hal_nrf_set_datarate(hal_nrf_datarate_t datarate)
 {
 rf_setup_t rf_setup;
 rf_setup.value = hal_nrf_read_reg (0x06);
 
 switch (datarate)
 {
 case HAL_NRF_250KBPS:
 rf_setup.bits.rf_dr_low = 1;
 rf_setup.bits.rf_dr_high = 0;
 break;
 case HAL_NRF_1MBPS:
 rf_setup.bits.rf_dr_low = 0;
 rf_setup.bits.rf_dr_high = 0;
 break;
 case HAL_NRF_2MBPS:
 default:
 rf_setup.bits.rf_dr_low = 0;
 rf_setup.bits.rf_dr_high = 1;
 break;
 }
 
 hal_nrf_write_reg (0x06, rf_setup.value);
 }
 
 unsigned char hal_nrf_rx_fifo_empty(void)
 {
 if(hal_nrf_get_rx_data_source()==7)
 {
 return 1;
 }
 else
 {
 return 0;
 }
 }
 
 unsigned char hal_nrf_rx_fifo_full(void)
 {
 return (unsigned char)((hal_nrf_read_reg(0x17)>> 0) & 1);
 }
 
 unsigned char hal_nrf_tx_fifo_empty(void)
 {
 return (unsigned char)((hal_nrf_read_reg(0x17) >> 4) & 1);
 }
 
 unsigned char hal_nrf_tx_fifo_full(void)
 {
 return (unsigned char)((hal_nrf_read_reg(0x17) >> 5) & 1);
 }
 
 unsigned char hal_nrf_get_tx_fifo_status(void)
 {
 return ((hal_nrf_read_reg(0x17) & ((1<<5)|(1<<4))) >> 4);
 }
 
 unsigned char hal_nrf_get_rx_fifo_status(void)
 {
 return (hal_nrf_read_reg(0x17) & ((1<<1)|(1<<0)));
 }
 
 unsigned char hal_nrf_get_fifo_status(void)
 {
 return hal_nrf_read_reg(0x17);
 }
 
 unsigned char hal_nrf_get_transmit_attempts(void)
 {
 return (hal_nrf_read_reg(0x08) & (0x08|0x04|0x02|0x01));
 }
 
 unsigned char hal_nrf_get_carrier_detect(void)
 {
 return hal_nrf_read_reg(0x09) & 1;
 }
 
 void hal_nrf_activate_features(void)
 {return;}
 
 void hal_nrf_setup_dynamic_payload (unsigned char setup)
 {
 en_pipes_t dynpd;
 dynpd.value = setup & ~0xC0;
 
 hal_nrf_write_reg (0x1C, dynpd.value);
 }
 
 void hal_nrf_enable_dynamic_payload(unsigned char enable)
 {
 feature_t feature;
 feature.value = hal_nrf_read_reg (0x1D);
 feature.bits.en_dpl = (enable) ? 1 : 0;
 
 hal_nrf_write_reg (0x1D, feature.value);
 }
 
 void hal_nrf_enable_ack_payload(unsigned char enable)
 {
 feature_t feature;
 feature.value = hal_nrf_read_reg (0x1D);
 feature.bits.en_ack_pay = (enable) ? 1 : 0;
 
 hal_nrf_write_reg (0x1D, feature.value);
 }
 
 void hal_nrf_enable_dynamic_ack(unsigned char enable)
 {
 feature_t feature;
 feature.value = hal_nrf_read_reg (0x1D);
 feature.bits.en_dyn_ack = (enable) ? 1 : 0;
 
 hal_nrf_write_reg (0x1D, feature.value);
 }
 
 void hal_nrf_write_tx_payload(const unsigned char *tx_pload, unsigned char length)
 {
 hal_nrf_write_multibyte_reg(0xA0, tx_pload, length);
 }
 
 void hal_nrf_write_tx_payload_noack(const unsigned char *tx_pload, unsigned char length)
 {
 hal_nrf_write_multibyte_reg(0xB0, tx_pload, length);
 }
 
 void hal_nrf_write_ack_payload(unsigned char pipe, const unsigned char *tx_pload, unsigned char length)
 {
 hal_nrf_write_multibyte_reg(0xA8 | pipe, tx_pload, length);
 }
 
 unsigned char hal_nrf_read_rx_payload_width()
 {
 return hal_nrf_read_reg(0x60);
 }
 
 unsigned int hal_nrf_read_rx_payload(unsigned char *rx_pload)
 {
 return hal_nrf_read_multibyte_reg(((unsigned char) (HAL_NRF_RX_PLOAD)), rx_pload);
 }
 
 unsigned char hal_nrf_get_rx_data_source(void)
 {
 return ((hal_nrf_nop() & (0x08|0x04|0x02)) >> 1);
 }
 
 void hal_nrf_reuse_tx(void)
 {
  do { RFCSN = 0; } while(0);
 hal_nrf_rw(0xE3);
  do { RFCSN = 1; } while(0);
 }
 
 unsigned char hal_nrf_get_reuse_tx_status(void)
 {
 return (unsigned char)((hal_nrf_get_fifo_status() & (1<<6)) >> 6);
 }
 
 void hal_nrf_flush_rx(void)
 {
  do { RFCSN = 0; } while(0);
 hal_nrf_rw(0xE2);
  do { RFCSN = 1; } while(0);
 }
 
 void hal_nrf_flush_tx(void)
 {
  do { RFCSN = 0; } while(0);
 hal_nrf_rw(0xE1);
  do { RFCSN = 1; } while(0);
 }
 
 unsigned char hal_nrf_nop(void)
 {
 unsigned char retval;
 
  do { RFCSN = 0; } while(0);
 retval = hal_nrf_rw(0xFF);
  do { RFCSN = 1; } while(0);
 
 return retval;
 }
 
 void hal_nrf_set_pll_mode(unsigned char pll_lock)
 {
 rf_setup_t rf_setup;
 rf_setup.value = hal_nrf_read_reg (0x06);
 rf_setup.bits.pll_lock = (pll_lock) ? 1 : 0;
 
 hal_nrf_write_reg(0x06, rf_setup.value);
 }
 
 unsigned char hal_nrf_get_rssi(void)
 {
 agc_config_t agc_config;
 unsigned char value[2];
 hal_nrf_read_multibyte_reg(0x1E, value);
 agc_config.value = ((value[1]) | (value[0] << 8));
 return ((unsigned char) (agc_config.bits.lnb_out));
 }
 
 void hal_nrf_enable_continious_wave (unsigned char enable)
 {
 rf_setup_t rf_setup;
 rf_setup.value = hal_nrf_read_reg (0x06);
 rf_setup.bits.cont_wave = (enable ? 1 : 0);
 
 hal_nrf_write_reg(0x06, rf_setup.value);
 }
 
 unsigned char hal_nrf_read_reg(unsigned char reg)
 {
 unsigned char temp;
 
  do { RFCSN = 0; } while(0);
 hal_nrf_rw(reg);
 temp = hal_nrf_rw(0);
  do { RFCSN = 1; } while(0);
 
 return temp;
 }
 
 unsigned char hal_nrf_write_reg(unsigned char reg, unsigned char value)
 {
 unsigned char retval;
 
  do { RFCSN = 0; } while(0);
 retval = hal_nrf_rw(0x20 + reg);
 hal_nrf_rw(value);
  do { RFCSN = 1; } while(0);
 
 return retval;
 }
 
 unsigned int hal_nrf_read_multibyte_reg(unsigned char reg, unsigned char *pbuf)
 {
 unsigned char ctr, length;
 switch(reg)
 {
 case HAL_NRF_PIPE0:
 case HAL_NRF_PIPE1:
 case HAL_NRF_TX:
 length = ctr = hal_nrf_get_address_width();
  do { RFCSN = 0; } while(0);
 hal_nrf_rw(0x0A + reg);
 break;
 
 case HAL_NRF_RX_PLOAD:
 if( (reg = hal_nrf_get_rx_data_source()) < 7)
 {
 length = ctr = hal_nrf_read_rx_payload_width();
 
  do { RFCSN = 0; } while(0);
 hal_nrf_rw(0x61);
 }
 else
 {
 ctr = length = 0;
 }
 break;
 
 case 0x1E:
 ctr = length = 2;
  do { RFCSN = 0; } while(0);
 hal_nrf_rw (0x1E);
 break;
 
 default:
 ctr = length = 0;
 break;
 }
 
 while(ctr--)
 {
 *pbuf++ = hal_nrf_rw(0);
 }
 
  do { RFCSN = 1; } while(0);
 
 return (((unsigned int) reg << 8) | length);
 }
 
 void hal_nrf_write_multibyte_reg(unsigned char cmd, const unsigned char *pbuf, unsigned char length)
 {
  do { RFCSN = 0; } while(0);
 
 hal_nrf_rw(cmd);
 
 while(length--)
 {
 hal_nrf_rw(*pbuf++);
 }
 
  do { RFCSN = 1; } while(0);
 }
