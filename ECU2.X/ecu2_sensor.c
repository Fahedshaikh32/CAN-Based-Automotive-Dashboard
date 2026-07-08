#include "ecu2_sensor.h"   // include ECU2 sensor header
#include "adc.h"   // include ADC functions
#include "can.h"   // include CAN functions
#include "msg_id.h"   // include message IDs
#include "uart.h"   // include UART functions
#include "digital_keypad.h"   // include keypad functions

#define _XTAL_FREQ 8000000   // define clock frequency

void display(char data[])   // function to display on SSD
{
    for(int i = 0; i < 4; i++)   // loop for 4 digits
    {
        PORTD = data[i];   // send data to PORTD
        PORTA = (PORTA & 0xf0) | (1 << i);   // enable current digit
        for(int delay = 500; delay--;);   // small delay
    }
}

char ssd[4];   // array for SSD display
char status = 0;   // indicator status variable
int rpm;   // variable to store RPM

char digit[10] = {0xE7,0x21,0xCB,0x6B,0x2D,0x6E,0xEE,0x23,0xEF,0x6F};   // SSD digit patterns

uint16_t get_rpm()   // function to get RPM
{
    rpm = ((unsigned long)read_adc(CHANNEL4) * 6000) / 1023;   // convert ADC to RPM

    ssd[0] = (rpm / 1000) + '0';   // thousand digit
    ssd[1] = ((rpm / 100) % 10) + '0';   // hundred digit
    ssd[2] = ((rpm / 10) % 10) + '0';   // tens digit
    ssd[3] = (rpm % 10) + '0';   // units digit

    can_transmit(RPM_MSG_ID, ssd, 4);   // send RPM via CAN

    __delay_ms(80);   // small delay

    return rpm;   // return RPM value
}

uint16_t get_engine_temp()   // function to get engine temperature
{
    //Implement the engine temperature function
}

IndicatorStatus process_indicator()   // function to process indicator
{
    unsigned key = read_digital_keypad(STATE_CHANGE);   // read keypad input

    if(key == 0x0e)   // left indicator key
    {
        status = 1;   // set left status
    }
    else if(key == 0x0b)   // right indicator key
    {
        status = 2;   // set right status
    }
    else if(key == 0x0d)   // off key
    {
        status = 0;   // set off status
    }

    can_transmit(INDICATOR_MSG_ID, &status, 1);   // send indicator status

    __delay_ms(80);   // small delay
}