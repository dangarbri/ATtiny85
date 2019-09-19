/**
 * Basic serial interface for attiny85
 *
 * PINS 5 and 7 are reserved for serial output
 *
 * This is a synchronous implementation. As clock generation
 * needs to be done in software and it is easier to do that
 * synchronously.
 */

#include <stdint.h>

/**
 * Initialize serial interface
 * ATtiny85 supports 2-wire and 3-wire transfer
 * This implementation only supports 2-wire transfer.
 */
void Serial_Initialize(void);

/**
 * Set baud rate for serial transfer
 */
void Serial_SetBaudRate(uint32_t baud_rate);

/**
 * Send string over serial
 *
 * @param[in] string - must be null terminated
 */
void Serial_Write(char *string);
