/*
 * File:   main.c
 * Author: dan1138
 *
 * Target: PIC18F25K42
 *
 * Description:
 *  
 *
 *
 */

#include "init.h"
#include "main.h"
#include "keypad.h"
#include "lcd.h"
#include "tick.h"

volatile unsigned char gScanKeypadFlag;

/*
 * Interrupt handlers
 */
void __interrupt(high_priority) ISR_Handler(void)
{
    /* Handle system tick */
    if (PIE3bits.TMR0IE)
    {
        if(PIR3bits.TMR0IF)
        {
            PIR3bits.TMR0IF = 0;
            if(gScanKeypadFlag == 0) gScanKeypadFlag = 1;
        }
    }
}
/* Catch a low priority request */
void __interrupt(low_priority) ISR_HandlerLow(void)
{
}
/*
 * Display application name and version
 */
void ShowVersion(void)
{
    unsigned char buffer[17] = "\010\011\012\013\014\015\016\017"; /* octal byte constants in a string */
    
    LCD_SetDDRamAddr(LINE_ONE);
    LCD_WriteConstString((const unsigned char *)"Test: LCD+Keypad");
    /* Show what is in the character generator RAM */
    LCD_SetDDRamAddr(LINE_TWO);
    LCD_WriteString(buffer); 
    LCD_WriteConstString((const unsigned char *)" 18MAR11");
}
/*
 * Application
 */
void main(void) 
{
    unsigned char Key;
    unsigned char KeyPressedMessageFlag;
    
    PIC_Init();
    LCD_Init();
    Keypad_Init();
    Tick_Init();

    INTCON0bits.GIEL = 1;
    INTCON0bits.GIE  = 1;

    /* Display the application name and version information */
    ShowVersion();
    KeyPressedMessageFlag = 0;
    
    for(;;)
    {
        /* Scan the kepad matrix about every 2 milliseconds */
        if(gScanKeypadFlag != 0)
        {
            gScanKeypadFlag = 0;
            Keypad_Scan();
        }
        /* check for and process key presses */
        if (Keypad_GetEvent() == eKeyChanged)
        {
            if (KeyPressedMessageFlag == 0)
            {
                KeyPressedMessageFlag = 1;
                LCD_SetDDRamAddr(LINE_TWO);
                LCD_WriteConstString((const unsigned char *)"Key Pressed:    ");
            }
            else
            {
                LCD_SetDDRamAddr(LINE_TWO+13);
                LCD_WriteData(' ');
            }
            Key = Keypad_GetKey(NULL);
            if (Key != 0)
            {
                LCD_SetDDRamAddr(LINE_TWO+13);
                LCD_WriteData(Key);
                switch (Key)
                {
                    case '0':
                        break;
                    case '1':
                        break;
                    case '2':
                        break;
                    case '3':
                        break;
                    case '4':
                        break;
                    case '5':
                        break;
                    case '6':
                        break;
                    case '7':
                        break;
                    case '8':
                        break;
                    case '9':
                        break;
                    case 'E':
                        break;
                    case '.':
                        break;
                    case 'U':
                        break;
                    case 'D':
                        break;
                    case 'L':
                        break;
                    case 'R':
                        break;
                    default:
                        break;
                }
            }
        }
    }
}
