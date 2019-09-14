#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0xFF;
    PORTB = 0XFF;

    while (1) {
        _delay_ms(500);
        PORTB = 0;
        _delay_ms(500);
        PORTB = 0xFF;
    }
}