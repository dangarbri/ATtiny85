#include <avr/io.h>
#include <util/delay.h>
#include "my_attiny85.h"

int main(void)
{
    DDRB |= PIN0;  // set PIN 0 as an output
    PORTB |= PIN0; // set PIN 0 output HIGH

    while (1) {
        _delay_ms(500);
        PORTB = TOGGLE_PORT_PIN(PORTB, PIN0);
        _delay_ms(500);
        PORTB = TOGGLE_PORT_PIN(PORTB, PIN0);
    }
}