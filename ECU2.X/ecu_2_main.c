#include "ecu2_sensor.h"   // include ECU2 sensor functions
#include "adc.h"   // include ADC functions
#include "can.h"   // include CAN functions
#include "msg_id.h"   // include message IDs
#include "uart.h"   // include UART functions
#include "digital_keypad.h"   // include keypad functions
#include <xc.h>   // include microcontroller header

void init_config(void)   // function to initialize modules
{
    init_adc();   // initialize ADC
    init_digital_keypad();   // initialize keypad
    init_can();   // initialize CAN
}

int main(void)   // main function
{
    init_config();   // call initialization

    while(1)   // infinite loop
    {
        get_rpm();   // read RPM value
        process_indicator();   // handle indicator logic
    }
}