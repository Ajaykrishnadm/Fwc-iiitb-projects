
.include "m328Pdef.inc"

.org 0x00
    rjmp RESET

RESET:
    ; Set pins PD2–PD7 and PB0 (Arduino pins 2–8) as output
    ldi r16, 0b11111100    ; PD2–PD7 = output
    out DDRD, r16
    ldi r16, 0b00000001    ; PB0 = output
    out DDRB, r16

    ; Now write segment values
    ; sevenseg(1,0,0,1,1,1,1)
    ; PD2=a=1, PD3=b=0, PD4=c=0, PD5=d=1, PD6=e=1, PD7=f=1, PB0=g=1

    ; Load PORTD values
    ldi r16, 0b11110100    ; PD7=1, PD6=1, PD5=1, PD4=0, PD3=0, PD2=1
    out PORTD, r16

    ; Load PORTB values
    ldi r16, 0b00000001    ; PB0=1 (g segment)
    out PORTB, r16

LOOP:
    rjmp LOOP              ; infinite loop
