//write bits
uint8_t SER = 0;
//synchronous clock
uint8_t SRCLK = 2;
//set bits on registers
uint8_t RCLK = 1;

//8 bit shift register (SNx4HC595 8-Bit Shift Registers)
uint8_t SHIFTREGISTER = 0x00;
//SER , SRCLK and RCLK as of now have to be set on the same PORT
void writeShiftRegister(volatile uint8_t *port){
	//Enables writing to shift register
	*port &= ~(1 << RCLK);
	//writes bits starting from the most significant bit
	for(int i = 7 ; i >= 0 ; i--){
		//sets synchronous clock to low
		*port &= ~(1 << SRCLK);
		//Writes low or high value to shift register
		if(SHIFTREGISTER & (1 << i)){
			*port |= (1 << SER);
			}else{
			*port &= ~(1 << SER);
		}
		//sets synchronous clock to high
		*port |= (1 << SRCLK);
	}
	//Sets Bits on register
	*port|= (1 << RCLK);
}
