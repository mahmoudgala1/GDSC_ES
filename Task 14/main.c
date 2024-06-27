/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    main.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : App
 *
 *
 */

#include "HAL/CLCD/CLCD_interface.h"
#include "HAL/KPD/KPD_interface.h"
#include "HAL/DCMOTOR/DCMOTOR_interface.h"

#define RIGHT DCMOTOR_CW
#define LEFT DCMOTOR_CCW
#define STOP DCMOTOR_STOP

void app(void);
void Motor1(void);
void Motor2(void);
void Print_Motor_Direction(u8 motor);
void Select_Motor_Direction(u8 motor);
void Select_Motor_Speed(u8 motor);

u8 value = 0;
u8 Clear_Flag = 0;
u8 Motor_1_Direction = RIGHT;
u8 Motor_2_Direction = LEFT;
DCMOTOR_CONFIG Motor_1 = {.Copy_u8DcMotorPort = GPIO_PORTA, .Copy_u8DcMotorPinA = GPIO_PIN0, .Copy_u8DcMotorPinB = GPIO_PIN1};
DCMOTOR_CONFIG Motor_2 = {.Copy_u8DcMotorPort = GPIO_PORTA, .Copy_u8DcMotorPinA = GPIO_PIN2, .Copy_u8DcMotorPinB = GPIO_PIN3};

int main(void)
{
	app();
	while (1)
	{
		value = KPD_u8GetPressed();
		if (value != NOTPRESSED)
		{
			if ('#' == value)
			{
				Display_Menu();
			}
		}

		if (1 == Clear_Flag)
		{
			Clear_Flag = 0;
			CLCD_voidClearScreen();
		}
		CLCD_voidSetPosition(CLCD_ROW1, CLCD_COL_1);
		CLCD_voidSendString("  <- DASH BOARD ->  ");
		CLCD_voidSetPosition(CLCD_ROW2, CLCD_COL_1);
		CLCD_voidSendString("Motor 1      Motor 2");
		CLCD_voidSetPosition(CLCD_ROW3, CLCD_COL_1);
		Print_Motor_Direction(1);
		CLCD_voidSendString("        ");
		Print_Motor_Direction(2);
		CLCD_voidSetPosition(CLCD_ROW4, CLCD_COL_1);
		CLCD_voidSendString("100%         100%");
	}
	return 0;
}

void app(void)
{
	CLCD_voidInit();
	KPD_Init();
	DCMOTOR_voidInit(&Motor_1);
	DCMOTOR_voidInit(&Motor_2);
	DCMOTOR_u8Control(&Motor_1, Motor_1_Direction);
	DCMOTOR_u8Control(&Motor_2, Motor_2_Direction);
}

void Display_Menu(void)
{
	Clear_Flag = 1;
	CLCD_voidClearScreen();
	CLCD_voidSendString("     <- MENU ->     ");
	CLCD_voidSetPosition(CLCD_ROW2, CLCD_COL_1);
	CLCD_voidSendString("1)Motor One");
	CLCD_voidSetPosition(CLCD_ROW3, CLCD_COL_1);
	CLCD_voidSendString("2)Motor Two");
	while (1)
	{
		value = KPD_u8GetPressed();
		if ('1' == value)
		{
			Motor1();
		}
		else if ('2' == value)
		{
			Motor2();
		}
		else if ('0' == value || '=' == value)
		{
			value = NOTPRESSED;
			main();
		}
	}
}

void Motor1(void)
{
	CLCD_voidClearScreen();
	CLCD_voidSendString("   <- MOTOR ONE ->  ");
	CLCD_voidSetPosition(CLCD_ROW2, CLCD_COL_1);
	CLCD_voidSendString("1)Dierction -> ");
	Print_Motor_Direction(1);
	CLCD_voidSetPosition(CLCD_ROW3, CLCD_COL_1);
	CLCD_voidSendString("2)Speed -> 100%");
	while (1)
	{
		value = KPD_u8GetPressed();
		if ('1' == value)
		{
			Select_Motor_Direction(1);
		}
		else if ('2' == value)
		{
			Select_Motor_Speed(2);
		}
		else if ('0' == value)
		{
			value = NOTPRESSED;
			Display_Menu();
		}
		else if ('=' == value)
		{
			value = NOTPRESSED;
			main();
		}
	}
}

