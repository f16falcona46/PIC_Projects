/*
 * File:   main.c
 * Author: f16fa
 *
 * Created on November 15, 2017, 9:09 PM
 */
// CONFIG
#pragma config OSC = ExtRC_CLKOUTEN// Oscillator Selection bits (EXTRC With CLKOUT and 1.125 ms DRT)
#pragma config WDT = ON         // Watchdog Timer Enable bit (WDT enabled)
#pragma config CP = OFF         // Code Protect (Code protection off)
#pragma config MCLRE = ON       // Master Clear Enable bit (RB3/MCLR pin functions as MCLR)
#pragma config IOSCFS = ON      // Internal Oscillator Frequency Select bit (8 MHz INTOSC Speed)

#define _XTAL_FREQ (8000000L)

#include <xc.h>

void main(void) {
    TRISB = 0x3f;
    TRISC = 0x3f;
    OPTION = 0x97;
    CM1CON0 = 0xf7;
    CM2CON0 = 0xf7;
    ADCON0 = 0x30;
    
    while (1) {
        PORTB = 0x3f;
        PORTC = 0x3f;
        __delay_ms(300);
        PORTB = 0x00;
        PORTC = 0x00;
        __delay_ms(300);
        PORTB |= 0x01;
        int i = 0;
        ++i;
        i = i << 3;
    }
    return;
}
