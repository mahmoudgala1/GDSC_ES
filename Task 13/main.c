/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    main.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : App
 *
 *
 */

#include "HAL/LED/LED_interface.h"
#include "HAL/CLCD/CLCD_interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include "HAL/LM35/LM35_interface.h"

void app(void);

LM35_CONFIG LM35 = {ADC0, 5, ADC_RESOLUTION_10_BIT};
LED_type Green_Led = {.Port = GPIO_PORTA, .Pin = GPIO_PIN1, .Active_State = ACTIVE_HIGH};
LED_type Red_Led = {.Port = GPIO_PORTA, .Pin = GPIO_PIN2, .Active_State = ACTIVE_HIGH};
u8 TempValue = 0;

int main(void)
{
	app();
	while (1)
	{
		LM35_u8GetTemp(&LM35, &TempValue);
		CLCD_voidSetPosition(CLCD_ROW1, CLCD_COL_1);
		CLCD_voidSendString("TempValue= ");
		CLCD_voidSendNumber(TempValue);
		CLCD_voidSendString("C ");
		if (TempValue >= 50)
		{
			LED_voidOn(Red_Led);
			LED_voidOff(Green_Led);
		}
		else
		{
			LED_voidOn(Green_Led);
			LED_voidOff(Red_Led);
		}
	}
	return 0;
}

void app(void)
{
	ADC_voidInit();
	CLCD_voidInit();
	LED_voidInit(Green_Led);
	LED_voidInit(Red_Led);
}
