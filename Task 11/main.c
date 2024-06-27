/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    main.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : App
 *
 *
 */

#include "HAL/DCMOTOR/DCMOTOR_interface.h"
#include "HAL/CLCD/CLCD_interface.h"
#include "HAL/KPD/KPD_interface.h"

DCMOTOR_CONFIG motor_1 = {.Copy_u8DcMotorPort = GPIO_PORTA, .Copy_u8DcMotorPinA = GPIO_PIN0, .Copy_u8DcMotorPinB = GPIO_PIN1};
DCMOTOR_CONFIG motor_2 = {.Copy_u8DcMotorPort = GPIO_PORTA, .Copy_u8DcMotorPinA = GPIO_PIN2, .Copy_u8DcMotorPinB = GPIO_PIN3};
DCMOTOR_CONFIG motor_3 = {.Copy_u8DcMotorPort = GPIO_PORTA, .Copy_u8DcMotorPinA = GPIO_PIN4, .Copy_u8DcMotorPinB = GPIO_PIN5};

u8 KPD_value = 0;
u8 motor_1_value = '0';
u8 motor_2_value = '0';
u8 motor_3_value = '0';

void app(void);

int main(void)
{
	app();
	CLCD_voidSendString("M1:");
	CLCD_voidSetPosition(CLCD_ROW1, CLCD_COL_10);
	CLCD_voidSendString("M2:");
	CLCD_voidSetPosition(CLCD_ROW2, CLCD_COL_5);
	CLCD_voidSendString("M3:");
	while (1)
	{
		KPD_value = KPD_u8GetPressed();

		if (KPD_value >= '1' && KPD_value <= '3')
		{
			motor_1_value = KPD_value;
		}
		else if (KPD_value >= '4' && KPD_value <= '6')
		{
			motor_2_value = KPD_value;
		}
		else if (KPD_value >= '7' && KPD_value <= '9')
		{
			motor_3_value = KPD_value;
		}

		if (motor_1_value == '1')
		{
			DCMOTOR_u8Control(&motor_1, DCMOTOR_CW);
			CLCD_voidSetPosition(CLCD_ROW1, CLCD_COL_4);
			CLCD_voidSendString("CW  ");
		}
		else if (motor_1_value == '2')
		{
			DCMOTOR_u8Control(&motor_1, DCMOTOR_CCW);
			CLCD_voidSetPosition(CLCD_ROW1, CLCD_COL_4);
			CLCD_voidSendString("CCW ");
		}
		else if (motor_1_value == '3' || motor_1_value == '0')
		{
			DCMOTOR_u8Control(&motor_1, DCMOTOR_STOP);
			CLCD_voidSetPosition(CLCD_ROW1, CLCD_COL_4);
			CLCD_voidSendString("STOP");
		}

		if (motor_2_value == '4')
		{
			DCMOTOR_u8Control(&motor_2, DCMOTOR_CW);
			CLCD_voidSetPosition(CLCD_ROW1, CLCD_COL_13);
			CLCD_voidSendString("CW  ");
		}
		else if (motor_2_value == '5')
		{
			DCMOTOR_u8Control(&motor_2, DCMOTOR_CCW);
			CLCD_voidSetPosition(CLCD_ROW1, CLCD_COL_13);
			CLCD_voidSendString("CCW ");
		}
		else if (motor_2_value == '6' || motor_2_value == '0')
		{
			DCMOTOR_u8Control(&motor_2, DCMOTOR_STOP);
			CLCD_voidSetPosition(CLCD_ROW1, CLCD_COL_13);
			CLCD_voidSendString("STOP");
		}

		if (motor_3_value == '7')
		{
			DCMOTOR_u8Control(&motor_3, DCMOTOR_CW);
			CLCD_voidSetPosition(CLCD_ROW2, CLCD_COL_8);
			CLCD_voidSendString("CW  ");
		}
		else if (motor_3_value == '8')
		{
			DCMOTOR_u8Control(&motor_3, DCMOTOR_CCW);
			CLCD_voidSetPosition(CLCD_ROW2, CLCD_COL_8);
			CLCD_voidSendString("CCW ");
		}
		else if (motor_3_value == '9' || motor_3_value == '0')
		{
			DCMOTOR_u8Control(&motor_3, DCMOTOR_STOP);
			CLCD_voidSetPosition(CLCD_ROW2, CLCD_COL_8);
			CLCD_voidSendString("STOP");
		}
	}
	return 0;
}

void app(void)
{
	DCMOTOR_voidInit(&motor_1);
	DCMOTOR_voidInit(&motor_2);
	DCMOTOR_voidInit(&motor_3);
	KPD_Init();
	CLCD_voidInit();
}
