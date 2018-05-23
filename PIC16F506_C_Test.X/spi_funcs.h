#ifndef SPI_FUNCS_H
#define	SPI_FUNCS_H

#include <xc.h>
#include <stdint.h>


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
    
#define SPI_PORT PORTCbits
#define NSS RC0
#define SCK RC1
#define MISO RC2
#define MOSI RC3

uint8_t shiftbyte(uint8_t data);
uint8_t shiftbyte_noNSS(uint8_t data);
void shiftout_buf(const uint8_t *buf, uint8_t size);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* SPI_FUNCS_H */

