/*
 * button.h
 *
 * Created: 10/15/2022 4:52:25 PM
 *  Author: Jehan Refaa
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Interrupt Library/interrupts.h"

//Button State
/*
#define LOW 0
#define High 1
*/

uint8_t BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);
uint8_t BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value);
void BUTTON_interrupt_init(void);



#endif /* BUTTON_H_ */