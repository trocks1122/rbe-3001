///*
// * main.c
// *
// *  Created on: Jan 21, 2016
// *      Author: Mt Landis
// */
//#include "RBELib/RBELib.h" //RBE Lib
//#include <avr/io.h> // AVR IO
//#include <stdio.h>
//#include "Usart.h"
//#include "TimerConfig.h"
//#include "adc.h"
//
//int ISR_Flag=0;
//volatile char time = 0;
//volatile int timeDivCount = 0;
//
//
//int main(void){
//	int timestamp = 1,ADCcount=2, potVal = 157, potAngle = 20;
//	debugUSARTInit(115200);    // Initialize USART, enables printf()
//
//	DDRB = 0xFF;    // Set Port as output
//	PORTB = 0x0F;
//
//
//	/////////TIMER STUFF
//	//CLKPR = 0b10001000; //we shouldn't slow down the system clock speed
//	//CLKPR &= 0b11111000;
//
//	initTimer(0,0,0); //Timer0, normal (overflow) mode, no compare value
//	initADC(4);
//
//	while (1)
//	{
//		//PORTB = ~time; // This now counts 8 times slower. Its pretty cool.
//		//timestamp, ADC Count, Pot Values in mV, Pot Angle in degrees
//		//ADCcount = getADC(4)/4;
//		//PORTB = ADCcount;
//		//PORTB = getADC(4)/4;
//		//printf("%d%c%d%c%d%c%d\n\r",timestamp,',',ADCcount,',',potVal,',',potAngle);
//		printf("%d%c%d%c%d\n\r", ADCH,',', ADCL,',',getADC(4));
//		_delay_ms(10);
//	}
//	return 0;
//}
//
//
//ISR(TIMER0_OVF_vect){
//	if(!(timeDivCount%8)){
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
