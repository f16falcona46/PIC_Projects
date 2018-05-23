#include "spi_funcs.h"

uint8_t shiftbyte(uint8_t data)
{
    SPI_PORT.NSS = 0;
    uint8_t output = shiftbyte_noNSS(data);
    SPI_PORT.NSS = 1;
    return output;
}

uint8_t shiftbyte_noNSS(uint8_t data)
{
    uint8_t output = 0;
    for (uint8_t i = 0; i < 8; ++i) {
        SPI_PORT.SCK = 0;
        if (data & 0x80) {
            SPI_PORT.MOSI = 1;
        }
        else {
            SPI_PORT.MOSI = 0;
        }
        SPI_PORT.SCK = 1;
        if (SPI_PORT.MISO) {
            output |= 1;
        }
        output = output << 1;
        data = data << 1;
    }
    return output;
}

void shiftout_buf(const uint8_t *buf, uint8_t size)
{
    SPI_PORT.NSS = 0;
    for (uint8_t i = 0; i < size; ++i) {
        shiftbyte_noNSS(buf[i]);
    }
    SPI_PORT.NSS = 1;
}