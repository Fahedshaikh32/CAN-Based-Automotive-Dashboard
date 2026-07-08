#include <xc.h>   // include microcontroller header
#include "digital_keypad.h"   // include keypad header

void init_matrix_keypad(void)   // function to initialize keypad
{
	ADCON1 = 0x0F;   // set PORTB as digital

	TRISB = 0x1E;   // set rows as output and columns as input

	RBPU = 0;   // enable pull-up resistors

	MATRIX_KEYPAD_PORT = MATRIX_KEYPAD_PORT | 0xE0;   // set rows high
}

unsigned char scan_key(void)   // function to scan pressed key
{
	ROW1 = LO;   // activate row 1
	ROW2 = HI;   // deactivate row 2
	ROW3 = HI;   // deactivate row 3

	if (COL1 == LO)   // check column 1
	{
		return 1;   // return key 1
	}
	else if (COL2 == LO)   // check column 2
	{
		return 4;   // return key 4
	}
	else if (COL3 == LO)   // check column 3
	{
		return 7;   // return key 7
	}
	else if (COL4 == LO)   // check column 4
	{
		return 10;   // return key 10
	} 

	ROW1 = HI;   // deactivate row 1
	ROW2 = LO;   // activate row 2
	ROW3 = HI;   // deactivate row 3

	if (COL1 == LO)   // check column 1
	{
		return 2;   // return key 2
	}
	else if (COL2 == LO)   // check column 2
	{
		return 5;   // return key 5
	}
	else if (COL3 == LO)   // check column 3
	{
		return 8;   // return key 8
	}
	else if (COL4 == LO)   // check column 4
	{
		return 11;   // return key 11
	} 

	ROW1 = HI;   // deactivate row 1
	ROW2 = HI;   // deactivate row 2
	ROW3 = LO;   // activate row 3
	ROW3 = LO;   // keep row 3 active

	if (COL1 == LO)   // check column 1
	{
		return 3;   // return key 3
	}
	else if (COL2 == LO)   // check column 2
	{
		return 6;   // return key 6
	}
	else if (COL3 == LO)   // check column 3
	{
		return 9;   // return key 9
	}
	else if (COL4 == LO)   // check column 4
	{
		return 12;   // return key 12
	} 
    
	return 0xFF;   // no key pressed
}

unsigned char read_switches(unsigned char detection_type)   // function to read key
{
	static unsigned char once = 1, key;   // variables for state detection

	if (detection_type == STATE_CHANGE)   // check for state change
	{
		key = scan_key();   // scan key

		if(key != 0xFF && once)   // if key pressed once
		{
			once = 0;   // disable repeat
			return key;   // return key
		}
		else if(key == 0xFF)   // if no key pressed
		{
			once = 1;   // reset flag
		}
	}
	else if (detection_type == LEVEL_CHANGE)   // check for level change
	{
		return scan_key();   // return key directly
	}

	return 0xFF;   // no key
}