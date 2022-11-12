/*
 * app.c
 *
 * Created: 10/15/2022 4:48:21 PM
 *  Author: Jehan Refaa
 */ 



#include "app.h"


void error_state(uint8_t);

uint8_t x=4 , y=0 , z=0 , error_state_return=0;
 

void APP_init(void)
{
	error_state_return += BUTTON_init(PED_BUTTON_PORT , PED_BUTTON_PIN);
	
	error_state_return += LED_init(CAR_GREEN_PORT , CAR_GREEN_PIN);
	error_state_return += LED_init(CAR_YELLOW_PORT , CAR_YELLOW_PIN);
	error_state_return += LED_init(CAR_RED_PORT , CAR_RED_PIN);
	
	error_state_return += LED_init(PED_GREEN_PORT , PED_GREEN_PIN);
	error_state_return += LED_init(PED_YELLOW_PORT , PED_YELLOW_PIN);
	error_state_return += LED_init(PED_RED_PORT , PED_RED_PIN);
	
	error_state(error_state_return);
    
	BUTTON_interrupt_init();
}

void APP_start(void)
{
	while (1)
	{		
		switch(x)
		{
			case 4:
			y=4;
			error_state_return = LED_on(CAR_GREEN_PORT, CAR_GREEN_PIN, PED_RED_PORT , PED_RED_PIN);
			error_state(error_state_return);
			if(x==5)
			{
				break;
			}
			
			case 5:
			if(x==5)
			{
				x=55;
			}
			y=5;
			
			case 6:
			y=6;
			error_state_return = LED_blink_Double(CAR_YELLOW_PORT , CAR_YELLOW_PIN, PED_YELLOW_PORT , PED_YELLOW_PIN, 0.556, 5);
			error_state(error_state_return);
			if(x==5)
			{
				break;
			}
			error_state_return = LED_off(CAR_GREEN_PORT, CAR_GREEN_PIN, PED_RED_PORT , PED_RED_PIN);
			error_state(error_state_return);
			if(x==55)
			{
				z=0;
				x=4;
			}
			
			case 0:
			   x=4;
			   y=0;
			   
			case 1:
			   y=1;
			   error_state_return = LED_on(PED_GREEN_PORT , PED_GREEN_PIN , CAR_RED_PORT , CAR_RED_PIN);
			   error_state(error_state_return);
			   if(x==0)
			   {
				   break;
			   }
			   z=0;
			   
			case 2:
			   if(x==2)
			   {
				   error_state_return = LED_blink_Single(CAR_YELLOW_PORT, CAR_YELLOW_PIN, 0.556, 5);
				   error_state(error_state_return);
				   x=22;
				   y=2;
			   }  
				  		   
			case 3:
			   if(y != 2)
			   {
				   y=3;
				   error_state_return = LED_blink_Double(CAR_YELLOW_PORT , CAR_YELLOW_PIN, PED_YELLOW_PORT , PED_YELLOW_PIN, 0.556, 5); 
				   error_state(error_state_return);
			   }
			   if(x==2)
			   {
				   break;
			   }
			   error_state_return = LED_off(PED_GREEN_PORT , PED_GREEN_PIN , CAR_RED_PORT , CAR_RED_PIN);
			   error_state(error_state_return);
			   if(x==22)
			   {
				   z=0;
				   x=4;				   
			   }			
		}
	}
}



ISR(EXT_INT_0) // interrupt action 
{
	if(z==0)
	{
		z=1;
		if(y == 1)
		{
			x=0;
			LED_breaker(0);
		}
		else if(y == 4 || y == 6)
		{
			x=5;
			y == 4 ? LED_breaker(0) : LED_breaker(1);
		}
		else if(y == 3)
		{
			x=2;
			LED_breaker(1);
		}
	}	
}

void error_state(uint8_t error) //error handling
{
	if(error != 0)
	{
		while(1)
		{
				LED_on(CAR_RED_PORT , CAR_RED_PIN , CAR_GREEN_PORT , CAR_GREEN_PIN);
				LED_on(CAR_YELLOW_PORT, CAR_YELLOW_PIN, PED_YELLOW_PORT, PED_YELLOW_PIN);
				LED_on(PED_RED_PORT , PED_RED_PIN , PED_GREEN_PORT , PED_GREEN_PIN);
		}
	}
}