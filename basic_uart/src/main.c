#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "common_ops.h"
#include "uart.h"
#include "my_attiny85.h"

#define PIN4_UART_ERROR (-8)

int main()
{
    DDRB = 0xFF;
    // PORTB = 0xFF;
    // char number[4];
    // UART_Initialize(4, 9600, PIN4_UART_ERROR);

    // UART_Calibrate(4, 9600);

    while (1)
    {
      _delay_ms(1000);
      // // Calibrate UART
      // UART_Print("Error is: ");
      // itoa(error, number, 10);
      // UART_Print(number);
      // UART_Print("\r\n");
      // UART_Print("Hello World\r\n");

      // error++;

      // UART_Print("Hello World!\r\n");
      // UART_SendByte('A');
    }
}