/*
 * MotorBesturing.c
 *
 * Created: 3/9/2018 12:18:55 PM
 * Author : Olasoji
 */ 
#define F_CPU 8000000
#define PWM 0xFFFF-1 
#include <avr/io.h>
#include <util/delay.h>
#include "rp6aansluitingen.h"

void initMotorPWM(){
	//
	TCCR1A |= ( 1 << COM1A1 )  | ( 1 << COM1B1) | ( 1 << WGM10);
	TCCR1B |= (  1 << CS10);
	
	//OCR1A = 6000;
	//OCR1B = 6000;
}
void driveFoward(){
	PORTC |= DIR_L |  DIR_R; 
	PORTD |= MOTOR_L  | MOTOR_R ;
}

void driveBackward(){
	PORTC &= ~ DIR_L; 
	PORTC &= ~ DIR_R;
	PORTD |= MOTOR_L  | MOTOR_R ; 
}
void stopMotor(){
	PORTD &= ~  MOTOR_L ;
	PORTD &= ~  MOTOR_R ;
}

int main(){
    DDRD |= MOTOR_R |  MOTOR_L; 
	DDRC |= DIR_L |  DIR_R;
	initMotorPWM();

	for(int i=0;i<100;i=i+5) {
		OCR1A = i;
		OCR1B = i;
		driveFoward(); 
		_delay_ms(1000);
	}
	
    while (1) 
    {
		  
		 
		 
		driveFoward(); 
		_delay_ms(200);
		stopMotor();
		_delay_ms(1000);
		driveBackward();
		_delay_ms(200);
		stopMotor();
		_delay_ms(1000);
		
	}
}

