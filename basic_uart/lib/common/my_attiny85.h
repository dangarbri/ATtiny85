/**
 * Mini library for assisting with programming
 * the attiny85 using avr-libc
 */

/**
 * Toggles a pin bit in the given port.
 *
 * @param[in] port_val - PORTX
 * @param[in] pin - pin to toggle, PINX
 */
#define TOGGLE_PORT_PIN(port_val, pin) (port_val ^ (1 << pin))