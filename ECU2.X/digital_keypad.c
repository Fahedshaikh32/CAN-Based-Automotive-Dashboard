#include <xc.h>   // include microcontroller header
#include "digital_keypad.h"   // include keypad header

void init_digital_keypad(void)   // function to initialize keypad
{
	TRISC = TRISC | INPUT_PINS;   // set input pins
}

unsigned char read_digital_keypad(unsigned char detection_type)   // function to read keypad
{
	static unsigned char once = 1;   // flag for single press

	if (detection_type == STATE_CHANGE)   // check state change mode
	{
		if (((KEY_PORT & INPUT_PINS) != ALL_RELEASED) && once)   // if key pressed once
		{
			once = 0;   // disable repeat
			return (KEY_PORT & INPUT_PINS);   // return key value
		}
		else if ((KEY_PORT & INPUT_PINS) == ALL_RELEASED)   // if no key pressed
		{
			once = 1;   // reset flag
		}
	}
	else if (detection_type == LEVEL)   // check level mode
	{
		return (KEY_PORT & INPUT_PINS);   // return key value
	}

	return 0xFF;   // no key pressed
}