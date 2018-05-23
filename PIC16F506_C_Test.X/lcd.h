#ifndef LCD_H
#define	LCD_H

#include <stdint.h>
#include <xc.h> // include processor files - each processor file is guarded.  

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

#define LCD_PORT PORTCbits
#define LCD_DC RC4
#define LCD_RST RC5

void setXY(uint8_t x, uint8_t y);
uint8_t convertReadingToPaddle(uint8_t reading);
void drawPaddle(uint8_t reading, uint8_t col);
void drawReading(uint8_t reading, uint8_t x, uint8_t y);
void eraseBall(uint8_t x, uint8_t y);
void drawBall(uint8_t x, uint8_t y);
void clearPaddles(void);
void drawNum(uint8_t num, uint8_t x, uint8_t y);
uint8_t outOfPaddle(uint8_t paddle, uint8_t y);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* LCD_H */

