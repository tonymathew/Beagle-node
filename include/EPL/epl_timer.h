#ifndef TIMER_H_
#define TIMER_H_

#include <Nordic/reg24le1.h>

typedef enum
{
	TIMER_30MS,
	TIMER_300MS,
    TIMER_1S,    
} epl_timer_period_t;

void epl_timer_start();
void epl_timer_init(epl_timer_period_t tp);
//void timer_interrupt() interrupt 1;
unsigned int epl_timer_get_data();

#endif /*TIMER_H_*/
