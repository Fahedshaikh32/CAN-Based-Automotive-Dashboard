#ifndef CAN_H   // header guard start to avoid multiple include
#define CAN_H

#include <stdint.h>   // include standard integer types

/* Defines ECAN */
#define   F_ECAN_MODE2_FP		CANCON & 0x0F   // get current CAN mode
#define   F_ECANFIFO_0			RXB0CONbits.RXFUL   // check if buffer 0 is full
#define   F_ECANFIFO_1			RXB1CONbits.RXFUL   // check if buffer 1 is full
#define   F_ECANFIFO_2			B0CONbits.RXFUL     // check if buffer 2 is full
#define   F_ECANFIFO_3			B1CONbits.RXFUL     // check if buffer 3 is full
#define   F_ECANFIFO_4			B2CONbits.RXFUL     // check if buffer 4 is full
#define   F_ECANFIFO_5			B3CONbits.RXFUL     // check if buffer 5 is full
#define   F_ECANFIFO_6			B4CONbits.RXFUL     // check if buffer 6 is full
#define   F_ECANFIFO_7			B5CONbits.RXFUL     // check if buffer 7 is full

#define CAN_SET_OPERATION_MODE_NO_WAIT(mode) \
{ \
	CANCON &= 0x1F; \
	CANCON |= mode; \
}

#define EIDH					0   // extended id high byte index
#define EIDL					1   // extended id low byte index
#define SIDH					2   // standard id high byte index
#define SIDL					3   // standard id low byte index
#define DLC						4   // data length code index
#define D0						5   // data byte 0 index
#define D1						6   // data byte 1 index
#define D2						7   // data byte 2 index
#define D3						8   // data byte 3 index
#define D4						9   // data byte 4 index
#define D5						10  // data byte 5 index
#define D6						11  // data byte 6 index
#define D7						12  // data byte 7 index

/* Function Prototypes  */
void init_can(void);   // function to initialize CAN module
void can_transmit(uint16_t msg_id, const uint8_t *data, uint8_t len);   // send CAN message
void can_receive(uint16_t *msg_id, uint8_t *data, uint8_t *len);   // receive CAN message

#endif   // header guard end