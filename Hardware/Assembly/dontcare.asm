.include "m328Pdef.inc"

.def temp = r16
.def x = r17
.def y = r18
.def z = r19
.def F = r20

.cseg
.org 0x00
rjmp RESET

RESET:
    ldi temp, 0b00011100     ; PD2,PD3,PD4 = inputs
    out DDRD, temp           ; PD5,PD6,PD7 = outputs
    ldi temp, 0b00000001     ; PB0 = output
    out DDRB, temp

MAIN:
    in temp, PIND            ; read input port
    mov x, temp
    lsr x                    ; shift PD2 into bit0
    lsr x
    andi x, 0x01

    mov y, temp
    lsr y
    lsr y
    lsr y                    ; PD3 into bit0
    andi y, 0x01

    mov z, temp
    lsr z
    lsr z
    lsr z
    lsr z                    ; PD4 into bit0
    andi z, 0x01

    ; F = Y + (!X * Z)
    com x
    andi x, 0x01
    mov F, x
    and F, z
    or  F, y

    ; send F to BCD outputs
    cpi F, 0
    breq DISP0

DISP1:
    sbi PORTD, 5
    cbi PORTD, 6
    cbi PORTD, 7
    cbi PORTB, 0
    rjmp MAIN

DISP0:
    cbi PORTD, 5
    cbi PORTD, 6
    cbi PORTD, 7
    cbi PORTB, 0
    rjmp MAIN
