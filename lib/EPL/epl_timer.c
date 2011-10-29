#include <EPL/epl_timer.h>

/*
 * 12 * 65536 tick 是一次 timer interrupt 最大值
 * 一次 tick 為 1 / 16 * 1000000
 * 12 * 1 / 16 / 1000000 * 4000 = 0.003 s = 3ms
 * counter = 40000 => 30ms
 * 
 * 注意讀出來的值要先乘上時間單位才是真正的值 
 * ex : 30ms 的counter 讀出來是500
 * 		500 * 30 (ms) / 1000 = 15(s)
 * 
 * 因為timer_data為unsigned int
 * 所以最多可計 65535 * 30 /1000/60 = 32.xxx (minute)
 */

static unsigned int timer_reload = 25536;
static unsigned int timer_data = 0;
static epl_timer_period_t timer_unit;

void epl_timer_start()
{
	TR0 = 1;
	EA = 1;
}

void epl_timer_init(epl_timer_period_t tp)
{
	timer_unit = tp;
	
	timer_data = 0;
	
	TL0 = timer_reload & 0xFF;
	TH0 = (timer_reload >> 8) & 0xFF;

	TMOD |= 0x01;                     // Timer0: Mode 1, 16-bit timer
	TF0 = 0;                          // Timer0: interrupt flag clear
	ET0 = 1;                          // Timer0: interrupt enable
	TR0 = 0;                          // Timer0: stop timer
}

void timer_interrupt(void) interrupt 1
{
	TL0 = timer_reload & 0xFF;
	TH0 = (timer_reload >> 8) & 0xFF;
	
	timer_data++;

	TR0 = 1;                          // start timer0
	return;
}

unsigned int epl_timer_get_data(){
	if(timer_unit == TIMER_30MS)
		return timer_data;
	else if(timer_unit == TIMER_300MS)
		return timer_data / 10;
	else if(timer_unit == TIMER_1S)
		return timer_data * 3 / 100;
	else
		return 0;
}
