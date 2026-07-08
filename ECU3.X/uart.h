#ifndef SCI_H   // header guard start
#define SCI_H

#define RX_PIN TRISC7   // define RX pin direction
#define TX_PIN TRISC6   // define TX pin direction

void init_uart(void);   // function to initialize UART
void putch(unsigned char byte);   // function to send one byte
int puts(const char *s);   // function to send string
unsigned char getch(void);   // function to receive one byte
unsigned char getch_with_timeout(unsigned short max_time);   // receive with timeout
unsigned char getche(void);   // receive and echo character

#endif   // header guard end