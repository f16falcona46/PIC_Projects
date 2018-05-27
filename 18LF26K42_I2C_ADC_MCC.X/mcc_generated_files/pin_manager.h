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

// get/set channel_ANA0 aliases
#define channel_ANA0_TRIS                 TRISAbits.TRISA0
#define channel_ANA0_LAT                  LATAbits.LATA0
#define channel_ANA0_PORT                 PORTAbits.RA0
#define channel_ANA0_WPU                  WPUAbits.WPUA0
#define channel_ANA0_OD                   ODCONAbits.ODCA0
#define channel_ANA0_ANS                  ANSELAbits.ANSELA0
#define channel_ANA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_ANA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_ANA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_ANA0_GetValue()           PORTAbits.RA0
#define channel_ANA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_ANA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_ANA0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define channel_ANA0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define channel_ANA0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define channel_ANA0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define channel_ANA0_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define channel_ANA0_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set channel_ANA1 aliases
#define channel_ANA1_TRIS                 TRISAbits.TRISA1
#define channel_ANA1_LAT                  LATAbits.LATA1
#define channel_ANA1_PORT                 PORTAbits.RA1
#define channel_ANA1_WPU                  WPUAbits.WPUA1
#define channel_ANA1_OD                   ODCONAbits.ODCA1
#define channel_ANA1_ANS                  ANSELAbits.ANSELA1
#define channel_ANA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define channel_ANA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define channel_ANA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define channel_ANA1_GetValue()           PORTAbits.RA1
#define channel_ANA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define channel_ANA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define channel_ANA1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define channel_ANA1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define channel_ANA1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define channel_ANA1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define channel_ANA1_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define channel_ANA1_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set channel_ANA2 aliases
#define channel_ANA2_TRIS                 TRISAbits.TRISA2
#define channel_ANA2_LAT                  LATAbits.LATA2
#define channel_ANA2_PORT                 PORTAbits.RA2
#define channel_ANA2_WPU                  WPUAbits.WPUA2
#define channel_ANA2_OD                   ODCONAbits.ODCA2
#define channel_ANA2_ANS                  ANSELAbits.ANSELA2
#define channel_ANA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define channel_ANA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define channel_ANA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define channel_ANA2_GetValue()           PORTAbits.RA2
#define channel_ANA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define channel_ANA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define channel_ANA2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define channel_ANA2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define channel_ANA2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define channel_ANA2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define channel_ANA2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define channel_ANA2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set channel_ANA3 aliases
#define channel_ANA3_TRIS                 TRISAbits.TRISA3
#define channel_ANA3_LAT                  LATAbits.LATA3
#define channel_ANA3_PORT                 PORTAbits.RA3
#define channel_ANA3_WPU                  WPUAbits.WPUA3
#define channel_ANA3_OD                   ODCONAbits.ODCA3
#define channel_ANA3_ANS                  ANSELAbits.ANSELA3
#define channel_ANA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define channel_ANA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define channel_ANA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define channel_ANA3_GetValue()           PORTAbits.RA3
#define channel_ANA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define channel_ANA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define channel_ANA3_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define channel_ANA3_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define channel_ANA3_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define channel_ANA3_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define channel_ANA3_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define channel_ANA3_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set channel_ANA4 aliases
#define channel_ANA4_TRIS                 TRISAbits.TRISA4
#define channel_ANA4_LAT                  LATAbits.LATA4
#define channel_ANA4_PORT                 PORTAbits.RA4
#define channel_ANA4_WPU                  WPUAbits.WPUA4
#define channel_ANA4_OD                   ODCONAbits.ODCA4
#define channel_ANA4_ANS                  ANSELAbits.ANSELA4
#define channel_ANA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define channel_ANA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define channel_ANA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define channel_ANA4_GetValue()           PORTAbits.RA4
#define channel_ANA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define channel_ANA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define channel_ANA4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define channel_ANA4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define channel_ANA4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define channel_ANA4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define channel_ANA4_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define channel_ANA4_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set channel_ANA5 aliases
#define channel_ANA5_TRIS                 TRISAbits.TRISA5
#define channel_ANA5_LAT                  LATAbits.LATA5
#define channel_ANA5_PORT                 PORTAbits.RA5
#define channel_ANA5_WPU                  WPUAbits.WPUA5
#define channel_ANA5_OD                   ODCONAbits.ODCA5
#define channel_ANA5_ANS                  ANSELAbits.ANSELA5
#define channel_ANA5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define channel_ANA5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define channel_ANA5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define channel_ANA5_GetValue()           PORTAbits.RA5
#define channel_ANA5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define channel_ANA5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define channel_ANA5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define channel_ANA5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define channel_ANA5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define channel_ANA5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define channel_ANA5_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define channel_ANA5_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set channel_ANA6 aliases
#define channel_ANA6_TRIS                 TRISAbits.TRISA6
#define channel_ANA6_LAT                  LATAbits.LATA6
#define channel_ANA6_PORT                 PORTAbits.RA6
#define channel_ANA6_WPU                  WPUAbits.WPUA6
#define channel_ANA6_OD                   ODCONAbits.ODCA6
#define channel_ANA6_ANS                  ANSELAbits.ANSELA6
#define channel_ANA6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define channel_ANA6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define channel_ANA6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define channel_ANA6_GetValue()           PORTAbits.RA6
#define channel_ANA6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define channel_ANA6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define channel_ANA6_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define channel_ANA6_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define channel_ANA6_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define channel_ANA6_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define channel_ANA6_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define channel_ANA6_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set channel_ANA7 aliases
#define channel_ANA7_TRIS                 TRISAbits.TRISA7
#define channel_ANA7_LAT                  LATAbits.LATA7
#define channel_ANA7_PORT                 PORTAbits.RA7
#define channel_ANA7_WPU                  WPUAbits.WPUA7
#define channel_ANA7_OD                   ODCONAbits.ODCA7
#define channel_ANA7_ANS                  ANSELAbits.ANSELA7
#define channel_ANA7_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define channel_ANA7_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define channel_ANA7_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define channel_ANA7_GetValue()           PORTAbits.RA7
#define channel_ANA7_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define channel_ANA7_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define channel_ANA7_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define channel_ANA7_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define channel_ANA7_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define channel_ANA7_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define channel_ANA7_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define channel_ANA7_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()               do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()                do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()                do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()       do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()      do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSELC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()               do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()                do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()                do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()       do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()      do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSELC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSELC1 = 0; } while(0)

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




#endif // PIN_MANAGER_H
/**
 End of File
*/