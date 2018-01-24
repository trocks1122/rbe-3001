///*
// * sample.c
// *
// *  Created on: Jan 27, 2016
// *      Author: tarocks
// */
//
//#include "RBELib/RBELib.h"
//#include <avr/iom644p.h>
//#include <stdio.h>
//
//volatile unsigned long int time = 0; timeDiv = 0;
//volatile int ADCcounter = 0;
//volatile unsigned long int hundreths = 0;
//
//int main(void){
//	CLKPR = 0x80;
//	debugUSARTInit(115200); // initialize USART
//	initRBELib();
//	// SET port D as inputs
//	DDRD = 0x00;
//	PORTD = 0xFF;
//
//	DDRB = 0xFF;
//	PORTB = 0xFF;
//
//	_delay_ms(1000);
//	//timer initialization
//	initTimer(0,0,0); //uses timer 0, in normal mode, with no compare value
//	initADC(4); //sets ADC to channel 4
//	int sample[1000];
//	char collected = 0;
//
//	int i = 0;
//	int imax = 0;
//	while(1){
//		if((PINDbits._P5 == 0) && (PINDbits._P4 & PINDbits._P6 & PINDbits._P7)){ //if button 5
//			time = 0;
//			while ((time % 9000) != 0){
//				if((time% 40) ==0){
//					PORTB ^= 0xFF;
//					sample[i] = ADCcounter;
//					sample[i+1] =time;
//					i = i+2;
//				}
//				collected =1;
//			}
//		}
//		if(collected == 1){
//			imax = i;
//			i =0;
//			while(i != imax){
//				printf("%d%c%d\n\r", sample[i],',', sample[i+1]/9);
//				i = i + 2;
//			}
//			collected = 0;
//		}
//	}
//}
