/*
 * File:   main.c
 * Author: f16fa
 *
 * Created on April 7, 2018, 2:56 AM
 */

#define NO_BIT_DEFINES
#include <pic14/pic16lf18313.h>

void main(void) {
    int i;
    PORTA = 0;
    for (i = 0; i < 20; ++i) {
        PORTAbits.RA1 ^= 1;
    }
    return;
}
