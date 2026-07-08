#ifndef DIGITAL_KEYPAD_H   // header guard start
#define DIGITAL_KEYPAD_H

#define LEVEL 0   // level detection mode
#define STATE_CHANGE 1   // state change detection mode

#define KEY_PORT PORTC   // keypad connected to PORTC

#define SWITCH1 0x0E   // switch 1 value
#define SWITCH2 0x0D   // switch 2 value
#define SWITCH3 0x0B   // switch 3 value
#define SWITCH4 0x07   // switch 4 value
#define ALL_RELEASED 0x0F   // no key pressed

#define INPUT_PINS 0x0F   // input pin mask

void init_digital_keypad(void);   // initialize keypad
unsigned char read_digital_keypad(unsigned char detection_type);   // read keypad input

#endif   // header guard end