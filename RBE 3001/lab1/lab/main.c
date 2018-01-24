/*
 * main.c
 *
 *  Created on: Jan 27, 2016
 *      Author: tarocks
 */

#include "RBELib/RBELib.h"
#include <avr/iom644p.h>
#include <stdio.h>

int ISR_Flag = 0;
volatile char runtime = 0;
volatile int timeDivCount = 0;

int main(void){
	unsigned long time = 1;
	int ADCcounter = 2;
	long potValue = 135;
	int potAngle = 10;
	char millivolts = 5.5;
	//initialize variables
	debugUSARTInit(115200); // initialize USART
	initRBELib();

	DDRB = 0xFF;
	PORTB = 0x0F;

	//timer initialization
	CLKPR = 0b10001000;
	CLKPR &= 0b11111000;
	initTimer(0,0,0); //uses timer 0, in normal mode, with no compare value
	initADC(7); //sets ADC to channel 7
	int i = 0;

	while(1){
		//		PORTB = ~runtime;
		ADCcounter = getADC(7);
		//		PORTB = ADCcounter;
		//		PORTB = getADC(7);
		//		printf("%d%c%d%c%d%c%d\n\r",time,',',ADCcounter,',',potValue,',',potAngle); //print out to putty
		potAngle = ADCcounter/2.841666666666667;
		millivolts =  ADCcounter/186;
		printf("%d\n\r", ADCcounter);
		printf("%d\n\r", potAngle);
		printf("%d\n\r", time);
		printf("%d\n\r", millivolts);
		i++;
		if(i == 1000){
			time += 1;
			i = 0;
		}

		_delay_ms(10); //ten millisecond delay
	}

	return 0;
}

//interrupt
ISR(TIMER0_OVF_vect){
	if(!(timeDivCount%8)){
		runtime++;
	}
	timeDivCount++;
}
