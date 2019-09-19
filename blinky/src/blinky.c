#include <avr/io.h>
#include <util/delay.h>
#include "my_attiny85.h"

int main(void)
{
    DDRB |= 1;  // set PIN 0 as an output

    while (1) {
        _delay_ms(500);
        PORTB = TOGGLE_PORT_PIN(PORTB, PIN0);
        _delay_ms(500);
        PORTB = TOGGLE_PORT_PIN(PORTB, PIN0);
    }
}