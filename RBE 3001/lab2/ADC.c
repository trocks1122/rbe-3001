/*
 * ADC.c

 *
 *  Created on: Feb 2, 2016
 *      Author: dtschifilliti
 */

#include "RBELib/RBELib.h"

void initADC(int channel){
	/*ADMUX is the ADC Multiplexer Selection Register
	 * Bits 7 and 6 are the Reference selection bits.
	 * They Select the voltage reference for the ADC
	 *
	 * Bit 5 is the ADC left adjust modifier.
	 * If 1 it is left adjusted, if 0 it is right adjusted.
	 *
	 * Bit 4,3,2,1,0 are the analog channel and gain
	 * selection bits.
	 * CH - Bits
	 * 0  - 000
	 * 1  - 001
	 * 2  - 010
	 * 3  - 011
	 * 4  - 100
	 * 5  - 101
	 * 6  - 110
	 * 7  - 111
	 */

	/*ADCSRA is the register for Control of ADC and port A
	 * Bit 7 is the ADC enable. Write 1 to enable the ADC
	 *
	 * Bit 6 is the ADC start conversion, to start each conversion
	 * write this bit 1
	 *
	 * Bit 5 is the Auto trigger enable, is starts a conversion
	 * everytime there is a positive leading edge
	 *
	 * Bit 4 is the ADC interrupt flag, this is set when a
	 * conversion completes and the registers are updated
	 *
	 * Bit 3 is the ADC interrupt pin and is written to 1 with SREG
	 * conversion is complete and interrupt is activated.
	 *
	 * Bits 2,1,0 are the prescaler bits, they determine the division
	 * factor for the XTAL frequency and clock
	 * 000 - /2
	 * 001 - /2
	 * 010 - /4
	 * 011 - /8
	 * 100 - /16
	 * 101 - /32
	 * 110 - /64
	 * 111 - /128
	 */
	ADMUX = 0b01000000 | channel;
	ADCSRA = 0b11100111;
	ADCSRB = 0b11100000;

}

void clearADC(int channel){
	ADMUX &amp;= 0b0100111;
}

unsigned short getADC(int channel){

	ADCSRA |= 0b11000000; //Starts the conversion

	while(!(ADSC &amp; ADIF)){} //do nothing until conversion is done

	return ADCW; //returns read value
}

void changeADC(int channel){
	ADMUX = 0b01000000 | channel;
}
