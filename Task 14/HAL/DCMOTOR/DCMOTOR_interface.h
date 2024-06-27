/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DCMOTOR_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : HAL
 *  SWC    : DCMOTOR
 *
 */
#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#define DCMOTOR_CW 0x00
#define DCMOTOR_CCW 0x01
#define DCMOTOR_STOP 0x02

typedef struct
{
    u8 Copy_u8DcMotorPort;
    u8 Copy_u8DcMotorPinA;
    u8 Copy_u8DcMotorPinB;
} DCMOTOR_CONFIG;

void DCMOTOR_voidInit(DCMOTOR_CONFIG *DcMotor);
u8 DCMOTOR_u8Control(DCMOTOR_CONFIG *DcMotor, u8 Copy_u8State);

#endif