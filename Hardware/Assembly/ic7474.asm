
.include "m328Pdef.inc"

.org 0x00
    rjmp RESET

RESET:
    ; Set Arduino pins as output
    ; D6=PD6 (W), D7=PD7 (X), D8=PB0 (Y), D9=PB1 (Z), D13=PB5 (CLK)
    ldi r16, 0b11000000    ; PD6, PD7 output
    out DDRD, r16
    ldi r16, 0b00100011    ; PB0, PB1, PB5 output
    out DDRB, r16

    ; Init state = 00
    ldi r17, 0x00

MAIN_LOOP:
    ; Load FSM state into outputs
    ; r17 bits: b0=W, b1=X, b2=Y, b3=Z

    ; Write W,X to PD6,PD7
    mov r18, r17
    andi r18, 0b00000011      ; keep bits 0,1
    swap r18                  ; shift to upper bits
    lsl r18                   ; align to PD6,PD7
    out PORTD, r18

    ; Write Y,Z to PB0,PB1
    mov r18, r17
    lsr r18
    lsr r18                   ; align to PB0,PB1
    out PORTB, r18

    ; Generate CLK pulse on PB5
    sbi PORTB, 5
    cbi PORTB, 5

    ; Next state (mod 4 counter)
    inc r17
    andi r17, 0x03            ; keep only 2 bits

    rjmp MAIN_LOOP
