#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include "common_ops.h"

/**
 * The range of errors used for calibration
 */
const int8_t CALIBRATION_MIN = -12;
const int8_t CALIBRATION_MAX = -5;

/**
 * Controls where data will be written.
 */
static uint8_t s_pin;
/**
 * Delay amount, generated from baud rate given in
 * UART_Initialize
 */
static uint16_t s_delay;

void UART_SendByte(uint8_t byte)
{
    register uint8_t pin = s_pin;
    register uint16_t delay = s_delay;

    cli(); // disable interrupts for time sensitive routine

    // Set pin low to initiate transfer
    SET_LOW(PORTB, pin);

    _delay_loop_2(delay);

    // Write each of the 8 bits
    for (uint8_t i = 0; i < 8; i++)
    {
        SET_BIT(PORTB, pin, (byte & 1));
        _delay_loop_2(delay);
        byte >>= 1;
    }

    SET_HIGH(PORTB, pin);

    _delay_loop_2(delay);

    // re-enable interrupts
    sei();
}

/**
 * Set output pin and baud rate
 *
 * @param pin - 0-5 for output pin output pin PBX
 * @param baud - baud rate for transmission
 */
void UART_Initialize(uint8_t pin, uint32_t baud, int8_t error)
{
    // Set pin as output pin
    SET_BIT(DDRB, pin, 1);

    // ATTiny85 only has PORTB, so we don't need
    // to specify anymore than the pin
    s_pin = pin;

    /**
     * _delay_loop_2 executes 4 cpu cycles per loop.
     * # of CPU clocks need to be delayed per bit is F_CPU / 9600.
     * Divide by 4 to get appropriate # of loops for _delay_loop_2.
     *
     * Extra "error" modification accounts for function additional overhead caused
     * by delay and programming pins (I'm not sure why this is needed... but
     * it doesn't work without it...)"
     *
     * Overall, software driven timings like this seem bad.
     */
    s_delay = ((F_CPU / baud) / 4) + error;

    // Also I can't move this calculation to a different function,
    // not sure why it causes problems when trying to send a byte...
    // s_delay = UART_CalculateBitDelay(baud, error);
}

/**
 * Print line through uart transmitter
 *
 * @param string - Null terminated string to write to uart
 */
void UART_Print(char *string)
{
    while (*string != '\0')
    {
        UART_SendByte(*string);
        string++;
    }
}

/**
 * Used to detect the proper "error" to supply
 * to UART_Initialize.
 *
 * This should run in a separate program to find the appropriate error.
 * Then in the proper program, the found error can be used.
 */
void UART_Calibrate(uint8_t pin, uint32_t baud)
{
    char num_buffer[4];

    for (int8_t error = CALIBRATION_MIN; error <= CALIBRATION_MAX; error++)
    {
        // Setup UART metadata
        UART_Initialize(pin, baud, error);

        // Print test message to "flush" uart
        UART_Print("Testing\r\n");
        // Allow adequate time to hold transfer pin high
        _delay_ms(100);
        // Get current error as a string and store in num_buf
        itoa(error, num_buffer, 10);

        // Print through UART with current error rate.
        UART_Print("Current error is: ");
        UART_Print(num_buffer);
        UART_Print("\r\n");
        _delay_ms(100);
    }
}
