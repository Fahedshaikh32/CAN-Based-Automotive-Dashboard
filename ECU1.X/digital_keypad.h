#ifndef MATRIX_KEYPAD_H   // header guard start
#define MATRIX_KEYPAD_H

#define MAX_ROW 4   // number of rows
#define MAX_COL 3   // number of columns

#define STATE_CHANGE 1   // detect state change
#define LEVEL_CHANGE 0   // detect level change

#define MATRIX_KEYPAD_PORT PORTB   // keypad connected to PORTB

#define ROW3 PORTBbits.RB7   // row 3 pin
#define ROW2 PORTBbits.RB6   // row 2 pin
#define ROW1 PORTBbits.RB5   // row 1 pin

#define COL4 PORTBbits.RB4   // column 4 pin
#define COL3 PORTBbits.RB3   // column 3 pin
#define COL2 PORTBbits.RB2   // column 2 pin
#define COL1 PORTBbits.RB1   // column 1 pin

#define MK_SW1 1   // switch 1
#define MK_SW2 2   // switch 2
#define MK_SW3 3   // switch 3
#define MK_SW4 4   // switch 4
#define MK_SW5 5   // switch 5
#define MK_SW6 6   // switch 6
#define MK_SW7 7   // switch 7
#define MK_SW8 8   // switch 8
#define MK_SW9 9   // switch 9
#define MK_SW10 10   // switch 10
#define MK_SW11 11   // switch 11
#define MK_SW12 12   // switch 12

#define ALL_RELEASED 0xFF   // no key pressed

#define HI 1   // high logic level
#define LO 0   // low logic level

void init_matrix_keypad(void);   // initialize keypad
unsigned char scan_key(void);   // scan key press
unsigned char read_switches(unsigned char detection_type);   // read keypad input

#endif   // header guard end