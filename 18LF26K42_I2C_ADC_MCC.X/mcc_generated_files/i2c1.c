/**
  I2C1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    i2c1.c

  @Summary
    This is the generated header file for the I2C1 driver using 
    PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for I2C1.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC18LF26K42
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/*
 This file provides some basic functions for common operations on the i2c API
 */
#include <xc.h>
#include <stdbool.h>
#include "i2c1.h"
#include "mcc.h"
#include "interrupt_manager.h"

typedef enum
{
    SLAVE_NORMAL_DATA,
    SLAVE_DATA_ADDRESS,
} SLAVE_WRITE_DATA_TYPE;

/**
 Section: Global Variables
*/
volatile uint8_t   I2C1_slaveWriteData = 0x55;

/**
 Section: Local Functions
*/
void I2C1_StatusCallback(I2C1_SLAVE_DRIVER_STATUS i2c1_bus_state);



/**
  Prototype:        void I2C1_Initialize(void)
  Input:            none
  Output:           none
  Description:      I2C1_Initialize is an
                    initialization routine that takes inputs from the GUI.
  Comment:          
  Usage:            I2C1_Initialize();

*/
void I2C1_Initialize(void)
{
    
		// ADR 28; 
		I2C1ADR0 = 0x1C;
		// ADR 127; 
		I2C1ADR1 = 0xFE;
		// ADR 0; 
		I2C1ADR2 = 0x00;
		// ADR 0; 
		I2C1ADR3 = 0x00;
		// TXU 0; CSD Clock Stretching enabled; ACKT 0; RXO 0; ACKDT Acknowledge; ACKSTAT ACK received; ACKCNT Acknowledge; 
		I2C1CON1 = 0x00;
		// ABD enabled; GCEN disabled; ACNT disabled; SDAHT 300 ns hold time; BFRET 8 I2C Clock pulses; FME disabled; 
		I2C1CON2 = 0x00;
		// CLK Fosc/4; 
		I2C1CLK = 0x00;
		// CNT 0; 
		I2C1CNT = 0x00;
		// CSTR Enable clocking; S Cleared by hardware after Start; MODE four 7-bit address; EN enabled; RSEN disabled; 
		I2C1CON0 = 0x80;
    
    PIR2bits.I2C1RXIF=0;
    PIR3bits.I2C1TXIF=0;
    PIR3bits.I2C1EIF=0;
    I2C1ERRbits.NACKIF=0;
    PIR3bits.I2C1IF=0;
    I2C1PIRbits.PCIF=0;
    I2C1PIRbits.ADRIF=0;
    
    PIE2bits.I2C1RXIE=1;//enable I2C RX interrupt
    PIE3bits.I2C1TXIE=1;//enable I2C TX interrupt
    PIE3bits.I2C1EIE=1;//enable I2C error interrupt
    I2C1ERRbits.NACKIE=1;//enable I2C error interrupt for NACK
    PIE3bits.I2C1IE=1;//enable I2C  interrupt
    I2C1PIEbits.PCIE=1;//enable I2C interrupt for stop condition
    I2C1PIEbits.ADRIE=1;//enable I2C interrupt for I2C address match condition
	
    
    I2C1PIR = 0;//    ;Clear all the error flags
    I2C1ERR = 0;
    
}

