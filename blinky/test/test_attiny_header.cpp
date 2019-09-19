#include <stdint.h>
#include <unity.h>
#include "common_ops.h"
#include "my_attiny85.h"

void test_toggle_pin(void) {
    struct TestCase {
        uint8_t port_val;
        uint8_t pin;
        uint8_t expected_val;
    };

    struct TestCase test_cases[] = {
        // Test cases to set all pins low and high individually
        {0xFF, 0, 0xFE},
        {0xFE, 0, 0xFF},
        {0xFF, 1, 0xFD},
        {0xFD, 1, 0xFF},
        {0xFF, 2, 0xFB},
        {0xFB, 2, 0xFF},
        {0xFF, 3, 0xF7},
        {0xF7, 3, 0xFF},
        {0xFF, 4, 0xEF},
        {0xEF, 4, 0xFF},
        {0xFF, 5, 0xDF},
        {0xDF, 5, 0xFF},
        // and a case for setting a pin with all other bits at 0
        {0x00, 0, 0x01}
    };

    for (int i = 0; i < ARRAY_SIZE(test_cases); i++)
    {
        struct TestCase test = test_cases[i];
        uint8_t toggled_val = TOGGLE_PORT_PIN(test.port_val, test.pin);
        TEST_ASSERT_EQUAL(test.expected_val, toggled_val);
    }
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_toggle_pin);
    UNITY_END();
}