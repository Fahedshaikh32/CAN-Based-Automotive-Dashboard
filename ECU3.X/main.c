#include <xc.h>   // include microcontroller header
#include <stdint.h>   // include standard integer types
#include "can.h"   // include CAN functions
#include "clcd.h"   // include LCD functions
#include "msg_id.h"   // include message id definitions
#include "message_handler.h"   // include message handler
//#include "isr.h"   // ISR header (not used)
#include "timer0.h"   // include timer0 functions

static void init_leds() {   // function to initialize LEDs
    TRISB = 0x08;   // set RB3 as input and others as output
    PORTB = 0x00;   // clear all PORTB pins
}

static void init_config(void) {   // function to initialize all modules
    init_clcd();   // initialize LCD
    init_can();   // initialize CAN
    init_leds();   // initialize LEDs

    PEIE = 1;   // enable peripheral interrupts
    GIE = 1;   // enable global interrupts

    init_timer0();   // initialize timer0
}

void main(void) {   // main function
    init_config();   // call initialization

    while (1) {   // infinite loop
        process_canbus_data();   // read and handle CAN data
    }

    return;   // end of program
}