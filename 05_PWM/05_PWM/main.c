/*
 * 05_PWM.c
 *
 * Created: 10.02.2018 14:50:01
 * Author : Joachim
 */ 

// this code sets up counter0 for an 8kHz PWM wave @ 16Mhz Clock

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>



int main(void)
{

	DDRD |= (1 << DDD6);
	// PD6 is now an output
	
	
	
	DDRD &= ~(1 << DDD2);     // Clear the PD2 pin
	// PD2 (PCINT0 pin) is now an input

	PORTD |= (1 << PORTD2);    // turn On the Pull-up
	// PD2 is now an input with pull-up enabled

	DDRD &= ~(1 << DDD3);     // Clear the PD3 pin
	// PD3 (PCINT1 pin) is now an input

	PORTD |= (1 << PORTD3);    // turn On the Pull-up
	// PD3 is now an input with pull-up enabled


	

	OCR0A = 64+128;
	// set PWM for 75% duty cycle


	TCCR0A |= (1 << COM0A1);
	// set none-inverting mode

	TCCR0A |= /*(1 << WGM02) | */(1 << WGM01)  | (1 << WGM00);
	// set fast PWM Mode

	TCCR0B |= (1 << CS01);
	// set prescaler to 8 and starts PWM
	
	

	//sei();
	while (1);
	{
		
	}
}
