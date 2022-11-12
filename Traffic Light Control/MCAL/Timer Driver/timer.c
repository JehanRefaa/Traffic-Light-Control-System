/*
 * timer.c
 *
 * Created: 10/15/2022 4:51:55 PM
 *  Author: Jehan Refaa
 */ 


#include "timer.h"

uint8_t inter = 0, error_t = 0;

void TIMER_init(void) //timer initialization
{
	//choose timer mode
	TCCR0 = 0x00; //normal mode
	//timer set initial value
	TCNT0 = 0x00;
}

uint8_t TIMER_start(uint16_t prescaler) //timer start
{
	error_t = 0;
    switch(prescaler)
	{
		case 1:
		    TCCR0 |= (1<<0);
		    break;
		
		case 8:
		    TCCR0 |= (1<<1);   
		    break;
		
		case 64:
		    TCCR0 |= (1<<0) | (1<<1);
		    break;
		
		case 256:
		    TCCR0 |= (1<<2);
		    break;
		
		case 1024:		
		   TCCR0 |= (1<<0) | (1<<2);
		   break;
		
		default:
		    error_t = 1;	
			break;	
	} 
	return error_t;
}

void TIMER_stop(void) //timer stop
{
	TCCR0 = 0x00;
}


uint8_t TIMER_delay(uint16_t prescaler, float T_delay) //timer delay function takes the prescaling and delay wanted
{	
	double OverFlowCounter = 0;
	
	float T_tick, T_max;
	double NO_OVERFLOW = 0;
	
	T_tick = prescaler / F_CPU;
	T_max = T_tick * 256;
	
	NO_OVERFLOW = T_delay / T_max; 
	
	error_t = TIMER_start(prescaler);
	
	while(OverFlowCounter < NO_OVERFLOW && error_t != 1)
	{
		if(inter == 1)
		{
			inter = 0;
			break;
		}
		
		while((TIFR & (1<<0)) == 0);
		
		TIFR |= (1<<0);
		
		OverFlowCounter++;
	}
	
	OverFlowCounter = 0;
	
	TIMER_stop();
	
	return error_t;
}

void Timer_breaker(uint8_t inter_a) //interrupt timer breaker
{
	inter = inter_a;
}


#if 0

#include "../DIO Driver/dio.h"

int main()
{
	uint8_t error_test_timer = 0;
	
	//error_test_timer = TIMER_start(NO_PRESCALING); //NO error
	//error_test_timer = TIMER_start(F64_PRESCALING); //NO error
	//error_test_timer = TIMER_start(F1024_PRESCALING); //NO error
	//error_test_timer = TIMER_start(Error_Test_PRESCALING); //error
	
	//error_test_timer = TIMER_delay(NO_PRESCALING, 5.0); //NO error
	//error_test_timer = TIMER_delay(F64_PRESCALING, 6.0); //NO error
	//error_test_timer = TIMER_delay(F1024_PRESCALING, 1.2); //NO error
	error_test_timer = TIMER_delay(Error_Test_PRESCALING, 2.5); //error
	
	if(error_test_timer != 0)
	{
		DIO_init (0,'A', 1);
		DIO_init (1,'A', 1);
		DIO_init (2,'A', 1);
		DIO_init (0,'B', 1);
		DIO_init (1,'B', 1);
		DIO_init (2,'B', 1);
		
		DIO_write (0,'A',1);
		DIO_write (1,'A',1);
		DIO_write (2,'A',1);
		DIO_write (0,'B',1);
		DIO_write (1,'B',1);
		DIO_write (2,'B',1);
	}
}
#endif
