#pragma once
#include <avr/io.h>

#include <stdlib.h>
/*Functions for serial input and output*/

void initSerial(){
	UCSR0B = (1 << TXEN0) | (1 << RXEN0) | (1 << RXCIE0); // Enable de USART Transmitter, Reciever and Reciever interrupt
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); /* 8 data bits, 1 stop bit */
	
	UBRR0H=00;
	UBRR0L=103; //baudrade 9600 bij
}

void writeChar(char character) {
	//wacht tot register leeg is 
	while (~UCSR0A & (1 << UDRE0));
	UDR0 = character;
}
//code van practicum
void writeString(char _string[])
{
	for (uint8_t i = 0; _string[i] != 0; i++) {
		writeChar(_string[i]);
	}
}
//code van practicum
void writeInt(int _int, int buffersize)
{
	char buffer[buffersize];
	itoa(_int, buffer, 10);
	writeString(buffer);
}
void writeFloat(float _float, int buffersize){
	char buffer[buffersize];
	dtostrf(_float,6,2,buffer);
	writeString(buffer);
}

char readChar() {
char c;
while(~UCSR0A & (1<<RXC0));
c=UDR0;
	  
return c; 
}
//code van practicum


//code van practicum
int readInt( int buffersize)
{
	
	char buffer[buffersize];
	for(int i =0; i<buffersize;i++){
		
		buffer[i] = readChar();
	    if(buffer[i]==13){
			
			i++;
			buffer[i] =0;
			break;
		}
	
	}
	return atoi(buffer);
}

