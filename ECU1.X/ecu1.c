#include "adc.h"   // include ADC functions
#include "can.h"   // include CAN functions
#include "ecu1_sensor.h"   // include sensor functions
#include "msg_id.h"   // include message IDs
#include "uart.h"   // include UART functions
#include "clcd.h"   // include LCD functions

int main()   // main function
{
    init_matrix_keypad();   // initialize keypad
    // init_clcd();   // LCD initialization (not used)
    init_adc();   // initialize ADC
    init_can();   // initialize CAN

    while(1)   // infinite loop
    {
        get_speed();   // read speed value
        get_gear_pos();   // read gear position
    }
}