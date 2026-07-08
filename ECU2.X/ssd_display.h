#ifndef SSD_DISPLAY_H   // header guard start
#define SSD_DISPLAY_H  

#define MAX_SSD_CNT 4   // maximum number of SSD digits

#define HIGH 1   // high logic level
#define LOW 0   // low logic level

#define MAX_SSD_CNT 4   // maximum SSD count (duplicate define kept as is)

#define SSD_DATA_PORT PORTD   // data port for SSD
#define SSD_CNT_PORT PORTA   // control port for SSD

#define ZERO 0xE7   // pattern for digit 0
#define ONE 0x21   // pattern for digit 1
#define TWO 0xCB   // pattern for digit 2
#define THREE 0x6B   // pattern for digit 3
#define FOUR 0x2D   // pattern for digit 4
#define FIVE 0x6E   // pattern for digit 5
#define SIX 0xEE   // pattern for digit 6
#define SEVEN 0x23   // pattern for digit 7
#define EIGHT 0xEF   // pattern for digit 8
#define NINE 0x6F   // pattern for digit 9
#define DOT 0x10   // pattern for dot
#define BLANK 0x00   // blank display

#define M_ONE 0x9D   // pattern for special -1
#define MINUS 0xFD   // pattern for minus sign

void init_ssd_control(void);   // initialize SSD
void display(unsigned char data[]);   // display data on SSD

#endif   // header guard end