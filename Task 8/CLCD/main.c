/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    main.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : App
 *
 *
 */

#include "HAL/CLCD/CLCD_interface.h"

void app(void);

int main(void)
{
	app();
	CLCD_voidSetPosition(CLCD_ROW1, CLCD_COL_3);
	CLCD_voidSendString("Mahmoud Galal");
	CLCD_voidSendExtraChar(CLCD_ROW2, CLCD_COL_5);
	while (1)
	{
	}
	return 0;
}

void app(void)
{
	CLCD_voidInit();
}
