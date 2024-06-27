/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DCMOTOR_programe.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : HAL
 *  SWC    : DCMOTOR
 *
 */

#include "DCMOTOR_INTERFACE.h"

void DCMOTOR_voidInit(DCMOTOR_CONFIG *DcMotor)
{
    GPIO_enumSetPinDirection(DcMotor->Copy_u8DcMotorPort, DcMotor->Copy_u8DcMotorPinA, GPIO_PIN_OUTPUT);
    GPIO_enumSetPinDirection(DcMotor->Copy_u8DcMotorPort, DcMotor->Copy_u8DcMotorPinB, GPIO_PIN_OUTPUT);
}

u8 DCMOTOR_u8Control(DCMOTOR_CONFIG *DcMotor, u8 Copy_u8State)
{
    u8 Local_u8ErrorState = OK;

    switch (Copy_u8State)
    {
    case DCMOTOR_CW:
        GPIO_enumSetPinValue(DcMotor->Copy_u8DcMotorPort, DcMotor->Copy_u8DcMotorPinA, GPIO_PIN_LOW);
        GPIO_enumSetPinValue(DcMotor->Copy_u8DcMotorPort, DcMotor->Copy_u8DcMotorPinB, GPIO_PIN_HIGH);
        break;
    case DCMOTOR_CCW:
        GPIO_enumSetPinValue(DcMotor->Copy_u8DcMotorPort, DcMotor->Copy_u8DcMotorPinB, GPIO_PIN_LOW);
        GPIO_enumSetPinValue(DcMotor->Copy_u8DcMotorPort, DcMotor->Copy_u8DcMotorPinA, GPIO_PIN_HIGH);
        break;
    case DCMOTOR_STOP:
        GPIO_enumSetPinValue(DcMotor->Copy_u8DcMotorPort, DcMotor->Copy_u8DcMotorPinA, GPIO_PIN_LOW);
        GPIO_enumSetPinValue(DcMotor->Copy_u8DcMotorPort, DcMotor->Copy_u8DcMotorPinB, GPIO_PIN_LOW);
        break;
    default:
        Local_u8ErrorState = NOK;
    }

    return Local_u8ErrorState;
}