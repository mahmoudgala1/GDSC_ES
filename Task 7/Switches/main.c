/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    main.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : App
 *
 *
 */

#include <util/delay.h>
#include "HAL/SSD/SSD_interface.h"
#include "HAL/SW/Sw_interface.h"

#define F_CPU 8000000UL

void app(void);
void Increment_Number(SW_Type SW, u8 *Number);
void Decrement_Number(SW_Type SW, u8 *Number);
void ShowResult(void);
void Reset(void);

SW_Type SW_count1_INC = {GPIO_PORTC, GPIO_PIN0, SW_PULL_DOWN};
SW_Type SW_count1_DEC = {GPIO_PORTC, GPIO_PIN1, SW_PULL_DOWN};
SW_Type SW_count2_INC = {GPIO_PORTC, GPIO_PIN2, SW_PULL_DOWN};
SW_Type SW_count2_DEC = {GPIO_PORTC, GPIO_PIN3, SW_PULL_DOWN};
SW_Type SW_Show_Result = {GPIO_PORTC, GPIO_PIN4, SW_PULL_DOWN};
SW_Type SW_Reset = {GPIO_PORTC, GPIO_PIN5, SW_PULL_DOWN};

u8 Count1 = 0;
u8 Count2 = 0;
u8 Result = 0;

int main(void)
{
	app();
	while (1)
	{
		Increment_Number(SW_count1_INC, &Count1);
		Decrement_Number(SW_count1_DEC, &Count1);
		Increment_Number(SW_count2_INC, &Count2);
		Decrement_Number(SW_count2_DEC, &Count2);
		ShowResult();
		Reset();
		SSD_voidWithDecoder(GPIO_PORTA, Count1, LOW_NIBBLES);
		SSD_voidWithDecoder(GPIO_PORTA, Count2, HIGH_NIBBLES);
		SSD_voidWithDecoder(GPIO_PORTB, Result / 10, LOW_NIBBLES);
		SSD_voidWithDecoder(GPIO_PORTB, Result % 10, HIGH_NIBBLES);
	}
	return 0;
}

void app(void)
{
	SW_voidInit(SW_count1_INC);
	SW_voidInit(SW_count1_DEC);
	SW_voidInit(SW_count2_INC);
	SW_voidInit(SW_count2_DEC);
	SW_voidInit(SW_Show_Result);
	SW_voidInit(SW_Reset);
}

void Increment_Number(SW_Type SW, u8 *Number)
{
	if (SW_u8GetPressed(SW))
	{
		while (SW_u8GetPressed(SW))
			;
		(*Number)++;
		if ((*Number) == 10)
		{
			(*Number) = 9;
		}
	}
}

void Decrement_Number(SW_Type SW, u8 *Number)
{
	if (SW_u8GetPressed(SW))
	{
		while (SW_u8GetPressed(SW))
			;
		if ((*Number) == 0)
		{
			(*Number) = 0;
		}
		else
		{
			(*Number)--;
		}
	}
}

void ShowResult(void)
{
	if (SW_u8GetPressed(SW_Show_Result))
	{
		while (SW_u8GetPressed(SW_Show_Result))
			;
		Result = Count1 + Count2;
	}
}

void Reset(void)
{
	if (SW_u8GetPressed(SW_Reset))
	{
		while (SW_u8GetPressed(SW_Reset))
			;
		Count1 = 0;
		Count2 = 0;
		Result = 0;
	}
}