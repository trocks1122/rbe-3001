///*
// * main.c
// *
// *  Created on: Feb 2, 2016
// *      Author: dtschifilliti
// */
//
#include "RBELib/RBELib.h"
#include <avr/iom644p.h>
#include <stdio.h>



int armAngle(void){
	int potVal, angleDeg;
	//575 ADC = 90 degrees
	//190 ADC = 0 degrees
	float divider = 4.277778;//(575-190)/90 degrees

	debugUSARTInit(115200); // initialize USART
	initRBELib();


	initADC(3); //sets ADC to channel 3
    _delay_ms(1);
	potVal = getADC(3);
	//printf("%d\n\r", potVal);
	angleDeg = (potVal-190)/divider;
	//printf("%d\n\r", angleDeg);
	return angleDeg;
}
