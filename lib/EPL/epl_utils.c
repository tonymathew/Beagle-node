#include <Nordic/reg24le1.h>
#include <stdint.h>
#include <EPL/epl_utils.h>

void epl_mdelay(unsigned int ms){
	unsigned int i, j;
	for(i = 0;i < ms;i++){
		for(j = 0;j < 1403;j++){ // 196
			//_nop_();
	    }
	}
}

void epl_led_init(){
	P0DIR &= ~0x80;  // P0.7 output LED
	P1DIR &= ~0x01;  // P1.0 output LED	
}

void epl_led_simple_init(){
	P1DIR &= ~0x18;	 // P1.3,P1.4 output LED
}

void epl_btn_init(){
	P0DIR |= 0x08;  // P0.3 input BUTTON	
}
