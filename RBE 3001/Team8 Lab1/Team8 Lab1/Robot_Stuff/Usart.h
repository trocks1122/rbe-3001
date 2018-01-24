/*
 * USART.h
 *
 *  Created on: Jan 23, 2016
 *      Author: Joe
 *
 *      this file implements the USARTDebug.h of RBELib
 */

#ifndef USART_H_
#define USART_H_

#include <avr/io.h> // AVR IO

#endif /* USART_H_ */

/**
 * @brief Initializes USART1 as a print terminal to the PC. This function
 * must check the incoming baudrate against the valid baudrates
 * from the data-sheet. If the baudrate is invalid, then the
 * DEFAULT_BAUD constant must be used instead.
 *
 * @param baudrate The desired baudrate to set for USART1.
 *
 * @todo Create the function that will initialize USART1 for debugging use.
 */
void debugUSARTInit(unsigned long baudrate){
	int numBaudRates=12, i=0;
	unsigned long bauds[] = {2400,4800,9600,14400,19200,28800,38400,57600,76800,115200,230400,250000}; //valid baudrates
	unsigned long setBaudrate, defBaud = 115200;

	//uses default baudrate if not a valid baudrate
	for(i=0;i<numBaudRates;i++){
		if(baudrate != bauds[i]){
			setBaudrate = defBaud;
		} else {
			setBaudrate = baudrate;
			break;
		}
	}

	initRBELib(); //changes stdout to USART output


	UCSR1A = 0b00100000; //turn off double transmission speed, indicate UDRE is empty
	UCSR1C = 0b00000110; //8-bit characters, 1 stop bit, asynchronous mode, disable parity

	UCSR1A &= ~(1<<U2X1); //disable double speed operation //everything is bit shifted one more than expected because whoever made the header made an oopsy. Everywhere.
	UCSR1B |= (1<<RXEN1|1<<TXEN1); //enable receive ,enable transmit

	UBRR1 = 9; //(18432000 / (16 * 115200) - 1), set baudrate of USART
}

/**
 * @brief Sends one byte to the USART1 Tx pin (Transmits one byte).
 *
 * @param byteToSend The byte that is to be transmitted through USART1.
 *
 * @todo Make the function that will put a character on the USART1 TX line.
 */
void putCharDebug(char byteToSend)
{
/* Wait for empty transmit buffer */
while ( !( UCSR1A & (1<<UDRE1)) );
/* Put data into buffer, sends the data */
UDR1 = byteToSend;
}


/**
 * @brief Recieves one byte of data from the serial port (i.e. from the PC).
 *
 * @return byteReceived Character that was received on the USART.
 *
 * @todo Make the function that will listen for input on the USART1 RX line.
 */
unsigned char getCharDebug(void){
	//wait for data to be received in RX register
	while(!(UCSR1A & (1<<RXC1)));

	//return data
	return UDR1;
}
