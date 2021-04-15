/*
 * File:   init.h
 * Author: dan1138
 * 
 * Target: PIC18F25K42
 *
 */
#ifndef INIT_H
#define INIT_H
#include <xc.h>
#include <stddef.h>

/*   Specify the System clock frequency in Hz */
#define FSYS (64000000ul)
    
/*   Specify the Peripheral clock frequency in Hz */
#define FCYC (FSYS/4ul)

#define _XTAL_FREQ FSYS

/*   Specify the TIMER0 prescale and keypad matrix debounce count based on the system clock frequency */
#if   (FSYS >= 64000000ul)
#define  T0CON1_INIT (0b01000110u) /* TMR0 clock edge low to high, TMR0 clock = FCY, TMR0 prescale 1:64      */
#define KP_DEBOUNCE_COUNT (128)
#elif (FSYS >= 32000000ul)
#define  T0CON1_INIT (0b01000101u) /* TMR0 clock edge low to high, TMR0 clock = FCY, TMR0 prescale 1:32      */
#define KP_DEBOUNCE_COUNT (64)
#elif (FSYS >= 16000000ul)
#define  T0CON1_INIT (0b01000100u) /* TMR0 clock edge low to high, TMR0 clock = FCY, TMR0 prescale 1:16      */
#define KP_DEBOUNCE_COUNT (32)
#elif (FSYS >= 8000000ul)
#define  T0CON1_INIT (0b01000011u) /* TMR0 clock edge low to high, TMR0 clock = FCY, TMR0 prescale 1:8       */
#define KP_DEBOUNCE_COUNT (16)
#elif (FSYS >= 4000000ul)
#define  T0CON1_INIT (0b01000010u) /* TMR0 clock edge low to high, TMR0 clock = FCY, TMR0 prescale 1:4       */
#define KP_DEBOUNCE_COUNT (16)
#elif (FSYS >= 2000000ul)
#define  T0CON1_INIT (0b01000001u) /* TMR0 clock edge low to high, TMR0 clock = FCY, TMR0 prescale 1:2       */
#define KP_DEBOUNCE_COUNT (16)
#elif (FSYS >= 1000000ul)
#define  T0CON1_INIT (0b01000000u) /* TMR0 clock edge low to high, TMR0 clock = FCY, TMR0 prescale 1:1       */
#define KP_DEBOUNCE_COUNT (16)
#elif (FSYS >=  500000ul)
#define  T0CON1_INIT (0b01000000u) /* TMR0 clock edge low to high, TMR0 clock = FCY, TMR0 prescale 1:1       */
#define KP_DEBOUNCE_COUNT (12)
#elif (FSYS >=  250000ul)
#define  T0CON1_INIT (0b01000000u) /* TMR0 clock edge low to high, TMR0 clock = FCY, TMR0 prescale 1:1       */
#define KP_DEBOUNCE_COUNT (8)
#elif (FSYS >=  125000ul)
#define  T0CON1_INIT (0b01000000u) /* TMR0 clock edge low to high, TMR0 clock = FCY, TMR0 prescale 1:1       */
#define KP_DEBOUNCE_COUNT (6)
#else 
#define  T0CON1_INIT (0b01000000u) /* TMR0 clock edge low to high, TMR0 clock = FCY, TMR0 prescale 1:1       */
#define KP_DEBOUNCE_COUNT (3)
#endif

void PIC_Init(void);

#endif
