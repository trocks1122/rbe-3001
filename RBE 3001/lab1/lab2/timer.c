/*
 * timer.c
 *
 *  Created on: Jan 27, 2016
 *      Author: tarocks
 */

//#ifndef TIMER_H_
//#define TIMER_H_

#include "RBELib/RBELib.h"
#include <avr/iom644p.h>
#include <avr/io.h>
#include <stdio.h>

void initTimer(int timer, int mode, unsigned int comp){
	//set timer mode
		if(timer == 0){
			if (mode == 1){
				OCR0A = comp;
				sei(); // interrupts enabled

				TIMSK0 |= 0x02; // set to compare match B enabled
			}
			else{
				TCCR0A |= 0x00; //normal mode

				TCCR0B |= 0b0000010;
				sei();

				TIMSK0 |= 0x01; // set to compare match A enabled

			}
		}
}


void setCompValue(unsigned char timer, unsigned short int comp){
	if(timer == 0){
		OCR0A = comp;
	}else if(timer == 1){
		OCR1A = (comp << 8);
		OCR1B = (comp);
	}else{
		OCR0A = comp;
	}

}

