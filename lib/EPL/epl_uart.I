
#line 1 "../LE1/lib/EPL/epl_uart.c" /0



 
 
  
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
 
 
 
#line 6 "../LE1/lib/EPL/epl_uart.c" /0
 
  
#line 1 "../LE1/INCLUDE\STDINT.H" /0








 
 



 
 
 
 
 
 
 
 typedef unsigned char uint8_t;         
 
 typedef signed char int8_t;           
 
 typedef unsigned int uint16_t;         
 
 typedef signed int int16_t;           
 
 typedef unsigned long uint32_t;        
 
 typedef signed long int32_t;          
 
 
 
 
 
 
 
 
#line 7 "../LE1/lib/EPL/epl_uart.c" /0
 
  
#line 1 "../LE1/INCLUDE\EPL/EPL_UART.H" /0








 
 
 
 
 
  
#line 1 "../LE1/INCLUDE\STDINT.H" /0








 
 



 
 
 
#line 17 "../LE1/INCLUDE\STDINT.H" /1
  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
 
 
 
#line 14 "../LE1/INCLUDE\EPL/EPL_UART.H" /0
#line 14 "../LE1/INCLUDE\EPL/EPL_UART.H" /0
 
 
 typedef enum
 {
 UART_BAUD_9K6,       
 UART_BAUD_19K2,      
 UART_BAUD_38K4,      
 UART_BAUD_57K6,      
 } epl_uart_baudrate_t;
 




 
 void epl_uart_init(epl_uart_baudrate_t baud);
 


 
 void epl_uart_putchar(unsigned char ch);
 
 


 
 void epl_uart_putstr(unsigned char* str);
 
 


 
 unsigned char epl_uart_getchar(void);
 


 
 void epl_uart_putint(unsigned int num) reentrant;
 
 


 
 void epl_uart_puthex(unsigned int num) reentrant;
 
 int epl_uart_rcv_buf_is_empty(void);
 
 
#line 8 "../LE1/lib/EPL/epl_uart.c" /0
 
 
 
 
 
 
 
 
 void epl_uart_init(epl_uart_baudrate_t baud){
 unsigned int temp;
 
 ES0 = 0;                                       
 REN0 = 1;                                      
 SM0 = 0;                                       
 SM1 = 1;                                       
 PCON |= 0x80;                                  
 ADCON |= 0x80;                                 
 
 switch(baud){
 case UART_BAUD_57K6:
 temp = 1015;
 break;
 case UART_BAUD_38K4:
 temp = 1011;
 break;
 case UART_BAUD_9K6:
 temp = 972;
 break;
 case UART_BAUD_19K2:
 default:
 temp = 998;
 break;
 }
 
 S0RELL = (unsigned char)temp;
 S0RELH = (unsigned char)(temp >> 8);
 
 P0DIR |= 0x10;       
 P0DIR &= ~0x08;		 
 
 TI0 = 0;
 RI0 = 0;
 }
 
 void epl_uart_putchar(unsigned char ch){
 S0BUF = ch;	 
 while (!TI0)	 
 ;
 TI0 = 0;	 
 }
 
 void epl_uart_putstr(unsigned char *str){
 while(*str)
 epl_uart_putchar(*str++);
 }
 
 unsigned char epl_uart_getchar(void){
 unsigned char ret;
 
 while (!RI0)	 
 ;
 RI0 = 0;		 
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
