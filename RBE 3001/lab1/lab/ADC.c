/*
 * ADC.c
 *
 *  Created on: Jan 27, 2016
 *      Author: tarocks
 */


#include "RBELib/RBELib.h"
#include <avr/iom644p.h>
/**
 * @brief Initializes the ADC and make one channel active.
 * You can choose to use either interrupts or polling to read
 * the desired channel.
 *
 * @param channel The ADC channel to initialize.
 *
 * @todo Create the corresponding function to initialize the ADC
 * using the channel parameter.
 */
volatile int ADC_F = 0;

#define BIT(A) 1 << A

void initADC(int channel){
	ADCSRA = BIT(ADEN) | (BIT(ADSC) & 0) | (BIT(ADATE) & 0) | (BIT(ADIF) & 0) | (BIT(ADIE) & 0) | BIT(ADPS1) | BIT(ADPS0);
	changeADC(channel);
}


void clearADC(int channel){
	cli();

	ADCSRA &= 0b01111111; //disable ADC to clear

	ADMUX |= 0x1F; // set to GND

	ADCL |= 0x00;
	ADCH = 0x00;
	sei(); // enable interrupts
 }


unsigned int getADC(int channel){
	changeADC(channel);

	ADCSRA |= BIT(ADSC);
	while ((ADCSRA & BIT(ADIF)) == 0)
		;
	return ADC;
}



void changeADC(int channel){
	cli();
	ADMUX &= 0b11100000;
	ADMUX |= channel;
	sei();
}


