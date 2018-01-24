///*
// * ADCTest.c
// *
// *  Created on: Jan 25, 2016
// *      Author: Joe
// *
// *
// *
// *
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
////LAB #1, Question 2
//int main(void){
//	int ADCcount, potAngle, potVal;
//	debugUSARTInit(115200);    // Initialize USART serial communications, enables printf()
//
//	initTimer(0,0,0); //Timer0, normal (overflow) mode, no compare value
//	initADC(4); //start ADC on analog channel 4
//
//	getCharDebug(); //wait for input from keyboard
//	time = 0; //reset timer
//	while (1)
//	{
//		ADCcount = getADC(4); //read adc 0-1023
//		potVal = (int) ((long) ADCcount)*((long) 5000)/1023; //convert to value in mV
//		potAngle = (int) ((long) ADCcount)*((long) 270)/1023; //convert from 0-1023 to 0-270 degree angle
//		printf("%ld%c%ld%c%d%c%d%c%d\n\r",time/1000,'.', time % 1000,',',ADCcount,',',potVal,',',potAngle); //print all
//		_delay_ms(10);
//	}
//	return 0;
//}
//
//
//ISR(TIMER0_OVF_vect){
//	if(!(timeDivCount%9)){
//		//I/O CLK/8 = 9000hz -> 9000hz/9 = 1000hz => 1ms
//		time++;
//	}
//	timeDivCount++;
//}
//
//
//
//
//
//
