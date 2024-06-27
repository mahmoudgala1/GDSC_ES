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

void app(void);
value = NOTPRESSED;
count = 0;
int main(void)
{
	app();
	while (1)
	{
		value = KPD_u8GetPressed();
		if (value != NOTPRESSED)
		{
			if (value == '#')
			{
				CLCD_voidClearScreen();
				count = 0;
			}
			else
			{
				count++;
				if (count == 17)
				{
					CLCD_voidSetPosition(CLCD_ROW2, CLCD_COL_1);
				}
				else if (count == 33)
				{
					count = 0;
					CLCD_voidClearScreen();
					CLCD_voidSetPosition(CLCD_ROW1, CLCD_COL_1);
				}
				CLCD_voidSendData(value);
			}
		}
	}
	return 0;
}

void app(void)
{
	CLCD_voidInit();
	KPD_Init();
}
