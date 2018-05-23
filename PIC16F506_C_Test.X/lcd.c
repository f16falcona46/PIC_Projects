#include "lcd.h"
#include "spi_funcs.h"
#include "font_6_8.h"

#define setXY_sm(x, y) {LCD_PORT.LCD_DC = 0;\
shiftbyte_noNSS(0x22);\
shiftbyte_noNSS(0x80 | x);\
shiftbyte_noNSS(0x40 | y);\
LCD_PORT.LCD_DC = 1;}

void setXY(uint8_t x, uint8_t y)
{
    LCD_PORT.LCD_DC = 0;
    SPI_PORT.NSS = 0;
    shiftbyte_noNSS(0x22);
    shiftbyte_noNSS(0x80 | x);
    shiftbyte_noNSS(0x40 | y);
    SPI_PORT.NSS = 1;
    LCD_PORT.LCD_DC = 1;
}

uint8_t convertReadingToPaddle(uint8_t reading)
{
    reading = reading >> 2;
    if (reading > 40) {
        reading = 40;
    }
    return reading;
}

void drawPaddle(uint8_t pos, uint8_t col)
{
    SPI_PORT.NSS = 0;
    uint8_t lower_index = pos >> 3;
    LCD_PORT.LCD_DC = 0;
    shiftbyte_noNSS(0x22);
    shiftbyte_noNSS(0x80 | col);
    shiftbyte_noNSS(0x40 | lower_index);
    LCD_PORT.LCD_DC = 1;
    if (pos & 7) {
        uint8_t lower = pos - (lower_index << 3);
        uint8_t upper = 8 - lower;
        
        shiftbyte_noNSS(0xff << lower);
        shiftbyte_noNSS(0xff >> upper);
    }
    else {
        shiftbyte_noNSS(0xff);
    }
    SPI_PORT.NSS = 1;
}

uint8_t mul10(uint8_t in) {
    return in << 3 + in << 1;
}

void drawReading(uint8_t reading, uint8_t x, uint8_t y)
{
    SPI_PORT.NSS = 0;
    uint8_t remain = reading;
    reading = reading / 10;
    remain = remain - (reading << 3) - reading - reading;
    for (int i = 0; i < 6; ++i) {
        setXY_sm(x + 12 + i, y);
        shiftbyte_noNSS(nums[mul10(remain) + i]);
    }
    remain = reading;
    reading = reading / 10;
    remain = remain - (reading << 3) - reading - reading;
    for (int i = 0; i < 6; ++i) {
        setXY_sm(x + 6 + i, y);
        shiftbyte_noNSS(nums[mul10(remain) + i]);
    }
    for (int i = 0; i < 6; ++i) {
        setXY_sm(x + i, y);
        shiftbyte_noNSS(nums[mul10(reading) + i]);
    }
    SPI_PORT.NSS = 1;
}

void eraseBall(uint8_t x, uint8_t y)
{
    SPI_PORT.NSS = 0;
    setXY_sm(x, y >> 3);
    shiftbyte_noNSS(0x00);
    shiftbyte_noNSS(0x00);
    SPI_PORT.NSS = 1;
}

void drawBall(uint8_t x, uint8_t y)
{
    SPI_PORT.NSS = 0;
    setXY_sm(x, y >> 3);
    y = y & 0x07;
    shiftbyte_noNSS(0x03 << y);
    if (y == 7) {
        shiftbyte_noNSS(0x01);
    }
    SPI_PORT.NSS = 1;
}

void clearPaddles(void)
{
    SPI_PORT.NSS = 0;
    setXY_sm(0, 0);
    for (uint8_t j = 0; j < 6; ++j) {
        shiftbyte_noNSS(0x00);
    }
    setXY_sm(83, 0);
    for (uint8_t j = 0; j < 6; ++j) {
        shiftbyte_noNSS(0x00);
    }
    SPI_PORT.NSS = 1;
}

void drawNum(uint8_t num, uint8_t x, uint8_t y)
{
    SPI_PORT.NSS = 0;
    uint8_t temp = 0;
    for (int i = 0; i < 6; ++i) {
        temp += num;
    }
    for (int i = 0; i < 6; ++i) {
        setXY_sm(x + i, y);
        shiftbyte_noNSS(nums[temp + i]);
    }
    SPI_PORT.NSS = 1;
}

uint8_t outOfPaddle(uint8_t paddle, uint8_t y)
{
    if (y < paddle) {
        return 1;
    }
    paddle = paddle + 7;
    if (y > paddle) {
        return 1;
    }
    return 0;
}