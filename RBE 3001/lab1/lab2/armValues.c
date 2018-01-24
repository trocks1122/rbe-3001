/*
 * armValues.c
 *
 *  Created on: Feb 2, 2016
 *      Author: tarocks
 */

#include "RBELib/RBELib.h"
#include <avr/iom644p.h>
#include <stdio.h>
#include <float.h>

int armAngle();

void armValues()
{
	int ADCcount;
	int millivolts = 0;
	int angle = 0;

	debugUSARTInit(115200); // initialize USART
	initRBELib();


	initADC(3); //sets ADC to channel 3

	ADCcount = getADC(3); //ADC value
	millivolts = 1000*(ADCcount/204.6); //1023 adc counts/(5-0) volts = 204.6
	angle = armAngle();//arm angle function
	printf("%d%c%d%c%d\n\r",ADCcount,',',millivolts,',',angle);
}
