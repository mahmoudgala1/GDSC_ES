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
#include "HAL/LED/LED_interface.h"

#define F_CPU 8000000UL

void app(void);

void TrafficLight(LED_type led, u8 duration);
void LedOff(void);

LED_type RedLed = {GPIO_PORTC, GPIO_PIN0, ACTIVE_HIGH};
LED_type YellowLed = {GPIO_PORTC, GPIO_PIN1, ACTIVE_HIGH};
LED_type GreenLed = {GPIO_PORTC, GPIO_PIN2, ACTIVE_HIGH};

SSD_Type S1 = {COMMON_CATHOD, GPIO_PORTA, GPIO_PORTA, GPIO_PIN7};
SSD_Type S2 = {COMMON_ANODE, GPIO_PORTB, GPIO_PORTB, GPIO_PIN7};

int main(void)
{
	app();
	while (1)
	{
		TrafficLight(GreenLed,60);
		TrafficLight(YellowLed,10);
		TrafficLight(RedLed,60);
		TrafficLight(YellowLed,10);
	}
	return 0;
}
void app(void)
{
	LED_voidInit(RedLed);
	LED_voidInit(YellowLed);
	LED_voidInit(GreenLed);
	SSD_voidInitDataPort(S1);
	SSD_voidEnable(S1);
	SSD_voidInitDataPort(S2);
	SSD_voidEnable(S2);
}
void TrafficLight(LED_type led, u8 duration)
{
	for (s8 counter = duration-1; counter >= 0; counter--)
	{
		LED_voidOn(led);
		SSD_voidSendNumber(S1, counter / 10);
		SSD_voidSendNumber(S2, counter % 10);
		_delay_ms(1000);
	}
	LedOff();
}

void LedOff(void){
	LED_voidOff(RedLed);
	LED_voidOff(YellowLed);
	LED_voidOff(GreenLed);
}
