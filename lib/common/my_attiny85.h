/**
 * Mini library for assisting with programming
 * the attiny85 using avr-libc
 */


/**
 * Define bits for pins for easier referencing
 */
#define PIN0 0b000001
#define PIN1 0b000010
#define PIN2 0b000100
#define PIN3 0b001000
#define PIN4 0b010000
#define PIN5 0b100000

/**
 * Toggles a pin bit in the given port.
 */
#define TOGGLE_PORT_PIN(port_val, pin) (port_val ^ pin)