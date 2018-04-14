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
    
    MOVLW b'11000000'
    TRIS PORTC
    TRIS PORTB
    MOVLW b'00111111'
    MOVWF PORTB
    MOVWF PORTC
    
    MOVLW b'10010111'
    OPTION
    MOVLW b'11110111'
    MOVWF CM1CON0
    MOVWF CM2CON0
    MOVLW b'00110000'
    MOVWF ADCON0
    
    ;BSF PORTB, 2
    
LOOP
    MOVLW b'00111111'
    MOVWF PORTB
    MOVWF PORTC
    
    MOVLW 0xff
    MOVWF counter_slow_0
LOOP_H
    MOVLW 0xff
    MOVWF counter_fast_0
    MOVLW 0x01
LOOP_FAST_H
    SUBWF counter_fast_0, F
    BTFSS STATUS, Z
    GOTO LOOP_FAST_H
    SUBWF counter_slow_0, F
    BTFSS STATUS, Z
    GOTO LOOP_H
    
    MOVLW b'00000000'
    MOVWF PORTB
    MOVWF PORTC
    
    MOVLW 0xff
    MOVWF counter_slow_0
LOOP_L
    MOVLW 0xff
    MOVWF counter_fast_0
    MOVLW 0x01
LOOP_FAST_L
    SUBWF counter_fast_0, F
    BTFSS STATUS, Z
    GOTO LOOP_FAST_L
    SUBWF counter_slow_0, F
    BTFSS STATUS, Z
    GOTO LOOP_L
    
    GOTO LOOP
    END