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

#define F_CPU 8000000UL

void app(void);

SSD_Type S1 = {COMMON_CATHOD, GPIO_PORTA, GPIO_PORTA, GPIO_PIN7};

int main(void)
{
	app();
	while (1)
	{
		for (u8 counter = 0; counter < 10; counter++)
		{
			SSD_voidSendNumber(S1, counter);
			_delay_ms(500);
		}
	}
	return 0;
}
void app(void)
{
	SSD_voidInitDataPort(S1);
	SSD_voidEnable(S1);
}
