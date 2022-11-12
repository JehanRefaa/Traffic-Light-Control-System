/*
 * dio.h
 *
 * Created: 10/15/2022 4:50:50 PM
 *  Author: Jehan Refaa
 */ 


#ifndef DIO_H_
#define DIO_H_


//include registers

#include "../../Utilities/registers.h"
#include "../Interrupt Library/interrupts.h"


//all internal driver typedefs
//all driver macros

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'


//direction defines

#define IN 0
#define OUT 1


//value defines

#define LOW 0
#define HIGH 1

//all driver functions prototypes

uint8_t DIO_init(uint8_t pinNumber,uint8_t portNumber,uint8_t direction);
uint8_t DIO_write(uint8_t pinNumber,uint8_t portNumber,uint8_t value);
uint8_t DIO_toggle(uint8_t pinNumber,uint8_t portNumber);
uint8_t DIO_read(uint8_t pinNumber,uint8_t portNumber,uint8_t *value);


#endif /* DIO_H_ */