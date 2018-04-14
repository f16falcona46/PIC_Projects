#include <p16f506.inc>

; PIC16F506 Configuration Bit Settings

; Assembly source line config statements

#include "p16f506.inc"

; CONFIG
; __config 0xFB4
 __CONFIG _OSC_IntRC_RB4EN & _WDT_OFF & _CP_OFF & _MCLRE_ON & _IOSCFS_OFF


CBLOCK 0x10
 counter_fast_0
 counter_slow_0
 adc_reading_0
 adc_complementary_reading_0
ENDC
CBLOCK 0x30
 counter1_1
ENDC

;*******************************************************************************
; Reset Vector
;*******************************************************************************

RES_VECT  CODE    0x0000            ; processor reset vector
    GOTO    START                   ; go to beginning of program


MAIN_PROG CODE                      ; let linker place main program

START

    ; TODO Step #5 - Insert Your Program Here
    BANKSEL 0
    
    MOVLW b'11000100'
    TRIS PORTC
    TRIS PORTB
    MOVLW b'00111011'
    MOVWF PORTB
    MOVWF PORTC
    
    MOVLW b'10010111'
    OPTION
    MOVLW b'11110111'
    MOVWF CM1CON0
    MOVWF CM2CON0
    MOVLW b'01111001'
    MOVWF ADCON0
    BSF ADCON0, GO
    
    ;BSF PORTB, 2
    
LOOP
    MOVLW 0x00
    MOVWF adc_complementary_reading_0
WAIT_FOR_ADC
    BTFSC ADCON0, GO_NOT_DONE
    GOTO WAIT_FOR_ADC
    MOVFW ADRES
    MOVWF adc_reading_0
    BSF ADCON0, GO
    
    MOVLW 0x01
    ADDWF adc_reading_0, F
    MOVFW adc_reading_0
    SUBWF adc_complementary_reading_0, F
    
    MOVLW 0x1f
    MOVWF counter_slow_0
LOOP_SLOW
    
    MOVLW b'00111011'
    MOVWF PORTB
    MOVWF PORTC
    MOVFW adc_reading_0
    MOVWF counter_fast_0
    MOVLW 0x01
LOOP_FAST_H
    SUBWF counter_fast_0, F
    BTFSS STATUS, Z
    GOTO LOOP_FAST_H
    
    MOVLW b'00000000'
    MOVWF PORTB
    MOVWF PORTC
    MOVFW adc_complementary_reading_0
    MOVWF counter_fast_0
    MOVLW 0x01
LOOP_FAST_L
    SUBWF counter_fast_0, F
    BTFSS STATUS, Z
    GOTO LOOP_FAST_L
    
    SUBWF counter_slow_0, F
    BTFSS STATUS, Z
    GOTO LOOP_SLOW
    
    GOTO LOOP
    END