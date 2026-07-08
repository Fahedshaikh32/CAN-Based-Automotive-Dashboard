#include <xc.h>   // include microcontroller header file
#include "timer0.h"   // include timer0 header file

void init_timer0(void) {   // function to initialize timer0
    
    /*
     * Setting instruction cycle clock (Fosc / 4) as the source of
     * timer0
     */

    /*Setting 8 bit timer register*/
    T08BIT = 1;   // set timer0 as 8-bit timer

    /* Selecting internal clock source */
    T0CS = 0;   // select internal clock source (Fosc/4)

    /* Enabling timer0*/
    TMR0ON = 1;   // turn ON timer0

    /* disabling prescaler*/
    PSA = 1;   // disable prescaler for timer0

    TMR0 = 6;   // load initial value to timer0

    /* Clearing timer0 overflow interrupt flag bit */
    TMR0IF = 0;   // clear overflow flag

    /* Enabling timer0 overflow interrupt */
    TMR0IE = 1;   // enable timer0 interrupt
}