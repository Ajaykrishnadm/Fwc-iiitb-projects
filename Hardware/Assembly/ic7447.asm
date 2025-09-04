; === Setup ===
; Arduino Uno pins:
; D2 -> PD2 (7447 A)
; D3 -> PD3 (7447 B)
; D4 -> PD4 (7447 C)
; D5 -> PD5 (7447 D)

.include "m328Pdef.inc"

.org 0x00
rjmp RESET              ; Reset vector

RESET:
    ; Set PORTD2–PORTD5 as output
    ldi r16, 0b00111100 ; binary for bits PD2..PD5 = 1 (output)
    out DDRD, r16

    ldi r17, 0          ; counter variable (num = 0)

MAIN_LOOP:
    ; Output number to PORTD (shifted to PD2–PD5)
    mov r18, r17        ; copy counter
    lsl r18             ; shift left by 2 (align with PD2–PD5)
    out PORTD, r18

    ; Delay ~1 second
    rcall DELAY_1S

    ; Increment counter
    inc r17
    cpi r17, 10         ; compare with 10
    brlt MAIN_LOOP      ; if < 10, continue
    ldi r17, 0          ; reset to 0
    rjmp MAIN_LOOP

; === Delay Subroutine (approx 1 second @ 16MHz) ===
; Simple software loop
DELAY_1S:
    ldi r19, 100
DELAY_LOOP1:
    ldi r20, 200
DELAY_LOOP2:
    ldi r21, 200
DELAY_LOOP3:
    dec r21
    brne DELAY_LOOP3
    dec r20
    brne DELAY_LOOP2
    dec r19
    brne DELAY_LOOP1
    ret
