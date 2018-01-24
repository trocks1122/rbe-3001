/*
* SignalSample.c
*
*  Created on: Jan 26, 2016
*      Author: Casey
*
*
*
*
*/

#include "RBELib/RBELib.h"
#include <avr/io.h> //
#include <stdio.h>
#include "Usart.h"
#include "TimerConfig.h"
#include "adc.h"

volatile unsigned long int time = 0, timeDiv = 0;
volatile int ADC_count=0;
volatile unsigned long int hundredths = 0;

//LAB #1, Question 6
int main(void){
	CLKPR = 0x80; // reset system clock prescale to 1/1
	debugUSARTInit(115200);    // Initialize USART serial communications, enables printf()

	initTimer(0,0,0); //Timer0, normal (overflow) mode, no compare value
	initADC(4); //start ADC on analog channel 4

	sei();
	DDRB = 0x00; //set as inputs (switches)
	PORTD = 0xFF; //pull-up resistors

	DDRB = 0xF0;
	DDRA = 0x00;

	int data[1000]; //data array
	char sampled = 0; //sample flag

	int i = 0, imax=0; //variable for iteration

	while(1){
				if((PINDbits._P4 == 0) && (PINDbits._P5 & PINDbits._P6 & PINDbits._P7)){//if button 4 is pressed
					time = 0;
					while((time % 9000) != 0){
						if((time % 40) == 0){
							PORTB ^= 0xFF; //toggle the pin
							data[i] = ADC_count;
							data[i+1] = time;
							i = i+2;
						}
						sampled = 1;
					}
				}
				if(sampled == 1){
					imax = i;
					i = 0;
					while(i != imax){
					printf("%d%c%d\n\r", data[i],',', data[i+1]/9);
					i = i + 2;
					}
					sampled = 0;
				}

	}
}

ISR(TIMER0_OVF_vect){
	time++;
}

ISR(ADC_vect){
	ADC_count = getADC(4);
}





