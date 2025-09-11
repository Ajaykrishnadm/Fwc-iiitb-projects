#define F_CPU 16000000UL   // 16 MHz for ATmega328P

#include <avr/io.h>
#include <util/delay.h>

// Clock output pin (Arduino D6 → PD6)
#define CLOCK_PIN PD6

int main(void) {
    // Set clock pin as output
    DDRD |= (1 << CLOCK_PIN);

    while (1) {
        // Clock HIGH
        PORTD |= (1 << CLOCK_PIN);
        _delay_ms(500);

        // Clock LOW
        PORTD &= ~(1 << CLOCK_PIN);
        _delay_ms(500);
    }
}
