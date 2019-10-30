/**********************************************************************************************************************
 * \file GPT12_PWM_Capture.c
 * \copyright Copyright (C) Infineon Technologies AG 2019
 *
 * Use of this file is subject to the terms of use agreed between (i) you or the company in which ordinary course of
 * business you are acting and (ii) Infineon Technologies AG or its licensees. If and as long as no such terms of use
 * are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization obtaining a copy of the software and
 * accompanying documentation covered by this license (the "Software") to use, reproduce, display, distribute, execute,
 * and transmit the Software, and to prepare derivative works of the Software, and to permit third-parties to whom the
 * Software is furnished to do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including the above license grant, this restriction
 * and the following disclaimer, must be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are solely in the form of
 * machine-executable object code generated by a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *********************************************************************************************************************/

/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "Ifx_Types.h"
#include "IfxGpt12.h"
#include "Bsp.h"
  
/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define ISR_PRIORITY_GPT12_T2_INT   10              /* Define the GPT12 Timer 2 interrupt priority                  */
#define ISR_PRIORITY_GPT12_T3_INT   11              /* Define the GPT12 Timer 2 interrupt priority                  */
#define MAX_VAL_16_BIT              0xFFFF          /* Used for calculation of timer value with overflows           */

#define PWM_PIN                     &MODULE_P00,8   /* Pin which is used to generate a simple PWM signal            */
#define PWM_DUTY                    0.5             /* Duty cycle of generated PWM signal, value between 0 and 1    */
#define FACTOR_SEC_TO_USEC          1000000         /* Factor to convert seconds to microseconds                    */

/*********************************************************************************************************************/
/*-------------------------------------------------Global variables--------------------------------------------------*/
/*********************************************************************************************************************/
float32 g_generatedPwmFreqHz    = 50.0; /* Global variable for frequency of generated PWM signal                    */
float32 g_measuredPwmFreqHz     = 0.0;  /* Global variable for frequency calculation of PWM signal                  */
uint32  g_cntOverflow           = 0;    /* Global counter variable for the timer overflow between two edges         */
uint32  g_previousCntVal        = 0;    /* Global variable which stores the timer value of the previous interrupt   */

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/* Macro to define the Interrupt Service Routine. */
IFX_INTERRUPT(GPT12_T2_Int0_Handler, 0, ISR_PRIORITY_GPT12_T2_INT);

/* Interrupt Service Routine of timer T2, gets triggered by rising edge on input pin of timer T2 */
void GPT12_T2_Int0_Handler(void)
{
    uint32 currentCntVal = IfxGpt12_T2_getTimerValue(&MODULE_GPT120); /* Get timer value of timer T2 */
    uint32 finalCntVal = 0; /* Variable to calculate final timer counter value */

    if(g_cntOverflow == 0)
    {
        /* If no overflow detected */
        finalCntVal = currentCntVal - g_previousCntVal; /* Total counter value calculation */
    }
    else
    {
        /* One or more overflows detected */
        /* Add to the current counter value, the amount of counter ticks which passed before the first overflow,
         * plus 65525 (0xFFFF) for each additional overflow since the previous rising edge.
         */
        finalCntVal = (uint32)(currentCntVal + (MAX_VAL_16_BIT - g_previousCntVal) + ((g_cntOverflow - 1) * MAX_VAL_16_BIT));
    }

    /* Calculation of the PWM frequency by dividing the frequency of timer T3 through the final total counter value */
    g_measuredPwmFreqHz = IfxGpt12_T3_getFrequency(&MODULE_GPT120) / finalCntVal;

    g_previousCntVal = currentCntVal;    /* Set g_previousCntVal to currentCntVal for the next calculation */
    g_cntOverflow = 0;                   /* Reset overflow flag */
}

/* Macro to define the Interrupt Service Routine. */
IFX_INTERRUPT(GPT12_T3_Int0_Handler, 0, ISR_PRIORITY_GPT12_T3_INT);

/* Interrupt Service Routine of timer T3, gets triggered after T3 timer overflow */
void GPT12_T3_Int0_Handler(void)
{
    g_cntOverflow++; /* Increase overflow counter */
}

/* This function initializes timer T2 and T3 of the block GPT1 of module GPT12 to capture PWM signals. */
void init_GPT12_module(void)
{
    /* Enable GPT12 module */
    IfxGpt12_enableModule(&MODULE_GPT120);
    /* Select 4 as prescaler for the GPT1 module -> fastest clock frequency for best accuracy */
    IfxGpt12_setGpt1BlockPrescaler(&MODULE_GPT120, IfxGpt12_Gpt1BlockPrescaler_4);
    /* Set core timer T3 in timer mode */
    IfxGpt12_T3_setMode(&MODULE_GPT120, IfxGpt12_Mode_timer);
    /* Set auxiliary timer T2 in capture mode */
    IfxGpt12_T2_setMode(&MODULE_GPT120, IfxGpt12_Mode_capture);
    /* Select input pin A of timer T2 which is P00.7 (the James Bond pin) */
    IfxGpt12_T2_setInput(&MODULE_GPT120, IfxGpt12_Input_A);
    /* Select rising edge as capture event */
    IfxGpt12_T2_setCaptureInputMode(&MODULE_GPT120, IfxGpt12_CaptureInputMode_risingEdgeTxIN);

    /* Service request configuration */
    /* Get source pointer of timer T2, initialize and enable */
    volatile Ifx_SRC_SRCR *src = IfxGpt12_T2_getSrc(&MODULE_GPT120);
    IfxSrc_init(src, IfxSrc_Tos_cpu0, ISR_PRIORITY_GPT12_T2_INT);
    IfxSrc_enable(src);
    /* Get source pointer of timer T3, initialize and enable */
    src = IfxGpt12_T3_getSrc(&MODULE_GPT120);
    IfxSrc_init(src, IfxSrc_Tos_cpu0, ISR_PRIORITY_GPT12_T3_INT);
    IfxSrc_enable(src);

    /* Initialize time constants */
    initTime();
    /* Initialize PWM_PIN port pin */
    IfxPort_setPinMode(PWM_PIN, IfxPort_Mode_outputPushPullGeneral);

    /* Start timer T3*/
    IfxGpt12_T3_run(&MODULE_GPT120, IfxGpt12_TimerRun_start);
}

/* Generation of simple PWM signal by toggling a pin (frequency can be changed during runtime) */
void generate_PWM_signal(void)
{
    /* Calculate the total time between two rising edges for the specific frequency */
    sint32 targetWaitTime_us = (1 / g_generatedPwmFreqHz) * FACTOR_SEC_TO_USEC * TimeConst_1us;
    /* Set the pin high to trigger an interrupt */
    IfxPort_setPinState(PWM_PIN, IfxPort_State_high);
    /* Wait for an amount of CPU ticks that represent the calculated microseconds considering the duty cycle */
    wait(PWM_DUTY * targetWaitTime_us);
    /* Set pin state to low */
    IfxPort_setPinState(PWM_PIN, IfxPort_State_low);
    /* Wait for an amount of CPU ticks that represent the calculated microseconds considering the duty cycle */
    wait((1 - PWM_DUTY) * targetWaitTime_us);
}