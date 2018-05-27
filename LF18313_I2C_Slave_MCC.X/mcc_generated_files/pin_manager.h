/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16LF18313
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SCL1 aliases
#define SCL1_TRIS                 TRISAbits.TRISA4
#define SCL1_LAT                  LATAbits.LATA4
#define SCL1_PORT                 PORTAbits.RA4
#define SCL1_WPU                  WPUAbits.WPUA4
#define SCL1_OD                   ODCONAbits.ODCA4
#define SCL1_ANS                  ANSELAbits.ANSA4
#define SCL1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define SCL1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define SCL1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define SCL1_GetValue()           PORTAbits.RA4
#define SCL1_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define SCL1_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define SCL1_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define SCL1_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define SCL1_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define SCL1_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define SCL1_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set SDA1 aliases
#define SDA1_TRIS                 TRISAbits.TRISA5
#define SDA1_LAT                  LATAbits.LATA5
#define SDA1_PORT                 PORTAbits.RA5
#define SDA1_WPU                  WPUAbits.WPUA5
#define SDA1_OD                   ODCONAbits.ODCA5
#define SDA1_ANS                  ANSELAbits.ANSA5
#define SDA1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SDA1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SDA1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SDA1_GetValue()           PORTAbits.RA5
#define SDA1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SDA1_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define SDA1_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define SDA1_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define SDA1_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define SDA1_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define SDA1_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/