/**
 * Simple software UART Transmitter
 * for ATTiny85.
 *
 * Receiver not implemented.
 */

#include <stdint.h>

/**
 * Set output pin and baud rate
 *
 * @param pin - 0-5 for output pin output pin PBX
 * @param baud - baud rate for transmission
 * @param error - extra influence on baud rate.
 *                This effects the # of clock cycles to wait between
 *                sending each bit
 */
void UART_Initialize(uint8_t pin, uint16_t baud, uint8_t error);

/**
 * I've noticed there are issues regarding software driven UART
 * and getting a proper baud calculation for the time between shifting
 * output bits.
 *
 * This function loops through several baud rates near the default calculation
 * and prints through UART in order to find the proper baud rate.
 */
void UART_Calibrate(uint8_t pin, uint32_t baud);


/**
 * Print line through uart transmitter
 *
 * @param string - Null terminated string to write to uart
 */
void UART_Print(char *string);

void UART_SendByte(uint8_t byte);