/*
 * registers.h
 *
 * Created: 10/15/2022 4:50:21 PM
 *  Author: Jehan Refaa
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_



#include "types.h"

/*DIO*/

//PORTA
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)

//PORTB
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)

//PORTC
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)

//PORTD
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)

//TIMER 0
#define TCCR0 *((volatile uint8_t*)0x53) //Mode Register
#define TCNT0 *((volatile uint8_t*)0x52) //Data Register
#define TIFR *((volatile uint8_t*)0x58)
#define TIMSK *((volatile uint8_t*)0x59)

//INTERRUPTS
#define MCUCR *((volatile uint8_t*)0x55)
#define MCUCSR *((volatile uint8_t*)0x54)
#define GICR *((volatile uint8_t*)0x5B)
#define GIFR *((volatile uint8_t*)0x5A)


#endif /* REGISTERS_H_ */