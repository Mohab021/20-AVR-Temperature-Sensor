
#define F_CPU 4000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "AVR_Ports.h"
#include "AVR_LCD_Declarations.h"
#include "AVR_ADC_Declarations.h"

int main(void)
{
	float Celsius;
	uint8_t x;
	char int_buffer[12]; //string for LCD printing
	
	LCD_Initialize();
	ADC_Initialize();
	
	while(1)
	{
		LCD_Clear;
		
		Celsius = ADC_Read(0); //read ADC value at PA0
		Celsius = (Celsius * 5) / (1023);
		Celsius *= 100; //41C = 0.41V from sensor, so we need to print Celsius not Volt
		x = (int) Celsius;
		itoa(x, int_buffer, 10); //for printing Int, 10 for decimal output (as a string)
		LCD_Print_xy(0, 0, "Temperature:");
		_delay_ms(100);
		LCD_Print_xy(1, 0, int_buffer);
		_delay_ms(100);
		LCD_Print(" C");
		_delay_ms(1000);
	}
}
