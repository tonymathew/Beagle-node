/* Copyright (c) 2008 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is confidential property of Nordic 
 * Semiconductor. The use, copying, transfer or disclosure of such information 
 * is prohibited except by express written agreement with Nordic Semiconductor.
 *
 * $LastChangedRevision:$
 */

/** @file
 *
 * The nRF24LE1 example application.
 *
 * @author Rune Brandsegg
 * @author Ivar C. OEsthus
 *
 */

#include <HAL/hal_nrf.h>
#include <EPL/epl_utils.h>
#include <nRF24LE1/radio.h>
#include <nRF24LE1/application.h>

#include <stdint.h>

uint8_t xdata packet[RADIO_MAX_PL];     // Buffer for sending or receiving
                                        // packet.
void transmitter_mode(void)
{
  LED1 = OFF;                           // LED2 blank, indicates PTX mode
  while(true)
  {
    while(radio_busy())                 // Wait until radio ready
      ;

    //if(!B0)
    //{
      send_packet(CMD1);
      //while(!B0)
       // ;                               // Wait until B0 relesed...
    //}
   // if(!B1)
    //{
    //  send_packet(CMD2);
      //while(!B1)
      //  ;                               // Wait until B1 relesed...
    //}
  }
}
void receiver_mode(void)
{
  uint8_t command;
  LED1 = ON;                            // LED2 lit, indicates PRX mode
  while(true)
  {
    if(radio_data_received())
    {
      command = read_packet();
      switch(command)
      {
        case CMD1:                      // "Link-packet" received
          LED0_BLINK();
          break;

        case CMD2:                      // "Boot message packet" received
          //boot_mess();                  // Show boot message
          LED1 = OFF;
          break;

        default:
          break;
      }
    }
  }
}

void send_packet(uint8_t command)
{
  bool packet_sent;
  uint8_t data_length;

  LED0 = ON;                            // Trans.; flash LED1...

  /* Assemble packet  */
  packet[0] = CMD_SEND_DATA;            // Add TYPE (data = 0x00)
  packet[1] = data_length = 1;          // Add LENGTH (1 byte)
  packet[DATA_POS] = command;           // Add DATA to send

  /* 
     .... Room for encryption of message .... 
                                              */

  /* Send packet with radio */
  radio_send_packet(packet, data_length+DATA_POS);

  /* Wait for respons from radio, TX_DS or MAX_RT */
  while(radio_busy())
    ;

  packet_sent = radio_packet_sent();

  if(packet_sent)
  {
    LED0_BLINK();                       // Packet sent, flash LED1
  }
  else
  {
    LED1_BLINK();                       // Packet lost, flash LED2
  }
  LED0 = OFF;
}

uint8_t read_packet(void)
{
  uint8_t command, data_length,type, pck_length;

  /* Get the packet	from radio */
  pck_length = radio_read_data(packet);

  /* Disassemble packet */
  type        =  packet[0];             // Get TYPE of message
  data_length =  packet[1];             // Get LENGTH of data part

  /* .... Room for decryption of message .... */

  command = packet[DATA_POS];           // Get the received command
  return command;
}

void radio_irq(void) interrupt RF_READY_INT_VECT  
{
  radio_interrupt();  
}
