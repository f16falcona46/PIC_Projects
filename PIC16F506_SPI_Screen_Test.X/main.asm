#include <p16f506.inc>

; PIC16F506 Configuration Bit Settings

; Assembly source line config statements

#include "p16f506.inc"

; CONFIG
; __config 0xFB4
 __CONFIG _OSC_IntRC_RB4EN & _WDT_OFF & _CP_OFF & _MCLRE_ON & _IOSCFS_OFF
BANK0        UDATA

GPR_VAR1    UDATA
    subroutine_input		RES 1
    subroutine_input2		RES 1
    subroutine_output		RES 1
    scratch1			RES 1
    scratch2			RES 1
    counter			RES 1
    counter2			RES 1
    num_to_output		RES 1
    char_index			RES 1
GPR_VAR2    UDATA
    stack			RES 0x10

;*******************************************************************************
; Reset Vector
;*******************************************************************************

RES_VECT  CODE    0x0000            ; processor reset vector
    GOTO    START                   ; go to beginning of program


;PIN DEFINITIONS FOR BIT-BANG SPI
NSS	EQU	0
SCK	EQU	1
MISO	EQU	2
MOSI	EQU	3

LCD_DC	EQU	4
LCD_RST	EQU	5

ShiftOut    MACRO   byte
    MOVLW byte
    MOVWF subroutine_input
    CALL SHIFTOUT_M
ENDM

MAIN_PROG CODE                      ; let linker place main program
    
;inputs: subroutine_input (the char), subroutine_input2 (the index in the char)
CHARTABLE_NUMS
    MOVFW subroutine_input
    ADDWF PCL, F
    GOTO CHARTABLE_NUMS0
    GOTO CHARTABLE_NUMS1
    GOTO CHARTABLE_NUMS2
    GOTO CHARTABLE_NUMS3
    GOTO CHARTABLE_NUMS4
    GOTO CHARTABLE_NUMS5
    GOTO CHARTABLE_NUMS6
    GOTO CHARTABLE_NUMS7
    GOTO CHARTABLE_NUMS8
    GOTO CHARTABLE_NUMS9
    GOTO CHARTABLE_NUMSa
    GOTO CHARTABLE_NUMSb
    GOTO CHARTABLE_NUMSc
    GOTO CHARTABLE_NUMSd
    GOTO CHARTABLE_NUMSe
    GOTO CHARTABLE_NUMSf
    
CHARTABLE_NUMS0
    MOVFW subroutine_input2
    ADDWF PCL, F
    RETLW 0x00
    RETLW 0x3e
    RETLW 0x51
    RETLW 0x49
    RETLW 0x45
    RETLW 0x3e
CHARTABLE_NUMS1
    MOVFW subroutine_input2
    ADDWF PCL, F
    RETLW 0x00
    RETLW 0x00
    RETLW 0x42
    RETLW 0x7f
    RETLW 0x40
    RETLW 0x00
CHARTABLE_NUMS2
    MOVFW subroutine_input2
    ADDWF PCL, F
    RETLW 0x00
    RETLW 0x62
    RETLW 0x51
    RETLW 0x49
    RETLW 0x49
    RETLW 0x46
CHARTABLE_NUMS3
    MOVFW subroutine_input2
    ADDWF PCL, F
    RETLW 0x00
    RETLW 0x22
    RETLW 0x49
    RETLW 0x49
    RETLW 0x49
    RETLW 0x36
CHARTABLE_NUMS4
    MOVFW subroutine_input2
    ADDWF PCL, F
    RETLW 0x00
    RETLW 0x18
    RETLW 0x14
    RETLW 0x12
    RETLW 0x7f
    RETLW 0x10
CHARTABLE_NUMS5
    MOVFW subroutine_input2
    ADDWF PCL, F
    RETLW 0x00
    RETLW 0x2f
    RETLW 0x49
    RETLW 0x49
    RETLW 0x49
    RETLW 0x31
CHARTABLE_NUMS6
    MOVFW subroutine_input2
    ADDWF PCL, F
    RETLW 0x00
    RETLW 0x3c
    RETLW 0x4a
    RETLW 0x49
    RETLW 0x49
    RETLW 0x30
