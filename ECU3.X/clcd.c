#include <xc.h>   // include microcontroller header
#include "clcd.h"   // include LCD header file

void clcd_write(unsigned char byte, unsigned char control_bit)   // function to send data/command to LCD
{
	CLCD_RS = control_bit;   // select data or instruction
	CLCD_PORT = byte;   // put data on LCD port

	CLCD_EN = HI;   // enable LCD
	CLCD_EN = LO;   // disable LCD

	PORT_DIR = INPUT;   // set port as input to check busy flag
	CLCD_RW = HI;   // set read mode
	CLCD_RS = INSTRUCTION_COMMAND;   // select instruction register

	do
	{
		CLCD_EN = HI;   // enable LCD
		CLCD_EN = LO;   // disable LCD
	} while (CLCD_BUSY);   // wait until LCD is free

	CLCD_RW = LO;   // set write mode
	PORT_DIR = OUTPUT;   // set port back to output
}

void init_clcd()   // function to initialize LCD
{
	TRISD = 0x00;   // set PORTD as output
	TRISC = TRISC & 0xF8;   // set control pins as output

	CLCD_RW = LO;   // set write mode

	CURSOR_HOME;   // move cursor to home
	TWO_LINE_5x8_MATRIX_8_BIT;   // set LCD mode
	DISP_ON_AND_CURSOR_OFF;   // turn display ON and cursor OFF
	CLEAR_DISP_SCREEN;   // clear LCD screen
}

void clcd_print(const unsigned char *data, unsigned char addr)   // function to print string
{
	clcd_write(addr, INSTRUCTION_COMMAND);   // set cursor position

	while (*data != '\0')   // loop until end of string
	{
		clcd_write(*data++, DATA_COMMAND);   // send each character
	}
}

void clcd_putch(const unsigned char data, unsigned char addr)   // function to print one char
{
	clcd_write(addr, INSTRUCTION_COMMAND);   // set cursor position
	clcd_write(data, DATA_COMMAND);   // send character
}