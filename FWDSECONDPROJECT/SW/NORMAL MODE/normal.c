/*
 * normal.c
 *
 * Created: 10/3/2022 4:27:19 PM
 *  Author: MOSTAFA EMARY
 */ 
#include "normal.h"
void NORMAL_MODE()
{
	LED_ON(LED_A,0);
	delay1(5);
	LED_OFF(LED_A,0);
	LED_BLINK(LED_A,1,5,.5);
	LED_ON(LED_A,2);
	delay1(5);
	LED_OFF(LED_A,2);
	
	LED_BLINK(LED_A,1,5,.5);
}