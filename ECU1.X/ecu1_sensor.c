#include "ecu1_sensor.h"   // include sensor header
#include "adc.h"   // include ADC functions
#include "can.h"   // include CAN functions
#include "msg_id.h"   // include message IDs
#include "digital_keypad.h"   // include keypad functions
#include "uart.h"   // include UART functions
#include "clcd.h"   // include LCD functions

char gear[9][3] = {"ON","GN","G1","G2","G3","G4","G5","Rr","Cl"};   // gear names
int ind = 0;   // index for gear

#define _XTAL_FREQ 8000000   // define clock frequency

uint16_t get_speed()   // function to get speed
{
    char str[3];   // array to store speed as string

    unsigned short speed = read_adc(CHANNEL4) / 10.33;   // read ADC and convert to speed

    str[0] = (speed / 10) + 48;   // convert tens digit to char
    str[1] = (speed % 10) + 48;   // convert units digit to char
    str[2] = '\0';   // end of string

    can_transmit(SPEED_MSG_ID, str, 2);   // send speed via CAN

    __delay_ms(80);   // small delay

    return speed;   // return speed value
}

unsigned char get_gear_pos()   // function to get gear position
{
    int key = read_switches(STATE_CHANGE);   // read keypad input

    if(key == 1)   // gear up
    {
        if(ind < 7)   // check max limit
        {
            ind++;   // increase gear
        }
    }
    else if(key == 2)   // gear down
    {
        if(ind > 0)   // check min limit
        {
            ind--;   // decrease gear
        }
    }
    else if(key == 3)   // collision case
    {
        ind = 8;   // set to collision state
    }

    can_transmit(GEAR_MSG_ID, gear[ind], 2);   // send gear via CAN

    __delay_ms(80);   // small delay
}