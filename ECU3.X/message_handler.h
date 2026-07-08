 /* 
 * File:   message_handler.h
 * Author: Fahed
 *
 * Created on 21 March, 2025, 12:36 PM
 */

#ifndef MESSAGE_HANDLER_H   // header guard start
#define	MESSAGE_HANDLER_H

#include <stdint.h>   // include standard integer types

#define LED_OFF 0   // LED OFF state
#define LED_ON 1   // LED ON state

#define RIGHT_IND_ON() (PORTB = PORTB | 0xC0)   // turn ON right indicator LEDs
#define RIGHT_IND_OFF() (PORTB = PORTB & ~0xC0)   // turn OFF right indicator LEDs
#define LEFT_IND_ON() (PORTB = PORTB | 0x03)   // turn ON left indicator LEDs
#define LEFT_IND_OFF() (PORTB = PORTB & ~0x03)   // turn OFF left indicator LEDs

extern volatile unsigned char led_state, status;   // external variables for LED and status

typedef enum {
    e_ind_off,   // indicator OFF
    e_ind_left,   // left indicator ON
    e_ind_right   // right indicator ON
} IndicatorStatus;   // enum for indicator status

void process_canbus_data();   // function to process CAN data
void handle_speed_data(uint8_t *data, uint8_t len);   // handle speed message
void handle_gear_data(uint8_t *data, uint8_t len);   // handle gear message
void handle_rpm_data(uint8_t *data, uint8_t len);   // handle RPM message
void handle_engine_temp_data(uint8_t *data, uint8_t len);   // handle engine temperature
void handle_indicator_data(uint8_t *data, uint8_t len);   // handle indicator message

#endif	/* MESSAGE_HANDLER_H */   // header guard end