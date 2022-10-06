/*
 * APPLICATION.c
 *
 * Created: 9/30/2022 2:28:50 PM
 *  Author: MOSTAFA EMARY
 */ 
#include "APPLICATION.h"
//#include "util/delay.h"
int mode=0;
char LED;
void APP_INIT()
{
	SREG|=(1<<7);
	MCUCR|=(1<<1)|(1<<0);
	GICR|=(1<<6);
	BUTTON_init(B_D,2);
	while(1)
	{
			LED_ON(LED_A,0);
			LED='G';
			delay1(5);
			LED_OFF(LED_A,0);
			LED='Y';
			LED_BLINK(LED_A,1,5,.5);
			LED_ON(LED_A,2);
			LED='R';
			delay1(5);
			LED_OFF(LED_A,2);
			LED='Y';
			LED_BLINK(LED_A,1,5,.5);
	}
}
ISR(EXT_INT(1))
{
	PREDESTRAIN_MODE(LED);
}

void PREDESTRAIN_MODE(char x)
{
	if(x=='R')
	{
		LED_OFF(LED_A,2);
		mode1();
		LED_ON(LED_A,2);
	}
	else if(x=='G')
	{
		
		LED_OFF(LED_A,0);
		mode2();
		LED_ON(LED_A,0);
	}
	else
	{
		LED_OFF(LED_A,1);
		mode2();
		LED_ON(LED_A,1);
	}
}