#ifndef CAN_H   // header guard start
#define CAN_H

#include <stdint.h>   // include standard integer types

#define F_ECAN_MODE2_FP (CANCON & 0x0F)   // get current CAN mode
#define F_ECANFIFO_0 RXB0CONbits.RXFUL   // check buffer 0 full
#define F_ECANFIFO_1 RXB1CONbits.RXFUL   // check buffer 1 full
#define F_ECANFIFO_2 B0CONbits.RXFUL   // check buffer 2 full
#define F_ECANFIFO_3 B1CONbits.RXFUL   // check buffer 3 full
#define F_ECANFIFO_4 B2CONbits.RXFUL   // check buffer 4 full
#define F_ECANFIFO_5 B3CONbits.RXFUL   // check buffer 5 full
#define F_ECANFIFO_6 B4CONbits.RXFUL   // check buffer 6 full
#define F_ECANFIFO_7 B5CONbits.RXFUL   // check buffer 7 full

#define CAN_SET_OPERATION_MODE_NO_WAIT(mode) \
{ \
    CANCON &= 0x1F; \
    CANCON |= mode; \
}

#define EIDH 0   // extended id high index
#define EIDL 1   // extended id low index
#define SIDH 2   // standard id high index
#define SIDL 3   // standard id low index
#define DLC 4   // data length index
#define D0 5   // data byte 0
#define D1 6   // data byte 1
#define D2 7   // data byte 2
#define D3 8   // data byte 3
#define D4 9   // data byte 4
#define D5 10   // data byte 5
#define D6 11   // data byte 6
#define D7 12   // data byte 7

void init_can(void);   // initialize CAN
void can_transmit(uint16_t msg_id, const uint8_t *data, uint8_t len);   // send data
void can_receive(uint16_t *msg_id, uint8_t *data, uint8_t *len);   // receive data

#endif   // header guard end