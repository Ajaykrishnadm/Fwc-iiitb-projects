#include <avr/io.h>
#define F_CPU 16000000UL   // 16 MHz CPU frequency for Arduino UNO
#include <util/delay.h>

int main(void) {
    // Set PD2..PD5 as outputs (7447 inputs A-D)
    DDRD |= (1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5);

    while (1) {
        for (uint8_t num = 0; num < 10; num++) {
            // Send lower 4 bits of num to PD2..PD5
            if (num & 0x01) PORTD |=  (1 << PD2); else PORTD &= ~(1 << PD2); // A
            if (num & 0x02) PORTD |=  (1 << PD3); else PORTD &= ~(1 << PD3); // B
            if (num & 0x04) PORTD |=  (1 << PD4); else PORTD &= ~(1 << PD4); // C
            if (num & 0x08) PORTD |=  (1 << PD5); else PORTD &= ~(1 << PD5); // D

            _delay_ms(1000); // Show digit for 1 second
        }
    }
}
