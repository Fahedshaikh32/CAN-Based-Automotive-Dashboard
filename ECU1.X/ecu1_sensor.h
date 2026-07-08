/* 
 * File:   ecu1_sensor.h
 * Author: Fahed
 *
 * Created on March 20, 2025, 6:14 PM
 */
#ifndef ECU1_SENSOR_H   // header guard start
#define	ECU1_SENSOR_H

#include <stdint.h>   // include standard integer types
#include "digital_keypad.h"   // include keypad header
#include <xc.h>   // include microcontroller header

#define MAX_GEAR 6   // maximum gear value
#define SPEED_ADC_CHANNEL 0x04   // ADC channel for speed
#define GEAR_UP SWITCH1   // gear up switch
#define GEAR_DOWN SWITCH2   // gear down switch
#define COLLISION SWITCH3   // collision switch

uint16_t get_speed();   // function to get speed value
unsigned char get_gear_pos();   // function to get gear position

#endif	/* ECU1_SENSOR_H */   // header guard end