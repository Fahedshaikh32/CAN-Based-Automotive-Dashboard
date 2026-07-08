#include <xc.h>   // include microcontroller header
#include "uart.h"   // include uart header file

void init_uart(void)   // function to initialize UART
{
	/* Serial initialization */
	RX_PIN = 1;   // set RX pin as input
	TX_PIN = 0;   // set TX pin as output

	/* TXSTA:- Transmitor Status and control Register */
	TX9 = 0;   // disable 9-bit transmission
	TXEN = 1;   // enable UART transmission
	SYNC = 0;   // select asynchronous mode
	SENDB = 0;   // disable break character
	BRGH = 1;   // set high baud rate

	/* RCSTA :- Recepition Status and control Register */
	SPEN = 1;   // enable serial port
	RX9 = 0;   // disable 9-bit reception
	CREN = 1;   // enable continuous receive

	/* BAUDCTL:- Baud rate control register */
	BRG16 = 0;   // use 8-bit baud rate generator

	/* Baud Rate Setting Register */
	SPBRG = 129;   // set baud rate value (9600)

	TXIF = 0;   // clear transmit interrupt flag
	RCIF = 0;   // clear receive interrupt flag
}

void putch(unsigned char byte)    // function to send one byte
{
	while(!TXIF)   // wait until transmit buffer is empty
	{
		continue;   // do nothing and wait
	}
	TXIF = 0;   // clear transmit flag
	TXREG = byte;   // load data to transmit register
} 

int puts(const char *s)   // function to send string
{
	while(*s)   // loop until end of string
	{
		putch(*s++);   // send each character
	}
	return 0;   // return success
}

unsigned char getch(void)   // function to receive one byte
{
	while(!RCIF)   // wait until data is received
	{
		continue;   // do nothing and wait
	}
	RCIF = 0;   // clear receive flag
	return RCREG;   // return received data
}

unsigned char getche(void)   // function to receive and echo character
{
	unsigned char c;   // variable to store character

	putch(c = getch());   // receive and send back same character

	return (c);   // return received character
}