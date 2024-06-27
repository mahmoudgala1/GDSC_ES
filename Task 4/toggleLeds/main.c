/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    main.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : App
 *
 *
 */

#include <util/delay.h>
#include "HAL/LED/LED_interface.h"

#define F_CPU 8000000UL

void app(void);
LED_type leds[32] = {
	{GPIO_PORTA, GPIO_PIN0, ACTIVE_HIGH},
	{GPIO_PORTA, GPIO_PIN1, ACTIVE_HIGH},
	{GPIO_PORTA, GPIO_PIN2, ACTIVE_HIGH},
	{GPIO_PORTA, GPIO_PIN3, ACTIVE_HIGH},
	{GPIO_PORTA, GPIO_PIN4, ACTIVE_HIGH},
	{GPIO_PORTA, GPIO_PIN5, ACTIVE_HIGH},
	{GPIO_PORTA, GPIO_PIN6, ACTIVE_HIGH},
	{GPIO_PORTA, GPIO_PIN7, ACTIVE_HIGH},
	{GPIO_PORTB, GPIO_PIN0, ACTIVE_HIGH},
	{GPIO_PORTB, GPIO_PIN1, ACTIVE_HIGH},
	{GPIO_PORTB, GPIO_PIN2, ACTIVE_HIGH},
	{GPIO_PORTB, GPIO_PIN3, ACTIVE_HIGH},
	{GPIO_PORTB, GPIO_PIN4, ACTIVE_HIGH},
	{GPIO_PORTB, GPIO_PIN5, ACTIVE_HIGH},
	{GPIO_PORTB, GPIO_PIN6, ACTIVE_HIGH},
	{GPIO_PORTB, GPIO_PIN7, ACTIVE_HIGH},
	{GPIO_PORTC, GPIO_PIN0, ACTIVE_lOW},
	{GPIO_PORTC, GPIO_PIN1, ACTIVE_lOW},
	{GPIO_PORTC, GPIO_PIN2, ACTIVE_lOW},
	{GPIO_PORTC, GPIO_PIN3, ACTIVE_lOW},
	{GPIO_PORTC, GPIO_PIN4, ACTIVE_lOW},
	{GPIO_PORTC, GPIO_PIN5, ACTIVE_lOW},
	{GPIO_PORTC, GPIO_PIN6, ACTIVE_lOW},
	{GPIO_PORTC, GPIO_PIN7, ACTIVE_lOW},
	{GPIO_PORTD, GPIO_PIN0, ACTIVE_lOW},
	{GPIO_PORTD, GPIO_PIN1, ACTIVE_lOW},
	{GPIO_PORTD, GPIO_PIN2, ACTIVE_lOW},
	{GPIO_PORTD, GPIO_PIN3, ACTIVE_lOW},
	{GPIO_PORTD, GPIO_PIN4, ACTIVE_lOW},
	{GPIO_PORTD, GPIO_PIN5, ACTIVE_lOW},
	{GPIO_PORTD, GPIO_PIN6, ACTIVE_lOW},
	{GPIO_PORTD, GPIO_PIN7, ACTIVE_lOW}};
int main(void)
{
	app();
	while (1)
	{
		_delay_ms(500);
		for (u8 i = 0; i < 32; i++)
		{
			LED_voidToggle(leds[i]);
		}
	}
	return 0;
}
void app(void)
{
	for (u8 i = 0; i < 32; i++)
	{
		LED_voidInit(leds[i]);
		if (i % 2 == 0)
		{
			LED_voidOn(leds[i]);
		}
		else
		{
			LED_voidOff(leds[i]);
		}
	}
}
