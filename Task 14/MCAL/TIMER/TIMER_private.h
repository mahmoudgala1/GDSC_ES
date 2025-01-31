/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    TIMER_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mahmoud Galal Elgendy
 *  Layer  : MCAL
 *  SWC    : TIMER
 *
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

/*  REG Bits */

#define TIMSK_TOIE0 0x00
#define TIMSK_OCIE0 0x01
#define TIMSK_TOIE1 0x02
#define TIMSK_OCIE1B 0x03
#define TIMSK_OCIE1A 0x04
#define TIMSK_TICIE1 0x05
#define TIMSK_TOIE2 0x06
#define TIMSK_OCIE2 0x07

#define TIFR_TOV0 0x00
#define TIFR_OCF0 0x01
#define TIFR_TOV1 0x02
#define TIFR_OCF1B 0x03
#define TIFR_OCF1A 0x04
#define TIFR_ICF1 0x05
#define TIFR_TOV2 0x06
#define TIFR_OCV2 0x07

/*Timer0*/
#define TCCR0_FOC0 0x07
#define TCCR0_WGM00 0x06
#define TCCR0_COM01 0x05
#define TCCR0_COM00 0x04
#define TCCR0_WGM01 0x03
#define TCCR0_CS02 0x02
#define TCCR0_CS01 0x01
#define TCCR0_CS00 0x00

/*Timer1*/

#define TCCR1A_COM1A1 0x07
#define TCCR1A_COM1A0 0x06
#define TCCR1A_COM1B1 0x05
#define TCCR1A_COM1B0 0x04
#define TCCR1A_WGM11 0x01
#define TCCR1A_WGM10 0x00

#define TCCR1B_ICNC1 0x07
#define TCCR1B_ICES1 0x06
#define TCCR1B_WGM13 0x04
#define TCCR1B_WGM12 0x03

/*Timer2*/

#define TCCR2_WGM20 0x06
#define TCCR2_COM21 0x05
#define TCCR2_COM20 0x04
#define TCCR2_WGM21 0x03

#define DISABLE 0x00
#define ENABLE 0x01

#define FALLING_EDGE 0x00
#define RISING_EDGE 0x01

#define TIMER_NO_CLOCK_SOURCE 0x00
#define TIMER_NO_PRESCALER_FACTOR 0x01
#define TIMER_DIVISION_FACTOR_8 0x02
#define TIMER_DIVISION_FACTOR_64 0x03
#define TIMER_DIVISION_FACTOR_256 0x04
#define TIMER_DIVISION_FACTOR_1024 0x05
#define TIMER_T0_ExTERNAL_CLOCK_SOURCE_FALLING 0x06
#define TIMER_T0_ExTERNAL_CLOCK_SOURCE_RISING 0x07

#define TIMER_PRESCALER_MASK 0b11111000

#define TIMER_NORMAL_MODE 0x00
#define TIMER_PWM_MODE 0x01
#define TIMER_CTC_MODE 0x02
#define TIMER_FAST_PWM_MODE 0x03

#define TIMER_OC_DISCONNECTED 0x00
#define TIMER_OC_TOGGEL 0x01
#define TIMER_OC_LOW 0x02
#define TIMER_OC_HIGH 0x03

#define TIMER_OC_DISCONNECTED 0x00
#define TIMER_CLR_ON_CTC_SET_ON_TOP 0x02
#define TIMER_SET_ON_CTC_CLR_ON_TOP 0x03

#define TIMER1_NORMAL_MODE 0x00
#define TIMER1_PWM_8_BIT_MODE 0x01
#define TIMER1_PWM_9_BIT_MODE 0x02
#define TIMER1_PWM_10_BIT_MODE 0x03
#define TIMER1_CTC_OCR1A_MODE 0x04
#define TIMER1_FAST_PWM_8_BIT_MODE 0x05
#define TIMER1_FAST_PWM_9_BIT_MODE 0x06
#define TIMER1_FAST_PWM_10_BIT_MODE 0x07
#define TIMER1_PWM_PHASE_AND_FREQ_CORRECT_ICR1_MODE 0x08
#define TIMER1_PWM_PHASE_AND_FREQ_CORRECT_OCR1A_MODE 0x09
#define TIMER1_PWM_PHASE_CORRECT_ICR1_MODE 0x0A
#define TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE 0x0B
#define TIMER1_CTC_ICR1_MODE 0x0C
#define TIMER1_FAST_PWM_ICR1_MODE 0x0D
#define TIMER1_FAST_PWM_OCR1A_MODE 0x0E

#define TIMER_u8_ICP_FALLING_EDGE 0x00
#define TIMER_u8_ICP_RAISING_EDGE 0x01

/* WDTCR Bits */
#define WDTCR_WDTOE 0x04
#define WDTCR_WDE 0x03
#define WDTCR_WDP2 0x02
#define WDTCR_WDP1 0x01
#define WDTCR_WDP0 0x00

/* WDT Prescaler select  */
#define WDT_PS_MASKING 0b11111000
#define WDT_PS_16_3_MS 0x00
#define WDT_PS_32_5_MS 0x01
#define WDT_PS_65_MS 0x02
#define WDT_PS_0_13_S 0x03
#define WDT_PS_0_26_S 0x04
#define WDT_PS_0_52_S 0x05
#define WDT_PS_1_0_S 0x06
#define WDT_PS_2_1_S 0x07

#endif /* TIMER_PRIVATE_H_ */