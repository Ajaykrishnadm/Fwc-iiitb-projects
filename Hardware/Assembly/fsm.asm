.include "m328Pdef.inc"

.def temp = r16
.def x = r17
.def y = r18
.def z = r19
.def outval = r20

.cseg
.org 0x00
rjmp RESET

RESET:
    ldi temp, 0x00
    out DDRB, temp
    out DDRD, temp
    ldi temp, 0b00111100
    out DDRD, temp

MAIN:
    in x, PIND
    lsr x
    lsr x
    lsr x
    lsr x
    lsr x
    lsr x
    lsr x
    andi x, 0x01

    in y, PINB
    andi y, 0x01

    in z, PINB
    lsr z
    andi z, 0x01

    clr outval
    mov temp, x
    lsl temp
    lsl temp
    or outval, temp
    mov temp, y
    lsl temp
    or outval, temp
    or outval, z

    ; ---- Swap bit0 and bit1 because orange & white wires interchanged ----
    mov temp, outval
    lsr temp
    andi temp, 0x01
    bst temp, 0

    mov temp, outval
    andi temp, 0x01
    bld outval, 1

    bclr 0
    brts setbit0
    rjmp noset0
setbit0:
    ori outval, 0x01
noset0:

    swap outval
    lsr outval
    lsr outval
    andi outval, 0b00111100
    out PORTD, outval

    rjmp MAIN
