/*
 * File:   main.c
 * Author: f16fa
 *
 * Created on April 29, 2018, 4:45 AM
 */


#include "xc.h"

int main(void) {
    int i, j;
    TRISAbits.TRISA0 = 1;
    while (1) {
        PORTAbits.RA0 ^= 1;
        for (i = 0; i < 1024; ++i) {
            for (j = 0; j < 1024; ++j) {
                Nop();
            }
        }
    }
    return 0;
}
