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
    ldi temp, 0b00011100     ; PD2..PD4 inputs
    out DDRD, temp           ; PD5..PD7 outputs
    ldi temp, 0b00000001     ; PB0 output
    out DDRB, temp

MAIN:
    in temp, PIND
    mov x, temp
    lsr x
    lsr x
    andi x, 0x01

    mov y, temp
    lsr y
    lsr y
    lsr y
    andi y, 0x01

    mov z, temp
    lsr z
    lsr z
    lsr z
    lsr z
    andi z, 0x01

    clr F

    ; m0 = X' Y' Z'
    com x
    andi x,0x01
    com y
    andi y,0x01
    com z
    andi z,0x01
    mov temp,x
    and temp,y
    and temp,z
    or F,temp

    ; restore x,y,z from inputs
    in temp,PIND
    mov x,temp
    lsr x
    lsr x
    andi x,0x01
    mov y,temp
    lsr y
    lsr y
    lsr y
    andi y,0x01
    mov z,temp
    lsr z
    lsr z
    lsr z
    lsr z
    andi z,0x01

    ; m1 = X' Y' Z
    com x
    andi x,0x01
    com y
    andi y,0x01
    mov temp,x
    and temp,y
    and temp,z
    or F,temp

    ; m2 = X' Y Z'
    in temp,PIND
    mov x,temp
    lsr x
    lsr x
    andi x,0x01
    mov y,temp
    lsr y
    lsr y
    lsr y
    andi y,0x01
    mov z,temp
    lsr z
    lsr z
    lsr z
    lsr z
    andi z,0x01

    com x
    andi x,0x01
    mov temp,x
    and temp,y
    com z
    andi z,0x01
    and temp,z
    or F,temp

    ; m3 = X' Y Z
    in temp,PIND
    mov x,temp
    lsr x
    lsr x
    andi x,0x01
    mov y,temp
    lsr y
    lsr y
    lsr y
    andi y,0x01
    mov z,temp
    lsr z
    lsr z
    lsr z
    lsr z
    andi z,0x01

    com x
    andi x,0x01
    mov temp,x
    and temp,y
    and temp,z
    or F,temp

    ; m7 = X Y Z
    in temp,PIND
    mov x,temp
    lsr x
    lsr x
    andi x,0x01
    mov y,temp
    lsr y
    lsr y
    lsr y
    andi y,0x01
    mov z,temp
    lsr z
    lsr z
    lsr z
    lsr z
    andi z,0x01

    mov temp,x
    and temp,y
    and temp,z
    or F,temp

    ; Output to 7447
    cpi F,0
    breq DISP0

DISP1:
    sbi PORTD,5
    cbi PORTD,6
    cbi PORTD,7
    cbi PORTB,0
    rjmp MAIN

DISP0:
    cbi PORTD,5
    cbi PORTD,6
    cbi PORTD,7
    cbi PORTB,0
    rjmp MAIN
