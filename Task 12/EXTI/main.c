/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    main.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : App
 *
 *
 */

#include "HAL/LED/LED_interface.h"
#include "MCAL/GIE/GIE_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"

void app(void);
void Int0_Isr(void);
void Int1_Isr(void);
void Int2_Isr(void);

LED_type led_0 = {.Port = GPIO_PORTA, .Pin = GPIO_PIN0, .Active_State = ACTIVE_HIGH};
LED_type led_1 = {.Port = GPIO_PORTA, .Pin = GPIO_PIN1, .Active_State = ACTIVE_HIGH};
LED_type led_2 = {.Port = GPIO_PORTA, .Pin = GPIO_PIN2, .Active_State = ACTIVE_HIGH};
LED_type led_3 = {.Port = GPIO_PORTA, .Pin = GPIO_PIN3, .Active_State = ACTIVE_HIGH};

int main(void)
{
	app();
	while (1)
	{
		LED_voidToggle(led_3);
		_delay_ms(5000);
	}
	return 0;
}

void app(void)
{
	GIE_VoidEnable();
	EXTI_voidInit(EXTI_0, EXTI_RISING_EDGE, Int0_Isr);
	EXTI_voidInit(EXTI_1, EXTI_RISING_EDGE, Int1_Isr);
	EXTI_voidInit(EXTI_2, EXTI_RISING_EDGE, Int2_Isr);
	LED_voidInit(led_0);
	LED_voidInit(led_1);
	LED_voidInit(led_2);
	LED_voidInit(led_3);
}

void Int0_Isr(void)
{
	LED_voidToggle(led_0);
}

void Int1_Isr(void)
{
	LED_voidToggle(led_1);
}

void Int2_Isr(void)
{
	LED_voidToggle(led_2);
}