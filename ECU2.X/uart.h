#ifndef SCI_H   // header guard start
#define SCI_H

#define RX_PIN TRISC7   // RX pin direction
#define TX_PIN TRISC6   // TX pin direction

void init_uart(void);   // initialize UART
void putch(unsigned char byte);   // send one byte
int puts(const char *s);   // send string
unsigned char getch(void);   // receive one byte
unsigned char getch_with_timeout(unsigned short max_time);   // receive with timeout
unsigned char getche(void);   // receive and echo

#endif   // header guard end