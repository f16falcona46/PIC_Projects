/*
 * File:   main.c
 * Author: f16fa
 *
 * Created on November 15, 2017, 9:09 PM
 */
// CONFIG
#pragma config OSC = IntRC_RB4EN// Oscillator Selection bits (INTRC With RB4 and 1.125 ms DRT)
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled)
#pragma config CP = OFF         // Code Protect (Code protection off)
#pragma config MCLRE = ON       // Master Clear Enable bit (RB3/MCLR pin functions as MCLR)
#pragma config IOSCFS = ON      // Internal Oscillator Frequency Select bit (8 MHz INTOSC Speed)

#define _XTAL_FREQ (8000000L)

#include <xc.h>
#include "spi_funcs.h"
#include "font_6_8.h"
#include "lcd.h"

static const uint8_t init[] = {0x23, 0x13, 0xC7, 0x22, 0x0C, 0x40, 0x80};

#define BALL_SPEED 4

uint8_t ball_vx = 1;
int8_t ball_vy = 1;
int8_t ball_x = 1;
uint8_t ball_y = 1;
uint8_t left_paddle = 0;
uint8_t right_paddle = 0;
uint8_t left_score = 0;
uint8_t right_score = 0;

uint8_t readADC(uint8_t chan);

void main(void) {
    TRISB = 0x3f;
    TRISC = 0x00;
    OPTION = 0x97;
    CM1CON0 = 0xf7;
    CM2CON0 = 0xf7;
    ADCON0 = 0xf1;
    
    LCD_PORT.LCD_RST = 0;
    __delay_ms(1);
    LCD_PORT.LCD_RST = 1;
    
    LCD_PORT.LCD_DC = 0;
    shiftout_buf(init, sizeof(init));
    LCD_PORT.LCD_DC = 1;
    
    for (uint8_t i = 0; i < 84; ++i) {
        for (uint8_t j = 0; j < 6; ++j) {
            shiftbyte(0x00);
        }
    }
    
    while (1) {
        left_paddle = readADC(1);
        right_paddle = readADC(2);
        //left_paddle = 40 - convertReadingToPaddle(reading);
        left_paddle = convertReadingToPaddle(left_paddle);
        right_paddle = convertReadingToPaddle(right_paddle);
        
        clearPaddles();
        drawPaddle(left_paddle, 0);
        drawPaddle(right_paddle, 83);
        
        __delay_ms(50);
        int8_t new_ball_x = ball_x + ball_vx;
        int8_t new_ball_y = ball_y + ball_vy;
        eraseBall(ball_x, ball_y);
        eraseBall(ball_x + 1, ball_y);
        if (new_ball_x < 1) {
            if (outOfPaddle(left_paddle, new_ball_y)) {
                new_ball_x = 21;
                new_ball_y = new_ball_y + 20;
                ++right_score;
            }
            else {
                new_ball_x = 1;
            }
            ball_vx = -ball_vx;
        }
        if (new_ball_x > 81) {
            if (outOfPaddle(right_paddle, new_ball_y)) {
                new_ball_x = 61;
                new_ball_y = new_ball_y + 20;
                ++left_score;
            }
            else {
                new_ball_x = 81;
            }
            ball_vx = -ball_vx;
        }
        if (new_ball_y < 0) {
            new_ball_y = 0;
            ball_vy = -ball_vy;
        }
        if (new_ball_y > 46) {
            new_ball_y = 46;
            ball_vy = -ball_vy;
        }
        
        if (left_score > 9 || right_score > 9) {
            left_score = 0;
            right_score = 0;
        }
        
        drawBall(new_ball_x, new_ball_y);
        drawBall(new_ball_x + 1, new_ball_y);
        ball_x = new_ball_x;
        ball_y = new_ball_y;
        drawNum(left_score, 20, 0);
        drawNum(right_score, 58, 0);
    }
}

uint8_t readADC(uint8_t chan)
{
    ADCON0bits.CHS = chan;
    ADCON0bits.GO = 1;
    while (ADCON0bits.nDONE);
    return ADRES;
}