/*
 * USART.c

 *
 *  Created on: Jan 27, 2016
 *      Author: tarocks
 */

#include "RBELib/RBELib.h"


void USART(){

	UBRR = (18432000 / (16 * 9600) - 1) >> 8;

}
