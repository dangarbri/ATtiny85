/**
 * Collection of common non-platform-specific
 * operations.
 */

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

#define GEN_BIT(bit) (1 << (bit))

/**
 * Macro for setting a pin low
 */
#define SET_LOW(port, pin) (port &= ~(GEN_BIT(pin)))
#define SET_HIGH(port, pin) (port |= (GEN_BIT(pin)))

/**
 * Macro for setting a specific bit
 */
#define SET_BIT(port, offset, value) (port = (port & ~(GEN_BIT(offset))) | (value << offset))