void __interrupt(irq(IRQ_I2C1TX,IRQ_I2C1RX,IRQ_I2C1E,IRQ_I2C1),base(IVT1_BASE_ADDRESS)) I2C1_ISR()
{

    uint8_t  I2C1_data = 0x55;
    if ((I2C1STAT1bits.RXBF)||(PIR2bits.I2C1RXIF))
    {
		PIR2bits.I2C1RXIF=0;
        I2C1_data = I2C1RXB;
    }
    if(1 == I2C1STAT0bits.R)
    {

        if (I2C1PIRbits.PCIF)
        {
            I2C1PIRbits.PCIF=0;
			PIR3bits.I2C1IF=0;
            I2C1STAT1bits.CLRBF=1;//clear I2C1TXB and TXBE
        }
        if (I2C1ERRbits.NACKIF)
        {
            I2C1ERRbits.NACKIF=0;
			PIR3bits.I2C1EIF=0;
            I2C1STAT1bits.CLRBF=1;//clear I2C1TXB and TXBE
            I2C1_StatusCallback(I2C1_SLAVE_READ_COMPLETED);
        }
        else if(PIR3bits.I2C1TXIF)
        {
			PIR3bits.I2C1TXIF=0;
            // callback routine should write data into I2C1TXB
            I2C1_StatusCallback(I2C1_SLAVE_READ_REQUEST);
        }
        if (I2C1PIRbits.ADRIF)
        {
            I2C1PIRbits.ADRIF=0;
			PIR3bits.I2C1IF=0;
        }

    }
    else if((I2C1PIRbits.ADRIF))
    {
        I2C1PIRbits.ADRIF=0;
		PIR3bits.I2C1IF=0;
        // callback routine should prepare to receive data from the master
        I2C1_StatusCallback(I2C1_SLAVE_WRITE_REQUEST);
    }
    else
    {
        I2C1_slaveWriteData   = I2C1_data;

        // callback routine should process I2C1_slaveWriteData from the master
        I2C1_StatusCallback(I2C1_SLAVE_WRITE_COMPLETED);
    }
    I2C1CON0bits.CSTR=0; 

} 

/**

    Example implementation of the callback

    This slave driver emulates an EEPROM Device.
    Sequential reads from the EEPROM will return data at the next
    EEPROM address.

    Random access reads can be performed by writing a single byte
    EEPROM address, followed by 1 or more reads.

    Random access writes can be performed by writing a single byte
    EEPROM address, followed by 1 or more writes.

    Every read or write will increment the internal EEPROM address.

    When the end of the EEPROM is reached, the EEPROM address will
    continue from the start of the EEPROM.
*/

void I2C1_StatusCallback(I2C1_SLAVE_DRIVER_STATUS i2c1_bus_state)
{

    static uint8_t EEPROM_Buffer[] =
    {
        0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,
        0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,
        0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2a,0x2b,0x2c,0x2d,0x2e,0x2f,
        0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3a,0x3b,0x3c,0x3d,0x3e,0x3f,
        0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,
        0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5a,0x5b,0x5c,0x5d,0x5e,0x5f,
        0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0x6b,0x6c,0x6d,0x6e,0x6f,
        0x70,0x71,0x72,0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7a,0x7b,0x7c,0x7d,0x7e,0x7f,
    };

    static uint8_t eepromAddress    = 0;
    static uint8_t eepromData    = 0x55;
    static uint8_t slaveWriteType   = SLAVE_NORMAL_DATA;


    switch (i2c1_bus_state)
    {
        case I2C1_SLAVE_WRITE_REQUEST:
            // the master will be sending the eeprom address next
            slaveWriteType  = SLAVE_DATA_ADDRESS;
            break;


        case I2C1_SLAVE_WRITE_COMPLETED:

            switch(slaveWriteType)
            {
                case SLAVE_DATA_ADDRESS:
                    eepromAddress   = I2C1_slaveWriteData;
                    break;


                case SLAVE_NORMAL_DATA:
                default:
                    // the master has written data to store in the eeprom
                    EEPROM_Buffer[eepromAddress++]    = I2C1_slaveWriteData;
                    if(sizeof(EEPROM_Buffer) <= eepromAddress)
                    {
                        eepromAddress = 0;    // wrap to start of eeprom page
                    }
                    break;

            } 

            slaveWriteType  = SLAVE_NORMAL_DATA;
            break;

        case I2C1_SLAVE_READ_REQUEST:
            if (I2C1STAT1bits.TXBE)
            {
                I2C1TXB = EEPROM_Buffer[eepromAddress++];
            }
            if(sizeof(EEPROM_Buffer) <= eepromAddress)
            {
                eepromAddress = 0;    // wrap to start of eeprom page
                
            }
            break;

        case I2C1_SLAVE_READ_COMPLETED:
        default:;

    } // end switch(i2c1_bus_state)

}
