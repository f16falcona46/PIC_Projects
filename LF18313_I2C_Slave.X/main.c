/*
 * File:   main.c
 * Author: f16fa
 *
 * Created on May 25, 2018, 2:48 PM
 */


#include <xc.h>
#include <stdint.h>

uint8_t prepare_for_reg = 0;
uint8_t selected_register = 0;
uint8_t buf[16] = {0};

void interrupt it(void);

void main(void)
{
    ANSELA = 0x07;
    SSP1CLKPPSbits.SSP1CLKPPS = 0x04;   //RA4->MSSP1:SCL1;    
    SSP1DATPPSbits.SSP1DATPPS = 0x05;   //RA5->MSSP1:SDA1;    
    RA4PPSbits.RA4PPS = 0x18;   //RA4->MSSP1:SCL1;    
    RA5PPSbits.RA5PPS = 0x19;   //RA5->MSSP1:SDA1; 
    
    SSP1STAT = 0;
    SSP1CON1 = 0b00100110; //I2C 7-bit slave mode
    SSP1CON2 = 0b00000001; //Clock stretching enable
    SSP1CON3 = 0b00000000; //Start interrupts disabled
    SSP1MSK = 0b11111110; //all seven bits of address are compared
    SSP1ADD = 0x1b << 1; //0x1b as slave address   
    
    PIE1bits.SSP1IE = 1;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    while (1);
}

void interrupt it(void)
{
    if (PIR1bits.SSP1IF) {
        PIR1bits.SSP1IF = 0;
        uint8_t i2c_data = SSP1BUF;
        if(SSP1STATbits.R_nW) {
            if (!(SSP1CON2bits.ACKSTAT && SSP1STATbits.D_nA)) {
                SSP1BUF = buf[selected_register++];
            }
        }
        else if (SSP1STATbits.D_nA) {
            if (prepare_for_reg) {
                selected_register = i2c_data;
            }
            else {
                buf[selected_register++] = i2c_data;
            }
            prepare_for_reg = 0;
        }
        else {
            prepare_for_reg = 1;
        }
        SSP1CON1bits.CKP = 1;
    }
}