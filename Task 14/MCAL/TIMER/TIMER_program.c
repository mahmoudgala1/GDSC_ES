/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : MCAL
 *  SWC    : TIMER
 *
 */

#include "../../LIB/BIT_MATH.h"
#include "TIMER_private.h"
#include "TIMER_interface.h"

static void (*TIMERS_pvCallBackFunc[16])(void) = {NULL};

void TIMER0_voidInit(void)
{
#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER_NORMAL_MODE
    CLEAR_BIT(TCCR0, TCCR0_WGM00);
    CLEAR_BIT(TCCR0, TCCR0_WGM01);
    TCNT0 = TIMER0_PRELOAD_VAL;
#if TIMER0_OVERFLOW_INTERRUPT == DISABLE
    CLR_BIT(TIMSK, TIMSK_TOIE0);
#elif TIMER0_OVERFLOW_INTERRUPT == ENABLE
    SET_BIT(TIMSK, TIMSK_TOIE0);
#endif
#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_PWM_MODE
    SET_BIT(TCCR0, TCCR0_WGM00);
    CLEAR_BIT(TCCR0, TCCR0_WGM01);
#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_CTC_MODE
    CLEAR_BIT(TCCR0, TCCR0_WGM00);
    SET_BIT(TCCR0, TCCR0_WGM01);
    OCR0 = TIMER0_CTC_VAL;
#if TIMER0_OC0_MODE == TIMER_OC_DISCONNECTED
    CLEAR_BIT(TCCR0, TCCR0_COM00);
    CLEAR_BIT(TCCR0, TCCR0_COM01);
#elif TIMER0_OC0_MODE == TIMER_OC_TOGGEL
    SET_BIT(TCCR0, TCCR0_COM00);
    CLEAR_BIT(TCCR0, TCCR0_COM01);
#elif TIMER0_OC0_MODE == TIMER_OC_LOW
    CLEAR_BIT(TCCR0, TCCR0_COM00);
    SET_BIT(TCCR0, TCCR0_COM01);
#elif TIMER0_OC0_MODE == TIMER_OC_HIGH
    SET_BIT(TCCR0, TCCR0_COM00);
    SET_BIT(TCCR0, TCCR0_COM01);
#endif
#if TIMER0_CTC_INTERRUPT == DISABLE
    CLEAR_BIT(TIMSK, TIMSK_OCIE0);
#elif TIMER0_CTC_INTERRUPT == ENABLE
    SET_BIT(TIMSK, TIMSK_OCIE0);
#endif
#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER_FAST_PWM_MODE
    SET_BIT(TCCR0, TCCR0_WGM00);
    SET_BIT(TCCR0, TCCR0_WGM01);
#if TIMER0_CTC_PWM_MODE == TIMER_OC_DISCONNECTED
    CLEAR_BIT(TCCR0, TCCR0_COM00);
    CLEAR_BIT(TCCR0, TCCR0_COM01);
#elif TIMER0_CTC_PWM_MODE == TIMER_CLR_ON_CTC_SET_ON_TOP
    CLEAR_BIT(TCCR0, TCCR0_COM00);
    SET_BIT(TCCR0, TCCR0_COM01);
#elif TIMER0_CTC_PWM_MODE == TIMER_SET_ON_CTC_CLR_ON_TOP
    SET_BIT(TCCR0, TCCR0_COM00);
    SET_BIT(TCCR0, TCCR0_COM01);
#endif
    OCR0 = TIMER0_CTC_VAL;
#endif
    TCCR0 &= TIMER_PRESCALER_MASK;
    TCCR0 |= TIMER0_PRESCALER;
}

void TIMER0_voidSetPreload(u8 Copy_u8Preload)
{
    TCNT0 = Copy_u8Preload;
}

void TIMER0_voidSetCTC(u8 Copy_u8CTC)
{
    OCR0 = Copy_u8CTC;
}

u8 TIMER0_u8GetTimerCounterValue(void)
{
    return TCNT0;
}

u8 TIMER_u8SetCallBack(void (*Copy_pvCallBackFunc)(void), u8 Copy_u8VectorID)
{
    u8 Local_u8ErrorState = OK;
    if (Copy_pvCallBackFunc != NULL)
    {
        TIMERS_pvCallBackFunc[Copy_u8VectorID] = Copy_pvCallBackFunc;
    }
    else
    {
        Local_u8ErrorState = NULL_POINTER;
    }
    return Local_u8ErrorState;
}

/*TIMER0 Normal Mode ISR*/
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
    if (TIMERS_pvCallBackFunc[TIMER0_OVF_VECTOR_ID] != NULL)
    {
        TIMERS_pvCallBackFunc[TIMER0_OVF_VECTOR_ID]();
    }
}

/*TIMER0 CTC Mode ISR*/
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
    if (TIMERS_pvCallBackFunc[TIMER0_CTC_VECTOR_ID] != NULL)
    {
        TIMERS_pvCallBackFunc[TIMER0_CTC_VECTOR_ID]();
    }
}