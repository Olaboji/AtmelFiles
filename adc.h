#pragma once
#include <avr/io.h>
//Analog to Digital

#include <stdlib.h>

void initAD(){
	ADMUX |= (1 << REFS0) ;
	ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2); /* ADC clock prescaler /128 */
	ADCSRA |= (1 << ADEN); /* enable ADC */
}

int readAnalog(int pin){
	int adc;
	ADMUX = (0xf0 & ADMUX) | pin ;
	ADCSRA |= (1 << ADSC | 1 << ADIF); /* start ADC conversion */
	while(ADCSRA & (1 <<ADIF));
	
	adc = ADC;
	return adc;
	
}
