#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // Set PB5 (Arduino digital pin 13) as output
    DDRB |= (1 << PB5);

    while(1) {
        // Set PB5 high
        PORTB |= (1 << PB5);
        _delay_ms(1000);

        // Set PB5 low
        PORTB &= ~(1 << PB5);
        _delay_ms(1000);
    }
    return 0;
}