CHARTABLE_NUMS7
    MOVFW subroutine_input2
    ADDWF PCL, F
    RETLW 0x00
    RETLW 0x01
    RETLW 0x71
    RETLW 0x09
    RETLW 0x05
    RETLW 0x03
CHARTABLE_NUMS8
    MOVFW subroutine_input2
    ADDWF PCL, F
    RETLW 0x00
    RETLW 0x36
    RETLW 0x49
    RETLW 0x49
    RETLW 0x49
    RETLW 0x36
CHARTABLE_NUMS9
    MOVFW subroutine_input2
    ADDWF PCL, F
    RETLW 0x00
    RETLW 0x06
    RETLW 0x49
    RETLW 0x49
    RETLW 0x29
    RETLW 0x1e
CHARTABLE_NUMSa
    MOVFW subroutine_input2
    ADDWF PCL, F
    RETLW 0x00
    RETLW 0x20
    RETLW 0x54
    RETLW 0x54
    RETLW 0x54
    RETLW 0x78
CHARTABLE_NUMSb
    MOVFW subroutine_input2
    ADDWF PCL, F
    RETLW 0x00
    RETLW 0x7f
    RETLW 0x44
    RETLW 0x44
    RETLW 0x44
    RETLW 0x38
CHARTABLE_NUMSc
    MOVFW subroutine_input2
    ADDWF PCL, F
    RETLW 0x00
    RETLW 0x38
    RETLW 0x44
    RETLW 0x44
    RETLW 0x44
    RETLW 0x28
CHARTABLE_NUMSd
    MOVFW subroutine_input2
    ADDWF PCL, F
    RETLW 0x00
    RETLW 0x38
    RETLW 0x44
    RETLW 0x44
    RETLW 0x44
    RETLW 0x7f
CHARTABLE_NUMSe
    MOVFW subroutine_input2
    ADDWF PCL, F
    RETLW 0x00
    RETLW 0x38
    RETLW 0x54
    RETLW 0x54
    RETLW 0x54
    RETLW 0x08
CHARTABLE_NUMSf
    MOVFW subroutine_input2
    ADDWF PCL, F
    RETLW 0x00
    RETLW 0x08
    RETLW 0x7e
    RETLW 0x09
    RETLW 0x09
    RETLW 0x00

;jump table
PAUSE
    GOTO PAUSE_IMPL
SHIFTOUT_M
    GOTO SHIFTOUT_M_IMPL
MUL_SW
    GOTO MUL_SW_IMPL
    
PAUSE_IMPL
    MOVWF counter
PAUSE_LOOP
    CLRF counter2
PAUSE_FAST
    DECF counter2
    BTFSS STATUS, Z
    GOTO PAUSE_FAST
    DECF counter
    BTFSS STATUS, Z
    GOTO PAUSE_LOOP
    
    RETLW 0x00

;   C0: CS
;   C1: SCK
;   C2: MISO
;   C3: MOSI

;   IN: subroutine_input, destroyed
;   OUT: subroutine_output: the byte shifted in (not implemented yet)
SHIFTBIT_M MACRO reg_shiftout, reg_shiftin
    RLF reg_shiftout, F
    BTFSC STATUS, C
    BSF PORTC, MOSI
    BTFSS STATUS, C
    BCF PORTC, MOSI
    NOP
    BSF PORTC, SCK
    BTFSC PORTC, MISO
    BSF STATUS, C
    BTFSS PORTC, MISO
    BCF STATUS, C
    RLF reg_shiftin, F
    BCF PORTC, SCK
ENDM
SHIFTOUT_M_IMPL
    CLRF subroutine_output
    SHIFTBIT_M subroutine_input, subroutine_output
    SHIFTBIT_M subroutine_input, subroutine_output
    SHIFTBIT_M subroutine_input, subroutine_output
    SHIFTBIT_M subroutine_input, subroutine_output
    SHIFTBIT_M subroutine_input, subroutine_output
    SHIFTBIT_M subroutine_input, subroutine_output
    SHIFTBIT_M subroutine_input, subroutine_output
    SHIFTBIT_M subroutine_input, subroutine_output
    RETLW 0x00
    
