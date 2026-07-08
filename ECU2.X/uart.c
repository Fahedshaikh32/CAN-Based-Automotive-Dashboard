#include <xc.h>   // include microcontroller header
#include "uart.h"   // include UART header

void init_uart(void)   // function to initialize UART
{
	RX_PIN = 1;   // set RX pin as input
	TX_PIN = 0;   // set TX pin as output

	TX9 = 0;   // disable 9-bit transmission
	TXEN = 1;   // enable transmission
	SYNC = 0;   // set asynchronous mode
	SENDB = 0;   // disable break signal
	BRGH = 1;   // set high baud rate

	SPEN = 1;   // enable serial port
	RX9 = 0;   // disable 9-bit reception
	CREN = 1;   // enable continuous receive

	BRG16 = 0;   // use 8-bit baud generator

	SPBRG = 129;   // set baud rate (9600)

	TXIF = 0;   // clear transmit flag
	RCIF = 0;   // clear receive flag
}

void putch(unsigned char byte)    // function to send one byte
{
	while(!TXIF)   // wait until buffer is empty
	{
		continue;   // keep waiting
	}
	TXIF = 0;   // clear transmit flag
	TXREG = byte;   // send data
} 

int puts(const char *s)   // function to send string
{
	while(*s)   // loop through string
	{
		putch(*s++);   // send each character
	}
	return 0;   // return success
}

unsigned char getch(void)   // function to receive one byte
{
	while(!RCIF)   // wait until data received
	{
		continue;   // keep waiting
	}
	RCIF = 0;   // clear receive flag
	return RCREG;   // return received data
}

unsigned char getche(void)   // function to receive and echo
{
	unsigned char c;   // variable to store data

	putch(c = getch());   // receive and send back

	return (c);   // return data
}