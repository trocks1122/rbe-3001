///*
// * SquareWaveTest.c
// *
// *  Created on: Jan 25, 2016
// *      Author: Joe
// */
//
//#include "RBELib/RBELib.h"
//#include <avr/io.h> //
//#include <stdio.h>
//#include "Usart.h"
//#include "TimerConfig.h"
//#include "adc.h"
//
//volatile unsigned long int time = 0;
//volatile unsigned long int timeDivCount = 0;
//
//unsigned int ceiling1;
//unsigned int ceiling2;
//char ceiling = 1;
//
////LAB #1, Question 3
//int main(void){
//	int ADCcount, dutyCycle, frequency;
//
//	unsigned int divider = 9;
//
//
//	debugUSARTInit(115200);    // Initialize USART serial communications, enables printf()
//	initADC(4); //start ADC on analog channel 4
//
//	initTimer(0,0,0); //Timer0, normal (overflow) mode, no compare value
//
//	//set pins of Port D as inputs
//	DDRD = 0x00;
//	PORTD = 0xFF; //pull-up resistors
//
//	DDRB = 0xFF;
//
//	PORTB = 0xFF;
//	_delay_ms(1000);
//
//
//	while(1){
//		ADCcount = getADC(4); //read adc 0-1023
//		dutyCycle = (int) ((long) ADCcount)*((long) 100)/1023; //convert to value in mV
//		//printf("%d%c\n\r", dutyCycle, ',');
//		frequency = 1000/divider;
//		printf("%d%c%d%c%d%c%d\n\r", dutyCycle, ',', frequency,',', ceiling, ',', ADCcount);
//
//		//printf("%d%d%d%d%d%d%d%d\n\r", PINDbits._P0,PINDbits._P1,PINDbits._P2,PINDbits._P3,PINDbits._P4,PINDbits._P5,PINDbits._P6,PINDbits._P7);
//		if((PINDbits._P4 == 0) && (PINDbits._P5 & PINDbits._P6 & PINDbits._P7)){
//			divider = 1000; //1hz wave
//		}
//		} else if((PINDbits._P6 == 0) && (PINDbits._P4 & PINDbits._P5 & PINDbits._P7)){
//			divider = 10; //100hz wave
//		}
//		cli();
//		ceiling1 = ((long) divider * (long) dutyCycle) /100;
//		ceiling2 = divider - ceiling1;
//		sei();
//
//
//	}
//
//}
//
//
ISR(TIMER0_OVF_vect){
	if(!(timeDivCount%9)){
		//I/O CLK/8 = 9000hz -> 9000hz/9 = 1000hz => 1ms
		time++;
		if (ceiling == 1){
			if (time >= ceiling1){
						PORTB = PORTB ^ 0xFF; //toggle wave
						time = 0;
						ceiling = 0;
					}
		} else if (ceiling == 0){
			if (time >= ceiling2){
						PORTB = PORTB ^ 0xFF; //toggle wave
						time = 0;
						ceiling = 1;
					}
		}
	}
	timeDivCount++;
//}
//
//
//
//
//
//
