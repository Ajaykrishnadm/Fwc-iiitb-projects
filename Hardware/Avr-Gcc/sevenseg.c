#define F_CPU 16000000UL   // 16 MHz for Arduino Uno
#include <avr/io.h>
#include <util/delay.h>


void sevenseg(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g) {
    // Set or clear each segment pin (PD2 to PD8)
    if (a) PORTD |= (1 << PD2); else PORTD &= ~(1 << PD2);
    if (b) PORTD |= (1 << PD3); else PORTD &= ~(1 << PD3);
    if (c) PORTD |= (1 << PD4); else PORTD &= ~(1 << PD4);
    if (d) PORTD |= (1 << PD5); else PORTD &= ~(1 << PD5);
    if (e) PORTD |= (1 << PD6); else PORTD &= ~(1 << PD6);
    if (f) PORTD |= (1 << PD7); else PORTD &= ~(1 << PD7);
    // For segment g, use PB0 since PD8 doesn't exist; Arduino digital pin 8 maps to PB0
    if (g) PORTB |= (1 << PB0); else PORTB &= ~(1 << PB0);
}

int main(void) {
    // Set PD2-PD7 as outputs
    DDRD |= (1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5) | (1 << PD6) | (1 << PD7);
    // Set PB0 as output (Arduino pin 8)
    DDRB |= (1 << PB0);

    while(1) {
        sevenseg(1, 0, 0, 1, 1, 1, 1);
        // Add any delay or other logic as needed
    }

    return 0;
}
