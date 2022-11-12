/*
 * interrupts.c
 *
 * Created: 11/9/2022 7:05:23 PM
 *  Author: Jehan Refaa
 */ 

#include "interrupts.h"


void Interrupt_init (void)
{
		sei();
		
		MCUCR |= (1<<0) | (1<<1);
		GICR |= (1<<6);
}

