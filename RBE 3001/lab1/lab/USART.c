/*
 * USART.c

 *
 *  Created on: Jan 27, 2016
 *      Author: tarocks
 */

#include "RBELib/RBELib.h"
//#include <avr/io.h>
#include <avr/iom644p.h>

void debugUSARTInit(unsigned long baudrate){

	initRBELib(); //changes stdout to USART output

	UBRR1H = (F_CPU / (16 * baudrate) - 1) >> 8;
	UBRR1L = (F_CPU / (16 * baudrate) - 1);
	//UBRRL1 = (unsigned char)baudrate;
	/* Enable receiver and transmitter */
	UCSR1B = (1<<RXEN1)|(1<<TXEN1);
	/* Set frame format: 8data, 2stop bit */
	UCSR1C = (1<<USBS1)|(3<<UCSZ10);

	return;

}


unsigned char getCharDebug( void )
{
/* Wait for data to be received */
while ( !(UCSR1A & (1<<RXC1)) )
;
/* Get and return received data from buffer */
return UDR1;
}


void putCharDebug(char byteToSend){
	/* Wait for empty transmit buffer */
	while ( !( UCSR1A & (1<<UDRE1)) )
	;
	/* Put data into buffer, sends the data */
	UDR1 = byteToSend;
}
