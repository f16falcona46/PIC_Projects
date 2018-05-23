/*
 * File:   main.c
 * Author: f16fa
 *
 * Created on November 15, 2017, 9:09 PM
 */
// CONFIG

#define _XTAL_FREQ (8000000L)

#include <xc.h>

void main(void) {
    TRISB = 0x3f;
    TRISC = 0x3f;
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
        i = i << 1;
    }
    return;
}
