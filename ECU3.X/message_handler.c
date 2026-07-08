#include <xc.h>   // include microcontroller header
#include <string.h>   // include string functions
#include "message_handler.h"   // include message handler
#include "msg_id.h"   // include message id definitions
#include "can.h"   // include CAN functions
#include "clcd.h"   // include LCD functions

int msg_id;   // variable to store message id
char data[6];   // array to store received data
char len;   // variable to store data length
unsigned int count = 0;   // counter for delay
volatile unsigned char led_state = LED_OFF, status = e_ind_off;   // LED and indicator status

void __interrupt() isr()   // interrupt service routine
{
    if(TMR0IF)   // check timer0 interrupt flag
    {
        TMR0 = TMR0 + 8;   // reload timer value

        if(count++ == 20000)   // check count limit
        {
            count = 0;   // reset counter

            if(status == e_ind_left)   // if left indicator
            {
                PORTBbits.RB0 = !PORTBbits.RB0;   // toggle left LED
                PORTBbits.RB1 = !PORTBbits.RB1;   // toggle left LED
            }
            else if(status  == e_ind_right)   // if right indicator
            {
                PORTBbits.RB6 = !PORTBbits.RB6;   // toggle right LED
                PORTBbits.RB7 = !PORTBbits.RB7;   // toggle right LED
            }
            else if(status  == e_ind_off)   // if indicator off
            {
                PORTBbits.RB0 = 0;   // turn off left LED
                PORTBbits.RB1 = 0;   // turn off left LED
                PORTBbits.RB6 = 0;   // turn off right LED
                PORTBbits.RB7 = 0;   // turn off right LED
            }
        }
        TMR0IF = 0;   // clear timer interrupt flag
    }
}

void handle_speed_data(uint8_t *data, uint8_t len)   // function to handle speed
{
    clcd_print("SP",LINE1(0));   // print SP on LCD
    clcd_print(data, LINE2(0));   // print speed value
}

void handle_gear_data(uint8_t *data, uint8_t len)    // function to handle gear
{
    clcd_print("GR",LINE1(4));   // print GR on LCD
    clcd_print(data,LINE2(4));   // print gear value
}

void handle_rpm_data(uint8_t *data, uint8_t len)    // function to handle RPM
{
    clcd_print("RPM",LINE1(8));   // print RPM on LCD
    clcd_print(data,LINE2(8));   // print RPM value
}

/*void handle_engine_temp_data(uint8_t *data, uint8_t len) 
{
    //Implement the temperature function
} */

void handle_indicator_data(uint8_t *data, uint8_t len)    // function to handle indicator
{
    clcd_print("IND",LINE1(12));   // print IND on LCD

    if(data[0] == e_ind_left)   // if left indicator
    {
        status = e_ind_left;   // set status
        clcd_print("<--",LINE2(12));   // show left arrow
    }
    else if(data[0] == e_ind_right)   // if right indicator
    {
        status = e_ind_right;   // set status
        clcd_print("-->",LINE2(12));   // show right arrow
    }
    else if(data[0] == e_ind_off)   // if indicator off
    {
        status = e_ind_off;   // set status
        clcd_print("---",LINE2(12));   // show off
    }
}

void process_canbus_data()    // function to process CAN data
{   
   can_receive(&msg_id,data,&len);   // receive CAN message
   data[len]='\0';   // add string end

   if(msg_id==SPEED_MSG_ID)   // check speed message
   {
      handle_speed_data(data,len);   // call speed function
   }
   else if(msg_id==GEAR_MSG_ID)   // check gear message
   {
     handle_gear_data(data,len);   // call gear function
   }
   else if(msg_id==RPM_MSG_ID)   // check RPM message
   {
       handle_rpm_data(data,len);   // call RPM function
   }
   else if(msg_id==INDICATOR_MSG_ID)   // check indicator message
   {
       handle_indicator_data(data,len);   // call indicator function
   }
}