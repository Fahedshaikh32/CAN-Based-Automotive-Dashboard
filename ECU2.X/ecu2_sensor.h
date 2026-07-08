/* 
 * File:   ecu1_sensor.h
 * Author: Fahed
 *
 * Created on March 20, 2025, 6:14 PM
 */
#ifndef ECU2_SENSOR_H   // header guard start
#define	ECU2_SENSOR_H

#include <stdint.h>   // include standard integer types
#include "digital_keypad.h"   // include keypad header
#include <xc.h>   // include microcontroller header

#define RPM_ADC_CHANNEL 0x04   // ADC channel for RPM
#define ENG_TEMP_ADC_CHANNEL 0x06   // ADC channel for engine temperature

#define LED_OFF 0   // LED OFF state
#define LED_ON 1   // LED ON state

#define RIGHT_IND_ON() (PORTB = PORTB | 0xC0)   // turn ON right indicator
#define RIGHT_IND_OFF() (PORTB = PORTB & ~0xC0)   // turn OFF right indicator
#define LEFT_IND_ON() (PORTB = PORTB | 0x03)   // turn ON left indicator
#define LEFT_IND_OFF() (PORTB = PORTB & ~0x03)   // turn OFF left indicator

typedef enum {
    e_ind_off,   // indicator OFF
    e_ind_left,   // left indicator
    e_ind_right   // right indicator
} IndicatorStatus;   // enum for indicator status

extern volatile IndicatorStatus prev_ind_status, cur_ind_status;   // previous and current status
extern volatile unsigned char led_state;   // LED state variable

uint16_t get_rpm();   // function to get RPM
uint16_t get_engine_temp();   // function to get engine temperature
IndicatorStatus process_indicator();   // function to process indicator

#endif	/* ECU1_SENSOR_H */   // header guard end