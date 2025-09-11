#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void) {
    // Segments a–g connected to PORTB0..PORTB6
    DDRB = 0x7F;  // PB0–PB6 outputs

    // Test 0–9
    while (1) {
        for (uint8_t num = 0; num < 10; num++) {
            uint8_t A = (num >> 3) & 1;
            uint8_t B = (num >> 2) & 1;
            uint8_t C = (num >> 1) & 1;
            uint8_t D = (num >> 0) & 1;

            uint8_t seg_a = A | C | (B ^ D);
            uint8_t seg_b = (!B) | (!C) | (A ^ D);
            uint8_t seg_c = B | (!C) | (!D);
            uint8_t seg_d = A | (!C) | (B ^ D);
            uint8_t seg_e = (!C) | (B ^ D);
            uint8_t seg_f = A | (!B) | (C ^ D);
            uint8_t seg_g = A | (B ^ C) | (C ^ D);

            // Combine bits into one byte (PB0=a, PB1=b, ... PB6=g)
            uint8_t pattern = (seg_a << 0) |
                              (seg_b << 1) |
                              (seg_c << 2) |
                              (seg_d << 3) |
                              (seg_e << 4) |
                              (seg_f << 5) |
                              (seg_g << 6);

            PORTB = pattern;

            _delay_ms(1000);
        }
    }
}
