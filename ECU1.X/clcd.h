#ifndef LCD_H   // header guard start
#define LCD_H

#define CLCD_PORT PORTD   // LCD data port
#define CLCD_EN RC2   // enable pin
#define CLCD_RS RC1   // register select pin
#define CLCD_RW RC0   // read/write pin
#define CLCD_BUSY RD7   // busy flag pin
#define PORT_DIR TRISD7   // direction control for busy pin

#define HI 1   // high logic level
#define LO 0   // low logic level

#define INPUT 0xFF   // set port as input
#define OUTPUT 0x00   // set port as output

#define DATA_COMMAND 1   // data mode
#define INSTRUCTION_COMMAND 0   // instruction mode

#define LINE1(x) (0x80 + (x))   // cursor position line 1
#define LINE2(x) (0xC0 + (x))   // cursor position line 2

#define TWO_LINE_5x8_MATRIX_8_BIT clcd_write(0x38, INSTRUCTION_COMMAND)   // set LCD mode
#define CLEAR_DISP_SCREEN clcd_write(0x01, INSTRUCTION_COMMAND)   // clear screen
#define CURSOR_HOME clcd_write(0x02, INSTRUCTION_COMMAND)   // move cursor home
#define DISP_ON_AND_CURSOR_OFF clcd_write(0x0C, INSTRUCTION_COMMAND)   // display ON cursor OFF

void init_clcd(void);   // initialize LCD
void clcd_print(const unsigned char *data, unsigned char addr);   // print string
void clcd_putch(const unsigned char data, unsigned char addr);   // print character
void clcd_write(unsigned char bit_values, unsigned char control_bit);   // send data/command

#endif   // header guard end