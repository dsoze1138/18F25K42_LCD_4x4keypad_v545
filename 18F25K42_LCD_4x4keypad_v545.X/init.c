/*
 * File:   init.c
 * Author: dan1138
 *
 * Target: PIC18F25K42
 *
 *                                 PIC18F25K42
 *                   +-----------------:_:-----------------+
 *         VPP ->  1 : RE3/MCLR/VPP           PGD/ANB7/RB7 : 28 <> PGD
 *             ->  2 : RA0/ANA0               PGC/ANB6/RB6 : 27 <> PGC
 *        LED1 <>  3 : RA1/ANA1                   ANB5/RB5 : 26 <> KP_COL2_OUT
 *        LED2 <>  4 : RA2/ANA2                   ANB4/RB4 : 25 <> KP_COL1_OUT
 *      LCD_RS <>  5 : RA3/ANA3                   ANB3/RB3 : 24 <> KP_ROW4_IN
 *      LCD_RW <>  6 : RA4/ANA4                   ANB2/RB2 : 23 <> KP_ROW3_IN
 *      LCD_E  <>  7 : RA5/ANA5                   ANB1/RB1 : 22 <> KP_ROW2_IN
 *         GND <>  8 : VSS                        ANB0/RB0 : 21 <> KP_ROW1_IN
 *       20MHz <>  9 : RA7/ANA7/OSC1                   VDD : 20 <- 5v0
 *       20MHz <> 10 : RA6/ANA6/OSC2                   VSS : 19 <- GND
 *   32.768KHz <> 11 : RC0/ANC0/SOSCO       RX/DT/ANxn/RC7 : 18 <> LCD_D7
 *   32.768KHz <> 12 : RC1/ANC1/SOSCI       TX/CK/ANC6/RC6 : 17 <> LCD_D6
 * KP_COL3_OUT <> 13 : RC2/ANC2/CCP1     SPI_MOSI/ANC5/RC5 : 16 <> LCD_D5
 * KP_COL4_OUT <> 14 : RC3/ANC3/SPI_CLK  SPI_MISO/ANC4/RC4 : 15 <> LCD_D4
 *                   +-------------------------------------:
 *                                   DIP-28
 *
 *   LCD Module        PIC        Keypad 4x4        PIC
 *   MC21605C6W-SPR  PIN GPIO     7207-1610203    PIN GPIO     Key Caps
 *   [ 1]GND         [19]GND      [1]KP_ROW1_IN   [21]RB0    [1][2][3][R] R1
 *   [ 2]PWR         [20]PWR      [2]KP_ROW2_IN   [22]RB1    [4][5][6][L] R2
 *   [ 3]CONTRAST    [ 8]GND      [3]KP_COL1_OUT  [25]RB4    [7][8][9][U] R3
 *   [ 4]LCD_RS      [ 5]RA3      [4]KP_COL2_OUT  [26]RB5    [E][0][.][D] R4
 *   [ 5]LCD_RW      [ 6]RA4      [5]KP_COL3_OUT  [13]RC2     C  C  C  C
 *   [ 6]LCD_E       [ 7]RA5      [6]KP_COL4_OUT  [14]RC3     1  2  3  4
 *   [11]LCD_D4      [15]RC4      [7]KP_ROW4_IN   [23]RB3
 *   [12]LCD_D5      [16]RC5      [8]KP_ROW3_IN   [24]RB2
 *   [13]LCD_D6      [17]RC6
 *   [14]LCD_D7      [18]RC7
 *
 */
