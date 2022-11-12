/*
 * led.c
 *
 * Created: 10/15/2022 4:52:49 PM
 *  Author: Jehan Refaa
 */ 

#include "led.h"


uint8_t LED_break = 0, error_l = 0;

uint8_t LED_init(uint8_t ledPort, uint8_t ledPin) //function to initialize led
{
	error_l += DIO_init(ledPin, ledPort, OUT);
	return error_l;
}

uint8_t LED_on(uint8_t ledPort1, uint8_t ledPin1,uint8_t ledPort2, uint8_t ledPin2) //function to turn led on
{
	error_l += DIO_write(ledPin1, ledPort1, HIGH);
	error_l += DIO_write(ledPin2, ledPort2, HIGH);
	error_l += TIMER_delay(NO_PRESCALING, 5.0);
	return error_l;
}
 
uint8_t LED_off(uint8_t ledPort1, uint8_t ledPin1,uint8_t ledPort2, uint8_t ledPin2) //function to turn led off
{
	error_l += DIO_write(ledPin1, ledPort1, LOW);
	error_l += DIO_write(ledPin2, ledPort2, LOW);
	return error_l;
}

uint8_t LED_toggle(uint8_t ledPort, uint8_t ledPin) //function to flip led status
{
	error_l += DIO_toggle(ledPin, ledPort);
	return error_l;
}

uint8_t LED_blink_Double(uint8_t ledPort1, uint8_t ledPin1,uint8_t ledPort2, uint8_t ledPin2, float T_delay, uint8_t iter) //function to blink two leds
{
	TIMER_init();
	for(uint8_t i=1 ; i<=iter ; i++)
	{
		if(LED_break == 1)
		{
			LED_break = 0;
			break;
		}
		error_l += LED_toggle(ledPort1, ledPin1);
		error_l += LED_toggle(ledPort2, ledPin2);
	    error_l += TIMER_delay(NO_PRESCALING, T_delay);
		error_l += LED_toggle(ledPort1, ledPin1);
		error_l += LED_toggle(ledPort2, ledPin2);
		if(i!=iter)
		{
			error_l += TIMER_delay(NO_PRESCALING, T_delay);
		}	
	}
	return error_l;
}

uint8_t LED_blink_Single(uint8_t ledPort, uint8_t ledPin, float T_delay, uint8_t iter) //function to blink single led
{
	TIMER_init();
	for(uint8_t i=1 ; i<=iter ; i++)
	{
		error_l += LED_toggle(ledPort, ledPin);
		error_l += TIMER_delay(NO_PRESCALING, T_delay);
		error_l += LED_toggle(ledPort, ledPin);
		if(i!=iter)
		{
			error_l += TIMER_delay(NO_PRESCALING, T_delay);
		}
	}
	return error_l;
}

void LED_breaker(int LED_break_a) //interrupt led breaker
{
	Timer_breaker(1);
	LED_break = LED_break_a;
}




#if 0

#include "../../MCAL/DIO Driver/dio.h"

int main()
{
	uint8_t error_test_led = 0;
	
	//error_test_led = LED_init('A', 0); //NO error
	//error_test_led = LED_init('G', 0); //error
	
	//error_test_led = LED_on('A', 0, 'B', 4); //NO error
	//error_test_led = LED_on('A', 0, 'T', 5); //error
	
	//error_test_led = LED_off('A', 0, 'B', 4); //NO error
	//error_test_led = LED_off('A', 0, 'T', 5); //error
	
	//error_test_led = LED_toggle('A', 0); //NO error
	//error_test_led = LED_toggle('G', 0); //error
	
	//error_test_led = LED_blink_Double('A', 0, 'B', 4 , 5 , 5); //NO error
	//error_test_led = LED_blink_Double('A', 0, 'T', 5 , 5 , 5); //error
	
	//error_test_led = LED_blink_Single('A', 0, 5 , 5); //NO error
	//error_test_led = LED_blink_Single('G', 0, 5 , 5); //error
	 
	if(error_test_led != 0)
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
