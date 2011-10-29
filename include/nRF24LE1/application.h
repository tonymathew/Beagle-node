/* Copyright (c) 2008 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is confidential property of Nordic 
 * Semiconductor. The use, copying, transfer or disclosure of such information 
 * is prohibited except by express written agreement with Nordic Semiconductor.
 *
 * $LastChangedRevision:$
 */
 
/** @file
 * The nRF24LE1 example application.
 *
 * @author Rune Brandsegg
 */

#define CMD_SEND_DATA 0			// Send a new command
#define CMD1 1							// Command-type 1 (dummy message)
#define CMD2 2							// Command-type 2	(boot message)

#define RF_READY_INT_VECT 9 // Radio interrupt vector

#define DATA_POS 7          // Defines the start-postion of the data in packet. 
#define RADIO_MAX_PL 32     // Defines MAX pck length for radio

/** This function is called if the application is entering the 
 *  primary transmitter mode. This is an endless loop, TX mode (PTX) function.
 */
void transmitter_mode(void);

/** This function is called if the application is entering the
 *  primary receiver mode. This is an endless loop, RX mode (PRX) function.
 */
void receiver_mode(void);

/** This function creates a data_packet from the incoming command and transfers
 *  it to the radio and which transmits it. It waits until the packet are sent,
 *  or MAX_RT, i.e. all tries done, then crates a led blink based on if the 
 *  packet was sent or not. Finally LED0 is switched off.
 */
void send_packet(uint8_t command);

/** This function gets the incoming data from the radio and returns the command 
 */
uint8_t read_packet(void);

void radio_irq(void) interrupt RF_READY_INT_VECT;
