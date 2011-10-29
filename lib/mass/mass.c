#include <Nordic/reg24le1.h>
#include <EPL/epl_uart.h>
#include <HAL/hal_nrf.h>
#include <EPL/epl_utils.h>
#include <mass/mass.h>

extern unsigned char id;
extern unsigned char xdata group_id;
extern unsigned int xdata pkt_seq;
extern unsigned char rf_ack_idx;
extern volatile unsigned char return_flag;
extern struct radio_buffer xdata rf_buf;
extern unsigned char xdata result_buf[RF_BUF_LEN];
extern unsigned char rf_rx_addr[5];
extern unsigned char rf_rx_addr2[5];
extern unsigned char xdata bm0[BITMAP_LEN];

//Cindy  - test OK 20091011
void get_data()
{
	#pragma asm
		; Pop ret address to ret directly back to while loop
		POP		B
		POP		B
	#pragma endasm
		
	/* Set xdata as data space */
	MEMCON = 0x00;

	#pragma asm
		MOV  	DPTR,#rf_buf+05H
	
		WHILE_LOOP:
			MOV		A, R2
			JZ		END_GET_DATA
			DEC		R2

			MOV		A, @R0
			MOVX 	@DPTR,A
			INC		R0
			INC 	DPTR
			SJMP	WHILE_LOOP

		END_GET_DATA:
	#pragma endasm

#ifdef DEBUG	
	epl_uart_putint(1); 
#endif

}

//Cindy  - test OK 20091011
void set_data()
{
	#pragma asm

		; Pop ret address to ret directly back to main while loop
		POP		B
		POP		B
	#pragma endasm
		
	/* Set xdata as data space */
	MEMCON = 0x00;
    
	#pragma asm

		MOV  	DPTR,#rf_buf+0FH
	WHILE_LOOP?3:
		MOV		A, R2
		JZ		END_SET_DATA
		DEC		R2
		; Copy data from rf_buf
		MOVX	A, @DPTR
		//MOV A,#01H
		; Write into designated location in IDATA
		MOV		@R0, A

		INC		R0
		INC		DPTR
		SJMP	WHILE_LOOP?3
	END_SET_DATA:

	#pragma endasm

#ifdef DEBUG	
	epl_uart_putint(2);	
#endif
}

//---------------Cindy - 暫時不會用到的func--------------------------//
//要get flash program memory的值
void get_ram()
{
	#pragma asm
		; Pop ret address to ret directly back to main while loop
		POP		B
		POP		B
	#pragma endasm
		
	/* Set xdata as data space */
	MEMCON = 0x00;

	#pragma asm	
		
		//Cindy - R0 stores len, DPTR stores ram_addr
		; Write into address starting from rf_buf.buffer[4]
		MOV		R1, #LOW(rf_buf+05H)
		; while(len--)
	WHILE_LOOP?2:
		MOV		A, R0
		JZ		END_GET_RAM
		DEC		R0

		MOVX	A, @DPTR
		MOVX	@R1, A

		INC		DPTR
		INC		R1
		SJMP	WHILE_LOOP?2
	END_GET_RAM:

	#pragma endasm

}
//---------------------------------------------------------------------//

//Cindy  - test OK 20091011
void ret_char()
{
	#pragma asm
		; Pop ret address to ret directly back to main while loop
		POP		B
		POP		B
	#pragma endasm
		
	/* Set xdata as data space */
	MEMCON = 0x00;
     
	#pragma asm
		MOV  	R5,rf_ack_idx
		MOV  	A,R5
		RLC  	A
		SUBB 	A,ACC
		MOV  	R6,A
		MOV  	A,#LOW (rf_buf+01H)
		ADD  	A,R5
		MOV  	DPL,A
		MOV  	A,#HIGH (rf_buf+01H)
		ADDC 	A,R6
		MOV  	DPH,A
		
		MOV  	A, R7
		MOVX 	@DPTR,A
		
		; rf_ack_idx++;
		INC		rf_ack_idx
	#pragma endasm
	
#ifdef DEBUG	
	epl_uart_putint(4);
#endif
}

//Cindy  - test OK 20091011
void ret_int()
{
	#pragma asm
		; Pop ret address to ret directly back to main while loop
		POP		B
		POP		B
	#pragma endasm
		
	/* Set xdata as data space */
	MEMCON = 0x00;
    
	#pragma asm
		MOV  	R5,rf_ack_idx
		MOV  	A,R5
		RLC  	A
		SUBB 	A,ACC
		MOV  	R4,A
		MOV  	A,#LOW (rf_buf+01H)
		ADD  	A,R5
		MOV  	DPL,A
		MOV  	A,#HIGH (rf_buf+01H)
		ADDC 	A,R4
		MOV  	DPH,A
		
		MOV  	A, R6
		MOVX 	@DPTR,A
		INC		DPTR
		MOV  	A, R7
		MOVX 	@DPTR,A

		; rf_ack_idx += 2;
		INC		rf_ack_idx
		INC		rf_ack_idx
	#pragma endasm

#ifdef DEBUG	
	epl_uart_putint(5);
#endif
}