void Motor2(void)
{
	CLCD_voidClearScreen();
	CLCD_voidSendString("   <- MOTOR TWO ->  ");
	CLCD_voidSetPosition(CLCD_ROW2, CLCD_COL_1);
	CLCD_voidSendString("1)Dierction -> ");
	Print_Motor_Direction(2);
	CLCD_voidSetPosition(CLCD_ROW3, CLCD_COL_1);
	CLCD_voidSendString("2)Speed -> 100%");
	while (1)
	{
		value = KPD_u8GetPressed();
		if ('1' == value)
		{
			Select_Motor_Direction(2);
		}
		else if ('2' == value)
		{
			Select_Motor_Speed(2);
		}
		else if ('0' == value)
		{
			value = NOTPRESSED;
			Display_Menu();
		}
		else if ('=' == value)
		{
			value = NOTPRESSED;
			main();
		}
	}
}

void Print_Motor_Direction(u8 motor)
{
	if (1 == motor)
	{
		if (RIGHT == Motor_1_Direction)
		{
			CLCD_voidSendString("RIGHT");
		}
		else if (LEFT == Motor_1_Direction)
		{
			CLCD_voidSendString("LEFT ");
		}
		else
		{
			CLCD_voidSendString("STOP ");
		}
	}
	else if (2 == motor)
	{
		if (RIGHT == Motor_2_Direction)
		{
			CLCD_voidSendString("RIGHT");
		}
		else if (LEFT == Motor_2_Direction)
		{
			CLCD_voidSendString("LEFT");
		}
		else
		{
			CLCD_voidSendString("STOP");
		}
	}
}

void Select_Motor_Direction(u8 motor)
{
	CLCD_voidClearScreen();
	CLCD_voidSendString("   <- DIRECTION ->  ");
	CLCD_voidSetPosition(CLCD_ROW2, CLCD_COL_1);
	CLCD_voidSendString("1) Right");
	CLCD_voidSetPosition(CLCD_ROW3, CLCD_COL_1);
	CLCD_voidSendString("2) Left");
	CLCD_voidSetPosition(CLCD_ROW4, CLCD_COL_1);
	CLCD_voidSendString("3) Stop");
	while (1)
	{
		value = KPD_u8GetPressed();
		if ('1' == value)
		{
			if (1 == motor)
			{
				Motor_1_Direction = RIGHT;
			}
			else if (2 == motor)
			{
				Motor_2_Direction = RIGHT;
			}
			DCMOTOR_u8Control(&Motor_1, Motor_1_Direction);
			DCMOTOR_u8Control(&Motor_2, Motor_2_Direction);
		}
		else if ('2' == value)
		{
			if (1 == motor)
			{
				Motor_1_Direction = LEFT;
			}
			else if (2 == motor)
			{
				Motor_2_Direction = LEFT;
			}
			DCMOTOR_u8Control(&Motor_1, Motor_1_Direction);
			DCMOTOR_u8Control(&Motor_2, Motor_2_Direction);
		}
		else if ('3' == value)
		{
			if (1 == motor)
			{
				Motor_1_Direction = STOP;
			}
			else if (2 == motor)
			{
				Motor_2_Direction = STOP;
			}
			DCMOTOR_u8Control(&Motor_1, Motor_1_Direction);
			DCMOTOR_u8Control(&Motor_2, Motor_2_Direction);
		}
		else if ('0' == value)
		{
			value = NOTPRESSED;
			if (1 == motor)
			{
				Motor1();
			}
			else if (2 == motor)
			{
				Motor2();
			}
		}
		else if ('=' == value)
		{
			value = NOTPRESSED;
			main();
		}
	}
}

void Select_Motor_Speed(u8 motor)
{
	CLCD_voidClearScreen();
	CLCD_voidSendString("     <- SPEED ->    ");
	CLCD_voidSetPosition(CLCD_ROW3, CLCD_COL_1);
	CLCD_voidSendString("    Comming Soon    ");
	while (1)
	{
		value = KPD_u8GetPressed();
		if ('0' == value)
		{
			value = NOTPRESSED;
			if (1 == motor)
			{
				Motor1();
			}
			else if (2 == motor)
			{
				Motor2();
			}
		}
		else if ('=' == value)
		{
			value = NOTPRESSED;
			main();
		}
	}
}