/*
 * adc.h
 *
 *  Created on: Jan 23, 2016
 *      Author: Joe
 */

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h> // AVR IO

#endif /* ADC_H_ */


volatile int ADC_Complete=0;

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
void initADC(int channel){
	//bits 7, 6 - select referenc voltage
	//bit 5 - left adjust
	//bits 4-0 channel select
	ADMUX &= 0x10;
	ADMUX |= channel;

	//bits 7-3 reserved
	//bits 2-0 auto trigger source
	ADCSRB = 0b00000000; //timer/counter0 = 000

	//bit 7 - ADC enable
	//bit 6 - start conversion bit
	//bit 5 - auto trigger enable
	//bit 4 - ADC interrupt flag
	//bit 3 - ADC interrupt enable
	//bit 2-0 - clock divider select
	//ADCSRA |= (ADEN | ADATE | ADIE);
	//ADCSRA &= 0b11111100; //clock select divider/2

	ADCSRA = 0b11101111;
}

/**
 * @brief Disables ADC functionality and clears any saved values (globals).
 *
 * @param channel  The ADC channel to disable.
 *
 * @todo Create the corresponding function to clear the last ADC
 * calculation register and disconnect the input to the ADC if desired.
 */
void clearADC(int channel){
	cli();
	//bit 7 - ADC enable
	//bit 6 - start conversion bit
	//bit 5 - auto trigger enable
	//bit 4 - ADC interrupt flag
	//bit 3 - ADC interrupt enable
	//bit 2-0 - clock divider select
	ADCSRA &= 0b01111111; //disable ADC

	//bits 7, 6 - select referenc voltage
	//bit 5 - left adjust
	//bits 4-0 channel select
	ADMUX |= 0x1F; //set ADC to GND

	ADCL = 0x00; //clear ADC data regs low and high
	ADCH = 0x00;
	sei();
}

/**
 * @brief Run a conversion on and get the analog value from one ADC
 * channel if using polling.
 *
 * @param channel  The ADC channel to run a conversion on.
 * @return adcVal The 8-10 bit value returned by the ADC
 * conversion.  The precision depends on your settings and
 * how much accuracy you desire.
 *
 * @todo Create the corresponding function to obtain the value of the
 * last calculation if you are using polling.
 */
unsigned short getADC(int channel){
	unsigned short adcVal=0;
	//bits 7, 6 - select referenc voltage
	//bit 5 - left adjust
	//bits 4-0 channel select
	ADMUX &= 0b11100000;
	ADMUX |= channel;

	//ADC_Complete = 0;

	//start conversion
	//bit 7 - ADC enable
	//bit 6 - start conversion bit
	//bit 5 - auto trigger enable
	//bit 4 - ADC interrupt flag
	//bit 3 - ADC interrupt enable
	//bit 2-0 - clock divider select
	//ADCSRA |= ADSC;

	//while(!ADC_Complete);

	adcVal = ADCL;
	adcVal |= ((int) ADCH) << 8;




	return adcVal;

}

/**
 * @brief Change the channel the ADC is sampling if using interrupts.
 *
 * @param channel  The ADC channel to switch to.
 *
 * @todo Create a way to switch ADC channels if you are using interrupts.
 */
void changeADC(int channel){
	cli();
	//bits 7, 6 - select referenc voltage
	//bit 5 - left adjust
	//bits 4-0 channel select
	ADMUX &= 0b11100000;
	ADMUX |= channel;
	sei();
}




