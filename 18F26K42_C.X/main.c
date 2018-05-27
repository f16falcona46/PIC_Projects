/*
 * File:   main.c
 * Author: f16fa
 *
 * Created on November 15, 2017, 9:09 PM
 */
// CONFIG

#define _XTAL_FREQ (64000000L)

#include <xc.h>
#include <stdint.h>

uint8_t buf[2048];

void main(void) {
    CM1CON0 = 0xf7;
    CM2CON0 = 0xf7;
    ADCON0 = 0x30;
    
    int i = 0;
    while (1) {
        ++i;
        i = i * 2;
        i = i << 5;
        i = i / 7;
        DMA1DCNTH = i;
        DMA1DCNTL = buf[i];
    }
    return;
}
