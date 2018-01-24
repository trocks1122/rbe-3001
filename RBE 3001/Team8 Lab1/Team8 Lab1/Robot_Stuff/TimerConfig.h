/*
 * timer.h
 *
 *  Created on: Jan 23, 2016
 *      Author: Joe
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "RBELib/timer.h"
#include <avr/io.h> // AVR IO

#endif /* TIMER_H_ */


/**
 * @brief Initializes the specified timer in the specified mode. This
 * header file provides constants for NORMAL operation mode and
 * CTC operation mode, however there are many more modes of operation
 * for the Timers that can be experimented with.
 *
 * @param timer The number of the timer to be initialized (0-2).
 * @param mode The mode to initialize the specified timer in.
 * @param comp Only used in CTC mode. The value that the
 * timer counts to before it triggers an interrupt and resets.
 *
 * @todo Create a function that initializes the desired timer in a given mode and set the compare value
 * (as appropriate).
 */
void initTimer(int timer, int mode, unsigned int comp){
	//Timer0, I/O CLOCK = 72000Hz = 18432000/256 !!!!!!
	if(timer == 0){
		//compare mode
		if(mode == 1){
			//8-bit CTC compare value
			OCR0A = comp;
			sei();//enable interrupts

			//bits 7-3 - reserved
			//bit 2 - CTC B interrupt enable
			//bit 1 - CTC A interrupt enable
			//bit 0 - overflow mode interrupt enable
			TIMSK0 |= 0x02;//compare match (CTC) A enabled
		//overflow mode
		} else {
			//TCCR0A
			//bits 7,6 - compare match output A mode
			//bits 5,4 - compare match output B mode
			//bits 3,2 - reserved
			//bits 1,0- waveform generation mode
			TCCR0A |= 0x00; //normal mode

			//TCCR0B
			//bits 7,6 - force output compare A and B
			//bits 5,4 - reserved
			//bit  3   - waveform generation mode
			//bits 2-0 - clock select
			TCCR0B |= 0b0000010; //clock select, clk/8)

			sei();//enable interrupts
			//bits 7-3 - reserved
			//bit 2 - CTC B interrupt enable
			//bit 1 - CTC A interrupt enable
			//bit 0 - overflow mode interrupt enable
			TIMSK0 |= 0x01;
		}
	//Timer1
	} else if(timer == 1){
		//compare mode
		if(mode == 1){
			//8-bit CTC compare value
			OCR1A = comp;
			sei();//enable interrupts

			//bits 7,6 - reserved
			//bit 5 - CTC B interrupt enable
			//bit 1 - CTC A interrupt enable
			//bit 0 - overflow mode interrupt enable
			TIMSK1 |= 0x02;//compare match (CTC) A enabled
		//overflow mode
		} else {

		}



	//Timer2
	} else if(timer == 2){
		//compare mode
		if(mode == 1){

	    //overflow mode
		} else {

		}

	} else { //default to Timer0, same as first case
		//compare mode
		if(mode == 1){
			OCR0A = comp; //compare value
			sei();//enable interrupts
			TIMSK0 |= 0x02;//compare match (CTC) A enabled
		//overflow mode
		} else {
			TCCR0A |= 0x00; //normal mode
			TCCR0B |= 0b00000010; //clock select (0x05 = clk/1024)
			sei();//enable interrupts
			TIMSK0 |= 0x01; //overflow interrupt enable
		}
	}
}

/**
 * @brief Only used when the specified timer is in CTC mode. Changes
 * the value of the comparison register to the new specified value.
 *
 * @param timer The timer comparison value to change (0-2).
 * @param comp The value to set the comparison register to.
 *
 * @todo Create a function that will set a new compare value for the given timer.
 */
void setCompValue(unsigned char timer, unsigned short int comp){
	//this may need to be fixed
	//Timer0 compare value
	if(timer == 0){
		OCR0A = comp;
	} else if(timer == 1){ //Timer1 compare value
		OCR1A = (comp << 8);
		OCR1B = (comp);
	} else if(timer == 2){ //Timer2 compare value
		OCR2A = (comp << 8);
		OCR2B = (comp);
	} else { //defaults to Timer0 compare value
		OCR0A = comp;
	}
}







