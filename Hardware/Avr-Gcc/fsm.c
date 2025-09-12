#include <avr/io.h>
#include <util/delay.h>

#define D1_PIN    PD2
#define CLK1_PIN  PD3
#define D2_PIN    PD4
#define CLK2_PIN  PD5
#define CLEAR_PIN PD6
#define BTN_PIN   PD7

#define SET_PIN(port, pin)     (port |= (1 << pin))
#define CLR_PIN(port, pin)     (port &= ~(1 << pin))

typedef enum {
    STATE_0, STATE_1, STATE_2, STATE_3, STATE_4,
    STATE_5, STATE_6, STATE_7, STATE_8, STATE_9
} CounterState;

void pulseClock(uint8_t clkPin) {
    SET_PIN(PORTD, clkPin);
    _delay_us(5);
    CLR_PIN(PORTD, clkPin);
    _delay_us(5);
}

void clearCounter() {
    CLR_PIN(PORTD, CLEAR_PIN);
    _delay_us(10);
    SET_PIN(PORTD, CLEAR_PIN);
}

int main(void) {
    DDRD |= (1 << D1_PIN) | (1 << D2_PIN) | (1 << CLK1_PIN) | (1 << CLK2_PIN) | (1 << CLEAR_PIN);
    DDRD &= ~(1 << BTN_PIN);
    PORTD |= (1 << BTN_PIN);

    CounterState state = STATE_0;
    clearCounter();

    while (1) {
        switch (state) {
            case STATE_0:
                CLR_PIN(PORTD, D1_PIN); CLR_PIN(PORTD, D2_PIN);
                break;
            case STATE_1:
                SET_PIN(PORTD, D1_PIN); CLR_PIN(PORTD, D2_PIN);
                break;
            case STATE_2:
                CLR_PIN(PORTD, D1_PIN); SET_PIN(PORTD, D2_PIN);
                break;
            case STATE_3:
                SET_PIN(PORTD, D1_PIN); SET_PIN(PORTD, D2_PIN);
                break;
            case STATE_4:
                CLR_PIN(PORTD, D1_PIN); CLR_PIN(PORTD, D2_PIN);
                break;
            case STATE_5:
                SET_PIN(PORTD, D1_PIN); CLR_PIN(PORTD, D2_PIN);
                break;
            case STATE_6:
                CLR_PIN(PORTD, D1_PIN); SET_PIN(PORTD, D2_PIN);
                break;
            case STATE_7:
                SET_PIN(PORTD, D1_PIN); SET_PIN(PORTD, D2_PIN);
                break;
            case STATE_8:
                CLR_PIN(PORTD, D1_PIN); CLR_PIN(PORTD, D2_PIN);
                break;
            case STATE_9:
                SET_PIN(PORTD, D1_PIN); CLR_PIN(PORTD, D2_PIN);
                break;
        }

        pulseClock(CLK1_PIN);
        pulseClock(CLK2_PIN);

        _delay_ms(1000);

        if (state == STATE_9) state = STATE_0;
        else state++;
    }
}