#pragma config FEXTOSC = OFF    // External Oscillator Selection (Oscillator not enabled)
#pragma config RSTOSC = HFINTOSC_64MHZ// Reset Oscillator Selection (HFINTOSC with HFFRQ = 64 MHz and CDIV = 1:1)
#pragma config CLKOUTEN = OFF   // Clock out Enable bit (CLKOUT function is disabled)
#pragma config PR1WAY = OFF     // PRLOCKED One-Way Set Enable bit (PRLOCK bit can be set and cleared repeatedly)
#pragma config CSWEN = ON       // Clock Switch Enable bit (Writing to NOSC and NDIV is allowed)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor enabled)
#pragma config MCLRE = EXTMCLR  // MCLR Enable bit (If LVP = 0, MCLR pin is MCLR; If LVP = 1, RE3 pin function is MCLR )
#pragma config PWRTS = PWRT_OFF // Power-up timer selection bits (PWRT is disabled)
#pragma config MVECEN = OFF     // Multi-vector enable bit (Interrupt contoller does not use vector table to prioritze interrupts)
#pragma config IVT1WAY = OFF    // IVTLOCK bit One-way set enable bit (IVTLOCK bit can be cleared and set repeatedly)
#pragma config LPBOREN = OFF    // Low Power BOR Enable bit (ULPBOR disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled , SBOREN bit is ignored)
#pragma config BORV = VBOR_2P45 // Brown-out Reset Voltage Selection bits (Brown-out Reset Voltage (VBOR) set to 2.45V)
#pragma config ZCD = OFF        // ZCD Disable bit (ZCD disabled. ZCD can be enabled by setting the ZCDSEN bit of ZCDCON)
#pragma config PPS1WAY = OFF    // PPSLOCK bit One-Way Set Enable bit (PPSLOCK bit can be set and cleared repeatedly (subject to the unlock sequence))
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config DEBUG = OFF      // Debugger Enable bit (Background debugger disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Extended Instruction Set and Indexed Addressing Mode disabled)
#pragma config WDTCPS = WDTCPS_31// WDT Period selection bits (Divider ratio 1:65536; software control of WDTPS)
#pragma config WDTE = OFF       // WDT operating mode (WDT Disabled; SWDTEN is ignored)
#pragma config WDTCWS = WDTCWS_7// WDT Window Select bits (window always open (100%); software control; keyed access not required)
#pragma config WDTCCS = SC      // WDT input clock selector (Software Control)
#pragma config BBSIZE = BBSIZE_512// Boot Block Size selection bits (Boot Block size is 512 words)
#pragma config BBEN = OFF       // Boot Block enable bit (Boot block disabled)
#pragma config SAFEN = OFF      // Storage Area Flash enable bit (SAF disabled)
#pragma config WRTAPP = OFF     // Application Block write protection bit (Application Block not write protected)
#pragma config WRTB = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-30000Bh) not write-protected)
#pragma config WRTC = OFF       // Boot Block Write Protection bit (Boot Block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)
#pragma config WRTSAF = OFF     // SAF Write protection bit (SAF not Write Protected)
#pragma config LVP = ON         // Low Voltage Programming Enable bit (Low voltage programming enabled. MCLR/VPP pin function is MCLR. MCLRE configuration bit is ignored)
#pragma config CP = OFF         // PFM and Data EEPROM Code Protection bit (PFM and Data EEPROM code protection disabled)
#include "init.h"

void PIC_Init(void) {
    INTCON0 = 0;     /* disable interrupts */
    PIE0 = 0;
    PIE1 = 0;
    PIE2 = 0;
    PIE3 = 0;
    PIE4 = 0;
    PIE5 = 0;
    PIE6 = 0;
    PIE7 = 0;
    PIE8 = 0;
    PIE9 = 0;
    PIE10 = 0;

    OSCTUNE = 0;

    ANSELA = 0x00;      /* configure all ADC inputs for digital I/O */
    ANSELB = 0xC0;      /* Leave RB7 & RB6 as analog inputs */
    ANSELC = 0x00;

    LATA   = 0x00;
    TRISA  = 0xC1;      /* RA1 output for LED1, RA2 output for LED2, RA3 output to LCD_RS, RA4 output for LCD_RW, RA5 output to LCD_E */
    LATB   = 0x30;
    TRISB  = 0xCF;      /* RB0-3 are keypad row inputs, RB4,RB5 are keypad COL1,COL2 drivers, RB6,RB7 are used for In-Circuit-Debug */
    WPUB   = 0x0F;      /* enable PORTB pull-ups for inputs */
    LATC   = 0x00;
    TRISC  = 0xF3;      /* RC2,RC3 are keypad COL3,COL4 drivers, RC4-RC7 are LCD I/O D4-D7 */
}
