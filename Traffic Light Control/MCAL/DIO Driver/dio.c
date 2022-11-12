/*
 * dio.c
 *
 * Created: 10/15/2022 4:51:03 PM
 *  Author: Jehan Refaa
 */ 



// include .h


#include "dio.h"


//globale variables
// function deffinitions

uint8_t error_d = 0;

uint8_t DIO_init(uint8_t pinNumber,uint8_t portNumber,uint8_t direction)
{
	switch(portNumber)
	{
		case PORT_A:
		
		if(direction == IN)
		{
			DDRA &=~ (1<<pinNumber); //INPUT
		}
		else if(direction == OUT)
		{
			DDRA |= (1<<pinNumber); //OUTPUT
		}
		else
		{
			error_d = 1;
		}
		break;
		
		case PORT_B:
		
		if(direction == IN)
		{
			DDRB &=~ (1<<pinNumber);
		}
		else if(direction == OUT)
		{
			DDRB |= (1<<pinNumber);
		}
		else
		{
			error_d = 1;
		}
		break;
		
		case PORT_C:
		
		if(direction == IN)
		{
			DDRC &=~ (1<<pinNumber);
		}
		else if(direction == OUT)
		{
			DDRC |= (1<<pinNumber);
		}
		else
		{
			error_d = 1;
		}
		break;
		
		case PORT_D:
		
		if(direction == IN)
		{
			DDRD &=~ (1<<pinNumber);
		}
		else if(direction == OUT)
		{
			DDRD |= (1<<pinNumber);
		}
		else
		{
			error_d = 1;
		}
		break;
		
		default:
		
		error_d = 1;
		break;
	}
	
	return error_d;
}


uint8_t DIO_write(uint8_t pinNumber,uint8_t portNumber,uint8_t value)
{
	switch(portNumber)
	{
		case PORT_A:
		
		if(value == LOW)
		{
			PORTA &=~ (1<<pinNumber); //WRITE 0
		}
		else if(value == HIGH)
		{
			PORTA |= (1<<pinNumber); //WRITE 1
		}
		else
		{
			error_d = 1;
		}
		break;
		
		case PORT_B:
		
		if(value == LOW)
		{
			PORTB &=~ (1<<pinNumber);
		}
		else if(value == HIGH)
		{
			PORTB |= (1<<pinNumber);
		}
		else
		{
			error_d = 1;
		}
		break;
		
		case PORT_C:
		
		if(value == LOW)
		{
			PORTC &=~ (1<<pinNumber);
		}
		else if(value == HIGH)
		{
			PORTC |= (1<<pinNumber);
		}
		else
		{
			error_d = 1;
		}
		break;
		
		case PORT_D:
		
		if(value == LOW)
		{
			PORTD &=~ (1<<pinNumber);
		}
		else if(value == HIGH)
		{
			PORTD |= (1<<pinNumber);
		}
		else
		{
			error_d = 1;
		}
		break;
	}
	return error_d;
}


uint8_t DIO_toggle(uint8_t pinNumber,uint8_t portNumber)
{
	switch(portNumber)
	{
		case PORT_A:
		PORTA ^=(1<<pinNumber);
		break;
		
		case PORT_B:
		PORTB ^=(1<<pinNumber);
		break;
		
		case PORT_C:
		PORTC ^=(1<<pinNumber);
		break;
		
		case PORT_D:
		PORTD ^=(1<<pinNumber);
		break;
		
		default:
		error_d = 1;
		break;
	}
	return error_d;
}


uint8_t DIO_read(uint8_t pinNumber,uint8_t portNumber,uint8_t *value)
{
	switch(portNumber)
	{
		case PORT_A:
		*value = (PINA & (1<<pinNumber))>>pinNumber;
		break;
		
		case PORT_B:
		*value = (PINB & (1<<pinNumber))>>pinNumber;
		break;
		
		case PORT_C:
		*value = (PINC & (1<<pinNumber))>>pinNumber;
		break;
		
		case PORT_D:
		*value = (PIND & (1<<pinNumber))>>pinNumber;
		break;
		
		default:
		error_d = 1;
		break;
	}
	return error_d;
}



#if 0

int main()
{
	uint8_t error_test_dio = 0;
	
	//error_test_dio = DIO_init(6,'A', 1); //NO error
	//error_test_dio = DIO_init(5, 6, 1); //error
	
	//error_test_dio = DIO_write(5 ,'G', 1); //error
	//error_test_dio = DIO_write('A', 6, 1); //error
	
	error_test_dio = DIO_read('A', 6, 1); //error
	//error_test_dio = DIO_read(6,'A', 1); //NO error
	
	//error_test_dio = DIO_toggle(2, 'H'); //error
	//error_test_dio = DIO_toggle(5, 6); //error
	
	if(error_test_dio != 0)
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
