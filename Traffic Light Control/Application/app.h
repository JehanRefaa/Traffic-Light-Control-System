/*
 * app.h
 *
 * Created: 10/15/2022 4:48:34 PM
 *  Author: Jehan Refaa
 */ 


#ifndef APP_H_
#define APP_H_



#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/Button Driver/button.h"

#define CAR_GREEN_PORT   PORT_A
#define CAR_YELLOW_PORT  PORT_A
#define CAR_RED_PORT     PORT_A

#define CAR_GREEN_PIN    0
#define CAR_YELLOW_PIN   1
#define CAR_RED_PIN      2

#define PED_GREEN_PORT   PORT_B
#define PED_YELLOW_PORT  PORT_B
#define PED_RED_PORT     PORT_B
		
#define PED_GREEN_PIN    0
#define PED_YELLOW_PIN   1
#define PED_RED_PIN      2

#define PED_BUTTON_PORT  PORT_D
#define PED_BUTTON_PIN   2


void APP_init(void);
void APP_start(void);



#endif /* APP_H_ */