MUL_SW_IMPL
    MOVLW 0x00
    RRF subroutine_input2
    BTFSC STATUS, C
    ADDWF subroutine_input, W
    RLF subroutine_input
    RRF subroutine_input2
    BTFSC STATUS, C
    ADDWF subroutine_input, W
    RLF subroutine_input
    RRF subroutine_input2
    BTFSC STATUS, C
    ADDWF subroutine_input, W
    RLF subroutine_input
    RRF subroutine_input2
    BTFSC STATUS, C
    ADDWF subroutine_input, W
    RLF subroutine_input
    RRF subroutine_input2
    BTFSC STATUS, C
    ADDWF subroutine_input, W
    RLF subroutine_input
    RRF subroutine_input2
    BTFSC STATUS, C
    ADDWF subroutine_input, W
    RLF subroutine_input
    RRF subroutine_input2
    BTFSC STATUS, C
    ADDWF subroutine_input, W
    RLF subroutine_input
    RRF subroutine_input2
    BTFSC STATUS, C
    ADDWF subroutine_input, W
    MOVWF subroutine_output
    RETLW 0x00
    
START
    MOVWF OSCCAL
    BANKSEL subroutine_input
    
    MOVLW 0xff
    TRIS PORTB
    MOVLW b'11000100'
    TRIS PORTC
    BSF PORTC, NSS
    BCF PORTC, LCD_RST
    
    MOVLW b'10010111'
    OPTION
    MOVLW b'11110111'
    MOVWF CM1CON0
    MOVWF CM2CON0
    
    MOVLW 0xff
    CALL PAUSE
    
    BSF PORTC, LCD_RST
    BCF PORTC, LCD_DC
    BCF PORTC, NSS
    ShiftOut 0x23	; PD=0, Vertical, Extended
    ShiftOut 0x13	; set bias
    ShiftOut 0xC7	; set VOp (BE for newer one, C7 for the older one)
    ShiftOut 0x22	; Power Down disabled, Vertical mode, basic instruction set
    ShiftOut 0x0C	; NORMAL display mode
    ShiftOut 0x40	; set Y addr = 0
    ShiftOut 0x80	; set X addr = 0
    BSF PORTC, NSS
    
    MOVLW 0x83
    MOVWF counter
    MOVLW 0x5
    MOVWF counter2
    BSF PORTC, LCD_DC
    BCF PORTC, NSS
CLEARSCREEN_LOOP_Y
CLEARSCREEN_LOOP_X
    ShiftOut 0x00
    DECF counter, F
    BTFSS STATUS, Z
    GOTO CLEARSCREEN_LOOP_X
    DECF counter2, F
    BTFSS STATUS, Z
    GOTO CLEARSCREEN_LOOP_Y

    CLRF counter2
LOOP
    CLRF counter
PRINT_2_LOOP
    BCF PORTC, LCD_DC
    BCF PORTC, NSS
    ShiftOut b'01000000'
    MOVFW counter2
    MOVWF subroutine_input
    MOVLW 0x06
    MOVWF subroutine_input2
    CALL MUL_SW
    MOVLW b'10000000'
    ADDWF subroutine_output, W
    ADDWF counter, W
    MOVWF subroutine_input
    CALL SHIFTOUT_M
    
    BSF PORTC, LCD_DC
    MOVFW counter2
    MOVWF subroutine_input
    MOVFW counter
    MOVWF subroutine_input2
    CALL CHARTABLE_NUMS
    MOVWF subroutine_input
    CALL SHIFTOUT_M
    INCF counter, F
    MOVLW 0x06
    SUBWF counter, W
    BTFSS STATUS, Z
    GOTO PRINT_2_LOOP
    BSF PORTC, NSS
    
    INCF counter2, F
    MOVLW 0x10
    SUBWF counter2, W
    MOVLW 0x00
    BTFSC STATUS, Z
    MOVWF counter2
    
    GOTO LOOP
    
    END