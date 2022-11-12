/*
 * button.c
 *
 * Created: 10/15/2022 4:52:11 PM
 *  Author: Jehan Refaa
 */ 



#include "button.h"

uint8_t error_b;

uint8_t BUTTON_init(uint8_t buttonPort, uint8_t buttonPin) 
{
	error_b = DIO_init(buttonPin, buttonPort, IN);
	return error_b;
}

uint8_t BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value)
{
	error_b = DIO_read(buttonPin, buttonPort, value);
	return error_b;
}

void BUTTON_interrupt_init(void)
{
	Interrupt_init ();
}


#if 0

#include "../../MCAL/DIO Driver/dio.h"

int main()
{
	uint8_t error_test_button = 0, value = 1;
	
	//error_test_button = BUTTON_init('A', 3); //NO error
	//error_test_button = BUTTON_init(5, 3); //error
	//error_test_button = BUTTON_init('G', 8); //error
	
	error_test_button = BUTTON_read('A', 3, &value); //NO error
	//error_test_button = BUTTON_read(5, 3, &value); //error
	//error_test_button = BUTTON_read('G', 8, &value); //error
		
	if(error_test_button != 0)
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
