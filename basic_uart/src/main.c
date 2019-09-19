#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "common_ops.h"
#include "uart.h"
#include "my_attiny85.h"

/**
 * Baud error needed to make UART work
 */
#define PIN4_UART_ERROR (-8)
#define BAUD_RATE 9600
#define UART_PIN 4

int main()
{
    UART_Initialize(UART_PIN, BAUD_RATE, PIN4_UART_ERROR);

    // UART_Calibrate(4, 9600);

    while (1)
    {
      _delay_ms(1000);
      UART_Print("Hello World\r\n");
    }
}