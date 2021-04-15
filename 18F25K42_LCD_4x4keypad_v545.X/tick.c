/*
 * File:   tick.c
 * Author: dan1138
 *
 * Target: PIC18F25K42
 */

#include "init.h"
#include "tick.h"

/*
 * Setup TIMER0 to assert an interrupt every 16384 instruction cycles
 */
void Tick_Init(void)
{
    PIE3bits.TMR0IE = 0;
    T0CON0 = 0;
    T0CON1 = T0CON1_INIT;
    TMR0 = 0;               /* TIMER0 will assert the overflow flag every 256*64 (16384)               */
    PIR3bits.TMR0IF = 0;    /* instruction cycles, with a 64MHz oscillator this is 1.024 milliseconds. */
    PIE3bits.TMR0IE = 1;
    T0CON0bits.EN   = 1;
}
