/*
 * predestrain.c
 *
 * Created: 10/5/2022 8:23:19 AM
 *  Author: MOSTAFA EMARY
 */ 
#include "predestrain.h"

void mode1()
{
	LED_ON(LED_A,2);
	LED_ON(LED_B,0);
	delay1(5);
	LED_OFF(LED_A,2);
	LED_OFF(LED_B,0);
}
void mode2()
{
	//LED_OFF(LED_A,0);
	//LED_OFF(LED_A,1);
	//LED_OFF(LED_A,2);
	LED_ON(LED_B,2);
	int i=5;
	while (i)
	{
		LED_ON(LED_B,1);
		LED_ON(LED_A,1);
		delay1(.5);
		LED_OFF(LED_B,1);
		LED_OFF(LED_A,1);
		delay1(.5);
		i--;
	}
	LED_ON(LED_B,0);
	LED_ON(LED_A,2);
	delay1(5);
	LED_OFF(LED_B,2);
	LED_OFF(LED_B,0);
	LED_OFF(LED_A,2);
}