//Cindy  - test OK 20091011
void ret_long()
{
	#pragma asm
		; Pop ret address to ret directly back to main while loop
		POP		B
		POP		B
	#pragma endasm
		
	/* Set xdata as data space */
	MEMCON = 0x00;
    
	#pragma asm
	
		MOV  	R3,rf_ack_idx
		MOV  	A,R3
		RLC  	A
		SUBB 	A,ACC
		MOV  	R2,A
		MOV  	A,#LOW (rf_buf+01H)
		ADD  	A,R3
		MOV  	DPL,A
		MOV  	A,#HIGH (rf_buf+01H)
		ADDC 	A,R2
		MOV  	DPH,A
		
		MOV  	A, R4
		MOVX 	@DPTR,A
		INC		DPTR
		MOV  	A, R5
		MOVX 	@DPTR,A
		INC		DPTR
		MOV  	A, R6
		MOVX 	@DPTR,A
		INC		DPTR
		MOV  	A, R7
		MOVX 	@DPTR,A

		; rf_ack_idx += 4;
		MOV  	A,#04H
		ADD  	A,rf_ack_idx
		MOV  	rf_ack_idx,A
	#pragma endasm

#ifdef DEBUG	
	epl_uart_putint(6);
#endif
}

//Cindy  - test OK 20091011
void ret_ptr()
{
	#pragma asm
		; Pop ret address to ret directly back to main while loop
		POP		B
		POP		B
	#pragma endasm
		
	/* Set xdata as data space */
	MEMCON = 0x00;
    
	#pragma asm
		MOV  	R5,rf_ack_idx
		MOV  	A,R5
		RLC  	A
		SUBB 	A,ACC
		MOV  	R6,A
		MOV  	A,#LOW (rf_buf+01H)
		ADD  	A,R5
		MOV  	DPL,A
		MOV  	A,#HIGH (rf_buf+01H)
		ADDC 	A,R6
		MOV  	DPH,A
		
		MOV  	A, R1
		MOVX 	@DPTR,A
		INC		DPTR
		MOV  	A, R2
		MOVX 	@DPTR,A
		INC		DPTR
		MOV  	A, R3
		MOVX 	@DPTR,A

		; rf_ack_idx += 3;
		MOV  	A,#03H
		ADD  	A,rf_ack_idx
		MOV  	rf_ack_idx,A
	#pragma endasm

#ifdef DEBUG	
	epl_uart_putint(7);
#endif
}

//Cindy  - 
void ret_func()
{
    unsigned int i; 
    unsigned char j;
     
    #pragma asm
		; Pop ret address to ret directly back to while loop
		POP		B
		POP		B
	#pragma endasm
		
	/* Set xdata as data space */
	MEMCON = 0x00;
     
#ifdef DEBUG
    epl_uart_putchar('f');     
#endif                       
    //Return Function result to host //
    result_buf[0] = rf_buf.buffer[7];
    result_buf[1] = group_id;
                 
    // Delay to avoid collision //
    if(rf_buf.buffer[8]){             
        // Delay to avoid collision //
        /*for(i = 0;i < group_id * 100 ;i++){
              for(j = 0;j < 140;j++)
                    ;
        }*/
        epl_mdelay(group_id*10);
    }

    return_flag = 1;
}

//Cindy  - 
void set_rfaddr()
{
    unsigned char i;
     
	#pragma asm
		; Pop ret address to ret directly back to while loop
		POP		B
		POP		B
	#pragma endasm
		
	/* Set xdata as data space */
	MEMCON = 0x00;
	
#ifdef DEBUG	
	epl_uart_putchar('c'); 
#endif

    //Reset pkt sequence number
    //pkt_seq = 0;

    // Change group rf addr //
    rf_rx_addr2[0] = rf_buf.buffer[7];
    rf_rx_addr2[1] = rf_buf.buffer[8];
    
    hal_nrf_set_address(HAL_NRF_PIPE0, rf_rx_addr2);    
    
    // Initialize bitmap //
    for(i = 0; i < rf_buf.buffer[10]; i++){
          bm0[i] = 0;
    }                           
    
    // Initialize group id //
    group_id = rf_buf.buffer[11];

}

//Cindy  - 
void ret_bitmap()
{
    unsigned int i; 
    unsigned char j, delay;
     
	#pragma asm
		; Pop ret address to ret directly back to while loop
		POP		B
		POP		B
	#pragma endasm
		
	/* Set xdata as data space */
	MEMCON = 0x00;
	
#ifdef DEBUG	
	epl_uart_putchar('r'); 
#endif

     delay = rf_buf.buffer[9];

    //Return Bitmap to host //
     rf_buf.buffer[0] = rf_buf.buffer[7];
     rf_buf.buffer[1] = group_id;
                    
     for( i=rf_buf.buffer[8] ; i >0 ; i--){
          rf_buf.buffer[i+1] = bm0[i-1]; 
     }    
     
     if(delay){
         // Delay to avoid collision //
         /*for(i = 0;i < group_id * 100 ;i++){
               for(j = 0;j < 140;j++)
                     ;
         }
         */
         epl_mdelay(group_id*10);
     }

}


//Cindy  - 
void set_bitmap()
{
    unsigned int i; 
    
    #pragma asm
		; Pop ret address to ret directly back to while loop
		POP		B
		POP		B
	#pragma endasm
		
	/* Set xdata as data space */
	MEMCON = 0x00;
	
#ifdef DEBUG	
	epl_uart_putchar('y'); 
#endif
    
    // Initialize bitmap //
    for(i = 0; i < rf_buf.buffer[7]; i++){
          bm0[i] = 0;
    }       
    
}

//Cindy  - test OK 20091011
void put_addr()
{
	/* Set xdata as data space */
	MEMCON = 0x00;
#ifdef DEBUG	
    epl_uart_putint(0);
#endif
    
	/* Set ACK packet SRC address */
	rf_buf.buffer[0] = id;
	rf_buf.buffer[1] = EXECUTE_SUCCESS;
	rf_buf.buffer[2] = rf_rx_addr[0];
	rf_buf.buffer[3] = rf_rx_addr[1];
	rf_buf.buffer[4] = rf_rx_addr[2];

	//Cindy - 為什麼是7?
	rf_ack_idx = 7;

	/* Set xdata as code space */
	MEMCON = 0x01;
}
