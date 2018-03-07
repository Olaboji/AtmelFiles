/*
 * Shift register.c
 *
 * Created: 3/6/2018 6:14:48 PM
 * Author : sojim
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <math.h>
#include <avr/delay.h>
//write bits 
#define SER 0 
//synchronous clock 
#define SRCLK 2
//set bits on registers 
#define RCLK 1

 //8 bit shift register (SNx4HC595 8-Bit Shift Registers)
 uint8_t SHIFTREGISTER = 0x00;

void writeShiftRegister(){ 
	
	
	PORTD &= ~(1 << RCLK);
	for(int i = 7 ; i >= 0 ; i--){
		PORTD &= ~(1 << SRCLK);
		if(SHIFTREGISTER & (1 << i)){ 
			PORTD |= (1 << SER);
		}else{
            PORTD &= ~(1 << SER);
		}
		PORTD |= (1 << SRCLK);
	}
	PORTD|= (1 << RCLK);
}
int main(void)
{

    while (1) 
    {
	
    }
}

