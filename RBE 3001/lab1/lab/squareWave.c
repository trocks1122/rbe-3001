/*
 * squareWave.c
 *
 *  Created on: Jan 27, 2016
 *      Author: tarocks
 */

#include "RBELib/RBELib.h"
#include <avr/iom644p.h>
#include <stdio.h>

unsigned int max1;
unsigned int max2;
char max = 1;

//volatile unsigned long int time = 0;
//volatile unsigned long int timeDivCount = 0;


int main(void){
	int ADCcounter;
	int dutyCycle;
	int freq;

	unsigned int divide = 1;


	debugUSARTInit(115200); // initialize USART
	initRBELib();
	// SET port D as inputs
	DDRD = 0x00;
	PORTD = 0xFF;

	DDRB = 0xFF;
	PORTB = 0xFF;

	_delay_ms(1000);
	//timer initialization
	initTimer(0,0,0); //uses timer 0, in normal mode, with no compare value
	initADC(4); //sets ADC to channel 4

	while(1){
		ADCcounter = getADC(4);
		dutyCycle = (int) ((long) ADCcounter)*((long) 100)/1023;
		freq = 1000/divide;
		printf("%d%c%d%c%d%c%d\n\r", dutyCycle, ',',freq, ',', max, ',', ADCcounter);


		if ((PINDbits._P4 == 0) && (PINDbits._P5 & PINDbits._P6 & PINDbits._P7)){
			divide = 1000;
		} else if((PINDbits._P5 == 0) && (PINDbits._P4 & PINDbits._P6 & PINDbits._P7)){
			divide = 50;
		}else if((PINDbits._P6 == 0) && (PINDbits._P4 & PINDbits._P5 & PINDbits._P7)){
			divide = 10;
		}
		cli();
		max1 = ((long) divide* (long) dutyCycle /100);
		max2 = divide - max1;
		sei();
}
}
//ISR(TIMER0_OVF_vect){
//		if(!(timeDivCount%9)){
//			//I/O CLK/8 = 9000hz -> 9000hz/9 = 1000hz => 1ms
//			time++;
//			if (max == 1){
//				if (time >= max1){
//					PORTB = PORTB ^ 0xFF; //toggle wave
//					time = 0;
//					max = 0;
//				}
//			} else if (max== 0){
//				if (time >= max2){
//					PORTB = PORTB ^ 0xFF; //toggle wave
//					time = 0;
//					max = 1;
//				}
//			}
//		}
//		timeDivCount++;
//}

