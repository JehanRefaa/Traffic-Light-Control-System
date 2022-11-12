/*
 * timer.h
 *
 * Created: 10/15/2022 4:51:42 PM
 *  Author: Jehan Refaa
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"

#define F_CPU 16000000.0
#define BIT_SIZE 256
#define NUM_OF_OVERFLOWS_FOR_ONE_SECOND 62500 //1000ms
#define NO_PRESCALING 1 
#define F8_PRESCALING 8
#define F64_PRESCALING 64
#define F256_PRESCALING 256
#define F1024_PRESCALING 1024
#define Error_Test_PRESCALING 123
//#define error_test 55


void TIMER_init(void);
uint8_t TIMER_start(uint16_t prescaler);
void TIMER_stop(void);
uint8_t TIMER_delay(uint16_t prescaler, float  T_delay);
void Timer_breaker(uint8_t inter_a);

#endif /* TIMER_H_ */