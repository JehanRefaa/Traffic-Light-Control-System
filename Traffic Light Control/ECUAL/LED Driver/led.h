/*
 * led.h
 *
 * Created: 10/15/2022 4:52:36 PM
 *  Author: Jehan Refaa
 */ 


#ifndef LED_H_
#define LED_H_


#include "../../MCAL/Timer Driver/timer.h"
#include "../../MCAL/DIO Driver/dio.h"

uint8_t LED_init(uint8_t ledPort, uint8_t ledPin);
uint8_t LED_on(uint8_t ledPort1, uint8_t ledPin1,uint8_t ledPort2, uint8_t ledPin2);
uint8_t LED_off(uint8_t ledPort1, uint8_t ledPin1,uint8_t ledPort2, uint8_t ledPin2);
uint8_t LED_toggle(uint8_t ledPort, uint8_t ledPin);
uint8_t LED_blink_Double(uint8_t ledPort1, uint8_t ledPin1,uint8_t ledPort2, uint8_t ledPin2, float T_delay, uint8_t iter);
uint8_t LED_blink_Single(uint8_t ledPort, uint8_t ledPin, float T_delay, uint8_t iter);
void LED_breaker(int LED_break_a);


#endif /* LED_H_ */