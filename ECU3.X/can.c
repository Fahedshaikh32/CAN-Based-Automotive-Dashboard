/*File for CAN configuration , setting message id's, Data Transmission, */
#include <xc.h>   // include microcontroller header
#include "can.h"   // include CAN header
#include "clcd.h"   // include LCD header

typedef enum _CanOpMode {
    e_can_op_mode_normal = 0x00,   // normal mode
    e_can_op_mode_loop = 0x40,   // loopback mode
    e_can_op_mode_config = 0x80   // configuration mode
} CanOpMode;

void init_can(void)   // function to initialize CAN
{
    TRISB2 = 0;   // set CAN TX pin as output
    TRISB3 = 1;   // set CAN RX pin as input

    CAN_SET_OPERATION_MODE_NO_WAIT(e_can_op_mode_config);   // set config mode

    while (CANSTAT != 0x80);   // wait until config mode set

    ECANCON = 0x00;   // set mode 0

    BRGCON1 = 0xE1;   // set timing register 1
    BRGCON2 = 0x1B;   // set timing register 2
    BRGCON3 = 0x03;   // set timing register 3

    RXFCON0 = 0x00;   // disable filters

    CAN_SET_OPERATION_MODE_NO_WAIT(e_can_op_mode_normal);   // set normal mode

    RXB0CON = 0x00;   // set receive buffer mode
    RXB0CONbits.RXM0 = 1;   // enable receive all
    RXB0CONbits.RXM1 = 1;   // enable receive all
}

static uint16_t get_msg_id_std(void)   // function to get message id
{
    uint16_t id = 0;   // variable to store id
    id = ((RXB0SIDL >> 5) & 0x7) | (RXB0SIDH << 3);   // extract id bits
    return id;   // return id
}

static void set_msg_id_std(unsigned int id)   // function to set message id
{
    TXB0SIDL = (id & 0x7) << 5;   // set lower bits
    TXB0SIDH = (id >> 3);   // set higher bits
}

void can_transmit(uint16_t msg_id, const uint8_t *data, uint8_t len)   // function to send CAN data
{
    uint8_t *ptr;   // pointer for data

    TXB0EIDH = 0x00;   // clear extended id high
    TXB0EIDL = 0x00;   // clear extended id low

    set_msg_id_std(msg_id);   // set message id

    TXB0DLC = len;   // set data length

    ptr = (uint8_t *) & TXB0D0;   // point to data register

    for (int i = 0; i < len; i++)   // loop through data
    {
        ptr[i] = data[i];   // copy data to buffer
    }

    TXB0REQ = 1;   // request transmission
}

void can_receive(uint16_t *msg_id, uint8_t *data, uint8_t *len)   // function to receive CAN data
{
    uint8_t *ptr;   // pointer for data

    if (RXB0FUL)   // check if data received
    {
        *msg_id = get_msg_id_std();   // get message id

        *len = RXB0DLC;   // get data length

        ptr = (uint8_t *) & RXB0D0;   // point to received data

        for (int i = 0; i < *len; i++)   // loop through data
        {
            data[i] = ptr[i];   // copy data
        }

        RXB0FUL = 0;   // clear buffer flag
        RXB0IF = 0;   // clear interrupt flag
    }

    // no data case handled by caller
}