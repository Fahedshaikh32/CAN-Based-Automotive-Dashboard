#include <xc.h>   // include microcontroller header
#include "ssd_display.h"   // include SSD header

void init_ssd_control(void)   // function to initialize SSD
{
	TRISD = 0x00;   // set PORTD as output for data lines
	TRISA = TRISA & 0xF0;   // set control pins as output

	SSD_CNT_PORT = SSD_CNT_PORT & 0xF0;   // turn OFF all SSDs
}

void display(unsigned char data[])   // function to display data on SSD
{
	unsigned int wait;   // variable for delay
	unsigned char data_bit;   // variable (not used but kept as it is)
	unsigned char digit;   // variable for digit index

	for (digit = 0; digit < MAX_SSD_CNT; digit++)   // loop through digits
	{
		SSD_DATA_PORT = data[digit];   // send data to SSD
		SSD_CNT_PORT = (SSD_CNT_PORT & 0xF0) | (0x01 << digit);   // enable current digit

		for (wait = 1000; wait--; );   // small delay for display
	}
}