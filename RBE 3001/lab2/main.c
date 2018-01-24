/*
 * main.c
 *
 *  Created on: Feb 2, 2016
 *      Author: dtschifilliti
 */

int main(void){

	int potVal, angleDeg;
	changeADC(2);
	_delay_ms(1);
	potVal = getADC(2);
	angleDeg = potVal*Somevalue+SomeotherValue;
	return angleDeg;
}
